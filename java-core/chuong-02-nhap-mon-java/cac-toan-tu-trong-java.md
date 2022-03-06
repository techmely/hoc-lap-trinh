---
title: "Các toán tử trong Java"
description: "Toán tử trong java là một ký hiệu được sử dụng để thực hiện một phép tính hoặc chức năng nào đó. Bài này chúng ta sẽ cùng nhau tìm hiểu về một số phép toán kiểu dữ liệu nguyên thủy nhé"
keywords:
  [
    "toán tử trong java",
    "toan tu trong java",
    "toán tử tăng giảm",
    "toan tu trong java",
    "toán tử java",
    "các toán tử bit trong java",
    "các toán tử trong java",
    "cách nạp chồng toán tử trong java",
    "hàm toán tử trong java",
    "thứ tự ưu tiên toán tử trong java",
    "toán tử 2 ngôi trong java",
    "toán tử 3 ngôi trong java",
    "toán tử and trong java",
    "toán tử bit trong java",
    "toán tử bình phương trong java",
    "toán tử chia hết trong java",
    "toán tử chia lấy dư trong java",
    "toán tử gán trong java",
    "phép chia trong java",
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
image: https://user-images.githubusercontent.com/29374426/126589001-77ef8e76-3d2d-4194-9a0f-c662485056a2.png
position: 13
---

Trong Java có cung cấp nhiều toán tử để thao tác các biến. Trong bài viết này chúng ta sẽ cùng nhau tìm hiểu về các Toán tử trong Java.

## Phép gán

Cú pháp:

```java
[Biến] = [BiểuThức];
```

Phép gán được thực hiện bằng toán tử `=`, nó có nghĩa là **hãy tính toán giá trị biểu thức bên phải dấu gán, sau đó đưa giá trị đó vào ô nhớ có tên nằm ở bên trái dấu gán**

![cac-toan-tu-trong-java](https://user-images.githubusercontent.com/29374426/126589001-77ef8e76-3d2d-4194-9a0f-c662485056a2.png)

<div class="note">
  <ul>
    <li>Câu lệnh gán gồm một dấu `=`</li>
    <li>Kiểu của biểu thức bên phải dấu gán phải tương thích với kiểu dữ liệu của biến</li>
    <li>Trong java ta có thể thực hiện một dẫy gán.</li>
  </ul>
</div>

<div class="example"></div>

```java
int a = 10;
int b = c = 10;// cả b và c đều có giá trị 10
```

## Toán tử toán học

Ngôn ngữ java cũng có các phép toán số học được sử dụng trong các biểu thức toán học như trong đại số: `+` (**phép cộng**), `-` (**phép trừ**), `*` (**phép nhân**), `/` (**phép chia**), `%` (**phép toán chia lấy phần nguyên**)

Ta mô tả tóm tắt các phép toán số học qua bảng tổng kết sau:

| Phép toán | Sử dụng    | Mô tả                                  |
| --------- | ---------- | -------------------------------------- |
| +         | op1 + op2  | Cộng op1 vớiop2                        |
| -         | op1 - op2  | Trừ op1 cho op2                        |
| \*        | op1 \* op2 | Nhân op1 với op2                       |
| /         | op1/ op2   | chia op1 cho op2                       |
| %         | op1 % op2  | Tính phần dư của phép chia op1 cho op2 |

## Toán tử tăng, giảm

Java cũng có phép toán tăng, giảm, ta có thể mô tả tóm tắt qua các bằng sau:

| Phép toán | Sử dụng | Mô tả |
| --- | --- | --- |
| ++ | op++ | Tăng op lên 1 đơn vị, giá trị của op được tăng lên trước khi biểu thức chứa nó được tính |
| ++ | ++op | Tăng op lên 1 đơn vị, giá trị của op được tăng lên sau khi biểu thức chứa nó được tính |
| -- | op-- | Giảm op xuống1 đơn vị, giá trị của op được giảm xuống trước khi biểu thức chứa nó được tính |
| -- | --op | Giảm op xuống1 đơn vị, giá trị của op được giảm xuống sau khi biểu thức chứa nó được tính |

Qua đây chúng ta cũng hiểu được sự khác nhau của a++ (a--) và ++a (--a)

<div class="example"></div>

```java
public class Thaycacac {
  public static void main(String[] args) {
    int a = 1;
    //In rồi mới tăng
    System.out.println(a++);
    //Tăng rồi mới in
    System.out.println(++a);
    //Cộng 1 và in ra rồi mới tăng
    System.out.println(a+++1);
    //Tăng rồi mới cộng 1 và in ra
    System.out.println(++a+1);
  }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>1</code><br/>
    <code>3</code><br/>
    <code>4</code><br/>
    <code>6</code>
  </div>
</div>

<div class="note">
  Nếu toán tử tăng trước, tăng sau (giảm trước, giảm sau) đứng một mình (không nằm trong biểu thức) thì chúng hoạt động như nhau, chúng chỉ khác nhau khi chúng nằm trong biểu thức
</div>

## Phép toán quan hệ

Phép toán quan hệ bao giờ cũng cho kết quả boolean, phép toán quan hệ sẽ so sánh 2 giá trị, nó xác định mối quan hệ giữa chúng, ví dụ `!=` sẽ trả về true nếu 2 toán hạng là khác nhau.

Ta tóm tắt các phép toán qua bảng sau:

| Phép toán | Sử dụng    | Nhận về giá trị true khi  |
| --------- | ---------- | ------------------------- |
| >         | op1 > op2  | op1 lớn hơn op2           |
| >=        | op1 >= op2 | op1 lớn hơn hoặc bằng op2 |
| <         | op1 < op2  | op1 nhỏ hơn op2           |
| <=        | op1 <= op2 | op1 nhỏ hơn hoặc bằng op2 |
| ==        | op1 == op2 | op1 bằng op2              |
| !=        | op1! = op2 | op1 khác op2              |

Ví dụ sử dụng các phép toán quan hệ

```java
public class Thaycacac {
    public static void main(String[] args) {
        int i = 37;
        int j = 42;
        int k = 42;
        System.out.println("Hiển thị các số...");
        System.out.println(" i = " + i);
        System.out.println(" j = " + j);
        System.out.println(" k = " + k);

        // kiểm tra lớn hơn
        System.out.println("Kiểm tra lớn hơn...");
        System.out.println(" i > j = " + (i > j)); // false
        System.out.println(" j > i = " + (j > i)); // true
        System.out.println(" k > j = " + (k > j)); // false, they are equal

        // kiểm tra lớn hơn hoặc bằng
        System.out.println("Kiểm tra lớn hơn hoặc bằng...");
        System.out.println(" i >= j = " + (i >= j)); // false
        System.out.println(" j >= i = " + (j >= i));
        System.out.println(" k >= j = " + (k >= j)); // true

        // kiểm tra nhỏ hơn
        System.out.println("Kiểm tra nhỏ hơn...");
        System.out.println(" i < j = " + (i < j)); // true
        System.out.println(" j < i = " + (j < i)); // false
        System.out.println(" k < j = " + (k < j)); // false

        // kiểm tra nhỏ hơn hoặc bằng
        System.out.println("Kiểm tra nhỏ hơn hoặc bằng...");
        System.out.println(" i <= j = " + (i <= j)); // true
        System.out.println(" j <= i = " + (j <= i)); // false
        System.out.println(" k <= j = " + (k <= j)); // true

        // kiểm tra bằng
        System.out.println("Kiểm tra bằng...");
        System.out.println(" i == j = " + (i == j)); // false
        System.out.println(" k == j = " + (k == j)); // true

        // kiểm tra không bằng
        System.out.println("Kiểm tra không bằng...");
        System.out.println(" i! = j = " + (i != j)); // true
        System.out.println(" k! = j = " + (k != j)); // false
    }
}

```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>Hiển thị các số...</code><br/>
    <code>i = 37</code><br/>
    <code>j = 42</code><br/>
    <code>k = 42</code><br/>
    <code>Kiểm tra lớn hơn...</code><br/>
    <code>i > j = false</code><br/>
    <code>j > i = true</code><br/>
    <code>k > j = false</code><br/>
    <code>Kiểm tra lớn hơn hoặc bằng...</code><br/>
    <code>i >= j = false</code><br/>
    <code>j >= i = true</code><br/>
    <code>k >= j = true</code><br/>
    <code>Kiểm tra nhỏ hơn...</code><br/>
    <code>i < j = true</code><br/>
    <code>j < i = false</code><br/>
    <code>k < j = false</code><br/>
    <code>Kiểm tra nhỏ hơn hoặc bằng...</code><br/>
    <code>i <= j = true</code><br/>
    <code>j <= i = false</code><br/>
    <code>k <= j = true</code><br/>
    <code>Kiểm tra bằng...</code><br/>
    <code>i == j = false</code><br/>
    <code>k == j = true</code><br/>
    <code>Kiểm tra không bằng...</code><br/>
    <code>i! = j = true</code><br/>
    <code>k! = j = false</code>
  </div>
</div>

## Phép toán logic

Java hỗ trợ 6 phép toán logic được chỉ ra trong bảng sau:

| Phép toán | Sử dụng | Nhận về giá trị true khi |
| --- | --- | --- |
| && | op1 && op2 | Cả op1 và op2 đều là true, giá trị của op2 chỉ được tính khi op1 là true |
| \|\| | op1 \|\| op2 | Hoặc op1 hoặc op2 là true, giá trị của op2 chỉ được tính khi op1 là false |
| ! | !op | op là false |
| & | op1 & op2 | Cả op1 và op2 đều là true, giá trị của op2 luôn được tính kể cả khi op1 là false |
| \| | op1 \| op2 | Hoặc op1 hoặc op2 là true, giá trị của op2 luôn luôn được tính kể cả khi op1 là true |
| ^ | op1 ^ op2 | Nếu op1 khác op2 |

<div class="note">
  <ul>
    <li>Phép toán && ( & ) chỉ nhận giá trị true khi và chỉ khi cả hai toán hạng đều là true</li>
    <li>Phép toán || ( | ) chỉ nhận giá trị false khi và chỉ khi cả hai toán hạng là false</li>
    <li>Phép toán ^ chỉ nhận giá trị true khi và chỉ khi hai toán hạng khác nhau</li>
  </ul>
</div>

## Phép toán thao tác trên bit

### Phép toán dịch bit

| Phép toán | Sử dụng | Kết quả |
| --- | --- | --- |
| >> | op1 >> op2 | Dịch chuyển op1 sang phải op2 bit, op2 bit phía bên phải sẽ được điền bằng các bít 0 |
| << | op1 << op2 | Dịch chuyển op1 sang trái op2 bit(giữ nguyên dấu của op1), op2 bit nằm bên trái sẽ được điền bằng các bít 0 |
| >>> | op1>>> op2 | Dịch chuyển op1 sang phải op2 bit, op2 bit |

Sau đây là hình minh hoạ phép toán dịch bít

![cac-toan-tu-trong-java](https://user-images.githubusercontent.com/29374426/124595107-cfe9ef00-de8a-11eb-8ccf-23c93c4d8f5d.png)

- `13>>1=6` vì `13=11012` do vậy khi dịch phải một bit ta sẽ được `1102=6`
- `5<<1=10` vì `5=1012` do vậy khi dịch trái 1 bit ta sẽ được `10102=10`
- `5<<2=100` vì `5=1012` do vậy khi dịch trái 2 bit ta sẽ được `101002=100`

<div class="note">
  Phép toán dịch trái một bit chính là phép nhân với 2, còn dịch phải chính là phép chia cho 2
</div>

### Phép toán logic trên bit

Các phép toán thao tác bit cho phép ta thao tác trên từng bit riêng lẻ trong một kiểu dữ liệu thích hợp, các phép toán thao tác bit thực hiện đại số boolean trên các bit tương ứng của 2 toán hạng để tạo ra kết quả.

Ta tóm tắt các phép toán trong bảng sau:

| Phép toán | Sử dụng | Thực hiện |
| --- | --- | --- |
| & | op1 & op2 | Thực hiện phép and các bit tương ứng của op1 với op2 |
| \| | op1 \| op2 | Thực hiện phép or các bit tương ứng của op1 với op2 |
| ^ | op1 ^ op2 | Thực hiện phép xor các bit tương ứng của op1 với op2 |
| ~ | ~op2 | Thực hiện phép lật các bit của op2 |

Bảng giá trị chân lý của các phép toán đái số boolean:

**Phép AND**

| op1 | op2 | Result |
| :-- | :-- | :----- |
| 0   | 0   | 0      |
| 0   | 1   | 0      |
| 1   | 0   | 0      |
| 1   | 1   | 1      |

**Phép OR**

| op1 | op2 | Result |
| :-- | :-- | :----- |
| 0   | 0   | 0      |
| 0   | 1   | 1      |
| 1   | 0   | 1      |
| 1   | 1   | 1      |

**Phép XOR**

| op1 | op2 | Result |
| :-- | :-- | :----- |
| 0   | 0   | 0      |
| 0   | 1   | 1      |
| 1   | 0   | 1      |
| 1   | 1   | 0      |

**Phép NOT**

| op1 | Result |
| :-- | :----- |
| 0   | 1      |
| 1   | 0      |

## Toán tử gán tắt

Ngoài ra Java cũng có toán tử gán tắt, ta tóm tắt các toán tử gán qua bảng sau:

| Phép gán | Sử dụng      | Tương đương       |
| -------- | ------------ | ----------------- |
| +=       | op1 += op2   | op1 = op1 + op2   |
| -=       | op1 -= op2   | op1 = op1 - op2   |
| \*=      | op1 \*= op2  | op1 = op1 \* op2  |
| /=       | op1/ = op2   | op1 = op1/ op2    |
| %=       | op1 %= op2   | op1 = op1 % op2   |
| &=       | op1 &= op2   | op1 = op1 & op2   |
| \|=      | op1 \|= op2  | op1 = op1 \| op2  |
| ^=       | op1 ^= op2   | op1 = op1 ^ op2   |
| <<=      | op1 <<= op2  | op1 = op1 << op2  |
| >>=      | op1 >>= op2  | op1 = op1 >> op2  |
| >>>=     | op1 >>>= op2 | op1 = op1 >>> op2 |

## Thứ tự ưu tiên của các phép toán

Thứ tự ưu tiên của các phép toán xác định trình tự tính toán giá trị của một biểu thức, java có những quy tắc riêng để xác định trình tự tính toán của biểu thức, ta phải nhớ quy tắc sau:

- Các phép toán một ngôi bao giờ cũng được thực hiện trước tiên
- Trong một biểu thức có nhiều phép toán thì phép toán nào có độ ưu tiên cao hơn sẽ được thực hiện trước phép toán có độ ưu tiên thấp
- Trong một biểu thức có nhiều phép toán có độ ưu tiên ngang nhau thì chúng sẽ được tính theo trình tự từ trái qua phải

Ta có bảng tóm tắt thứ tự ưu tiên của các phép toán trong bảng sau:

| Kiểu                 | Thứ tự ưu tiên                           |
| -------------------- | ---------------------------------------- |
| postfix operators    | []. (params) expr++ expr--               |
| unary operators      | ++expr --expr +expr -expr ~!             |
| creation or cast     | new (type)expr                           |
| multiplicative       | \_/ %                                    |
| additive             | + -                                      |
| shift                | << >> >>>                                |
| relational           | < > <= >= instanceof                     |
| equality             | ==! =                                    |
| Bitwise AND          | &                                        |
| Bitwise exclusive OR | ^                                        |
| Bitwise inclusive OR | \|                                       |
| Logical AND          | &&                                       |
| Logical OR           | \|\|                                     |
| Conditional          | ?:                                       |
| Assignment           | = += -= \_=/ = %= &= ^= \|= <<= >>= >>>= |

Trong bảng trên thứ tự ưu tiên của các phép toán được giảm từ trên xuống dưới, trên cùng một hàng thì chúng có độ ưu tiên ngang nhau.
