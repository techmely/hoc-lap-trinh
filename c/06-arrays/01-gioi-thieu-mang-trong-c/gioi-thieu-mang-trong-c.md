---
title: "Giới thiệu mảng trong C"
description: "Mảng là một khái niệm quan trọng trong lập trình C, và việc hiểu cách sử dụng chúng là một phần thiết yếu của việc trở thành một lập trình viên thành thạo. Bài viết này sẽ giới thiệu mảng trong ngôn ngữ lập trình C một cách toàn diện."
chapter:
  name: "Mảng"
  slug: "chuong-06-array"
category:
  name: "C"
  slug: "c"
image: https://user-images.githubusercontent.com/29374426/127596066-fa46df01-982f-4a72-b6d1-f7d8f5c5a9b3.png
position: 1
---

Trong bài này chúng ta sẽ tìm hiểu về cách làm việc với mảng:

- Khai báo mảng
- Truy cập vào phần tử của mảng
- Khởi tạo mảng
- Thay đổi giá trị phần tử của mảng
- Nhập xuất phần tử mảng

## Khai mảng trong C

#### Syntax:

```cpp
dataType arrayName[arraySize]
```

Ví dụ:

```cpp
int number[10]
```

Tại đây, chúng ta đã khai báo một mảng `number` thuộc loại `int`. Và kích thước của nó là `10`. Có nghĩa là, nó có thể chứa `10` giá trị `int`.

Điều quan trọng cần lưu ý là không thể thay đổi kích thước và kiểu của một mảng sau khi nó được khai báo.

## Truy cập vào các phần tử của mảng trong C

Chúng ta có thể truy cập các phần tử của một mảng theo các chỉ số.

Giả sử chúng ta đã khai báo một mảng `number` như trên. Phần tử đầu tiên là `number[0]`, phần tử thứ hai là `number[1]` và như thế.

#### Take note

- Mảng có 0 là chỉ mục đầu tiên, không phải 1. Trong ví dụ này, `number[0]` là phần tử đầu tiên.
- Nếu kích thước của một mảng là `n`, thì để truy cập phần tử cuối cùng, `n-1` chỉ mục được sử dụng. Trong ví dụ này, `number[4]` là phần tử cuối cùng.

## Khởi tạo một mảng trong

Chúng ta có thể khởi tạo mảng trong quá trình khai báo.

```cpp
int number[5] = {10, 15, 13, 31, 56};
```

Hoặc chúng ta cũng có thể khởi tạo mảng theo cách này:

```cpp
int number[] = {10, 15, 13, 31, 56};
```

Ở đây, chúng ta chưa khai báo kích thước. Tuy nhiên, trình biên dịch biết kích thước của nó là 5 vì chúng ta đang khởi tạo nó với 5 phần tử.

Lúc này ta có các giá trị được lưu vào các biến:
| Phần tử | Giá trị |
| :-----: | -------- |
| `number[0]` | `10` |
| `number[1]` | `15` |
| `number[2]` | `13` |
| `number[3]` | `31` |
| `number[4]` | `56` |

## Thay đổi giá trị của mảng trong C

```cpp
int number[5] = {10, 15, 13, 31, 56};

// thay đổi giá trị phần tử đầu tiên thành -10
mark[0] = -10;

// thay đổi giá trị phần tử thứ 4 thành 6
mark[3] = 6;
```

## Nhập và xuất các phần tử trong mảng

Để nhập giá trị cho các phần tử trong mảng chúng ta sử dụng vòng lặp `for` để duyệt mảng và gán giá trị lần lượt cho các phần tử hoặc chỉ định ra phần tử nhập giá trị trực tiếp `scanf("%d", &number[2]);`.

Tương tự để in ra các phần tử trong mảng chúng ta sử dụng vòng lặp `for` để duyệt mảng và in lần lượt các phần tử hoặc chỉ định ra phần tử in `printf("%d", number[2]);`.

Ví dụ:

```cpp
#include <stdio.h>

int main() {
    int number[5];

    printf("Enter 5 integer numbers: ");

    for(int i = 0; i < 5; ++i) {
        scanf("%d", &number[i]);
    }

    printf("\nDisplay array: ");

    for(int i = 0; i < 5; ++i) {
        printf("%d ", number[i]);
    }
    return 0;
}
```

Kết quả:

```cpp
Enter 5 integer numbers: 1
4
3
5
6

Display array: 1 4 3 5 6
```
