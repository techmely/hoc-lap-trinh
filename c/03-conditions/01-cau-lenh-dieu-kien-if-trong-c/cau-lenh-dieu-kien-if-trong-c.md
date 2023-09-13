---
title: "Câu lệnh điều kiện if trong C"
description: "Câu lệnh điều kiện 'if' là một phần quan trọng không thể thiếu trong việc xây dựng các chương trình máy tính. Nó cho phép bạn kiểm tra điều kiện và thực hiện các hành động khác nhau dựa trên kết quả của điều kiện đó. Hãy khám phá chi tiết về cách sử dụng câu lệnh 'if' để kiểm soát luồng của chương trình và tạo ra các ứng dụng mạnh mẽ trong ngôn ngữ lập trình C. Đọc ngay nào!"
chapter:
  name: "Câu điều kiện"
  slug: "chuong-03-conditions"
category:
  name: "C"
  slug: "c"
image: https://user-images.githubusercontent.com/29374426/127596066-fa46df01-982f-4a72-b6d1-f7d8f5c5a9b3.png
position: 1
---

Mệnh đề `if-else` trong C được sử dụng để kiểm tra một **biểu thức điều kiện (condition)** nào đó có đúng hay không, nếu đúng thì thực thi những câu lệnh bên trong khối lệnh `if` và ngược lại nếu sai thì nó sẽ bỏ qua những câu lệnh đó. Có ba dạng của câu lệnh `if` trong C.

- `if`
- `if-else`
- `if-else if-else`

Trước khi tìm hiểu luôn về `if-else` thì chúng ta cần tìm hiểu và ghi nhớ một số toán tử tiếp theo vì những toán tử này được dùng rất nhiều trong **condition** ở mệnh đề `if`.

_Bạn có thể xem lại bài viết về toán tử [tại đây](/bai-viet/c/cac-loai-toan-tu-trong-c)._

## Toán tử quan hệ trong C

Một toán tử quan hệ kiểm tra mối quan hệ giữa hai toán hạng. Nếu quan hệ là `true`, nó trả về `1`; nếu quan hệ là `false`, nó trả về giá trị `0`.

Vì vậy, hãy nhớ trong lập trình C - **giá trị `1` đại diện cho `true`, giá trị `0` đại diện cho `false`**.

| Toán tử | Mô tả             | Ví dụ (a = 3, b = 5) | Kết quả |
| :-----: | ----------------- | -------------------- | ------- |
|   ==    | Bằng              | a == b               | `false` |
|   !=    | Khác              | a != b               | `true`  |
|    >    | Lớn hơn           | a > b                | `false` |
|    <    | Nhỏ hơn           | a < b                | `true`  |
|   >=    | Lớn hơn hoặc bằng | a >= b               | `false` |
|   <=    | Nhỏ hơn hoặc bằng | a <= b               | `true`  |

## Toán tử logic trong C

Một biểu thức chứa toán tử logic trả về `0` hoặc `1` tùy thuộc vào kết quả biểu thức đúng hay sai.

|    Toán tử    | Mô tả                                                   | Ví dụ (a = 3, b = 5)         | Kết quả |
| :-----------: | ------------------------------------------------------- | ---------------------------- | ------- |
|      &&       | Toán tử AND - `true` nếu tất cả các toán hạng là `true` | (a == 3 && b < 5)            | `false` |
| &#124; &#124; | Toán tử OR - `true` nếu một toán hạng là `true`         | (a == 3 &#124; &#124; b < 5) | `true`  |
|       !       | Toán tử NOT - `true` nếu toán hạng bằng `false`         | !(a == 3)                    | `false` |

## Câu lệnh if-else

### if statement

- Nếu điều kiện trả về `true` thì các câu lệnh bên trong phần thân của `if` sẽ được thực thi.
- Nếu điều kiện trả về `false` thì các câu lệnh bên trong phần thân của `if` sẽ được bỏ qua.

```cpp
if (condition) {
    // khối lệnh này được thực thi nếu condition = true
}
```

> **Tại vị trí `condition`, chúng ta sẽ viết một điều kiện để kiểm tra sử dụng các toán tử quan hệ đã được hướng dẫn ở trên.**

Đây là một ví dụ:

```cpp
// Program to display a number if it is negative

#include <stdio.h>

int main() {

    int number;

    printf("Enter an integer: ");
    scanf("%d", &number);

    // true if number is less than 0
    if (number < 0) {
        printf("You entered %d.\n", number);
    }

    printf("Done.");
}
```

Kết quả khi bạn nhập một số âm:

```cpp
Enter an integer: -5
You entered -5.
Done.
```

Kết quả khi bạn nhập một số dương:

```cpp
Enter an integer: 5
Done.
```

### if-else statement

- Nếu điều kiện trả về `true` thì các câu lệnh bên trong phần thân của `if` được thực thi và các câu lệnh bên trong phần thân của `else` bị bỏ qua.
- Nếu điều kiện trả về `false` thì các câu lệnh bên trong phần thân của `if` bị bỏ qua và các câu lệnh trong `else` được thực thi.

