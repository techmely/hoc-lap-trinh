---
title: "Form login đơn giản"
description: "Sau khi học được 1 chút kiến thức cơ bản của Spring thì bài này chúng ta hãy cùng nhau tạo 1 chương trình đơn giản nhé."
chapter:
  name: "Spring controller"
  slug: "chuong-04-spring-controller"
category:
  name: "Spring Boot"
  slug: "spring-boot"
image: https://user-images.githubusercontent.com/29374426/127596066-fa46df01-982f-4a72-b6d1-f7d8f5c5a9b3.png
position: 6
---

Sau khi học được 1 chút kiến thức cơ bản của Spring thì bài này chúng ta hãy cùng nhau tạo 1 chương trình đơn giản nhé.

## Tạo project

Đầu tiên mình sẽ hướng dẫn các bạn cách tạo project Spring Web để chạy chương trình.

**_Bước 1_**
Chọn **File** -> **New** -> **Project**

![form-hello-1](https://github.com/techmely/hoc-lap-trinh/assets/29374426/53753b4b-9f65-4f3c-a876-1cd05ccb715a)

**_Bước 2_**
Chọn mục **Spring Initializr** -> Đặt **tên project** và điền các mục như dưới đây (nếu **jdk** của bạn là **1.8** hoặc bản cũ hơn thì chọn **Java: 8**) -> **Next**

![form-hello-2](https://github.com/techmely/hoc-lap-trinh/assets/29374426/d0e5abdc-7143-42b8-a789-122ca749748c)

**_Bước 3_**
Ở mục **Web** chọn **Spring Web** và ở **Template Engines** chọn **Thymeleaf** (bạn chưa biết cái này thì cứ hiểu nó công cụ hỗ trợ generate dữ liệu ra trang HTML) -> cuối cùng chọn **Finish**

![form-hello-3](https://github.com/techmely/hoc-lap-trinh/assets/29374426/d4d80536-1b6d-417d-858a-e2309c8e95ad)

**_Bước 4_**
Sau khi tạo xong cấu trúc project sẽ như này:

![form-hello-4](https://github.com/techmely/hoc-lap-trinh/assets/29374426/bc1e591d-9dbd-4503-bd7c-995d30452ac7)

**_Bước 5_**
Bây giờ đến bước tạo các file để viết chương trình, bạn _click chuột phải_ vào package chứa class main của project, ở đây chính là package: `com.example.hellospring` -> tiếp theo chọn **New** -> **Java Class**

![form-hello-5](https://github.com/techmely/hoc-lap-trinh/assets/29374426/a7ecc722-d019-4133-a732-65fda8688720)

**_Bước 6_**
Ở đây, bạn đặt tên là **WebController** với mục đích nó sẽ là class xử lý các `request` từ browser gửi đến

![form-hello-6](https://github.com/techmely/hoc-lap-trinh/assets/29374426/21c43d37-4e3e-4bb1-96bd-824dde5853d4)

**_Bước 7_**
Tiếp đến, bạn tạo thêm 2 file html: `index.html` và `hello.html`. Mình sẽ vứt 2 file này ở `resouces/template` (quy ước chung)

![form-hello-7](https://github.com/techmely/hoc-lap-trinh/assets/29374426/0d7612c0-c11a-4b01-8ab6-10af3b71b74b)

_File pom.xml_

```xml
<?xml version="1.0" encoding="UTF-8"?>
<project xmlns="http://maven.apache.org/POM/4.0.0" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
         xsi:schemaLocation="http://maven.apache.org/POM/4.0.0 https://maven.apache.org/xsd/maven-4.0.0.xsd">
    <modelVersion>4.0.0</modelVersion>
    <parent>
        <groupId>org.springframework.boot</groupId>
        <artifactId>spring-boot-starter-parent</artifactId>
        <version>2.6.7</version>
        <relativePath/> <!-- lookup parent from repository -->
    </parent>
    <groupId>com.example</groupId>
    <artifactId>HelloSpring</artifactId>
    <version>0.0.1-SNAPSHOT</version>
    <name>HelloSpring</name>
    <description>HelloSpring</description>
    <properties>
        <java.version>11</java.version>
    </properties>
    <dependencies>
        <dependency>
            <groupId>org.springframework.boot</groupId>
            <artifactId>spring-boot-starter-thymeleaf</artifactId>
        </dependency>
        <dependency>
            <groupId>org.springframework.boot</groupId>
            <artifactId>spring-boot-starter-web</artifactId>
        </dependency>

        <dependency>
            <groupId>org.springframework.boot</groupId>
            <artifactId>spring-boot-starter-test</artifactId>
            <scope>test</scope>
        </dependency>
    </dependencies>

    <build>
        <plugins>
            <plugin>
                <groupId>org.springframework.boot</groupId>
                <artifactId>spring-boot-maven-plugin</artifactId>
            </plugin>
        </plugins>
    </build>

</project>
```

### Bắt đầu viết chương trình hello

_WebController.java_

```java
package com.example.hellospring;

import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestParam;

@Controller
public class WebController {

    // Đón nhận request GET nếu người dùng request tới địa chỉ "/"
    @GetMapping("/")
    public String index(){
        // Trả về file index.html
        return "index";
    }

    // Đón nhận request POST nếu người dùng request tới địa chỉ "/hello"
    @PostMapping("/hello")
    public String hello(
            // Request param "name" sẽ được gán giá trị vào biến String
            @RequestParam(name = "yourname",required = false, defaultValue = "") String yourname,
            // Model là một object của Spring Boot, được gắn vào trong mọi request.
            Model model
                        )
    {
        // Gắn vào model giá trị yourname nhận được
        model.addAttribute("yourname",yourname);
        // trả về file hello.html cùng với thông tin trong object Model
        return "hello";
    }
}
```

Đầu tiên, mình đánh dấu `@Controller` trên class Webcontroller để cho Spring biết đây là nơi tiếp đón các request.
Mình viết 2 hàm cho việc xử lý request có method Get và Post.

::alert{type="infor"}
Ở `hàm index()`, nó sẽ đón nhận _request tới địa chỉ "/" và có phương thức Get_ (đánh dấu Annotation @GetMapping). Hàm này thì chỉ có nhiệm vụ trả về `1 String "index"`, đây chính là tên của trang html `index.html` mà mình đã tạo trước đó, mục đích là mình muốn nó chuyển đến trang này.
::

::alert{type="infor"}
Hàm `hello()` thì về ý nghĩa thì cũng tương tự hàm index() chỉ khác là nó xử lý _request có method POST_. Còn về nhiệm vụ, cụ thể nó sẽ nhận tham số chứa dữ liệu input (chính là trường Your name) của form bên trang `index.html`, rồi nhét vào thằng 1 object Model -> chuyển dữ liệu sang trang `hello.html` để làm việc, generate data đó.
::

_index.html_

```html
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Title</title>
</head>
<body>

    <h1>Day la trang index</h1>

    <form method="post" action="/hello">
        Your name: <input type="text" name="yourname"></br>
        <input type="submit" value="Go to hello">
    </form>

</body>
</html>
```

hello.html

```html
<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="UTF-8" />
    <title>Title</title>
  </head>
  <body>
    <h1 th:text="'Hello, ' + ${yourname}"></h1>
  </body>
</html>
```

Sau khi viết xong giờ là lúc bạn chạy chương trình, mở class main của project (ở đây thì có tên `HelloSpringApplication.java`) rồi chạy project thôi!

_HelloSpringApplication.java_

```java
package com.example.hellospring;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.context.ApplicationContext;

@SpringBootApplication
public class HelloSpringApplication {

    public static void main(String[] args) {
       ApplicationContext context = SpringApplication.run(HelloSpringApplication.class, args);
    }

}
```

Sau khi chạy xong thì chương trình đang ở đường dẫn `http://localhost:8080/` rồi.

![form-hello-8](https://github.com/techmely/hoc-lap-trinh/assets/29374426/13f21c49-b565-4e45-b7a3-ed2a0c75535a)

![form-hello-9](https://github.com/techmely/hoc-lap-trinh/assets/29374426/7e689fb6-8f08-4968-b133-33bbbebe8250)
