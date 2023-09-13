---
title: "Cấu trúc if đủ trong c++"
description: "Chào mừng đến với loạt bài hướng dẫn sử dụng ngôn ngữ lập trình C++! Loạt bài hướng dẫn này được thiết kế cho những người chưa hoặc biết một ít lập trình."
chapter:
  name: "Các cấu trúc trong C++"
  slug: "chuong-03-cau-truc-trong-c++"
category:
  name: "Khóa học C++ cơ bản"
  slug: "C++"
image: https://kungfutech.edu.vn/thumbnail.png
position: 4
---

## Cấu trúc rẽ nhánh (tiếp)

Quay trở lại với câu hỏi của bài trước.

> Nếu **cái gì đó** không đúng thì sao?

Như chúng ta đã biết kiểu dữ liệu boolean được sử dụng trong cấu trúc rẽ nhánh( so sánh). Có hai giá trị trả về **true** hoặc **false**.

Vì vậy

```cpp
bool b;

if(b) {
  cout << b << endl;
}
```

Trong ví dụ trên nếu **b = true** thì màn hình console sẽ in ra là **1( true)**.
Nếu b không phải là true thì sao.

```cpp
 bool b = false;
if(b)
{
cout << b << endl;
}
```

![2 4 1](https://github.com/daynhauhoc/cppcoban/assets/88678933/77af6fc3-2d72-4c82-861c-327f35ec6672)

Nếu điều kiện gì đó đúng thì làm việc gì đó. Còn không thì sao ?

### Cấu trúc if đủ

```cpp
if (điều kiện)
{
// Làm gì đó !
}
else
{
// Cũng làm gì đó !
}
```

> Giả sử, Nếu hôm này là thứ 7 tôi sẽ làm tiếng anh. Còn không phải thứ 7 tôi sẽ học lập trình C++.

Nếu trong một cấu trúc rẽ nhánh. Ta có trường hợp **true**( giá trị **KHÁC** 0) và **false**( giá trị bằng 0). Khi đó ta sẽ sử dụng từ khóa **else** để xử lý trường hợp không đúng xảy ra.

```cpp
#include<iostream>
using namespace std;
int main()
{
bool b = false;
if(b)
{
cout << " Gia tri cua b " << b << endl;
}
else
{
cout << " Gia tri cua b " << b << endl;
}
return 0;
}
```

**Output**

Gia tri cua b 0

Với từ khóa **else** sẽ nhận ngay giá trị 0 của biểu thức điều kiện, nên ta không cần thêm biểu thức điều kiện hay giá trị sau else nữa.
Sau **else** vẫn là một** câu lệnh** hoặc **khối lệnh** tương tự sẽ được thực hiện nếu biểu thức điều kiện là sai.

> Hiểu đơn giản đi thì ta có. Nếu giá trị tại biểu thức điều kiện trả về khác 0 thì đoạn lệnh sau if sẽ được chạy. Nếu trả về 0 thì lệnh sau else sẽ được chạy

## Một số ví dụ sử dụng if else đủ với toán tử Logic

### Logic NOT (!)

Phép toán Logic NOT chuyển một biểu thức từ giá trị đúng thành giá trị sai và ngược lại.

```cpp
#include<iostream>
using namespace std;
int main(){
bool b = true ;
if(!b)
{
cout << " Not b l true " << endl;
}
else
{
cout << " NOT b la false " << endl;
}
return 0;
}
```

**Output**a
NOT b la flase

Khởi tạo ban đầu b = true. Sau đó ta sử dụng toán tử NOT !b, giá trị trả về sẽ là ngược lại giá trị ban đầu của b => false(0).
Vì giá trị sau if trả về là 0 nên câu lệnh sau else sẽ được thực hiện.

```cpp
#include<iostream>
using namespace std;
int main(){
int a = 5 , b =7;
    if(!a==b)
{
cout << " a khac b " << endl;
}
else
{
cout << " a bang b " << endl;
}
return 0;
}
```

**Output**

`a bang b`

Kết quả sai rồi. Vì sao vậy ?
Sự ưu tiên toán tử. Vì toán tử logic NOT được ưu tiên thực hiện trước toán tử quan hệ ==. Điều này dẫn tới kết quả không như mong đợi.

> !a trả về giá trị 0. 0==7 trả giá trị về 0. Dẫn tới câu lệnh sau else được gọi.

Để khắc phục việc này chúng ta cần cho toán tử quan hệ thực hiện trước bằng việc thêm ngoặc tròn. Điều này sẽ giúp compiler hiểu được sự ưu tiên toán tử.

```cpp
#include<iostream>
using namespace std;
int main(){
int a = 5 , b =7;
    if(!(a==b))
{
cout << " a khac b " << endl;
}
else
{
cout << " a bang b " << endl;
}
return 0;
}
```

**Output**

`a khac b`

> 5==7 trả về giá trị 0(false). Sau đó, toán tử NOT được gọi, **!false = true**. Chương trình sẽ in ra **a khac b**

### Logic OR (||)

Toán tử logic OR dùng để đánh giá hai giá trị điều kiện.
Ví dụ: A||B

- Nếu **cả hai** cùng đúng(true) thì trả về giá trị đúng(true)
- Nếu **một trong hai** đúng(true) thì trả về giá trị đúng(true)
- Nếu cả hai **cùng sai** thì trả về giá trị sai(false)

Ví dụ : Nhập vào một số nguyên bất kì kiểm tra xem số đó có bằng 9 hoặc bằng 6 hay không? Nếu có thì in ra thông báo số đó bằng 9 hoặc bằng 6. Còn không thì thông báo số đó không bằng 9 hoặc không bằng 6.

```cpp
#include<iostream>
using namespace std;
int main(){
int n;
cout << " Nhap N " << endl;
cin>>n;
if(n==9||n==6)
{
cout << " So nhap vao bang 9 hoac 6 " << endl;
}
else
{
cout << " So nhap vao khong bang 9 hoac 6 " << endl;
}
return 0;
}
```

**Input 1**
n = 6;

**Output 1**
So nhap vao bang 9 hoac 6

**Input 2**
n = 9;

**Output 2**
So nhap vao bang 9 hoac 6

**Input 3**
n = 60;

**Output 3**
So nhap vao khong bang 9 hoac 6

### Logic AND (&&)

Toán tử logic và được sử dụng có nhiều điều kiện cần kiểm tra tính đúng sai.
Ví dụ : C&&D

- Nếu **cả hai** điều kiện **cùng đúng** thì trả về giá trị **true**
- Nếu **một trong hai** điều kiện **sai** thì trả về giá trị **false**

Ví dụ: Nhập vào một số nguyên và kiểm tra số đó có thuộc khoảng 0 - 10 hay không? Nếu có thì in ra màn hình thông báo? Nếu không thì in ra màn hình thông báo số đó không thuộc trong khoảng 0-10

```cpp
#include<iostream>
using namespace std;
int main(){
int n;
cout << " Nhap N " << endl;
cin>>n;
if(n>0 && n<10)
{
	cout << " So nay thuoc trong khoang 0 - 10    " << endl;
}
else
{
	cout << " So nay khong thuoc vao khoang 0 -10 " << endl;
}
return 0;
}
```

**Input 1**
n = 6;

**Output 1**
So nay thuoc trong khoang 0 - 10

**Input 2**
n = 90;

**Output 2**
So nay khong thuoc vao khoang 0 - 10

---

Lưu ý :

- Chỉ có dạng if thiếu( không có else) chứ **KHÔNG TỒN TẠI** else thiếu( không có if)
- Sự ưu tiên và mặt toán tử trong khi thực hiện lệnh điều kiện if else để tránh phát sinh lỗi không mong muốn.
  Một số bài tập áp dụng :

1. Nhập vào một số nguyên n.

- Kiểm tra xem số đó có lớn hơn bằng 10? Nếu có thì in ra màn hình dòng " Co ", Nếu không thì in ra màn hình " Không " ?
- Kiểm tra số n khác 50? Nếu có thì in ra màn hình dòng " Co ", Nếu không thì in ra màn hình " Không " ?
- Kiểm tra số n nhỏ hơn bằng 100? Nếu có thì in ra màn hình dòng " Co ", Nếu không thì in ra màn hình " Không " ?
- ...
