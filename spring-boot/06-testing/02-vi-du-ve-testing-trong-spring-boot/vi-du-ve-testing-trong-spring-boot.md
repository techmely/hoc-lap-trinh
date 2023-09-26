---
title: "Ví dụ về testing trong Spring Boot"
description: "Trong bài viết này, chúng ta sẽ tìm hiểu cách thực hiện testing trong Spring Boot bằng Java, với sự hỗ trợ của Hibernate, Spring JPA, Lombok và Spring Boot"
chapter:
  name: "Testing"
  slug: "chuong-06-testing"
category:
  name: "SpringBoots"
  slug: "springboots"
image: https://kungfutech.edu.vn/thumbnail.png
position: 2
---

Testing là một phần quan trọng trong quá trình phát triển ứng dụng để đảm bảo rằng mã nguồn của bạn hoạt động đúng và ổn định. Trong bài viết này, chúng ta sẽ tìm hiểu cách thực hiện testing trong Spring Boot bằng Java, với sự hỗ trợ của Hibernate, Spring JPA, Lombok và Spring Boot.

## Chuẩn bị Dự Án

Đầu tiên, hãy tạo một dự án Spring Boot đơn giản. Dưới đây là một ví dụ về `pom.xml` để sử dụng các dependency cần thiết:

```xml
<?xml version="1.0" encoding="UTF-8"?>
<project xmlns="http://maven.apache.org/POM/4.0.0"
         xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
         xsi:schemaLocation="http://maven.apache.org/POM/4.0.0 https://maven.apache.org/xsd/maven-4.0.0.xsd">
    <modelVersion>4.0.0</modelVersion>
    <parent>
        <groupId>org.springframework.boot</groupId>
        <artifactId>spring-boot-starter-parent</artifactId>
        <version>2.0.5.RELEASE</version>
        <relativePath/>
    </parent>
    <groupId>me.kungfutech.spring</groupId>
    <artifactId>example-independent-maven-spring-project</artifactId>
    <version>0.0.1-SNAPSHOT</version>
    <name>example-independent-maven-spring-project</name>
    <description>Demo project for Spring Boot</description>
    <properties>
        <java.version>1.8</java.version>
    </properties>
    <dependencies>
        <dependency>
            <groupId>org.springframework.boot</groupId>
            <artifactId>spring-boot-starter-web</artifactId>
        </dependency>
        <dependency>
            <groupId>org.springframework.boot</groupId>
            <artifactId>spring-boot-devtools</artifactId>
            <scope>runtime</scope>
            <optional>true</optional>
        </dependency>
        <dependency>
            <groupId>org.projectlombok</groupId>
            <artifactId>lombok</artifactId>
            <optional>true</optional>
        </dependency>
        <dependency>
            <groupId>org.springframework.boot</groupId>
            <artifactId>spring-boot-starter-test</artifactId>
            <scope>test</scope>
        </dependency>
        <!-- Spring JPA -->
        <dependency>
            <groupId>org.springframework.boot</groupId>
            <artifactId>spring-boot-starter-data-jpa</artifactId>
        </dependency>
        <!-- In-memory database -->
        <dependency>
            <groupId>com.h2database</groupId>
            <artifactId>h2</artifactId>
            <scope>runtime</scope>
        </dependency>
    </dependencies>
    <build>
        <plugins>
            <plugin>
                <groupId>org.springframework.boot</groupId>
                <artifactId>spring-boot-maven-plugin</artifactId>
            </plugin>
        </plugins>
    </build>
</project>
```

Sau khi tạo dự án, hãy thêm các class cơ bản sau:

### Todo.java

```java
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;

@Data
@AllArgsConstructor
@NoArgsConstructor
@Entity
public class Todo {
    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private int id;
    private String title;
    private String detail;
}
```

### TodoRepository.java

```java
import org.springframework.data.jpa.repository.JpaRepository;

import java.util.List;

public interface TodoRepository extends JpaRepository<Todo, Long> {
    List<Todo> findAll();

    Todo findById(int id);
}
```

### TodoController.java

```java
import lombok.RequiredArgsConstructor;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

@RestController
@RequestMapping("/api/v1")
@RequiredArgsConstructor
public class TodoRestController {
    private final TodoService todoService;

    @GetMapping("/todo")
    public List<Todo> findAll() {
        return todoService.getAll();
    }
}
```

### DataJpaAnnotationTest.java

