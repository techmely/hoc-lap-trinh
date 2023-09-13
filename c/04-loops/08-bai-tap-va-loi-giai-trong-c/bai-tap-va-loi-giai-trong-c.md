---
title: "Bài tập và lời giải trong C"
description: "Cùng tổng hợp những kiến thức đã học được trong phần vừa rồi bằng cách giải các bài tập đơn giản trong phần này nào."
chapter:
  name: "Vòng lặp"
  slug: "chuong-04-loops"
category:
  name: "C"
  slug: "c"
image: https://user-images.githubusercontent.com/29374426/127596066-fa46df01-982f-4a72-b6d1-f7d8f5c5a9b3.png
position: 8
---

Ở bài này, chúng ta sẽ cùng nhau ôn luyện làm bài và phân tích chi tiết cách giải quyết các bài toán trong lập trình qua ví dụ cụ thể.

## Bài 1

> **Kiểm tra số `n` có phải số nguyên tố hay không.**

### Khái niệm số nguyên tố

_Số nguyên tố là số nguyên dương có duy nhất 2 ước phân biệt là `1` và chính nó. Lưu ý: Số 1 không phải số nguyên tố do chỉ có 1 ước._

### Ý tưởng kiểm tra số nguyên tố

- Nếu `n < 2`, kết luận `n` không phải số nguyên tố. Sử dụng **`if`** để kiểm tra `n`.
- Đếm số ước của `n` trong đoạn từ `2` đến căn bậc hai của `n` (sử dụng **`for`**). Nếu `n` không có ước nào trong đoạn từ `2` đến căn bậc hai của `n` thì nó là số nguyên tố (sử dụng **`if`** để kiểm tra). Ngược lại thì không phải.

### Tại sao lại chỉ đếm các ước trong đoạn từ `2` đến căn của `n`?

Nếu bạn để ý thì một số nguyên `>= 2` bất kỳ sẽ luôn có số ước ở nửa đầu căn bậc 2 của nó bằng số ước ở nửa sau căn bậc 2 của nó. Cụ thể, các ước sẽ phân bố thành 2 miền từ `2 → sqrt(n)` và từ `sqrt(n) → n`.

Phân tích cụ thể:

> Với số **12**, ta có `sqrt(12) ≈ 3.464`  
> Đoạn [ 2 → 3.464 ] có ước bằng 2, tương ứng đoạn [ 3.464 → 12 ] có ước bằng 6.
> Đoạn [ 2 → 3.464 ] có ước bằng 3, tương ứng đoạn [ 3.464 → 12 ] có ước bằng 4.
> Trong đoạn [ 2 → 3.464 ] số **12** chia hết cho 2 số [ 2, 3 ] → **12** không phải là số nguyên tố.

> Với số **9**, ta có `sqrt(9) = 3`
> Đoạn [ 2 → 3 ] có ước 3, tương ứng đoạn [ 3 → 9 ] có ước 3.
> Trong đoạn [ 2 → 3 ] số **9** chia hết cho 1 số [ 3 ] → **9** không phải là số nguyên tố.

> Với số **7**, ta có `sqrt(7) ≈ 2.646`  
> Trong đoạn từ [ 2 → 2.646 ] không có số nguyên nào mà **7** chia hết → **7** là số nguyên tố.

### Triển khai code

Qua phân tích bên trên chúng ta có thể nhận thấy chương trình này cần kết hợp nhiều thứ đã học lại từ trước đến này bao gồm:

- Thư viện **`math.h`** cụ thể là hàm **`sqrt()`** để tính căn bậc 2.
- **`if`** để kiểm tra một số điều kiện.
- **`for`** dùng để duyệt từ `2` đến `n` để đếm số ước của `n`.

Code hoàn chỉnh:

```cpp
 1    #include <stdio.h>
 2    #include <math.h>
 3
 4    int main() {
 5
 6        int n;
 7
 8        printf("Enter n: ");
 9        scanf("%d", &n);
10
11        if (n < 2) {
12            printf("n is not a prime number.\n");
13            return 0;
14        }
15
16        int check = 1;
17        for (int i = 2; i <= sqrt(n); i++) {
18            if (n % i == 0) {
19                printf("n is not a prime number.\n");
20                check = 0;
21                break;
22            }
23        }
24
25        if (check) {
26            printf("n a prime number.\n");
27        }
28    }
```

Kết quả khi chạy chương trình:

```cpp
Enter n: 1
n is not a prime number.
```

```cpp
Enter n: 11
n a prime number.
```

```cpp
Enter n: 12
n is not a prime number.
```

**`return`** - đây là từ khoá dùng để kết thúc một hàm xử lý, khi gặp từ khoá **`return`** thì chương trình sẽ không chạy tiếp các dòng mã bên dưới từ **`return`** nữa. Trong ví dụ trên, khi nhập `n < 2` thì chương trình sẽ chạy vào câu lệnh **`if`** (line 11) và thực hiện lệnh `return 0;` (line 13) - lúc này **chương trình sẽ kết thúc** và những dòng mã từ line 15 → line 27 sẽ **không** được thực hiện.

**`break`** - tại sao lại dùng **`break`** tại đây? Vì trong khoảng từ `2 → sqrt(n)` có thể có rất nhiều ước của `n`, chúng ra chỉ cần tìm thấy 1 ước đầu tiên là kết luận được `n is not a prime number` mà không cần chạy hết vòng lặp (dư thừa không cần thiết). Bạn có thể đọc lại về **`break`** [tại đây](/bai-viet/c/cau-lenh-break-trong-c).

## Bài tập tự luyện tập

### Bài 1

> **Nhập một số nguyên `n` từ bàn phím. Đếm số lần `xuất hiện` của số chẵn từ 0 cho đến bằng số nguyên `n`.**

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

```cpp
Enter the number: 10

OUTPUT:
The number of occurrences of even number is 6
--------------------------------
```

### Bài 2

> **Nhập một số nguyên `n` từ bàn phím. Tính tổng tất cả các `số chẵn` trong khoảng từ 0 cho đến bằng số nguyên `n`.**

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

```cpp
Enter the number: 10

OUTPUT:
result is 30
--------------------------------
```

### Bài 3

> **Nhập một số nguyên `n` từ bàn phím. Tính tổng tất cả các `số chữ số ` của số nguyên `n`.**

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

```cpp
Enter the number: 12345

OUTPUT:
Sum of digits in 0 is 15

--------------------------------
```
