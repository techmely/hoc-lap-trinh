---
title: "Giới thiệu S3 MFA Delete, Default Encryption"
description: "MFA (Multi factor authentication) bắt buộc người dùng phải sử dụng một đoạn code được gen ra trên thiết bị xác thực 2 lớp(thường là điện thoại) trước khi thực hiện các operations quan trọng trên S3. Điều này nhằm mục đích bảo mật những resource quan trọng có trên S3, Amazon S3 muốn chắc chắn rằng chỉ có owner của Bucket mới có quyền để xóa một version hoặc thay đổi version của nó."
keywords:
  [
    "S3 MFA Delete la gi",
    "S3 MFA Delete trong aws",
    "S3 Default Encryption la gi",
    "S3 Default Encryption trong aws",
    "S3 MFA Delete trên S3",
    "S3 Default Encryption tren S3",
    "Hosting website tren S3",
    "S3 MFA Delete là gì",
    "S3 Default Encryption là gì",
  ]
author:
  fullname: Phan Văn Đức
  username: ducpv
  avatar: "/configs/author/ducpv.jpg"
category:
  name: "Khóa học AWS từ cơ bản đến nâng cao"
  slug: "aws"
chapter:
  name: "Simple Storage Serivce"
  slug: "s3"
position: 55
---

## S3 MFA Delete

MFA (Multi factor authentication) bắt buộc người dùng phải sử dụng một đoạn code được gen ra trên thiết bị xác thực 2 lớp(thường là điện thoại) trước khi thực hiện các operations quan trọng trên S3. Điều này nhằm mục đích bảo mật những resource quan trọng có trên S3, Amazon S3 muốn chắc chắn rằng chỉ có owner của Bucket mới có quyền để xóa một version hoặc thay đổi version của nó.

- Để sử dụng MFA-Delete, bạn cần enable Versioning trên S3 bucket
- Khi đã sử dụng MFA-Delete, bạn cần thêm một bước xác thực nữa để có thể thực hiện:
  - Thay đổi Versioning của Bucket
  - Xóa một Object version
- Bạn không cần sử dụng MFA để:
  - Enable versioning
  - Xem những versions đã xóa
- **Chỉ có bucket owner (root account) mới có quền enable/disable MFA-Delete**
- MFA-Delete hiện tại chỉ có thể enabled bằng CLI

[Hướng dẫn enable MFA-Delete bằng CLI](https://cloudkatha.com/how-to-enable-mfa-delete-on-s3-bucket/)

## S3 Default Encryption

- Khi tạo một bucket trên S3, chúng ta có thể "force encryption" những object được upload lên. Điều này đảm bảo rằng những object được upload lên S3 đã được mã hóa.
- Bạn có thể sử dụng "Default Encryption", khi enable option này lên, object sẽ được Amazon S3 mã hóa mặc định.

![S3 Default Encryption](https://user-images.githubusercontent.com/29729545/150817284-8318d392-87ee-46db-a462-f5aa57863863.png)
