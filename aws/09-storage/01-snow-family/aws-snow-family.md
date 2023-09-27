---
title: "Giới thiệu AWS Snow Family"
description: "AWS Snow Family là tập hợp những thiết bị vật lý giúp cho việc migrate dữ liệu từ bên ngoài vào AWS hoặc ngược lại, từ AWS ra bên ngoài. Giải pháp migrate dữ liệu này không phụ thuộc vào các yếu tố của network (tốc độ, băng thông)."
chapter:
  name: "Mở rộng storage"
  slug: "chap-09-cloud-storage"
image: https://user-images.githubusercontent.com/29729545/153702726-8c021c92-5402-490f-8036-5ba008edf4d5.png
position: 91
---

## AWS Snow Family là gì

Trước tiên mình sẽ đưa ra một bài toán chúng ta sẽ cùng thảo luận. Nếu mình muốn upload dữ liệu có dung lượng hàng TetaByte lên một S3 Bucket.

|        | 100Mbps  | 1Gbps    | 10Gbps   |
| ------ | -------- | -------- | -------- |
| 10 TB  | 12 days  | 30 hours | 3 hours  |
| 100 TB | 124 days | 12 days  | 30 hours |
| 1 PB   | 3 years  | 124 days | 12 days  |

Như các bạn có thể thấy để upload một khối dữ liệu có size là 1 PB cần 3 năm với băng thông 100Mbps, hay 124 ngày với băng thông 1Gbps. Thật stress khi ngồi chờ dữ liệu được upload thành công. Ngoài ra chúng ta sẽ phải bị ảnh hưởng bởi nhiều yếu tố như:

- Kết nối có vấn đề
- Chi phí network cao
- Bandwidth không ổn định...

Đừng lo về vấn đề này, Amazon sẽ giúp bản giải quyết những vấn đề này với dịch vụ **AWS Snow Family**.

**Vậy AWS Snow Family là gì ?**

AWS Snow Family là tập hợp những thiết bị vật lý giúp cho việc thu thập và phân tích dữ liệu; hay migrate dữ liệu từ bên ngoài vào AWS hoặc ngược lại, từ AWS ra bên ngoài. Giải pháp migrate dữ liệu này không phụ thuộc vào các yếu tố của network (tốc độ, băng thông). Nếu dữ liệu của bạn cần nhiều hơn 1 tuần để có thể tranfer qua internet, hãy nghĩ đến những thiết bị Snowball.

![AWS Snow Family là gì](https://user-images.githubusercontent.com/29729545/153702726-8c021c92-5402-490f-8036-5ba008edf4d5.png)

AWS Snow Family sử dụng trong 2 usecase chính đó là:

- Data migration: có 3 loại devices
  - **Snowcone**
  - **Snowball Edge**
  - **Snowmobile**
- Edge computing: (thu phập, phân tích dữ liệu trước khi chuyển tới AWS)
  - **Snowcone**
  - **Snowball Edge**

## Snowball Edge là gì (dùng cho data tranfers)

![Snowball Edge](https://cafedev.vn/wp-content/uploads/2021/02/cafedev-aws-snowball3.png)

- Là thiết bị truyền dữ liệu dung lượng lớn (TBs, PBs) vào hoặc ra khỏi AWS
- Trả tiền trên mỗi data transfer job
- Có thể cung cấp số lượng lớn storage hoặc những function tính toán
- **Snowball Edge Storage Optimized**: tối ưu hóa về lưu trữ
- **Snowball Edge Compute Optimized**: tối ưu hóa về tính toán
- Use case: migrate lượng dữ liệu lớn, disaster recovery

## AWS Snowcone là gì

![AWS Snowcone](https://d1.awsstatic.com/cloud-storage/Storage/AWS-Snowcone.650f397305c8b7e9891b72d6b6dd490b0985e735.png)

- AWS Snowcone là thành viên nhỏ nhất trong AWS Snow family, Snowcone an toàn, bảo mật và có thể **chịu được môi trường khắc nhiệt.** (dưới nước, thời tiết...)
- Được dùng trong mục đích Edge computing, lưu trữ hay tranfer dữ liệu
- **8 TBs dung lượng lưu trữ**
- Bạn cần tự cung cấp nguồn, cap mạng để sử dụng Snowcone
- Có thể gửi lại Snowcone cho AWS hoặc kết nối tới internet và dùng **AWS DataSync** để gửi dữ liệu

## AWS Snowmobile là gì

- AWS Snowmobile thực ra là một chiếc xe tải hay container
- Dùng để transfer dữ liệu rất lớn, mỗi Snowmobile có sức chứa 100 PB dữ liệu
- Có thể transfer dữ liệu lên tới exabytes (1 EB = 1000 PB = 1000000TBs)
- Có hệ thống giám sát, định vị 24/7, mỗi chiếc xe có hệ thống quản lý nhiệt độ
- **Nên sử dụng Snowmobile khi transfer dữ liệu lớn hơn 10 PB**

|                  | Snowcone                          | Snowball                                            | Snowmobile                |
| ---------------- | --------------------------------- | --------------------------------------------------- | ------------------------- |
| Storage capacity | 8 TB usable                       | 80 TB usable                                        | < 100 PB                  |
| Migrate size     | Lên tới 24TB, online hoặc offline | Lên tới petabytes, offline                          | Lên tới exabytes, offline |
| DataSync         | Pre-installed                     |                                                     |                           |
| Storage Cluter   |                                   | Có thể đặt tối đa 15 nodes để tăng khả năng lưu trữ |                           |

::alert{type="infor"}
Snowball không thể import trực tiếp data vào Glacier. Bạn cần import vào các storage class khác (ví dụ Standard IA), sau đó dùng đến S3 lifecycle để chuyển sang Glacier.
::
