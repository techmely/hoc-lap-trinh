---
title: "Các loại hàm trong C"
description: "Các loại hàm trong C"
chapter:
  name: "Hàm"
  slug: "chuong-05-functions"
category:
  name: "C"
  slug: "c"
image: https://user-images.githubusercontent.com/29374426/127596066-fa46df01-982f-4a72-b6d1-f7d8f5c5a9b3.png
position: 2
---

Có hai loại hàm trong lập trình C là:

- Standard library functions
- User-defined functions

Trong bài viết này, chúng ta sẽ cùng đi tìm hiểu chi tiết về 2 loại hàm này.

## Các hàm trong thư viện tiêu

- Standard library functions (Hàm thư viện chuẩn) là những hàm có sẵn trong lập trình C.
- Các hàm với tên và chức năng riêng biệt đã được định nghĩa trong các thư viện tiêu chuẩn.

Ví dụ:

- Hàm `Printf()` là một hàm dùng để hiển thị đầu ra được định dạng ra màn hình. Hàm này
  được định nghĩa trong thư viện `stdio.h`, để sử dụng hàm chúng ta cần import thư viện
  với câu lệnh: `#include<stdio.h>`
- Hàm `Sqrt()` là một hàm dùng để tính căn bậc hai của một số. Hàm này được định nghĩa trong
  thư viện `math.h` và để sử dụng được hàm này chúng ta cần import thư viện với câu lệnh:`#include<math.h>`

<h3>Advantages of Using C library functions:</h3>

1. Các hàm chức năng này "hoạt động":

   - _Các hàm này đã trải qua các thử nhiệm nghiêm ngặt của nhà phát triển ngôn ngữ lập trình C nó đơn giản, dễ sử dụng._

2. Các hàm chức năng đã được tối ưu hóa về hiệu suất:

   - _Do các hàm đều được định nghĩa trong thư viện tiêu chuẩn (standard library), các hàm này được phát triển liên tục để nhằm mục đích làm chúng trở nên tốt hơn._

3. Tiết kiệm thời gian:

   - _Vì đây là hầu hết các chức năng cơ bản nhất mà người lập trình có thể sử dụng (in ra màn hình, tính căn bậc hai,...) vậy nên chúng ta không cần phải tạo lại chúng một lần nữa._

4. Các chức năng có thể di động:
   - _Các chức năng thư viện này giúp bạn ở chỗ chúng thực hiện điều tương tự trên mọi máy tính._

Ví dụ: Tính giá trị tuyệt đối của một số nguyên nhập từ bàn phím.
Để tính toán được giá trị tuyệt đối của một số chúng ta có thể sử dụng hàm thư viện `fabs()`. Để sử dụng
nó chúng ta cần import thư viện `math.h` ở phần đầu file code.

```cpp
#include <stdio.h>
#include <math.h>

int main() {
    int num, abs;
    printf("Enter a number: ");
    scanf("%d", &num);

     // Tính toán giá trị tuyệt đối của "num" và gán vào biến abs
    abs = fabs(num);

    printf("Absolute value = %d", num);
    return 0;
}
```

Kết quả:

```cpp
Enter a number: -7
Absolute value = 7
```

## Định nghĩa hàm trong C

- Ngoài việc sử dụng các hàm viết sẵn được định nghĩa trong các thư viện của chương trình C
  chúng ta cũng có thể tạo các hàm theo mục đích hoặc yêu cầu của bài toán.
- Những hàm được lập trình viên tạo ra được gọi là hàm do người dùng định nghĩa.
- Mỗi hàm thực hiện một chức năng cụ thể.

Ví dụ: Tính tổng hai số nguyên có giá trị được nhập từ bàn phím.

Khác với những bài tập và ví dụ trước, với bài toán này chúng ta sẽ sử dụng hàm `addition()` để tính toán:

```cpp
#include <stdio.h>

int addition(int a, int b); // Nguyên mẫu hàm (Function prototype)

int main() {

    int x, y, result;
    printf("Enter x: ");
    scanf("%d", &x);
    printf("Enter y: ");
    scanf("%d", &y);

    result = addition(x, y); // Gọi hàm (Function call)

    printf("x + y = ", result);

    return 0;
}

int addition(int a, int b){ // Định nghĩa hàm (Function definition)
    int sum;
    sum = a + b;
    return sum; // Trả về kết quả của hàm (Return statement)
}
```

