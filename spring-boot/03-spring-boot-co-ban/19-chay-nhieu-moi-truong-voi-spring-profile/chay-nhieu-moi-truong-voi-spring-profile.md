---
title: "Chạy nhiều môi trường với Spring Profile"
description: "Spring Boot cung cấp một giải pháp mạnh mẽ cho vấn đề này thông qua Spring Profiles. Trong bài viết này, chúng ta sẽ tìm hiểu về cách sử dụng Spring Profiles để quản lý cấu hình ứng dụng của bạn dựa trên môi trường mà bạn đang chạy"
chapter:
  name: "Spring Boot cơ bản"
  slug: "chuong-03-spring-boot-co-ban"
category:
  name: "Spring Boot"
  slug: "spring-boot"
position: 19
---

Trong lập trình ứng dụng, việc quản lý cấu hình và chạy ứng dụng trên nhiều môi trường khác nhau là một nhiệm vụ quan trọng. Điều này đặc biệt đúng trong các ứng dụng Spring Boot, nơi bạn có thể cần cấu hình các thông số như cơ sở dữ liệu, cấu hình bản ghi, cài đặt bật/tắt và nhiều điều khác tùy thuộc vào môi trường cụ thể.

Spring Boot cung cấp một giải pháp mạnh mẽ cho vấn đề này thông qua Spring Profiles. Trong bài viết này, chúng ta sẽ tìm hiểu về cách sử dụng Spring Profiles để quản lý cấu hình ứng dụng của bạn dựa trên môi trường mà bạn đang chạy.

## Giới thiệu về Spring Profiles

Spring Profiles là một tính năng quan trọng của Spring Framework, cho phép bạn quản lý và cấu hình ứng dụng dựa trên môi trường mà bạn đang chạy. Một môi trường có thể tương ứng với một tập hợp cụ thể các cài đặt, tài nguyên và thiết lập.

Ví dụ về các môi trường khác nhau có thể bao gồm:

- `local`: Môi trường phát triển trên máy tính cá nhân.
- `dev`: Môi trường phát triển trên máy chủ phát triển.
- `qa`: Môi trường kiểm tra chất lượng.
- `staging`: Môi trường trình dựng trước sản xuất.
- `production`: Môi trường sản xuất thực tế.

Mỗi môi trường này có thể có các cấu hình khác nhau, chẳng hạn như cơ sở dữ liệu, cài đặt bản ghi, cấu hình bật/tắt, và nhiều thông số khác.

## Cách sử dụng Spring Profiles

### Tạo các tệp cấu hình cho từng Profile

Để sử dụng Spring Profiles, bạn cần tạo các tệp cấu hình cho từng profile tương ứng. Các tệp cấu hình này phải được đặt tên theo mẫu `application-{profile-name}.properties` hoặc `application-{profile-name}.yml`. Ví dụ, nếu bạn có môi trường `local` và `production`, bạn có thể tạo các tệp `application-local.properties`, `application-production.properties`, hoặc tương tự cho các tệp `.yml`.

### Cấu hình Profiles mặc định

Bạn cũng có thể cấu hình một profile mặc định bằng cách sử dụng thuộc tính `spring.profiles.active` trong tệp `application.properties` hoặc `application.yml`. Nếu không có profile nào được kích hoạt, Spring Boot sẽ sử dụng profile mặc định này.

```properties
spring.profiles.active=local
```

### Sử dụng Profiles trong mã nguồn

Để sử dụng Spring Profiles trong mã nguồn của bạn, bạn có thể sử dụng annotation `@Profile` để chỉ định rằng một bean hoặc một thành phần cụ thể chỉ nên được tạo ra khi một profile cụ thể được kích hoạt.

```java
@Component
@Profile("local")
public class LocalDatasourceConfig {
    // Cấu hình dành cho profile "local"
}
```

Ngoài ra, bạn có thể sử dụng toán tử logic trong `@Profile` để xác định khi nào bean nên hoặc không nên được tạo ra.

```java
@Component
@Profile("!local")
public class ProductionDatasourceConfig {
    // Cấu hình dành cho các profile khác ngoại trừ "local"
}
```

### Kích hoạt Profiles

Có nhiều cách để kích hoạt các profile khi chạy ứng dụng Spring Boot. Dưới đây là một số trong những cách phổ biến:

