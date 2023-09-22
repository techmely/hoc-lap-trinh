---
title: "Demo Spring Boot với Thymeleaf, MySQL và i18n"
description: "Trong loạt series về Spring Boot này, chúng ta đã học qua nhiều kiến thức căn bản và cần thiết. Hôm nay, chúng ta sẽ áp dụng những kiến thức đã học để xây dựng một ứng dụng web quản lý công việc sử dụng Spring Boot, Thymeleaf, MySQL và i18n"
chapter:
  name: "Spring Boot cơ bản"
  slug: "chuong-03-spring-boot-co-ban"
category:
  name: "Spring Boot"
  slug: "spring-boot"
position: 14
---

Trong loạt series về Spring Boot này, chúng ta đã học qua nhiều kiến thức căn bản và cần thiết. Hôm nay, chúng ta sẽ áp dụng những kiến thức đã học để xây dựng một ứng dụng web quản lý công việc sử dụng Spring Boot, Thymeleaf, MySQL và i18n. Ứng dụng này sẽ cho phép bạn thêm, xem danh sách công việc và hỗ trợ đa ngôn ngữ.

## Cài đặt

Trước hết, chúng ta cần thêm các dependency sau vào file `pom.xml` để tạo dự án Spring Boot:

```xml
<!-- Spring Boot Starter Web -->
<dependency>
    <groupId>org.springframework.boot</groupId>
    <artifactId>spring-boot-starter-web</artifactId>
</dependency>

<!-- Lombok - Giúp giảm code boilerplate -->
<dependency>
    <groupId>org.projectlombok</groupId>
    <artifactId>lombok</artifactId>
    <optional>true</optional>
</dependency>

<!-- Spring Boot Starter Thymeleaf -->
<dependency>
    <groupId>org.springframework.boot</groupId>
    <artifactId>spring-boot-starter-thymeleaf</artifactId>
</dependency>

<!-- Spring Boot Starter Data JPA -->
<dependency>
    <groupId>org.springframework.boot</groupId>
    <artifactId>spring-boot-starter-data-jpa</artifactId>
</dependency>

<!-- MySQL Connector -->
<dependency>
    <groupId>mysql</groupId>
    <artifactId>mysql-connector-java</artifactId>
</dependency>
```

### Tạo Database

Chúng ta sẽ sử dụng MySQL là cơ sở dữ liệu. Hãy tạo một schema `todo_db` và một bảng `todo` trong cơ sở dữ liệu này bằng cách sử dụng các câu lệnh SQL sau:

```sql
CREATE SCHEMA IF NOT EXISTS `todo_db` DEFAULT CHARACTER SET utf8mb4 ;

CREATE TABLE IF NOT EXISTS `todo_db`.`todo` (
  `id` INT(11) NOT NULL AUTO_INCREMENT,
  `title` VARCHAR(255) NULL DEFAULT NULL,
  `detail` VARCHAR(255) NULL DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE = InnoDB DEFAULT CHARACTER SET = utf8mb4;
```

### Cấu hình ứng dụng

Chúng ta cần cấu hình ứng dụng Spring Boot để kết nối với cơ sở dữ liệu MySQL và cung cấp hỗ trợ cho Thymeleaf và i18n (đa ngôn ngữ). Các thông tin này được cấu hình trong file `application.properties`:

```properties
# Chạy ứng dụng trên port 8085
server.port=8085

# Tắt tính năng cache của Thymeleaf để phát triển nhanh hơn
spring.thymeleaf.cache=false

# Định nghĩa thư mục chứa các message đa ngôn ngữ
spring.messages.basename=i18n/messages

# Chỉ định ngôn ngữ mặc định (Tiếng Việt)
spring.mvc.locale=vi_VN

# Cấu hình kết nối đến cơ sở dữ liệu MySQL
spring.datasource.url=jdbc:mysql://localhost:3306/todo_db?useSSL=false
spring.datasource.username=root
spring.datasource.password=root

# Hibernate Properties
spring.jpa.properties.hibernate.dialect = org.hibernate.dialect.MySQL5InnoDBDialect
spring.jpa.hibernate.ddl-auto = update
```

### Tạo Model

Chúng ta sẽ tạo một model `Todo` để liên kết với bảng `todo` trong cơ sở dữ liệu MySQL. Đây là cách chúng ta sử dụng Lombok và Hibernate để định nghĩa model này:

```java
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;

import lombok.Data;

@Entity
@Data
public class Todo {
    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long id;

    private String title;
    private String detail;
}
```

