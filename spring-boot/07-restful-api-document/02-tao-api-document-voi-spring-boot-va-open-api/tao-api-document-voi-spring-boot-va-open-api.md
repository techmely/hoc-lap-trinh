---
title: "Tạo API Document với Spring Boot và OpenApi 3.0"
description: "Trong bài này, chúng ta sẽ tiến xa hơn bằng cách giới thiệu phiên bản mới nhất của tiêu chuẩn RESTful document, đó là OpenAPI 3.0"
chapter:
  name: "RESTful API Document"
  slug: "chuong-07-restful-api-document"
category:
  name: "SpringBoots"
  slug: "springboots"
image: https://kungfutech.edu.vn/thumbnail.png
position: 2
---

Trong bài viết trước, chúng ta đã tìm hiểu về cách tạo tài liệu cho [RESTful API bằng cách sử dụng Swagger 2](/bai-viet/spring-boot/tao-api-document-voi-spring-boot-va-swagger). Tuy nhiên, trong bài này, chúng ta sẽ tiến xa hơn bằng cách giới thiệu phiên bản mới nhất của tiêu chuẩn RESTful document, đó là OpenAPI 3.0.

Tại sao không gọi là Swagger 3? Câu trả lời đằng sau là việc SmartBear mua lại Swagger và chuyển tên Swagger Specification thành OpenAPI Specification, đồng thời bắt đầu tạo ra các tiêu chuẩn mới cho việc xây dựng tài liệu document. Tuy nhiên, OpenAPI 3.0 vẫn được xây dựng dựa trên nền tảng core của Swagger.

OpenAPI 3.0 là phiên bản mới nhất của tiêu chuẩn tại thời điểm viết bài này.

## Cài đặt OpenAPI 3.0 trong dự án Spring Boot

Để sử dụng OpenAPI 3.0 trong dự án Spring Boot của bạn, bạn cần thêm các phụ thuộc (dependencies) liên quan vào tệp `pom.xml`. Dưới đây là một ví dụ về cách thêm các phụ thuộc cho OpenAPI 3.0 vào dự án Spring Boot:

```xml
<dependencies>
    <!-- Các phụ thuộc khác -->
    <dependency>
        <groupId>org.springdoc</groupId>
        <artifactId>springdoc-openapi-core</artifactId>
        <version>1.1.49</version>
    </dependency>
    <dependency>
        <groupId>org.springdoc</groupId>
        <artifactId>springdoc-openapi-ui</artifactId>
        <version>1.1.49</version>
    </dependency>
</dependencies>
```

Sau khi thêm các phụ thuộc này, dự án của bạn đã sẵn sàng để sử dụng OpenAPI 3.0.

## Cấu hình OpenAPI 3.0

Bây giờ, chúng ta sẽ cấu hình OpenAPI 3.0 trong dự án Spring Boot của mình. Đầu tiên, bạn cần tạo một lớp cấu hình (configuration class) để định cấu hình OpenAPI.

```java
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springdoc.core.GroupedOpenApi;
import org.springdoc.core.SwaggerUiConfigParameters;
import org.springdoc.webmvc.ui.SwaggerConfig;
import org.springdoc.webmvc.ui.SwaggerUiConfigParameters.SwaggerUiOAuth2ConfigParameters;
import org.springdoc.webmvc.ui.SwaggerUiConfigParameters.SwaggerUiSupportConfigParameters;

@Configuration
public class OpenApiConfig {

    @Bean
    public GroupedOpenApi publicApi() {
        return GroupedOpenApi.builder()
            .group("public")
            .packagesToScan("your.package.name")
            .build();
    }

    @Bean
    public SwaggerUiConfigParameters swaggerUiConfigParameters() {
        return new SwaggerUiConfigParameters()
            .withDefaultModelRendering(SwaggerUiConfigParameters.ModelRendering.EXAMPLE)
            .withDeepLinking(true)
            .withDisplayOperationId(false)
            .withDisplayRequestDuration(false)
            .withDocExpansion(SwaggerUiConfigParameters.DocExpansion.NONE)
            .withFilter(false)
            .withLayout(SwaggerUiConfigParameters.Layout.DOC)
            .withOauth2(new SwaggerUiOAuth2ConfigParameters())
            .withOperationsSorter(SwaggerUiConfigParameters.OperationsSorter.ALPHA)
            .withShowExtensions(false)
            .withShowCommonExtensions(false)
            .withSupportHeaderParams(true)
            .withSupportCredentials(true)
            .withTagsSorter(SwaggerUiConfigParameters.TagsSorter.ALPHA)
            .withUiSorter(SwaggerUiConfigParameters.UiSorter.ALPHA)
            .withValidatorUrl(null)
            .withWithCredentials(false)
            .withRequestTimeout(null)
            .withPresets(Arrays.asList(SwaggerUiConfigParameters.Preset.MOBILE, SwaggerUiConfigParameters.Preset.SUPPORTED_METHODS))
            .withHideDownloadUrl(false)
            .withHideDownloadButton(false)
            .withMaxDisplayedTags(null)
            .withOperationsSorter(SwaggerUiConfigParameters.OperationsSorter.ALPHA)
            .withPersistAuthorization(true)
            .withShowCommonExtensions(false)
            .withShowExtensions(false)
            .withSwaggerUiSupportConfig(new SwaggerUiSupportConfigParameters());
    }
}
```

