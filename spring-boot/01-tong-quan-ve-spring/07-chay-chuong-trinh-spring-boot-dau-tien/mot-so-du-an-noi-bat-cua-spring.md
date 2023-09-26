---
title: "Chạy chương trình spring đầu tiên"
description: "Chạy chương trình Spring Boot đầu tiên không phải là một công việc phức tạp. Trong bài viết này, chúng ta sẽ hướng dẫn bạn bắt đầu với một ứng dụng Spring Boot đơn giản để tạo một dịch vụ web Hello World"
chapter:
  name: "Tổng quan về Spring"
  slug: "chuong-01-tong-quan-ve-spring"
image: https://kungfutech.edu.vn/thumbnail.png
position: 7
---

Chạy chương trình Spring Boot đầu tiên không phải là một công việc phức tạp. Trong bài viết này, chúng ta sẽ hướng dẫn bạn bắt đầu với một ứng dụng Spring Boot đơn giản để tạo một dịch vụ web "Hello World". Chúng ta sẽ làm theo các bước sau:

## Bước 1: Tạo Dự Án Spring Boot Mới

1. Truy cập trang web [start.spring.io](https://start.spring.io/).

2. Chọn các tùy chọn cho dự án của bạn:

   - Project: Maven hoặc Gradle (chúng tôi sẽ sử dụng Maven trong ví dụ này).
   - Language: Java.
   - Spring Boot: Phiên bản mới nhất (hoặc bạn có thể chọn phiên bản khác nếu cần).
   - Project Metadata: Điền các thông tin như Group, Artifact, và Package theo ý muốn.
     ![Tạo Dự Án Spring Boot Mới](https://github.com/techmely/hoc-lap-trinh/assets/29374426/d804007c-73d3-4577-9593-440f5e820ae5)

3. Bước quan trọng: Trong mục "Dependencies", tìm kiếm và thêm dependency "web" bằng cách gõ "web" vào ô tìm kiếm. Dependency này là cần thiết để tạo dịch vụ web.

4. Sau khi bạn đã thiết lập các tùy chọn, nhấn nút "Generate" để tạo dự án Spring Boot của bạn.

5. Tải xuống tệp zip và giải nén nó vào một thư mục trên máy tính của bạn.

## Bước 2: Viết chương trình spring đầu tiên

1. Mở dự án trong IDE của bạn và tìm tệp `DemoApplication.java` trong thư mục `src/main/java/com/example/demo`.

2. Thay đổi nội dung của tệp `DemoApplication.java` bằng cách thêm phương thức và chú thích như sau:

```java
package com.example.demo;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

@SpringBootApplication
@RestController
public class DemoApplication {
    public static void main(String[] args) {
        SpringApplication.run(DemoApplication.class, args);
    }
    @GetMapping("/hello")
    public String hello(@RequestParam(value = "name", defaultValue = "World") String name) {
        return String.format("Hello %s!", name);
    }
}
```

Mã trên đây đã tạo một dịch vụ web "Hello World" đơn giản trong Spring Boot.

Phương thức `hello()` đã được thêm vào để nhận một tham số String có tên là `name`, sau đó kết hợp tham số này với từ "Hello" trong mã. Điều này có nghĩa là nếu bạn đặt tên của mình là "Amy" trong yêu cầu, phản hồi sẽ là "Hello Amy".

Chú thích `@RestController` cho biết rằng mã này mô tả một điểm cuối (endpoint) có sẵn trên web. `@GetMapping("/hello")` cho biết rằng Spring sẽ sử dụng phương thức `hello()` của chúng tôi để xử lý các yêu cầu được gửi đến địa chỉ `http://localhost:8080/hello`. Cuối cùng, `@RequestParam` nói cho Spring mong đợi một giá trị `name` trong yêu cầu, nhưng nếu không có, nó sẽ sử dụng từ "World" làm giá trị mặc định.

## Bước 3: Thử Nghiệm

1. Hãy xây dựng và chạy chương trình. Mở một dòng lệnh (hoặc terminal) và điều hướng đến thư mục chứa tệp dự án.

2. Bạn có thể xây dựng và chạy ứng dụng bằng cách thực hiện lệnh sau:

   - MacOS/Linux: `./gradlew bootRun`
   - Windows: `.\gradlew.bat bootRun`

3. Bạn sẽ thấy đầu ra tương tự như sau:

::result

Task :bootRun
...
Tomcat started on port(s): 8080 (http) with context path ''
Started DemoApplication in x.xxx seconds (JVM running for x.xxx)
::

![Thử Nghiệm](https://github.com/techmely/hoc-lap-trinh/assets/29374426/a270bd4a-6e47-4b1a-9b69-c533324f3595)

Dòng cuối cùng ở đây cho chúng ta biết rằng Spring đã khởi động. Máy chủ Apache Tomcat được tích hợp trong Spring Boot đang hoạt động và lắng nghe các yêu cầu trên cổng 8080 của localhost.

4. Mở trình duyệt và truy cập vào địa chỉ http://localhost:8080/hello. Bạn sẽ nhận được một phản hồi thân thiện như sau:

::result
Hello World!
::

::alert{type="warning"}
Bài kiểm tra: Nếu bạn thêm `?name=Amy` vào cuối URL, điều gì sẽ xảy ra
::
