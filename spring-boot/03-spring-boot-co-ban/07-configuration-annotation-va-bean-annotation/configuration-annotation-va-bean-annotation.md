---
title: "@Configuration annotation và @Bean annotation"
description: "Trong lập trình Spring Boot, hai Annotation quan trọng là @Configuration và @Bean cho phép bạn tạo và quản lý các đối tượng (beans) trong ứng dụng của bạn"
chapter:
  name: "Spring Boot cơ bản"
  slug: "chuong-03-spring-boot-co-ban"
category:
  name: "Spring Boot"
  slug: "spring-boot"
position: 7
---

## Giới thiệu

Trong lập trình Spring Boot, hai Annotation quan trọng là `@Configuration` và `@Bean` cho phép bạn tạo và quản lý các đối tượng (beans) trong ứng dụng của bạn. Bài viết này sẽ giúp bạn hiểu cách sử dụng và lợi ích của `@Configuration` và `@Bean`.

## Cài đặt

Trước khi bắt đầu, bạn cần tạo một dự án Spring Boot cơ bản. Dưới đây là một phần của tệp `pom.xml` để thêm Spring Boot vào dự án của bạn:

```xml
<!-- Các dependency Spring Boot -->
<dependencies>
    <dependency>
        <groupId>org.springframework.boot</groupId>
        <artifactId>spring-boot-starter-web</artifactId>
    </dependency>
</dependencies>
```

## `@Configuration` trong Spring Boot

- `@Configuration` là một Annotation đánh dấu trên một class, cho biết rằng class đó chứa các thông tin cấu hình cho ứng dụng.
- Spring Boot sẽ tìm và quét các class được đánh dấu `@Configuration` để tạo và quản lý các beans.

```java
import org.springframework.context.annotation.Configuration;

@Configuration
public class AppConfig {
    // Các cấu hình và định nghĩa beans sẽ ở đây.
}
```

## `@Bean` trong Spring Boot

- `@Bean` là một Annotation đánh dấu trên một method trong class được đánh dấu `@Configuration`.
- Nó cho biết rằng method đó tạo và trả về một bean, và Spring Boot nên quản lý bean đó trong ứng dụng.

```java
import org.springframework.context.annotation.Bean;

@Configuration
public class AppConfig {
    @Bean
    public MyBean myBean() {
        return new MyBean();
    }
}
```

### Ví dụ

Dưới đây là một ví dụ cụ thể:

```java
public class MyBean {
    private String message;

    public MyBean() {
        this.message = "Hello, I'm a custom bean!";
    }

    public String getMessage() {
        return message;
    }
}
```

```java
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.context.ApplicationContext;

@SpringBootApplication
public class App {
    public static void main(String[] args) {
        ApplicationContext context = SpringApplication.run(App.class, args);
        MyBean myBean = context.getBean(MyBean.class);
        System.out.println(myBean.getMessage());
    }
}
```

Kết quả khi chạy ứng dụng:

::result

Hello, I'm a custom bean!

::

## @Bean có tham số

Nếu method được đánh dấu `@Bean` có tham số, Spring Boot sẽ tự động inject các beans khác từ context vào làm tham số.

```java
@Configuration
public class AppConfig {
    @Bean
    public MyBean myBean(OtherBean otherBean) {
        return new MyBean(otherBean);
    }
}
```

## Lợi ích

- `@Configuration` và `@Bean` cho phép bạn tạo và quản lý các beans một cách tường minh và linh hoạt.
- Bạn có thể tạo ra các beans với các cấu hình phức tạp hoặc phụ thuộc vào các beans khác.
- Điều này giúp quản lý phần cấu hình và khởi tạo beans một cách hiệu quả.

::alert{type="success"}
Annotation `@Configuration` và `@Bean` là một phần quan trọng của Spring Boot, cho phép bạn tạo và quản lý các beans trong ứng dụng của bạn. Việc sử dụng chúng giúp bạn tạo ra các beans theo cách tường minh và quản lý chúng một cách hiệu quả. Điều này rất hữu ích khi bạn cần cấu hình và khởi tạo các thành phần phức tạp trong ứng dụng của mình.
::
