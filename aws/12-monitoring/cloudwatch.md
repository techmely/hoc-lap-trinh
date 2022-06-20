---
title: "Giới thiệu CloudWatch"
description: "AWS CloudWatch là một dịch vụ giúp giám sát, tổng hợp, phân tích dữ liệu, nguồn tài nguyên chạy trên AWS. Dịch vụ này giúp cung cấp thông tin thực tiễn một cách realtime, cho phép giám sát các vùng nhớ của ứng dụng"
keywords:
  [
    "CloudWatch la gi",
    "CloudWatch là gì",
    "CloudWatch trong aws",
    "CloudWatch Metrics trong AWS",
    "Log trong CloudWatch",
    "CloudWatch Log la gi",
    "CloudWatch Log là gì",
    "CloudWatch Agent la gi",
    "CloudWatch Agent là gì",
    "CloudWatch Alarms la gi",
    "CloudWatch Alarms là gì",
    "CloudWatch Logs metric filter la gi",
    "CloudWatch Logs metric filter là gì",
  ]
author:
  fullname: Phan Văn Đức
  username: ducpv
  avatar: "/configs/author/ducpv.jpg"
category:
  name: "Khóa học AWS từ cơ bản đến nâng cao"
  slug: "aws"
chapter:
  name: "Monitoring & Audit"
  slug: "chap-12-monitoring"
image: https://user-images.githubusercontent.com/29729545/172035832-f10e7f18-5289-4309-a3e8-cf5e9bf9113e.png
position: 221
---

## CloudWatch là gì

AWS CloudWatch là một dịch vụ giúp giám sát, tổng hợp, phân tích dữ liệu, nguồn tài nguyên chạy trên AWS. Dịch vụ này giúp cung cấp thông tin thực tiễn một cách realtime, cho phép giám sát các vùng nhớ của ứng dụng, cơ sở hạ tầng và dịch vụ ví dụ như Ram, Disk,... và sử dụng cảnh báo, tự động hành động; hỗ trợ việc tối ưu hóa hiệu suất ứng dụng, quản lý sử dụng tài nguyên và hiểu rõ tình trạng hoạt động của toàn hệ thống.

## CloudWatch Metrics trong AWS

- CloudWatch cung cấp các metric cho mọi dịch vụ trên AWS
- Metric là một biến số dùng để monitor (lượng CPU sử dụng, NetworkIn, NetworkOut...)
- Mỗi metric thuộc về một **Namespaces**
- **Dimensions** là một attribute của metric được biểu diễn dưới dạng _key/value_ (instance id, environment,...)
- Mỗi metric có tối đa 10 dimensions
- Mỗi metric data point cần được liên kết với một timestamp
- Bạn có thể tạo các custome metric bằng cách sử dụng API call **PutMetricData**

## CloudWatch Logs là gì

CloudWatch Logs là dịch vụ ghi lại log của hệ thống hoặc của các dịch vụ AWS khác

- **Log groups**: có thể một tên bất kỳ, thường là tên đại diện của ứng dụng
- **Log stream**: là tập hợp con của log groups, log stream chứa các log event (các message)
- Bạn có thể xác định thời gian tồn tại của log (forever, 30days,...)

## CloudWatch Logs Metric Filter & Insights

- CloudWatch Logs có thể dùng một hoặc nhiều _metric filter_ để search hoặc lọc dữ liệu
  - Ví dụ: tìm số message "Error" trong log của bạn
- Metric filters có thể dùng để trigger CloudWatch Alarm
- **CloudWatch Logs Insights** có thể được dùng để query log đơn giản

## CloudWatch Agent là gì

- Mặc định EC2 sẽ không thể gửi log đến CloudWatch
- Bạn cần chạy **CloudWatch Agent** trên EC2 để push log theo ý muốn

![CloudWatch Agent](https://user-images.githubusercontent.com/29729545/172035832-f10e7f18-5289-4309-a3e8-cf5e9bf9113e.png)

## CloudWatch Alarms là gì

- Dùng để trigger thông báo cho metric đã được định nghĩa
- Có nhiểu option để lựa chọn phân tích (sampling, %, max, min,...)
- Alarm states:
  - OK
  - INSUFFICIENT_DATA (không đủ data point để quyết đinh OK hay ALARM)
  - ALARM
- Period:
  - Khoảng thời gian (tính theo giây) để tính toán metric

## EC2 Instance Recovery

Bạn có thể dùng một CloudWatch Alarm để monitor EC2 instance của bạn. Alarm sẽ theo dõi **"StatusCheckFailed_System"** metric, từ đó sẽ đưa ra các cảnh báo và recovery lại một EC2 instance mới. Instance mới này được giữa nguyên Private/Public IP, Elastic IP, metadata...
