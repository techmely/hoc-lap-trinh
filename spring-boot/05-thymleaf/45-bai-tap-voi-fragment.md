---
title: "Tạo layout với Fragment."
description: "Các fragment có tác dụng để lắp ghép lại với nhau tạo thành một trang."
keywords:
  [
    "Tạo layout với Fragment trong Spring.",
    "Cach tạo layout với Fragment trong Spring.",
    "layout trong spring",
    "fragment trong Spring"
    "layout trong spring la gi",
    "Tạo layout với Fragment trong Spring nhu the nao",
    "fragment trong Spring la gi",
    "fragment trong Spring dung de lam gi",
    "lam the nao tạo layout với Fragment trong Spring.  "
  ]
chapter:
  name: "Thymleaf"
  slug: "05-thymleaf"
category:
  name: "SpringBoots"
  slug: "springboots"
image: https://kungfutech.edu.vn/thumbnail.png
position: 45
---
## Sử dụng Layout

### Nhắc lại bài học
Page Layout (bố cục trang) đề cập đến việc xắp xếp văn bản, hình ảnh và các đối tượng khác trên một trang, và nó là vấn đề được quan tâm lớn nhất của những người thiết kế website. Trong bài học này tôi sẽ giới thiệu kỹ thuật được sử dụng trong Thymeleaf để tạo ra một Layout.
Một website có thể có nhiều trang, nhưng các trang có một cấu trúc tương tự nhau. Chẳng hạn, dưới đây là một cấu trúc đơn giản:
 ![layout](https://s1.o7planning.com/vi/12369/images/40274059.png)
 Dựa trên cấu trúc trên bạn có thể tạo ra các trang khác nhau:
 ![layout](https://s1.o7planning.com/vi/12369/images/40277382.gif)
 
 ### Bài tập Layout với Thymleaf
Trong phần hướng dẫn này chúng ta sẽ dùng Thymeleaf sử dụng các fragment để lắp ghép lại với nhau tạo thành một trang cho ứng dụng quản lý khách hàng.Đây là một ứng dụng CRUD đơn giản cho phép người dùng quản lý danh sách khách hàng,với dữ liệu khách hàng được giả lập là có sẵn.
