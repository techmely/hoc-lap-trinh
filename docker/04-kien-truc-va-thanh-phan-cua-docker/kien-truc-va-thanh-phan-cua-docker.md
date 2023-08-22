---
title: "Kiến trúc và thành phần của docker"
description: "Bài này chúng ta cùng nhau tìm hiểu về kiến trúc và thành phần sâu bên trong của docker xem chúng hoạt động như thế nào nhé."
chapter:
  name: "Nhập môn docker"
  slug: "chuong-01-nhap-mon-docker"
category:
  name: "Docker"
  slug: "docker"
image: https://kungfutech.edu.vn/thumbnail.png
position: 4
---

Ở các phần trước mình đã giới thiệu tổng quan về container và hướng dẫn cài đặt Docker. Phần này mình sẽ giới thiệu tổng quan các về các thành phần, các khái niệm cơ bản trong hệ sinh thái của Docker.

## Docker Engine

**Docker Engine** là một ứng dụng **client-server**. Có hai phiên bản Docker Engine phổ biến là:

- **Docker Community Edition (CE)**: Là phiên bản miễn phí và chủ yếu dựa vào các sản phầm nguồn mở khác. Cũng sẽ là phiên bản mình sử dụng trong suốt serie này.
- **Docker Enterprise**: Khi sử dụng phiên bản này bạn sẽ nhận được sự support của nhà phát hành, có thêm các tính năng quản lý và _security_. (Bản thân mình chưa được dùng thử Docker Enterprise bao giờ

Các thành phần chính của Docker Engine gồm có:

- **Server** hay còn được gọi là **docker daemon (dockerd)**: chịu trách nhiệm tạo, quản lý các **Docker objects** như images, containers, networks, volume.
- **REST API**: docker daemon cung cấp các api cho Client sử dụng để thao tác với Docker
- **Client** là thành phần đầu cuối cung cấp một tập hợp các câu lệnh sử dụng api để người dùng thao tác với Docker. (_Ví dụ docker images, docker ps, docker rmi image v.v.._)

![image](https://user-images.githubusercontent.com/29374426/118499185-e314f400-b750-11eb-91df-0d16bababc76.png)

## Kiến trúc của Docker

Docker sử dụng kiến trúc client-server. Docker **server** (hay còn gọi là daemon) sẽ chịu trách nhiệm build, run, distrubute Docker container. Docker **client** và Docker **server** có thể nằm trên cùng một **server** hoặc khác server. Chúng giao tiếp với nhau thông qua REST API dựa trên UNIX sockets hoặc network interface.

### Docker daemon

Docker daemon (dockerd) là thành phần core, lắng nghe API request và quản lý các **Docker object**. Docker daemon host này cũng có thể giao tiếp được với Docker daemon ở host khác.

### Docker client

Docker client (docker) là phương thức chính để người dùng thao tác với Docker. Khi người dùng gõ lệnh docker run imageABC tức là người dùng sử dụng CLI và gửi request đến dockerd thông qua api, và sau đó Docker daemon sẽ xử lý tiếp.

Docker client có thể giao tiếp và gửi request đến nhiều Docker daemon.

### Docker registry

Docker registry là một kho chứa các **Image**. Nổi tiếng nhất chính là **Docker Hub**, ngoài ra bạn có thể tự xây dựng một Docker registry cho riêng mình.

### Docker object

Các object này chính là các đối tượng mà bạn thường xuyên gặp phải khi sử dụng Docker gồm có

**Images**

**Image** là một template read-only sử dụng để chạy **container**.

Một image có thể base trên một image khác. Ví dụ bạn muốn tạo một image nginx, tất nhiên nginx phải chạy trên linux ubuntu chẳng hạn. Khi đó image nginx trước hết sẽ phải base trên ubuntu trước đã.

Bạn có thể tự build image cho riêng mình hoặc tải các image có sẵn của người khác trên Docker registry.

Ở các phần tiếp theo mình sẽ nói rõ hơn về việc tự build image sử dụng **Dockerfile** cũng như các layer trong image.

**Container**

Container được chạy dựa trên 1 image cụ thể. Bạn có thể tạo, start, stop, move, delete container.

Bạn cũng có thể kết nối các container với nhau hoặc attach storage cho nó, thậm chí là tạo lại một image từ chính state hiện tại của container

Container cô lập tài nguyên với host và các container khác.

![image](https://user-images.githubusercontent.com/29374426/118499262-f58f2d80-b750-11eb-8261-deb2db7cc238.png)

Phía trên là một quá trình thao tác với Docker. Mình sẽ lấy ví dụ quá trình để chạy một container nhé:

B1. Docker client (CLI) dùng lệnh sau để chạy một container centos trắng:

```bash
docker run -itd centos
```

B2. Docker daemon sẽ kiểm tra xem nó có image centos nào không. Nếu có nó sẽ chạy container luôn. Nếu không nó sẽ pull image centos (tag mặc định là lastest) về từ Registry và sau đó mới chạy container. Kiểm tra xem container đang chạy sử dụng lệnh:

```bash
docker ps
```

## Ví dụ

Lý thuyết dông dài không bằng thực hành thực tế :v. Mình sẽ lấy ví dụ luôn. Ví dụ của mình là sẽ chạy một container centos trắng.

### Điều kiện tiên quyết

Điều kiện bắt buộc là máy bạn đã cài đặt docker.

### Kiểm tra list image

Theo lý thuyết, để chạy một **container** thì cần có một image tương ứng. Để kiểm tra image đã có chưa ta sử dụng lệnh

```bash
docker images
```

![image](https://user-images.githubusercontent.com/29374426/118499300-fde76880-b750-11eb-822d-f867fd58fb25.png)

### Tìm image để pull

Ở đây mình chưa có image nào cả, giờ phải tìm được một image centos trên mạng thôi.

Tìm xem có image repository nào trên mạng có tên là centos không

```bash
docker search images
```

![image](https://user-images.githubusercontent.com/29374426/118499348-0c358480-b751-11eb-8a22-ec5c330712e5.png)

Đây rồi có ông `centos` rồi.

> Quên không nói: Repository là tập hợp các image có cùng tên nhưng khác tag (tag ở đây có thể là centos6, centos7, centos7.6.1810, 7.6.1810, lastest …)

### Download image

```bash
docker pull centos
```

![image](https://user-images.githubusercontent.com/29374426/118499389-148dbf80-b751-11eb-8c8d-f3391e417055.png)

Mặc định nếu không chỉ rõ phiên bản thì docker sẽ pull image lastest từ phía Registry về.

### Kiểm tra lại image

```bash
docker images
```

![image](https://user-images.githubusercontent.com/29374426/118499419-1c4d6400-b751-11eb-9f7b-42ffefce31d5.png)

### Chạy container

Để chạy container có thể sử dụng **tên image** hoặc **ImageID** đều được.

```bash
docker run -itd centos
```

Kiểm tra xem container đã chạy chưa

```bash
docker ps
```

![image](https://user-images.githubusercontent.com/29374426/118499456-25d6cc00-b751-11eb-8cc2-d90894b6a529.png)

Đây. như này là đang chạy rồi đây này.

### Kiểm tra sâu hơn vào trong container

```bash
docker exec -it 5ae53dede04d bash
cat /etc/centos-release
```

![image](https://user-images.githubusercontent.com/29374426/118499503-338c5180-b751-11eb-98e8-037cf4eab96b.png)

Như vậy là mình đã thực hiện chạy một container với image được pull về (nằm trên Docker host rồi). Trong trường hợp các bạn biết tên image cần chạy thì chỉ cần chạy container luôn và ngay thôi.

Ví dụ: `docker run -itd ubuntu`. Khi này Docker sẽ tự pull image về host cho bạn rồi sau đó nó mới chạy container

Ở bài này có một số thông tin cần nắm rõ đó là:

- Docker Engine, các thành phần và chức năng của chúng.
- Docker container được chạy từ một image. Image này có thể tự build, hoặc pull về từ Registry.
- Khi chạy container nếu Image không có sẵn trong Docker host thì Docker sẽ tự động tải về Docker host trước. Các option khi chạy container (ví dụ trong bài này là -itd) mình sẽ giải thích trong các bài viết tiếp theo nhé :v. Để đảm bảo không bị lỗi, các bạn cứ chạy đủ và đúng option -itd nhé.
