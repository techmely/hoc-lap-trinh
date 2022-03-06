---
title: "Docker Container"
description: "Bài tiếp theo chúng ta sẽ tìm hiểu về docker container nhé"
keywords:
  [
    "docker container",
    "container trong docker",
    "container docker",
    "docker",
    "tìm hiểu docker container",
    "tim hieu docker container",
  ]
author:
  fullname: Techmely Team
  username: Techmely Team
  avatar: "/configs/author/logo.jpg"
chapter:
  name: "Nhập môn docker"
  slug: "chuong-01-nhap-mon-docker"
category:
  logo: "/language/docker.png"
  name: "Docker"
  slug: "docker"
  description: "Học Docker từ cơ bản đến thông thạo cho mọi đối tượng"
image: https://kungfutech.edu.vn/thumbnail.png
trend: true
position: 2
---

Docker là một ứng dụng mang lại lợi ích cho cả **SysAdmin, Developer (Dev)** lẫn **Devops**. Đối với Dev, họ không cần phải biết nhiều về việc vận hành các chương trình, phần mềm phía dưới. Ngoài ra Dev cũng tận dụng được hàng nghìn các chương trình được đóng gói sẵn và chia sẻ trên mạng. Đối với SysAd, Docker mang đến sự linh hoạt trong quản lý, tăng khả năng tận dụng tài nguyên hệ thống. Đối với Devops, lợi ích chính là tận dụng cả hai lợi ích ở trên.

Theo cá nhân mình đánh giá, việc sử dụng Docker với những người đã có kiến thức nền tảng vững vàng từ trước thì đã là thánh sẽ trở thành thần một cách vô cùng nhanh chóng =)). Nhưng đối với những người chưa có kiến thức vững vàng, việc sử dụng docker, tận dụng lại các app, các chương trình được đóng gói sẵn sẽ làm giảm khả năng hiểu biết về luồng lạch hệ thống.

Bài viết này sẽ là bài viết đầu tiên trong chuỗi bài viết Tìm hiểu Docker của mình. Trong bài viết này mình sẽ đưa ra một số khái niệm cơ bản cũng như lịch sử hình thành của Docker.

## Container

Tại sao lại nói về container khi nói đến Docker? Bạn nên nhớ, Docker là một ứng dụng dựa vào và cải tiến lại các tính năng có sẵn của Linux kernel, trong đó bao gồm Linux container (LXC), cgroup, namespaces…

Khái niệm container được nhắc đến ở đây không phải là công-ten-nơ trong ngành vận tải :v. Nó là một phương thức ảo hóa được Linux Contaiers (LXC) sử dụng đầu tiên để ảo hóa đến mức hệ điều hành giúp chạy nhiều hệ thống cô lập và được điều khiển bởi một kernel duy nhất dựa trên các tính năng có sẵn của Linux kernel như namespace, cgroup (Xem thêm về lịch sử ở đây đây).

LXC lần đầu xuất hiện vào ngày 6 tháng Tám năm 2008,tính đến thời điểm mình viết bài viết này, LXC đã release đến version 3.1.0.

## Sự ra đời của Containerlization

Nói về sự ra đời của **Containerlization** - ảo hóa mức container thì chắc phải kể từ những vấn đề mà loài người gặp phải trong giai đoạn đầu của cuộc cách mạng công nghệ.

![Sự ra đời của Containerlization](https://blog.cloud365.vn/images/img-docker/docker1/server-vat-ly.jpg)

Khi đó chưa có khái niệm VM hay VPS, mỗi máy chủ là một máy vật lý, đặt trên DC hay nhà riêng nào đó =)). Vấn đề gặp phải ở đây là nó chỉ chạy được một hệ điều hành duy nhất, không tận dụng được hết công suất. Trừ khi có thánh nào tính toán để tận dụng được khoảng 98% tài nguyên hệ thống thì mình không nói, nhưng chắc đa số chúng ta chỉ là người phàm mà thôi :v.

Chưa kể quá trình nâng cấp, mở rộng vô cùng phức tạp và mất thời gian cộng với việc tốn thêm cả đống tiền thuê diện tích ở DC nữa. Điều này làm đau đầu các doanh nghiệp khi vừa muốn giảm thiểu chi phí lại vừa muốn nâng cao chất lượng dịch vụ.

Và ảo hóa ra đời..

Mình tin chắc bạn nào đọc bài viết này đã ít nhất một lần cũng đã từng cài máy ảo trên VMWare, Vitualbox. hay một số nền tảng ảo hóa khác.

**Ảo hóa ra đời** cho phép những người quản trị chạy được nhiều hệ điều hành, nhiều máy chủ trên cùng một máy chủ duy nhất. Giúp giảm thiểu chi phí, dễ dàng trong việc triển khai và vận hành. Tận dụng tốt hơn tài nguyên hệ thống. Thay vì trước đây server vật lý 64GB ram chỉ để chạy một dịch vụ web thì giờ đây nó có thể chạy thêm cả dịch vụ mail nữa chẳng hạn. Anh em giờ lab cũng dễ dàng hơn chứ không phải mua máy thật về lab nữa :v.

