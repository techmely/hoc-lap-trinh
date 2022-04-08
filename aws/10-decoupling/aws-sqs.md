---
title: "Giới thiệu Amazon SQS - Standard Queues"
description: "Amazon Simple Queue Service (SQS) là một dịch vụ hàng đợi (queue) lưu trữ message nhanh chóng, đáng tin cậy, có khả năng mở rộng và quản lý một cách đầy đủ. Với SQS, bạn có thể gửi, nhận và lưu trữ message giữa các thành phần trong một phần mềm."
keywords:
  [
    "Amazon SQS là gì",
    "AWS SQS la gi",
    "SQS trong AWS",
    "AWS Standard SQS là gì",
    "AWS Standard SQS la gi",
    "Producing message trong SQS",
    "Consuming message trong SQS",
    "Multiple consuming message trong SQS",
    "SQS - auto scaling group",
    "SQS security",
  ]
author:
  fullname: Phan Văn Đức
  username: ducpv
  avatar: "/configs/author/ducpv.jpg"
category:
  name: "Khóa học AWS từ cơ bản đến nâng cao"
  slug: "aws"
  description: "Mang kiến thức AWS đến với mọi lập trình viên"
chapter:
  name: "Decoupling trong AWS"
  slug: "decoupling"
position: 171
---

## Amazon SQS là gì

Amazon Simple Queue Service (SQS) là một dịch vụ hàng đợi (queue) lưu trữ message nhanh chóng, đáng tin cậy, có khả năng mở rộng và quản lý một cách đầy đủ. Với SQS, bạn có thể gửi, nhận và lưu trữ message giữa các thành phần trong một phần mềm.

Attributes:

- Không giới hạn số lượng messages trong queue
- Mặc định message có thể tồn tại trong 4 ngày, tối đa là 14 ngày
- Độ trễ thấp khi gửi và nhận message
- **Mỗi message dung lượng tối đa là 256KB**

## SQS publish (producing) message

- Sử dụng SDK để tạo mới message và gửi message đó đến SQS (SendMessage API)
- Message sẽ nằm trong SQS cho đến khi consumer nhận, xử lý và xóa nó đi khỏi queue
- Message có thể nằm trong SQS 4 ngày và tối đa là 14 ngày

![SQS publish message](https://user-images.githubusercontent.com/29729545/154323509-5fada95e-6873-4eb3-8a6d-76f10cbf597b.png)

## SQS consuming message

- Consumers (EC2 instance, server, Lambda function...)
- Recevie message từ SQS (có thể nhận tối đa 10 message từ SQS)
- Xử lý message nhận được
- Xóa message sử dụng DeleteMessage API

![SQS consuming message](https://user-images.githubusercontent.com/29729545/154324541-b667c90b-9c40-499b-9f6a-2168b1afef85.png)

## SQS Multiple EC2 consumer

![SQS Multiple EC2 consumer](https://user-images.githubusercontent.com/29729545/154622068-a6f7d2a9-0ffb-4b37-b69a-55d1de93b231.png)

- Consumers nhận message parallel
- Mỗi message chỉ được process một lần duy nhất
- Consumers sẽ xóa message sau khi message đó được process

## SQS - Auto Scaling Group

![SQS - Auto Scaling Group](https://user-images.githubusercontent.com/29729545/154786325-cbaaefd6-f118-494a-add9-b1e23ecafdd8.png)

## SQS - Security

- **Encryption**:
  - In-flight encryption bằng cách sử dụng HTTPS
  - Sử dụng KMS keys
  - Client-side encryption
- **Access Controls**: sử dụng IAM policies
- **SQS Access Policies** (tương tự như S3 bucket policies)
