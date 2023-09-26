---
title: "Component Scan là gì"
description: "Trong lập trình Spring Boot, Component Scan là một khái niệm quan trọng để Spring Boot có thể tìm kiếm và quản lý các đối tượng (beans) trong ứng dụng của bạn một cách tự động"
chapter:
  name: "Spring Boot cơ bản"
  slug: "chuong-03-spring-boot-co-ban"
category:
  name: "Spring Boot"
  slug: "spring-boot"
position: 6
---

Trong lập trình Spring Boot, "Component Scan" là một khái niệm quan trọng để Spring Boot có thể tìm kiếm và quản lý các đối tượng (beans) trong ứng dụng của bạn một cách tự động. Trong bài viết này, chúng ta sẽ tìm hiểu về Component Scan và cách nó hoạt động.

## Giới thiệu

Trong các ứng dụng Spring Boot, chúng ta thường định nghĩa các bean bằng cách sử dụng các Annotation như `@Component`, `@Service`, `@Repository`, hoặc `@Controller`. Các bean này cần được quản lý và tạo ra bởi Spring Boot để chúng ta có thể sử dụng chúng trong ứng dụng.

Tuy nhiên, việc đánh dấu các bean này không đủ để Spring Boot biết cần tạo và quản lý chúng như thế nào. Đây là lúc Component Scan ra đời.

## Cài đặt

Trước khi đi sâu vào Component Scan, hãy xem qua cấu trúc Maven của một dự án Spring Boot thông qua ví dụ sau:

```xml
<?xml version="1.0" encoding="UTF-8"?>
<project xmlns="http://maven.apache.org/POM/4.0.0" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
         xsi:schemaLocation="http://maven.apache.org/POM/4.0.0 http://maven.apache.org/xsd/maven-4.0.0.xsd">
    <modelVersion>4.0.0</modelVersion>
    <packaging>pom</packaging>
    <parent>
        <groupId>org.springframework.boot</groupId>
        <artifactId>spring-boot-starter-parent</artifactId>
        <version>2.0.5.RELEASE</version>
        <relativePath /> <!-- lookup parent from repository -->
    </parent>
    <groupId>me.kungfutech.spring</groupId>
    <artifactId>spring-boot-learning</artifactId>
    <version>0.0.1-SNAPSHOT</version>
    <name>spring-boot-learning</name>
    <description>Everything about Spring Boot</description>

    <!-- Các dependency -->

</project>
```

### Component Scan là gì

Component Scan cho phép Spring Boot tự động tìm kiếm và quản lý các bean trong ứng dụng của bạn. Mặc định, Spring Boot sẽ quét toàn bộ các package và các package con của package chứa class chứa hàm `main`.

Dưới đây là ví dụ minh họa:

Giả sử chúng ta có cấu trúc thư mục ứng dụng như sau:

```css
src
└── main
    └── java
        └── me
            └── kungfutech
                └── spring
                    ├── App.java
                    ├── Girl.java
                    └── componentscan
                        └── others
                            └── OtherGirl.java
```

Chúng ta đã đánh dấu hai bean bằng `@Component` ở hai class `Girl` và `OtherGirl`. Khi chúng ta chạy ứng dụng, Spring Boot sẽ tự động quét và tạo các bean này.

```java
@Component
public class Girl {
    @Override
    public String toString() {
        return "Girl.java";
    }
}

@Component
public class OtherGirl {
    @Override
    public String toString() {
        return "OtherGirl.java";
    }
}
```

#### Ứng dụng chính

```java
@SpringBootApplication
public class App {
    public static void main(String[] args) {
        ApplicationContext context = SpringApplication.run(App.class, args);
        try {
            Girl girl = context.getBean(Girl.class);
            System.out.println("Bean: " + girl.toString());
        } catch (Exception e) {
            System.out.println("Bean Girl không tồn tại");
        }

        try {
            OtherGirl otherGirl = context.getBean(OtherGirl.class);
            if (otherGirl != null) {
                System.out.println("Bean: " + otherGirl.toString());
            }
        } catch (Exception e) {
            System.out.println("Bean Girl không tồn tại");
        }
    }
}
```

Khi chúng ta chạy ứng dụng này, cả hai bean `Girl` và `OtherGirl` đều được tạo ra và quản lý bởi Spring Boot.

::result

Bean: Girl.java</br>
Bean: OtherGirl.java

::

Kết quả in ra màn hình là cả hai bean đã được Spring Boot quét và tạo ra trong Context.

### Tuỳ chỉnh Component Scan

Trong trường hợp bạn muốn tuỳ chỉnh cấu hình cho Component Scan để chỉ tìm kiếm các bean trong một package nhất định, bạn có hai cách sau đây:

#### Cách 1: Sử dụng `@ComponentScan`

Bạn có thể sử dụng Annotation `@ComponentScan` trên class `App` để chỉ định các package cần quét.

```java
@ComponentScan("me.kungfutech.spring.componentscan.others")
@SpringBootApplication
public class App {
    // ...
}
```

#### Cách 2: Sử dụng `scanBasePackages`

Hoặc, bạn có thể sử dụng thuộc tính `scanBasePackages` trong Annotation `@SpringBootApplication` để chỉ định các package cần quét.

```java


@SpringBootApplication(scanBasePackages = "me.kungfutech.spring.componentscan.others")
public class App {
    // ...
}
```

Kết quả sẽ chỉ quét và tạo bean trong package `others`.

::result

Bean Girl không tồn tại</br>
Bean: OtherGirl.java

::

::alert{type="success"}
Component Scan là một tính năng quan trọng trong Spring Boot giúp tự động tìm kiếm và quản lý các bean trong ứng dụng của bạn. Việc sử dụng Component Scan giúp giảm sự phức tạp trong việc cấu hình và quản lý các bean. Bằng cách mặc định, Spring Boot quét toàn bộ package và package con của class chứa hàm `main`. Tuy nhiên, bạn có thể tuỳ chỉnh cấu hình Component Scan để chỉ tìm kiếm trong các package cụ thể hoặc nhiều package khác nhau.
::
