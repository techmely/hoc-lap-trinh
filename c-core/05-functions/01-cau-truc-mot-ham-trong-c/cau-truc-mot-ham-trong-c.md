---
title: "Cấu trúc một hàm trong C"
description: "Cấu trúc một hàm trong C"
keywords:
  ["học lập trình c", "khoá học lập trình c", "Khoá học lập trình c căn bản"]
chapter:
  name: "Hàm"
  slug: "chuong-05-functions"
category:
  name: "C"
  slug: "c-core"
image: https://user-images.githubusercontent.com/29374426/127596066-fa46df01-982f-4a72-b6d1-f7d8f5c5a9b3.png
position: 1
---

Trong bài này chúng ta sẽ cùng nhau tìm hiểu về cấu trúc của một hàm (function) trong C.

## Khai báo và khởi tạo hàm trong C

Cú pháp để khai báo 1 hàm như sau:

`kiểu dữ liệu` `tên hàm` `() { }` ;

Ví dụ một hàm do người dùng định nghĩa:

```c
int sum() {
    //
    return sum;
}
```

- `int` chính là kiểu dữ liệu của hàm, các kiểu dữ liệu của hàm giống với kiểu dữ liệu của biến. Kiểu dữ liệu của hàm quyết định giá trị trả về của hàm đó.
- `sum` là tên của hàm do lập trình viên tự đặt tên, quy tắc đặt tên hàm giống với quy tắc đặt tên biến. Tên hàm sẽ thể hiện chức năng của hàm đó làm gì. Ở đây hàm `sum()` sẽ có ý nghĩa - chức năng tính tổng các số nguyên.
- Một hàm sẽ có thêm `()` sau tên hàm và body code nằm trong block code `{ }`.
- `()` là nơi truyền **tham số** cho hàm. Cụ thể chúng ta sẽ tìm hiểu ở bên dưới.
- Kết thúc hàm luôn luôn phải có `return` để trả về kết quả cho hàm. Ví dụ ở đây khi hàm `sum()` tính tổng xong thì chúng ta cần phải `return` lại kết quả tổng đã tính được.

Ví dụ một hàm hệ thống:

```c
double sqrt(double x) {
    //
    return result;
}
```

- `double` chính là kiểu dữ liệu của hàm này.
- `sqrt` là tên của hàm do lập trình viên viết lên C định đặt tên.
- Ở hàm này chúng ta có thể thấy trong `()` có một biến `double x`. Biến `x` được gọi là tham số của hàm `sqrt()`. Ở đây bạn có thể hiểu hàm `sqrt()` sẽ tính kết quả căn bậc 2 của 1 số mà chúng ta mong muốn, vì chúng ta chưa biết chính xác số đó là gì nên chúng ta sẽ dùng một biến đại diện để tính toán, ở đây chính là biến `x`. Hàm `sqrt()` sẽ tính giá trị căn bậc 2 của `x` và trả về kết quả thông qua `return`.

Cùng xem lại cách sử dụng hàm `sqrt()`:

```c
#include <stdio.h>
#include <math.h>

int main() {

    double result;
    result = sqrt(9);

    printf("result = %.2lf", result);
}
```

- Nhìn cấu trúc hàm `sqrt()` bên trên bạn có thể thấy là lúc sử dụng hàm, chúng ta đã thay thế biến `x` bằng một số cụ thể là `9` để tính toán.
- Vì hàm `sqrt()` có kiểu dữ liệu là `double` nên chúng ta cần khai báo biến `double result` để lấy kết quả trả về của hàm `sqrt()` gán vào biến `result`.

Kết quả:

```c
result = 3.00
```
