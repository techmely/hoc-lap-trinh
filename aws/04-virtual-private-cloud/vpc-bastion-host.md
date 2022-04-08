---
title: "Giới thiệu về Bastion hosts"
description: "Bastion hosts là cách để chúng ta có thể truy cập vào 1 instance trong private subnet"
keywords: ["Bastion hosts trong AWS"]
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
position: 18
---

Đây là bài toán khá phổ biến khi làm việc với VPC và EC2 instance.

![Bastion host la gi](https://user-images.githubusercontent.com/29729545/146036055-8a9991ba-d596-4e3c-aed8-fcd71d5dedd6.png)

Như hình vẽ trên, chúng ta không thể SSH vào EC2 vì nó đang nằm trong Private subnet (B). Bài toán đặt ra là cần truy cập vào được máy EC2 nằm trong 1 private subnet. Giải pháp của chúng ta sẽ là sử dụng 1 EC2 instance ở Public subnet (A) hay còn gọi là Bastion hosts. Người dùng sẽ ssh vào Bastion hosts thông qua port 22, từ Bastion hosts đó sẽ ssh đến máy đang nằm trong private subnet.

- Chú ý nên chỉ giới hạn truy cập vào bastion host qua port 22 giới hạn một số IP của bạn, để đảm bảo tính bảo mật.
- Bastion hosts phải nằm trong public subnet
