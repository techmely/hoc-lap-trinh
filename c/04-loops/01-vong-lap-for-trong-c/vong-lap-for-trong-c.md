---
title: "Vòng lặp for trong C"
description: "Vòng lặp 'for' là một trong những cấu trúc quan trọng nhất, giúp bạn thực hiện các tác vụ lặp lại một cách hiệu quả và linh hoạt. Với khả năng kiểm soát được số lần lặp và quản lý biến điều kiện, bạn có thể xây dựng các chương trình mạnh mẽ và hiệu quả. Hãy khám phá chi tiết cách sử dụng vòng lặp for ngay nào"
chapter:
  name: "Vòng lặp"
  slug: "chuong-04-loops"
category:
  name: "C"
  slug: "c"
image: https://user-images.githubusercontent.com/29374426/127596066-fa46df01-982f-4a72-b6d1-f7d8f5c5a9b3.png
position: 1
---

Vòng lặp **`for`** được sử dụng để duyệt qua các phần tử trong một tập hợp. Nó thường được sử dụng khi bạn có một khối câu lệnh cần được thực thi **`n`** lần, có nghĩa là bạn biết được số lượng vòng lặp cần thực hiện.

## Cấu trúc vòng lặp for trong C

Cú pháp cơ bản của vòng lặp "for" trong C như sau:

```cpp
for (khởi tạo giá trị biến lặp; điều kiện lặp; cập nhật biến lặp) {

   // statements inside the body of loop
}
```

- `khởi tạo giá trị biến lặp`: Điều này thường là một biến dùng để kiểm soát số lần lặp. Bạn có thể khởi tạo giá trị ban đầu của biến ở đây.
- `điều kiện lặp`: Điều kiện được kiểm tra trước mỗi lần lặp. Nếu điều kiện trả về false, vòng lặp sẽ kết thúc.
- `cập nhật biến lặp`: Bước này thường là để thay đổi giá trị của biến lặp sau mỗi lần lặp.


Ví dụ:

```cpp
for (int i = 0; i <= 10; i++) {

   // statements inside the body of loop
}
```

## Vòng lặp hoạt động như thế nào?

![Vòng lặp hoạt động như thế nào](https://user-images.githubusercontent.com/29374426/183098010-5ac9e1d3-66cb-4a83-8a3e-103365f3d933.png)

- Bước 1: Khởi tạo giá trị biến lặp.
    Bước này chỉ diễn ra một lần duy nhất, ở đầu vòng lặp. Nó được sử dụng để khởi tạo biến lặp và thường được thực hiện một lần duy nhất.
- Bước 2: Kiểm tra điều kiện lặp.
    Trước mỗi lần lặp, điều kiện lặp được kiểm tra. Nếu điều kiện trả về **`false`**, vòng lặp kết thúc. Nếu trả về **`true`**, vòng lặp tiếp tục.
- Bước 3: Thực Hiện Câu Lệnh Trong Vòng Lặp.
    Tuy nhiên, nếu biểu thức kiểm tra bằng **`true`**, các câu lệnh bên trong phần thân của vòng lặp **`for`** được thực thi.
- Bước 4: Cập Nhật Biến Lặp.
    Cập nhật giá trị biến lặp và quay trở lại bước 2 để kiểm tra.

Quá trình này diễn ra cho đến khi biểu thức điều kiện (bước 2) kiểm tra là **`false`**. Khi biểu thức điều kiện kiểm tra là **`false`**, vòng lặp chấm dứt.

## Luồng của vòng lặp for

![Luồng của vòng lặp for](https://user-images.githubusercontent.com/29374426/183098078-3a8046f5-14f4-4194-aae2-db4154e17ee8.png)

## Example

Ví dụ 1:

> In ra các số từ 1 đến 10.

```cpp
#include <stdio.h>

int main() {

    for (int i = 1; i <= 10; i++) {
        printf("%d\n", i);
    }

    printf("End loop!\n");
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
End loop!</br>
::

Giải thích:

- Bước 1. Gán biến lặp `i = 1` - thực hiện 1 lần duy nhất.
- Bước 2. Kiểm tra điều kiện `(i = 1) < 10` → **`true`**.
- Bước 3. Do kiểm tra điều kiện **`true`** → Thực hiện thân vòng lặp **`for`** → in ra giá trị của `i`.
- Bước 4. Gọi tới `i++` → tăng `i` lên `1` đơn vị → lúc này `i = 2`.
- Bước 5. Quay lại bước 2 và chạy lại.
- Chúng ta sẽ lặp đi lặp lại bước 2 đến bước 5 cho đến khi `i = 11`, lúc này bước 2 sẽ trả về **`false`** → Kết thúc luôn vòng lặp.

Ví dụ 2:

> In ra các số chẵn từ 1 đến 10.

```cpp
#include <stdio.h>

int main() {

    for (int i = 1; i <= 10; i++) {
        if (i % 2 == 0) {
            printf("%d\n", i);
        }
    }

    printf("End loop!\n");
}
```

::result
2</br>
4</br>
6</br>
8</br>
10</br>
End loop!</br>
::

Chúng ta còn có một cách khác là sửa lại vòng lặp như sau:

```cpp
#include <stdio.h>

int main() {

    for (int i = 2; i <= 10; i = i + 2) {
        printf("%d\n", i);
    }

    printf("End loop!\n");
}
```

Ví dụ 3:

> Tính tổng các số từ 1 đến 10.

```cpp
#include <stdio.h>

int main() {

    int sum = 0;
    for (int i = 1; i <= 10; i++) {
        sum += i;
    }

    printf("sum = %d\n", sum);
    printf("End loop!\n");
}
```

::result
sum = 55</br>
End loop!</br>
::
