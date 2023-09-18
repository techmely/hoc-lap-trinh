---
title: "Lớp Wrapper trong Java"
description: "Lớp Wrapper trong java cung cấp cơ chế để chuyển đổi kiểu dữ liệu nguyên thủy thành kiểu đối tượng và từ đối tượng thành kiểu dữ liệu nguyên thủy"
chapter:
  name: "Lập trình hướng đối tượng"
  slug: "chuong-03-lap-trinh-huong-doi-tuong"
category:
  name: "Java"
  slug: "java"
image: https://user-images.githubusercontent.com/29374426/131335866-d1c536a4-fa19-4e3f-9d16-45d6198f7c8f.png
position: 19
---

Lớp Wrapper trong Java cung cấp cơ chế cho phép chuyển đổi giữa kiểu dữ liệu nguyên thủy và kiểu đối tượng. Đây là một khía cạnh quan trọng của Lập Trình Hướng Đối Tượng (OOP) trong Java. Trong bài viết này, chúng ta sẽ tìm hiểu về Lớp Wrapper, bao gồm tính năng `autoboxing` và `unboxing`, cùng với các ví dụ minh họa bằng ngôn ngữ Java.

![Lớp Wrapper trong Java](https://user-images.githubusercontent.com/29374426/131335866-d1c536a4-fa19-4e3f-9d16-45d6198f7c8f.png)

## Tính Năng Autoboxing và Unboxing

Từ phiên bản J2SE 5.0 trở đi, Java đã giới thiệu tính năng `autoboxing` và `unboxing` để tự động chuyển đổi kiểu dữ liệu nguyên thủy thành kiểu đối tượng và ngược lại. Dưới đây là một ví dụ đơn giản:

```java
int primitiveInt = 42;
Integer wrapperInt = Integer.valueOf(primitiveInt); // Chuyển từ int thành Integer
int backToInt = wrapperInt.intValue(); // Chuyển từ Integer thành int
```

Tính `autoboxing` tự động chuyển đổi kiểu dữ liệu nguyên thủy sang kiểu đối tượng và `unboxing` tự động chuyển đổi từ kiểu đối tượng sang kiểu dữ liệu nguyên thủy.

## Các Lớp Wrapper cho Kiểu Dữ Liệu Nguyên Thủy

Java cung cấp các lớp Wrapper tương ứng cho mỗi kiểu dữ liệu nguyên thủy. Dưới đây là bảng liệt kê các kiểu dữ liệu nguyên thủy và các lớp Wrapper tương ứng:

| Kiểu Nguyên Thủy | Lớp Wrapper |
| ---------------- | ----------- |
| boolean          | Boolean     |
| char             | Character   |
| byte             | Byte        |
| short            | Short       |
| int              | Integer     |
| long             | Long        |
| float            | Float       |
| double           | Double      |

Ví dụ: Chuyển đổi kiểu dữ liệu nguyên thủy thành kiểu Wrapper và ngược lại.

```java
public class WrapperExample {
    public static void main(String[] args) {
        int primitiveInt = 42;
        Integer wrapperInt = Integer.valueOf(primitiveInt); // Chuyển từ int thành Integer (autoboxing)
        int backToInt = wrapperInt.intValue(); // Chuyển từ Integer thành int (unboxing)

        System.out.println(primitiveInt + " " + wrapperInt + " " + backToInt);
    }
}
```

::Result

42 42 42

::

## Đặc Điểm của Lớp Wrapper trong Java

### Khởi Tạo

Các lớp Wrapper có hai cách khởi tạo. Cách thứ nhất là sử dụng giá trị nguyên thủy để tạo đối tượng tương ứng, cách thứ hai là chuyển một chuỗi biểu diễn kiểu dữ liệu nguyên thủy thành đối tượng Wrapper tương ứng. Lưu ý rằng nếu giá trị chuỗi không hợp lệ, nó sẽ ném ra ngoại lệ `NumberFormatException`.

```java
Integer intObj1 = Integer.valueOf(42); // Tạo từ giá trị nguyên thủy
Integer intObj2 = Integer.valueOf("42"); // Tạo từ chuỗi
```

### Hàm `toString()`

Các lớp Wrapper (trừ lớp Character) viết đè hàm `toString()` để trả về biểu diễn chuỗi của giá trị nguyên thủy.

```java
String intStr = intObj1.toString(); // "42"
```

### Hàm `typeValue()`

Các lớp Wrapper có hàm `typeValue()` để trả về giá trị nguyên thủy tương ứng với đối tượng Wrapper.

```java
int intValue = intObj1.intValue(); // 42
```

### Hàm `equals()`

Các lớp Wrapper viết đè hàm `equals()` để so sánh bằng nhau của các đối tượng Wrapper.

```java
Integer intObj3 = Integer.valueOf(42);
boolean isEqual = intObj1.equals(intObj3); // true
```

Lớp Wrapper trong Java cung cấp một cách tiện lợi để làm việc với kiểu dữ liệu nguyên thủy trong môi trường OOP, cho phép bạn chuyển đổi dễ dàng giữa kiểu dữ liệu nguyên thủy và kiểu đối tượng. Tính năng `autoboxing` và `unboxing` giúp giảm thiểu công việc chuyển đổi và làm cho mã nguồn của bạn trở nên dễ đọc hơn
