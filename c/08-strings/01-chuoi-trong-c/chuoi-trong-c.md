---
title: "Strings trong C"
description: "Chuỗi (Strings) là một phần quan trọng trong lập trình C, và việc hiểu cách xử lý chuỗi là một kỹ năng cần thiết cho mọi lập trình viên. Bài viết này sẽ giúp bạn khám phá sâu hơn về cách làm việc với chuỗi trong C và tận dụng sức mạnh của chúng cho các bài toán sau này."
chapter:
  name: "Strings"
  slug: "chuong-08-strings"
category:
  name: "C"
  slug: "c"
image: https://user-images.githubusercontent.com/29374426/127596066-fa46df01-982f-4a72-b6d1-f7d8f5c5a9b3.png
position: 1
---

Trong bài học này, chúng ta sẽ tìm hiểu về chuỗi trong lập trình C. Ta sẽ học cách khai báo chúng, khởi tạo chúng và sử dụng chúng cho các hoạt động Input / Output khác nhau thông qua các ví dụ.

- Khai báo chuỗi
- Khởi tạo chuỗi
- Gán giá trị cho chuỗi
- Đọc chuỗi từ người dùng
- Truyền chuỗi vào mảng
- Chuỗi và con trỏ

## Chuỗi trong C là gì

Chuỗi là một mảng các kí tự được kết thúc bằng kí tự **_null_** `\0`.

Ví dụ:

```cpp
char c[] = "Hello Kungfutech";
```

Khi trình biên dịch gặp một chuỗi các ký tự được đặt trong dấu ngoặc kép, theo mặc định, nó sẽ thêm một ký tự **_null_** vào cuối.

| H   |  e  | l   | l   | o   |     | K   | u   | n   | g   | f   | u   | t   | e   | c   | h   | \0  |
| --- | :-: | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |

## Khởi tạo chuỗi trong C

Đây là cách ta khai báo một chuỗi gồm 10 kí tự:

```cpp
char str[10];
```

## Khởi tạo chuỗi

Ta có thể khởi ta một chuỗi bằng một trong các cách sau:

```cpp
char c[] = "abcde";

char c[50] = "abcde";

char c[] = {'a', 'b', 'c', 'd', 'e', '\0'};

char c[6] = {'a', 'b', 'c', 'd', 'e', '\0'};
```

| c[0] | c[1] | c[2] | c[3] | c[4] | c[5] |
| :--: | :--: | :--: | :--: | :--: | :--: |
|  a   |  b   |  c   |  d   |  e   |  \0  |

Hoặc cũng có thể khởi tạo như sau

```cpp
char c[5] = "abcde";
```

Lúc này, ta đang cố gán 6 ký tự (ký tự cuối cùng là `\0`) cho một mảng c có 5 ký tự. Điều này thật tệ và ta không nên làm như thế.

## Gán giá trị vào chuỗi trong C

Chuỗi không hỗ trợ cho toán tử gán `=` nên ta phải dùng hàm `strcpy()` để sao chép chuỗi.

Ví dụ:

```cpp
#include <stdio.h>
#include <string.h>

int main()
{
  char c[100];
  //c = "Hello Kungfutech"; //error
  strcpy(c, "Hello Kungfutech");
  puts(c);
}
```

::result
Hello Kungfutech
::

::alert{type="warning"}
Lưu ý: khi sử dụng hàm `strcpy()` hãy khai báo thư viên `<string.h>`
::

## Đọc chuỗi từ người dùng

### Chúng ta có thể sử dụng hàm `scanf()` để đọc một chuỗi.

Hàm `scanf()` giúp ta đọc chuỗi ký tự cho đến khi nó gặp **khoảng trắng** (dấu cách, dòng mới, tab,...).

Ví dụ:

```cpp
#include <stdio.h>
int main()
{
    char name[20];
    printf("Enter name: ");
    scanf("%s", name);
    printf("Your name is %s.", name);
    return 0;
}
```

::result
Enter name: Kungfutech Academy</br>
Your name is Kungfutech.</br>
::

Mặc dù `Kungfutech Academy` đã được nhập tại chương trình trên nhưng chỉ `Kungfutech` được lưu trữ tại string `name`, đó là vì có một khoảng trắng đằng sau `Kungfutech`

Vậy làm thế nào để đọc một dòng văn bản?

### Chúng ta sử dụng hàm `fgets()` để đọc một dòng văn bản

Ví dụ:

```cpp
#include <stdio.h>
int main()
{
    char name[30];
    printf("Enter name: ");
    fgets(name, sizeof(name), stdin);
    printf("Name: ");
    puts(name);
    return 0;
}
```

::result
Enter name: Kungfutech Academy</br>
Name: Kungfutech Academy</br>
::

Tại chương trình trên ta đã sử dụng hàm `fgets()` để đọc một chuỗi văn bản từ người dùng và hàm `puts()` để hiển thị văn bản đó.

```cpp
fgets(name, sizeof(name), stdin);
//code
puts(name);
```

`sizeof(name)` sẽ mang giá trị là 30, do đó chúng ta có thể đọc được một chuỗi tối đa 30 kí tự.

## Truyền chuỗi vào hàm trong C

Các chuỗi có thể được truyền cho một hàm theo cách tương tự như các mảng.

Ví dụ:

```cpp
#include <stdio.h>
void displayString(char str[]);

int main()
{
    char name[50];
    printf("Enter string: ");
    fgets(name, sizeof(name), stdin);
    displayString(name);
    return 0;
}
void displayString(char str[])
{
    printf("String Output: ");
    puts(str);
}
```

::result
Enter string: Kungfutech Academy</br>
String Output: Kungfutech Academy</br>
::

Tại đây chúng ta truyền một chuỗi `name` vào hàm `displayString()`.

```cpp
displayString(name);
```

## Chuỗi và con

Ví dụ:

```cpp
#include <stdio.h>

int main(void) {
  char name[] = "Kungfutech Academy";

  printf("%c", *name);
  printf("%c", *(name+4));
  printf("%c", *(name+8));

  char *namePtr;
  printf("\n");

  namePtr = name;
  printf("%c", *namePtr);
  printf("%c", *(namePtr+4));
  printf("%c", *(namePtr+8));
}
```

::result
Kfc</br>
Kfc</br>
::
