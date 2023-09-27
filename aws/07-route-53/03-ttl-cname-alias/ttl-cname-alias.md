---
title: "Giới thiệu TTL, CNAME và Alias"
description: "TTL là viết tắt của Time to Live, là khái niệm được sử dụng trong DNS caching, hay CDN caching. Giá trị TTL thường được tính bằng giây. Theo đó, TTL càng lớn thì máy chủ DNS sẽ ghi nhớ thông tin trong thời gian càng lâu. Điều này đồng nghĩa với việc khi thay đổi tên miền website trên DNS chính thì thời gian cập nhật thông tin trên máy chủ DNS trung gian sẽ bị chậm đi."
chapter:
  name: "Route 53"
  slug: "chap-07-route-53"
image: https://user-images.githubusercontent.com/29729545/168469715-9e9dc7ee-d839-4e1d-9abd-66636ce1e399.png
position: 62
---

## TTL là gì

![TTL là gì](https://user-images.githubusercontent.com/29729545/168469715-9e9dc7ee-d839-4e1d-9abd-66636ce1e399.png)
TTL là viết tắt của Time to Live, là khái niệm được sử dụng trong DNS caching, hay CDN caching. Giá trị TTL thường được tính bằng giây. Theo đó, TTL càng lớn thì máy chủ DNS sẽ ghi nhớ thông tin trong thời gian càng lâu. Điều này đồng nghĩa với việc khi thay đổi tên miền website trên DNS chính thì thời gian cập nhật thông tin trên máy chủ DNS trung gian sẽ bị chậm đi.

## CNAME và Alias trong route 53

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
