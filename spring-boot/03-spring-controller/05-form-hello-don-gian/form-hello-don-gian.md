---
title: "Form hello đơn giản"
description: "Sau khi học được 1 chút kiến thức cơ bản của Spring thì bài này chúng ta hãy cùng nhau tạo 1 chương trình đơn giản nhé."
keywords:
  [
    "Form hello đơn giản",
    "khóa học Spring cơ bản",
    "tạo form hello",
    "tạo chương trình Spring đơn giản",
  ]
chapter:
  name: "Spring controller"
  slug: "chuong-03-spring-controller"
category:
  name: "Spring Boot"
  slug: "spring-boot"
image: https://user-images.githubusercontent.com/29374426/127596066-fa46df01-982f-4a72-b6d1-f7d8f5c5a9b3.png
position: 5
---

Sau khi học được 1 chút kiến thức cơ bản của Spring thì bài này chúng ta hãy cùng nhau tạo 1 chương trình đơn giản nhé.

## Tạo project

Đầu tiên mình sẽ hướng dẫn các bạn cách tạo project Spring Web để chạy chương trình.

**_Bước 1_**
Chọn **File** -> **New** -> **Project**

![form-hello](https://github.com/techmely/hoc-lap-trinh/blob/spring-boots/spring-boot/images/form-hello-1.png)

**_Bước 2_**
Chọn mục **Spring Initializr** -> Đặt **tên project** và điền các mục như dưới đây (nếu **jdk** của bạn là **1.8** hoặc bản cũ hơn thì chọn **Java: 8**) -> **Next**

![form-hello](https://github.com/techmely/hoc-lap-trinh/blob/spring-boots/spring-boot/images/form-hello-2.png)

**_Bước 3_**
Ở mục **Web** chọn **Spring Web** và ở **Template Engines** chọn **Thymeleaf** (bạn chưa biết cái này thì cứ hiểu nó công cụ hỗ trợ generate dữ liệu ra trang HTML) -> cuối cùng chọn **Finish**

![form-hello](https://github.com/techmely/hoc-lap-trinh/blob/spring-boots/spring-boot/images/form-hello-3.png)

**_Bước 4_**
Sau khi tạo xong cấu trúc project sẽ như này:

![form-hello](https://github.com/techmely/hoc-lap-trinh/blob/spring-boots/spring-boot/images/form-hello-4.png)

**_Bước 5_**
Bây giờ đến bước tạo các file để viết chương trình, bạn _click chuột phải_ vào package chứa class main của project, ở đây chính là package: `com.example.hellospring` -> tiếp theo chọn **New** -> **Java Class**

![form-hello](https://github.com/techmely/hoc-lap-trinh/blob/spring-boots/spring-boot/images/form-hello-5.png)

**_Bước 6_**
Ở đây, bạn đặt tên là **WebController** với mục đích nó sẽ là class xử lý các `request` từ browser gửi đến

![form-hello](https://github.com/techmely/hoc-lap-trinh/blob/spring-boots/spring-boot/images/form-hello-6.png)

**_Bước 7_**
Tiếp đến, bạn tạo thêm 2 file html: `index.html` và `hello.html`. Mình sẽ vứt 2 file này ở `resouces/template` (quy ước chung)

![form-hello](https://github.com/techmely/hoc-lap-trinh/blob/spring-boots/spring-boot/images/form-hello-7.png)

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

<content-info>
Ở `hàm index()`, nó sẽ đón nhận _request tới địa chỉ "/" và có phương thức Get_ (đánh dấu Annotation @GetMapping). Hàm này thì chỉ có nhiệm vụ trả về `1 String "index"`, đây chính là tên của trang html `index.html` mà mình đã tạo trước đó, mục đích là mình muốn nó chuyển đến trang này.
</content-info>

<content-info>
Hàm `hello()` thì về ý nghĩa thì cũng tương tự hàm index() chỉ khác là nó xử lý _request có method POST_. Còn về nhiệm vụ, cụ thể nó sẽ nhận tham số chứa dữ liệu input (chính là trường Your name) của form bên trang `index.html`, rồi nhét vào thằng 1 object Model -> chuyển dữ liệu sang trang `hello.html` để làm việc, generate data đó.
</content-info>

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

![form-hello](https://github.com/techmely/hoc-lap-trinh/blob/spring-boots/spring-boot/images/form-hello-8.png)

![form-hello](https://github.com/techmely/hoc-lap-trinh/blob/spring-boots/spring-boot/images/form-hello-9.png)
