---
title: "Spring Security với Hibernate JWT"
description: "JWT (JSON Web Token) là một phần quan trọng trong bảo mật ứng dụng web hiện đại, giúp xác thực và phân quyền người dùng một cách an toàn"
chapter:
  name: "Spring security"
  slug: "chuong-08-spring-security"
image: https://kungfutech.edu.vn/thumbnail.png
position: 3
---

Trong bài viết này, chúng ta sẽ tìm hiểu cách kết hợp **Spring Security**, **Hibernate**, và **JSON Web Token (JWT)** để xây dựng một hệ thống bảo mật cho ứng dụng web. **JWT** (JSON Web Token) là một phần quan trọng trong bảo mật ứng dụng web hiện đại, giúp xác thực và phân quyền người dùng một cách an toàn.

Chúng ta sẽ cùng đi qua các bước để triển khai một ứng dụng sử dụng **Spring Security** để quản lý việc xác thực người dùng và **JWT** để bảo vệ các tài nguyên của ứng dụng.

## Cài đặt

Chúng ta sử dụng Maven để quản lý dự án, và ta cần thêm thư viện `io.jsonwebtoken.jwtt` để hỗ trợ việc tạo và kiểm tra JWT.

```xml
<dependencies>
    <!-- ... Các dependency khác ... -->
    <dependency>
        <groupId>io.jsonwebtoken</groupId>
        <artifactId>jjwt</artifactId>
        <version>0.9.1</version>
    </dependency>
</dependencies>
```

## Cấu trúc thư mục dự án

Cấu trúc thư mục dự án gồm:

- `src/main/java`: Chứa mã nguồn Java.
- `src/main/resources`: Chứa các tài liệu tĩnh, cấu hình, và giao diện người dùng (thư mục `templates`).
- `src/main/resources/application.properties`: Tệp cấu hình ứng dụng Spring Boot.

## Triển khai ứng dụng

### Định nghĩa Entity `User`

Đầu tiên, chúng ta sẽ định nghĩa một Entity `User` để tham chiếu đến thông tin người dùng trong cơ sở dữ liệu.

```java
import javax.persistence.*;

@Entity
@Table(name = "user")
public class User {
    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long id;

    @Column(nullable = false, unique = true)
    private String username;

    private String password;

    // Getter và setter
}
```

### Triển khai Repository `UserRepository`

Chúng ta sẽ sử dụng `UserRepository` để tương tác với cơ sở dữ liệu để tìm kiếm người dùng theo `username`.

```java
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;

@Repository
public interface UserRepository extends JpaRepository<User, Long> {
    User findByUsername(String username);
}
```

### Định nghĩa `CustomUserDetails`

`CustomUserDetails` là một lớp được tạo ra để thể hiện thông tin người dùng dưới dạng `UserDetails` mà **Spring Security** sử dụng.

```java
import org.springframework.security.core.GrantedAuthority;
import org.springframework.security.core.authority.SimpleGrantedAuthority;
import org.springframework.security.core.userdetails.UserDetails;
import java.util.Collection;
import java.util.Collections;

public class CustomUserDetails implements UserDetails {
    private User user;

    public CustomUserDetails(User user) {
        this.user = user;
    }

    @Override
    public Collection<? extends GrantedAuthority> getAuthorities() {
        // Mặc định, chúng ta sẽ sử dụng ROLE_USER.
        return Collections.singleton(new SimpleGrantedAuthority("ROLE_USER"));
    }

    @Override
    public String getPassword() {
        return user.getPassword();
    }

    @Override
    public String getUsername() {
        return user.getUsername();
    }

    @Override
    public boolean isAccountNonExpired() {
        return true;
    }

    @Override
    public boolean isAccountNonLocked() {
        return true;
    }

    @Override
    public boolean isCredentialsNonExpired() {
        return true;
    }

    @Override
    public boolean isEnabled() {
        return true;
    }
}
```

### Triển khai `UserService`

`UserService` là một dịch vụ được tạo ra để thực hiện việc truy vấn người dùng từ cơ sở dữ liệu dựa trên `username`.

```java
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.security.core.userdetails.UserDetails;
import org.springframework.security.core.userdetails.UserDetailsService;
import org.springframework.security.core.userdetails.UsernameNotFoundException;
import org.springframework.stereotype.Service;

@Service
public class UserService implements UserDetailsService {

    @Autowired
    private UserRepository userRepository;

    @Override
    public UserDetails loadUserByUsername(String username) {
        User user = userRepository.findByUsername(username);
        if (user == null) {
            throw new UsernameNotFoundException(username);
        }
        return new CustomUserDetails(user);
    }
}
```

### Triển khai `JwtTokenProvider`

`JwtTokenProvider` là một lớp được tạo ra để giúp tạo và kiểm tra JWT.

