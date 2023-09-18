---
title: "Lớp StringBuffer trong Java"
description: "Trong java, lớp StringBuffer được sử dụng để tạo chuỗi có thể thay đổi (mutable). Lớp StringBuffer trong java tương tự như lớp String ngoại trừ nó có thể thay đổi."
chapter:
  name: "Lập trình hướng đối tượng"
  slug: "chuong-03-lap-trinh-huong-doi-tuong"
category:
  name: "Java"
  slug: "java"
image: https://user-images.githubusercontent.com/29374426/132500048-e2a8272c-e223-4bef-a04e-36a79c9e78d6.png
position: 24
---

Lớp `StringBuffer` trong Java là một công cụ mạnh mẽ để làm việc với chuỗi, cho phép thay đổi, nối chuỗi một cách hiệu quả. Trong bài viết này, chúng ta sẽ tìm hiểu về cách khởi tạo một đối tượng `StringBuffer`, các phương thức quan trọng của lớp `StringBuffer`, và cách sử dụng chúng trong Java.

![image](https://user-images.githubusercontent.com/29374426/132500048-e2a8272c-e223-4bef-a04e-36a79c9e78d6.png)

## Khởi tạo một đối tượng StringBuffer

Lớp `StringBuffer` cung cấp nhiều cách khởi tạo đối tượng, dưới đây là các ví dụ:

1. Sử dụng constructor mặc định:

```java
StringBuffer s1 = new StringBuffer();
```

2. Sử dụng constructor với dung lượng ban đầu:

```java
StringBuffer s2 = new StringBuffer(20);
```

3. Sử dụng constructor với một chuỗi ban đầu:

```java
StringBuffer s3 = new StringBuffer("StringBuffer");
```

Trong ví dụ trên, `s3` sẽ chứa chuỗi "StringBuffer".

```java
System.out.println("s3 = " + s3); // s3 = StringBuffer
System.out.println(s2.length());  // 0
System.out.println(s3.length());  // 12
System.out.println(s1.capacity());  // 16
System.out.println(s2.capacity());  // 20
System.out.println(s3.capacity());  // 28
```

Hãy lưu ý rằng `length()` và `capacity()` của `StringBuffer` là hai phương thức khác nhau. `length()` trả về số ký tự thực sự trong `StringBuffer`, trong khi `capacity()` trả về dung lượng tối đa mà `StringBuffer` có thể chứa mà không cần tăng cấp thêm.

Dung lượng của `StringBuffer` có thể thay đổi bằng cách sử dụng phương thức `ensureCapacity()`. Nếu dung lượng mới được yêu cầu lớn hơn dung lượng hiện tại, nó sẽ được tăng lên theo cơ chế:

```java
NewCapacity = OldCapacity * 2 + 2
```

Chúng ta có thể thấy cách hoạt động của `ensureCapacity()` qua ví dụ sau:

```java
StringBuffer s1 = new StringBuffer(5);
System.out.println("Initial capacity of s1 = " + s1.capacity()); // 5
s1.ensureCapacity(8);
System.out.println("Capacity of s1 after ensureCapacity(8) = " + s1.capacity()); // 12
s1.ensureCapacity(30);
System.out.println("Capacity of s1 after ensureCapacity(30) = " + s1.capacity()); // 30
```

Trong ví dụ trên, dung lượng ban đầu của `s1` là 5. Sau khi sử dụng `ensureCapacity(8)`, dung lượng của `s1` tăng lên thành 12 vì 8 < 12 (5 \* 2 + 2). Sau đó, khi sử dụng `ensureCapacity(30)`, dung lượng của `s1` tăng lên 30 vì 30 > 12.

## Các phương thức của lớp StringBuffer

### `append()`

Phương thức `append()` dùng để nối thêm chuỗi, mảng ký tự hoặc bất kỳ kiểu dữ liệu nào vào cuối của `StringBuffer`. Ví dụ:

```java
StringBuffer s1 = new StringBuffer("Good");
s1.append(" evening");
```

Kết quả sau khi sử dụng `append` là chuỗi "Good evening".

### `insert()`

Phương thức `insert()` cho phép chèn một chuỗi, một ký tự, một giá trị nguyên hoặc số thực vào vị trí bất kỳ trong `StringBuffer`. Phương thức này có hai tham số: vị trí chèn và giá trị được chèn. Ví dụ:

```java
StringBuffer str = new StringBuffer("Java sion");
str.insert(1, 'b');
```

Kết quả sau khi sử dụng `insert` là chuỗi "Jbava sion".

### `charAt()`

Phương thức `charAt()` trả về ký tự tại một vị trí xác định trong `StringBuffer`. Ví dụ:

```java
StringBuffer str = new StringBuffer("James Gosling");
char letter = str.charAt(6); // letter chứa 'G'
```

### `setCharAt()`

Phương thức `setCharAt()` dùng để thay thế ký tự tại một vị trí cụ thể trong `StringBuffer` bằng một ký tự khác. Ví dụ:

```java
StringBuffer name = new StringBuffer("Jawa");
name.setCharAt(2, 'v');
```

Kết quả sau khi sử dụng `setCharAt` là chuỗi "Java".

### `setLength()`

Phương thức `setLength()` dùng để thiết lập chiều dài của `StringBuffer`. Nếu chiều dài mới nhỏ hơn chiều dài hiện tại của `StringBuffer`, các ký tự thừa sẽ bị cắt bỏ. Nếu chiều dài mới lớn hơn, các ký tự null sẽ được thêm vào cuối. Ví dụ:

```java
StringBuffer str = new StringBuffer(10);
str.setLength(str.length() + 10);
```

### `getChars()`

Phương thức `getChars()` dùng để trích xuất các ký tự từ `StringBuffer` và sao chép chúng vào một mảng. Phương thức này có bốn tham số: vị trí bắt đầu, vị trí kết thúc, mảng đích và vị trí bắt đầu trong mảng đích. Ví dụ:

```java
StringBuffer str = new StringBuffer("Leopard");
char[] ch = new char[10];
str.getChars(3, 6, ch,

0);
```

Kết quả là biến `ch` chứa chuỗi "par".

### `reverse()`

Phương thức `reverse()` dùng để đảo ngược nội dung của `StringBuffer` và trả về một đối tượng `StringBuffer` mới. Ví dụ:

```java
StringBuffer str = new StringBuffer("devil");
StringBuffer strrev = str.reverse();
```

Kết quả là biến `strrev` chứa chuỗi "lived".

Lớp `StringBuffer` trong Java là một công cụ mạnh mẽ cho việc làm việc với chuỗi. Bài viết này đã giới thiệu cách khởi tạo đối tượng `StringBuffer`, các phương thức quan trọng và cách sử dụng chúng trong Java. Sử dụng lớp `StringBuffer` có thể giúp bạn thực hiện các thao tác liên quan đến chuỗi một cách thuận tiện và hiệu quả.
