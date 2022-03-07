---
title: "Lớp StringBuffer trong Java"
description: "Trong java, lớp StringBuffer được sử dụng để tạo chuỗi có thể thay đổi (mutable). Lớp StringBuffer trong java tương tự như lớp String ngoại trừ nó có thể thay đổi."
keywords:
  [
    "lớp stringbuffer trong java bị lỗi",
    "lớp stringbuffer trong java code",
    "lớp stringbuffer trong java cơ bản",
    "lớp stringbuffer trong java dịch",
    "lớp stringbuffer trong java edition",
    "lớp stringbuffer trong java fpt",
    "lớp stringbuffer trong java free",
    "lớp stringbuffer trong java game",
    "lớp stringbuffer trong java là gì",
  ]
author:
  fullname: Techmely Team
  username: Techmely Team
  avatar: "/configs/author/logo.jpg"
chapter:
  name: "Lập trình hướng đối tượng"
  slug: "chuong-03-lap-trinh-huong-doi-tuong"
category:
  logo: "/language/java.png"
  name: "Java"
  slug: "java"
  description: "Học Java từ cơ bản đến thông thạo cho mọi đối tượng"
image: https://user-images.githubusercontent.com/29374426/132500048-e2a8272c-e223-4bef-a04e-36a79c9e78d6.png
position: 24
---

Trong java, lớp StringBuffer được sử dụng để tạo chuỗi có thể thay đổi (mutable). Lớp StringBuffer trong java tương tự như lớp String ngoại trừ nó có thể thay đổi.

