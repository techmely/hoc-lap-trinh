---
title: "Kiến trúc và module của Spring"
description: "Kiến trúc Spring được tổ chức theo kiểu module. Mặc dù khá là nhiều nhưng bạn chỉ cần quan tâm đến những gì bạn cần dùng đến và mình sẽ giới thiệu chi tiết ở phần dưới."
keywords:
  [
    "giới thiệu spring",
    "spring framework",
    "spring cơ bản",
    "lộ trình spring",
    "kiến trúc của spring",
    "module của spring",
    "Dependency Injection và Inversion of Control",
  ]
chapter:
  name: "Tổng quan về Spring"
  slug: "chuong-02-tong-quan-ve-spring"
category:
  name: "Spring Boot"
  slug: "spring-boot"
position: 2
---

## Kiến trúc và module của Spring

![Kiến trúc spring](https://github.com/techmely/hoc-lap-trinh/assets/29374426/0fb746c7-cbe6-4ad7-860c-c4956b52a3ea)

Kiến trúc Spring được tổ chức theo kiểu module. Mặc dù khá là nhiều nhưng bạn chỉ cần quan tâm đến những gì bạn cần dùng đến và mình sẽ giới thiệu chi tiết ở phần dưới.

## Dependency Injection và Inversion of Control

- **Dependency Injection (DI)** là một design pattern để loại bỏ sự phụ thuộc lẫn nhau giữa những đoạn code (ví dụ: các hàm các class,..), vì vậy nó giúp rễ ràng quản lý, mở rộng code và test ứng dụng.

- **Inversion of Control (IoC)** Container có trách nhiệm khởi tạo, configure, gắn kết các đối tượng. Có hai kiểu của IoC containers là **BeanFactory** và **ApplicationContext**.

## Các module của Spring Framework

Spring Framework bao gồm nhiều tính năng được tổ chức thành khoảng 20 module. Nó được chia như sau:
![module Spring](https://github.com/techmely/hoc-lap-trinh/blob/spring-boots/spring-boot/images/spring-overview.png)

## Test

hỗ trợ việc kiểm tra các thành phần Spring với JUnit hoặc TestNG khuôn khổ.

### Core Container

**Core Container** bao gồm các module: **spring-core** , **spring-beans**, **spring-context**, và **spring-expression** (<b>Spring Expression Language</b>).

- **spring-core** và **spring-beans** cung cấp những phần cơ bản của framework, bao gồm **IoC** và **Dependency Injection** `Spring Bean` là center của `Spring Core`
  và được coi như là linh hồn của `Spring Application`.
- **spring-context** hỗ trợ đa ngôn ngữ (internationalization), các tính năng Java EE như EJB, JMX.
- **spring-expression** được mở rộng từ `Expression Language` trong **JSP**. Nó cung cấp hỗ trợ việc `setting/getting` giá trị, các method cải tiến cho phép truy cập collections, index, các toán tử logic v.v.

### Data Access/Integration

**Data Access/Integration** bao gồm các module JDBC, ORM, OXM, JMS và Transaction.

- **Module spring-jdbc** cung cấp một lớp JDBC-abstraction để loại bỏ những code tẻ nhạt cả JDBC và phân tích những mã lỗi cụ thể của database-vendor.
- **Module spring-orm** cung cấp lớp tích hợp với các orm API phổ biến như JPA, JDO và Hibernate.

* **Module spring-oxm** cung cấp lớp abstraction hỗ trợ triển khai Object/XML mapping như AXB, Castor, XMLBeans, JiBX and XStream.

- **Module spring-jms** chứa các tính năng tạo và sử dụng các message. Từ Spring Framework 4.1, nó được tích hợp với **spring-messaging**.
- **Module spring-transaction** hỗ trợ quản lý giao dịch theo chương trình và khai báo cho các lớp mà thực hiện các giao diện đặc biệt và cho tất cả các POJO của bạn.

#### _Web_

Hay còn được gọi là `Spring MVC` để hỗ trợ việc tạo ứng dụng Web, bao gồm: **spring-web** , **spring-webmvc**, **spring-websocket** và **springwebmvc-portlet**.

- **Module spring-web** cung cấp tính năng tích hợp web theo định hướng cơ bản như chức năng tập tin tải lên nhiều phần dữ liệu và khởi tạo các **container
  IoC** sử dụng nghe servlet và một bối cảnh ứng dụng web theo định hướng.
- **Module spring-webmvc** bao gồm việc triển khai _Model-View-Controller (MVC)_ của Spring cho các ứng dụng web.
- **Module spring-websocket** cung cấp hỗ trợ cho WebSocket-based, giao tiếp hai chiều giữa client và server trong các ứng dụng web.
- **Module springwebmvc-portlet** cung cấp việc triển khai MVC được sử dụng trong môi trường portlet và ánh xạ chức năng của **module Web-Servlet**.

### AOP, Aspects, Instrumentation và Messaging

Những module này hỗ trợ cài đặt lập trình hướng khía cạnh (Aspect Oriented Programming), hỗ trợ tích hợp với AspectJ.

- **Module AOP** cung cấp một thực hiện lập trình hướng khía cạnh cho phép bạn xác định phương pháp-chặn và pointcuts để sạch tách mã thực hiện chức
  năng đó nên được tách ra.
- **Module Aspects** cung cấp tích hợp với AspectJ, mà lại là một khuôn khổ AOP mạnh mẽ và trưởng thành.
- **Module Instrumentation** cung cấp thiết bị đo đạc lớp hỗ trợ và triển khai lớp bộ nạp được sử dụng trong các máy chủ ứng dụng nhất định.
- **Module Messaging** cung cấp hỗ trợ cho STOMP như **WebSocket** sub-protocol để sử dụng trong các ứng dụng. Nó cũng hỗ trợ một mô hình lập trình chú thích
  cho việc định tuyến và xử lý tin nhắn STOMP từ các máy khách **WebSocket**.
