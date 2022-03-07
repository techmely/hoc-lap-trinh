---
title: "EC2 Mở rộng"
description: "EC2 Hibernate một EC2 instance khi được launch bạn có thể stop/terminate nó đi. Nitro là Platform cho thế hệ sau của EC2 instances"
keywords:
  [
    "EC2 Hibernate là gì",
    "EC2 Hibernate trong aws",
    "EC2 Nitro là gì",
    "EC2 Nitro trong aws",
  ]
author:
  fullname: Phan Văn Đức
  username: ducpv
  avatar: "/configs/author/ducpv.jpg"
category:
  name: "Khóa học AWS từ cơ bản đến nâng cao"
  slug: "aws"
chapter:
  name: "Elastic Compute Cloud"
  slug: "ec2"
position: 100
---

## EC2 Hibernate

Một EC2 instance khi được launch bạn có thể stop/terminate nó đi

- Stop: OS sẽ shutdown process, khi stop instance AWS sẽ không tính phí instance đó mà sẽ tính phí EBS hay EIP liên quan đến instance đó.
- Terminate: xóa instance và giải phóng tài nguyên

Chúng ta sẽ cùng tìm hiểu trạng thái Hibernate của instance ![Hibernate instance](https://docs.aws.amazon.com/AWSEC2/latest/UserGuide/images/hibernation-flow.png)

- Trạng tháu của RAM sẽ được bảo quản
- Instance được khởi động nhanh hơn (OS không stopped/restarted)
- RAM state được viết vào file ở root EBS
- Root EBS phải được **encrypted**

Phù hợp với những ứng dụng:

- Long-running process
- Saving RAM state

## EC2 Nitro

- Nitro là Platform cho thế hệ sau của EC2 instances
- Được trang bị công nghệ Virtualization mới
- Performance tốt hơn
- Bảo mật tốt hơn
