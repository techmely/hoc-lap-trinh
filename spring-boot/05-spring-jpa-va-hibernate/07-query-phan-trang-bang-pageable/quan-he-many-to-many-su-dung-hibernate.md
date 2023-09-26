---
title: "Query phân trang bằng Pageable"
description: "Trong bài viết này, chúng ta sẽ tìm hiểu cách thực hiện phân trang dữ liệu bằng Spring JPA sử dụng Pageable"
chapter:
  name: "Spring JPA và Hibernate"
  slug: "chuong-05-spring-jpa-va-hibernate"
category:
  name: "SpringBoots"
  slug: "springboots"
image: https://kungfutech.edu.vn/thumbnail.png
position: 7
---

Trong phần lớn ứng dụng, chúng ta thường không lấy toàn bộ dữ liệu từ cơ sở dữ liệu, mà chỉ cần một phần nhất định và chia thành từng trang. Điều này giúp tiết kiệm băng thông, tăng hiệu suất và giảm dữ liệu không cần thiết. Trong bài viết này, chúng ta sẽ tìm hiểu cách thực hiện phân trang dữ liệu bằng **Spring JPA** sử dụng **Pageable**.

Trước tiên, hãy đảm bảo rằng bạn đã thêm dependency `spring-boot-starter-data-jpa` vào tệp `pom.xml` của dự án Spring Boot của bạn. Dưới đây là một phần của tệp `pom.xml`:

```xml
<!-- Thêm dependency spring-boot-starter-data-jpa -->
<dependency>
    <groupId>org.springframework.boot</groupId>
    <artifactId>spring-boot-starter-data-jpa</artifactId>
</dependency>
```

Trong ví dụ này, chúng tôi sử dụng cơ sở dữ liệu **H2** để minh họa. H2 là cơ sở dữ liệu trong bộ nhớ, dữ liệu sẽ tồn tại trong bộ nhớ RAM và sẽ bị xóa khi ứng dụng tắt.

### Tạo Model và Repository

Đầu tiên, chúng ta sẽ tạo một đối tượng model đơn giản, ví dụ là "User", và sau đó chúng ta sẽ thêm một số dữ liệu mẫu vào cơ sở dữ liệu.

#### Model "User"

```java
@Entity
@Data
@Builder
public class User {
    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long id;

    private String name;
}
```

#### Repository "UserRepository"

```java
public interface UserRepository extends JpaRepository<User, Long> {
}
```

#### DatasourceConfig

Chúng ta cũng cần một lớp cấu hình để chèn dữ liệu mẫu vào cơ sở dữ liệu. Dưới đây là một ví dụ:

```java
@Configuration
@RequiredArgsConstructor
public class DatasourceConfig {
    private final UserRepository userRepository;

    @PostConstruct
    public void initData() {
        // Chèn 100 User vào cơ sở dữ liệu
        userRepository.saveAll(
            IntStream.range(0, 100)
                .mapToObj(i -> User.builder()
                                   .name("name-" + i)
                                   .build())
                .collect(Collectors.toList())
        );
    }
}
```

### Sử dụng Pageable

Để truy vấn dữ liệu dưới dạng trang, chúng ta sử dụng **Pageable**. Hàm `findAll(Pageable pageable)` sẽ trả về một đối tượng **Page** chứa dữ liệu của trang cụ thể.

Dưới đây là cách lấy ra 5 bản ghi đầu tiên:

```java
Page<User> page = userRepository.findAll(PageRequest.of(0, 5));
```

Để lấy ra 5 bản ghi tiếp theo, bạn có thể sử dụng một trong các cách sau:

```java
// Sử dụng đối tượng Page trước đó
page.nextPageable()

// Sử dụng PageRequest mới
PageRequest.of(1, 5)
```

### Sắp xếp dữ liệu

Bạn có thể yêu cầu dữ liệu được sắp xếp theo một trường cụ thể bằng cách sử dụng **Sort**:

```java
Page<User> page = userRepository.findAll(PageRequest.of(1, 5, Sort.by("name").descending()));
```

