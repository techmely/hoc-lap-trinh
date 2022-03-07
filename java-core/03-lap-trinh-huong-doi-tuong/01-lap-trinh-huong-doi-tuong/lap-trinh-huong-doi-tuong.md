---
title: "Lập trình hướng đối tượng (OOP) là gì?"
description: "Lập trình hướng đối tượng (Object Oriented Programming – OOP) là một trong những kỹ thuật lập trình rất quan trọng và sử dụng nhiều hiện nay. Hầu hết các ngôn ngữ lập trình hiện nay như Java, PHP, .NET, Ruby, Python… đều hỗ trợ OOP"
keywords:
  [
    "4 tính chất của oop java",
    "4 tính chất oop java",
    "4 tính chất oop trong java",
    "interface lập trình hướng đối tượng là gì",
    "lập trình hướng đối tượng",
    "lập trình hướng đối tượng (oop) là gì",
    "lập trình hướng đối tượng class",
    "lập trình hướng đối tượng java là gì",
    "lập trình hướng đối tượng là gì",
    "lập trình hướng đối tượng là gì ebook",
  ]
chapter:
  name: "Lập trình hướng đối tượng"
  slug: "chuong-03-lap-trinh-huong-doi-tuong"
category:
  name: "Java"
  slug: "java"
image: https://user-images.githubusercontent.com/29374426/130178941-fc8cbd22-d121-48e0-a260-7b580e4d1298.png
position: 1
---

Lập trình hướng đối tượng (Object Oriented Programming – OOP) là một trong những kỹ thuật lập trình rất quan trọng và sử dụng nhiều hiện nay. Hầu hết các ngôn ngữ lập trình hiện nay như Java, PHP, .NET, Ruby, Python… đều hỗ trợ OOP.

## Lập trình hướng đối tượng (OOP) là gì?

Lập trình hướng đối tượng (OOP) là một mô hình lập trình dựa trên khái niệm về **lớp** và **đối tượng**. Nó được sử dụng để cấu trúc một chương trình phần mềm thành các phần đơn giản, có thể tái sử dụng của các bản thiết kế mã (thường được gọi là các lớp), được sử dụng để tạo các thể hiện riêng lẻ của các đối tượng.

![Ví dụ lập trình hướng đối tượng](https://user-images.githubusercontent.com/29374426/130178941-fc8cbd22-d121-48e0-a260-7b580e4d1298.png)

### Đối tượng

Một đối tượng bao gồm 2 thông tin **thuộc tính** và **phương thức**

- **Thuộc tính** chính là những thông tin, đặc điểm của đối tượng. Ví dụ con người có các đặc tính như tên, tuổi, chiều cao, ...
- **Phương thức** là những thao tác, hành động mà đối tượng đó có thể thực hiện. Ví dụ một người sẽ có thể thực hiện hành động nói, đi, ăn, uống, . . .

### Lớp

Một lớp là một kiểu dữ liệu bao gồm các **thuộc tính** và các **phương thức** được định nghĩa từ trước. Đây là sự trừu tượng hóa của đối tượng. Khác với kiểu dữ liệu thông thường, một lớp là một đơn vị (trừu tượng) bao gồm sự kết hợp giữa các phương thức và các thuộc tính. Hiểu nôm na hơn là các **đối tượng** có các đặc tính tương tự nhau được gom lại thành một lớp đối tượng.

### Sự khác nhau giữa đối tượng và lớp

Lớp bạn có thể hiểu nó như là khuôn mẫu, đối tượng là một thực thể thể hiện dựa trên khuôn mẫu đó. Ví dụ ta nói về chiếc xe thì sẽ có thông tin như sau:

- Các thông tin, đặc điểm: màu sắc của xe, thương hiệu của xe, và model của xe.
- Các hành động như: sơn lại màu xe, xe chạy, ...

Đối tượng thì chính là chiếc xe của chúng ta, xe đang chạy trên đường,... và chúng sẽ có những đặc điểm riêng của các thuộc tính bên trên. Ví dụ như chiếc xe của tôi màu đỏ, thương hiệu Dodge, modal Charger còn chiếc xe của bạn tôi thì lại có màu xanh dương, thương hiệu Nissan, modal Ultima.

![Sự khác nhau giữa đối tượng và lớp](https://user-images.githubusercontent.com/29374426/130180243-66b064c8-cb08-46b4-80e2-145972a20fbb.png)

## Các ưu điểm của lập trình hướng đối tượng

- OOP mô hình hóa những thứ phức tạp dưới dạng cấu trúc đơn giản, có thể tái tạo
- Có thể tái sử dụng, dựa trên nguyên lý kế thừa, trong quá trình mô tả các lớp có thể loại bỏ những chương trình bị lặp, dư. Và có thể mở rộng khả năng sử dụng các lớp mà không cần thực hiện lại
- Cho phép hành động dành riêng cho lớp thông qua tính đa hình
- Tính bảo mật cao, bảo vệ thông tin thông qua tính đóng gói
- Sự xuất hiện của 2 khái niệm mới là lớp và đối tượng chính là đặc trưng của phương pháp lập trình hướng đối tượng. Nó đã giải quyết được các khuyết điểm của phương pháp lập trình hướng cấu trúc để lại. Ngoài ra 2 khái niệm này đã giúp biểu diễn tốt hơn thế giới thực trên máy tính.

## Các nguyên lý cơ bản của OOP

Java có 4 tính chất của lập trình hướng đối tượng là:

- [Tính đóng gói](/bai-viet/java/tinh-dong-goi-trong-java)
- [Tính thừa kế](/bai-viet/java/tinh-thua-ke-trong-java)
- [Tính đa hình](/bai-viet/java/tinh-da-hinh-trong-java)
- [Tính trừu tượng](/bai-viet/java/tinh-truu-tuong-trong-java)
