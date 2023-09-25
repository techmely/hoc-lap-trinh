---
title: "Exception handling trong Spring Boot"
description: "Xử lý ngoại lệ (Exception handling) là một phần quan trọng của việc phát triển ứng dụng, bao gồm cả việc xây dựng các Restful API trong Spring Boot"
chapter:
  name: "Spring Boot cơ bản"
  slug: "chuong-03-spring-boot-co-ban"
category:
  name: "Spring Boot"
  slug: "spring-boot"
position: 14
---

**Xử lý ngoại lệ** (Exception handling) là một phần quan trọng của việc phát triển ứng dụng, bao gồm cả việc xây dựng các Restful API trong **Spring Boot**. Trong bài viết này, chúng ta sẽ tìm hiểu về cách xử lý ngoại lệ trong Spring Boot bằng cách sử dụng các chú thích quan trọng như `@RestControllerAdvice`, `@ControllerAdvice`, và `@ExceptionHandler`. Các ví dụ sẽ được thực hiện bằng ngôn ngữ Java để giúp bạn hiểu rõ hơn.

## Giới Thiệu

Trong việc phát triển các Restful API, có nhiều tình huống mà bạn cần kiểm soát, ví dụ như khi người dùng yêu cầu thông tin của một đối tượng không tồn tại. Trong trường hợp như vậy, chúng ta không muốn ứng dụng gửi về cho người dùng một lỗi hệ thống mà thay vào đó muốn trả về một thông báo lỗi thân thiện hơn.

### @RestControllerAdvice & @ControllerAdvice + @ExceptionHandler

- `@RestControllerAdvice` là một Annotation được áp dụng trên một class và thường được sử dụng cùng với `@ExceptionHandler`. Nó can thiệp vào việc xử lý của các `@RestController`.

- `@ControllerAdvice` là một Annotation tương tự như `@RestControllerAdvice`, nhưng thường được sử dụng cùng với `@ExceptionHandler` để can thiệp vào việc xử lý của các Controller thông thường.

`@RestControllerAdvice` và `@ControllerAdvice` thường được kết hợp với `@ExceptionHandler` để xử lý ngoại lệ.

```java
@RestControllerAdvice
public class ApiExceptionHandler {

    @ExceptionHandler(IndexOutOfBoundsException.class)
    @ResponseStatus(value = HttpStatus.BAD_REQUEST)
    public ErrorMessage todoException(Exception ex, WebRequest request) {
        return new ErrorMessage(10100, "Đối tượng không tồn tại");
    }
}
```

Trong ví dụ trên, chúng ta đã sử dụng `@RestControllerAdvice` và `@ExceptionHandler` để xử lý ngoại lệ `IndexOutOfBoundsException`. Khi một ngoại lệ này xảy ra trong một Rest Controller, Spring Boot sẽ gọi phương thức `todoException` và trả về một thông báo lỗi thân thiện hơn với HTTP status code là `BAD_REQUEST`.

### @ResponseStatus

`@ResponseStatus` cho phép bạn định nghĩa HTTP status code mà bạn muốn trả về cho người dùng. Bạn có thể sử dụng nó trên một đối tượng được trả về từ một phương thức. Nếu bạn không muốn sử dụng `ResponseEntity`, bạn có thể sử dụng `@ResponseStatus`.

## Demo

### Cài Đặt

Chúng ta sẽ tạo một ứng dụng Spring Boot đơn giản để minh họa việc xử lý ngoại lệ.

#### Thêm Dependency

Chúng ta cần thêm dependency cho Spring Boot Web trong file `pom.xml`:

```xml
<dependency>
    <groupId>org.springframework.boot</groupId>
    <artifactId>spring-boot-starter-web</artifactId>
</dependency>
```

#### Tạo Model

Chúng ta sẽ tạo một đối tượng `Todo` và một đối tượng `ErrorMessage`:

```java
@Data
@AllArgsConstructor
public class Todo {
    private String title;
    private String detail;
}

@Data
@AllArgsConstructor
public class ErrorMessage {
    private int statusCode;
    private String message;
}
```

#### Tạo Rest Controller

Chúng ta sẽ tạo một Rest Controller đơn giản:

```java
@RestController
@RequestMapping("/api/v1")
public class RestApiController {

    private List<Todo> todoList;

    @PostConstruct
    public void init() {
        todoList = IntStream.range(0, 10)
                 .mapToObj(i -> new Todo("title-" + i, "detail-" + i))
                 .collect(Collectors.toList());
    }

    @GetMapping("/todo/{todoId}")
    public Todo getTodo(@PathVariable(name = "todoId") Integer todoId) {
        return todoList.get(todoId);
    }
}
```

#### Tạo Exception Handler

Chúng ta sẽ tạo một Exception Handler để xử lý ngoại lệ `IndexOutOfBoundsException`:

```java
@RestControllerAdvice
public class ApiExceptionHandler {

    @ExceptionHandler(IndexOutOfBoundsException.class)
    @ResponseStatus(value = HttpStatus.BAD_REQUEST)
    public ErrorMessage todoException(Exception ex, WebRequest request) {
        return new ErrorMessage(10100, "Đối tượng không tồn tại");
    }
}
```

### Chạy Thử

Chúng ta có thể chạy ứng dụng Spring Boot và gửi một request đến địa chỉ sau:

```bash
GET http://localhost:8080/api/v1/todo/11
```

Ở đây, đối tượng có `todoId

`là 11 không tồn tại trong danh sách, và chúng ta sẽ nhận được một thông báo lỗi thân thiện hơn với HTTP status code là`BAD_REQUEST`.

::result

{
"statusCode": 10100,
"message": "Đối tượng không tồn tại"
}

::

::alert{type="success"}

Trong bài viết này, chúng ta đã tìm hiểu cách xử lý ngoại lệ trong Spring Boot bằng cách sử dụng các chú thích quan trọng như `@RestControllerAdvice`, `@ControllerAdvice`, và `@ExceptionHandler`. Việc xử lý ngoại lệ là một phần quan trọng của việc xây dựng các ứng dụng, và Spring Boot cung cấp một cách dễ dàng để làm điều này, giúp ứng dụng của bạn trở nên mạnh mẽ và thân thiện hơn với người dùng.

::
