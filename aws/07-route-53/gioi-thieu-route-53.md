---
title: "Giới thiệu về Route 53"
description: "Amazon Route 53 là dịch vụ Domain Name System có khả năng duy trì và mở rộng cao. Route53 cung cấp cho nhà phát triển phương thức hiệu quả trong việc định tuyến cho End User với các ứng dụng Internet bằng cách dịch tên miền, chẳng hạn sample.com sang một địa chỉ IP như 10.22.3.11."
keywords:
  [
    "Route 53 la gi",
    "Route 53 trong aws",
    "Record A là gì",
    "Host Zone trong Route 53",
    "Định tuyến trong Route 53",
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
  slug: "chap-07-route-53"
position: 61
---

## Route 53 là gì

Amazon Route 53 là dịch vụ Domain Name System có khả năng duy trì và mở rộng cao. Route53 cung cấp cho nhà phát triển phương thức hiệu quả trong việc định tuyến cho End User với các ứng dụng Internet bằng cách dịch tên miền, chẳng hạn sample.com sang một địa chỉ IP như 10.22.3.11. Chúng ta có thể sử dụng sử dụng Route 53 trong 3 function chính: **Domain registration, DNS routing, Health check**.

## Route 53 - Record

Sau khi tạo được domain, chúng ta cần tạo các record để định tuyến traffic. Mỗi record bao gồm:

- Tên của domain/sub-domain
- Record types (A, AAAA..)
- Giá trị (ex: 10.2.11.3)
- Routing Policy
- TTL

## Các loại record trong Route 53

- **A**: Mapping hostname tới 1 địa chỉ IPv4
- **AAAA**: Mapping hostname tới 1 địa chỉ IPv6
- **CNAME**: Mapping hostname tới hostname khác
- **NS**: Name Servers cho Hosted Zone

## Hosted Zones

Hosted Zones là một khái niệm trong Amazon Route 53 là nơi quản lý những record, những record đó chứa thông tin định tuyến cho domain/sub-domain. Có 2 loại hosted zones:

- **Public hosted zones**: chứa các record mà bạn muốn định tuyến traffic trên internet
- **Private hosted zones**: chứa các record mà bạn muốn định tuyến traffic trong Amazon VPC. Sau khi tạo một Hosted zone sẽ thì AWS cung cấp cho bạn 4 nameserver phụ trách phân giải domain được rải đều các nơi trên thế giới.

Tại thời điểm mình viết bài viết này mỗi hosted zone bạn cần trả 0.5$/tháng.
