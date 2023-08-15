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
position: 2
---

Chào mừng các bạn đến với bài học tiếp theo trong khóa học lập trình C++ hướng thực hành.

Trong bài trước, [Viết chương trình C++ đầu tiên](1-cpp-co-ban/1-0-viet-chuong-trinh-dau-tien.md), chúng ta đã cùng nhau tạo 1 project có tên **HelloWorld**. Các bạn lưu ý rằng khi làm việc với Visual studio 2015 thì chúng ta làm việc trên 1 project chứ không làm việc với file mã nguồn đơn lẻ. Project **HelloWorld** hiện tại chỉ có một file có tên là **main.cpp**. Kết quả khi thực thi project này (bằng cách nhấn phím F5 để Debug) thì chúng ta được như hình bên dưới:

![1-1-0](https://github.com/daynhauhoc/cppcoban/assets/88678933/041b94cb-b73b-4794-90a9-1b66283d4365)

Kết quả là một dòng chữ **Hello World** xuất hiện trên console.

Khi các bạn Debug trên Visual studio 2015, có thể Visual studio sẽ download một số file PDB về làm tốn thời gian. Các bạn có thể tắt việc tự động download các file đó bằng cách làm theo các bước sau:

Đưa chuột vào phần DEBUG trên Menu bar -> chọn Options and Settings...

![1-1-1](https://github.com/daynhauhoc/cppcoban/assets/88678933/8dcac668-3834-4a91-9383-609340a166c6)

Chọn Symbols và bỏ dấu tick trong Symbol file (.pdb) locations đi

![1-1-2](https://github.com/daynhauhoc/cppcoban/assets/88678933/fb2fde36-b0e4-4cb0-bfc9-508802a8857e)

Bây giờ chúng ta nhìn lại mã nguồn trong file main.cpp và mình sẽ phân tích chức năng của từng dòng code.

```cpp
/_ HelloWorld program_/
#include <iostream>
using namespace std;
int main() {
// We write some code inside main function.
cout << "Hello World." << endl; // The "Hello World" string will be appear on screen.
system("pause"); // Pause the program to see the result.
return 0;
}

```

- **Dòng 6**:

```cpp
int main()
```

Như đã nói ở bài trước, **main là một hàm mà đi sau nó là một cặp dấu ngoặc nhọn { }**, một điểm xuất phát cho một project của ngôn ngữ C++. Không cần biết một project C++ của bạn có bao nhiêu file, một khi project đã được build và liên kết các file thành một file thực thi (.exe), hệ điều hành sẽ thực thi những dòng lệnh trong phạm vi dấu ngoặc nhọn nằm sau hàm main một cách **lần lượt từ trên xuống dưới**.

Với những bạn lần đầu viết code C++, các bạn có thể bỏ sót dòng này. Cùng xem thử Visual studio sẽ làm gì khi bạn không viết ra dòng int main() bằng cách đổi tên **main** thành một tên bất kỳ.

![1-1-3](https://github.com/daynhauhoc/cppcoban/assets/88678933/087f2274-8dfc-47a2-895e-f00ad9cb9263)

Visual studio thông báo một lỗi nghiêm trọng LNK1561, và nó còn đưa thêm hướng dẫn để lập trình viên có thể tự sửa lỗi có nghĩa là điểm khởi đầu cần được định nghĩa.

Chúng ta quay lại với đoạn mã nguồn có thể chạy được như lúc đầu bằng cách sửa lại tên hàm là
`int main()`.

- **Dòng 7**:

```cpp
// We write some code inside main function.
```

Đây không phải là một dòng lệnh. Đây là một dòng comment, mục đích của comment trong code là để ghi chú lại những gì mình đang làm. Việc ghi chú này cần được thực hiện thường xuyên đối với những người mới học lập trình. Ghi chú giúp bạn ít bị rối và khó hiểu khi nhìn lại những đoạn code cũ

![1-1-4](https://github.com/daynhauhoc/cppcoban/assets/88678933/55287efd-297d-4697-931d-df47ef09c005)

và những người làm việc cùng nhóm với bạn cũng sẽ hiểu được bạn đang muốn làm gì.

**Một dòng comment bắt đầu với 2 dấu gạch chéo //**.

Bây giờ bạn thử tự viết cho mình vài dòng comment đi nào. Comment bạn có thể đặt ở bất kỳ vị trí nào trong mã nguồn (ngoại trừ chèn comment làm ảnh hưởng đến dòng lệnh) mà không bị báo lỗi. Vì khi biên dịch, compiler nhìn thấy dòng comment thì nó sẽ bỏ qua và không làm gì cả.

- **Dòng 9**:

```cpp
cout << "Hello World." << endl; // The "Hello World" string will be appear on screen.
```

Đây là một dòng lệnh và đi kèm sau đó là một dòng comment. Dòng lệnh này chính là thứ đã viết lên console dòng **Hello World** mà bạn đã thấy trong kết quả của chương trình.

**Một dòng lệnh phải được kết thúc bằng dấu chấm phẩy ";"**

Lệnh **cout** có tác dụng viết lên console tất cả những gì nằm trong cặp dấu ngoặc kép **" "**. Như các bạn thấy, chúng ta đặt 2 từ **Hello** và **World** bên trong cặp ngoặc kép nên nó đã được in ra màn hình console.

- **Dòng 11**:

```cpp
system("pause"); // Pause the program to see the result.
```

Tiếp tục là một dòng lệnh và đi kèm một dòng comment ở phía sau.
Mục đích của dòng lệnh này là để dừng chương trình và xem kết quả trên màn hình console. Các bạn có thể xóa dòng này đi và chạy lại chương trình bằng cách nhấn phím F5 để kiểm chứng kết quả. Lúc này màn hình console hiện lên và tắt ngay lập tức.

- **Dòng 12**:

```cpp
return 0;
```

Là giá trị trả về của hàm main. Hàm main của chúng ta có từ khóa **int** đứng trước, có nghĩa là kiểu trả về của hàm main sẽ là một giá trị có kiểu **int** (integer - số nguyên). Giá trị trả về này do lập trình viên tự quy định. Kết quả hàm main sẽ hiển thị trong cửa sổ **Output** bên trong IDE sau khi bạn tắt chương trình HelloWorld đang chạy đi.

![1-1-5](https://github.com/daynhauhoc/cppcoban/assets/88678933/2b700a52-6566-49ce-9c04-2ae57220ad83)

Thông thường, dòng này sẽ đặt cuối cùng trong phạm vi cặp ngoặc nhọn { } phía sau hàm main. Các bạn có thể thay bằng một con số bất kì sao cho bạn có thể hiểu được rằng, khi chương trình kết thúc, nếu **Output** xuất hiện con số mà bạn đã chọn, điều đó có nghĩa chương trình của bạn hoạt động một cách bình thường.

- **Dòng 3 và 4**:

```cpp
#include <iostream>
```

```cpp
using namespace std;
```

Đây là những dòng lệnh đặc biệt. Để có thể sử dụng dòng lệnh số 9 trong chương trình thì chúng ta cần có dòng lệnh số 3 và số 4 này. Mục đích của 2 dòng lệnh này là thêm thư viện có tên **iostream** và không gian tên **std** để tích hợp vào chương trình. Hay nói cách khác, vì lệnh **cout** được định nghĩa bên trong thư viện có tên **iostream** và bên trong không gian tên **std** nên chúng ta cần tích hợp 2 thứ đó vào chương trình. Đến đây các bạn sẽ thắc mắc là **"Làm thế nào biết được dòng lệnh nào đã được định nghĩa bên trong thư viện nào?"**

Qua quá trình thực hành trong khóa học này, mình sẽ cùng các bạn sử dụng một số chức năng bên trong một số thư viện chuẩn do ngôn ngữ C++ đã định nghĩa sẵn và các bạn sẽ quen với việc tìm và sử dụng chức năng nào trong thư viện nào.

_Đây cũng là một đặc trưng của ngôn ngữ lập trình bậc cao. Chúng ta sử dụng lại những gì đã được định nghĩa sẵn giúp công việc lập trình của chúng ta dễ dàng hơn._

- **Dòng 1**:

```cpp
/* HelloWorld program*/
```

Đây cũng là một đoạn comment. Đoạn comment khác với dòng comment. Đoạn comment được đặt giữa cặp dấu /_ và _/ trong khi dòng comment đứng sau 2 dấu gạch chéo //. Chúng ta có thể có nhiều dòng comment trong 1 đoạn comment. Ví dụ:

```cpp
/*
Đây là một dòng comment.
Đây là một dòng comment khác.
Các bạn thích viết bao nhiêu dòng comment giữa này cũng được.
*/
```

Mình đã giải thích xong chức năng và cách hoạt động của mã nguồn file **main.cpp** trong project **HelloWorld**. Có thể các bạn chưa thể hiểu hết được, nhưng đừng lo lắng về điều đó, chúng ta sẽ quen với việc sử dụng ngôn ngữ C++ khi thực hành nhiều và nếu cần thiết các bạn sẽ được những người làm khóa học này hỗ trợ trực tiếp.

Bây giờ là lúc để hình dung về cấu trúc của chương trình C++ cơ bản mà chúng ta đã làm cùng nhau.

### Cấu trúc cơ bản của chương trình C++

Đâu tiên, chúng ta có hàm **main**

```cpp
int main()
```

Sau đó, chúng ta có phần thân của hàm main là cặp dấu ngoặc nhọn đứng sau từ khóa **main**, cuối thân hàm **main** là giá trị trả về của hàm **main**.

```cpp
int main() {
  return 0;
}
```

Tiếp đến, chúng ta có những dòng lệnh đặt bên trong thân hàm **main**

```cpp
int main() {
  cout << "This is a command" << endl;
  return 0;
}
```

Bên cạnh những dòng lệnh, chúng ta còn có những dòng **comment**

```cpp
// This comment is located outside main function

/* We can put comment everywhere in a C++ file */

int main() {
  // We are coding inside main function
  cout << "This is a command" << endl;
  return 0;
}
```

Và cuối cùng là những thư viện cần thiết để compiler có thể hiểu được những lệnh đã được định nghĩa sẵn trong ngôn ngữ lập trình C++

```cpp
#include <iostream>
#include <cmath>
#include <string>
using namespace std;
// This comment is located outside main function
/* We can put comment everywhere in a C++ file */
int main()
{
  // We are coding inside main function
  cout << "This is a command" << endl;
  return 0;
}
```

Các bạn lưu ý là không nên include cả đống thư viện chưa cần dùng đến nhé. Cần dùng lệnh gì đã được định nghĩa sẵn mới cần include vào. Tất nhiên khi thêm nhiều thư viện vào chương trình thì IDE sẽ không báo lỗi, nhưng chương trình của chúng ta sau khi build ra sẽ nặng hơn. Nếu các bạn sử dụng những lệnh được định nghĩa trong thư viện mà không include nó vào thì IDE sẽ báo lỗi ngay.
Ví dụ mình bỏ dòng `#include <iostream>` đi, IDE sẽ báo lỗi như hình bên dưới:

![1-1-6](https://github.com/daynhauhoc/cppcoban/assets/88678933/1efd366d-fce5-4d41-b7a9-790096e458ad)

Như các bạn thấy, cả lệnh **cout**, **system("")**, và **endl** đều được định nghĩa bên trong thư viện **iostream** nên khi xóa thư viện đó đi, chương trình gạch chân màu đỏ các từ đó, đồng thời thông báo lỗi trong cửa sổ **Output**.

### Tổng kết

Trong bài học hôm nay, chúng ta đã biết thêm một số điểm đáng chú ý khi làm việc với chương trình C++:

- Một dòng comment sẽ đứng sau 2 dấu gạch chéo //.

- Một đoạn comment sẽ nằm giữa cặp /_ và _/.

- Một dòng lệnh phải được kết thúc bằng dấu chấm phẩy **";"**

- Cấu trúc của một chương trình C++ cơ bản:

  - Hàm main: (bắt buộc phải có)

    - Kiểu trả về của hàm main (int).
    - Tên của hàm main (cũng là main luôn).
    - Thân của hàm main (cặp dấu ngoặc nhọn { và }).
    - Giá trị trả về của hàm main (return 0; //hoặc giá trị bao nhiêu cũng đc).

  - Những dòng lệnh bên trong thân hàm main. (Có thể có hoặc không)

  - Những dòng comment. (Có thể có hoặc không)

  - Tích hợp thư viện và không gian tên. (Phụ thuộc vào các lệnh mà bạn sử dụng).

### Bài tập cơ bản

1. Trong chương trình C++ HelloWorld đầu tiên, ở dòng 1 là đoạn comment chứa thông tin về tên Project và tên người viết chương trình. Các bạn đã viết cùng mình mà hình như vẫn chưa có tên của các bạn đấy. Sửa lại comment đó đi nào! :D

2. Thay vì in ra dòng chữ Hello World, thay vì in ra dòng **Hello World**, hãy thử in ra cái gì đó thú vị hơn xem nào! (Tên của bạn thì sao?)

3. Hãy comment theo cách của bạn! :D
