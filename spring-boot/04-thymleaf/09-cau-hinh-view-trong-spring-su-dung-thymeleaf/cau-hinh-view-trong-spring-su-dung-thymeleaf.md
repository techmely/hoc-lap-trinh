---
title: "Cấu hình view trong spring sử dụng Thymeleaf"
description: "Chúng ta sẽ tạo một trang web đơn giản để hiểu rõ hơn về các loại biểu thức trong Thymeleaf"
chapter:
  name: "Thymeleaf"
  slug: "chuong-04-thymeleaf"
position: 09
---

Chúng ta sẽ tạo một trang web đơn giản để hiểu rõ hơn về các loại biểu thức trong `Thymeleaf`.

### Cấu hình Maven

Thêm dependency cho Spring Boot và Thymeleaf vào `pom.xml`:

```xml
<dependency>
    <groupId>org.springframework.boot</groupId>
    <artifactId>spring-boot-starter-web</artifactId>
</dependency>

<dependency>
    <groupId>org.springframework.boot</groupId>
    <artifactId>spring-boot-starter-thymeleaf</artifactId>
</dependency>
```

### Cấu trúc Thư Mục

Cấu trúc thư mục của dự án:

### Cấu hình Thymeleaf

Cấu hình ứng dụng thông qua tệp `application.properties`:

```properties
# Chạy ứng dụng trên port 8085
server.port=8085

# Vô hiệu hóa tính năng cache của Thymeleaf để phát triển nhanh hơn
spring.thymeleaf.cache=false

# Các thông báo cố định sẽ được lưu tại thư mục i18n
spring.messages.basename=i18n/messages

# Bỏ comment dòng này để đặt ngôn ngữ mặc định là Tiếng Anh
# spring.mvc.locale=en_US
```

### Tạo Trang Index

Trang `index.html` sẽ là trang mặc định mà Thymeleaf tìm khi không có đường dẫn cụ thể. Chúng ta sẽ sử dụng nó để hiển thị thông báo chào mừng và một nút liên kết tới trang profile.

```html
<!DOCTYPE html>
<html xmlns:th="http://www.thymeleaf.org">
  <head>
    <meta charset="UTF-8" />
    <title>Hello World</title>
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />

    <!-- CSS -->
    <link th:href="@{/css/bootstrap.css}" rel="stylesheet" />

    <!-- JavaScript -->
    <script th:src="@{/js/bootstrap.js}"></script>
  </head>
  <body>
    <h1 th:text="#{kungfutech.hello}"></h1>
    <a th:href="@{/profile}" class="btn btn-primary">Kungfutech Profile</a>
  </body>
</html>
```

### Tạo `@Controller` cho `/profile`

Chúng ta sẽ tạo một `@Controller` để xử lý các yêu cầu tới `/profile`. Đây là đoạn mã Java:

```java
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;

import java.util.ArrayList;
import java.util.List;

@Controller
public class WebController {

    @GetMapping("/profile")
    public String profile(Model model) {
        // Tạo danh sách thông tin cá nhân
        List<Info> profile = new ArrayList<>();
        profile.add(new Info("fullname", "KungfuTech"));
        profile.add(new Info("nickname", "kungfutech"));
        profile.add(new Info("email", "techmely.creation@gmail.com"));
        profile.add(new Info("website", "https://kungfutech.me"));

        // Đưa danh sách vào Model
        model.addAttribute("kungfutechProfile", profile);

        // Trả về template profile.html
        return "profile";
    }
}
```

### Tạo Trang Profile

Trang `profile.html` sẽ hiển thị thông tin từ Model, sử dụng Thymeleaf để hiển thị dữ liệu từ danh sách thông tin cá nhân.

```html
<!DOCTYPE html>
<html xmlns:th="http://www.thymeleaf.org">
  <head>
    <meta charset="UTF-8" />
    <title>Kungfutech Profile</title>
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />

    <!-- CSS -->
    <link th:href="@{/css/bootstrap.css}" rel="stylesheet" />

    <!-- JavaScript -->
    <script th:src="@{/js/bootstrap.js}"></script>
  </head>
  <body>
    <h1 th:text="#{kungfutech.hello}"></h1>
    <h2>Kungfutech Profile</h2>
    <ul>
      <!-- Duyệt qua toàn bộ danh sách kungfutechProfile -->
      <li th:each="info : ${kungfutechProfile}">
        <!-- Lấy key và value từ danh sách -->
        <span th:text="*{info.key}"></span> :
        <span th:text="*{info.value}"></span>
      </li>
    </ul>
  </body>
</html>
```

### Chạy Ứng Dụng

Chúng ta đã hoàn thành ứng dụng của mình. Hãy chạy ứng dụng Spring Boot như sau:

```java
@SpringBootApplication
public class App {
    public static void main(String[] args) {
        SpringApplication.run(App.class, args);
    }
}
```

Truy cập địa chỉ `http://localhost:8085/` để xem trang chào mừng.

Nhấn vào nút "Kungfutech Profile" để xem trang thông tin cá nhân.

Đó là một ứng dụng web cơ bản sử dụng Thymeleaf và Spring Boot để hiển thị trang chào mừng và trang thông tin cá nhân.

::alert{type="success"}
Trong bài viết này, chúng ta đã tìm hiểu về Thymeleaf và cách sử dụng nó trong ứng dụng Spring Boot để tạo trang web đơn giản. Chúng ta đã biết cách sử dụng các biểu thức Thymeleaf để truyền dữ liệu từ Model vào template và tạo các liên kết URL dễ dàng. Hy vọng rằng bài viết này đã giúp bạn hiểu rõ hơn về cách sử dụng Thymeleaf trong phát triển ứng dụng web với Spring Boot.
::
