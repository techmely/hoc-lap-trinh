---
title: "Giới thiệu Serverless"
description: "Serverless là môi trường, nền tảng thực thi ứng dụng và dịch vụ mà không phải quan tâm đến máy chủ. Ứng dụng serverless không cần phải quan tâm việc phân bổ, quản lý tài nguyên của hệ điều hành, và bỏ qua các vấn đề về nâng cấp và bảo mật. Với khái niệm là chỉ cần tập trung phát triển sản phẩm, việc còn lại về vận hành sẽ để nền tảng này đảm nhiệm."
keywords:
  [
    "Serverless là gì",
    "Serverless la gi",
    "Serverless trong AWS",
    "Serverless lambda là gì",
    "Serverless lambda la gi",
    "Serverless lambda trong AWS",
    "Lambda function là gì",
    "Lambda function la gi",
    "Lambda function trong AWS",
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
position: 191
---

## Serverless là gì

Serverless là môi trường, nền tảng thực thi ứng dụng và dịch vụ mà không phải quan tâm đến máy chủ. Ứng dụng serverless không cần phải quan tâm việc phân bổ, quản lý tài nguyên của hệ điều hành, và bỏ qua các vấn đề về nâng cấp và bảo mật. Với khái niệm là chỉ cần tập trung phát triển sản phẩm, việc còn lại về vận hành sẽ để nền tảng này đảm nhiệm.

Điều quan trọng và khác biệt nhất trong serverless là bạn **chỉ trả tiền khi và chỉ những phần bạn sử dụng**. Giả sử bạn có một máy chủ ảo, thì thường sẽ được tính tiền trọn gói bao gồm thời gian chạy 24/7 trong 1 tháng, CPU và RAM, băng thông, lưu trữ. Bạn vẫn sẽ phải trả tiền hàng tháng đều đặn cho dù cái máy chủ ảo đó không chạy, hoặc chỉ sử dụng 5~10% công suất thì bạn vẫn phải trả trọn gói. Hiểu một cách nôm na, thì serverless như gói cước điện thoại được tính theo block giây, gọi bao nhiêu tính tiền bấy nhiêu, còn máy chủ ảo thường thì phải trả tiền thuê bao hàng tháng dù có phải sử dụng hay không.

## Serverless trong AWS

Amazon cung cấp những dịch sụ serverless sau đây:

- AWS Lambda
- DynamoDB
- AWS Cognito
- AWS API Gateway
- Amazon S3
- AWS SNS, SQS
- AWS Kinesis Data Firehost
- Aurora Serverless
- Step Function
- Fargate

Hiện nay có rất nhiều nhà cung cấp dịch vụ giúp bạn tạo ra các functions sử dụng mô hình serverless một cách khá dễ dàng:

- Google Cloud Function: hiện tại chỉ hỗ trợ Nodejs
- Azure Functions: cung cấp bởi Microsoft, hỗ trợ C#, JavaScript, F#, Python, Batch, PHP, PowerShell