```java
import org.springframework.stereotype.Component;
import io.jsonwebtoken.*;
import lombok.extern.slf4j.Slf4j;
import java.util.Date;

@Component
@Slf4j
public class JwtTokenProvider {
    private final String JWT_SECRET = "your-secret-key"; // Thay thế bằng secret key của bạn
    private final long JWT_EXPIRATION = 604800000L; // 7 ngày

    public String generateToken(CustomUserDetails userDetails) {
        Date now = new Date();
        Date expiryDate = new Date(now.getTime() + JWT_EXPIRATION);

        return Jwts.builder()
                   .setSubject(Long.toString(userDetails.getUser().getId()))
                   .setIssuedAt(now)
                   .setExpiration(expiryDate)
                   .signWith(SignatureAlgorithm.HS512, JWT_SECRET)
                   .compact();
    }

    public Long getUserIdFromJWT(String token) {
        Claims claims = Jwts.parser()
                            .setSigningKey(JWT_SECRET)
                            .parseClaimsJws(token)
                            .getBody();

        return Long.parseLong(claims.getSubject());
    }

    public boolean validateToken(String authToken) {
        try {
            Jwts.parser().setSigningKey(JWT_SECRET).parseClaimsJws(authToken);
            return true;
        } catch (MalformedJwtException ex) {
            log.error("Invalid JWT token");
        } catch (ExpiredJwtException ex) {
            log.error("Expired JWT token");
        } catch (UnsupportedJwtException ex) {
            log.error("Unsupported JWT token");
        } catch (IllegalArgumentException ex) {
            log.error("

JWT claims string is empty.");
        }
        return false;
    }
}
```

### Cấu hình và Phân quyền với Spring Security

Chúng ta cần cấu hình **Spring Security** và xác định quyền truy cập cho các tài nguyên. Dưới đây là một phần của cấu hình Spring Security:

```java
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.context.annotation.Bean;
import org.springframework.security.authentication.AuthenticationManager;
import org.springframework.security.config.BeanIds;
import org.springframework.security.config.annotation.authentication.builders.AuthenticationManagerBuilder;
import org.springframework.security.config.annotation.web.builders.HttpSecurity;
import org.springframework.security.config.annotation.web.configuration.EnableWebSecurity;
import org.springframework.security.config.annotation.web.configuration.WebSecurityConfigurerAdapter;
import org.springframework.security.crypto.bcrypt.BCryptPasswordEncoder;
import org.springframework.security.crypto.password.PasswordEncoder;
import org.springframework.security.web.authentication.UsernamePasswordAuthenticationFilter;

@EnableWebSecurity
public class WebSecurityConfig extends WebSecurityConfigurerAdapter {

    @Autowired
    private UserService userService;

    @Bean
    public JwtAuthenticationFilter jwtAuthenticationFilter() {
        return new JwtAuthenticationFilter();
    }

    @Bean(BeanIds.AUTHENTICATION_MANAGER)
    @Override
    public AuthenticationManager authenticationManagerBean() throws Exception {
        return super.authenticationManagerBean();
    }

    @Bean
    public PasswordEncoder passwordEncoder() {
        return new BCryptPasswordEncoder();
    }

    @Override
    protected void configure(AuthenticationManagerBuilder auth) throws Exception {
        auth.userDetailsService(userService)
            .passwordEncoder(passwordEncoder());
    }

    @Override
    protected void configure(HttpSecurity http) throws Exception {
        http
            .cors()
            .and()
            .authorizeRequests()
                .antMatchers("/api/login").permitAll()
                .anyRequest().authenticated();

        http.addFilterBefore(jwtAuthenticationFilter(), UsernamePasswordAuthenticationFilter.class);
    }
}
```

Điểm quan trọng là việc đăng ký `JwtAuthenticationFilter` để kiểm tra JWT trước khi xử lý request.

### Xây dựng Controller

Chúng ta cần xây dựng các API để đăng nhập và truy cập tài nguyên an toàn. Dưới đây là ví dụ về một số API:

```java
@RestController
@RequestMapping("/api")
public class ApiController {

    @Autowired
    AuthenticationManager authenticationManager;

    @Autowired
    private JwtTokenProvider tokenProvider;

    @PostMapping("/login")
    public ResponseEntity<?> authenticateUser(@Valid @RequestBody LoginRequest loginRequest) {
        Authentication authentication = authenticationManager.authenticate(
                new UsernamePasswordAuthenticationToken(
                        loginRequest.getUsername(),
                        loginRequest.getPassword()
                )
        );

        SecurityContextHolder.getContext().setAuthentication(authentication);

        String jwt = tokenProvider.generateToken((CustomUserDetails) authentication.getPrincipal());
        return ResponseEntity.ok(new JwtAuthenticationResponse(jwt));
    }

    @GetMapping("/secure-resource")
    public ResponseEntity<String> getSecureResource() {
        return ResponseEntity.ok("This is a secure resource.");
    }
}
```

### Chạy ứng dụng

Khi ứng dụng được triển khai, bạn có thể sử dụng các API như sau:

1. `POST /api/login`: Đăng nhập để nhận JWT token.
2. `GET /api/secure-resource`: Truy cập tài nguyên an toàn bằng cách gửi JWT token trong Header của request.

Khi truy cập tài nguyên an toàn mà không cung cấp JWT token, bạn sẽ nhận được mã lỗi `403 - Access Denied`.

::alert{type="success"}

- Trong bài viết này, chúng ta đã tìm hiểu cách kết hợp **Spring Security**, **Hibernate**, và **JWT** để xây dựng một hệ thống bảo mật cho ứng dụng web. JWT giúp chúng ta xác thực và phân quyền người dùng một cách an toàn và hiệu quả.
- Việc triển khai một hệ thống bảo mật như vậy đòi hỏi hiểu biết về Spring Security, Hibernate và JWT. Tuy nhiên, khi đã triển khai thành công, bạn sẽ có một hệ thống bảo mật mạnh mẽ cho ứng dụng web của mình.

::
