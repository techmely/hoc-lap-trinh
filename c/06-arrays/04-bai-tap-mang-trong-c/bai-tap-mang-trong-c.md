---
title: "Bài tập mảng trong C"
description: "Đã đến lúc thực hành thật sự rồi. Nên nhớ vừa làm vừa tìm hiểu và nghiên cứu sâu sẽ giúp bạn nắm bắt được kiến thức một cách nhanh nhất. Vậy thì cùng chúng mình bắt đầu vào thực hành nào."
chapter:
  name: "Mảng"
  slug: "chuong-06-array"
category:
  name: "C"
  slug: "c"
image: https://user-images.githubusercontent.com/29374426/127596066-fa46df01-982f-4a72-b6d1-f7d8f5c5a9b3.png
position: 4
---

Các bài tập sẽ có template code, các bạn sao chép về và thực hiện code vào đó, yêu cầu **không chỉnh sửa** bất kỳ dòng code template nào. Chỉ được viết code của bạn vào đúng chỗ được ghi chú.

## Bài 1

> Nhập giá trị số nguyên cho **_mười phần tử_** của một mảng và sắp xếp dãy số trong mảng đó theo thứ tự tăng dần bằng **_thuật toán nổi bọt_** (Bubble Sort).

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

::result
Enter the 10 elements of array: 3 5 6 1 13 54 34 8 22 11

OUTPUT:
Unsorted array: 3, 5, 6, 1, 13, 54, 34, 8, 22, 11
Sorted array: 1, 3, 5, 6, 8, 11 , 13, 22, 34, 54
--------------------------------
::

## Bài 2

> Nhập vào số lượng phần tử của một mảng, nhập vào giá trị kiểu dữ liệu số nguyên cho các phần tử mảng đó, sắp xếp dãy số trong mảng đó theo thứ tự tăng dần bằng **_thuật toán sắp xếp chọn_** (Selection Sort).

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

::result
Eter the number of elements of the array: 10
Enter the 10 elements of array: 3 5 6 1 13 54 34 8 22 11

OUTPUT:
Unsorted array: 3, 5, 6, 1, 13, 54, 34, 8, 22, 11
Sorted array: 1, 3, 5, 6, 8, 11 , 13, 22, 34, 54
--------------------------------
::

## Bài 3

> Tạo ngẫu nhiên giá trị số nguyên dương từ **_1_** đến **_100_** cho mảng có **_mười phần tử_**, nhập giá trị cần tìm và tìm giá trị đó trong mảng, hiển thị vị trí của giá trị cần tìm trong mảng bằng phương pháp **_Binary Search_**. 

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

Màn hình chương trình:

Test case 1

::result
Enter value you want to search: 8

OUTPUT:
Display array: 1, 4, 6, 2, 20, 8, 36, 22, 89, 77
Found 8 at index 5 in array
--------------------------------
::

Test case 2

::result
Enter value you want to search: 5

OUTPUT:
Display array: 1, 4, 6, 2, 20, 8, 36, 22, 89, 77
Not found 5 in array
--------------------------------
::
