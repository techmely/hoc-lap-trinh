---
title: "Vòng lặp for trong java"
description: "Vòng lặp for trong java thường được sử dụng trong trường hợp biết trước số lần lặp, trong bài này chúng ta sẽ cùng nhau tìm hiểu về vòng lặp for trong Java nhé"
keywords:
  [
    "bài tập vòng lặp for trong java",
    "câu lệnh for trong java",
    "hàm for trong java",
    "lệnh for trong java",
    "vòng lặp for cải tiến trong java",
    "vòng lặp for each",
    "vòng lặp for each trong java",
    "vòng lặp for java",
    "vòng lặp for trong java",
    "vòng lặp for trong java developer",
  ]
chapter:
  name: "Nhập môn Java"
  slug: "chuong-02-nhap-mon-java"
category:
  name: "Java"
  slug: "java"
image: https://user-images.githubusercontent.com/29374426/127631954-6589402a-aaab-4df9-b37b-ddebb90db820.png
position: 20
---

Khi chúng ta cần thực hiện một đoạn code một vài lần, điều này có thể được xem như một vòng lặp.

Java có 3 kỹ thuật lặp linh động, bạn có thể sử dụng một trong ba vòng lặp sau:

- Vòng lặp `for`
- Vòng lặp `while`
- Vòng lặp `do…while`

Vòng lặp `for` trong java thường được sử dụng trong trường hợp biết trước số lần lặp, còn nếu số lần lặp không cố định thì nên sử dụng vòng lặp `while` hoặc do `while`. Trong bài này chúng ta sẽ cùng nhau tìm hiểu về vòng lặp for trong Java nhé.

## Cấu trúc vòng lặp for

Đây là cấu trúc lặp phổ biến nhất trong các ngôn ngữ lập trình, mà nội dung cuả vòng lặp cần phải lặp đi lặp lại một số lần biết trước, cú pháp của nó như sau:

```java
for (<Khởi tạo biến chạy>; <Biểu thức điều kiện>; <Thay đổi biến chạy>) {
  <Khối lệnh lặp lại>
}
```

Trong đó:

- **Khởi tạo biến chạy**: là giá trị khởi tạo trước khi vòng lặp bắt đầu, nó chỉ được thực hiện duy nhất một lân trước khi vòng lặp bắt đầu.
- **Biểu thức điều kiện**: là điều kiện dùng để kết thúc quá trình lặp
- **Thay đổi biến chạy**: là câu lệnh dùng để điều khiển quá trình lặp, thay đổi biến chạy
- **Khối lệnh lặp lại** là câu lệnh mà ta cần phải thực hiện lặp đi lặp lại.

Sơ đồ khối diễn giải sự hoạt động của cấu trúc for sau:

- **Bước 1:** Thực hiện <Khởi tạo biến chạy>
- **Bước 2:** Kiểm tra <Biểu thức điều kiện> nếu biểu thức đúng thì thực hiện <Khối lệnh lặp lại> . Nếu sai thì qua Bước 4
- **Bước 3:** Thực hiện <Thay đổi biến chạy>, quay lại Bước 2
- **Bước 4:** Kết thúc vòng lặp

