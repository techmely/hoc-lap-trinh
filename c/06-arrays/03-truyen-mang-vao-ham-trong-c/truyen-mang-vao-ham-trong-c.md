---
title: "Truyền mảng vào hàm trong C"
description: "Truyền mảng vào hàm trong lập trình C là một kỹ thuật quan trọng giúp bạn xử lý dữ liệu một cách linh hoạt và hiệu quả. Bài viết này sẽ hướng dẫn bạn cách truyền mảng vào hàm, khai báo hàm với tham số mảng và sử dụng mảng bên trong hàm. Chúng mình sẽ giải thích cả trường hợp truyền mảng một chiều và mảng đa chiều vào hàm. Cùng đón xem nào."
chapter:
  name: "Mảng"
  slug: "chuong-06-array"
category:
  name: "C"
  slug: "c"
image: https://user-images.githubusercontent.com/29374426/127596066-fa46df01-982f-4a72-b6d1-f7d8f5c5a9b3.png
position: 3
---

Trong bài học này, chúng ta sẽ học cách chuyển mảng (cả mảng một chiều và nhiều chiều) cho một hàm trong lập trình C.

Chúng ta sẽ có những phương pháp hay dùng như sau:

- Pass Individual Array Elements
- Pass Arrays to Functions
- Pass Multidimensional Arrays to a Function

## Pass Individual Array Elements

Trong lập trình C, ta có thể chuyển toàn bộ mảng cho các hàm. Trước khi chúng ta tìm hiểu điều đó, hãy xem cách chúng ta có thể chuyển các phần tử riêng lẻ của một mảng cho các hàm.

Ví dụ:

```cpp
#include <stdio.h>

void display(int num1, int num2);

int main() {
    int num[] = {1, 4, 3, 5};

    //chuyền vào phần tử thứ nhất và phần tử thứ 3 vào hàm display()
    display(num[0], num[2]);
    return 0;
}

void display(int num1, int num2) {
    printf("%d\n", num1);
    printf("%d\n", num2);
}
```

::result
1
3
::

> Tại đây chúng ta đã truyền tham số vào trong hàm `display` giống như cách chúng ta truyền các biến cho hàm.

```cpp
//chuyền vào phần tử thứ nhất và phần tử thứ 3 vào hàm display()
display(num[0], num[2]);
```

> Chúng ta có thể thấy điều này trong định nghĩa hàm `display()`, trong đó các tham số của hàm là các biến riêng lẻ:

```cpp
void display(int num1, int num2);
```

## Pass Arrays to Functions

Ví dụ:

```cpp
#include <stdio.h>

float sum(float num[]);

int main() {
    float result, num[] = {26.5, 37.2, 21.2, 3.6, 34.2};

    // mảng num được truyền vào hàm sum
    result = sum(num);
    printf("Result = %.2f", result);
    return 0;
}

float sum(float num[]) {
    float s = 0.0;

    for (int i = 0; i < 5; ++i) {
        s += num[i];
    }

    return s;
}
```

::result
Result = 122.70
::

> Để truyền toàn bộ mảng cho một hàm, ta chỉ truyền tên của mảng vào hàm (chỉ truyền `num` chứ không truyền `num[]`).

```cpp
result = sum(num);
```

::alert{type="warning"}
Tuy nhiên, hãy lưu ý việc sử dụng `[]` trong khai báo hàm vì điều này đồng nghĩa việc ta đang thông báo cho trình biên dịch là ta đang truyền mảng một chiều cho hàm.
::

```cpp

float sum(float num[]) {
    //code
}
```

## Pass Multidimensional Arrays to a Function

Để truyền mảng đa chiều cho một hàm, ta chỉ truyền tên của mảng vào hàm (tương tự như mảng một chiều).

Ví dụ:

```cpp
#include <stdio.h>
void display(int num[][2]);

int main() {
    int num[2][2];
    printf("Enter 4 numbers:\n");
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            scanf("%d", &num[i][j]);
        }
    }

    // pass multi-dimensional array to a function
    display(num);

    return 0;
}

void display(int num[][2]) {
    printf("4 numbers you entered:\n");
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
      printf("%d\n", num[i][j]);
        }
    }
}
```


::result
Enter 4 numbers:
1 5 4 6
4 numbers you entered:
1
5
4
6
::

> Khi truyền mảng hai chiều, không bắt buộc phải chỉ định số hàng trong mảng. Tuy nhiên, số lượng cột phải luôn được chỉ định.

```cpp
void display(int num[][2]);

```
