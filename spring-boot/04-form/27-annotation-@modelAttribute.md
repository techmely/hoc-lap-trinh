---
title: "Annotation @ModelAttribute"
description:"@ModelAttribute là một trong những annotation quan trọng nhất trong Spring MVC."
keywords:
  [
    "khóa học Spring cơ bản",
    "annotation @modelAttribute",
    "annotation @modelAttribute là gì",
    "annotation @modelAttribute ý nghĩa",
    "annotation @modelAttribute cách dùng"
  ]
chapter:
  name: "form"
  slug: "chuong-04-form"
category:
  name: "spring"
  slug: "spring"
# image: https://user-images.githubusercontent.com/29374426/127596066-fa46df01-982f-4a72-b6d1-f7d8f5c5a9b3.png
position: 19
---
## Annotation @ModelAttribute

![form-hello](https://github.com/techmely/hoc-lap-trinh/blob/spring-boots/spring-boot/images/model-attribute.png)


> ***Nội dung bài viết***
> - [Khái niệm](#khái-niệm)
> - [Ý nghĩa](#ý-nghĩa)
> - [Ví dụKhái niệm](#ví-dụ)
> - [Bind kết quả trả về của một method thành model attribute](#bind-kết-quả-trả-về-của-một-method-thành-model-attribute)
> - [Bind tham số của một method thành model attribute](#bind-tham-số-của-một-method-thành-model-attribute)

### Khái niệm
`@ModelAttribute` là một trong những annotation quan trọng nhất trong ***Spring MVC***.

Thông thường, controller có thể chuyển tập các model attribute tới cho front controller (và nhờ đó view có thể truy cập các model atrribute này) bằng cách sử dụng kiểu trả về ModelAndView, hoặc bằng cách thông qua tham số Model/ModelMap.
Annotation `@ModelAttribute` là một cách bổ sung, nó giúp bind tham số hoặc kết quả trả về của một phương thức thành một model attribute dưới tên được chỉ định.

### Ý nghĩa
`@ModelAttribution` có thể được sử dụng làm đối số/tham số của method hoặc trước khi khai báo method. Mục tiêu chính của *annotation* này để liên kết các tham số yêu cầu hoặc các trường form với một đối tượng mô hình.

### Ví dụ

#### Bind kết quả trả về của một method thành model attribute

```java
@ModelAttribute("customers")
public Iterable<Customer> getAllCustomers() {
    return customerService.findAll();
}
```
Phương thức trên được gọi ngay trước mỗi khi handle method (những method có annotation `@RequestMapping` hoặc tương đương) được gọi, và nó bổ sung model attribute có tên “customers” vào model trả về của bất kỳ handle method nào. Có nghĩa là mọi view được handle method dẫn ra sau đó đều có thể sử dụng model attribute này.

#### Bind tham số của một method thành model attribute

```java
@PostMapping
public String submitCustomer(@ModelAttribute("customer") Customer newCustomer) {
    customerService.save(newCustomer);
    return "customers/info";
}
```
Tham số newCustomer ở trên, dĩ nhiên được tổng hợp lại từ request. Ở đây, nhờ có annotation `ModelAttribute`, đối tượng này cũng được bổ sung tự động vào model cho view “customers/info”, dưới tên “customer”.
