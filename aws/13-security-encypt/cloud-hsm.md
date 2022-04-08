---
title: "Giới thiệu CloudHSM, Shield và WAF"
description: "AWS CloudHSM là một module bảo mật phần cứng dựa trên đám mây (HSM) cho phép bạn dễ dàng tạo và sử dụng các khóa mã hóa của riêng bạn trên AWS."
keywords:
  [
    "CloudHSM la gi",
    "CloudHSM là gì",
    "CloudHSM trong aws",
    "AWS Shield la gi",
    "AWS Shield là gì",
    "Shield trong aws",
    "DDoS la gi",
    "DDoS là gì",
    "AWS WAF la gi",
    "AWS WAF là gì",
    "WAF trong aws",
  ]
author:
  fullname: Phan Văn Đức
  username: ducpv
  avatar: "/configs/author/ducpv.jpg"
category:
  name: "Khóa học AWS từ cơ bản đến nâng cao"
  slug: "aws"
chapter:
  name: "Security & Encryption"
  slug: "security"
position: 242
---

## Cloud Hardware Security Module (CloudHSM) là gì

- KMS: AWS quản lý phần mềm cho encryption
- CloudHSM: AWS cung cấp phần cứng (**hardware**) encryption
- Với CloudHSM, bạn có thể quản lý các khóa mã hóa bằng các HSM đạt chuẩn FIPS 140-2 level 3
- **Phù hợp với SSE-C encryption**

## DDoS là gì

Distributed Denial of Service (DDoS) là hình thức tấn công vào hệ thống của bạn. Hacker dùng DDoS sẽ gửi rất nhiều request đến server của bạn cùng một lúc (ví dụ hàng triệu request). Khi request gửi lên quá nhiều, server của bạn trở nên quá tải và không thể tiếp nhận những request khác, và hệ thống của bạn không thể hoạt động bình thường như mong muốn.

## AWS Shield là gì

AWS Shield là dịch vụ chống lại các cuộc tấn công bằng DDoS.

- **AWS Shield Standard**
  - Là dịch vụ miễn phí cho người dùng
- **AWS Shield Advanced**
  - Option có tính phí (3$/tháng)
  - Phát hiện tấn công qua Health-check
  - Hỗ trợ 24/7 bởi AWS Shield Response Team (SRT)

## AWS WAF là gì

- Web Application Firewall (WAF) giúp bảo vệ website của bạn bởi các cuộc tấn công (Layer 7: HTTP)
- WAF được deploy trên **Application Load Balancer, API Gateway, CloudFront**
- Web ACL (Web Access Control List)
  - Giới hạn IP không được phép truy cập vào website của bạn
  - Bảo vệ bởi tấn công SQL Injection, Cross-Site Scripting (XSS)
  - Size contraints (Ví dụ giới hạn size quuery string < 5MB)
  - Geo-match (block contries)
  - **Rate-based rules** - dùng cho DDoS. Ví dụ bạn có thể define mỗi IP chỉ được gửi lên 5 request/per second
