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

Java có một lớp gọi là lớp **Math** cung cấp các hàm về toán học như `abs`, `ceil`, `floor`,... Lớp này nằm trong gói `java.lang` (gói mặc định) do vậy bạn không cần phải thêm câu lệnh `import` ở đầu chương trình để có thể sử dụng lớp này. Các hàm này được viết là các phương thức tĩnh do vậy ta không cần phải tạo ra thể hiện của lớp _Math_.

![cac-ham-toan-hoc-java](https://user-images.githubusercontent.com/29374426/135853402-d20a065b-d818-4519-a823-f73709bde64d.png)

## Các thuộc tính của lớp Math

Thư viện toán học Math là thư viện cung cấp các [phương thức](/bai-viet/java/ham-phuong-thuc-la-gi) có sẵn để giải quyết các vấn đề về số học, chính vì thế mà lớp này cũng đã cung cấp cho chúng ta những thuộc tính để chúng ta sử dụng.

- **E**: hằng số Euler (~ 2.7) // Math.E
- **PI**: số pi (~ 3.14). // Math.PI

```java
double eu = Math.E; // ~ 2.7
double pi = Math.PI; // ~ 3.14
```

## Các hàm toán học trong Java

Trong java cung cấp cho chúng ta các hàm hỗ trợ tính toán nâng cao như tính sin, cos, căn bậc 2, làm tròn,... Sử dụng tốt lớp này khiến cho việc lập trình của chúng ta trở nên đơn giản hơn, dưới đây là tổng hợp các phép tính mà lớp **Math** hỗ trợ

### Lấy giá trị tuyệt đối của Java - Math.abs()

`Math.abs()` trả về giá trị tuyệt đối của tham số truyền vào, hàm này có 4 cách nhận giá trị đầu vào như sau:

```java
Math.abs(int)
Math.abs(long)
Math.abs(float)
Math.abs(double)
```

```java
public class Main {
  public static void main(String[] args) {
    int x = 10;
    int y = -20;
    System.out.println(Math.abs(x - y)); // 30
    System.out.println(Math.abs(y - x)); // 30
    System.out.println(Math.abs(y)); // 20
    System.out.println(Math.abs(x)); // 10
  }
}
```

### Làm tròn lên trong Java – Math.ceil()

`Math.ceil()` trả về giá trị double là số làm tròn lên với giá trị số nguyên gần nhất

```java
public class Main {
  public static void main(String[] args) {
    int i = 5;
    float f = 5.4f;
    double d = 5.224d;
    double ri = Math.ceil(i); // 5.0
    double rf = Math.ceil(f); // 6.0
    double rd = Math.ceil(d); // 6.0
  }
}
```

### Làm tròn xuống trong Java – Math.floor()

`Math.floor()` trả về giá trị double là số làm tròn xuống với giá trị số nguyên gần nhất

```java
public class Main {
  public static void main(String[] args) {
    int i = 5;
    float f = 5.4f;
    double d = 5.224d;
    double ri = Math.floor(i); // 5.0
    double rf = Math.floor(f); // 5.0
    double rd = Math.floor(d); // 5.0
  }
}
```

### Làm tròn số trong java – Math.round()

Ngoài ra Java còn cung cấp một hàm `Math.round()` để làm tròn số theo quy luật thông thường trong toán học. Hàm này có 2 kiểu nhận tham số đầu vào như sau:

```java
Math.round(float, float)
Math.round(double, double)
```

```java
double roundedDown = Math.round(23.445); // 23
double roundedUp   = Math.round(23.545); // 24
```

### Chia 2 số nguyên và làm tròn trong Java – floorDiv()

`Math.floorDiv()` chia 1 số nguyên(int/long) với một số khác, và làm tròn xuống giá trị integer gần nhất.

```java
public class Main {
  public static void main(String[] args) {
    double result1 = Math.floorDiv(-100,9);
    System.out.println("result: " + result1);
    double result2 = -100 / 9;
    System.out.println("result: " + result2);
    double result3 = Math.floorDiv(100,9);
    System.out.println("result: " + result3);
    double result4 = 100 / 9;
    System.out.println("result: " + result4);
  }
}
```

### Tìm số lớn nhất của 2 số trong Java – Math.max()

Java cung cấp cho chúng ta hàm `Math.max()` để lấy số lớn trong hai số. Hàm này có 4 kiểu nhận tham số đầu vào

```java
Math.max(int, int)
Math.max(long, long)
Math.max(float, float)
Math.max(double, double)
```

```java
public class Main {
  public static void main(String[] args) {
    int i = Math.max(1, 2); // 2
    float f = Math.max(3.4f, 3.5f); // 3.5f
    float f1 = Math.max(3, 3.5f); // 3.5
    double d = Math.max(3.434d, 3.435d); // 3.435d
    double d1 = Math.max(3, 3.345d); // 3.345d
    double d2 = Math.max(3.5f, 3.345d); // 3.5
  }
}
```

### Tìm số lớn nhỏ của 2 số trong Java – Math.min()

Java cung cấp cho chúng ta hàm `Math.min()` để lấy số nhỏ trong hai số. Hàm này có 4 kiểu nhận tham số đầu vào

```java
Math.min(int, int)
Math.min(long, long)
Math.min(float, float)
Math.min(double, double)
```

```java
public class Main {
  public static void main(String[] args) {
    int i = Math.min(1, 2); // 1
    float f = Math.min(3.4f, 3.5f); // 3.4f
    float f1 = Math.min(3, 3.5f); // 3
    double d = Math.min(3.434d, 3.435d); // 3.434d
    double d1 = Math.min(3, 3.345d); // 3
    double d2 = Math.min(3.5f, 3.345d); // 3.345d
  }
}
```

### Lấy một số ngẫu nhiên trong Java - Math.random()

Ta có hàm `Math.random()` sẽ trả một một float trong khoảng 0 đến 1.

```java
double random = Math.random();
```

Nếu bạn muốn random số nguyên ngẫu nhiên trong khoảng **0 đến 100** có thể kết hợp `Math.random()` với `round()`, `ceil()`, `floor()`.

```java
System.out.println(Math.ceil(Math.random() * 100D));
```

### Một số hàm khác của lớp Math trong Java

`Math.pow()` lấy lũy thừa (cơ-số, số mũ)

```java
double p = Math.pow(2, 3); // 8.0
```

`Math.sqrt()` khai căn

```java
double a = Math.sqrt(9); //3
```

`Math.sin(), Math.cos()` sin và cos của góc đơn vị radian

```java
double s = Math.sin(Math.PI/2); //1
```

`Math.toDegrees()` đổi góc radian thành độ

```java
double goc = Math.toDegrees(Math.PI/2); //90
```

`Math.toRadians()` đổi góc đơn vị độ ra radian

```java
double goc = Math.toRadians(45); //0.7853981633974483
```

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
