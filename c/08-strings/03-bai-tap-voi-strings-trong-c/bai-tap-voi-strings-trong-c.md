---
title: "Bài tập thao tác với chuỗi trong C"
description: "Bài viết này sẽ giới thiệu một loạt các bài tập thực tế liên quan đến chuỗi, giúp bạn rèn luyện kỹ năng cơ bản và nâng cao khả năng xử lý dữ liệu văn bản."
chapter:
  name: "Strings"
  slug: "chuong-08-strings"
category:
  name: "C"
  slug: "c"
image: https://user-images.githubusercontent.com/29374426/127596066-fa46df01-982f-4a72-b6d1-f7d8f5c5a9b3.png
position: 3
---

Các bài tập sẽ có template code, các bạn sao chép về và thực hiện code vào đó, yêu cầu **không chỉnh sửa** bất kỳ dòng code template nào. Chỉ được viết code của bạn vào đúng chỗ được ghi chú.

## Bài 1

> **Nhập vào một chuỗi và một kí tự, đếm số lần xuất hiện của kí tự đó trong chuỗi vừa nhập.**

Template:

```cpp
#include <stdio.h>

int main() {
    // Add your code in here:


    // Fixed Do not edit anything here.
    printf("\nOUTPUT:\n");
    // Write your output here:


    return 0;
}
```

Màn hình kết quả chương trình:

Test case 1

::result
Enter string: Hello Kungfutech
Enter character: e

OUTPUT:
Frequency of e is 2
--------------------------------
::

## Bài 2

> **Nhập vào một số thập phân, rồi nhập 1 để chuyển sang hệ nhị phân, nhập 2 để chuyển sang hệ bát phân, nhập 3 để chuyển sang hệ thập lục phân.**

Template:

```cpp
#include <stdio.h>

int main() {
    // Add your code in here:


    // Fixed Do not edit anything here.
    printf("\nOUTPUT:\n");
    // Write your output here:


    return 0;
}
```

Màn hình kết quả chương trình:

Test case 1

::result
1. Convert to binary
2. Convert to octal
3. Convert to hexa
Enter your number: 112427
Enter your choice: 1

OUTPUT:
Binary is 11011011100101011
--------------------------------
::

> không nên để kiểu dữ liệu của binary là `int` hay `long long` vì giá trị max của long long chỉ giới hạn tại 9,223,372,036,854,775,807.

Test case 2

::result
1. Convert to binary
2. Convert to octal
3. Convert to hexa
Enter your number: 10856
Enter your choice: 2

OUTPUT:
Octal is 25150
--------------------------------
::

Test case 3

::result
1. Convert to binary
2. Convert to octal
3. Convert to hexa
Enter your number: 265084
Enter your choice: 3

OUTPUT:
Hexa is 40B7C
--------------------------------
::
