---
title: "Giới thiệu PrivateLink và ClassicLink"
description: "AWS PrivateLink là một các kết nối an toàn giữa VPCs, AWS Serives, hay On-premises network của bạn. Kết nối này không đi qua internet, nó sẽ nằm trong network của AWS."
keywords: ["PrivateLink trong AWS", "PrivateLink là gì", "PrivateLink la gi"]
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
position: 24
---

## Expose service từ VPC của bạn đến các VPC khác ?

**Option I: để cho service đó được public**

Lựa chọn này sẽ để service của bạn có thể truy cập từ Internet. Tuy nhiên sẽ không đảm bảo an toàn và khó có thể quản lý truy cập. ![PrivateLink](https://user-images.githubusercontent.com/29729545/147399102-cb227613-1e19-448a-a263-e42a09de6015.png)

**Option II: sử dụng VPC peering**

- Cần tạo nhiều VPC peering
- Khi tạo VPC peering, tất cả network sẽ được mở giữa các VPC. Tuy nhiên nếu muốn expose chỉ một Application, VPC peering không phải là 1 lựa chọn tốt

## AWS PrivateLink (VPC Endpoint Services)

AWS PrivateLink là một các kết nối an toàn giữa VPCs, AWS Serives, hay On-premises network của bạn. Kết nối này không đi qua internet, nó sẽ nằm trong network của AWS.

![AWS PrivateLink trong AWS](https://user-images.githubusercontent.com/29729545/147399276-62b44e17-3793-433d-83b3-79a89b98b066.png)

- Có thể expose service tới 1000s VPC (chung account hoặc account khác nhau)
- Không cần phải sử dụng VPC peering, IGW, NAT, Route tables...
- CẦN có Network Load Balancer (Serive VPC) và ENI (Customer VPC) hoặc GWLB (Gateway load balancer)

## AWS ClassicLink (Không được sử dụng nữa)

Từ trước tháng 12 năm 2013, chúng ta có thể tạo EC2-Classic (không được sử dụng nữa). EC2-Classic là loại instance được chạy trong single network và được chia sẻ với khách hàng. ClassicLink cho phép kết nối EC2-Classic tới VPC trong account của bạn.
