---
title: "Câu lệnh điều kiện th:if, th:switch th:case trong Thymeleaf"
description: "Câu lệnh điều kiện th:if, th:switch. th:case trong Thymeleaf"
chapter:
  name: "Thymeleaf"
  slug: "chuong-04-thymeleaf"
image: https://kungfutech.edu.vn/thumbnail.png
position: 4
---

Trong việc phát triển ứng dụng web, việc hiển thị nội dung dựa trên các điều kiện là một phần quan trọng. Thymeleaf, một Java Template Engine mạnh mẽ, cung cấp cho chúng ta các công cụ mạnh mẽ để thực hiện điều này. Trong bài viết này, chúng ta sẽ tìm hiểu cách sử dụng câu lệnh điều kiện `th:if`, cùng với câu lệnh `th:switch` và `th:case` để làm cho việc kiểm soát dữ liệu trên trang web trở nên đơn giản và hiệu quả.

## Câu lệnh `th:if` - Điều kiện Đơn giản

Câu lệnh `th:if` trong Thymeleaf cho phép bạn thực hiện các kiểm tra điều kiện đơn giản trên dữ liệu và hiển thị hoặc ẩn nội dung dựa trên kết quả của kiểm tra này. Dưới đây là cách bạn có thể sử dụng nó:

```html
<p th:if="${user.isAdmin()}">This user is an admin.</p>
```

Trong ví dụ này, chúng ta kiểm tra xem đối tượng `user` có phải là một quản trị viên không. Nếu điều kiện trả về `true`, nội dung bên trong thẻ `<p>` sẽ được hiển thị. Ngược lại, nếu điều kiện trả về `false`, nội dung sẽ bị ẩn đi.

## Câu lệnh `th:switch` và `th:case` - Điều kiện Nhiều Lựa chọn

Câu lệnh `th:switch` và `th:case` giúp bạn xử lý nhiều lựa chọn và hiển thị nội dung tương ứng với lựa chọn đã chọn. Dưới đây là cách sử dụng chúng:

```html
<div th:switch="${user.role}">
  <p th:case="'ADMIN'">Welcome, Admin!</p>
  <p th:case="'USER'">Welcome, User!</p>
  <p th:case="*">Unknown Role</p>
</div>
```

- Trong ví dụ này, chúng ta kiểm tra giá trị của thuộc tính `role` của đối tượng `user`.
- Nếu giá trị là `'ADMIN'`, câu lệnh `th:case="'ADMIN'"` sẽ hiển thị "Welcome, Admin!".
- Nếu giá trị là `'USER'`, câu lệnh `th:case="'USER'"` sẽ hiển thị "Welcome, User!".
- Nếu không khớp với bất kỳ trường hợp nào, câu lệnh `th:case="*"` cuối cùng sẽ hiển thị "Unknown Role".

## Kết hợp Với Biến và Vòng Lặp

Các câu lệnh điều kiện này có thể kết hợp với biến và vòng lặp để tạo ra các tình huống phức tạp hơn. Dưới đây là một ví dụ:

```html
<div th:if="${not empty users}">
  <ul>
    <li th:each="user : ${users}">
      <span
        th:if="${user.isAdmin()}"
        th:text="${user.name + ' (Admin)'}"
      ></span>
      <span
        th:unless="${user.isAdmin()}"
        th:text="${user.name + ' (User)'}"
      ></span>
    </li>
  </ul>
</div>
```

- Trong ví dụ này, chúng ta kiểm tra xem danh sách `users` có phần tử nào không.
- Nếu danh sách không trống, chúng ta duyệt qua từng `user` trong danh sách.
- Với mỗi `user`, chúng ta kiểm tra xem họ có phải là admin không, và hiển thị tên của họ với tên vai trò tương ứng.

::alert{type="success"}

Các câu lệnh điều kiện `th:if`, `th:switch`, và `th:case` trong Thymeleaf cho phép bạn kiểm soát việc hiển thị nội dung dựa trên điều kiện và tạo ra các trang web phức tạp dễ dàng hơn. Sử dụng chúng, bạn có thể tùy chỉnh trải nghiệm người dùng và hiển thị dữ liệu theo cách linh hoạt và hiệu quả. Điều này làm cho việc phát triển ứng dụng web trở nên mạnh mẽ và dễ dàng hơn bao giờ hết.

::
