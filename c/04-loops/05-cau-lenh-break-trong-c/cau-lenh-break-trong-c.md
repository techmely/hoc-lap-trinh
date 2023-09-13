---
title: "Câu lệnh break trong C"
description: "Câu lệnh 'break' là một công cụ quan trọng để kiểm soát và điều hướng luồng chương trình. Nó cho phép bạn thoát khỏi vòng lặp hoặc chấm dừng thực hiện các câu lệnh khi một điều kiện cụ thể được đáp ứng. Hãy xem chúng mình sử dụng break như thế nào trong bài này nha."
chapter:
  name: "Vòng lặp"
  slug: "chuong-04-loops"
category:
  name: "C"
  slug: "c"
image: https://user-images.githubusercontent.com/29374426/127596066-fa46df01-982f-4a72-b6d1-f7d8f5c5a9b3.png
position: 5
---

Câu lệnh **`break`** trong C là một câu lệnh điều khiển vòng lặp được sử dụng để chấm dứt vòng lặp. Ngay khi gặp câu lệnh **`break`** từ bên trong một vòng lặp, các vòng lặp sẽ dừng ngay ở đó và chương trình sẽ tiếp tục chạy đến câu lệnh tiếp theo sau vòng lặp.

Về cơ bản các câu lệnh **`break`** thường được sử dụng trong các tình huống khi chúng ta không chắc chắn về số lần lặp thực tế cho vòng lặp hoặc chúng ta muốn chấm dứt vòng lặp dựa trên một số điều kiện.

## Cú pháp câu lệnh break trong C

```cpp
break;
```

Câu lệnh **`break`** thường được sử dụng với câu lệnh **`if-else`** bên trong vòng lặp.

## Cách câu lệnh break hoạt động trong C

### Vòng lặp for trong C

![Vòng lặp for trong C](https://user-images.githubusercontent.com/29374426/183126406-356d321f-8277-4bd3-96ec-82572122c4d4.png)

### Vòng lặp do-while trong C

![Vòng lặp do-while trong C](https://user-images.githubusercontent.com/29374426/183126464-1d56b1ef-14a3-41fe-be18-6078ea8fb5d2.png)

### Vòng lặp while trong C

![Vòng lặp while trong C](https://user-images.githubusercontent.com/29374426/183126520-36c66aa6-52ad-4a55-b29c-0964137fb2be.png)

## Luồng hoạt động câu lệnh break trong C

![Luồng hoạt động câu lệnh break trong C](https://user-images.githubusercontent.com/29374426/183126557-c6fd7a77-01c5-4846-8ff6-a8b891d24dc2.png)

## Ví dụ về câu lệnh break trong C

Chúng ta sẽ cùng xem qua cách sử dụng lệnh **`break`** với ba loại vòng lặp:

- Vòng lặp đơn giản - Simple loops
- Vòng lặp lồng nhau - Nested loops
- Vòng lặp vô hạn - Infinite loops

Bây giờ chúng ta sẽ đi xem xét chi tiết các ví dụ cho từng loại trong ba loại vòng lặp trên.

### Một cấu trúc lặp đơn giản

Ví dụ:

> Chương trình tính tổng tối đa 10 số. Nếu nhập vào một số âm, vòng lặp chấm dứt và tính tổng các số được nhập vào trước đó.

```cpp
# include <stdio.h>

int main() {

    double n, sum = 0;

    for (int i = 1; i <= 10; ++i) {

        printf("Enter a n%d: ",i);
        scanf("%lf", &n);

        // If the user enters a negative number, the loop ends
        if(n < 0) {
            break;
        }

        sum += n;
    }

    printf("\nsum = %.2lf", sum);
}
```

Kết quả chương trình:

```cpp
Enter a n1: 4
Enter a n2: 5
Enter a n3: 8
Enter a n4: -2

sum = 17.00
```

Chương trình này tính tổng của tối đa 10 số. Nhưng vì sao mới nhập 3 số dương và 1 số âm nó đã dừng lại và tính tổng? Đó là bởi vì nếu người dùng nhập số âm, câu lệnh **`break`** được thực thi. Điều này sẽ kết thúc vòng lặp **`for`**, tổng được tính và hiển thị.

### Sử dụng break trong trường hợp vòng lặp lồng nhau

Chúng ta cũng có thể sử dụng lệnh **`break`** trong khi làm việc với các vòng lặp lồng nhau. Nếu câu lệnh **`break`** được sử dụng trong vòng lặp nào, nó sẽ chỉ chấm dứt vòng lặp đó.

Ví dụ:

> In ra hình chữ nhật.

```cpp
# include <stdio.h>

int main() {

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 6; j++) {
            printf("* ");
        }
        printf("\n");
    }
}
```

Kết quả chương trình:

```cpp
* * * * * *
* * * * * *
* * * * * *
```

Chúng ta có thể thấy vòng **`for i`** (**`for`** bên ngoài) sẽ chạy 3 lần (từ `0` → `2`). Vòng **`for j`** (**`for`** bên trong) sẽ chạy 6 lần (từ `0` → `5`).

Bây giờ chúng ta muốn vòng **`for j`** chỉ chạy 3 lần để **In ra hình vuông**, chúng ta sẽ kiểm tra điều kiện cho **`j`** và **`break`** như sau:

```cpp
# include <stdio.h>

int main() {

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 6; j++) {
            if (j > 2) {
                break;
            } else {
                printf("* ");
            }
        }
        printf("\n");
    }
}
```

Kết quả chương trình:

```cpp
* * *
* * *
* * *
```

Bạn có thể thấy vòng **`for i`** vẫn chạy 3 lần, **`break`** chỉ kết thúc vòng **`for j`**, nơi nó được viết mã khi thoã màn câu lệnh **`if-else`**.

### Sử dụng câu lệnh break cho vòng lặp vô tận

Hãy xem xét vòng lặp vô hạn dưới đây:

```cpp
#include <stdio.h>

int main() {

    int i = 0;

    while (1) {
        printf("%d\n", i);
        i++;
    }
}
```

::alert{type="warning"}
Lưu ý: Không chạy chương trình trên vì đây là một vòng lặp vô hạn, nó sẽ chạy mãi không dừng - bạn chỉ có thể dừng nó bằng cách tắt cửa sổ terminal đi.
::

Trong chương trình trên, điều kiện trong vòng lặp là `1` - có nghĩa là luôn luôn đúng. Vì vậy, vòng lặp thực hiện vô số lần hay còn gọi là vòng lặp vô hạn. Chúng ta có thể sửa lỗi này bằng cách sử dụng câu lệnh **`break`** như sau:

```cpp
#include <stdio.h>

int main() {

    int i = 0;

    while (1) {
      if(i > 5) {
            break;
        }

        printf("%d\n", i);
        i++;
    }
}
```

Kết quả chương trình:

```cpp
0
1
2
3
4
5
```

Ngoài ra, bạn cũng có thể thấy **`break`** được sử dụng trong các câu lệnh **`Switch`**.
