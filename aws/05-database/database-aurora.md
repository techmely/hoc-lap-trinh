---
title: "Gới thiệu Amazon Aurora"
description: "Aurora là công nghệ AWS phát triển được tương thích với MySQL và PostgreSQL"
author:
  fullname: Phan Văn Đức
  username: ducpv
  avatar: "/configs/author/ducpv.jpg"
category:
  name: "Khóa học AWS từ cơ bản đến nâng cao"
  slug: "aws"
chapter:
  name: "Database"
  slug: "chap-05-database"
image: https://user-images.githubusercontent.com/29729545/172041829-ff34741c-82fc-4ffd-88b6-3f98b2ef4787.png
position: 22
---

## Amazon Aurora là gì

Là công nghệ AWS phát triển được tương thích với MySQL và PostgreSQL

- Cả Postgres và MySQL đều được support bởi Aurora DB (Có nghĩa là driver vẫn hoạt động nếu Aurora là Postgres hay MySQL database)
- Aurora là "AWS Cloud optimized", được cho rằng x5 performance so với MySQL trên RDS, x3 Postgres
- Aurora tự động scale storage, bạn không cần phải lo nghĩ đến việc monitor storage
- Aurora có 15 replicas (MySQL có 5)
- Cost cao hơn RDS ~20%

### Aurora High Availability và Read Scaling

- 6 bản copies dữ liệu của bạn cross 3 AZ
- 1 Aurora instance take write (master)
- Tự động phục hội < 30s nếu master bị lỗi hay có vấn đề
- Master + upto 15 replicas (for read)
- Hỗ trợ cross Region

### Aurora DB Cluster

![Aurora DB Cluster](https://user-images.githubusercontent.com/29729545/172041829-ff34741c-82fc-4ffd-88b6-3f98b2ef4787.png) Như hình vẽ:

- Cluster volume là 1 "Shared storage volume" có thể lưu trữ dữ liệu từ 10G => 64TB
- Cluster endpoint (Writer enpoint) được trỏ đến master
- Read enpoint point đến connection Load Balancing các Replicas

### Aurora security

Tương tự với RDS

### Aurora advanced concepts

#### Aurora Replicas - Auto scaling

![Aurora Replicas - Auto scaling](https://user-images.githubusercontent.com/29729545/172041975-4329a3f0-b18a-424c-bc56-3f00a1d00791.png)

Khi có nhiều request đến Reader Endpoint dẫm đến việc DB instance tăng CPU usage, do đó cần setup Replicas Auto Scaling. Read Endpoint cũng sẽ tự động extend để cover Replicas mới

#### Aurora Replicas - Custom Endpoint

![Aurora Replicas - Custom Endpoint](https://user-images.githubusercontent.com/29729545/172041992-822ef411-f834-4987-8e93-fc7a540f67bd.png)

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

![Global Aurora](https://docs.aws.amazon.com/AmazonRDS/latest/AuroraUserGuide/images/aurora-global-databases-conceptual-illo.png)

- **Aurora Cross Region Read Replicas**
  - Hữu ích cho Disaster Recovery (DR)
- Aurora Global Database
  - 1 primary Region (read/write)
  - Up to 5 secondary (**read-only**) region, replication lag < 1s
  - Up to 16 Read Replicas/ mỗi secondary region
  - Giảm thiểu độ trễ
  - Khi có vấn đề ở Primary region, tự động promote region khác với RTO < 1minutes (Recovery Time Objective)
