---
title: "Giới thiệu Read Replicas"
description: "Read replicas giúp bạn scaling việc read. Read replicas cho phép bạn tạo 1 hoặc nhiều bản copies của DB instance trong chung region hoặc khác region"
keywords: ["Read replicas la gi", "RDS multi AZ la gi"]
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
position: 21
---

## RDS Read Replicas vs Multiple AZ

### Read Replicas

![Read](https://cacoo.com/diagrams/2XNdewVsgellO3x8-1506D.png)

Read replicas giúp bạn scaling việc read. Read replicas cho phép bạn tạo 1 hoặc nhiều bản copies của DB instance trong chung region hoặc khác region. Handle việc bạn có 1 RDS database phải tiếp nhận nhiều request,RDS instance sẽ **ASYNC replicated** các bản sao khác

- Up to 5 Read Replicas, mỗi Read Replicas có 1 DNS enpoind khác nhau.
- Cross AZ, hoặc cross Region
- Read Replicas có thể promotes thành own DB
- Application cần thay đổi connection string để connect được read replicas

**Use case**

- Business reporting hoặc data warehouse, chúng ta sẽ tạo ra bản sao từ DB production, sau đó thực hiện query để analy **Cost**
- Nếu trong cùng 1 region thì giá sẽ free
- Nếu cross AZ ở khác region thì AWS sẽ tính phí của bạn

### RDS Multi AZ (Disaster Recovery)

![](https://miro.medium.com/max/1200/1*Tpg2Xo1fIMX-Cz5tzeOZ1g.png) RDS Multi AZ cung cấp khả năng sẵn sàng cho DB của bạn trong 1 Region. Dữ liệu sẽ được **SYNC replicated** tới các standby insatnce ở AZ khác

Ví dụ: DB instance chính của bạn ở AZs ap-northeast-1a, standby insatnce ở ap-northeast-1d

NOTES:

- SYNC replication
- Sử dụng chung 1 DNS endpoint
- Không sử dụng cho scaling
- Read Replicas có thể setup như là Multi AZ cho Disaster Recovery

### RDS From single AZ to Multi AZ

![](https://miro.medium.com/max/668/1*ewojRDRfLgZW7loOtSR0TQ.png)

- Zero downtime
- Chỉ cần click "modify"
- Các hoạt động:
  - Tạo 1 snapshot
  - DB mới được restored từ snapshot sang AZ mới
  - Synchronyze giữa 2 DB
