---
title: "Giới thiệu S3 Hosting, CORS"
description: "S3 hosting cho phép bạn có thể tạo 1 public website từ source code html, css, javascript của bạn. Bạn không cần config web server, dns... tất cả Amazon S3 đã làm cho bạn, việc cần làm là đẩy source code của bạn lên bucket."
chapter:
  name: "Simple Storage Serivce"
  slug: "chap-06-s3"
image: https://user-images.githubusercontent.com/29729545/147963279-d4fc596c-ee8b-4ae9-a54d-c2d902ca49b8.png
position: 54
---

## S3 Hosting trong AWS

S3 hosting cho phép bạn có thể tạo 1 public website từ source code html, css, javascript của bạn. Bạn không cần config web server, dns... tất cả Amazon S3 đã làm cho bạn, việc cần làm là đẩy source code của bạn lên bucket.

- URL website sẽ có format:

```bash
http://<bucket-name>.s3-website-<region>.amazonaws.com
Hoặc
http://<bucket-name>.s3-website.<region>.amazonaws.com
```

- Cần cho phép bucket của bạn access public

Tham khảo các bước để tạo một static website:

[Tạo S3 static website](https://www.sqlshack.com/launch-a-static-website-using-aws-s3-buckets/)

## S3 CORS trong AWS

Trong lập trình web chắc hẳn chúng ta sẽ biết đến CORS là gì rồi. Nếu các chưa biết về CORS, hãy tham khảo ở đây nhé: [CORS là gì](https://viblo.asia/p/cors-la-gi-Qbq5Q0j3lD8)

![S3 CORS](https://user-images.githubusercontent.com/29729545/147963279-d4fc596c-ee8b-4ae9-a54d-c2d902ca49b8.png)

Như trên hình vẽ chúng ta có 2 bucket

- HTML bucket: Chứa các file html được host trên S3
- Assets bucket: Chứa các file ảnh của project Khi gửi request đến HTML bucket, website cần request đến tiếp những file ảnh trong Assets bucket. Khi đó cần enable CORS trong Assets bucket để những request từ url: http://sample.s3-website-us-east-2.amazonaws.com có thể đọc được những file ảnh này.
