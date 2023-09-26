---
title: "Tìm hiểu về Spring Security"
description: "Spring Security là một trong những tính năng cốt lõi của Spring Framework, nó cho phép bạn quản lý việc phân quyền và xác thực người dùng trước khi cho họ truy cập vào các tài nguyên của ứng dụng web"
chapter:
  name: "Spring security"
  slug: "chuong-08-spring-security"
category:
  name: "SpringBoots"
  slug: "springboots"
image: https://kungfutech.edu.vn/thumbnail.png
position: 1
---

**Spring Security** là một trong những tính năng cốt lõi của Spring Framework, nó cho phép bạn quản lý việc phân quyền và xác thực người dùng trước khi cho họ truy cập vào các tài nguyên của ứng dụng web. Trong bài viết này, chúng ta sẽ tìm hiểu cách triển khai Spring Security cơ bản và dễ hiểu. Chúng ta sẽ tiếp cận các chức năng nâng cao hơn ở các bài viết sau.

## Cài đặt

Trước khi bắt đầu, chúng ta cần cài đặt các phụ thuộc cần thiết cho dự án Spring Boot của mình. Dưới đây là một ví dụ về cách thêm các phụ thuộc Spring Security vào tệp `pom.xml`:

```xml
<dependencies>
    <!-- Các phụ thuộc khác -->
    <dependency>
        <groupId>org.springframework.boot</groupId>
        <artifactId>spring-boot-starter-security</artifactId>
    </dependency>
</dependencies>
```

Sau khi thêm phụ thuộc này, chúng ta đã sẵn sàng để bắt đầu triển khai Spring Security.

## Triển khai cơ bản

### Kích hoạt tính năng Spring Security

Để bắt đầu sử dụng Spring Security, bạn cần kích hoạt tính năng này trong ứng dụng Spring Boot của bạn. Bạn có thể làm điều này bằng cách thêm annotation `@EnableWebSecurity` lên một bean bất kỳ trong ứng dụng của bạn.

```java
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.security.config.annotation.web.builders.HttpSecurity;
import org.springframework.security.config.annotation.web.configuration.EnableWebSecurity;
import org.springframework.security.config.annotation.web.configuration.WebSecurityConfigureAdapter;

@Configuration
@EnableWebSecurity
public class SecurityConfig extends WebSecurityConfigureAdapter {

    @Override
    protected void configure(HttpSecurity http) throws Exception {
        // Cấu hình phân quyền và xác thực ở đây
    }
}
```

### Xác thực người dùng

#### Sử dụng In-Memory Authentication

Trong ví dụ cơ bản này, chúng ta sẽ sử dụng phương thức xác thực In-Memory để tạo một tài khoản người dùng và mật khẩu. Tuy nhiên, đây chỉ là mục đích minh họa, trong thực tế, bạn sẽ xác thực từ cơ sở dữ liệu hoặc nguồn dữ liệu khác.

```java
import org.springframework.context.annotation.Bean;
import org.springframework.security.config.annotation.web.builders.HttpSecurity;
import org.springframework.security.config.annotation.web.configuration.EnableWebSecurity;
import org.springframework.security.config.annotation.web.configuration.WebSecurityConfigurerAdapter;
import org.springframework.security.core.userdetails.User;
import org.springframework.security.core.userdetails.UserDetails;
import org.springframework.security.core.userdetails.UserDetailsService;
import org.springframework.security.provisioning.InMemoryUserDetailsManager;

@Configuration
@EnableWebSecurity
public class SecurityConfig extends WebSecurityConfigurerAdapter {

    @Bean
    @Override
    public UserDetailsService userDetailsService() {
        // Tạo một tài khoản người dùng trong bộ nhớ (chỉ cho mục đích minh họa)
        UserDetails user = User.withDefaultPasswordEncoder()
            .username("user")
            .password("password")
            .roles("USER")
            .build();
        return new InMemoryUserDetailsManager(user);
    }

    @Override
    protected void configure(HttpSecurity http) throws Exception {
        // Cấu hình phân quyền và xác thực ở đây
    }
}
```

Ở đoạn mã trên:

- Chúng ta tạo một tài khoản người dùng có tên đăng nhập "user" và mật khẩu "password" bằng cách sử dụng phương thức `User.withDefaultPasswordEncoder()`.
- Bạn có thể thay đổi thông tin xác thực theo nhu cầu của bạn.

### Phân quyền truy cập

Khi đã có tài khoản người dùng, chúng ta có thể xác định quyền truy cập đối với các tài nguyên trong ứng dụng. Ví dụ sau đây cho phép tất cả mọi người truy cập vào trang chủ (`/`) và trang `/public`. Tuy nhiên, trang `/private` yêu cầu xác thực và có quyền truy cập cho người dùng với vai trò "USER".

