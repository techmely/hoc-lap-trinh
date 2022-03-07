---
title: "Giới thiệu KMS"
description: "Key Management Service (KMS) là dịch vụ dùng để quản lý key. KMS giúp bạn dễ dàng encrypt/decrypt dữ liệu trên AWS resources."
keywords:
  [
    "KMS la gi",
    "KMS là gì",
    "KMS trong aws",
    "Symmetric trong KMS",
    "KMS Symmetric la gi",
    "KMS Symmetric là gì",
    "KMS Asymmetric la gi",
    "KMS Asymmetric là gì",
  ]
author:
  fullname: Phan Văn Đức
  username: ducpv
  avatar: "/configs/author/ducpv.jpg"
category:
  name: "Khóa học AWS từ cơ bản đến nâng cao"
  slug: "aws"
chapter:
  name: "Security & Encryption"
  slug: "security"
position: 241
---

## Key Management Service (KMS)

Key Management Service (KMS) là dịch vụ dùng để quản lý key. KMS giúp bạn dễ dàng encrypt/decrypt dữ liệu trên AWS resources.

- Không nên lưu những thông tin quan trọng dưới dạng plaintext
- **KMS chỉ có thể encrypt tối đa 4KB data mối lần call**
- Do đó, KMS không phù hợp nếu bạn muốn encrypt, decrypt data lớn

## KMS - Customer Master Key (CMK) Types

- **Symmetric (AES-256 keys)** - khóa đối xứng
  - Single encyption key dùng trong cả Encryptvaf Decrypt
  - Những dịch vụ trên AWS sử dụng KMS-Symmetric để mã hóa
- **Asymmetric(RSA & ECC key pairs)** - bất đối xứng
  - Cặp Public (encrypt) và Private Key (decrypt)
  - Dùng trong Encrypt/Decrypt hoặc Sign/Verify
  - Public key có thể download, private key cần giữ cẩn thận
  - Use case: người dùng muốn encrypt bên ngoài AWS (không thể call KMS API)

## KMS Automatic Key Rotation

- Cho Customer-managed CMK (không phải AWS managed CMK)
- Bạn có thể lựa chọn key tự động gia hạn mỗi năm, hoặc gia hạn bằng tay (90 ngày, 180 ngày...)
