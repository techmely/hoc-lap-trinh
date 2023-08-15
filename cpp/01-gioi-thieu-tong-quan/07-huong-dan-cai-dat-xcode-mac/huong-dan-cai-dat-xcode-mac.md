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
  name: "Giới thiệu tổng quan về khóa học C++"
  slug: "chuong-01-gioi-thieu-tong-quan-ve-khoa-hoc"
category:
  name: "Khóa học C++ cơ bản"
  slug: "C++"
image: https://kungfutech.edu.vn/thumbnail.png
position: 7
---

Ở bài viết này, mình sẽ hướng dẫn các bạn thiết lập môi trường để lập trình
C/C++ trên hệ điều hành **Mac OS X**.

## Chúng ta phải làm gì đầu tiên?

- Chúng ta học lập trình, học code (mã lệnh) thì phải có thứ gì đó để biến
  những dòng code của chúng ta thành một chương trình để chạy. Để làm được
  điều
  này ta có một chương trình được gọi là **Compiler**.
- **Compiler** hiểu đơn giản là chương trình dịch những dòng code của ta
  thành
  mã máy (bit) để máy tính hiểu được và thực thi.
- Để dịch được code C/C++ trên **Mac OS X**, ta có thể cài phần mềm **Xcode**
  hoặc sử dụng **Terminal**.

## Giới thiệu và hướng dẫn cài đặt Xcode

### 1. Giới thiệu Xcode

**Xcode** là một Integrated Development Environment (viết tắt là **IDE**) tức
là một môi trường tích hợp bao gồm nhiều công cụ khác nhau như chương trình
viết mã lệnh hay code editor, chương trình sửa lỗi hay debugger, chương trình
mô phỏng ứng dụng khi chạy thực tế hay simulator... do hãng **Apple** cung cấp
cho những nhà phát triển lập trình trên hệ điều hành **Mac OS X**.

### 2. Cài đặt

Đầu tiên ta sẽ download **Xcode** từ trên **App Store**. Nếu bạn chưa tìm
được App Store ở đâu thì đây sẽ là một vài chỉ dẫn cho bạn.
Ở góc trên bên trái màn hình, nhấn vào biểu tượng **Apple -> System
Preferences...**

<img width="254" alt="xcode-001" src="https://github.com/daynhauhoc/cppcoban/assets/88678933/1d37b490-07bf-42ff-b72e-8952d27e1669">

Chọn biểu tượng **Keyboard**

<img width="218" alt="xcode-002" src="https://github.com/daynhauhoc/cppcoban/assets/88678933/66f0e0e4-eea5-4be4-a5ea-870508d55a1c">

Ở đây, chọn Tab **Shortcuts** ở phía trên và chọn mục **Spotlight** bên trái.

<img width="635" alt="xcode-003" src="https://github.com/daynhauhoc/cppcoban/assets/88678933/a85fec3e-c16a-4d3d-a575-0fe995960bed">

Dòng **Show Spotlight Search** có chỉ dẫn mặc định là nhấn tổ hợp
<kbd>Cmd</kbd> + <kbd>Space</kbd> để mở **Spotlight**, nếu ở máy bạn khác
với mình thì
hãy bấm theo chỉ dẫn ở máy bạn hoặc nháy vào và đổi tổ hợp phím khác. **Đừng
quên tích vào ô vuông bên cạnh dòng chữ!**

**Spotlight** là một tiện ích mà hệ điều hành **Mac OS X** cung cấp giúp tìm
nhanh các file, folder, ảnh, ... có trong máy tính của bạn! Hãy tận dụng
Spotlight thường xuyên để thao tác tìm kiếm nhanh hơn trên máy của bạn từ bây
giờ!
Bây giờ hãy **search** trên Spotlight phần mềm **App Store**.

<img width="707" alt="xcode-004" src="https://github.com/daynhauhoc/cppcoban/assets/88678933/9861fa7a-ad2c-4198-adac-3f2eb5a191ca">

Ở góc trên bên phải có khung tìm kiếm, hãy nhập **"Xcode"** và nhấn <kbd>Enter
</kbd>.

<img width="231" alt="xcode-005" src="https://github.com/daynhauhoc/cppcoban/assets/88678933/df37c126-0e8d-4d4c-9a29-5653e2ffcd96">

Chọn vào phần mềm **Xcode** có biểu tượng như dưới

<img width="284" alt="xcode-006" src="https://github.com/daynhauhoc/cppcoban/assets/88678933/46655816-4819-46f2-864c-f7fa603ca918">

Nhấn vào <kbd>Install</kbd> (hay <kbd>Download</kbd>). Ở máy mình do đã cài
nên hiện chữ
Update.

<img width="230" alt="xcode-007" src="https://github.com/daynhauhoc/cppcoban/assets/88678933/dbeb1ed0-7405-4213-bc12-24e4270710e7">

Rồi, bây giờ chỉ đơn giản là chờ thôi. Nếu muốn xem tiến trình download có thể
vào **Launchpad** (search trên Spotlight ngay nếu bạn không tìm được)

<img width="1280" alt="xcode-008" src="https://github.com/daynhauhoc/cppcoban/assets/88678933/c530cde4-680d-4afc-9376-7eed799c2c3f">

**Launchpad** là nơi chứa danh sách **shortcut các ứng dụng** có trên máy bạn,
giúp bạn mở nhanh hơn!
Yay, vậy là chúng ta đã cài đặt xong **Xcode**. Giờ hãy mở lên và code ngay
một chương trình C++ đầu tiên nào.
Đây là giao diện khi bắt đầu mở **Xcode**. Hãy chọn **Create a new Xcode
project**.

