---
title: "Hàm đệ quy trong C"
description: "Hàm đệ quy trong C"
keywords:
  ["học lập trình c", "khoá học lập trình c", "Khoá học lập trình c căn bản"]
chapter:
  name: "Hàm"
  slug: "chuong-05-functions"
category:
  name: "C"
  slug: "c-core"
image: https://user-images.githubusercontent.com/29374426/127596066-fa46df01-982f-4a72-b6d1-f7d8f5c5a9b3.png
position: 3
---

Trong bài viết này, chúng ta sẽ tìm hiểu và học cách viết các hàm đệ quy trong lập trình C.

## What is recursion?

Một hàm gọi lại chính nó bên trong body code được gọi là hàm đệ quy. Và kỹ thuật này được gọi là đệ quy.

### Syntax

```c
void recurse() {
    ... .. ...
    recurse();  // gọi lại chính nó bên trong nó
    ... .. ...
}

int main() {
    ... .. ...
    recurse();
    ... .. ...
}
```

## How recursion works?

Vì đệ quy là một hàm gọi lại chính nó nên có thể xem như là lặp đi lặp lại, vì vậy để ngăn đệ quy chạy vô hạn, cần có điều kiện để kết thúc nó. Thông thường chúng ta sẽ sử dụng `if-else` để làm việc đó.

Ví dụ:

> Tính tổng các số từ `1` đến `n`.

Đối với bài toán này chúng ta có 3 cách giải như sau:

### Solution 1

Sử dụng công thức toán học.

```c
#include <stdio.h>

int main() {

    int number, result;

    printf("Enter a positive integer: ");
    scanf("%d", &number);

    result = number * (number + 1) / 2;

    printf("sum = %d", result);
}
```

### Solution 2

Sử dụng vòng lặp `for`.

```c
#include <stdio.h>

int main() {

    int number, result;

    printf("Enter a positive integer: ");
    scanf("%d", &number);

    for(int i = 1; i <= n; ++i) {
        result += i;
    }

    printf("sum = %d", result);
}
```

Sử dụng vòng lặp `while`.

```c
#include <stdio.h>

int main() {

    int number, result;

    printf("Enter a positive integer: ");
    scanf("%d", &number);

    int i = 1;
    while (i <= n) {
        result += i;
        ++i;
    }

    printf("sum = %d", result);
}
```

### Solution 3

Sử dụng hàm đệ quy.

```c
#include <stdio.h>

int sum(int);

int main() {
    int number, result;

    printf("Enter a positive integer: ");
    scanf("%d", &number);

    result = sum(number);

    printf("sum = %d", result);
    return 0;
}

int sum(int n) {

    if (n != 0) {
        // sum() function calls itself
        return n + sum(n-1);
    } else {
        return n;
    }
}
```

- Đầu tiên, hàm `sum()` được gọi từ hàm `main()` với `number` được truyền vào bằng giá trị lấy từ người dùng nhập vào.
- Giả sử, giá trị của `n` truyền vào trong `sum()` là `3`. Trong lần gọi hàm tiếp theo, bạn có thể thấy chúng ta sẽ truyền giá trị `n-1` vào hàm `sum()` → `2` được truyền vào hàm `sum()`. Quá trình này tiếp tục cho đến khi `n = 0` thì kết thúc (kiểm tra trong `if`).
- Khi `n = 0`, `if` trả về `false` và phần `else` được thực thi trả về tổng số nguyên cuối cùng cho hàm `main()`.

## Advantages and Disadvantages of Recursion

- Đệ quy làm cho chương trình trông gọn gàng hơn. Tuy nhiên, một chương trình quan trọng hiệu suất hơn, thay vì sử dụng đệ quy hãy sử dụng các vòng lặp vì đệ quy thường chạy chậm hơn nhiều.
- Nhưng đệ quy lại là một khái niệm quan trọng cần biết. Vì nó thường được sử dụng trong cấu trúc dữ liệu và thuật toán.
