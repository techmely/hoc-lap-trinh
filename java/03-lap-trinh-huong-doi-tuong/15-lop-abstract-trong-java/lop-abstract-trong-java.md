---
title: "Lớp abstract trong java"
description: "Một lớp cơ sở trừu tượng là một lớp chỉ được dùng làm cơ sở cho các lớp khác, ta không thể tạo ra thể hiện của lớp này, bởi vì nó được dùng để định nghĩa một giao diện chung cho các lớp khác"
chapter:
  name: "Lập trình hướng đối tượng"
  slug: "chuong-03-lap-trinh-huong-doi-tuong"
category:
  name: "Java"
  slug: "java"
image: https://user-images.githubusercontent.com/29374426/131245758-916ed8f2-11d1-4808-b7d4-d1890ad3cc1c.png
position: 15
---

Một lớp cơ sở trừu tượng là một lớp chỉ được dùng làm cơ sở cho các lớp khác, ta không thể tạo ra thể hiện của lớp này, bởi vì nó được dùng để định nghĩa một giao diện chung cho các lớp khác.

Một lớp được khai báo với từ khóa abstract là lớp abstract trong Java. Lớp abstract có nghĩa là lớp trừu tượng, nó có thể có các phương thức abstract hoặc non-abtract.

![image](https://user-images.githubusercontent.com/29374426/131245758-916ed8f2-11d1-4808-b7d4-d1890ad3cc1c.png)

Trước khi tìm hiểu về lớp trừu tượng trong Java, bạn cần hiểu [tính trừu tượng là gì](/bai-viet/java/tinh-truu-tuong-trong-java).

## Phương thức trừu tượng

Một lớp trừu tượng có thể chứa một vài phương thức trừu tượng, do lớp trừu tượng chỉ làm lớp cơ sở cho các lớp khác, do vậy các phương thức trừu tượng cũng không được cài đặt cụ thể, chúng chỉ gồm có khai báo, việc cài đặt cụ thể sẽ dành cho lớp con.

Nếu bạn muốn một lớp chứa một phương thức cụ thể nhưng bạn muốn triển khai thực sự phương thức đó để được quyết định bởi các lớp con, thì bạn có thể khai báo phương thức đó trong lớp cha ở dạng abstract.

Phương thức trừu tượng được sử dụng từ khóa `abstract` để khai báo, và một phương thức abstract không có thân. Phương thức abstract sẽ không có định nghĩa, được theo sau bởi dấu chấm phảy, không có cặp dấu ngoặc nhọn.

```java
// Khai báo phương thwucs với từ khóa abstract và không có thân phương thức
abstract void printStatus();
```

<div class="example">Ví dụ dưới dây Bike là lớp trừu tượng chỉ chứa một phương thức trừu tượng là run. Trình triển khai của nó được cung cấp bởi lớp Honda.</div>

```java
abstract class Bike{
  abstract void run();
}
class Honda4 extends Bike{
    void run() {
        System.out.println("running...");
    }

    public static void main(String args[]) {
        Bike obj = new Honda4();
        obj.run();
    }
}
```

::Result

    <code>running...</code>

::

::alert{type="infor"}

<ul>
  <li>Nếu trong lớp có phương thức trừu tượng thì lớp đó phải được khai báo là trừu tượng</li>
  <li>Nếu một lớp kế thừa từ lớp trừu tượng thì: hoặc chúng phải ghi đè tất cả các phương thức ảo của lớp cha, hoặc lớp đó phải là lớp trừu tượng</li>
  <li>Không thể tạo ra đối tượng của lớp trừu tượng</li>
</ul>
::

## Kế thừa lớp Abstract trong Java

<div class="example">
ví dụ dưới đây, Shape là lớp trừu tượng, ta có 2 lớp con Rectangle và lớp Circle. Hai lớp này kế thừa lớp trừu tượng Shape.
</div>

```java
// lớp trừu tượng shape
abstract class Shape{
    abstract void draw();
}

// Rectangle thừ kế lớp Shape
class Rectangle extends Shape{
void draw(){
  System.out.println("Ve hinh chu nhat");
  }
}

// Circle thừ kế lớp Shape
class Circle extends Shape{
  void draw(){
     System.out.println("Ve hinh tron");
  }
}


class Main{
  public static void main(String args[]) {
   Shape s=new Circle();
   s.draw();
   }
}
```

::Result

    <code>Ve hinh tron</code>

::