![vong-lap-for-trong-java](https://user-images.githubusercontent.com/29374426/127631954-6589402a-aaab-4df9-b37b-ddebb90db820.png)

<content-info>
  <ul>
    <li>Nếu ta khai báo biến chạy trong Biểu thức khởi tạo vòng lặp thì sau khi kết thúc, biến chạy tự giải phóng</li>
    <li>Thân của cấu trúc lặp for ta chỉ có thể đặt được duy nhất một lệnh, do vậy để có thể thực hiện nhiều tác vụ trong thân for ta phải bao chúng trong khối lệnh</li>
    <li>Thân vòng lặp for có thể không được thực hiện lần nào</li>
    <li>Các phần Khởi tạo biến chạy, Biểu thức điều kiện, Thay đổi biến chạy có thể khuyết tuy nhiên dấy phẩy dành cho nó vẫn phải có</li>
    <li>Số lần thực hiện Khởi tạo biến chạy là 1 lần</li>
    <li>Số lần thực hiện Biểu thức điều kiện bằng số lần lặp + 1</li>
    <li>Số lần thực hiện Biểu thức điều kiện bằng số lần lặp</li>
    <li>Ta có thể đặt một vài khai báo biến trong phần Khởi tạo biến chạy</li>
    <li>Ta có thể mô tả cấu trúc while thông qua cấu trúc for như sau for(; Biểu thức boolean;) statement;</li>
  </ul>
</content-info>

<div class="example"> in ra màn hình các số nguyên nhỏ hơn 11</div>

```java
public class Thaycacac {
  public static void main(String[] args) {
    for(int i = 0; i < 11; i++) {
      System.out.println(i);
    }
  }
}
```

![vong-lap-for-trong-java](https://user-images.githubusercontent.com/29374426/127634450-1c6f052c-39b2-424c-9030-e3d9a5ae49a0.png)

<div class="example"> viết chương trình in ra các số lẻ trong khoảng 1 đến 10</div>

```java
public class Thaycacac {
  public static void main(String[] args) {
    for(int i = 1; i <= 10; i += 2){
      System.out.println(i);
    }
  }
}
```

<div class="example"> toán tử đẫy</div>

```java
public class CommaOperator {
  public static void main(String[] args) {
    for(int i = 1, j = i + 10; i < 5; i++, j = i * 2) {
      System.out.println("i= " + i + " j= " + j);
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
    <code>i= 1 j= 11</code><br/>
    <code>i= 2 j= 4</code><br/>
    <code>i= 3 j= 6</code><br/>
    <code>i= 4 j= 8</code>
  </div>
</div>

## Vòng lặp for cải tiến

Vòng lặp for cải tiến được sử dụng để lặp mảng (`array`) hoặc `collection` trong java. Bạn có thể sử dụng nó dễ dàng, dễ hơn cả vòng lặp for đơn giản. Bởi vì bạn không cần phải tăng hay giảm giá trị của biến rồi kiểm tra điều kiện, bạn chỉ cần sử dụng ký hiệu hai chấm `:`

**Cú pháp:**

```java
for (<Kiểu tập hợp> var : <Tập hợp>) {
  <Khối lệnh lặp lại>
}
```

**Trong đó:**

- **Kiểu tập hợp**: là kiểu dữ liệu của tập hợp có thể là kiểu dữ liệu hoặc các kiểu object
- **Tập hợp**: là danh sách tập hợp có thể là mảng thông thường, ArrayList, LinkedList, HashSet, ...
- **Khối lệnh lặp lại** là câu lệnh mà ta cần phải thực hiện lặp đi lặp lại.

<content-example />

```java
public class Thaycacac {
  public static void main(String[] args){
    int[] arr = {1, 2, 3, 4, 5};
    for (int i : arr) {
      System.out.println(i);
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
    <code>1</code><br/>
    <code>2</code><br/>
    <code>3</code><br/>
    <code>4</code><br/>
    <code>5</code>
  </div>
</div>

## Vòng lặp for gán nhãn

Chúng ta có để đặt tên cho mỗi vòng lặp for bằng cách gán nhãn trước vòng lặp for. Điều này rất hữu dụng khi chúng ta muốn thoát/tiếp tục(break/continues) chạy vòng lặp for.

Cú pháp:

```java
<Tên nhãn>: for (<Khởi tạo biến chạy>; <Biểu thức điều kiện>; <Thay đổi biến chạy>) {
  <Khối lệnh lặp lại>
}
```

<content-example />

```java
public class Thaycacac {
  public static void main(String[] args) {
    aa: for (int i = 1; i <= 3; i++) {
      bb: for (int j = 1; j <= 3; j++) {
        if (i == 2 && j == 2) {
          break aa;
        }
        System.out.println(i + " " + j);
      }
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
    <code>1 1</code><br/>
    <code>1 2</code><br/>
    <code>1 3</code><br/>
    <code>2 1</code>
  </div>
</div>
