---
title: "Gới thiệu AWS Config"
description: "AWS config là full managed service, cung cấp thông tin history cấu hình, báo notify thì có thay đổi về configuration để đảm bảo security và governance."
author:
  fullname: Phan Văn Đức
  username: ducpv
  avatar: "/configs/author/ducpv.jpg"
category:
  name: "Khóa học AWS từ cơ bản đến nâng cao"
  slug: "aws"
chapter:
  name: "Monitoring & Audit"
  slug: "chap-12-monitoring"
image: https://user-images.githubusercontent.com/29729545/172041253-7eb6e911-7513-4656-92e3-4e8cf69d71a0.png
position: 224
---

## AWS Config là gì

- AWS Config là dịch vụ hỗ trợ cho việc audit AWS resources của bạn
- Record lại cấu hình và sự thay đổi cấu hình theo thời gian
- Ví dụ:
  - AWS EBS đã được encrypt hay chưa ?
  - EIP đã được attach đến EC2 instance hay chưa ?
  - ...
- Kiểm tra cấu hình của một hoặc nhiều resource có trên account của bạn
- Nhận thông báo khi resource được tạo mới/thay đổi/xóa

![AWS Config](https://user-images.githubusercontent.com/29729545/172041253-7eb6e911-7513-4656-92e3-4e8cf69d71a0.png)

## Phân biệt Cloudwatch vs CloudTrail vs Config

- **Cloudwatch**
  - Monitoring (metrics, CPU, network,...), dashboard
  - Events & Alert
  - Logging & Analysis
- **CloudTrail**
  - Record API call
- **Config**
  - Record Configuration changes
  - Evaluate resources against compliance rules

**Ví dụ với Elastic Load Balancer**

- **Cloudwatch**
  - Monitoring những request đến
  - Tạo dashboard để theo dõi performance
- **CloudTrail**
  - Kiểm tra ai đã thay đổi config của Load Balancer qua API call
- **Config**
  - Kiểm tra config thay đổi
  - Đảm bảo Load Balancer luôn được assign một SSL certificate (compliance)
