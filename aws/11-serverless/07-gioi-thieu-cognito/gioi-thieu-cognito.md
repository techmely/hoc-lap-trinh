---
title: "Giới thiệu Cognito"
description: "Amazon Cognito là dịch vụ của Amazon Web Services cung cấp xác thực, ủy quyền và quản lý người dùng cho các ứng dụng web và di động của bạn. Người dùng có thể đăng nhập trực tiếp bằng tên người dùng và mật khẩu hoặc thông qua bên thứ ba như Facebook, Amazon, Google hoặc Apple."
chapter:
  name: "Serverless"
  slug: "chap-11-serverless"
image: https://user-images.githubusercontent.com/29729545/155877906-06f1d98a-d17e-4e5e-9232-595b4e46f27e.png
position: 196
---

## Cognito là gì

Amazon Cognito là dịch vụ của Amazon Web Services cung cấp xác thực, ủy quyền và quản lý người dùng cho các ứng dụng web và di động của bạn. Người dùng có thể đăng nhập trực tiếp bằng tên người dùng và mật khẩu hoặc thông qua bên thứ ba như Facebook, Amazon, Google hoặc Apple.

- **Cognito User Pools**
- **Cognito Identity Pools (Federated Identity)**
- **Cognito Sync**

## Cognito User Pools là gì

- Khi tạo Cognito User Pools (CUP), AWS sẽ cung cấp một UI tích hợp, có thể tùy chỉnh, để đăng nhập người dùng.
- Tạo một serverless Database chưa thông tin user cho application
- Login: Username(email)/password
- Có thể xác thực 2 lớp qua Email/Phone/MFA
- Có thể đăng nhập thông qua bên thứ 3 (Facebook, Google, Apple...)
- Sau khi đăng nhập sẽ gửi lại một JSON Web Token (JWT)
- **Có thể tích hợp với API Gateway cho authentication**

![Cognito User Pools (CUP)](https://user-images.githubusercontent.com/29729545/155877906-06f1d98a-d17e-4e5e-9232-595b4e46f27e.png)

## Cognito Identity Pools là gì

- Cognito Identity Pools (Federated Identity) - FIP: cho phép Client có thể truy cập trực tiếp vào AWS Resource
- Ví dụ: Truy cập vào S3 thông qua đăng nhập Facebook

![Cognito Identity Pools](https://d2908q01vomqb2.cloudfront.net/0a57cb53ba59c46fc4b692527a38a87c78d84028/2017/07/19/CognitoDiagram.png)

## Cognito Sync là gì

- Deprecated - có thể sử dụng AWS AppSync để thay thế (Tuy nhiên, trong bài thì vẫn có thể hỏi đến)
- Cognito Sync là dịch vụ cho phép đồng bộ dữ liệu người dùng liên quan đến ứng dụng trên nhiều thiết bị (iOS, Android...)
- Lưu trữ configuration, state của ứng dụng
- **Yêu cầu Federated Identity Pool (not User Pool)**
