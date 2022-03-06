---
title: "Đa luồng trong Java"
description: ""
keywords:
  [
    "code đa luồng trong java",
    "lập trình thread trong java",
    "lập trình đa luồng trong java",
    "sử dụng thread trong java",
    "đa luồng trong java",
    "tiến trình là gì",
    "luồng là gì",
    "process là gì",
    "thread là gì",
    "Đa luồng trong java là gì",
    "hệ điều hành đơn nhiệm, hệ điều hành đa nhiệm",
  ]
author:
  fullname: Techmely Team
  username: Techmely Team
  avatar: "/configs/author/logo.jpg"
chapter:
  name: "Lập trình đa luồng"
  slug: "chuong-06-lap-trinh-da-luong"
category:
  logo: "/language/java.png"
  name: "Java"
  slug: "java"
  description: "Học Java từ cơ bản đến thông thạo cho mọi đối tượng"
image: https://user-images.githubusercontent.com/29374426/146175674-fa7e09f7-4e42-485e-a2b5-8c664601b203.png
position: 1
---

## Tiến trình (process) là gì?

Tiến trình là một thể hiện của một chương trình đang xử lý. Sở hữu một con trỏ lệnh, tập các thanh ghi và các biến. Để hoàn thành tác vụ của mình, một tiến trình còn cần đến một số tài nguyên khác như: _CPU, bộ nhớ, các tập tin, các thiết bị ngoại vi..._

Cần phân biệt được giữa tiến trình và chương trình. Một chương trình là một thể hiện thụ động, chứa các chỉ thị điều khiển máy tính để thực hiện mục đích gì đó; khi cho thực thi chỉ thị này thì chương trình sẽ biến thành tiến trình

Có thể nói tóm tắt tiến trình là một chương trình chạy trên hệ điều hành và được quản lý thông qua một số hiệu.

## Luồng (thread) là gì?

Một luồng là một đơn vị xử lý cơ bản trong hệ thống. Mỗi luồng xử lý tuần tự các đoạn code của nó, sở hữu một con trỏ lệnh, một tập các thanh ghi và một vùng nhớ stack riêng, các luồng chia sẻ CPU với nhau giống như cách chia sẻ giữa các tiến trình. Một tiến trình sở hữu nhiều luồng, tuy nhiên một luồng chỉ có thể thuộc về một tiến trình, các luồng bên trong cùng một tiến trình chia sẻ nhau không gian địa chỉ chung, điều này có nghĩa là các luồng có thể chia sẻ nhau các biến toàn cục của tiến trình. Một luồng cũng có thể có các trạng thái giống như các trạng thái của một tiến trình.

## Hệ điều hành đơn nhiệm, đa nhiệm

- Hệ điều hành đơn nhiệm là hệ điều hành chỉ cho phép 1 tiến trình chạy tại một thời điểm, ví dụ hệ điều hành DOS là Hệ điều hành đơn nhiệm.
- Hệ điều hành đa nhiệm cho phép nhiều tiến trình chạy tại một thời điểm, ví dụ hệ điều hành windows, Unix, Linux là các hệ điều hành đa nhiệm
- Hệ điều hành đa nhiệm ưu tiên: các tiến trình được cấp phát thời gian sử dụng CPU theo mức ưu tiên khác nhau
- Hệ điều hành đa nhiệm không ưu tiên: các tiến trình không có mức ưu tiên nào cả, chúng "tự giác" nhả quyền kiểm soát `CPU` sau khi kết thúc phần công việc

_Chú ý:_ trong thực tế mỗi máy thường chỉ có 1 `CPU`, nên không thể có nhiều tiến trình chạy tại một thời điểm. Nên thông thường sự đa chương chỉ là giả lập. Chúng được giả lập bằng cách lưu trữ nhiều tiến trình trong bộ nhớ tại một thời điểm, và điều phối `CPU` qua lại giữa các tiến trình.

## Các trạng thái của tiến trình

Trạng thái của một tiến trình tại một thời điểm được xác định bởi hoạt động hiện thời của tiến trình đó. Trong quá trình sống một tiến trình thay đổi trạng thái do nhiều nguyên nhân như hết thời gian sử dụng CPU, phải chờ một sự kiện nào đó xẩy ra, hay đợi một thao tác nhập/xuất hoàn tất…

Tại một thời điểm một tiến trình có thể nhận một trong các trạng thái sau đây:

- **Tạo mới**: tiến trình đang được thành lập
- **Running**: các chỉ thị của tiến trình đang được xử lý, hay nói cách khác tiến trình đang sở hữu CPU
- **Blocked**: tiến trình đang chờ được cấp tài nguyên, hay chờ một sự kiện nào đó xẩy ra
- **Ready**: tiến trình đang chờ cấp CPU để xử lý
- **Kết thúc**: tiến trình đã hoàn tất việc xử lý

## Đa luồng trong java là gì?

Đa luồng (Multi Thread) là một tiến trình thực hiện nhiều luồng đồng thời. Trong một chương trình, ngoài luồng chính thì có thể có các luồng khác thực thi đồng thời làm ứng dụng chạy nhanh và hiệu quả hơn. Theo như những gì chúng ta làm từ trước đến giờ, thì code của chúng ta sẽ được hệ thống xử lý một cách tuần tự từ trên xuống dưới.

![Đa luồng trong java](https://user-images.githubusercontent.com/29374426/146175674-fa7e09f7-4e42-485e-a2b5-8c664601b203.png)

Giả sử chương trình của chúng ta chia ra làm 3 phần A, B, C và chương trình sẽ chạy lần lượt từ A, rồi đến B, và cuối cùng là C. Nhưng sau bài viết này, chúng ta sẽ tổ chức sao cho A, B, C là 3 thread độc lập nhau và hệ thống sẽ xử lý 3 thread này một cách đồng thời.

Một ví dụ đơn giản về đa luồng đó chính là trình phát nhạc trên điện thoại của bạn. Khi bạn đang nghe một bài hát, bạn thấy hay và bạn muồn tải nó về, thì quá trình tải bài hát đó sẽ được chạy trên một thread riêng, quá trình phát nhạc được chạy trên một thread riêng nữa, vì vậy bạn vừa có thể nghe nhạc đồng thời có thể tải bài hát đó về máy.

Đa luồng trong java được sử dụng hầu hết trong các game, hoạt hình,...

## Ưu điểm của đa luồng trong java

- Nó không chặn người sử dụng vì các luồng là độc lập và bạn có thể thực hiện nhiều công việc cùng một lúc.
- Bạn có thể thực hiện nhiều hoạt động với nhau để tiết kiệm thời gian.
- Luồng là độc lập vì vậy nó không ảnh hưởng đến luồng khác nếu ngoại lệ xảy ra trong một luồng duy nhất.
