---
title: "Cấu trúc switch case trong Java"
description: "Trong bài viết này mình sẽ chia sẻ cho bạn một cấu trúc lệnh rẽ nhánh cơ bản và hay sử dụng đó là cấu trúc switch case trong Java."
keywords:
  [
    "cách dùng switch case",
    "cách dùng switch case trong java",
    "cách sử dụng switch case trong java",
    "câu lệnh switch case trong java",
    "cấu trúc switch case trong java",
    "hàm switch case trong java",
    "lệnh switch case trong java",
    "switch case trong java",
    "switch case trong java bị lỗi",
    "switch case trong java example",
    "switch case trong java fpt",
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
image: https://user-images.githubusercontent.com/29374426/125040317-b383c780-e0c1-11eb-8dbc-98bfa0af2509.png
position: 18
---

Đối với trường hợp có nhiều câu điều điện cần kiểm tra ví dụ như: **"Hôm nay trời nắng thì ... trời mưa thì... trời râm thì... trời quang thì..."** thì Java cũng cung cấp cho ta một cú pháp khác để tránh phải viết nhiều lần if, đó chính là switch-case

## Dạng khuyết

**Cú pháp**

```java
switch(biến) {
  case giá trị 1:
    câu lệnh 1;
    câu lệnh 2;
    ...
    break;
  case giá trị 2:
    câu lệnh 1;
    câu lệnh 2;
    ...
    break;
  ...
  case giá trị n:
    câu lệnh 1;
    câu lệnh 2;
    ...
    break;
}
```

Sau đây là sơ đồ khối mô tả sự hoạt động của cấu trúc rẽ nhánh switch dạng thiếu

![cau-truc-switch-case-trong-java](https://user-images.githubusercontent.com/29374426/125040317-b383c780-e0c1-11eb-8dbc-98bfa0af2509.png)

Switch sẽ kiểm tra giá trị của **biến** (nằm trong ngoặc đơn sau switch kia), và so sánh biến với từng giá trị khác nhau, lần lượt từ trên xuống dưới, mỗi giá trị cần so sánh gọi là một case. Ở đoạn code trên, các giá trị để so sánh với **biến** là **giá trị 1**, **giá trị 2**. Khi một trường hợp đúng (`true`), khối lệnh ở trong `case` đó sẽ được thực thi. Câu lệnh `break` để thoát ra khỏi cấu trúc switch bạn có thể xem thêm ở bài [từ khóa break và continue](/bai-viet//bai-viet/java/tu-khoa-break-va-continue).

<div class="example"></div>

```java
public class Thaycacac {
  public static void main(String[] args) {
    int number = 2;
    switch (number) {
      case 1:
        System.out.println("Đây là số 1");
        break;
      case 2:
        System.out.println("Đây là số 2");
        break;
      case 3:
        System.out.println("Đây là số 3");
        break;
      case 4:
        System.out.println("Đây là số 4");
        break;
      case 5:
        System.out.println("Đây là số 5");
        break;
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
    <code>Đây là số 2</code>
    </div>
</div>

## Dạng đủ

**Cú pháp**

```java
switch(biểu thức) {
  case giá trị 1:
    câu lệnh 1;
    câu lệnh 2;
    ...
    break;
  case giá trị 2:
    câu lệnh 1;
    câu lệnh 2;
    ...
    break;
  ...
  case giá trị n:
    câu lệnh 1;
    câu lệnh 2;
    ...
    break;
  default:
    câu lệnh 1;
    câu lệnh 2;
    ...
}
```

Sau đây là sơ đồ khối mô tả sự hoạt động của cấu trúc switch dạng đủ

![cau-truc-switch-case-trong-java](https://user-images.githubusercontent.com/29374426/125040355-bf6f8980-e0c1-11eb-9bfa-391815ff5c3c.png)

Nếu tất cả các trường hợp đều sai (tức là các giá trị ở `case` không bằng với **biến**), thì khối lệnh ở trong `default` sẽ được thực thi.

<div class="example"></div>

```java
public class Thaycacac {
  public static void main(String[] args) {
    int number = 2;
    switch (number) {
    case 1:
      System.out.println("Đây là số 1");
    case 2:
      System.out.println("Đây là số 2");
    case 3:
      System.out.println("Đây là số 3");
    case 4:
      System.out.println("Đây là số 4");
    case 5:
      System.out.println("Đây là số 5");
    default:
      System.out.println("Chạy vào khối default");
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
    <code>Đây là số 2</code><br/>
    <code>Đây là số 3</code><br/>
    <code>Đây là số 4</code><br/>
    <code>Đây là số 5</code><br/>
    <code>Chạy vào khối default</code><br/>
  </div>
</div>

<div class="note">
  <ul>
    <li> <b>Biến</b> phải là một biểu thức có kiểu char, byte, short, int nhưng không thể là kiểu long, nếu <b>Biến</b> có kiểu khác với các kiểu liệt kê ở trên thì java sẽ đưa ra một thông báo lỗi.</li>
    <li>Nếu case không có break thì nó sẽ thực hiện đến hết, khi không còn khối nào thì thôi.</li>
  </ul>
</div>
