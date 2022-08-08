—
title:”Biến trong C#”
description:”Trong bài này mình sẽ giới thiệu định nghĩa của biến trong C#, cách hoạt động của biến và cách thao tác với biến và cuối cùng là quy tắc đặt tên biến”
keywords:[
“biến trong C#”,
“bien trong C#”,
]
chapter:
name: ”Biến trong C#”
slug: ”Bien-trong-C#”
categoy:
name: "C#"
slug: "C#"
image: <https://kungfutech.edu.vn/thumbnail.png>
position: 2
—

# Định nghĩa về biến trong C#

<content-info>
Tương tự với biến trong toán học, biến trong ngôn ngữ lập trình là một giá trị dữ liệu có thể thay đổi được. Biến là tên gọi tham chiếu đến một vùng nhớ nào đó trong bộ nhớ.
</content-info>

## Tại sao phải sử dụng biến?

Biến sinh ra với mục đích lưu trữ dữ liệu và tái sử dụng khi cần. Ví dụ khi chương trình yêu cầu người dùng nhập ngày tháng năm sinh nhưng lại không lưu lại ở đâu cả, đến khi cần sử dụng thông tin đó thì chương trình sẽ không thể lấy được thông tin người dùng nhập trước đó để sử dụng. Để giải quyết bài toán trên biến sinh ra cho phép chương trình lưu trữ tạm thông tin người dùng trên một vùng nhớ và thực hiện truy suất khi cần sử dụng.

## Biến thao tác với bộ nhớ như thế nào?

Cấu trúc của bộ nhớ gồm nhiều ô nhớ liên tiếp nhau, mỗi ô nhớ có một địa chỉ riêng (địa chỉ ô nhớ thường mã hex). Khi chương trình muốn thao tác với ô nhớ nào (lấy giá trị, hủy giá trí, lưu giá trị) thì phải thông qua địa chỉ của ô nhớ đó. Để làm được việc đó ta sẽ khai báo biến, nó sẽ tham chiếu đến ô nhớ, sau đó ta khởi tạo giá trị cho biến, lúc này ô nhớ đó sẽ mang giá trị của biến, khi muốn thao tác với giá trị của ô nhớ ta sẽ sử dụng biến.

# Khai báo sử dụng biến

cú pháp:

```
{kiểu dữ liệu} {tên biến};
```

{kiểu dữ liệu}: có thể là kiểu dữ liệu cơ bản hoặc kiểu dữ liệu có cầu trúc (kiểu dữ liệu sẽ được trình bày chi tiết tại link bài viết kiểu dữ liệu.)

{tên biến}: là tên do người dùng đặt, phải tuân thủ theo quy tắc đặt tên (sẽ được trình bày ở phần dưới).

## ví dụ về khai báo biến

Biến kiểu số nguyên:

```
int bienKieuSoNguyen;
```

Biến kiểu số thực:

```
float bienKieuSoThuc;
```

Biến kiểu chuỗi:

```
string bienKieuChuoi;
```

Biến kiểu luận lý:

```
bool bienKieuKieuLuanLy;
```

Biến kiểu ký tự:

```
char bienKieuKieuKyTu;
```

# Sử dụng biến trong C#

## Tạo 1 biến có giá trị

Để tạo 1 biến có giá trị ta có 2 cách.
<space><space>

Cách 1: Khai báo biến rồi gán giá trị

```
int soNguyen; //Khai báo biến
soNguyen = 1; //Gán giá trị
```

Cách 2: khởi tạo giá trị cho biến

```
int soNguyen = 1;
```

## Sửa giá trị của biến

Để sử giá trị của biến ta thực hiện gán giá trị mới cho biến đó

```
soNguyen = 1; //Gán giá trị
soNguyen = 2; //Gán giá trị mới cho biến
```

## Lấy giá trị của biến

Để lấy giá trị của biến ta chỉ cần gọi tên của biến đó

```
int soNguyen; //Khai báo biến
soNguyen = 1; //Gán giá trị
Console.WriteLine(soNguyen);
Output: 1
```

```
int a = 1, b = 2 ;
int c = a + b; 
Console.WriteLine(c);

Output: 3
```

# Quy tắc đặt tên biến

Sau đây là một số quy tắc đặt tên biến:

- Tên biến là một chuỗi ký tự liên kết (không có khoảng trắng) và không chứa ký tự đặc biệt.
- Tên biến không được đặt bằng tiếng việt có dấu.
- Tên biến không được bắt đầu bằng số.
- Tên biến không được trùng với từ khóa.

Dưới đây là danh sách các từ khóa trong C#:
![15471](https://user-images.githubusercontent.com/50008521/183381973-fda2b2d9-3a74-48e1-a732-b6e02a2fbdba.jpg)

<content-info>
Biến trong C# thường được đặt tên bằng quy tắc (camel case) tức là viết thường từ đầu tiên và viết hoa chữ cái đầu tiên của những từ tiếp theo.
</content-info>
