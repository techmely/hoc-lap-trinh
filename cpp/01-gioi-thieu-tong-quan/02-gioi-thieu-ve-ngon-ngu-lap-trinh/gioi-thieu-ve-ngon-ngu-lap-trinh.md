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
position: 2
---

## Giới thiệu bài học

Trong bài học này, chúng ta bắt đầu với những khái niệm đầu tiên
về ngôn ngữ lập trình.

- Ngôn ngữ lập trình là gì?
- Nó được sử dụng với mục đích gì?
- Có các loại ngôn ngữ lập trình nào?
- Làm thế nào để chọn một ngôn ngữ lập trình phù hợp với bản thân?

## Giới thiệu chung về ngôn ngữ lập trình

Ngày nay, những máy tính hiện đại có tốc độ xử lý nhanh đáng kinh ngạc,
nhưng máy tính vốn chỉ có thể hiểu được một cách giới hạn các câu lệnh,
chúng ta cần phải nói với máy tính chính xác những gì chúng ta muốn nó làm.

Một chương trình máy tính (hay còn được gọi là phần mềm hoặc ứng dụng)
là một tập hợp các câu lệnh, chúng nói cho máy tính biết phải làm những gì,
và các thiết bị trên máy tính thực thi các câu lệnh được gọi là phần cứng.

Những tập hợp các câu lệnh được thiết kế để ra lệnh cho máy tính
được gọi là Ngôn ngữ lập trình.

Ngôn ngữ lập trình được chia là 2 loại:

- Ngôn ngữ lập trình bậc thấp
- Ngôn ngữ lập trình bậc cao

### Ngôn ngữ bậc thấp (Mã máy)

Một CPU của máy tính không đủ khả năng để hiểu được ngôn ngữ lập trình C++.
Chỉ một tập hợp rất hạn chế các chỉ thị mà máy tính hiển nhiên hiểu được,
chúng được gọi là mã máy (ngôn ngữ máy hay tập chỉ thị).
Hay nói cách khác, ngôn ngữ lập trình bậc thấp cung cấp cho máy tính
các chỉ thị rõ ràng, không có tính trừu tượng giúp máy tính
có thể hiểu được ngay lập tức.

Trong khóa học này, chúng ta chỉ quan tâm đến 2 điều:

- Một chỉ thị được hợp thành bởi một số các con số ở dạng nhị phân,
  nó chỉ có thể là 0 hoặc 1. Những con số dạng nhị phân này thường được gọi là
  những bit (là đơn vị lưu trữ nhỏ nhất trong máy tính).

- Mỗi tập hợp các số nhị phân được dịch bởi CPU thành các chỉ thị bảo
  máy tính làm một công việc cụ thể. Ví dụ: so sánh 2 số, lưu một giá trị
  vào một vùng nhớ máy tính. Mỗi CPU có một tập các chỉ thị khác nhau.

  Lập trình viên là những người tạo ra mã máy, nó rất khó và tốn thời gian
  để làm một thứ gì đó.

### Ngôn ngữ lập trình bậc cao

Ngôn ngữ lập trình bậc cao được thiết kế để lập trình viên viết chương trình
mà không cần bận tâm vào loại máy tính, có thể thấy ngôn ngữ lập trình bậc cao
khá gần gũi với ngôn ngữ tự nhiên.

Vì thế ngôn ngữ lập trình bậc cao phải được dịch ngược về mã máy
để CPU có thể hiểu được chúng.
Và thứ giúp lập trình viên thực hiện quá trình biên dịch mã máy này gọi là
**Compiler** (trình biên dịch).

Đây là mô tả đơn giản về quá trình biên dịch:

