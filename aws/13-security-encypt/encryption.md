---
title: "Giới thiệu KMS"
description: "Key Management Service (KMS) là dịch vụ dùng để quản lý key. KMS giúp bạn dễ dàng encrypt/decrypt dữ liệu trên AWS resources."
author:
  fullname: Phan Văn Đức
  username: ducpv
  avatar: "/configs/author/ducpv.jpg"
category:
  name: "Khóa học AWS từ cơ bản đến nâng cao"
  slug: "aws"
chapter:
  name: "Security & Encryption"
  slug: "chap-13-security"
image: https://user-images.githubusercontent.com/29729545/172041483-cd0784e1-4a91-47e6-9a61-3599fe3e24f9.png
position: 241
---

## AWS KMS là gì

![AWS KMS là gì](https://user-images.githubusercontent.com/29729545/172041483-cd0784e1-4a91-47e6-9a61-3599fe3e24f9.png)

Key Management Service (KMS) là dịch vụ dùng để quản lý key. KMS giúp bạn dễ dàng encrypt/decrypt dữ liệu trên AWS resources.

- Không nên lưu những thông tin quan trọng dưới dạng plaintext
- **KMS chỉ có thể encrypt tối đa 4KB data mối lần call**
- Do đó, KMS không phù hợp nếu bạn muốn encrypt, decrypt data lớn

## KMS - Customer Master Key (CMK) Types

- **Symmetric (AES-256 keys)** - khóa đối xứng
  - Single encyption key dùng trong cả Encrypt và Decrypt
  - Những dịch vụ trên AWS sử dụng KMS-Symmetric để mã hóa
- **Asymmetric(RSA & ECC key pairs)** - bất đối xứng
  - Cặp Public (encrypt) và Private Key (decrypt)
  - Dùng trong Encrypt/Decrypt hoặc Sign/Verify
  - Public key có thể download, private key cần giữ cẩn thận
  - Use case: người dùng muốn encrypt bên ngoài AWS (không thể call KMS API)

## KMS Automatic Key Rotation

- Được dùng cho Customer-managed CMK (không phải AWS managed CMK)
- Sau một thời gian nhất định, khóa của bạn sẽ bị hết hiệu lực => cần phải gia hạn
- Bạn có thể lựa chọn key tự động gia hạn mỗi năm, hoặc gia hạn bằng tay (90 ngày, 180 ngày...)
