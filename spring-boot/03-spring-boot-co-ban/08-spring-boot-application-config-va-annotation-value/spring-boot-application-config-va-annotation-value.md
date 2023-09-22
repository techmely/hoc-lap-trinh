---
title: "Spring Boot Application Config và @Value annotation"
description: "Trong bài viết này, chúng ta sẽ tìm hiểu về khái niệm cấu hình ứng dụng Spring Boot và cách sử dụng annotation @Value để đọc các giá trị cấu hình từ file application.properties"
chapter:
  name: "Spring Boot cơ bản"
  slug: "chuong-03-spring-boot-co-ban"
category:
  name: "Spring Boot"
  slug: "spring-boot"
position: 8
---

## Giới thiệu

Trong thực tế, không phải lúc nào chúng ta cũng nên để mọi thứ trong code của mình. Có những thông số tốt hơn nên được truyền từ bên ngoài vào ứng dụng, để giúp ứng dụng của bạn dễ dàng thay đổi giữa các môi trường khác nhau. Trong bài viết này, chúng ta sẽ tìm hiểu về khái niệm cấu hình ứng dụng Spring Boot và cách sử dụng annotation `@Value` để đọc các giá trị cấu hình từ file `application.properties`.

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

## `application.properties`

Trong Spring Boot, các thông tin cấu hình mặc định được lấy từ file `resources/application.properties`. Ví dụ, bạn có thể cấu hình Spring Boot để chạy trên cổng 8081 thay vì 8080:

```properties
server.port = 8081
```

Hoặc bạn có thể điều chỉnh cấu hình logging của ứng dụng bằng cách chuyển nó sang chế độ Debug:

```properties
logging.level.root=DEBUG
```

Điều này cho phép bạn can thiệp vào các cấu hình của ứng dụng từ bên ngoài, giúp thay đổi linh hoạt giữa các môi trường khác nhau.

## Annotation `@Value`

Trong trường hợp bạn muốn tự cấu hình các giá trị của riêng mình, Spring Boot hỗ trợ bạn thông qua annotation `@Value`. `@Value` được sử dụng để chú thích các thuộc tính trong class, nơi mà bạn muốn đọc các giá trị cấu hình từ file `application.properties` hoặc các nguồn khác.

Ví dụ, nếu bạn muốn cấu hình thông tin về cơ sở dữ liệu của mình từ bên ngoài ứng dụng:

```properties
loda.mysql.url=jdbc:mysql://host1:33060/loda
```

Sử dụng `@Value` để lấy giá trị cấu hình này trong class:

```java
public class AppConfig {
    // Lấy giá trị cấu hình từ file application.properties
    @Value("${loda.mysql.url}")
    private String mysqlUrl;
}
```

Tên của thuộc tính trong `@Value` chính là tên của cấu hình đặt trong dấu `${name}`.

## Ví dụ

Dưới đây là một ví dụ cụ thể:

```java
public class DatabaseConnector {
    private String url;

    public DatabaseConnector(String url) {
        this.url = url;
    }

    public void connect() {
        System.out.println("Kết nối đến cơ sở dữ liệu: " + url);
    }
}
```

Chúng ta muốn cấu hình thông tin về cơ sở dữ liệu từ bên ngoài ứng dụng. File `application.properties` sẽ chứa thông tin cấu hình:

```properties
loda.mysql.url=jdbc:mysql://host1:33060/loda
```

Tiếp theo, chúng ta cấu hình và sử dụng class `AppConfig` để sử dụng `@Value` để đọc giá trị từ file cấu hình và tạo bean `DatabaseConnector`:

```java
import org.springframework.beans.factory.annotation.Value;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

@Configuration
public class AppConfig {

    // Lấy giá trị cấu hình từ file application.properties
    @Value("${loda.mysql.url}")
    private String mysqlUrl;

    @Bean
    public DatabaseConnector mysqlConnector() {
        return new DatabaseConnector(mysqlUrl);
    }
}
```

Cuối cùng, chúng ta chạy ứng dụng và sử dụng bean `DatabaseConnector`:

```java
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.context.ApplicationContext;

@SpringBootApplication
public class App {
    public static void main(String[] args) {
        ApplicationContext context = SpringApplication.run(App.class, args);
        DatabaseConnector databaseConnector = context.getBean(DatabaseConnector.class);
        databaseConnector.connect();
    }
}
```

Kết quả khi chạy ứng dụng:

::result

Kết nối đến cơ sở dữ liệu: `jdbc:mysql://host1:33060/loda`

::

Ứng dụng đã chạy trên cổng 8081 và cấu hình thông tin cơ sở dữ liệu được đọc từ file `application.properties` và đưa vào bean `DatabaseConnector`.

::alert{type="result"}
Annotation `@Value` và cách cấu hình ứng dụng Spring Boot thông qua file `application.properties` cho phép bạn quản lý các giá trị cấu hình ứng dụng một cách linh hoạt và tùy chỉnh. Điều này giúp bạn dễ dàng thay đổi cấu hình giữa các môi trường khác nhau
::