![0-1-CompiledExecutable](https://github.com/daynhauhoc/cppcoban/assets/88678933/68c987ea-82f0-4e0c-a045-ba5136bef70b)

Một **_Interpreter_** (trình thông dịch) là một chương trình chuyển đổi
trực tiếp ngôn ngữ lập trình bậc cao về mã máy không thông qua
quá trình biên dịch. Sử dụng Interpreter hướng đến sự linh hoạt,
nhưng không hiệu quả khi chạy chương trình, vì quá trình thông dịch diễn ra
liên tục khi chương trình đang chạy.

Đây là mô tả về quá trình thông dịch:

![0-1-Interpreted](https://github.com/daynhauhoc/cppcoban/assets/88678933/78d67e1c-c15c-43dd-b5b6-1d8b3548155e)

Thông thường, một chương trình C/C++ cần được biên dịch mới chạy được
trên phần cứng máy tính. Một số ngôn ngữ lập trình khác có thể sử dụng
đồng thời cả hai phương pháp (thông dịch hoặc biên dịch) để chạy
chương trình như Java.

Một số đặc điểm đáng chú ý ở các ngôn ngữ lập trình bậc cao:

- Dễ đọc và viết.
  Ví dụ: `a = 10`;

- Chỉ yêu cầu một số lượng ít các chỉ thị để thực hiện cùng một
  công việc mà ngôn ngữ lập trình bậc thấp thực hiện.

  Ví dụ: trong C++ bạn có thể thực hiện phép tính `a = b * 5 + 2;`
  chỉ trong một dòng lệnh.

- Tính tiện dụng.
  Chương trình được viết bằng ngôn ngữ lập trình bậc cao có thể tương thích
  với nhiều kiến trúc khác nhau.

## Lựa chọn ngôn ngữ lập trình

Hiện nay, có khoảng hơn 500 ngôn ngữ lập trình đã được sử dụng trên thế giới.
Đối với những người mới tiếp cận với ngôn ngữ lập trình, hay có dự định
theo đuổi con đường lập trình, việc chọn ra một ngôn ngữ lập trình để học
có thể là một trở ngại lớn bởi vì bạn có thể không có đầy đủ thông tin
cần thiết để đưa ra một lựa chọn tốt. Một khi bạn dành thời gian để suy nghĩ
về những gì bạn sẽ học, sẽ làm và phát triển...
Bạn có thể bắt đầu suy nghĩ về ngôn ngữ mà bạn sẽ học.

Sau đây là một số yếu tổ ảnh hưởng đến việc lựa chọn ngôn ngữ lập trình
để học và dùng trong dự án của bạn:

- **Nền tảng được hỗ trợ**: là một yếu tố quan trọng quyết định ngôn ngữ nào
  nên được sử dụng ngoại trừ ngôn ngữ lập trình hỗ trợ đa nền tảng.

  Ví dụ ứng dụng được phát triển trên nền tảng Microsoft có thể
  được lập trình bằng một số ngôn ngữ mà Microsoft hỗ trợ như C, C++, C#,
  và một số ngôn ngữ có thể viết được trên Visual studio.
  Trong khi đó, những ứng dụng liên quan đến Internet,
  ứng dụng trên điện thoại di động có thể được phát triển bằng ngôn ngữ Java.
  PHP cũng có thể dùng để phát triển ứng dụng Web...

- **Thời gian phát triển ứng dụng**:
  Với những ứng dụng được phát triển nhanh, Visual Basic là lựa chọn phù hợp
  để tăng tốc độ phát triển. Tuy nhiên, khi mà thời gian không bị ràng
  buộc bởi khách hàng, một số ngôn ngữ lập trình như
  C, C++ có thể được sử dụng.

- **Chi phí phát triển phần mềm**: Để phù hợp với ngân sách của
  người dùng cuối hoặc khách hàng, việc lựa chọn ngôn ngữ lập trình
  không làm nên sự khác biệt. Những ngôn ngữ lập trình với giấy phép
  phải được mua có chi phí phát triển phần mềm cao hơn
  những ngôn ngữ mã nguồn mở.
  Đó là lý do ứng dụng được viết bởi PHP có chi phí thấp hơn
  ứng dụng được viết trên ASP .NET framework.

- **Tính hiệu quả**: Tính hiệu quả của ứng dụng phụ thuộc trên nhiều yếu tố
  khác nhau (Tốc độ xử lý, khả năng đáp trả, tài nguyên sử dụng...)
  và việc lựa chọn ngôn ngữ lập trình cũng ảnh hưởng nhiều đến hiệu suất
  của ứng dụng. Thử đưa ra 2 ngôn ngữ lập trình Perl và PHP để so sánh.
  Perl được cho là hiệu quả hơn PHP về mặt tốc độ xử lý, sức mạnh...
  nhưng bên cạnh đó, PHP dễ học và triển khai hơn.

- **Độ tin cậy của ứng dụng**: Một số chương trình cần đảm bảo độ tin cậy
  lên đến 100%, như hệ thống trên máy bay. Sử dụng những chương trình
  có độ tin cậy thấp có thể dẫn đến hậu quả làm thiệt mạng
  hành khách trên máy bay. Một ngôn ngữ có khả năng vẫn được sử dụng cho các
  hệ thống quan trọng là ADA.

Trình biên dịch của mỗi ngôn ngữ lập trình cũng tác động đến hiệu suất của nó.
Tuy nhiên, điều này không cần thiết để đưa ra quyết định cho việc
chọn ngôn ngữ lập trình.

Lập trình viên có nhiều kinh nghiệm có thể làm ra một ứng dụng chạy tốt hơn
trên một trình biên dịch chậm hơn.

Điều này có nghĩa ngôn ngữ lập trình chỉ là công cụ,
thứ quan trọng nhất vẫn là kỹ năng của lập trình viên.
