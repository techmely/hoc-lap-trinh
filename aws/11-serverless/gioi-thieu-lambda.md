---
title: "Giới thiệu Lambda"
description: "AWS Lambda là một dịch vụ tính toán nơi mà bạn có thể upload code của mình lên, và AWS Lambda sẽ giúp bạn chạy đoạn code đó bằng việc sử dụng các tài nguyên sẵn có của AWS. Sau khi bạn upload code, và bạn tạo ra một Lambda function, AWS sẽ cung cấp và quản lý các server mà bạn sử dụng để chạy code."
keywords:
  [
    "Serverles la gi",
    "Serverles là gì",
    "Serverles trong aws",
    "Lambda la gi",
    "Lambda là gì",
    "Lambda trong aws",
    "Limit cua Lambda",
    "Limit của Lambda",
    "Lambda@Edge là gì",
    "Lambda@Edge la gi",
    "Lambda Edge là gì",
    "Lambda Edge la gi",
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
  name: "Serverless"
  slug: "serverless"
position: 192
---

## Lambda là gì

Hiện nay, các giải pháp serverless ngày càng trở nên phổ biến. Đây là công nghệ mà lập trình viên chỉ cần thực hiện quá trình viết code mà không cần lo lắng đến việc thiết lập server hay chạy các đoạn code đã viết. Đây được coi là lời giải cho bài toán chi phí cũng như giải pháp cho quá trình vận hành, khi lập trình viên chỉ cần tập trung vào việc hoàn thành các đoạn code.

AWS Lambda là một dịch vụ tính toán nơi mà bạn có thể upload code của mình lên, và AWS Lambda sẽ giúp bạn chạy đoạn code đó bằng việc sử dụng các tài nguyên sẵn có của AWS. Sau khi bạn upload code, và bạn tạo ra một Lambda function, AWS sẽ cung cấp và quản lý các server mà bạn sử dụng để chạy code.

- Là virtual functions (không cần quản lý server)
- Giới hạn thời gian execute (short execute)
- Run on-demand
- Scaling tự động

## Lợi ích của Lambda

- Chi phí rẻ
  - Trả tiền theo request và compute time
  - Mỗi tháng sẽ có 1,000,000 request free và 400,000 GBs compute time (có nghĩa: nếu bạn sử dụng RAM 1GB thì bạn sẽ có free 400,000s execute)
- Dễ dàng tích hợp với những dịch vụ khác của AWS
- Hỗ trợ nhiều ngôn ngữ lập trình: Java, Javascript, Python...
- Dễ dàng scale resource trên mỗi function
- Tăng RAM sẽ cải thiện CPU và Network

## Lambda hoạt động như thế nào

Lambda có 2 phần chính: Lambda Function và Event Source

- Event Source: là nơi phát sinh ra sư kiện để gọi đến Lambda function
- Lambda Function: function thực thi code logic của bạn. Bạn chỉ cần upload source code lên, phần còn lại AWS sẽ quản lý.

## Lambda limit

- Memory allocation: 128MB - 10 GB
- Maximum timeout: 900s (15min)
- Environment variables: 4KB
- Source deployment (file .zip): tối đa 50MB
- Có thể sử dụng folder /tmp để chứa những file tạm thời

## Lambda@Edge là gì

Lambda@Edge cho phép bạn chạy các hàm của Lamda để customize nội dung mà CloudFront deliver tới người dùng, cụ thể hơn 1 chút nó cho phép chạy các function ở AWS location gần với người dùng nhất từ đó nâng cao tốc độ vận chuyển content.

Bạn có thể chạy function của Lambda để thay đổi CloudFront request và CloudFront response ở các thời điểm sau:

- Sau khi CloudFront nhận request từ viewer (viewer request)
- Trước khi CloudFront chuyển tiếp request tới origin (origin request)
- Sau khi CloudFront nhận response từ origin (origin response)
- Trước khi CloudFront chuyển tiếp response tới viewer (viewer response)

<content-note>Để có thể tạo mới một Lambda@Edge, bạn cần chon Region là us-east-1
"CloudFront blueprints are available only in the US-East-1 (N. Virginia) Region (us-east-1)."</content-note>

![Lambda@Edge là gì](https://docs.aws.amazon.com/lambda/latest/dg/images/cloudfront-events-that-trigger-lambda-functions.png)
