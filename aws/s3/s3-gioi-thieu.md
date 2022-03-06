---
title: "Giới thiệu về S3"
description: "Amazon S3 (Amazon Simple Storage Service) là dịch vụ lưu trữ dữ liệu đơn giản của Amazon cung cấp."
keywords:
  [
    "S3 la gi",
    "S3 trong aws",
    "S3 Buckets trong aws",
    "Buckets trong s3",
    "S3 Buckets là gì",
    "S3 Buckets la gi",
    "Objects trong s3",
    "S3 Objects là gì",
    "S3 Objects la gi",
    "S3 versioning là gì",
    "S3 versioning la gi",
  ]
author:
  fullname: Phan Văn Đức
  username: ducpv
  avatar: "/configs/author/ducpv.jpg"
category:
  name: "Khóa học AWS từ cơ bản đến nâng cao"
  slug: "aws"
  description: "Mang kiến thức AWS đến với mọi lập trình viên"
chapter:
  name: "Simple Storage Serivce"
  slug: "s3"
position: 50
---

## AWS S3 là gì

Amazon S3 (Amazon Simple Storage Service) là dịch vụ lưu trữ dữ liệu đơn giản của Amazon cung cấp. Amazon S3 cung cấp khả nẳng mở rộng, tính khả dụng của dữ liệu, bảo mật cao.

## S3 Buckets và Object

Amazon S3 cho phép người dùng có thể lưu trữ Objects (files) trong Buckets (directories).

### Buckets

- Bucket cần có tên là duy nhất trên toàn cầu
- Khi tạo buckets cần chon region
- Naming convention:
  - Chỉ chưa ký tự viết thường, số, dấu chấm (.), gạch ngang (-)
  - Độ dài từ 3-63 ký tự
  - Không được có format của IP
  - Phải bắt đầu bằng ký tự thường hoặc số

### Objects

Object giống như một file dữ liệu của chúng ta. Object có **Key** chính là path tên object trong bucket.

- Key có thể là kết hợp của: **prefix + object_name**

![Key trong object](https://user-images.githubusercontent.com/29729545/147766077-fce2bc9e-0852-4d72-b89e-b30b67d78eb0.png)

(prefix: _path1/path2_, object_name: _file-name.txt_)

- Object value là nội dung của body
  - Object size tối đa là: 5TB (5000GB)
  - Nếu muốn upload nhiều hơn 5GB, cần dùng **"multi-path upload"** để chia nhỏ upload nhiều phần.

## S3 Versioning

- Chúng ta có thể tạo các version của file
- Tính năng này được enable ở **"bucket level"**
- Khi 1 file có chung key, version sẽ tự động tạo ra
- Khi đánh version cho 1 file, chúng ta có thể dễ dàng phục hồi các version của 1 file
<div class="note">
Nếu enable versioning của một bucket thì những file đã tồn tại trước đó sẽ có <b>version ID = null</b>
</div>