```cpp
if (condition) {
    // khối lệnh này được thực thi nếu condition = true
} else {
    // khối lệnh này được thực thi nếu condition = false
}
```

Đây là một ví dụ:

```cpp
#include <stdio.h>

int main() {

    int age;

    printf("Enter your age: ");
    scanf("%d", &age);

    if (age >= 18) {
	// Câu lệnh này sẽ được thực thi nếu điều kiện trên (age >= 18) trả về true
	printf("You are eligible for voting.");
    } else {
	// Câu lệnh này sẽ được thực thi nếu điều kiện trên (age >= 18) trả về false
	printf("You are not eligible for voting.");
    }
}
```

Kết quả khi bạn nhập số tuổi thỏa mãn điều kiện lớn hơn hoặc bằng 18:

```cpp
Enter your age: 22
You are eligible for voting.
```

Kết quả khi bạn nhập số tuổi không thỏa mãn điều kiện lớn hơn hoặc bằng 18:

```cpp
Enter your age: 14
You are not eligible for voting.
```

**Chú ý:**  
_Nếu chỉ có một câu lệnh xuất hiện trong thân `if` hoặc `else` thì bạn không cần phải sử dụng cặp dấu `{ }`. Ví dụ, chương trình trên có thể được viết lại như sau:_

```cpp
#include <stdio.h>

int main() {

    int age;

    printf("Enter your age:");
    scanf("%d", &age);

    if (age >= 18)
	    printf("You are eligible for voting.");
    else
	    printf("You are not eligible for voting.");
}
```

### if-else if-else statement

Câu lệnh `else if` rất hữu ích khi bạn cần kiểm tra nhiều điều kiện trong chương trình, có thể tránh việc lồng các khối `if-else` bằng cách sử dụng câu lệnh `else if`.

Cú pháp của `if-else if-else`:

```cpp
if (condition1) {
    // khối lệnh này được thực thi nếu condition1 = true
} else if (condition2) {
    // khối lệnh này được thực thi nếu condition1 = false và condition2 = true
    ...
} else {
    // khối lệnh này được thực thi nếu nếu tất cả những condition trên = false
}
```

Và đây là một ví dụ minh họa:

```cpp
#include <stdio.h>

int main() {

   int var1, var2;

   printf("Input the value of var1: ");
   scanf("%d", &var1);

   printf("Input the value of var2: ");
   scanf("%d",&var2);

   if (var1 == var2) {
	printf("\nvar1 is equal to var2.\n");
   } else if (var1 > var2) {
	printf("\nvar1 is greater than var2.\n");
   } else {
	printf("\nvar1 is less than var2.");
   }
}
```

Và sau đây là kết quả:

```cpp
Input the value of var1: 9
Input the value of var2: 8

var1 is greater than var2.
```

## Nested if-else statement

Khi một câu lệnh `if` hoặc `if-else` xuất hiện bên trong phần thân của một `if` hoặc `if-else` khác thì đây được gọi là mệnh đề `if` lồng nhau. Các câu lệnh `if` bên trong được thực thi dựa trên các câu lệnh `if` bên ngoài.

Cú pháp:

```cpp
if (condition 1) {

    // if-else bên trong mệnh đề if
    if (condition 2) {
       ...
    } else {
       ...
    }
} else {
    if (condition 3) {
        ...
    }
}
```

Cùng xem ví dụ sau:

```cpp
#include <stdio.h>

int main() {

   int var1, var2;

   printf("Input the value of var1:");
   scanf("%d", &var1);

   printf("Input the value of var2:");
   scanf("%d", &var2);

   if (var1 != var2) {
	printf("\nvar1 is not equal to var2.\n");

	if (var1 > var2) {
	    printf("var1 is greater than var2.\n");
	} else {
	    printf("var1 is less than var2.\n");
	}
   } else {
	printf("var1 is equal to var2.\n");
   }
}
```

Và đây là kết quả:

```cpp
Input the value of var1: 5
Input the value of var2: 2

var1 is not equal to var2.
var1 is greater than var2.
```

## if-else statement with many conditions

Trong câu lệnh `if` hoặc `else if` chúng ta cũng có thể dùng `Logical Operators` để kết hợp nhiều **conditions** lại với nhau để xử lý nhiều điều kiện một lúc.

Hãy xem qua ví dụ sau:

```cpp
#include <stdio.h>

int main() {

    float grade;

    printf("Input the value of grade: ");
    scanf("%f", &grade);

    if (grade < 0 || grade > 10) {
        printf("Invalid grade.\n");
    } else if (grade <= 10 && grade >= 9) {
        printf("Excellent!\n");
    } else if (grade < 9 && grade >= 7) {
        printf("Well done.\n");
    } else if (grade < 7 && grade >= 5) {
        printf("You passed.\n");
    } else {
        printf("Better try again.\n");
    }
}
```

Kết quả:

```cpp
Input the value of grade: 7.5
Well done.
```

```cpp
Input the value of grade: -1
Invalid grade.
```
