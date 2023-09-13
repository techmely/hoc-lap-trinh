---
title: "Auto Scaling Group trong AWS"
description: "AWS Auto Scaling Group là tính năng tự động mở rộng để đảm bảo rằng các phiên bản Amazon EC2 đủ để chạy các ứng dụng của bạn. Bạn có thể tạo một nhóm AWS Auto Scaling trong các phiên bản EC2."
author:
  fullname: Phan Văn Đức
  username: ducpv
  avatar: "/configs/author/ducpv.jpg"
category:
  name: "Khóa học AWS từ cơ bản đến nâng cao"
  slug: "aws"
chapter:
  name: "High Availability"
  slug: "chap-03-ha"
image: https://user-images.githubusercontent.com/29729545/163433393-63707570-9252-4b50-b24a-d7a29f8ef48f.png
position: 23
---

## Auto Scaling Group (ASG) là gì

AWS Auto Scaling Group là tính năng tự động mở rộng để đảm bảo rằng các phiên bản Amazon EC2 đủ để chạy các ứng dụng của bạn. Bạn có thể tạo một nhóm AWS Auto Scaling trong các phiên bản EC2.

![AWS Auto Scaling Group](https://user-images.githubusercontent.com/29729545/163433393-63707570-9252-4b50-b24a-d7a29f8ef48f.png)

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

::alert{type="infor"}
<strong>Tổng kết</strong>

  <ul>
    <li>Có thể tạo Scaling Policies dựa trên % CPU, Network... hoặc đặt lịch (Scheduled)</li>
    <li>Cần sử dụng <b>Launch configuration</b> hoặc <b>Launch Templates</b> (version mới)</li>
    <li>Để update ASG chỉ cần update lại Launch configuration/Launch Templates</li>
    <li>IAM role attach vào ASG sẽ assign cho EC2 instances</li>
    <li>ASG miên phí, chúng ta chỉ cần trả cho resource như EC2, EBS...</li>
  </ul>
::
