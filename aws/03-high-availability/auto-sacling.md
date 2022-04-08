---
title: "Auto Scaling Group trong AWS"
description: "AWS Auto Scaling Group là tính năng tự động mở rộng để đảm bảo rằng các phiên bản Amazon EC2 đủ để chạy các ứng dụng của bạn. Bạn có thể tạo một nhóm AWS Auto Scaling trong các phiên bản EC2."
keywords: [
  "AWS ha là gì",
  "ASG là gì",
  "ASG la gi", 
  "Scheduled actions trong ASG",
  "Scaling policies trong ASG", 
  "Tự động Scale trong AWS"
]
author:
  fullname: Phan Văn Đức
  username: ducpv
  avatar: "/configs/author/ducpv.jpg"
category:
  name: "Khóa học AWS từ cơ bản đến nâng cao"
  slug: "aws"
chapter:
  name: "High Availability"
  slug: "ha"
position: 23
---

## Auto Scaling Group (ASG) là gì

AWS Auto Scaling Group là tính năng tự động mở rộng để đảm bảo rằng các phiên bản Amazon EC2 đủ để chạy các ứng dụng của bạn. Bạn có thể tạo một nhóm AWS Auto Scaling trong các phiên bản EC2. ![AWS Auto Scaling Group](https://docs.aws.amazon.com/autoscaling/ec2/userguide/images/as-basic-diagram.png)

- Minimum size: Số lượng EC2 instance tối thiểu cần có
- Maximum size: Số lượng EC2 instance tối đa
- Desired capacity: Số lượng EC2 instance thực tế chạy

## Thành phần của ASG

- Launch configuration: config khi launch instance mới
  - AMI + Instance types
  - EC2 user data (optional)
  - EBS volumes
  - Security Groups
  - SSH key pair
- Min size / Max size / Initial Capacity
- Network, subnets
- Load Balancer (optional)
- Scaling policies (đặt ra các policies để mở rộng, ví dụ: tỉ lệ CPU, Network...)
- Scheduled actions (Lịch trình để sử dụng scaling, ví dụ: cứ 5 phút 1 lần...)

<content-info>
<strong>Tổng kết</strong>
  <ul>
    <li>Có thể tạo Scaling Policies dựa trên % CPU, Network... hoặc đặt lịch (Scheduled)</li>
    <li>Cần sử dụng <b>Launch configuration</b> hoặc <b>Launch Templates</b> (version mới)</li>
    <li>Để update ASG chỉ cần update lại Launch configuration/Launch Templates</li>
    <li>IAM role attach vào ASG sẽ assign cho EC2 instances</li>
    <li>ASG miên phí, chúng ta chỉ cần trả cho resource như EC2, EBS...</li>
  </ul>
</content-info>
