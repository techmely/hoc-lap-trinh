---
title: "Đa luồng trong Java"
description: "Đa luồng (Multi-Thread) trong Java là khả năng của một ứng dụng để thực hiện nhiều luồng đồng thời. Thay vì thực hiện công việc tuần tự từ trên xuống dưới, ứng dụng Java có thể chạy nhiều luồng đồng thời, làm cho ứng dụng chạy nhanh và hiệu quả hơn."
chapter:
  name: "Lập trình đa luồng"
  slug: "chuong-06-lap-trinh-da-luong"
image: https://user-images.githubusercontent.com/29374426/146175674-fa7e09f7-4e42-485e-a2b5-8c664601b203.png
position: 1
---

Đa luồng (Multi-Thread) trong Java là khả năng của một ứng dụng để thực hiện nhiều luồng đồng thời. Thay vì thực hiện công việc tuần tự từ trên xuống dưới, ứng dụng Java có thể chạy nhiều luồng đồng thời, làm cho ứng dụng chạy nhanh và hiệu quả hơn.

## Tiến Trình (Process) là Gì?

Tiến trình là một thể hiện của một chương trình đang chạy trong hệ thống. Mỗi tiến trình sở hữu một con trỏ lệnh, tập các thanh ghi và các biến riêng. Để hoàn thành công việc của mình, tiến trình cần sử dụng các tài nguyên như CPU, bộ nhớ, tệp tin, và các thiết bị ngoại vi.

Để phân biệt giữa tiến trình và chương trình, chúng ta cần hiểu rằng một chương trình là một thực thể tĩnh, nó chỉ chứa các chỉ thị điều khiển máy tính để thực hiện một tác vụ cụ thể. Khi được thực thi, chương trình trở thành một tiến trình.

Một tiến trình có thể sở hữu nhiều luồng (threads) để thực hiện các tác vụ đồng thời. Tiến trình và luồng là hai khái niệm quan trọng liên quan đến đa nhiệm và đa luồng trong lập trình.

## Luồng (Thread) là Gì?

Một luồng (thread) là một đơn vị xử lý cơ bản trong hệ thống. Mỗi luồng thực hiện tuần tự các đoạn mã của nó và sở hữu một con trỏ lệnh, tập các thanh ghi và một vùng nhớ stack riêng. Các luồng có thể chia sẻ CPU với nhau, tương tự như cách chia sẻ giữa các tiến trình. Một tiến trình có thể sở hữu nhiều luồng, nhưng mỗi luồng chỉ thuộc về một tiến trình duy nhất. Các luồng bên trong cùng một tiến trình chia sẻ không gian địa chỉ chung, cho phép chúng chia sẻ biến toàn cục của tiến trình.

Luồng cũng có các trạng thái tương tự như các tiến trình, bao gồm trạng thái "Tạo mới," "Running," "Blocked," "Ready," và "Kết thúc."

## Hệ Điều Hành Đơn Nhiệm và Đa Nhiệm

- **Hệ điều hành đơn nhiệm**: Trong hệ điều hành đơn nhiệm, chỉ có một tiến trình có thể chạy tại một thời điểm. Ví dụ về hệ điều hành đơn nhiệm là DOS.

- **Hệ điều hành đa nhiệm**: Hệ điều hành đa nhiệm cho phép nhiều tiến trình chạy cùng một thời điểm. Ví dụ về hệ điều hành đa nhiệm bao gồm Windows, Unix, và Linux.

- **Hệ điều hành đa nhiệm ưu tiên**: Trong hệ điều hành đa nhiệm ưu tiên, các tiến trình được cấp phát thời gian sử dụng CPU theo mức ưu tiên khác nhau.

- **Hệ điều hành đa nhiệm không ưu tiên**: Trong hệ điều hành đa nhiệm không ưu tiên, các tiến trình không có mức ưu tiên, chúng "tự giác" nhả quyền kiểm soát CPU sau khi hoàn tất phần công việc.

Lưu ý rằng trong thực tế, hầu hết các máy tính chỉ có một CPU, do đó không thể có nhiều tiến trình chạy đồng thời. Thay vào đó, hệ thống giả lập đa nhiệm bằng cách lưu trữ nhiều tiến trình trong bộ nhớ tại một thời điểm và điều phối CPU giữa các tiến trình này.

## Các Trạng Thái của Tiến Trình

Trạng thái của một tiến trình tại một thời điểm xác định bởi hoạt động hiện tại của tiến trình đó. Trong suốt quá trình sống của một tiến trình, trạng thái của nó có thể thay đổi do nhiều nguyên nhân như hết thời gian sử dụng CPU, chờ sự kiện xảy ra, hoặc thao tác nhập/xuất hoàn tất.

Tại một thời điểm, một tiến trình có thể ở một trong các trạng thái sau:

- **Tạo mới**: Tiến trình đang được tạo ra và chưa bắt đầu thực hiện.
- **Running**: Tiến tr

ình đang được thực hiện, sở hữu CPU để thực hiện các chỉ thị.

- **Blocked**: Tiến trình đang chờ đợi được cấp tài nguyên hoặc chờ xảy ra sự kiện nào đó.
- **Ready**: Tiến trình đã sẵn sàng để thực hiện và chờ CPU.
- **Kết thúc**: Tiến trình đã hoàn thành tác vụ của mình và chấm dứt.

## Đa Luồng trong Java

Đa luồng (Multi-Thread) trong Java là khả năng của một ứng dụng để thực hiện nhiều luồng đồng thời. Thay vì thực hiện công việc tuần tự từ trên xuống dưới, ứng dụng Java có thể chạy nhiều luồng đồng thời, làm cho ứng dụng chạy nhanh và hiệu quả hơn.

![Đa Luồng trong Java](https://user-images.githubusercontent.com/29374426/146175674-fa7e09f7-4e42-485e-a2b5-8c664601b203.png)

Ví dụ, một ứng dụng nghe nhạc có thể chạy một luồng để phát nhạc và một luồng khác để tải bài hát mới về máy cùng lúc. Điều này giúp người dùng có thể nghe nhạc mà không cần chờ quá lâu để tải bài hát mới.

## Ưu Điểm của Đa Luồng trong Java

- **Không Chặn Người Sử Dụng**: Đa luồng cho phép ứng dụng thực hiện nhiều công việc cùng một lúc mà không chặn người dùng, do các luồng là độc lập.
- **Tiết Kiệm Thời Gian**: Ứng dụng có thể thực hiện nhiều hoạt động song song để tiết kiệm thời gian.
- **Xử Lý Ngoại Lệ Tốt**: Các luồng là độc lập, vì vậy nếu một luồng xảy ra ngoại lệ, nó không ảnh hưởng đến các luồng khác.
- **Tái Sử Dụng Tài Nguyên**: Luồng cho phép tái sử dụng tài nguyên CPU một cách hiệu quả.

Đa luồng trong Java thường được sử dụng trong các ứng dụng yêu cầu đồng thời xử lý nhiều tác vụ khác nhau như game, ứng dụng đồ họa, và các hệ thống đa nhiệm.
