---
title: "Elastic Load Balancer trong AWS"
description: "Load Balancer là 1 server dùng để forward traffic đến nhiêu server (Ec2...). Mỗi Target Group dùng để route request tới 1 hay nhiều target khác nhau. Như ở hình vẽ trê, ALB đặt các Rule Listener để định tuyến request."
keywords: [
  "Load Balancer là gì",
  "Load Balancer la gi",
  "Elastic Load Balancer trong aws",
  "Target Group trong ELB",
  "Target Group là gì",
  "Target Group la gi"
]
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
position: 9
---

## Elastic Load Balancer là gì

![ELB là gì](https://images.viblo.asia/08716e60-0e8c-443f-8487-d461fd66ccdf.png)

Từ hình vẽ trên chúng ta có thể hình dung được cách hoạt động của 1 load balancer là như thế nào. Load Balancer là 1 server dùng để forward traffic đến nhiêu server (Ec2...)

## Tại sao cần sử dụng Load Balancer?

- Chia traffic ra nhiều server khác để chia tải
- Expose ra 1 DNS để truy cập vào ứng dụng của bạn
  - Điểu này rất quan trọng, nếu chúng ta có 10 server con (ec2), chúng ta không thể truy cập 10 đường link khác nhau
  - Vì vậy giải pháp sử dụng ALB và truy cập ứng dụng qua 1 enpoint duy nhất là hiệu quả hơn
- ELB có thể tích hợp với rất nhiều dịch vụ của AWS
- Sử dụng health check cho instance của bạn
- Cung cấp HTTPS cho ứng dụng (sẽ được tìm hiểu ở phần ALB)
- HA cross zone

## Health Check

Đây là phần vô cùng quan trọng trong ứng dụng ELB. ![Health check trong ELB](https://i.ytimg.com/vi/fMgA3rE0aPY/maxresdefault.jpg)

- Đây là cách để ELB xác nhận xem EC2 có khả năng tiếp nhận request hay không (health)
- Load Balancer sẽ gửi định kỳ 1 request đến instance
  - Nếu response ok (200): server vẫn hoạt động bình thường
  - Nếu response khác: server đang gặp vấn đề, Load Balancer sẽ không gửi request đến server này nữa

## Security Group trong ELB

![Security trong Load Balancer](https://images.viblo.asia/1f07c53f-368e-4fe2-b85b-6d881aef19de.png)

- ELB chúng ta tạo 1 SG cho phép các request từ ngoài internet vào ELB qua cổng 80 (HTTP), 442(HTTPS) và sẽ chuyển request này đễn EC2 instance qua cổng 80 (HTTP)
- EC2 instance tạo 1 SG chỉ nhận request từ ELB qua cổng 80 (HTTP)
- Như vậy sẽ ko có 1 request nào từ internet có thể tấn công được vào EC2 instance

## Target Group trong AWS

![Target group trong AWS](https://static.cuongquach.com/resources/images/2019/04/aws-alb-target-group.png)

Mỗi Target Group dùng để route request tới 1 hay nhiều target khác nhau. Như ở hình vẽ trê, ALB đặt các **Rule Listener** để định tuyến request.

- Ví dụ:
  - Rule Listener ở port 80 (HTTP) sẽ forward request đến target group 1
  - Rule Listener ở port 443 (HTTPS) sẽ forward request đến target group 2
- Target type:
  - instance: EC2 instance được xác định bởi instance ID
  - ip: 1 địa chỉ IP (phải là private IP)
  - lambda: lambda function (chúng ta sẽ học ở phần serverless)
- Health check được thực hiện ở level target group
