---
title: "Chương trình Javascript đầu tiên"
description: "Chương trình Javascript đầu tiên trong javascript, chúng ta cùng tìm hiểu nhé"
keywords:
  [
    "javascript",
    "Chương trình Javascript đầu tiên",
    "khoá học javascript",
    "giới thiệu javascript",
    "Javascript là gì",
    "html css javascript co ban",
    "cach su dung javascript",
    "code javascript bang gi",
    "Tạo chương trình javascript đơn giản",
    "chương trình javascript cho người mới bắt đầu",
    "hoc javascript"
  ]
chapter:
  name: "Javascript cơ bản"
  slug: "chuong-02-javascript-co-ban"
category:
  name: "Javascript"
  slug: "javascript"
image: https://kungfutech.edu.vn/thumbnail.png
position: 1
---

Trong toàn bộ khoá học này, chúng ta sẽ chỉ sử dụng Javascript là ngôn ngữ xây dựng ứng dụng client (front-end) trên trình duyệt.

## Hello World JavaScript Console

Cách đơn giản nhất để viết và chạy chương trình JavaScript đầu tiên là sử dụng tiện ích console của Dev Tools trên trình duyệt.

Tùy thuộc vào trình duyệt bạn đang sử dụng, bạn có thể nhấn **F12** hoặc tổ hợp phím **Ctrl Shift I** (Windows) hoặc **Ctrl Opt J** (macOS),...

Sau đó, bạn chọn tab **console** rồi gõ lệnh sau: `console.log("JavaScript Helloworld")`. Tiếp theo, bạn nhấn **Enter** (để viết nhiều dòng code, bạn nhấn tổ hợp **Shift Enter**).

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>JavaScript Helloworld</code><br/>
  </div>
</div>

### Console.log là gì?

`Console.log` trong JavaScript là một hàm được sử dụng để in ra bất kể thứ gì (với trình duyệt thì nơi hiển thị kết quả đó là tab console của Dev Tools).

Bạn sẽ không cần phải cài đặt thêm bất cứ phần mềm nào khác. Bạn chỉ cần mở trình duyệt, vừa đọc hướng dẫn và thực hành trên tab console của Dev Tools.

Sau khi bạn đã nắm hết kiến thức cơ bản về ngôn ngữ JavaScript, mình sẽ bắt đầu học về trình duyệt, HTML, và cách JavaScript giao tiếp với HTML,...

## Chương trình JavaScript đầu tiên với HTML

Để chạy một chương trình Javascript, bạn cần đưa mã JS vào trong một trong HTML.

## Viết mã lệnh trực tiếp vào trang web

Bạn đặt toàn bộ mã Javascript vào trong thẻ `<script>`. Điều này giúp trình duyệt phân biệt mã JS với phần còn lại. Ngoài ra, vì có các ngôn ngữ kịch bản cho client khác nữa (ví dụ: VBScript...), do đó, bạn nên chỉ định ngôn ngữ kịch bản mà bạn sử dụng trong thẻ `<script>`, kiểu như sau:

```html
<script type="text/javascript">
```

Bạn tạo mới một tệp `html` đặt tên là `index.html`, có nội dung như sau:

```html
<html lang="en">
  <head>
    <meta charset="UTF-8" />
    <title>Học lập trình Javascript </title>
  </head>
  <body>
    <h2>Xin chào độc giả kungfutech</h2>
    <span id="content"></span>
  </body>
  <script type="text/javascript">
    document.getElementById("content").innerHTML = "Học lập trình Javascript ";
  </script> </html
>;
```

Bạn lưu lại và mở tệp lên bằng trình duyệt. Đây là kết quả thu được

## Viết mã lệnh JavaScript vào tập tin JavaScript

Với cách viết Javascript trực tiếp vào trong HTML sẽ khiến cho mã nguồn trở nên "rối rắm", đặc biệt khi dự án ngày càng trở nên phức tạp. Đặc biệt là trong trường hợp chúng ta muốn xây dựng các plugin/module bằng javascript, tách biệt với HTML.

Chúng ta sẽ tách mã JS ra khỏi HTML, và chỉ nhúng đường dẫn trỏ tới tệp `.js` trong HTML mà thôi.

```html
<html lang="en">
  <head>
    <meta charset="UTF-8" />
    <title>Sách học lập trình Javascript</title>
  </head>
  <body>
    <h2>Xin chào độc giả kungfutech</h2>
    <span id="content"></span>
  </body>
  <script src="src/index.js"></script> </html
>;
```

Còn nội dung tệp `index.js` như sau:

```js
document.getElementById("content").innerHTML =
  "Tài liệu học Javascript toàn tập";
```

## Sử dụng IDE online.

Để học Javascript, thay vì sử dụng hai cách trên, mình thường tìm tới các Text Editor Online để viết và chạy thử chương trình Javascript được nhanh và trực quan nhất.

Một số Text Editor Online gợi ý cho bạn:

- [Codesandbox.io](https://codesandbox.io/)
- [Playcode.io](https://playcode.io/)
- [Jsfiddle.net](https://jsfiddle.net/)

Ưu điểm của những trình Text Editor Online này là dễ sử dụng, được tích hợp sẵn mọi thứ, không cần cài đặt thêm gì cả. Việc của bạn chỉ là gõ code và chạy

Đọc đến đây, minh hi vọng bạn đã hiểu được phần nào về ngôn ngữ lập trình Javascript, biết cách tạo một ứng dụng đơn giản với Javascript. Phần tiếp theo, chúng ta sẽ cùng nhau tìm hiểu các cú pháp từ cơ bản tới nâng cao của Javascript nhé
