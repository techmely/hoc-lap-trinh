---
title: "Giới thiệu về EC2"
description: "EC2 là dịch vụ web cung cấp năng lực điện toán bảo mật và có kích cỡ linh hoạt trên đám mây. Dịch vụ này được thiết kế để giúp các nhà phát triển dễ sử dụng điện toán đám mây ở quy mô web hơn."
keywords:
  [
    "Amazon EC2 là gì",
    "aws ec2 là gì",
    "ec2 instance là gì",
    "ec2 là gì",
    "ec2 la gi",
    "ec2 instance la gi",
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
image: https://user-images.githubusercontent.com/29729545/162225080-a2fb1728-9a20-425a-be8f-2b601ba0b67d.png
position: 3
---

## Amazon EC2 là gì

![Amazon EC2 là gì](https://user-images.githubusercontent.com/29729545/162225080-a2fb1728-9a20-425a-be8f-2b601ba0b67d.png)

Amazon Elastic Compute Cloud (Amazon EC2) là dịch vụ web cung cấp năng lực điện toán bảo mật và có kích cỡ linh hoạt trên đám mây. Dịch vụ này được thiết kế để giúp các nhà phát triển dễ sử dụng điện toán đám mây ở quy mô web hơn. EC2 cung cấp các ứng dụng máy tính ảo hoá có thể mở rộng về khả năng xử lý cùng các thành phần phần cứng ảo như bộ nhớ máy tính (ram), CPU, linh hoạt trong việc lựa chọn các phân vùng lưu trữ dữ liệu ở các nền tảng khác nhau và sự an toàn trong quản lý dịch vụ bởi kiến trúc ảo hoá đám mây mạnh mẽ của AWS.

Để dễ hình dung thì EC2 như một máy tính của chúng ta, nó cũng có:

- RAM
- CPU
- AMI (OS-Hệ điều hành)
- Card mạng
- EBS (Ổ cứng)

## Dịch vụ liên quan đến EC2

Chúng ta sẽ làm quen với những services:

- Amazon Elastic Compute Cloud (Amazon EC2)
- Amazon Lightsail
- AWS Elastic Beanstalk
- Amazon Elastic Container Service (Amazon ECS)
- Amazon Elastic Container Service for Kubernetes (Amazon EKS)
- AWS Lambda
- Elastic Block Store (EBS)
- Elastic Load Balancing (ELB)
- Auto Scaling Group (ASG)

Khi tạo 1 EC2 instance sẽ giống như bạn đang quản lý 1 máy tính server riêng của mình.

**Connect EC2 from git bash**

```
  ssh -i “ec2-key-pair-name.pem” ec2-user@ec2-public-ip-address
```

**Copy file from local to EC2**

```
  chmod 400 file_pem
  scp -i file_name.pem test.txt ec2-user@54.238.227.150:/home/ec2-user
```

## Security group

Đây là một khái niệm bạn cần làm quen khi làm việc với môi trường AWS. Security Group là một tường lửa ảo (Virtual Firewall) để quản lý truy cập vào Instance của bạn.

- Quản lý việc access EC2 theo IP, IP range, hay port
- Thay đổi trong SG được apply ngay lập tức
- Mỗi security group có tối đa 50 rules inbound và outbound
- Tối đa có 5 security group được attach cho 1 instance
- Statefull
  - Những traffic được allowed ở inbound thì cũng tự động được allowed ở outbound.
  - Vì thế ko cần đặt outbound rule nếu rule đó đã được định nghĩa ở inbound
- Trong trường hợp nhiều rule tương đồng apply cho EC2 instance thì rule nào rộng hơn sẽ được apply. Ví du:
  - Rule 1: cho phép giao tiếp trên TCP port 22 từ IP: 10.115.53.222
  - Rule 2: cho phép giao tiếp trên TCP port 22 từ mọi nơi (0.0.0.0)
  - => Rule 2 (Cho phép truy cập từ mọi nơi) sẽ được apply
- Mặc định, khi security group mới được tạo, nó sẽ **block tất cả incomming communication** và cho **phép tất cả outgoing communication**
