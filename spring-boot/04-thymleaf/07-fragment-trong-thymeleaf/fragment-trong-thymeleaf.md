---
title: "Fragment trong Thymeleaf"
description: "Fragments là một khái niệm mạnh mẽ trong Thymeleaf, một Java Template Engine phổ biến cho phát triển web. Fragments cho phép bạn tái sử dụng các phần của trang web của bạn, giúp tạo ra giao diện thú vị, dễ quản lý và hiệu quả"
chapter:
  name: "Thymeleaf"
  slug: "chuong-04-thymeleaf"
image: https://kungfutech.edu.vn/thumbnail.png
position: 7
---

Fragments là một khái niệm mạnh mẽ trong Thymeleaf, một Java Template Engine phổ biến cho phát triển web. Fragments cho phép bạn tái sử dụng các phần của trang web của bạn, giúp tạo ra giao diện thú vị, dễ quản lý và hiệu quả. Trong bài viết này, chúng ta sẽ tìm hiểu về fragments trong Thymeleaf và cách chúng có thể cải thiện quá trình phát triển trang web của bạn.

## Fragment là gì?

Trong Thymeleaf, fragment là một phần của trang web, chẳng hạn như header, footer, menu, hoặc bất kỳ phần nào bạn muốn tái sử dụng. Fragments cho phép bạn đóng gói các phần này thành các module độc lập mà bạn có thể sử dụng lại trên nhiều trang web khác nhau. Điều này giúp giảm lặp lại mã nguồn và tạo ra các trang web dễ bảo trì.

## Cách Sử Dụng Fragments trong Thymeleaf

### Định nghĩa Fragment

Để bắt đầu sử dụng fragments, bạn cần định nghĩa chúng trong các tệp template HTML của bạn. Điều này thường được thực hiện bằng cách sử dụng các thuộc tính đặc biệt của Thymeleaf như `th:fragment`:

```html
<!-- Trong header.html -->
<div th:fragment="header">
  <!-- Nội dung của header -->
</div>

<!-- Trong footer.html -->
<div th:fragment="footer">
  <!-- Nội dung của footer -->
</div>
```

### Sử dụng Fragment

Khi bạn đã định nghĩa các fragment, bạn có thể sử dụng chúng trong các trang web khác nhau bằng cách sử dụng các hàm `th:replace`, `th:include`, hoặc `th:insert`. Ví dụ:

```html
<!-- Trong trang web index.html -->
<!DOCTYPE html>
<html>
  <head>
    <title>Trang Chủ</title>
  </head>
  <body>
    <header th:replace="fragments/header :: header"></header>

    <div class="content">
      <!-- Nội dung của trang web -->
    </div>

    <footer th:replace="fragments/footer :: footer"></footer>
  </body>
</html>
```

Trong ví dụ trên, chúng ta sử dụng `th:replace` để thay thế nội dung của thẻ `header` và `footer` bằng các fragment tương ứng.

## Lợi Ích của Fragments

Sử dụng fragments trong Thymeleaf mang lại nhiều lợi ích quan trọng:

### Tái sử dụng

Bạn có thể tái sử dụng các phần giao diện trên nhiều trang web khác nhau, giúp giảm lặp lại mã nguồn và tiết kiệm thời gian phát triển.

### Quản lý dễ dàng

Fragments giúp bạn quản lý các phần của trang web một cách dễ dàng. Bạn có thể chỉnh sửa hoặc cập nhật một fragment mà không ảnh hưởng đến các trang web khác.

### Mã sạch hơn

Việc chia nhỏ trang web thành các fragment giúp làm cho mã nguồn trở nên sạch sẽ và dễ đọc hơn.

::alert{type="success"}

Fragments là một tính năng mạnh mẽ trong Thymeleaf cho phép bạn tạo ra các trang web tích hợp và dễ quản lý. Bằng cách định nghĩa và sử dụng fragments, bạn có thể giảm thiểu lặp lại mã nguồn, tạo ra các trang web linh hoạt và tiết kiệm thời gian trong quá trình phát triển. Hãy sử dụng fragments để cải thiện quá trình phát triển trang web của bạn và tạo ra các trang web đẹp và dễ bảo trì.

::
