---
title: "Giới thiệu S3 Event Notifications, Requester Pays"
description: "Amazon S3 Event Notifications là tính năng nhận thông báo khi có event nhất định trên S3 bucket. Với Requester Pays buckets , người request, download sẽ trả tiền cho Network transfer data"
keywords:
  [
    "S3 Event Notifications la gi",
    "S3 Event Notifications là gì",
    "S3 Requester Pays la gi",
    "S3 Requester Pays là gì",
    "S3 Event Notifications trong S3",
    "S3 Requester Pays trong S3"
  ]
author:
  fullname: Phan Văn Đức
  username: ducpv
  avatar: "/configs/author/ducpv.jpg"
category:
  name: "Khóa học AWS từ cơ bản đến nâng cao"
  slug: "aws"
chapter:
  name: "Simple Storage Serivce"
  slug: "s3"
position: 60
---

## S3 Event Notifications là gì

Amazon S3 Event Notifications là tính năng nhận thông báo khi có event nhất định trên S3 bucket. Amazon S3 có thể publish cho nhiều events như: S3:ObjectCreated, S3:ObjectRemoved, S3:Replication...

- Amazon S3 có thể gửi message đến những target sau đây:
  - Amazon SNS
  - Amazon SQS
  - Amazon Lambda function

![S3 Event Notifications](https://user-images.githubusercontent.com/29729545/151324830-92d2db09-c437-4e21-a732-865bab8a9466.png)

## Gới thiệu Requester Pays

- Mặc định Amazon S3 sẽ tính tiền sử dụng dịch vụ lưu trữ cho owner của bucket
- Với **Requester Pays buckets** , người request, download sẽ trả tiền cho Network transfer data
- Người tạo request (requester) phải được định danh (authenticated) trong AWS

![Requester Pays](https://user-images.githubusercontent.com/29729545/151326716-7681bab7-d7c2-4c5e-afdf-aeb5d66abd01.png)
