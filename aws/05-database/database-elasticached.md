---
title: "Elasticache là gì"
description: "Elasticache là dịch vụ bộ nhớ đệm được quản lý dành cho Redis và Memcached"
keywords: ["Elasticache la gi", "Redis trong aws", "Memcached trong aws"]
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
position: 23
---

## Amazon ElasticCache

- Elasticache là dịch vụ bộ nhớ đệm được quản lý dành cho Redis và Memcached
- Giúp giảm thiểu thời gian load dữ liệu, vì load từ cache chắc chắn sẽ nhanh hơn ![](https://d1.awsstatic.com/Getting%20Started/Boosting%20Database%20Performance/image001.0660c8da047acc2702ca49a548d4721101f7dd38.png)

### Phân biệt Redis (Remote Dictionary Server) và Memcached

- REDIS:
  - Read Replicas để scale việc đọc, high avaiability
  - có tính năng Backup và restore
- MEMCACHED:
  - Multi-node cho việc phân vùng data, cho phép mở rộng thêm dữ liệu khi nhu cầu tăng lên
  - Memcache không có tính persis. Tức là một khi xóa là xóa hẳn, không có backup
  - Multi-thread
