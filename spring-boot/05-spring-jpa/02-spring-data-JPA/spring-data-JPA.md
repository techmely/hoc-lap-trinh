---
title: "Spring data JPA"
description: "Spring Data là một module của Spring Framework. Mục đích của Spring Data JPA là giảm thiểu việc thực hiện quá nhiều bước để có thể implement được JPA."
chapter:
  name: "Spring data JPA"
  slug: "chuong-07-spring-data-jpa"
category:
  name: "SpringBoots"
  slug: "springboots"
image: https://kungfutech.edu.vn/thumbnail.png
position: 2
---

## Java Persistence API

Trong Java để thực hiện các thao tác CRU (create–read–update-delete)đến CSDL thường sử dụng JDBC.Với JDBC chúng ta cần thực hiện các việc chúng ta cần hiểu code Java và SQL.Khi CSDL thay đổi thì cần phải thay đổi lại code của câu lệnh sql vì mỗi hệ quản trị CSDL sẽ có một số phần khác nhau.Công việc sửa code lại đòi hỏi phải test lại ứng dụng.Điều này gây tốn thày gian,chi phí phát triển và cũng gặp không ít rủi ro.

Để khắc phục nhược điểm trên,đã có nhiều Framework ra đời với mục đích xoá đi vấn đề về tương thích giữa các CSDL giúp tập trung vào phần xử lý nghiệp vụ.Và JPA là một chuẩn đặc tả cho các ORM Framework để giải quyết vấn đề trên.

#### Java Persistence API(JPA)là gì

JPA là một bộ đặc tả tiêu chuẩn của Java,trong đó mô tả các thao tác quản lý dữ liệu quan hệ sử dụng công nghệ ORM trong các ứng dụng sử dụng Java.

![Java Persistence API(JPA)là gì](https://user-images.githubusercontent.com/29374426/174511700-1b2170bd-bbad-4221-9ffc-46b7a4532240.png)

JPA cung cấp đầy đủ các công cụ cho phép thao tác với CSDL một cách đơn giản và nhanh chóng. JPA có thể dùng để persist một đối tượng POJO vào trong CSDL hoặc lấy dữ liệu từ CSDL và ánh xạ ra các đối tượng POJO.
JPA hoạt động như một cầu nối giữa các bảng/các mối quan hệ giữa các bảng trong cơ sở dữ liệu và các lớp/mối quan hệ giữa các đối tượng.Ví dụ:table USER với các cột(Id,username,password)sẽ tương ứng với lớp Userjava với các field Id,username,password.Từ đó mỗi khi truy vấn bảng hay các cột ta sẽ gọi trực tiếp các phương thức trên các lớp,các thuộc tính của class mà không cần quan tâm tới việc đang dùng loại cơ sở dữ liệu nào.

Lợi ích JPA

- Viết ít code hơn
- Performance tốt
- Độc lập về cơ sở dữ liệu
- Tránh được các lỗi cú pháp của SQL do không phải làm việc với SQL
- Hỗ trợ cấu hình triển khai bằng annotation và xml
- Có nhiều framework ORM miễn phí hỗ trợ có thể dùng để phát triển nhiều loại ứng dụng khácnhau
- JPA là một đặc tả đã được chuẩn hóa và là một thành phần trong đặc tả EJB3 Dễ dàng chuyển từ một ORM này sang một ORM khác
