---
title: "Chuyển đổi kiểu dữ liệu trong Java"
description: "Ngoài việc ép kiểu trong java thì chuyển đối kiểu dữ liệu từ kiểu số ngày sang kiểu số khác như từ int sang string, từ string sang int, từ string sang double, từ double sang string, từ string sang date, từ date sang string cũng được java hỗ trợ "
keywords:
  [
    "chuyển đổi kiểu dữ liệu trong java",
    "kiểu dữ liệu trong java",
    "chuyển string sang int java",
    "kiểu boolean trong java",
    "kiểu double trong java",
    "cac kieu du lieu trong java",
    "kieu du lieu java",
    "kiểu int trong java",
    "chuyển kiểu string sang int trong java",
    "chuyển tự char sang int trong java",
    "chuyển từ string sang double trong java",
    "convert trong java",
  ]
chapter:
  name: "Nhập môn Java"
  slug: "chuong-02-nhap-mon-java"
category:
  logo: "/language/java.png"
  name: "Java"
  slug: "java"
  description: "Học Java từ cơ bản đến thông thạo cho mọi đối tượng"
image: https://user-images.githubusercontent.com/29374426/137243686-d91b1294-cb1f-4cc4-9e36-130d13a48352.png
position: 15
---

Ngoài việc ép kiểu thì chuyển đối kiểu dữ liệu từ kiểu số ngày sang kiểu số khác (ví dụ như từ double thành int) cũng được java hỗ trợ. Bài này [KungFu Tech](https://kungfutech.edu.vn/) sẽ hướng dẫn các bạn một vài cách thông dụng để chuyển đổi qua lại giữa các kiểu dữ liệu.

![Chuyển đổi kiểu dữ liệu trong Java](https://user-images.githubusercontent.com/29374426/137243686-d91b1294-cb1f-4cc4-9e36-130d13a48352.png)

## Chuyển đổi String thành int trong java

Việc chuyển đổi String thành int trong java thường được sử dụng nếu chúng ta phải thực hiện các phép toán trên chuỗi có chứa số. Chúng ta sử dụng phương thức `Integer.parseInt()`.

<div class="example"></div>

```java
int i = Integer.parseInt("200");
```

## Chuyển đổi int thành String trong java

Việc chuyển đổi **int** thành **String** trong java cũng thường được sử dụng trong nhiều trường hợp ví dụ như tham số truyền vào một hàm cần phải là **String**

Chúng ta có thể chuyển đổi int thành **String** trong java bằng 2 cách sau:

- Sử dụng phương thức `String.valueOf()`
- Sử dụng phương thức `Integer.toString()`

<div class="example"></div>

```java
// Cách 1
int i=10;
String s=String.valueOf(i); // kết quả là s = "10"

// Cách 2
int i=10;
String s=Integer.toString(i); // kết quả là s = "10"
```

## Chuyển đổi String thành long trong java

Để chuyển đổi **String** thành **long** trong java, chúng ta có thể sử dụng phương thức `Long.parseLong()`.

<div class="example"></div>

```java
long i = Long.parseLong("200");
```

## Chuyển đổi long thành String trong java

Tương tự như chuyển đổi **int** thành **string**, ta có 2 cách sau:

- Sử dụng phương thức `String.valueOf()`
- Sử dụng phương thức `Long.toString()`

<div class="example"></div>

```java
// Cách 1
int i=10;
String s=String.valueOf(i); // kết quả là s = "10"

// Cách 2
int i=10;
String s=Long.toString(i); // kết quả là s = "10"
```

## Chuyển đổi String thành float trong java

Để chuyển đổi **String** thành **float** trong java, chúng ta có thể sử dụng phương thức `Float.parseFloat()`.

<div class="example"></div>

```java
float i = Float.parseFloat("200");
```

## Chuyển đổi float thành String trong java

Chúng ta có thể chuyển đổi **float** thành **String** trong java bằng 2 cách sau:

- Sử dụng phương thức `String.valueOf()`
- Sử dụng phương thức `Float.toString()`

<div class="example"></div>

```java
// Cách 1
float i = 999.999F; // F là subfix cho số float
String s = String.valueOf(i); // kết quả là s = "999.999"

// Cách 2
float i = 999.999F;
String s = Float.toString(i); // kết quả là s = "999.999"
```

## Chuyển đổi String thành double trong java

Để chuyển đổi **String** thành **double** trong java, chúng ta có thể sử dụng phương thức `Double.parseDouble()`.

<div class="example"></div>

```java
double i = Double.parseLong("200");
```

## Chuyển đổi double thành String trong java

Chúng ta có thể chuyển đổi **double** thành **String** trong java bằng 2 cách sau:

- Sử dụng phương thức `String.valueOf()`
- Sử dụng phương thức `Double.toString()`

<div class="example"></div>

```java
// Cách 1
double i = 999.999D; // D là subfix cho số double
String s = String.valueOf(i); // kết quả là s = "999.999"

// Cách 2
double i = 999.999D;
String s = Double.toString(i); // kết quả là s = "999.999"
```

## Chuyển đổi String thành Date trong java

Chúng ta có thể chuyển đổi **String** thành **Date** trong java bằng cách sử dụng phương thức `parse()` của các lớp `DateFormat` và SimpleDateFormat.

<div class="example"></div>

```java
import java.text.SimpleDateFormat;
import java.util.Date;

public class StringToDateExample {
    public static void main(String[] args) throws Exception {
        String sDate = "17/07/2017";
        Date date = new SimpleDateFormat("dd/MM/yyyy").parse(sDate);
        System.out.println(sDate + "\t" + date);
    }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>17/07/2017 Mon Jul 17 00:00:00 ICT 2017</code>
  </div>
</div>

## Toán tử +

Ngoài các cách chuyển đổi kiểu dữ liệu số học thành **String** ở trên, java cung cấp toán tử cộng `+` cũng được sử dụng để chuyển các kiểu số thành **String**.

<div class="example"></div>

```java
public class ToanTuCong {
    public static void main(String[] args) {
        double d = 100D;
        String s = "" + d;
        System.out.println(s);
    }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>100.0</code>
  </div>
</div>
