---
title: "Giới thiệu S3 Select, Athena"
description: "S3 Select và Athena là hai dịch vụ giúp người dùng có thể truy vấn dữ liệu được lưu trữ trên Amazon S3. Cả Amazon S3 Select và Amazon Athena đều cho phép thực hiện các truy vấn kiểu SQL."
keywords:
  [
    "S3 Select la gi",
    "S3 Select là gì",
    "S3 Athena la gi",
    "S3 Athena là gì",
    "S3 Select trong S3",
    "S3 Athena trong S3",
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
position: 60
---

S3 Select và Athena là hai dịch vụ giúp người dùng có thể truy vấn dữ liệu được lưu trữ trên Amazon S3. Cả Amazon S3 Select và Amazon Athena đều cho phép thực hiện các truy vấn kiểu SQL. Tuy nhiên, hai dịch vụ này có những điểm khác nhau, hãy cùng mình tìm hiểu rõ hơn về hai dịch vụ này để có chọn lựa phù hợp cho dự án của mình.

## S3 Select

Amazon S3 Select là tính năng cho phép bạn thực hiện các SQL operations đơn giản dựa trên dữ liệu thô của bạn được lưu trữ trong S3. Dữ liệu của bạn phải ở định dạng có cấu trúc, ví dụ: JSON, CSV, Parquet... Nó cũng sẽ hoạt động ngay cả khi dưới dạng file nén (.zip, .rar...), vì vậy bạn không cần phải giải nén chúng trước khi đọc.

- S3 Select chỉ hỗ trợ SELECT, FROM, LIMT trong SQL
- Chí phí sử dụng tính theo lượng request (SELECT query) và data scanned
- S3 Select phù hợp với việc phân tích dữ liệu đơn giản không quá phức tạp

## Amazon Athena

Amazon Athena là một dịch vụ truy vấn dữ liệu lớn cho phép bạn dễ dàng phân tích khối lượng lớn dữ liệu mà không cần phải cung cấp server hoặc database. Giống như S3 Select, Athena cũng không có máy chủ và dựa trên SQL. Nhưng sự khác biệt chính giữa hai loại này là quy mô mà Athena cho phép bạn thực hiện các truy vấn của mình.

- Có thể sử dụng các câu truy vấn phức tạp
- Hỗ trợ phân tích dữ liệu dưới định dạng: CSV, JSON, ORC, Avro...
- Chi phí: $5/mỗi TB data scanned
- Usa-case: Phân tích, thống kê, báo cáo dữ liệu...
