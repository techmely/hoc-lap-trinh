---
title: "Spring JPA Method và @Query"
description: "Trong Spring Boot, Spring JPA cung cấp một cách dễ dàng để tạo và thực thi các truy vấn cơ sở dữ liệu. Điều này giúp tiết kiệm thời gian và giảm bớt lặp lại code."
chapter:
  name: "Spring Boot cơ bản"
  slug: "chuong-03-spring-boot-co-ban"
category:
  name: "Spring Boot"
  slug: "spring-boot"
position: 12
---

Trong bài viết này, chúng ta sẽ tìm hiểu về cách sử dụng Spring JPA Method và `@Query` để tạo các câu truy vấn trong ứng dụng Spring Boot. Chúng ta sẽ đi từ việc sử dụng các phương thức tạo truy vấn tự động dựa trên tên method của repository đến việc sử dụng `@Query` để tạo các câu truy vấn tùy chỉnh.

## Giới thiệu

Trong Spring Boot, Spring JPA cung cấp một cách dễ dàng để tạo và thực thi các truy vấn cơ sở dữ liệu. Điều này giúp tiết kiệm thời gian và giảm bớt lặp lại code.

## Query Creation

### Cơ chế tự động tạo truy vấn

Spring JPA cho phép tạo câu truy vấn dựa trên tên của method trong repository. Cơ chế này xây dựng câu truy vấn tự động từ tên method mà không cần viết thêm code SQL.

Ví dụ, nếu bạn có một đối tượng `User` và bạn muốn tìm tất cả người dùng có chỉ số tấn công (`atk`) bằng 50, bạn có thể đặt tên method như sau trong repository:

```java
List<User> findAllByAtk(int atk);
```

Khi bạn gọi phương thức này, Spring JPA sẽ tự động tạo một câu truy vấn SQL tương ứng và thực hiện nó.

Cơ chế này rất hữu ích cho các truy vấn đơn giản và giúp code trở nên dễ đọc hơn.

### Quy tắc đặt tên method

Quy tắc đặt tên method trong Spring JPA được xác định bởi các tiền tố sau:

- `find…By`
- `read…By`
- `query…By`
- `count…By`
- `get…By`

Phần còn lại của tên method sẽ được phân tích dựa trên tên thuộc tính (viết hoa chữ cái đầu). Nếu bạn có nhiều điều kiện, bạn có thể kết hợp chúng bằng các từ khóa `And` hoặc `Or`.

Ví dụ:

```java
interface UserRepository extends JpaRepository<User, Long> {
    List<User> findByLastName(String lastName);

    List<User> findByEmailAddressAndLastName(EmailAddress emailAddress, String lastName);

    List<User> findByLastNameOrFirstName(String lastName, String firstName);
}
```

Các thuộc tính trong tên method phải thuộc về lớp đối tượng tương ứng. Tuy nhiên, bạn cũng có thể truy vấn bằng thuộc tính con trong một số trường hợp.

### Ví dụ về Query Creation

Dưới đây là một ví dụ về cách sử dụng Query Creation trong Spring JPA:

```java
@Autowired
UserRepository userRepository;

// Tìm tất cả người dùng có chỉ số tấn công (atk) bằng 50
List<User> usersWithAtk50 = userRepository.findAllByAtk(50);
usersWithAtk50.forEach(System.out::println);
```

## @Query Annotation

Nếu bạn muốn tạo các truy vấn phức tạp hơn hoặc sử dụng SQL trực tiếp, bạn có thể sử dụng annotation `@Query`.

### Sử dụng JPQL (Java Persistence Query Language)

Với `@Query`, bạn có thể sử dụng JPQL để tạo câu truy vấn. JPQL giống với SQL nhưng sử dụng các tên đối tượng Java thay vì tên bảng cơ sở dữ liệu.

Ví dụ:

```java
@Repository
public interface UserRepository extends JpaRepository<User, Long> {

    @Query("SELECT u FROM User u WHERE u.atk = :atk")
    List<User> findUsersWithAtk(@Param("atk") int atk);
}
```

Trong ví dụ trên, chúng ta đã sử dụng JPQL để tìm tất cả người dùng có chỉ số tấn công (`atk`) bằng một giá trị cụ thể.

### Sử dụng SQL Native Query

Nếu bạn muốn sử dụng SQL trực tiếp, bạn có thể sử dụng `nativeQuery = true`:

```java
@Repository
public interface UserRepository extends JpaRepository<User, Long> {

    @Query(value = "SELECT * FROM user WHERE atk = :atk", nativeQuery = true)
    List<User> findUsersWithAtk(@Param("atk") int atk);
}
```

Trong trường hợp này, chúng ta đã sử dụng một câu truy vấn SQL thay vì `JPQL`.

### Truyền tham số

Để truyền tham số vào câu truy vấn `@Query`, bạn có thể sử dụng `:tên_tham_số` trong câu truy vấn và sử dụng `@Param("tên_tham_số")` trong phương thức repository.

Ví dụ:

```java
@Repository
public interface UserRepository extends JpaRepository<User, Long> {

    @Query("SELECT u FROM User u WHERE u.atk = :atk AND u.def = :def")
    List<User> findUsersWithAtkAndDef(@Param("atk") int atk, @Param("def") int def);
}
```

## Demo

Dưới đây là một ví dụ hoàn chỉnh về cách sử dụng Spring JPA Method và `@Query`:

### Cấu trúc dự án

- Tạo một ứng dụng Spring Boot v

ới Spring JPA và MySQL.

- Tạo một đối tượng `User` và một repository `UserRepository`.
- Cấu hình cơ sở dữ liệu MySQL và tạo bảng `user`.
- Tạo và thực hiện các truy vấn sử dụng Spring JPA Method và `@Query`.

::result

Tìm tất cả người dùng có chỉ số tấn công (atk) bằng 50</br>
findAllByAtk:</br>
User(id=1, hp=100, stamina=90, atk=50, def=60, agi=70)</br>
User(id=4, hp=80, stamina=85, atk=50, def=55, agi=65)</br>
Tìm tất cả người dùng có chỉ số tấn công (atk) bằng 50 và phòng thủ (def) bằng 60</br>
findUsersWithAtkAndDef:</br>
User(id=1, hp=100, stamina=90, atk=50, def=60, agi=70)</br>

::

::alert{type="success"}
Trong bài viết này, chúng ta đã tìm hiểu cách sử dụng Spring JPA Method và `@Query` để tạo các câu truy vấn trong ứng dụng Spring Boot. Chúng ta đã thấy cách sử dụng các phương thức tạo truy vấn tự động dựa trên tên method của repository và cách sử dụng `@Query` để tạo các câu truy vấn tùy chỉnh. Việc này giúp giảm bớt công sức và tối ưu hóa việc tương tác với cơ sở dữ liệu trong ứng dụng Spring Boot của bạn.
::
