---
title: "Câu lệnh goto trong C"
description: "Câu lệnh 'goto' là một công cụ mạnh mẽ và đa dạng cho phép bạn kiểm soát luồng của chương trình. Mặc dù nó có thể gây ra chút trở ngại trong việc đọc code và khả năng debug không quá linh hoạt, nhưng có các tình huống đặc biệt khi sử dụng 'goto' có thể là lựa chọn hợp lý. Học cách sử dụng 'goto' một cách chín chắn và hiệu quả để xử lý các tình huống phức tạp trong lập trình C."
chapter:
  name: "Vòng lặp"
  slug: "chuong-04-loops"
category:
  name: "C"
  slug: "c"
image: https://user-images.githubusercontent.com/29374426/127596066-fa46df01-982f-4a72-b6d1-f7d8f5c5a9b3.png
position: 7
---

Câu lệnh **`goto`** là một câu lệnh nhảy đôi khi cũng được gọi là câu lệnh nhảy vô điều kiện. Câu lệnh **`goto`** có thể được sử dụng để nhảy từ bất cứ đâu đến bất cứ đâu trong một hàm.

## Cú pháp câu lệnh goto trong C

```cpp
Syntax1      |    Syntax2
------------------------------
goto label;   |    label:
.             |    .
.             |    .
.             |    .
label:        |    goto label;
```

Các `label` là một định danh (tùy bạn đặt tên như tên biến). Khi gặp câu lệnh **`goto`**, chương trình sẽ nhảy tới `label` và bắt đầu thực thi mã.

## Ví dụ câu lệnh goto trong C

### Syntax 1

Ví dụ 1:

> Kiểm tra một số là số chẵn hay số lẻ.

```cpp
#include <stdio.h>

int main() {

    int n;

    printf("Enter n: ");
    scanf("%d", &n);

    if (n % 2 == 0) {
        // jump to even
        goto even;
    } else {
        // jump to odd
        goto odd;
    }

    even:
        printf("%d is even.", n);
        // return if even
        return 0;
    odd:
        printf("%d is odd.", n);
}
```

::result
Enter n: 44</br>
44 is even.</br>
::

Ví dụ 2:

> Chương trình tính tổng và trung bình của các số dương. Nếu người dùng nhập số âm, tổng và trung bình được hiển thị.

```cpp
#include <stdio.h>

int main() {

    int maxInput = 5, i;
    double number, average, sum = 0;

    for (i = 1; i <= maxInput; i++) {
        printf("Enter a number: ", i);
        scanf("%lf",&number);

        if(number < 0) {
            goto jump;
        }
        sum += number;
    }

    jump:
    average = sum/(i-1);
    printf("\nSum = %.2f\n", sum);
    printf("Average = %.2f", average);
}
```

::result
Enter a number: 4</br>
Enter a number: 6</br>
Enter a number: 6</br>
Enter a number: -1</br>

Sum = 16.00</br>
Average = 5.33</br>
::

### Syntax 2

Ví dụ:

> In ra các số từ `1` đến `10`.

```cpp
#include <stdio.h>

int main() {

    int n = 1;

    label:
        printf("%d\n", n);
        n++;
        if (n <= 10) {
            goto label;
        }
}
```

::result
1</br>
2</br>
3</br>
4</br>
5</br>
6</br>
7</br>
8</br>
9</br>
10</br>
::

## Disadvantages of using goto statement

- Việc sử dụng câu lệnh **`goto`** rất không được khuyến khích vì nó làm cho logic chương trình rất phức tạp.
- Việc sử dụng **`goto`** làm cho nhiệm vụ phân tích và xác minh tính đúng đắn của các chương trình (đặc biệt là các chương trình liên quan đến các vòng lặp) rất khó khăn.
- Tránh sử dụng **`goto`** - có thể thay thế đơn giản bằng cách sử dụng các câu lệnh **`break`** và **`continue`**.
