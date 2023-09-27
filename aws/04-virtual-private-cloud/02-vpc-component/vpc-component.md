---
title: "Các components trong VPC"
description: "ENI đại diện như 1 card mạng ảo (virtual network card). Route tables chứa những rules giúp định tuyến network traffic. Internet Getway giúp traffic trong VPC có thể giao tiếp ra ngoài internet"
chapter:
  name: "Virtual Private Cloud"
  slug: "chap-04-vpc"
image: https://user-images.githubusercontent.com/29729545/166088006-6c5d114a-63e7-4a0b-9398-919f19b0204e.png
position: 17
---

## VPC networking components

### ENI (Elastic Network Intefaces) trong AWS

- ENI đại diện như 1 card mạng ảo (_virtual network card_)
- Thuộc tính chính của ENI:
  - 1 primary private IPv4 trong range IP của VPC/subnet
  - 1 hay nhiều secondary private IPv4 trong range IP của VPC/subnet
  - 1 Elastic IP address (IPv4) per private IPv4 address
  - 1 public IPv4 address
  - 1 hay nhiều IPv6 addresses
  - 1 hay nhiều security group
  - 1 MAC address (Media Access Control)

Khi 1 instance EC2 được tạo trong VPC, nó sẽ tự động tạo 1 Network Interface và attach vào EC2. NI(Network interface) default này là _primate network interface_, và ko thể detach NI này. Tuy nhiên, bạn có thể tạo thêm 1 NI khác được gọi là _secondary network interfaces_, NI này có thể detach hay atach vào instance khác

### Route table trong AWS

_Route tables_ chứa những rules giúp định tuyến network traffic

- Mỗi VPC cần có 1 Route table, nó không thể bị xóa đi, chỉ có thể modify

### Internet Getway trong AWS

**Internet Getway** giúp EC2 instances có thể giao tiếp ra ngoài internet

- Mỗi VPC chỉ có thể attached tới 1 IGW và ngược lại
- Nếu 1 subnet được liên kết với route table và routed đến 1 IGW thì đó là _public subnet_
- Ngược lại, nếu 1 subnet được liên kết trong route table và không routed đến IGW thì đó là _private subnet_
  ![VPC](https://user-images.githubusercontent.com/29729545/166088006-6c5d114a-63e7-4a0b-9398-919f19b0204e.png)

### Egress-only IGW trong AWS

- Chỉ làm việc với IPv6
- Cho phép resource connect ra bên ngoài internet, nhưng prevent bên ngoài internet connect với resource bên trong subnet hay VPC
