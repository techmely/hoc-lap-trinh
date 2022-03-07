---
title: "Các câu lệnh với Container"
description: "Bài này chúng ta sẽ tìm hiểu những câu lệnh container trong docker nhé."
keywords:
  [
    "docker",
    "docker container",
    "container docker",
    "các câu lệnh với container",
    "cac cau lenh voi container",
    "docker container command",
    "docker command",
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
position: 6
---

Ở các phần trước mình đã giới thiệu tổng quan về **Docker**, các thành phần cấu tạo nên Docker. Image là gì ? Container là gì ? Đó cũng chính là điều kiện tiên quyết khi các bạn đọc đến bài này của mình.

Trong bài viết này mình sẽ tập trung viết về một số command cơ bản để thao tác với container.

## Một số lưu ý nhỏ

**Trong bài viết mình sẽ viết hai command trong một block chẳng hạn như thế này**

```bash
docker run httpd
docker container run httpd
```

Cả hai command trên đều tương tự như nhau. Các bạn có thể chọn một trong hai. Bản thân mình thì thường sử dụng command trên cho nó ngắn gọn :v.

Vì đâu có sự tương đương này? Là do **Docker v1.13** đã tái cấu trúc lại CLI.

**Một số option hay sử dụng trong bài viết:**

`-d detach container` (Có thể hiểu là chạy ngầm container cũng được). Ví dụ nếu không có option này chạy container, cửa sổ dòng lệnh phải giữ phiên. Nếu kết thúc cửa sổ dòng lệnh, container cũng stop theo.

`-t Tạo một pseudo-TTY`: Ví dụ nếu không có option này khi attach lại container thì sẽ không có cửa sổ dòng lệnh

`-i giữ lại một STDIN kể cả khi detach`: Ví dụ nếu không có option này khi attach lại container thì khi gõ command sẽ không có kết quả trả về. Theo khuyến cáo thì nên sử dụng cả 3 option này theo dạng `-itd` đối với các command như: docker run, docker create …

**Docker làm việc, tương tác với các thành phần qua ID hoặc NAME**

## Nhóm các Command liên quan đến Lifecycle của Container

### Hiển thị list các container

- Ý nghĩa: Hiển thị list danh sách các container đang được Docker quản lý

```bash
docker ps [OPTIONS]
docker container ls [OPTIONS]
```

- Ví dụ list các container đang chạy (Up)

```bash
docker ps
```

- Ví dụ list tất cả các container

```bash
docker ps -a
```

### Tạo mới một container

- Ý nghĩa: Tạo mới một container nhưng không start

- Cú pháp:

```bash
docker create [OPTIONS] IMAGE [COMMAND] [ARG...]
docker container create [OPTIONS] IMAGE [COMMAND] [ARG...]
```

- Ví dụ:

```bash
docker create -itd centos
```

### Chạy một container

- Ý nghĩa: Tạo mới một container và start container đó luôn

- Cú pháp:

```bash
docker run [OPTIONS] IMAGE [COMMAND] [ARG...]
docker container run [OPTIONS] IMAGE [COMMAND] [ARG...]
```

- Ví dụ:

```bash
docker run -itd centos
```

### Xóa container

- Ý nghĩa: Xóa Container

- Cú pháp:

```bash
docker rm [OPTIONS] CONTAINER [CONTAINER...]
docker container rm [OPTIONS] CONTAINER [CONTAINER...]
```

- Ví dụ xóa một container đã stop

```bash
docker rm my-container
```

- Ví dụ xóa một container đã stop

```bash
docker rm my-container
```

- Ví dụ xóa một container chưa stop

```bash
docker rm -f my-container
```

- Ví dụ xóa tất cả các container

```bash
docker rm -f $(docker ps -aq)
```

### Xóa tất cả container đang stop

- Ý nghĩa: Xóa tất cả các container đang stop

- Cú pháp:

```bash
docker prune [OPTIONS]
docker container prune [OPTIONS]
```

- Ví dụ:

```bash
docker prune
```

## Nhóm các Command quản lý trạng thái của container

### Start container

- Ý nghĩa: Start một container

- Cú pháp:

```bash
docker start [OPTIONS] CONTAINER [CONTAINER...]
docker container start [OPTIONS] CONTAINER [CONTAINER...]
```

- Ví dụ:

```bash
docker start my-container
```

### Stop container

- Ý nghĩa: Stop một container

- Cú pháp:

```bash
docker stop [OPTIONS] CONTAINER [CONTAINER...]
docker container stop [OPTIONS] CONTAINER [CONTAINER...]
```

- Ví dụ:

```bash
docker stop my-container
```

### Restart container

- Ý nghĩa: Restart một container

- Cú pháp:

```bash
docker restart [OPTIONS] CONTAINER [CONTAINER...]
docker container restart [OPTIONS] CONTAINER [CONTAINER...]
```

- Ví dụ:

```bash
docker restart my-container
```

### Pause container

- Ý nghĩa: Tạm dừng lại một container

- Cú pháp:

```bash
docker pause CONTAINER [CONTAINER...]
docker container pause CONTAINER [CONTAINER...
```

- Ví dụ:

```bash
docker pause my-container
```

### Unpause container

- Ý nghĩa: Tạm dừng lại một container

- Cú pháp

```bash
docker pause CONTAINER [CONTAINER...]
docker container pause CONTAINER [CONTAINER...
```

- Ví dụ:

```bash
docker pause my-container
```

### Kill container

- Ý nghĩa: Kill một hoặc nhiều container (Kill ở đây giống như stop, container chỉ bị stop chứ không mất đi)

- Cú pháp

```bash
docker kill [OPTIONS] CONTAINER [CONTAINER...]
docker container kill [OPTIONS] CONTAINER [CONTAINER...]
```

- Ví dụ:

```bash
docker kill my-container
```

## Nhóm các Command hiển thị thông tin của container

### Log container

- Ý nghĩa: Hiển thị log của container

- Cú pháp

```bash
docker logs [OPTIONS] CONTAINER
docker container logs [OPTIONS] CONTAINER
```

- Ví dụ

```bash
docker logs my-container
```

### Hiển thị thông tin container

- Ý nghĩa: Hiển thị thông tin chi tiết của container

- Cú pháp

```bash
docker inspect [OPTIONS] CONTAINER [CONTAINER...]
docker container inspect [OPTIONS] CONTAINER [CONTAINER...]
```

- Ví dụ

```bash
docker inspect my-container
```

### Hiển thị tài nguyên của contaier

- Ý nghĩa: Hiển thị tài nguyên đang sử dụng của contaier

- Cú pháp

```bash
docker stats [OPTIONS] [CONTAINER...]
docker container stats [OPTIONS] [CONTAINER...]
```

- Ví dụ:

```bash
docker stats my-container
```

### Hiển thị các tiến trình đang chạy trong container

- Ý nghĩa: Hiển thị các tiến trình đang chạy trong container

- Cú pháp

```bash
docker top CONTAINER [ps OPTIONS]
docker container top CONTAINER [ps OPTIONS]
```

- Ví dụ:

```bash
docker top my-container
```

### Hiển thị các port được map

- Ý nghĩa: Hiển thị các port mapping hoặc một port mapping cụ thể

- Cú pháp

```bash
docker port CONTAINER [PRIVATE_PORT[/PROTO]]
docker container port CONTAINER [PRIVATE_PORT[/PROTO]]
```

- Ví dụ

```bash
docker port my-container
```

### Hiển thị các thay đổi về filesystem trong container

- Ý nghĩa: Hiển thị các thay đổi về filesystem trong container từ lúc create container

- Cú pháp

```bash
docker diff CONTAINER
docker container diff CONTAINER
```

- Ví dụ

```bash
docker diff my-container
```

## Nhóm các Command thực thi với container#

### Attach container

- Ý nghĩa: Attach một màn hình cho phép nhập input và hiển thị output đối với một container đang chạy

- Cú pháp

```bash
docker attach [OPTIONS] CONTAINER
docker container attach [OPTIONS] CONTAINER
```

- Ví dụ

```bash
docker attach my-container
```

### Thực thi một câu lệnh trong container

- Ý nghĩa: Thực thi một câu lệnh trong container đang chạy

- Cú pháp

```bash
docker exec [OPTIONS] CONTAINER COMMAND [ARG...]
docker container exec [OPTIONS] CONTAINER COMMAND [ARG...]
```

- Ví dụ

```bash
docker exec my-container free -m
```

### Update resource cho container

- Ý nghĩa: Update resource cho container, mở rộng, limit tài nguyên cho container

- Cú pháp

```bash
docker update [OPTIONS] CONTAINER [CONTAINER...]
```

- Ví dụ

```bash
docker update -m 512M --memory-swap 1024M my-container
```

### Copy file giữa host và container

- Ý nghĩa: Copy file giữa Docker host và container

- Cú pháp

```bash
docker cp [OPTIONS] SRC_PATH CONTAINER:DEST_PATH
docker container cp [OPTIONS] CONTAINER:SRC_PATH DEST_PATH
```

- Ví dụ

```bash
docker cp my-container:/opt/myfile /opt/
docker cp myfile1.txt my-container:/opt/
```

### Đổi tên container

- Ý nghĩa: Đổi tên một container

- Cú pháp

```bash
docker rename CONTAINER NEW_NAME
docker container rename CONTAINER NEW_NAME
```

- Ví dụ

```bash
docker rename my-container my-container1
```

### Export toàn bộ filesystem trong container

- Ý nghĩa: Export toàn bộ filesysystem trong container thành một file **tar**

- Cú pháp

```bash
docker export [OPTIONS] CONTAINER
docker container export [OPTIONS] CONTAINER
```

- Ví dụ

```bash
docker export -o huytm.tar my-container
```

### Tạo một image từ container đang chạy

- Ý nghĩa: Tạo một image từ container đang chạy

- Cú pháp

```bash
docker commit [OPTIONS] CONTAINER [REPOSITORY[:TAG]]
```

- Ví dụ

```bash
docker container commit my-container my_new_image
```

Như vậy trong bài viết này mình đã giới thiệu một số các command cở bản để làm việc với container. Mỗi commnad có các option - hay còn gọi là flag đi kèm. Trong phạm vi bài viết mình chưa thể giới thiệu sâu về các option này, mình sẽ có một bài viết cụ thể cho từng command sau.

Bài viết này chỉ giới thiệu các command cơ bản đủ để thao tác và tìm hiểu về Docker.
