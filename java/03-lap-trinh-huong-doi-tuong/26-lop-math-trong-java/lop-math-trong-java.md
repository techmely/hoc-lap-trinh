---
title: "Lớp Math trong Java"
description: "Bài này chúng ta sẽ tìm hiểu về Lớp math của Java, tự học lập trình java, chia sẻ kiến thức về java"
chapter:
  name: "Lập trình hướng đối tượng"
  slug: "chuong-03-lap-trinh-huong-doi-tuong"
category:
  name: "Java"
  slug: "java"
image: https://media.geeksforgeeks.org/wp-content/uploads/java.math-class-methods1.png
position: 26
---

Lớp [final](/bai-viet/java/tu-khoa-final-trong-java) class Math định nghĩa một tập các hàm tĩnh để thực hiện các chức năng chung của toán học như các phép làm tròn số, sinh số ngẫu nhiên, tìm số cực đại, cực tiểu,... Ngoài ra lớp này còn cung cấp những hằng số như số e (cơ số của logarithm), số pi thông qua `Math.E` và `Math.PI`.

## Các phương thức trong lớp Math

### Các hàm làm tròn và xử lý các giá trị giới hạn

- `abs()`: được nạp chồng để trả lại giá trị tuyệt đối của đối số.

```java
static int abs(int i)
static long abs(long l)
static float abs(float f)
static double abs(double d)
```

- `ceil()`: trả lại giá trị nhỏ nhất kiểu double mà không nhỏ hơn đối số và lại bằng số nguyên. Ví dụ ceil(3.14) cho giá trị 4.0 là số trần trên của đối số.

```java
static double ceil(double d)
```

- `floor()`: trả lại giá trị lớn nhất kiểu double mà không lớn hơn đối số và lại bằng số nguyên. Ví dụ floor(3.14) cho giá trị 3.0 là số sàn dưới của đối số.

```java
static double floor(double d)
```

- `round()`: được nạp chồng để trả lại số nguyên gần nhất của đối số

```java
static int round(float f d)
static long round(double d)
```

- `max()`: được nạp chồng để trả lại giá trị cực đại của hai đối số

```java
static int max(int a, int b)
static long max(long a, long b)
static float max(float a, float b)
static double max(double a, double b)
```

- `min()`: được nạp chồng để trả lại giá trị cực tiểu của hai đối số.

```java
static int	min(int a, int b)
static long	min(long a, long b)
static float	min(float a, float b)
static double min(double a, double b)
```

### Các hàm lũy thừa

- `pow()`: trả lại giá trị là lũy thừa của d1 và d2 (d1d2)

```java
static double pow(double d1, double d2)
```

- `exp()`: trả lại giá trị là luỹ thừa cơ số e và số mũ d (ed).

```java
static double exp(double d)
```

- `log()`: trả lại giá trị là lô-ga-rit tự nhiên (cơ số e) của d

```java
static double log(double d)
```

- `sqrt()` trả lại giá trị là căn bậc hai của d , hoặc giá trị NaN nếu đối số âm.

```java
static double sqrt(double d)
```

### Các hàm lượng giác

- `sin()` trả lại giá trị là sine của góc d được cho dưới dạng radian.

```java
static double sin(double d)
```

- `cos()` trả lại giá trị là cose của góc d được cho dưới dạng radian

```java
static double cos(double d)
```

- `tan()` trả lại giá trị là tangent của góc d được cho dưới dạng radian.

```java
static double tan(double d)
```

Hàm sinh số ngẫu nhiên, Hàm `random()` cho lại giá trị là số ngẫu nhiên trong khoảng từ 0.0 đến 1.0

```java
static double random()
```
