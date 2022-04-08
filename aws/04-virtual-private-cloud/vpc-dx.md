---
title: "Kết nối Data Center tới AWS"
description: "AWS hỗ trợ bạn có thể kết nối một cách bảo mật giữa môi trường AWS tới các Data Center tại chỗ (chẳng hạn như data center của công ty bạn). Những dịch vụ đó bao gồm. Nếu bạn muốn setup Direct Connect tới một hoặc nhiều VPC ở các Region khác nhau (chung account), thì cần dùng đến Direct Connect Gateway. Mặc định khi chúng ta launch 1 EC2 instance trong VPC thì không thể giao tiếp được Network của bạn (remote network). Để có thể access vào remote network chúng ta cần tạo một Site-to-Site VPN Connection."
keywords:
  [
    "Direct Connect trong AWS",
    "Direct Connect là gì",
    "Direct Connect la gi",
    "AWS Site to Site VPN trong AWS",
    "AWS Site to Site là gì",
    "AWS Site to Site la gi",
    "AWS Direct Connect Gateway trong AWS",
    "AWS Direct Connect Gateway là gì",
    "AWS Direct Connect Gateway la gi",
  ]
author:
  fullname: Phan Văn Đức
  username: ducpv
  avatar: "/configs/author/ducpv.jpg"
category:
  name: "Khóa học AWS từ cơ bản đến nâng cao"
  slug: "aws"
chapter:
  name: "Virtual Private Cloud"
  slug: "vpc"
position: 23
---

AWS hỗ trợ bạn có thể kết nối một cách bảo mật giữa môi trường AWS tới các Data Center tại chỗ (chẳng hạn như data center của công ty bạn). Những dịch vụ đó bao gồm:

- AWS Site to Site VPN
- Vitual Private Gateway & Customer Gateway
- AWS Direct Connect
- AWS Direct Connect Gateway Chúng ta sẽ cùng đi tìm hiểu từng dịch vụ trên hoạt động như thế nào.

## AWS Site-to-Site VPN

![Giới thiệu về Site to site VPN](https://user-images.githubusercontent.com/29729545/147389403-c4a2301b-c0b5-4662-bb23-6c6b707cc0b1.png)

Mặc định khi chúng ta launch một EC2 instance trong VPC thì không thể giao tiếp được Network của bạn (remote network). Để có thể access vào remote network chúng ta cần tạo một **Site-to-Site VPN Connection**. Như hình vẽ, chúng ta sẽ tạo một connection từ VPC đến [On-premises network]. Để làm được điều này, chúng ta cần nó VPN Gateway trên VPC và Customer Gateway trên [On-premises network], tiếp đó là VPN Connection. VPN Connection sẽ được mã hóa để đảm bảo về bảo mật.

- **Virtual Private Gateway (VGW)**:
  - VGW được tạo ra và attach vào VPC mà bạn muốn tạo Site-to-Site VPN Connection
- **Customer Gateway (CGW)**
  - Có thể là phần mềm hay thiết bị trên Customer Side trong VPN Connection

<content-info>
<ul>
    <li>Customer Gateway cần có public IP (hoặc thông qua NAT) để tạo kết nối</li>
    <li>Subnet trong VPC cần route đến VGW</li>
    <li>Nếu muốn access đến EC2 instance cần thêm protocol ICMP trong security groups</li>
  </ul>
</content-info>

## Direct Connect (DX) là gì

Hiểu đơn giản, Direct Connection cung cấp một đường truyền chuyên dụng, ổn định, được thiết lập riêng giữa AWS và Data center hay office. Khi sử dụng Direct Connection bạn không kết nối qua internet mà kết nối trực tiếp tới AWS, vì vậy đường truyền có thể lên tới 1-10 Gbps.

### Use Cases

- Yêu cầu bandwidth cao, làm việc với data set lớn mà yêu cầu chi phí thấp
  - Việc chuyển các file dữ liệu lớn qua Internet là rất tốn kém
- Phản hồi dữ liệu real-time, độ trễ nhỏ
- Các ứng dụng Cloud Native (Cloud + On-premises)

### Direct Connect virtual interfaces

- **Private virtual interface**: Truy cập đến VPC qua private IP
- **Public virtual interface**: Truy cập đến dịch vụ của AWS từ Data center của bạn. Cho phép đi ra ngoài Public Network thông qua Interface thay vì Internet

![Giới thiệu về Direct Connect](https://user-images.githubusercontent.com/29729545/147390545-1c1f9982-31c6-4ef4-a80b-51f19d8ff47e.png)

<content-info>
  <ul>
    <li>Thời gian setup Connection thường sẽ mất nhiều hơn 1 tháng.</li>
  </ul>
</content-info>

## Direct Connect Gateway trong AWS

Nếu bạn muốn setup Direct Connect tới một hoặc nhiều VPC ở các Region khác nhau (chung account), thì cần dùng đến Direct Connect Gateway.

![Giới thiệu về Direct Connect Gateway](https://user-images.githubusercontent.com/29729545/147390769-04b883bc-1a65-4835-ba02-6ab598fb3dae.png)
