---
title: "Giới thiệu SNS"
description: "Amazon SNS là một dịch vụ cho phép bạn gửi tin nhắn (SMS), thông báo (notification) số lượng lớn tới các thiết bị đầu cuối hay các client thông qua một topic. Các thiết bị đầu cuối (hay client) có thể là một web server (HTTP/S), email, Amazon SQS hay AWS Lambda."
keywords:
  [
    "Amazon SNS là gì",
    "AWS SNS la gi",
    "Endpoint trong SNS",
    "Endpoint SNS"
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
  slug: "chap-10-decoupling"
image: https://user-images.githubusercontent.com/29729545/170851047-cbba6e41-e5da-44ed-b801-f3ce6885492e.png
position: 174
---

## Amazon SNS là gì

- Amazon SNS(Simple Notification Service) là một dịch vụ cho phép bạn gửi tin nhắn (SMS), và thông báo với số lượng lớn tới các endpoint hay các client thông qua một topic.
- Các endpoint, subscription (hay client) có thể là:
  - SQS
  - HTTP/HTTPS
  - Lambda
  - Emails
  - SMS message
  - Mobile notifications

Chẳng hạn mình muốn gửi mail cho lớp cấp 3 mình mỗi khi 20/11 để nhắn các bạn đi họp lớp. Khi đó có thể hiểu Topic là "Họp lớp 20/11", Endpoint (subscription) là email của thành viên trong lớp, Message có thể là "Họp lớp 20/11 đi nhé". Khi đó message sẽ được gửi đến mail của tất cả thành viên trong lớp.

![Giới thiệu về SNS](https://user-images.githubusercontent.com/29729545/170851047-cbba6e41-e5da-44ed-b801-f3ce6885492e.png)
