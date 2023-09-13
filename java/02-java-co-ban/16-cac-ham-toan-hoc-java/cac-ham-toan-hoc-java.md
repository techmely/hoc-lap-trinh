---
title: "Các hàm toán học trong Java"
description: "Java có một lớp gọi là lớp Math cung cấp các hàm về toán học như lấy giá trị tuyệt đối Math.abs, làm tròn lên Math.ceil, làm tròn xuống Math.floor, tìm số nhỏ nhất Math.min, tìm số lớn nhất Math.max, lấy một số ngẫu nhiên Math.random... bài này chúng ta sẽ cùng tìm hiểu về các hàm toán học"
chapter:
  name: "Nhập môn Java"
  slug: "chuong-02-nhap-mon-java"
category:
  name: "Java"
  slug: "java"
image: https://user-images.githubusercontent.com/29374426/135853402-d20a065b-d818-4519-a823-f73709bde64d.png
position: 16
---

Java là một ngôn ngữ lập trình mạnh mẽ không chỉ trong việc xử lý dữ liệu và chuỗi, mà còn cung cấp một loạt các hàm toán học phong phú thông qua lớp **Math**. Lớp này được đặt sẵn trong gói `java.lang`, do đó bạn không cần phải thêm câu lệnh `import` để sử dụng các hàm toán học này. Hãy cùng điểm qua các hàm toán học quan trọng trong Java.

