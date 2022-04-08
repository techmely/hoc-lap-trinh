---
title: "Giới thiệu Storage Gateway"
description: "Hybrid Cloud là concept được dùng đến khi một phần ứng dụng hay dữ liệu của bạn nằm trên Cloud và một phần nằm ở on-premise. Vì đặc thù từng loại dự án yêu cầu bảo mật, khách hàng không muốn tất cả dữ liệu của họ được đưa lên Cloud. AWS Storage Gateway là dịch vụ hybrid cloud storage cung cấp cho bạn khả năng kết nối on-premise với storage trên Cloud (S3)."
keywords:
  [
    "Hybrid Cloud for Storage là gì",
    "Hybrid Cloud for Storage la gi",
    "Hybrid Cloud for Storage trong AWS",
    "AWS Storage Gateway là gì",
    "AWS Storage Gateway la gi",
    "AWS Storage Gateway trong AWS",
    "AWS File Gateway là gì",
    "AWS File Gateway la gi",
    "AWS File Gateway trong AWS",
    "AWS Volume Gateway là gì",
    "AWS Volume Gateway la gi",
    "AWS Volume Gateway trong AWS",
    "AWS Tape Gateway là gì",
    "AWS Tape Gateway la gi",
    "AWS Tape Gateway trong AWS",
  ]
author:
  fullname: Phan Văn Đức
  username: ducpv
  avatar: "/configs/author/ducpv.jpg"
category:
  name: "Khóa học AWS từ cơ bản đến nâng cao"
  slug: "aws"
chapter:
  name: "Mở rộng storage"
  slug: "cloud-storage"
position: 94
---

## Hybrid Cloud for Storage

"Hybrid Cloud" là concept được dùng đến khi một phần ứng dụng hay dữ liệu của bạn nằm trên Cloud và một phần nằm ở on-premise. Vì đặc thù từng loại dự án yêu cầu bảo mật, khách hàng không muốn tất cả dữ liệu của họ được đưa lên Cloud. **AWS Storage Gateway** là dịch vụ hybrid cloud storage cung cấp cho bạn khả năng kết nối on-premise với storage trên Cloud (thường là S3). ![Hybrid Cloud for Storage](https://d1.awsstatic.com/pdp-how-it-works-assets/product-page-diagram_AWS-Storage-Gateway_HIW@2x.6df96d96cdbaa61ed3ce935262431aabcfb9e52d.png) Có 3 loại Storage Gateway bao gồm:

- File Gateway
- Volume Gateway
- Tape Gateway

## File Gateway

- Cấu hình cho phép truy cập S3 bucket sử dụng NFS/SMB protocol
- Hỗ trợ **S3 standard, S3 IA, S3 One Zone IA**
- Dữ liệu sử dụng được cached lại ở file gateway => Giảm độ trễ
- Có thể mounted nhiều server khác nhau
- Sử dụng **Active Directory (AD)** cho user authentication

![File Gateway](https://user-images.githubusercontent.com/29729545/153909576-6789f647-f2f9-4d0a-bf19-993e0aec4404.png)

## Volume Gateway

- Block storage sử dụng iSCSI
- Bạn sẽ lưu lại dữ liệu của mình bằng EBS snapshot, từ đó có thể restore volume của on-premise
- Có 2 loại:
  - **Cached volume**: Độ trễ thấp truy cập đến những dữ liệu thường xuyên truy cập
  - **Stored volume**: Toàn bộ dữ liệu trên on-premise, scheduled backup lên S3

![Volume Gateway](https://user-images.githubusercontent.com/29729545/154086310-497a2c10-cfcf-4170-9547-5911854ae7ad.png)

## Tape Gateway (Tape: băng đĩa)

- Tape Gateway chủ yếu được sử dụng để sao lưu dữ liệu
- Tape Gateway cho phép thay thế việc sử dụng các tape vật lý trên on-premise bằng các Virtual Tape trên AWS

![Tape Gateway](<https://d1.awsstatic.com/product-marketing/Product-Page-Diagram_Tape-Gateway_HIW%402x%20(2).5ba3326ea93003722acc487804a34971613ec3c1.png>)

## Storage Gateway Hardware Appliance

- Nếu sử dụng Storage Gateway, ứng dụng của bạn được kết nối với qua máy ảo (cần on-premise virtualization)
- Tuy nhiên bạn có thể lựa chọn sử dụng **Storage Gateway Hardware Appliance**, đây là thiết bị có thể đặt mua qua amazon.com
- Hoạt động với cả 3 loại Gateway: File Gateway, Volume Gateway và Tape Gateway
- Thiết bị có Memory, Network, CPU và SSD
- Sử dụng tốt cho việc backup NFS hằng ngày trong những data center nhỏ

![Storage Gateway Hardware Appliance](https://d2908q01vomqb2.cloudfront.net/e1822db470e60d090affd0956d743cb0e7cdf113/2020/08/12/AWS-Storage-Gateway-Hardware-Appliance-photo1.png)
