---
title: "Giới thiệu về High Availability và Scalability"
description: "High availability có nghĩa “Độ sẵn sàng cao”. Tức là máy chủ luôn trong tình trạng hoạt động tốt và có tĩnh sẵn sàng cao"
keywords: ["availability là gì", "high availability là gì"]
author:
  fullname: Phan Văn Đức
  username: ducpv
  avatar: "/configs/author/ducpv.jpg"
category:
  name: "Khóa học AWS từ cơ bản đến nâng cao"
  slug: "aws"
chapter:
  name: "High Availability"
  slug: "ha"
position: 8
---

Đến đây chúng ta sẽ đi tìm hiểu sâu hơn về thiết kế một kiến trúc tốt trong AWS. Hệ thống máy tính cần yêu cầu tính sẵn sàng cao, đảm bảo hoạt động tốt 24/7. Do đó High Availability (HA) ra đời nhằm đem lại giải pháp tốt cho sản phẩm phần mềm.

## HA là gì?

Vậy HA hay High Availability là gì?

Có thể hình dung đơn giản cần tối thiểu 2 máy chủ cùng chạy song song và hoạt động liên tục. Nếu xảy ra tình huống một máy chủ gặp sự cố thì máy còn lại sẽ thay thế nhằm giúp hệ thống vẫn tiếp tục hoạt động bình thường.

## Lợi ích của high availability là gì?

Với một hệ thống lớn hệ thống đảm bảo tính sẵn sàng cao là vô cùng quan trọng. Một trang chắc hẳn ai cũng dùng đó là Facebook, HA đảm bảo cho trang mạng xã hội này luôn hoạt động tốt.

Tiếp đến là về đảm bảo dữ liệu được lưu trữ ở nhiều nơi. Khi có bất kỳ sự cố xảy ra trên VPS thì không gây ảnh hưởng hay làm mất mát dữ liệu nghiêm trọng.

## HA cần những thành phần nào?

- **Redundancy**: (Dự phòng) Đảm bảo rằng các thành phần, dữ liệu quan trọng của hệ thống có một bản cloned giống hệt khác có cùng dữ liệu có thể tiếp quản trong trường hợp bị lỗi.
- **Monitoring**: Hệ thống cần được giám sát để có thể kiểm soát cũng như xử lý các tính huống gặp phải
- **Failover**: Khả năng chuyển đổi giữa hệ thống đang chạy sang hệ thống dự phòng
- **Failback**: Khả năng chuyển trở lại từ thành phần dự phòng thành thành phần hoạt động chính khi nó đã khôi phục sau lỗi.

## Scalability là gì

Scalability là ứng dụng của bạn có khả năng mở rộng một cách nhanh chóng để đối ứng với những vấn đề phát sinh. Ví dụ như website của bạn 1 ngày nào đó tự nhiên trở nên hot và có quá nhiều người truy cập vào , khi đó với tài nguyên hiện hữu thì application của bạn không đủ khả năng phục vụ hết tất cả mọi người, khi đó chúng ta cần scale nó lên .

Có 2 loại scalability:

- **Vertical Scalability**: có nghĩa là mở rộng theo chiều sâu
  - Ví dụ bạn đang làm task với junior member, sau đó có nhiều việc hơn leader chuyển sang 1 senior member làm việc đó.
- **Horizontal scalability**: mở rộng theo chiều ngang
  - Ví dụ bạn đang làm task với junior member, sau đó có nhiều việc hơn leader tuyển thêm 2-3 junior member để làm cho xong việc đó

High Availability không phải là Scalability nhưng chúng có liên quan đến nhau. Chúng kết hợp với nhau để đưa ra một kiến trúc AWS tốt hơn.
