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
    "luồng Spring mvc",
  ]
chapter:
  name: "Tổng quan về Spring"
  slug: "chuong-02-tong-quan-ve-spring"
category:
  name: "Spring Boot"
  slug: "spring-boot"
position: 5
---

## MVC hoạt động thế nào trong Spring

Ở bài này thì mình sẽ chia sẻ cách thức hoạt động của Spring MVC, từ đó các bạn sẽ hiểu được luồng đi của nó.

![Spring MVC](https://github.com/techmely/hoc-lap-trinh/assets/29374426/ccf4b629-2efb-48e7-ac73-30ef550bb7cb)

- Đầu tiên. sau khi nhận được yêu cầu **HTTP**, **DispatcherServlet** liên lạc với **HandlerMapping** để xác định _controller_ nào sẽ xử lý yêu cầu này.
- **DispatcherServlet** gửi yêu cầu đến _controller_ sau khi biết được _controller_ nào sẽ xử lý yêu cầu. _Controller_ nhận các yêu cầu và gọi phương thức thích hợp bằng cách sử dụng phương thức `GET` hoặc `POST`. Tại đây phương thức thích hợp được gọi sẽ thiết lập model dữ liệu và trả về tên view (đối tượng ModelAndView) cho **DispatcherServlet**.
- Tiếp theo, **DispatcherServlet** sẽ nhận được sử trợ giúp từ **ViewResolver** để xác định _view_ cho các yêu cầu.
- Cuối cùng, quá trình chọn _view_ hoàn thành, **DispatcherServlet** chuyển model dữ liệu tới _view_ đó và cuối cùng chuyển tới trình duyệt.

Túm lại, luồng hoạt động của **Spring MVC** có thể được hiểu như sau:

Đầu tiên mỗi request đến sẽ được đón nhận và xử lý bởi **DispatcherServlet**, về cơ bản **DispatcherServlet** được sử dụng để xử lý các **HTTP request**, vì nó được kế thừa từ **HTTPServlet**. **DispatcherServlet** gửi các request tới các _controller_ và quyết định hồi đáp bằng cách gửi lại _view_.
