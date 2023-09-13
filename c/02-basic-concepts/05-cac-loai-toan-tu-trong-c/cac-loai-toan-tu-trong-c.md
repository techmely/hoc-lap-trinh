---
title: "Các loại toán tử trong C"
description: "Các loại toán tử  là một phần quan trọng trong quá trình học lập trình bằng ngôn ngữ C. Các loại toán tử cơ bản như toán tử số học (+, -, *, /), toán tử gán (=), toán tử so sánh (==, <, >), toán tử logic (&&, ||), và nhiều loại toán tử khác sẽ quyết định cách thực hiện các phép tính và thao tác trên dữ liệu."
chapter:
  name: "Nhập môn C"
  slug: "chuong-02-basic-concepts"
category:
  name: "C"
  slug: "c"
image: https://user-images.githubusercontent.com/29374426/127596066-fa46df01-982f-4a72-b6d1-f7d8f5c5a9b3.png
position: 5
---

Trong bài này chúng ta sẽ cùng nhau tìm hiểu về những loại toán tử trong lập trình C.

## Toán tử số học trong C

Đầu tiên chúng ta sẽ cùng nhau thực hiện những phép tính toán toán học cơ bản trong lập trình C.

Hãy xem qua ví dụ sau:

```cpp
#include <stdio.h>

int main() {

    int result;
    result = 5 + 3;

    // hiển thị ra kết quả lên màn hình
    printf("result = %d", result);
}
```

Kết quả:

```cpp
result = 8
```

Và đó là phép cộng.
Và với những phép toán khác, cũng tương tự, chỉ cần thay đổi kí tự tính toán như sau:

| Định dạng | Phép toán                              |
| :-------: | -------------------------------------- |
|    `+`    | Phép cộng - addition                   |
|    `-`    | Phép trừ - subtraction                 |
|    `*`    | Phép nhân - multiplication             |
|    `/`    | Phép chia - division                   |
|    `%`    | Phép chia lấy dư - modulo or remainder |

Các phép tính toán trên được gọi là **toán tử số học (Arithmetic Operators)**.

### Ví dụ về phép nhân `*`

```cpp
#include <stdio.h>

int main() {

    int result;
    result = 5 * 3;

    // hiển thị ra kết quả lên màn hình
    printf("result = %d", result);
}
```

Kết quả:

```cpp
result = 15
```

### Ví dụ phép chia lấy dư `%`

```cpp
#include <stdio.h>

int main() {

    int result;
    result = 5 % 3;

    // hiển thị ra kết quả lên màn hình
    printf("result = %d", result);
}
```

Kết quả:

```cpp
result = 2
```

#### Một số lưu ý

- Khi lưu kết quả tính toán, cần phải xác định kiểu dữ liệu của kết quả để tạo đúng kiểu dữ liệu cho biến lưu kết quả. Như 3 ví dụ trên, kết quả cộng, nhân, chia lấy dư của 2 số nguyên sẽ trả về kết quả là 1 số nguyên -> vì vậy biến `result` được khai báo kiểu `int`.
- Khi hiển thị cũng cần khai báo đúng định dạng `%` hiển thị của kiểu dữ liệu trong câu lệnh `printf()`.

#### Lưu ý với phép chia `/`

Riêng với phép chia, kết quả chúng ta nhận được sẽ có 2 trường hợp:

- Số nguyên
- Số thập phân

Vì vậy các bạn cần phải chú ý phần lưu ý bên trên -> `tạo đúng kiểu dữ liệu cho biến lưu kết quả` để nhận được kết quả chính xác.

### Ví dụ phép chia hết (không có số dư)

```cpp
#include <stdio.h>

int main() {

    // xác định được kết quả là số nguyên nên khai báo kiểu dữ liệu cho biến result là int
    int result = 0;
    result = 8 / 4;

    // hiển thị ra kết quả lên màn hình
    printf("result = %d", result);
}
```

Kết quả:

```cpp
result = 2
```

### Ví dụ phép chia có số dư

```cpp
#include <stdio.h>

int main() {

    // xác định được kết quả là số thập phân những vẫn khai báo kiểu dữ liệu cho biến result là int
    int result = 0;
    result = 5 / 2;

    // hiển thị ra kết quả lên màn hình
    printf("result = %d", result);
}
```

Ở ví dụ này bạn **KHÔNG** thay đổi kiểu dữ liệu cho biến `result` là `float` mà vẫn giữ là `int`, kết quả của bạn sẽ được làm tròn mất đi phần thập phân sau dấu phẩy - kết quả nhận được sẽ bị sai như sau:

```cpp
result = 2
```

Chúng ta sẽ sửa lại như sau:

```cpp
#include <stdio.h>

int main() {

    // xác định được kết quả là số thập phân nên khai báo kiểu dữ liệu cho biến result là float
    float result = 0;
    result = 5 / 2;

    // hiển thị ra kết quả lên màn hình
    printf("result = %f", result);
}
```

**NHƯNG** khi làm đúng với ví dụ, chúng ta lại nhận được một kết quả vẫn không chính xác như sau:

```cpp
result = 2.000000
```

**VÌ SAO LẠI NHƯ VẬY?**

