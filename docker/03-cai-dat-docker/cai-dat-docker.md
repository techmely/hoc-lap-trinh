---
title: "Cài đặt Docker"
description: "Hướng dẫn cài đặt docker trên windows và trên CentOS"
keywords:
  [
    "cài đặt docker",
    "cai dat docker",
    "hướng dẫn cài đặt docker",
    "huong dan cai dat docker",
    "cài docker trên windows",
    "cai dat docker tren windows",
    "cài đặt docker trên CentOS",
    "cai dat docker tren CentOS",
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
position: 3
---

## Cài đặt Docker trên Windows

Trên Windows, cài Docker Desktop Installer theo link này: [https://desktop.docker.com/win/stable/Docker Desktop Installer.exe](https://desktop.docker.com/win/stable/Docker Desktop Installer.exe), có nhiều options nhưng tôi khuyến khích chọn theo recommendation.

Sau khi cài đặt xong, ở góc phải bên dưới sẽ hiện lên icon của Docker Desktop và trạng thái của nó. Có 3 trạng thái: Stopping, Restarting và Running.

![image](https://user-images.githubusercontent.com/29374426/118397610-16874e00-b67f-11eb-8e14-f6c657d9d028.png)

Click chuột phải vào Docker icon sẽ hiện ra các option. Ở đây tôi chọn Dashboard

![image](https://user-images.githubusercontent.com/29374426/118397630-299a1e00-b67f-11eb-8dea-36c236ea7918.png)

Đây là giao diện chính của Docker Desktop

![image](https://user-images.githubusercontent.com/29374426/118397636-37e83a00-b67f-11eb-88c1-d6fde0e1ad88.png)

Có 2 cách để vào phần Settings (mục này quan trọng lắm)

1. Click chuột phải docker icon và chọn Settings
2. Vào giao diện chính như hình trên và chọn icon bánh răng

![image](https://user-images.githubusercontent.com/29374426/118397646-45052900-b67f-11eb-9cf3-1c3d65a027b3.png)

Ở đây xảy ra 2 trường hợp:

Bạn chọn dùng Windows Container làm backend engine

1. Bạn chọn dùng WSL 2 làm backend engine
2. Cả 2 cách có ưu/nhược bù trừ. Như bạn dùng Windows Container thì setup đơn giản vì Windows 10 hỗ trợ hết rồi, nhưng khổ nỗi chạy không mượt bằng WSL 2. Còn nếu bạn dùng cách 2 thì chạy ngon hơn cách 1 nhưng setup thì rườm rà.

Tôi sẽ hướng dẫn các bạn cách 1 trước: sử dụng Windows Container

Bạn vào Apps&Features, một mục trong Settings của Windows

![image](https://user-images.githubusercontent.com/29374426/118397658-54847200-b67f-11eb-9911-77d3a176743e.png)

Vào phần Programes and Features góc phải bên trên

![image](https://user-images.githubusercontent.com/29374426/118397670-5f3f0700-b67f-11eb-883a-ee62a70e12be.png)

Vào phần Turn Windows features on or off

![image](https://user-images.githubusercontent.com/29374426/118397677-682fd880-b67f-11eb-9d0d-18531c856770.png)

Bạn chọn 2 ô `Containers` và `Hyper-V` ở hình dưới

![image](https://user-images.githubusercontent.com/29374426/118397687-72ea6d80-b67f-11eb-869e-828dddfb22b3.png)

Restart máy

Nếu bạn dùng cách này thì trong phần Settings của Docker Desktop sẽ có phần thiết lập tài nguyên máy của mỗi Docker Container và thiết lập đường dẫn để mount thư mục trong Container với bên ngoài.

![image](https://user-images.githubusercontent.com/29374426/118397701-8564a700-b67f-11eb-9be7-0e5d065270db.png)

![image](https://user-images.githubusercontent.com/29374426/118397714-99a8a400-b67f-11eb-875c-97ba40fec0fb.png)

Sau khi điều chỉnh ok thì bạn ấn vào Apply & Restart để lưu thay đổi.

Ok thế là xong cách 1, chúng ta chuyển sang cách 2 nhé.

### Cài đặt WSL 2

Bật tính năng Windows Subsystem for Linux bằng CMD của Windows, type dòng này:

```bash
dism.exe /online /enable-feature /featurename:Microsoft-Windows-Subsystem-Linux /all /norestart
```

Kiểm tra cấu hình máy xem có đủ điều kiện không

- For x64 systems: Version 1903 or higher, with Build 18362 or higher.
- For ARM64 systems: Version 2004 or higher, with Build 19041 or higher.

Bật tính năng Virtual Machine (máy ảo) lên

```bash
dism.exe /online /enable-feature /featurename:VirtualMachinePlatform /all /norestart
```

Tải về gói update Linux kernel qua link: [https://wslstorestorage.blob.core.windows.net/wslblob/wsl_update_x64.msi](https://wslstorestorage.blob.core.windows.net/wslblob/wsl_update_x64.msi)

Để WSL 2 làm mặc định khi cài đặt Linux distribution

```bash
wsl --set-default-version 2
```

Về cơ bản làm xong bước trên là ok rồi nhưng nếu bạn muốn dùng Ubuntu hay Kali hay Debian thì vào Microsoft Store để tải các Linux distribution về nhé [https://aka.ms/wslstore](https://aka.ms/wslstore)

Sau đó Linux sẽ đòi hỏi bạn tạo Username, Password các kiểu nhưng chỉ một lần thôi

Nếu bạn dùng WSL 2 làm backend thì không cần lo việc thay đổi Settings của Docker Desktop như tài nguyên máy cần sử dụng hay mount đường dẫn trong/ngoài container bởi mọi thứ đã được config sẵn rồi.

## Cài đặt Docker trên CentOS 7

Cài đặt các gói cần thiết

```bash
sudo yum install -y yum-utils device-mapper-persistent-data lvm2
```

Thêm Docker repo

```bash
sudo yum-config-manager --add-repo https://download.docker.com/linux/centos/docker-ce.repo
```

Cài đặt bản lastest của Docker CE

```bash
sudo yum install -y docker-ce docker-ce-cli containerd.io
```

Kiểm tra lại cài đặt

```bash
sudo systemctl start docker
docker -v
```

Chạy container đầu tiên với Docker

```bash
sudo docker run hello-world
```

![Cài đặt Docker trên CentOS 7](https://user-images.githubusercontent.com/29374426/118398056-2bfd7780-b681-11eb-9e5f-368b903d4928.png)

Bản chất của câu lệnh trên, Docker sẽ pull một image là **hello-world** trên **Docker hub** về server và chạy container với image đó.
