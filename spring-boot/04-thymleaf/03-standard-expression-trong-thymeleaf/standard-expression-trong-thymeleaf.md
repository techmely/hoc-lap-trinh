---
title: "Standard Expression trong Thymeleaf"
description: "Trong template thymeleaf, để lấy các thông tin trong Model chúng ta sẽ sử dụng Thymeleaf Standard Expression"
chapter:
  name: "Thymeleaf"
  slug: "chuong-04-thymeleaf"
category:
  name: "Spring Boot"
  slug: "spring-boot"
image: https://kungfutech.edu.vn/thumbnail.png
position: 3
---

Trong template **Thymeleaf**, để lấy các thông tin trong **Model**. bạn sẽ sử dụng `Thymeleaf Standard Expression`.

![Standard Expression trong Thymeleaf](https://github.com/techmely/hoc-lap-trinh/assets/29374426/5a614a07-a8c1-4bd5-b750-e6759fd207f5)

Ở bài này chúng ta sẽ đề cập đến 4 loại `Expression` sau:

- `${...}`: Lấy giá trị của một biến.
- `*{...}`: Lấy giá trị của một biến được chỉ định
- `#{...}`: Lấy message
- `@{...}`: Lấy đường dẫn URL dựa theo context của server

## Biểu thức `${...}` - Truy cập Giá Trị Biến

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

Biểu thức `${...}` cho phép bạn truy cập giá trị biến trong phạm vi của Context hoặc Model.

## Biểu thức `*{...}` - Truy cập Giá Trị Biến trên các Phần Tử

Biểu thức `*{...}`, còn được gọi là `asterisk syntax`, có chức năng giống `${...}`, tức là lấy giá trị của một biến. Tuy nhiên, nó sẽ lấy giá trị của biến trong ngữ cảnh của `th:object`.

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

## Biểu thức `#{...}` - Lấy Thông Báo (Message)

Ví dụ, trong tệp cấu hình `.properties` của bạn, bạn có một thông báo chào đón người dùng bằng nhiều ngôn ngữ:

```java
home.welcome=Hello bạn
```

Thì cách lấy nó ra nhanh nhất là:

```html
<p th:utext="#{home.welcome}">Xin chào các bạn!</p>
```

Đoạn văn bản tiếng Việt bên trong thẻ `p` sẽ bị thay thế bởi Thymeleaf khi render `#{home.welcome}`. Điều này cho phép bạn tạo các ứng dụng hỗ trợ nhiều ngôn ngữ một cách dễ dàng.

## Biểu thức `@{...}` - Lấy URL Dựa Trên Ngữ Cảnh Máy Chủ

`@{...}` xử lý và trả về giá trị URL dựa trên ngữ cảnh của máy chủ. Bạn có thể sử dụng nó để tạo các liên kết URL động.

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

::alert{type="success"}

Qua bài viết này, bạn đã biết cách sử dụng Thymeleaf Standard Expression để truy cập và hiển thị thông tin từ `Model`, lấy các thông báo đa ngôn ngữ và tạo các liên kết URL động. Sử dụng những biểu thức này, bạn có thể làm cho ứng dụng web của mình trở nên mạnh mẽ và linh hoạt hơn.

::
