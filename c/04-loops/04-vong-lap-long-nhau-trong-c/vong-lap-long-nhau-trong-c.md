---
title: "Vòng lặp lồng nhau trong C"
description: "Khi bạn đã trang bị đủ kiến thức về vòng lặp rồi, ta có thể nâng cao chúng với bài học này. Bằng cách kết hợp và lồng nhiều vòng lặp, bạn có thể kiểm soát luồng của chương trình một cách chi tiết và hiệu quả hơn. Học cách sử dụng vòng lặp lồng nhau sao cho hợp lý để giải quyết các vấn đề phức tạp, tối ưu hóa mã nguồn, và tạo ra các ứng dụng đa năng. "
chapter:
  name: "Vòng lặp"
  slug: "chuong-04-loops"
category:
  name: "C"
  slug: "c"
image: https://user-images.githubusercontent.com/29374426/127596066-fa46df01-982f-4a72-b6d1-f7d8f5c5a9b3.png
position: 4
---

Vòng lặp lồng nhau có nghĩa là một câu lệnh vòng lặp nằm bên trong một câu lệnh vòng lặp khác.

## Cấu trúc lặp for lồng nhau nhau trong C

```cpp
for (initialization; condition; increment) {

    for (initialization; condition; increment) {

        // statement of inside loop
    }

    // statement of outer loop
}
```

## Cấu trúc lặp while lồng nhau nhau trong C

```cpp
while (condition) {

    while (condition) {

        // statement of inside loop
    }

    // statement of outer loop
}
```

## Cấu trúc do-while lồng nhau trong C

```cpp
do {

    do {

        // statement of inside loop
    } while (condition);

    // statement of outer loop
} while (condition);
```

::alert{type="warning"}
Lưu ý: Không có quy tắc nào rằng là một vòng lặp phải được lồng trong đúng loại của nó. Trong thực tế, có thể có bất kỳ loại vòng lặp nào được lồng bên trong bất kỳ loại vòng lặp nào khác và với bất kỳ cấp độ nào.
::

Ví dụ:

```cpp
do {

   while (condition) {

      for (initialization; condition; increment) {

         // statement of inside for loop
      }

      // statement of inside while loop
   }

   // statement of outer do-while loop
} while (condition);
```
