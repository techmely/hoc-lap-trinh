---
title: "Package trong Java"
description: "Package (gói) trong java là một nhóm các class, interface và các package khác. Trong java chúng ta sử dụng package để tổ chức cấu trúc dự án hợp lý"
keywords:
  [
    "class package trong java",
    "cách import package trong java",
    "cách tạo package trong java",
    "cách tổ chức package trong java",
    "cách đặt tên package trong java",
    "huong dan tao package trong java",
    "import package trong java",
    "khi nào dùng package trong java",
    "lenh package trong java",
    "làm việc với package trong java",
    "lấy dữ liệu từ package trong java",
    "lớp package trong java",
    "package trong java",
    "package trong java example",
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
image: https://user-images.githubusercontent.com/29374426/127757327-7ca27569-a1d9-4345-a313-3785ef68174c.png
position: 6
---

Package (gói) trong java là một nhóm các `class`, `interface` và các `package` khác. Trong java chúng ta sử dụng `package` để tổ chức cấu trúc dự án hợp lý. Đừng lo lắng nếu bạn chưa biết về class, hay interface vì chúng ta sẽ tìm hiểu chúng sau.

Java có 2 loại package chính:

- Các package tích hợp sẵn
- Các package do chúng ta tự định nghĩa.

Các package tích hợp được java xây dựng sẵn dựa trên các nhu cầu thường xuyên của các lập trình viên.

<div class="example"></div>

```java
import java.util.Scanner;
```

Trong đó:

- **import** là từ khóa dùng để khai báo chúng ta sẽ sử dụng gói
- **java**: là gói cha
- **util** : là gói con của gói java
- **Scanner**: là một class chứa trong gói util.

Sử dụng package trong java cho chúng ta rất nhiều lợi ích, có thể kể đến như: (Nếu bạn chưa từng học java thì hãy bỏ qua phần dưới và đọc phần tiếp theo)

## Tái sử dụng

Trong một dự án, sẽ có lúc một logic được sử dụng ở nhiều nơi, nếu mỗi chỗ như vậy bạn đều code lại logic thì việc bị lặp code sẽ ngày càng nhiều Đến khi logic đó thay đổi thì chúng ta lại phải lục lọi tất cả mọi nơi sử dụng logic đó mà sửa lại. Điều này vừa gây rủi ro và vừa khổ cực. VÌ thế, trường hợp này chúng ta nên tạo ra package chứa class implement logic đó và `import` vào những nơi cùng sử dụng. Đến lúc sửa chúng ta chỉ cần tìm đến `package` chứa class `implement` nó và sửa lại thôi.

## Cấu trúc tốt

Trong một dự án lớn, nó có thể chứa đến hàm trăm, hàng ngàn class, interface để thực thi các nhóm chức năng khác nhau. Sử dụng package để phân tầng theo nhóm chức năng và chứa các class liên quan giúp chúng ta quản lý code hiệu quả. Tên package phải nói lên được ý nghĩa của package đó.

## Xung đột tên

Đôi lúc chúng ta đặt tên của 2 hoặc nhiều class cùng tên. Dùng package chúng ta có thể tránh được xung đột bằng cách chỉ định đúng đường dẫn từ package cha đến các class cùng tên

![package-trong-java](https://user-images.githubusercontent.com/29374426/127757327-7ca27569-a1d9-4345-a313-3785ef68174c.png)

Ở ví dụ trên chúng ta có package **com** là package lớn nhất, theo sau đó là **company**. Mình đặt 2 class đều có tên `Example` trong package company nhưng được báo lỗi là không thể có 2 class cùng tên trong company. Để giải quyết vấn đề này, mình đã tạo ra 2 package package1 và package2 để chứa 2 class Example của mình.

<div class="example"></div>

```java
// File Example.java trong package1
package com.company.package1;
public class Example {
  public void display() {
    System.out.println("ví dụ trong package 1");
  }
}
```

```java
// File Example.java trong package2
package com.company.package2;
public class Example {
  public void display() {
    System.out.println("ví dụ trong package 2");
  }
}
```

```java
// File Main.java
package com.company;
public class Main {
  public static void main(String[] args) {
    com.company.package1.Example example1 = new com.company.package1.Example();
    example1.display();
    com.company.package2.Example example2 = new com.company.package2.Example();
    example2.display();
  }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>ví dụ trong package 1</code><br/>
    <code>ví dụ trong package 2</code>
  </div>
</div>

## Sub package

Trong một package có thể chứa các package khác, các package này được gọi là sub package.

<div class="example">chúng ta có TopPackage chứa SubPackage, và class Example thuộc về SubPackage.</div>

```java
// File Example.java
package TopPackage.SubPackage;
public class Example {
  public void demo() {
    System.out.println("Sub package");
  }
}
```

## Import package với ký tự (\*)

Giả sử có 2 class **Example1**, **Example2** chứa trong package **thaycacac**. Chúng ta muốn sử dụng cả **Example1** và **Example2**.

**_Cách 1_**: import từng class vào

<div class="example"></div>

```java
import thaycacac.Example1;
import thaycacac.Example2;
public class Main {
  public static void main(String[] args) {
    Example1 example1 = new Example1();
    Example2 example2 = new Example2();
    example1.demo();
    example2.demo();
  }
}
```

**_Cách 1_**: Thay vì import từng class như vậy sẽ khiến code trở nên dài dòng, chúng ta sẽ sử dụng \_ với hàm ý `import` tất cả các `class`, `interface` etc chứa trong **thaycacac**

<div class="example"></div>

```java
// File Example1.java
package thaycacac;
public class Example1 {
    public void demo() {
        System.out.println("ví dụ 1");
    }
}
// File Example2.java
package thaycacac;
public class Example2 {
    public void demo() {
        System.out.println("ví dụ 2");
    }
}
// File Main.java
import thaycacac.*;
public class Main {
  public static void main(String[] args) {
    Example1 example1 = new Example1();
    Example2 example2 = new Example2();
    example1.demo();
    example2.demo();
  }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>ví dụ 1</code><br/>
    <code>ví dụ 2</code>
  </div>
</div>
