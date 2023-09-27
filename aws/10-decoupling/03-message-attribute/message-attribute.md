---
title: "Những thuộc tính của SQS Queue"
description: "Amazon Simple Queue Service (SQS) là một dịch vụ hàng đợi (queue) lưu trữ message nhanh chóng, đáng tin cậy, có khả năng mở rộng và quản lý một cách đầy đủ. Với SQS, bạn có thể gửi, nhận và lưu trữ message giữa các thành phần trong một phần mềm."
chapter:
  name: "Decoupling trong AWS"
  slug: "chap-10-decoupling"
image: https://user-images.githubusercontent.com/29729545/154991548-4f808264-b07b-418f-8c4e-0d5bd7c623eb.png
position: 173
---

## SQS Message Visibility Timeout là gì

- Một message sau khi được polled bởi một consumer, nó trở nên **invisible** với các consumers khác.
- Đó gọi là "Message Visibility Timeout", mặc định là 30 giây (có thể chỉnh sửa)
- Sau thời gian timeout đó, message quay trở lại **visible**

![Message Visibility Timeout](https://user-images.githubusercontent.com/29729545/154991548-4f808264-b07b-418f-8c4e-0d5bd7c623eb.png)

## SQS Dead Letter Queue là gì

- Mỗi message sẽ có một "Visibility Timeout" sau khi được polled, trong thời gian đó, message được process. Tại đây, sẽ có hai trường hợp xảy ra:
  - Message được process thành công: => Xóa message ra khỏi queue
  - Message process thất bại: => Message sẽ quay trở lại Queue và nằm chờ ở đó
- Như vậy sẽ có trường hợp vòng lặp vô tận khi:
  - Message process bị lỗi => Quay trở lại Queue => Process lại message...
- Chúng ta có thể config "MaximumReceives", hiểu đơn giản là số lần message sau khi process và vẫn quay trở lại Queue. Nếu vượt quá "MaximumReceives", message bị lỗi đó sẽ tự động gửi đến một Queue khác là **Dead Letter Queue (DLQ)**

![Dead Letter Queue](https://user-images.githubusercontent.com/29729545/154995256-cb892923-6a89-43ea-9e47-9eb901c66aed.png)

## SQS Delay Queue là gì

- Mặc định thời gian delay là 0s (message được nhận ngay lập tức)
- Chúng ta có thể config thời gian delay để nhận được message (tối đa là 15 phút)

## SQS Long Polling là gì

- Mục đích của Long Polling là giảm thiểu những response empty từ phía Queue
- Khi có một request nhận message, nếu trong Queue không có message nào, SQS sẽ chờ đến khi có message để response lại
- **WaitTimeSeconds** có thể từ 1s-20s

## SQS Request-Response Pattern (Virtual queues) là gì

- Đây là pattern mà Requester và Responser giao tiếp với nhau bẳng message qua một Virtual Queue
- Để có thể implement pattern này cần sử dụng: **SQS Temporary Queue Client**

![SQS Request-Response Pattern](https://d2908q01vomqb2.cloudfront.net/1b6453892473a467d07372d45eb05abc2031647a/2019/07/26/Selection_015.png)

## SQS FIFO Queue là gì

- FIFO = Firt In Firt Out (Message đến đầu tiên được đọc đầu tiên)
- Ordering message theo GroupID
