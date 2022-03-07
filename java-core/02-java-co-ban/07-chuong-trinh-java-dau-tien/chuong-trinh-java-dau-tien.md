---
title: "Chương trình Java đầu tiên"
description: "Trong bài học này chúng ta sẽ viết một chương trình in ra màn hình dòng chữ Hello World - bài học nhập môn của hầu hết các ngôn ngữ lập trình trong ngôn ngữ Java."
keywords:
  [
    "chương trình java đầu tiên",
    "chương trình java đầu tiên fpt",
    "chương trình java đầu tiên java",
    "chương trình java đầu tiên là gì",
    "chương trình java đầu tiên như thế nào",
    "ứng dụng đầu tiên java fpt",
    "ứng dụng đầu tiên java gì",
    "ứng dụng đầu tiên java học",
  ]
author:
  fullname: Techmely Team
  username: Techmely Team
  avatar: "/configs/author/logo.jpg"
chapter:
  name: "Nhập môn Java"
  slug: "chuong-02-nhap-mon-java"
category:
  logo: "/language/java.png"
  name: "Java"
  slug: "java"
  description: "Học Java từ cơ bản đến thông thạo cho mọi đối tượng"
image: https://user-images.githubusercontent.com/29374426/128105937-9674217e-0299-420e-8d65-6546375985eb.png
position: 7
---

Trong bài học này chúng ta sẽ viết một chương trình in ra màn hình dòng chữ **Hello World** - bài học nhập môn của hầu hết các ngôn ngữ lập trình trong ngôn ngữ Java.

![chuong-trinh-java-dau-tien](https://user-images.githubusercontent.com/29374426/128105937-9674217e-0299-420e-8d65-6546375985eb.png)

## Chương trình Java đầu tiên

```java
public class Main {
  public static void main(String[] args) {
    System.out.println("Hello world");
  }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>Hello world</code>
    </div>
</div>

Ví dụ huyền thoại mỗi khi chúng ta học một ngôn ngữ mới đây. Trong một ứng dụng Java thì hàm `main` sẽ luôn chạy đầu tiên. Chúng ta có các `keyword` chúng ta sẽ phân tích kỹ hơn nhé

- `public`: định nghĩa rằng method được phép truy cập ở bất cứ nơi nào.
- `static`: cho phép gọi method main mà không cần phải khởi tạo đối tượng main.
- `void`: hàm không có giá trị trả về
- `main`: tên method
- `(String[] args)`: Các đối số khi dùng lệnh cmd.