<img width="804" alt="xcode-009" src="https://github.com/daynhauhoc/cppcoban/assets/88678933/d11362c0-d76b-4d0c-ae4f-f6b705a5f8e3">

Chọn mục **Appliance** dưới dòng OS X, rồi chọn **Command Line Tool** và <kbd>
Next</kbd>.

<img width="734" alt="xcode-010" src="https://github.com/daynhauhoc/cppcoban/assets/88678933/f762aeae-7ccd-44b5-8c04-4c3d32ce70c6">

**Đặt tên** cho Project. Ví dụ của mình là "Hello-World". Nhớ ở mục
**Language** chọn **C++**. Nhấn <kbd>Enter</kbd> (hay <kbd>Next</kbd>).

<img width="730" alt="xcode-011" src="https://github.com/daynhauhoc/cppcoban/assets/88678933/af4d6349-8f90-40cd-b1dd-53a405d8c5bf">

Chọn thư mục nơi bạn muốn lưu trữ project. Nhấn <kbd>Create</kbd>!

<img width="713" alt="xcode-012" src="https://github.com/daynhauhoc/cppcoban/assets/88678933/bdaa5bca-3790-4869-afad-eb721c26a352">

Tada, vậy là ta **đã tạo được một project lập trình C++**. Apple rất tốt bụng
khi đã viết cho chúng ta một chương trình chạy được ngay trong file
**main.cpp** sau khi **Create Project**. Bấm nút **Run** (nút hình tam giác
góc trên bên trái) để chạy chương trình.

<img width="823" alt="xcode-013" src="https://github.com/daynhauhoc/cppcoban/assets/88678933/f403aeae-d0f0-4f0f-994b-4ef48e6f8fc7">

Ở phía dưới là kết quả chúng ta chạy ra, in ra dòng chữ **"Hello, World!"**.
Nếu máy bạn không hiện thấy hãy bấm **Tab thứ 2** ở góc trên từ phải sang để
mở khung kết quả chay.

<img width="1023" alt="xcode-014" src="https://github.com/daynhauhoc/cppcoban/assets/88678933/53faa30a-2616-4db4-8048-7f3b77adbb37">

Vậy là chúng ta đã biết cách **cài đặt và tạo Project C++ trên Mac OS X bằng
Xcode**. Trong những bài hướng dẫn tiếp theo, nếu bạn quên cách tạo một
project, **đừng ngại quay lại bài viết này để xem cách hướng dẫn!**

## Giới thiệu và sử dụng Terminal

### 1. Giới thiệu

Xcode thì trông rất đẹp, tốt và chuyên nghiệp. Nhưng nếu bạn là người thích sự
đơn giản, hiệu quả và làm việc gọn lẹ **be like hacker** thì không thể không
thử dùng **Terminal**!
**Terminal** là chương trình **điều khiển bằng mã lệnh** và ta có thể làm rất
nhiều điều thú vị, hay ho thông qua nó. Nhưng trong phạm vi bài viết, mình sẽ
chỉ hướng dẫn cách **compile** và **chạy** một chương trình viết bằng C++.
Rất may, trong hệ điều hành **Mac OS X** đã có
**bộ biên dịch mã C++ (GNU, GCC)** nên ta chỉ cần một file có code C++ và thực
hiện vài lệnh trên **Terminal** để chạy.

### 2. Sử dụng

Tạo một file code có phần đuôi mở rộng là **.cpp**. Ta có thể sử dụng bất cứ
một **TextEditor** nào để viết. Ví dụ như **TextWrangler**, có kèm cả
**highlight syntax** (làm "màu" các từ khoá của các ngôn ngữ lập trình).
**Hãy thử tìm trên Google và download!**
Tạo một file **Hello.cpp** như dưới:

```cpp
#include <iostream>

int main()
{
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
```

**Save** lại vào một nơi bất kì và mở **Terminal** lên (dùng Spotlight nếu bạn
không tìm được, nhớ chứ!)
Hãy dẫn **Terminal** tới **folder chứa file Hello.cpp** bằng cú pháp

`cd "đường dẫn"` (cd là change directory)
ví dụ ở đây là: `cd Working/"[DNH] Dạy C++"/`

Tiếp là cú pháp

`g++ -o {tên chương trình} {tên file cần compile}`
vd ở đây là: `g++ -o hello hello.cpp`

Lệnh này **compile file hello.cpp** để **tạo một chương trình tên hello**

Sau đó, để chạy chương trình ta dùng cú pháp: `./{tên chương trình}`

ví dụ ở đây là: `./hello`

<img width="561" alt="xcode-015" src="https://github.com/daynhauhoc/cppcoban/assets/88678933/2a35a2de-fe5c-4996-8da9-ee1aeaeb5e00">

**Vậy là chương trình của ta đã chạy thành công!**
Nếu bạn không chạy được như mình, **đừng quá lo lắng,** **Terminal** hầu hết
đều khó khăn với những người mới bắt đầu nhưng nếu làm được thì hãy tự thưởng
cho mình vì bạn đã làm **rất tốt!** Hãy thử tìm trên Google và tìm hiểu thêm
về Terminal nếu bạn thích. Bạn có thể không cần làm được ngay bây giờ và quay
lại thử sức khi khác, **nhưng đừng quên rằng sớm hay muộn rồi bạn cũng sẽ gặp
lại nó vào một ngày đẹp giời nào đó.**

Vậy là ta đã hoàn thành việc thiết lập môi trường, ở những bài sau các bạn sẽ
được học cách code và viết những chương trình đầu tiên, cảm ơn các bạn.
