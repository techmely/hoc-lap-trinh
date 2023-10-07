---
title: "Mảng đa chiều trong C"
description: "Mảng đa chiều trong ngôn ngữ lập trình C là một công cụ mạnh mẽ cho việc xử lý dữ liệu phức tạp và tạo ra các ứng dụng đa chiều đầy thách thức. Bài viết này sẽ giúp bạn hiểu sâu hơn về mảng đa chiều, cung cấp cách khai báo, truy cập và thao tác với chúng."
chapter:
  name: "Mảng"
  slug: "chuong-06-array"
image: https://user-images.githubusercontent.com/29374426/127596066-fa46df01-982f-4a72-b6d1-f7d8f5c5a9b3.png
position: 2
---

Trong bài học này, chúng ta sẽ học cách làm việc với mảng đa chiều.

## Mảng đa chiều trong C

Trong lập trình C, chúng ta có thể tạo một mảng mảng. Mảng này được gọi là mảng đa chiều.

Ví dụ:

```cpp
int num[4][3]
```

Ở đây, `num` là một mảng hai chiều. Mảng có thể chứa `12` phần tử. ta có thể hình dung rằng mảng như một bảng có `3` hàng và mỗi hàng có `4` cột.

|       | Col 1       | Col 2       | Col 3       | Col 4       |
| :---: | ----------- | ----------- | ----------- | ----------- |
| Row 1 | `num[0][0]` | `num[0][1]` | `num[0][2]` | `num[0][3]` |
| Row 2 | `num[1][0]` | `num[1][1]` | `num[1][2]` | `num[1][3]` |
| Row 3 | `num[2][0]` | `num[2][1]` | `num[2][2]` | `num[2][3]` |

Tương tự, bạn có thể khai báo một mảng ba chiều.

Ví dụ:

```cpp
int num[4][2][3]
```

Và mảng `num` này có thể chứa `4` _ `2` _ `3` = `24` phần tử.

## Khởi tạo một mảng đa chiều trong C

Chúng ta có thể khởi tạo mảng đa chiều bằng một trong các cách sau.

Ví dụ khởi tạo mảng hai chiều:

```cpp
int num[3][2] = {{1, 3}, {-5, 4}, {17, 35}};

int num[][2] = {{1, 3}, {-5, 4}, {17, 35}};
```

Ví dụ khởi tạo mảng ba chiều:

```cpp
int num[2][3][4] = {
    {{1, 2, 3, 4}, {-5, 6, -9, 18}, {43, 21, 22, 23}},
    {{1, 4, -5, 6}, {-6, 8, 9, -11}, {0, 1, 2, 3}}
};
```

## Nhập và xuất phần tử trong mảng

Để nhập vào, lưu trữ và hiển thị giá trị các phần tử của mảng hai chiều chúng ta sẽ sử dụng **`nested loop`**.

Ví dụ nhập vào một matrix có 3 hàng và 4 cột và hiển thị ra matrix đó:

```cpp
#include <stdio.h>

int main() {

    int row = 3;
    int col = 4;
    int matrix[row][col];

    // nhập vào mảng 2 chiều

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("Enter matrix[%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }

    // hiển thị mảng 2 chiều

    printf("\nDisplay matrix: \n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("[%d]", matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}
```

::result
Enter matrix[1][1]: 1</br>
Enter matrix[1][2]: 3</br>
Enter matrix[1][3]: 2</br>
Enter matrix[1][4]: 5</br>
Enter matrix[2][1]: 2</br>
Enter matrix[2][2]: 3</br>
Enter matrix[2][3]: 4</br>
Enter matrix[2][4]: 5</br>
Enter matrix[3][1]: 6</br>
Enter matrix[3][2]: 1</br>
Enter matrix[3][3]: 3</br>
Enter matrix[3][4]: 4</br>

Display matrix:</br>
[1][3][2][5]</br>
[2][3][4][5]</br>
[6][1][3][4]</br>
::

Tương tự ta có ví dụ về nhập và hiển thị mảng ba chiều:

```cpp
#include <stdio.h>

int main() {

	int num[2][3][2];

    // nhập vào mảng 3 chiều sử dụng 3 vòng for lồng nhau

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 2; ++k) {
            	printf("Enter num[%d][%d][%d]: ", i, j, k);
                scanf("%d", &num[i][j][k]);
            }
        }
    }

    // hiển thị giá trị mảng ba chiều

    printf("\nDisplaying values:\n");
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 2; ++k) {
                printf("num[%d][%d][%d] = %d\n", i, j, k, num[i][j][k]);
            }
        }
    }

    return 0;
}
```

::result
Enter num[0][0][0]: -2</br>
Enter num[0][0][1]: 0</br>
Enter num[0][1][0]: 1</br>
Enter num[0][1][1]: 5</br>
Enter num[0][2][0]: 4</br>
Enter num[0][2][1]: -2</br>
Enter num[1][0][0]: 23</br>
Enter num[1][0][1]: 32</br>
Enter num[1][1][0]: -12</br>
Enter num[1][1][1]: 21</br>
Enter num[1][2][0]: 32</br>
Enter num[1][2][1]: -2</br>

Displaying values:</br>
num[0][0][0] = -2</br>
num[0][0][1] = 0</br>
num[0][1][0] = 1</br>
num[0][1][1] = 5</br>
num[0][2][0] = 4</br>
num[0][2][1] = -2</br>
num[1][0][0] = 23</br>
num[1][0][1] = 32</br>
num[1][1][0] = -12</br>
num[1][1][1] = 21</br>
num[1][2][0] = 32</br>
num[1][2][1] = -2</br>
::
