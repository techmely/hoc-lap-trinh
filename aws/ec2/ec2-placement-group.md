---
title: "Placement Group trong EC2"
description: "Placement group xác định cách các instance được đặt trên phần cứng cơ bản. Đây là cách để chúng ta yêu cầu cầu phần cứng được đặt ở đâu. Chúng ta sẽ cùng tìm hiểu các loại placement group.
"
keywords:
  [
    "Placement group là gì",
    "Clustered Placement group là gì",
    "Spread Placement group là gì",
    "Partition Placement group là gì",
    "Placement group là gì",
    "Placement group la gi",
    "Clustered Placement group la gi",
    "Spread Placement group la gi",
    "Partition Placement group la gi",
    "Placement group la gi",
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
  name: "Elastic Compute Cloud"
  slug: "ec2"
position: 6
---

## Placement group

Placement group xác định cách các instance được đặt trên phần cứng cơ bản. Đây là cách để chúng ta yêu cầu cầu phần cứng được đặt ở đâu. Chúng ta sẽ cùng tìm hiểu các loại placement group.

#### Clustered Placement Group

- Những EC2 được đặt gần nhau trong cùng 1 AZ, có thể là đặt trên cùng 1 máy vật lý của AWS
- Phù hợp với những ứng dụng có độ trễ thấp
- Tuy nhiên khi có lỗi ở 1 AZ thất cả EC2 trong cluster có thể bị down

#### Spread Placement Group

- Pros:
  - Các máy được đặt ở các AZ, hardware khác nhau
  - Giảm thiểu risk khi 1 máy down các máy khác vẫn hoạt động tốt
- Cons:
  - Giới hạn 7 instance/mỗi AZ/mỗi placement group
- Use case:
  - Dùng cho các application cần high avaibility
  - Các instance chạy độc lập với nhau

#### Partition Placement Group

Đây là kiểu kết hợp giữa Spread và Clusted

**Phân biệt bằng hình vẽ dưới đây:** ![Placement group](https://tridentsys.net/content/images/2020/07/placementgroups.jpg)
