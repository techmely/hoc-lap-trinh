---
title: "CloudFront nâng cao"
description: "Cloudfront Egde locations được nằm khắp nơi trên toàn cầu, chi phí data của mỗi Egde location là khác nhau. Bạn có thể giảm thiểu chi phí sử dụng Cloudfront bằng cách giảm số lượng edge location."
keywords:
  [
    "Cloudfront giá",
    "Cloudfront chi phí",
    "Cloudfront chi phi",
    "Giá cloudfront",
    "Gia cloudfront",
    "Price classes trong cloudfront",
    "Cloudfront price classes là gì",
    "Cloudfront price classes la gi",
    "Cloudfront multiple origin classes là gì",
    "Cloudfront multiple origin classes la gi",
    "Cloudfront Origin Groups là gì",
    "Cloudfront Origin Groups la gi",
  ]
author:
  fullname: Phan Văn Đức
  username: ducpv
  avatar: "/configs/author/ducpv.jpg"
category:
  name: "Khóa học AWS từ cơ bản đến nâng cao"
  slug: "aws"
chapter:
  name: "Cloudfront, Accelerator"
  slug: "cloud-front"
position: 72
---

## CloudFront - Pricing

Cloudfront Egde locations được nằm khắp nơi trên toàn cầu, chi phí data của mỗi Egde location là khác nhau.

![CloudFront - Pricing](https://preventdirectaccess.com/wp-content/uploads/2021/08/pda-cloudfront-on-demand-pricing.png)

## CloudFront - Price classes

Bạn có thể giảm thiểu chi phí sử dụng Cloudfront bằng cách giảm số lượng edge location. Nếu ứng dụng của bạn có lượng người dùng chỉ trong khu vực Đông Nam Á, bạn không cần phải dùng tất cả các Edge location trên toàn cầu. Có 3 price classes:

- Price Class All: Tất cả các regions - hiệu suất tốt nhất (chi phí đắt nhât)
- Price Class 200: Hầu hết regions, nhưng sẽ giảm thiểu những region có chi phí đắt
- Price Class 100: Chỉ có ít những region có chi phí đắt

![CloudFront - Price classes](https://user-images.githubusercontent.com/29729545/153042484-2e8e09f3-92ad-494d-ad07-f79914c14772.png)

## CloudFront - Multiple Origin

Bạn có thể route tới những origin khác nhau dựa vào path hoặc content type: ![CloudFront - Multiple Origin](https://user-images.githubusercontent.com/29729545/153046606-e7540a73-3072-4ed0-bc48-053dac372277.png)

## CloudFront - Origin Groups

Origin Groups bao gồm **một primary và một secondary origin**, nhằm tăng cường tính sẵn sàng và khả năng phục hồi khi có sự cố ở 1 origin. Nếu primary origin có vấn đề, secondary origin sẽ được sử dụng ![CloudFront - Origin Groups](https://docs.aws.amazon.com/AmazonCloudFront/latest/DeveloperGuide/images/origingroups-overview.png)

## CloudFront - Field Level Encryption

Field-level encryption là một layer security có nhiệm vụ bảo mật những thông tin quan trọng được gửi đi từ phía client. Những thông tin quan trọng (ví dụ như: mật khẩu...) sẽ được mã hóa tại Edge gần với user.

- Cách sử dụng:
  - Gửi thông tin các field qua POST request (tối đa 10 fields)
  - Sử dụng public key để encrypt
  - Phía origin (vd: EC2 server...) sẽ dùng private key để decrypt những field đó

![CloudFront - Field Level Encryption](https://user-images.githubusercontent.com/29729545/153169711-be572b7b-cd39-4683-a088-f0e4fd585601.png)