Ngoài ra, chúng ta cũng tạo một đối tượng `TodoValidator` để kiểm tra tính hợp lệ của đối tượng `Todo` trước khi lưu vào cơ sở dữ liệu:

```java
import org.thymeleaf.util.StringUtils;
import java.util.Optional;

public class TodoValidator {
    public boolean isValid(Todo todo) {
        return Optional.ofNullable(todo)
                       .filter(t -> !StringUtils.isEmpty(t.getTitle()))
                       .filter(t -> !StringUtils.isEmpty(t.getDetail()))
                       .isPresent();
    }
}
```

### Tầng Config

Chúng ta sử dụng `@Configuration` và `@Bean` để tạo một bean `TodoValidator`:

```java
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

@Configuration
public class TodoConfig {
    @Bean
    public TodoValidator validator() {
        return new TodoValidator();
    }
}
```

### Tầng Repository

Tầng Repository được sử dụng để giao tiếp với cơ sở dữ liệu. Chúng ta sử dụng Spring JPA để định nghĩa repository:

```java
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;

@Repository
public interface TodoRepository extends JpaRepository<Todo, Long> {
}
```

### Tầng Service

Tầng Service chứa các logic xử lý nghiệp vụ và hỗ trợ cho tầng Controller. Dưới đây là một số phương thức trong tầng Service:

```java
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.data.domain.PageRequest;
import org.springframework.stereotype.Service;
import org.thymeleaf.util.StringUtils;

import java.util.List;
import java.util.Optional;

@Service
public class TodoService {
    @Autowired
    private TodoRepository todoRepository;

    @Autowired
    private TodoValidator validator;

    public List<Todo> findAll(Integer limit) {
        return Optional.ofNullable(limit)
                       .map(value -> todoRepository.findAll(PageRequest.of(0, value)).getContent())
                       .orElseGet(() -> todoRepository.findAll());
    }

    public Todo add(Todo todo) {
        if (validator.isValid(todo)) {
            return todoRepository.save(todo);
        }
        return null;
    }
}
```

### Tầng Controller

Tầng Controller nhận các request từ người dùng và chuyển tiếp cho tầng Service xử lý. Dưới đây là một số phương thức trong tầng `Controller`:

```java
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.*;
import java.util.List;

@Controller
public class TodoController {
    @Autowired
    private TodoService todoService;

    @GetMapping("/listTodo")
    public String index(Model model, @RequestParam(value = "limit", required = false) Integer limit) {
        model.addAttribute("todoList", todoService.findAll(limit));
        return "listTodo";
    }

    @GetMapping("/addTodo")
    public String addTodo(Model model) {
        model.addAttribute("todo", new Todo());
        return "addTodo";
    }

    @PostMapping("/addTodo")
    public String addTodo(@ModelAttribute Todo todo) {
        return todoService.add(todo) != null ? "success" : "failed";
    }
}
```

### Templates

Chúng ta sử dụng Thymeleaf làm Template Engine để xây dựng các trang web. Dưới đây là một số ví dụ về các template:

**index.html**

```html
<!DOCTYPE html>
<html xmlns:th="http://www.thymeleaf.org">
  <head>
    <meta charset="UTF-8" />
    <title>Kungfutech To-do</title>
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />

    <!--css-->
    <link th:href="@{/css/bootstrap.css}" rel="stylesheet" />
    <link th:href="@{/css/main.css}" rel="stylesheet" />

    <!--js-->
    <script th:src="@{/js/bootstrap.js}"></script>
  </head>
  <body>
    <h1 th:text="#{kungfutech.message.hello}"></h1>

    <a
      th:href="@{/listTodo}"
      th:text="#{kungfutech.value.viewListTodo}"
      class="btn btn-primary"
    ></a>
    <a
      th:href="@{/addTodo}"
      th:text="#{kungfutech.value.addTodo}"
      class="btn btn-success"
    ></a>
  </body>
</html>
```

**listTodo.html**

```html
<!DOCTYPE html>
<html xmlns:th="http://www.thymeleaf.org">
  <head>
    <meta charset="UTF-8" />
    <title>Kungfutech To-do</title>
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />

    <!--css-->
    <link th:href="@{/css/bootstrap.css}" rel="stylesheet" />
    <link th:href="@{/css/main.css}" rel="stylesheet" />

    <!--js-->
    <script th:src="@{/js/bootstrap.js}"></script>
  </head>
  <body>
    <h1 th:text="#{kungfutech.value.listTodo} + ':'"></h1>

    <ul>
      <li th:each="todo : ${todoList}">
        <span th:text="${todo.getTitle()}"></span> :
        <span th:text="${todo.getDetail()}"></span>
      </li>
    </ul>

    <a
      th:href="@{/addTodo}"
      th:text="#{kungfutech.value.addTodo}"
      class="btn btn-success"
    ></a>
  </body>
</html>
```

