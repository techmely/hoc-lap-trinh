---
title: "Gới thiệu Amazon Aurora"
description: "Aurora là công nghệ AWS phát triển được tương thích với MySQL và PostgreSQL"
keywords: ["Amazon Aurora trong AWS", "Amazon Aurora la gi"]
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
position: 22
---

## Amazon Aurora là gì

Là công nghệ AWS phát triển được tương thích với MySQL và PostgreSQL

- Cả Postgres và MySQL đều được support bởi Aurora DB (Có nghĩa là driver vẫn hoạt động nếu Aurora là Postgres hay MySQL database)
- Aurora là "AWS Cloud optimized", được cho rằng x5 performance so với MySQL trên RDS, x3 Postgres
- Aurora tự động scal storage, bạn không cần phải lo nghĩ đến việc monitor storage
- Aurora có 15 replicas (MySQL có 5)
- Cost cao hơn RDS ~20%

### Aurora High Availability và Read Scaling

![](https://docs.aws.amazon.com/zh_tw/AmazonRDS/latest/AuroraUserGuide/images/AuroraArch001.png)

- 6 bản copies dữ liệu của bạn cross 3 AZ
- 1 Aurora instance take write (master)
- Tự động phục hội < 30s nếu master bị lỗi hay có vấn đề
- Master + upto 15 replicas (for read)
- Hỗ trợ cross Region

### Aurora DB Cluster

![](https://miro.medium.com/max/1100/1*2_cCgfIV0fuBIDSNTcMmQg.png) Như hình vẽ:

- Cluster volume là 1 "Shared storage volume" có thể expand từ 10G => 64TB
- Cluster endpoint (Writer enpoint) point đến master
- Read enpoint point đến connection Load Balancing các Replicas

### Aurora security

Tương tự với RDS

### Aurora advanced concepts

#### Aurora Replicas - Auto scaling

![](https://image.slidesharecdn.com/trainingaws-module8-rdsauroraelasticache-210907145521/95/training-aws-module-8-rds-aurora-elasticache-21-638.jpg?cb=1631026831)

Khi có nhiều request đến Reader Endpoint dẫm đến việc DB instance tăng CPU usage, do đó cần setup Replicas Auto Scaling. Read Endpoint cũng sẽ tự động extend để cover Replicas mới

#### Aurora Replicas - Custom Endpoint

![](https://www.icode9.com/i/l/?n=20&i=blog/364241/202108/364241-20210802210955333-624922716.png)

Ví dụ như trên hình vẽ, chúng ta có thể tạo ra 2 Custom Endpoint cho DB.rc3 và DB.rc5. Khi request cần cấu hình cao sẽ dùng endpoint của DB.rc5 nếu thấp hơn thì sẽ dùng endpoint của DB.rc3.

#### Aurora Replicas - Serverless

- Tự động scaling dự trên lượng sử dụng thực tế
- Phù hợp với ứng dụng không thường xuyên, hoặc không biết trước được workload
- Không cần có plan về capacity
- Giá cả trả theo giây sử dụng

#### Aurora Replicas - Multi-Master

- Trong trường hợp bạn muốn ngay lập tức chuyển đổi dự phòng (failover) cho writer node (HA)
- Các Read Replicas tự động promote lên Master

#### Global Aurora

![](https://docs.aws.amazon.com/AmazonRDS/latest/AuroraUserGuide/images/aurora-global-databases-conceptual-illo.png)

- **Aurora Cross Region Read Replicas**
  - Hữu ích cho Disaster Recovery (DR)
- Aurora Global Database
  - 1 primary Region (read/write)
  - Up to 5 secondary (**read-only**) region, replication lag < 1s
  - Up to 16 Read Replicas/ mỗi secondary region
  - Giảm thiểu độ trễ
  - Khi có vấn đề ở Primary region, tự động promote region khác với RTO < 1minutes (Recovery Time Objective)
