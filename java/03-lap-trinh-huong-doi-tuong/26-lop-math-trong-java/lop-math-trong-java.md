---
title: "Lớp Math trong Java"
description: "Bài này chúng ta sẽ tìm hiểu về Lớp math của Java, tự học lập trình java, chia sẻ kiến thức về java"
chapter:
  name: "Lập trình hướng đối tượng"
  slug: "chuong-03-lap-trinh-huong-doi-tuong"
image: https://media.geeksforgeeks.org/wp-content/uploads/java.math-class-methods1.png
position: 26
---

Lớp `Math` trong Java định nghĩa một tập các phương thức tĩnh để thực hiện các chức năng toán học cơ bản. Nó cung cấp các phép toán như làm tròn số, tính lũy thừa, tính sin, cos, tan và nhiều phương thức khác. Trong bài viết này, chúng ta sẽ tìm hiểu về các phương thức quan trọng của lớp `Math` và cách sử dụng chúng trong Java.

## Các Phương Thức Trong Lớp Math

### Các Hàm Làm Tròn và Xử Lý Giới Hạn

#### `abs()`

Phương thức `abs()` được sử dụng để lấy giá trị tuyệt đối của một số. Nó trả về giá trị dương của số được cung cấp.

```java
double absoluteValue = Math.abs(-5.5); // absoluteValue = 5.5
```

#### `ceil()`

Phương thức `ceil()` trả về số nguyên lớn nhất không nhỏ hơn một số đã cho. Nó làm tròn số lên.

```java
double ceilingValue = Math.ceil(3.14); // ceilingValue = 4.0
```

#### `floor()`

Phương thức `floor()` trả về số nguyên lớn nhất không lớn hơn một số đã cho. Nó làm tròn số xuống.

```java
double floorValue = Math.floor(3.14); // floorValue = 3.0
```

#### `round()`

Phương thức `round()` làm tròn một số double hoặc float đến số nguyên gần nhất.

```java
int roundedValue = Math.round(3.75); // roundedValue = 4
```

#### `max()` và `min()`

Phương thức `max()` và `min()` trả về giá trị lớn nhất và nhỏ nhất trong hai số đã cho.

```java
int maxValue = Math.max(10, 20); // maxValue = 20
int minValue = Math.min(10, 20); // minValue = 10
```

### Các Hàm Lũy Thừa

#### `pow()`

Phương thức `pow()` tính lũy thừa của một số. Nó trả về giá trị của số thứ nhất được nâng lên số mũ của số thứ hai.

```java
double result = Math.pow(2, 3); // result = 8.0
```

#### `exp()`

Phương thức `exp()` tính giá trị của lũy thừa cơ số e với một số mũ đã cho.

```java
double result = Math.exp(2); // result = 7.3890560989306495
```

#### `log()`

Phương thức `log()` tính giá trị của logarithm tự nhiên (cơ số e) của một số.

```java
double result = Math.log(10); // result = 2.302585092994046
```

#### `sqrt()`

Phương thức `sqrt()` tính căn bậc hai của một số. Nó trả về giá trị căn bậc hai dương của số.

```java
double result = Math.sqrt(16); // result = 4.0
```

### Các Hàm Lượng Giác

#### `sin()`, `cos()`, và `tan()`

Các phương thức `sin()`, `cos()`, và `tan()` tính giá trị của sin, cos, và tan của một góc được cung cấp dưới dạng radian.

```java
double sinValue = Math.sin(Math.PI / 2);   // sinValue = 1.0
double cosValue = Math.cos(Math.PI);       // cosValue = -1.0
double tanValue = Math.tan(Math.PI / 4);   // tanValue = 1.0
```

### Hàm Sinh Số Ngẫu Nhiên

#### `random()`

Phương thức `random()` trả về một số ngẫu nhiên trong khoảng từ 0.0 (bao gồm) đến 1.0 (không bao gồm).

```java
double randomValue = Math.random(); // Giá trị ngẫu nhiên từ 0.0 đến 1.0
```

Lớp `Math` trong Java cung cấp một loạt các phương thức toán học cơ bản để thực hiện các phép toán như làm tròn số, tính lũy thừa, tính sin, cos, tan và nhiều chức năng khác. Bài viết này đã giới thiệu các phương thức quan trọng của lớp `Math` và cách sử dụng chúng trong Java. Sử dụng lớp `Math` có thể giúp bạn thực hiện các tính toán toán học một cách thuận tiện và hiệu quả trong ứng dụng Java của bạn.
