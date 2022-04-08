---
title: "AWS Global Accelerator là gì"
description: "AWS Global Accelerator là dịch vụ cải thiện hiệu suất của ứng dụng của bạn bằng cách tận dụng mạng nội bộ toàn cầu của AWS."
keywords:
  [
    "Unicast IP là gì",
    "Unicast IP la gi",
    "Anycast IP là gì",
    "Anycast IP la gi",
    "AWS Global Accelerator là gì",
    "AWS Global Accelerator la gi",
    "Phân biệt AWS Global Accelerator với Cloudfront",
    "AWS Global Accelerator với Cloudfront",
    "AWS Global Accelerator vs Cloudfront",
  ]
author:
  fullname: Phan Văn Đức
  username: ducpv
  avatar: "/configs/author/ducpv.jpg"
category:
  name: "Khóa học AWS từ cơ bản đến nâng cao"
  slug: "aws"
chapter:
  name: "Cloudfront, Accelerator"
  slug: "cloud-front"
position: 73
---

## Unicast IP và Anycast IP

Đầu tiên chúng ta sẽ cùng tìm hiểu về 2 concepts là **Unicast IP và Anycast IP**

- Unicast IP: Mỗi server giữ một địa chỉ IP
- Anycast IP: Tất cả server cùng giữ một địa chỉ IP, client sẽ gửi request đến server nào gần nhất

![Unicast IP và Anycast IP](https://user-images.githubusercontent.com/29729545/153176578-7e06fe25-f933-4a02-a619-1fc275d90d73.png)

## Ứng dụng với người dùng toàn cầu

Trước khi tìm hiểu xem AWS Global Accelerator là gì, chúng ta sẽ cùng tìm hiểu một bài toán về ứng dụng có người dùng ở toàn cầu. Giả sử ứng dụng của bạn được deploy ở Ấn Độ, và có lượng user toàn cầu truy cập vào hằng ngày. Một user ở Mỹ muốn truy cập đến ứng dụng của bạn, network không thể gửi đi theo một đường thẳng từ Mỹ đến Ấn Độ. Chúng cần đi qua các **hops**, điều này làm tăng độ trễ khi gửi gói tin qua internet. Càng cách xa nhau, độ trễ sẽ càng lớn.

![AWS Global Accelerator là gì](https://user-images.githubusercontent.com/29729545/153230724-8a15bd83-020a-49b7-a02f-d6fce90699b0.png)

## AWS Global Accelerator là gì

AWS Global Accelerator là dịch vụ cải thiện hiệu suất của ứng dụng của bạn bằng cách tận dụng mạng nội bộ toàn cầu của AWS.

- Global Accelerator sẽ cung cấp cho ứng dụng của bạn 2 Anycast IP (static IP)
- Anycast IP sẽ gửi traffic trực tiếp đến Edge location
- Edge location sẽ gửi traffic đến ứng dụng của bạn (qua Global AWS private network)

![AWS Global Accelerator là gì](https://user-images.githubusercontent.com/29729545/153238666-efea5caf-ba0b-4234-9c82-ad5f7340626d.png)

## Phân biệt Global Accelerator và Cloudfront

- Cả hai đều sử dụng hệ thống network và edge location của AWS trên toàn cầu
- Cả hai đều có thể tích hợp với AWS Shield cho DDos

Khác nhau:

- **Cloudfront:**
  - Tăng hiệu năng bằng cách cache content tại các Edge location
  - Client gửi request lần đầu tiên, content sẽ được cache tại Edge. Từ các request tiếp theo, content sẽ được lấy tại cahed edge
- **Global Accelerator:**
  - Tăng hiệu năng của ứng dụng thông qua TCP và UDP