```java
import org.assertj.core.api.Assertions;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.autoconfigure.orm.jpa.DataJpaTest;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.test.context.junit4.SpringRunner;

import javax.persistence.EntityManager;
import javax.sql.DataSource;

@RunWith(SpringRunner.class)
@DataJpaTest
public class DataJpaAnnotationTest {
    @Autowired
    private DataSource dataSource;
    @Autowired
    private JdbcTemplate jdbcTemplate;
    @Autowired
    private EntityManager entityManager;
    @Autowired
    private TodoRepository todoRepository;

    @Test
    public void allComponentAreNotNull() {
        Assertions.assertThat(dataSource).isNotNull();
        Assertions.assertThat(jdbcTemplate).isNotNull();
        Assertions.assertThat(entityManager).isNotNull();
        Assertions.assertThat(todoRepository).isNotNull();
    }
}
```

## Testing với `@DataJpaTest`

Testing một ứng dụng Spring Boot có thể phức tạp, đặc biệt là khi liên quan đến cơ sở dữ liệu. Tuy nhiên, chúng ta có thể sử dụng `@DataJpaTest` để giới hạn phạm vi testing. `@DataJpaTest` sẽ giúp chúng ta tạo ra môi trường test cho các tầng Repository mà không cần khởi động toàn bộ ứng dụng Spring Boot.

Trong ví dụ trên, chúng ta đã test các thành phần liên quan đến cơ sở dữ liệu như `DataSource`, `JdbcTemplate`, `EntityManager`, và `TodoRepository`. `@DataJpaTest` sẽ khởi tạo các Bean liên quan đến tầng Repository, giúp bạn kiểm tra chúng một cách dễ dàng.

## Chuẩn bị Dữ Liệu Test

Trong thực tế, chúng ta không thể mãi mãi sử dụng dữ liệu giả mạo cho các test case. Điều này có thể tạo ra một lỗ hổng lớn trong kiểm thử của bạn. Bên cạnh đó, bạn cũng muốn kiểm tra quá trình tương tác với cơ sở dữ liệu thật của ứng dụng của bạn.

Spring Boot đã cung cấp một số cách để chuẩn bị dữ liệu cho các test case.

### Tạo Dữ Liệu Giả Mạo

Một cách đơn giản để chuẩn bị dữ liệu giả mạo là tự thêm dữ liệu bằng cách sử dụng `repository`. Dưới đây là một ví dụ:

```java
@Test
public void testTodoRepositoryByCode() {
    todoRepository.save(new Todo(0, "Todo-1", "Detail-1"));
    todoRepository.save(new Todo(0, "Todo-2", "Detail-2"));

    Assertions.assertThat(todoRepository.findAll()).hasSize(2);
    Assertions.assertThat(todoRepository.findById(1).getTitle()).isEqualTo("Todo-1");
}
```

Trong ví dụ này, chúng ta đã thêm hai bản ghi `Todo` bằng cách sử dụng `todoRepository`, sau đó kiểm tra xem chúng đã được thêm thành công hay không.

### Sử dụng `@Sql`

Một cách tốt hơn để chuẩn bị dữ liệu cho các test case là sử dụng annotation `@Sql`. Annotation này cho phép bạn chạy các tệp script SQL trước khi thực hiện các test case. Dưới đây là một ví dụ:

#### createTodo.sql

```sql
INSERT INTO todo (title, detail) VALUES ('Todo-1', 'Do homework');
INSERT INTO todo (title, detail) VALUES ('Todo-2', 'Walking');
```

Để chạy script SQL này trong test case, bạn có thể sử dụng annotation `@Sql` như sau:

```java
@RunWith(SpringRunner.class)
@DataJpaTest
public class SqlAnnotationTest {
    @Autowired
    private TodoRepository todoRepository;

    @Test
    @Sql("/createTodo.sql")
    public void testTodoRepositoryBySqlSchema() {
        Assertions.assertThat(todoRepository.findAll()).hasSize(2);
        Assertions.assertThat(todoRepository.findById(1).getTitle()).isEqualTo("Todo-1");
    }
}
```

Annotation `@Sql` giúp bạn thực thi các tệp script SQL trước khi thực hiện các test case. Điều này giúp bạn chuẩn bị dữ liệu một cách dễ dàng và nhanh chóng.

::alert{type="success"}
Trong bài viết này, chúng ta đã tìm hiểu cách thực hiện testing trong Spring Boot bằng cách sử dụng các annotation như `@DataJpaTest` và `@Sql`. Testing là một phần quan trọng của quá trình phát triển ứng dụng để đảm bảo tính ổn định và đúng đắn của mã nguồn. Chúng ta cũng đã thấy cách chuẩn bị dữ liệu cho các test case một cách hiệu quả.
::
