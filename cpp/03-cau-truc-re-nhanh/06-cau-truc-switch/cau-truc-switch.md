---
title: "Giới thiệu về ngôn ngữ lập trình"
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
  name: "Các cấu trúc trong C++"
  slug: "chuong-03-cau-truc-trong-c++"
category:
  name: "Khóa học C++ cơ bản"
  slug: "C++"
image: https://kungfutech.edu.vn/thumbnail.png
position: 6
---

---

## Cấu trúc Switch-Case

Chúng ta thử cùng xem ví dụ sau :

Nhập vào một số nguyên. Sau đó kiểm tra số đó có bằng 1 trong các số từ 0 tới 3 hay không ?
Nếu có thì in ra màn hình số đó là số nào ?

    	#include<iostream>
    		using namespace std;
    		int main()
    		{
    	int n;
    	cout << " Nhap vao n : " << endl;
    	cin >> n;
    	if(n==0)
    	{
    	cout << " n la so  0"<< endl;
    	}
    	else
    	{
    		if(n==1)
    			{
    		cout << " n la so  1"<< endl;
    			}
    		else
    		   {
    			if(n==2)
    				{
    			cout << " n la so  2"<< endl;
    				}
    				else
    				    {
    					if(n==3)
    						{
    							cout << " n la so  3"<< endl;
    				    		}
    					else
    						{
    							cout << " n khong thuoc khoang 0 -3 " << endl;
    						}
    				    }
    		    }
    	}
    		return 0;
    	}

---

Chúng ta có thể thấy việc sử dụng if else ìf trong trường hợp này gây phức tạp cho bài toán và gây khó đọc.
Chúng ta sẽ sử dụng cấu trúc switch case như sau :

    	#include<iostream>

    	using namespace std;

    	int main()
    		{
    	 	int n;
    		cout << " Nhap vao n : " << endl;
    		cin >> n;

    		switch(n)
    		{
    		case 0 :
     				{
    			 cout << " n la so  0" << endl;
    			}
    			break;
    		case 1:
     				{
    			 cout << " n la so  1" << endl;
    			}
    			break;
    		case 2 :
     				{
    			 cout << " n la so  2" << endl;
    			}
    			break;
    		case 3 :
     				{
    			 cout << " n la so  3" << endl;
    			}
    			break;
    		defual :

{
cout << " n khong thuoc khoang 0 -3 " << endl;
}
break;
}
return 0;
}

---

Cùng đi phân tích kỹ hơn về cấu trúc của switch case

### Switch

Để sử dụng switch chúng ta bắt đầu với từ khóa `switch`. Ngay sau đó là phần mà chúng ta muốn kiểm tra điều kiện. Chúng ta có thể truyền vào các kiểu như

- `char`
- `short`
- `int`
- `long int `
- `enum`

> float double pointer . . . và một số kiểu khác không sử dụng được.
> _Đây là một hạn chế của cấu trúc switch_

### Case, Default

Sau khi đã nhận kiểu cần kiểm tra. Phần kiểm tra sẽ được thực hiện trong các khối.
Có 2 loại khối được sử dụng đó là case hoặc defual.

- Với **case**, chúng ta sẽ sử dụng với từ khóa `case` và ngay sau đó là một biểu thức hằng số có giá trị không đổi.
- Với các khối **case** chúng sẽ được kiểm tra lần lượt như nhau.

- Với **default** là một khối mặc định của cấu trúc **switch**. Nó được gọi tới khi các khối **case** không có giá trị thỏa mãn với phần chúng ta truyền vào tại **switch**. Chúng ta sử dụng **default** với từ khóa `default` thường được đặt dưới cùng sau các **case**.

> Có thể có hoặc không khối `default` trong một cấu trúc `switch`.

Để hiểu rõ hơn chúng ta cùng xem đoạn code sau :
Ví dụ :

```cpp
#include<iostream>

using namespace std;
int main()
{
int n=1;
switch(n)
{
case 0 :
		{
	 cout << " la so  0" << endl;
	}
case 1:
		{
	 cout << " la so  1" << endl;
	}
case 2 :
		{
	 cout << " la so  2" << endl;
	}
case 3 :
		{
	 cout << " la so  3" << endl;
	}
default :
	{
	cout << " la mot so nao do " << endl;
	}
}
return 0;
}
```

**Output**

```
la so 1
la so 2
la so 3
la mot so nao do
```

Tại sao lại như vậy ?

Khi thực hiện khối **case** hoặc **default** nếu gặp trường hợp đúng. Thì các khối tiếp theo vẫn được thực hiện lần lượt.

Chúng chỉ kết thúc khi gặp một trong các trường hợp sau :

- Khi **kết thúc** cấu trúc switch
- Khi gặp lệnh `return`
- Khi gặp lệnh `goto`
- Khi gặp lệnh `break`

### Break trong cấu trúc switch

Trong các khối **case** và **default** cần có lệnh break để kết thúc việc kiểm tra và thoát ra khỏi switch.

> Lệnh `break` được khai báo với từ khóa `break`. Nó có chức năng thông báo cho trình biên dịch biết rằng : switch( hay `for`, `while`,`do while` . . .) đã kết thúc tại đây. Sau lệnh `break` chương trình sẽ tiếp tục thực hiện các câu lệnh sau khối switch( hay `for`, `while`,`do while` . . .)

Quay lại với ví dụ ở phần trước :

```cpp
#include<iostream>
using namespace std;
int main()
{
int n = 1;

switch(n)
{
case 0 :
{
cout << " la so 0" << endl;
break;
}
case 1:
{
cout << " la so 1" << endl;
break;
}
case 2 :
{
cout << " la so 2" << endl;
break;
}
case 3 :
{
cout << " la so 3" << endl;
break;
}
default :
{
cout << " la mot so nao do " << endl;
break;
}
}
cout << " Chuong trinh da hoan thanh " << endl;
return 0;
}
```

**Output**

```
la so  1
Chuong trinh da hoan thanh
```

Vấn đề đã được giải quyết. Chương trình chạy, `Case 1 :` đúng với điều kiện, màn hình in ra " la so 1". Tiếp theo là lệnh `break` và cấu trúc switch kết thúc tại đây. Và lệnh cout cuối được gọi vì nó nằm sau cấu trúc **switch**.

## LƯU Ý

- Biểu thức truyền vào sau switch. Phải là một biếu thức được phép.

- Lệnh `break` sau mỗi khối case và default. Nếu ta không sử dụng break ta phải kiểm soát được việc mình đang muốn thực hiện trong `switch case`

- Cặp `{}`. Khi có nhiều hơn hai câu lệnh với các khối case và default ta phải có cặp ngoặc {} để tránh tình trạng xảy ra lỗi không như mong muốn.

- Khi có nhiều khối case có chức năng như nhau thì ta có thể sử dụng cấu trúc sau :

```cpp
case <hang so>:
case <hang so>:
case <hang so>:
case <hang so>:
case <hang so>:
case <hang so>:
{
	// làm gì đó
	break;
}
```

Áp dụng :

- Nhập vào một ký tự bất kì và kiểm tra xem kí tự đó có phải là các kí tự từ '0' - '9' hay không ?
- Nhập vào tháng trong năm nhuận và in ra số ngày tối đa của tháng đó ?
