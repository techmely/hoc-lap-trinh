---
title: "Cách hoạt động của Spring MVC"
description: "Spring MVC (Model-View-Controller) là một phần quan trọng của Spring Framework và là một trong những framework phát triển ứng dụng web phổ biến nhất"
chapter:
  name: "Tổng quan về Spring"
  slug: "chuong-01-tong-quan-ve-spring"
category:
  name: "Spring Boot"
  slug: "spring-boot"
position: 5
---

Spring MVC (Model-View-Controller) là một phần quan trọng của Spring Framework và là một trong những framework phát triển ứng dụng web phổ biến nhất. Nó giúp bạn tách biệt logic trong ứng dụng web thành các phần riêng biệt, giúp quản lý và phát triển dễ dàng hơn. Hãy cùng tìm hiểu cách Spring MVC hoạt động.

![Cách hoạt động của Spring MVC](https://github.com/techmely/hoc-lap-trinh/assets/29374426/46942e94-d850-4fea-9cc1-f7bea3731cd6)


## Quá Trình Hoạt Động của Spring MVC

Dưới đây là một tóm tắt về quá trình hoạt động của Spring MVC khi một yêu cầu được gửi từ máy khách (client) đến máy chủ (server):

1. **Yêu Cầu từ Client:** Người dùng gửi một yêu cầu từ trình duyệt hoặc ứng dụng di động đến máy chủ thông qua URL.

2. **DispatcherServlet:** DispatcherServlet là một thành phần quan trọng của Spring MVC, nó nhận yêu cầu từ client và quyết định Controller nào sẽ xử lý yêu cầu này.

3. **Controller Handling:** Controller nhận yêu cầu và xử lý nó. Controller thực hiện các thao tác liên quan đến dữ liệu như truy xuất cơ sở dữ liệu, xử lý nghiệp vụ, và chuẩn bị dữ liệu cần thiết để hiển thị.

4. **ModelAndView:** Controller trả về một đối tượng ModelAndView, chứa dữ liệu cần hiển thị và tên của View.

5. **View Resolution:** DispatcherServlet sử dụng tên của View từ ModelAndView để tìm View tương ứng. View có thể là một trang JSP, Thymeleaf, hoặc một đối tượng hiển thị JSON/XML.

6. **Hiển Thị Kết Quả:** View nhận dữ liệu từ ModelAndView và hiển thị chúng theo định dạng thích hợp. Sau đó, kết quả được gửi trả lại cho client.

7. **Phản Hồi cho Client:** Kết quả được gửi trả lại client và hiển thị trên trình duyệt hoặc ứng dụng di động của họ.

## Ưu Điểm của Spring MVC

- **Tách Biệt Logic:** Spring MVC giúp tách biệt logic của ứng dụng thành các thành phần riêng biệt, dễ quản lý và phát triển.

- **Kiểm Soát Tốt:** Điều này cho phép bạn kiểm soát tốt hơn quá trình xử lý yêu cầu và dữ liệu của ứng dụng.

- **Thiết Kế Mạnh Mẽ:** Spring MVC cung cấp một thiết kế mạnh mẽ và linh hoạt cho phát triển ứng dụng web.

- **Kỹ Thuật Spring Core:** Spring MVC tích hợp nhiều tính năng mạnh mẽ của Spring Core như Dependency Injection và AOP.

Spring MVC là một mô hình kiến trúc mạnh mẽ cho phát triển ứng dụng web. Nó giúp bạn tạo ra các ứng dụng có tổ chức và dễ quản lý, đồng thời tận dụng được các tính năng của Spring Framework. Nắm vững cách hoạt động của Spring MVC là một bước quan trọng để trở thành một lập trình viên web xuất sắc.
