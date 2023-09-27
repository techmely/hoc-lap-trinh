---
title: "DMS là gì"
description: "Database Migration Service là dịch vụ migrate database một cách an toàn, tin cậy."
chapter:
  name: "Database"
  slug: "chap-05-database"
image: https://user-images.githubusercontent.com/29729545/166097186-a22dce8c-8f7b-49f4-afa2-856e2e91f269.png
position: 27
---

## DMS là gì

Database Migration Service (DMS) là dịch vụ migrate Database mạnh mẽ mà AWS cung cấp. DMS có thể migrate database trên cùng AWS, từ On-premises sang RDS.. DMS cung cấp 2 kiểu migrate là:
- Cùng Engine (Homogenous)
  Ví dụ: migrate từ MySQL -> MySQL
- Khác Engine (Hetorogeneous)
  Ví dụ: migrate từ SQL Server -> MySQL

## Components trong DMS
- Source DB: Database gốc mà bạn muốn migrate
- Target DB: Ngược lại là database đích bạn sẽ migrate tới
- Source Enpoint: Định nghĩa endpoint tới database nguồn, ví dụ như hostname, username, password của DB
- Target Endpoint: Tương tự sẽ định nghĩa một endpoint tới database đích
- Replication instance: Là một EC2 instance có nhiệm vụ thực thi các task migration
- Replication tasks: định nghĩa những rule, công việc sẽ thực hiện migration. Ví dụ như chyển đổi tên database, table...