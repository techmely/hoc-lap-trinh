---
title: "Chi phí sử dụng EC2"
description: "Tùy theo cấu hình EC2 mình chọn, AWS sẽ tính tiền dựa trên những lựa chọn của mình. Khi bạn chạy những ứng dụng lâu bền, AWS cung cấp reserved instance. Bạn có thể trả trước tiền (1 phần, hoặc trả tất), hoặc commit sử dụng lâu dài. Khi đó AWS sẽ discount giá"
chapter:
  name: "Elastic Compute Cloud"
  slug: "chap-02-ec2"
image: https://user-images.githubusercontent.com/29729545/162227316-62f67100-d142-4a64-9c78-8f15b94143ac.png
position: 4
---

## Cách tính tiền dịch vụ EC2

![Chi phí EC2](https://user-images.githubusercontent.com/29729545/162227316-62f67100-d142-4a64-9c78-8f15b94143ac.png)
**AWS cung cấp 4 option để trả phí với EC2**

- On-demand
- Spot instances
- Reserved instances
- Dedicated hosts

### On-demand instance là gì

On-demand instance là các tính tiền dễ hiểu nhất "dùng bao nhiêu trả tiền bấy nhiêu" . Tùy theo cấu hình EC2 mình chọn, AWS sẽ tính tiền dựa trên những lựa chọn của mình

- Tính tiền theo thời gian sử dụng thực tế (Chỉ tính tiền khi state running)
- Option đắt tiền nhất

### Spot instances là gì

AWS có rất nhiều tài nguyên dư thừa, họ một tối ưu hoá phần hạ tầng chưa dùng đến bằng Spot Instance. Bạn có thể hiểu là bán ghế trống trên máy bay hay ô tô.
Bạn sẽ bid (đấu thầu) giá **max_price** mà mình muốn trả, Spot instance sẽ có **current_price** và current_price này sẽ thay đổi theo thời gian <br /> AWS sẽ thống báo trước 2 phút và lấy lại Spot instance của bạn khi **max_price** < **current_price**

- Use-case: dùng cho những ứng dụng flexible, có thể bị interrupted.

### Spot fleet là gì

- Spot Fleets là tập hợp các Spot Instances + On-Demand Instances

### Reserved instances là gì

Khi bạn chạy những ứng dụng lâu bền, AWS cung cấp reserved instance. Bạn có thể trả trước tiền (1 phần, hoặc trả tất), hoặc commit sử dụng lâu dài. Khi đó AWS sẽ discount giá

### Dedicated hosts là gì

Đa phần những EC2 chúng ta sử dụng đều được share phần cứng giữa nhiều instance. Dedicated hosts là thuê luôn phần cứng của AWS, phần cứng đó sẽ được AWS cung cấp chỉ cho bạn sử dụng. Có một số trường hợp đặc thù bạn cần cài những software có yêu cầu không được share phần cứng giữa các tenant khác nhau.

- Phù hợp cho ứng dụng license model phức tạp (BYOL- Bring your own license)
- Hoặc cho các công ty có rule về bảo mật (Họ không muốn sử dụng chung phần cứng với các công ty khác trên môi trường AWS)

Về chi chí khi sử dụng Dedicated hosts, chúng ta có thể chọn những option mà AWS đưa ra:

- On-demand Dedicated hosts: Dùng bao nhiêu trả tiền bấy nhiêu
- Dedicated hosts Reservations: Cam kết thời gian sử dụng, hay trả tiền trước...
- Saving plan: là cách tiết kiệm chi phí bằng cách cam kết mức sử dụng (tính theo USD/giờ) ví dụ cam kết sử dụng 0.6$/giờ trong 1 khoảng thời gian là 1 hoặc 3 năm, khi đó giá của bạn sẽ giảm lên tới 66% so với on-demand

Keyword gặp trong exam: **compliance requirement** and **use your existing server-bound software licenses**
