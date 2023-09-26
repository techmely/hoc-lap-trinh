---
title: "Lớp Character trong Java"
description: "Bài này chúng ta sẽ tìm hiểu về Một số lớp cơ bản của Java, tự học lập trình java, chia sẻ kiến thức về java"
chapter:
  name: "Lập trình hướng đối tượng"
  slug: "chuong-03-lap-trinh-huong-doi-tuong"
image: https://user-images.githubusercontent.com/29374426/131965653-d093ebae-2089-4057-b718-f2e6bfb13c88.png
position: 21
---

Character class là một [Wrapper class](/bai-viet/java/lop-wrapper-trong-java) của char trong java. Cung cấp nhiều method giúp thao tác nhanh với `char`, ngoài ra một `object Character` chỉ chứa duy nhất một giá trị `char`. Trong bài viết này, chúng ta sẽ tìm hiểu cách khởi tạo một đối tượng `Character` và các phương thức quan trọng của lớp `Character` để thao tác với ký tự trong Java.

![Lớp Character trong Java](https://user-images.githubusercontent.com/29374426/131965653-d093ebae-2089-4057-b718-f2e6bfb13c88.png)

Lớp `Character` trong Java cung cấp các phương thức hữu ích để làm việc với các ký tự. Trong bài viết này, chúng ta sẽ tìm hiểu cách khởi tạo một đối tượng `Character` và các phương thức quan trọng của lớp `Character` để thao tác với ký tự trong Java.

## Khởi tạo một đối tượng Character

Để khởi tạo một đối tượng `Character`, bạn có thể sử dụng hàm tạo (constructor) như sau:

```java
Character ch = new Character('a');
```

Trong ví dụ trên, chúng ta đã tạo một đối tượng `Character` với ký tự `'a'`.

## Các phương thức trong lớp Character

Lớp `Character` cung cấp một loạt các phương thức để thực hiện các thao tác với ký tự. Dưới đây là một số phương thức quan trọng của lớp `Character`:

### `isLetter()`

Phương thức `isLetter()` xác định xem một giá trị char có phải là một chữ cái hay không. Nó trả về `true` nếu ký tự là một chữ cái và `false` nếu không phải.

```java
Character ch = new Character('a');
boolean isLetter = Character.isLetter(ch); // true
```

### `isDigit()`

Phương thức `isDigit()` xác định xem một giá trị char có phải là một chữ số hay không. Nó trả về `true` nếu ký tự là một chữ số và `false` nếu không phải.

```java
boolean isDigit = Character.isDigit('0'); // true
```

### `isWhitespace()`

Phương thức `isWhitespace()` xác định xem một giá trị char có phải là một ký tự khoảng trắng (space) hay không.

```java
boolean isWhitespace = Character.isWhitespace(' '); // true
```

### `isUpperCase()` và `isLowerCase()`

Phương thức `isUpperCase()` xác định xem một giá trị char có phải là chữ hoa hay không, trong khi `isLowerCase()` xác định xem một giá trị char có phải là chữ thường hay không.

```java
boolean isUpperCase = Character.isUpperCase('A'); // true
boolean isLowerCase = Character.isLowerCase('a'); // true
```

### `toUpperCase()` và `toLowerCase()`

Phương thức `toUpperCase()` chuyển đổi một ký tự thường thành ký tự hoa, trong khi `toLowerCase()` chuyển đổi một ký tự hoa thành ký tự thường.

```java
char uppercaseChar = Character.toUpperCase('a'); // 'A'
char lowercaseChar = Character.toLowerCase('A'); // 'a'
```

### `toString()`

Phương thức `toString()` chuyển đổi một ký tự char thành chuỗi.

```java
String charToString = Character.toString('a'); // "a"
```

### `charValue()`

Phương thức `charValue()` trả về giá trị char của đối tượng `Character`.

```java
char charValue = ch.charValue(); // 'a'
```

### `equals()`

Phương thức `equals()` so sánh hai đối tượng `Character` và trả về `true` nếu chúng có giá trị char bằng nhau, ngược lại trả về `false`.

```java
Character ch1 = new Character('a');
Character ch2 = new Character('b');
boolean isEqual = ch1.equals(ch2); // false
```

### `compareTo()`

Phương thức `compareTo()` so sánh đối tượng `Character` với một đối tượng `Character` khác dựa trên giá trị char. Nó trả về số âm nếu đối tượng gọi (caller) nhỏ hơn, 0 nếu bằng và số dương nếu lớn hơn đối tượng so sánh.

```java
Character ch1 = new Character('a');
Character ch2 = new Character('b');
int compareResult = ch1.compareTo(ch2); // -1
```
