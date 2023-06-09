---
title: "Mô hình MVC là gì?"
description: "MVC là viết tắt của cụm từ “Model-View-Controller“ - một mô hình kiến trúc phần mềm được tạo ra với mục đích quản lí và xây dựng dự án phần mềm có hệ thống hơn."
keywords:
  [
    "Mô hình MVC",
    "Mô hình MVC là gì spring boot",
    "Mô hình MVC để làm gì trong spring",
    "cách sử dụng mô dình MVC trong spring",
    "mo hinh mvc co tac dung nhuw the nao trong spring",
  ]
chapter:
  name: "Tổng quan về Spring"
  slug: "chuong-02-tong-quan-ve-spring"
category:
  name: "Spring Boot"
  slug: "spring-boot"
image: https://kungfutech.edu.vn/thumbnail.png
position: 4
---

## Mô hình MVC

### Khái niệm.

MVC là một mô hình kiến trúc phần mềm được tạo ra với mục đích quản lí và xây dựng dự án phần mềm có hệ thống hơn, nói cụ thể thì nó là một mẫu thiết kế nhằm chia tách phần giao diện và phần code của ứng dụng để dễ dàng quản lí, bảo trì và phát triển. MVC được áp dụng trên hầu hết các ngôn ngữ lập trình hướng đối tượng hiện nay như C++, C#, Java, PHP,...

MVC chia ứng dụng phần mềm ra thành 3 phần có tương tác với nhau:

**Model:** thường là các class chứa thông tin đối tượng (dữ liệu), tương tác truy xuất database. Model sẽ đóng gói dữ liệu của ứng dụng và logic nghiệp vụ.

**View:** là nơi nhận dữ liệu từ model, database và sắp xếp chúng chính xác nhờ yêu cầu từ controller và truyền về client. View sẽ xử lý hiễn thị trên ứng dụng.

**Controller:** Đóng vai trò trung gian giữa Model và View, nó có nhiệm vụ nhận yêu cầu từ client sau đó xử lý request, load model và gửi data qua view tương ứng với nhau rồi trả kết quả về cho client.

![Mô hình MVC](https://github.com/techmely/hoc-lap-trinh/assets/29374426/4f3a0d22-eebe-49bd-bc32-9df03fe8ae6b)

### Luồng đi trong mô hình MVC.

Bạn có thể hình dung, khi một yêu cầu từ máy client gửi tới server, Controller sẽ thực hiện nhiệm vụ của mình đó là tiếp nhận và xử lý yêu cầu. Trong trường hợp cần thiết, nó có thể liên hệ Model – bộ phận làm việc với database để hỗ trợ.
Khi xử lý xong yêu cầu, kết quả sẽ được trả về View. Tại View sẽ tạo mã HTML thành giao diện và trả về hiển thị trên trình duyệt.
Ưu & nhược điểm của MVC?
Ưu điểm của mô hình MVC
Nhẹ, tiết kiệm băng thông: MVC không sử dụng viewstate nên khá tiết kiệm diện tích băng thông. Khi sử dụng, người dùng có thể sử dụng ứng dụng trên web cần tương tác gửi và nhận dữ liệu một cách liên tục. Do đó, việc giảm băng thông giúp cho website hoạt động tốt và ổn định hơn.

### Ưu - nhược điểm của mô hình MVC.

#### Ưu điểm của mô hình MVC.

- Kiểm tra dễ dàng: Với MVC, bạn có thể dễ dàng kiểm tra, rà soát lỗi phần mềm trước khi tới tay người tiêu dùng, đảm bảo chất lượng và độ uy tín cao hơn.
- Chức năng control: Trên các nền website thì ngôn ngữ lập trình như CSS, HTML, Javascript có một vai trò vô cùng quan trọng. Việc sử dụng mô hình MVC sẽ giúp bạn có một bộ control ưu việt trên nền tảng các ngôn ngữ hiện đại với nhiều hình thức khác nhau.
- View và size: View sẽ là nơi lưu trữ các dữ liệu. Càng nhiều yêu cầu được thực hiện thì kích thước càng tệp càng lớn. Khi đó, đường truyền mạng cũng giảm tốc độ load. Việc sử dụng mô hình MVC sẽ giúp bạn tiết kiệm được diện tích băng thông một cách tối ưu.
- Chức năng Soc (Separation of Concern): Chức năng này cho phép bạn phân tách rõ ràng các phần như Model, giao diện, data, nghiệp vụ.
- Tính kết hợp: Việc tích hợp ở mô hình MVC cho phép bạn thoải mái viết code trên nền tảng website. Khi đó, server của bạn sẽ được giảm tải khá nhiều.
- Đơn giản: Đây là một mô hình với kết cấu tương đối đơn giản. Dù bạn không có quá nhiều chuyên môn cũng có thể sử dụng được.

#### Nhược điểm của mô hình MVC

- Theo chia sẻ của đơn vị chuyên phát triển phần mềm (Outsource .NET Development Company – Groovetechnology.com) MVC thường được sử dụng vào những dự án lớn. Do đó, với các dự án nhỏ, mô hình MVC có thể gây cồng kềnh, tốn thời gian trong quá trình phát triển cũng như thời gian trung chuyển dữ liệu.

### Ứng dụng của mô hình MVC.

MVC đang là mô hình được ứng dụng rất nhiều trong lập trình.
Hệ thống MVC phát triển tốt sẽ cho phép phát triển front–end, back–end cùng trên hệ thống mà không có sự can thiệp, chia sẻ, chỉnh sửa các tập tin trong khi một hoặc hai bên vẫn đang làm việc.

Việc sử dụng mô hình tương đối đơn giản. Chỉ cần hiểu rõ quy trình vận hành, nắm được các chức năng của từng bộ phận thì việc triển khai mô hình MVC tương đối dễ dàng.
