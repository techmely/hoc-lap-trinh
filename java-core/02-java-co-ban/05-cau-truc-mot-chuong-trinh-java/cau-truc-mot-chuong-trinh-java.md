---
title: "Cấu trúc một chương trình Java"
description: "Ngôn ngữ lập trình Java được thiết kế với các đặc tính xoay quanh đặc trưng hướng đối tượng. Bài này chúng ta cùng nhau tìm hiểu xem cấu trúc của một chương trình java"
keywords:
  [
    "cấu trúc 1 chương trình java",
    "cấu trúc chương trình java",
    "cấu trúc của 1 chương trình java",
    "cấu trúc của một chương trình",
    "cấu trúc của một chương trình java",
    "cấu trúc một chương trình java",
    "cấu trúc một chương trình java bị lỗi",
    "cấu trúc một chương trình java desktop",
    "cấu trúc một chương trình java developer",
    "cấu trúc một chương trình java eclipse",
    "cấu trúc một chương trình java example",
  ]
chapter:
  name: "Nhập môn Java"
  slug: "chuong-02-nhap-mon-java"
category:
  name: "Java"
  slug: "java"
image: https://user-images.githubusercontent.com/29374426/126427809-717c3eb0-ffba-4fa5-8e52-ec12ad9b548d.png
position: 5
---

Ngôn ngữ lập trình Java được thiết kế với các đặc tính xoay quanh đặc trưng hướng đối tượng. Đó chính là việc xoay quanh việc thiết kế các lớp (Class) và việc tạo các đối tượng (Object) là thể hiện của lớp.

Trong ngôn ngữ Java, lớp là một đơn vị mẫu có chứa dữ liệu và mã lệnh liên quan đến một thực thể nào đó. Khi xây dựng một lớp, thực chất bạn đang tạo ra một một kiểu dữ liệu. Kiểu dữ liệu mới này được sử dụng để xác định các biến mà ta thương gọi là “đối tượng”. Đối tượng là các thể hiện (instance) của lớp. Tất cả các đối tượng đều thuộc về một lớp có chung đặc tính và hành vi. Mỗi lớp xác định một thực thể, trong khi đó mỗi đối tượng là một thể hiện thực sự.

Phát triển ứng dụng Java sẽ được khởi đầu bằng việc định nghĩa các lớp, Sau khi định nghĩa các lớp xong, định dạng của tệp lưu trữ các lớp sẽ có đuôi mở rộng là .java. Ví dụ:

```java
package <package_name>;

import <oher_package>;

public class ClassName {
  <Variables (also known as fields)>;

  <constructor method(s)>;

  <other methods>;
}
```

_Trong đó:_

- **package**: Một package (gói) mô tả không gian tên có chứa các lớp của Java, sử dụng ký tự thường và dấu chấm để định nghĩa tên, chúng ta có thể xem package như là một thư mục, còn class chính là các file trực thuộc thư mục.
- **import**: Từ khóa được sử dụng trong Java nhằm để xác định các class hoặc các package được sử dụng trong lớp này.
- **class**: Từ khóa nhằm để định nghĩa lớp của Java. Nó đứng trước khai báo tên lớp của Java. Ngoài ra còn có từ khóa public, từ khóa này xác định phạm vi truy cập của lớp. Đặc tính này chính là tính đóng gói trong lập trình hướng đối tượng. (chúng ta sẽ tìm hiểu phần này ở các bài sau)
- **variables**: Biến hay còn gọi là trường, cũng có một số tài liệu gọi là thuộc tính trực thuộc lớp. Nó chứa thông tin cụ thể liên quan tới các đối tượng là thể hiện của lớp.
- **methods**: Phương thức hay còn gọi là hàm chứa các hành động thực thi của đối tượng. Đương nhiên nội dung của phương thức chính là các đoạn mã thực thi của chính phương thức này.
- **constructors** : Phương thức khởi tạo (Hay hàm khởi tạo) của đối tượng. Hình dạng của đối tượng được thể hiện ra sao sẽ phụ thuộc vào phương thức này.

<content-example />

![cau-truc-mot-chuong-trinh-java](https://user-images.githubusercontent.com/29374426/126427809-717c3eb0-ffba-4fa5-8e52-ec12ad9b548d.png)
