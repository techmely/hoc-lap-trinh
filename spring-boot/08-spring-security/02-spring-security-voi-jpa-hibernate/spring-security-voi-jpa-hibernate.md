---
title: "Spring Security với JPA Hibernate"
description: "Spring Security là một framework mạnh mẽ cho việc quản lý bảo mật trong ứng dụng web, trong khi JPA Hibernate được sử dụng để tương tác với cơ sở dữ liệu"
chapter:
  name: "Spring security"
  slug: "chuong-08-spring-security"
category:
  name: "SpringBoots"
  slug: "springboots"
image: https://kungfutech.edu.vn/thumbnail.png
position: 2
---

Trong bài viết này, chúng ta sẽ tìm hiểu cách kết hợp **Spring Security** và **JPA Hibernate** để xây dựng một hệ thống xác thực và phân quyền người dùng trong ứng dụng Spring Boot. **Spring Security** là một framework mạnh mẽ cho việc quản lý bảo mật trong ứng dụng web, trong khi **JPA Hibernate** được sử dụng để tương tác với cơ sở dữ liệu.

### Cài đặt

Chúng ta sẽ sử dụng **Maven** để quản lý dự án. Để bắt đầu, bạn cần thêm các phần tử sau vào file `pom.xml` để khai báo các phụ thuộc cần thiết.

```xml
<dependencies>
    <!-- Spring Boot Starter Web -->
    <dependency>
        <groupId>org.springframework.boot</groupId>
        <artifactId>spring-boot-starter-web</artifactId>
    </dependency>

    <!-- Spring Boot Starter Security -->
    <dependency>
        <groupId>org.springframework.boot</groupId>
        <artifactId>spring-boot-starter-security</artifactId>
    </dependency>

    <!-- Spring Boot Starter Data JPA -->
    <dependency>
        <groupId>org.springframework.boot</groupId>
        <artifactId>spring-boot-starter-data-jpa</artifactId>
    </dependency>

    <!-- H2 Database (In-Memory Database) -->
    <dependency>
        <groupId>com.h2database</groupId>
        <artifactId>h2</artifactId>
        <scope>runtime</scope>
    </dependency>

    <!-- Spring Boot Starter Thymeleaf (Optional) -->
    <dependency>
        <groupId>org.springframework.boot</groupId>
        <artifactId>spring-boot-starter-thymeleaf</artifactId>
    </dependency>
</dependencies>
```

### Cấu trúc thư mục dự án

Chúng ta sẽ tạo một ứng dụng Spring Boot với cấu trúc thư mục như sau:

```scss
src
├── main
│   ├── java
│   │   └── com
│   │       └── example
│   │           └── securitydemo
│   │               ├── model
│   │               │   └── User.java
│   │               ├── repository
│   │               │   └── UserRepository.java
│   │               ├── service
│   │               │   └── UserService.java
│   │               ├── controller
│   │               │   └── WebController.java
│   │               └── SecurityDemoApplication.java
│   ├── resources
│   │   ├── application.properties
│   │   └── templates
│   │       ├── home.html
│   │       └── hello.html
```

### Triển khai Entity `User`

Đầu tiên, chúng ta cần định nghĩa một Entity `User` để tham chiếu đến thông tin người dùng trong cơ sở dữ liệu. Entity này sẽ được ánh xạ vào bảng `user` trong cơ sở dữ liệu.

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

Chúng ta sử dụng `UserRepository` để tương tác với cơ sở dữ liệu để tìm kiếm người dùng theo `username`.

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

### Cấu hình và Phân quyền với Spring Security

Chúng ta cần cấu hình **Spring Security** và xác định quyền truy cập cho các tài nguyên. Dưới đây là một phần của cấu hình Spring Security:

```java
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.context.annotation.Bean;
import org.springframework.security.config.annotation.authentication.builders.AuthenticationManagerBuilder;
import org.springframework.security.config.annotation.web.builders.HttpSecurity;
import org.springframework.security.config.annotation.web.configuration.EnableWebSecurity;
import org.springframework.security.config.annotation.web.configuration.WebSecurityConfigurerAdapter;
import org.springframework.security.crypto

.bcrypt.BCryptPasswordEncoder;
import org.springframework.security.crypto.password.PasswordEncoder;

@EnableWebSecurity
public class WebSecurityConfig extends WebSecurityConfigurerAdapter {

    @Autowired
    UserService userService;

    @Bean
    public PasswordEncoder passwordEncoder() {
        // Sử dụng mã hóa BCrypt cho mật khẩu người dùng
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
            .authorizeRequests()
                .antMatchers("/", "/home").permitAll()
                .anyRequest().authenticated()
                .and()
            .formLogin()
                .defaultSuccessUrl("/hello")
                .permitAll()
                .and()
            .logout()
                .permitAll();
    }
}
```

Điểm quan trọng là việc đăng ký `UserService` để cung cấp thông tin người dùng và sử dụng `BCryptPasswordEncoder` để mã hóa mật khẩu.

### Xây dựng Controller và Trang Web

Chúng ta cần xây dựng các API và trang web để đăng nhập và truy cập tài nguyên an toàn. Dưới đây là ví dụ về một số API và trang web:

```java
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;

@Controller
public class WebController {

    @GetMapping(value = {"/", "/home"})
    public String homepage() {
        return "home";
    }

    @GetMapping("/hello")
    public String hello() {
        return "hello";
    }
}
```

Các trang web được sử dụng Thymeleaf để hiển thị, như `home.html` và `hello.html`.

### Chạy ứng dụng

Khi ứng dụng được triển khai, bạn có thể sử dụng các API như sau:

1. `GET /home`: Truy cập trang chủ.
2. `GET /hello`: Truy cập trang an toàn sau khi đăng nhập.
3. `POST /login`: Đăng nhập để nhận JWT token (do Spring Security xử lý).

Khi truy cập trang an toàn mà không đăng nhập, bạn sẽ được chuyển hướng đến trang đăng nhập. Sau khi đăng nhập thành công, bạn sẽ có quyền truy cập trang an toàn.

::alert{type="success"}
Trong bài viết này, chúng ta đã tìm hiểu cách kết hợp **Spring Security** và **JPA Hibernate** để xây dựng một hệ thống xác thực và phân quyền trong ứng dụng Spring Boot. Điều này giúp đảm bảo rằng người dùng chỉ có quyền truy cập vào những tài nguyên mà họ được phép, và thông tin người dùng được lưu trữ và quản lý một cách an toàn.
::
