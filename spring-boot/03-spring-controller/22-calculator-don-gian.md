---
title: "Model and View"
description: "Là sự kết hợp của 2 khía cạnh truyền dữ liệu và view."
keywords:
  [
    "Model and View",
    "post la gi",
    "get la gi",
    "get va post trong springboot",
    "get data la gi",
    "put va post khac nhau nhu the nao",
    "du ieu truyen di bang phuong thuc get",
    "du ieu truyen di bang phuong thuc post"
  ]
chapter:
  name: "Spring Controller"
  slug: "03-spring-controller"
category:
  name: "SpringBoots"
  slug: "springboots"
image: https://kungfutech.edu.vn/thumbnail.png
position: 22
---
## Bài tập xây dựng ứng dụng calculator đơn giản
### Mô tả
Xây dựng ứng dụng máy tính cá nhân thực hiện 2 phép tính cộng và trừ để minh hoạ việc lựa chọn action bằng cách sử dụng các tham số.
![calculator don gian](https://1.bp.blogspot.com/-mZg8eyAh0oU/Xf7wlAvQTCI/AAAAAAAAARM/94SD5pgmUys83aM2NNmYiTYxxunmzFBuACLcBGAsYHQ/s640/Screen%2BShot%2B2019-12-22%2Bat%2B11.24.21%2BAM.png)

Controller chứa action calculate.jsp với 3 cách gọi khác nhau:
- GET: calculate.jsp - Không tham số
- POST: calculate.jsp?add - Tham số là "add"
- POST: calculate.jsp?sub - Tham số là "sub"

Với giao diện trên, khi người dùng click vào nút + hoặc - thì action caculate cùng với tham số add hoặc sub tương ứng với nút được click.