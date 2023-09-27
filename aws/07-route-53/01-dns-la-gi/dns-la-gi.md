---
title: "DNS là gì"
description: "DNS là viết tắt của: Domain Name System là hệ thống phân giải tên miền được phát minh vào năm 1984. Hiểu một cách ngắn gọn nhất, DNS cơ bản là một hệ thống chuyển đổi các tên miền website mà chúng ta đang sử dụng, ở dạng www.domain.com sang một địa chỉ IP dạng số tương ứng với tên miền đó và ngược lại."
chapter:
  name: "Route 53"
  slug: "chap-07-route-53"
image: https://user-images.githubusercontent.com/29729545/149654735-e330eab1-a835-42c9-aa2a-6b67e961c43b.png
position: 60
---

## DNS là gì

DNS là viết tắt của: **Domain Name System** là hệ thống phân giải tên miền được phát minh vào năm 1984. Hiểu một cách ngắn gọn nhất, DNS cơ bản là một hệ thống chuyển đổi các tên miền website mà chúng ta đang sử dụng, ở dạng *www.domain.com* sang một địa chỉ IP dạng số tương ứng với tên miền đó và ngược lại.

![DNS la gi](https://imc.org.vn/uploads/plugin/news/519/1627437317-1622235566-dns-server-8-8-8-8-lam-gi-m-t-c-truy-c-p-m-ng.png)

## Thuật ngữ trong DNS

- **Domain Registrar**: Nơi đăng ký tên miền (Route 53, Tenten, MatBao...)
- **DNS Resolver**: Nhận các yêu cầu phân giải tên miền từ Clients (Browser) và gửi tới nơi cung cấp dịch vụ DNS (Ví dụ: Google Resolver 8.8.8.8, 8.8.4.4)
- **DNS Records**: A, AAAA, CNAME, NS,...
- **Zone File**: Lưu trữ DNS records
- **Name Server**: Là hệ thống server có chức năng điều phối quá trình chuyển đổi từ tên miền sang địa chỉ IP.
- **Top Level Domain (TLD)**: .com, .us, .edu,...
- **Second Level Domain (SLD)**: amazon.com, google.com,...

![DNS giai thich](https://user-images.githubusercontent.com/29729545/149654735-e330eab1-a835-42c9-aa2a-6b67e961c43b.png)

## DNS hoạt động như thế nào

![How DNS works](https://user-images.githubusercontent.com/29729545/149654930-0b0d3a35-d0a2-4990-a725-a3a5d4f61afb.png)

Local DNS Server hiện tại ở Việt Nam có những nhà mạng lớn như FPT, Viettel, VNPT, CMC... Trên thực tế không phải bất cứ khi nào bạn truy cập đến sample.com hệ thống sẽ gửi đến nhiều DNS server như vậy, khi Local DNS Server có được thông tin IP của sample.com chúng sẽ được cached lại, từ các request sau đó sẽ được lấy từ cached. Hình vẽ khá cụ thể, mình hi vọng mọi người có thể hiểu được thực sự DNS hoạt động như thế nào.