**addTodo.html**

```html
<!DOCTYPE html>
<html xmlns:th="http://www.thymeleaf.org">
  <head>
    <meta charset="UTF-8" />
    <title>Kungfutech To-do</title>
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />

    <!--css-->
    <link th:href="@{/css/bootstrap.css}" rel="stylesheet" />
    <link th:href="@{/css/main.css}" rel="stylesheet" />

    <!--js-->
    <script th:src="@{/js/bootstrap.js}"></script>
  </head>
  <body>
    <h1>To-do</h1>

    <form th:action="@{/addTodo}" th:object="${todo}" method="post">
      <p>title: <input type="text" th:field="*{title}" /></p>
      <p>detail: <input type="text" th:field="*{detail}" /></p>
      <p><button type="submit" class="btn btn-success">Add</button></p>
    </form>
  </body>
</html>
```

**success.html**

```html
<!DOCTYPE html>
<html xmlns:th="http://www.thymeleaf.org">
  <head>
    <meta charset="UTF-8" />
    <title>Kungfutech To-do</title>
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />

    <link th:href="@{/css/bootstrap.css}" rel="stylesheet" />
    <link th:href="@{/css/main.css}" rel="stylesheet" />
  </head>
  <body>
    <h1>To-do</h1>
    <h1 style="color: green" th:text="#{kungfutech.message.success}"></h1>

    <a
      th:href="@{/listTodo}"
      th:text="#{kungfutech.value.viewListTodo}"
      class="btn btn-primary"
    ></a>
  </body>
</html>
```

**failed.html**

```html
<!DOCTYPE html>
<html xmlns:th="http://www.thymeleaf.org">
  <head>
    <meta charset="UTF-8" />
    <title>Kungfutech To-do</title>
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />

    <link th:href="@{/css/bootstrap.css}" rel="stylesheet" />
    <link th:href="@{/css/main.css}" rel="stylesheet" />
  </head>
  <body>
    <h1>To-do</h1>
    <h1 style="color: red" th:text="#{kungfutech.message.failed}"></h1>

    <a
      th:href="@{/listTodo}"
      th:text="#{kungfutech.value.viewListTodo}"
      class="btn btn-primary"
    ></a>
  </body>
</html>
```

### i18n

Chúng ta sử dụng i18n (Internationalization) để hỗ trợ nhiều ngôn ngữ trong ứng dụng. Các message được định nghĩa trong các file properties cho từng ngôn ngữ. Dưới đây là ví dụ về file message tiếng Việt và tiếng Anh:

**i18n/messages_vi.properties**

```properties
kungfutech.message.hello=Chào mừng bạn đến với ứng dụng Todo
kungfutech.message.success=Thêm công việc thành công!
kungfutech.message.failed=Thêm công việc thất bại!

kungfutech.value.addTodo=Thêm công việc
kungfutech.value.viewListTodo=Xem danh sách công việc
kungfutech.value.listTodo=Danh sách công việc
```

**i18n/messages_en.properties**

```properties
kungfutech.message.hello=Welcome to TodoApp
kungfutech.message.success=Add To-do Successfully!
kungfutech.message.failed=Add To-do Failed!

kungfutech.value.addTodo=Add To-do
kungfutech.value.viewListTodo=View To-do list
kungfutech.value.listTodo=To-do list
```

### Chạy ứng dụng

Để chạy ứng dụng, bạn cần tạo một class chính (main class) để khởi động ứng dụng. Dưới đây là ví dụ về class main:

```java
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;

@SpringBootApplication
public class TodoApplication {
    public static void main(String[] args) {
        SpringApplication.run(TodoApplication.class, args);
    }
}
```

Sau khi đã tạo class main, bạn có thể chạy ứng dụng bằng cách chọn Run hoặc Debug trong IDE của bạn.

Khi ứng dụng đã chạy, bạn có thể truy cập nó bằng cách mở trình duyệt và nhập URL `http://localhost:8080`.

::alert{type="success"}
Trong bài viết này, chúng ta đã tạo một ứng dụng web đơn giản sử dụng Spring Boot, Thymeleaf, MySQL và i18n. Chúng ta đã xây dựng các tầng Controller, Service, và Repository, và sử dụng Thymeleaf để tạo các trang web. Chúng ta cũng đã học cách sử dụng i18n để hỗ trợ nhiều ngôn ngữ trong ứng dụng.
::
