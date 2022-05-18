---
title: "Lớp ModelAndView"
description: "Lớp ModelAndView là nơi chứa 2 class là Model và View trong framework MVC web. 2 lớp này riêng biệt, không giống nhau. 
ModelAndView thì đơn thuần là chứa 2 thằng trên để giúp controller có thể return được cả model và view trong 1 giá trị duy
nhất."
keywords:
  [
    "Lớp ModelAndView",
    "Lớp ModelAndView là gì",
    "Model và view",
    "khóa học Spring cơ bản",
    "ViewResolver là gì"
  ]
chapter:
  name: "Spring controller"
  slug: "chuong-03-spring-controller"
category:
  name: "spring"
  slug: "spring"
# image: https://user-images.githubusercontent.com/29374426/127596066-fa46df01-982f-4a72-b6d1-f7d8f5c5a9b3.png
position: 19
---

## Lớp ModelAndView

> ***Nội dung bài viết***
> - [ModelAndView là gì?](#modelandview-là-gì)
> - [Cú pháp tạo ModelAndView](#cú-pháp-tạo-modelandview)

### ModelAndView là gì?
Lớp ModelAndView là nơi chứa 2 class là Model và View trong framework MVC web. 2 lớp này riêng biệt, không giống nhau. ModelAndView thì đơn thuần là chứa 2 thằng trên để giúp controller có thể return được cả model và view trong 1 giá trị duy
nhất.
View được giải quyết bởi đối tượng ViewResolver còn Model chính là dữ liệu được chứa trong Map. 


### Cú pháp tạo ModelAndView

```java
new ModelAndView (logical_name_of_View, logical_name_of_model_data, actual_value_of_model_data)
```

***Giải thích***
- *logical_name_of_View* : tên của view chúng ta muốn hiển thị dữ liệu
- *logical_name_ of model_data* : tên của model chứa dữ liệu
- *actual_value_of_model_data* : gia trị của model chứa dữ liệu

