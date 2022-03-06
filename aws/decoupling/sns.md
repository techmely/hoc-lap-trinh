---
title: "Giới thiệu SNS"
description: "Amazon SNS là một dịch vụ cho phép bạn gửi tin nhắn (SMS), thông báo (notification) số lượng lớn tới các thiết bị đầu cuối hay các client thông qua một topic. Các thiết bị đầu cuối (hay client) có thể là một web server (HTTP/S), email, Amazon SQS hay AWS Lambda."
keywords:
  [
    "Amazon SNS là gì",
    "AWS SNS la gi",
    "Endpoint trong SNS",
    "Endpoint SNS",
    "Queue Access Policy",
    "SNS subscription là gì",
    "SNS subscription la gi",
    "SQS Dead Letter Queue là gì",
    "SQS Dead Letter Queue la gi",
    "SQS Delay Queue là gì",
    "SQS Delay Queue la gi",
    "SQS Long Polling là gì",
    "SQS Long Polling la gi",
    "SQS Request-Response Pattern là gì",
    "SQS Request-Response Pattern la gi",
  ]
author:
  fullname: Phan Văn Đức
  username: ducpv
  avatar: "/configs/author/ducpv.jpg"
category:
  name: "Khóa học AWS từ cơ bản đến nâng cao"
  slug: "cloud"
  description: "Mang kiến thức AWS đến với mọi lập trình viên"
chapter:
  name: "Decoupling trong AWS"
  slug: "decoupling"
position: 174
---

## Giới thiệu về SNS

- Amazon SNS(Simple Notification Service) là một dịch vụ cho phép bạn gửi tin nhắn (SMS), và thông báo với số lượng lớn tới các endpoint hay các client thông qua một topic.
- Các endpoint, subscription (hay client) có thể là:
  - SQS
  - HTTP/HTTPS
  - Lambda
  - Emails
  - SMS message
  - Mobile notifications

Chẳng hạn mình muốn gửi mail cho lớp cấp 3 mình mỗi khi 20/11 để nhắn các bạn đi họp lớp. Khi đó có thể hiểu Topic là "Họp lớp 20/11", Endpoint (subscription) là email của thành viên trong lớp, Message có thể là "Họp lớp 20/11 đi nhé". Khi đó message sẽ được gửi đến mail của tất cả thành viên trong lớp.

![Giới thiệu về SNS](https://d1.awsstatic.com/product-marketing/SNS/Product-Page-Diagram_Amazon-SNS_2-SMS-How-it-works%401.5x.4c649e5fe667e525de01e8c88024d782d8a25ccf.png)
