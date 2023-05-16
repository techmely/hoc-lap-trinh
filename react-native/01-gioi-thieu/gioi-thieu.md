---
title: "Hướng dẫn học React-Native cho người mới bắt đầu"
description: "Chào mừng các bạn đến với hướng dẫn học React-Native cho người mới bắt. Sau đây là một số chia sẻ, hướng dẫn của mình cho người mới bắt đầu tìm hiểu về React-Native. Qua đó nhằm giúp các bạn có cách nhìn tổng quát hơn và dễ dàng tìm hiểu vấn đề khi mới chập chững bước chân vào lập trình với React-Native."
keywords:
  [
    "gioi thieu react native",
    "giới thiệu react native",
    "khoá học react native",
    "giới thiệu react native",
    "giới thiệu jreact native cơ bản",
    "react native la gi",
    "tong quan ve react native",
    "gioi thieu ve ngon ngu lap trinh react native",
    "tom tat react native",
    "code react native la gi",
  ]
chapter:
  name: "Giới thiệu khoá học React Native"
  slug: "chuong-01-gioi-thieu-khoa-hoc-react-native"
category:
  name: "React Native"
  slug: "react-native"
image: https://kungfutech.edu.vn/thumbnail.png
position: 1
---

Chào mừng các bạn đến với hướng dẫn học React-Native cho người mới bắt. Sau đây là một số chia sẻ, hướng dẫn của mình cho người mới bắt đầu tìm hiểu về React-Native. Qua đó nhằm giúp các bạn có cách nhìn tổng quát hơn và dễ dàng tìm hiểu vấn đề khi mới chập chững bước chân vào lập trình với React-Native.

## Mục tiêu hướng dẫn

- Hiểu được các thành phần cơ bản của React-Native.
- Nắm vững được vòng đời của một màn hình, component của React-Native.
- Tùy biến các component theo ý muốn.
- Tìm kiếm, sử dụng và tùy biến thư viện.
- Xây dựng 1 ứng dụng đọc báo như báo mới.

## Một vài lưu ý

- Bài viết nhắm tới các bạn đã có cơ bản về javascript nhất là quen với ES6. Nếu bạn chưa biết về javascript vui lòng tìm hiểu javascript cơ bản ít nhất bạn cần nắm vững những kiến thức sau:

  - Biến và toán tử trong javascript
  - Lệnh If...else
  - Lệnh Switch..case
  - Vòng lặp white
  - Vòng lặp for
  - Vòng lặp for...in
  - Viết hàm thực thi các tác vụ cơ bản
  - Mảng: (duyệt mảng lấy các phần tử)

- Nếu biết về css thì đó cũng là một điểm lợi thế. Bạn có thể tìm hiểu thêm tại đây <https://freetuts.net/css-la-gi-hoc-css-nhu-the-nao-327.html>
- Hiện tại hệ điều hành Windows chỉ build được ứng dụng Android.
- Hệ điều hành IOS có thể build được cả Android và IOS.
- Phiên bản IOS thấp nhất mà react-native có thể hỗ trợ là IOS 8.0
- Phiên bản Android thấp nhất mà react-native có thể hỗ trợ là Android 4.1 (API 16)
- Các hướng dẫn dưới đây ngoại trừ phần cài đặt, đều là hướng dẫn để xây dựng ứng dụng trên IOS. Một số chức năng có thể IOS hỗ trợ nhưng Android không hỗ trợ và ngược lại, nên nếu có lỗi các bạn có thể bình luận tại đây hoặc tìm kiếm google để nâng cao khả năng giải quyết vấn đề nhé.
- Để chạy các code mẫu, sau khi tải về vui lòng vào thư mục và chạy dòng lệnh `npm install` để tải toàn bộ thư viện cần sử dụng. Và chạy `react-native run-ios` để chạy ứng dụng trên IOS. `react-native run-android` để chạy ứng dụng trên hệ điều hành Android.

**Khuyến nghị**: Sau những lần tìm hiểu và phát triển ứng dụng thì mình khuyến cáo không nên sử dụng Expo (framework của react) để phát triển ứng dụng đơn giản. Bởi vì dự án của bạn sẽ nặng lên, bạn rất khó quản lý permission và các thư viện đi kèm.