### Tùy chỉnh Query

Ngoài ra, bạn có thể tùy chỉnh các truy vấn để trả về danh sách theo yêu cầu của mình. Ví dụ, dưới đây là một ví dụ về tạo một phương thức tùy chỉnh trong **UserRepository** để lấy danh sách User theo tên:

```java
public interface UserRepository extends JpaRepository<User, Long> {
    List<User> findAllByNameLike(String name, Pageable pageable);
}
```

### Ví dụ DEMO

Dưới đây là ví dụ hoàn chỉnh về cách sử dụng **Pageable** và các phương thức tương ứng:

```java
@SpringBootApplication
@RequiredArgsConstructor
public class App {
    public static void main(String[] args) {
        SpringApplication.run(App.class, args);
    }

    private final UserRepository userRepository;

    @Bean
    CommandLineRunner run() {
        return args -> {
            // Lấy ra 5 User đầu tiên
            Page<User> page = userRepository.findAll(PageRequest.of(0, 5));
            System.out.println("In ra 5 User đầu tiên: ");
            page.forEach(System.out::println);

            // Lấy ra 5 User tiếp theo
            page = userRepository.findAll(page.nextPageable());
            System.out.println("In ra 5 User tiếp theo: ");
            page.forEach(System.out::println);

            // In ra số lượng User ở page hiện tại
            System.out.println("In ra số lượng User ở page hiện tại: " + page.getSize());

            // In ra tổng số lượng User
            System.out.println("In ra tổng số lượng User: " + page.getTotalElements());

            // In ra tổng số page
            System.out.println("In ra tổng số page: " + page.getTotalPages());

            // Lấy ra 5 User ở page 1, sắp xếp theo tên giảm dần


            page = userRepository.findAll(PageRequest.of(1, 5, Sort.by("name").descending()));
            System.out.println("In ra 5 User ở page 1, sắp xếp theo tên giảm dần:");
            page.forEach(System.out::println);

            // Sử dụng phương thức tùy chỉnh
            List<User> list = userRepository.findAllByNameLike("name-%", PageRequest.of(0, 5));
            System.out.println(list);
        };
    }
}
```

Kết quả thực hiện các truy vấn sử dụng **Pageable** và tùy chỉnh query:

::result
In ra 5 User đầu tiên:<br/>>
User(id=1, name=name-0)<br/>
User(id=2, name=name-1)<br/>
User(id=3, name=name-2)<br/>
User(id=4, name=name-3)<br/>
User(id=5, name=name-4)<br/>

In ra 5 User tiếp theo:<br/>
User(id=6, name=name-5)<br/>
User(id=7, name=name-6)<br/>
User(id=8, name=name-7)<br/>
User(id=9, name=name-8)<br/>
User(id=10, name=name-9)<br/>

In ra số lượng User ở page hiện tại: 5<br/>

In ra tổng số lượng User: 100<br/>

In ra tổng số page: 20<br/>

In ra 5 User ở page 1, sắp xếp theo tên giảm dần:<br/>
User(id=95, name=name-94)<br/>
User(id=94, name=name-93)<br/>
User(id=93, name=name-92)<br/>
User(id=92, name=name-91)<br/>
User(id=91, name=name-90)<br/>

Sử dụng phương thức tùy chỉnh<br/>
[User(id=1, name=name-0), User(id=2, name=name-1), User(id=3, name=name-2), User(id=4, name=name-3), User(id=5, name=name-4)]
::

::alert{type="success"}
Phân trang dữ liệu bằng **Pageable** là một công cụ mạnh mẽ trong **Spring JPA** để giới hạn lượng dữ liệu trả về và tăng hiệu suất ứng dụng. Bài viết này đã giới thiệu cách sử dụng **Pageable** và cách tùy chỉnh các truy vấn dựa trên nhu cầu của bạn. Sử dụng **Pageable** sẽ giúp ứng dụng của bạn hoạt động một cách hiệu quả hơn và tối ưu hóa việc sử dụng dữ liệu từ cơ sở dữ liệu.
::
