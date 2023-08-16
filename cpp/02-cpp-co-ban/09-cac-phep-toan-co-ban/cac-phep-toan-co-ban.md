---
title: "Các phép toán cơ bản trong c++"
description: "Chào mừng đến với loạt bài hướng dẫn sử dụng ngôn ngữ lập trình C++! Loạt bài hướng dẫn này được thiết kế cho những người chưa hoặc biết một ít lập trình."
keywords:
  [
    "gioi thieu C++",
    "giới thiệu C++",
    "khoá học C++",
    "giới thiệu C++",
    "giới thiệu C++ cơ bản",
    "C++ la gi",
    "tong quan ve C++",
    "gioi thieu ve ngon ngu lap trinh C++",
    "tom tat C++",
    "code C++ la gi",
  ]
chapter:
  name: "Làm quen với ngôn ngữ C++"
  slug: "chuong-01-ngon-ngu-cpp-co-ban"
category:
  name: "Khóa học C++ cơ bản"
  slug: "C++"
image: https://kungfutech.edu.vn/thumbnail.png
position: 9
---

Chúng ta cùng đến với bài học tiếp theo trong khóa học lập trình C++ trực tuyến hướng thực hành.

Trong bài học hôm nay, chúng ta sẽ học cách sử dụng các phép toán cơ bản như phép cộng, trừ, nhân, chia, chia lấy phần dư, căn bậc 2, lũy thừa, giá trị tuyệt đối, ... áp dụng trên các kiểu dữ liệu số cơ bản (int, float, double ...).

Ngôn ngữ C++ đã định nghĩa sẵn một số toán tử toán học cơ bản cho các phép tính thông dụng (+, -, \*, /, ...), một số phép toán phức tạp hơn như căn bậc 2, lũy thừa, ... chưa có toán tử được định nghĩa, vì thế chúng ta sẽ sử dụng thêm thư viện **cmath** để tính kết quả các phép toán trên.

## Các toán tử toán học đã được định nghĩa trong C++

Các toán tử toán học được chia thành hai loại: Toán tử một ngôi (**unary operators**) và toán tử hai ngôi (**binary operators**).

- Toán tử một ngôi (unary operators) là toán tử chỉ đi cùng với một toán hạng để tạo thành biểu thức có nghĩa.
- Toán tử hai ngôi (binary operators) là toán tử thường dùng kèm với hai toán hạng để tạo thành một biểu thức có nghĩa.

Trong ngôn ngữ lập trình C++, một toán hạng có thể là một giá trị hoặc một biến (**variable**).

### Toán tử một ngôi

Có hai toán tử một ngôi trong C++:

