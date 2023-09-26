---
title: "Giới thiệu CloudHSM, Shield và WAF"
description: "AWS CloudHSM là một module bảo mật phần cứng dựa trên đám mây (HSM) cho phép bạn dễ dàng tạo và sử dụng các khóa mã hóa của riêng bạn trên AWS."
author:
  fullname: Phan Văn Đức
  username: ducpv
  avatar: "/configs/author/ducpv.jpg"
category:
  name: "Khóa học AWS từ cơ bản đến nâng cao"
  slug: "aws"
chapter:
  name: "Security & Encryption"
  slug: "chap-13-security"
image: https://user-images.githubusercontent.com/29729545/172041759-334616af-83bc-4660-99e7-6e6d18c086cd.png
position: 242
---

## AWS CloudHSM là gì

![AWS CloudHSM là gì](https://user-images.githubusercontent.com/29729545/172041759-334616af-83bc-4660-99e7-6e6d18c086cd.png)

- KMS: AWS quản lý phần mềm cho encryption
- Cloud Hardware Security Module(CloudHSM): AWS cung cấp phần cứng (**hardware**) encryption
- Với CloudHSM, bạn có thể quản lý các khóa mã hóa bằng các HSM đạt chuẩn FIPS 140-2 level 3
- **Phù hợp với SSE-C encryption**

## Tấn công DDoS là gì

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
  - Size contraints (Ví dụ giới hạn size query string < 5MB)
  - Geo-match (block contries)
  - **Rate-based rules** - dùng cho ngăn ngừa tấn công DDoS. Ví dụ bạn có thể config để mỗi IP chỉ được gửi lên 5 request mỗi giây (request/s)
