---
title: "Hướng dẫn cài đặt VSCode2015"
description: "Chào mừng đến với loạt bài hướng dẫn sử dụng ngôn ngữ lập trình C++! Loạt bài hướng dẫn này được thiết kế cho những người chưa hoặc biết một ít lập trình."
chapter:
  name: "Giới thiệu tổng quan về khóa học C++"
  slug: "chuong-01-gioi-thieu-tong-quan-ve-khoa-hoc"
image: https://kungfutech.edu.vn/thumbnail.png
position: 5
---

Trong chủ đề này, chúng ta sẽ cùng nhau cài đặt IDE Visual studio 2015
để phục vụ việc học tập sao cho thực sự hiệu quả.

## Giới thiệu sơ lược về Visual Studio

Đầu tiên, chúng ta sẽ
[ghé thăm trang chủ của Visual Studio do ông trùm Microsoft nắm quyền](https://www.visualstudio.com/en-us/downloads/download-visual-studio-vs.aspx).

> Thông tin thêm Xamarin đã được microsoft mua lại và phát hành miễn phí
> cho người dùng. Hiện tại thì với Vs có thể phát triển được nhiều nền tảng
> (Android, iOS và Windowns Phone)

Tại đây có nhiều sự lựa chọn cho bạn :

- Visual Studio Community 2015.
  Bản này là bản miễn phí với các tính năng cơ bản như sau :

  > "A rich, integrated development environment for creating
  > stunning applications for Windows, Android, and iOS, as well as modern
  > web applications and cloud services"

- Visual Studio Enterprise 2015 :
  Bản này chúng ta được phép dùng thử và khi hết thời hạn dùng thử
  thì tất nhiên bạn sẽ phải trả tiền để tiếp tục sử dụng nó.
  Bản này có các tính năng được giới thiệu như sau :

  > "Enterprise-grade solution with advanced capabilities for teams
  > working on projects of any size or complexity, including
  > advanced testing and DevOps."

- Visual Studio Code :

  Bản này tiếp tục là một bản miễn phí nữa của Microsoft.

  > "Code editing redefined. Build and debug modern web and
  > cloud applications. Code is free and available on
  > your favorite platform — Windows, Mac OS X, or Linux."

  Với bản này chúng ta có thể cài đặt trên nền tảng Mac, Linux.

## Lựa chọn phiên bản cài đặt

Mình khuyên mọi người nên cài đặt bản Visual studio Community 2015. Vì các lí do
sau đây:

- Hỗ trợ đầy đủ tính năng cho chúng ta trong việc học lập trình.
- Miễn phí với mọi người. Sẽ không còn phải lo lắng về vấn đề bản quyền.

Nếu bạn muốn trải nghiệm với Visual Studio Enterprise 2015 thì sẽ phải bỏ ra
một khoản chi phí để mua bản quyền nhé.

# Tải bản cài đặt của Visual studio Community 2015

Trước khi cài đặt bạn cần lưu ý với phiên bản VS Community 2015
nên có Microsoft .NET Framework 4.6.1.

Nên update Framework trước khi cài đặt. Để tránh xảy ra lỗi đáng tiếc.

[Bấm vào đây để để thực tải bản update cho .NET Framework](https://www.microsoft.com/en-us/download/details.aspx?id=48130)

// Tải phiên bản cài đặt
Link tải phiên bản cài đặt Visual studio Community 2015 (206,63 Kb)

Sau khi tải xong, Chúng ta mở thư mục chứa file cài đặt có tên
`vs_community_ENU.exe`

Thực hiện các thao tác cài đặt như thường lệ :D
(Hình 0.5.2)

Sau đó sẽ hiện một cửa sổ thông báo nơi cài đặt và kiểu cài đặt

Kiểu cài đặt có 2 kiểu:

- Default: sẽ cài C#/Vb và tính năng với desktop
- Custom: người dùng sẽ tùy chọn tính năng muốn cài đặt (Hình 0.5.3)

Khuyên nên chọn kiểu Custom và tick các tùy chọn theo nhu cầu sử dụng

Khi đã chọn xong thì chúng ta nhấp **Next** và chờ đợi...

Sau khi công việc cài đặt đã hoàn tất.
Chúng ra reset máy để xem thành quả như thế nào

Đầu tiên, Visual Studio yêu cầu đăng nhập với tài khoản Microsoft
hoặc không đăng nhập.

Việc đăng nhập có lợi thế là sẽ đồng bộ hóa lại những cài đặt trên Visual Studio

Tiếp theo là việc lựa chọn theme (Hình 0.5.6)

Việc khởi động cho lần đầu tiên sử dụng sẽ mất chút thời gian tùy theo
việc cài đặt ở phần Custom

(Hinh 0.5.7)

## Hướng dẫn tạo project trong Visual Studio 2015

- Trong giao diện của VS chọn File -> New -> Project
  (Phím tắt Ctrl + Shift + N) (Hình.5.8)

- Sẽ có một cửa sổ New Project xuất hiện (Hình 0.5.9)

- Tìm tới phần Visual C++ -> Chọn General -> Empty Project.
- Bên dưới là phần đặt tên của project và nơi lưu project.
- **Name** thì các bạn có thể đặt có dấu

- **Location** thì khuyên là nên tạo riêng từng mục một
  và đặt ở phần ổ cứng khác với ổ C (với các bạn sử dụng Window)
  để tránh việc mất các project quan trọng đã là đã làm

- **Solution name**: Không nên đặt tên có dấu hoặc kí tự như dấu cách
  Khi file được chuyển sang các máy khác có thể không hoạt động

Đây là hình ảnh sau khi bạn đã tạo một project mới (Hình 0.5.10)

Có 2 phần các bạn cần để ý là phần :

- **Solution Explorer**:
  Tại đây có chứa các mục quan trọng các bạn cần để ý
  Header File / Source File

  Nếu sau khi tạo xong project mà phần Solution Explorer
  chưa xuất hiện các bạn có thể click vào
  View -> Solution Explorer (Ctr+Alt+L)

- **Error List**:
  Tại đây có chứa các lỗi cú pháp gặp phải khi chạy chương trình.
  Mở Error List : Click View -> Error List

## Tạo file CPP để thực hiện chương trình

- Click chuột phải vào Source File -> Add -> New Item
  (Ctr+Shift+A) (Hình 0.5.11)

- Một cửa sổ mới sẽ được tạo (Hình 0.5.12)

- Chọn C++ File(.cpp) Chưa cần để ý tới phần Header File(.h) vội nha !
  Đặt tên cho File mới (.cpp)

Như vậy là đã xong phần cài đặt Visual Stuido 2015 và Hướng dẫn tạo project mới.
Hẹn Gặp lại các bạn vào buổi tới với nhiều điều thú vị hơn nữa nhé.
