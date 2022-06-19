---
title: "Deployment ứng dụng Spring boot trên server"
description: "Deployment ứng dụng Spring boot trên server"
keywords:
  [
    "Deployment ứng dụng Spring boot trên server",
    "deploy spring boot",
    "tomcat server",
    "spring boot la gi",
    "Deploy Spring Boot len Tomcat",
    " trien khai du an spring boot",
    "cach trien khai du an spring boot"
  ]
chapter:
  name: "Spring boots"
  slug: "07-spring-boots"
category:
  name: "SpringBoots"
  slug: "springboots"
image: https://kungfutech.edu.vn/thumbnail.png
position: 11
---
## Deployment ứng dụng Spring boot trên server
### Mục tiêu
Luyện tập đóng gói và deploy ứng dụng được phát triển trên Spring Boot.

### Mô tả
Trong phần này, chúng ta sẽ đóng gói và deploy ứng dụng được phát triển trên Spring Boot lên server Tomcat.

### Hướng dẫn
**Bước 1**: Tạo dự án Spring Boot

Để tạo mới dự án, các bạn chọn File -> New -> Project.

Sau đó chọn Gradle -> Tích chọn Java, Web -> Chọn Next


Bạn nhập thông tin vào GroupId, và ArtifactId. Sau đó nhấn Next:


Màn hình sau đó bạn tiếp tục nhấn Next:


Nhập vào Project name, Project location. Sau đó nhấn Finish.

**Bước 2**: Tạo cấu trúc của dự án.

Bạn tạo cấu trúc của dự án như sau. Nhớ xóa file index.jsp trong trong thư mục webapp.


**Bước 3**: Cấu hình dependency trong build.gradle:
```java
dependencies {
    // https://mvnrepository.com/artifact/org.springframework.boot/spring-boot-starter-web
    compile group: 'org.springframework.boot', name: 'spring-boot-starter-web', version: '2.0.2.RELEASE'
    // https://mvnrepository.com/artifact/org.springframework.boot/spring-boot-starter-tomcat
    compile group: 'org.springframework.boot', name: 'spring-boot-starter-tomcat', version: '2.0.2.RELEASE'
    // https://mvnrepository.com/artifact/jstl/jstl
    compile group: 'jstl', name: 'jstl', version: '1.2'
    // https://mvnrepository.com/artifact/org.apache.tomcat.embed/tomcat-embed-jasper
    compile group: 'org.apache.tomcat.embed', name: 'tomcat-embed-jasper', version: '9.0.8'
}
```
**Bước 4**: Thêm “Main” class cho project

Trong file SpringBootWebApplication.java, thêm static method “Main”:
```java
package com.techmely;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.boot.builder.SpringApplicationBuilder;
import org.springframework.boot.web.servlet.support.SpringBootServletInitializer;


@SpringBootApplication
public class SpringBootWebApplication extends SpringBootServletInitializer {

    @Override
    protected SpringApplicationBuilder configure(SpringApplicationBuilder application) {
        return application.sources(SpringBootWebApplication.class);
    }

    public static void main(String[] args) throws Exception {
        SpringApplication.run(SpringBootWebApplication.class, args);
    }
}
```
Trong đó:

Hàm “Main” để tạo mới một spring boot app. Spring Boot cung cấp SpringApplication class để khởi động cho ứng dụng Spring từ hàm main() sử dụng static method SpringApplication.run(…).
**Bước 5**: Thêm controller
```java
package com.techmely.controller;

import java.util.Map;

import org.springframework.beans.factory.annotation.Value;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;

@Controller
public class WelcomeController {

    // inject via application.properties
    @Value("Welcome!")
    private String message = "Welcome!";

    @RequestMapping("/")
    public String welcome(Map<String, Object> model) {
        model.put("message", this.message);
        return "welcome";
    }
}
```
**Bước 6**: Cấu hình file application.properties
```java
spring.mvc.view.prefix:/WEB-INF/views/
spring.mvc.view.suffix:.jsp
welcome.message:Welcome!
```
**Bước 7**: Xây dựng view
```html
<!DOCTYPE html>
<%@ taglib prefix="spring" uri="http://www.springframework.org/tags" %>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<html lang="en">
<head>
</head>
<body>
<div>
    <div>
        <h1>Spring Boot Example</h1>
        <h2>${message}</h2>
    </div>
</div>
</body>
</html>
```
**Bước 8**: Start Spring Boot web app

Chuột phải vào file SpringBootWebApplication -> Run…


Màn hình console sẽ hiển thị như sau:


Truy cập http://localhost:8080


**Bước 9**: Đóng gói project

Mở cửa sổ “Run Gradle Task”. Nhập “clean build” vào text box “Command line”. Nhấn “OK”:


Chúng ta sẽ thấy một file (.war) được sinh ra trong “..\build\libs\”:


**Bước 10**: Deploy lên server Tomcat

Copy file (.war) trong thư mục “\build\libs\” ra một thư mục bất kỳ trên máy tính. Trong ví dụ này, file (.war) sẽ được copy vào ổ (E:\).

Chạy Tomcat, truy cập vào ứng dụng(Tomcat Manager Application) theo url (http://localhost:8080/manager). Nhập vào như sau:


Sau đó nhấn “Deploy”.

Ứng dụng đã được triển khai lên Tomcat:


Chạy ứng dụng (http://localhost:8080/welcome):