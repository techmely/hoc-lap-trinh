---
title: "Restful API với @RestController, @PathVariable, @RequestBody"
description: "Trong bài viết này, chúng ta sẽ tìm hiểu về cách tạo Restful API bằng Spring Boot, sử dụng các chú thích quan trọng như @RestController, @PathVariable, và @RequestBody"
chapter:
  name: "Spring Boot cơ bản"
  slug: "chuong-03-spring-boot-co-ban"
position: 13
---

Trong bài viết này, chúng ta sẽ tìm hiểu về cách tạo Restful API bằng Spring Boot, sử dụng các chú thích quan trọng như `@RestController`, `@PathVariable`, và `@RequestBody`. Các ví dụ sẽ được thực hiện bằng ngôn ngữ Java để giúp bạn hiểu rõ hơn.

## Giới Thiệu

Trong thế giới phát triển web hiện nay, có một xu hướng để phía frontend framework thực hiện nhiều công việc hơn, trong khi phía máy chủ (server) chỉ cung cấp API cho frontend. Spring Boot là một framework mạnh mẽ cho việc xây dựng các Restful API.

## @RestController annotation

`@RestController` là một chú thích quan trọng trong Spring Boot. Khác với `@Controller`, nó không trả về một template mà thay vào đó trả về dữ liệu dưới dạng JSON.

```java
@RestController
@RequestMapping("/api/v1")
public class RestApiController {

    @GetMapping("/todo")
    public List<Todo> getTodoList() {
        return todoList;
    }
}
```

Các đối tượng được trả về sẽ tự động được Spring Boot chuyển đổi thành JSON. Bạn có thể trả về nhiều loại đối tượng như `List`, `Map`, và nó sẽ được chuyển đổi một cách tự động. Spring Boot sử dụng Jackson converter mặc định để thực hiện việc này. Nếu bạn muốn tùy chỉnh kiểu dữ liệu trả về, bạn có thể sử dụng đối tượng `ResponseEntity`.

## @RequestBody annotation

Khi bạn xây dựng các API, thông tin từ phía client thường được gửi trong phần `Body` của request dưới dạng JSON.

```java
@RestController
@RequestMapping("/api/v1")
public class RestApiController {

    @PostMapping("/todo")
    public ResponseEntity addTodo(@RequestBody Todo todo) {
        todoList.add(todo);
        return ResponseEntity.ok().body(todo);
    }
}
```

Spring Boot sẽ tự động chuyển đổi chuỗi JSON trong request thành một đối tượng Java. Bạn chỉ cần sử dụng chú thích `@RequestBody` để cho Spring Boot biết bạn muốn chuyển đổi JSON thành đối tượng Java.

## @PathVariable annotation

RESTful API thường đặt thông tin quan trọng trong URL của API. Để truy cập thông tin này, chúng ta sử dụng `@PathVariable`.

```java
@RestController
@RequestMapping("/api/v1")
public class RestApiController {

    @GetMapping("/todo/{todoId}")
    public Todo getTodo(@PathVariable(name = "todoId") Integer todoId){
        return todoList.get(todoId);
    }
}
```

`@PathVariable` cho biết cho Spring Boot lấy thông tin từ URL dựa trên tên thuộc tính đã định nghĩa trong chú thích `@GetMapping`.

## Ví dụ

Dưới đây là một ví dụ đơn giản về cách xây dựng một Restful API bằng Spring Boot:

```java
@RestController
@RequestMapping("/api/v1")
public class RestApiController {

    private List<Todo> todoList = new CopyOnWriteArrayList<>();

    @PostConstruct
    public void init(){
        todoList.add(null);
    }

    @GetMapping("/todo")
    public List<Todo> getTodoList() {
        return todoList;
    }

    @GetMapping("/todo/{todoId}")
    public Todo getTodo(@PathVariable(name = "todoId") Integer todoId){
        return todoList.get(todoId);
    }

    @PutMapping("/todo/{todoId}")
    public Todo editTodo(@PathVariable(name = "todoId") Integer todoId, @RequestBody Todo todo){
        todoList.set(todoId, todo);
        return todo;
    }

    @DeleteMapping("/todo/{todoId}")
    public ResponseEntity deleteTodo(@PathVariable(name = "todoId") Integer todoId){
        todoList.remove(todoId.intValue());
        return ResponseEntity.ok().build();
    }

    @PostMapping("/todo")
    public ResponseEntity addTodo(@RequestBody Todo todo) {
        todoList.add(todo);
        return ResponseEntity.ok().body(todo);
    }
}
```

::alert{type="success"}
Trong bài viết này, chúng ta đã tìm hiểu cách tạo Restful API bằng Spring Boot và sử dụng các chú thích quan trọng như `@RestController`, `@PathVariable`, và `@RequestBody`. Restful API là một phần quan trọng của phát triển ứng dụng web ngày nay và Spring Boot cung cấp một cách dễ dàng để xây dựng chúng.
::
