---
title: "Routing Policy trong Route 53 (Phần 2)"
description: "Mỗi khi tạo một record mới, chúng ta cần chọn một Routing Policy. Đây là cách Route 53 phản hồi DNS queries. Routing Policies Simple định tuyến traffic tới một single resource."
keywords:
  [
    "Route 53 - Health Checks",
    "Routing policy la gi",
    "Routing policy là gì",
    "Routing policy trong Route 53",
    "Routing policy trong Route 53",
    "Routing policy - simple trong route 53",
    "Routing policy - weighted trong route 53",
    "Routing policy - latency trong route 53",
    "Routing policy - failover trong route 53",
    "Routing policy - geolocation trong route 53",
    "Routing policy - geoproximity trong route 53",
    "Routing policy - multi value trong route 53",
  ]
author:
  fullname: Phan Văn Đức
  username: ducpv
  avatar: "/configs/author/ducpv.jpg"
category:
  name: "Khóa học AWS từ cơ bản đến nâng cao"
  slug: "aws"
chapter:
  name: "Route 53"
  slug: "chap-07-route-53"
image: https://user-images.githubusercontent.com/29729545/150668689-58a59c45-5789-4d82-81c0-fac0166b10e6.png
position: 64
---

## Route 53 - Health Checks

Health Checks trong Route 53 chỉ được áp dụng với các public resource. Đây là một công cụ rất tốt để kiểm tra trạng thái của từng resource. Như phần trước mình có đề cập đến Routing Policy Latency, traffic sẽ gửi request đến region gần nhất với user. Tuy nhiên khi server ở Tokyo có vấn đề, thì không thể phản hồi lại response, do đó cần tạo Health Checks ở Route 53 để có thể quản lý phân tải.

- Health Checks có thể theo dõi các nhiều dạng endpoint khác nhau (Application , server, public resourch khác của AWS )
- Health Check có thể theo dõi các Health Check khác
- Healcheck cũng có thể theo dõi CloudWatch Alarms (Điều này rất có ích cho việc kiểm xoát các Private Resouce)
- Có 15 Healtch Checker đến từ khắp các nơi trên thế giới check endpoint chúng ta setup
  - Healthy/Unhealthy Threshold (Default : 3)
  - Interval (Time set Healthy or Unheathy) 30s (default)
  - Support method : HTTP, HTTPS, TCP
  - Nếu > 18% heath checker report endpoint là healthy thì Router 53 sẽ đánh giá là Healthy và ngược lại

## Routing Policies - Failover trong route 53

- Sử dụng khi bạn muốn chuyển đổi dự phòng
- DNS record có thể có chung **name và type**
- Nếu Primary có trạng thái healthy, route 53 sẽ response với primary record
- Nếu Primary có trạng thái un-healthy, route 53 sẽ response với secondary record 

![Routing Policies - Failover](https://user-images.githubusercontent.com/29729545/150668689-58a59c45-5789-4d82-81c0-fac0166b10e6.png)

## Routing Policies - Geolocation trong route 53

- Khác với Latency-based
- Sử dụng đinh tuyến dựa vào vị trí địa lý phía client.
- Bạn có thể định nghĩa user ở khu vực Asia sẽ request đến IP_A, user khu vực EU sẽ request đến IP_B chẳng hạn.
- Chúng ta cần tạo một record "Default" để sử dụng cho các user không được định nghĩa vị trí. 

![Routing Policies - Geolocation](https://i.stack.imgur.com/2baLZ.png)

## Routing Policies - Geoproximity trong route 53

- Sử dụng khi bạn muốn định tuyến lưu lượng dựa trên vị trí của tài nguyên của mình.
- Có thể thay đổi lưu lượng traffic bằng cách định nghĩa **bias**
  - Tăng bias (1...99): Tăng lưu lượng đến resource
  - Giảm bias (-1...-99): Giảm traffic đến resource
- Resource có thể là AWS resources hoặc Non-AWS resource
- **Cần dùng Route 53 Traffic Flow (advanced) để dử dụng tính năng này**
- Use-case: Ví dụ Facebook có 2 máy chủ ở Việt Name có IP là A và B, A được đặt ở Hà Nội và B đặt ở HCM. Bias sẽ quy định user ở Huế, Đà Năng sẽ truy cập đến máy chủ nào. 

![Routing Policies - Geoproximity](https://user-images.githubusercontent.com/29729545/150670334-0d757e9f-acac-4018-8238-97888873c8f8.png)

## Route 53 - Multi Value trong route 53

- Sử dụng khi routing traffic đến multi resources
- Route 53 trả về multiple values/resources
- Có thể sử dụng với Healthy Check (chỉ return cho healthy resources)
- Mỗi query Multi-Value có thể return 8 healthy record
- Multi-Value không phù hợp ELB

| Name           | Type     | Value       | TTL | SetID | Health check   |
| -------------- | -------- | ----------- | --- | ----- | -------------- |
| www.sample.com | A record | 192.11.44.1 | 60  | Web 1 | A Health check |
| www.sample.com | A record | 182.41.24.3 | 60  | Web 2 | B Health check |
| www.sample.com | A record | 193.16.49.1 | 60  | Web 3 | C Health check |
