---
title: "Giới thiệu Amazon RDS"
description: "Relational Database Service là dịch vụ quản lý Database sử dụng SQL"
keywords:
  [
    "Relational Database Service",
    "RDS trong AWS",
    "Postgres trong AWS",
    "MySQL trong AWS",
    "MariaDB trong AWS",
    "Microsoft SQL Server trong AWS",
    "Aurora trong AWS",
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
position: 20
---

## AWS RDS là gì

- Viết tắt của Relational Database Service, là dịch vụ quản lý Database sử dụng SQL
- Types:

  - Postgres
  - MySQL
  - MariaDB
  - Microsoft SQL Server
  - Aurora (DB của AWS)

- RDS backup

  - Tự động backup: Daily full backup Transaction log được back-up bởi RDS mỗi 5' => có thể restore lại data Dữ liệu sẽ được dữ lại(retention) 7 ngày (có thể tăng lên tối đa là 35 ngày)
  - DB snapshots: Thực hiện bởi user Retention tùy ý 10 ngày, 1 tháng, 6 tháng ...

- RDS Storage Auto Scaling
  - Tự động gia tăng storage của RDS DB instance
  - Bạn có thể set **Maximum Storage Threshold**
  - Phù hợp cho ứng dụng không biết trước workload
