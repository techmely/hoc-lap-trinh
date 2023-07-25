---
title: "Standard Expression trong Thymeleaf"
description: "Trong template thymeleaf, để lấy các thông tin trong Model. bạn sẽ sử dụng Thymeleaf Standard Expression"
keywords:
  [
    "khóa học Spring cơ bản",
    "Giới thiệu thymeleaf",
    "Thymeleaf là gì",
    "hướng dẫn thymeleaf",
    "thymeleaf cơ bản",
    "expression trong thymeleaf",
    "standard expression trong thymeleaf là gì",
    "sử dụng standard expression trong thymeleaf",
    "variable expression trong thymeleaf",
    "message expression trong thymeleaf",
    "url expression trong thymeleaf",
    "các loại standard expression trong thymeleaf",
  ]
chapter:
  name: "Thymeleaf"
  slug: "chuong-05-thymeleaf"
category:
  name: "Spring Boot"
  slug: "spring-boot"
image: https://kungfutech.edu.vn/thumbnail.png
position: 3
---

![thymeleaf](https://github.com/techmely/hoc-lap-trinh/assets/29374426/5a614a07-a8c1-4bd5-b750-e6759fd207f5)

Trong template `Thymeleaf`, để lấy các thông tin trong **Model**. bạn sẽ sử dụng `Thymeleaf Standard Expression`.
Ở bài này chúng ta sẽ đề cập đến 4 loại `Expression` sau:

- `${...}`: Lấy giá trị của một biến.
- `*{...}`: Lấy giá trị của một biến được chỉ định
- `#{...}`: Lấy message
- `@{...}`: Lấy đường dẫn URL dựa theo context của server

### `${...}` - Lấy giá trị của một biến (Variables Expressions)

Ví dụ, trên Controller bạn đưa vào một số giá trị:

```java
model.addAttribute("techMely", "kenh day lap trinh hap dan");
```

Để lấy giá trị của biến today, ta sử dụng `${...}`

```java
<p>Techmely la: <span th:text="${today}"></span>.</p>
```

Kết quả sẽ in ra:
<content-result>Techmely la: kenh day lap trinh hap dan </content-result>
Đoạn expression trên tương đương với:

```java
ctx.getVariable("today");
```

### `*{...}` - Lấy giá trị của một biến được chỉ định (Variables Expressions on selections)

Chức năng của nó giống với `${...}` là lấy giá trị của một biến.

Điểm khác biệt là `*{...}` sẽ lấy ra giá trị của một biến cho trước bởi **th:object**, còn `${...}` sẽ lấy ra giá trị cục bộ trong **Context** hay **Model**.
Ví dụ:

```html
<div th:object="${session.user}">   <!-- th:object tồn tại trong phạm vi của thẻ div này -->

<!-- Lấy ra tên của đối tượng session.user -->
<p>
Name: <span th:text="*{firstName}"></span>  <!-- Lấy ra firstName của đối tượng session.user -->
</p>
<p>
Surname: <spanth:text="*{lastName}"></span>. <!-- Lấy ra lastName của đối tượng session.user -->
</p>
</div>
```

Đoạn code này tương đương:

```html
<div>
<p>Name: <span th:text="${session.user.firstName}"></span>.</p>
<p>Surname: <spanth:text="${session.user.lastName}"></span>.</p>
</div>
```

### `#{...}` - Lấy message (Message Expression)

Ví dụ, trong file config `.properties` có một **_message_** chào người dùng bằng nhiều ngôn ngữ.

```java
home.welcome = Hello, how's it going!
```

Thì cách lấy nó ra nhanh nhất là:

```java
<p th:utext="#{home.welcome}">Xin chào các bạn!</p>
```

Đoạn text tiếng việt _"Xin chào các bạn!"_ bên trong thẻ **p** sẽ bị thay thế bởi `Thymeleaf` khi render `#{home.welcome}`.
<content-result> Hello, how's it going!</content-result>

### `@{...}` - Lấy đường dẫn URL (URL Expression)

`@{...}` xử lý và trả ra giá trị **URL** theo context của máy chủ cho chúng ta.
Ví dụ:

```java
<!-- tương đương với 'http://localhost:8080/order/details?orderId=3' -->
<a href="details.html" th:href="@{http://localhost:8080/order/details(orderId=${o.id})}">view</a>
<!-- tương đương  '/order/details?orderId=3' -->

<a href="details.html" th:href="@{/order/details(orderId=${o.id})}">view</a>
<!-- tương dương '/gtvg/order/3/details' -->

<a href="details.html" th:href="@{/order/{orderId}/details(orderId=${o.id})}">view</a>
```

Nếu bắt dầu bằng dấu `/` thì nó sẽ là **Relative URL** và sẽ tương ứng theo context của máy chủ của bạn.
