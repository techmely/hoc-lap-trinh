---
title: "Giới thiệu NAT trong AWS"
description: "Bastion hosts là cách để chúng ta có thể truy cập vào 1 instance trong private subnet"
keywords:
  [
    "NAT trong vpc",
    "NAT là gì",
    "NAT la gi",
    "NAT instance la gi",
    "NAT getway la gi",
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
position: 19
---

## Network Address Translation (NAT)

Như ở phần trước chúng ta tìm hiểu các sử dùng Bastion hosts để truy cập vào EC2 instances nằm trong private subnet. Ở bài học này chúng ta sẽ tìm hiểu làm thế nào để EC2 instances trong private subnet connect ra ngoài internet. ![NAT la gi](https://user-images.githubusercontent.com/29729545/146040993-981308a2-2164-4fba-9bce-035e723d737b.png)

Khi các resources trong private subnet muốn request ra bên ngoài internet(VD: npm install package), **NAT** sẽ thay đổi IP private của tài nguyên thành IP của mình và request ra ngoài internet. Khi có response NAT sẽ gửi lại response cho private IP của resource tương ứng. Đó là cách để resources trong private subnet có thể giao tiếp ra bên ngoài internet

### NAT instance

NAT instance giống như một nhà vận chuyển request giữa Internet và EC2 instances trong private subnet. ![NAT instance](https://user-images.githubusercontent.com/29729545/146041464-e911b8ef-2b5c-4e31-8570-8e53740987e8.png)

- Là EC2 instance được launch trong public subnet
- Phải được attached Elastic IP
- Route table phải được config để route traffic từ private subnet đến NAT instance
- AWS cung cấp AMI cho NAT instances, chúng ta có thể sự dụng nó khi launch instance mới
- NAT instances hiện nay không được sử dụng nhiều nhưng trong exam vẫn xuất hiện các câu hỏi về nó

### NAT gateway

NAT gateway dùng để instances trong private subnet có thể connect với services bên ngoài VPC, nhưng ko tạo kết nối giữa instances và services đó Khi tạo mới NAT getway có 2 loại kết nối:

- **Public(default)**:
  - Có thể connect ra bên ngoài internet
  - Phải allocated Elastic IP
  - Tính tiền theo giờ và bandwidth
  - Cần IGW để ra ngoài internet (Private subnet => NAT GW => IGW)
- **Private**:
  - Có thể connect với VPC khác, không thể connect internet. Nếu IGW attach vào _private NAT_ thì connection đó cũng sẽ bị drop
  - Không cần allocated Elastic IP

### So sánh NAT instance and NAT getway

- NAT getway được managed bởi AWS, vì vậy được recommended sử dụng hơn là NAT instance (managed bởi bạn).
- NAT getway better avaiability và bandwidth cao hơn NAT instance (vì NAT instance còn dựa vào EC2 type)
- NAT GW trả tiền theo giờ và số lượng data tranfer, còn NAT instance thì trả tiền giống EC2 tùy thuộc vào kiểu máy, network
