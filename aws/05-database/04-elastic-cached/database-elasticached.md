---
title: "Elasticache là gì"
description: "Elasticache là dịch vụ bộ nhớ đệm được quản lý dành cho Redis và Memcached"
chapter:
  name: "Database"
  slug: "chap-05-database"
image: https://user-images.githubusercontent.com/29729545/166097048-404380f8-ed8a-4f61-9698-0b59720cd83e.png
position: 23
---

## Amazon ElasticCache là gì

- Elasticache là dịch vụ bộ nhớ đệm được quản lý dành cho Redis và Memcached
- Giúp giảm thiểu thời gian load dữ liệu, vì load từ cache chắc chắn sẽ nhanh hơn

![](https://user-images.githubusercontent.com/29729545/166097048-404380f8-ed8a-4f61-9698-0b59720cd83e.png)

### Phân biệt Redis (Remote Dictionary Server) và Memcached

- REDIS:
  - Read Replicas để scale việc đọc, high avaiability
  - có tính năng Backup và restore
- MEMCACHED:
  - Multi-node cho việc phân vùng data, cho phép mở rộng thêm dữ liệu khi nhu cầu tăng lên
  - Memcache không có tính persis. Tức là một khi xóa là xóa hẳn, không có backup
  - Multi-thread
