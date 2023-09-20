---
title: "Cấu hình ứng dụng với annotation"
description: "Spring Boot làm cho việc cấu hình Spring dễ dàng hơn với tính năng cấu hình tự động của nó. Các tính năng này phần lớn được sử dụng thông qua các annotation mà Spring Boot cung cấp."
chapter:
  name: "Tổng quan về Spring"
  slug: "chuong-01-tong-quan-ve-spring"
category:
  name: "Spring Boot"
  slug: "spring-boot"
image: https://kungfutech.edu.vn/thumbnail.png
position: 08
---

Cấu hình ứng dụng Spring bằng `Annotation` là một cách tiện lợi và hiệu quả để quản lý các thành phần và xử lý các yêu cầu HTTP. Annotation cho phép bạn đánh dấu các lớp và phương thức trong ứng dụng để Spring có thể tự động nhận biết và quản lý chúng. Trong bài viết này, chúng ta sẽ tìm hiểu cách cấu hình ứng dụng Spring bằng Annotation.

## Sử dụng Annotation trong ứng dụng Spring

Để sử dụng Annotation trong ứng dụng Spring, bạn cần bao gồm `spring-context` trong các phụ thuộc của dự án của bạn. Sau đó, bạn có thể sử dụng các Annotation như sau:

- `@Controller`: Đánh dấu một lớp là một Controller trong ứng dụng Spring MVC. Controllers xử lý các yêu cầu HTTP từ người dùng.
- `@RequestMapping`: Đánh dấu một phương thức là một xử lý cho một URL cụ thể. Bạn có thể chỉ định URL hoặc HTTP method (GET, POST, PUT, DELETE) mà phương thức sẽ xử lý.
- `@Autowired`: Đánh dấu một trường hoặc phương thức là một dependency mà Spring sẽ tự động tiêm (inject) vào đối tượng đó.
- `@Service`: Đánh dấu một lớp là một dịch vụ (Service) trong ứng dụng Spring. Services chứa logic kinh doanh và thường được sử dụng bởi Controllers.
- `@Repository`: Đánh dấu một lớp là một Repository trong ứng dụng Spring. Repositories thường sử dụng để truy cập cơ sở dữ liệu.
- `@Component`: Đánh dấu một lớp là một thành phần (Component) trong ứng dụng Spring. Annotation này là một cách tự định nghĩa các bean.

## Cấu hình ứng dụng với Annotation

Để cấu hình ứng dụng Spring bằng Annotation, bạn cần thực hiện các bước sau:

### Bước 1: Bao gồm các phụ thuộc

Trong tệp `pom.xml` của dự án Maven, bạn cần bao gồm `spring-context` để sử dụng Annotation.

```xml
<dependency>
    <groupId>org.springframework</groupId>
    <artifactId>spring-context</artifactId>
    <version>5.3.10</version> <!-- Sử dụng phiên bản Spring mới nhất -->
</dependency>
```

### Bước 2: Cấu hình Annotation

Trong tệp cấu hình `dispatcher-servlet.xml` (hoặc tệp cấu hình chính của ứng dụng), bạn cần thêm cấu hình để sử dụng Annotation.

```xml
<!-- Cho phép sử dụng Annotation -->
<context:component-scan base-package="ten_goi_goi_cac_linh_vuc_controller"/>
<mvc:annotation-driven/>
```

Trong đó, `<context:component-scan>` cho phép Spring quét và tìm các lớp và phương thức được đánh dấu bởi Annotation trong gói `ten_goi_goi_cac_linh_vuc_controller`.

### Bước 3: Sử dụng Annotation trong mã nguồn

Sau khi đã cấu hình, bạn có thể sử dụng các Annotation như `@Controller`, `@RequestMapping`, `@Autowired`, `@Service`, và `@Repository` trong mã nguồn của bạn. Ví dụ:

```java
@Controller
public class MyController {

    @RequestMapping("/hello")
    public String sayHello() {
        return "hello";
    }
}

@Service
public class MyService {

    public String getMessage() {
        return "Hello from MyService!";
    }
}

@Repository
public class MyRepository {

    public String getData() {
        return "Data from MyRepository";
    }
}
```

Trong ví dụ trên, `@Controller` đánh dấu lớp `MyController` là một Controller và `@RequestMapping` đánh dấu phương thức `sayHello()` để xử lý URL "/hello". `@Service` và `@Repository` đánh dấu lớp `MyService` và `MyRepository` là các dịch vụ và kho dữ liệu (repository) tương ứng.

Điều này cho phép Spring tự động quản lý các Controller, Services, và Repositories và ánh xạ chúng với các URL và dependencies.

::alert{type="success"}
Cấu hình ứng dụng Spring bằng Annotation là một cách tiện lợi và sáng sủa để quản lý các thành phần và xử lý các yêu cầu HTTP trong ứng dụng Spring. Annotation giúp bạn đánh dấu
::
