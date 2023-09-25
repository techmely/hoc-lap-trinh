---
title: "Giới thiệu Spring Boot JPA"
description: "Trong bài viết này, chúng ta sẽ tìm hiểu về Spring Boot JPA, một công cụ mạnh mẽ cho việc tương tác với cơ sở dữ liệu MySQL. Chúng ta sẽ đi từ việc cài đặt, tạo bảng và dữ liệu, tạo model, và cuối cùng là thao tác với cơ sở dữ liệu bằng Spring Boot JPA"
chapter:
  name: "Spring Boot cơ bản"
  slug: "chuong-03-spring-boot-co-ban"
category:
  name: "Spring Boot"
  slug: "spring-boot"
position: 11
---

Trong loạt bài viết về Spring Boot, chúng ta không thể bỏ qua một phần quan trọng trong ứng dụng web - đó là giao tiếp với cơ sở dữ liệu. Trong bài viết này, chúng ta sẽ tìm hiểu về Spring Boot JPA, một công cụ mạnh mẽ cho việc tương tác với cơ sở dữ liệu MySQL. Chúng ta sẽ đi từ việc cài đặt, tạo bảng và dữ liệu, tạo model, và cuối cùng là thao tác với cơ sở dữ liệu bằng Spring Boot JPA.

### Spring Boot JPA là gì?

**Spring Boot JPA** là một phần của hệ sinh thái Spring Data, giúp tạo ra một lớp trung gian giữa tầng dịch vụ (service layer) và cơ sở dữ liệu. Nó giúp chúng ta thao tác với cơ sở dữ liệu dễ dàng hơn, tự động cấu hình và giảm thiểu code lặp lại. **Spring Boot JPA** sử dụng Hibernate và cung cấp một giao diện mạnh mẽ, giúp giải quyết các vấn đề khi làm việc với Hibernate.

### Cài đặt Spring Boot JPA

Để sử dụng Spring Boot JPA, bạn cần thêm dependency `spring-boot-starter-data-jpa` vào dự án của mình. Đồng thời, để kết nối với cơ sở dữ liệu MySQL, bạn cần thêm dependency `mysql-connector-java` vào tệp `pom.xml`. Dưới đây là một ví dụ về cấu hình `pom.xml`:

```xml
<!-- Đoạn mã XML trong pom.xml -->

<dependencies>
    <!-- Spring Boot Web -->
    <dependency>
        <groupId>org.springframework.boot</groupId>
        <artifactId>spring-boot-starter-web</artifactId>
    </dependency>

    <!-- Spring Boot JPA -->
    <dependency>
        <groupId>org.springframework.boot</groupId>
        <artifactId>spring-boot-starter-data-jpa</artifactId>
    </dependency>

    <!-- MySQL Connector -->
    <dependency>
        <groupId>mysql</groupId>
        <artifactId>mysql-connector-java</artifactId>
    </dependency>
</dependencies>
```

Sau khi cài đặt, dự án của bạn sẽ có khả năng sử dụng Spring Boot JPA.

### Tạo bảng và dữ liệu

Trước khi bắt đầu làm việc với Spring Boot JPA, chúng ta cần có cơ sở dữ liệu. Trong ví dụ này, chúng ta sẽ sử dụng cơ sở dữ liệu MySQL. Bạn cần tạo một cơ sở dữ liệu `micro_db` và một bảng `User`. Dưới đây là mã SQL để tạo cơ sở dữ liệu và bảng, cũng như thêm dữ liệu mẫu:

```sql
-- Tạo cơ sở dữ liệu micro_db
CREATE DATABASE micro_db;
USE micro_db;

-- Tạo bảng User và thêm dữ liệu mẫu
CREATE TABLE `user`
(
  `id`         bigint(20) NOT NULL      AUTO_INCREMENT,
  `hp`         int                    DEFAULT NULL,
  `stamina`    int                    DEFAULT NULL,
  `atk`        int                    DEFAULT NULL,
  `def`        int                    DEFAULT NULL,
  `agi`        int                    DEFAULT NULL,
  PRIMARY KEY (`id`)
);

DELIMITER $$
CREATE PROCEDURE generate_data()
BEGIN
  DECLARE i INT DEFAULT 0;
  WHILE i < 100 DO
    INSERT INTO `user` (`hp`, `stamina`, `atk`, `def`, `agi`) VALUES (i, i, i, i, i);
    SET i = i + 1;
  END WHILE;
END$$
DELIMITER ;

CALL generate_data();
```

Sau khi chạy mã SQL này, cơ sở dữ liệu `micro_db` sẽ được tạo ra và chứa 100 bản ghi dữ liệu trong bảng `User`.

### Tạo Model User

