---
title: "Biến trong Thymeleaf"
description: "Biến trong Thymeleaf là một khía cạnh quan trọng khi bạn xây dựng các trang web động và muốn hiển thị dữ liệu từ máy chủ Java của bạn lên trang web của bạn"
chapter:
  name: "Thymeleaf"
  slug: "chuong-04-thymeleaf"
image: https://kungfutech.edu.vn/thumbnail.png
position: 2
---

Biến trong Thymeleaf là một khía cạnh quan trọng khi bạn xây dựng các trang web động và muốn hiển thị dữ liệu từ máy chủ Java của bạn lên trang web của bạn. Trong bài viết này, chúng ta sẽ tìm hiểu cách sử dụng biến trong Thymeleaf để hiển thị dữ liệu và làm cho trang web của bạn trở nên phong phú hơn.

## Thymeleaf - Một Java Template Engine

Trước khi chúng ta bắt đầu, hãy nhớ rằng Thymeleaf là một Java Template Engine. Nó cho phép bạn kết hợp mã Java và giao diện người dùng một cách hiệu quả. Thymeleaf sử dụng các biến để truyền dữ liệu từ phía máy chủ Java sang mã HTML, làm cho trang web của bạn trở nên linh hoạt và đáng tin cậy.

## Định nghĩa Biến trong Thymeleaf

Trong Thymeleaf, bạn có thể định nghĩa biến bằng cách sử dụng cú pháp `th:object` hoặc `th:field`. Dưới đây là cách bạn có thể sử dụng chúng:

### Biến đối tượng (`th:object`)

Biến đối tượng cho phép bạn đặt một đối tượng Java vào phạm vi của Thymeleaf. Ví dụ, nếu bạn có một đối tượng `Person` với thuộc tính `name`, bạn có thể sử dụng `th:object` như sau:

```html
<div th:object="${person}">
  <p>Name: <span th:text="*{name}"></span></p>
</div>
```

Ở đây, `${person}` đại diện cho đối tượng `Person`, và bạn có thể truy cập thuộc tính `name` của nó bằng cách sử dụng `*{name}`.

### Biến trường (`th:field`)

Biến trường làm cho việc xử lý các trường dữ liệu trong các biểu mẫu HTML trở nên dễ dàng hơn. Ví dụ, nếu bạn có một biểu mẫu đăng ký với trường `username`, bạn có thể sử dụng `th:field` như sau:

```html
<form th:object="${user}" th:action="@{/register}" method="post">
  <label for="username">Username:</label>
  <input type="text" id="username" th:field="*{username}" />
</form>
```

Trong trường này, `${user}` đại diện cho đối tượng `User`, và `*{username}` là cách Thymeleaf liên kết trường `username` trong biểu mẫu HTML với thuộc tính `username` của đối tượng `User`.

## Hiển thị Giá trị Biến

Khi bạn đã định nghĩa biến trong Thymeleaf, bạn có thể hiển thị giá trị của chúng bằng cách sử dụng các thuộc tính Thymeleaf như `th:text`, `th:value`, `th:src`, và nhiều thuộc tính khác. Dưới đây là một số ví dụ:

### Hiển thị giá trị văn bản (`th:text`)

```html
<p th:text="${user.name}"></p>
```

Trong ví dụ này, `th:text` sẽ hiển thị giá trị của thuộc tính `name` của đối tượng `user`.

### Gán giá trị vào trường (`th:value`)

```html
<input type="text" th:value="${user.email}" />
```

`th:value` cho phép bạn gán giá trị của thuộc tính `email` vào trường nhập liệu.

## Điều kiện và Vòng lặp

Thymeleaf cung cấp cách mạnh mẽ để sử dụng biến trong các biểu thức điều kiện và vòng lặp. Bạn có thể kiểm tra điều kiện, duyệt qua danh sách và hiển thị các phần tử tùy thuộc vào giá trị của biến.

### Ví dụ về Điều kiện

```html
<p th:if="${user.isAdmin()}">This user is an admin.</p>
```

Trong ví dụ này, `th:if` sẽ kiểm tra xem đối tượng `user` có phải là admin hay không.

### Ví dụ về Vòng lặp

```html
<ul>
  <li th:each="item : ${items}" th:text="${item}"></li>
</ul>
```

Với `th:each`, bạn có thể duyệt qua danh sách `items` và hiển thị mỗi phần tử trong danh sách.

::alert{type="success"}

Biến trong Thymeleaf cho phép bạn tạo ra các trang web động và tương tác bằng cách truyền dữ liệu từ máy chủ Java của bạn vào giao diện người dùng. Bằng cách sử dụng cú pháp Thymeleaf và các thuộc tính như `th:text`, `th:if`, và `th:each`, bạn có thể hiển thị dữ liệu theo cách linh hoạt và dễ dàng. Điều này làm cho việc phát triển ứng dụng web trở nên dễ dàng và mạnh mẽ hơn bao giờ hết.

::
