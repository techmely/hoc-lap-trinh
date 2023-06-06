---
title: "Cài đặt và sử dụng thư viện"
description: ""
keywords:
  [
    "gioi thieu react native",
    "giới thiệu react native",
    "khoá học react native",
    "giới thiệu react native",
    "giới thiệu react native cơ bản",
    "react native la gi",
    "tong quan ve react native",
    "gioi thieu ve ngon ngu lap trinh react native",
    "tom tat react native",
    "code react native la gi",
  ]
chapter:
  name: "Tương tác trong react native"
  slug: "chuong-05-tuong-tac-trong-react-native"
category:
  name: "React Native"
  slug: "react-native"
image: https://kungfutech.edu.vn/thumbnail.png
position: 2
---

## Cài đặt thư viện

Thông thường trong React-Native sử dụng thư viện rất nhiều có lẽ vì một vài lý do:

- Code từ đầu thì lâu hơn.
- Thư viện được nhiều người xây dựng nên khả năng tốt hơn so với việc mình code một mình.
- Có cộng đồng hỗ trợ nên có lỗi thì cũng dễ dàng sửa lỗi.
- Những thư viện liên quan đến SDK của các nhà phát triển như Facebook, Google, Firebase... đều được cộng đồng phát triển để hỗ trợ việc bạn xây dựng ứng dụng tốt nhất.
- Và nhiều lý do khác nữa.

Khi bạn gặp vấn đề hoặc cần làm một cái gì đó với react-native hãy tìm Google với từ khóa react-native + cái gì bạn muốn làm.
Ví dụ muốn làm chức năng đăng nhập với facebook thì có thể tìm: react-native login with facebook. Đa phần bạn sẽ thấy thư viện hỗ trợ nằm ngay trang đầu tiên. Hãy vào trang chính thống của thư viện để xem cách cài đặt và sử dụng thư viện. Nhớ xem lại số star và các vấn đề trước khi bạn muốn sử một thư viện nào đó trên github.
Nếu thư viện được publish trên [npmjs](https://www.npmjs.com) thì bạn có thể cài đặt thông qua

`npm install package_name`

## Link thư viện

Một phần khá quan trọng, sau khi bạn kéo thư viện từ npm về, thì bạn cần link thư viện đó vào app của bạn để ứng dụng có thể khởi chạy các phần code native của thư viện hoặc được quyền chạy một số tác vụ khác.
Thông thường các thư viện đều có link tự động qua lệnh `react-native link`. Tùy vào từng thư viện sẽ có hướng dẫn và cách link bổ sung. Bên cạnh đó một số thư viện không link tự động được hoặc project của bạn có vấn đề phải link bằng tay lúc đó bạn nên tham khảo bài viết này trước để biết cách link và hiểu sâu hơn [https://facebook.github.io/react-native/docs/linking-libraries-ios](https://facebook.github.io/react-native/docs/linking-libraries-ios)

## Chỉnh sửa thư viện

Đa phần trình quản lý source code (git/svn) sẽ không commit các thư viện có sẵn được cài đặt từ npm (thư mục _node_modules_) hoặc nếu mình cố gắng commit sẽ làm dự án của chúng ta nặng lên rất nhiều lần. Do vậy chúng ta không sửa trực tiếp thư viện trong _node_modules_. Sau khi cài đặt và link thư viện. Bạn hãy copy nguyên source code của thư viện qua app/modules và tiến hành sửa đổi, tùy biến thư viện tại đây. Lúc sử dụng nhớ chuyển đổi đường dẫn import thư viện qua dự án của bạn. Nếu đó là phần chỉnh sửa quan trong hy vọng bạn sẽ đóng góp cho cộng đồng bằng cách report lên dự án chính hoặc chia sẻ lại cho mọi người.
