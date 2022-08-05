---
title: "Vòng lặp while trong C"
description: "Vòng lặp while trong C"
keywords:
  ["học lập trình c", "khoá học lập trình c", "Khoá học lập trình c căn bản"]
chapter:
  name: "Vòng lặp"
  slug: "chuong-04-loops"
category:
  name: "C"
  slug: "c"
image: https://user-images.githubusercontent.com/29374426/127596066-fa46df01-982f-4a72-b6d1-f7d8f5c5a9b3.png
position: 2
---

Vòng lặp **`while`** cũng được sử dụng để lặp lại một khối câu lệnh. Nó sẽ kiểm tra điều kiện trước khi bắt đầu vòng lặp để quyết định xem có thực hiện vòng lặp hay không. Khối câu lệnh bên trong vòng lặp sẽ được thực hiện 1 hoặc nhiều lần cho đến khi kiểm tra điều kiện trả về bằng **`false`** thì sẽ kết thúc vòng lặp.

Nên sử dụng vòng lặp **`while`** khi bạn không biết rõ số lượng vòng lặp - chỉ biết điều kiện dừng.

## Cấu trúc của vòng lặp while

```c
while (testExpression) {

    // statements inside the body of the loop
}
```

Ví dụ:

```c
int i = 0;

while (i < 10) {

    // statements inside the body of the loop
    // need to update the value of i
}
```

## Vòng lặp while hoạt động như thế nào?

- Đầu tiên vòng lặp **`while`** đánh giá biểu thức kiểm tra điều kiện bên trong ngoặc đơn `()`.
- Nếu biểu thức kiểm tra là **`true`**, các câu lệnh bên trong thân vòng lặp **`while`** được thực thi. Các câu lệnh thực thi bên trong thân vòng lặp cần phải cập nhật lại biểu thức kiểm tra điều kiện.
- Sau đó, biểu thức kiểm tra điều kiện được đánh giá lại.
- Quá trình diễn ra cho đến khi biểu thức kiểm tra được đánh giá là **`false`**.
- Nếu biểu thức kiểm tra là **`false`**, vòng lặp chấm dứt (kết thúc).

## Luồng hoạt độngc ủa vòng lặp white

<p align="center">
  <img src="https://github.com/AnestLearning/Course-C-Fundamentals/blob/master/Images/c-while-loop.jpg">
</p>

## Ví dụ vòng lặp white trong c

Ví dụ 1:

> In ra các số từ `1` đến `5`.

```c
#include <stdio.h>

int main() {

    int i = 1;

    while (i <= 5) {
        printf("%d\n", i);
        ++i;
    }
}
```

Kết quả:

```c
1
2
3
4
5
```

Giải thích:

- Vì `i` sẽ được dùng để kiểm tra điều kiện nên chúng ta cần phải khởi tạo và gán giá trị cho `i` trước.
- Khi `i = 1`, biểu thức kiểm tra `i <= 5` trả về **`true`**. Do đó, phần thân của vòng lặp **`while`** được thực hiện.
  - In `1` trên màn hình.
  - Tăng giá trị của `i` lên `1` → `i = 2`.
- Tiếp theo ta có `i = 2`, biểu thức kiểm tra `i <= 5` lại trả về **`true`**. Phần thân của vòng lặp **`while`** được thực hiện lại.
  - In `2` trên màn hình.
  - Tiếp tục tăng giá trị của `i` lên `1` → `i = 3`.
- Quá trình này diễn ra cho đến khi `i = 6`. Lúc này biểu thức kiểm tra `i <= 5` trả về **`false`** → vòng lặp chấm dứt.

Ví dụ 2:

> Nhập một số `n` từ bàn phím. Tính tổng các số của `n`. Ví dụ: `n = 2456` → `sum = 2 + 4 + 5 + 6 = 17`.

Phân tích bài toán:

- Để cộng tổng các số của `n`, chúng ta cần tách được riêng từng số của `n` ra bằng cách lấy `n` chia lấy dư cho `10`. Chúng ta sẽ lấy được số hàng đơn vị là số `4`, cộng `4` vào biến `sum`.
- Sau đó chúng ta cần bỏ đi hàng đơn vị để được số `69` bằng cách lấy `n = 694` chia cho `10` (n = 694 / 10 = 69).
- Chúng ta lại lấy `n = 69` chia lấy dư cho `10` để lấy được số hàng đơn vị là số `9`, cộng `9` vào biến `sum`.
- Sau đó lại tiếp tục lấy `n = 69` chia cho `10` để còn `n = 6`.
- ...
- Các bạn có thể thấy chúng ta sẽ lặp đi lặp lại 2 việc chính đối với `n` đó là:
  - Chia lấy dư cho `10`
  - Chia hết cho `10`
- Vì vậy chúng ta cần dùng vòng lặp để làm bài này, vậy nên chọn vòng lặp nào?
- Bạn không thể biết người dùng sẽ nhập số nào? (số dài hay ngắn) nên rõ ràng chúng ta không thể biết cần lặp bao nhiêu lần?
  - Vì vậy chúng ra sẽ dùng vòng lặp **`while`** thay vì **`for`**.
- Vậy điều kiện dừng là gì? Đề bài không thấy nói đến?
  - Bạn có nhận thấy mỗi lần chia hết cho `10` thì `n` sẽ giảm dần giá trị, và cuối cùng khi `n < 10` hay là `n` chỉ còn 1 chữ số thì `n / 10 = 0`. Vì vậy chúng ta sẽ có điều kiện dừng ở đây là `n > 0`.

Solution code:

```c
#include <stdio.h>

int main() {

    int n;
    int sum = 0;

    printf("Enter n: ");
    scanf("%d", &n);

    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }

    printf("sum = %d", sum);
}
```

Kết quả:

```c
Enter n: 694
sum = 19
```
