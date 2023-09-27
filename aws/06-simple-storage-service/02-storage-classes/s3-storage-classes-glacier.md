---
title: "Giới thiệu S3 Storage Classes, Glacier"
description: "Amazon S3 cung cấp một loạt các lớp lưu trữ mà bạn có thể lựa chọn dựa trên các yêu cầu về quyền truy cập dữ liệu, khả năng phục hồi và chi phí tương ứng với khối lượng công việc. Các lớp lưu trữ S3 được xây dựng nhằm mục đích cung cấp khả năng lưu trữ với chi phí thấp nhất cho các kiểu truy cập khác nhau. Lớp lưu trữ S3 lý tưởng cho hầu hết mọi trường hợp sử dụng, bao gồm cả những trường hợp có nhu cầu hiệu năng cao, yêu cầu lưu trữ dữ liệu, kiểu truy cập không xác định hoặc hay thay đổi, hoặc dùng để lưu trữ."
chapter:
  name: "Simple Storage Serivce"
  slug: "chap-06-s3"
position: 57
---

## S3 Storage Classes trong AWS

Amazon S3 cung cấp một loạt các lớp lưu trữ mà bạn có thể lựa chọn dựa trên các yêu cầu về quyền truy cập dữ liệu, khả năng phục hồi và chi phí tương ứng với khối lượng công việc. Các lớp lưu trữ S3 được xây dựng nhằm mục đích cung cấp khả năng lưu trữ với chi phí thấp nhất cho các kiểu truy cập khác nhau. Lớp lưu trữ S3 lý tưởng cho hầu hết mọi trường hợp sử dụng, bao gồm cả những trường hợp có nhu cầu hiệu năng cao, yêu cầu lưu trữ dữ liệu, kiểu truy cập không xác định hoặc hay thay đổi, hoặc dùng để lưu trữ.

Các storage class hiện có bao gồm:

- Standard
- Standard-Infrequent Access (Standard-IA)
- One Zone-Infrequent Access (One Zone-IA)
- Intelligent-Tiering
- Glacier
- Glacier Deep Archive

Mỗi storage class khác nhau có các thuộc tính khác nhau về: Chi phí, Độ khả dụng (availability), Độ bền (durability), Mức độ truy cập (frequency)

### S3 Standard là gì - General Purpose

- Là class thông dụng nhất
- Được thiết kế cho tất cả các mục đích lưu trữ
- Là lựa chọn mặc định
- 99.999999999% độ bền object (11' 9)
- 99.99% độ khả dụng object
- Có chi phí cao nhất
- Use-case: Dùng cho phân tích dữ liệu, Mobile & gaming application, content distribution...

### S3 Standard-Infrequent Access (Standard-IA) là gì

- Được thiết kế cho các object không được truy cập thường xuyên nhưng cần phải khả dụng ngay lập tức khi được truy cập.
- 99.999999999% độ bền object (11' 9)
- 99.9% độ khả dụng object
- Chi phí rẻ hơn Standard
- Use-case: Dữ liệu backup cho phục hồi khi thiên tai...

### S3 One Zone-Infrequent Access (One Zone-IA) là gì

- Tương tự như IA nhưng được lưu trữ ở một single AZ
- 99.999999999% độ bền object (11 số 9) trong single AZ, nếu AZ đó bị phá hủy, dữ liệu sẽ bị mất đi
- Latency thấp và throughput cao
- Hỗ trợ SSL với dữ liệu đang truyền đi, và mã hóa dữ liệu đã lưu trữ
- Chi phí rẻ hơn Standard-IA (~20%)
- Use-case: Sử dụng trong lưu trữ bản sao dự phòng thứ cấp của on-premise data, hoặc dữ liệu dễ dàng tạo lại

### S3 Intelligent-Tiering là gì

- Được thiết kế cho các object chưa xác định mức độ truy cập hoặc có mức độ truy cập không cố định. S3 sẽ theo dõi mức độ truy cập các object và chuyển chúng vào cấp truy cập phù hợp.
- 99.999999999% độ bền object (11 số 9)
- 99.9% độ khả dụng object
- Chi phí thấp cho việc monitor hàng tháng và chuyển đổi kiểu lưu trữ

### S3 Glacier là gì

- Được thiết kế cho việc lưu trữ dung lượng lớn, dài hạn
- Thời gian truy xuất dữ liệu có thể từ vài phút đến vài tiếng
- Mỗi item trong Glacier gọi là "**Archive**" (tối đa 40TB)
- Những Archives được lưu trữ trong "**Vaults**". Để dễ hình dung thì "Vaults" là folder ảnh về biển "Beach" còn "Archive" là những bức ảnh về bãi biển chứa trong vaults
- Glacier có 3 option truy xuất dữ liệu
  - Expedited (1-5 phút) (đắt hơn 2 option còn lại)
  - Standard (3-5 giờ)
  - Bulk (5-12 giờ)
- Thời gian lưu trữ tối thiểu là **90 ngày**

### S3 Glacier Deep Archive là gì

- Tương tự như Glacier nhưng sử dụng cho việc lưu trữ dài hạn hơn Glacier
- Chi phí rẻ hơn Glacier
- Là storage class có giá rẻ nhất
- Glacier Deep Archive có 2 option truy xuất dữ liệu
  - Standard (12 giờ)
  - Bulk (48 giờ)
- Thời gian lưu trữ tối thiểu là **180 ngày**

![s3 storage classes comparison](https://user-images.githubusercontent.com/29729545/151008602-30204774-5704-492b-a009-092785df81f5.png)

## Exam tips
- Dữ liệu cần độ trễ truy cập dữ liệu thấp (latency sensitive), truy cập thường xuyên (frequently access) => **Standard Tier**
- Dữ liệu ít truy cập (Infrequently Access) => **IA**
- Dữ liệu ít truy cập (Infrequently Access), dữ liệu có thể khôi phục nếu một AZ bị sự cố => **One-Zone IA**
- Dữ liệu lưu trữ lâu dài(1~10 năm),thời gian lấy dữ liệu từ phút tới < 12giờ => **Glacier**
- Dữ liệu lưu trữ lâu dài ( > 10 năm), thời gian lấy dữ liệu > 12 hours => **Deep Archived**