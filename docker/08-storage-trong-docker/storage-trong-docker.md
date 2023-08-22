---
title: "Storage trong docker"
description: "Ở bài này mình sẽ giới thiệu một thành phần vô cùng quan trọng trong kiến trúc của Docker, đó chính là Storage trong Docker"
chapter:
  name: "Nhập môn docker"
  slug: "chuong-01-nhap-mon-docker"
category:
  name: "Docker"
  slug: "docker"
image: https://kungfutech.edu.vn/thumbnail.png
position: 8
---

Ở các phần trước mình đã giới thiệu cơ bản về các thành phần trong kiến trúc tổng quan của Docker bao gồm: Docker Daemon, Docker Container, Docker Image… cũng như các câu lệnh thao tác cơ bản với Container, Image.

Ở phần này mình sẽ giới thiệu một thành phần vô cùng quan trọng trong kiến trúc của Docker, đó chính là **Storage trong Docker**.

## Storage trong Docker

**Storage trong Docker** là một tính năng quản lý data của Docker. Data ở đây có thể hiểu là các file được sinh ra trong quá trình chạy Ứng dụng, ví dụ như file log, file data, file report …

Mặc định khi một container được khởi chạy, data trong quá trình vận hành được chứa ở writeable layer và sẽ bị mất đi khi container bị xóa. . Ngoài ra thì một nhược điểm nữa đó là data ở container này khó có thể chia sẻ data với các container khác.

Vậy để giải quyết các vấn đề này, Docker đưa ra một cơ chế để quản lý data của các Container đó là **Docker Storage**

Về bản chất, **Docker Storage** là một cơ chế cho phép lưu trữ các data của Container vào Docker Host bằng cách mount một folder từ Docker Container vào Docker Host.

Bằng việc mount này, data trong container giờ đây sẽ được an toàn hơn, dễ dàng chia sẻ giữa các container với nhau hơn. Một số folder chứa setting hay log có thể được đọc dễ dàng hơn trong quá trình troubleshoot các Container.

## Các kiểu mount của Docker Storage

Có 3 kiểu mount của Docker Storage đó là:

- **Volumes**: Mount-point sẽ nằm ở /var/lib/docker/volumes/ của Docker Host và được quản lý bằng Docker.
- **bind mounts**: Mount-point có thể nằm ở bất kỳ đâu Docker Host không được quản lý bởi Docker.
- **tmpfs mounts**: Data sẽ được lưu vào memory của Docker Host và sẽ mất đi khi khởi động lại hoặc stop container.

```bash
-v và -mount flag
```

Ban đầu -v hoặc –volume flag được dùng cho standalone container và –mount flag được dùng cho swarm services. Tuy nhiên từ phiên bản Docker 17.06 bạn có thể sử dụng –mount flag cho standalone container. Nói chung điểm khác biệt duy nhất chính là là cú pháp. Trong khi -v flag, các option được gói gọn làm một thì -mount flag lại phân chia chúng rõ ràng hơn với từng option các nhau bởi dấu phẩy. Trong bài viết này mình sẽ sử dụng cả 2 option là -v và -mount.

## Volumes

- Về hoạt động Volume tương tự như Bind mounts, nhưng Volume được quản lý bởi Docker. Trong khi bind mounts, file hoặc thư mục cần mount phải được tồn tại trên docker host.
- Volume khi tạo ra sẽ nằm ở thư mục `/var/lib/docker/volumes`
- Volume cũng support cơ chế của volume drivers, cho phép lưu trữ dữ liệu tới một server remote hoặc Cloud …
- Bạn có thể quản lý volume sử dụng CLI hoặc API.
- Volume hoạt động trên cả Linux và Windows container

**Sử dụng Volume khi nào ?**

- Khi chia sẻ dữ liệu giữa nhiều container đang chạy.
- Lưu dữ liệu tới một server remote hoặc cloud.
- Khi cần backup, restore hoặc migrate dữ liệu từ Docker Host này sang Docker Host khác.
- Cần quản lý dễ dàng và thuận tiện hơn so với bind mounts.

**Ví dụ**

Tạo một volume và chạy container mount với volume đó

Tạo Volume

```bash
docker volume create my-volume    ## Tạo một volume
docker volume ls                  ## List danh sách volume
docker volume inspect my-volume   ## Hiển thị thông tin của Volume
ll /var/lib/docker/volumes        ## Kiểm tra volume được tạo ra
```

Chạy container với volume

```bash
docker run -itd -v my-volume:/opt/mount_point/ centos
# Hoặc
docker run -itd --mount type=volume,src=my-volume,dst=/opt/mount_point/ centos
# Hoặc
docker run -itd --mount type=volume,source=my-volume,target=/opt/mount_point/ centos
```

Kiểm tra lại

```bash
docker exec my-container bash -c "echo 'This is test file' > /opt/mount_point/test.txt"
docker exec my-container bash -c "cat /opt/mount_point/test.txt"
cat /var/lib/docker/volumes/my-volume/_data/test.txt
```

**Một số chú ý với volume**

- Nếu bạn mount một volume vào trong một thư mục của container, mà thư mục của container này đã có dữ liệu thì dữ liệu từ container sẽ được copy vào volume mount-point của docker host
- Thông thường nếu bạn không tạo volume từ trước mà chạy container với volume mount thì Docker sẽ tự động tạo một volume và dữ liệu sẽ vẫn tồn tại ngoài vòng đời của container.

Ví dụ:

```bash
docker run -itd --name webapp --mount source=webapp-vol,destination=/var/ centos
```

