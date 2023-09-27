---
title: "Cài đặt môi trường Spring"
description: "Trong bài viết này, chúng ta sẽ hướng dẫn cách cài đặt môi trường để phát triển ứng dụng Spring. Để làm việc này, bạn cần cài đặt JDK, Apache Tomcat (hoặc Glassfish), và một IDE như IntelliJ (hoặc Eclipse)"
chapter:
  name: "Tổng quan về Spring"
  slug: "chuong-01-tong-quan-ve-spring"
position: 6
---

Trong bài viết này, chúng ta sẽ hướng dẫn cách cài đặt môi trường để phát triển ứng dụng Spring. Để làm việc này, bạn cần cài đặt JDK, Apache Tomcat (hoặc Glassfish), và một IDE như IntelliJ (hoặc Eclipse).

## Cài đặt JDK (Java Development Kit)

JDK, viết tắt của Java Development Kit, là một bộ phần mềm cung cấp môi trường phát triển cho ứng dụng Java. JDK bao gồm cả Java Runtime Environment (JRE), giúp lập trình viên có thể chạy thử và kiểm tra ứng dụng trong quá trình phát triển.

**Bước 1**: Truy cập trang web của Oracle để tải JDK. Chọn phiên bản 1.8 trở lên để đảm bảo tương thích với Spring.

![Cài đặt JDK](https://github.com/techmely/hoc-lap-trinh/assets/29374426/d2f9ed48-ba89-4989-965a-c9cff24f297b)

**Link tải**: [https://www.oracle.com/java/technologies/javase/javase8-archive-downloads.html](https://www.oracle.com/java/technologies/javase/javase8-archive-downloads.html)

**Bước 2**: Sau khi tải xong, bạn cài đặt JDK bằng cách chạy tệp cài đặt.

**Bước 3**: Để kiểm tra cài đặt thành công, mở Command Prompt (hoặc Terminal trên macOS) và nhập lệnh sau:

```bash
java -version
```

Nếu bạn thấy thông tin về phiên bản JDK hiển thị, điều này có nghĩa cài đặt đã thành công.

## Cài đặt Apache Tomcat (hoặc Glassfish)

Apache Tomcat là một máy chủ web HTTP được phát triển bởi Apache Software Foundation, dành cho việc phát triển ứng dụng Java Servlet, JavaServer Pages (JSP), Java EL và WebSocket.

**Bước 1**: Truy cập trang web của Apache Tomcat để tải phiên bản mới nhất.

![Tải Apache Tomcat](https://github.com/techmely/hoc-lap-trinh/assets/29374426/ca88f639-2b1c-4036-8214-c2d3572bf0fa)

**Link tải**: [https://tomcat.apache.org/download-80.cgi](https://tomcat.apache.org/download-80.cgi)

**Bước 2**: Tải tệp cài đặt và chạy tệp đó để cài đặt Apache Tomcat.

**Bước 3**: Kiểm tra cài đặt bằng cách mở trình duyệt và truy cập địa chỉ sau: `http://localhost:8080/`. Nếu bạn thấy trang quản trị của Tomcat, cài đặt đã thành công.

## Cài đặt IDE IntelliJ (hoặc Eclipse)

IDE (Integrated Development Environment) là môi trường phát triển tích hợp, giúp bạn dễ dàng phát triển ứng dụng Spring.

**Bước 1**: Truy cập trang web của IntelliJ để tải phiên bản Community hoặc đăng ký tài khoản Jetbrains để sử dụng bản Ultimate miễn phí trong 1 năm.

![Tải IntelliJ](https://github.com/techmely/hoc-lap-trinh/assets/29374426/f8132d91-6c5b-43e0-b742-05cd15439a46)

**Link tải**: [https://www.jetbrains.com/idea/download/#section=windows](https://www.jetbrains.com/idea/download/#section=windows)

**Bước 2**: Tải tệp cài đặt và chạy tệp đó để cài đặt IntelliJ.

**Bước 3**: Mở IntelliJ và tạo một dự án mới để bắt đầu phát triển ứng dụng Spring.

Bây giờ, bạn đã có môi trường phát triển hoàn chỉnh để bắt đầu phát triển ứng dụng Spring. Chúc bạn thành công trong việc phát triển ứng dụng của mình!
