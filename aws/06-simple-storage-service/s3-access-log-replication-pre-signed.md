---
title: "Giới thiệu S3 Access Logs, Replication và Pre-signed"
description: "S3 Access Logs giúp bạn có thể lưu lại thông tin request đến S3 buckets. Dữ liệu này có thể dùng để phân tích bằng những dịch vụ phân tích như Amazon Athena...S3 Replication là tính năng sao chép các object giữa các vùng lưu trữ."
keywords:
  [
    "S3 Access Logs la gi",
    "S3 Access Logs là gì",
    "S3 Access Logs trong aws",
    "S3 Replication la gi",
    "S3 Replication là gì",
    "S3 Replication trong aws",
    "S3 Pre-signed la gi",
    "S3 Pre-signed là gì",
    "S3 Pre-signed trong aws",
    "S3 Cross Region Replication la gi",
    "S3 Cross Region Replication là gì",
    "S3 Cross Region Replication trong aws",
    "S3 Same Region Replication la gi",
    "S3 Same Region Replication là gì",
    "S3 Same Region Replication trong aws",
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
position: 56
---

## S3 Access Logs

- S3 Access Logs lưu lại thông tin request đến S3 buckets của bạn
- Như hình vẽ dưới đây, những request đến "S3 Bucket", cho dù accept hay denied đều được ghi lại vào "Log Bucket"
- Dữ liệu này có thể dùng để phân tích bằng những dịch vụ phân tích như Amazon Athena...

S3 access logs format:

```
79a59df900b949e55d96a1e698fbacedfd6e09d98eacf8f8d5218e7cd47ef2be awsexamplebucket1 [06/Feb/2019:00:00:38 +0000] 192.0.2.3 79a59df900b949e55d96a1e698fbacedfd6e09d98eacf8f8d5218e7cd47ef2be 3E57427F3EXAMPLE REST.GET.VERSIONING - "GET /awsexamplebucket1?versioning HTTP/1.1" 200 - 113 - 7 - "-" "S3Console/0.4" - s9lzHYrFp76ZVxRcpX9+5cjAnEH2ROuNkd2BHfIa6UkFVdtjf5mKR3/eTPFvsiP/XV/VLi31234= SigV2 ECDHE-RSA-AES128-GCM-SHA256 AuthHeader awsexamplebucket1.s3.us-west-1.amazonaws.com TLSV1.1

```

![S3 Access Logs](https://user-images.githubusercontent.com/29729545/150820622-f7eebb9c-aa28-45b7-9d80-a343b31fb451.png)

<span style="color:red">Chú ý: Log bucket KHÔNG được là monitored bucket</span> Điều này sẽ tạo một vòng lặp vô tận.

![S3 Access Logs loop](https://user-images.githubusercontent.com/29729545/150823145-ec002c49-da51-43de-aaed-d3547f1cfd65.png)

## S3 Replication (CRR & SRR)

- CRR: Cross Region Replication
- SRR: Same Region Replication

S3 Replication là tính năng sao chép các object giữa các vùng lưu trữ. Với S3 Replication, bạn có thể config Amazon S3 tự động sao chép S3 Object trên các Region khác nhau (Cross Region Replication), hoặc giữa các vùng lưu trữ trên cùng một Region (Same Region Replication).

- Phải "Enable versioning" trong bucket source và destination
- Buckets có thể ở account khác nhau
- Việc copy là asynchronous
- Cần cung cấp IAM permission cần thiết tới S3

<content-info>
  <ul>
    <li>Sau khi enable replica, bạn chỉ có thể copy những Object mới, còn objects cũ trước đó sẽ không được copy</li>
    <li>Copy không thể có tính "chaining". Có nghĩa nếu Bucket A copy sang Bucket B, Bucket B copy sang Bucket C. Thì khi tạo Object D sẽ không được copy sang Bucket C</li>
    <li>Có thể sử dụng "Replicate delete markers" để có thể xóa bản copy từ source => destination</li>
  </ul>
</content-info>

## S3 Pre-signed

Pre-signed URL là URL mà bạn có thể cung cấp cho người dùng của mình để cấp quyền truy cập tạm thời vào một đối tượng S3 cụ thể. Sử dụng URL, người dùng có thể đọc và ghi đối tượng (hoặc cập nhật đối tượng hiện có). URL chứa các thông số cụ thể do ứng dụng mà bạn cài đặt.

- Mặc định Pre-signed URL có hiệu lực 3600s, bạn có thể thay đổi với CLI (--expires-in argument)
- Khi đã quá thời gian hết hạn, người dùng không thể truy cập được đến Object chỉ định

```bash
# AWS CLI
aws s3 presign s3://awsexamplebucket/test2.txt
```

```bash
# Ví vụ S3 Pre-signed URL
https://presignedurldemo.s3.eu-west-2.amazonaws.com/image.png?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIAJJWZ7B6WCRGMKFGQ%2F20180210%2Feu-west-2%2Fs3%2Faws4_request&X-Amz-Date=20180210T171315Z&X-Amz-Expires=1800&X-Amz-Signature=12b74b0788aa036bc7c3d03b3f20c61f1f91cc9ad8873e3314255dc479a25351&X-Amz-SignedHeaders=host
```
