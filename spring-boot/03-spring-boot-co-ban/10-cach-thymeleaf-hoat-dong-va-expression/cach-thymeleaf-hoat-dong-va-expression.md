---
title: "Cách Thymeleaf hoạt động và expression"
description: "Trong bài này, chúng ta sẽ chi tiết hơn về Thymeleaf và sử dụng nó để xây dựng một trang web đơn giản"
chapter:
  name: "Spring Boot cơ bản"
  slug: "chuong-03-spring-boot-co-ban"
category:
  name: "Spring Boot"
  slug: "spring-boot"
position: 10
---

## Giới thiệu

Trong bài này, chúng ta sẽ chi tiết hơn về Thymeleaf và sử dụng nó để xây dựng một trang web đơn giản.

## Thymeleaf

**Thymeleaf** là một Java Template Engine có nhiệm vụ xử lý và tạo ra các tệp HTML, XML, v.v. Các tệp HTML được tạo ra bởi Thymeleaf dựa trên sự kết hợp giữa dữ liệu và các mẫu (templates) cùng với các quy tắc được định sẵn.

![Thymeleaf](https://github.com/techmely/hoc-lap-trinh/assets/29374426/0977fea6-eb16-4d23-ada9-d8b0642f555e)

Nhiệm vụ của bạn là cung cấp dữ liệu và chỉ định cách sử dụng các mẫu, còn việc tạo tệp HTML sẽ được Thymeleaf thực hiện.

## Cú pháp trong Thymeleaf

Cú pháp của Thymeleaf được thêm vào các thuộc tính của các thẻ HTML và bắt đầu bằng tiền tố `th:`.

Với cách tiếp cận này, bạn có thể sử dụng các thẻ HTML thông thường mà không cần học thêm cú pháp hoặc thêm các thẻ mới như trong JSP truyền thống.

Ví dụ:

Để truyền dữ liệu từ biến `name` trong Java vào một thẻ `H1` của HTML:

```html
<h1 th:text="${name}"></h1>
```

Chúng ta viết thẻ `H1` như bình thường, nhưng không có văn bản cố định trong thẻ. Thay vào đó, chúng ta sử dụng cú pháp `th:text="${name}"` để Thymeleaf lấy giá trị từ biến `name` và đưa vào thẻ `H1`.

Kết quả khi render:

```html
<!-- Giả sử String name = "loda" -->
<h1>Loda</h1>
```

Thuộc tính `th:text` đã biến mất và giá trị của biến `name` được đưa vào trong thẻ `H1`.

Đó là cách Thymeleaf hoạt động.

## Model & View Trong Spring Boot

Trong bài trước, chúng ta đã giới thiệu việc sử dụng đối tượng `Model`. Trong bài này, chúng ta sẽ đi sâu hơn.

`Model` là một đối tượng dùng để lưu trữ thông tin và được sử dụng bởi **Template Engine** để tạo ra trang web. Nó có thể được hiểu như là "Context" của Thymeleaf.

`Model` lưu trữ thông tin dưới dạng cặp key-value.

Trong template Thymeleaf, để lấy thông tin từ `Model`, bạn sử dụng Thymeleaf Standard Expression.

1. `${...}`: Giá trị của một biến.
2. `*{...}`: Giá trị của một biến được chỉ định (sẽ giải thích ở dưới).

Ngoài ra, để lấy các thông tin đặc biệt hơn:

1. `#{...}`: Lấy thông báo (message).
2. `@{...}`: Lấy URL dựa trên ngữ cảnh của máy chủ.

Chúng ta sẽ thấy rõ hơn về từng loại biểu thức trong ví dụ.

## `${...}` - Biểu thức Biến

Trong Controller, bạn có thể đặt một số giá trị như sau:

```java
model.addAttribute("today", "Monday");
```

Để lấy giá trị của biến `today`, bạn sử dụng `${...}` như sau:

```html
<p>Today is: <span th:text="${today}"></span>.</p>
```

Biểu thức trên tương đương với:

```java
ctx.getVariable("today");
```

## `*{...}` - Biểu thức Biến trên các phần tử

Biểu thức `*` còn được gọi là `asterisk syntax`. Chức năng của nó giống với `${...}`, tức là lấy giá trị của một biến.

Tuy nhiên, nó sẽ lấy giá trị của biến trong ngữ cảnh của `th:object`.

```html
<div th:object="${session.user}">
  <!-- th:object tồn tại trong phạm vi của thẻ div này -->

  <!-- Lấy tên từ đối tượng session.user -->
  <p>Name: <span th:text="*{firstName}"></span>.</p>
  <!-- Lấy lastName từ đối tượng session.user -->
  <p>Surname: <span th:text="*{lastName}"></span>.</p>
</div>
```

`${...}` sẽ lấy giá trị cục bộ trong `Context` hoặc `Model`, trong khi `*{...}` sẽ lấy giá trị từ đối tượng đã được chỉ định bởi `th:object`.

## `#{...}` - Biểu thức Message

Ví dụ, trong tệp cấu hình `.properties` của bạn, bạn có một thông báo chào đón người dùng bằng nhiều ngôn ngữ:

```java
home.welcome=Hello bạn
```

Thì cách lấy nó ra nhanh nhất là:

```html
<p th:utext="#{home.welcome}">Xin chào các bạn!</p>
```

Đoạn văn bản tiếng Việt bên trong thẻ `p` sẽ bị thay thế bởi Thymeleaf khi render `#{home.welcome}`.

## `@{...}` - Biểu thức URL

`@{...}` xử lý và trả về giá trị URL dựa trên ngữ cảnh của máy chủ.

Ví dụ:

```html
<!-- Tương đương 'http://localhost:8080/order/details?orderId=3' -->
<a
  href="details.html"
  th:href="@{http://localhost:8080/order/details(orderId=${o.id})}"
  >view</a
>

<!-- Tương đương '/order/details?orderId=3' -->
<a href="details.html" th:href="@{/order/details(orderId=${o.id})}">view</a>

<!-- Tương đương '/gtvg/order/3/details' -->
<a href="details.html" th:href="@{/order/{orderId}/details(orderId=${o.id})}"
  >view</a
>
```

Nếu bạn bắt đầu bằng dấu `/`, nó sẽ là URL tương đối và sẽ được xác định dựa trên ngữ cảnh máy chủ của bạn.

## Demo Minh Họa

Chúng ta sẽ tạo một trang web đơn giản để hiểu rõ hơn về các loại biểu thức trong Thymeleaf.

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
    <h1 th:text="#{loda.hello}"></h1>
    <a th:href="@{/profile}" class="btn btn-primary">Kungfutech Profile</a>
  </body>
</html>
```

### Tạo @Controller cho `/profile`

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
        profile.add(new Info("fullname", "Nguyễn Hoàng Nam"));
        profile.add(new Info("nickname", "loda"));
        profile.add(new Info("email", "loda.namnh@gmail.com"));
        profile.add(new Info("website", "https://loda.me"));

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
    <h1 th:text="#{loda.hello}"></h1>
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
