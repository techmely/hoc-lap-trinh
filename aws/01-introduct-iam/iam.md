---
title: "Giới thiệu về IAM và CLI"
description: "IAM (Identify and Access Management) là công cụ để kiểm soát quyền truy cập của cá nhân và nhóm đến tài nguyên AWS của bạn một cách an toàn."
keywords:
  ["iam trong aws", "iam trong aws cli", "aws iam là gì", "aws iam la gi"]
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
image: https://user-images.githubusercontent.com/29729545/162231353-1e81131e-5e9e-4e36-bdbb-d17d797093ee.png
position: 2
---

## IAM trong AWS

![](https://user-images.githubusercontent.com/29729545/162231353-1e81131e-5e9e-4e36-bdbb-d17d797093ee.png)

IAM (Identify and Access Management) là công cụ để kiểm soát quyền truy cập của cá nhân và nhóm đến tài nguyên AWS của bạn một cách an toàn.

Mỗi tổ chức sử dụng IT service đều có nhiều resources, projects... Tuy nhiên không phải ai cũng có thể truy cập được tất cả ngoại trừ người có quyền cao nhất. Ví dụ phòng kế toán không thể xem thông tin được thông tin của phòng IT. Chính vì vậy cần có concept để giới hạn role của mỗi phòng/ban chỉ được đảm nhiệm một nhiệm vụ nhất định.

AWS IAM thiết kế để quản lý users, groups, roles, policies để quản lý truy cập AWS resources. IAM có 2 nhiệm vụ chính:

- **Authentication**: Xác thực người dùng
- **Authorization**: Phân quyền người dùng

## AWS root user

Khi tạo tài khoản AWS lần đầu tiên, thì đó cũng là root user. Khi dùng email và password được gọi là "**root account credentials**"\
Root account có quyền cao nhất bao gồm cả thông tin billing.

AWS recommended hạn chế dùng root account hàng ngày, thay vì đó tạo các IAM user tùy thuộc vào role của nó

## Thành phần chính của IAM

- **User**: User có thể truy cập vào tài nguyên của AWS với username-password hoặc (**access key** và **secret key**)
- **Access key**: Chuỗi chữ và số độ dài 20 ký tự, có thể hiểu giống user ID
- **Secret key**: Chuỗi chữ và số độ dài 40 ký tự, có thể hiểu giống password. **Access key** và **Secret key** dùng vơi nhau để khởi tạo API, SDK, và xác thực CLI
- **Password policy**: Định nghĩa chính sách về mật khẩu như: độ phức tạp, thời hạn...
- **Multi-Factor Authentication (MFA)**: Thêm 1 lớp bảo vệ account, khi login sẽ yêu cầu nhập thêm chuỗi 6 ký tự. Thông thường MFA được bật lên cho root user để đảm bảo an toàn
- **Group**: Một group là 1 collection của IAM users
- **Role**: Quản lý IAM có những quyền truy cập đến resources nào của AWS
- **Policy**: Là JSON format, mỗi một policy có những tính năng và quyền hạn (permission) nhất định gắn với User, Group, Roles trong IAM.

**Access key** và **Secret key** được generate 1 lần, bạn có thể tải xuống dưới dạng CSV file và giữ nó an toàn. Khi mất hoặc quên Access key và Secret key, chỉ có cách duy nhất là tạo lại key mới

> _Use access keys to make programmatic calls to AWS from the AWS CLI, Tools for PowerShell, AWS SDKs, or direct AWS API calls. You can have a maximum of two access keys (active or inactive) at a time_

## AWS CLI là gì

CLI là command line interface giúp người dùng có thể truy cập dịch vụ trông qua màn hình cmd. Chỉ với một công cụ để tải xuống và cấu hình, bạn có thể kiểm soát nhiều dịch vụ AWS bằng một dòng lệnh và tự động hóa chúng thông qua các tập lệnh.

## Exam tips

- AWS IAM service là 1 global service (không quan tâm đến region)
- Khi tạo mới IAM users, nó mặc định chưa được cấp quyền gì, cần thêm quyền cho nó để có thể sử dụng các service của AWS
- Group không thể nested
- Có thể attach nhiều policy vào user
