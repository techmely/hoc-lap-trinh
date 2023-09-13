---
title: "Chương trình Java đầu tiên"
description: "Trong bài học này chúng ta sẽ viết một chương trình in ra màn hình dòng chữ Hello World - bài học nhập môn của hầu hết các ngôn ngữ lập trình trong ngôn ngữ Java."
chapter:
  name: "Nhập môn Java"
  slug: "chuong-02-nhap-mon-java"
category:
  name: "Java"
  slug: "java"
image: https://user-images.githubusercontent.com/29374426/128105937-9674217e-0299-420e-8d65-6546375985eb.png
position: 7
---

Trong bài học này, chúng ta sẽ viết một chương trình Java đơn giản để in ra màn hình dòng chữ **Hello World**. Đây là bước đầu tiên và là bài học nhập môn trong hầu hết các khóa học lập trình sử dụng ngôn ngữ Java.

![Chương trình Java đầu tiên](https://user-images.githubusercontent.com/29374426/128105937-9674217e-0299-420e-8d65-6546375985eb.png)

## Chương trình Java đầu tiên

```java
public class Main {
  public static void main(String[] args) {
    System.out.println("Hello world");
  }
}
```

### Giải thích mã nguồn

Trước khi bạn bắt đầu viết chương trình, hãy tìm hiểu một chút về các thành phần trong mã nguồn trên:

- `public class Main`: Đây là khai báo một lớp (class) có tên là "Main". Trong Java, một chương trình thường bắt đầu từ một lớp chứa phương thức main.

- `public static void main(String[] args)`: Đây là phần quan trọng nhất của chương trình. Đây là phương thức (method) chính của chương trình, có tên là "main". Phương thức này là điểm bắt đầu khi chương trình được thực thi. Hãy xem xét một số điểm quan trọng:

  - `public`: Đây là từ khoá quy định rằng phương thức main có quyền truy cập từ bất kỳ đâu trong chương trình.

  - `static`: Từ khoá "static" cho biết rằng bạn có thể gọi phương thức main mà không cần tạo một đối tượng của lớp "Main". Điều này cho phép chương trình được chạy mà không cần khởi tạo đối tượng.

  - `void`: Đây là kiểu dữ liệu trả về của phương thức main. Trong trường hợp này, phương thức không trả về giá trị nào (nó chỉ in dòng chữ "Hello world" ra màn hình).

  - `main`: Đây là tên của phương thức chính.

  - `(String[] args)`: Đây là tham số mà phương thức main có thể nhận vào. Trong trường hợp này, chúng ta nhận một mảng các chuỗi (strings) có tên là "args", nhưng chúng ta chưa sử dụng nó trong ví dụ này.

### Kết quả

Khi chúng ta chạy chương trình trên, kết quả sẽ là:

::result

Hello world

::

Đây là thông điệp "Hello world" được in ra màn hình, và nó thể hiện sự thành công của chương trình đầu tiên của bạn trong Java - một bước quan trọng trên hành trình học lập trình. Chúc mừng bạn đã hoàn thành bài học này!
