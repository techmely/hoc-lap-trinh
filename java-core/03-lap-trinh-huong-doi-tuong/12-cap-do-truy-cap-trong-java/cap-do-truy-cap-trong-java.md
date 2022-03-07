---
title: "Cấp độ truy cập trong Java"
description: "Bài này chúng ta sẽ tìm hiểu về Điều khiển việc truy cập đến các thành viên của một lớp, tự học lập trình java, chia sẻ kiến thức về java"
keywords:
  [
    "access modifier java là gì",
    "access modifier là gì",
    "access modifier trong java",
    "bien public trong java",
    "biến private trong java",
    "cách sử dụng hàm private trong java",
    "hàm private trong java",
    "hàm public trong java",
    "khai báo private trong java",
    "lệnh private trong java",
    "private class trong java",
    "private final trong java",
    "private protected public trong java",
    "private và public trong java",
    "public là gì trong java",
  ]
author:
  fullname: Techmely Team
  username: Techmely Team
  avatar: "/configs/author/logo.jpg"
chapter:
  name: "Lập trình hướng đối tượng"
  slug: "chuong-03-lap-trinh-huong-doi-tuong"
category:
  logo: "/language/java.png"
  name: "Java"
  slug: "java"
  description: "Học Java từ cơ bản đến thông thạo cho mọi đối tượng"
image: https://user-images.githubusercontent.com/29374426/131236803-4e0e053a-1843-4d16-9306-46140849c6b4.png
position: 12
---

Có hai loại cấp độ truy cập (Access Modifier) trong Java, đó là: Access Modifier và Non-access Modifier.

Trong đó thì access modifier xác định phạm vi có thể truy cập của biến, phương thức, constructor hoặc lớp để có thể hạn chế sự truy cập đến các thành viên của lớp, từ một đối tượng khác và có 4 phạm vi truy cập như sau:

- private
- default
- protected
- public

Ngoài ra, còn có nhiều Non-access Modifier như static, abstract, synchronized, native, volatile, transient,...

![image](https://user-images.githubusercontent.com/29374426/131236803-4e0e053a-1843-4d16-9306-46140849c6b4.png)

## Tổng quan về cấp độ truy cập trong java

Bảng dưới đây mô tả khả năng truy cập của các Access Modifier trong java:

| Từ khoá | Truy cập trong chính lớp đó | Truy cập trong lớp con cùng gói | Truy cập trong lớp con khác gói | Truy cập trong lớp khác cùng gói | Truy cập trong lớp khác khác gói |
| --: | --: | --: | --: | --: | --- |
| private | X | - | - | - | - |
| protected | X | X | X | X | - |
| public | X | X | X | X | X |
| default | X | X | - | X | - |

Trong bảng trên thì X thể hiện cho sự truy cập hợp lệ còn – thể hiện không thể truy cập vào thành phần này.

## Phạm vi truy cập private

Các thành phần private chỉ có thể sử dụng bên trong lớp, ta không thể truy cập các thành phần private từ bên ngoài lớp này.

<div class="example"></div>

```java
class Alpha {
  private int bienPrivate;
  private void privateMethod() {
    System.out.println("Đây là phương thức private");
  }
}


class Beta {
  void accessMethod() {
    Alpha a = new Alpha();
    a.iamprivate = 10;// không hợp lệ
    a.privateMethod();// không hợp lệ
  }
}
```

<div class="note">
<ul>
  <li>Một lớp không thể là private hoặc protected, ngoại trừ lớp lồng nhau.</li>
  <li>Nếu bạn tạo bất kỳ constructor là private trong lớp, bạn sẽ không thể tạo instance của class bên ngoài nó.</li>
</ul>
</div>

## Phạm vi truy cập default

Nếu bạn không khai báo modifier nào, thì nó chính là trường hợp mặc định. Default Access Modifier là chỉ được phép truy cập trong cùng package.

<div class="example"></div>

```java
// Lưu file với tên Alpha.java
package thaycacac.package1;

class Alpha {
  void defaultMethod() {
    System.out.println("Đây là phương thức default");
  }
}
```

```java
// Lưu file với tên Beta.java
package thaycacac.package12;

class Beta {
    public static void main(String args[]) {
        Alphaobj = new Alpha();
        obj.defaultMethod(); // Không hợp lệ
    }
}
```

Trong ví dụ trên, phạm vi truy cập của lớp Alpha và phương thức của defaultMethod() của nó là mặc định nên chúng không thể được truy cập từ bên ngoài package.

## Phạm vi truy cập protected

Protected access modifier được truy cập bên trong package và bên ngoài package nhưng phải kế thừa.

<div class="example"></div>

```java
// Lưu file với tên Alpha.java
package thaycacac.package1;

class Alpha {
  protected void protectedMethod() {
    System.out.println("Đây là phương thức protected");
  }
}
```

```java
// Lưu file với tên Beta.java
package thaycacac.package12;

class Beta extends Alpha {
    public static void main(String args[]) {
        Alpha obj = new Alpha();
        obj.protectedMethod(); // Không hợp lệ
    }
}
```

## Phạm vi truy cập public

Các thành viên public có thể truy cập từ bất cứ đâu. Để

<div class="example"></div>

````java
public class Alpha {
  public int bienPublic;
  public void publicMethod() {
    System.out.println("Đây là phương thức public");
  }
}

```java
class Beta  {
  void accessMethod() {
    Alpha a = new Alpha();
    a.bienPublic = 10; // hợp lệ
    a.publicMethod(); // hợp lệ
  }
}
````
