---
title: "Khám phá Kiến trúc và Module của Spring"
description: "Kiến trúc Spring được tổ chức theo kiểu module. Mặc dù khá là nhiều nhưng bạn chỉ cần quan tâm đến những gì bạn cần dùng đến và mình sẽ giới thiệu chi tiết ở phần dưới."
chapter:
  name: "Tổng quan về Spring"
  slug: "chuong-01-tong-quan-ve-spring"
position: 2
---

![Kiến trúc Spring](https://github.com/techmely/hoc-lap-trinh/assets/29374426/0fb746c7-cbe6-4ad7-860c-c4956b52a3ea)

## Giới Thiệu về Kiến trúc và Module của Spring

Spring Framework, một công cụ mạnh mẽ cho lập trình Java, được tổ chức theo kiểu module để mang đến tính linh hoạt và dễ quản lý cho các dự án phức tạp. Dưới đây, chúng tôi sẽ giới thiệu một số khía cạnh quan trọng của kiến trúc và các module quan trọng của Spring.

## Dependency Injection và Inversion of Control

[Dependency Injection (DI)](/bai-viet/spring-boot/dependency-injection) là một design pattern quan trọng trong Spring Framework, giúp loại bỏ sự phụ thuộc lẫn nhau giữa các thành phần của ứng dụng. Điều này làm cho việc quản lý, mở rộng mã nguồn và kiểm tra ứng dụng trở nên dễ dàng hơn.

[Inversion of Control (IoC)](/bai-viet/spring-boot/nguyen-ly-ioc-trong-spring) Container trong Spring chịu trách nhiệm khởi tạo, cấu hình và kết nối các đối tượng. Spring cung cấp hai loại IoC containers: **BeanFactory** và **ApplicationContext**, giúp quản lý các đối tượng của bạn một cách thông minh.

## Các Module Quan Trọng của Spring Framework

Spring Framework được chia thành khoảng 20 module, được tổ chức hợp lý để phục vụ các mục tiêu cụ thể. Dưới đây là một số module quan trọng:

### Core Container

**Core Container** bao gồm các module: **spring-core**, **spring-beans**, **spring-context**, và **spring-expression** (Spring Expression Language).

- **spring-core** và **spring-beans** cung cấp các phần cơ bản của framework, bao gồm **IoC** và **Dependency Injection**. `Spring Bean` được coi như linh hồn của ứng dụng Spring.
- **spring-context** hỗ trợ đa ngôn ngữ (internationalization) và tích hợp các tính năng Java EE như EJB và JMX.
- **spring-expression** cung cấp hỗ trợ cho việc đặt và lấy giá trị, toán tử logic và truy cập các tập hợp dữ liệu.

### Data Access/Integration

**Data Access/Integration** bao gồm các module JDBC, ORM, OXM, JMS và Transaction.

- **spring-jdbc** giúp giảm thiểu mã JDBC và hỗ trợ nhiều cơ sở dữ liệu.
- **spring-orm** tích hợp với các orm API phổ biến như JPA, JDO và Hibernate.
- **spring-oxm** hỗ trợ Object/XML mapping với nhiều công cụ như AXB, Castor, XMLBeans và nhiều công cụ khác.
- **spring-jms** cung cấp khả năng tạo và sử dụng các message và tích hợp với **spring-messaging**.
- **spring-transaction** hỗ trợ quản lý giao dịch cho các POJO và các lớp đặc biệt.

### Web

Spring cung cấp **Spring MVC** để xây dựng ứng dụng web. Module bao gồm: **spring-web**, **spring-webmvc**, **spring-websocket** và **springwebmvc-portlet**.

- **spring-web** hỗ trợ tích hợp web, chức năng tải tệp và khởi tạo **IoC container** sử dụng servlet.
- **spring-webmvc** triển khai Model-View-Controller (MVC) cho ứng dụng web.
- **spring-websocket** hỗ trợ WebSocket-based, giao tiếp hai chiều giữa client và server trong các ứng dụng web.
- **springwebmvc-portlet** dành cho môi trường portlet và ánh xạ chức năng của **module Web-Servlet**.

### AOP, Aspects, Instrumentation và Messaging

Những module này hỗ trợ lập trình hướng khía cạnh (Aspect Oriented Programming) và tích hợp với AspectJ.

- **Module AOP** cung cấp lập trình hướng khía cạnh, cho phép tách rời mã và các chức năng của ứng dụng.
- **Module Aspects** tích hợp với AspectJ, một khuôn khổ AOP mạnh mẽ.
- **Module Instrumentation** hỗ trợ đo đạc và triển khai lớp bộ nạp.
- **Module Messaging** hỗ trợ STOMP và WebSocket, cung cấp mô hình lập trình chú thích cho định tuyến và xử lý tin nhắn STOMP.

Spring Framework mang đến sự linh hoạt và tính mạnh mẽ cho lập trình Java, giúp bạn xây dựng ứng dụng hiệu quả và dễ bảo trì. Hãy khám phá các module này để tận dụng toàn bộ tiềm năng của Spring và trở thành một lập trình viên Java xuất sắc!
