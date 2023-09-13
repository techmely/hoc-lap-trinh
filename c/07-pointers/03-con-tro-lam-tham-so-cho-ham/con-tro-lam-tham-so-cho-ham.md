---
title: "Con trỏ làm tham số cho hàm"
description: "Trong lập trình C, sử dụng con trỏ làm tham số cho hàm là một kỹ thuật mạnh mẽ giúp bạn thao tác với dữ liệu một cách linh hoạt và hiệu quả. Bài viết này sẽ hướng dẫn bạn cách sử dụng con trỏ như tham số cho các hàm, cung cấp ví dụ cụ thể và lý do tại sao nó quan trọng."
chapter:
  name: "Con trỏ"
  slug: "chuong-07-pointer"
category:
  name: "C"
  slug: "c"
image: https://user-images.githubusercontent.com/29374426/127596066-fa46df01-982f-4a72-b6d1-f7d8f5c5a9b3.png
position: 3
---

Trong bài này, chúng ta sẽ học cách chuyển địa chỉ và con trỏ làm tham số cho các hàm thông qua các ví dụ.

- Truyền địa chỉ đến hàm
- Truyền con trỏ đến hàm

## Truyền địa chỉ vào hàm trong

Ví dụ:

```cpp
#include <stdio.h>
void swap(int *n1, int *n2);

int main()
{
    int num1 = 1, num2 = 2;

    swap( &num1, &num2);

    printf("num1 = %d\n", num1);
    printf("num2 = %d", num2);
    return 0;
}

void swap(int* n1, int* n2)
{
    int temp;
    temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}
```

kết quả:

```cpp
num1 = 2
num2 = 1
```

địa chỉ của `num1` và `num2` được truyền vào hàm `swap()` bằng cách sử dụng cú pháp:

```cpp
swap( &num1, &num2);
```

con trỏ n1 và n2 sẽ nhận hai tham số này trong khai báo hàm:

```cpp
void swap(int *n1, int *n2);
```

Bên trong hàm `swap()`, `*n1` và `*n2` hoán đổi. Kể từ đây,`num1` và `num2` cũng được hoán đổi. vì chúng ta đã truyền vào hàm địa chỉ của `num1` chứ không phải là giá trị của `num1`

> Lưu ý rằng `swap()` không trả lại bất cứ điều gì; kiểu trả về của nó là `void`.

## Truyền con trỏ vào hàm trong C

Ví dụ:

```cpp
#include <stdio.h>

void add(int* p1, int *p2) {
    (*p1) += 2;
    (*p2) += 3;
}

int main()
{
    int* pa, a = 5;
    int* pb, b = 6;
    pa = &a;
    pb = &b;
    add(pa, pb);

    printf("%d\n", a);
    printf("%d\n", b);
  return 0;
}
```

Kêt quả:

```cpp
7
9
```

Trong chương trình này, con trỏ `pa` nhận địa chỉ của biến `a`, con trỏ `pb` nhận giá trị của biến `b`

```cpp
int* pa, a = 5;
int* pb, b = 6;
pa = &a;
pb = &b;
```

hàm `add()` trong chương trình đang thay đổi giá trị trực tiếp trên địa chỉ của con trỏ do chúng ta truyền con trỏ vào hàm.

Do đó sau khi hàm `add()` được thực thi, lúc này giá trị của con trỏ `pa` là `7` còn `pb` là `9`, mà hai con trỏ này đang trỏ vào hai biến `a` và `b` nên hai biến này sẽ có giá trị lần lượt là `7` và `9`
