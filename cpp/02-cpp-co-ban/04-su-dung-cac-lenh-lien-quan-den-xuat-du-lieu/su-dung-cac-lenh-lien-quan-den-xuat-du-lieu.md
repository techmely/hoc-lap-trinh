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
  name: "Làm quen với ngôn ngữ C++"
  slug: "chuong-01-ngon-ngu-cpp-co-ban"
category:
  name: "Khóa học C++ cơ bản"
  slug: "C++"
image: https://kungfutech.edu.vn/thumbnail.png
position: 4
---
Hôm nay, chúng ta tiếp tục với khóa học lập trình C++ hướng thực hành.

Trong bài học này, chúng ta cùng nhau học cách sử dụng một số **lệnh** để in dữ liệu ra màn hình **console**, ngoài ra chúng ta còn tập cách định dạng chúng cho phù hợp, và một số thứ khác liên quan đến luồng dữ liệu output (**ostream**)...

Trước khi bắt đầu, chúng ta tạo một project C++ mới có tên là Bai1.3 (các bạn nhớ chọn thư mục lưu sao cho phù hợp)

![1-3-0](https://github.com/daynhauhoc/cppcoban/assets/88678933/af8f54b9-d749-4610-8615-f905eaac8db7)


Sau đó tạo file **main.cpp** và viết sẵn cấu trúc cơ bản một chương trình C++ trong file main.cpp

![1-3-1](https://github.com/daynhauhoc/cppcoban/assets/88678933/e2e4daa7-c1c1-4425-b832-d38ea0034ae3)


Nhấn tổ hợp phím **Ctrl + Shift + B** để thực hiện quá trình build project (làm thế để đảm bảo mọi thứ hoạt động bình thường trước khi bắt đầu viết code)

![1-3-2](https://github.com/daynhauhoc/cppcoban/assets/88678933/86022c1b-3415-4a9b-a006-30163f1bd05c)


Mình bắt đầu với một ví dụ đơn giản, đó là in tên của mình ra màn hình console. Để làm được điều này, chúng ta sử dụng lệnh **cout** và chúng ta từng dùng trong project **HelloWorld**. 

**cout** là một đối tượng được định nghĩa trong thư viện **iostream**, nó điều khiển một luồng dữ liệu đầu ra của chương trình, mặc định kết nối với output stream có tên là **stdout**. Dữ liệu được đưa vào đối tượng file **stdout** này sẽ được chuyển lên màn hình (hoặc thiết bị đầu ra chuẩn nào đó).

Vì thế, muốn sử dụng lệnh **cout** chúng ta cần include thư viện **iostream** vào trước (sử dụng luôn dòng **using namespace std** nhé).

![1-3-3](https://github.com/daynhauhoc/cppcoban/assets/88678933/c0c05945-2387-466d-8e43-553245751b40)


Để đưa một chuỗi kí tự lên màn hình, chúng ta cần đặt chuỗi kí tự đó giữa cặp dấu ngoặc kép **"** và **"**

![1-3-4](https://github.com/daynhauhoc/cppcoban/assets/88678933/2594d590-9ee8-4131-b45e-8e02d752e496)


Có một toán tử đi kèm với lệnh **cout** là **<<**. Về mặt cú pháp, chúng ta đặt toán tử **<<** giữa lệnh **cout** và cái mà chúng ta muốn đưa lên màn hình (có thể là một chuỗi kí tự, một con số, một biến số...)

Chạy thử chương trình bằng cách nhấn phím **F5**

![1-3-5](https://github.com/daynhauhoc/cppcoban/assets/88678933/0682a7a5-fa28-441c-82f5-2d49898870d4)


Nhìn vào kết quả chương trình, chúng ta thấy rất khó đọc vì lệnh ```system("pause")``` cũng in ra một dòng chữ và nó đứng liền kề với dòng chữ chúng ta muốn in ra. Để giải quyết vấn đề này, chúng ta cần làm cách nào đó để tách dòng chữ mà lệnh ```system("pause")``` in ra xuống 1 dòng khác. C++ đã hỗ trợ cho chúng ta một đối tượng khác cũng thuộc thư viện **iostream**, đó là **endl**.

Các bạn sử dụng **endl** như trong hình bên dưới.

![1-3-6](https://github.com/daynhauhoc/cppcoban/assets/88678933/5210c25e-640a-4a52-bca8-6fb0e77de366)


Nhìn vào kết quả, chúng ta thấy đã có sự khác biệt so với ban đầu.

Chúng ta còn có thể nối nhiều đoạn kí tự để in ra màn hình cùng lúc chỉ với 1 lần sử dụng lệnh **cout** bằng cách sử dụng nhiều lần toán tử **<<**

![1-3-7](https://github.com/daynhauhoc/cppcoban/assets/88678933/5396c713-577f-45f4-a0b5-130245c38baf)


Dòng dữ liệu chúng ta in ra vẫn chưa được đẹp mắt lắm. Hai câu "Hello friend!" và "Nice to meet you!" được truyền lần lượt theo thứ tự vào đối tượng file **stdout** thông qua lệnh **cout**, nhưng khi sử dụng nhiều lần toán tử **<<**, nó không tự động sinh ra khoảng trắng giữa các chuỗi riêng biệt, mà nó cứ nối vào nhau cho đến khi đến giới hạn số kí tự cho phép trên 1 dòng của **console** thì mới xuống dòng.

Vì thế, chúng ta cần điều chỉnh lại một chút. (Thêm 1 kí tự trắng sau câu đầu tiên)

![1-3-8](https://github.com/daynhauhoc/cppcoban/assets/88678933/acfcbc6d-8852-4b43-ab2e-aafa7383a3de)


Hai câu chúng ta in ra giờ đã rõ đẹp hơn phải không nào?

Qua ví dụ trên, chắc các bạn cũng phần nào hình dung được cách thức hoạt động của lệnh **cout**.

![1-3-cout](https://github.com/daynhauhoc/cppcoban/assets/88678933/75c65880-e1b4-43d1-849f-782453e36155)


(Nguồn: http://www.c4learn.com)

Ngoài việc sử dụng đối tượng **cout** để in các chuỗi kí tự lên màn hình, bạn còn có thể in những con số cụ thể.

![1-3-9](https://github.com/daynhauhoc/cppcoban/assets/88678933/e4a1c468-620c-4a90-afa5-7a1fe463159a)


Mình vừa thêm dòng bên dưới vào chương trình.

	cout << "I'm " << 24 << " years old." << endl;

Chúng ta cùng xem dòng này hoạt động như thế nào.

![1-3-10](https://github.com/daynhauhoc/cppcoban/assets/88678933/278c6f51-a5b8-4866-aa47-976e1c021399)

Khi bạn muốn in một giá trị lên màn hình, bạn có thể làm nhiều cách khác nhau. Bạn có thể đưa số đó vào trong cặp dấu ngoặc kép để biến nó thành chuỗi kí tự.

	cout << "I'm 24 years old." << endl;

Bạn có thể đưa nó ra ngoài cặp dấu ngoặc kép (nhớ sử dụng thêm toán tử **<<** nữa, vì kiểu chuỗi kí tự và kiểu số là hai loại kiểu dữ liệu khác nhau, nên cần tách chúng ra bằng toán tử **<<** để lệnh cout có thể hiểu được).

	cout << "I'm " << 24 << " years old." << endl;

Hoặc có một cách khác mà chúng ta sẽ dùng thường xuyên hơn trong các bài học sau, đó là đưa giá trị vào một biến số.

	int myAge = 24;
	cout << "I'm " << myAge << " years old." << endl;

Cả 3 cách trên đều cho ra kết quả giống nhau.

Trong ngôn ngữ lập trình C++, có một số kí tự trên bàn phím chúng ta không thể đưa trực tiếp vào cặp dấu ngoặc kép để in ra màn hình trong lệnh **cout** được. Chúng ta cần định dạng chúng lại một chút. Sau đây là bảng một số kí tự đặc biệt và cách để in chúng ra màn hình: 

![1-3-11](https://github.com/daynhauhoc/cppcoban/assets/88678933/4e949eb5-6c76-43a8-9c1f-5a8e2e21d7f5)


(Nguồn: https://msdn.microsoft.com)

Chúng ta cùng thử dùng một vài kí tự trong bảng trên và xem kết quả.
Đầu tiên là sử dụng kí tự xuống dòng:

![1-3-12](https://github.com/daynhauhoc/cppcoban/assets/88678933/e7adad84-c303-40a2-b59e-1b67930e9626)


Như các bạn thấy, không còn sử dụng đối tượng **endl** nữa nhưng chuỗi kí tự trên vẫn được tách thành 2 dòng bằng cách sử dụng kí tự new line **"\n"**.

Tiếp theo, chúng ta thêm kí tự **Tab** và đầu chuỗi kí tự muốn in ra:

![1-3-13](https://github.com/daynhauhoc/cppcoban/assets/88678933/f9ff5b72-3ca4-44f5-8b73-ad5a89e02afc)


Ta thấy dòng đầu tiên đã được đẩy vào 1 Tab so với dòng thứ 2. Các bạn có thể thử lần lượt các kí tự đặc biệt trên nếu có thời gian. Tuy nhiên, cần lưu ý rằng kí tự new line "\n" và đối tượng **endl** đều đóng vai trò là kí tự xuống dòng nhưng nó hoàn toàn khác nhau, mình sẽ giải thích vấn đề này sau.

Ngoài ra, các bạn còn có thể sử dụng đối tượng **cout** để in ra kết quả của một biểu thức toán học:

![1-3-14](https://github.com/daynhauhoc/cppcoban/assets/88678933/99eb938e-32ea-43f9-bb73-c0d2f0d47141)


Trong câu lệnh trên, biểu thức **12 + 2 * 3** được tính ra kết quả, kết quả biểu thức này được chương trình coi như một giá trị số, và nó hoàn toàn có thể đưa vào đối tượng file **stdout** bằng đối tượng **cout**.

Ngoài tính toán và cho ra kết quả số nguyên, một chương trình C++ còn có thể tính toán các biểu thức và in ra giá trị là số âm, số thực...

![1-3-15](https://github.com/daynhauhoc/cppcoban/assets/88678933/de3d8a8d-15fa-4753-b2f9-5b0ed35f8f6b)


- Chương trình C++ không thể in ra giá trị là một phân số (trừ khi chúng ta tự định nghĩa lại), vì thế, ở biểu thức cuối cùng, máy tính không in ra được giá trị là **5/10** mà nó chỉ có thể in ra giá trị 0 (tại sao lại không phải là 0.5?), chúng ta sẽ tìm hiểu vấn đề này trong bài học [Biến - cách khai báo và sử dụng biến](/1-cpp-co-ban/1-5-bien-cach-khai-bao-va-su-dung-bien.md).

- Compiler của Visual studio sẽ báo lỗi nếu nó bắt gặp biểu thức có dạng **x / 0**. Ví dụ:

		cout << 5 / 0 << endl; //This command makes an error



##Sử dụng thư viện iomanip

**iomanip** viết tắt của cụm từ **iostream manipulator** là một thư viện thuộc namespace **std**, nó định nghĩa một số hàm giúp lập trình viên có thể định dạng output.

Trong bài này, chúng ta chỉ làm quen với một số hàm đơn giản thường xuyên được sử dụng.

###setw(int n)

**setw** là một hàm cho phép giới hạn độ rộng của một giá trị được xuất lên màn hình.

Cách sử dụng:

![1-3-16](https://github.com/daynhauhoc/cppcoban/assets/88678933/b60fca36-3212-4dce-a992-defc27c20c27)


Cùng nhìn vào hình trên để xem cú pháp sử dụng và đánh giá kết quả.

- Đầu tiên, chúng ta include thêm thư viện **iomanip** vào chương trình.
- Tiếp theo, gọi hàm **setw(int n)** với n là một số nguyên (ví dụ: setw(8)) để định dạng độ rộng cho kiểu dữ liệu số, ngay lúc này, bất kì giá trị số nào được truyền vào luồng output stream thông qua **cout** đều bị đối tượng **cout** format có độ rộng là 10 ô.
- Cuối cùng thì thử truyền vài giá trị số nguyên vào để kiểm chứng thôi.

Trong hình trên, mình định dạng độ rộng của các số được đưa vào **cout** có độ rộng là 10, mình truyền thử 2 số nguyên mà số đầu tiên chỉ có 1 chữ số, số thứ 2 thì có 10 chữ số. Kết quả cho thấy có 9 khoảng trắng thừa đứng trước số 1 ở dòng đầu tiên.

Nếu các bạn muốn định dạng khoảng trắng phía sau, chỉ cần đổi giá trị trong hàm **setw** thành số âm như hình bên dưới:

![1-3-17](https://github.com/daynhauhoc/cppcoban/assets/88678933/e341eda0-20c0-4a8a-866c-a1968ba7a766)

###setprecision(int n)

Cũng tương tự như hàm **setw**, hàm **setprecision** cũng nhận vào một giá trị số nguyên, nhưng mục đích của hàm này là định dạng số lượng chữ số trong phần thập phân của kiểu số thực.

Cách sử dụng:

![1-3-18](https://github.com/daynhauhoc/cppcoban/assets/88678933/fb5918a8-692a-43cb-9b6a-a24f2d28e02d)


- Đảm bảo rằng thư viện **iomanip** đã được include vào chương trình.

- Đẩy định dạng độ chính xác **setpresicion(int n)** và đối tượng **cout** thông qua toán tử **<<**, sau thời điểm này, mọi số thực có phần thập phân sẽ được định dạng lại, với độ dài phần thập phân bằng với số nguyên mà bạn đặt trong hàm **setprecision**.

Nhìn vào kết quả của đoạn chương trình trên, ta thấy rằng mặc định phần thập phân của một số thực chỉ có 6 chữ số. Sau khi định dạng lại với hàm **setprecision(9)** thì độ chính xác đã lên đến 9 chữ số.

##Tổng kết

Đến đây, chúng ta đã nắm được cú pháp và cách hoạt động của đối tượng **cout** thuộc thư viện **iostream** trong **namespace std**. Các bạn đã biết cách: 

- In một dòng chữ lên màn hình console.
- In liên tiếp nhiều chuỗi kí tự trong một lần sử dụng đối tượng **cout**.
- In giá trị số nguyên, số thực.
- In các kí tự đặc biệt "\n", "\t", ... lên màn hình.
- In kết quả của một biểu thức.
- Một số định dạng cơ bản với số nguyên và số thực.


##Bài tập rèn luyện

1. Viết chương trình in kết quả 4 phép tính +, -, *, / của 2 số.
2. Từ chương trình đã viết được ở câu 1, thêm vào 1 dòng lệnh khiến chương trình phát ra 1 âm báo.


**Hẹn gặp lại các bạn trong bài học tiếp theo trong khóa học lập trình C++ hướng thực hành.**


Mọi ý kiến đóng góp hoặc thắc mắc có thể đặt câu hỏi trực tiếp tại diễn đàn 

**www.daynhauhoc.com**
