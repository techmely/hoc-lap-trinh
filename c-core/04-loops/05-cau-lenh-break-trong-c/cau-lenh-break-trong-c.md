---
title: "Câu lệnh break trong C"
description: "Câu lệnh break trong C"
keywords:
  ["học lập trình c", "khoá học lập trình c", "Khoá học lập trình c căn bản"]
chapter:
  name: "Vòng lặp"
  slug: "chuong-04-loops"
category:
  name: "C"
  slug: "c"
image: https://user-images.githubusercontent.com/29374426/127596066-fa46df01-982f-4a72-b6d1-f7d8f5c5a9b3.png
position: 5
---

Câu lệnh **`break`** trong C là một câu lệnh điều khiển vòng lặp được sử dụng để chấm dứt vòng lặp. Ngay khi gặp câu lệnh **`break`** từ bên trong một vòng lặp, các vòng lặp sẽ dừng ngay ở đó và chương trình sẽ tiếp tục chạy đến câu lệnh tiếp theo sau vòng lặp.

Về cơ bản các câu lệnh **`break`** thường được sử dụng trong các tình huống khi chúng ta không chắc chắn về số lần lặp thực tế cho vòng lặp hoặc chúng ta muốn chấm dứt vòng lặp dựa trên một số điều kiện.

## Cú pháp câu lệnh break trong C

```c
break;
```

Câu lệnh **`break`** thường được sử dụng với câu lệnh **`if-else`** bên trong vòng lặp.

## Cách câu lệnh break hoạt động trong C

### Vòng lặp for trong C

<p align="center">
  <img src="https://github.com/AnestLearning/Course-C-Fundamentals/blob/master/Images/c-break-statement-works-1.jpg">
</p>

### Vòng lặp do-while trong C

<p align="center">
  <img src="https://github.com/AnestLearning/Course-C-Fundamentals/blob/master/Images/c-break-statement-works-2.jpg">
</p>

### Vòng lặp while trong C

<p align="center">
  <img src="https://github.com/AnestLearning/Course-C-Fundamentals/blob/master/Images/c-break-statement-works-3.jpg">
</p>

## Luồng hoạt động câu lệnh break trong C

<p align="center">
  <img src="https://github.com/AnestLearning/Course-C-Fundamentals/blob/master/Images/c-break-statement-flowchart.jpg">
</p>

## Ví dụ về câu lệnh break trong C

Chúng ta sẽ cùng xem qua cách sử dụng lệnh **`break`** với ba loại vòng lặp:

- Vòng lặp đơn giản - Simple loops
- Vòng lặp lồng nhau - Nested loops
- Vòng lặp vô hạn - Infinite loops

Bây giờ chúng ta sẽ đi xem xét chi tiết các ví dụ cho từng loại trong ba loại vòng lặp trên.

### Một cấu trúc lặp đơn giản

Ví dụ:

> Chương trình tính tổng tối đa 10 số. Nếu nhập vào một số âm, vòng lặp chấm dứt và tính tổng các số được nhập vào trước đó.

```c
# include <stdio.h>

int main() {

    double n, sum = 0;

    for (int i = 1; i <= 10; ++i) {

        printf("Enter a n%d: ",i);
        scanf("%lf", &n);

        // If the user enters a negative number, the loop ends
        if(n < 0) {
            break;
        }

        sum += n;
    }

    printf("\nsum = %.2lf", sum);
}
```

Kết quả chương trình:

```c
Enter a n1: 4
Enter a n2: 5
Enter a n3: 8
Enter a n4: -2

sum = 17.00
```

Chương trình này tính tổng của tối đa 10 số. Nhưng vì sao mới nhập 3 số dương và 1 số âm nó đã dừng lại và tính tổng? Đó là bởi vì nếu người dùng nhập số âm, câu lệnh **`break`** được thực thi. Điều này sẽ kết thúc vòng lặp **`for`**, tổng được tính và hiển thị.

### Sử dụng break trong trường hợp vòng lặp lồng nhau

Chúng ta cũng có thể sử dụng lệnh **`break`** trong khi làm việc với các vòng lặp lồng nhau. Nếu câu lệnh **`break`** được sử dụng trong vòng lặp nào, nó sẽ chỉ chấm dứt vòng lặp đó.

Ví dụ:

> In ra hình chữ nhật

```c
# include <stdio.h>

int main() {

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 6; j++) {
            printf("* ");
        }
        printf("\n");
    }
}
```

Kết quả chương trình:

```c
* * * * * *
* * * * * *
* * * * * *
```

Chúng ta có thể thấy vòng **`for i`** (**`for`** bên ngoài) sẽ chạy 3 lần (từ `0` → `2`). Vòng **`for j`** (**`for`** bên trong) sẽ chạy 6 lần (từ `0` → `5`).

Bây giờ chúng ta muốn vòng **`for j`** chỉ chạy 3 lần để **In ra hình vuông**, chúng ta sẽ kiểm tra điều kiện cho **`j`** và **`break`** như sau:

```c
# include <stdio.h>

int main() {

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 6; j++) {
            if (j > 2) {
                break;
            } else {
                printf("* ");
            }
        }
        printf("\n");
    }
}
```

Kết quả chương trình:

```c
* * *
* * *
* * *
```

Bạn có thể thấy vòng **`for i`** vẫn chạy 3 lần, **`break`** chỉ kết thúc vòng **`for j`**, nơi nó được viết mã khi thoã màn câu lệnh **`if-else`**.

### Sử dụng câu lệnh break cho vòng lặp vô tận

Hãy xem xét vòng lặp vô hạn dưới đây:

```c
#include <stdio.h>

int main() {

    int i = 0;

    while (1) {
        printf("%d\n", i);
        i++;
    }
}
```

_Lưu ý : Không chạy chương trình trên vì đây là một vòng lặp vô hạn, nó sẽ chạy mãi không dừng - bạn chỉ có thể dừng nó bằng cách tắt cửa sổ terminal đi._

Trong chương trình trên, điều kiện trong vòng lặp là `1` - có nghĩa là luôn luôn đúng. Vì vậy, vòng lặp thực hiện vô số lần hay còn gọi là vòng lặp vô hạn. Chúng ta có thể sửa lỗi này bằng cách sử dụng câu lệnh **`break`** như sau:

```c
#include <stdio.h>

int main() {

    int i = 0;

    while (1) {
      if(i > 5) {
            break;
        }

        printf("%d\n", i);
        i++;
    }
}
```

Kết quả chương trình:

```c
0
1
2
3
4
5
```

Ngoài ra, bạn cũng có thể thấy **`break`** được sử dụng trong các câu lệnh **`Switch`**.
