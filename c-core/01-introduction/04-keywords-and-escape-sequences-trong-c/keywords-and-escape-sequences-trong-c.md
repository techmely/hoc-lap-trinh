---
title: "Keywords và Escape Sequences trong C"
description: "Keywords và Escape Sequences trong C"
keywords:
  ["học lập trình c", "khoá học lập trình c", "Khoá học lập trình c căn bản"]
chapter:
  name: "Giới thiệu"
  slug: "chuong-01-introduction"
category:
  name: "C"
  slug: "c"
image: https://user-images.githubusercontent.com/29374426/127596066-fa46df01-982f-4a72-b6d1-f7d8f5c5a9b3.png
position: 4
---

## Từ khoá (keyword) trong C

Ngôn ngữ C có một số từ khoá đặc biệt được tạo ra với mục đích nhất định. Trong quá trình học các bạn sẽ gặp các từ khoá này thường xuyên.

Vì C là ngôn ngữ phân biệt chữ hoa chữ thường, tất cả các từ khóa phải được viết bằng chữ thường. Dưới đây là danh sách tất cả các từ khóa trong C:

|     `auto`     |    `break`     |     `case`     |    `char`    |
| :------------: | :------------: | :------------: | :----------: |
|  **`const`**   | **`continue`** | **`default`**  |   **`do`**   |
|  **`double`**  |   **`else`**   |   **`enum`**   | **`extern`** |
|  **`float`**   |   **`for`**    |   **`goto`**   |   **`if`**   |
|   **`int`**    |   **`long`**   | **`register`** | **`return`** |
|  **`short`**   |  **`signed`**  |  **`sizeof`**  | **`static`** |
|  **`struct`**  |  **`switch`**  | **`typedef`**  | **`union`**  |
| **`unsigned`** |   **`void`**   | **`volatile`** | **`while`**  |

## Escape Sequences trong C

Đôi khi, chúng ta cần phải sử dụng các ký tự không thể gõ hoặc có ý nghĩa đặc biệt trong lập trình C.

Ví dụ: dòng mới (enter), tab, dấu hỏi... Chúng ta cũng đã nói qua một chút về nó ở bài trước khi muốn xuống một dòng mới - đó chính là escape sequences `\n`.

Để sử dụng các ký tự này, các **Escape Sequences** được sử dụng.

| Escape Sequences | Character             |
| ---------------- | --------------------- |
| `\b`             | Backspace             |
| `\f`             | Form feed             |
| `\n`             | Newline               |
| `\r`             | Return                |
| `\t`             | Horizontal tab        |
| `\v`             | Vertical tab          |
| `\\`             | Backslash             |
| `\'`             | Single quotation mark |
| `\"`             | Double quotation mark |
| `\?`             | Question mark         |

Ví dụ muốn in ra dấu `\` trong hàm `printf()`:

```c
#include <stdio.h>

int main() {

    printf("\\");
}
```

Nếu bạn chỉ viết `printf("\");` thì sẽ không in ra được dấu `\` như mong muốn.
