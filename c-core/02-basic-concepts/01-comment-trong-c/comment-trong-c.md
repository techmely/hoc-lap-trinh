---
title: "Comment trong C"
description: "Comment trong C"
keywords:
  ["học lập trình c", "khoá học lập trình c", "Khoá học lập trình c căn bản"]
chapter:
  name: "Giới thiệu"
  slug: "chuong-02-basic-concepts"
category:
  name: "C"
  slug: "c-core"
image: https://user-images.githubusercontent.com/29374426/127596066-fa46df01-982f-4a72-b6d1-f7d8f5c5a9b3.png
position: 1
---

Comments có thể được sử dụng để giải thích một đoạn code trong C và để làm cho nó dễ đọc - dễ hiểu hơn. Nó cũng có thể được sử dụng để tạm dừng việc thực thi khi kiểm tra một đoạn code thay thế.

## Comment một d trong C

Comments một dòng bắt đầu bằng hai dấu gạch chéo `//`.

Bất kỳ văn bản nào nằm giữa `//` đến cuối dòng đều bị C bỏ qua (sẽ không được thực thi).

Ví dụ:

```c
#include <stdio.h>

int main() {

    // This is a comment
    printf("Hello World!");
}
```

Ví dụ này sử dụng một comment ở cuối dòng code:

```c
#include <stdio.h>

int main() {

    printf("Hello World!"); // This is a comment
}
```

## Comment nhiều dòng trong C

Comment nhiều dòng bắt đầu bằng `/*` và kết thúc bằng `*/`.

Mọi văn bản giữa `/*` và `*/` sẽ bị C bỏ qua.

Ví dụ này sử dụng một comment nhiều dòng (một khối comment) để giải thích đoạn code:

```c
#include <stdio.h>

int main() {

    /* The code below will print the words Hello World
       to the screen, and it is amazing */
    printf("Hello World!");
}
```

### Vậy nên dùng single hay multi-line comments

> Điều này tuỳ thuộc vào cách sử dụng của mỗi người. Thông thường, chúng ta nên sử dụng `//` cho các comment ngắn và `/* */` cho những comment dài cần phải xuống nhiều dòng.
