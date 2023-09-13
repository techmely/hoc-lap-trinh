---
title: "Lớp Boolean trong Java"
description: "Lớp Boolean là một Wrapper class của kiểu dữ liệu nguyên thuỷ boolean. Một object Boolean lưu trữ duy nhất một giá trị boolean"
chapter:
  name: "Lập trình hướng đối tượng"
  slug: "chuong-03-lap-trinh-huong-doi-tuong"
category:
  name: "Java"
  slug: "java"
image: https://user-images.githubusercontent.com/29374426/131364995-fd123de1-6e6d-49e8-ae2a-376e62e739db.png
position: 20
---

Lớp Boolean là một [Wrapper class](/bai-viet/java/lop-wrapper-trong-java) của kiểu dữ liệu nguyên thuỷ boolean. Một object Boolean lưu trữ duy nhất một giá trị boolean. Ngoài ra Boolean class còn xây dựng sẵn rất nhiều method hữu ích chúng ta thao tác dễ dàng với boolean trong java.

![image](https://user-images.githubusercontent.com/29374426/131364995-fd123de1-6e6d-49e8-ae2a-376e62e739db.png)

## Khởi tạo một object Boolean

Có 2 cách để khởi tạo đối tượng Boolean

- Boolean(boolean value): Khởi tạo một object Boolean từ giá trị boolean được cung cấp.
- Boolean(String s): Khởi tạo object Boolean từ chuỗi được cung cấp sẵn. Nếu s = "true" thì giá trị là `true`, tất cả các trường hợp còn lại là `false`.

```java
Boolean b1 = new Boolean(true); // true
Boolean b2 = new Boolean(false); // false
Boolean b1 = new Boolean("0"); // false
Boolean b2 = new Boolean("aaa"); // false
Boolean b3 = new Boolean("1"); // false
Boolean b4 = new Boolean("true"); // true
```

Boolean class cung cấp 2 hằng số:

- static Boolean TRUE: Trả về object Boolean với giá trị `true`
- static Boolean FALSE: Trả về object Boolean với giá trị `false`

```java
Boolean b1 = Boolean.TRUE; // true
Boolean b2 = Boolean.FALSE; // false
```

## Các phương thức trong Boolean class

- `parseBoolean(String s)`: Chuyển chuỗi sang object Boolean. Ngoài giá trị "true" thì các trường hợp khác đều trả về object Boolean có giá trị false.

```java
Boolean b1 = Boolean.parseBoolean("0"); // false
Boolean b2 = Boolean.parseBoolean("aaa"); // false
Boolean b3 = Boolean.parseBoolean("1"); // false
Boolean b4 = Boolean.parseBoolean("true"); // true
```

- `booleanValue()`: Trả về giá trị boolean của object Boolean.

```java
Boolean b1 = Boolean.parseBoolean("0"); // false
Boolean b2 = Boolean.parseBoolean("aaa"); // false
Boolean b3 = Boolean.parseBoolean("1"); // false
Boolean b4 = Boolean.parseBoolean("true"); // true
System.out.println(b1.booleanValue());
System.out.println(b2.booleanValue());
System.out.println(b3.booleanValue());
System.out.println(b4.booleanValue());
```

- `valueOf()`: Trả về object Boolean class từ giá trị boolean hoặc chuỗi s được cung cấp.

```java
Boolean b1 = Boolean.valueOf(false); // false
Boolean b2 = Boolean.valueOf(true); // true
Boolean b3 = Boolean.parseBoolean("false"); // false
Boolean b4 = Boolean.parseBoolean("true"); // true
System.out.println(b1.booleanValue());
System.out.println(b2.booleanValue());
System.out.println(b3.booleanValue());
System.out.println(b4.booleanValue());
```

- `toString()`: Chuyển giá trị boolean value của object Boolean sang chuỗi.

```java
Boolean b1 = Boolean.valueOf(false);
Boolean b2 = Boolean.valueOf(true);
System.out.println(b1.toString()); // false
System.out.println(b2.toString()); // true

// su dung static toString()
        System.out.println(Boolean.toString(true)); // true
        System.out.println(Boolean.toString(false));
```

- `equals()`: So sánh bằng, trả về true nếu 2 object có boolean bằng nhau, ngược lại false.

```java
Boolean b1 = Boolean.valueOf(false);
Boolean b2 = Boolean.valueOf(true);
Boolean b3 = Boolean.valueOf(false);
System.out.println(b1.equals(b2)); // false
System.out.println(b1.equals(b3)); // true
```

- `compareTo()`: So sánh với một object Boolean khác được truyền vào.

```java
Boolean b1 = new Boolean("True");
Boolean b2 = new Boolean("False");
Boolean b3 = new Boolean("TRue");
Boolean b4 = new Boolean(null);

//comparing b1,b2,b3,b4
System.out.println(b1.compareTo(b2));  // 1
System.out.println(b1.compareTo(b3)); // 0
System.out.println(b2.compareTo(b1)); // -1
System.out.println(b1.compareTo(b4)); // 1
System.out.println(b2.compareTo(b4)); // 0
```
