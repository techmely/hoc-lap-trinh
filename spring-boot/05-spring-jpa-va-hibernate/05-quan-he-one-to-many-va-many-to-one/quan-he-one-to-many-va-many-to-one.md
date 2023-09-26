---
title: "Quan hệ @OneToMany và @ManyToOne sử dụng Hibernate"
description: "Trong bài viết này, chúng ta sẽ tìm hiểu cách sử dụng Hibernate để thể hiện quan hệ @OneToMany và @ManyToOne trong cơ sở dữ liệu"
chapter:
  name: "Spring JPA và Hibernate"
  slug: "chuong-05-spring-jpa-va-hibernate"
image: https://kungfutech.edu.vn/thumbnail.png
position: 5
---

**Quan hệ một-nhiều (@OneToMany)** và **nhiều-một (@ManyToOne)** trong cơ sở dữ liệu là hai loại quan hệ phổ biến, ví dụ như một địa chỉ có thể chứa nhiều người (gia đình).

Trong bài viết này, chúng ta sẽ tìm hiểu cách sử dụng **Hibernate** để thể hiện quan hệ @OneToMany và @ManyToOne trong cơ sở dữ liệu. Chúng ta sẽ sử dụng ngôn ngữ lập trình Java và một số công cụ hỗ trợ như **Spring Boot** và **Lombok** để viết mã nguồn ngắn gọn và dễ hiểu.

## Tạo Dự Án

Trước khi bắt đầu, chúng ta cần tạo một dự án Spring Boot sử dụng Gradle. Dự án này sẽ giúp chúng ta thực hiện ví dụ về quan hệ @OneToMany và @ManyToOne bằng Hibernate.

### Cài đặt Gradle

Trước hết, bạn cần cài đặt **Gradle** trên máy tính của mình. Sau đó, bạn có thể tạo dự án bằng cách sử dụng Spring Initializr hoặc tạo thủ công thông qua cấu hình Gradle. Dưới đây là một ví dụ về cấu hình Gradle build.gradle cho dự án của bạn:

```groovy
plugins {
    id 'org.springframework.boot' version '2.5.4'
    id 'io.spring.dependency-management' version '1.0.11.RELEASE'
    id 'java'
}

group = 'com.example'
version = '0.0.1-SNAPSHOT'
sourceCompatibility = '1.8'

repositories {
    mavenCentral()
}

dependencies {
    implementation 'org.springframework.boot:spring-boot-starter-data-jpa'
    implementation 'org.springframework.boot:spring-boot-starter-web'
    implementation 'org.projectlombok:lombok:1.18.22'
    runtimeOnly 'com.h2database:h2'
    testImplementation 'org.springframework.boot:spring-boot-starter-test'
}

test {
    useJUnitPlatform()
}
```

### Tạo Entity

Để biểu thị quan hệ @OneToMany và @ManyToOne trong cơ sở dữ liệu, chúng ta cần tạo hai entity tương ứng với hai bảng: `Person` và `Address`. Trong ví dụ này, mỗi `Address` sẽ chứa nhiều `Person`.

```java
import javax.persistence.*;
import java.util.List;

import lombok.*;

@Entity
@Data
@Builder
@NoArgsConstructor
@AllArgsConstructor
public class Address {
    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long id;

    private String city;
    private String province;

    @OneToMany(mappedBy = "address", cascade = CascadeType.ALL)
    private List<Person> persons;
}
```

```java
import javax.persistence.*;

import lombok.*;

@Entity
@Data
@Builder
@NoArgsConstructor
@AllArgsConstructor
public class Person {
    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long id;

    private String name;

    @ManyToOne
    @JoinColumn(name = "address_id")
    private Address address;
}
```

Trong đó:

- `@Entity` xác định rằng lớp này là một Entity.
- `@Id` đánh dấu trường `id` là khóa chính của Entity.
- `@GeneratedValue` chỉ định cách tạo giá trị cho trường `id`.
- `@OneToMany` và `@ManyToOne` xác định quan hệ một nhiều giữa `Address` và `Person`.
- `mappedBy` và `@JoinColumn` được sử dụng để chỉ định cách ánh xạ giữa hai bảng.

### Tạo Repository

Chúng ta cần tạo các repository cho `Person` và `Address` để có thể thực hiện các thao tác truy vấn dữ liệu.

```java
import org.springframework.data.jpa.repository.JpaRepository;

public interface PersonRepository extends JpaRepository<Person, Long> {
}
```

```java
import org.springframework.data.jpa.repository.JpaRepository;

public interface AddressRepository extends JpaRepository<Address, Long> {
}
```

## Thực Hiện Ví dụ

### Thêm Dữ Liệu

Bây giờ, chúng ta hãy thêm dữ liệu vào cơ sở dữ liệu bằng cách sử dụng `CommandLineRunner`.

```java
import org.springframework.boot.CommandLineRunner;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;

import lombok.RequiredArgsConstructor;

@SpringBootApplication
@RequiredArgsConstructor
public class OneToManyExampleApplication implements CommandLineRunner {

    private final PersonRepository personRepository;
    private final AddressRepository addressRepository;

    public static void main(String[] args) {
        SpringApplication.run(OneToManyExampleApplication.class, args);
    }

    @Override
    public void run(String... args) throws Exception {
        // Tạo đối tượng Address và liên kết với nhiều Person
        Address address = Address.builder()
                                 .city("New York")
                                 .province("NY")
                                 .build();

        Person person1 = Person.builder()
                               .name("John Doe")
                               .address(address)
                               .build();

        Person person2 = Person.builder()
                               .name("Jane Doe")
                               .address(address)
                               .build();

        address.setPersons(List.of(person1, person2));

        // Lưu vào db
        addressRepository.save(address);

        // In thông tin Address và Person
        System.out.println("Address: " + address);
        System.out.println("Persons: " + address.getPersons());
    }
}
```

Trong ví dụ này, chúng ta tạo một `Address` và hai `Person`, sau đó liên kết chúng với nhau thông qua quan hệ @OneToMany và @ManyToOne. Khi chúng ta chạy ứng dụng, dữ liệu sẽ được thêm vào cơ sở dữ liệu.

### Kiểm Tra Kết Quả

Sau khi chạy ứng dụng, bạn có thể truy cập cơ sở dữ liệu để kiểm tra kết quả. Sử dụng giao diện trình duyệt của **H2 Database**, bạn có thể truy cập tại `http://localhost:8080/h2-console/`. Đăng nhập với các thông số cấu hình trong `application.properties`.

Kết quả trong cơ sở dữ liệu sẽ hiển thị một bảng `ADDRESS` và một bảng `PERSON` với thông tin được liên kết:

::result

Bảng ADDRESS:

| ID  | CITY     | PROVINCE |
| --- | -------- | -------- |
| 1   | New York | NY       |

Bảng PERSON:

| ID  | NAME     | ADDRESS_ID |
| --- | -------- | ---------- |
| 1   | John Doe | 1          |
| 2   | Jane Doe | 1          |

::alert{type="success"}
Quan hệ @OneToMany và @ManyToOne là hai loại quan hệ quan trọng trong cơ sở dữ liệu. Sử dụng Hibernate và Spring Boot, chúng ta có thể dễ dàng biểu thị và quản lý quan hệ này trong ứng dụng của mình. Hy vọng bài viết này đã giúp bạn hiểu cách sử dụng @OneToMany và @ManyToOne trong Hibernate và Spring Boot.
::
