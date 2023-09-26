---
title: "Pointer trong C là gì"
description: "Pointer (Con trỏ) trong ngôn ngữ lập trình C là một khái niệm quan trọng, đóng vai trò quan trọng trong việc quản lý bộ nhớ và truy cập dữ liệu. Bài viết này sẽ giúp bạn hiểu rõ về con trỏ, từ định nghĩa đến cách sử dụng, và tại sao nó là một tính năng mạnh mẽ trong lập trình C."
chapter:
  name: "Con trỏ"
  slug: "chuong-07-pointer"
image: https://user-images.githubusercontent.com/29374426/127596066-fa46df01-982f-4a72-b6d1-f7d8f5c5a9b3.png
position: 1
---

Pointer (biến con trỏ) là các biến đặc biệt được sử dụng để lưu trữ địa chỉ hơn là giá trị.

Và trong bài học ngày hôm nay chúng ta sẽ cùng tìm hiểu về:

- Cú pháp con trỏ.
- Gán địa chỉ vào một con trỏ.
- Lấy giá trị của địa chỉ được con trỏ trỏ vào.
- Thay đổi giá trị được trỏ bởi con trỏ.
- Cách con trỏ hoạt động.

## Cú pháp con trỏ trong C

Đây là cách chúng ta dùng để khai báo con trỏ:

```cpp
int* p;
```

Tại đây ta đã khai báo một con trỏ tên là `p` và có kiểu dữ liệu là `int`.

Hoặc ta có thể khai báo theo cách sau:

```cpp
int *p1;
int * p2;
```

Chú ý ta có trường hợp sau:

```cpp
int* p1, p2;
```

Dòng lệnh trên có nghĩa là chúng ta khai báo một con trỏ `p1` kiểu dữ liệu `int` và một biến `p2` cùng kiểu dữ liệu

## Gắn địa chỉ cho con trỏ trong C

Ví dụ:

```cpp
int* pc, c;
c = 10;
pc = &c;
```

Như đã nói ở trên, tại đây chúng ta đang khai báo con trỏ `pc` và một biến `c` mang cùng kiểu dữ liệu `int`.

Ở đây 10 được gán cho biến `c`, sau đó địa chỉ của c được gán cho con trỏ `pc`

## Lấy giá trị của con trỏ trong C

Để nhận giá trị từ địa chỉ được con trỏ trỏ vào ta sử dụng `*`, Ví dụ:

```cpp
int* pc, c;
c = 10;
pc = &c;
printf("%d", *pc);   // Output: 5
```

Địa chỉ của `c` được trỏ bởi con trỏ `pc`: `pc = &c` . Để lấy giá trị được lưu trữ trong địa chỉ đó chúng ta sử dụng `*pc`.

> `pc` là một con trỏ trỏ tới một địa chỉ, còn `*pc` là cú pháp để lấy giá trị được lưu trữ trong địa chỉ mà con trỏ `pc` trỏ vào nên chúng ta không được code như `*pc = &c`.

## Thay đổi giá trị của con trỏ

Ví dụ 1:

```cpp
int* pc, c;
c = 10;
pc = &c;
c = 2;
printf("%d", c);    // Output: 2
printf("%d", *pc);  // Output: 2
```

Tại ví dụ này chúng ta đã dùng con trỏ `pc` để trỏ tới địa chỉ của `c` thì khi ta thay đổi biến `c = 2` đồng nghĩa với việc `*pc` cũng được thay đổi giá trị thành `2`.

Ví dụ 2:

```cpp
int* pa, a, b;
a = 2;
b = -3;

pa = &a;
printf("%d", *pa); // Output: 2
pa = &b;
printf("%d", *pa); // Output: -3
```

Ở ví dụ này con trỏ `pa` sẽ trỏ vào địa chỉ của biến `a`
mà giá trị của biến `a` lúc này là 2 nên giá trị của `*pa` cũng là 2.

Sau đó con trỏ `pa` sẽ trỏ vào địa chỉ của biến `b`, tương tự `*pa` lúc này mang giá trị là -3 do `b = -3`.

## Cách làm việc của con trỏ

Ví dụ:

```cpp
#include <stdio.h>
int main()
{
   int* pc, c;

   c = 18;
   printf("Address of c: %p\n", &c);
   printf("Value of c: %d\n\n", c);

   pc = &c;
   printf("Address of pointer pc: %p\n", pc);
   printf("Content of pointer pc: %d\n\n", *pc);

   c = 10;
   printf("Address of pointer pc: %p\n", pc);
   printf("Content of pointer pc: %d\n\n", *pc);

   *pc = -2;
   printf("Address of c: %p\n", &c);
   printf("Value of c: %d\n\n", c);
   return 0;
}
```

::result
Address of c: 000000000062FE14
Value of c: 18

Address of pointer pc: 000000000062FE14
Content of pointer pc: 18

Address of pointer pc: 000000000062FE14
Content of pointer pc: 10

Address of c: 000000000062FE14
Value of c: -2
::

Giải thích về cách hoạt động của con trỏ.

```cpp
int* pc, c;
```

Tại đây chúng ta đang khai báo một con trỏ `pc` và một biến `c` thuộc kiểu dữ liệu `int`.

```cpp
c = 18;
```

Giá trị `18` đang được lưu trữ trong bộ nhớ của `c`.

```cpp
pc = &c;
```

Con trỏ `pc` sẽ trỏ đến địa chỉ bộ nhớ của biến `c`.

```cpp
c = 10;
```

Giá trị `10` được lưu trữ trong bộ nhớ của `c`.

Trong khi đó con trỏ `pc` đang được trỏ đến địa chỉ bộ nhớ của biến sẽ nên lúc này `*pc` sẽ có giá trị là `10`.

```cpp
*pc = -2;
```

Ta thay đổi giá trị được lưu trữ tại bộ nhớ mà con trỏ `pc` trỏ vào nên giá trị của biến `c` thay đổi, lúc này giá trị được lưu trự tại biến `c` là `-2`.
