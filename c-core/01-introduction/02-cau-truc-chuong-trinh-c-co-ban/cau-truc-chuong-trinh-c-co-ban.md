---
title: "Cấu trúc chương trình C cơ bản"
description: "Cấu trúc chương trình C cơ bản"
keywords:
  ["học lập trình c", "khoá học lập trình c", "Khoá học lập trình c căn bản"]
chapter:
  name: "Giới thiệu"
  slug: "chuong-01-introduction"
category:
  name: "C"
  slug: "c"
image: https://user-images.githubusercontent.com/29374426/127596066-fa46df01-982f-4a72-b6d1-f7d8f5c5a9b3.png
position: 2
---

Dưới đây là một đoạn mã chương trình cơ bản nhất khi bắt đầu học lập trình với ngôn ngữ C.
Hãy sao chép đoạn mã ví dụ bên dưới vào **Dev C** và nhấn `F11` để chạy chương trình.

```cpp
#include <stdio.h>

int main() {

   printf("Hello World!\n");
   return 0;
}
```

Kết quả nhận được:

```cpp
Hello World!

--------------------------------
Process exited after 0.02965 seconds with return value 0
Press any key to continue . . .
```

Sau đây, chúng ta sẽ đi tìm hiểu các thành phần cơ bản bên dưới để giúp bạn bắt đầu với một chương trình C.

- **`#include <stdio.h>`**

  - Đây được gọi là dòng **khai báo thư viện** cho một chương trình C, `#include` là cú pháp còn tên thư viện sẽ nằm trong cặp dấu `< >`. Một chương trình C cơ bản luôn luôn cần thư viện `stdio.h` - là thư viện cơ bản và cốt lõi nhất.
  - Thư viện là nơi định nghĩa các câu lệnh mà mình sẽ viết bên dưới cho máy tính hiểu và có thể chạy được những gì mình viết.
  - Thư viện có khá nhiều và chia ra theo chức năng mà nó có thể làm, ví dụ `stdio.h` là thư viện `core` bắt buộc phải có trong một chương trình, trong quá trình học chúng ta sẽ tìm hiểu thêm về một vài thư viện thường gặp.

- **`int main() { }`**

  - Thường được gọi là `hàm main` - hay là hàm chính - khi chương trình của bạn chạy nó sẽ bắt đầu chạy từ hàm này và nó chỉ chạy những đoạn code có trong này. Do đó mọi chương trình C đều phải tồn tại một hàm main.
  - Tất cả code phải được viết trong cặp dấu ngoặc nhọn `{ }` của hàm main và được xem là code của hàm main.

- **`printf("Hello World!\n");`**

  - Đây là dòng lệnh in ra màn hình dòng chữ `Hello World`. Dòng này kết thúc với dấu `;` (trong ngôn ngữ C tất cả dòng lệnh đều phải kết thúc bằng dấu `;`).
  - Tạm hiểu câu lệnh `printf()` là câu lệnh in ra - hiển thị ra một chuỗi mà bạn truyển vào `( )`.
  - Chuỗi truyền vào cần nằm trong cặp dấu nháy kép `" "` để chương trình hiểu được đó là một đoạn văn bản.
  - Phần `\n` trong chuỗi là một dạng format để báo rằng chúng ra muốn xuống dòng tại đó.

- **`return 0;`**
  - Câu lệnh này tạm hiểu là để kết thúc viết code trong hàm main, nằm cuối cùng trong hàm main để kết thúc chương trình.

> `printf()` được gọi chính xác là một `hàm (function)` trong C, các bạn có thể hiểu đơn giản một hàm là một chức năng cụ thể, làm một công việc cụ thể nào đó.
> Trong quá trình học chúng ta sẽ sử dụng rất nhiều hàm có sẵn của C trong các thư viện khác nhau và cũng sẽ tự viết các hàm chức năng của riêng mình.
