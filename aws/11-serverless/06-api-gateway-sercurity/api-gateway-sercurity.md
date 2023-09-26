---
title: "API Gateway Sercurity là gì"
description: "API Gateway đóng vai trò là cửa trước cho các ứng dụng để truy cập dữ liệu, logic nghiệp vụ hoặc chức năng từ các dịch vụ backend của bạn"
author:
  fullname: Phan Văn Đức
  username: ducpv
  avatar: "/configs/author/ducpv.jpg"
category:
  name: "Khóa học AWS từ cơ bản đến nâng cao"
  slug: "aws"
  description: "Mang kiến thức AWS đến với mọi lập trình viên"
chapter:
  name: "Serverless"
  slug: "chap-11-serverless"
position: 196
---

## IAM Permissions trong API Gateway

- Tạo IAM policy authorization và attach vào User/Role
- API Gateway sẽ verifies IAM policy
- Sử dụng IAM Permissions để cho phép truy cập bên trong infrastructure trên AWS
- Không thể sử dụng IAM Permissions để quản lý truy cập client bên ngoài AWS
- Tận dụng **"Sig v4"**

![IAM Permissions](https://user-images.githubusercontent.com/29729545/155875332-03d8ef5a-0ac9-4a09-a8ea-2e5efc8e9d3f.png)

## Custome Authorizers (Lambda authorizer)

- Sử dụng AWS Lambda để validate token trên Header của request
- Hỗ trợ sử dụng OAuth/SAML/xác thực bên thứ 3
- Lambda phải return một IAM policy cho user

![Custome Authorizers](https://user-images.githubusercontent.com/29729545/155875516-df64436d-4ded-4bbf-b239-0a3af8ec133c.png)

## Cognito User Pools là gì

Chúng ta sẽ tìm hiểu Cognito là gì ở bài viết sau, ở bài này chung ta sẽ đi tìm hiểu API Gateway sử dụng user pool trong Cognito như thế nào.

- Bạn có thể quản lý User pools cho riêng mình
- Không cần viết thêm source code

![Cognito User Pools](https://user-images.githubusercontent.com/29729545/155876131-0a183c5b-20dd-4fb1-9bd6-27c90130b20e.png)

::alert{type="infor"}
Cognito chỉ giúp bạn Authentication, NOT Authorization
::
