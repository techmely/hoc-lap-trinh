---
title: "Tạo image từ dockerfile"
description: "Hướng dẫn tạo image từ docker file"
keywords:
  [
    "docker",
    "docker image",
    "image docker",
    "tạo image từ docker file",
    "tạo image trong docker",
    "tao image trong docker",
    "tao image tu docker file",
    "tạo image docker file",
  ]
chapter:
  name: "Nhập môn docker"
  slug: "chuong-01-nhap-mon-docker"
category:
  name: "Docker"
  slug: "docker"
image: https://kungfutech.edu.vn/thumbnail.png
position: 5
---

Ở các phần trước mình đã giới thiệu tổng quan **Docker Engine** và kiến trúc của **Docker**, cũng như chạy một container đầu tiên với các **image** có sẵn. Ở phần này mình sẽ viết hướng dẫn tạo image bằng **Dockerfile.**

![image](https://user-images.githubusercontent.com/29374426/118439306-eb007400-b70f-11eb-9d53-919634f5c044.png)

## 1. Dockerfile là gì ?

- **Dockerfile** là một file dạng text không có extension, và tên bắt buộc phải là _Dockerfile_
- **Dockerfile** là một file kịch bản sử dụng để tạo mới một _image_

## Cấu trúc một Dockerfile

Đây là cấu trúc một Dockerfile của ứng dụng Wordpress

```bash
FROM php:7.1-apache

# install the PHP extensions we need
RUN set -ex; \
	\
	savedAptMark="$(apt-mark showmanual)"; \
	\
	apt-get update; \
	apt-get install -y --no-install-recommends \
		libjpeg-dev \
		libpng-dev \
	; \
	\
	docker-php-ext-configure gd --with-png-dir=/usr --with-jpeg-dir=/usr; \
	docker-php-ext-install gd mysqli opcache zip; \
	\
# reset apt-mark's "manual" list so that "purge --auto-remove" will remove all build dependencies
	apt-mark auto '.*' > /dev/null; \
	apt-mark manual $savedAptMark; \
	ldd "$(php -r 'echo ini_get("extension_dir");')"/*.so \
		| awk '/=>/ { print $3 }' \
		| sort -u \
		| xargs -r dpkg-query -S \
		| cut -d: -f1 \
		| sort -u \
		| xargs -rt apt-mark manual; \
	\
	apt-get purge -y --auto-remove -o APT::AutoRemove::RecommendsImportant=false; \
	rm -rf /var/lib/apt/lists/*

# set recommended PHP.ini settings
# see https://secure.php.net/manual/en/opcache.installation.php
RUN { \
		echo 'opcache.memory_consumption=128'; \
		echo 'opcache.interned_strings_buffer=8'; \
		echo 'opcache.max_accelerated_files=4000'; \
		echo 'opcache.revalidate_freq=2'; \
		echo 'opcache.fast_shutdown=1'; \
		echo 'opcache.enable_cli=1'; \
	} > /usr/local/etc/php/conf.d/opcache-recommended.ini

RUN a2enmod rewrite expires

VOLUME /var/www/html

ENV WORDPRESS_VERSION 5.0.3
ENV WORDPRESS_SHA1 f9a4b482288b5be7a71e9f3dc9b5b0c1f881102b

RUN set -ex; \
	curl -o wordpress.tar.gz -fSL "https://wordpress.org/wordpress-${WORDPRESS_VERSION}.tar.gz"; \
	echo "$WORDPRESS_SHA1 *wordpress.tar.gz" | sha1sum -c -; \
# upstream tarballs include ./wordpress/ so this gives us /usr/src/wordpress
	tar -xzf wordpress.tar.gz -C /usr/src/; \
	rm wordpress.tar.gz; \
	chown -R www-data:www-data /usr/src/wordpress

COPY docker-entrypoint.sh /usr/local/bin/

ENTRYPOINT ["docker-entrypoint.sh"]
CMD ["apache2-foreground"]
```

## Các command cơ bản trong Dockerfile

### FROM

`FROM` chỉ định rằng image build này sẽ base trên image gốc nào

```ssh
FROM centos:centos7
```

### LABLE

`LABEL` chỉ định label metadata của image. Để xem được các label này sử dụng câu lệnh `docker inspect <IMAGE ID>`

```bash
LABEL "image-type"="huy-test"
LABEL "image-type1"="huy-test1"
LABEL "image-type2"="huy-test2"
```

### MAINTAINER

`MAINTERNER` là author (tác giả) build image đó.

```bash
MAINTAINER huytm
```

### RUN

`RUN` thực hiện một câu lệnh Linux. Tùy vào image gốc mà có các câu lệnh tương ứng (ví dụ Ubuntu sẽ là `RUN apt-get update -y`)

```bash
RUN yum update -y
```

### COPY

`COPY` Copy một file từ **Dockerhost** vào image trong quá trình build image

```bash
COPY start.sh /start.sh
```

### ENV

`ENV` là biến môi trường sử dụng trong quá trình build image.

```bash
ENV source /var/www/html/
COPY index.html ${source}
```

ENV chỉ có thể được sử dụng trong các command sau:

- ADD
- COPY
- ENV
- EXPOSE
- FROM
- LABEL
- STOPSIGNAL
- USER
- VOLUME
- WORKDIR

### CMD

`CMD` dùng để truyền một Linux command khi khởi tạo container từ image

### VOLUME

`VOLUME` tạo một volume nằm trong folder **/var/lib/docker/volumes** của docker host và mount với folder chẳng hạn **/etc/http** khi khởi chạy container

### EXPOSE

`EXPOSE` chỉ định các port sẽ **Listen** trong container khi khởi chạy container từ image

```bash
EXPOSE 80 443
```

## 4. Tạo images httpd với Dockerfile

**Tạo một folder làm việc với Dockerfile**

```bash
cd ~
mkdir build_image && cd build_image
```

**Tạo Dockerfile để build image**

```bash
touch Dockerfile
```

_Lưu ý_: Filename phải là Dockerfile và không có phần mở rộng

**Nội dung Dockerfile như sau:**

```bash
FROM centos:centos7

LABEL "image-type"="huy-test"
MAINTAINER huytm

RUN yum update -y
RUN yum install httpd -y

ENV source /var/www/html/

VOLUME ["/var/log/httpd"]

COPY index.html ${source}
COPY start.sh /start.sh

RUN chmod +x /start.sh
CMD ["/start.sh"]

EXPOSE 80
```

Giải thích:

- `FROM centos:centos7`: Build image dựa trên image gốc là centos 7.
- `RUN yum update -y và RUN yum install httpd -y`: Thực hiện các command của centos để update và cài đặt httpd
- `LABEL “image-type”=”huy-test”`: Metadata của image có thể có hoặc không.
- `MAINTAINER huytm`: Tác giả viết Dockerfile để build image có thể có hoặc không.
- `ENV source /var/www/html/` : Khai báo một biến môi trường tên là source và có giá trị là **/var/www/html/**. Biến này sẽ được sử dụng ở bước COPY index.html ${source}
- `COPY index.html ${source}`: Copy file index.html từ Dockerhost vào đường dẫn biến - được khai báo ở bước trên.
- `COPY start.sh /start.sh`: Copy một bash script file vào đường dẫn / để thực hiện một số Linux command khi khởi tạo container từ image này.
- `RUN chmod +x /start.sh`: Cho phép quyền thực thi đối với script vừa copy từ bước trên.
- `CMD [“/start.sh”]`: Thực thi script khi khởi chạy container từ image này.
- `EXPOSE 80`: Chỉ ra rằng container khi khởi chạy từ image này sẽ LISTEN port 80
- `VOLUME [“/var/log/httpd”]`: Chỉ định một phân vùng trên Docker host mount với container khi chạy. Ở đây mình mount theo dạng volume (Có ba kiểu volume, mình sẽ nói trong các bài viết sau). Mount folder /var/log/httpd của container với volume nằm tại /var/lib/portal/volume/ của Docker host

**Tạo các file cần thiết bổ trợ cho Dockerfile**

Vì ở trên mình có sử dụng COPY để COPY các file script `start.sh` và file source code index.html nên mình sẽ tạo tiếp hai file này.

```bash
cat <<EOF > start.sh
	#!/bin/bash
	rm -rf /run/httpd/* /tmp/httpd*
	exec /usr/sbin/apachectl -DFOREGROUND
EOF
```

```bash
echo "<h1>Hello World</h1>" > index.html
```

**Tạo image từ Dockerfile**

```bash
docker build -t huytm/centos7-httpd .
```

Đây là toàn bộ log của quá trình build

```s
Sending build context to Docker daemon  4.096kB
Step 1/12 : FROM centos:centos7
 ---> 1e1148e4cc2c
Step 2/12 : LABEL "image-type"="huy-test"
 ---> Running in 220997b26a05
Removing intermediate container 220997b26a05
 ---> 767cb6c0db64
Step 3/12 : MAINTAINER huytm
 ---> Running in 87547a35ac1f
Removing intermediate container 87547a35ac1f
 ---> 1333a9d9ceed
Step 4/12 : RUN yum update -y
 ---> Running in 66eb8c88d680
Loaded plugins: fastestmirror, ovl
Determining fastest mirrors
 * base: centos-hn.viettelidc.com.vn
 * extras: centos-hn.viettelidc.com.vn
 * updates: centos-hn.viettelidc.com.vn
Resolving Dependencies
--> Running transaction check
---> Package bind-license.noarch 32:9.9.4-72.el7 will be updated
---> Package bind-license.noarch 32:9.9.4-73.el7_6 will be an update
---> Package device-mapper.x86_64 7:1.02.149-10.el7_6.2 will be updated
---> Package device-mapper.x86_64 7:1.02.149-10.el7_6.3 will be an update
---> Package device-mapper-libs.x86_64 7:1.02.149-10.el7_6.2 will be updated
---> Package device-mapper-libs.x86_64 7:1.02.149-10.el7_6.3 will be an update
---> Package glibc.x86_64 0:2.17-260.el7 will be updated
---> Package glibc.x86_64 0:2.17-260.el7_6.3 will be an update
---> Package glibc-common.x86_64 0:2.17-260.el7 will be updated
---> Package glibc-common.x86_64 0:2.17-260.el7_6.3 will be an update
---> Package krb5-libs.x86_64 0:1.15.1-34.el7 will be updated
---> Package krb5-libs.x86_64 0:1.15.1-37.el7_6 will be an update
---> Package nss.x86_64 0:3.36.0-7.el7_5 will be updated
---> Package nss.x86_64 0:3.36.0-7.1.el7_6 will be an update
---> Package nss-sysinit.x86_64 0:3.36.0-7.el7_5 will be updated
---> Package nss-sysinit.x86_64 0:3.36.0-7.1.el7_6 will be an update
---> Package nss-tools.x86_64 0:3.36.0-7.el7_5 will be updated
---> Package nss-tools.x86_64 0:3.36.0-7.1.el7_6 will be an update
---> Package nss-util.x86_64 0:3.36.0-1.el7_5 will be updated
---> Package nss-util.x86_64 0:3.36.0-1.1.el7_6 will be an update
---> Package openldap.x86_64 0:2.4.44-20.el7 will be updated
---> Package openldap.x86_64 0:2.4.44-21.el7_6 will be an update
---> Package systemd.x86_64 0:219-62.el7 will be updated
---> Package systemd.x86_64 0:219-62.el7_6.3 will be an update
---> Package systemd-libs.x86_64 0:219-62.el7 will be updated
---> Package systemd-libs.x86_64 0:219-62.el7_6.3 will be an update
---> Package tzdata.noarch 0:2018g-1.el7 will be updated
---> Package tzdata.noarch 0:2018i-1.el7 will be an update
--> Finished Dependency Resolution

Dependencies Resolved

================================================================================
 Package                Arch       Version                    Repository   Size
================================================================================
Updating:
 bind-license           noarch     32:9.9.4-73.el7_6          updates      87 k
 device-mapper          x86_64     7:1.02.149-10.el7_6.3      updates     292 k
 device-mapper-libs     x86_64     7:1.02.149-10.el7_6.3      updates     320 k
 glibc                  x86_64     2.17-260.el7_6.3           updates     3.7 M
 glibc-common           x86_64     2.17-260.el7_6.3           updates      12 M
 krb5-libs              x86_64     1.15.1-37.el7_6            updates     803 k
 nss                    x86_64     3.36.0-7.1.el7_6           updates     835 k
 nss-sysinit            x86_64     3.36.0-7.1.el7_6           updates      62 k
 nss-tools              x86_64     3.36.0-7.1.el7_6           updates     515 k
 nss-util               x86_64     3.36.0-1.1.el7_6           updates      78 k
 openldap               x86_64     2.4.44-21.el7_6            updates     356 k
 systemd                x86_64     219-62.el7_6.3             updates     5.1 M
 systemd-libs           x86_64     219-62.el7_6.3             updates     406 k
 tzdata                 noarch     2018i-1.el7                updates     490 k

Transaction Summary
================================================================================
Upgrade  14 Packages

Total download size: 24 M
Downloading packages:
Delta RPMs disabled because /usr/bin/applydeltarpm not installed.
warning: /var/cache/yum/x86_64/7/updates/packages/bind-license-9.9.4-73.el7_6.noarch.rpm: Header V3 RSA/SHA256 Signature, key ID f4a80eb5: NOKEY
Public key for bind-license-9.9.4-73.el7_6.noarch.rpm is not installed
--------------------------------------------------------------------------------
Total                                              5.4 MB/s |  24 MB  00:04
Retrieving key from file:///etc/pki/rpm-gpg/RPM-GPG-KEY-CentOS-7
Importing GPG key 0xF4A80EB5:
 Userid     : "CentOS-7 Key (CentOS 7 Official Signing Key) <security@centos.org>"
 Fingerprint: 6341 ab27 53d7 8a78 a7c2 7bb1 24c6 a8a7 f4a8 0eb5
 Package    : centos-release-7-6.1810.2.el7.centos.x86_64 (@CentOS)
 From       : /etc/pki/rpm-gpg/RPM-GPG-KEY-CentOS-7
Running transaction check
Running transaction test
Transaction test succeeded
Running transaction
  Updating   : tzdata-2018i-1.el7.noarch                                   1/28
  Updating   : glibc-2.17-260.el7_6.3.x86_64                               2/28
  Updating   : glibc-common-2.17-260.el7_6.3.x86_64                        3/28
  Updating   : nss-util-3.36.0-1.1.el7_6.x86_64                            4/28
  Updating   : systemd-libs-219-62.el7_6.3.x86_64                          5/28
  Updating   : systemd-219-62.el7_6.3.x86_64                               6/28
Failed to get D-Bus connection: Operation not permitted
  Updating   : 7:device-mapper-1.02.149-10.el7_6.3.x86_64                  7/28
  Updating   : 7:device-mapper-libs-1.02.149-10.el7_6.3.x86_64             8/28
  Updating   : nss-sysinit-3.36.0-7.1.el7_6.x86_64                         9/28
  Updating   : nss-3.36.0-7.1.el7_6.x86_64                                10/28
  Updating   : nss-tools-3.36.0-7.1.el7_6.x86_64                          11/28
  Updating   : openldap-2.4.44-21.el7_6.x86_64                            12/28
  Updating   : krb5-libs-1.15.1-37.el7_6.x86_64                           13/28
  Updating   : 32:bind-license-9.9.4-73.el7_6.noarch                      14/28
  Cleanup    : 32:bind-license-9.9.4-72.el7.noarch                        15/28
  Cleanup    : openldap-2.4.44-20.el7.x86_64                              16/28
  Cleanup    : nss-tools-3.36.0-7.el7_5.x86_64                            17/28
  Cleanup    : nss-sysinit-3.36.0-7.el7_5.x86_64                          18/28
  Cleanup    : nss-3.36.0-7.el7_5.x86_64                                  19/28
  Cleanup    : 7:device-mapper-1.02.149-10.el7_6.2.x86_64                 20/28
  Cleanup    : 7:device-mapper-libs-1.02.149-10.el7_6.2.x86_64            21/28
  Cleanup    : systemd-219-62.el7.x86_64                                  22/28
  Cleanup    : systemd-libs-219-62.el7.x86_64                             23/28
  Cleanup    : nss-util-3.36.0-1.el7_5.x86_64                             24/28
  Cleanup    : krb5-libs-1.15.1-34.el7.x86_64                             25/28
  Cleanup    : glibc-common-2.17-260.el7.x86_64                           26/28
  Cleanup    : glibc-2.17-260.el7.x86_64                                  27/28
  Cleanup    : tzdata-2018g-1.el7.noarch                                  28/28
  Verifying  : systemd-libs-219-62.el7_6.3.x86_64                          1/28
  Verifying  : nss-tools-3.36.0-7.1.el7_6.x86_64                           2/28
  Verifying  : systemd-219-62.el7_6.3.x86_64                               3/28
  Verifying  : 32:bind-license-9.9.4-73.el7_6.noarch                       4/28
  Verifying  : nss-util-3.36.0-1.1.el7_6.x86_64                            5/28
  Verifying  : 7:device-mapper-libs-1.02.149-10.el7_6.3.x86_64             6/28
  Verifying  : krb5-libs-1.15.1-37.el7_6.x86_64                            7/28
  Verifying  : nss-sysinit-3.36.0-7.1.el7_6.x86_64                         8/28
  Verifying  : nss-3.36.0-7.1.el7_6.x86_64                                 9/28
  Verifying  : tzdata-2018i-1.el7.noarch                                  10/28
  Verifying  : glibc-2.17-260.el7_6.3.x86_64                              11/28
  Verifying  : glibc-common-2.17-260.el7_6.3.x86_64                       12/28
  Verifying  : 7:device-mapper-1.02.149-10.el7_6.3.x86_64                 13/28
  Verifying  : openldap-2.4.44-21.el7_6.x86_64                            14/28
  Verifying  : nss-3.36.0-7.el7_5.x86_64                                  15/28
  Verifying  : openldap-2.4.44-20.el7.x86_64                              16/28
  Verifying  : nss-util-3.36.0-1.el7_5.x86_64                             17/28
  Verifying  : 7:device-mapper-1.02.149-10.el7_6.2.x86_64                 18/28
  Verifying  : systemd-libs-219-62.el7.x86_64                             19/28
  Verifying  : glibc-common-2.17-260.el7.x86_64                           20/28
  Verifying  : systemd-219-62.el7.x86_64                                  21/28
  Verifying  : nss-tools-3.36.0-7.el7_5.x86_64                            22/28
  Verifying  : glibc-2.17-260.el7.x86_64                                  23/28
  Verifying  : krb5-libs-1.15.1-34.el7.x86_64                             24/28
  Verifying  : 7:device-mapper-libs-1.02.149-10.el7_6.2.x86_64            25/28
  Verifying  : 32:bind-license-9.9.4-72.el7.noarch                        26/28
  Verifying  : nss-sysinit-3.36.0-7.el7_5.x86_64                          27/28
  Verifying  : tzdata-2018g-1.el7.noarch                                  28/28

Updated:
  bind-license.noarch 32:9.9.4-73.el7_6
  device-mapper.x86_64 7:1.02.149-10.el7_6.3
  device-mapper-libs.x86_64 7:1.02.149-10.el7_6.3
  glibc.x86_64 0:2.17-260.el7_6.3
  glibc-common.x86_64 0:2.17-260.el7_6.3
  krb5-libs.x86_64 0:1.15.1-37.el7_6
  nss.x86_64 0:3.36.0-7.1.el7_6
  nss-sysinit.x86_64 0:3.36.0-7.1.el7_6
  nss-tools.x86_64 0:3.36.0-7.1.el7_6
  nss-util.x86_64 0:3.36.0-1.1.el7_6
  openldap.x86_64 0:2.4.44-21.el7_6
  systemd.x86_64 0:219-62.el7_6.3
  systemd-libs.x86_64 0:219-62.el7_6.3
  tzdata.noarch 0:2018i-1.el7

Complete!
Removing intermediate container 66eb8c88d680
 ---> 7827c1f58d69
Step 5/12 : RUN yum install httpd -y
 ---> Running in b3b027cccc5b
Loaded plugins: fastestmirror, ovl
Loading mirror speeds from cached hostfile
 * base: centos-hn.viettelidc.com.vn
 * extras: centos-hn.viettelidc.com.vn
 * updates: centos-hn.viettelidc.com.vn
Resolving Dependencies
--> Running transaction check
---> Package httpd.x86_64 0:2.4.6-88.el7.centos will be installed
--> Processing Dependency: httpd-tools = 2.4.6-88.el7.centos for package: httpd-2.4.6-88.el7.centos.x86_64
--> Processing Dependency: system-logos >= 7.92.1-1 for package: httpd-2.4.6-88.el7.centos.x86_64
--> Processing Dependency: /etc/mime.types for package: httpd-2.4.6-88.el7.centos.x86_64
--> Processing Dependency: libaprutil-1.so.0()(64bit) for package: httpd-2.4.6-88.el7.centos.x86_64
--> Processing Dependency: libapr-1.so.0()(64bit) for package: httpd-2.4.6-88.el7.centos.x86_64
--> Running transaction check
---> Package apr.x86_64 0:1.4.8-3.el7_4.1 will be installed
---> Package apr-util.x86_64 0:1.5.2-6.el7 will be installed
---> Package centos-logos.noarch 0:70.0.6-3.el7.centos will be installed
---> Package httpd-tools.x86_64 0:2.4.6-88.el7.centos will be installed
---> Package mailcap.noarch 0:2.1.41-2.el7 will be installed
--> Finished Dependency Resolution

Dependencies Resolved

================================================================================
 Package             Arch          Version                    Repository   Size
================================================================================
Installing:
 httpd               x86_64        2.4.6-88.el7.centos        base        2.7 M
Installing for dependencies:
 apr                 x86_64        1.4.8-3.el7_4.1            base        103 k
 apr-util            x86_64        1.5.2-6.el7                base         92 k
 centos-logos        noarch        70.0.6-3.el7.centos        base         21 M
 httpd-tools         x86_64        2.4.6-88.el7.centos        base         90 k
 mailcap             noarch        2.1.41-2.el7               base         31 k

Transaction Summary
================================================================================
Install  1 Package (+5 Dependent packages)

Total download size: 24 M
Installed size: 31 M
Downloading packages:
--------------------------------------------------------------------------------
Total                                              4.9 MB/s |  24 MB  00:04
Running transaction check
Running transaction test
Transaction test succeeded
Running transaction
  Installing : apr-1.4.8-3.el7_4.1.x86_64                                   1/6
  Installing : apr-util-1.5.2-6.el7.x86_64                                  2/6
  Installing : httpd-tools-2.4.6-88.el7.centos.x86_64                       3/6
  Installing : centos-logos-70.0.6-3.el7.centos.noarch                      4/6
  Installing : mailcap-2.1.41-2.el7.noarch                                  5/6
  Installing : httpd-2.4.6-88.el7.centos.x86_64                             6/6
  Verifying  : mailcap-2.1.41-2.el7.noarch                                  1/6
  Verifying  : apr-util-1.5.2-6.el7.x86_64                                  2/6
  Verifying  : httpd-tools-2.4.6-88.el7.centos.x86_64                       3/6
  Verifying  : httpd-2.4.6-88.el7.centos.x86_64                             4/6
  Verifying  : apr-1.4.8-3.el7_4.1.x86_64                                   5/6
  Verifying  : centos-logos-70.0.6-3.el7.centos.noarch                      6/6

Installed:
  httpd.x86_64 0:2.4.6-88.el7.centos

Dependency Installed:
  apr.x86_64 0:1.4.8-3.el7_4.1
  apr-util.x86_64 0:1.5.2-6.el7
  centos-logos.noarch 0:70.0.6-3.el7.centos
  httpd-tools.x86_64 0:2.4.6-88.el7.centos
  mailcap.noarch 0:2.1.41-2.el7

Complete!
Removing intermediate container b3b027cccc5b
 ---> ceaa2c4dc611
Step 6/12 : ENV source /var/www/html/
 ---> Running in 0dae76377156
Removing intermediate container 0dae76377156
 ---> 3d6abf9b4e60
Step 7/12 : VOLUME ["/var/log/httpd"]
 ---> Running in a5851687922f
Removing intermediate container a5851687922f
 ---> 5bedc77aef79
Step 8/12 : COPY index.html ${source}
 ---> 233244890ca7
Step 9/12 : COPY start.sh /start.sh
 ---> dde006532a47
Step 10/12 : RUN chmod +x /start.sh
 ---> Running in e639aca6cafe
Removing intermediate container e639aca6cafe
 ---> eeb387dba352
Step 11/12 : CMD ["/start.sh"]
 ---> Running in 2ae88e34619b
Removing intermediate container 2ae88e34619b
 ---> 1e9cab6ef65f
Step 12/12 : EXPOSE 80
 ---> Running in e697bcee7199
Removing intermediate container e697bcee7199
 ---> 97ba637ff1df
Successfully built 97ba637ff1df
Successfully tagged huytm/centos7-httpd:latest
```

**Kiểm tra lại image vừa build**

```bash
docker images
```

```s
REPOSITORY            TAG                 IMAGE ID            CREATED             SIZE
huytm/centos7-httpd   latest              97ba637ff1df        4 minutes ago       457MB
centos                centos7             1e1148e4cc2c        2 months ago        202MB
```

**Chạy container với image vừa build**

```bash
docker run -itd -p 9000:80 --name huytm huytm/centos7-httpd
```

**Truy cập vào apache của container**

Truy cập vào apache của container theo địa chỉ

```bash
http://<Docker_host_ip>:9000
```

Như vậy, trong bài viết này mình đã giới thiệu cách build một image từ Dockerfile cũng như giải thích các command trong cấu trúc file của Dockerfile.

![image](https://user-images.githubusercontent.com/29374426/118439280-da4ffe00-b70f-11eb-9dfc-5ae57b962fb0.png)

Ở bài viết tiếp theo mình sẽ viết về các command cở của Docker, để thao tác với container.
