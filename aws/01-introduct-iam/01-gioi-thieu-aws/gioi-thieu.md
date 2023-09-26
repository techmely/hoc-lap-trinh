---
title: "Tổng quan về AWS"
description: "Amazon Web Services (AWS) là nền tảng đám mây toàn diện và được sử dụng rộng rãi nhất, cung cấp trên 200 dịch vụ đầy đủ tính năng từ các trung tâm dữ liệu trên toàn thế giới."
author:
  fullname: Phan Văn Đức
  username: ducpv
  avatar: "/configs/author/ducpv.jpg"
category:
  name: "Khóa học AWS từ cơ bản đến nâng cao"
  slug: "aws"
chapter:
  name: "Giới thiệu AWS"
  slug: "chap-01-introduction"
image: https://user-images.githubusercontent.com/29729545/162230977-5b127f4a-6c28-416b-9096-4cdc99010ffa.png
position: 1
---

## Amazon Web Service là gì

Hiện tại Cloud Computing đang là xu thế của ngành công nghệ phần mềm. Việc coding và triển khai lên 1 server ngày nay trở nên rất dễ dàng. Thị phần của Cloud được chia ra các ông lớn: AWS, GCP (google), Azure (Microsoft)...

Tuy nhiên trong khóa học này chúng ta cùng tìm hiểu về AWS. Vậy AWS là gì?

Amazon Web Services (AWS) là nền tảng đám mây toàn diện và được sử dụng rộng rãi nhất, cung cấp trên 600 dịch vụ đầy đủ tính năng từ các trung tâm dữ liệu trên toàn thế giới. Hàng triệu khách hàng—bao gồm các công ty khởi nghiệp tăng trưởng nhanh nhất, các tập đoàn lớn nhất cũng như các cơ quan hàng đầu của chính phủ đều tin tưởng vào AWS để giảm chi phí, trở nên linh hoạt hơn và đổi mới nhanh hơn.

## Khi nào thì sử dụng AWS

- Một tổ chức sản xuất nhỏ sử dụng kiến ​​thức chuyên môn của họ để mở rộng hoạt động kinh doanh bằng các giao việc quản lý CNTT của AWS.
- Một doanh nghiệp lớn trên toàn cầu có thể sử dụng AWS để cung cấp các khóa đào tạo cho lực lượng lao động phân tán ở nhiều nơi.
- Một công ty tư vấn kiến ​​trúc có thể sử dụng AWS để kết xuất, tạo ra các mẫu xây dựng cần phải tính toán phức tạp.
- Một công ty truyền thông có thể sử dụng AWS để cung cấp các loại nội dung khác nhau như hộp thư điện tử(mail) hoặc file âm thanh, video, hình ảnh.v..v trên toàn thế giới.

## Dùng bao nhiêu trả bấy nhiêu

Dựa trên khái niệm `Pay-As-You-Go` mà AWS cung cấp dịch vụ cho khách hàng.

AWS cung cấp dịch vụ cho khách hàng khi được yêu cầu mà không cần cam kết trước hoặc đầu tư trả trước(nghĩa là không cần đặt cọc trước). Pay-As-You-Go cho phép khách hàng mua được các dịch vụ AWS sau đây:

- Cơ sở hạ tầng tin học(Computing)
- Môi trường lập trình(Programming models)
- Nơi lưu trữ cơ sở dữ liệu(Database storage)
- Tạo mạng lưới networking(Networking)

Bạn có thể tham khảo hình sau để hiểu hơn về các dịch vụ trên.

