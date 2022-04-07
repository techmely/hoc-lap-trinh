---
title: "Địa chỉ IP trong EC2"
description: "Mỗi EC2 cần được cung cấp địa chỉ IP để được định danh trên AWS và trên môi trường internet. Chúng ta sẽ làm quen với 3 loại IP (public/private/elastic)"
keywords:
  ["Private IP trong EC2", "Public IP trong EC2", "Elastic IP trong EC2"]
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
image: https://user-images.githubusercontent.com/29729545/162227832-5b45cf1f-be45-4461-985c-3bdae5478519.png
position: 5
---
![Địa chỉ IP trong EC2](https://user-images.githubusercontent.com/29729545/162227832-5b45cf1f-be45-4461-985c-3bdae5478519.png)

Mỗi EC2 cần được cung cấp địa chỉ IP để được định danh trên AWS và trên môi trường internet. Chúng ta sẽ làm quen với 3 loại IP (public/private/elastic), mỗi loại IP có tác dụng khác nhau trên AWS cũng như trên internet.

#### Networking IPs

Trong networking có 2 loại IPs: **IPv4** và **IPv6**:<br/>

- `IPv4`: 1.222.33.22
- `IPv6`: format y:y:y:y:y:y:y:y

Hiện tại IPv4 vẫn phổ biến nhất<br/> IPv6 ra đời mới hơn IPv4 và giải quyết tốt các bài toán về IoT<br/> IPv4 format: [0-255].[0-255].[0-255].[0-255]

#### Public IP trong EC2

- Một máy có public IP có nghĩa được định danh trên internet
- IP đó phải là duy nhất trên internet (không có chuyện 2 máy có chung public IP)
- Public IP có thể được định danh vị trí địa lý (Có thể biết IP đó ở khu vực nào)

#### Private IP trong EC2

- Private IP tương ứng với máy được định danh trong private network (Mạng trong một công ty)
- IP đó phải là duy nhất trong private network
- 2 private network khác nhau có thể trùng IPs với nhau
- Máy tính trong private network cần sử dụng Internet Getway để có thể truy cập internet

#### Elastic IP trong EC2

- Khi stop/start lại 1 EC2 instance, public IP sẽ thay đổi
- Nếu muốn có 1 static IP hãy sử dụng Elastic IP
- EIP: là 1 IPv4 và có thể attach vào 1 EC2 instance
- Mặc định mỗi account chỉ có thể tạo 5 EIP, có thể request AWS để tạo được nhiều hơn

<content-info>
Cố gắng hạn chế sử dụng EIP
<ul>
  <li>Thay vì vậy có thể sử dụng DNS name kết hợp với Route 53</li>
  <li>Hoặc sử dụng 1 Load Balancer</li>
<ul>
</content-info>