- Volume thường là sự lựa chọn tốt hơn là sử dụng wriable layer của Container. Bởi vì sử dụng Volume không làm tăng dung lượng của container sử dụng.

## bind mounts

Bind mounts trong Docker xuất hiện trước Volume. Bind mounts bị giới hạn một số các tính năng hơn so với volume. Binds mount có hiệu năng tốt nhưng bị phụ thuộc vào cấu trúc filesystem của Docker host

Khi sử dụng bind mount thì một file hoặc một folder trong docker host được mount vào trong container. File hoặc Folder này yêu cầu đường dẫn tuyệt đối. Vậy nên, trong trường hợp file hoặc folder này không tồn tại trên docker host, thì quá trình mount sẽ bị lỗi.

**Sử dụng bind mounts khi nào ?**

- Khi chia sẻ file cấu hình từ docker host với container.
- Chia sẻ thư mục source code hoặc môt trường từ docker host với container
- Khi cấu trúc filesystem của docker host là rõ ràng và phù hợp với các yêu cầu của bind mount

Ví dụ: Chạy một container với bind mounts theo hai cách

Sử dụng `flag -v`

Khi sử dụng flag -v nếu source folder trên docker host chưa tồn tại, Docker sẽ tự động tạo mới folder

```bash
docker run -itd --name my_contanier -v /opt/docker_host_folder/:/opt/ centos
docker exec my_contanier bash -Sử dụng flag –mount "touch /opt/cloud365.vn"
ll /opt/docker_host_folder
```

Sử dụng `flag –mount`

Khi sử dụng flag –mount, thì đảm bảo folder trên docker host đã được tồn tại, nếu không sẽ bị lỗi

```bash
mkdir -p /opt/docker_host_folder
docker run -itd --name my_contanier --mount type=bind,src=/opt/docker_host_folder,dst=/opt/ centos
docker exec my_contanier bash -c "touch /opt/cloud365.vn"
ll /opt/docker_host_folder
```

**Một số chú ý với binds mount**

- Khi sử dụng bind mounts và flag –mount thì phải đảm bảo file hoặc folder từ docker host đã được tồn tại.
- Không giống như volume, nếu folder trong Container “không trống” và được mount với folder của docker host thì tất cả các file trong folder của container sẽ bị ẩn đi. Điều này giống với khi bạn save dữ liệu của mình trong /mnt, sau đó cắm USB và mount USB với thư mục /mnt thì những file dữ liệu có từ trước sẽ bị ẩn đi đến khi USB được umount. Để test trường hợp này mình có một ví dụ sau:

Tạo một Image từ Dockerfile đảm bảo rằng có một folder “không trống” khi chạy container

```bash
cd ~
mkdir create_image && cd create_image
```

```bash
cat <<EOF > Dockerfile
	FROM centos:centos7

  LABEL "image-type"="huy-test"
  MAINTAINER huytm
  RUN mkdir /opt/test_folder && \
      touch /opt/test_folder/test_file.txt
EOF
```

```bash
docker build -t image-test .
docker images
```

Chạy một container và đảm bảo image tạo ra một container có một folder “không trống”

```bash
docker run -itd --name test_container image-test
docker exec test_container bash -c "ls /opt/test_folder/"
```

> test_file.txt

Chạy contaier sử dụng chính image đó với **bind mounts** và kiểm tra thư mục mount

```bash
mkdir /opt/docker_host_folder
docker run -itd --privileged --name another_container --mount type=bind,src=/opt/docker_host_folder,dst=/opt/test_folder/ image-test
docker exec another_container bash -c "ls /opt/test_folder/"
```

Kết quả trả về là không có gì cả chứng tỏ file đã bị ẩn đi

Unmount thư mục trong container và kiểm tra lại

```bash
docker exec another_container bash -c "umount  /opt/test_folder/"
docker exec another_container bash -c "ls /opt/test_folder/"
```

> test_file.txt

## tmpfs

Volumes và bind mounts cho phép bạn chia sử dữ liệu giữa docker host và container kể cả khi container bị stop hoặc xóa đi. Nếu bạn sử dụng Docker trên Linux thì bạn có một option thứ ba là **tmpfs mounts**

**Sử dụng tmpfs mounts khi nào ?**

- Khi bạn không muốn giữ data trên docker host hoặc trong container.
- Khi muốn bảo mật, hoặc muốn đảm bảo hiệu suất container khi ứng dụng cần ghi một số lượng lớn dữ liệu không liên tục.
- tmpfs mount sẽ lưu dữ liệu tạm thời trên memory. Khi container stop, tmpfs mount sẽ bị xóa bỏ.

Ví dụ:

```bash
docker run -itd --name tmp_mount --mount type=tmpfs,dst=/opt/ centos
docker exec tmp_mount bash -c "touch /opt/test.txt"
docker exec tmp_mount bash -c "ls /opt/"
```

> test.txt

Restart container và kiểm tra lại

```bash
docker container restart tmp_mount
docker exec tmp_mount bash -c "ls /opt/"
```

Kết quả trả về là trắng tinh.

Như vậy trong bài viết này mình đã giới thiệu một thành phần quan trọng trong Docker đó là Docker Storage. Docker Storage có 3 option cho bạn lựa chọn là **volumes, bind mounts, tmpfs mounts**. Tùy vào nhu cầu sử dụng mà các bạn có thể sử dụng option phù hợp cho ngữ cảnh của mình.

Cảm ơn các bạn đã theo dõi và chúc các bạn áp dụng thành công :D
