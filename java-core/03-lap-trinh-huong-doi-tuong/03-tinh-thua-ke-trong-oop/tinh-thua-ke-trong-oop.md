---
title: "Tính thừa kế trong OOP"
description: "Tính kế thừa trong lập trình hướng đối tượng cho phép xây dựng một lớp mới dựa trên các định nghĩa của lớp đã có"
keywords:
  [
    "class trong lập trình hướng đối tượng",
    "thừa kế java",
    "thừa kế trong java",
    "tính kế thừa java",
    "tính kế thừa trong lập trình hướng đối tượng",
    "tính kế thừa trong oop",
    "tính kế thừa và đa hình trong java",
    "tính thừa kế trong java",
    "tính thừa kế trong oop java",
    "tính thừa kế trong oop java là gì",
    "lập trình hướng đối tượng",
    "tính chất lập trình hướng đối tượng",
  ]
chapter:
  name: "Lập trình hướng đối tượng"
  slug: "chuong-03-lap-trinh-huong-doi-tuong"
category:
  logo: "/language/java.png"
  name: "Java"
  slug: "java"
  description: "Học Java từ cơ bản đến thông thạo cho mọi đối tượng"
image: https://user-images.githubusercontent.com/29374426/131276922-2608f214-0690-4eb4-96e3-b7384d4b2df3.png
position: 3
---

Ý tưởng nảy sinh của Tính kế thừa chính là những mối quan hệ trong đời sống. Chẳng hạn như "MayAsus" và "MayAcer" hay "MayLenovo" đều là hai lớp con thuộc lớp cha là "MayViTinh". Do đó, cả hai lớp con này đều thừa hưởng được những đặc điểm của lớp cha.

Ví dụ trong lập trình nó được thể hiện thông qua việc ta có các lớp `mayAsus`, `mayAcer`, `mayLenovo` đều có các thuộc tính (attribute): `chieudai`, `chieurong` và phương thức (method): `upRam()`. Khi đó, nếu chúng ta tạo các lớp này thì chúng ta phải viết trong mỗi lớp đều có 3 phương thức trên. Hơn thế nữa, nếu bạn muốn sửa lại code trong một phương thức nào đó thì bạn phải sửa chúng cả ở 3 lớp sẽ rất tốn thời gian, và có thể dễ sai sót. Vì thế tính kế thừa sẽ được sử dụng trong trường hợp này để giải quyết vấn đề trên.

## Tính kế thừa (Inheritance)

**Tính kế thừa** cho phép xây dựng một lớp mới dựa trên các định nghĩa của lớp đã có. Có nghĩa là lớp cha có thể chia sẽ dữ liệu và phương thức cho các lớp con. Các lớp con khỏi phải định nghĩa lại, ngoài ra có thể mở rộng các thành phần kế thừa và bổ sung thêm các thành phần mới. Tái sử dụng mã nguồn 1 cách tối ưu, tận dụng được mã nguồn.

![image](https://user-images.githubusercontent.com/29374426/131276922-2608f214-0690-4eb4-96e3-b7384d4b2df3.png)

Hình ảnh trên cho thấy khi áp dụng **tính kế thừa**, ta chỉ cần viết một lần các phương thức kia trong lớp cha và cho các lớp con kế thừa lại. Điều này sẽ tránh việc sai sót khi sửa và tăng khả năng sử dụng lại. Ví dụ, nếu bạn muốn thêm một lớp `MayMac` , bạn chỉ cần khai báo nó kế thừa từ Class Mayvitinh là cũng có thể dùng được các thuộc tính và phương thức trên rồi.

## Ví dụ tính kế thừa trong Java

<div class="example">ví dụ dưới dây lớp A thừa kế lớp B và ở lớp con không gọi hàm tạo của lớp cha nhưng nó vẫn được chạy</div>

```java
class B {
  public B () {
    System.out.println ( "Hàm khởi tạo lớp cha" );
  }
}


public class A extends B {
  public A () { // không gọi hàm tạo của lớp cha tường minh
    System.out.println ( "Hàm khởi tạo lớp con" );
  }


  public static void main ( String arg[] ) {
    A thu = new A ();
  }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả sẽ hiển thị thông báo lỗi</span>
  </div>
  <div class="window-body">
    <code>Hàm khởi tạo lớp cha</code><br/>
    <code>Hàm khởi tạo lớp con</code><br/>
  </div>
</div>

<div class="example">Đây là cách gọi tường minh</div>

```java
class B {
  public B () {
    System.out.println ( "Hàm khởi tạo lớp cha" );
  }
}


public class A extends B {
  public A () {
    super(); // gọi tạo của lớp cha một cách tường minh
    System.out.println ( "Hàm khởi tạo lớp con" );
  }


  public static void main ( String arg[] ) {
    A thu = new A ();
  }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>Hàm khởi tạo lớp cha</code><br/>
    <code>Hàm khởi tạo lớp con</code><br/>
  </div>
</div>

<div class="example">Một ví dụ khác</div>

```java
class B {
  public B () {
    System.out.println ( "Hàm khởi tạo lớp cha" );
  }

  public B ( int i ) {
    System.out.println ( "Hàm khởi tạo lớp cha" );
  }
}


public class A extends B {
  public A () {
    super();
    super(10);// không thể gọi nhiều hơn 1 hàm tạo của lớp cơ sở
    System.out.println ( "Hàm khởi tạo lớp con" );
  }


  public static void main ( String arg[] ) {
    A thu = new A ();
  }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>Hàm khởi tạo lớp cha</code><br/>
    <code>Hàm khởi tạo lớp con</code><br/>
    <code>Hàm khởi tạo lớp con</code>
  </div>
</div>
