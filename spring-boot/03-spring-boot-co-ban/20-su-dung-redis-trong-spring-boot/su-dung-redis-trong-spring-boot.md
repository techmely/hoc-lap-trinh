---
title: "Sử dụng Redis trong Spring Boot"
description: "Redis là một hệ thống lưu trữ key-value in-memory mạnh mẽ và phổ biến. Redis nổi bật với việc hỗ trợ nhiều cấu trúc dữ liệu khác nhau như hash, list, set, sorted set, và string, giúp thao tác với dữ liệu nhanh chóng và thuận tiện"
chapter:
  name: "Spring Boot cơ bản"
  slug: "chuong-03-spring-boot-co-ban"
position: 20
---

**Redis** là một hệ thống lưu trữ key-value in-memory mạnh mẽ và phổ biến. Redis nổi bật với việc hỗ trợ nhiều cấu trúc dữ liệu khác nhau như hash, list, set, sorted set, và string, giúp thao tác với dữ liệu nhanh chóng và thuận tiện. Trong bài viết này, chúng ta sẽ tìm hiểu cách kết nối ứng dụng Spring Boot với Redis và thực hiện một số thao tác cơ bản.

### Cài đặt

Chúng ta sử dụng **Maven** để quản lý dự án Spring Boot và thêm các dependencies sau vào file `pom.xml`:

```xml
<dependencies>
    <!-- Spring Boot Starter Web -->
    <dependency>
        <groupId>org.springframework.boot</groupId>
        <artifactId>spring-boot-starter-web</artifactId>
    </dependency>

    <!-- Spring Data Redis -->
    <dependency>
        <groupId>org.springframework.boot</groupId>
        <artifactId>spring-boot-starter-data-redis</artifactId>
    </dependency>

    <!-- Lettuce Core (Redis client) -->
    <dependency>
        <groupId>io.lettuce.core</groupId>
        <artifactId>lettuce-core</artifactId>
        <version>5.1.3.RELEASE</version>
    </dependency>
</dependencies>
```

Trong đó, `spring-boot-starter-data-redis` là thư viện Spring cho phép chúng ta thao tác với Redis, và `lettuce-core` là một thư viện mã nguồn mở cho việc kết nối tới Redis một cách thread-safe và hỗ trợ nhiều cách sử dụng.

### Cấu trúc thư mục

Dự án Spring Boot sẽ có cấu trúc thư mục như sau:

```scss
src
├── main
│   ├── java
│   │   └── com
│   │       └── example
│   │           └── redisdemo
│   │               ├── config
│   │               │   └── RedisConfig.java
│   │               ├── controller
│   │               │   └── RedisController.java
│   │               ├── model
│   │               │   └── Student.java
│   │               ├── repository
│   │               │   └── StudentRepository.java
│   │               ├── service
│   │               │   └── RedisService.java
│   │               └── RedisDemoApplication.java
│   └── resources
│       └── application.properties
```

### Cấu hình Redis

Trước tiên, bạn cần cấu hình kết nối tới Redis bằng cách thêm các thông tin sau vào file `application.properties`:

```properties
spring.redis.host=localhost
spring.redis.port=6379
```

Sau đó, chúng ta tạo một class `RedisConfig` để cấu hình Redis trong ứng dụng Spring Boot:

```java
import org.springframework.beans.factory.annotation.Value;
import org.springframework.boot.context.properties.EnableConfigurationProperties;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.context.annotation.Primary;
import org.springframework.data.redis.connection.RedisConnectionFactory;
import org.springframework.data.redis.connection.RedisStandaloneConfiguration;
import org.springframework.data.redis.connection.lettuce.LettuceConnectionFactory;
import org.springframework.data.redis.core.RedisTemplate;

@Configuration
public class RedisConfig {
    @Value("${spring.redis.host}")
    private String redisHost;

    @Value("${spring.redis.port}")
    private int redisPort;

    @Bean
    public LettuceConnectionFactory redisConnectionFactory() {
        // Tạo Standalone Connection tới Redis
        return new LettuceConnectionFactory(new RedisStandaloneConfiguration(redisHost, redisPort));
    }

    @Bean
    @Primary
    public RedisTemplate<Object, Object> redisTemplate(RedisConnectionFactory redisConnectionFactory) {
        // Tạo một RedisTemplate
        // Với Key là Object
        // Value là Object
        // RedisTemplate giúp chúng ta thao tác với Redis
        RedisTemplate<Object, Object> template = new RedisTemplate<>();
        template.setConnectionFactory(redisConnectionFactory);
        return template;
    }
}
```

