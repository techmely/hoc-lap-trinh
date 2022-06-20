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
  name: "Spring Boot"
  slug: "spring-boot"
position: 3
---

## ModelAndView là gì?

Lớp ModelAndView là nơi chứa 2 class là Model và View trong framework MVC web. 2 lớp này riêng biệt, không giống nhau. ModelAndView thì đơn thuần là chứa 2 thằng trên để giúp controller có thể return được cả model và view trong 1 giá trị duy
nhất.
View được giải quyết bởi đối tượng ViewResolver còn Model chính là dữ liệu được chứa trong Map.

## Cú pháp tạo ModelAndView

```java
new ModelAndView (logical_name_of_View, logical_name_of_model_data, actual_value_of_model_data)
```

**_Giải thích_**

- _logical_name_of_View_ : tên của view chúng ta muốn hiển thị dữ liệu
- _logical*name* of model_data_ : tên của model chứa dữ liệu
- _actual_value_of_model_data_ : gia trị của model chứa dữ liệu
