---
title: "Các thư viện cơ bản trong C"
description: "Các thư viện cơ bản trong C"
chapter:
  name: "Giới thiệu"
  slug: "chuong-01-introduction"
category:
  name: "C"
  slug: "c"
image: https://user-images.githubusercontent.com/29374426/127596066-fa46df01-982f-4a72-b6d1-f7d8f5c5a9b3.png
position: 3
---

Trong bài này, chúng ta sẽ tìm hiểu về các thư viện tiêu chuẩn trong C.

Hiểu đơn giản, thư viên trong C là nơi định nghĩa - viết sẵn các hàm chức năng cơ bản của ngôn ngữ C.

Như ở ví dụ trước (Program Structure) khi muốn sử dụng hàm `printf()`, chúng ta cần include thư viện `<stdio.h>` vì hàm `printf()` được định nghĩa trong thư viện này - chức năng của nó làm gì.

_Thực tế, `stdio.h` là một file code, các file code được lưu với đuôi `.h` trong C được xem là những file thư viện._

```cpp
#include <stdio.h>

int main() {
   printf("Catch me if you can.");
}
```

Nếu bạn cố gắng sử dụng hàm `printf()` mà không include thư viện `<stdio.h>`, bạn sẽ gặp lỗi.

### Các thư viện cơ bản trong C

| Thư viện     | Mô tả                                 |
| ------------ | ------------------------------------- |
| `<assert.h>` | Program assertion functions           |
| `<ctype.h>`  | Character type functions              |
| `<locale.h>` | Localization functions                |
| `<math.h>`   | Mathematics functions                 |
| `<setjmp.h>` | Jump functions                        |
| `<signal.h>` | Signal handling functions             |
| `<stdarg.h>` | Variable arguments handling functions |
| `<stdio.h>`  | Standard Input/Output functions       |
| `<stdlib.h>` | Standard Utility functions            |
| `<string.h>` | String handling functions             |
| `<time.h>`   | Date time functions                   |

Các bạn chỉ cần xem và tìm hiểu qua cho biết, trong chương trình học cơ bản này chúng ta cũng sẽ không đi tìm hiểu hết tất cả những thư viện này đâu.
