---
title: "Giới Thiệu Website"
description: "Website là trang thông tin có thể chứa văn bản, hình ảnh, âm thanh, video… Chúng ta truy cập 1 trang web thông qua địa chỉ của nó, được gọi là URL."
keywords:
  [
    "giới thiệu website",
    "website là gì",
    "web tĩnh là gì",
    "web động là gì",
    "phân loại website",
  ]
chapter:
  name: "Tổng quan về ứng dụng web"
  slug: "chuong-01-tong-quan-ve-ung-dung-web"
category:
  name: "Spring Boot"
  slug: "spring-boot"
position: 1
---

![Giới Thiệu Website](https://github.com/techmely/hoc-lap-trinh/assets/29374426/3e4238b1-4481-47c7-90d4-67909e22804e)

### Website là gì?

Về mặt lý thuyết, website là trang thông tin có thể chứa văn bản, hình ảnh, âm thanh, video… Chúng ta truy cập 1 trang web thông qua địa chỉ của nó, được gọi là URL.

Còn để cho các bạn dễ hiểu hơn thì hãy hình dung [Facebook](https://www.facebook.com) facebook là 1 website,
hàng ngày chúng ta "on phây" bằng việc truy cập “https://www.facebook.com”, đó chính là URL.
[Youtube](https://www.youtube.com) thì URL là “https://www.youtube.com”.

### Phân loại

Website được chia làm 2 loại:

- **Website tĩnh** (Static Website)
- **Website động** (Dynamic Website)

#### Web tĩnh:

là loại website cơ bản mà người dùng hầu như không thể tương tác với web và chỉ được code bằng ngôn ngữ HTML (hoặc có thể thêm CSS, Javascript để tạo hiệu ứng).

<content-info>
Mình thường gọi loại web này nôm na là read-only, chỉ việc user truy cập web chỉ để đọc mà không tương tác được.
</content-info><br/><br/>

#### Web động:

là website mà nội dung có khả năng thay đổi có thể dựa theo yêu cầu client, thời gian hoặc ngữ cảnh.
<content-info>
Chúng ta có thể tương tác qua lại với trang web, kiểu như: 2 người nói chuyện, 1 người hỏi và 1 người trả lời (cái này hay còn gọi phía thuật ngữ chuyên ngành là <b>mô hình Client - Server</b>)
</content-info>

Nội dung của web này được lấy từ cơ sở dữ liệu (database) hoặc hệ thống quản lý nội dung (CMS). Và để tạo được 1 trang website động, chúng ta thường sử dụng ngôn ngữ phía server như: Java, Servlet, JSP, Python, C#,..
<content-info>
Chúng ta tương tác với website động bằng việc gửi 1 request -> server, server nhận -> xử lý request lấy những thông tin mà người dùng yêu cầu -> gửi lại tới user.
</content-info>
