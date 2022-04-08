---
title: "Giới thiệu Glue"
description: "AWS Glue là gì. AWS Glue là dịch vụ tích hợp dữ liệu server-less, giúp người dùng dễ dàng tìm kiếm, chuẩn bị và tổng hợp dữ liệu cho hoạt động phân tích, máy học và phát triển ứng dụng. "
keywords:
  [
    "AWS Glue la gi",
    "AWS Glue là gì",
    "Glue trong AWS",
    "AWS Glue Data Catalog la gi",
    "AWS Glue Data Catalog là gì",
    "Glue Data Catalog trong AWS",
    "ETL la gi",
    "ETL là gì",
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
position: 25
---

## AWS Glue là gì

- Là dịch vụ Serverless giúp quản lý: **Extract, Transform và Load (ETL)** dữ liệu. Hữu ích với việc chuẩn bị, transform dữ liệu phục vụ cho analytics

![AWS Glue là gì](https://user-images.githubusercontent.com/29729545/156197109-261efa39-6875-49b0-8817-937244765d9d.png)

## Glue Data Catalog

- Glue Data Catalog là nơi lưu trữ metadata của data nguồn
- Ví dụ bạn muốn transform dữ liều từ Amazon RDS:
  - Step 1: Crawler sẽ thực hiện crawl dữ liệu của Database trên RDS, crawler sẽ lấy được dữ liệu như (schema, định nghĩa của table, các table...)
  - Sau khi crawl, thông tin metadata sẽ được lưu vào Data Catalog theo dạng bảng
  - Dữ liệu trên Catalog này sẽ được sử dụng bởi: Glue Jobs (ETL), hay Amazon Athena...

![Glue Data Catalog](https://user-images.githubusercontent.com/29729545/156202343-764934a2-ed83-470a-ac2e-1e8822e34cb8.png)
