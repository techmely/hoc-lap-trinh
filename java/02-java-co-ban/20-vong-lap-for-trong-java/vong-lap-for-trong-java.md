---
title: "Vòng lặp for trong java"
description: "Vòng lặp for trong java thường được sử dụng trong trường hợp biết trước số lần lặp, trong bài này chúng ta sẽ cùng nhau tìm hiểu về vòng lặp for trong Java nhé"
chapter:
  name: "Nhập môn Java"
  slug: "chuong-02-nhap-mon-java"
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

![Vòng lặp for trong java](https://user-images.githubusercontent.com/29374426/127631954-6589402a-aaab-4df9-b37b-ddebb90db820.png)

::alert{type="infor"}

- Nếu ta khai báo biến chạy trong Biểu thức khởi tạo vòng lặp thì sau khi kết thúc, biến chạy tự giải phóng
- Thân của cấu trúc lặp for ta chỉ có thể đặt được duy nhất một lệnh, do vậy để có thể thực hiện nhiều tác vụ trong thân for ta phải bao chúng trong khối lệnh
- Thân vòng lặp for có thể không được thực hiện lần nào
- Các phần Khởi tạo biến chạy, Biểu thức điều kiện, Thay đổi biến chạy có thể khuyết tuy nhiên dấy phẩy dành cho nó vẫn phải có
- Số lần thực hiện Khởi tạo biến chạy là 1 lần
- Số lần thực hiện Biểu thức điều kiện bằng số lần lặp + 1
- Số lần thực hiện Biểu thức điều kiện bằng số lần lặp
- Ta có thể đặt một vài khai báo biến trong phần Khởi tạo biến chạy
- Ta có thể mô tả cấu trúc while thông qua cấu trúc for như sau for(; Biểu thức boolean;) statement;

::

Ví dụ: in ra màn hình các số nguyên nhỏ hơn 11

```java
public class Thaycacac {
  public static void main(String[] args) {
    for(int i = 0; i < 11; i++) {
      System.out.println(i);
    }
  }
}
```

![Vòng lặp for trong java](https://user-images.githubusercontent.com/29374426/127634450-1c6f052c-39b2-424c-9030-e3d9a5ae49a0.png)

Ví dụ: viết chương trình in ra các số lẻ trong khoảng 1 đến 10

```java
public class Thaycacac {
  public static void main(String[] args) {
    for(int i = 1; i <= 10; i += 2){
      System.out.println(i);
    }
  }
}
```

Ví dụ: toán tử đẫy

```java
public class CommaOperator {
  public static void main(String[] args) {
    for(int i = 1, j = i + 10; i < 5; i++, j = i * 2) {
      System.out.println("i= " + i + " j= " + j);
    }
  }
}
```

::result

- i= 1 j= 11<br/>
- i= 2 j= 4<br/>
- i= 3 j= 6<br/>
- i= 4 j= 8

::

## Vòng lặp `for` cải tiến

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

::result

1<br/>
2<br/>
3<br/>
4<br/>
5

::

## Vòng lặp for gán nhãn

Chúng ta có để đặt tên cho mỗi vòng lặp for bằng cách gán nhãn trước vòng lặp for. Điều này rất hữu dụng khi chúng ta muốn thoát/tiếp tục(break/continues) chạy vòng lặp for.

Cú pháp:

```java
<Tên nhãn>: for (<Khởi tạo biến chạy>; <Biểu thức điều kiện>; <Thay đổi biến chạy>) {
  <Khối lệnh lặp lại>
}
```

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

::result

1 1<br/>
1 2<br/>
1 3<br/>
2 1

::
