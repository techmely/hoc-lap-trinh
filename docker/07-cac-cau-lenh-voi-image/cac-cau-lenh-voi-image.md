---
title: "Các câu lệnh với image"
description: "Hướng dẫn tạo image từ docker file"
keywords:
  [
    "docker",
    "docker image",
    "image docker",
    "các câu lệnh với image trong docker",
    "cac cau lenh voi image",
    "câu lệnh với image docker",
    "cau lenh voi image docker image",
    "các câu lệnh với image",
    "cac cau lenh voi image",
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
position: 7
---

Ở các phần trước mình đã giới thiệu về các lệnh cơ bản để thao tác với Container. Ở phần này mình sẽ giới thiệu một số lệnh cơ bản thao tác với Image.

Trong Docker, Image dùng để chạy Container. Các bạn có thể tưởng tượng Image giống như file GHOST khi cài Windows và Container chính là Windows được cài hoàn chỉnh từ file GHOST đó.

Giống như file GHOST, bản thân mỗi image nên được đóng gói một số thư viện nhất định, vừa đủ để khởi tạo container. Hoặc đóng sẵn thêm một số phần mềm có sẵn tùy vào mục đích sử dụng của người dùng.

## Một số chú ý nho nhỏ

Cũng giống như bài viết trước. Để thực hiện một thao tác đối với Image chúng ta cũng có thể có nhiều cách (nhiều command) giống như Container. Vậy nên bài viết này mình cũng sẽ viết nhiều command trong một block code.

Với mỗi block code có nhiều command, các command này có ý nghĩa như nhau. Vậy nên các bạn việc sử dụng command nào cũng được, tùy hoàn cảnh và cách sử dụng của mỗi người nhé :v

## Các command cơ bản với Image

### Hiển thị list images đang có

- Ý nghĩa: Hiển thị list các Image đang có

```bash
docker images [OPTIONS]
docker image ls [OPTIONS]
```

Khi chạy một trong hai command trên sẽ hiển thị list các image có trong Docker host.

```s
REPOSITORY       TAG        IMAGE ID            CREATED             SIZE
huytm/httpd      1.0        aea3873b1da1        7 minutes ago       458MB
huytm/httpd      2.0        aea3873b1da1        7 minutes ago       458MB
```

Trong đó

- `REPOSITORY`: là kho chứa của một Image. Image này có thể có nhiều TAG
- `TAG`: TAG có thể hiểu là version của Image cũng được
- `IMAGE ID`: ID của Image
- `CREATED`: Thời gian tạo Image
- `SIZE`: Dung lượng của Image

### Tải một image về từ Registry

- Ý nghĩa: Tải một image về từ Registry (Mặc định là DockerHub)
- Cú pháp:

```bash
docker image pull [OPTIONS] NAME[:TAG|@DIGEST]
```

- Ví dụ:

```bash
docker image pull centos
```

### Đẩy một image lên Registry

- Ý nghĩa: Đẩy một image về lên Registry (Mặc định là DockerHub)
- Cú pháp:

```bash
docker image push [OPTIONS] NAME[:TAG]
```

Ví dụ đẩy một image lên DockerHub. Trước hết bạn phải tạo một tài khoản của DockerHub. Tiếp theo là tên Image phải bắt đầu bởi tên tài khoản DockerHub của bạn (Chẳng hạn huytm/centost_httpd )

```bash
 docker image push huytm/centost_httpd:1.0
```

Nhập username / password của DockerHub và đợi một chút để image được đẩy lên. Kết quả như sau:

![image](https://user-images.githubusercontent.com/29374426/118496411-4ea99200-b74e-11eb-900f-764d66f0fe28.png)

### Hiển thị chi tiết của Image

- Ý nghĩa: Hiển thị chi tiết của một image
- Cú pháp

```bash
docker inspect [OPTIONS] IMAGE
docker image inspect [OPTIONS] IMAGE
```

- Ví dụ

```bash
docker inspect my_image
```

### Hiển thị lịch sử của image

- Ý nghĩa: Hiển thị lịch sử của image

- Cú pháp

```bash
docker image history [OPTIONS] IMAGE
```

- Ví dụng

```bash
docker image history my_image
docker image history my_image:<TAG>
```

### Tạo một Image TAG mới

- Ý nghĩa: Tạo một Image có TAG mới từ một Image đang có

- Cú pháp

```bash
docker image tag SOURCE_IMAGE[:TAG] TARGET_IMAGE[:TAG]
```

- Ví dụ

```bash
docker image tag my-image:TAG1 my-image:TAG2
```

### Save một image thành môt file tar

- Ý nghĩa: Save một image thành một file .tar. File này sẽ bao gồm các Layer sử dụng để tạo image đó, các file data dạng .json …

- Cú pháp

```bash
docker image save [OPTIONS] IMAGE [IMAGE...]
```

- Ví dụ:

```bash
docker image save -o /opt/my_image_file.tar my_image
```

### Tạo lại image bằng việc load lại file tar

- Ý nghĩa: Sử dụng file tar vừa save được ở câu lệnh docker save để tạo lại một image

- Cú pháp

```bash
docker image load [OPTIONS]
```

- Ví dụ

```bash
docker image load -i my_image_file.tar
```

### Xóa image

- Ý nghĩa: Xóa một hoặc nhiều image

- Cú pháp

```bash
docker rmi [OPTIONS] IMAGE [IMAGE...]
docker image rm [OPTIONS] IMAGE [IMAGE...]
```

- Ví dụ

```bash
docker image rm my_image
```

Như vậy trong bài viết này mình đã giới thiệu một số các command cơ bản để làm việc với Image. Ở phần tiếp theo mình sẽ giới thiệu một khái niệm quan trọng trong Docker đó là Docker Volume.
