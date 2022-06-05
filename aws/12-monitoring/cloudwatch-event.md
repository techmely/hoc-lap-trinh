---
title: "Giới thiệu CloudWatch Events"
description: "CloudWatch Events cung cấp các event để mô tả những thay đổi resource trên AWS. Bằng cách sử dụng những rules, bạn có thể định nghĩa những target mà khi một event được gọi tới. EventBridge là giải pháp thay thế cho CloudWatch Events"
keywords:
  [
    "CloudWatch la gi",
    "CloudWatch là gì",
    "CloudWatch trong aws",
    "AWS CloudWatch Events la gi",
    "AWS CloudWatch Events là gì",
    "AWS EventBridge la gi",
    "AWS EventBridge là gì",
    "EventBridge Schema Registry la gi",
    "EventBridge Schema Registry là gì"
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
image: https://user-images.githubusercontent.com/29729545/172041126-1b9595ec-2bba-4509-8639-36944c107bb4.png
position: 222
---

## AWS CloudWatch Events là gì

![AWS CloudWatch Events là gì](https://user-images.githubusercontent.com/29729545/172041126-1b9595ec-2bba-4509-8639-36944c107bb4.png)

CloudWatch Events cung cấp các event để mô tả những thay đổi resource trên AWS. Bằng cách sử dụng những **rules**, bạn có thể định nghĩa những target mà khi một event được gọi tới.

Ví dụ: Bạn có thể cài đặt một Event: nhận biết state của EC2 instance chuyển sang "pending". Target của event đó sẽ là một SNS Topic gửi mail đến người dùng.

- **Events**: là sự kiện xác định thay đổi resource trên môi trường AWS
- **Rules**: định nghĩa những event và target khi event đó xảy ra
- **Target**: nơi xử lý khi event xảy ra. Target có thể là: Lambda, SNS, Batch jobs, SQS...

## AWS EventBridge là gì

- EventBridge là giải pháp thay thế cho CloudWatch Events
- **Default event bus**: được tạo ra bởi AWS (giống với CloudWatch Events)
- **Partner event bus**: tiếp nhập event từ một dịch vụ SaaS hoặc một Application (DataDog, Zendesk...)
- **Custom Event Buses**: custom để sử dụng cho application của riêng bạn

## EventBridge Schema Registry là gì

- EventBridge có thể phân tích các events
- EventBridge Schema Registry lưu trữ các cấu trúc của event hoặc schema
- Khi bạn đã có Schema cho một event, EventBridge sẽ tạo ra những source code sample. Bạn có thể download code ở nhiểu ngôn ngữ (java, js...) để tiếp tục phát triển thêm.