- Sử dụng JVM System Parameter: Bạn có thể sử dụng tùy chọn dòng lệnh `-Dspring.profiles.active` để chỉ định profile bạn muốn kích hoạt.

```bash
java -jar your-app.jar -Dspring.profiles.active=local
```

- Sử dụng Environment Variable (Unix): Bạn có thể đặt biến môi trường `SPRING_PROFILES_ACTIVE` trước khi chạy ứng dụng.

```bash
export SPRING_PROFILES_ACTIVE=local
```

- Sử dụng annotation `@ActiveProfiles` trong JUnit tests: Đối với việc kiểm tra đơn vị, bạn có thể sử dụng annotation `@ActiveProfiles` để kích hoạt các profile cụ thể cho các bài kiểm tra.

```java
  @RunWith(SpringJUnit4ClassRunner.class)
  @SpringApplicationConfiguration(classes = YourApplication.class)
  @ActiveProfiles("test")
  public class YourTest {
    // Bài kiểm tra của bạn ở đây
  }
```

### Chạy ứng dụng với Profiles

Khi bạn đã cấu hình và kích hoạt các profile, bạn có thể chạy ứng dụng Spring Boot với các cấu hình tương ứng với profile mà bạn đã chọn.

Dưới đây là một ví dụ về cách chạy ứng dụng Spring Boot trong mã nguồn và kiểm tra kết quả:

```java
public static void main(String[] args) {
  SpringApplication application = new SpringApplication(YourApplication.class);
  ConfigurableEnvironment environment = new StandardEnvironment();
  environment.setActiveProfiles("local"); // Thay đổi profile ở đây
  application.setEnvironment(environment);
  ApplicationContext context = application.run(args);

  // Kiểm tra kết quả
  LocalDatasource localDatasource = context.getBean(LocalDatasource.class);
  System.out.println(localDatasource);
}
```

### Ví dụ thực tế

Hãy xem một ví dụ cụ thể về việc sử dụng Spring Profiles trong một ứng dụng Spring Boot.

#### Tạo Model

Trong ví dụ này, chúng ta tạo một class `LocalDatasource` để biểu thị dữ liệu của cơ sở dữ liệu cục bộ, và chúng ta chỉ muốn nó được tạo ra khi profile `local` được kích hoạt.

```java
@Data
@AllArgsConstructor
public class LocalDatasource {
    private String url;
}
```

#### Cấu hình Profiles

Chúng ta cũng cần tạo một cấu hình cho profile `local`. Class `LocalDatasourceConfig` chỉ được tạo ra khi profile này được kích hoạt.

```java
@Configuration
@Profile("local")
public class LocalDatasourceConfig {

    @Bean
    public LocalDatasource localDatasource() {
        return new LocalDatasource("Local object, Chỉ khởi tạo khi 'local' profile active");
    }
}
```

#### Chạy ứng dụng

Cuối cùng, trong mã nguồn, chúng ta chạy ứng dụng với profile `local` và kiểm tra kết quả.

```java
public static void main(String[] args) {
    SpringApplication application = new SpringApplication(App.class);
    ConfigurableEnvironment environment = new StandardEnvironment();
    environment.setActiveProfiles("local"); // Chỉnh profile ở đây
    application.setEnvironment(environment);
    ApplicationContext context = application.run(args);

    LocalDatasource localDatasource = context.getBean(LocalDatasource.class);
    System.out.println(localDatasource);
}
```

Khi chạy ứng dụng với profile `local`, bean `LocalDatasource` sẽ được tạo ra và kết quả được in ra màn hình.

Kết quả của đoạn mã trên khi chạy với profile `local` sẽ là:

::result
LocalDatasource(url=Local object, Chỉ khởi tạo khi 'local' profile active)
::

Như bạn có thể thấy, chúng ta đã thành công trong việc kích hoạt và sử dụng Spring Profiles trong ứng dụng Spring Boot của mình.

::alert{type="success"}
Spring Profiles là một tính năng mạnh mẽ cho phép bạn quản lý và cấu hình ứng dụng của mình dựa trên các môi trường khác nhau một cách hiệu quả. Bằng cách tận dụng Spring Profiles, bạn có khả năng thích ứng ứng dụng của mình cho nhiều môi trường và kịch bản khác nhau mà không cần phải thay đổi mã nguồn chính. Điều này giúp giảm thiểu sự phức tạp và tạo điều kiện thuận lợi cho việc triển khai và quản lý ứng dụng.
::
