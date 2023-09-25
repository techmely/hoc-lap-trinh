---
title: "@PostMapping annotation và @RequestMapping annotation"
description: "Trong bài viết này, chúng ta sẽ tìm hiểu về cách sử dụng hai annotation quan trọng trong Spring Boot để xử lý các yêu cầu HTTP: @PostMapping và @RequestMapping"
chapter:
  name: "Spring Boot cơ bản"
  slug: "chuong-03-spring-boot-co-ban"
category:
  name: "Spring Boot"
  slug: "spring-boot"
position: 10
---

Trong bài viết này, chúng ta sẽ tìm hiểu về cách sử dụng hai annotation quan trọng trong Spring Boot để xử lý các yêu cầu HTTP: `@PostMapping` và `@RequestMapping`. Chúng ta sẽ giải thích ý nghĩa và cách sử dụng của chúng thông qua ví dụ Java cụ thể.

## `@PostMapping` trong Spring Boot

`@PostMapping` là một annotation trong Spring Boot được sử dụng để đánh dấu một phương thức xử lý yêu cầu HTTP POST. Trong HTTP, POST được sử dụng để gửi dữ liệu từ máy khách đến máy chủ. Điều này thường được sử dụng khi bạn muốn thêm dữ liệu mới, ví dụ: thêm một bài viết vào cơ sở dữ liệu hoặc gửi biểu mẫu đăng ký.

### Ví dụ `@PostMapping`

Dưới đây là ví dụ minh họa về cách sử dụng `@PostMapping`:

```java
@Controller
public class WebController {
    // Xử lý yêu cầu POST để thêm công việc
    @PostMapping("/addTodo")
    public String addTodo(@ModelAttribute Todo todo) {
        // Thêm công việc vào cơ sở dữ liệu hoặc danh sách công việc
        // Trả về trang thành công
        return "success";
    }
}
```

Ở ví dụ trên, chúng ta có một phương thức `addTodo` được đánh dấu bởi `@PostMapping("/addTodo")`. Khi một yêu cầu POST được gửi đến đường dẫn `/addTodo`, Spring Boot sẽ gọi phương thức này và chúng ta có thể xử lý yêu cầu và thêm công việc vào cơ sở dữ liệu.

## `@RequestMapping` trong Spring Boot

`@RequestMapping` là một annotation mạnh mẽ trong Spring Boot cho phép bạn định nghĩa một phương thức xử lý yêu cầu HTTP cho nhiều phương thức HTTP khác nhau (GET, POST, PUT, DELETE, v.v.). Nó cũng cho phép bạn chỉ định một đường dẫn cơ bản cho một nhóm phương thức xử lý yêu cầu.

### Ví dụ `@RequestMapping`

Dưới đây là ví dụ về cách sử dụng `@RequestMapping`:

```java
@Controller
@RequestMapping("/api/v1")
public class WebController {
    // Xử lý yêu cầu GET đến /api/v1/addTodo
    @RequestMapping(value = "/addTodo", method = RequestMethod.GET)
    public String addTodo(Model model) {
        // Xử lý yêu cầu GET
        return "addTodo";
    }

    // Xử lý yêu cầu POST đến /api/v1/addTodo
    @RequestMapping(value = "/addTodo", method = RequestMethod.POST)
    public String addTodo(@ModelAttribute Todo todo) {
        // Xử lý yêu cầu POST
        return "success";
    }
}
```

Trong ví dụ trên, chúng ta có một lớp `WebController` được đánh dấu bởi `@RequestMapping("/api/v1")`, điều này có nghĩa là tất cả các phương thức trong lớp này sẽ có một tiền tố là `/api/v1`. Bằng cách này, chúng ta có thể quản lý các yêu cầu cho một tài nguyên cụ thể.

Chú ý rằng `@RequestMapping` cũng cho phép bạn sử dụng các phương thức HTTP khác nhau như `GET`, `POST`, `PUT`, và `DELETE` bằng cách chỉ định `method`.

## Kết quả của đoạn code

Dưới đây là kết quả của đoạn mã code trong bài viết:

### Khi gửi yêu cầu GET đến `/addTodo`

Nếu bạn gửi một yêu cầu GET đến đường dẫn `/addTodo`, phương thức `addTodo` với `@RequestMapping` sẽ được gọi và bạn có thể xử lý yêu cầu `GET`.

### Khi gửi yêu cầu POST đến `/addTodo`

Nếu bạn gửi một yêu cầu POST đến đường dẫn `/addTodo`, phương thức `addTodo` với `@PostMapping` sẽ được gọi và bạn có thể xử lý yêu cầu `POST`.

::alert{type="success"}
Trong bài viết này, chúng ta đã tìm hiểu cách sử dụng `@PostMapping` và `@RequestMapping` trong Spring Boot để xử lý các yêu cầu HTTP GET và POST. Điều này cho phép chúng ta xây dựng các ứng dụng web mạnh mẽ với khả năng xử lý các loại yêu cầu khác nhau từ máy khách. Chúc bạn thành công trong việc phát triển ứng dụng Spring Boot của mình!
::
