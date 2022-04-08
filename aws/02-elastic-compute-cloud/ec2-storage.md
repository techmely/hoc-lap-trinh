---
title: "Lưu trữ trong EC2"
description: "EBS (Elastic Block Store) là dịch vụ lưu trữ dưới dạng block của AWS. Một EBS có thể attach vào duy nhất 1 EC2 trong cùng AZ. Bạn có thể hiểu EBS sẽ giống như 1 USB hay 1 ổ cứng ngoài."
keywords:
  [
    "EBS là gì",
    "EBS trong aws",
    "EBS snapshot trong aws",
    "AMI là gì",
    "AMI trong aws",
    "EFS là gì",
    "EFS trong aws",
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
image: https://user-images.githubusercontent.com/29729545/162230387-c12857b1-4554-46b7-a465-861d2554e657.png
position: 7
---

## EBS là gì

EBS (Elastic Block Store) là dịch vụ lưu trữ dưới dạng block của AWS. Một EBS có thể attach vào duy nhất 1 EC2 trong cùng AZ. Bạn có thể hiểu EBS sẽ giống như 1 USB hay 1 ổ cứng ngoài.

- Có thể attach nhiều EBS vào 1 EC2 instance.
- EBS trong AWS không cross AZ
- AWS tính phí dựa trên dung lượng của EBS

EBS volume bị lock trong 1 AZ, có nghĩa là:

- 1 EBS được tạo ở us-east-1a thì không thể attach vào EC2 instance ở us-east-1b
- Để cross AZ chúng ta cần snapshot volume đó

Khi tạo EC2 instance có thể kiểm soát việc xóa EBS khi instance bị xóa (terminate)

- Mặc định, root EBS volume chọn xóa
- Những EBS volume khác sẽ không bị xóa

## EBS Snapshots trong AWS

Như đã đề cập ở phần EBS volume, chúng ta không thể cross AZ 1 EBS volume. Nhưng AWS cung cấp dịch vụ EBS snapshots giúp chúng ta có thể giải quyết bài toán đó.

- EBS snapshots tạo 1 bản backup (snapshot) của EBS volume của bạn
- Có thể copy snapshots across AZ hay region 

![EBS snapshot](https://images.viblo.asia/618fe942-940b-43fa-9185-9b474bd25a4d.png)

## Các loại EBS

Trên thực tế chúng ta khá quen thuộc với 2 công nghệ ổ cứng là SSD, HDD. AWS cũng cung cấp những loại EBS sau đây dựa trên 2 công nghệ ổ cứng trên:

- Solid State Drive (SSD)
  - General Purpose SSD (gp2/gp3)
  - Provisioned IPOS SSD (io1/io2)
- Hard Disk Drive (HDD)
  - Throughput Optimized HDD (st1)
  - Cold HDD (sc1) 
  
![EBS volume type](https://user-images.githubusercontent.com/29729545/162230387-c12857b1-4554-46b7-a465-861d2554e657.png)

## EBS multi-attach

Ở phần đầu giới thiệu về EBS chúng ta tiếp cận rằng: "1 EBS chỉ có thể attach vào 1 EC2 instance"

Như với kiến thức để thi SAA chúng ta có thể multi-attach, có nghĩa là 1 EBS có thể attach vào nhiều instance trong 1 AZ. Tuy nhiên nó sẽ có những giới hạn của nó:

- EBS và các EC2 instance phải chung AZ
- EBS volume type: **Provisioned IPOS SSD (io1/io2)** 

![EBS multil-attacg](https://images.viblo.asia/f9dd2497-f955-4081-90d6-2334aab37793.png)

## AMI là gì

AMI trong AWS viết tắt của Amazon Machine Image

Với AMI chúng ta có thể customize lại EC2 instance theo mình mong muốn:

- Thêm software, configuration...
- Giúp thời gian launch EC2 instance nhanh hơn

AMI được tạo ở 1 region xác định, và có thể copy nó sang region khác

Như vậy chúng ta có thêm 1 cách để launch EC2 instance:

- Public AMI: được cung cấp bởi AWS
- Own AMI: là AMI được tự mình tạo ra theo ý muốn
- Market AMI: là AMI do một bên khác tạo ra và nếu bạn dùng nó thì có thể sẽ tính phí 

![AMI process](https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcT07WeeI1BwAmVizxnFHZdAx9idLlM_LHgZGQ&usqp=CAU)

## EFS là gì (Elastic File System)

- Quản lý NFS(Network file system) có thể mount vào nhiều EC2 instance
- Các EC2 instance ở các AZ khác nhau cũng có thể dùng chung EFS 

![EFS](https://images.viblo.asia/5ba45b52-bddb-4376-aa93-57176313b73b.png)
- EFS có giá cao hơn EBS, nhưng chỉ cần trả tiền cho dung lượng mà bạn sử dụng
- Use case: Sử dụng trong các ứng dụng Content manage, sharing data
- Hand-on:
  - Tạo 2 EC2 ở 2 AZ khác nhau
  - Tạo 1 EFS
  - Mount EFS đó vào 2 EC2 (cần tạo)
  - 2 EC instance này có thể sharing data với nhau
- Chỉ tương thích với EC2 có AMI base là Linux, _không thể mount EFS vào EC2 có OS là window_
- EFS có thể tự động scale
- Có thể cài đặt nếu trong 1 khoảng thời gian (vd: 30day) ko truy cập đến file đó => tự động move file đó đến EFS-IA (EFS infrequently Access)
