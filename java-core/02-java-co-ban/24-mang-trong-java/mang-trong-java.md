---
title: "Mảng trong java"
description: "Java cung cấp cho chúng ta rất nhiều cấu trúc dữ liệu, trong đó array là một cấu trúc cho phép lưu trữ một tập hợp các dữ liệu cùng loại, tuần tự và có số lượng xác định."
keywords:
  [
    "array trong java",
    "array trong java example",
    "array trong java fpt",
    "array trong java là gì",
    "bai tap mảng trong java",
    "biến mảng trong java",
    "bài tập mảng 1 chiều trong java",
    "bài tập mảng 2 chiều trong java",
    "bài tập mảng trong java",
    "bài tập nhập mảng trong java",
    "bài tập về mảng 1 chiều trong java",
    "bài tập về mảng 2 chiều trong java",
    "bài tập về mảng một chiều trong java",
    "bài tập về mảng trong java",
  ]
author:
  fullname: Techmely Team
  username: Techmely Team
  avatar: "/configs/author/logo.jpg"
chapter:
  name: "Nhập môn Java"
  slug: "chuong-02-nhap-mon-java"
category:
  logo: "/language/java.png"
  name: "Java"
  slug: "java"
  description: "Học Java từ cơ bản đến thông thạo cho mọi đối tượng"
image: https://user-images.githubusercontent.com/29374426/127758202-bce42e1f-86eb-4557-aaf3-a6afa24bbe29.png
position: 24
---

Java cung cấp cho chúng ta rất nhiều cấu trúc dữ liệu, trong đó array là một cấu trúc cho phép lưu trữ một tập hợp các dữ liệu cùng loại, tuần tự và có số lượng xác định.

Cứ tưởng tượng nếu chúng ta cần sử dụng đến 100 biến `int` để lưu trữ data, thì chỉ với việc khai báo chúng ta đã ngốn hết 100 dòng code. Java cung cấp cho chúng ta rất nhiều cấu trúc dữ liệu, trong đó array là một cấu trúc cho phép lưu trữ một tập hợp các dữ liệu cùng loại, tuần tự và có số lượng xác định.

<div class="example"></div>

```java
int[] arr = new int[100];
```

## Khai báo mảng trong java

Cú pháp khai báo mảng trong java

```java
<Kiểu dữ liệu>[] <tên mảng>;
```

## Khởi tạo mảng

**Cách 1:** Khởi tạo không gán giá trị ban đầu

```java
<Kiểu dữ liệu>[] <tên mảng> = new <kiểu dữ liệu>[số lượng phần tử];
```

**Cách 2:** Khởi tạo có giá trị ban đầu

```java
<Kiểu dữ liệu>[] <tên mảng> = {value 0, value 1, ... value n};
```

## Mảng hoạt động như thế nào

Một mảng sẽ có chỉ số index từ 0 đến n – 1 (n là số lượng phần tử của mảng).

<div class="example">Khởi tạo mảng số nguyên 10 phần tử, có giá trị tuần tự từ 1 đến 10. Và xuất các giá trị của mảng ra màn hình console.</div>

```java
public class Thaycacac {
  public static void main(String[] args) {
    int[] arr = new int[10];
    for (int i = 0; i < 10; i++) {
      arr[i] = i + 1;
    }
    for(int item : arr) {
      System.out.print(item + " ");
    }
  }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>1 2 3 4 5 6 7 8 9 10</code>
  </div>
</div>
 
</div>

![mang-trong-java](https://user-images.githubusercontent.com/29374426/127758202-bce42e1f-86eb-4557-aaf3-a6afa24bbe29.png)

Trong một mảng phần tử đầu tiên (index = 0) gọi là foundation address. Các phần tử khác sẽ được truy xuất dựa vào phần tử đầu tiên.

## Truy xuất các phần tử của mảng

Chúng ta có 2 cách để truy xuất các phần tử của mảng

- Truy xuất trực tiếp
- Truy xuất tuần tự

### Truy xuất trực tiếp

```java
<mảng>[vị trí phần tử trong mảng];
```

<div class="example">truy xuất phần tử thứ 5 của mảng</div>

```java
public class Thaycacac {
  public static void main(String[] args) {
    // Khoi tao mang
    int[] arr = new int[10];
    for (int i = 0; i < 10; i++) {
      arr[i] = i + 1;
    }
    System.out.println(arr[5]);
  }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>6</code>
  </div>
</div>

<div class="note">
  Nếu index vượt ra khoảng chưá của mảng thì chúng ta sẽ bị ném một ngoại lệ. Khoảng hợp lệ 0 đến n – 1( n số lượng phần tử của mảng).
</div>

Ví dụ khi mình truy xuất arr[10] là vị trí không hợp lệ mình sẽ được kết quả sau: `Exception in thread “main” ava.lang.ArrayIndexOutOfBoundsException: 10 at Main.main(Main.java:11)`

### Truy xuất tuần tự

Sử dụng vòng lặp `for` truyền thống

```java
for(int i = 0; i < 10; i++) {
  System.out.println(i);
}
```

Sử dụng `foreach`

```java
for(int item : arr) {
  System.out.println(item);
}
```

## Passing by reference

Khi truyền mảng vào một method và xử lý trên các phần tử thì sẽ thay đổi giá trị của mảng ban đầu.

<div class="example">tăng mỗi phần tử trong mảng lên mảng lên 1 và in ra màn hình console.</div>

```java
public class Thaycacac {
  public static void main(String[] args) {
    // Khoi tao mang
    int[] arr = new int[10];
    for (int i = 0; i < 10; i++) {
      arr[i] = i + 1;
    }
    increment(arr);
    for(int item : arr) {
      System.out.print(item + " ");
    }
  }
  public static void increment(int[] arr) {
    for (int i = 0; i < 10; i++) {
      arr[i] += 1;
    }
  }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>2 3 4 5 6 7 8 9 10 11 </code>
  </div>
</div>

Chúng ta thấy hàm `increment()` đã thay đổi các giá trị trong mảng. Vì vậy ở hàm main truy xuất được mảng đã được update bởi `increment()`.

## Thao tác cơ bản trên mảng

Java cung cấp cho chúng ta một số thao tác cơ bản mà chúng ta thường xuyên sử dụng như sắp xếp, so sánh, ...

Ví dụ:

```java
public static int binarySeach(Object[] a, Object key) // Tìm kiếm phần tử key trong mảng, điều kiện mảng đã được sắp xếp
public static boolean equals(long[] a, long[] a2) // So sánh 2 mảng, trả về true nếu bằng nhau(index, value), ngược lại false
public static void fill(int[] a. int val) // Khởi tạo mảng với giá trị được gán sẵn val
public static void sort(Object[] a) // Sắp xếp mảng tăng dần
```

<div class="example">hàm sort</div>

```java
import java.util.Arrays;

public class Thaycacac {
  public static void main(String[] args) {
    // Khởi tạo mảng
    int[] arr = {5, 2, 0, -4, 3, 9};
    Arrays.sort(arr);
    for (int item : arr) {
        System.out.print(item + " ");
    }
  }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>-4 0 2 3 5 9 </code>
  </div>
</div>

## Bài tập thực hành

**Cho mảng số nguyên arr, gồm n phần tử. Tìm**

- Xuất giá trị của tất cả các phần tử trong mảng
- Tìm phần tử nhỏ nhất
- Tìm phần tử lớn nhất
- Đếm số lượng phần tử chẵn
- Đếm số lượng phần tử lẽ
