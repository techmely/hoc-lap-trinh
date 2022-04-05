---
title: "Amazon FSx là gì"
description: "Amazon FSx là dịch vụ cho phép bạn có thể launch hệ thống files với hiệu suất cao. FSx được xây dựng trên công nghệ máy tính, network, phần cứng mới nhất hiện nay đem lại hiệu suất cao."
keywords:
  [
    "AWS FSx là gì",
    "AWS FSx la gi",
    "FSx trong AWS",
    "FSx File System Deployment Options",
    "AWS FSx Lustre là gì",
    "AWS FSx Lustre la gi",
    "AWS FSx Window File Server là gì",
    "AWS FSx Window File Server la gi",
    "AWS FSx Scratch File System là gì",
    "AWS FSx Scratch File System la gi",
    "AWS FSx Persistent File System là gì",
    "AWS FSx Persistent File System la gi",
  ]
author:
  fullname: Phan Văn Đức
  username: ducpv
  avatar: "/configs/author/ducpv.jpg"
category:
  name: "Khóa học AWS từ cơ bản đến nâng cao"
  slug: "aws"
chapter:
  name: "Mở rộng storage"
  slug: "cloud-storage"
position: 93
---

## Giới thiệu Amazon FSx

Amazon FSx là dịch vụ cho phép bạn có thể launch hệ thống files với hiệu suất cao. FSx được xây dựng trên công nghệ máy tính, network, phần cứng mới nhất hiện nay đem lại hiệu suất cao. Bên cạnh những dịch vụ lưu trữ đã học bao gồm: S3, EBS, EFS, sau khi học bài này bạn có thể lựa chọn những option khác như:

- **FSx for Lustre**
- **FSx for Window File Server**
- FSx for NetApp ONTAP... (Không có trong exam)

## FSx for Window File Server

Như chúng ta đã biết, EFS là dịch vụ có thể share tới nhiều **EC2 Linux instance**. Điểm hạn chế của EFS là không tương tích với những server chạy trên OS là Window.

- **FSx for Windows** chính là giải pháp tương tự EFS, có thể tương thích với những server có OS là Window.
- Hỗ trợ SMB protocol (giao thức chia sẻ file trong Window), Window NTFS
- Microsoft Active Directory integration, ACLs
- Xây dựng trên SSD
- Có thể truy cập từ on-premise infrastructure
- Có thể cấu hình Multi-AZ
- Dữ liệu được backup hằng ngày lên S3

## FSx for Lustre

![FSx for Lustre](https://d1.awsstatic.com/pdp-how-it-works-assets/product-page-diagram_Amazon-FSx-for-Lustre.097ed5e5175fa96e8ac77a2470151965774eec32.png)

- Lustre là tên xuất phát từ "Linux" và "Cluster"
- "FSx for Lustre" là hệ thống chia sẻ storage với khả năng mở rộng và hiệu suất cao
- Được sử dụng trong Machine Learning, Video Processing, **High Performance Computing (HPC)**
- IOPS cao, độ trễ thấp (nhỏ hơn ms)
- **Tương thích tốt với S3**
  - Có thể đọc dữ liệu trong S3 (thông qua FSx)
  - Có thể ghi ngược trở lại dữ liệu computing vào S3 (thông qua FSx)
- Có thể dùng từ on-premise server

## FSx File System Deployment Options

Khi tạo FSx file cần phân biệt được 2 option là: **Scratch File System** và **Persistent File System**

- **Scratch File System**:
  - Temporary storage
  - Dữ liệu không được replicate (nếu có lỗi sẽ bị mất dữ liệu)
  - Tốc độ đọc ghi cao
  - Sử dụng trong process ngắn hạn, tối ưu hóa chi phí
- **Persistent File System**:
  - Long-term storage
  - Dữ liệu được replicate trong chung một AZ
  - Phục hội file bị lỗi trong vòng một hoặc vài phút
  - Sử dụng trong process dài hạn

![FSx File System Deployment Options](https://user-images.githubusercontent.com/29729545/153895635-377566d8-82a7-418b-a3ac-0b25739c6e3b.png)
