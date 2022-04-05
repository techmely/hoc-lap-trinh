---
title: "Những thuộc tính của SQS Queue"
description: "Amazon Simple Queue Service (SQS) là một dịch vụ hàng đợi (queue) lưu trữ message nhanh chóng, đáng tin cậy, có khả năng mở rộng và quản lý một cách đầy đủ. Với SQS, bạn có thể gửi, nhận và lưu trữ message giữa các thành phần trong một phần mềm."
keywords:
  [
    "Amazon SQS là gì",
    "AWS SQS la gi",
    "Producing message trong SQS",
    "Consuming message trong SQS",
    "Queue Access Policy",
    "SQS Message Visibility Timeout là gì",
    "SQS Message Visibility Timeout la gi",
    "SQS Dead Letter Queue là gì",
    "SQS Dead Letter Queue la gi",
    "SQS Delay Queue là gì",
    "SQS Delay Queue la gi",
    "SQS Long Polling là gì",
    "SQS Long Polling la gi",
    "SQS Request-Response Pattern là gì",
    "SQS Request-Response Pattern la gi",
    "SQS FIFO Queue là gì",
    "SQS FIFO Queue la gi",
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
position: 173
---

## SQS Message Visibility Timeout

- Một message sau khi được polled bởi một consumer, nó trở nên **invisible** với các consumers khác.
- Đó gọi là "Message Visibility Timeout", mặc định là 30 giây (có thể chỉnh sửa)
- Sau thời gian timeout đó, message quay trở lại **visible**

![Message Visibility Timeout](https://user-images.githubusercontent.com/29729545/154991548-4f808264-b07b-418f-8c4e-0d5bd7c623eb.png)

## SQS Dead Letter Queue

- Mỗi message sẽ có một "Visibility Timeout" sau khi được polled, trong thời gian đó, message được process. Tại đây, sẽ có hai trường hợp xảy ra:
  - Message được process thành công: => Xóa message ra khỏi queue
  - Message process thất bại: => Message sẽ quay trở lại Queue và nằm chờ ở đó
- Như vậy sẽ có trường hợp vòng lặp vô tận khi:
  - Message process bị lỗi => Quay trở lại Queue => Process lại message...
- Chúng ta có thể config "MaximumReceives", hiểu đơn giản là số lần message sau khi process và vẫn quay trở lại Queue. Nếu vượt quá "MaximumReceives", message bị lỗi đó sẽ tự động gửi đến một Queue khác là **Dead Letter Queue (DLQ)**

![Dead Letter Queue](https://user-images.githubusercontent.com/29729545/154995256-cb892923-6a89-43ea-9e47-9eb901c66aed.png)

## SQS Delay Queue

- Mặc định thời gian delay là 0s (message được nhận ngay lập tức)
- Chúng ta có thể config thời gian delay để nhận được message (tối đa là 15 phút)

## SQS Long Polling

- Mục đích của Long Polling là giảm thiểu những response empty từ phía Queue
- Khi có một request nhận message, nếu trong Queue không có message nào, SQS sẽ chờ đến khi có message để response lại
- **WaitTimeSeconds** có thể từ 1s-20s

## SQS Request-Response Pattern (Virtual queues)

- Đây là pattern mà Requester và Responser giao tiếp với nhau bẳng message qua một Virtual Queue
- Để có thể implement pattern này cần sử dụng: **SQS Temporary Queue Client**

![SQS Request-Response Pattern](https://d2908q01vomqb2.cloudfront.net/1b6453892473a467d07372d45eb05abc2031647a/2019/07/26/Selection_015.png)

## SQS FIFO Queue

- FIFO = Firt In Firt Out (Message đến đầu tiên được đọc đầu tiên)
- Ordering message theo GroupID
