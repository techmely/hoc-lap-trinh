---
title: "Output trong C"
description: "Output trong C"
keywords:
  ["học lập trình c", "khoá học lập trình c", "Khoá học lập trình c căn bản"]
chapter:
  name: "Giới thiệu"
  slug: "chuong-02-basic-concepts"
category:
  name: "C"
  slug: "c-core"
image: https://user-images.githubusercontent.com/29374426/127596066-fa46df01-982f-4a72-b6d1-f7d8f5c5a9b3.png
position: 3
---

Chúng ta đã được xem qua cách hiển thị một đoạn văn bản với hàm `printf()` ở những bài trước.

Trong ngôn ngữ lập trình C, hàm `printf()` được sử dụng để in ra các ký tự, chuỗi, các giá trị số nguyên, số thực hay số thập phân, bát phân... và hiển thị lên màn hình console.

Hôm nay chúng ta sẽ cùng tìm hiểu kỹ hơn về hàm `printf()`.

## Displays the string

In ra một chuỗi rất đơn giản trong C, bạn chỉ cần truyền chuỗi văn bản vào hàm `printf()` như ví dụ sau:

```c
#include <stdio.h>

int main() {

    printf ("I am student.");
}
```

_Lưu ý: chuỗi văn bản cần phải được nằm trong cặp dấu nháy kép `" "` để chương trình hiểu được đó là một chuỗi văn bản bình thường._

Kết quả:

```c
I am student.
```

Nếu bạn cần phải sử dụng các ký tự không thể gõ hoặc có ý nghĩa đặc biệt - hãy xem lại bài viết này [Escape Sequences](https://github.com/AnestLearning/Course-C-Fundamentals/blob/master/1.%20Introduction/4.%20Keywords%20&%20Escape%20Sequences.md).

## Displays the value of a variable

Bây giờ, chúng ta sẽ xem làm sao để hiển thị một giá trị của biến cũng với hàm này. Chúng ta cũng sẽ sử dụng `printf()` với phương pháp cũ, nhưng thêm vào một định dạng đặc biệt tại vị trí mà chúng ta muốn hiển thị giá trị của biến đó.

Vậy định dạng đặc biệt đó là gì?

- Chúng ta sử dụng hàm `printf()` với định dạng `%d` để hiển thị giá trị của biến kiểu số nguyên `int`.
- Tương tự, sử dụng `%c` để hiển thị giá trị của các biến kiểu ký tự, `%f` để hiển thị giá trị số thực và `%x` cho kiểu số ở hệ thập lục phân (hệ cơ số 16).

Vì vậy ứng với mỗi kiểu dữ liệu, chúng ta sẽ có ký tự đặc biệt của kiểu dữ liệu đó, dưới đây là bảng các kiểu dữ liệu thường dùng và định dạng của nó.

| Định dạng | Kiểu dữ liệu |
| --------- | ------------ |
| `%d`      | int          |
| `%ld`     | long         |
| `%f`      | float        |
| `%lf`     | double       |
| `%c`      | char         |

Chúng ta đã chỉ ra vị trí cần hiển thị một biến, nhưng chúng ta vẫn chưa nói là hiển thị giá trị của biến nào - biến tên là gì. Vì thể chúng ta cần chỉ cho hàm `printf()` biết phải hiển thị biến nào.

Hãy xem ví dụ sau:

```c
#include<stdio.h>

int main() {

    int age = 22;
    printf ("I am %d year old.", age); // giá trị của biến age sẽ được thay thế vào vị trí %d
}
```

Kết quả nhận được:

```c
I am 22 year old.
```

Chúng ta cũng xem tiếp một ví dụ khác:

```c
#include<stdio.h>

int main() {

    int age = 22;
    age = 25;

    printf ("I am %d year old.", age); // giá trị của biến age sẽ được thay thế vào vị trí %d
}
```

Kết quả nhận được:

```c
I am 25 year old.
```

Ở ví dụ này, tuy bạn đã khai báo và gán giá trị cho biến `age = 22` nhưng ngay dòng tiếp theo chúng ta lại gán lại `age = 25` - vì vậy lúc này giá trị của biến `age` sẽ bị ghi đè và mang giá trị mới.

## Format display the value of a variable

Nếu chúng ta thực hiện in ra giá trị một số thập phân, bạn sẽ thấy như sau:

```c
#include<stdio.h>

int main() {

    float a = 2.5;

    printf ("a = %f", a);
}
```

Kết quả nhận được:

```c
a = 2.500000
```

Vì `a` là một số thập phân nên khi hiển thị ra kết quả, chương trình sẽ hiển thị thêm 6 số sau dấu phẩy để người dùng hiểu được đó là số thập phân. Nhưng đôi lúc chúng ta lại nhận được yêu cầu chỉ hiển thị `2` hoặc `3` số sau dấu chấm động thôi. Ví dụ `a = 2.50` hay `a = 2.500`.

Vậy chúng ta sẽ làm như thế nào? Hãy xem qua ví dụ sau:

```c
#include<stdio.h>

int main() {

    float a = 2.5;

    printf ("a = %.2f\n", a); // hiện thị 2 số sau dấu phẩy
    printf ("a = %0.3f", a);  // hiện thị 3 số sau dấu phẩy
}
```

Kết quả nhận được:

```c
a = 2.50
a = 2.500
```

Các bạn có thấy chúng ta đã chỉnh sửa thêm gì không? đó là trong `%f` chúng ta viết thêm số lượng số thập phân mà chúng ta muốn hiển thị sau dấy phẩy `%.2f` hoặc `%0.3f`.

> Trong lập trình nếu một số thập phân bắt đầu bằng chữ số `0`, bạn có thể bỏ số `0` đi cho ngắn gọn, chúng ta có viết `0.2` bằng `.2`.

Chúng ta cũng có thể viết số lượng hiển thị mong muốn ở trước dấu phẩy để căn chỉnh hiển thị nhiều số cho dễ nhìn hơn.

Ví dụ:

```c
#include<stdio.h>

int main() {

    float a = 2.5;
    float b = 3.75;
    float c = 5.66;

    printf ("%8.2f", a);
    printf ("%8.2f", b);
    printf ("%8.2f", c);
}
```

Kết quả nhận được:

```c
    2.50    3.75    5.66
```

Lúc này tổng chiều dài hiển thì cho mỗi số là `8` ký tự (đã tính cả dấu `.` và `2` số sau dấu `.`). Xem hình minh hoạ để hiểu rõ hơn:

<p align="center">
  <img src="https://github.com/AnestLearning/Course-C-Fundamentals/blob/master/Images/format-display.jpg">
</p>

Đối với các kiểu dữ liệu khác, bạn cũng sẽ làm tương tự như ví dụ trên.

Ví dụ:

- `%5d`
- `%5.2lf`
- `%3c`
