---
title: "Vòng lặp do while trong C"
description: "Vòng lặp 'do-while' như một người anh em với vòng lặp while vậy. Chúng đều là một công cụ mạnh mẽ cho việc lặp lại một dãy lệnh dựa trên điều kiện. Nhưng do-while sẽ có điểm khác biệt gì so với while, hãy cùng tìm hiểu nó trong bài học hôm nay nào."
chapter:
  name: "Vòng lặp"
  slug: "chuong-04-loops"
image: https://user-images.githubusercontent.com/29374426/127596066-fa46df01-982f-4a72-b6d1-f7d8f5c5a9b3.png
position: 3
---

Vòng lặp **`do-while`** cũng gần giống như vòng lặp **`while`** nhưng sự khác biệt chính giữa vòng lặp **`do-while`** và vòng lặp **`while`** là trong vòng lặp **`do-while`**, điều kiện được kiểm tra ở cuối thân vòng lặp. Khối câu lệnh bên trong vòng lặp sẽ được thực hiện 1 hoặc nhiều lần cho đến khi kiểm tra điều kiện trả về bằng false thì sẽ kết thúc vòng lặp.

**_Trong vòng lặp do-while, thân vòng lặp sẽ thực thi ít nhất một lần rồi mới kiểm tra điều kiện._**

Sử dụng **`do-while`** khi bạn không biết rõ số lượng vòng lặp - chỉ biết điều kiện dừng.

## Cấu trúc của vòng lặp do-while

```cpp
do {

   // statements inside the body of the loop
} while (testExpression);
```

Ví dụ:

```cpp
int n = 1234;

do {

   // statements inside the body of the loop
   // need to update the value of n
} while (n > 0);
```

## Vòng lặp do-while hoạt động như thế nào

- Đầu tiên khối câu lệnh bên trong vòng lặp **`do-while`** sẽ được chạy một lần rồi mới đến đánh giá biểu thức kiểm tra điều kiện bên trong ngoặc đơn `()`.
- Nếu biểu thức kiểm tra là **`true`**, các câu lệnh bên trong thân vòng lặp **`do-while`** được thực thi tiếp. Các câu lệnh thực thi bên trong thân vòng lặp cần phải cập nhật lại biểu thức kiểm tra điều kiện.
- Sau đó, biểu thức kiểm tra được đánh giá lại.
- Quá trình diễn ra cho đến khi biểu thức kiểm tra được đánh giá là **`false`**.
- Nếu biểu thức kiểm tra là **`false`**, vòng lặp chấm dứt (kết thúc).

## Luồng hoạt động của vòng lặp do-while

![Luồng hoạt động của vòng lặp do-while](https://user-images.githubusercontent.com/29374426/183098360-68d525b2-fcb1-41b7-8ef1-35b333729efa.png)

## Ví dụ về vòng lặp do-while

Ví dụ:

> Tính tổng các số nguyên dương cho đến khi nhập vào một số bằng `0` hoặc một số âm thì dừng lại (không cộng số âm này vào tổng).

```cpp
#include <stdio.h>

int main() {

    int number;
    int sum = 0;

    do {
        printf("Enter a number: ");
        scanf("%d", &number);

        if (number > 0) {
            sum += number;
        }
    } while (number > 0);

    printf("\nSum = %d",sum);
}
```

::result
Enter a number: 5</br>
Enter a number: 4</br>
Enter a number: 6</br>
Enter a number: 2</br>
Enter a number: -2</br>

Sum = 17
::

- Bài này nói rõ điều kiện dừng là `n > 0`, nhưng chúng ta sẽ không thể biết được người dùng sẽ nhập bao nhiêu số để tính tổng nên sẽ cần dùng vòng lặp.
- `n` lại do người dùng nhập từ bàn phím, chúng ta sẽ không thể biết được lần đầu tiên người dùng sẽ nhập số gì? Vì vậy chúng ta sử dụng **`do-while`** để code bên trong thân vòng lặp được chạy một lần để chúng ta lấy được giá trị của `n` rồi mới kiểm tra được điều kiện.
