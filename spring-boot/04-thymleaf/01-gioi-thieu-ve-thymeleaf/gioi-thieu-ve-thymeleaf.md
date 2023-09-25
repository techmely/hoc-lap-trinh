---
title: "Giới thiệu về Thymeleaf"
description: "Thymeleaf là một Java Template Engine có nhiệm vụ xử lý và tạo ra các tệp HTML, XML, v.v. Các tệp HTML được tạo ra bởi Thymeleaf dựa trên sự kết hợp giữa dữ liệu và các mẫu (templates) cùng với các quy tắc được định sẵn."
chapter:
  name: "Thymeleaf"
  slug: "chuong-04-thymeleaf"
category:
  name: "Spring Boot"
  slug: "spring-boot"
image: https://kungfutech.edu.vn/thumbnail.png
position: 1
---

## Thymeleaf là gì?

Thymeleaf là một thư viện mã nguồn mở và được coi là một Java Template Engine, được sử dụng để xử lý và tạo ra các trang HTML, XML, JavaScript, CSS, text, và raw content. Nó có khả năng làm việc cả trong môi trường web và môi trường không phải là web. Mục tiêu chính của Thymeleaf là tạo ra các template đơn giản và dễ bảo trì để phát triển giao diện.

![Giới thiệu về Thymeleaf](https://github.com/techmely/hoc-lap-trinh/assets/29374426/b11aaeb5-f5ac-46a8-89e9-00a9d499dad6)

## Ưu điểm của Thymeleaf

### Sử dụng HTML làm View

Thymeleaf sử dụng các thẻ HTML làm view và tích hợp trực tiếp vào các tệp HTML. Điều này đồng nghĩa rằng bạn không cần phải thêm các thẻ "non-HTML" vào tệp HTML của mình. Ví dụ, khi bạn sử dụng JSP, bạn cần phải sử dụng thẻ `JSTL` và khai báo `taglib`. Tuy nhiên, với Thymeleaf, bạn chỉ cần sử dụng các thẻ HTML chuẩn mà không cần thêm bất kỳ thẻ nào khác.

### Tự động làm mới Giao diện

Thường, để thấy sự thay đổi trên giao diện của một trang web, bạn cần phải làm mới lại trình duyệt. Thymeleaf cho phép bạn xem các thay đổi trên giao diện mà không cần phải tải lại trang web. Điều này giúp tăng hiệu suất phát triển và giúp bạn thấy các thay đổi ngay lập tức.

## Các loại template của Thymeleaf

Thymeleaf cho phép xử lý sáu loại template khác nhau, mỗi loại được gọi là một chế độ template:

### HTML Template

Chế độ template HTML cho phép bạn làm việc với các tệp HTML chuẩn như HTML5, HTML4 và XHTML. Thymeleaf kiểm tra tính hợp lệ và tính đúng đắn của các tệp này, và cấu trúc template (hoặc mã template) được ưu tiên ở mức độ cao nhất trong đầu ra.

### XML Template

Chế độ template XML cho phép bạn xử lý các tệp XML. Trình phân tích cú pháp sẽ báo lỗi nếu tệp XML vi phạm các quy tắc cú pháp như thiếu thẻ mở/đóng, thiếu dấu `< >`, thiếu thuộc tính, vv. Tuy nhiên, trình phân tích cú pháp không áp dụng với DTD hoặc schema.

### Text Template

Chế độ template Text cho phép bạn sử dụng cú pháp đặc biệt cho các template không chứa đánh dấu (markup). Ví dụ về các template như vậy có thể là email hoặc các tài liệu thông thường.

::alert{type="warning"}
Các template HTML hoặc XML cũng có thể được xử lý dưới dạng Text, trong trường hợp này, chúng sẽ không được coi là chứa đánh dấu (markup), và tất cả các thẻ, DOCTYPE, comment, vv. sẽ được coi là văn bản thuần túy.
::

### Javascript Template

Chế độ template Javascript cho phép bạn xử lý các tệp Javascript trong ứng dụng Thymeleaf. Điều này có nghĩa là bạn có thể sử dụng dữ liệu mô hình trong các tệp Javascript giống như cách bạn làm trong các tệp HTML. Chế độ template Javascript cũng được coi là văn bản và sử dụng cú pháp đặc biệt giống với chế độ template Text.

### CSS Template

Chế độ template CSS cho phép xử lý các tệp CSS liên quan đến ứng dụng Thymeleaf. Tương tự như chế độ template Javascript, chế độ template CSS cũng là một chế độ văn bản và sử dụng cú pháp xử lý đặc biệt từ chế độ template Text.

### RAW Template

Chế độ template RAW đơn giản là không xử lý các template. Điều này có nghĩa là nó được sử dụng để chèn các tài nguyên không bị ảnh hưởng (tệp, URL phản hồi, vv.) vào các template đang được xử lý. Ví dụ, các tài nguyên bên ngoài, không được kiểm soát và không phải là định dạng HTML, có thể được đưa vào các template ứng dụng Thymeleaf mà không cần phải thực hiện bất kỳ mã Thymeleaf nào.

::alert{type="success"}
Thymeleaf là một thư viện mạnh mẽ cho việc tạo và xử lý các template trong các ứng dụng Java. Nó cho phép bạn tạo các giao diện động và dễ bảo trì mà không cần phải thêm các thẻ "non-HTML" vào tệp HTML của bạn.
::
