---
title: "AWS Transfer Family là gì"
description: "AWS Transfer Family là gì? AWS Transfer Family là dịch vụ quản lý truyền file đến và ra ngoài Amazon S3 hoặc EFS sử dụng giao thức FTP."
author:
  fullname: Phan Văn Đức
  username: ducpv
  avatar: "/configs/author/ducpv.jpg"
category:
  name: "Khóa học AWS từ cơ bản đến nâng cao"
  slug: "aws"
chapter:
  name: "Mở rộng storage"
  slug: "chap-09-cloud-storage"
image: https://user-images.githubusercontent.com/29729545/154086310-497a2c10-cfcf-4170-9547-5911854ae7ad.png
position: 95
---

## AWS Transfer Family là gì

AWS Transfer Family là dịch vụ quản lý truyền file đến và ra ngoài Amazon S3 hoặc EFS sử dụng giao thức FTP. AWS Transfer Family sẽ lưu trữ host endpoint hỗ trợ những giao thức truyền file.

- Phương thức hỗ trợ:
  - AWS transfer for FTP (File Transfer Protocol)
  - AWS transfer for FTPS (File Transfer Protocol over SSL)
  - AWS transfer for SFTP (Secure File Transfer Protocol)
- Trả tiền theo lượng endpoint lưu trữ theo giờ và data transfer (GB)
- Có thể tích hợp với những dịch vụ như (Microsoft Active Directory, Cognito...) để xác thực người dùng

![AWS Transfer Family là gì](https://d1.awsstatic.com/cloud-storage/product-page-diagram_AWS-Transfer-Family_HIW-Diagram.4af0b3b19477f22bc7e37995c43cf833b6db0ce9.png)
