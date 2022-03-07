---
title: "Constructor trong Java"
description: "constructor trong java là một phương thức của lớp nhưng khá đặc biệt và thường được sử dụng để khởi tạo các đối tượng"
keywords:
  [
    "class constructor trong java",
    "constructor function trong javascript",
    "constructor method trong java",
    "constructor trong java",
    "constructor trong java fpt",
    "constructor trong java là gì",
    "constructor trong java online",
    "constructor trong java pdf",
    "khối khởi tạo trong java cơ bản",
    "khối khởi tạo trong java fpt",
  ]
chapter:
  name: "Lập trình hướng đối tượng"
  slug: "chuong-03-lap-trinh-huong-doi-tuong"
category:
  name: "Java"
  slug: "java"
image: https://user-images.githubusercontent.com/29374426/131241303-40011fad-8ec9-408e-9590-ddafd7c43734.png
position: 13
---

Phương thức tạo dựng (constructor) trong java là một phương thức của lớp (nhưng khá đặc biệt) thường được sử dụng để khởi tạo các đối tượng. Thông thường người ta thường sử dụng hàm tạo để khởi gán giá trị cho các thuộc tính của đối tượng và có thể thực hiện một số công việc cần thiết khác nhằm chuẩn bị cho đối tượng mới.

![image](https://user-images.githubusercontent.com/29374426/131241303-40011fad-8ec9-408e-9590-ddafd7c43734.png)

## Đặc điểm của constructor

- Hàm tạo có tên trùng với tên của lớp
- Hàm tạo không bao giờ trả về kết quả
- Nó được java gọi tự động khi một đối tượng của lớp được tạo ra
- Hàm tạo có thể có đối số như các phương thức thông thường khác
- Trong một lớp có thể có nhiều hàm tạo

**Có 2 kiểu của constructor**

- Constructor mặc định (không có tham số truyền vào)
- Constructor tham số

![image](https://user-images.githubusercontent.com/29374426/131241310-2a6f2b11-33e8-4898-8639-6066f3b3c7fa.png)

## Constructor mặc định trong java

Khi xây dựng một lớp mà không xây dựng hàm tạo thế thì java sẽ cung cấp cho ta một hàm tạo không đối mặc định, hàm tạo này thực chất không làm gì cả, nếu trong lớp đã có ít nhất một hàm tạo thì hàm tạo mặc định sẽ không được tạo ra, khi ta tạo ra một đối tượng thì sẽ có một hàm tạo nào đó được gọi, nếu trình biên dịch không tìm thấy hàm tạo tương ứng nó sẽ thông báo lỗi, điều này thường xẩy ra khi chúng ta không xây dựng hàm tạo không đối nhưng khi tạo dựng đối tượng ta lại không truyền vào tham số, như được chỉ ra trong ví dụ sau:

<div class="example"></div>

```java
class Student {

    Student() { // Đây là constructor mặc định
        System.out.println("Đang tạo student");
    }
}

public class SimpleConstructor {

    public static void main(String[] args) {
        for (int i = 0; i < 10; i++) {
            new Student(); // gọi constructor
        }
    }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>Đang tạo student</code><br/>
  <code>Đang tạo student</code><br/>
  <code>Đang tạo student</code><br/>
  <code>Đang tạo student</code><br/>
  <code>Đang tạo student</code><br/>
  <code>Đang tạo student</code><br/>
  <code>Đang tạo student</code><br/>
  <code>Đang tạo student</code><br/>
  <code>Đang tạo student</code><br/>
  <code>Đang tạo student</code>
  </div>
</div>

<div class="note">
  Nếu không có constructor trong một lớp, trình biên dịch sẽ tự động tạo một constructor mặc định trong lớp đó.
</div>

## Constructor có tham số trong java

Một constructor có tham số truyền vào được gọi là constructor tham số. Constructor tham số được sử dụng để cung cấp các giá trị khác nhau cho các đối tượng khác nhau.

<div class="example"></div>

```java
public class Student {

    int id;
    String name;

    Student(int i, String n) {
        id = i;
        name = n;
    }

    void display() {
        System.out.println(id + " " + name);
    }

    public static void main(String args[]) {
        Student s1 = new Student(1, "Thaycacac");
        Student s2 = new Student(2, "HoaPN");
        s1.display();
        s2.display();
    }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>1 Thaycacac</code><br/>
    <code>2 HoaPN</code>
  </div>
</div>

## Constructor Overloading trong java

Constructor Overloading là một kỹ thuật trong Java. Bạn có thể tạo nhiều constructor trong cùng một lớp với danh sách tham số truyền vào khác nhau. Trình biên dịch phân biệt các constructor này thông qua số lượng và kiểu dữ liệu của các tham số truyền vào.

<div class="example"></div>

```java
class Student {
 int id;
 String name;
 int age;

 Student(int i, String n) {
  id = i;
  name = n;
 }

 Student(int i, String n, int a) {
  id = i;
  name = n;
  age = a;
 }

 void display() {
  System.out.println(id + " " + name + " " + age);
 }

 public static void main(String args[]) {
  Student s1 = new Student(1, "Thaycacac");
  Student s2 = new Student(2, "HoaPN", 25);
  s1.display();
  s2.display();
 }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>1 Thaycacac 0</code><br/>
    <code>2 HoaPN 25</code>
  </div>
</div>

## Sự khác nhau giữa constructor và phương thức trong java

| Constructor | Phương thức |
| --- | --- |
| Constructor được sử dụng để khởi tạo trạng thái của một đối tượng. | Phương thức được sử dụng để thể hiện hành động của một đối tượng. |
| Constructor không có kiểu trả về. | Phương thức có kiểu trả về. |
| Constructor được gọi ngầm. | Phương thức được gọi tường minh. |
| Trình biên dịch Java tạo ra constructor mặc định nếu bạn không có constructor nào. | Phương thức không được tạo ra bởi trình biên dịch Java. |
| Tên của constructor phải giống tên lớp. | Tên phương thức có thể giống hoặc khác tên lớp. |
