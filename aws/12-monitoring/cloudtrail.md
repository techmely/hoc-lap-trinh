---
title: "Giới thiệu CloudTrail"
description: "AWS CloudTrail là một dịch vụ cho phép thực hiện việc quản lý,  kiểm tra vận hành và đánh giá rủi ro cho tài khoản AWS của bạn. Với CloudTrail, bạn có thể ghi nhật ký, giám sát liên tục và duy trì hoạt động của tài khoản có liên quan đến các hoạt động diễn ra trên cơ sở hạ tầng AWS của bạn."
keywords:
  [
    "CloudTrail la gi",
    "CloudTrail là gì",
    "CloudTrail trong aws",
    "CloudTrail Events la gi",
    "CloudTrail Events là gì",
    "CloudTrail Events trong aws",
    "CloudTrail Insight Events la gi",
    "CloudTrail Insight Events là gì",
  ]
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
position: 223
---

## CloudTrail là gì

AWS CloudTrail là một dịch vụ cho phép thực hiện việc quản lý, kiểm tra vận hành và đánh giá rủi ro cho tài khoản AWS của bạn. Với CloudTrail, bạn có thể ghi nhật ký, giám sát liên tục và duy trì hoạt động của tài khoản có liên quan đến các hoạt động diễn ra trên cơ sở hạ tầng AWS của bạn.

- Kiểm tra lịch sử của events/API call trong AWS account của bạn, events/API call đó có thể tạo bởi:
  - Console
  - SDK
  - CLI
  - AWS services
- CloudTrail mặc định sẽ được enable
- Ví dụ: bạn muốn kiểm tra xem 1 EC2 instance bị xóa bởi ai, thời gian nào...
- Event được lưu lại tối đa 90 ngày trên CloudTrail
- Để có thể lưu lại lâu hơn hãy log lại trên một S3 bucket và Athena để query data

![CloudTrail là gì](https://user-images.githubusercontent.com/29729545/156514323-4e79540d-4b9f-4294-8922-9ccbefbcd2ca.png)

## CloudTrail Events

- **Management Events**
  - Hoạt động được thực thi trên resource của AWS account
  - Ví dụ:
    - Configuring security (IAM)
    - Create Subnet...
  - Có thể tách riêng Read Event và Write Event
- **Data Events**
  - Mặc định data event không được ghi ra
  - Amazon S3 object-level activity
  - Lambda function execution
- **CloudTrail Insights Events**
  - Khi có nhiều lời gọi API hay dịch vụ trên AWS, bạn khó có thể detech được hết các event đó, đâu là event bình thường, đâu là event cảnh bảo cho bạn
  - CloudTrail Insights giúp bạn detech những hành động bất thường (unusual activity) trên AWS account
