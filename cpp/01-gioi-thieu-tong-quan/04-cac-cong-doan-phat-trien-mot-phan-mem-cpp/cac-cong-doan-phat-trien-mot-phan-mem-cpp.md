---
title: "Các công đoạn phát triển một phần mềm với C++"
description: "Chào mừng đến với loạt bài hướng dẫn sử dụng ngôn ngữ lập trình C++! Loạt bài hướng dẫn này được thiết kế cho những người chưa hoặc biết một ít lập trình."
chapter:
  name: "Giới thiệu tổng quan về khóa học C++"
  slug: "chuong-01-gioi-thieu-tong-quan-ve-khoa-hoc"
image: https://kungfutech.edu.vn/thumbnail.png
position: 4
---

Ở bài trước, chúng ta đã cùng nhau tìm hiểu C++ là gì, nó được dùng cho mục đích gì... Các bạn xem đến bài này nghĩa là các bạn đã xác định được phần nào hướng đi trong tương lai, hi vọng các bạn có thể theo đuổi đến cùng với lựa chọn của mình.

Trong bài học này, chúng ta thảo luận về các bước để phát triển ra một chương
trình C++ trước khi các bạn bắt đầu với chương trình đầu tiên của mình.

Một chương trình máy tính (phần mềm) được tạo ra nhằm được sử dụng trong một
hoặc một vài mục đích cụ thể nào đó (Thống kê, dạy học, y tế, để giải trí,...
hay thậm chí phần mềm được tạo ra để hổ trợ lập trình viên tạo
ra những phần mềm).

Viết một chương trình là một công đoạn nhỏ trong quá trình sản xuất phần mềm
(vì một phần mềm thường là tập hợp của nhiều chương trình nhỏ) nhưng nó
cũng được thực hiện thông qua những công đoạn tương tự như phát triển
một phần mềm lớn.

