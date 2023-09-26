---
title: "Lớp Boolean trong Java"
description: "Lớp Boolean là một Wrapper class của kiểu dữ liệu nguyên thuỷ boolean. Một object Boolean lưu trữ duy nhất một giá trị boolean"
chapter:
  name: "Lập trình hướng đối tượng"
  slug: "chuong-03-lap-trinh-huong-doi-tuong"
image: https://user-images.githubusercontent.com/29374426/131364995-fd123de1-6e6d-49e8-ae2a-376e62e739db.png
position: 20
---

Lớp Boolean là một [Wrapper class](/bai-viet/java/lop-wrapper-trong-java) của kiểu dữ liệu nguyên thuỷ boolean. Một object Boolean lưu trữ duy nhất một giá trị boolean. Ngoài ra Boolean class còn xây dựng sẵn rất nhiều method hữu ích chúng ta thao tác dễ dàng với boolean trong java. Trong bài viết này, chúng ta sẽ tìm hiểu cách khởi tạo một đối tượng `Boolean`, các phương thức quan trọng của lớp `Boolean`, và cách sử dụng chúng trong ngôn ngữ Java.

![Lớp Boolean trong Java](https://user-images.githubusercontent.com/29374426/131364995-fd123de1-6e6d-49e8-ae2a-376e62e739db.png)

## Khởi tạo một đối tượng Boolean

Có hai cách để khởi tạo một đối tượng `Boolean`:

1. Sử dụng constructor `Boolean(boolean value)`: Khởi tạo một đối tượng `Boolean` từ một giá trị boolean được cung cấp.

2. Sử dụng constructor `Boolean(String s)`: Khởi tạo một đối tượng `Boolean` từ một chuỗi được cung cấp. Nếu chuỗi là "true" (không phân biệt chữ hoa và chữ thường), thì giá trị là `true`; trong trường hợp khác, giá trị là `false`.

Ví dụ:

```java
Boolean b1 = new Boolean(true);   // true
Boolean b2 = new Boolean(false);  // false
Boolean b3 = new Boolean("0");    // false
Boolean b4 = new Boolean("aaa");  // false
Boolean b5 = new Boolean("1");    // false
Boolean b6 = new Boolean("true"); // true
```

Ngoài ra, lớp `Boolean` cung cấp hai hằng số:

- `Boolean.TRUE`: Trả về một đối tượng `Boolean` với giá trị `true`.
- `Boolean.FALSE`: Trả về một đối tượng `Boolean` với giá trị `false`.

Ví dụ:

```java
Boolean b1 = Boolean.TRUE;  // true
Boolean b2 = Boolean.FALSE; // false
```

## Các phương thức trong lớp Boolean

Lớp `Boolean` cung cấp một số phương thức quan trọng để làm việc với giá trị boolean.

### `parseBoolean(String s)`

Phương thức này chuyển đổi một chuỗi thành một đối tượng `Boolean`. Nếu chuỗi là "true" (không phân biệt chữ hoa và chữ thường), thì kết quả là `true`; trong trường hợp khác, kết quả là `false`.

```java
Boolean b1 = Boolean.parseBoolean("0");    // false
Boolean b2 = Boolean.parseBoolean("aaa");  // false
Boolean b3 = Boolean.parseBoolean("1");    // false
Boolean b4 = Boolean.parseBoolean("true"); // true
```

### `booleanValue()`

Phương thức này trả về giá trị boolean của đối tượng `Boolean`.

```java
Boolean b1 = Boolean.valueOf("false"); // false
System.out.println(b1.booleanValue());  // false
```

### `valueOf()`

Phương thức này trả về một đối tượng `Boolean` từ một giá trị boolean hoặc một chuỗi được cung cấp.

```java
Boolean b1 = Boolean.valueOf(false);  // false
Boolean b2 = Boolean.valueOf(true);   // true
Boolean b3 = Boolean.valueOf("false"); // false
Boolean b4 = Boolean.valueOf("true");  // true
```

### `toString()`

Phương thức này chuyển đổi giá trị boolean của đối tượng `Boolean` thành một chuỗi.

```java
Boolean b1 = Boolean.valueOf(false);
Boolean b2 = Boolean.valueOf(true);
System.out.println(b1.toString()); // "false"
System.out.println(b2.toString()); // "true"
```

### `equals()`

Phương thức này so sánh hai đối tượng `Boolean` và trả về `true` nếu chúng có giá trị boolean bằng nhau, ngược lại trả về `false`.

````java
Boolean b1 = Boolean.valueOf(false);
Boolean b2 = Boolean.valueOf(true);
Boolean b3 = Boolean.valueOf(false);

System.out.println(b1.equals(b2)); // false
System.out.println(b1.equals(b3)); // true
``

`

### `compareTo()`

Phương thức này so sánh đối tượng `Boolean` với một đối tượng `Boolean` khác được truyền vào và trả về giá trị 1 nếu đối tượng gọi (caller) lớn hơn, 0 nếu bằng, và -1 nếu nhỏ hơn đối tượng được so sánh.

```java
Boolean b1 = new Boolean("True");
Boolean b2 = new Boolean("False");
Boolean b3 = new Boolean("TRue");

System.out.println(b1.compareTo(b2));  // 1
System.out.println(b1.compareTo(b3));  // 0
System.out.println(b2.compareTo(b1));  // -1
````
