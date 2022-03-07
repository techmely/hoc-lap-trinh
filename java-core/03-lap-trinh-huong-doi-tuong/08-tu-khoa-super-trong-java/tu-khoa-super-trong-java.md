---
title: "Từ khóa super trong Java"
description: "Từ khóa super trong java là một biến tham chiếu được sử dụng để tham chiếu trực tiếp đến đối tượng của lớp cha gần nhất."
keywords:
  [
    "câu lệnh super trong java",
    "hàm super trong java",
    "lệnh super trong java",
    "super class trong java",
    "super trong java",
    "super trong java bị lỗi",
    "super trong java eclipse",
    "super trong java example",
    "super trong java fpt",
    "super trong java là gì",
  ]
chapter:
  name: "Lập trình hướng đối tượng"
  slug: "chuong-03-lap-trinh-huong-doi-tuong"
category:
  name: "Java"
  slug: "java"
image: https://user-images.githubusercontent.com/29374426/131205533-8930a7b8-1557-45d9-9d88-7d57b6306f98.png
position: 8
---

Từ khóa **super** trong java là một biến tham chiếu được sử dụng để tham chiếu trực tiếp đến đối tượng của lớp cha gần nhất.

Khi một lớp được kế thừa từ lớp cha trong cả lớp cha và lớp con đều có một phương thức trùng tên nhau, thế thì làm thế nào có thể gọi phương thức trùng tên đó của lớp cha, java cung cấp cho ta từ khoá `super` dùng để chỉ đối tượng của lớp cha.

Bất cứ khi nào bạn tạo ra instance(thể hiển) của lớp con, một instance của lớp cha được tạo ra ngầm định, nghĩa là được tham chiếu bởi biến super.

![image](https://user-images.githubusercontent.com/29374426/131205533-8930a7b8-1557-45d9-9d88-7d57b6306f98.png)

## Super tham chiếu đến biến instance của lớp cha

Từ khóa super được sử dụng để tham chiếu trực tiếp đến biến instance của lớp cha.

<div class="example">Xe đạp thừa kế lớp cha, tốc độ của lớp cha là 50, tốc độ lớp con là 100, nếu không sử dụng super thì khi in tốc độ ra chúng ta sẽ được kết quả là của lớp con</div>

```java
class Xe {
    int speed = 50;
}

public class XeDap extends Xe {
    int speed = 100;

    void display() {
        System.out.println(speed); // speed của lớp con
    }

    public static void main(String args[]) {
        Bike b = new Bike();
        b.display();
    }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>100</code>
  </div>
</div>

<div class="example">Nếu chúng ta sử dụng super thì sẽ in ra được tốc độ của lớp cha</div>

```java
class Xe {
    int speed = 50;
}

public class XeDap extends Xe {
    int speed = 100;

    void display() {
        System.out.println(super.speed); // speed của lớp cha
    }

    public static void main(String args[]) {
        XeDap b = new XeDap();
        b.display();

    }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>50</code>
  </div>
</div>

## Sử dụng super() để gọi contructor của lớp cha

Trong java, `super()` được sử dụng để gọi trực tiếp [constructor](/bai-viet/java/phuong-thuc-khoi-tao) của lớp cha.

```java
class Xe {
    Xe() {
        System.out.println("Xe được tạo");
    }
}

class XeDap extends Xe {
    XeDap() {
        super();// gọi Constructor của lớp cha
        System.out.println("Xe đạp được tạo");
    }

    public static void main(String args[]) {
        XeDap b = new XeDap();
    }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>Xe được tạo</code><br/>
    <code>Xe đạp được tạo</code><br/>
  </div>
</div>

<div class="note">
  super() được tự động thêm vào mỗi Constructor của class bởi trình biên dịch.
</div>

![image](https://user-images.githubusercontent.com/29374426/131205555-ca114d78-97b6-4ee4-8727-55cbbeb233f9.png)

Như chúng ta đã biết [constructor](/bai-viet/java/phuong-thuc-khoi-tao) được tạo ra tự động bởi trình biên dịch nhưng nó cũng thêm `super()` vào câu lệnh đầu tiên. Nếu bạn tạo constructor và bạn không có `this()` hoặc `super()` ở dòng lệnh đầu tiên, trình biên dịch sẽ cung cấp `super()` của Constructor.

_Chú ý:_ ta không thể dùng nhiều từ khoá này để chỉ lớp ông, lớp cụ… chẳng hạn viết như sau là sai: super.super.add(1,4);

```java
class Xe {
    Xe() {
        System.out.println("Xe đã được tạo");
    }
}

public class XeDap extends Xe {
    int speed;

    XeDap(int speed) {
        this.speed = speed;
        System.out.println(speed);
    }

    public static void main(String args[]) {
        XeDap b = new XeDap(10);
    }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>Xe được tạo</code><br/>
    <code>10</code>
  </div>
</div>

## Super được sử dụng để gọi phương thức của lớp cha

Từ khóa `super` cũng có thể được sử dụng để gọi phương thức của lớp cha. Nó nên được sử dụng trong trường hợp lớp chứa các phương thức tương tự như lớp cha như trong ví dụ dưới đây

```java
class Nguoi {
    void xinChao() {
        System.out.println("Xin chao");
    }
}

public class HocSinh extends Nguoi {
    void xinChao() {
        System.out.println("Xin chao Thaycacac");
    }

    void display() {
        message();// gọi phương thức message() của lớp hiện tại
        super.message();// gọi phương thức message() của lớp cha
    }

    public static void main(String args[]) {
        HocSinh hocSinh = new HocSinh();
        hocSinh.display();
    }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>Xin chao Thaycacac</code><br/>
    <code>Xin chao</code>
  </div>
</div>
