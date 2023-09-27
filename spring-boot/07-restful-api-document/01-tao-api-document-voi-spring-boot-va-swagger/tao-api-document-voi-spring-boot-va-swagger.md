---
title: "Tạo API Document với Spring Boot và swagger"
description: "Spring Boot là một framework mạnh mẽ cho phát triển ứng dụng Java, và nó cho phép chúng ta tạo RESTful API một cách nhanh chóng và tiện lợi. Tuy nhiên, việc tạo API chỉ là một phần của công việc"
chapter:
  name: "RESTful API Document"
  slug: "chuong-07-restful-api-document"
image: https://kungfutech.edu.vn/thumbnail.png
position: 1
---

Spring Boot là một framework mạnh mẽ cho phát triển ứng dụng Java, và nó cho phép chúng ta tạo RESTful API một cách nhanh chóng và tiện lợi. Tuy nhiên, việc tạo API chỉ là một phần của công việc. Việc tạo tài liệu mô tả API để cho phép các nhà phát triển khác hiểu cách sử dụng API của bạn cũng quan trọng không kém.

Trong bài viết này, chúng ta sẽ tìm hiểu cách sử dụng Swagger để tạo tài liệu API một cách dễ dàng và tiện lợi trong dự án Spring Boot.

## Giới thiệu về Swagger

Swagger là một framework phổ biến được sử dụng để tạo tài liệu mô tả cho các dự án API. Nó cho phép bạn mô tả API của mình bằng các chú thích (annotations) trong mã nguồn Java, sau đó tự động tạo ra tài liệu API dưới dạng trang web dễ đọc.

Swagger hỗ trợ việc quản lý tài liệu API, bao gồm:

- Tự động tạo tài liệu API từ mã nguồn Java.
- Hỗ trợ mô tả các request, response, parameter, và các thông tin khác của API.
- Cho phép thử nghiệm API trực tiếp từ tài liệu mô tả.
- Hỗ trợ nhiều phiên bản API khác nhau.
- Tích hợp với các công cụ khác như Postman để kiểm tra API.

## Cài đặt Swagger trong dự án Spring Boot

Để sử dụng Swagger trong dự án Spring Boot của bạn, bạn cần thêm các phụ thuộc (dependencies) liên quan vào tệp `pom.xml`. Dưới đây là một ví dụ về cách thêm các phụ thuộc cho Swagger vào dự án Spring Boot:

```xml
<dependencies>
    <!-- Các phụ thuộc khác -->
    <dependency>
        <groupId>io.springfox</groupId>
        <artifactId>springfox-swagger2</artifactId>
        <version>2.9.2</version>
    </dependency>
    <dependency>
        <groupId>io.springfox</groupId>
        <artifactId>springfox-swagger-ui</artifactId>
        <version>2.9.2</version>
    </dependency>
</dependencies>
```

Sau khi thêm các phụ thuộc này, dự án của bạn đã sẵn sàng để sử dụng Swagger.

## Cấu hình Swagger

Bây giờ, chúng ta sẽ cấu hình Swagger trong dự án Spring Boot của mình. Đầu tiên, bạn cần tạo một lớp cấu hình (configuration class) để định cấu hình Swagger.

```java
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import springfox.documentation.builders.ApiInfoBuilder;
import springfox.documentation.builders.PathSelectors;
import springfox.documentation.builders.RequestHandlerSelectors;
import springfox.documentation.spi.DocumentationType;
import springfox.documentation.spring.web.plugins.Docket;
import springfox.documentation.swagger2.annotations.EnableSwagger2;

@Configuration
@EnableSwagger2
public class SwaggerConfig {

    @Bean
    public Docket api() {
        return new Docket(DocumentationType.SWAGGER_2)
            .select()
            .apis(RequestHandlerSelectors.basePackage("your.package.name"))
            .paths(PathSelectors.any())
            .build()
            .apiInfo(apiInfo());
    }

    private ApiInfo apiInfo() {
        return new ApiInfoBuilder()
            .title("Your API Title")
            .description("Your API Description")
            .version("1.0")
            .build();
    }
}
```

Trong mã nguồn trên:

- Chúng ta sử dụng `@Configuration` để đánh dấu lớp này là một lớp cấu hình.
- `@EnableSwagger2` được sử dụng để kích hoạt Swagger trong dự án.
- Phương thức `api()` tạo ra một đối tượng `Docket`, mà làm nhiệm vụ cấu hình Swagger.
- `.apis(RequestHandlerSelectors.basePackage("your.package.name"))` chỉ định package chứa các API mà bạn muốn Swagger tạo tài liệu cho.
- `.paths(PathSelectors.any())` cho phép Swagger tạo tài liệu cho tất cả các endpoint.
- `apiInfo()` tạo ra thông tin tài liệu API như tiêu đề, mô tả và phiên bản.

## Sử dụng Swagger Annotations

Swagger cho phép bạn sử dụng các chú thích (annotations) để mô tả API của bạn. Dưới đây là một ví dụ về cách sử dụng các annotations cơ bản trong mã nguồn Java:

```java
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import io.swagger.annotations.ApiResponse;
import io.swagger.annotations.ApiResponses;
import org.springframework.web.bind.annotation.*;

import java.util.List;

@RestController
@RequestMapping("/api/users")
@Api(value = "User Management System", description = "Operations pertaining to user management")
public class UserController {

    @ApiOperation(value = "View a list of available users", response = List.class)
    @ApiResponses(value = {
            @ApiResponse(code = 200, message = "Successfully retrieved list"),
            @ApiResponse(code = 401, message = "You are not authorized to view the resource"),
            @ApiResponse(code = 403, message = "Accessing the resource you were trying to reach is forbidden"),
            @ApiResponse(code = 404, message = "The resource you were trying to reach is not found")
    })
    @GetMapping("/")
    public List<User> getAllUsers() {
        return userService.getAllUsers();
    }

    // Các phương thức khác
}
```

Trong ví dụ trên:

- `@Api` đánh dấu lớp controller là một phần của hệ thống quản lý người dùng và cung cấp mô tả về chức năng của nó.
- `@ApiOperation` mô tả một phương thức và cung cấp thông tin về việc nó thực hiện.
- `@ApiResponses` mô tả các phản hồi mà phương thức có thể tạo ra, bao gồm mã trạng thái và thông điệp.

## Kết quả

Bây giờ, khi bạn chạy ứng dụng Spring Boot và truy cập địa chỉ `http://localhost:8080/swagger-ui.html`, bạn sẽ thấy tài liệu mô tả API của bạn được hiển thị trên giao diện web Swagger UI. Bạn có thể xem các phương thức API, thử nghiệm chúng và kiểm tra các thông tin mô tả.

::alert{type="success"}
Swagger là một công cụ mạnh mẽ giúp tạo tài liệu mô tả cho các API trong dự án Spring Boot của bạn. Bằng cách sử dụng các annotations và cấu hình cơ bản, bạn có thể tạo ra tài liệu mô tả API một cách dễ dàng và tiện lợi. Điều này giúp cho việc phát triển và sử dụng API của bạn trở nên hiệu quả và dễ dàng hơn.
::
