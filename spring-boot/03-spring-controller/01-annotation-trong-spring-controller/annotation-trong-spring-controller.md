---
title: "Spring Controller"
description: "Controller trong ứng dụng Spring Boot là nơi tiếp nhận request và trả về response cho client. Có thể hiểu controller chính là lớp trung gian giữa server của bạn và bên ngoài."
chapter:
  name: "Spring Controller"
  slug: "chuong-03-spring-controller"
category:
  name: "Spring Boot"
  slug: "spring-boot"
position: 1
---

### Giới thiệu

Về mặt code, Controller chỉ đơn thuần là một bean được đánh dấu với @Controller hoặc @RestController.

Trong Spring Boot, có hai dạng Controller, tương ứng hai annotation trên:

@Controller có thể trả về View qua một String hoặc JSON data trong response body (nếu được chỉ định). Thích hợp cho các controller có routing, chuyển trang các kiểu.
@RestController chỉ có thể trả về data trong response body. Thích hợp cho các controller để cung cấp API.
Do đó, ta có thể nói @RestController = @Controller + @ResponseBody.

### @Controller Annotation

Dưới đây là một ví dụ của controller:

**HomeController.java**

```java
@Controller
public class HomeController {
    // Bên trong controller sẽ có nhiều method, mỗi cái sẽ bắt request cụ thể

    // Bắt GET /home request và trả về view
    @GetMapping("/home")
    public String home(Model model) {
        model.addAttribute("name", "John");
        return "index";  // Return tên của View, model sẽ tự động pass vào view
    }

    // Hoặc có thể trả về data trong response body (như các API)
    @GetMapping("/users")
    @ResponseBody
    public List<User> getUserList() {
        return new ArrayList<>();
    }

    // Hoặc cái này tương tự như trên, nhưng có thể tùy chỉnh response status code, header,...
    @GetMapping("/users/{id})
    public ResponseEntity<User> getUserById(@PathVariable("id") String userId) {
        // Không cần @ResponseBody do có body rồi
        return ResponseEntity.status(200).body(new User());
    }
}
```

### Controller Mapping

#### 1. Các loại HTTP request

Bạn nào học về web hẳn đã rõ về khái niệm HTTP request. Mình sẽ không nói sâu về phần này, nhưng tạm hiểu mỗi HTTP request sẽ gồm 2 thông tin quan trọng:

- Request tới URL nào (request tới đâu)
- HTTP method là gì (thể hiện hành động gì đấy với URL)

Trong controller, chỉ cần nắm được hai thông tin trên thì sẽ bắt được mọi request được gửi tới, sau đó mới xử lý tiếp.

Trong Rest API design, thì người ta thường dùng danh từ trong URL để chỉ đối tượng được tác động. Còn các HTTP method để đại diện cho hành động nào sẽ áp dụng lên đối tượng đó.

Ví dụ như:

- Request tới GET /users có đối tượng tác động là users (tất cả user), và hành động là GET (lấy thông tin)
- Request tới PUT /users/123 có đối tượng là users/123 (user có mã là 123) và hành động là PUT (cập nhật thông tin)

Thường thì theo khuyến nghị người ta sử dụng đúng HTTP method với các hành động CRUD tương ứng:

- Create: dùng POST method
- Read: dùng GET method
- Update: dùng PUT method
- Delete: dùng DELETE method

#### 2.Bắt các request

Spring Boot dùng các annotation sau, đánh dấu lên từng method của controller, để chỉ định rằng khi HTTP method tương ứng gọi tới thì method sẽ được thực thi.

```java
@RestController
public class UserController {
    @GetMapping("/users")
    public ResponseEntity<?> getAllUsers() {}

    @DeleteMapping("/users/{id}")
    public void deleteUser(@PathVariable("id") int id) {}
}
```

Ví dụ trên có 2 method, bắt tương ứng hai request là GET /users và DELETE /users/{id}. Khi có request tương ứng gửi tới, thì hai method trên sẽ thực thi và trả về kết quả cho client.

Các annotation phổ biến như @GetMapping, @PostMapping, @PutMapping,... có dạng là tên HTTP method cộng với từ "mapping". Ngoài ra còn có thể dùng @RequestMapping và chỉ định thuộc tính method như sau.

```java
@RequestMapping(value = "/users", method = RequestMethod.GET)
```

Ngoài ra, @RequestMapping còn có thể dùng bên trên class controller, để chỉ định endpoint gốc cho toàn bộ method bên trong nó. Ví dụ như sau.

**UserController.java**

```java
@RestController
@RequestMapping("/users")
public class UserController {
    // Kết hợp với route gốc ở trên, ta có /users/info
    @GetMapping("/info")
}
```

---

Trong bài sau chúng ta sẽ đi sâu hơn về một số Annotaion trong Spring
