---
title: "Cấu trúc if else if trong c++"
description: "Chào mừng đến với loạt bài hướng dẫn sử dụng ngôn ngữ lập trình C++! Loạt bài hướng dẫn này được thiết kế cho những người chưa hoặc biết một ít lập trình."
chapter:
  name: "Các cấu trúc trong C++"
  slug: "chuong-03-cau-truc-trong-c++"
category:
  name: "Khóa học C++ cơ bản"
  slug: "C++"
image: https://kungfutech.edu.vn/thumbnail.png
position: 5
---

---

## Cấu trúc if khác (if...else if ..., cấu trúc if lồng nhau)

> Chúng ta sẽ cùng sử dụng kiến thức của bài if else và toán tử logic để cùng tìm hiểu bài này.

> Hi vọng các bạn nắm chắc kiến thức bài trước. Để không khỏi bỡ ngỡ tại bài này.

Ví dụ: Nhập vào một số nguyên. Kiểm tra xem số đó có là số dương hay không ? Nếu có thì in ra màn hình thông báo là số dương. Nếu không thì in ra màn hình là số âm.

Các bạn tham khảo đoạn code sau :

```cpp
#include<iostream>
	using namespace std;
	int main()
	{
	int n;
	cout << " Nhap vao so nguyen "<< endl;
	cin >> n;
		if( n > 0)
			{
				cout << n << " la so duong " << endl;
			}
		else
			{
				cout << n << " la so am" << endl;
			}
	return 0;
}
```

**Input 1**

    n=10;

**Output 1**
10 la so duong

**Input 2**

    n=-10;

**Output 2**
-10 la so am

**Input 3**

    `n=0;`

**Output 3**
`0 la so am`

### Có điều gì đó không ổn ở Output số 3 rồi.

Vì vậy, bài toán chưa thực sự hoạt động tốt.
Chúng ta sẽ sử dụng cấu trúc if esle if lồng nhau để giải quyết vấn đề này.

```cpp
#include<iostream>
using namespace std;
int main()
{
int n;
cout << " Nhap vao so nguyen "<< endl;
cin >> n;
	if( n > 0)
		{
			cout << n << " la so duong " << endl;
		}
	else
		{
			if( n < 0)
				{
						cout << n << " la so am" << endl;
					}
			else
				{
					cout << n << " la so 0" << endl;
				}
		}
return 0;
}
```

**Input 1**

    n=10;

**Output 1**
10 la so duong

**Input 2**

    n=-10;

**Output 2**
-10 la so am

**Input 3**

    n=0;

**Output 3**
0 la so 0

Chúng ta có thể diễn giải đoạn code trên như sau :

**Nếu** _n > 0_ **thì** _in ra_ màn hình **n là số dương**

**Ngược lại** _n không lớn hơn 0_, **thì** chỉ có 2 trường hợp là _nhỏ hơn 0_ hoặc _bằng 0_.

**Tiếp tục** kiểm tra **nếu** _n<0_ **thì** _in ra_ màn hình **n là số âm**.

**Nếu** _n không nhỏ hơn không_ **thì** lúc này chắc chắn **n bằng 0** và _in ra_ màn hình **n là số 0**

> Các bạn có thể áp dụng if else if một cách linh hoạt tùy vào từng trường hợp.

**Lưu ý**: Trong khối lệnh sau if hoặc else chúng ta có thể gọi thêm các cấu trúc if else khác. Nhưng phải để ý tới điều kiện của biểu thức để tránh có lỗi không mong muốn.

Áp dụng :
Các bạn đã có thể làm một trò kinh điển đơn giản sử dụng với việc sử dụng if else if.

### Búa Giấy Kéo...

Xây dụng một ứng dụng console. Cho phép nhập vào lựa chọn

**1** ứng với **Búa**

**2** ứng với **Giấy**

**3** ứng với **Kéo**

Kiểm tra việc nhập và in ra màn hình xem người dùng vừa lựa chọn Búa , Giấy hay Kéo.

> Nâng cấp. Cho 2 người dùng lần lượt chọn. Sau đó kiểm tra xem sự lựa chọn của người dùng nào thắng. Và in ra màn hình người thắng cuộc
> Búa thắng Kéo.
> Kéo thắng Giấy.
> Giấy Thắng Búa.
