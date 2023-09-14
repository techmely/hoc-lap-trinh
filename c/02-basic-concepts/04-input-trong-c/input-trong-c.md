---
title: "Input trong C"
description: "Hiểu cách nhận và xử lý dữ liệu đầu vào trong C là một phần quan trọng để tạo ra các ứng dụng có khả năng tương tác với người dùng và thực hiện các tính toán phức tạp. Hãy bắt đầu khám phá cách tạo các chương trình mà có thể đọc và sử dụng thông tin từ nhiều nguồn khác nhau"
chapter:
  name: "Nhập môn C"
  slug: "chuong-02-basic-concepts"
category:
  name: "C"
  slug: "c"
image: https://user-images.githubusercontent.com/29374426/127596066-fa46df01-982f-4a72-b6d1-f7d8f5c5a9b3.png
position: 4
---

Chúng ta đã được tìm hiểu về cách khởi tạo, gán giá trị và in ra giá trị của biến, nhưng thực tế trong một chương trình, các giá trị cần được người dùng nhập từ bàn phím vào để tính toán hay sử dụng.

Vì vậy hôm nay chúng ta sẽ sang tìm hiểu về cách lấy giá trị nhập từ bàn phím và gán vào cho một biến cụ thể trong C thông qua hàm `scanf()`.

Trong ngôn ngữ lập trình C, hàm `scanf()` được sử dụng để đọc vào ký tự, chuỗi, các giá trị số mà người dùng nhập từ bàn phím.

## Nhập một giá trị từ bàn phím

Chúng ta cùng xem qua ví dụ sau:

```cpp
#include <stdio.h>

int main() {

    int n;  // khai báo nhưng không gán giá trị cho n

    printf("Enter n: "); // in ra thông báo cho người dùng biết sẽ phải làm gì
    scanf("%d", &n);     // cú pháp của hàm scanf()

    printf("%d", n);     // in ra giá trị của n
}
```

Các bạn có thể thấy hàm `scanf()` có các thành phần khá giống với hàm `printf()`. Chúng ta sẽ cùng đi tìm hiểu chi tiết.

Trong hàm `scanf()` có 2 phần chính:

- `"%d"` - định dạng này chúng ta đã nói ở phần in ra giá trị của biến, trong hàm `scanf()` nó có ý nghĩa để báo cho hàm `scanf()` sẽ nhận vào từ bàn phím kiểu giá trị nào. Ví dụ trên là muốn lấy giá trị một số nguyên từ bàn phím nên chúng ta dùng `%d`, nếu bạn muốn lấy một giá trị `float` thì cần thay thế `%d` bằng `%f`...
- `&n` - phần này có ý nghĩa báo cho hàm `scanf()` sẽ gán giá trị vừa nhận được cho biến nào, ở đây là biến `n` và chúng ta cần viết thêm ký tự `&` trước biến muốn gán giá trị vào.

::alert{type="infor"}

- Cần xác định kiểu dữ liệu của biến cần gán giá trị trước để chọn định dạng `%` trong hàm `scanf()` cho đúng.
- Không giống như hàm `printf()`, chúng ta không được viết thêm bất cứ đoạn text nào trong hàm `scanf()` ngoài định dạng `%`. Nếu bạn viết thêm text, chương trình sẽ chạy ra kết quả không như mong muốn.
::

Kết quả khi chạy chương trình:

::result
Enter n: _
::

Lúc này các bạn sẽ thấy chương trình không kết thúc như những ví dụ trước, mà sẽ tạm dừng tại đây - bạn sẽ thấy có con trỏ `_` nhấp nháy báo hiệu chương trình đang đợi bạn nhập một giá trị vào từ bàn phím.

Và đây là kết quả khi chúng ta nhập vào một số, ví dụ nhập n = 5:

::result
Enter n: 5
5
::

## Nhập nhiều giá trị từ bàn phím

Chúng ta cũng có thể nhập nhiều giá trị một lúc cho nhanh bằng cách nhập nhiều giá trị trên cùng một dòng, mỗi giá trị cách nhau bằng một `space`.

Ví dụ:

```cpp
#include <stdio.h>

int main() {

    int a, b, c;
    printf("Enter a b c: ");
    scanf("%d %d %d", &a, &b, &c); // gán giá trị cho 3 biến a, b, c cùng một lần

    printf("a = %d\nb = %d\nc = %d", a, b, c);
}
```

Kết quả:

::result
Enter a b c: 1 2 3
a = 1
b = 2
c = 3
::

Bạn cũng có thể nhập mỗi giá trị cách nhau bằng một dấu phẩy `,` như sau:

```cpp
#include <stdio.h>

int main() {

    int a, b, c;
    printf("Enter a b c: ");
    scanf("%d, %d, %d,", &a, &b, &c); // gán giá trị cho 3 biến a, b, c cùng một lần

    printf("a = %d\nb = %d\nc = %d", a, b, c);
}
```

Kết quả:

::result
Enter a b c: 1, 2, 3
a = 1
b = 2
c = 3
::
