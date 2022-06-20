---
title: "Giới thiệu Kinesis"
description: "Amazon Kinesis là dịch vụ giúp bạn xây dựng được một ứng dụng có khả năng phân tích và xử lý luồng dữ liệu (stream data) theo thời gian thực (realtime). Amazon Kinesis có khả năng thu nhận, lưu trữ đến hàng terabytes dữ liệu trong một giờ."
keywords:
  [
    "Amazon Kinesis là gì",
    "AWS Kinesis la gi",
    "Kiến trúc Amazon Kinesis",
    "Streaming data trong Kinesis",
    "Kinesis Data Streams là gì",
    "Kinesis Data Streams la gi",
    "Kinesis Data Firehorse là gì",
    "Kinesis Data Firehorse la gi",
    "Kinesis Data Analytics là gì",
    "Kinesis Data Analytics la gi",
  ]
author:
  fullname: Phan Văn Đức
  username: ducpv
  avatar: "/configs/author/ducpv.jpg"
category:
  name: "Khóa học AWS từ cơ bản đến nâng cao"
  slug: "aws"
  description: "Mang kiến thức AWS đến với mọi lập trình viên"
chapter:
  name: "Decoupling trong AWS"
  slug: "chap-10-decoupling"
image: https://user-images.githubusercontent.com/29729545/170851127-9dfb7b17-d9fa-4cfd-a4a2-44d9d204c52a.png
position: 175
---

## Amazon Kinesis là gì

Amazon Kinesis là dịch vụ giúp bạn xây dựng được một ứng dụng có khả năng phân tích và xử lý luồng dữ liệu (stream data) theo thời gian thực (realtime). Amazon Kinesis có khả năng thu nhận, lưu trữ đến hàng terabytes dữ liệu trong một giờ.

Amazon Kinesis có thể nhận dữ liệu từ nhiều nguồn khác nhau như: Logs của ứng dụng, Website ClickStream,... Dữ liệu được thu thập, phân tích, lưu trữ khi kết hợp với những dịch vụ khác như: Amazon S3, Athena...

Hiện tại có 4 components về Kinesis bao gồm:

- **Kinesis Data Streams**: thu thập, xử lý và lưu trữ data stream
- **Kinesis Data Firehorse**: load data stream vào AWS data store (ví dụ: S3)
- **Kinesis Data Analytics**: phân tích data stream với SQL hoặc Apache Flink
- **Kinesis Video Stream**: thu thập, xử lý và lưu trữ data stream

Ở bài viết này mình sẽ giới thiệu về 3 component đầu tiên.

## Kiến trúc Amazon Kinesis

![Kiến trúc Amazon Kinesis](https://user-images.githubusercontent.com/29729545/170851127-9dfb7b17-d9fa-4cfd-a4a2-44d9d204c52a.png)

- **Procuders**: là nguồn của data, ví dụ một website send logs đến Kinesis
- **Consumers**: lấy lại data từ Kinesis và process chúng.
- **Shards**: là một nhóm data records được xác định và duy nhất trên Stream. Hiểu đơn giản ở đây thì Stream giống như là dòng nước từ điểm A đến điểm B thì _shards giống như là ống nước_ vậy. Càng nhiều ống nước thì bạn càng chuyển được nhiều nước. Mỗi một ống nước này đầu vào có thể ghi đến 1MB/1s (hay là 1000 data records / 1s), trong khi đó đầu ra có thể đưa ra 2MB/1s. Shards thể hiện lưu lượng dữ liệu của bạn truyền vào stream. Nếu lượng dữ liệu lớn thì bạn cần nhiều shard và ngược lại.

## Kinesis Data Streams là gì

- Amazon sẽ tính phí dựa trên số lượng Shard, bạn có thể có nhiều shard để tăng throughput
- Khi data được insert vào Kinesis sẽ không thể xóa được (immutability)
- Procuders: AWS SDK, Kinesis Agent
- Consumers:
  - Kinesis Client Library (KCL), AWS SDK
  - Kinesis Data Firehorse, Kinesis Data Analytics

## Kinesis Data Firehorse là gì

![Kinesis Data Firehorse](https://user-images.githubusercontent.com/29729545/170851143-4b32bf62-9864-4eb5-918e-f4b95ed4b84e.png)

- Kinesis Firehose là một dịch vụ được sử dụng để cung cấp dữ liệu trực tuyến đến các điểm đến như Amazon S3, Amazon Redshift, Amazon Elasticsearch.
- Kinesis Firehose là dịch vụ serverless, automatic scaling
- **Near Real Time**

| Kinesis Data Streams | Kinesis Data Firehorse |
| --- | --- |
| Streaming service | Load streaming data đến S3/Redshift/ES/3rd party |
| Quản lý thủ công | Quản lý tự động (fully managed) |
| Real time | Near real time |
| Quản lý scaling (tăng, giảm shard) | Automatic scaling |
| Data storage từ 1-365 ngày | Không có data storage |

## Kinesis Data Analytics là gì

Kinesis Analytics là một dịch vụ của Kinesis, trong đó dữ liệu truyền trực tuyến được xử lý và phân tích bằng cách sử dụng SQL.

![Kinesis Data Analytics](https://user-images.githubusercontent.com/29729545/170851158-2ae1bd39-85e9-4b40-a165-e5e3866ed1dd.png)

- Fully managed, serverless
- Automatic sacling
- Real-time analytics
- Use cases:
  - Time-series analytics
  - Real-time dashboards
