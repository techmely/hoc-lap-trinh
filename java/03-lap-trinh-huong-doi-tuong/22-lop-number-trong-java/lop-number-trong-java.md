---
title: "Lớp Number trong Java"
description: "Lớp Number là một lớp bao trong java. Cung cấp nhiều method giúp thao tác nhanh với số, ngoài ra một object Number chỉ chứa duy nhất một giá trị number."
chapter:
  name: "Lập trình hướng đối tượng"
  slug: "chuong-03-lap-trinh-huong-doi-tuong"
category:
  name: "Java"
  slug: "java"
image: https://user-images.githubusercontent.com/29374426/132489584-c670b65c-7c28-497e-bca3-f3e8b49215ee.png
position: 22
---

Lớp Number là một [Wrapper class](/bai-viet/java/lop-wrapper-trong-java) trong java. Trong Java, các kiểu dữ liệu số nguyên (`byte`, `short`, `int`, `long`) và kiểu số thực (`float`, `double`) đều là các kiểu dữ liệu nguyên thủy. Tuy nhiên, Java cung cấp các lớp bao (wrapper classes) cho các kiểu dữ liệu này để làm việc với chúng như các đối tượng. Các lớp này bao gồm `Byte`, `Short`, `Integer`, `Long`, `Float`, và `Double`, và tất cả đều là các lớp con của lớp `Number`.. Trong bài viết này, chúng ta sẽ tìm hiểu về các lớp bao kiểu số, giới hạn của chúng và cách sử dụng chúng trong Java.

![Lớp Number trong Java](https://user-images.githubusercontent.com/29374426/132489584-c670b65c-7c28-497e-bca3-f3e8b49215ee.png)

Trong bài viết này, chúng ta sẽ tìm hiểu về các lớp bao kiểu số (`Number`) trong Java và cách sử dụng chúng.

### Các giới hạn của kiểu số

Mỗi lớp bao kiểu số (`Byte`, `Short`, `Integer`, `Long`, `Float`, `Double`) đều xác định hai giá trị quan trọng:

- `<Lớp bao>.MIN_VALUE`: Giá trị tối thiểu mà kiểu dữ liệu đó có thể lưu trữ.
- `<Lớp bao>.MAX_VALUE`: Giá trị tối đa mà kiểu dữ liệu đó có thể lưu trữ.

Ví dụ:

```java
byte minByte = Byte.MIN_VALUE;     // -128
byte maxByte = Byte.MAX_VALUE;     // 127
int minInt = Integer.MIN_VALUE;    // -2147483648
int maxInt = Integer.MAX_VALUE;    // 2147483647
```

### Chuyển đổi giá trị số từ đối tượng

Trong mỗi lớp bao kiểu số (`Byte`, `Short`, `Integer`, `Long`, `Float`, `Double`), bạn có thể sử dụng các phương thức sau để chuyển đổi giá trị số từ đối tượng:

- `byteValue()`: Chuyển đối tượng thành kiểu `byte`.
- `shortValue()`: Chuyển đối tượng thành kiểu `short`.
- `intValue()`: Chuyển đối tượng thành kiểu `int`.
- `longValue()`: Chuyển đối tượng thành kiểu `long`.
- `floatValue()`: Chuyển đối tượng thành kiểu `float`.
- `doubleValue()`: Chuyển đối tượng thành kiểu `double`.

Ví dụ:

```java
Integer myInteger = new Integer(42);
int intValue = myInteger.intValue(); // Chuyển thành kiểu int
```

### Chuyển đổi từ chuỗi sang số

Trong mỗi lớp bao kiểu số (`Byte`, `Short`, `Integer`, `Long`, `Float`, `Double`), bạn có thể sử dụng phương thức static `parse<Type>(String s)` để chuyển đổi giá trị từ chuỗi sang kiểu số tương ứng. Ví dụ:

- `Byte.parseByte(String s)`: Chuyển đổi chuỗi thành kiểu `byte`.
- `Integer.parseInt(String s)`: Chuyển đổi chuỗi thành kiểu `int`.
- `Double.parseDouble(String s)`: Chuyển đổi chuỗi thành kiểu `double`.

Ví dụ:

```java
byte parsedByte = Byte.parseByte("16");
int parsedInt = Integer.parseInt("2002");
double parsedDouble = Double.parseDouble("3.14");
```

### Ví dụ: Sắp xếp dãy số trong Java

Dưới đây là một ví dụ minh họa về việc nhập vào một dãy số và sắp xếp chúng theo thứ tự tăng dần:

```java
import java.util.Arrays;
import java.util.Scanner;

public class SortNumbers {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Nhập số lượng số: ");
        int n = scanner.nextInt();

        int[] numbers = new int[n];

        for (int i = 0; i < n; i++) {
            System.out.print("Nhập số thứ " + (i + 1) + ": ");
            numbers[i] = scanner.nextInt();
        }

        Arrays.sort(numbers);

        System.out.println("Dãy số sau khi sắp xếp:");
        for (int number : numbers) {
            System.out.print(number + " ");
        }
    }
}
```

Kết quả của đoạn mã trên sẽ nhập một dãy số từ người dùng, sau đó sắp xếp chúng theo thứ tự tăng dần và hiển thị dãy số đã sắp xếp.

::Result

Nhập số lượng số: 5
Nhập số thứ 1: 42
Nhập số thứ 2: 17
Nhập số thứ 3: 9
Nhập số thứ 4: 35
Nhập số thứ 5: 2
Dãy số sau khi sắp xếp:
2 9 17 35 42

::

Chúng ta đã tìm hiểu về các lớp bao kiểu số (`Number`) trong Java và cách sử dụng chúng để làm việc với giá trị số, cũng như một ví dụ về sắp xếp dãy số.
