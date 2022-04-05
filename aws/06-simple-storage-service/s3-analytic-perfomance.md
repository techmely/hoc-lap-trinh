---
title: "Giới thiệu S3 Analytics, Performance"
description: "Storage Class Analysis giúp bạn phân tích lượng truy cập, dung lượng lưu trữ... trong một khoảng thời gian nhất định. Từ đó giúp người dùng xác định được khi nào nên chuyển đổi Objects từ Standard => Standard_IA"
keywords:
  [
    "S3 Analytics Rules la gi",
    "S3 Analytics Rules là gì",
    "S3 Performance Rules la gi",
    "S3 Performance Rules là gì",
    "Lifecycle Rules trong S3",
    "S3 Glacier la gi",
    "S3 Glacier là gì",
    "S3 Glacier trong aws",
    "S3 Standard-IA la gi",
    "S3 Standard-IA là gì",
    "S3 Standard-IA trong aws",
    "S3 One Zone-IA la gi",
    "S3 One Zone-IA là gì",
    "S3 One Zone-IA trong aws",
    "S3 Intelligent-Tiering la gi",
    "S3 Intelligent-Tiering là gì",
    "S3 Intelligent-Tiering trong aws",
    "Chuyển đổi storage classes",
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
position: 59
---

## S3 Analytics - Storage Class Analysis

Storage Class Analysis giúp bạn phân tích lượng truy cập, dung lượng lưu trữ... trong một khoảng thời gian nhất định. Từ đó giúp người dùng xác định được khi nào nên chuyển đổi Objects từ Standard => Standard_IA ![S3 Analytics - Storage Class Analysis](https://d2908q01vomqb2.cloudfront.net/b6692ea5df920cad691c20319a6fffd7a4a766b8/2017/06/28/visualize_s3_quicksight_2.gif)

- Không sử dụng cho việc chuyển đổi Storage Class sang ONEZONE_IA hoặc S3 Glacier
- Report được cập nhật hằng ngày
- Lần đầu tiên bắt đầu sẽ mất khoảng 24-48h
- Công cụ hữu ích để đưa ra các Lifecyle Rules hợp lý

## S3 Performance

- Amazon S3 đáp ứng hiệu xuất hàng nghìn transaction/giây với độ trễ thấp (100-200ms)
- **Ứng dụng của bạn có thể xử lý 3,500 PUT/COPY/POST/DELETE hoặc 5,500 GET/HEAD request trên mỗi prefix trong bucket**
- Không có giới hạn prefix trên mỗi bucket
- Prefix (Object path => prefix):
  - bucket/folder-1/sub-fold-1/file.txt => /folder-1/sub-fold-1/
  - bucket/folder-1/sub-fold-2/file.txt => /folder-1/sub-fold-2/
  - bucket/folder-1/file.txt => /folder-1/
- Nếu bạn tạo 10 prefix trong bucket, bạn có thể có 55,000 read requests/giây

## S3 Optimizing performance

- **Multi-part upload**
  - Được recommended cho file có dung dượng > 100MB, bắt buộc sử dụng với file 5BG
  - Giải pháp này chia file có dung lượng lớn ra các phần nhỏ rồi upload lên Amazon S3. Sau đó S3 sẽ merge các phần nhỏ đó thành file ban đầu của bạn.
- **S3 Transfer Acceleration**
  - Tăng tốc độ truyền dữ liệu bằng cách tranfer file tới một AWS Egde location, sau đó forward dữ liệu đến S3 bucket.

![S3 Optimizing performance](https://user-images.githubusercontent.com/29729545/151316622-048ab8ab-a2ba-4abc-a7c2-731951bbb833.png)
