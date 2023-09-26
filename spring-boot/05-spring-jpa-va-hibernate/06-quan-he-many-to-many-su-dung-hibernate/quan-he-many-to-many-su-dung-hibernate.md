---
title: "Quan hệ @ManyToMany sử dụng Hibernate"
description: "Chúng ta sẽ tìm hiểu cách sử dụng Hibernate để biểu thị và quản lý quan hệ @ManyToMany giữa hai đối tượng, ví dụ là "Person" và "Address", bằng cách sử dụng ngôn ngữ lập trình Java"
chapter:
  name: "Spring JPA và Hibernate"
  slug: "chuong-05-spring-jpa-va-hibernate"
category:
  name: "SpringBoots"
  slug: "springboots"
image: https://kungfutech.edu.vn/thumbnail.png
position: 6
---

Trong cơ sở dữ liệu, quan hệ n-n (many-to-many) là một loại quan hệ rất phổ biến. Ví dụ, một địa chỉ có thể chứa nhiều người (gia đình), và một người có thể có nhiều địa chỉ. Để biểu thị quan hệ này trong cơ sở dữ liệu và thao tác với nó trong ứng dụng Java, chúng ta sử dụng **Hibernate**, một framework ORM (Object-Relational Mapping) phổ biến.

Trong bài viết này, chúng ta sẽ tìm hiểu cách sử dụng **Hibernate** để biểu thị và quản lý quan hệ @ManyToMany giữa hai đối tượng, ví dụ là "Person" và "Address", bằng cách sử dụng ngôn ngữ lập trình Java.

## Chuẩn bị Dự Án

Trước khi bắt đầu, chúng ta cần tạo một dự án Java Spring Boot với sự hỗ trợ của **Hibernate**. Bạn có thể sử dụng **Gradle** hoặc **Maven** để quản lý dự án. Dưới đây là một ví dụ về cấu hình **Gradle**:

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

Trong ví dụ này, chúng ta sử dụng **Spring Boot Starter** cho **Spring Data JPA**, **Spring Web**, và thư viện **Lombok** để giảm bớt mã nguồn. Chúng ta cũng sử dụng **H2 Database** để làm cơ sở dữ liệu.

## Tạo Entity

Để biểu thị quan hệ @ManyToMany, chúng ta cần tạo hai đối tượng (entity) tương ứng: "Person" và "Address".

### Entity "Person"

```java
import lombok.*;

import javax.persistence.*;
import java.util.Collection;

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

    @ManyToMany(mappedBy = "persons")
    private Collection<Address> addresses;
}
```

- `@Entity`: Đánh dấu lớp này là một entity.
- `@Id`: Đánh dấu trường `id` là khóa chính.
- `@GeneratedValue`: Xác định cách tạo giá trị cho trường `id`.
- `@ManyToMany`: Xác định quan hệ many-to-many với entity "Address".
- `mappedBy`: Chỉ định trường trong "Address" quản lý quan hệ này.

### Entity "Address"

```java
import lombok.*;

import javax.persistence.*;
import java.util.Collection;

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

    @ManyToMany(cascade = CascadeType.ALL)
    @JoinTable(
            name = "address_person",
            joinColumns = @JoinColumn(name = "address_id"),
            inverseJoinColumns = @JoinColumn(name = "person_id")
    )
    private Collection<Person> persons;
}
```

- `@Entity`: Đánh dấu lớp này là một entity.
- `@Id`: Đánh dấu trường `id` là khóa chính.
- `@GeneratedValue`: Xác định cách tạo giá trị cho trường `id`.
- `@ManyToMany`: Xác định quan hệ many-to-many với entity "Person".
- `cascade = CascadeType.ALL`: Đảm bảo các thay đổi trong "Address" cũng được áp dụng vào "Person".
- `@JoinTable`: Xác định tên bảng trung gian và các khóa ngoại.

## Tạo Repository

Chúng ta cần tạo các repository để thực hiện các thao tác truy vấn dữ liệu.

```java
import org.springframework.data.jpa.repository.JpaRepository;

public interface PersonRepository extends JpaRepository<Person, Long> {
}

import org.springframework.data.jpa.repository.JpaRepository;

public interface AddressRepository extends JpaRepository<Address, Long> {
}
```

## Thực Hiện Ví dụ

### Thêm Dữ Liệu

Chúng ta sẽ thêm dữ liệu vào cơ sở dữ liệu bằng cách sử dụng `CommandLineRunner`.

```java
import org.springframework.boot.CommandLineRunner;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import lombok.RequiredArgsConstructor;

@SpringBootApplication
@RequiredArgsConstructor
public class ManyToManyExampleApplication implements CommandLineRunner {

    private final PersonRepository personRepository;
    private final AddressRepository addressRepository;

    public static void main(String[] args) {
        SpringApplication.run(ManyToManyExampleApplication.class, args);
    }

    @Override
    public void run(String... args) throws Exception {
        Address hanoi = Address.builder()
                .city("Hanoi")
                .province("HN")
                .build();

        Address hatay = Address.builder()
                .city("Hai Phong")
                .province("HP")
                .build();

        Person person1 = Person.builder()
                .name("John")
                .build();

        Person person2 = Person.builder()
                .name("Jane")
                .build();

        hanoi.setPersons(List.of(person1, person2));
        hatay.setPersons(List.of(person1));

        addressRepository.save(hanoi);
        addressRepository.save(hatay);

        System.out.println("Data saved successfully.");
    }
}
```

### Query Dữ Liệu

Chúng ta có thể truy vấn dữ liệu theo cách thông qua repository.

```java
import org.springframework.boot.CommandLineRunner;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import lombok.RequiredArgsConstructor;

@SpringBootApplication
@RequiredArgsConstructor
public class ManyToManyExampleApplication implements CommandLineRunner {

    private final PersonRepository personRepository;
    private final AddressRepository addressRepository;

    public static void main(String[] args) {
        SpringApplication.run(ManyToManyExampleApplication.class, args);
    }

    @Override
    public void run(String... args) throws Exception {
        // Query dữ liệu
        Address hanoi = addressRepository.findById(1L).orElse(null);
        if (hanoi != null) {
            System.out.println("City: " + hanoi.getCity());
            System.out.println("Persons in Hanoi: " + hanoi.getPersons());
        }
    }
}
```

Khi bạn chạy ứng dụng, dữ liệu sẽ được thêm vào cơ sở dữ liệu và kết quả truy vấn dữ liệu từ bảng "Address" sẽ được hiển thị.

::result
City: Hanoi</br>
Persons in Hanoi: [Person(id=1, name=John), Person(id=2, name=Jane)]
::

::alert{type="success"}
Quan hệ @ManyToMany trong **Hibernate** là một công cụ mạnh mẽ để biểu thị và quản lý quan hệ n-n giữa các đối tượng trong cơ sở dữ liệu. Chúng ta đã thực hiện ví dụ đơn giản với các entity "Person" và "Address". Việc sử dụng **Spring Boot**, **Hibernate**, và **Spring Data JPA** giúp chúng ta dễ dàng thực hiện các thao tác truy vấn và tương tác với cơ sở dữ liệu một cách hiệu quả.
::
