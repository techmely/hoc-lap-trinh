---
title: "Spring Boot Application Config và @Value annotation"
description: "Trong bài viết này, chúng ta sẽ tìm hiểu về cách cấu hình ứng dụng Spring Boot bằng cách sử dụng tệp application.properties và Annotation @Value"
chapter:
  name: "Spring Boot cơ bản"
  slug: "chuong-03-spring-boot-co-ban"
category:
  name: "Spring Boot"
  slug: "spring-boot"
position: 9
---

Trong thực tế, việc cấu hình ứng dụng thường không nên để mọi thông tin cứng cố định trong mã nguồn, mà nên được truyền từ bên ngoài vào ứng dụng. Điều này giúp ứng dụng của bạn linh hoạt hơn và dễ dàng thay đổi giữa các môi trường khác nhau. Trong bài viết này, chúng ta sẽ tìm hiểu về cách cấu hình ứng dụng Spring Boot bằng cách sử dụng tệp `application.properties` và Annotation `@Value`.

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

## Tệp application.properties

Trong Spring Boot, các thông tin cấu hình mặc định được lấy từ tệp `application.properties`. Ví dụ, bạn muốn ứng dụng chạy trên cổng 8081 thay vì 8080, bạn có thể chỉ định như sau trong tệp `application.properties`:

```properties
server.port = 8081
```

Hoặc nếu bạn muốn thiết lập cấp độ log của ứng dụng thành Debug, bạn có thể sử dụng:

```properties
logging.level.root=DEBUG
```

Tùy chỉnh các thuộc tính này trong `application.properties` cho phép bạn can thiệp vào các cấu hình của ứng dụng từ bên ngoài và thay đổi chúng dễ dàng cho các môi trường khác nhau.

## Annotation @Value

Trong trường hợp bạn muốn tự cấu hình một số giá trị riêng, Spring Boot hỗ trợ bạn thông qua Annotation `@Value`. Điều này cho phép bạn đọc các giá trị từ tệp `application.properties` và sử dụng chúng trong mã nguồn của bạn.

Ví dụ, bạn muốn cấu hình thông tin kết nối database của bạn từ bên ngoài ứng dụng. Trước hết, bạn định nghĩa các thông tin trong tệp `application.properties` như sau:

```properties
kungfutech.mysql.url=jdbc:mysql://host1:33060/kungfutech
```

Sau đó, bạn có thể sử dụng `@Value` để đọc giá trị này và sử dụng nó trong mã nguồn của bạn:

```java
import org.springframework.beans.factory.annotation.Value;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

@Configuration
public class AppConfig {

    // Sử dụng @Value để lấy giá trị từ application.properties
    @Value("${kungfutech.mysql.url}")
    String mysqlUrl;

    @Bean
    DatabaseConnector mysqlConfigure() {
        DatabaseConnector mySqlConnector = new MySqlConnector();

        // Sử dụng giá trị cấu hình
        mySqlConnector.setUrl(mysqlUrl);

        // Cài đặt các thông tin khác nếu cần
        return mySqlConnector;
    }
}
```

Trong ví dụ này, giá trị của `mysqlUrl` sẽ được đọc từ tệp `application.properties` và sử dụng để cấu hình kết nối database.

## Ví dụ

Dưới đây là ví dụ hoàn chỉnh:

### Tệp application.properties`

```properties
server.port = 8081
logging.level.root=INFO

kungfutech.mysql.url=jdbc:mysql://host1:33060/kungfutech
```

### Class `DatabaseConnector`

```java
public abstract class DatabaseConnector {
    private String url;

    public abstract void connect();

    public String getUrl() {
        return url;
    }

    public void setUrl(String url) {
        this.url = url;
    }
}
```

### Class `MySqlConnector`

```java
public class MySqlConnector extends DatabaseConnector {
    @Override
    public void connect() {
        System.out.println("Đã kết nối tới MySQL: " + getUrl());
    }
}
```

### Class `AppConfig`

```java
import org.springframework.beans.factory.annotation.Value;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

@Configuration
public class AppConfig {

    @Value("${kungfutech.mysql.url}")
    String mysqlUrl;

    @Bean
    DatabaseConnector mysqlConfigure() {
        DatabaseConnector mySqlConnector = new MySqlConnector();
        mySqlConnector.setUrl(mysqlUrl);
        return mySqlConnector;
    }
}
```

### Class `App`

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

Khi chạy ứng dụng, bạn sẽ thấy rằng ứng dụng đã chạy trên cổng 8081 và giá trị cấu hình đường dẫn MySQL đã được đọc từ tệp `application.properties` và sử dụng trong kết nối database.

::alert{type="success"}
Trong bài viết này, chúng ta đã tìm hiểu cách cấu hình ứng dụng Spring Boot bằng cách sử dụng tệp `application.properties` và Annotation `@Value`. Điều này cho phép bạn linh hoạt cấu hình ứng dụng của mình và dễ dàng thay đổi các thông số cho từng môi trường khác nhau.
::