Sử dụng Spring Boot JPA, bạn cần tạo một lớp Java để ánh xạ dữ liệu từ bảng `User`. Trong ví dụ này, chúng ta sẽ sử dụng Hibernate để thực hiện ánh xạ này. Dưới đây là mã của lớp `User`:

```java
import javax.persistence.*;

@Entity
@Table(name = "user")
public class User {

    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long id;

    @Column(name = "hp")
    private int hp;

    @Column(name = "stamina")
    private int stamina;

    private int atk;
    private int def;
    private int agi;

    // Constructors, getters, and setters...
}
```

Lớp `User` này sử dụng các annotation của Hibernate để đánh dấu các thuộc tính của nó để Hibernate có thể ánh xạ chúng với cột tương ứng trong bảng `User` trong cơ sở dữ liệu.

### Thao tác với cơ sở dữ liệu

Trước khi sử dụng Spring Boot JPA, thao tác với cơ sở dữ liệu MySQL thông qua Hibernate truyền thống có thể phức tạp. Dưới đây là ví dụ về cách truy vấn tất cả các bản ghi `User` bằng Hibernate truyền thống:

```java
// Giả sử bạn đã có đối tượng session của Hibernate
Session session = getSession();

try {
    // Bắt đầu giao dịch
    session.getTransaction().begin();

    // Tạo câu truy vấn
    String sql = "Select u from " + User.class.getName() + " u ";
    Query<User> query = session.createQuery(sql);

    // Thực hiện truy vấn và lấy dữ liệu
    List<User> users = query.getResultList();

    // In dữ liệu ra màn hình
    for (User user : users) {
        System

.out.println(user);
    }

    // Commit giao dịch và kết thúc session
    session.getTransaction().commit();
} catch (Exception e) {
    e.printStackTrace();
    // Rollback trong trường hợp có lỗi xảy ra
    session.getTransaction().rollback();
}
```

Mặc dù Hibernate đã giảm thiểu code so với JDBC, nhưng nó vẫn phức tạp đối với nhiều lập trình viên. Để giải quyết vấn đề này, Spring Data đã tạo ra Spring Boot JPA, giúp giảm thiểu code và làm cho việc thao tác với cơ sở dữ liệu dễ dàng hơn.

### JpaRepository

Spring Boot JPA sử dụng interface `JpaRepository` để tạo các phương thức thao tác với cơ sở dữ liệu. Để sử dụng `JpaRepository`, bạn cần tạo một interface và kế thừa nó. Dưới đây là một ví dụ về việc tạo `UserRepository`:

```java
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;

@Repository
public interface UserRepository extends JpaRepository<User, Long> {
}
```

Trong ví dụ trên, `UserRepository` sử dụng annotation `@Repository` để đánh dấu nó là một Bean và chịu trách nhiệm giao tiếp với cơ sở dữ liệu. Spring Boot sẽ tự động tạo và cấu hình `UserRepository` trong context.

Bây giờ, bạn có thể sử dụng `UserRepository` để thao tác với cơ sở dữ liệu một cách dễ dàng:

```java
@Autowired
UserRepository userRepository;

// Lấy ra toàn bộ user trong cơ sở dữ liệu
userRepository.findAll().forEach(System.out::println);

// Lưu một user mới vào cơ sở dữ liệu
User user = userRepository.save(new User());
System.out.println("User vừa lưu có ID: " + user.getId());

// Cập nhật thông tin của user
user.setAgi(100);
userRepository.save(user);

// Truy vấn một user theo ID
User user2 = userRepository.findById(user.getId()).orElse(null);
System.out.println("User: " + user);
System.out.println("User2: " + user2);

// Xóa user khỏi cơ sở dữ liệu
userRepository.delete(user);

// Kiểm tra xem user còn tồn tại trong cơ sở dữ liệu không
User user3 = userRepository.findById(user.getId()).orElse(null);
System.out.println("User3: " + user3);
```

Với Spring Boot JPA, việc thao tác với cơ sở dữ liệu trở nên đơn giản và ngắn gọn hơn rất nhiều.

::result

User vừa lưu có ID: 101<br/>
User: User(id=101, hp=0, stamina=0, atk=0, def=0, agi=100)<br/>
User2: User(id=101, hp=0, stamina=0, atk=0, def=0, agi=100)<br/>
User3: null

::

::alert{type="success"}
Bài viết đã giới thiệu về Spring Boot JPA, từ việc cài đặt, tạo bảng và dữ liệu, tạo model, và cuối cùng là thao tác với cơ sở dữ liệu bằng Spring Boot JPA. Chúng ta đã thấy rằng Spring Boot JPA giúp đơn giản hóa việc làm việc với cơ sở dữ liệu và giảm bớt sự phức tạp của việc sử dụng Hibernate truyền thống.
::
