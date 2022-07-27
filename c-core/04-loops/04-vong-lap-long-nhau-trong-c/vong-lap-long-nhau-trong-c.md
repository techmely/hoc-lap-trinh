---
title: "Vòng lặp lồng nhau trong C"
description: "Vòng lặp lồng nhau trong C"
keywords:
  ["học lập trình c", "khoá học lập trình c", "Khoá học lập trình c căn bản"]
chapter:
  name: "Vòng lặp"
  slug: "chuong-04-loops"
category:
  name: "C"
  slug: "c-core"
image: https://user-images.githubusercontent.com/29374426/127596066-fa46df01-982f-4a72-b6d1-f7d8f5c5a9b3.png
position: 4
---

Vòng lặp lồng nhau có nghĩa là một câu lệnh vòng lặp nằm bên trong một câu lệnh vòng lặp khác.

## Syntax for Nested loop

### Nested `for` loop

```c
for (initialization; condition; increment) {

    for (initialization; condition; increment) {

        // statement of inside loop
    }

    // statement of outer loop
}
```

### Nested `while` loop

```c
while (condition) {

    while (condition) {

        // statement of inside loop
    }

    // statement of outer loop
}
```

### Nested `do-while` loop

```c
do {

    do {

        // statement of inside loop
    } while (condition);

    // statement of outer loop
} while (condition);
```

_**Lưu ý**: Không có quy tắc nào rằng là một vòng lặp phải được lồng trong đúng loại của nó. Trong thực tế, có thể có bất kỳ loại vòng lặp nào được lồng bên trong bất kỳ loại vòng lặp nào khác và với bất kỳ cấp độ nào._

Ví dụ:

```c
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
