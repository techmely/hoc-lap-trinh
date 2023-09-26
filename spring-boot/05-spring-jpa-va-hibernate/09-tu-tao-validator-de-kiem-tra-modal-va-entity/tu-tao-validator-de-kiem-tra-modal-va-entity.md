---
title: "Tự tạo Validator để kiểm tra Model và Entity"
description: "Hibernate và Java đã cung cấp cho chúng ta nhiều Annotation để kiểm tra dữ liệu của model. Nhưng đôi khi, chúng ta cần kiểm tra các điều kiện cụ thể phù hợp với logic kinh doanh của dự án. Để làm điều này, chúng ta có thể tự tạo Validator riêng cho mình"
chapter:
  name: "Spring JPA và Hibernate"
  slug: "chuong-05-spring-jpa-va-hibernate"
category:
  name: "SpringBoots"
  slug: "springboots"
image: https://kungfutech.edu.vn/thumbnail.png
position: 9
---

Hibernate và Java đã cung cấp cho chúng ta nhiều Annotation để kiểm tra dữ liệu của model. Nhưng đôi khi, chúng ta cần kiểm tra các điều kiện cụ thể phù hợp với logic kinh doanh của dự án. Để làm điều này, chúng ta có thể tự tạo Validator riêng cho mình. Trong bài viết này, chúng tôi sẽ hướng dẫn bạn cách tự tạo Validator bằng Hibernate Validator và Spring Boot.

## Cài đặt

Trước khi tạo Validator, chúng ta cần chuẩn bị một số thành phần cơ bản.

### Tạo Model

Chúng ta sẽ sử dụng một model đơn giản là `User` như sau:

```java
@Data
public class User {
    private String lodaId;
}
```

### Tạo Controller

Chúng ta cần một Controller để giao tiếp với client:

```java
@RestController
@RequestMapping("api/v1/users")
public class UserController {

    @PostMapping
    public Object createUser(@Valid @RequestBody User user) {
        return user;
    }
}
```

### Cài đặt Hibernate Validator

Chúng ta cần thêm Hibernate Validator vào Maven `pom.xml`:

```xml
<dependency>
    <groupId>org.hibernate</groupId>
    <artifactId>hibernate-validator</artifactId>
    <version>6.1.0.Final</version>
</dependency>
```

## Tạo Annotation

### Định nghĩa Annotation

Đầu tiên, chúng ta cần định nghĩa một Annotation mới. Trong ví dụ này, chúng ta sẽ tạo Annotation `@LodaId` để kiểm tra tính hợp lệ của trường `lodaId`:

```java
@Documented
@Constraint(validatedBy = LodaIdValidator.class)
@Target({ElementType.METHOD, ElementType.FIELD})
@Retention(RetentionPolicy.RUNTIME)
public @interface LodaId {
    String message() default "LodaId must start with loda://";
    Class<?>[] groups() default {};
    Class<? extends Payload>[] payload() default {};
}
```

### Gắn Annotation lên Model

Bây giờ, chúng ta có thể gắn `@LodaId` lên trường cần kiểm tra tính hợp lệ trong model `User`:

```java
@Data
public class User {
    @LodaId
    private String lodaId;
}
```

## Tạo Validator

Sau khi đã tạo Annotation, chúng ta cần tạo một Validator để kiểm tra tính hợp lệ của trường dựa trên `@LodaId`. Validator này sẽ kiểm tra xem trường `lodaId` có bắt đầu bằng chuỗi "loda://" hay không.

```java
import javax.validation.ConstraintValidator;
import javax.validation.ConstraintValidatorContext;

public class LodaIdValidator implements ConstraintValidator<LodaId, String> {
    private static final String LODA_PREFIX = "loda://";

    @Override
    public boolean isValid(String s, ConstraintValidatorContext constraintValidatorContext) {
        if (s == null || s.isEmpty()) return false;

        return s.startsWith(LODA_PREFIX);
    }
}
```

## Chạy thử

Bây giờ, chúng ta có thể thực hiện kiểm tra tính hợp lệ của trường `lodaId` trong `User` thông qua `@LodaId` Annotation. Dưới đây là kết quả của việc chạy thử các request:

### Request một User hợp lệ

**Request:**

```json
{
  "lodaId": "loda://user_1"
}
```

**Kết quả (200 OK):**

```json
{
  "lodaId": "loda://user_1"
}
```

### Request một User không hợp lệ:

**Request:**

```json
{
  "lodaId": "Laula://user_1"
}
```

**Kết quả (400 Bad Request):**

```json
{
  "timestamp": "2019-12-19T10:26:14.554+0000",
  "status": 400,
  "error": "Bad Request",
  "errors": [
    {
      "codes": [
        "LodaId.user.lodaId",
        "LodaId.lodaId",
        "LodaId.java.lang.String",
        "LodaId"
      ],
      "arguments": [
        {
          "codes": ["user.lodaId", "lodaId"],
          "arguments": null,
          "defaultMessage": "lodaId",
          "code": "lodaId"
        }
      ],
      "defaultMessage": "LodaId must start with loda://",
      "objectName": "user",
      "field": "lodaId",
      "rejectedValue": "Laula://user_1",
      "bindingFailure": false,
      "code": "LodaId"
    }
  ],
  "message": "Validation failed for object='user'. Error count: 1",
  "path": "/api/v1/users"
}
```

::alert{type="success"}
Việc tự tạo Validator cho model và entity trong ứng dụng Spring Boot sử dụng Hibernate Validator rất đơn giản và mạnh mẽ. Bằng cách sử dụng Annotation và Validator tùy chỉnh, bạn có thể kiểm tra tính hợp lệ của dữ liệu dựa trên logic kinh doanh của dự án một cách dễ dàng và hiệu quả. Điều này giúp bảo đảm tính toàn vẹn của dữ liệu và cải thiện chất lượng của ứng dụng của bạn.
::