![1-8-0](https://github.com/daynhauhoc/cppcoban/assets/88678933/8fb998c9-c082-4cb6-96f8-fd6eed03a6fc)

Sử dụng toán tử cộng một ngôi trước một giá trị thì kết quả trả về giá trị dương, ngược lại, ta nhận được giá trị âm. Ví dụ:

![1-8-1](https://github.com/daynhauhoc/cppcoban/assets/88678933/b69a5dcd-02c3-43dc-9c0c-cc40ad3859bf)

Chạy lại chương trình trên và nhập từ bàn phím vào một giá trị âm, ta được kết quả:

![1-8-2](https://github.com/daynhauhoc/cppcoban/assets/88678933/11546bd9-c261-475e-9be7-a50990640808)

Giá trị ban đầu nhập vào là -100. Khi sử dụng toán tử một ngôi, ta viết lại như sau:

+(-100) = -100

-(-100) = 100

### Toán tử hai ngôi

Ngôn ngữ C++ định nghĩa cho chúng ta 5 toán tử toán học hai ngôi như bảng bên dưới:

![1-8-3](https://github.com/daynhauhoc/cppcoban/assets/88678933/9692ccfd-abb0-45cb-9b3c-d75c43513109)

Phép toán Modulus (%) có nghĩa là thực hiện phép chia hai số nhưng chỉ lấy phần dư. **Phép toán Modulus (%) chỉ cho phép thực hiện với hai giá trị số nguyên.**

Chúng ta cùng viết một chương trình in ra kết quả của các phép toán sử dụng toán tử hai ngôi trong C++:

![1-8-4](https://github.com/daynhauhoc/cppcoban/assets/88678933/1162e931-3117-4910-a2aa-da9533dca601)

Chạy chương trình trên, nhập vào giá trị cho x là 9, nhập giá trị cho y là 5 và xem kết quả.

![1-8-5](https://github.com/daynhauhoc/cppcoban/assets/88678933/c4a43396-d4b2-4b22-8ab2-4766191f6ce6)

Chương trình cho kết quả của các biểu thức như mong đợi, ngoại trừ kết quả của phép chia (**/**).

Khi thực hiện tính giá trị biểu thức **9 / 5** trong toán học, chúng ta được kết quả là **1.8**, nhưng vì kiểu dữ liệu của hai biến chúng ta sử dụng là **int** (kiểu số nguyên) nên kết quả cũng trả về một giá trị số nguyên (bị mất phần thập phân).

Để giải quyết vấn đề này chúng ta có hai cách:

- Sử dụng kiểu dữ liệu số thực (float, double, ...) cho biến.
- Ép kiểu.

### Sử dụng static_cast<> để thực hiện phép chia hai số nguyên

Sử dụng **static_cast<>** là một cách để ép kiểu dữ liệu trong C++. Ép kiểu sẽ tạo ra một giá trị từ một giá trị có kiểu dữ liệu khác.

Cú pháp sử dụng **static_cast<>**:

```
static_cast<new_type>(expression)
```

**static_cast** có thể nhận một biểu thức làm đầu vào, chuyển nó thành bất cứ kiểu dữ liệu cơ bản gì mà **new_type** mô tả.

Các bạn cùng xem ví dụ bên dưới để rõ hơn về cách sử dụng **static_cast**

![1-8-6](https://github.com/daynhauhoc/cppcoban/assets/88678933/136f9408-13b6-408c-a3bd-229834fa2c7d)

Để lấy giá trị kiểu float của biến x, chúng ta viết `static_cast<float>(x)`. Trong chương trình trên, chỉ cần ép kiểu cho một biến x là đủ để thực hiện phép chia trả về số thực.

Cùng xem kết quả chương trình:

![1-8-7](https://github.com/daynhauhoc/cppcoban/assets/88678933/8698e2ba-4151-4c24-8f7d-6b5c85ba7b03)

Chúng ta đã nhận được kết quả đúng.

Có một lưu ý khi thực hiện phép chia hai số nguyên có chứa giá trị âm trong C++. Trước phiên bản C++11, compiler tự ý làm tròn lên hoặc xuống. Ví dụ **-5 / 2** sẽ được kết quả là -3 hoặc -2 tùy vào cách mà compiler làm tròn số.

### Toán tử gán (assignment operator)

Phép gán cũng là một trong những toán tử toán học được C++ định nghĩa. Phép gán có tác dụng đưa giá trị của một con số, một biểu thức hoặc lấy giá trị của một biến khác để đưa vào biến được gán.

Cú pháp sử dụng toán tử gán như sau:

```cpp
<variable> = <expression>;
```

**_Biến được gán giá trị luôn luôn nằm bên trái toán tử "="._**

Toán tử gán có thể dùng ngay khi khai báo biến để vừa khai báo vừa khởi tạo giá trị cho biến, hoặc có thể tách riêng thành một dòng lệnh.

```cpp
int variable = 5;
variable = 10;
variable = 5 * 3 + 2;
int another_variable = 3;
variable = another_variable * 2;
variable = variable + 1; //tăng giá trị biến variable lên 1.
variable = variable - 1; //giảm giá trị biến variable đi 1.
variable = variable * 2; //nhân giá trị biến variable lên 2 lần.
variable = variable / 2; //chia giá trị biến variable đi 2 lần.
variable = variable % 3; //lấy phần dư của biến variable khi chia 3.
```

Những cách sử dụng toán tử gán như trên hoàn toàn hợp lệ.

Riêng với 5 dòng lệnh gán cuối cùng, chúng ta có một cách viết tắt khác ngắn gọn hơn.

```cpp
variable += 1;
variable -= 1;
variable *= 2;
variable /= 2;
variable %= 3;
```

Cách dùng này có ý nghĩa hoàn toàn giống với cách viết ở trên.

Ý nghĩa của các toán tử này các bạn có thể tra ở bảng bên dưới:

![1-8-8](https://github.com/daynhauhoc/cppcoban/assets/88678933/faf3406b-8f22-4b52-9758-0eb827211e84)

## Sử dụng thư viện cmath

Thư viện **cmath** định nghĩa cho chúng ta một số hàm tính toán và chuyển đổi toán học cơ bản. Để sử dụng thư viện này, các bạn chỉ cần thêm dòng

`#include <cmath>`

tại phần khai báo thư viện trong chương trình.

### Một số hàm tính lũy thừa, số mũ:

- **Pow**:

  double pow (double base, double exponent);
  float pow (float base, float exponent);
  long double pow (long double base, long double exponent);

Các bạn chưa cần phải hiểu về cách khai báo hàm pow như trên. Về mặt ý nghĩa, giá trị thứ nhất (base) được đưa vào hàm pow là cơ số, giá trị thứ hai (exponent) là số mũ, giá trị trả về là lũy thừa cơ số base mũ exponent.

Ví dụ:

![1-8-9](https://github.com/daynhauhoc/cppcoban/assets/88678933/b2dc6f8f-b564-4b2d-bf2a-e8af1ad64f20)

Các bạn cùng viết ví dụ trên vào Visual studio và chạy chương trình để xem kết quả mà hàm pow trả về.

![1-8-10](https://github.com/daynhauhoc/cppcoban/assets/88678933/039dbb5d-2fe7-4ae5-be13-ba62293f919f)

- **Sqrt**:

```cpp
double sqrt (double x);
float sqrt (float x);
long double sqrt (long double x);
```

Phía trên là phần khai báo hàm **sqrt** trong thư viện **cmath**, hàm này nhận vào một giá trị số thực (float, double, long double) và trả về giá trị là căn bậc 2 của giá trị mà bạn đưa vào.

Sau đây là ví dụ mẫu về cách sử dụng hàm sqrt để tính căn bậc 2:

![1-8-11](https://github.com/daynhauhoc/cppcoban/assets/88678933/6fb2da58-483a-4201-8bda-9d6ec7da714d)

Kết quả chúng ta thu được như sau:

![1-8-12](https://github.com/daynhauhoc/cppcoban/assets/88678933/9ad8a8fb-c512-49cb-8826-43c450cb7629)

### Một số hàm lượng giác

- **Cos**:

```cpp
double cos (double angle);
float cos (float angle);
long double cos (long double angle);
```

Hàm **cos** nhận vào một giá trị số thực angle (đơn vị **radian**) đại diện cho góc mà bạn muốn tính đường cosine, và trả về giá trị là cosine của góc angle đó.

Ví dụ như sau:

![1-8-13](https://github.com/daynhauhoc/cppcoban/assets/88678933/5a070758-6a1d-42f2-a4ad-53f64ca93e3a)

- **Sin**:

```cpp
double sin (double x);
float sin (float x);
long double sin (long double x);
```

Hàm **sin** nhận vào một giá trị số thực angle (đơn vị **radian**) đại diện cho góc mà bạn muốn tính đường sine, và trả về giá trị trên đường sine của góc angle đó.

Ví dụ mẫu:

![1-8-14](https://github.com/daynhauhoc/cppcoban/assets/88678933/9809c4de-71f6-460b-ad5a-b8be17e50eda)

Ngoài ra, chúng ta còn có nhiều hàm khác như **tan**, **atan**, ... đã được định nghĩa bên trong thư viện **cmath**.

### Một số hàm khác

- **Abs**:

```cpp
double abs (double x);
float abs (float x);
long double abs (long double x);
```

Hàm **abs** sẽ nhận vào một giá trị số thực **x** (kiểu float, double hoặc long double) và trả về giá trị tuyệt đối của **x**.

Các bạn cùng thử làm theo ví dụ mẫu để làm quen với cách sử dụng hàm **abs**.

![1-8-15](https://github.com/daynhauhoc/cppcoban/assets/88678933/9f02fc47-0a35-4581-b1df-0caeafe80753)

Giá trị ban đầu được khởi tạo cho biến x là -5.0, giá trị tuyệt đối được trả về thông qua hàm **abs** là 5.0.

Do số lượng các hàm toán học được định nghĩa rất nhiều, nên mình xin dẫn đường link hướng dẫn sử dụng các hàm trong thư viện **cmath** để các bạn có thể tiện tham khảo khi cần thiết.

[http://www.cplusplus.com/reference/cmath/](http://www.cplusplus.com/reference/cmath/)

### Tổng kết

Trong bài học hôm nay, chúng ta học cách sử dụng các toán tử toán học trong C++, một số cách sử dụng phép gán (với toán tử ''=''), và một số hàm hổ trợ tính toán trong thư viện **cmath**.