Các bạn hãy chuyển sang đọc tiếp riêng một bài viết về vấn đề này tại đây [Type Conversion](/bai-viet/c/chuyen-doi-kieu-du-lieu-trong-c)

## Tăng giá trị và giảm giá trị trong

### Incrementing (Phương pháp tăng giá trị)

Trong qua trình học lập trình C, bạn sẽ thấy rằng - bạn sẽ phải thường xuyên tăng giá trị một biến số lên 1. Và ta làm như sau:

```cpp
#include <stdio.h>

int main() {

    int index = 0;
    index = index + 1;
}
```

Chúng ta lấy `index + 1`, và sau đó giá trị của `index` sẽ được tăng lên 1 đơn vị và được gán lại vào chính biến số `index`.

Và họ đã tạo ra một cách viết rút gọn gọi là **increment**. Đoạn mã sau cũng biểu thị điều tương tự với đoạn mã ta vừa thấy ở trên:

```cpp
#include <stdio.h>

int main() {

    int index = 0;
    index++;
}
```

Đoạn mã này khá ngắn so với những gì ta thấy trước đó, chỉ cần viết tên biến số, sau đó thêm vào hai dấu cộng liên tiếp `++`, và đừng quên dấu chấm phẩy đặt ở cuối cùng.

### Decrementing (Phương pháp giảm giá trị)

Đơn giản có thể hiểu là phương pháp này tương tự với **increment** nhưng là giảm đi giá trị. Chúng ta sẽ giảm giá trị của biến số đi 1. Và chúng ta cũng sẽ sử dụng nó thường xuyên như **increment**.

Nếu như ta viết nó đầy đủ:

```cpp
#include <stdio.h>

int main() {

    int index = 0;
    index = index - 1;
}
```

Thì đây là dạng rút gọn:

```cpp
#include <stdio.h>

int main() {

    int index = 0;
    index--;
}
```

### Kiểu tăng và giảm giá trị trong C

Toán tử **Increment** và **Decrement** được chia làm 2 loại tuỳ vào vị trí của dấu `++` hoặc `--` đứng trước hay sau một biến:

#### Tiền tố (Prefix)

> **Tiền tố (Prefix)**: tăng hoặc giảm giá trị của biến x, sau đó x được sử dụng để tính toán.

Ví dụ:

```cpp
#include <stdio.h>

int main() {

    int i = 9;
    int j = ++i;   // tăng luôn giá trị i lên bằng 10, và gán giá trị 10 cho j

    printf("i = %d\n", i);
    printf("j = %d", j);
}
```

Kết quả:

```cpp
i = 10
j = 10
```

#### Hậu tố (Postfix)

> **Hậu tố (Postfix)**: sử dụng x để tính toán, sau đó tăng hoặc giảm giá trị của biến x. Đối với trường hợp này, performance sẽ giảm vì compiler phải thực hiện nhiều hơn. Đầu tiên, compiler sẽ tạo một bản sao của x, sau đó biến x được tăng hoặc giảm, mọi tính toán trong biểu thức sẽ sử dụng giá trị của bản sao và bản sao sẽ được xóa sau khi sử dụng.

Ví dụ:

```cpp
#include <stdio.h>

int main() {

    int i = 9;
    int j = i++;   // giá trị 9 sẽ được gán cho j trước, rồi sau đó i mới được tăng lên bằng 10

    printf("i = %d\n", i);
    printf("j = %d", j);
}
```

Kết quả:

```cpp
i = 10
j = 9
```

## Assignment Operators

Toán tử gán được sử dụng để gán giá trị cho một biến. Toán tử gán phổ biến nhất là `=`. Hãy xem qua các toán tử gán phổ biến sau:

| Toán tử | Ví dụ    | Tương đương |
| :-----: | -------- | ----------- |
|   `=`   | `a = b`  | `a = b`     |
|  `+=`   | `a += b` | `a = a + b` |
|  `-=`   | `a -= b` | `a = a - b` |
|  `*=`   | `a *= b` | `a = a * b` |
|  `/=`   | `a /= b` | `a = a / b` |
|  `%=`   | `a %= b` | `a = a % b` |

Ví dụ nếu bạn muốn tăng giá trị của một biến lên 2 - chúng ta sẽ lấy biến đó cộng với 2 sau đó gán lại luôn giá trị vừa cộng được cho biến đó:

```cpp
#include <stdio.h>

int main() {

    int index = 0;
    index += 2;     // lúc này biến index sẽ có giá trị = 2
}
```

Với những phép toán cơ bản khác cũng hoạt động y như vậy, đây là một chương trình làm ví dụ:

```cpp
#include <stdio.h>

int main() {

    int index = 5;
    index += 4; // index tăng lên 4
    index -= 3; // index giảm đi 3
    index *= 5; // index nhân với 5
    index /= 3; // index chia cho 3
    index %= 3; // index chia lấy dư cho 3
}
```

**Trong lập trình C sẽ còn 2 loại toán tử nữa - nhưng chúng ta sẽ tìm hiểu về nó ở những bài sau đó là:**

- **Relational Operators (Toán tử quan hệ)**
- **Logical Operators (Toán tử logic)**
