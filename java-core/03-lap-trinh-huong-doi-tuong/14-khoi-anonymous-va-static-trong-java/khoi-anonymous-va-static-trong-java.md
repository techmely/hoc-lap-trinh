---
title: "Khối Anonymous và Static trong Java"
description: "Trong java ta có thể đặt một khối lệnh không thuộc một phương thức nào, nghĩa là khối này không thuộc bất cứ phương thức nào kể cả hàm tạo, khi đó khối lệnh này được gọi là khối vô danh"
keywords:
  [
    "khối anonymous java class",
    "khối anonymous java cơ bản",
    "khối anonymous java fpt",
    "khối anonymous và static trong java code",
    "khối static java block",
    "khối static java class",
    "khối static java cơ bản",
    "khối static java fpt",
    "khối static java gì",
  ]
chapter:
  name: "Lập trình hướng đối tượng"
  slug: "chuong-03-lap-trinh-huong-doi-tuong"
category:
  name: "Java"
  slug: "java"
image: https://user-images.githubusercontent.com/29374426/131244991-bd72ce64-f07c-465c-9a2b-677bcc58ba01.png
position: 14
---

## Khối vô danh (anonymous) trong Java

Trong java ta có thể đặt một khối lệnh không thuộc một phương thức nào, nghĩa là khối này không thuộc bất cứ phương thức nào kể cả hàm tạo, khi đó khối lệnh này được gọi là khối vô danh, khối vô danh này được java gọi thực thi khi một đối tượng được tạo ra, các khối vô danh được gọi trước cả hàm tạo.

Thông thường ta hay sử dụng khối vô danh để khởi đầu các thuộc tính của lớp hoặc được sử dụng để khởi tạo cho các thộc tính của một lớp vô danh (vì lớp vô danh không có tên do vậy ta không thể viết hàm tạo cho lớp này, trong trường hợp này khối vô danh là giải pháp duy nhất).

![image](https://user-images.githubusercontent.com/29374426/131244991-bd72ce64-f07c-465c-9a2b-677bcc58ba01.png)

<div class="example">
  Ở ví dụ này ta có 3 khối vô danh, khi chạy java cho thực thi các khối vô danh này theo thứ tự từ trên xuống dưới
</div>

```java
public class Student {
  // hàm constructor
  public Student (){
    System.out.println ( "Đây là hàm tạo" );
  }

  // bắt đầu khối vô danh
  {
    System.out.println ( "Khối vô danh thứ 1 ");
  }// kết thúc khối vô danh

  //bắt đầu khối vô danh
  {
    System.out.println ( "Khối vô danh thứ 2");
  }//kết thúc khối vô danh

  // bắt đầu khối vô danh
  {
    System.out.println ( "Khối vô danh thứ 3");
  }//kết thúc khối vô danh

  public static void main ( String[] args ) {
    Student dt1 = new Student ();
    Student dt2 = new Student ();
  }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>Khối vô danh thứ 1 </code> <br/>
    <code>Khối vô danh thứ 2</code> <br/>
    <code>Khối vô danh thứ 3</code> <br/>
    <code>Đây là hàm tạo</code> <br/>
    <code>Khối vô danh thứ 1 </code> <br/>
    <code>Khối vô danh thứ 2</code> <br/>
    <code>Khối vô danh thứ 3</code> <br/>
    <code>Đây là hàm tạo</code>
  </div>
</div>

## Khối tĩnh (static) trong Java

Khối tĩnh (static) là một khối lệnh bên ngoài tất cả các phương thức, kể cả hàm tạo, trước khối lệnh này ta đặt từ khoá `static`, từ khoá này báo cho java biết đây là khối khởi đầu tĩnh, khối này chỉ được gọi 1 lần khi đối tượng đầu tiên của lớp này được tạo ra, khối khởi đầu tĩnh này cũng được java gọi tự động trước bất cứ hàm tạo nào, thông thường ta sử dụng khối khởi đầu tĩnh để khởi đầu các thuộc tính `static`

<div class="example">
  Sau đây là một ví dụ có 1 khối khởi đầu tĩnh và một khối vô danh, để bạn thấy được sự khác nhau giữa khối khởi đầu tĩnh và khối vô danh
</div>

```java
public class Student {
  // hàm constructor
  public Student (){
    System.out.println ( "Đây là hàm tạo" );
  }

  // bắt đầu khối vô danh
  {
    System.out.println ( "Khối vô danh thứ 1 ");
  }// kết thúc khối vô danh

  //bắt đầu khối vô danh
  {
    System.out.println ( "Khối vô danh thứ 2");
  }//kết thúc khối vô danh

  // bắt đầu khối vô danh
  {
    System.out.println ( "Khối vô danh thứ 3");
  }//kết thúc khối vô danh

  static { // đây là khối static
    System.out.println ("Đây là khối static");
    System.out.println("Khối này chỉ được gọi 1 lần khi thể hiện đầu tiên của lớp được tạo ra");
  }

  public static void main ( String[] args ) {
    Student dt1 = new Student ();
    Student dt2 = new Student ();
  }
}

```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>Đây là khối static</code><br/>
    <code>Khối này chỉ được gọi 1 lần khi thể hiện đầu tiên của lớp được tạo ra</code><br/>
    <code>Khối vô danh thứ 1 </code><br/>
    <code>Khối vô danh thứ 2</code><br/>
    <code>Khối vô danh thứ 3</code><br/>
    <code>Đây là hàm tạo</code><br/>
    <code>Khối vô danh thứ 1 </code><br/>
    <code>Khối vô danh thứ 2</code><br/>
    <code>Khối vô danh thứ 3</code><br/>
    <code>Đây là hàm tạo</code>
  </div>
</div>

Nhìn vào kết quả ra ta thấy khối khởi đầu tĩnh chỉ được java gọi thực hiện 1 lần khi đối tượng đầu tiên của lớp này được tạo, còn khối vô danh được gọi mỗi khi một đối tượng mới được tạo ra
