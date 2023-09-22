---
title: "Annotation @Component @Service @Repository"
description: "Trong lập trình Spring Boot, chúng ta thường sử dụng các Annotation như @Component, @Service, và @Repository để đánh dấu các thành phần của ứng dụng. Trong bài viết này, chúng ta sẽ tìm hiểu sự khác biệt giữa các Annotation này và cách chúng được sử dụng"
chapter:
  name: "Spring Boot cơ bản"
  slug: "chuong-03-spring-boot-co-ban"
category:
  name: "Spring Boot"
  slug: "spring-boot"
position: 5
---

Trong lập trình Spring Boot, có ba Annotation quan trọng là `@Component`, `@Service`, và `@Repository`.

## Giới thiệu

Trong bài này, chúng ta sẽ tìm hiểu về các Annotation `@Component`, `@Service`, và `@Repository`.

## Kiến trúc trong Spring Boot

Spring Boot xây dựng kiến trúc MVC (Model-View-Controller) dựa trên nguyên tắc "độc lập" và các nguyên tắc thiết kế hướng đối tượng. Kiến trúc "độc lập" đề cập đến việc các tầng trong ứng dụng phục vụ cho mục tiêu cụ thể và không can thiệp vào các tầng khác. Điều này được thể hiện qua việc các tầng thực hiện nhiệm vụ riêng của mình và có thể giao tiếp với các tầng khác thông qua giao diện.

Kiến trúc Controller-Service-Repository chia ứng dụng thành 3 tầng chính:

![Kiến trúc Spring Boot](../../images/loda1557627097246/2.png)

- **Tầng Controller**: Là tầng giao tiếp với bên ngoài và xử lý các yêu cầu từ người dùng hoặc các yêu cầu gửi đến từ bên ngoài hệ thống.
- **Tầng Service**: Thực hiện các logic nghiệp vụ và xử lý các yêu cầu từ tầng Controller.
- **Tầng Repository**: Chịu trách nhiệm giao tiếp với cơ sở dữ liệu hoặc các nguồn dữ liệu khác, thực hiện các thao tác truy vấn và cung cấp dữ liệu cho tầng Service.

## `@Controller` vs `@Service` vs `@Repository` trong Spring Boot

Để phục vụ cho kiến trúc ứng dụng trong Spring Boot, chúng ta có ba Annotation là `@Controller`, `@Service`, và `@Repository` để đánh dấu các lớp trong ứng dụng.

1. **@Controller**: Đánh dấu một class là tầng Controller, chịu trách nhiệm xử lý các yêu cầu từ người dùng hoặc các yêu cầu gửi đến từ bên ngoài hệ thống.

2. **@Service**: Đánh dấu một class là tầng Service, chứa các logic nghiệp vụ và xử lý các yêu cầu từ tầng Controller.

3. **@Repository**: Đánh dấu một class là tầng Repository, chịu trách nhiệm giao tiếp với cơ sở dữ liệu hoặc các nguồn dữ liệu khác, thực hiện các thao tác truy vấn và cung cấp dữ liệu cho tầng Service.

### Cài đặt

Để thực hiện ví dụ, bạn cần cấu hình Maven cho dự án Spring Boot của mình. Dưới đây là một ví dụ cấu hình `pom.xml`:

```xml
<?xml version="1.0" encoding="UTF-8"?>
<project xmlns="http://maven.apache.org/POM/4.0.0" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
         xsi:schemaLocation="http://maven.apache.org/POM/4.0.0 http://maven.apache.org/xsd/maven-4.0.0.xsd">
    <!-- Cấu hình Maven -->
</project>
```

### Ví dụ

Dưới đây là một ví dụ minh họa sử dụng `@Service` và `@Repository`.

#### Model `Girl`

```java
public class Girl {
    private String name;

    public Girl(String name) {
        this.name = name;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    @Override
    public String toString() {
        return "Girl(" + this.name + ")";
    }
}
```

#### Interface `GirlRepository`

```java
public interface GirlRepository {
    Girl getGirlByName(String name);
}
```

#### Implementation `GirlRepositoryImpl`

```java
@Repository
public class GirlRepositoryImpl implements GirlRepository {

    @Override
    public Girl getGirlByName(String name) {
        // Đây là ví dụ giả định, thực tế bạn cần thực hiện truy vấn trong cơ sở dữ liệu
        return new Girl(name);
    }


}
```

#### Service `GirlService`

```java
@Service
public class GirlService {
    @Autowired
    private GirlRepository girlRepository;

    public Girl getRandomGirl() {
        String name = randomGirlName(10);
        return girlRepository.getGirlByName(name);
    }

    public String randomGirlName(int length) {
        return RandomStringUtils.randomAlphanumeric(length).toLowerCase();
    }
}
```

#### Chạy ứng dụng

```java
@SpringBootApplication
public class App {

    public static void main(String[] args) {
        ApplicationContext context = SpringApplication.run(App.class, args);

        GirlService girlService = context.getBean(GirlService.class);
        Girl girl = girlService.getRandomGirl();
        System.out.println(girl);
    }
}
```

::result
Girl(ulmvchvgkf)
::

### Giải thích

- `@Service` và `@Repository` đánh dấu các lớp là các `Bean` đảm nhiệm các nhiệm vụ cụ thể trong kiến trúc ứng dụng.
- `@Component`, `@Service`, và `@Repository` đều có cùng chức năng là đánh dấu các lớp để Spring Boot biết rằng chúng là các `Bean`. Tuy nhiên, việc sử dụng `@Service` và `@Repository` giúp tạo ra sự phân biệt về mặt logic giữa các tầng trong kiến trúc ứng dụng.
- Bạn có thể sử dụng `@Component` thay cho `@Service` và `@Repository`, và chương trình vẫn hoạt động bình thường. Tuy nhiên, việc sử dụng các Annotation phù hợp giúp làm rõ mục tiêu và nhiệm vụ của mỗi lớp.

::alert{type="success"}
Trong bài viết này, chúng ta đã tìm hiểu về ba Annotation quan trọng trong Spring Boot: `@Component`, `@Service`, và `@Repository`. Mỗi Annotation này có vai trò và mục tiêu cụ thể trong việc quản lý các lớp và nhiệm vụ trong ứng dụng Spring Boot. Việc sử dụng chúng giúp làm rõ kiến trúc và mục tiêu của ứng dụng, đồng thời giúp Spring Boot quản lý các `Bean` một cách hiệu quả.
::
