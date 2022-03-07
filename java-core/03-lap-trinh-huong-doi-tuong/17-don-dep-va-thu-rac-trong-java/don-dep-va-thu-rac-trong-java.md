---
title: "Dọn dẹp và thu rác trong Java"
description: "Bài này chúng ta sẽ tìm hiểu về dọn dẹp, kết thúc và thu rác, tự học lập trình java, chia sẻ kiến thức về java"
keywords:
  [
    "bước đầu học lập trình java",
    "các bước học lập trình java",
    "cách học lập trình java hiệu quả",
    "có nên học lập trình java",
    "công cụ học lập trình java",
    "dọn dẹp trong java fpt",
    "dọn dẹp và thu rác trong java cơ bản",
    "dọn dẹp và thu rác trong java dùng để làm gì",
    "thu rác trong java bị lỗi",
    "thu rác trong java code",
    "thu rác trong java fpt",
  ]
chapter:
  name: "Lập trình hướng đối tượng"
  slug: "chuong-03-lap-trinh-huong-doi-tuong"
category:
  name: "Java"
  slug: "java"
image: https://user-images.githubusercontent.com/29374426/131286911-92c85605-6bb1-4e91-81be-735a89f56188.png
position: 17
---

Khi bạn khởi tạo một object với từ khoá new một object mới được tạo ra và lưu vào heap và nó trả về một reference. Hay nói cách khác reference là một địa chỉ của object được lưu trong heap và đương nhiên chúng ta sẽ cần một trình dọn dẹp và thu rác để giải phóng vùng nhớ này khi không còn dùng đến nữa

![image](https://user-images.githubusercontent.com/29374426/131286911-92c85605-6bb1-4e91-81be-735a89f56188.png)

## Reference là gì?

Khi bạn khởi tạo một object với từ khoá new một object mới được tạo ra và lưu vào heap và nó trả về một reference. Hay nói cách khác reference là một địa chỉ của object được lưu trong heap.

```java
Student student = new Student();
```

Như đoạn code trên, trình biên dịch sẽ khởi tạo một đối tượng là student và lưu chúng vào heap, sau đó trả về một `reference` của nó cho biến student nắm giữ.

Các object được lưu trữ trong heap không thể tự giải phóng mà phải nhờ vào trình thu gom rác của java. Các object được dọn dẹp phải thoả điều kiện rằng không có một reference nào đến nó.

## Dọn dẹp và thu rác trong Java

Trong java không có kiểu dữ liệu con trỏ như trong C, người lập trình không cần phải quá bận tâm về việc cấp phát và giải phóng vùng nhớ, sẽ có một trình dọn dẹp hệ thống đảm trách việc này. Trình dọn dẹp hệ thống sẽ dọn dẹp vùng nhớ cấp phát cho các đối tượng trước khi hủy một đối tượng.

- Phương thức `finalize()` là một phương thức đặc biệt được cài đặt sẵn cho các lớp. Trình dọn dẹp hệ thống sẽ gọi phương thức này trước khi hủy một đối tượng. Vì vậy việc cài đặt một số thao tác giải phóng, dọn dẹp vùng nhớ đã cấp phát cho các đối tượng dữ liệu trong phương thức finalize() sẽ giúp cho người lập trình chủ động kiểm soát tốt quá trình hủy đối tượng thay vị giao cho trình dọn dẹp hệ thống tự động. Đồng thời việc cài đặt trong phương thức finalize() sẽ giúp cho bộ nhớ được giải phóng tốt hơn, góp phần cải tiến tốc độ chương trình.
- Phương thức `System.gc()`: gọi trình thu gom rác để nó tiến hành giải phóng các object không còn được sử dụng.

<div class="example"></div>

```java
class Thaycacac {
    String fullname;
    public Test(String fullname) {
        this.fullname = fullname;
    }
    static void show() {
        new Test("show...");
        display();
    }
    static void display() {
        new Test("display...");
    }

    public static void main(String args[]) {
        show();
        System.gc();
    }

    @Override
    protected void finalize() throws Throwable {
        System.out.println(this.fullname + " successfully garbage collected");
    }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>display... successfully garbage collected</code><br/>
    <code>show... successfully garbage collected</code>
  </div>
</div>
