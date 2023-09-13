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

Lớp Number là một [Wrapper class](/bai-viet/java/lop-wrapper-trong-java) trong java. Cung cấp nhiều method giúp thao tác nhanh với số, ngoài ra một object Number chỉ chứa duy nhất một giá trị number.

![image](https://user-images.githubusercontent.com/29374426/132489584-c670b65c-7c28-497e-bca3-f3e8b49215ee.png)

### Các lớp bao kiểu số

Các lớp `Byte`, `Short`, `Integer`, `Long`, `Float`, `Double` là các lớp con của lớp Number.

Trong các lớp này đều xác định hai giá trị:

```java
<Lớp bao>.MIN_VALUE
<Lớp bao>.MAX_VALUE
```

là các giới hạn của các số trong kiểu đó.

```java
byte minByte = Byte.MIN_VALUE; // -128
int maxInt  = Integer.MAX_VALUE; // 2147483647
```

Trong mỗi lớp bao có hàm `typeValue()` để chuyển các giá trị của các đối tượng nguyên thủy về giá trị số.

```java
byte byteValue()
short shortValue()
int intValue()
long longValue()
float floatValue()
double doubleValue()
```

Trong mỗi lớp bao còn có hàm static `parseType(String s)` để chuyển các giá trị được biểu diễn dưới dạng xâu về các giá trị số.

```java
byte value1  = Byte.parseByte(“16”);
int value2 = Integer.parseInt(“2002”);
double value3 = Double.parseDouble(“3.14”);
```

Ví dụ: viết chương trình để nhập vào một dãy số tùy ý và sắp xếp theo thứ tự tăng dần

```java
import java.io.*; class SapXep{
static int[] day;

static void nhap() {
  String str;
  int n = day.length;
  DataInputStream stream = new DataInputStream(System.in);
  System.out.println("Nhap vao " + n + " so nguyen");
  for (int k = 0; k < n; k++) {
    try{
      System.out.print(k + ": ");
      str = stream.readLine();
      day[k] = Integer.valueOf(str).intValue();
    } catch(IOException e){
    System.err.println("I/O Error!");
    }
  }
}

static void hienThi() {
  int n = day.length;
  for (int k = 0; k < n; k++)
    System.out.print(day[k] + " ");
  System.out.println();
}

static void sapXep(){
  int x, max, k;
  for(int i =day.length-1; i > 0; i--){
    max = day[i];k = i;
    for (int j = 0; j < i; j++)
      if (max < day[j]) {
        max = day[j]; k = j;
      }
    day[k] = day[i]; day[i] = max;
    }
  }

public static void main(String[] args){
  String str;
  int n;
  DataInputStream stream = new DataInputStream(System.in);
  System.out.print("\nCho biet bao nhieu so nhap vao: ");

  try{
    str = stream.readLine();
  } catch(IOException e){
    System.err.println("I/O Error!");
    str = "0";
  }

  n = Integer.valueOf(str).intValue();
  SapXep.day = new int[n];
  nhap();
  sapXep();
  System.out.println("Day so duoc sap xep: ");
  hienThi();
  }
}
```
