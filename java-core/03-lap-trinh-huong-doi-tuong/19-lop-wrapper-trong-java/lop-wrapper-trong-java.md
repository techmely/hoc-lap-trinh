---
title: "Lớp Wrapper trong Java"
description: "Lớp Wrapper trong java cung cấp cơ chế để chuyển đổi kiểu dữ liệu nguyên thủy thành kiểu đối tượng và từ đối tượng thành kiểu dữ liệu nguyên thủy"
keywords: []
chapter:
  name: "Lập trình hướng đối tượng"
  slug: "chuong-03-lap-trinh-huong-doi-tuong"
category:
  name: "Java"
  slug: "java"
image: https://user-images.githubusercontent.com/29374426/131335866-d1c536a4-fa19-4e3f-9d16-45d6198f7c8f.png
position: 19
---

Lớp Wrapper trong java cung cấp cơ chế để chuyển đổi kiểu dữ liệu nguyên thủy thành kiểu đối tượng và từ đối tượng thành kiểu dữ liệu nguyên thủy.

![image](https://user-images.githubusercontent.com/29374426/131335866-d1c536a4-fa19-4e3f-9d16-45d6198f7c8f.png)

Tính năng `autoboxing` và `unboxing` chuyển đổi kiểu dữ liệu nguyên thủy thành kiểu đối tượng và từ đối tượng thành kiểu dữ liệu nguyên thủy một cách tự động từ J2SE 5.0. Sự chuyển đổi tự động kiểu dữ liệu nguyên thủy thành kiểu đối tượng được gọi là `autoboxing` và ngược lại được gọi là `unboxing`.

## Các lớp bao kiểu nguyên thủy (Wrapper class)

Các giá trị nguyên thủy không phải là đối tượng trong Java. Để có thể thao tác được trên các giá trị nguyên thủy (giá trị số, kí tự và logic) thì gói java.lang cung cấp các lớp bao gói (Wrapper) cho từng kiểu dữ liệu nguyên thủy (gọi tắt là lớp bao). Có 8 lớp Wrapper chúng được thiết kế trong gói `java.lang` như sau

| Kiểu nguyên thủy | Kiểu Wrapper |
| ---------------- | ------------ |
| boolean          | Boolean      |
| char             | Character    |
| byte             | Byte         |
| short            | Short        |
| int              | Integer      |
| long             | Long         |
| float            | Float        |
| double           | Double       |

<div class="example">
  chuyển kiểu dữ liệu nguyên thủy thành kiểu Wrapper
</div>

```java
public class Thaycacac {
    public static void main(String args[]) {
        // Đổi int thành Integer
        int a = 2;
        Integer i = Integer.valueOf(a);// đổi int thành Integer
        Integer j = a;// autoboxing, tự động đổi int thành Integer trong nội bộ trình biên dịch
        System.out.println(a + " " + i + " " + j);
    }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>2 2 2</code>
    </div>
</div>

<div class="example">
  chuyển kiểu Wrapper thành kiểu dữ liểu nguyên thủy
</div>

```java
public class Thaycacac {
    public static void main(String args[]) {
        // đổi Integer thành int
        Integer a = new Integer(9);
        int i = a.intValue();// đổi Integer thành int
        int j = a;// unboxing, tự động đổi Integer thành int trong nội bộ trình biên dịch

        System.out.println(a + " " + i + " " + j);
    }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>9 9 9</code>
    </div>
</div>

## Các đặc điểm của lớp Wrapper trong Java

### Khởi tạo

Các lớp bao (trừ lớp Character chỉ có một cách khởi tạo) đều có hai cách khởi tạo:

- Các thứ nhất là sử dụng giá trị nguyên thủy để tạo ra đối tượng tương ứng

```java
Character charObj = new Character('a');
Boolean boolObj = new Boolean(true);
Integer intObj	= new Integer(2002);
Float floatObj	= new Float(3.14F);
Double doubleObj = new Double(3.14);
```

- Cách thứ 2 là chuyển thành String biểu diễn cho các giá trị nguyên thủy về các lớp tương ứng. Các toán tử này sẽ ném ra ngoại lệ `NumberFormatException` khi giá trị String truyền vào hàm tạo không hợp lệ.

```java
Boolean boolObj = new Boolean("true");
Integer intObj = new Integer("2002");
Float floatObj = new Float("3.14F");
Double doubleObj= new Double("3.14");
```

## Có các hàm chung: `valueOf(String s)`, `toString()`, `typeValue()`, `equals()`

- Mỗi lớp (trừ lớp Character) đều định nghĩa hàm static `valueOf(String s)` trả lại đối tượng tương ứng

Các hàm này ném ra ngoại lệ `NumberFormatException` khi giá trị String truyền vào phương thức không hợp lệ.

```java
Boolean boolObj = Boolean.valueOf("true");
Integer intObj = Integer.valueOf("2002");
Float floatObj = Float.valueOf("3.14F");
Double doubleObj= Double.valueOf("3.14");
```

- Các lớp viết đè hàm `toString()` trả lại là các đối tượng String biểu diễn cho các giá trị nguyên thủy ở dạng chuỗi

```java
String charStr = charObj.toString(); // "a"
String boolStr = boolObj.toString();	// "true"
String intStr = intObj.toString(); // "2002"
String doubleStr = doubleObj.toString(); // "3.14"
```

- Các lớp định nghĩa hàm `typeValue()` trả lại các giá trị nguyên thủy tương ứng với các đối tượng nguyên thủy

```java
boolean b = boolObj.booleanValue(); // true
int i = intObj.intValue();	// 2002
float f = floatObj.floatValueOf();	// 3.14F
double d = doubleObj.doubleValueOf(); // 3.14
char c = charObj.charValue();	// 'a'
```

- Các lớp viết đè hàm `equals()` để thực hiện so sánh bằng nhau của các đối tượng nguyên thủy

```java
Character charObj = new Character('a');
boolean charTest = charObj.equals('b');	// false
Integer intObj1 = Integer.valueOf("2010");
boolean intTest = intObj.equals(intObj1); // false
```