```java
import org.springframework.context.annotation.Bean;
import org.springframework.security.config.annotation.web.builders.HttpSecurity;
import org.springframework.security.config.annotation.web.configuration.EnableWebSecurity;
import org.springframework.security.config.annotation.web.configuration.WebSecurityConfigurerAdapter;
import org.springframework.security.core.userdetails.User;
import org.springframework.security.core.userdetails.UserDetails;
import org.springframework.security.core.userdetails.UserDetailsService;
import org.springframework.security.provisioning.InMemoryUserDetailsManager;

@Configuration
@EnableWebSecurity
public class SecurityConfig extends WebSecurityConfigurerAdapter {

    @Bean
    @Override
    public UserDetailsService userDetailsService() {
        UserDetails user = User.withDefaultPasswordEncoder()
            .username("user")
            .password("password")
            .roles("USER")
            .build();
        return new InMemoryUserDetailsManager(user);
    }

    @Override
    protected void configure(HttpSecurity http) throws Exception {
        http
            .authorizeRequests()
                .antMatchers("/", "/public").permitAll() // Cho phép tất cả mọi người truy cập vào trang chủ và trang public
                .anyRequest().authenticated() // Tất cả các request khác đều cần phải xác thực mới được truy cập
            .and()
            .formLogin() // Cho phép người dùng xác thực bằng form login
                .loginPage("/login") // Trang đăng nhập tùy chỉnh
                .permitAll() // Tất cả đều được truy cập vào trang đăng nhập
            .and()
            .logout() // Cho phép logout
                .permitAll();
    }
}
```

Ở đoạn mã trên:

- Chúng ta sử dụng `.authorizeRequests()` để định cấu hình quyền truy cập.
- `.antMatchers()` cho phép chúng ta xác định các URL mà người dùng có thể truy cập mà không cần xác thực.
- `.anyRequest().authenticated()` yêu cầu xác thực đối với tất cả các URL còn lại.
- `.formLogin()` cho phép xác thực người dùng bằng cách sử dụng một trang đăng nhập tùy chỉnh.
- `.loginPage("/login")` xác định trang đăng nhập tùy chỉnh. Nếu bạn không cung cấp trang đăng nhập, Spring Security sẽ tạo một trang đăng nhập mặc định.
- `.logout()` cho phép người dùng đăng xuất.

### Controller và Giao diện người dùng

Cuối cùng, chúng ta tạo các controller và giao diện người dùng cho ứng dụng. Ở ví dụ sau, chúng ta có hai trang: "home" và "private". Trang "home" có quyền truy cập công khai và trang "private" yêu cầu xác thực.

```java
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;

@Controller
public class WebController {

    @GetMapping(value = {"/", "/public"})
    public String home() {
        return "home"; // Trang chủ công khai
    }

    @GetMapping("/private")
    public String privatePage() {
        return "private"; // Trang yêu cầu xác thực
    }

    @GetMapping("/login")
    public String loginPage() {
        return "login"; // Trang đăng nhập tùy chỉnh
    }
}
```

Trang giao diện người dùng được tạo bằng sử dụng Thymeleaf (một template engine) và đặt trong thư mục `resources/templates/`.

**home.html**:

```html
<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="UTF-8" />
    <title>Home</title>
  </head>
  <body>
    <h1>Welcome to the Home Page!</h1>
    <a href="/public">Public Page</a>
    <a href="/private">Private Page</a>
  </body>
</html>
```

**private.html**:

```html
<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="UTF-8" />
    <title>Private Page</title>
  </head>
  <body>
    <h1>Welcome to the Private Page!</h1>
    <a href="/public">Public Page</a>
    <a href="/logout">Logout</a>
  </body>
</html>
```

**login.html**:

```html
<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="UTF-8" />
    <title>Login</title>
  </head>
  <body>
    <h1>Login</h1>
    <form action="/login" method="post">
      <label for="username">Username:</label>
      <input type="text" id="username" name="username" /><br /><br />
      <label for="password">Password:</label>
      <input type="password" id="password" name="password" /><br /><br />
      <input type="submit" value="Login" />
    </form>
  </body>
</html>
```

## Chạy thử

Bây giờ chúng ta đã triển khai Spring Security cơ bản, chúng ta có thể chạy ứng dụng bằng cách chạy lớp `App` chứa hàm `main`.

```java
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;

@SpringBootApplication
public class App {
    public static void main(String[] args) {
        SpringApplication.run(App.class, args);
    }
}
```

Sau khi ứng dụng được chạy, bạn có thể truy cập địa chỉ `http://localhost:8080` để vào trang chủ. Bạn cũng có thể truy cập các trang "Public Page" và "Private Page" từ đó.

**Kết quả**:

- Truy cập `/` và `/public`: Bạn có thể truy cập mà không cần xác thực.
- Truy cập `/private` khi chưa đăng nhập: Bạn sẽ bị chuyển hướng đến trang đăng nhập tùy chỉnh.
- Đăng nhập bằng tên đăng nhập "user" và mật khẩu "password".
- Sau khi đăng nhập thành công, bạn có thể truy cập `/private` và "Private Page" sẽ hiển thị.
- Truy cập `/logout`: Bạn sẽ đăng xuất khỏi ứng dụng.

::alert{type="success"}
Trong bài viết này, chúng ta đã tìm hiểu về Spring Security và cách triển khai một ứng dụng web cơ bản với xác thực và phân quyền. Chúng ta đã sử dụng In-Memory Authentication và cấu hình phân quyền truy cập đối với các trang web. Spring Security cung cấp nhiều tính năng mạnh mẽ khác cho việc quản lý bảo mật ứng dụng web.
::
