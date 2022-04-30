---
title: "Cách hoạt động của Spring MVC"
description: "Ở bài này thì mình sẽ chia sẻ cách thức hoạt động của Spring MVC, từ đó các bạn sẽ hiểu được luồng đi của nó."
keywords:
  [
    "giới thiệu spring",
    "spring framework",
    "spring cơ bản",
    "lộ trình spring",
    "cách họat động của spring mvc",
    "nguyên lý hoạt động của spring mvc",
    "luồng Spring mvc"
  ]
chapter:
  name: "Tổng quan về Spring"
  slug: "chuong-02-tong-quan-ve-spring"
category:
  name: "spring"
  slug: "spring"
position: 19
---

## MVC hoạt động thế nào trong Spring
Ở bài này thì mình sẽ chia sẻ cách thức hoạt động của Spring MVC, từ đó các bạn sẽ hiểu được luồng đi của nó.

![Spring MVC](https://github.com/techmely/hoc-lap-trinh/blob/spring-boots/spring-boot/images/cach-hoat-dong-spring-mvc.png)

* Đầu tiên. sau khi nhận được yêu cầu **HTTP**, **DispatcherServlet** liên lạc với **HandlerMapping** để xác định *controller* nào sẽ xử lý yêu cầu này.
* **DispatcherServlet** gửi yêu cầu đến *controller* sau khi biết được *controller* nào sẽ xử lý yêu cầu. *Controller* nhận các yêu cầu và gọi phương thức thích hợp bằng cách sử dụng phương thức `GET` hoặc `POST`. Tại đây phương thức thích hợp được gọi sẽ thiết lập model dữ liệu và trả về tên view (đối tượng ModelAndView) cho **DispatcherServlet**.
* Tiếp theo, **DispatcherServlet** sẽ nhận được sử trợ giúp từ **ViewResolver** để xác định *view* cho các yêu cầu.
* Cuối cùng, quá trình chọn *view* hoàn thành, **DispatcherServlet** chuyển model dữ liệu tới *view* đó và cuối cùng chuyển tới trình duyệt.

Túm lại, luồng hoạt động của **Spring MVC** có thể được hiểu như sau: 
<content-info>
Đầu tiên mỗi request đến sẽ được đón nhận và xử lý bởi **DispatcherServlet**, về cơ bản **DispatcherServlet** được sử dụng để xử lý các **HTTP request**, vì nó được kế thừa từ **HTTPServlet**. **DispatcherServlet** gửi các request tới các *controller* và quyết định hồi đáp bằng cách gửi lại *view*.
</content-info>
