---
title: "Vòng đời của Bean và @PostConstruct, @PreDestroy"
description: "Trong lập trình Spring Boot, việc hiểu vòng đời của một Bean và sử dụng các Annotation như @PostConstruct và @PreDestroy là rất quan trọng. Bài viết này sẽ giúp bạn hiểu rõ hơn về chúng."
chapter:
  name: "Spring Boot cơ bản"
  slug: "chuong-03-spring-boot-co-ban"
position: 4
---

Trong lập trình Spring Boot, việc hiểu vòng đời của một Bean và sử dụng các Annotation như `@PostConstruct` và `@PreDestroy` là rất quan trọng. Bài viết này sẽ giúp bạn hiểu rõ hơn về chúng.

## Giới thiệu

Trước khi tìm hiểu về vòng đời của Bean và Annotation, bạn cần nắm vững các khái niệm về Bean và cách inject chúng trong Spring Boot bằng `@Component` và `@Autowired`. Bạn có thể tham khảo các bài viết trước, trong bài viết này, chúng ta sẽ tìm hiểu về vòng đời của Bean trong Spring Boot.

## Cài đặt

Để bắt đầu, bạn cần cấu hình Maven cho dự án Spring Boot của mình. Dưới đây là một ví dụ về cấu hình `pom.xml`:

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

    <properties>
        <java.version>1.8</java.version>
    </properties>

    <dependencies>
        <!-- Thêm các dependencies cần thiết cho dự án của bạn -->
        <dependency>
            <groupId>org.springframework.boot</groupId>
            <artifactId>spring-boot-starter-web</artifactId>
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

## Annotation `@PostConstruct` trong Spring Boot

`@PostConstruct` là một Annotation đánh dấu trên một method bên trong một Bean. IoC Container hoặc ApplicationContext sẽ gọi method này **sau khi** Bean đó được tạo ra và quản lý.

Ví dụ:

```java
import org.springframework.stereotype.Component;
import javax.annotation.PostConstruct;

@Component
public class Girl {

    @PostConstruct
    public void postConstruct(){
        System.out.println("\t>> Đối tượng Girl sau khi khởi tạo xong sẽ chạy hàm này");
    }
}
```

## Annotation `@PreDestroy` trong Spring Boot

`@PreDestroy` là một Annotation đánh dấu trên một method bên trong một Bean. IoC Container hoặc ApplicationContext sẽ gọi method này **trước khi** Bean đó bị xóa hoặc không được quản lý nữa.

Ví dụ:

```java
import org.springframework.stereotype.Component;
import javax.annotation.PreDestroy;

@Component
public class Girl {

    @PreDestroy
    public void preDestroy(){
        System.out.println("\t>> Đối tượng Girl trước khi bị destroy thì chạy hàm này");
    }
}
```

## Vòng Đời của Bean

Một Bean trong Spring Boot có một vòng đời được biểu diễn như hình dưới đây:

![Vòng Đời của Bean](https://github.com/techmely/hoc-lap-trinh/assets/29374426/35c65897-cfdc-4be1-aad6-3f46193df01a)

Tóm tắt vòng đời của Bean:

1. Khi IoC Container tìm thấy một Bean cần quản lý, nó sẽ khởi tạo bằng Constructor.
2. Dependencies sẽ được inject vào Bean thông qua Setter và thực hiện các quá trình cài đặt khác.
3. Hàm được đánh dấu `@PostConstruct` sẽ được gọi.
4. Bean đã sẵn sàng để hoạt động.
5. Nếu IoC Container không quản lý Bean nữa hoặc bị shutdown, hàm `@PreDestroy` sẽ được gọi.
6. Bean được xóa.

## Ví dụ

Dưới đây là một ví dụ minh họa:

```java
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.context.ApplicationContext;
import org.springframework.context.ConfigurableApplicationContext;

@SpringBootApplication
public class App {
    public static void main(String[] args) {
        System.out.println("> Trước khi IoC Container được khởi tạo");
        ApplicationContext context = SpringApplication.run(App.class, args);
        System.out.println("> Sau khi IoC Container được khởi tạo");

        Girl girl = context.getBean(Girl.class);

        System.out.println("> Trước khi IoC Container destroy Girl");
        ((ConfigurableApplicationContext) context).getBeanFactory().destroyBean(girl);
        System.out.println("> Sau khi IoC Container destroy Girl");
    }
}
```

::result
Trước khi IoC Container được khởi tạo</br>
Trước khi IoC Container được khởi tạo</br>
Đối tượng Girl sau khi khởi tạo xong sẽ chạy hàm này</br>
Sau khi IoC Container được khởi tạo</br>
Trước khi IoC Container destroy Girl</br>
Đối tượng Girl trước khi bị destroy thì chạy hàm này

::

## Ý nghĩa

`@PostConstruct` và `@PreDestroy` rất hữu ích trong việc quản lý vòng đời của Bean. Bạn có thể sử dụng chúng để thực hiện các nhiệm vụ như cài đặt giá trị mặc định trong thuộc tính sau khi Bean được khởi tạo hoặc xóa dữ liệu trước khi Bean bị xóa.

::alert{type="success"}
Qua bài viết này, bạn đã hiểu rõ về vòng đời của Bean trong Spring Boot và cách sử dụng `@PostConstruct` và `@PreDestroy` để quản lý vòng đời của Bean. Hiểu biết về chúng sẽ giúp bạn tận dụng tốt tính năng này trong phát triển ứng dụng Spring Boot.
::
