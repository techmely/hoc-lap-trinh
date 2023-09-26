---
title: "Mã hóa dữ liệu trong S3"
description: "Để tránh việc lưu trữ dữ liệu dưới dạng thô, Amazon S3 cung cấp phương thức mã hóa dữ liệu. Trong S3 có 2 cách chính để mã hóa"
author:
  fullname: Phan Văn Đức
  username: ducpv
  avatar: "/configs/author/ducpv.jpg"
category:
  name: "Khóa học AWS từ cơ bản đến nâng cao"
  slug: "aws"
chapter:
  name: "Simple Storage Serivce"
  slug: "chap-06-s3"
image: https://user-images.githubusercontent.com/29729545/147951666-48c6c7af-c3b0-42fd-b434-ed21edcb1f9e.png
position: 52
---

## S3 Encryption trong aws

Để tránh việc lưu trữ dữ liệu dưới dạng thô, Amazon S3 cung cấp phương thức mã hóa dữ liệu. Cách thức hoạt động của mã hóa là dùng **key** và **thuật toán (algorithm)** để biến dữ liệu ban đầu thành dữ liệu được mã hóa. Vậy nên, vấn đề cần quan tâm là lưu trữ key ở đâu. Trong S3 có 2 cách chính để mã hóa

- Server-side encryption: Mã hóa phía server (S3)
- Client-side encryption: Mã hóa phía client (dùng các libs để mã hóa) rồi upload dữ liệu được mã hóa lên S3 Amazon S3 cung cấp 4 phương thức mã hóa object:
- **SSE-S3**: Mã hóa S3 objects sử dụng key quản lý bởi AWS
- **SSE-KMS**: Sử dụng AWS Key Management Service (KMS) để quản lý encryption keys
- **SSE-C**: Sử dụng khi bạn muốn quản lý encryption keys riêng của mình
- **Client Side Encryption**

### SSE-S3 trong AWS

- Mã hóa sử dụng key quản lý bởi Amazon S3
- Object được mã hóa phía server side
- Phương thức mã hóa: **AES-256**
- Phải set header: **"x-amz-server-side-encryption":"AES256"**

![SSE-S3 mã hóa](https://user-images.githubusercontent.com/29729545/147951666-48c6c7af-c3b0-42fd-b434-ed21edcb1f9e.png)

### SSE-KMS trong AWS

- Mã hóa sử dụng key quản lý bởi AWS Key Management Service (KMS)
- Object được mã hóa phía server side
- Phải set header: **"x-amz-server-side-encryption":"aws:kms"**

![SSE-KMS mã hóa](https://user-images.githubusercontent.com/29729545/147951666-48c6c7af-c3b0-42fd-b434-ed21edcb1f9e.png)

### SSE-C trong AWS

- Là server-side encryption sử dụng key cung cấp bởi khách hàng (AWS không quản lý key này)
- **Phải dùng HTTPS**
- Encyption key phải được cung cấp trong HTTPs headers trong mỗi request

![SSE-C mã hóa](https://user-images.githubusercontent.com/29729545/147952597-e8809e11-cf3a-4dab-af64-8a15b80a4849.png)

### Client Side Encryption trong AWS

- Mã hóa phía client trước khi upload lên S3
- Sử dụng client libs chẳng hạn như: Amazon S3 Encryption Client
- Khi đọc dữ liệu trả về cần decrypt chúng

![Client Side Encryption](https://user-images.githubusercontent.com/29729545/147953387-1df6f1ad-3e43-4590-9bc1-2555815e23ab.png)
