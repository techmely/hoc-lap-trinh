---
title: "Vòng lặp trong Thymeleaf"
description: "Với vòng lặp, bạn có khả năng lặp qua danh sách các đối tượng và hiển thị chúng trên trang web của mình một cách dễ dàng và hiệu quả"
chapter:
  name: "Thymeleaf"
  slug: "chuong-04-thymeleaf"
category:
  name: "Spring Boot"
  slug: "spring-boot"
image: https://kungfutech.edu.vn/thumbnail.png
position: 8
---

Vòng lặp là một khía cạnh quan trọng của Thymeleaf, một Java Template Engine phổ biến trong phát triển web. Với vòng lặp, bạn có khả năng lặp qua danh sách các đối tượng và hiển thị chúng trên trang web của mình một cách dễ dàng và hiệu quả. Trong bài viết này, chúng ta sẽ tìm hiểu về cách sử dụng vòng lặp trong Thymeleaf và tại sao chúng lại quan trọng.

## Sử Dụng Vòng Lặp Trong Thymeleaf

### Cú Pháp Cơ Bản

Thymeleaf cung cấp một số cú pháp để bạn có thể lặp qua danh sách đối tượng hoặc tập hợp. Cú pháp cơ bản nhất là sử dụng `th:each`. Ví dụ:

```html
<ul>
  <li th:each="item : ${items}">
    <span th:text="${item}"></span>
  </li>
</ul>
```

Trong đoạn mã trên, chúng ta đang lặp qua danh sách `items` và hiển thị mỗi phần tử trong danh sách như một mục danh sách (`<li>`).

### Sử Dụng Với Đối Tượng

Ngoài việc lặp qua danh sách cơ bản, bạn cũng có thể lặp qua các thuộc tính của một đối tượng. Ví dụ:

```html
<table>
  <tr th:each="user : ${users}">
    <td th:text="${user.name}"></td>
    <td th:text="${user.email}"></td>
  </tr>
</table>
```

Ở đây, chúng ta lặp qua danh sách các đối tượng `user` và hiển thị thông tin `name` và `email` của mỗi người dùng trong bảng.

### Sử Dụng Index

Thymeleaf cung cấp cách để bạn truy cập chỉ số của phần tử trong vòng lặp. Ví dụ:

```html
<ul>
  <li th:each="item, iterStat : ${items}">
    <span th:text="${iterStat.index}"></span>:
    <span th:text="${item}"></span>
  </li>
</ul>
```

Trong ví dụ này, chúng ta sử dụng biến `iterStat.index` để hiển thị chỉ số của mỗi phần tử.

## Lợi Ích của Vòng Lặp trong Thymeleaf

### Hiển Thị Dữ Liệu Đa Dạng

Vòng lặp cho phép bạn hiển thị dữ liệu từ các danh sách, tập hợp hoặc đối tượng một cách dễ dàng. Điều này giúp bạn xây dựng các trang web đa dạng và động.

### Tiết Kiệm Thời Gian và Mã Nguồn

Thay vì viết mã HTML tĩnh cho mỗi phần tử trong danh sách, bạn có thể sử dụng vòng lặp để tạo mã nguồn linh hoạt và tiết kiệm thời gian.

### Dễ Bảo Trì

Vòng lặp giúp làm cho mã nguồn của bạn dễ bảo trì hơn. Khi bạn cần thay đổi cách hiển thị các phần tử, bạn chỉ cần chỉnh sửa một phần của mã thay vì phải thay đổi từng phần tử riêng lẻ.

::alert{type="success"}
Vòng lặp là một tính năng quan trọng trong Thymeleaf cho phép bạn tận dụng sức mạnh động của trang web. Bằng cách sử dụng vòng lặp, bạn có thể hiển thị dữ liệu một cách hiệu quả, tiết kiệm thời gian và làm cho mã nguồn của bạn dễ bảo trì hơn. Hãy khám phá cách sử dụng vòng lặp trong Thymeleaf để xây dựng các trang web động và linh hoạt hơn.
::