![cac-ham-toan-hoc-java](https://user-images.githubusercontent.com/29374426/135853402-d20a065b-d818-4519-a823-f73709bde64d.png)

## Các thuộc tính của lớp Math

Trước khi chúng ta khám phá các hàm toán học, hãy tìm hiểu về một số thuộc tính quan trọng của lớp Math:

- **E**: Đây là hằng số Euler, xấp xỉ khoảng 2.7. Bạn có thể truy cập nó bằng cách sử dụng `Math.E`.

- **PI**: Đây là số Pi, xấp xỉ khoảng 3.14. Bạn có thể truy cập nó bằng cách sử dụng `Math.PI`.

```java
double euler = Math.E; // ~ 2.7
double pi = Math.PI;   // ~ 3.14
```

## Các hàm toán học trong Java

Trong java cung cấp cho chúng ta các hàm hỗ trợ tính toán nâng cao như tính sin, cos, căn bậc 2, làm tròn,... Sử dụng tốt lớp này khiến cho việc lập trình của chúng ta trở nên đơn giản hơn, dưới đây là tổng hợp các phép tính mà lớp **Math** hỗ trợ

### Lấy giá trị tuyệt đối của Java - Math.abs()

Hàm `Math.abs()` trả về giá trị tuyệt đối của một số. Java hỗ trợ nhiều kiểu dữ liệu khác nhau, vì vậy bạn có thể sử dụng nó cho số nguyên, số thực và nhiều kiểu khác.

```java
int x = 10;
int y = -20;
System.out.println(Math.abs(x - y)); // 30
System.out.println(Math.abs(y - x)); // 30
System.out.println(Math.abs(y));     // 20
System.out.println(Math.abs(x));     // 10
```

### Làm tròn lên - `Math.ceil()`

Hàm `Math.ceil()` trả về giá trị làm tròn lên của một số thực.

```java
int i = 5;
float f = 5.4f;
double d = 5.224d;
double roundedI = Math.ceil(i); // 5.0
double roundedF = Math.ceil(f); // 6.0
double roundedD = Math.ceil(d); // 6.0
```

### Làm tròn xuống - `Math.floor()`

Hàm `Math.floor()` trả về giá trị làm tròn xuống của một số thực.

```java
int i = 5;
float f = 5.4f;
double d = 5.224d;
double roundedI = Math.floor(i); // 5.0
double roundedF = Math.floor(f); // 5.0
double roundedD = Math.floor(d); // 5.0
```

### Làm tròn - `Math.round()`

Hàm `Math.round()` làm tròn một số thực theo quy tắc thông thường trong toán học.

```java
double roundedDown = Math.round(23.445); // 23
double roundedUp = Math.round(23.545);   // 24
```

### Chia số nguyên và làm tròn - `Math.floorDiv()`

Hàm `Math.floorDiv()` chia một số nguyên cho một số khác và làm tròn kết quả xuống đến số nguyên gần nhất.

```java
double result1 = Math.floorDiv(-100, 9);  // -12.0
double result2 = -100 / 9;                // -11.0
double result3 = Math.floorDiv(100, 9);   // 11.0
double result4 = 100 / 9;                 // 11.0
```

### Tìm số lớn nhất - `Math.max()`

Hàm `Math.max()` trả về số lớn hơn trong hai số được cung cấp.

```java
int maxInt = Math.max(1, 2);                // 2
float maxFloat = Math.max(3.4f, 3.5f);      // 3.5f
double maxDouble = Math.max(3.434d, 3.435d);// 3.435d
```

### Tìm số nhỏ nhất - `Math.min()`

Hàm `Math.min()` trả về số nhỏ hơn trong hai số được cung cấp.

```java
int minInt = Math.min(1, 2);                // 1
float minFloat = Math.min(3.4f, 3.5f);      // 3.4f
double minDouble = Math.min(3.434d, 3.435d);// 3.434d
```

### Sin, Cos, Tan - `Math.sin()`, `Math.cos()`, `Math.tan()`

Java cung cấp các hàm để tính sin, cos và tan của một góc (đơn vị radian).

```java
double sinValue = Math.sin(Math.PI/2);   // 1.0
double cosValue = Math.cos(Math.PI);     // -1.0
double tanValue = Math.tan(Math.PI/4);   // 1.0
```

### Lũy thừa - `Math.pow()`

Hàm `Math.pow()` tính lũy thừa của một số.

```java
double power = Math.pow(2, 3);  // 8.0
```

### Căn bậc hai - `Math.sqrt()`

Hàm `Math.sqrt()` tính căn bậc hai của một số.

```java
double squareRoot = Math.sqrt(9);  // 3.0
```

### Số ngẫu nhiên - `Math.random()`

Hàm `Math.random()` trả về một số ngẫu nhiên trong khoảng từ 0 (bao gồm) đến 1 (không bao gồm).

```java
double randomValue = Math.random();
```

Để tạo số ngẫu nhiên trong một phạm vi cụ thể, bạn có thể kết hợp `Math.random()` với các phép toán làm tròn.

```java
int randomInt = (int)(Math.random() * 100); // Số nguyên ngẫu nhiên từ 0 đến 99
```

## Tổng hợp một số phương thức và ý nghĩa

| Tên phương thức   | Mô tả ý nghĩa                                                                                | Kiểu tham số                                                          | Kiểu trả về                                                                |
| ----------------- | -------------------------------------------------------------------------------------------- | --------------------------------------------------------------------- | -------------------------------------------------------------------------- |
| sin(arg)          | tính sin của arg                                                                             | arg là một biểu thức kiểu double thể hiện một cung theo radians       | double                                                                     |
| cos(arg)          | tính cos của arg                                                                             | arg là một biểu thức kiểu double thể hiện một cung theo radians       | double                                                                     |
| tan(arg)          | tính tang của arg                                                                            | arg là một biểu thức kiểu double thể hiện một cung theo radians       | double                                                                     |
| asin(arg)         | tính sin-1 (arcsin)                                                                          | arg arg là một biểu thức kiểu double thể hiện một cung theo radians   | double trong hệ radians                                                    |
| acos(arg)         | tính cos-1 (arccosin) của arg                                                                | arg là một biểu thức kiểu double thể hiện một cung theo radians       | double trong hệ radians                                                    |
| atan(arg)         | tính tan-1 (arctang) của arg                                                                 | arg là một biểu thức kiểu double thể hiện một cung theo radians       | double trong hệ radians                                                    |
| atan2 (arg1,arg2) | tính tan-1 (arctang) của arg1/arg2                                                           | arg1,arg2 là các biểu thức kiểu double thể hiện một cung theo radians | double trong hệ radians                                                    |
| abs(arg)          | tính trị tuyệt đối của arg                                                                   | arg là một biểu thức kiểu int, long, float, hoặc double               | The same type as the argument                                              |
| max (arg1,arg2)   | Nhận về giá trị lớn trong hai tham số                                                        | arg1, arg2 là một biểu thức kiểu int, long, float, hoặc double        | Nhận về kiểu cùng kiểu với tham số                                         |
| min (arg1,arg2)   | Nhận về giá trị nhỏ trong hai tham số                                                        | arg1, arg2 lµ mét biùu thøc kiùu int, long, float, hoÆc double        | Nhận về kiểu cùng kiùu với tham số                                         |
| ceil(arg)         | Nhận về giá trị nguyên nhỏ hơn hoặc bằng arg                                                 | arg là biểu thức kiểu float hoặc double                               | double                                                                     |
| floor(arg)        | Nhận về giá trị nguyên lớn hơn hoặc bằng arg                                                 | arg là biểu thức kiểu float hoặc double                               | double                                                                     |
| round(arg)        | Trả về giá trị nguyên gần arg nhất, giá trị này chính là giá trị của arg sau khi đã làm tròn | arg là biểu thức kiểu float hoặc double                               | Nhận về kiểu int nếu arg kiêu float, nhận về kiùu long nếu arg kiểu double |
| rint(arg)         | Giống như round(arg)                                                                         | arg là biểu thức kiểu double                                          | double                                                                     |
| sqrt(arg)         | tính căn bậc hai của arg                                                                     | arg là biểu thức kiểu double double                                   |
| pow (arg1,arg2)   | tính arg1arg2                                                                                | Cả arg1 và arg2 là các biểu thức kiểu double                          | double                                                                     |
| exp(arg)          | tính earg                                                                                    | arg là biểu thức kiểu double                                          | double                                                                     |
| log(arg)          | tính logarithmớ số e của arg                                                                 | arg là biểu thức kiểu double                                          | double                                                                     |
| random()          | Nhận về một số giả ngẫu nhiên nằm trong khoản [0, 1)                                         | Không có tham số                                                      | double                                                                     |

::alert{type="infor"}
Trong Java, lớp **Math** cung cấp một loạt các hàm toán học mạnh mẽ giúp bạn thực hiện các phép tính toán phức tạp và xử lý dữ liệu số học một cách dễ dàng. Nhớ rằng các hàm này là các phương thức tĩnh và không cần tạo đối tượng **Math** mới để sử dụng chúng.
::
