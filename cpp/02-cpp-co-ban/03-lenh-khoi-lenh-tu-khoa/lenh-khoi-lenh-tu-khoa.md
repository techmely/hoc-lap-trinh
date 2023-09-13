---
title: "Lệnh và khối lệnh trong c++"
description: "Chào mừng đến với loạt bài hướng dẫn sử dụng ngôn ngữ lập trình C++! Loạt bài hướng dẫn này được thiết kế cho những người chưa hoặc biết một ít lập trình."
chapter:
  name: "Làm quen với ngôn ngữ C++"
  slug: "chuong-01-ngon-ngu-cpp-co-ban"
category:
  name: "Khóa học C++ cơ bản"
  slug: "C++"
image: https://kungfutech.edu.vn/thumbnail.png
position: 3
---

Rất vui khi được gặp lại các bạn trong bài học tiếp theo trong khóa học lập trình C++ hướng thực hành. Hôm trước, chúng ta đã có cái nhìn đầu tiên về các thành phần cơ bản hình thành nên một chương trình C++.

Mình sẽ nhắc lại một chút trong bài học trước.

Cấu trúc của một chương trình C++ cơ bản: + Hàm main: (bắt buộc phải có)

- Kiểu trả về của hàm main (int).
- Tên của hàm main (cũng là main luôn).
- Thân của hàm main (cặp dấu ngoặc nhọn { và }).
- Giá trị trả về của hàm main (return 0; //hoặc giá trị bao nhiêu cũng đc).
- Những dòng lệnh bên trong thân hàm main. (Có thể có hoặc không)
- Những dòng comment. (Có thể có hoặc không)
- Tích hợp thư viện và không gian tên. (Phụ thuộc vào các lệnh mà bạn sử dụng).

Chúng ta đã biết hàm main là thứ quan trọng nhất cần phải có của một chương trình C++. Chúng ta hoàn toàn có thể khai báo hàm main xong và chạy chương trình ngay mà không bị báo lỗi.

![image](https://github.com/techmely/hoc-lap-trinh/assets/29374426/1d34c80e-1d1f-4a8c-a357-a4c72a201faa)

Như các bạn thấy, chương trình vẫn được build thành file .exe và hoàn toàn có thể chạy được (Các bạn nhấn thử phím F5). Nhưng khi cửa sổ console vừa hiện lên thì chương trình đóng lại ngay lập tức. Vì bạn không yêu cầu máy tính thực hiện công việc gì cả. Một chương trình máy tính được tạo ra để không làm gì cả thì thật là vô ích.

Để giải quyết vấn đề mà chúng ta đặt ra trên máy tính, chúng ta cần ra lệnh cho máy tính thực hiện các công việc cụ thể. Chúng ta ra lệnh cho máy tính bằng các lệnh trong ngôn ngữ lập trình. Để máy tính thực hiện công việc và cho ra kết quả, nó cần nhận lệnh từ người lập trình. Vì thế, yếu tố quan trọng chỉ đứng sau hàm **main** chính là **những câu lệnh**.

### Lệnh trong ngôn ngữ lập trình C++

Trong C++, một lệnh là một chỉ thị riêng biệt của một chương trình.
Ví dụ:

```cpp
int variable = 0;
cout << "Print something";
variable = variable + 10;
system("pause");
```

Ở trên đây, chúng là có 4 dòng lệnh. 4 dòng lệnh này chỉ dẫn máy tính thực hiện 4 công việc khác nhau, nhưng trên phương diện cú pháp, nó có một đặc điểm chung rất quan trọng cần phải nhớ: **dòng lệnh kết thúc bằng dấu chấm phẩy ";"**

Chỉ cần một dòng lệnh bị bỏ sót dấu chấm phẩy, IDE sẽ thông báo với người lập trình lỗi về cú pháp.

![image](https://github.com/techmely/hoc-lap-trinh/assets/29374426/9dff2a9e-68e6-43b6-b565-f1430c75533c)

Thông báo lỗi này có nghĩa bạn viết thiếu dấu chấm phẩy ";" ở trước dòng thứ 6 trong chương trình.

![image](https://github.com/techmely/hoc-lap-trinh/assets/29374426/1cc35deb-783d-4907-a891-a6dcf4738acf)

Sau khi thêm dấu chấm phẩy vào dòng lệnh trước đó, chương trình được build bình thường.

::alert{type="warning"}
Một điều cần lưu ý nữa là: **Tại một thời điểm, chương trình chỉ có thể thực hiện được 1 dòng lệnh. Các dòng lệnh được thực hiện tuần tự từ trên xuống dưới.**
::

![image](https://github.com/techmely/hoc-lap-trinh/assets/29374426/a03dda35-7d3f-48ca-9183-3ddb5c99f2be)

Như kết quả trong hình, ta có dòng chữ **"Statement 1"** được in ra trước dòng **"Statement 2"** và **"Statement 3"** vì dòng lệnh dùng để in ra **"Statement 1"** nằm phía trên các lệnh còn lại.

Ở ví dụ trên chỉ bao gồm các câu lệnh đơn giản. Chúng ta sẽ được học những lệnh có cấu trúc đặc biệt như **câu lệnh có cấu trúc rẽ nhánh**, **câu lệnh có cấu trúc lặp**... trong những bài sau.

###Khối lệnh

Trong C++, một khối lệnh là tập hợp những câu lệnh được đặt trong cặp dấu ngoặc nhọn **{** và **}**.

Một khối lệnh có thể chứa nhiều dòng lệnh, có thể chứa một dòng lệnh hoặc không chứa dòng lệnh nào. Một khối lệnh còn có thể chứa một hoặc nhiều khối lệnh khác.

```cpp
#include <iostream>
using namespace std;
int main()	{
	int variable = 1;
	{
		int variable = 10;
		cout << "The variable inside this block is not concerning the variable above" << endl;
		cout << "We print the value of the second variable: " << variable << endl;
	}
	cout << "We print the value of the first variable: " << variable << endl;
	system("pause");
	return 0;
}
```

Dễ thấy nhất là khối lệnh đóng vai trò **thân của hàm main**. Trong khối lệnh thân hàm main, chúng ta có một khối lệnh khác có chức năng in ra giá trị của biến variable thứ hai (bên trong khối lệnh con). Khối lệnh con này không gây ảnh hưởng gì với các câu lệnh bên ngoài nó.

Chúng ta cùng xem kết quả đoạn chương trình trên:

![image](https://github.com/techmely/hoc-lap-trinh/assets/29374426/d3ae430f-e6c0-4be0-98f6-d874ed56b1a1)

Chúng ta thấy giá trị của biến variable bên trong khối lệnh con hoàn toàn khác so với giá trị của biến variable bên ngoài. (**Các bạn sẽ hiểu được biến là gì qua những bài học tiếp theo**)

### Từ khóa trong C++

Trong ngôn ngữ lập trình C++ hay bất kỳ ngôn ngữ lập trình nào khác, chúng ta đều có sẵn một số các **từ khóa** do người tạo ra ngôn ngữ đó định nghĩa sẵn. Mỗi từ khóa có một ý nghĩa riêng, khi chúng ta kết hợp các từ khóa và một số cú pháp đi kèm, chúng ta sẽ có được câu lệnh.

Ví dụ:

`int var;`

Lệnh trên sử dụng từ khóa **int** để định nghĩa một biến tên **var** có kiểu số nguyên (**integer**).

`const float f_number = 1.0f;`

Câu lệnh trên sử dụng 2 từ khóa: **const** và **float** kết hợp với một số yếu tổ khác tạo nên một câu lệnh có chức năng khai báo một hằng số kiểu số thực và gắn cho nó giá trị cố định là 1.

Những từ khóa đã được định nghĩa và luôn sẵn sàng để sử dụng. Vì thế, chúng ta không cần **include** các thư viện ngoài vào để sử dụng chúng.

Dưới đây là bảng các từ khóa phổ biến dùng trong ngôn ngữ C++ 11

![image](https://github.com/techmely/hoc-lap-trinh/assets/29374426/36e2b4cc-3ced-46fe-a4fa-c5aa1dab4c8e)

Các bạn sẽ được cùng mình sử dụng những từ khóa thông dụng trong quá trình học và làm bài tập của khóa học này.

_Trong bảng từ khóa trên có một vài từ khóa được bổ sung thông qua chuẩn C++ 11._

### Tổng kết

Qua bài học ngày hôm nay, chúng ta hiểu rõ hơn khái niệm **Lệnh và khối lệnh**, để sau này khi mình thường xuyên dùng đến từ này thì các bạn sẽ tránh khỏi một số thắc mắc không cần thiết.

Ngoài ra, chúng ta còn được xem qua bảng các từ khóa đã được định nghĩa sẵn trong ngôn ngữ lập trình C++.

Hẹn gặp lại các bạn trong bài học tiếp theo. Cảm ơn các bạn đã quan tâm đến khóa học. Mọi ý kiến đóng góp hoặc thắc mắc các bạn có thể đặt câu hỏi trực tiếp thông qua diễn đàn
