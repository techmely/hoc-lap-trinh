---
title: "Giới thiệu Transit Gateway"
description: "Transit Gateway giống như một trung tâm chuyển tiếp các gói tin dùng trong kết nối VPCs với On-premises network thông qua một central hub."
keywords:
  [
    "Transit Gateway trong AWS",
    "Transit Gateway là gì",
    "Transit Gateway la gi",
    "Site-to-Site VPN ECMP là gì",
    "Site-to-Site VPN ECMP la gi",
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
position: 25
---

Transit Gateway giống như một trung tâm chuyển tiếp các gói tin dùng trong kết nối VPCs với On-premises network thông qua một central hub.

## Nếu không sử dụng Transit Gateway

![Giới thiệu về Transit Gateway](https://user-images.githubusercontent.com/29729545/147404623-e06ade34-5425-4562-aece-83f160a7dce0.png)

Trên thực tế chúng ta có thể sử dụng rất nhiều VPC. Hình bên trái mô tả kết nối giữa On-premises network và các VPC, chúng ta cần tạo Site-to-Site đến nhiều VPC hay VPC peering... Tuy nhiên, Transit Gateway giúp bạn đơn giản hóa chuyện này rất nhiều. Các kết nối sẽ chỉ đi qua một central hub.

## Transit Gateway

![Giới thiệu về Transit Gateway](https://user-images.githubusercontent.com/29729545/147404793-f4f042f7-8e2d-4fdb-96ce-3c3685ee8ea9.png)

- Sử dụng cho kết nối giữa hàng nghìn VPC và on-premises connection
- Có thể cross-region
- Có thể **cross-account** khi sử dụng **Resource Access Manager (RAM)**
- Route table: có thể giới hạn những VPC nào có thể giao tiếp với nhau
- Có thể kết hợp với Direct Connection, VPN connection
- Có hỗ trợ **IP Multicast**

## Transit Gateway: Site-to-Site VPN ECMP

**ECMP = Equal-cost Multi-path routing**

- Đây là chiến lược để cho phép chuyển tiếp gói tin qua nhiều đường nhất.
- Có thể attach nhiều Site-to-Site VPN connection tới Transit Gateway
- **Use case**: Tạo ra nhiều Site-to-Site VPN connection để tăng bandwidth của kết nối đến AWS ![Transit Gateway Site-to-Site VPN ECMP](https://user-images.githubusercontent.com/29729545/147412624-2a353580-1ce6-4023-8a1a-27e7c5986092.png)

**Phân biệt VGW, DGW, TGW**

Tham khảo: [https://www.megaport.com/blog/aws-vgw-vs-dgw-vs-tgw/](https://www.megaport.com/blog/aws-vgw-vs-dgw-vs-tgw/)
