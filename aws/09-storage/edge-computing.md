---
title: "Giới thiệu Edge Computing"
description: "Edge computing là quá trình phân tích, xử lý dữ liệu khi chúng được tạo ở một Edge location (không giống Edge location trong Cloudfront). Một egde location có thể là bất kỳ đâu, có thể là một trang trại, hay một chiếc tàu thủy..."
keywords:
  [
    "Edge computing là gì",
    "Edge computing la gi",
    "AWS OpsHub là gì",
    "AWS OpsHub la gi",
    "Snow Family trong AWS",
    "Migrate dữ liệu trong AWS"
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
  slug: "chap-09-cloud-storage"
image: https://user-images.githubusercontent.com/29729545/169690071-850e190d-504d-4d10-a888-e190adcc8a75.png
position: 92
---

## Edge Computing là gì

![Edge Computing là gì](https://user-images.githubusercontent.com/29729545/169690071-850e190d-504d-4d10-a888-e190adcc8a75.png)

Edge computing là quá trình phân tích, xử lý dữ liệu khi chúng được tạo ở một **Edge location** (không giống Edge location trong Cloudfront). Một egde location có thể là bất kỳ đâu, có thể là một trang trại, hay một chiếc tàu thủy...

- Những location có thể hoạt động ngay cả không có kết nối internet
- Bạn cần setup Snowball Egde/Snowcone để thực hiện edge computing

Mình sẽ đưa ra một ví dụ để mọi người dễ hình dung hơn về Edge computing (mình chỉ ví dụ đơn giản vì trên thực tế cần các thiết bị IoT để thực hiện). Ví dụ mình có một trang trại cần hệ thống tưới cây tự động khi độ ẩm không đủ. Theo tư duy về Cloud AWS thì mình sẽ cần tạo một máy server (EC2 chẳng hạn) trên region Tokyo. Máy server đó có nhiệm vụ collect dữ liệu về độ ẩm và tính toán, sau đó sẽ gọi đến function "Tưới cây" . Tuy nhiên nếu 1 ngày đẹp trời, mạng internet của trang trại bị hỏng hay có vấn đề, hệ thông không thể hoạt động được :((. Để giải quyết được tình huống này chúng ta sẽ nghĩ đến giải pháp là cần một công cụ đặt bên ngoài Data center ở Tokyo, có thể là đặt luôn tại trang trại. Công cụ này sẽ thu thập thông tin về độ ẩm và có thể thực thi luôn function "Tưới cây" với độ trễ rất thấp vì không cần thông qua internet. Đó chính là Edge Computing.

## Snow family - Edge Computing

- **Snowcone**
  - 2CPUs, 4GB memory, có thể truy cập có dây hoặc không dây
  - Cổng USB-C
- **Snowball Edge - Computed Optimized**
  - 52vCPUs, 208 GB RAM memory
  - Optimized GPU (Trong video streaming...)
- **Snowball Edge - Storage Optimized**
  - Tối đa 40vCPUs, 80 GB RAM memory
  - Có _Object storage clustering_

**Tất cả có thể chạy EC2 instance hoặc Lambda function** (Sử dụng dịch vụ IoT Greengrass)

## AWS OpsHub là gì

AWS OpsHub là phần mềm được cài trên máy tính của bạn với mục đích quản lý những thiết bị Snow Family
