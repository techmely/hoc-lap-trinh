---
title: "Tính trừu tượng trong lập trình hướng đối tượng(OOP)"
description: "Trong lập trình hướng đối tượng, tính trừu tượng nghĩa là chọn ra các thuộc tính, phương thức của đối tượng cần cho việc giải quyết bài toán đang lập trình"
chapter:
  name: "Lập trình hướng đối tượng"
  slug: "chuong-03-lap-trinh-huong-doi-tuong"
category:
  name: "Java"
  slug: "java"
image: https://user-images.githubusercontent.com/29374426/131304738-aaf13d70-84e1-4787-b0b0-03fce36eaa2d.png
position: 5
---

Trong lập trình OOP, tính trừu tượng nghĩa là chọn ra các thuộc tính, phương thức của đối tượng cần cho việc giải quyết bài toán đang lập trình. Vì một đối tượng có rất nhiều thuộc tính phương thức, nhưng với bài toán cụ thể không nhất thiết phải chọn tất cả.

## Tính trừu tượng (Abstraction)

Trừu tượng có nghĩ là tổng quát hóa một cái gì đó lên, không cần chú ý chi tiết bên trong. Nó không màng đến chi tiết bên trong là gì và người ta vẫn hiểu nó mỗi khi nghe về nó.

Ví dụ: Bài toán quản lý sinh viên chúng ta chỉ cần quản lý các thông tin như

- Họ tên
- Ngày sinh
- Giới tính
- Điểm thi

Mà lại không cần quản lý thêm các thông tin:

- Màu tóc
- Sở thích
- Chiều cao

Tại vì chúng thực sự không cần thiết.

![Tính trừu tượng trong OOP](https://user-images.githubusercontent.com/29374426/131304738-aaf13d70-84e1-4787-b0b0-03fce36eaa2d.png)

## Ưu điểm khi sử dụng tính trừu tượng để lập trình

- Tính trừu tượng cho phép các lập trình viên loại bỏ tính chất phức tạp của đối tượng bằng cách chỉ đưa ra các thuộc tính và phương thức cần thiết của đối tượng trong lập trình, cải thiện khả năng bảo trì của hệ thống.
- Tính trừu tượng giúp chúng ta tập trung vào những cốt lõi cần thiết của đối tượng thay vì quan tâm đến cách nó thực hiện.
- Tính trừu tượng cung cấp nhiều tính năng mở rộng khi sử dụng kết hợp với tính đa hình và kế thừa trong lập trình hướng đối tượng.

Java trừu tượng hóa thông qua các lớp trừu tượng [Abstract class](/bai-viet/java/lop-abstract-trong-java) và các [Interface](/bai-viet/java/interface-trong-java)
