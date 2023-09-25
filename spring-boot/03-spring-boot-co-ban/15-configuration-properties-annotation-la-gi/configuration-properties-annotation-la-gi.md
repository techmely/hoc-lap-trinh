---
title: "@ConfigurationProperties annotation là gì"
description: "Spring Boot giúp bạn dễ dàng cấu hình ứng dụng từ bên ngoài và truy xuất các thông tin cấu hình này một cách tiện lợi. Trong bài viết này, chúng ta sẽ tìm hiểu về @ConfigurationProperties, một annotation quan trọng trong Spring Boot, cung cấp một cách khoa học để quản lý cấu hình của ứng dụng"
chapter:
  name: "Spring Boot cơ bản"
  slug: "chuong-03-spring-boot-co-ban"
category:
  name: "Spring Boot"
  slug: "spring-boot"
position: 15
---

**Spring Boot** giúp bạn dễ dàng cấu hình ứng dụng từ bên ngoài và truy xuất các thông tin cấu hình này một cách tiện lợi. Trong bài viết này, chúng ta sẽ tìm hiểu về **@ConfigurationProperties**, một annotation quan trọng trong Spring Boot, cung cấp một cách khoa học để quản lý cấu hình của ứng dụng. Bây giờ, chúng ta sẽ đi sâu hơn vào việc quản lý cấu hình ứng dụng.

## Cài Đặt

Để sử dụng **@ConfigurationProperties**, chúng ta cần thêm dependency cho Spring Boot Web vào file **pom.xml**:

```xml
<dependency>
    <groupId>org.springframework.boot</groupId>
    <artifactId>spring-boot-starter-web</artifactId>
</dependency>
```

### Cấu Hình Đơn Giản

Giả sử bạn muốn ứng dụng của mình có một số giá trị toàn cục, chẳng hạn như email và ID của Google Analytics, mà bạn muốn lưu chúng ở bên ngoài ứng dụng để dễ dàng thay đổi. Để làm điều này, bạn có thể sử dụng **@ConfigurationProperties**.

Chúng ta sẽ tạo một class **LodaAppProperties** chứa các thông tin này:

```java
@Data
@Component
@ConfigurationProperties(prefix = "loda")
public class LodaAppProperties {
    private String email;
    private String googleAnalyticsId;
}
```

Trong đoạn code trên:

- **@Component**: Đánh dấu class này là một Spring bean, cho phép Spring quản lý nó.

- **@ConfigurationProperties**: Đánh dấu class bên dưới nó là một properties class. Các thuộc tính trong class này sẽ tự động nạp giá trị từ cấu hình ứng dụng.

Lưu ý: Các thuộc tính trong class phải có các setter method tương ứng.

Để kích hoạt tính năng này, bạn cần thêm annotation **@EnableConfigurationProperties** vào một configuration nào đó trong ứng dụng. Thường là annotation này được gắn lên hàm main của ứng dụng:

```java
@SpringBootApplication
@EnableConfigurationProperties
public class App {
    public static void main(String[] args) {
        SpringApplication.run(App.class, args);
    }
}
```

Sau đó, bạn cần tạo một file **application.yml** trong thư mục **resources** để chứa cấu hình:

```yml
loda:
  email: loda.namnh@gmail.com
  googleAnalyticsId: U-xxxxx
```

### Sử Dụng Cấu Hình

Bây giờ, bạn có thể sử dụng **LodaAppProperties** để truy xuất các giá trị cấu hình từ bên ngoài ứng dụng một cách dễ dàng. Ví dụ:

```java
@Autowired LodaAppProperties lodaAppProperties;

public void someMethod() {
    System.out.println("Email: " + lodaAppProperties.getEmail());
    System.out.println("Google Analytics ID: " + lodaAppProperties.getGoogleAnalyticsId());
}
```

Các giá trị cấu hình này sẽ tự động được nạp vào các thuộc tính tương ứng trong **LodaAppProperties** từ file **application.yml**.

### Nested Properties

Bạn có thể cấu hình các thuộc tính bên trong class, kể cả khi chúng là các danh sách (Lists), bản đồ (Maps) hoặc một class khác. Ví dụ:

```java
@Data
@Component
@ConfigurationProperties(prefix = "loda")
public class LodaAppProperties {
    private String email;
    private String googleAnalyticsId;
    private List<String> authors;
    private Map<String, String> exampleMap;
}
```

Và cấu hình trong file **application.yml**:

```yml
loda:
  email: loda.namnh@gmail.com
  googleAnalyticsId: U-xxxxx
  authors:
    - loda
    - atom
  exampleMap:
    key1: hello
    key2: world
```

Khi bạn sử dụng **LodaAppProperties**, các thuộc tính **authors** và **exampleMap** sẽ chứa các giá trị từ cấu hình tương ứng.

::alert{type="success"}

Trong bài viết này, chúng ta đã tìm hiểu về **@ConfigurationProperties**, một annotation quan trọng trong Spring Boot cho phép bạn quản lý cấu hình ứng dụng dễ dàng hơn. Điều này giúp bạn kiểm soát và thay đổi cấu hình một cách linh hoạt mà không cần thay đổi code.

::
