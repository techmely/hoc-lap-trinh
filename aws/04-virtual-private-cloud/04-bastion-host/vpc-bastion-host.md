---
title: "Giới thiệu về Bastion hosts"
description: "Bastion hosts là cách để chúng ta có thể truy cập vào 1 instance trong private subnet"
author:
  fullname: Phan Văn Đức
  username: ducpv
  avatar: "/configs/author/ducpv.jpg"
category:
  name: "Khóa học AWS từ cơ bản đến nâng cao"
  slug: "aws"
chapter:
  name: "Virtual Private Cloud"
  slug: "chap-04-vpc"
image: https://user-images.githubusercontent.com/29729545/166088413-89b4f088-78c8-4510-911b-242f4ef41068.png
position: 18
---

## Bastion hosts trong AWS

Đây là bài toán khá phổ biến khi làm việc với VPC và EC2 instance.

![Bastion host la gi](https://user-images.githubusercontent.com/29729545/166088413-89b4f088-78c8-4510-911b-242f4ef41068.png)

Như hình vẽ trên, chúng ta không thể SSH vào EC2 vì nó đang nằm trong Private subnet (B). Bài toán đặt ra là cần truy cập vào được máy EC2 nằm trong 1 private subnet. Giải pháp của chúng ta sẽ là sử dụng 1 EC2 instance ở Public subnet (A) hay còn gọi là Bastion hosts. Người dùng sẽ ssh vào Bastion hosts thông qua port 22, từ Bastion hosts đó sẽ ssh đến máy đang nằm trong private subnet.

- Chú ý nên chỉ giới hạn truy cập vào bastion host qua port 22 giới hạn một số IP của bạn, để đảm bảo tính bảo mật.
- Bastion hosts phải nằm trong public subnet
