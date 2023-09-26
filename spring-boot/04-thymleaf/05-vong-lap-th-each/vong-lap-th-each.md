---
title: "Vòng lặp th:each trong Thymeleaf"
description: "Trong bài viết này, chúng ta sẽ tìm hiểu về cú pháp th:each trong Thymeleaf, cùng với các ví dụ minh họa"
chapter:
  name: "Thymeleaf"
  slug: "chuong-04-thymeleaf"
image: https://kungfutech.edu.vn/thumbnail.png
position: 5
---

Vòng lặp là một phần quan trọng của việc hiển thị dữ liệu trong ứng dụng web. Thymeleaf, một Java Template Engine phổ biến, cung cấp cú pháp mạnh mẽ để bạn có thể dễ dàng lặp qua danh sách dữ liệu và hiển thị chúng trên trang web. Trong bài viết này, chúng ta sẽ tìm hiểu về cú pháp `th:each` trong Thymeleaf, cùng với các ví dụ minh họa.

## Vòng Lặp `th:each` Là Gì?

`th:each` là một cú pháp trong Thymeleaf cho phép bạn lặp qua danh sách hoặc bất kỳ tập hợp dữ liệu nào, và áp dụng một phần tử HTML cho mỗi phần tử trong danh sách. Điều này rất hữu ích khi bạn muốn hiển thị danh sách sản phẩm, bài viết, hoặc bất kỳ loại dữ liệu lặp lại nào trên trang web của bạn.

Dưới đây là cú pháp cơ bản của `th:each`:

```html
<div th:each="item : ${items}">
  <!-- Nội dung bạn muốn hiển thị cho mỗi item -->
</div>
```

Trong đó:

- `"item"` là biến mà bạn sẽ sử dụng để tham chiếu đến mỗi phần tử trong danh sách.
- `"${items}"` là danh sách hoặc tập hợp dữ liệu bạn muốn lặp qua.

## Ví dụ về Vòng Lặp `th:each`

### Lặp qua Danh Sách Sản Phẩm

Dưới đây là một ví dụ về cách bạn có thể sử dụng `th:each` để hiển thị danh sách sản phẩm:

```html
<ul>
  <li th:each="product : ${products}">
    <span th:text="${product.name}"></span>:
    <span th:text="${product.price}"></span> USD
  </li>
</ul>
```

Trong ví dụ này, chúng ta lặp qua danh sách `products` và hiển thị tên và giá của mỗi sản phẩm trong danh sách.

### Lặp qua Danh Sách Người Dùng

Dưới đây là một ví dụ về cách bạn có thể sử dụng `th:each` để hiển thị danh sách người dùng:

```html
<table>
  <tr>
    <th>Name</th>
    <th>Email</th>
  </tr>
  <tr th:each="user : ${users}">
    <td th:text="${user.name}"></td>
    <td th:text="${user.email}"></td>
  </tr>
</table>
```

Ở đây, chúng ta tạo một bảng để hiển thị danh sách người dùng với các cột "Name" và "Email".

## Sử Dụng Vòng Lặp `th:each` Với Điều Kiện

Ngoài việc lặp qua danh sách, bạn cũng có thể kết hợp `th:each` với câu lệnh điều kiện `th:if` để hiển thị dữ liệu dựa trên điều kiện cụ thể. Ví dụ:

```html
<ul>
  <li th:each="product : ${products}" th:if="${product.inStock}">
    <span th:text="${product.name}"></span>:
    <span th:text="${product.price}"></span> USD
  </li>
</ul>
```

Trong ví dụ này, chúng ta chỉ hiển thị các sản phẩm có sẵn trong kho (có thuộc tính `inStock` là `true`).

::alert{type="success"}

Vòng lặp `th:each` trong Thymeleaf là một công cụ mạnh mẽ để hiển thị danh sách dữ liệu trên trang web của bạn một cách dễ dàng và linh hoạt. Bạn có thể lặp qua bất kỳ danh sách nào và hiển thị nội dung một cách tùy chỉnh. Kết hợp với các câu lệnh điều kiện, bạn có thể kiểm soát việc hiển thị dữ liệu dựa trên các điều kiện cụ thể. Sử dụng cú pháp `th:each`, bạn có thể tạo ra các trang web động và phong phú một cách dễ dàng.

::
