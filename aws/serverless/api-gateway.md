---
title: "Giới thiệu API Gateway"
description: "API Gateway đóng vai trò là cửa trước cho các ứng dụng để truy cập dữ liệu, logic nghiệp vụ hoặc chức năng từ các dịch vụ backend của bạn"
keywords:
  [
    "API Gateway la gi",
    "API Gateway là gì",
    "API Gateway trong aws",
    "API Gateway Throttling la gi",
    "API Gateway Throttling là gì",
    "API Gateway Throttling trong aws",
    "API Gateway Endpoint Types la gi",
    "API Gateway Endpoint Types là gì",
    "API Gateway Endpoint Types trong aws",
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
  name: "Serverless"
  slug: "serverless"
position: 195
---

## API Gateway là gì

- API Gateway là dịch vụ tiếp nhận và xử lý các lời gọi API
- API Gateway đóng vai trò "cửa trước" cho các ứng dụng để truy cập dữ liệu, logic phía backend của bạn
- Hỗ trợ WebSocket Protocol
- Xử lý về security (Authentication, Authorization)
- Cache API response
- Dễ dàng quản lý rate limit, throttle...
- Transform và validate requests, responses
- **Timeout: tối đa 30s**
- Có thể gọi đến nhiều dịch vụ backend như:
  - Lambda function:
  - HTTP endpoint
  - AWS services

![API Gateway là gì](https://d1.awsstatic.com/serverless/New-API-GW-Diagram.c9fc9835d2a9aa00ef90d0ddc4c6402a2536de0d.png)

## API Gateway Throttle

Để tránh việc API bị quá tải và lạm dụng do quá nhiều request(tốn nhiều tiền), Amazon API Gateway cho phép thắt cổ chai (Throttle)

- **Rate**: số request nhận tối đa trên 1 giây (1s)
- **Burst**: Số request tối đa được xử lý tại một thời điểm

Khi số lượng request vượt quá Rate hoặc Burst hệ thống sẽ trả về lỗi: _429 - Too many Requests._

## API Gateway Endpoint Types

AWS cung cấp 3 cách để deploy API Gateway của bạn:

- **Edge-Optimized (default)**: dùng cho global client
  - Request được routed qua các CloudFront Edge location
  - API Gateway vẫn tồn tại ở một region nhất định
- **Regional**:
  - Cho các client ở chung một region
  - Cũng có thể tích hợp với CloudFront để giải quyết vấn đề về caching
- **Private**:
  - Chỉ có thể truy cập từ VPC của bạn qua VPC Endpoint (ENI)
  - Sử dụng Resource Policy để xác định quyền truy cập