![Sự ra đời của Containerlization](https://blog.cloud365.vn/images/img-docker/docker1/aohoa.jpg)

Tuy nhiên **ảo hóa** vẫn chưa phải là giải pháp tối ưu nhất. Chẳng hạn bạn tạo một máy ảo 5GB RAM thì trên máy vật lý sẽ mất 5GB RAM cho máy ảo đó. Nếu không tận dụng tốt thì đâu đó vẫn có sự lãng phí tài nguyên ở đây.

Và ở bước tiến tiếp theo, nhân loại đã nghĩ ra **Containerlization**.

**Containerlization - ảo hóa container** . Phương pháp ảo hóa này gần giống với phương pháp ảo hóa trước đó ở trên (đều sinh ra các hệ điều hành con nằm trên cùng một hệ điều hành bố). Nhưng nó tối ưu hơn hơn chỗ , các máy con này cùng sử dụng kernel của máy bố nhưng lại hoàn toàn độc lập với nhau như ảnh phía dưới.

![Sự ra đời của Containerlization](https://blog.cloud365.vn/images/img-docker/docker1/contaierztion.png)

## Docker

Đọc đến đây thì chắc các bạn cũng đã có một cái nhìn tổng quan cũng như lý tưởng mà docker hướng tới rồi đó. Giờ sẽ đến phần chính của bài viết - đó là **Docker**

Docker là một ứng dụng mã nguồn mở cho phép đóng gói các ứng dụng, các phần mềm phụ thuộc lẫn nhau vào trong cùng một container. Container này sau đó có thể mang đi triển khai trên bất kỳ một hệ thống Linux phổ biến nào. Các container này hoàn toàn độc lập với các container khác.

Docker dựa vào tính năng LXC, được phát triển bởi dotCloud. dotCloud Ban đầu là một công ty cung cấp PaaS (Platform as a service). Tháng 3 năm 2013 họ sử dụng Docker để cung cấp các platform cho những nhà phát triển khác, nhưng sau đó họ nhận thấy tốc độ phát triển nhanh chóng của Docker cũng như hệ sinh thái bao quanh nó. Công ty đã đổi luôn tên của mình thành Docker

Những lợi ích mà Docker đem lại:

- Sử dụng ít tài nguyên: Thay vì phải ảo hóa toàn bộ hệ điều hành thì chỉ cần build và chạy các container độc lập sử dụng chung kernel duy nhất.
- Tính đóng gói và di động: Tất cả các gói dependencies cần thiết đều được đóng gói vừa đủ trong container. Và sau đó có thể mang đi triển khai trên các server khác.
- Cô lập tài nguyên: server bố không biết ở trong container chạy gì và container cũng không cần biết bố nó là CentOs hay Ubuntu. Các container độc lập với nhau và có thể giao tiếp với nhau bằng một interface
- Hỗ trợ phát triển và quản lý ứng dụng nhanh: Đối với Dev, sử dụng docker giúp họ giảm thiểu thời gian setup môi trường, đóng gói được các môi trường giống nhau từ Dev - Staging - Production :v
- Mã nguồn mở: Cộng đồng support lớn, các tính năng mới được release liên tục.

## Các khái niệm quan trọng trong Docker

**Image** là một template được đóng gói sẵn và không đổi trong toàn bộ quá trình chạy container (trừ khi build lại image). Liên tưởng đến lập trình hướng đối tượng, Image là class và container là object của class đó. Các bạn có thể tự build image cho riêng mình, hoặc download các image có sẵn của cộng đồng từ Docker Hub.

**Container** được khởi chạy từ các Image, bên trong sẽ có đầy đủ các ứng dụng cần thiết mà bạn định nghĩa từ Image

**Docker Registry** là một kho chứa các image. Bạn có thể dựng riêng một con Docker Registry cho riêng mình. Hoặc up lên Docker Hub để đóng góp ngược lại cho cộng đồng :D

## Các điểm hạn chế của Docker

Docker không phải là hoàn hảo

- Docker base trên **Linux 64bit** và các tính năng **cgroup, namespaces**. Vì thế Linux 32bit hoặc môi trường Window không thể chạy được docker (đối với phiên bản CE).
- Sử dụng container tức là bạn sử dụng chung kernel của hệ điều hành. Trong trường hợp bạn download image có sẵn và trong đó có một số công cụ có thể kiểm soát được kernel thì server của bạn có thể bị mất kiểm soát hoàn toàn.
- KiếnCác tiến trình chạy container một khi bị stop thì sẽ mất hoàn toàn dữ liệu nếu không được mount hoặc backup. Điều này có thể sẽ gây ra một số bất tiện… Tuy nhiên **Docker** nói riêng hay **Containerlization** nói chung vẫn sẽ là tương lai và là xu hướng chung của hầu hết các doanh nghiệp trên toàn thế giới.

![Các điểm hạn chế của Docker](https://blog.cloud365.vn/images/img-docker/docker1/aohoa-tuonglai.png)

Ở bài viết này mình đã giới thiệu sơ bộ về Container, Docker. Các ưu và nhược điểm mà Docker đem lại. Ở phần tiếp theo mình sẽ viết hướng dẫn sử dụng Docker để chạy container đầu tiên, cũng như một số câu lệnh cơ bản khi vận hành.
