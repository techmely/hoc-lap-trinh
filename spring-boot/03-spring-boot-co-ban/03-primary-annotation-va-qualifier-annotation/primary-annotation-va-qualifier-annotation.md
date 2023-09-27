---
title: "@Primary annotation và @Qualifier annotation"
description: "Trong Spring Boot, khi bạn có nhiều bean cùng loại trong một ứng dụng và muốn chỉ định bean nào sẽ được ưu tiên sử dụng hoặc chọn bean cụ thể để sử dụng, bạn có thể sử dụng hai annotation quan trọng là @Primary và @Qualifier"
chapter:
  name: "Spring Boot cơ bản"
  slug: "chuong-03-spring-boot-co-ban"
position: 3
---

Trong Spring Boot, khi bạn có nhiều bean cùng loại trong một ứng dụng và muốn chỉ định bean nào sẽ được ưu tiên sử dụng hoặc chọn bean cụ thể để sử dụng, bạn có thể sử dụng hai annotation quan trọng là `@Primary` và `@Qualifier`. Trong bài viết này, chúng ta sẽ tìm hiểu cách sử dụng hai annotation này để quản lý các bean và giải quyết vấn đề khi có nhiều bean cùng loại trong Spring Boot.

### Cài đặt

Trước khi đi vào phần thực hành, hãy đảm bảo bạn đã cài đặt các gói thư viện của Spring Boot trong Maven bằng cách thêm `spring-boot-starter-parent` là parent của dự án và các dependencies cần thiết. Dưới đây là một ví dụ về cách cấu hình `pom.xml`:

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

## Cách `@Autowired` hoạt động

Trước khi tìm hiểu về `@Primary` và `@Qualifier`, hãy hiểu cách `@Autowired` hoạt động trong Spring Boot.

Annotation `@Autowired` cho biết Spring Boot nên tự động inject bean tương ứng vào vị trí được đánh dấu. Ví dụ:

```java
@Component
public class Girl {
    @Autowired
    Outfit outfit;

    public Girl(Outfit outfit) {
        this.outfit = outfit;
    }
}
```

Tuy nhiên, quá trình này yêu cầu rằng class phải có constructor hoặc setter cho thuộc tính cần inject.

Nếu bạn không cung cấp constructor hoặc setter, bạn sẽ nhận được một lỗi. Ví dụ:

```java
@Component
public class Girl {
    @Autowired
    Outfit outfit;

    public Girl() { }

    public void setOutfit(Outfit outfit) {
        this.outfit = outfit;
    }
}
```

Annotation `@Autowired` cũng có thể được sử dụng trên method, thay vì thuộc tính, để Spring Boot tự động inject các dependency vào method tương ứng.

## Vấn đề của `@Autowired` trong Spring Boot

Trong thực tế, khi ứng dụng của bạn chứa nhiều bean cùng loại trong Spring context, Spring Boot có thể gặp khó khăn trong việc xác định bean nào cần được inject. Ví dụ:

```java
@Component
public class Bikini implements Outfit {
    @Override
    public void wear() {
        System.out.println("Mặc bikini");
    }
}

@Component
public class Naked implements Outfit {
    @Override
    public void wear() {
        System.out.println("Đang không mặc gì");
    }
}
```

Class `Girl` yêu cầu inject một `Outfit`.

```java
@Component
public class Girl {
    @Autowired
    Outfit outfit;

    public Girl(Outfit outfit) {
        this.outfit = outfit;
    }
}
```

Khi bạn chạy ứng dụng, Spring Boot sẽ báo lỗi:

::result
Parameter 0 of constructor in `spring.helloprimaryqualifier.Girl` required a single bean, but 2 were found:

- bikini: defined in file `/path/to/Bikini.class`
- naked: defined in file `/path/to/Naked.class`

::

Điều này xảy ra vì Spring Boot không biết phải chọn bean nào để inject vào `Girl` khi có nhiều bean cùng loại trong context.

## `@Primary` trong Spring Boot

Cách giải quyết đầu tiên là sử dụng Annotation `@Primary`.

`@Primary` đánh dấu một bean là ưu tiên và sẽ luôn được ưu tiên chọn trong trường hợp có nhiều bean cùng loại trong context.

Trong ví dụ ở trên

, nếu bạn đánh dấu `Naked` là primary, Spring Boot sẽ chọn `Naked` để inject vào `Girl`.

```java
@Component
@Primary
public class Naked implements Outfit {
    @Override
    public void wear() {
        System.out.println("Đang không mặc gì");
    }
}
```

## `@Qualifier` trong Spring Boot

Cách giải quyết thứ hai là sử dụng Annotation `@Qualifier`.

`@Qualifier` xác định tên của một bean mà bạn muốn chỉ định để inject.

Ví dụ:

```java
@Component("bikini")
public class Bikini implements Outfit {
    @Override
    public void wear() {
        System.out.println("Mặc bikini");
    }
}

@Component("naked")
public class Naked implements Outfit {
    @Override
    public void wear() {
        System.out.println("Đang không mặc gì");
    }
}

@Component
public class Girl {
    Outfit outfit;

    @Autowired
    public Girl(@Qualifier("naked") Outfit outfit) {
        this.outfit = outfit;
    }
}
```

Với cách này, bạn chỉ cần xác định tên của bean bạn muốn inject vào `Girl` thông qua `@Qualifier("naked")`, và Spring Boot sẽ tìm bean có tên đó trong context để inject.

::result
Annotation `@Primary` và `@Qualifier` là hai công cụ mạnh mẽ để quản lý các bean và giải quyết vấn đề khi có nhiều bean cùng loại trong Spring Boot. Sử dụng chúng giúp bạn kiểm soát việc inject bean vào các đối tượng một cách hiệu quả trong ứng dụng của bạn.
::
