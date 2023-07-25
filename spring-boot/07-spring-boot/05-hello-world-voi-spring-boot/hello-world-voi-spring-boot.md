---
title: "Hello World với Spring Boot"
description: "Hello World với Spring Boot"
keywords:
  [
    "spring boot la gi",
    "java spring boot",
    "web application voi spring boot",
    "java spring boot intellij idea",
    "tao ung dung voi spring boot",
    "java spring boot application",
    "web application voi spring boot",
    "java spring boot",
    "web application voi spring boot",
  ]
chapter:
  name: "Spring boots"
  slug: "chuong-07-spring-boots"
category:
  name: "SpringBoots"
  slug: "springboots"
image: https://kungfutech.edu.vn/thumbnail.png
position: 5
---

## Hello World với Spring Boot

Trong phần hướng dẫn này sẽ hướng dẫn các bạn tạo ứng dụng Spring boot đơn giản để hiển thị ra
dòng chữ:Hello World!

### Các bước thực hiện

Bước1:Truy cập vào:https://start.spring io

Tạo ứng dụng spring boot với thông số sau

![taoungdung](https://github.com/techmely/hoc-lap-trinh/assets/29374426/0b487096-79cc-4773-b031-7d6bfbf9d821)

Bước2:Mở IntellJ Idea.

Mở project vừa tạo và tổ chức lại thư mục dự án như sau:

![to chuc thu muc](https://github.com/techmely/hoc-lap-trinh/assets/29374426/29fef1cc-6097-42c9-ae22-0f297104adb5)

Bước3:Cài đặt GreetingController

```java
package com.codelean.controller;
import org.springframework.web.bind.annotation RequestMapping;
import org.springframework.web.bind.annotation RestController;

@RestController
public class GreetingController{
  @RequestMapping(value="/home")
  public String greeting(){
    return"Hello World!";
 }
}
```

Bước4:Điều chỉnh lại file GreetingSpringbootApplication

```java
package com.codelean.app;
import org.springframework.boot Spring Application;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.context.annotation.ComponentScan;

@SpringBootApplication
@ComponentScan("com.techmely")
public class GreetingSpringbootApplication{
  public static void main(String[]args){
    SpringApplication.run(GreetingSpringbootApplication.class,args);
 }
}
```

Bước5:Cấu hình và chạy ứng dụng
http://localhost:8080/home
