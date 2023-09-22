---
title: "Gradle là gì? Maven là gì?"
description: "Gradle là gì? Maven là gì?"
chapter:
  name: "Form"
  slug: "chuong-05-form"
category:
  name: "Spring Boot"
  slug: "spring-boot"
image: https://kungfutech.edu.vn/thumbnail.png
position: 6
---

## Maven là gì ?

![maven-pic](https://cloudviet.com.vn/wp-content/uploads/2021/10/Apache-maven.jpg)

- Apache maven được ra đời vào năm 2004 là một chương trình quản lý dự án cho phép các lập trình viên có thể quản lý về version, các thư viện sử dụng trong dự án, quản lý build,…
- Nó giúp chúng ta đơn giản hoá và chuẩn hoá quá trình xây dựng dự án và nó hoàn toàn free.

## Gradle là gì ?

![gradle-pic](https://raw.githubusercontent.com/docker-library/docs/c3d3ca6beed000f9ba6eabc98f3399158f520256/gradle/logo.png)

- Gradle là một hệ thống tự động build mã nguồn mở dựa trên các khái niệm về Apache Ant và Apache Maven. Maven mình đã giới thiệu ở trên nên dưới đây mình sẽ giới thiệu qua về Ant.
- Apache Ant được ra đời vào năm 2000 – là một trong những công cụ đóng gói hiện đại và nhanh chóng được sử dụng trong các dự án sử dụng ngôn ngữ Java. Ant cho phép nhà phát triển mô tả meta-data của dự án cũng như các hoạt động trong quá trình build bằng việc sử dụng cú pháp XML. Tuy nhiên những đoạn mã viết theo tiêu chuẩn của Ant quá dài và phức tạp.
- Và sau này Gradle được ra đời, kết hợp các ưu điểm của Maven cũng như của Ant và thêm một số các cải thiện mới và sử dụng Groovy để giải quyết bài toán đóng gói

## Gradle vs Maven

- Giữa Gradle vs Maven có một số điểm khác biệt cơ bản trong cách tiếp cận build một dự án. Gradle dựa vào đồ thị phụ thuộc task. Trong khi đó Maven thì lại dựa trên mô hình cố định và tuyến tính của các giai đoạn. Với Maven, các mục tiêu gắn liền với các giai đoạn của dự án và các mục tiêu có chức năng tương tự như các task của Gradle.
- Xét về hiệu suất làm việc thì cả hai đều cho phép các build module được chạy song song. Tuy nhiên, Gradle cho phép tăng khả năng build vì nó kiểm tra tác vụ nào được cập nhật hay không nên thời gian build của Gradle sẽ nhanh hơn so với Maven.
- Các tính năng khác biệt về mặt hiệu suất mà bạn có thể tìm thấy trên Gradle bao gồm:
  - Tăng khả năng complie cho các class Java
  - Sử dụng API cho việc tăng số lượng các task con
- Còn về việc quản lý các dependency, cả Gradle và Maven đều có thể xử lý các dependency động và bắc cầu, để sử dụng bộ nhớ đệm dependency của bên thứ ba và đọc định dạng siêu dữ liệu POM. Bạn cũng có thể khai báo các phiên bản thư viện thông qua định nghĩa lập phiên bản trung tâm và thực thi lập phiên bản trung tâm. Cả hai đều tải xuống các dependency bắc cầu từ kho tạo tác của chúng. Maven có Maven Central trong khi Gradle có JCenter. Nếu có một số phụ thuộc được yêu cầu, Maven có thể tải chúng xuống đồng thời.
- Các tính năng quản lý dependency khác mà chúng ta chỉ có thể tìm thấy trên Gradle là:
  - Việc sử dụng các quy tắc thay thế cho các thư viện tương thích
  - Việc sử dụng các quy tắc ReplacedBy
- Ngoài ra việc tạo các Build Script của Gradle cũng đơn giản hơn so với Maven rất nhiều.
- Cho nên Gradle sẽ là lựa chọn tốt hơn cho chúng ta so với Maven
