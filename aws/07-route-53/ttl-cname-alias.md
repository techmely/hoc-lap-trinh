---
title: "Giới thiệu TTL, CNAME và Alias"
description: "TTL là viết tắt của Time to Live, là khái niệm được sử dụng trong DNS caching, hay CDN caching. Giá trị TTL thường được tính bằng giây. Theo đó, TTL càng lớn thì máy chủ DNS sẽ ghi nhớ thông tin trong thời gian càng lâu. Điều này đồng nghĩa với việc khi thay đổi tên miền website trên DNS chính thì thời gian cập nhật thông tin trên máy chủ DNS trung gian sẽ bị chậm đi."
keywords:
  [
    "TTL la gi",
    "TTL trong Route 53",
    "TTL là gì",
    "TTL trong Route 53",
    "CNAME trong Route 53",
    "Dinh tuyen trong Route 53",
    "Đăng ký tên miền Route 53",
    "Dang ky ten mien Route 53",
    "Ten mien trong Route 53",
  ]
author:
  fullname: Phan Văn Đức
  username: ducpv
  avatar: "/configs/author/ducpv.jpg"
category:
  name: "Khóa học AWS từ cơ bản đến nâng cao"
  slug: "aws"
chapter:
  name: "Route 53"
  slug: "route-53"
position: 62
---

## TTL là gì

TTL là viết tắt của Time to Live, là khái niệm được sử dụng trong DNS caching, hay CDN caching. Giá trị TTL thường được tính bằng giây. Theo đó, TTL càng lớn thì máy chủ DNS sẽ ghi nhớ thông tin trong thời gian càng lâu. Điều này đồng nghĩa với việc khi thay đổi tên miền website trên DNS chính thì thời gian cập nhật thông tin trên máy chủ DNS trung gian sẽ bị chậm đi.

## CNAME với Alias

Có những dịch vụ trong Amazon được expose một AWS hostname (chẳng hạn như: Load Balancer, CloudFront, S3 Static Website...). Bạn muốn URL của S3 website được thân thiện hơn như _app1.sample.com_, chúng ta có thể sử dụng CNAME hoặc Alias trong Route 53.

**CNAME:**

- Trỏ từ hostname này sang hostname khác
- **Chỉ sử dụng cho NON-ROOT-DOMAIN** (aa1.sample.com)

**Alias**

- Sử dụng để trỏ từ hostname đến một AWS Resources (aa1.sample.com => aaa.amazon.com)
- Sử dung cho **ROOT-DOMAIN**(sample.com) và **NON-ROOT-DOMAIN**(app.sample.com)
- Alias record luôn là kiểu A/AAAA
- **Không thể set TTL** **Alias record target**
- Elastic Load Balancer
- Cloudfront
- API Gateway
- S3 website
- Elastic Beanstalk environment
- VPC Interface Endpoints
- Global Accelerator
- Route 53 record trong cùng hosted zone **Không thể set Alias cho EC2 DNS name**