Kết quả:

```cpp
Enter x: 3
Enter y: 4
x + y = 7
```

<h3>1. Function prototype</h3>

- Nguyên mẫu hàm chỉ là khai báo một hàm gồm tên hàm, các tham số và kiểu trả về. Không chứa
  thân hàm.
- Nó cung cấp cho trình biên dịch là hàm này có thể được sử dụng trong chương trình.

Syntax of function prototype:

```cpp
returnType functionName(dataType1 argument1, dataType2 argument2, ...);
```

Với ví dụ ở trên ta có thể phân tích hàm `addition()`:

1. Tên của hàm là `addition()`.
2. Kiểu trả về là `int`.
3. Có hai tham số `int` được truyền vào hàm.

> Nguyên mẫu hàm là không cần thiết nếu hàm do bạn định nghĩa ở trước `main()`.

<h3>2. Function call</h3>

Syntax of function call:

```cpp
functionName(argument1, argument2, ...);
```

Trong ví dụ trên ta gọi hàm `addition(x, y);` bên trong hàm `main()`.

<h3>3. Function definition</h3>

Định nghĩa hàm cho hàm một khối lệnh để hàm thực hiện chức năng cụ thể, như ví dụ ở trên hàm thực hiện chức năng tính tổng hai số và trả về kết quả.

Syntax of function definition:

```cpp
returnType functionName(dataType1 argument1, dataType2 argument2, ...){
    // body of the function
}
```

> Khi hàm được gọi (function call) trình biên dịch chuyển đến hàm và bắt đầu thực thi các câu lệnh bên trong thân hàm.

<h3>4. Argument & Parameters</h3>

- Trong lập trình đối số (argument) là cách chúng ta gọi các biến được truyền cho hàm. Ở ví dụ trên, hai biến **x** và **y** là đối số.
- Các tham số (parameter) **a** và **b** chấp nhận đối số được truyền vào hàm, được coi là tham số chính thức của hàm.

<p align="center">
  <img src="https://github.com/AnestAcademy/Course-C-Fundamentals/blob/master/Images/c-function-argument-and-parameter.jpg">
</p>

- Kiểu dữ liệu của đối số và tham số phải trùng với nhau nếu không chương trình sẽ bị lỗi.
- Một hàm đôi khi cũng không cần truyền đối số.

<h3>5. Return statement</h3>

Câu lệnh _return_ kết thúc thực thi của một hàm và trả về giá trị cho hàm đang được gọi.

Trong ví dụ trên giá trị của biến kết quả trong hàm `addition()` được trả về hàm `main()` và biến **result** được gán giá trị này.

Syntax of return statement:

```cpp
return (expression);
```

Ví dụ:

```cpp
return a;
return a+b;
```

> Kiểu dữ liệu được trả về từ hàm và kiểu dữ liệu trả về được chỉ định trong nguyên mẫu hàm (hoặc định nghĩa hàm) phải khớp nhau.

Chúng ta có thể xem lại cú pháp khởi tạo một hàm tại đây [Structure of a function](<https://github.com/AnestAcademy/Course-C-Fundamentals/blob/master/5.%20Functions%20(coming%20soon)/1.%20Structure%20of%20a%20function.md>).

<h3>6. How user-defined function works?</h3>

Cùng xem hình ảnh mô tả cách hoạt động của hàm do người dùng định nghĩa:

<p align="center">
    <img src="https://github.com/AnestAcademy/Course-C-Fundamentals/blob/master/Images/c-function-how-user-defined-function-work.jpg">
</p>

**_Giải thích_**:

- Chương trình bắt đầu chạy từ hàm `main()` khi trình biên dịch gặp `functionName();` sẽ chuyển tới: `void functionName()`. Và trình biên dịch bắt đầu thực thi các đoạn code bên trong `functionName();`

- Khi kết thúc việc thực thi các dòng lệnh trong `functionName();` trình biên dịch quay trở lại `main()`.

> Lưu ý: Một hàm với tên được định nghĩa phải là duy nhất.

<h3>7. Advantages of user-defined function</h3>

- Chương trình sẽ dễ hiểu, dễ duy trì và gỡ lỗi hơn.
- Code có thể tái sử dụng trong các chương trình khác.
- Một chương trình lớn có thể được chia thành các mô-đun nhỏ hơn. Do đó, nó có thể được chia cho nhiều lập trình viên cùng thực hiện.
