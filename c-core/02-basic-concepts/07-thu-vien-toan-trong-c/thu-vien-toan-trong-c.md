---
title: "Thư viện toán trong C"
description: "Thư viện toán trong C"
keywords:
  ["học lập trình c", "khoá học lập trình c", "Khoá học lập trình c căn bản"]
chapter:
  name: "Nhập môn C"
  slug: "chuong-02-basic-concepts"
category:
  name: "C"
  slug: "c"
image: https://user-images.githubusercontent.com/29374426/127596066-fa46df01-982f-4a72-b6d1-f7d8f5c5a9b3.png
position: 7
---

Chúng ta đã từng sử dụng 2 hàm `printf()` và `scanf()` trong thư viện `stdio.h`. Các bạn phải hiểu rằng còn nhiều thư viện khác nữa, mỗi thư viện sẽ chứa những hàm với những cụm chức năng riêng biệt.

Và ở bài trước chúng ta đã tìm hiểu qua những phép tính toán đơn giản trong C, hôm nay chúng ta sẽ cùng tìm hiểu những phép tính toán phức tạp hơn và hiệu quả hơn thông qua một thư viện hỗ trợ mới là `math.h`, nó chứa những hàm xử lý toán học đã được viết trước.

## Các hàm xử lý toán học trong thư viện math.h

| STT | Tên hàm                                | Mô tả                                               |
| --- | -------------------------------------- | --------------------------------------------------- |
| 1   | `double cos(double x)`                 | Trả về cos của một góc radian x.                    |
| 2   | `double sin(double x)`                 | Trả về sin của một góc radian x.                    |
| 3   | `double exp(double x)`                 | Trả về giá trị của e mũ x.                          |
| 4   | `double ldexp(double x, int exponent)` | Trả về x \* 2^exp.                                  |
| 5   | `double log(double x)`                 | Trả về logarit tự nhiên (logarit cơ sở) của x.      |
| 6   | `double log10(double x)`               | Trả về logarit chung (logarit cơ sở 10) của x.      |
| 7   | `double pow(double x, double y)`       | Trả về x mũ y.                                      |
| 8   | `double sqrt(double x)`                | Trả về căn bậc hai của x.                           |
| 9   | `double ceil(double x)`                | Trả về giá trị nguyên nhỏ nhất lớn hơn hoặc bằng x. |
| 10  | `double fabs(double x)`                | Trả về giá trị tuyệt đối của x.                     |
| 11  | `double floor(double x)`               | Trả về giá trị nguyên lớn nhất nhỏ hơn hoặc bằng x. |
| 12  | `double fmod(double x, double y)`      | Trả về số dư còn lại của x chia cho y.              |

## Một số ví dụ mình hoạ:

### Hàm fabs

Hàm này sẽ trả về **giá trị tuyệt đối** của một số, trong toán học viết là `| |`.

Ví dụ:

```cpp
#include <stdio.h>
#include <math.h>

int main() {

    int a;
    a = fabs(-5);

    printf("a = %d", a);
}
```

Kết quả chương trình:

```cpp
a = 5
```

### Hàm ceil

Hàm này sẽ **trả về giá trị dạng số nguyên** nếu như ta đưa cho nó một số thực. Hay chúng ta còn gọi là **làm tròn số**, nhưng hàm `ceil` sẽ luôn làm tròn giá trị lên (tăng giá trị).

Ví dụ:

```cpp
#include <stdio.h>
#include <math.h>

int main() {

    int a;
    int b;

    a = ceil(5.125);
    a = ceil(5.7);

    printf("a = %d, b = %d", a, b);
}
```

Kết quả chương trình:

```cpp
a = 6, b = 6
```

### Hàm floor

Trái ngược với hàm `ceil`, hàm `floor` sẽ luôn làm tròn giá trị xuống (giảm giá trị).

Ví dụ:

```cpp
#include <stdio.h>
#include <math.h>

int main() {

    int a;
    int b;

    a = ceil(5.125);
    a = ceil(5.7);

    printf("a = %d, b = %d", a, b);
}
```

Kết quả chương trình:

```cpp
a = 5, b = 5
```

### Hàm pow

Hàm này cho phép tính **lũy thừa** một số. Chúng ta phải chỉ ra cho nó 2 giá trị: số hạng và cấp lũy thừa của số đó. Đây là cấu trúc của hàm này:

`pow(number, exponential)`

Ví dụ:

```cpp
#include <stdio.h>
#include <math.h>

int main() {

    int a = 4;
    int b = 3;

    int c = pow(a, b); // tương đương pow(4, 3) <=> 4^3

    printf("c = %d", c);
}
```

Kết quả chương trình:

```cpp
c = 64
```

### Hàm sqrt

Hàm này sẽ tính **căn bậc 2** của một số được truyền vào. Giá trị trả về có thể là **số nguyên** hoặc **số thập phân**.

Ví dụ:

```cpp
#include <stdio.h>
#include <math.h>

int main() {

    int a;
    double b;

    a = sqrt(9);
    b = sqrt(15);

    printf("a = %d, b = %lf", a, b);
}
```

Kết quả chương trình:

```cpp
a = 3, b = 3.872983
```

### Hàm exp

Hàm này sẽ tính **exponential**, hay còn gọi là **lũy thừa cơ số e**. Trả về giá trị là một **số thập phân**.

Ví dụ:

```cpp
#include <stdio.h>
#include <math.h>

int main() {

    double a;

    a = exp(5); // tương đương e^5

    printf("a = %lf", a);
}
```

Kết quả chương trình:

```cpp
a = 148.413159
```
