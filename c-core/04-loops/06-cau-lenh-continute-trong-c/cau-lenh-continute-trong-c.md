---
title: "Câu lệnh continue trong C"
description: "Câu lệnh continue trong C"
keywords:
  ["học lập trình c", "khoá học lập trình c", "Khoá học lập trình c căn bản"]
chapter:
  name: "Vòng lặp"
  slug: "chuong-04-loops"
category:
  name: "C"
  slug: "c"
image: https://user-images.githubusercontent.com/29374426/127596066-fa46df01-982f-4a72-b6d1-f7d8f5c5a9b3.png
position: 6
---

**`continue`** cũng là một câu lệnh điều khiển vòng lặp giống như câu lệnh **`break`**. Nhưng câu lệnh **`continue`** trái ngược với câu lệnh **`break`**, thay vì kết thúc vòng lặp, nó buộc phải thực hiện lần lặp tiếp theo của vòng lặp.

Khi câu lệnh **`continue`** được thực thi trong vòng lặp, mã bên trong vòng lặp sau câu lệnh **`continue`** sẽ bị bỏ qua và lần lặp tiếp theo của vòng lặp sẽ bắt đầu.

## Cú pháp câu lệnh continue trong C

```c
continue;
```

Câu lệnh **`continue`** thường được sử dụng với câu lệnh **`if-else`** bên trong vòng lặp.

## Cách hoạt động của câu lệnh continue hoạt động trong C

### Continue trong vòng lặp for

<p align="center">
  <img src="https://github.com/AnestLearning/Course-C-Fundamentals/blob/master/Images/c-continue-statement-works-1.jpg">
</p>

### Continue trong vòng lặp do-while

<p align="center">
  <img src="https://github.com/AnestLearning/Course-C-Fundamentals/blob/master/Images/c-continue-statement-works-2.jpg">
</p>

### Continue trong vòng lặp while

<p align="center">
  <img src="https://github.com/AnestLearning/Course-C-Fundamentals/blob/master/Images/c-continue-statement-works-3.jpg">
</p>

## Sơ đồ hoạt động câu lệnh continue trong C

<p align="center">
  <img src="https://github.com/AnestLearning/Course-C-Fundamentals/blob/master/Images/c-continue-statement-flowchart.jpg">
</p>

## Ví 

Ví dụ 1:

> In ra các số từ `1` đến `10` trừ số `5` (không in ra số `5`). Kết quả đầu ra như sau: 1 2 3 4 6 7 8 9 10

```c
#include <stdio.h>

int main() {

    for (int i = 1; i <= 10; i++) {

        // If i is equals to 6,
        // continue to next loop
        // without printing
        if (i == 5) {
            continue;
        } else {
            printf("%d ", i);
        }
    }
}
```

Các bạn có thể thấy khi `i = 5` câu lệnh **`continue`** sẽ được thực thi, lúc này chương trình sẽ bỏ qua đoạn mã bên dưới **`continue`** và chạy vòng **`for`** mới - vì vậy câu lệnh `printf()` sẽ không được thực hiện, `5` sẽ không được in ra màn hình.

Kết quả chương trình:

```c
1 2 3 4 6 7 8 9 10
```

Ví dụ 2:

> Tính tổng tối đa 5 số. Nếu người dùng nhập số âm thì bỏ qua (không cộng số âm vào tổng).

```c
# include <stdio.h>

int main() {

    int number;
    int sum = 0;

    for (int i = 1; i <= 5; ++i){
        printf("Enter a n%d: ",i);
        scanf("%d", &number);

        if(number < 0) {
            continue;
        }

        sum += number; // sum = sum + number;
    }

    printf("\nSum = %d", sum);
}
```

Khi nhập `n < 0` câu lệnh **`continue`** sẽ được thực thi, lúc này chương trình sẽ bỏ qua đoạn mã bên dưới **`continue`** và chạy vòng **`for`** mới - vì vậy câu lệnh `sum += number;` sẽ không được thực hiện, số âm sẽ không được cộng vào tổng.

Kết quả chương trình:

```c
Enter a n1: 1
Enter a n2: 2
Enter a n3: -3
Enter a n4: 4
Enter a n5: -5

Sum = 7
```

Câu lệnh **`continue`** có thể được sử dụng với bất kỳ vòng lặp nào khác cũng như **`while`** hoặc **`do-while`** theo cách tương tự như nó được sử dụng với vòng lặp **`for`** ở trên.
