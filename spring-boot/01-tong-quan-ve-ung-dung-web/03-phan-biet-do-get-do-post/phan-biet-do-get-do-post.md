---
title: "Phân biệt giữa Get và Post"
description: "GET và POST là hai kỹ thuật phổ biến để gửi dữ liệu đến server và browser cần chúng để giao tiếp với server. Hai phương thức này khác biệt ở chỗ phương thức GET thêm dữ liệu được mã hóa vào URI trong khi trong với phương thức POST, dữ liệu được nối vào phần body chứ không phải URI."
keywords:
  [
    "Phân biệt giữa Get và Post",
    "post la gi",
    "get la gi",
    "get va post trong springboot",
    "get data la gi",
    "put va post khac nhau nhu the nao",
    "du ieu truyen di bang phuong thuc get",
    "du ieu truyen di bang phuong thuc post",
  ]
chapter:
  name: "Tổng quan về ứng dụng web"
  slug: "chuong-01-tong-quan-ve-ung-dung-web"
category:
  name: "Spring Boot"
  slug: "spring-boot"
image: https://kungfutech.edu.vn/thumbnail.png
position: 3
---

## Phân biệt giữa Get và Post

POST VÀ GET khác nhau như thế nào?

Trên đây là câu hỏi huyền thoại mỗi khi bạn đi phỏng vấn lập trình web mà chắc chắc lập trình viên cũng gặp phải vậy bạn đã biết phân biệt 2 HTTP METHOD này chưa?

Phương thức GET

- Yêu cầu có thể được lưu trữ (cached)
- Giữ lại trong lịch sử duyệt Web của trình duyệt
- Có thể được đánh dấu ghi nhớ lại (bookmarked)
- Không được dùng để làm việc với những dữ liệu nhạy cảm
- Có giới hạn về độ dài
- Nên được sử dụng để nhận dữ liệu

Phương thức POST

- Yêu cầu sẽ không bao giờ được lưu trữ (cached)
- Không lưu trữ lại trong lịch sử trình duyệt Web
- Không thể đánh dấu ghi nhớ lại (bookmarked)
- Không bị giới hạn với độ dài của dữ liệu

## Lưu ý:

- Phương thức GET thì được dùng nhiều để nhận dữ liệu, ít được sử dụng để gửi các dữ liệu nhạy cảm,
  và có nhiều giới hạn về độ dài cũng như kiểu dữ liệu.
- Phương thức POST thì hay được sử dụng để có thể gửi các dữ liệu nhạy cảm, và không có giới hạn độ
  dài hay các kiểu dữ liệu.
