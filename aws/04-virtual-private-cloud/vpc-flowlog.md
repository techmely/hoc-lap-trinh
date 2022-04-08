---
title: "Giới thiệu VPC FLow logs"
description: "VPC FLow logs là tính năng giúp chúng ta có thể nắm bắt được thông tin IP traffic đến và đi Network Interfaces trong VPC."
keywords:
  ["VPC FLow logs trong AWS", "VPC FLow logs là gì", "VPC FLow logs la gi"]
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
position: 22
---

## VPC FLow logs là gì

- VPC FLow logs là tính năng giúp chúng ta có thể nắm bắt được thông tin IP traffic đến và đi Network Interfaces trong VPC.
  - VPC flow logs
  - Subnet flow logs
  - Elastic Network Interface (ENI) flow logs
- VPC flow logs giúp cho việc monitor các vấn đề về kết nối
- Dữ liệu của flow logs có thể ghi trên S3 hoặc CloudWatch Logs
- Có thể Query dữ liệu của VPC Flow logs sử dụng Athena hoặc CloudWatch Logs Insights

## VPC Flow Logs Syntax

![VPC Flow Logs](https://user-images.githubusercontent.com/29729545/147268701-1e638881-bee6-4e67-a529-0708c689e879.png)

```ssh
2 123456789010 eni-1235b8ca123456789 172.31.16.139 172.31.16.21 20641 22 6 20 4249 1418530010 1418530070 ACCEPT OK
```
