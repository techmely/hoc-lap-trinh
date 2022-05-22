---
title: "Cloudfront là gì"
description: "Amazon CloudFront là một dạng CDN giúp tăng tốc độ tải một trang web tĩnh hoặc động đến với user của bạn. CloudFront phân phối content của bạn trên khắp mạng internet trên thế thế giới thông qua các data center được gọi là Egde location."
keywords:
  [
    "Cloudfront la gi",
    "Cloudfront là gì",
    "Cloudfront hoạt động như thế nào",
    "Cloudfront hoat dong nhu the nao",
    "Cloudfront geo restriction là gì",
    "Cloudfront giới hạn địa lý",
    "Cloudfront hoạt động",
    "Cloudfront hoat dong",
    "Giới thiệu Cloudfront Origins"
  ]
author:
  fullname: Phan Văn Đức
  username: ducpv
  avatar: "/configs/author/ducpv.jpg"
category:
  name: "Khóa học AWS từ cơ bản đến nâng cao"
  slug: "aws"
chapter:
  name: "Cloudfront, Accelerator"
  slug: "chap-08-cloud-front"
image: https://user-images.githubusercontent.com/29729545/152686502-58ce75ad-3018-4eac-842a-bb039aea1c66.png
position: 70
---

## AWS Cloudfront là gì

Amazon CloudFront là một dạng Content Delivery Network(CDN) giúp tăng tốc độ tải một trang web tĩnh hoặc động (html, css, javascript) đến với user của bạn. CloudFront phân phối content của bạn trên khắp mạng internet trên thế thế giới thông qua các data center được gọi là Egde location.

- Tăng hiệu xuất cho việc đọc data bằng cách cache lại ở Egde location
- Hiện tại có khoảng 216 Edge location trên toàn cầu
- Bảo mật tấn công DDoS với việc kết hợp với những dịch vụ khác như: AWS Shield, AWS Web Application Firewall (WAF), Route 53

![AWS Cloudfront là gì](https://images.viblo.asia/b039a4e3-ce07-4dda-8896-2220fdfcf2f0.png)

## Giới thiệu Cloudfront Origins

- S3 bucket:
  - Dùng cho cache các file tại các Edge location
  - Tăng cường bảo mật với Cloudfront **Origin Access Identity(OAI)**
  - Cloudfront có thể sử dụng như một ingress (dùng để upload file lên S3 bucket)
- Custom origin (HTTP)
  - Application Load Balancer
  - EC2 instance
  - S3 website 
  
  ![Cloudfront-S3 as an origin](https://user-images.githubusercontent.com/29729545/152686502-58ce75ad-3018-4eac-842a-bb039aea1c66.png)

## Cloudfront - Giới hạn địa lý (geo restriction)

Cloudfront _geo restriction_ giúp giới hạn truy cập thông qua Cloudfront distribution với nhứng người dùng trong một khu vực địa lý nhất định.

- Whitelist: Cho phép truy cập nếu bạn nằm trong quốc gia/khu vực trong danh sách whitelist
- Blacklist: Ngăn chặn truy cập nếu bạn nằm trong quốc gia/khu vực trong danh sách blacklist
- Use case: Dùng trong trường hợp giới hạn nội dung từng quốc gia. Ví dụ hiện nay Việt Nam đang chặn những phim 18+
