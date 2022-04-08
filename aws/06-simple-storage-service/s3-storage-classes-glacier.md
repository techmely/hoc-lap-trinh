---
title: "Giới thiệu S3 Storage Classes, Glacier"
description: "Amazon S3 cung cấp một loạt các lớp lưu trữ mà bạn có thể lựa chọn dựa trên các yêu cầu về quyền truy cập dữ liệu, khả năng phục hồi và chi phí tương ứng với khối lượng công việc. Các lớp lưu trữ S3 được xây dựng nhằm mục đích cung cấp khả năng lưu trữ với chi phí thấp nhất cho các kiểu truy cập khác nhau. Lớp lưu trữ S3 lý tưởng cho hầu hết mọi trường hợp sử dụng, bao gồm cả những trường hợp có nhu cầu hiệu năng cao, yêu cầu lưu trữ dữ liệu, kiểu truy cập không xác định hoặc hay thay đổi, hoặc dùng để lưu trữ."
keywords:
  [
    "S3 Storage Classes la gi",
    "S3 Storage Classes là gì",
    "S3 Storage Classes trong aws",
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
position: 57
---

## S3 Storage Classes

Amazon S3 cung cấp một loạt các lớp lưu trữ mà bạn có thể lựa chọn dựa trên các yêu cầu về quyền truy cập dữ liệu, khả năng phục hồi và chi phí tương ứng với khối lượng công việc. Các lớp lưu trữ S3 được xây dựng nhằm mục đích cung cấp khả năng lưu trữ với chi phí thấp nhất cho các kiểu truy cập khác nhau. Lớp lưu trữ S3 lý tưởng cho hầu hết mọi trường hợp sử dụng, bao gồm cả những trường hợp có nhu cầu hiệu năng cao, yêu cầu lưu trữ dữ liệu, kiểu truy cập không xác định hoặc hay thay đổi, hoặc dùng để lưu trữ.

Các storage class hiện có bao gồm:

- Standard
- Standard-Infrequent Access (Standard-IA)
- One Zone-Infrequent Access (One Zone-IA)
- Intelligent-Tiering
- Glacier
- Glacier Deep Archive

Mỗi storage class khác nhau có các thuộc tính khác nhau về: Chi phí, Độ khả dụng (availability), Độ bền (durability), Mức độ truy cập (frequency)

### Standard - General Purpose

- Là class thông dụng nhất
- Được thiết kế cho tất cả các mục đích lưu trữ
- Là lựa chọn mặc định
- 99.999999999% độ bền object (11' 9)
- 99.99% độ khả dụng object
- Có chi phí cao nhất
- Use-case: Dùng cho phân tích dữ liệu, Mobile & gaming application, content distribution...

### Standard-Infrequent Access (Standard-IA)

- Được thiết kế cho các object không được truy cập thường xuyên nhưng cần phải khả dụng ngay lập tức khi được truy cập.
- 99.999999999% độ bền object (11' 9)
- 99.9% độ khả dụng object
- Chi phí rẻ hơn Standard
- Use-case: Dữ liệu backup cho phục hồi khi thiên tai...

### One Zone-Infrequent Access (One Zone-IA)

- Tương tự như IA nhưng được lưu trữ ở một single AZ
- 99.999999999% độ bền object (11 số 9) trong single AZ, nếu AZ đó bị phá hủy, dữ liệu sẽ bị mất đi
- Latency thấp và throughput cao
- Hỗ trợ SSL với dữ liệu đang truyền đi, và mã hóa dữ liệu đã lưu trữ
- Chi phí rẻ hơn Standard-IA (~20%)
- Use-case: Sử dụng trong lưu trữ bản sao dự phòng thứ cấp của on-premise data, hoặc dữ liệu dễ dàng tạo lại

### Intelligent-Tiering

- Được thiết kế cho các object chưa xác định mức độ truy cập hoặc có mức độ truy cập không cố định. S3 sẽ theo dõi mức độ truy cập các object và chuyển chúng vào cấp truy cập phù hợp.
- 99.999999999% độ bền object (11 số 9)
- 99.9% độ khả dụng object
- Chi phí thấp cho việc monitor hàng tháng và chuyển đổi kiểu lưu trữ

### Glacier

- Được thiết kế cho việc lưu trữ dung lượng lớn, dài hạn
- Thời gian truy xuất dữ liệu có thể từ vài phút đến vài tiếng
- Mỗi item trong Glacier gọi là "**Archive**" (tối đa 40TB)
- Những Archives được lưu trữ trong "**Vaults**". Để dễ hình dung thì "Vaults" là folder ảnh về biển "Beach" còn "Archive" là những bức ảnh về bãi biển chứa trong vaults
- Glacier có 3 option truy xuất dữ liệu
  - Expedited (1-5 phút) (đắt hơn 2 option còn lại)
  - Standard (3-5 giờ)
  - Bulk (5-12 giờ)
- Thời gian lưu trữ tối thiểu là **90 ngày**

### Glacier Deep Archive

- Tương tự như Glacier nhưng sử dụng cho việc lưu trữ dài hạn hơn Glacier
- Chi phí rẻ hơn Glacier
- Là storage class có giá rẻ nhất
- Glacier Deep Archive có 2 option truy xuất dữ liệu
  - Standard (12 giờ)
  - Bulk (48 giờ)
- Thời gian lưu trữ tối thiểu là **180 ngày**

![s3 storage classes comparison](https://user-images.githubusercontent.com/29729545/151008602-30204774-5704-492b-a009-092785df81f5.png)
