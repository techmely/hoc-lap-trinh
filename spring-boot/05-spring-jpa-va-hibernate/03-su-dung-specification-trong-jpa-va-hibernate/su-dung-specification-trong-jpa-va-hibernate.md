---
title: "Sử dụng Specification trong JPA và Hibernate"
description: "Trong bài viết này, chúng ta sẽ tìm hiểu về cách sử dụng Specification trong JPA và Hibernate để xây dựng các câu truy vấn linh hoạt và tái sử dụng chúng. Specification là một công cụ mạnh mẽ giúp bạn xây dựng các điều kiện truy vấn động mà bạn có thể thêm hoặc loại bỏ dễ dàng"
chapter:
  name: "Spring JPA và Hibernate"
  slug: "chuong-05-spring-jpa-va-hibernate"
image: https://kungfutech.edu.vn/thumbnail.png
position: 3
---

Trong bài viết này, chúng ta sẽ tìm hiểu về cách sử dụng Specification trong JPA và Hibernate để xây dựng các câu truy vấn linh hoạt và tái sử dụng chúng. Specification là một công cụ mạnh mẽ giúp bạn xây dựng các điều kiện truy vấn động mà bạn có thể thêm hoặc loại bỏ dễ dàng.

Trong một số bài viết trước đó, chúng ta đã tìm hiểu về cách sử dụng Criteria API và JPA Repository để truy vấn cơ sở dữ liệu trong Spring Boot. Tuy nhiên, có những tình huống mà chúng ta cần xây dựng các truy vấn phức tạp hơn và muốn có khả năng tái sử dụng chúng.

Ví dụ, khi sử dụng JpaRepository, bạn sẽ phải viết rất nhiều phương thức truy vấn và mỗi phương thức sẽ phục vụ cho một mục đích cụ thể. Điều này có thể dẫn đến việc bạn phải viết quá nhiều phương thức và không thể tái sử dụng chúng.

```java
public interface UserRepository extends JpaRepository<User, Long> {
    User findByEmailAddress(String emailAddress);
    List<User> findByLastName(String lastName, Sort sort);
    Page<User> findByFirstName(String firstName, Pageable pageable);
}
```

Để giải quyết vấn đề này và xây dựng các truy vấn linh hoạt hơn, Spring cung cấp cho chúng ta interface Specification.

Với Specification, bạn có thể xây dựng các điều kiện truy vấn theo cách linh hoạt và có khả năng tái sử dụng chúng theo ý muốn.

## Khái niệm Specification

Specification trong JPA và Hibernate tương đương với Predicate trong Hibernate. Một Specification là một functional interface (giao diện hàm) với một phương thức duy nhất `toPredicate`.

```java
public interface Specification<T> {
    Predicate toPredicate(Root<T> root, CriteriaQuery<?> query, CriteriaBuilder criteriaBuilder);
}
```

Trong đó:

- `Root<T>` là đối tượng gốc (root) mà chúng ta xây dựng truy vấn.
- `CriteriaQuery<?>` là truy vấn tổng quan.
- `CriteriaBuilder` là builder giúp bạn xây dựng các điều kiện truy vấn.

## Cài đặt

Trước tiên, chúng ta cần cài đặt các phụ thuộc cho dự án Spring Boot của chúng ta.

```xml
<dependency>
    <groupId>org.springframework.boot</groupId>
    <artifactId>spring-boot-starter-data-jpa</artifactId>
</dependency>
<dependency>
    <groupId>com.h2database</groupId>
    <artifactId>h2</artifactId>
    <scope>runtime</scope>
</dependency>
```

Chúng ta sử dụng H2 database làm cơ sở dữ liệu mẫu trong ví dụ này. H2 là một cơ sở dữ liệu trong bộ nhớ, nghĩa là nó sẽ lưu trữ dữ liệu trong bộ nhớ và mất khi ứng dụng kết thúc.

## Ví dụ với Specification

Chúng ta sẽ bắt đầu với một ví dụ đơn giản sử dụng Specification để truy vấn dữ liệu từ một bảng `User`.

### Entity User

Đầu tiên, chúng ta định nghĩa một entity `User`.

```java
@Entity
@Data
public class User {
    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long id;

    private String username;
    private String email;
    private Boolean active;

    // Constructors, getters, and setters
}
```

### UserRepository

Tiếp theo, chúng ta định nghĩa một repository cho entity `User` và kế thừa `JpaSpecificationExecutor<User>`.

```java
public interface UserRepository extends JpaRepository<User, Long>, JpaSpecificationExecutor<User> {
}
```

### Sử dụng Specification

Bây giờ, chúng ta sẽ xây dựng một ví dụ sử dụng Specification để truy vấn danh sách các người dùng có email kết thúc bằng "@example.com" và đang hoạt động (`active = true`).

```java
import org.springframework.data.jpa.domain.Specification;

public class UserSpecifications {
    public static Specification<User> activeUsers() {
        return (root, query, criteriaBuilder) -> criteriaBuilder.isTrue(root.get("active"));
    }

    public static Specification<User> emailEndsWithExample() {
        return (root, query, criteriaBuilder) -> criteriaBuilder.like(root.get("email"), "%@example.com");
    }
}
```

Chúng ta đã xây dựng hai Specification: `activeUsers` và `emailEndsWithExample`. Specification `activeUsers` sẽ kiểm tra xem trường `active` có giá trị `true` hay không. Specification `emailEndsWithExample` sẽ kiểm tra xem trường `email` có kết thúc bằng "@example.com" hay không.

Bây giờ, chúng ta có thể kết hợp các Specification này để tạo một truy vấn phức tạp.

```java
import org.springframework.data.jpa.domain.Specification;
import org.springframework.data.jpa.domain.JpaSort;

public class Main {
    public static void main(String[] args) {
        Specification<User> spec = Specification.where(UserSpecifications.activeUsers())
                .and(UserSpecifications.emailEndsWithExample());

        List<User> users = userRepository.findAll(spec, JpaSort.unsorted());

        users.forEach(System.out::println);
    }
}
```

Chúng ta sử dụng `Specification.where` để bắt đầu xây dựng Specification và sau đó kết hợp chúng bằng `and`. Trong ví dụ này, chúng ta truy vấn danh sách người dùng đã được kết hợp bởi cả hai điều kiện: `activeUsers` và `emailEndsWithExample`.

::result
User(id=1, username=user1, email=user1@example.com, active=true)</br>
User(id=2, username=user2, email=user2@example.com, active=true)
::

Kết quả của đoạn mã trên là danh sách các người dùng mà email kết thúc bằng "@example.com" và đang hoạt động (`active = true`).

::alert{type="success"}
Specification là một công cụ mạnh mẽ trong JPA và Hibernate giúp bạn xây dựng các câu truy vấn linh hoạt và tái sử dụng chúng một cách dễ dàng. Điều này giúp bạn viết mã nguồn gọn hơn, dễ bảo trì hơn và giảm sự phụ thuộc vào số lượng method truy vấn trong repository của bạn. Hy vọng bài viết này đã giúp bạn hiểu rõ hơn về cách sử dụng Specification trong JPA và Hibernate.
::
