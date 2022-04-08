---
title: "Chi phí sử dụng EC2"
description: "Tùy theo cấu hình EC2 mình chọn, AWS sẽ tính tiền dựa trên những lựa chọn của mình. Khi bạn chạy những ứng dụng lâu bền, AWS cung cấp reserved instance. Bạn có thể trả trước tiền (1 phần, hoặc trả tất), hoặc commit sử dụng lâu dài. Khi đó AWS sẽ discount giá"
keywords:
  [
    "Chi phí EC2",
    "Chi phi EC2",
    "Giá EC2",
    "gia ec2",
    "On-demand trong AWS là gì",
    "On-demand trong AWS la gi",
    "On-demand instance là gì",
    "On-demand instance la gi",
    "Spot instances là gì",
    "Reserved instances là gì",
    "Dedicated hosts là gì",
    "Spot instances la gi",
    "Reserved instances la gi",
    "Dedicated hosts la gi",
  ]
author:
  fullname: Phan Văn Đức
  username: ducpv
  avatar: "/configs/author/ducpv.jpg"
category:
  name: "Khóa học AWS từ cơ bản đến nâng cao"
  slug: "aws"
chapter:
  name: "Elastic Compute Cloud"
  slug: "ec2"
image: https://user-images.githubusercontent.com/29729545/162227316-62f67100-d142-4a64-9c78-8f15b94143ac.png
position: 4
---

## Cách tính tiền dịch vụ EC2
![Chi phí EC2](https://user-images.githubusercontent.com/29729545/162227316-62f67100-d142-4a64-9c78-8f15b94143ac.png)
**AWS cung cấp 4 option để trả phí với EC2**

- On-demand
- Spot instances
- Reserved instances
- Dedicated hosts

### 1. On-demand instance là gì

Tùy theo cấu hình EC2 mình chọn, AWS sẽ tính tiền dựa trên những lựa chọn của mình

- Tính tiền theo thời gian sử dụng thực tế (Chỉ tính tiền khi state running)
- Option đắt tiền nhất

### 2. Spot instances là gì

Bạn sẽ bid (đấu thầu) giá **max_price** mà mình muốn trả, pot instance sẽ có **current_price** và current_price này sẽ thay đổi theo thời gian <br /> AWS sẽ lấy lại spot instance của bạn khi **max_price** < **current_price**

- Dùng cho những ứng dụng flexible, có thể bị interrupted

### 3. Reserved instances là gì

Khi bạn chạy những ứng dụng lâu bền, AWS cung cấp reserved instance. Bạn có thể trả trước tiền (1 phần, hoặc trả tất), hoặc commit sử dụng lâu dài. Khi đó AWS sẽ discount giá

### 4. Dedicated hosts là gì

Là thuê luôn phần cứng của AWS, phần cứng đó sẽ được AWS cung cấp chỉ cho bạn sử dụng.

- Phù hợp cho ứng dụng license model phức tạp (BYOL- Bring your own license)
- Hoặc cho các công ty có rule về bảo mật (Họ không muốn sử dụng chung phần cứng với các công ty khác trên môi trường AWS)

Về chi chí khi sử dụng Dedicated hosts, chúng ta có thể chọn những option mà AWS đưa ra:

- On-demand Dedicated hosts: Dùng bao nhiêu trả tiền bấy nhiêu
- Dedicated hosts Reservations: Cam kết thời gian sử dụng, hay trả tiền trước...
- Saving plan: là cách tiết kiệm chi phí bằng cách cam kết mức sử dụng (tính theo USD/giờ) ví dụ cam kết sử dụng 0.6$/giờ trong 1 khoảng thời gian là 1 hoặc 3 năm, khi đó giá của bạn sẽ giảm lên tới 66% so với on-demand

Keyword gặp trong exam: **compliance requirement** and **use your existing server-bound software licenses**
