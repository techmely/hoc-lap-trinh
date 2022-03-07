---
title: "Docker là gì?"
description: "Bài đầu tiên chúng ta sẽ cùng nhau tìm hiểu xem docker là gì gì nhé."
keywords:
  [
    "docker là gì",
    "container docker là gì",
    "docker la gi",
    "tìm hiểu docker là gì",
    "tim hieu docker la gi",
  ]
chapter:
  name: "Nhập môn docker"
  slug: "chuong-01-nhap-mon-docker"
category:
  logo: "/language/docker.png"
  name: "Docker"
  slug: "docker"
  description: "Học Docker từ cơ bản đến thông thạo cho mọi đối tượng"
image: https://kungfutech.edu.vn/thumbnail.png
position: 1
---

## Docker là gì?

Docker là một nền tảng để cung cấp cách để building, deploying và running ứng dụng dễ dàng hơn bằng cách sử dụng các containers (trên nền tảng ảo hóa). Ban đầu viết bằng Python, hiện tại đã chuyển sang Golang.

- Docker là một nền tảng mở cho phát triển, vận chuyển và chạy ứng dụng.
- Docker cho phép bạn tách các ứng dụng ra khỏi cơ sở hạ tầng của mình để có thể cung cấp phần mềm một cách nhanh chóng.
- Với Docker, bạn có thể quản lý cơ sở hạ tầng theo cùng cách quản lý ứng dụng của mình.
- Bằng cách tận dụng các phương pháp của Docker để vận chuyển, thử nghiệm và triển khai mã một cách nhanh chóng, bạn có thể làm giảm đáng kể sự chậm trễ giữa việc viết mã và chạy nó trong sản xuất

![Docker là gì?](https://viblo.asia/uploads/027c723e-f029-4bc7-bd4e-6f5239aa3f92.png)

## Docker platform

Docker cung cấp khả năng đóng gói và chạy một ứng dụng trong một môi trường tách biệt lỏng lẻo gọi là container. Docker giúp cách ly và bảo mật, cho phép bạn chạy nhiều containers đồng thời trên một máy chủ nhất định. Các containes là light weight và chúng không cần tải thêm của một hypervisor, chạy trực tiếp trên kernel của máy chủ. Điều này có nghĩa là bạn có thể chạy nhiều contains hơn trên một kết hợp phần cứng nhất định hơn là nếu bạn đang sử dụng các máy ảo. Bạn thậm chí có thể chạy các container Docker trong máy chủ lưu trữ mà thực sự là các máy ảo!

Docker cung cấp công cụ và nền tảng để quản lý vòng đời của các containers của bạn:

- Phát triển ứng dụng của bạn và các thành phần hỗ trợ bằng cách sử dụng các containers.
- Các container trở thành đơn vị phân phối và thử nghiệm ứng dụng của bạn.
- Khi bạn đã sẵn sàng, triển khai ứng dụng của bạn vào môi trường production, dưới dạng container hoặc orchestrated service. Điều này hoạt động giống nhau cho dù môi trường sản xuất của bạn là một trung tâm dữ liệu cục bộ, nhà cung cấp đám mây hay là một tổ hợp của hai.