Trong `RedisConfig`, chúng ta sử dụng `LettuceConnectionFactory` để kết nối tới Redis. Nếu bạn muốn cấu hình kết nối với Redis Cluster hoặc có yêu cầu cụ thể khác, bạn có thể thay đổi cấu hình ở đây.

### Thực hiện các thao tác Redis

Chúng ta đã có Redis được cấu hình, giờ hãy tạo một ví dụ đơn giản để thực hiện một số thao tác Redis.

Đầu tiên, tạo một class `Student` để thể hiện một đối tượng sinh viên:

```java
import java.io.Serializable;

public class Student implements Serializable {
    private static final long serialVersionUID = 1L;

    private String id;
    private String name;
    private int age;

    // Getter và setter
}
```

Tiếp theo, chúng ta tạo một service `RedisService` để thực hiện các thao tác CRUD đối với sinh viên trong Redis:

```java
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.data.redis.core.HashOperations;
import org.springframework.data.redis.core.RedisTemplate;
import org.springframework.stereotype.Service;

import java.util.Map;

@Service
public class RedisService {
    private static final String HASH_KEY = "STUDENT";

    @Autowired
    private RedisTemplate<Object, Object> redisTemplate;

    private HashOperations<Object, String, Student> hashOperations;

    @Autowired
    public RedisService(RedisTemplate<Object, Object> redisTemplate) {
        this.redisTemplate = redisTemplate;
        this.hashOperations = redisTemplate.opsForHash();
    }

    public void save(Student student) {
        hashOperations.put(HASH_KEY, student.getId(), student);
    }

    public Map<String, Student> findAll() {
        return hashOperations.entries(HASH_KEY);
    }

    public Student findById(String id) {
        return hashOperations.get(HASH_KEY, id);
    }

    public void update(Student student) {
        save(student);
    }

    public void delete(String id) {
        hashOperations.delete(HASH_KEY, id);
    }
}
```

Bây giờ chúng ta có một service `RedisService` để thực hiện các thao tác CRUD đối với sinh viên sử dụng Redis. Chúng ta sử dụng HashOperations để quản lý dữ liệu.

Cuối cùng, chúng ta tạo một controller `RedisController` để xử lý các yêu cầu HTTP và thực hiện thao tác với Redis thông qua `RedisService`:

```java
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.util.Map;

@RestController
@RequestMapping("/students")
public class RedisController {
    @Autowired
    private RedisService redisService;

    @PostMapping
    public void addStudent(@RequestBody Student student) {
        redisService.save(student);
    }

    @GetMapping
    public Map<String, Student> getAllStudents() {
        return redisService.findAll();
    }

    @GetMapping("/{id}")
    public Student getStudentById(@PathVariable String id) {
        return redisService.findById(id);
    }

    @PutMapping("/{id}")
    public void updateStudent(@PathVariable String id, @RequestBody Student student) {
        Student existingStudent = redisService.findById(id);
        if (existingStudent != null) {
            student.setId(id);
            redisService.update(student);
        }
    }

    @DeleteMapping("/{id}")
    public void deleteStudent(@PathVariable String id) {
        redisService.delete(id);
    }
}
```

### Kết quả

Bây giờ, chúng ta đã có ứng dụng Spring Boot tích hợp Redis. Bạn có thể thực hiện các thao tác CRUD đối với sinh viên thông qua các yêu cầu HTTP:

1. **Thêm sinh viên**: `POST` tới `/students` với dữ liệu sinh viên trong body.
2. **Lấy danh sách sinh viên**: `GET` tới `/students`.
3. **Lấy sinh viên theo ID**: `GET` tới `/students/{id}`.
4. **Cập nhật sinh viên**: `PUT` tới `/students/{id}` với dữ liệu cập nhật trong body.
5. **Xóa sinh viên**: `DELETE` tới `/students/{id}`.

Hãy sử dụng [Postman](https://www.postman.com/) hoặc công cụ tương tự để thử nghiệm các yêu cầu này và kiểm tra các thao tác Redis.

::alert{type="success"}
Trong bài viết này, chúng ta đã tìm hiểu cách tích hợp Redis vào ứng dụng Spring Boot để thực hiện các thao tác CRUD đối với dữ liệu Redis. Việc sử dụng Redis có thể cải thiện hiệu suất và tối ưu hóa việc lưu trữ dữ liệu đối với ứng dụng của bạn. Hãy tận dụng sức mạnh của Redis để xây dựng các ứng dụng mạnh mẽ và có hiệu suất cao.
::