![Các công đoạn phát triển một phần mềm với C++](https://github.com/techmely/hoc-lap-trinh/assets/29374426/6042d3a1-7c9b-4ff2-9721-88db7f4d3579)

Các bước phát triển một phần mềm

- Xác định vấn đề cần giải quyết.
- Thiết kế giải pháp (chọn nền tảng phát triển, chọn ngôn ngữ, chọn công cụ,
  xác định thuật toán cho chương trình...).
- Viết chương trình thực hiện theo giải pháp đã đề ra.
- Biên dịch chương trình (chuyển đổi mã lập trình về mã máy).
- Liên kết các file đã được biên dịch.
- Chạy chương trình, kiểm tra và sửa lỗi cho chương trình.

Đối với một số lập trình viên chuyên nghiệp (hoặc do vấn đề cần giải quyết
quá đơn giản), người ta có thể thực hiện nhanh bước 1, 2 và bắt tay vào viết
chương trình ngay lập tức. Mục tiêu của khóa học này cũng bao gồm rèn luyện
tư duy giúp bạn phát triển khả năng tự giải quyết vấn đề của riêng mình.

Chúng ta bắt đầu làm rõ từng bước trong quá trình phát triển
chương trình phần mềm (hay cụ thể là chương trình C++).

## Bước 1: Xác định vấn đề cần giải quyết

Công đoạn này quyết định phần lớn đến việc chương trình của bạn được thực hiện
một cách khó khăn hay dễ dàng. Nhưng trên lý thuyết, nó khá đơn giản.
Tất cả những gì bạn cần là một ý tưởng có thể dễ dàng xác định.

Để dễ hiểu hơn, chúng ta cùng đặt một câu hỏi: Bạn đang gặp phải vấn đề gì?

Mình xin đưa ra một số tình huống cụ thể:

- Mình muốn có một chương trình cho phép nhập vào năm sinh,
  sau đó tính ra số tuổi hiện tại của bạn. (Hình 0.3.1)
- Mình muốn viết một chương trình tìm ra đường đi ngắn nhất
  để đi từ nhà đến trường. (Hình 0.3.2)
- Mình cần một chương trình giúp mình hoàn tất đống sổ sách
  một cách nhanh chóng hơn. (Hình 0.3.3)

Trên đây là ba trường hợp ngẫu nhiên mình nghĩ đến vì mình cần dùng nó trong
cuộc sống. Vì mình cần máy tính giúp mình giải quyết những thứ tương tự
như trên, nên mình đã xác định vấn đề của riêng mình.
Cùng xem thử mình đã xác định được nó bằng cách nào.

- Trường hợp 1: Mình muốn có một chương trình cho phép nhập vào năm sinh, sau
  đó tính ra số tuổi hiện tại của bạn. (Hình 0.3.1)

  Có lẽ đây là một vấn đề quá đơn giản so với một số người, nhưng trước khi
  làm cho máy tính hiểu được vấn đề, bản thân chúng ta phải hiểu được vấn đề
  trước.

  Mình đã tự đặt câu hỏi với bản thân là:
  "Hiện tại, mình đang cần biết điều gì?".

  Sau đó mình tự trả lời với bản thân là:
  "Mình muốn biết năm nay mình bao nhiêu tuổi".

- Trường hợp 2: Mình muốn viết một chương trình tìm ra đường đi ngắn nhất để
  đi từ nhà đến trường. (Hình 0.3.2)

  Câu hỏi mình tự đặt ra: "Làm thế nào để tiết kiệm xăng bây giờ?"

  Tự trả lời luôn: "Để tìm coi đường nào ngắn nhất để đi tới trường mới được".

- Trường hợp 3: Mình cần một chương trình giúp mình hoàn tất đống sổ sách
  một cách nhanh chóng hơn. (Hình 0.3.3)

  Câu hỏi: "Với cái đống sổ sách này, làm sao mình có thể dành thời gian
  đi chơi với gấu được?"

  Trả lời: "Phải tìm cách để quản lý nó thôi, tiện thể đưa cho máy tính
  làm luôn cho khỏe".

Có thể trong cuộc sống các bạn gặp phải những vấn đề không giống với mình đưa ra
ở trên. Có thể đó là một bài toán khó, một trường hợp khó giải quyết, và bạn cần
cái máy tính của bạn giúp đỡ, đó là lúc mà bạn phải tự tìm ra
câu trả lời cho bản thân.

## Bước 2: Thiết kế giải pháp

Đây là lúc mà bạn cần đặt ra câu hỏi: "Làm thế nào" để giải quyết những vấn đề
trên? (Hình 0.3.4). Vấn đề nan giải là một trường hợp ở trên đều có nhiều hơn 1
cách giải quyết. Một trong số chúng tốt, số còn lại đa phần là không tốt.
Thường thì trong bước này, một số lập trình viên tồi sẽ thực hiện
một cách lôi thôi, cẩu thả nhất trong tất cả các công đoạn.

Mình đã thấy nhiều người mới học lập trình, sau khi nhìn ra được vấn đề,
họ ngồi xuống và bắt đầu code những gì họ đang tưởng tượng.
Đa phần, kết quả sinh ra không như mong đợi.

Điển hình, một giải pháp tốt thường có những đặc điểm sau:

- Nó có tính minh bạch, rõ ràng.
- Nó có thể sử dụng lại và dễ thay đổi trong tương lai.
- Tính hiệu quả.

Thực hiện tốt công đoạn này, bạn sẽ giảm được tối đa khả năng phát sinh lỗi
trong chương trình (sẽ tiết kiệm được khối thời gian cho việc sửa lỗi).

Ở những bài sau, các bạn sẽ được học cách tự mình đưa ra giải pháp cho
từng tình huống cụ thể.

## Bước 3: Viết chương trình

Để viết được chương trình, bạn cần biết:

- Ngôn ngữ lập trình bạn đang sử dụng. (Hình 0.3.5)
- IDE (môi trường phát triển ứng dụng). (Hình 0.3.6)

Bạn hoàn toàn có thể viết chương trình trên một số công cụ soản thảo văn bản như
Notepad, Notepad++, Sublime Text,... Nhưng trong khóa học này, mình khuyên
các bạn nên sử dụng IDE, vì nó hổ trợ khá nhiều cho các bạn trong việc
compile và liên kết các file đối tượng.

Cụ thể, mình sử dụng công cụ Visual studio 2015 mà mình sẽ hướng dẫn cài đặt
trong bài học tiếp theo.

File chứa mã nguồn C++ của bạn cần được đặt tên và lưu với phần mở rộng
là `.cpp` giúp cho hệ điều hành có thể hiểu được đó là file mã nguồn C++.

Sau này bạn có thể gặp một số file C++ có định dạng phần mở rộng khác
như `.h`, `.hpp` ... nhưng chúng ta sẽ nói về vấn đề này sau.

## Bước 4: Biên dịch chương trình

Để biên dịch một chương trình C++, chúng ta cần một trình biên dịch (compiler).
(Hình 0.3.7)

Mục đích của compile chương trình là biến những file mã nguồn có đuôi
`.cpp`, `.h`, ... thành những object file `.o`

(Hình 0.3.8)

Chúng ta sử dụng luôn trình biên dịch tích hợp sẵn trong visual studio 2015
nên khá tiện lợi.

## Bước 5: Liên kết các object file

(Hình 0.3.9)

Các object file sau khi được compiler biên dịch vẫn còn nằm tách biệt với nhau.
Nên quá trình này sẽ thực hiện liên kết chúng thành một file duy nhất,
gọi là executable file (file `.exe`).

## Bước 6: Chạy chương trình và kiểm lỗi

Trong công đoạn này, bạn hoặc ai đó chạy chương trình mà bạn đã tạo ra,
với nhiều giá trị khác nhau được đưa vào nhằm chắc chắn rằng chương trình
hoạt động như ý muốn.

Ở bài sau, chúng ta sẽ nói về IDE (môi trường tích hợp phát triển).

Hẹn gặp lại các bạn.
