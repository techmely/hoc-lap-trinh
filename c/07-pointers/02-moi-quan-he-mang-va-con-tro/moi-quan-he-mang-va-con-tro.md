---
title: "Mối quan hệ mảng và con trỏ"
description: "Mảng và con trỏ là hai khái niệm quan trọng trong lập trình, và hiểu mối quan hệ giữa chúng là vô cùng quan trọng. Bài viết này sẽ giúp bạn khám phá mối liên kết sâu sắc giữa mảng và con trỏ, và làm thế nào chúng tương tác với nhau để tạo ra các ứng dụng mạnh mẽ."
chapter:
  name: "Con trỏ"
  slug: "chuong-07-pointer"
category:
  name: "C"
  slug: "c"
image: https://user-images.githubusercontent.com/29374426/127596066-fa46df01-982f-4a72-b6d1-f7d8f5c5a9b3.png
position: 2
---

Trong bài học này, chúng ta sẽ tìm hiểu về mối quan hệ giữa mảng và con trỏ trong lập trình C. Ta cũng sẽ học cách truy cập các phần tử mảng bằng cách sử dụng con trỏ.

## Mối quan hệ giữa mảng và con

Mảng là một khối dữ liệu tuần tự, khi chúng ta in ra địa chỉ các phần tử của mảng như chương trình sau:

```cpp
#include <stdio.h>
int main() {
   int num[5];
   int i;

   for(i = 0; i < 5; ++i) {
      printf("&x[%d] = %p\n", i, &num[i]);
   }

   printf("Address of array num: %p", num);

   return 0;
}
```

kết quả

```cpp
&x[0] = 000000000062FE00
&x[1] = 000000000062FE04
&x[2] = 000000000062FE08
&x[3] = 000000000062FE0C
&x[4] = 000000000062FE10
Address of array num: 000000000062FE00
```

vì kích thước của `int` là `4 byte` nên địa chỉ của hai phần tử mảng liên tiếp cũng chênh nhau `4 byte`

> địa chỉ của `&num[0]` và `num` là giống nhau vì `num` trỏ đến phần tử đầu tiên của mảng

từ ví dụ trên rõ ràng `&num[0]` là tương đương với `num`. Và, `num[0]` tương đương với `*num`.

Tương tự,

- `&num[1]` tương đương với `num+1` và `num[1]` tương đương với `*(num+1)`.
- `&num[2]` tương đương với `num+2` và `num[2]` tương đương với `*(num+2)`.
- Về cơ bản, `&num[i]` tương đương với `num+i` và `num[i]` tương đương với `*(num+i)`.

## Một số ví dụ để hiểu rõ hơn về con trỏ và mảng

Ví dụ 1:

```cpp
#include <stdio.h>
int main() {

    int i, num[5], sum = 0;

    printf("Enter 5 numbers: ");

    for(i = 0; i < 5; ++i) {
        //  scanf("%d", &x[i]);
        scanf("%d", num+i);

        // Equivalent to sum += x[i]
        sum += *(num+i);
    }

    printf("Sum = %d", sum);

    return 0;
}
```

Kết quả:

```cpp
Enter 5 numbers: 1
-2
4
1
6
Sum = 10
```

Ví dụ 2:

```cpp
#include <stdio.h>
int main() {

    int num[5] = {1, 2, 3, 4, 5};
    int* pn;

    pn = &num[3];

    printf("*pn = %d \n", *pn);
    printf("*(pn+1) = %d \n", *(pn+1));
    printf("*(pn-1) = %d", *(pn-1));

   return 0;
}

```

Kết quả

```cpp
*pn = 4
*(pn+1) = 5
*(pn-1) = 3
```

Trong ví dụ này `&num[3]` là địa chỉ của phần tử thứ tư, được gán cho con trỏ `pn`, do đó giá trị của `*pn` lúc này sẽ là `4`

Và tương tự `pn+1` sẽ trỏ vào phần tử thứ năm, `*pn+1` lúc này sẽ mang giá trị là `5`, còn `*pn-1` sẽ mang giá trị là `3`
