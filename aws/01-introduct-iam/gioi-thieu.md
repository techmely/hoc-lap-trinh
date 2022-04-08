---
title: "Tổng quan về AWS"
description: "Amazon Web Services (AWS) là nền tảng đám mây toàn diện và được sử dụng rộng rãi nhất, cung cấp trên 200 dịch vụ đầy đủ tính năng từ các trung tâm dữ liệu trên toàn thế giới."
keywords:
  [
    "Amazon Web Services (AWS) là gì",
    "Amazon Web Services (AWS) la gi",
    "aws cli là gì",
    "aws là gì",
    "bằng aws là gì",
    "cloud aws là gì",
    "cloud aws la gi",
    "cloud la gi",
    "học aws",
    "học aws cơ bản",
    "hoc aws co ban"
  ]
author:
  fullname: Phan Văn Đức
  username: ducpv
  avatar: "/configs/author/ducpv.jpg"
category:
  name: "Khóa học AWS từ cơ bản đến nâng cao"
  slug: "aws"
chapter:
  name: "Giới thiệu AWS"
  slug: "index"
image: https://user-images.githubusercontent.com/29729545/162230977-5b127f4a-6c28-416b-9096-4cdc99010ffa.png
position: 1
---

## Amazon Web Service là gì

Hiện tại Cloud Computing đang là xu thế của ngành công nghệ phần mềm. Việc coding và triển khai lên 1 server ngày nay trở nên rất dễ dàng. Thị phần của Cloud được chia ra các ông lớn: AWS, GCP (google), Azure (Microsoft)...

Tuy nhiên trong khóa học này chúng ta cùng tìm hiểu về AWS. Vậy AWS là gì?

Amazon Web Services (AWS) là nền tảng đám mây toàn diện và được sử dụng rộng rãi nhất, cung cấp trên 200 dịch vụ đầy đủ tính năng từ các trung tâm dữ liệu trên toàn thế giới. Hàng triệu khách hàng—bao gồm các công ty khởi nghiệp tăng trưởng nhanh nhất, các tập đoàn lớn nhất cũng như các cơ quan hàng đầu của chính phủ đều tin tưởng vào AWS để giảm chi phí, trở nên linh hoạt hơn và đổi mới nhanh hơn.

## Tạo tài khoản AWS

Để sử dụng được các dịch vụ của AWS bạn cần tạo một tài khoản. Bạn sẽ được sử dụng free 1 năm đầu trong khoảng cho phép của AWS, ví dụ 750h sử dụng EC2 free tier. Hãy làm theo hướng dẫn để tạo 1 tài khoản cho riêng mình: [=>Xem thêm](https://viblo.asia/p/huong-dan-tao-tai-khoan-aws-free-1-nam-GrLZDpwJZk0)

## Truy cập AWS services

Khi chúng ta sử dụng các dịch vụ trên nền tảng của AWS chắc chắn rằng cần truy cập những dịch vụ đó. Hiện tại có 3 phương thức để truy cập những services của AWS.

- **AWS Management Console**: Truy cập từ giao diện (website của AWS)
- **AWS Comand Line Interface(CLI)**: Truy cập thông qua màn mình cmd
- **AWS Software Development Kits (SDKs)**: Kết hợp với các language khác để phát triển (NodeJS...)

## AWS global infrastructure

AWS có hàng triệu khách hàng, họ cung cấp dịch vụ trên cơ sở hạ tầng toàn cầu. Hạ tầng của AWS xoay quanh 2 khái niệm là **Regions** và **Availability Zones (AZs)**. Tại thời điểm mình viết post này AWS có 25 regions và 81 AZs trên toàn cầu.

### Regions and AZs

Mỗi **Regions** là collection của (min 2 AZs, max 6 AZs, **thường là 3**), có thể coi Region là cụm data centers (cluster of datacenters). Mỗi regions độc lập với các region khác để đảm bảo an toàn khi có thiên tai xảy ra. Hiện tại ở Việt Nam chưa có datacenter nào của AWS, gần nhất với chúng ra là Nhật Bản (Tokyo, Osaka), Singapore... 

![Regions](https://user-images.githubusercontent.com/29729545/162230977-5b127f4a-6c28-416b-9096-4cdc99010ffa.png)

<content-info>AZs bao gồm 1 hoặc nhiều center riêng biệt, mỗi center có hệ thống điện, làm mát... Chúng được kết nối với nhau và kết nối với mạng với băng thông cao và độ trễ thấp.</content-info>

Khi lựa chọn region để sử dụng các services, nên chọn region gần với bạn để giảm độ trễ (latency).

## SaaS, PaaS, and IaaS

Đây là 3 models phổ biến trong Cloud Computing: **Infrastructure as a Service (IaaS)**, **Platform as a Service (PaaS)**, and **Software as a Service (SaaS)**

- **IaaS**: Provider cung cấp cho bạn phần cứng ảo hóa. VD: AWS EC2, Google ComputeEngine (GCE)...
- **PaaS**: Provider cung cấp dịch vụ dưới dạng flatforms hay tool để phát triển application, bạn không cần quan tâm đến phần cứng, network... VD: AWS Elastic Beanstalk, Heroku
- **SaaS**: Provider cung cấp software hoặc application. VD: Google Apps, Dropbox
- **On-premises**: là mô hình phần mềm được cài đặt trên server của chính doanh nghiệp, giúp doanh nghiệp toàn quyền kiểm soát.

<content-info>
Tất cả model đều có điểm mạnh, yếu riêng biệt. Càng dễ dùng (convenient) thì càng ít kiểm soát (less-control). Vì vậy hãy chọn model cũng như dịch vụ phù hợp với đặc thù dự án của bạn.
</content-info>
