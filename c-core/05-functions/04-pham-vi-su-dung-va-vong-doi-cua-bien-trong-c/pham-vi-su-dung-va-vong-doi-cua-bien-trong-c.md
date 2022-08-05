---
title: "Phạm vi sử dụng và vòng đời của biến trong C"
description: "Phạm vi sử dụng và vòng đời của biến trong C"
keywords:
  ["học lập trình c", "khoá học lập trình c", "Khoá học lập trình c căn bản"]
chapter:
  name: "Hàm"
  slug: "chuong-05-functions"
category:
  name: "C"
  slug: "c-core"
image: https://user-images.githubusercontent.com/29374426/127596066-fa46df01-982f-4a72-b6d1-f7d8f5c5a9b3.png
position: 4
---

Ở bài này chúng ta sẽ học về phạm vi sử dụng, vòng đời của các biến trong c thông qua **Storage Class**

Lớp lưu trữ `Storage Class` định nghĩa phạm vi và vòng đời của biến và/hoặc các hàm bên trong một chương trình C. Chúng thường đứng trước kiểu dữ liệu mà chúng tác động. Dưới đây là các lớp lưu trữ có thể được sử dụng trong C

Mọi biến trong lập trình C đều có hai thuộc tính: `type` và `Storage Class`.

`type` đề cập đến kiểu dữ liệu của một biến. Và `Storage Class` xác định phạm vi, khả năng hiển thị và thời gian tồn tại của một biến.

#### Có 4 loại `Storage Class`:

- `automatic`
- `external`
- `register`
- `static`

## Biến cục bộ trong C

Các biến được khai báo bên trong một khối là biến tự động hoặc biến cục bộ. Các biến cục bộ chỉ tồn tại bên trong khối mà nó được khai báo.

Ví dụ

```c
#include <stdio.h>

int main(void) {

    for (int i = 0; i < 10; ++i) {
          printf("Hello Anest");
    }

    // Lỗi: i chỉ là biến cục bộ được khai báo trong vòng lặp for nên khi ra khỏi vòng lặp i không tồn tại
    printf("%d", i);
    return 0;
}
```

Khi bạn chạy chương trình trên, bạn sẽ gặp lỗi `undeclared identifier i`. Là vì `i` được khai báo bên trong khối lặp `for`, bên ngoài khối lặp `for` nó không được khai báo

## Biến toàn cục trong C

Các biến được khai báo bên ngoài tất cả các hàm được gọi là biến bên ngoài hoặc biến toàn cục. Chúng có thể truy cập từ bất kỳ vị trí nào bên trong chương trình.

ví dụ

```c
#include <stdio.h>
void display();

int a = 3;  // global variable

int main()
{
    a = a + 2;
    display();
    return 0;
}

void display()
{
    a++;
    printf("a = %d", a);
}
```

Kết quả

```c
a = 6
```

Trong ví dụ này t thấy biến `a` được khai báo ở bên ngoài tất cả các hàm nên khi hàm `main()` gọi `a` và tăng giá trị của nó lên **2**, lúc này `a = 5`, trong hàm `display()` lại tăng `a` thêm 1 nên kết quả khi in ra là `a = 6`

## Biến thanh ghi trong C

Từ khóa `register` dùng để khai báo các biến thanh ghi. Các biến thanh ghi được cho là nhanh hơn các biến cục bộ.

Ví dụ

```c
{
    register int a;
}
```

## Biến tĩnh trong C

Một biến tĩnh được khai báo bằng cách sử dụng từ khóa `static`. Giá trị của một biến tĩnh vẫn tồn tại cho đến khi kết thúc chương trình.

Ví dụ:

```c
#include <stdio.h>
void display();

int main()
{
    display();
    display();
}
void display()
{
    static int a = 1;
    a += 5;
    printf("%d  ",c);
}
```

Kết quả

```c
6 11
```

Trong lần gọi hàm đầu tiên, giá trị của `a` được khởi tạo thành 1. Giá trị của nó được tăng lên 5. Bây giờ, giá trị của `a` là 6, được in trên màn hình.

Trong lần gọi hàm thứ hai, `a` không được khởi tạo lại thành 1. Là vì `a` là một biến tĩnh. Giá trị `a` được tăng từ 6 và tăng thêm 5. Bây giờ, giá trị của nó sẽ là 11, được in trên màn hình.
