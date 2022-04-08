---
title: "Giới thiệu VPC Peering, VPC Endpoints"
description: "VPC peering là cách liên kết giữa 2 VPC với nhau và không phát sinh thêm chi phí. Khi 2 VPC được peering, chúng có thể giao tiếp với nhau bằng private IP."
keywords:
  [
    "VPC Peering trong AWS",
    "VPC Peering là gì",
    "VPC Peering la gi",
    "VPC Endpoints trong AWS",
    "VPC Endpoints là gì",
    "VPC Endpoints la gi",
  ]
author:
  fullname: Phan Văn Đức
  username: ducpv
  avatar: "/configs/author/ducpv.jpg"
category:
  name: "Khóa học AWS từ cơ bản đến nâng cao"
  slug: "aws"
chapter:
  name: "Virtual Private Cloud"
  slug: "vpc"
position: 21
---

## VPC Peering

![VPC Peering](https://user-images.githubusercontent.com/29729545/146628771-2fa2c807-c51f-4c7e-8870-256e2fa7f74a.jpg)

VPC peering là cách liên kết giữa 2 VPC với nhau và không phát sinh thêm chi phí. Khi 2 VPC được peering, chúng có thể giao tiếp với nhau bằng private IP.

- Các VPC không được overlap CIDRs của nhau
- Có thể tạo VPC peering cross Account/Region

VPC Peering không có tính bắc cầu (Transitive Peering)

![VPC transitive](https://user-images.githubusercontent.com/29729545/146629046-7ae50cee-a585-4102-b609-043e91b65667.jpg)

Khi VPC-B và VPC-C được peering với VPC-A, chúng không thể bắc cầu qua nhau mà cần phải tạo thêm 1 VPC peering mới giữa B và C

<content-info>
  <ul>
    <li>Khi tạo VPC peering bạn cần confirm request</li>
    <li>Cần chỉnh sửa lại Router để có thể connect đến instance giữa các VPC</li>
  </ul>
</content-info>

## VPC Endpoints (AWS PrivateLink)

![Kungfutech VPC Enpoints](https://user-images.githubusercontent.com/29729545/146681296-eb3a3d74-61e0-4327-b0a0-33a830a5663d.png)

Đây là cách thông thường 1 EC2 instance connect đến DynamoDB. DynamoDB sẽ expose ra một enpoint cho phép có thể truy cập qua internet. EC2 instance đi ra ngoài internet qua IGW và có thể connect đến DynamoDB.

**VPC Enpoint** cho phép kết nối tới các AWS resource mà không cần thông qua internet. ![Kungfutech VPC Enpoints](https://user-images.githubusercontent.com/29729545/146681295-b24a2862-a6d1-4c2f-a14b-99b916b566aa.png)

VPC enpoint là các thiết bị ảo có tính dự phòng và có thể scale theo chiểu ngang (tăng số lượng nếu cần xử lý khối lượng công việc lớn). VPC enpoint cho phép chúng ta có thể kết nối sử dụng private network thay vì public internet. Khi sử dụng VPC enpoints sẽ giúp tăng tốc độ đường truyền, đồng thời giảm độ trễ (vì không cần phải đi ra ngoài internet)

**Các loại Enpoints:**

- Interface Endpoint
  - Cung cấp 1 ENI(private IP)
  - Hỗ trợ hầu hết các dịch vụ của AWS
- Gateway Enpoint
  - Cung cấp 1 gateway và cần dùng như là 1 target trong route table
  - Hỗ trợ cả S3 và DynamoDB
