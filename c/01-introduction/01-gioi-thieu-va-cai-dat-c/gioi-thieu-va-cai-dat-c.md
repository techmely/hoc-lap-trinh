---
title: "Giới thiệu và cài đặt C"
description: "Chào mừng bạn đến với hướng dẫn giới thiệu và cài đặt C! Trong bài viết này, chúng mình sẽ khám phá ngôn ngữ lập trình C và cung cấp hướng dẫn cài đặt môi trường phát triển C, một ngôn ngữ cơ bản dễ hiểu và dễ dùng, rất thích hợp cho các bạn bắt đầu học lập trình. Cùng tìm hiểu về sức mạnh và tính di động của ngôn ngữ C và cách bắt đầu hành trình lập trình của bạn."
chapter:
  name: "Giới thiệu"
  slug: "chuong-01-introduction"
category:
  name: "C"
  slug: "c"
image: https://user-images.githubusercontent.com/29374426/127596066-fa46df01-982f-4a72-b6d1-f7d8f5c5a9b3.png
position: 1
---

## Giới thiệu về ngôn ngữ C

Ngôn ngữ lập trình C là một ngôn ngữ mệnh lệnh được phát triển từ đầu thập niên 1970 bởi Dennis Ritchie để dùng trong hệ điều hành UNIX. Từ đó, ngôn ngữ này đã lan rộng ra nhiều hệ điều hành khác và trở thành một những ngôn ngữ phổ dụng nhất. C là ngôn ngữ rất có hiệu quả và được ưa chuộng nhất để viết các phần mềm hệ thống, mặc dù nó cũng được dùng cho việc viết các ứng dụng. Ngoài ra, C cũng thường được dùng làm phương tiện giảng dạy trong khoa học máy tính.

C là một ngôn ngữ lập trình tương đối nhỏ gọn vận hành gần với phần cứng và nó giống với ngôn ngữ Assembler hơn hầu hết các ngôn ngữ bậc cao. Hơn thế, C đôi khi được đánh giá như là "có khả năng di động", cho thấy sự khác nhau quan trọng giữa nó với ngôn ngữ bậc thấp như là Assembler, đó là việc mã C có thể được dịch và thi hành trong hầu hết các máy tính, hơn hẳn các ngôn ngữ hiện tại trong khi đó thì Assembler chỉ có thể chạy trong một số máy tính đặc biệt. Vì lý do này C được xem là ngôn ngữ bậc trung.

### Điểm mạnh ngôn ngữ C

- **Ngôn ngữ lập trình cấp thấp**  
  Hệ điều hành Unix có tới 90% là được viết bởi ngôn ngữ C. 10% là được viết bởi hợp ngữ. Ngoài ra có rất nhiều các trình điều khiển hỗ trợ lập trình bằng ngôn ngữ C.

- **Ngôn ngữ có kích cỡ nhỏ**  
  So với các ngôn ngữ như C++/C#, Java, ngôn ngữ C có kích cỡ nhỏ. Các thư viện trong ngôn ngữ C là hạn chế, chỉ chứa các hàm cơ bản.

- **Mạnh và linh hoạt**  
  Ngôn ngữ C không đưa ra các ràng buộc đối với người lập trình. C được sử dụng trong nhiều dự án khác nhau, như viết hệ điều hành, chương trình xử lý văn bản, đồ hoạ, bảng tính, và thậm chí cả chương trình dịch cho các ngôn ngữ khác.

- **Ngôn ngữ có tính khả chuyển**  
  Một chương trình viết bằng C cho một hệ máy tính (ví dụ như IBM PC) có thể được dịch và chạy trên hệ máy tính khác (chẳng hạn như DEC VAX) chỉ với rất ít các sử đổi. Tính khả chuyển đã được bởi chuẩn ANSI cho C.

### Điểm yếu ngôn ngữ C

- **Các chương trình của C dễ bị lỗi**  
  Do tính mềm dẻo của ngôn ngữ C cũng chính là nguyên nhân dễ gây lỗi. Giống như các ngôn ngữ lập trình hợp ngữ các lỗi chỉ được phát hiện khi thực hiện biên dịch chương trình.

- **Các chương trình viết bằng ngôn ngữ C có thể khó hiểu**  
  Tuy ngôn ngữ C có kích cỡ nhỏ và số lượng các từ khóa không nhiều. Tuy nhiên cú pháp viết ngôn ngữ C có thể gây khó hiểu đối với các lập trình viên mới vào nghề vì các từ khóa và cú pháp có thể không gợi nhớ như các ngôn ngữ hiện đại C#, java.

- **Các chương trình viết bằng ngôn ngữ C khó chỉnh sửa**  
  Các chương trình lớn viết bằng ngôn ngữ C có thể khó chỉnh sửa nếu các tài liệu thiết kế chương trình không được thực hiện chi tiết. Các chương trình lớn thông thương được thiết kế theo các lớp và gói thông tin tuy nhiên ngôn ngữ C thiếu đặc điểm này.

## Cài đặt IDE (Integrated Development Environment)

IDE là phần mềm soạn thảo văn bản có tích hợp rất nhiều chức năng hỗ trợ cho chúng ta trong việc viết mã code, đối với C có khá nhiều IDEs như vậy, ví dụ một số IDE phổ biến:

- Code::Block
- Dev-C++
- C++ Builder
- CLion

Trọng phạm vi học tập, sẽ sử dụng IDE có tên là Dev-C++ vì nó nhẹ và dễ sử dụng - đầy đủ các chức năng cơ bản, các IDE còn lại dành cho người có nhiều kinh nghiệm hơn.

Phần mềm Dev C++ có đầy đủ các tính năng tích hợp cho ngôn ngữ lập trình C và C++. Nó sử dụng trình MinGW để làm phiên dịch.

Và Dev-C++ là một chương trình chỉ chạy trên Windows.

Tải Dev C++ [tại đây](https://drive.google.com/open?id=1hfDtkXXeafUQSH35dB0neBKQ5VtJdXle).
