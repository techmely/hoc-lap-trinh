---
title: "Phạm vi của biến trong c++"
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
position: 8
---

Chào các bạn! Chúng ta cùng tiếp tục với bài học tiếp theo trong khóa học lập trình trực tuyến ngôn ngữ C++ hướng thực hành.

Trong các bài học trước, chúng ta đã cùng nhau tìm hiểu cách sử dụng biến (**variable**) gồm có cách khai báo, khởi tạo, nhập giá trị từ bàn phím và đưa vào biến, tính toán giá trị của biến và đưa giá trị của biến lên màn hình...

> Khi một biến được khai báo, hệ điều hành sẽ cấp phát cho chương trình một vùng nhớ có độ lớn tương ứng với độ lớn kiểu dữ liệu của biến.

![1-7-0](https://github.com/daynhauhoc/cppcoban/assets/88678933/4dc5d257-18a7-406d-9717-4a1af5e3ee4a)

Vấn đề là không phải chỉ có một mình chương trình mà các bạn đang viết sử dụng các vùng nhớ trên RAM, mà còn nhiều chương trình khác đang chạy ngầm nữa.

![1-7-1](https://github.com/daynhauhoc/cppcoban/assets/88678933/9f64bfc5-cc67-4571-a74f-2f5ce10887dd)

Trong khi đó, bộ nhớ RAM của chúng ta chỉ có giới hạn. Vì thế, một khi biến (**variable**) không còn giá trị sử dụng nữa, chúng phải được tiêu hủy để trả lại vùng nhớ mà nó đang giữ, để cấp phát cho những ứng dụng khác cần sử dụng bộ nhớ.

Khi bạn kiểm soát được việc lúc nào cần khai báo biến, khi nào cần tiêu hủy biến sẽ giúp bạn quản lý tài nguyên máy tính tốt hơn. Điều này cần kĩ năng tổ chức và thiết kế chương trình, một kĩ năng quan trọng cần có thời gian để rèn luyện.

Trong bài học này, chúng ta sẽ tìm hiểu hai khái niệm luôn luôn gắn liền với biến (**variable**):

- Phạm vi của biến.
- Thời gian tồn tại của biến.

_Hai khái niệm này thường có liên kết chặt chẽ với nhau._

## Phạm vi của biến

Phạm vi của biến xác định nơi chúng ta có thể truy cập vào biến.

- Biến được khai báo bên trong **khối lệnh** (block) được gọi là **biến cục bộ** (local variable).

Chương trình bên dưới minh họa cho việc khai báo biến cục bộ, truy cập và truy xuất giá trị của biến cục bộ.

![1-7-2](https://github.com/daynhauhoc/cppcoban/assets/88678933/cc641e45-dd8a-4b76-baa8-739535f8f144)

Biến **local variable** được khai báo bên trong khối lệnh của hàm **main**, nên các câu lệnh truy xuất đến biến **local variable** hoàn toàn hợp lệ.

Một khối lệnh có thể chứa nhiều khối lệnh con khác nhau. Ví dụ:

![1-7-3](https://github.com/daynhauhoc/cppcoban/assets/88678933/c79bfd37-3163-4787-86ff-7ef686ad0d37)

Trong đoạn chương trình trên, chúng ta có thêm một khối lệnh nằm bên trong khối lệnh của hàm **main**, và xuất hiện một biến có tên **local variable 2** được khai báo bên trong nó. Ở trong khối lệnh con này (khối lệnh nằm trong khổi lệnh của hàm **main**) chúng ta có thể truy xuất giá trị của biến **local variable 2** như mình đã làm thông qua dòng lệnh

```cpp
cout << "local_variable2: " << local_variable2 << endl;
```

để in giá trị của biến **local variable 2** lên màn hình. Ngoài ra, mình còn sử dụng phép gán (với toán tử "**=**") để sửa đổi giá trị cho biến **local variable 1** vốn được định nghĩa bên ngoài khối lệnh con.

_Điều này có nghĩa là chúng ta có thể truy cập đến một biến đã được khai báo trong những khối lệnh con bên dưới biến đó nếu những khối lệnh con này cũng được đặt trong khối lệnh chứa biến được khai báo._

Khi các bạn sử dụng các khối lệnh con, bạn có thể đặt tên biến trùng với biến được khai báo trong khối lệnh bên ngoài mà nó chứa khối lệnh con đó. Các bạn nhìn vào chương trình bên dưới để thấy rõ hơn:

![1-7-4](https://github.com/daynhauhoc/cppcoban/assets/88678933/5d5fb367-4c95-4700-bf6d-650ed62fb3a4)

Chương trình trên không hề vi phạm quy tắc đặt tên biến mà mình đã nói ở những bài trước.

> Trong cùng một khối lệnh không được phép có hai biến trùng tên.

Trong chương trình trên, hai biến **number of employees** hoàn toàn được khai báo trong hai khối lệnh khác nhau. Bây giờ chúng ta chạy thử chương trình xem kết quả in ra trên màn hình như thế nào.

![1-7-5](https://github.com/daynhauhoc/cppcoban/assets/88678933/376858dc-8e80-409d-a70b-5685ae9e96c5)

Như các bạn cũng đã thấy, khi mình thực hiện truy xuất giá trị của biến **number of employees** bên trong khối lệnh con thì chỉ lấy được giá trị của biến được khai báo bên trong khối lệnh con đó. Tương tự, khi mình thực hiện truy xuất giá trị của biến **number of employees** của khối lệnh sau hàm **main** thì chỉ lấy được giá trị của biến được khai báo trong khối lệnh sau hàm **main**.

_Việc đặt tên biến trùng nhau trong nhiều khối lệnh lồng nhau được compiler của Visual studio cho phép, nhưng mình khuyên các bạn nên nghĩ ra một tên biến khác phù hợp hơn để tránh việc nhầm lẫn khi thiết kế một chương trình có quy mô lớn._

- Biến được khai báo bên ngoài **khối lệnh** được gọi là **biến toàn cục** (global variable).

Các bạn cùng nhìn vào đoạn chương trình mẫu bên dưới để xem cách mình khai báo một biến toàn cục như thế nào.

![1-7-6](https://github.com/daynhauhoc/cppcoban/assets/88678933/b7a5efd1-c6cd-4f9f-aee8-59a27f14df7e)

Như các bạn thấy, mình không đặt dòng khai báo biến bên trong khối lệnh của hàm **main** nữa mà mình đặt nó bên ngoài và nằm trên khối lệnh của hàm **main**.

_Trong bài học đầu tiên, mình có nói về việc khối lệnh của hàm main sẽ là nơi mà chương trình bắt đầu thực thi, ngoại trừ một số câu lệnh đặc biệt có thể đặt ngoài khối lệnh (khai báo biến, include thư viện, gọi namespace, định nghĩa các class, ...)._

Khi có một biến khác nằm trong phạm vi của khối lệnh hàm main được khai báo cùng tên với biến toàn cục bên ngoài khối lệnh hàm main, mỗi câu lệnh truy xuất đến biến đó đều được ưu tiên tìm đến biến cục bộ bên trong hàm main trước. **Vậy có cách nào để ta truy xuất được biến toàn cục bên ngoài hàm main không?**

Câu trả lời là có! Chúng ta sử dụng toán tử phạm vi (**::**) như sau:

```cpp
#include <iostream>
using namespace std;
int value = 1;
int main()	{
  int value = 10;
  cout << "local value: " << value << endl;
  cout << "global value: " << ::value << endl;
  system("pause");
  return 0;
}
```

_Các bạn thử chạy đoạn code trên xem chương trình thông báo kết quả như thế nào nhé._

Một khi biến toàn cục đã được khai báo, chúng có thể được truy cập tại mọi khối lệnh nằm bên dưới nó. Trong khi đó, biến cục bộ chỉ được phép truy cập khi dòng lệnh còn đặt bên trong khối lệnh chứa nó. Ví dụ:

![1-7-7](https://github.com/daynhauhoc/cppcoban/assets/88678933/8a5e7345-fad8-4789-ab49-2aa795307d5c)

Chương trình báo lỗi biến **local_variable** không được khai báo trước đó trong khi mình đã khai báo bên trong khối lệnh con của khối lệnh hàm **main**.

Nguyên nhân là do biến **local_variable** đã bị tiêu hủy trước khi mình kịp truy xuất đến nó.

## Thời gian tồn tại của biến

Đối với những biến cục bộ (local variable) có kiểu dữ liệu thông thường như các bạn đã học trong những bài trước, vùng nhớ của biến sẽ tự động giải phóng khi ra khỏi khối lệnh chứa nó.

![1-7-8](https://github.com/daynhauhoc/cppcoban/assets/88678933/6a28753c-badb-49bb-b256-bfc683842869)

Việc cố gắng truy cập đến một biến đã bị hủy sẽ gây nên lỗi. Thời gian tồn tại của biến cục bộ phụ thuộc vào của khối lệnh chứa nó.

Đối với biến toàn cục (được khai báo bên ngoài khối lệnh của hàm **main**), nó sẽ tồn tại cho đến khi chương trình kết thúc hoặc bị kết thúc bởi người dùng.

Vì thế, các bạn chỉ nên sử dụng biến toàn cục khi cần thiết, để tránh việc vùng nhớ của biến toàn cục được cấp phát nhưng bị chiếm giữ quá lâu gây ảnh hưởng đến việc cấp phát bộ nhớ cho những chương trình khác.

### Tổng kết

- Biến cục bộ được khai báo bên trong khối lệnh. Những biến này chỉ được phép truy cập ở bên trong khối lệnh đó. Biến cục bộ sẽ bị hủy tại thời điểm kết thúc khối lệnh.

- Biến toàn cục được khai báo bên ngoài khối lệnh. Những biến này được phép truy cập trong mọi khối lệnh nằm bên dưới nó. Biến toàn cục chỉ bị hủy khi chương trình kết thúc.