![Dùng bao nhiêu trả bấy nhiêu](https://user-images.githubusercontent.com/29374426/228418402-282f36f5-5328-48ca-a6d9-d5617a68eb23.png)

## Ưu điểm của AWS

### Tính linh hoạt

- Chúng ta có thể có nhiều thời gian hơn cho các nhiệm vụ kinh doanh cốt lõi của mình bằng cách dùng các tính năng và dịch vụ mới có sẵn trong AWS.
- Nó cung cấp lưu trữ dễ dàng các ứng dụng kế thừa(Là các ứng dụng đã rất cũ nhưng tính ổn định cao, vì vậy cần yêu cầu môi trường cũ để lưu trữ và AWS làm được điều đó). AWS không yêu cầu học các công nghệ mới và việc di chuyển các ứng dụng sang AWS để cung cấp khả năng tính toán nâng cao hơn và lưu trữ hiệu quả hơn.
- AWS cũng cung cấp sự lựa chọn cho dù chúng ta có muốn chạy các ứng dụng và dịch vụ cùng nhau hay không. Chúng ta cũng có thể chọn chạy một phần cơ sở hạ tầng CNTT trong AWS và phần còn lại trong trung tâm dữ liệu.

### Hiệu quả về chi phí

AWS không yêu cầu đầu tư trả trước, cam kết dài hạn và chi phí tối thiểu khi so sánh với cơ sở hạ tầng CNTT truyền thống đòi hỏi đầu tư lớn.

### Khả năng mở rộng / Độ co giãn

Thông qua AWS, các kỹ thuật cân bằng tải tự động và cân bằng tải đàn hồi được tự động tăng hoặc giảm tỷ lệ, khi nhu cầu tăng hoặc giảm tương ứng. Các kỹ thuật AWS rất lý tưởng để xử lý tải không thể đoán trước hoặc tải rất cao. Vì lý do này, các tổ chức được hưởng lợi ích từ việc giảm chi phí và tăng sự hài lòng của người dùng.

### Bảo mật

- AWS cung cấp bảo mật cho người dùng cuối và quyền riêng tư cho khách hàng.
- AWS có cơ sở hạ tầng ảo cung cấp tính khả dụng tối ưu trong khi quản lý toàn bộ quyền riêng tư và cách ly các hoạt động của họ.
- Khách hàng có thể mong đợi mức độ bảo mật vật lý cao vì Amazon đã có nhiều năm kinh nghiệm trong việc thiết kế, phát triển và duy trì các trung tâm vận hành CNTT quy mô lớn.
- AWS đảm bảo ba khía cạnh bảo mật, tức là Tính bảo mật, tính toàn vẹn và tính khả dụng của dữ liệu người dùng.

## Tạo tài khoản AWS

Để sử dụng được các dịch vụ của AWS bạn cần tạo một tài khoản. Bạn sẽ được sử dụng free 1 năm đầu trong khoảng cho phép của AWS, ví dụ 750h sử dụng EC2 free tier. Hãy làm theo hướng dẫn để tạo 1 tài khoản cho riêng mình: [Xem thêm](https://viblo.asia/p/huong-dan-tao-tai-khoan-aws-free-1-nam-GrLZDpwJZk0)

## Truy cập AWS services

Khi chúng ta sử dụng các dịch vụ trên nền tảng của AWS chắc chắn rằng cần truy cập những dịch vụ đó. Hiện tại có 3 phương thức để truy cập những services của AWS.

- **AWS Management Console**: Truy cập từ giao diện (website của AWS)
- **AWS Comand Line Interface(CLI)**: Truy cập thông qua màn mình cmd
- **AWS Software Development Kits (SDKs)**: Kết hợp với các language khác để phát triển (NodeJS...)

## AWS global infrastructure

AWS có hàng triệu khách hàng, họ cung cấp dịch vụ trên cơ sở hạ tầng toàn cầu. Hạ tầng của AWS xoay quanh 2 khái niệm là **Regions** và **Availability Zones (AZs)**. Tại thời điểm mình viết post này AWS có 32 regions và 102 AZs trên toàn cầu.

### Regions and AZs

Mỗi **Regions** là collection của (min 3 AZs, max 6 AZs, **thường là 3**), có thể coi **Region** là cụm data centers (cluster of datacenters). Mỗi regions độc lập với các region khác để đảm bảo an toàn khi có thiên tai xảy ra. Hiện tại ở Việt Nam chưa có datacenter nào của AWS, gần nhất với chúng ra là Nhật Bản (Tokyo, Osaka), Singapore...

![Regions](https://user-images.githubusercontent.com/29729545/162230977-5b127f4a-6c28-416b-9096-4cdc99010ffa.png)

::alert{type="infor"}AZs bao gồm 1 hoặc nhiều center riêng biệt, mỗi center có hệ thống điện, làm mát... Chúng được kết nối với nhau và kết nối với mạng với băng thông cao và độ trễ thấp.::

Khi lựa chọn region để sử dụng các services, nên chọn region gần với bạn để giảm độ trễ (latency).

### Edge locations (Access points)
Đây là một trong những hạ tầng mà AWS cung cấp cho người dùng. Hiện tại ở Việt Nam có 2 Edge location đặt tại Hà Nội và Hồ Chí Minh. Edge location như một điểm trung chuyển giúp request người dùng đến các Datacenter nhanh hơn. Edge locations có thể cached những content giúp giảm độ trễ. Ví dụ server bạn đặt ở Tokyo, Edge location ở Hà Nội hoặc Hồ Chí Minh giúp người dùng ở Việt Nam có thể truy cập nhanh hơn. Hiện tại có khoảng hơn 550 Access points trên toàn cầu.

## SaaS, PaaS, and IaaS

Đây là 3 models phổ biến trong Cloud Computing: **Infrastructure as a Service (IaaS)**, **Platform as a Service (PaaS)**, and **Software as a Service (SaaS)**

- **IaaS**: Provider cung cấp cho bạn phần cứng ảo hóa. VD: AWS EC2, Google ComputeEngine (GCE)...
- **PaaS**: Provider cung cấp dịch vụ dưới dạng flatforms hay tool để phát triển application, bạn không cần quan tâm đến phần cứng, network... VD: AWS Elastic Beanstalk, Heroku
- **SaaS**: Provider cung cấp software hoặc application. VD: Google Apps, Dropbox
- **On-premises**: là mô hình phần mềm được cài đặt trên server của chính doanh nghiệp, giúp doanh nghiệp toàn quyền kiểm soát.

::alert{type="infor"}
Tất cả model đều có điểm mạnh, yếu riêng biệt. Càng dễ dùng (convenient) thì càng ít kiểm soát (less-control). Vì vậy hãy chọn model cũng như dịch vụ phù hợp với đặc thù dự án của bạn.
::

