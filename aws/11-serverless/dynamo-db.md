---
title: "Giới thiệu DynamoDB"
description: "DynamoDB là môt dịch vụ quản lý NoSQL có khả năng đáp ứng hiệu suất cao và nhanh kèm theo khả năng mở rộng. Nếu bạn là một nhà phát triển, bạn có thể sử dụng DynamoDB để tạo ra một bảng có khả năng lưu trữ và truy xuất bất kỳ số lượng dữ liệu, mà vẫn có thể phục vụ cho bất kỳ mức độ request traffic."
keywords:
  [
    "No-SQL la gi",
    "No-SQL là gì",
    "No-SQL trong aws",
    "Dynamo DB la gi",
    "Dynamo DB là gì",
    "Dynamo DB trong aws",
    "Limit cua Lambda",
    "Limit của Lambda",
    "DynamoDB Read/Write Capacity Modes",
  ]
author:
  fullname: Phan Văn Đức
  username: ducpv
  avatar: "/configs/author/ducpv.jpg"
category:
  name: "Khóa học AWS từ cơ bản đến nâng cao"
  slug: "aws"
  description: "Mang kiến thức AWS đến với mọi lập trình viên"
chapter:
  name: "Serverless"
  slug: "chap-11-serverless"
position: 193
---

Ở bài này mình sẽ giới thiệu đến các bạn dịch vụ có kiến trúc Serverless, đó chính là DynamoDB.

## DynamoDB là gì

- Là dịch vụ NoSQL Database (Database không quan hệ)
- Khả năng mở rộng cao
- Lưu trữ dự liệu theo mô hình key-value
- Dữ liệu được lưu trữ trên SSD => tốc độ đọc ghi cao
- Dữ liệu tự động được replicate ở các AZs khác nhau trong cùng Region (high availablity and data durability)

## Tính chất của DynamoDB

- Khi tạo Table, bạn cần xác định **Primary key**
- Mỗi Table không giới hạn số lượng item lưu trữ
- Mỗi item có các **attributes** (có thể thêm, chỉnh sửa dễ dàng)
- Mỗi item có kích thước tối đa **400KB** (Dynamo chỉ phù hợp với lưu trữ dữ liệu không quá lớn)
- Hỗ trợ nhiều kiểu dữ liệu khác nhau

![](https://d2908q01vomqb2.cloudfront.net/887309d048beef83ad3eabf2a79a64a389ab1c9f/2018/09/10/dynamodb-partition-key-1.gif)

## DynamoDB Read/Write Capacity Modes

- **Provisioned Mode (default)**
  - Cần xác định số lượng reads/writes trên mỗi giây
  - AWS sẽ tính tiền cho **provisioned** Read Capacity Units (RCU) và Write Capacity Units (WCU)
  - Có thể thêm auto-scaling mode cho RCU & WCU
- **On-Demand Mode**
  - AWS tự động sale up/down dự trên lượng read/write thực tế
  - Không cần xác định số lượng reads/writes
  - Dùng bao nhiêu trả tiền bấy nhiêu (đắt hơn Provisioned Mode)
  - Phù hợp với những ứng dụng không biết trước được workload
