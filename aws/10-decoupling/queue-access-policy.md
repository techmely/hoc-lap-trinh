---
title: "Access Policy trong SQS Queue"
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
    "Queue Access Policy",
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
position: 172
---

## Cross Account Access

![Cross Account Access](https://user-images.githubusercontent.com/29729545/154985076-c1e7036c-2d22-40e7-8ab3-2498892ae77a.png)

Khi Account 2 muốn lấy message từ SQS của Account 1 thì cần config Policy như sau:

```json
{
  "Version": "2012-10-17",
  "Statement": [
    {
      "Sid": "Queue1_AllActions",
      "Effect": "Allow",
      "Principal": {
        "AWS": ["222222222222"]
      },
      "Action": "sqs:ReceiveMessage",
      "Resource": "arn:aws:sqs:us-east-1:111111111111"
    }
  ]
}
```

## Publish S3 Event Notifications

![Publish S3 Event Notifications](https://user-images.githubusercontent.com/29729545/154986346-ece71484-b90d-438c-bb01-edc8309052b7.png)

```json
{
  "Version": "2012-10-17",
  "Statement": [
    {
      "Sid": "example-statement-ID",
      "Effect": "Allow",
      "Principal": {
        "AWS": "*"
      },
      "Action": ["SQS:SendMessage"],
      "Resource": "arn:aws:sqs:<region>:<account-id></account-id>:queue1",
      "Condition": {
        "ArnLike": {
          "aws:SourceArn": "arn:aws:s3:*:*:bucket1"
        },
        "StringEquals": {
          "aws:SourceAccount": "<bucket-owner-account-id>"
        }
      }
    }
  ]
}
```