Trong mã nguồn trên:

- `publicApi()` tạo một nhóm (group) OpenAPI cho các API công khai. Bạn có thể thay đổi package quét (`packagesToScan`) để chọn các package chứa các API của bạn.
- `swaggerUiConfigParameters()` cung cấp cấu hình cho giao diện Swagger UI.

## Sử dụng OpenAPI Annotations

OpenAPI cho phép bạn sử dụng các chú thích (annotations) để mô tả API của bạn. Dưới đây là một ví dụ về cách sử dụng các annotations trong mã ng

uồn của bạn:

```java
import org.springframework.web.bind.annotation.*;
import javax.validation.Valid;
import java.util.List;

@RestController
@RequestMapping("/api/v1")
public class UserController {
    private final UserRepository userRepository;

    @Operation(summary = "Xem danh sách User")
    @ApiResponses(value = {
            @ApiResponse(responseCode = "200", description = "Thành công"),
            @ApiResponse(responseCode = "401", description = "Chưa xác thực"),
            @ApiResponse(responseCode = "403", description = "Truy cập bị cấm"),
            @ApiResponse(responseCode = "404", description = "Không tìm thấy")
    })
    @GetMapping("/users")
    public List<User> getAllUsers() {
        return userRepository.findAll();
    }

    @GetMapping("/users/{id}")
    public User getUser(@PathVariable("id") Long id) {
        return userRepository.findById(id).orElse(new User());
    }

    @PostMapping("/users")
    public User createUser(
            @Valid
            @RequestBody User user) {
        return userRepository.save(user);
    }

    @PutMapping("/users/{id}")
    public User updateUser(@PathVariable("id") Long id, @Valid @RequestBody User user) {
        user.setId(id);
        return userRepository.save(user);
    }

    @DeleteMapping("/users/{id}")
    public void deleteUser(@PathVariable("id") Long id) {
        userRepository.deleteById(id);
    }
}
```

Trong mã nguồn trên:

- `@Operation` mô tả một phương thức API.
- `@ApiResponse` mô tả các phản hồi mà phương thức có thể tạo ra, bao gồm mã trạng thái và mô tả.

## Kết quả

Bây giờ, khi bạn chạy ứng dụng Spring Boot và truy cập địa chỉ `http://localhost:8080/swagger-ui.html`, bạn sẽ thấy tài liệu mô tả API của bạn được hiển thị trên giao diện web Swagger UI. Bạn có thể xem các phương thức API, thử nghiệm chúng và kiểm tra các thông tin mô tả.

::alert{type="success"}
OpenAPI 3.0 là một công cụ mạnh mẽ giúp tạo tài liệu mô tả cho các API trong dự án Spring Boot của bạn. Bằng cách sử dụng các annotations và cấu hình cơ bản, bạn có thể tạo tài liệu mô tả API một cách dễ dàng và tiện lợi. Điều này giúp cho việc phát triển và sử dụng API của bạn trở nên hiệu quả và dễ dàng hơn.
::
