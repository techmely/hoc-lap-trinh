---
title: "Giới thiệu Redshift"
description: "Amazon Redshift là dịch vụ lưu trữ dữ liệu quy mô hàng petabyte nhanh và mạnh mẽ."
keywords:
  [
    "Redshift la gi",
    "Redshift là gì",
    "Redshift Redshift Spectrum la gi",
    "Redshift Redshift Spectrum là gì",
    "Redshift trong aws",
    "Redshift architecture",
    "Cluster trong Redshift",
    "Node trong Redshift",
    "Leader node trong Redshift",
    "Slice node trong Redshift",
    "Redshift - Snapshot & DR (Disaster recovery)",
  ]
author:
  fullname: Phan Văn Đức
  username: ducpv
  avatar: "/configs/author/ducpv.jpg"
category:
  name: "Khóa học AWS từ cơ bản đến nâng cao"
  slug: "aws"
chapter:
  name: "Database"
  slug: "database"
position: 24
---

## Redshift là gì

- Amazon Redshift là dịch vụ lưu trữ dữ liệu quy mô hàng petabyte nhanh và mạnh mẽ.
- Redshift được base trên PostgreSQL, tuy nhiên không được dùng trong OLTP (On-line transactional processing)
- **Redshift là OLAP** - On-line analytical processing (dùng cho analytics và data warehousing)
- Redshift tính tiền theo giờ chạy dựa trên instance mà bạn lựa chọn
- x10 về mặt performance so với các data warehouse khác
- **Lưu trữ dữ liệu dưới dạng cột (Column)**
- Hỗ trợ mạn hình SQL interface để tạo các câu query truy vấn
- **Masively Parallel Query Execution (MPP)**
- **Analytics/BI(Business intelligence)/Data Warehouse**

## Redshift architecture

![Redshift architecture](https://docs.aws.amazon.com/redshift/latest/dg/images/02-NodeRelationships.png)

- **Cluster**: Đây là thành phần cốt lỗi trong kiến trúc của Redshift. Mỗi Cluster bao gồm một hoặc nhiều nodes thực hiện việc tính toán
- Trong một Cluster sẽ có một hoặc nhiều Database
- **Leader node** xử lý giao tiếp với các layer bên ngoài, ví dụ như thực hiện query, tổng hợp kết quả
- **Compute node**: thực thi các câu truy vấn, gửi lại kết quả cho leader node
- **Node slices**: Mỗi một Compute Node tiếp tục được chia nhỏ ra thành các Node Slice. Mỗi một Node Slice sẽ được phân chia đều CPU, Memory và Storage từ Compute Node đó.
- **Redshift Spectrum**: truy vấn dữ liệu trực tiếp tới Amazon S3 mà không cần load dữ liệu vào các bảng của Redshift.
- Backup & Restore, Security VPC/IAM/KMS, Monitoring

## Redshift - Snapshot & DR (Disaster recovery)

- Redshift không có cơ chế "Multi-AZ"
- Bạn cần sử dụng snapshot để backup cluster và store trên S3
- Bạn có thể restore một snapshot ra một cluster mới
- Tạo snapshot có thể tự động hoặc bằng tay
  - Automated: bạn có thể tạo schedule tạo mỗi 8h/mỗi 5GB...
  - Manual:
- **Bạn có thể config Amazon Redshift tự động copy snapshots của một Cluster sang một Region mới**

![Redshift - Snapshot & DR (Disaster recovery)](https://user-images.githubusercontent.com/29729545/156191122-d0a4153b-6c80-4288-9106-b881acdec4cc.png)

## Redshift Spectrum

![Redshift Spectrum](https://d2908q01vomqb2.cloudfront.net/b6692ea5df920cad691c20319a6fffd7a4a766b8/2017/07/18/redshift_spectrum-1.gif)
