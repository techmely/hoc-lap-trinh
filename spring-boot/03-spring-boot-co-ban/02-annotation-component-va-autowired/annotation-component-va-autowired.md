---
title: "Annotation @Component và @Autowired"
description: "Trong lập trình Spring Boot, hai annotation quan trọng bạn nên biết là @Component và @Autowired. Đây là hai khái niệm cơ bản giúp bạn quản lý và kết nối các thành phần của ứng dụng Spring Boot một cách dễ dàng"
chapter:
  name: "Spring Boot cơ bản"
  slug: "chuong-03-spring-boot-co-ban"
category:
  name: "Spring Boot"
  slug: "spring-boot"
position: 2
---

Trong lập trình Spring Boot, Annotation `@Component` và `@Autowired` là hai trong những khái niệm quan trọng giúp quản lý và tiêm các thành phần (component) vào ứng dụng của bạn. Bài viết này sẽ giúp bạn hiểu rõ hơn về hai annotation này.

## Giới thiệu

Trước khi tìm hiểu về `@Component` và `@Autowired`, bạn nên nắm vững hai khái niệm quan trọng sau đây:

1. **Tight coupling (liên kết ràng buộc) và loose coupling (liên kết lỏng lẻo)**: Tight coupling là sự phụ thuộc mạnh giữa các thành phần trong ứng dụng, trong khi loose coupling là sự phụ thuộc yếu hoặc không phụ thuộc giữa các thành phần.

2. **Dependency Injection (DI) và Inversion of Control (IoC)**: DI là một nguyên tắc trong lập trình, nói rằng các thành phần không nên tạo ra các đối tượng phụ thuộc của chúng, mà nên nhận chúng từ bên ngoài. IoC là một nguyên tắc quản lý và cung cấp các đối tượng phụ thuộc.

## Cài đặt

Trước tiên, bạn cần cài đặt các gói thư viện của Spring Boot trong Maven. Để làm điều này, bạn cần thêm `spring-boot-starter-parent` là parent của project và thêm dependency `spring-boot-starter-web` cho việc lập trình web hoặc server side. Dưới đây là ví dụ cấu hình `pom.xml`:

```xml
<parent>
    <groupId>org.springframework.boot</groupId>
    <artifactId>spring-boot-starter-parent</artifactId>
    <version>2.0.5.RELEASE</version>
    <relativePath /> <!-- lookup parent from repository -->
</parent>

<dependencies>
    <dependency>
        <groupId>org.springframework.boot</groupId>
        <artifactId>spring-boot-starter-web</artifactId>
    </dependency>
</dependencies>
```

## Cách chạy ứng dụng Spring Boot

Trong Spring Boot, để chạy ứng dụng, bạn cần chỉ cho Spring Boot biết nơi ứng dụng bắt đầu. Điều này được thực hiện bằng cách thêm annotation `@SpringBootApplication` trên class chính và gọi `SpringApplication.run(App.class, args);` để khởi tạo ứng dụng. Ví dụ:

```java
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.context.ApplicationContext;

@SpringBootApplication
public class App {
    public static void main(String[] args) {
        ApplicationContext context = SpringApplication.run(App.class, args);
    }
}
```

Trong ví dụ trên, chúng ta đã tạo một ứng dụng Spring Boot và khởi tạo `ApplicationContext`, container chứa toàn bộ các dependency trong ứng dụng.

## Annotation `@Component` trong Spring Boot

`@Component` là một annotation đánh dấu trên các class để cho biết chúng là các bean được quản lý bởi Spring Boot. Điều này có nghĩa là Spring Boot sẽ tạo và quản lý các instance của các class được đánh dấu `@Component`.

Ví dụ:

```java
import org.springframework.stereotype.Component;

@Component
public class Bikini implements Outfit {
    @Override
    public void wear() {
        System.out.println("Mặc bikini");
    }
}
```

Trong ví dụ trên, `Bikini` được đánh dấu là một `@Component`, nên Spring Boot sẽ tạo một instance của `Bikini` và quản lý nó.

## Annotation `@Autowired` trong Spring Boot

`@Autowired` được sử dụng để tiêm (inject) các dependency vào các thành phần khác. Khi bạn đánh dấu một thuộc tính bằng `@Autowired`, Spring Boot sẽ tự động tiêm một instance của dependency tương ứng vào thuộc tính đó.

Ví dụ:

```java
import org.springframework.beans.factory.annotation.Autowired;

@Component
public class Girl {

    @Autowired
    Outfit outfit;

    // Các getter và setter
}
```

Trong ví dụ trên, `Girl` có m

ột thuộc tính `outfit` được đánh dấu bằng `@Autowired`. Khi Spring Boot tạo một instance của `Girl`, nó sẽ tiêm một instance của `Outfit` (trong trường hợp này là `Bikini`) vào thuộc tính `outfit`.

## Singleton

Một điều đặc biệt là các bean trong Spring Boot được quản lý bởi `ApplicationContext` đều là singleton. Điều này có nghĩa là chỉ có một instance duy nhất của mỗi bean và nó được chia sẻ giữa các thành phần khác nhau. Điều này có thể thấy từ ví dụ sau:

```java
ApplicationContext context = SpringApplication.run(App.class, args);

Outfit outfit = context.getBean(Outfit.class);
Girl girl = context.getBean(Girl.class);

System.out.println("Outfit Instance: " + outfit);
System.out.println("Girl Outfit: " + girl.outfit);
```

Cả `outfit` và `girl.outfit` đều trỏ vào cùng một instance của `Bikini`.

::alert{type="success"}
Bài viết này đã giới thiệu về hai annotation cơ bản trong Spring Boot là `@Component` và `@Autowired`. Hiểu cách chúng hoạt động là quan trọng để xây dựng các ứng dụng Spring Boot hiệu quả và dễ quản lý.
::
