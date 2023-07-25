---
title: "Giới thiệu về Thymeleaf"
description: "Thymeleaf một một thư viện mở và được coi là một Java Template Engine,
được dùng để xử lý và tạo ra HTML, XML, JavaScript, CSS, text, Raw, nó có thể
làm việc với cả môi trường web và non-web"
keywords:
  [
    "khóa học Spring cơ bản",
    "Giới thiệu thymeleaf",
    "Thymeleaf là gì",
    "hướng dẫn thymeleaf",
    "thymeleaf cơ bản",
    "Ưu điểm của thymeleaf",
    "Nhược điểm của thymeleaf",
    "phân loại template thymeleaf",
    "xml template trong thymeleaf",
    "html template trong thymeleaf",
    "javascript template trong thymeleaf",
    "css template trong thymeleaf",
    "raw template trong thymeleaf"
  ]
chapter:
  name: "Thymeleaf"
  slug: "chuong-05-thymeleaf"
category:
  name: "Spring Boot"
  slug: "spring-boot"
image: https://kungfutech.edu.vn/thumbnail.png
position: 1
---


![Thymeleaf](https://github.com/techmely/hoc-lap-trinh/assets/29374426/b11aaeb5-f5ac-46a8-89e9-00a9d499dad6)

## Thymeleaf là gì?

`Thymeleaf` một một thư viện mở và được coi là một **_Java Template Engine_**,
được dùng để xử lý và tạo ra **HTML**, **XML**, **JavaScript**, **CSS**, **text**, **Raw**, nó có thể
làm việc với cả môi trường web và non-web.
Mục tiêu chính của `Thymeleaf` là mong muốn tạo ra các template đơn giản,
dễ bảo trì cho các công việc phát triển giao diện.

## Ưu điểm của Thymeleaf

`Thymeleaf` sử dụng các thẻ **HTML** làm view và tham gia vào file html dưới
dạng các thuộc tính của các thẻ html. Do đó không cần phải thêm bất cứ loại thẻ
**non-HTML** nào cả. Ví dụ với **JSP** nếu muốn sử dụng các thẻ chuẩn của jsp như **JSTL**
thì cần có taglib, thới `Thymeleaf` thì không cần sử dụng bất kỳ loại thẻ nào
khác html nên được gọi là **non-HTML**.

Thông thường với các view như jsp, jsf muốn nhìn thấy được sự thay đổi
của giao diện phải nhấn refresh lại trang web. Với `Thymeleaf` ta có thể xem các
thay đổi trên giao diện mà không cần tải lại trang

## Các loại template của Thymeleaf

`Thymeleaf` cho phép bạn xử lý 6 loại template, mỗi loại được gọi là một
chế độ template bao gồm:

- HTML
- XML
- TEXT
- JAVASCRIPT
- CSS
- RAW

### HTML Template

Template này cho phép bất kỳ loại đầu vào là các file **HTML** như
**HTML5, HTML4 và XHTML**. Việc kiểm tra tính hợp lệ hoặc tính đúng đắn sẽ được
thực hiện và cấu trúc mẫu (hoặc code mẫu) sẽ được ưu tiên ở mức độ cao nhất
trong đầu ra.

### XML Template

cho phép đầu vào là các file **XML**. Trình phân tích cú
pháp sẽ ném ra lỗi khi file **XML** vi phạm các lỗi như thiếu thẻ đóng/mở, thiếu
dấu <>, thiếu thuộc tính v.v. Tuy nhiên trình phân tích cú pháp không áp
dụng với **DTD hoặc schema**.

### Text Template

cho phép sử dụng cú pháp đặc biệt cho các template
không đánh dấu (markup). Ví dụ về các template như vậy có thể là email hoặc các
tài liệu thông thường.
Lưu ý rằng, các template **HTML hoặc XML** cũng có thể được xử lý dưới dạng
**TEXT**, trong trường hợp này, chúng sẽ không được coi là đánh dấu (markup) và tất
cả các thẻ, DOCTYPE, comment, v.v. sẽ được coi là văn bản thuần túy.

### Javascript Template

cho phép xử lý các tệp **JavaScript** trong ứng dụng
`Thymeleaf`. Điều này có nghĩa là có thể sử dụng dữ liệu mô hình bên trong các
tệp **JavaScript** theo cùng cách thực hiện trong các tệp **HTML**. Chế độ template
**JAVASCRIPT** được coi là văn bản và do đó, nó sử dụng cú pháp đặc biệt giống như
chế độ template **TEXT**.

### CSS Template

Template này sẽ cho phép xử lý các tệp **CSS** liên quan đến ứng dụng
`Thymeleaf`. Tương tự như chế độ template **JAVASCRIPT**, chế độ template **CSS** cũng là
một chế độ văn bản và sử dụng cú pháp xử lý đặc biệt từ chế độ template **TEXT**.

### RAW Template

Template này đơn giản là không xử lý các template. Có nghĩa là, nó được sử dụng để
chèn các tài nguyên không bị ảnh hưởng (tệp, phản hồi URL, v.v.) vào các
template đang được xử lý.
Ví dụ, các tài nguyên bên ngoài, không được kiểm soát
ở định dạng **HTML** có thể được đưa vào các template ứng dụng, sẽ là an toàn khi
biết rằng bất kỳ mã `Thymeleaf` nào mà các tài nguyên này có thể include sẽ không
được thực hiện.
