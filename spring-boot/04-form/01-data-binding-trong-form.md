---
title: "Data binding trong form"
description: "Data Binding là cơ chế liên kết dữ liệu đầu vào hoặc đầu ra với các đối tượng model. Hay nói cách khác đó là sự kết nối dữ liệu của bean đặt trong model đến các điều khiển trên form."
keywords:
  [
    "data binding trong spring boot",
    "data binding la gi",
    "trinh bay co che data binding trong spring",
    "data binding trong spring mvc",
    "valid trong spring",
    "service trong spring",
    "data binding trong spring boot la gi",
    "data binding trong spring boot su dung nhu the nao",
    "the nao la data binding trong spring boot",
    "cach su dung data binding spring",
  ]
chapter:
  name: "Form"
  slug: "chuong-04-form"
category:
  name: "Spring"
  slug: "spring"
image: https://kungfutech.edu.vn/thumbnail.png
position: 1
---

## Data binding

Data Binding là cơ chế liên kết dữ liệu đầu vào hoặc đầu ra với các đối tượng model. Hay nói cách khác đó là sự kết nối dữ liệu của bean đặt trong model đến các điều khiển trên form.
Data Binding giúp cho việc tương tác với dữ liệu trở nên dễ dàng. Sử dụng Data binding, các form đều được liên kết với một đối tượng biểu diễn dữ liệu ở phía sau (dữ liệu của bean đặt trong model). Khi tương tác với form, dữ liệu trên form sẽ được tự động chuyển đổi thành các thuộc tính của đối tượng liên kết với nó. Khi thay đổi dữ liệu của đối tượng thì dữ liệu trên các điều khiển cũng thay đổi theo.
Một cách hiểu khác là ràng buộc dữ liệu có thể là một chiều hoặc hai chiều

- Chiều đi: Chuyển dữ liệu từ các điều khiển trên form vào các thuộc tính của đối tượng dữ liệu
  (bean)
- Chiều về: Hiển thị dữ liệu từ của các thuộc tính của đối tượng lên các điều khiển của form

![databinding](https://1.bp.blogspot.com/-H8EUpjgF_Ls/XgElekvDX1I/AAAAAAAAARY/XsVIZPJITWUf3hjXfB0gbbpEUrAdowEugCLcBGAsYHQ/s640/a1.png)
Ngoài ta data binding hỗ trợ chuyển đổi dữ liệu (data conversioin) và validate dữ liệu. Data binding trong Spring hoạt động dựa trên Data Binder.
