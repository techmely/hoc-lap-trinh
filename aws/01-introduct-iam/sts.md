---
title: "Security Token  là gì"
description: "AWS Security Token Service (STS) là web service cho phép người dùng gửi request tạm thời và cấp quyền một cách giới hạn cho IAM user"
keywords:
  [
    "iam trong aws",
    "iam trong aws cli",
    "aws iam là gì",
    "aws iam la gi",
    "aws sts là gì",
    "aws sts la gi",
  ]
author:
  fullname: Phan Văn Đức
  username: ducpv
  avatar: "/configs/author/ducpv.jpg"
category:
  name: "Khóa học AWS từ cơ bản đến nâng cao"
  slug: "aws"
chapter:
  name: "Giới thiệu AWS"
  slug: "index"
image: https://user-images.githubusercontent.com/29729545/162231674-0f3da49a-2fcf-40c0-8b99-9a2240094ea6.png
position: 3
---

## STS là gì

AWS Security Token Service (STS) là web service cho phép người dùng gửi request tạm thời và cấp quyền một cách giới hạn cho IAM user.

- Token có hiệu lực tối đa trong 1 giờ, sau đó cần phải refresh lại

![Security Token Service](https://user-images.githubusercontent.com/29729545/162231674-0f3da49a-2fcf-40c0-8b99-9a2240094ea6.png)

Như trên hình vẽ, Dev account không có quyền truy cập đến Amazon S3. Tuy nhiên một này vì lý do dự án muốn Dev account này xem được các bucket có trên S3 trong khoảng thời gian 30'. Alice sẽ được cấp một token tạm thời (STS) để có thể truy cập được vào S3 bucket. Token này chỉ có thời hạn 30', sau 30' Alice không thể truy cập lại S3 nữa.

## STS: Assume Role

![STS: Assume Role](https://user-images.githubusercontent.com/29729545/156545085-0d148e6b-94f3-4f97-9221-acbbe286936e.png)

## Identity Federation

- AWS sử dụng bên thứ 3 để xác thực người dùng, user cần login qua bên thứ 3 để có thể access tài nguyên trên AWS
- Federation (bên thứ 3) có thể là:
  - SAML 2.0
  - Cognito
  - Single Sign On
- **Khi dùng Federation bạn không bần tạo IAM user (vì user được quản lý ở bên thứ 3)**

![Identity Federation](https://user-images.githubusercontent.com/29729545/156547213-ce09e199-9d6a-4868-af21-5fdc656925c4.png)
