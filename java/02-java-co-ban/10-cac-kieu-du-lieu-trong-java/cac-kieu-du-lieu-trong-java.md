---
title: "Các kiểu dữ liệu trong java"
description: "Java có 2 loại kiểu dữ liệu là kiểu dữ liệu nguyên thủy và kiểu dữ liệu tham chiếu, trong đó có 8 kiểu dữ liệu nguyên thủy (Primitive Data type) đó là: boolean, byte, char, short, int, long, float, double."
chapter:
  name: "Nhập môn Java"
  slug: "chuong-02-nhap-mon-java"
category:
  name: "Java"
  slug: "java"
image: https://user-images.githubusercontent.com/29374426/123082975-cc497780-d449-11eb-8315-b4e53f2257fe.png
position: 10
---

## Tổng quan các kiểu dữ liệu

Java có 2 loại kiểu dữ liệu:

- Các kiểu dữ liệu nguyên thủy (Primitive Data Types)
- Các kiểu dữ liệu tham chiếu (Reference Types)

## Các kiểu dữ liệu nguyên thuỷ

Có 8 kiểu dữ liệu nguyên thủy (Primitive Data type) đó là: boolean, byte, char, short, int, long, float, double.

![Các kiểu dữ liệu trong java](https://user-images.githubusercontent.com/29374426/123082975-cc497780-d449-11eb-8315-b4e53f2257fe.png)

Dưới đây là các thông số chi tiết

|  Kiểu   | Mô tả                           | Kích cỡ         | Tối thiểu | Tối đa         | Lớp bao   |
| :-----: | :------------------------------ | --------------- | --------- | -------------- | --------- |
|  byte   | số nguyên một byte              | 8 bit           | -128      | 127            | Byte      |
|  short  | số nguyên ngắn                  | 16 bit          | -2^15     | 2^15-1         | Short     |
|   int   | số nguyên                       | 32 bit          | -2^31     | 2^31-1         | Integer   |
|  long   | số nguyên dài                   | 64 bit          | -2^63     | -2^63-1        | Long      |
|  float  | kiểu thực với độ chính xác đơn  | 32 bit          | IEEE754   | IEEE754        | Float     |
| double  | Double-precision floating point | 64 bit          | IEEE754   | IEEE754        | Double    |
|  char   | kiểu kí tự                      | 16 bit          | Unicode 0 | Unicode 2^16-1 | Character |
| boolean | kiểu logic                      | true hoặc false | -         | -              | Boolean   |
|  void   | -                               | -               | -         | -              | Void      |

Đặc điểm của các biến có kiểu nguyên thủy là vùng nhớ của chúng được cấp phát ở phần stack. Do vậy việc truy xuất vào một biến kiểu nguyên thủy rất nhanh.

### Kiểu số nguyên trong Java

- Java cung cấp 4 kiểu số nguyên khác nhau là: `byte`, `short`, `int`, `long`. Kích thước, giá trị nhỏ nhất, lớn nhất, cũng như giá trị mặc định của các kiểu dữ liệu số nguyên được mô tả chi tiết trong bảng trên.
- Kiểu mặc định của các số nguyên là kiểu `int`.
- Các số nguyên kiểu `byte` và `short` rất ít khi được dùng.
- Trong java không có kiểu số nguyên không dấu như trong ngôn ngữ C/C++.

Khai báo và khởi tạo giá trị cho các biến kiểu nguyên:

```java
int x = 0;
long y = 100;
```

::alert{type="infor"}

Nếu hai toán hạng kiểu long thì kết quả là kiểu long. Một trong hai toán hạng không phải kiểu long sẽ được chuyển thành kiểu long trước khi thực hiện phép toán.</p>

- Nếu hai toán hạng đầu không phải kiểu long thì phép tính sẽ thực hiện với kiểu int.
- Các toán hạng kiểu byte hay short sẽ được chuyển sang kiểu int trước khi thực hiện phép toán.
- Trong java không thể chuyển biến kiểu int và kiểu boolean như trong ngôn ngữ C/C++.

::

Ví dụ:

```java
boolean b = false;
if (b == 0) {
  System.out.println("Xin chao");
}
```

Lúc biên dịch đoạn chương trình trên trình dịch sẽ báo lỗi **không được phép so sánh biến kiểu `boolean` với một giá trị kiểu `int`.**

## Kiểu dấu chấm động trong Java

Đối với kiểu dấu chấm động hay kiểu thực, java hỗ trợ hai kiểu dữ liệu là `float` và `double`.

- Kiểu `float` có kích thước 4 byte và giá trị mặc định là 0.0f.
- Kiểu `double` có kích thước 8 byte và giá trị mặc định là 0.0d

Số kiểu dấu chấm động không có giá trị nhỏ nhất cũng không có giá trị lớn nhất. Chúng có thể nhận các giá trị:

- Số âm
- Số dương
- Vô cực âm
- Vô cực dương

Ví dụ khai báo và khởi tạo giá trị cho các biến kiểu dấu chấm động:

```java
float x = 100.0/7;
double y = 1.56E6;
```

::alert{type="infor"}

Một số lưu ý đối với các phép toán trên số dấu chấm động

- Nếu mỗi toán hạng đều có kiểu dấn chấm động thì phép toán chuyển thành phép toán dấu chấm động.
- Nếu có một toán hạng là double thì các toán hạng còn lại sẽ được chuyển thành kiểu double trước khi thực hiện phép toán.
- Biến kiểu float và double có thể ép chuyển sang kiểu dữ liệu khác trừ kiểu boolean.
  ::

## Kiểu ký tự (char) trong Java

Kiểu ký tự trong ngôn ngữ lập trình java có kích thước là 2 bytes và chỉ dùng để biểu diễn các ký tự trong bộ mã Unicode. Như vậy kiểu char trong java có thể biểu diễn tất cả `2^16 = 65536` ký tự khác nhau.

Giá trị mặc định cho một biến kiểu `char` là `null`.

### Ví dụ kiểu dữ liệu kí tự

```java
char myLetter = 'D';
```

## Kiểu Boolean trong Java

- Kiểu boolean chỉ nhận 1 trong 2 giá trị: `true` hoặc `false`.
- Trong java kiểu boolean không thể chuyển thành kiểu nguyên và ngược lại.
- Giá trị mặc định của kiểu `boolean` là `false`.

```java
boolean myBool = true;
```

## Kiểu dữ liệu tham chiếu

Trong Java có 3 kiểu dữ liệu tham chiếu

| Kiểu dữ liệu          | Mô tả                                                                           |
| --------------------- | :------------------------------------------------------------------------------ |
| Mảng (Array)          | Tập hợp các dữ liệu cùng kiểu.                                                  |
| Lớp (Class)           | Là sự cài đặt mô tả về một đối tượng trong bài toán.                            |
| Giao diện (Interface) | Là một lớp thuần trừu tượng được tạo ra cho phép cài đặt đa thừa kế trong Java. |

Đặc điểm của các biến kiểu tham chiếu là nó chứa địa chỉ của đối tượng mà nó trỏ đến.

Vùng nhớ của biến tham chiếu được cấp phát ở vùng nhớ stack còn vùng nhớ của đối tượng được cấp phát ở vùng nhớ heap. Việc truy xất vào vùng nhớ heap `chậm` hơn truy xất vào vùng nhớ stack tuy nhiên java có cơ chế cho phép truy cập vào vùng nhớ heap với tốc độ xấp xỉ bằng tốc độ truy cập vào vùng nhớ stack.