![image](https://user-images.githubusercontent.com/29374426/132500048-e2a8272c-e223-4bef-a04e-36a79c9e78d6.png)

## Khởi tạo một lớp StringBuffer

Lớp này cung cấp nhiều phương thức khởi tạo, chương trình sau minh hoạ cách sử dụng các phương thức khởi tạo khác nhau để tạo ra các đối tượng của lớp này

```java
class StringBuffer {
  public static void main(String args[]){
    StringBuffer s1 = new StringBuffer();
    StringBuffer s2 = new StringBuffer(20);
    StringBuffer s3 = new StringBuffer("StringBuffer");
    System.out.println("s3 = "+ s3);
    System.out.println(s2.length()); // chứa 0
    System.out.println(s3.length()); //chứa 12
    System.out.println(s1.capacity());  //chứa 16
    System.out.println(s2.capacity());  //chứa 20
    System.out.println(s3.capacity()); //chứa 28
  }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>0</code><br/>
    <code>12</code><br/>
    <code>16</code><br/>
    <code>20</code><br/>
    <code>28</code>
  </div>
</div>

`length()` và `capacity()` của StringBuffer là hai phương thức hoàn toàn khác nhau. Phương thức `length()` đề cập đến số các ký tự mà đối tượng thực chứa, trong khi `capacity()` trả về tổng dung lượng của một đối tượng (mặc định là 16) và số ký tự trong đối tượng **StringBuffer**.

Dung lượng của StringBuffer có thể thay đổi với phương thức `ensureCapacity()`. Đối số `int` đã được truyền đến phương thức này, và dung lượng mới được tính toán như sau:

```java
NewCapacity = OldCapacity * 2 + 2
```

Trước khi dung lượng của **StringBuffer** được đặt lại, điều kiện sau sẽ được kiểm tra:

- Nếu dung lượng mới (NewCapacity) lớn hơn đối số được truyền cho phương thức `ensureCapacity()`, thì dung lượng mới bằng NewCapacity được đặt.
- Nếu dung lượng mới nhỏ hơn đối số được truyền cho phương thức `ensureCapacity()`, thì dung lượng được đặt bằng giá trị tham số truyền vào.

<div class="example">Chương trình sau minh hoạ dung lượng được tính toán và được đặt như thế nào</div>

```java
class StringBuffer {
  public static void main(String args[]) {
    StringBuffer s1 = new StringBuffer(5);
    System.out.println("Dung	lượng	của	bộ	nhớ	đệm	= "+s1.capacity()); //chứa 5
    s1.ensureCapacity(8);
    System.out.println("Dung	lượng	của	bộ	nhớ	đệm	= "+s1.capacity()); //chứa 12
    s1.ensureCapacity(30);
    System.out.println("Dung	lượng	của	bộ	nhớ	đệm	= "+s1.capacity()); // chứa 30
  }
}
```

Trong đoạn mã trên, dung lượng ban đầu của s1 là 5. Câu lệnh

```java
s1.ensureCapacity(8);
```

Thiết lập dung lượng của s1 đến 12 =(5\*2 + 2) bởi vì dung lượng truyền vào là 8 nhỏ hơn dung lượng được tính toán là 12.

```java
s1.ensureCapacity(30);
```

Thiết lập dung lượng của "s1" đến 30 bởi vì dung lượng truyền vào là 30 thì lớn hơn dung lượng được tính toán (12\*2+2).

## Các phương thức lớp StringBuffer

- `void append()`: Phương thức này nối thêm một chuỗi hoặc một mảng ký tự vào cuối cùng của đối tượng StringBuffer. Ví dụ:

<div class="example"></div>

```java
StringBuffer s1 = new StringBuffer("Good");
s1.append("evening");
```

Giá trị trong s1 bây giờ là `Goodevening`.

- `insert()`: Phương thức này có hai tham số. Tham số đầu tiên là vị trí chèn. Tham số thứ hai có thể là một chuỗi, một ký tự (char), một giá trị nguyên (int), hay một giá trị số thực (float) được chèn vào. Vị trí chèn sẽ lớn hơn hay bằng 0, và nhỏ hơn hay bằng chiều dài của đối tượng StringBuffer. Bất kỳ đối số nào, trừ ký tự hoặc chuỗi, được chuyển sang chuỗi và sau đó mới được chèn vào.

<div class="example"></div>

```java
StringBuffer str = new StringBuffer("Java sion");
str.insert(1,’b’);
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>Biến "str" chứa chuỗi "Jbava sion"</code>
  </div>
</div>

- `char charAt()`: Phương thức này trả về một giá trị ký tự trong đối tượng StringBuffer tại vị trí được chỉ định.

<div class="example"></div>

```java
StringBuffer str = new StringBuffer("James Gosling");
char letter = str.charAt(6); //chứa "G"
```

- `void setCharAt(int index, char value)`: Phương thức này được sử dụng để thay thế ký tự trong một StringBuffer bằng một ký tự khác tại một vị trí được chỉ định.

<div class="example"></div>

```java
StringBuffer name = new StringBuffer("Jawa");
name.setCharAt(2,’v’);
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>Biến "name" chứa "Java".</code>
  </div>
</div>

- `void setLength()`: Phương thức này thiết lập chiều dài của đối tượng StringBuffer. Nếu chiều dài được chỉ định nhỏ hơn chiều dài dữ liệu hiện tại của nó, thì các ký tự thừa sẽ bị cắt bớt. Nếu chiểu dài chỉ định nhiều hơn chiều dài dữ liệu thì các ký tự null được thêm vào phần cuối của StringBuffer

<div class="example"></div>

```java
StringBuffer str = new StringBuffer(10);
str.setLength(str.length() + 10);
```

`char [] getChars()`: Phương thức này được sử dụng để trích ra các ký tự từ đối tượng StringBuffer, và sao chép chúng vào một mảng và có bốn tham số sau:

- Chỉ số đầu: vị trí bắt đầu, từ nơi mà ký tự được lấy ra.
- Chỉ số kết thúc: vị trí kết thúc
- Mảng: Mảng đích, nơi mà các ký tự được sao chép.
- Vị trí bắt đầu trong mảng đích: Các ký tự được sao chép vào mảng đích từ vị trí này.

<div class="example"></div>

```java
StringBuffer str = new StringBuffer("Leopard");
char ch[] = new char[10];
str.getChars(3,6,ch,0);
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>Bây giờ biến "ch" chứa "par"</code>
  </div>
</div>

- `void reverse()`: Phương thức này đảo ngược nội dung của một đối tượng StringBuffer, và trả về một đối tượng StringBuffer khác.

<div class="example"></div>

```java
StringBuffer str = new StringBuffer("devil");
StringBuffer strrev = str.reverse();
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>Biến "strrev" chứa "lived".</code>
  </div>
</div>
