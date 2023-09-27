---
title: "Lập trình hướng đối tượng (OOP) là gì?"
description: "Lập trình hướng đối tượng (Object Oriented Programming – OOP) là một trong những kỹ thuật lập trình rất quan trọng và sử dụng nhiều hiện nay. Hầu hết các ngôn ngữ lập trình hiện nay như Java, PHP, .NET, Ruby, Python… đều hỗ trợ OOP"
chapter:
  name: "Lập trình hướng đối tượng"
  slug: "chuong-03-lap-trinh-huong-doi-tuong"
image: https://user-images.githubusercontent.com/29374426/130178941-fc8cbd22-d121-48e0-a260-7b580e4d1298.png
position: 1
---

Lập trình hướng đối tượng (Object-Oriented Programming – OOP) là một phương pháp lập trình mạnh mẽ và phổ biến trong thế giới phát triển phần mềm. Nó đã trở thành tiêu chuẩn cho nhiều ngôn ngữ lập trình như Java, PHP, .NET, Ruby, Python và nhiều ngôn ngữ khác. OOP giúp tạo ra các ứng dụng phức tạp bằng cách sử dụng mô hình lập trình dựa trên các đối tượng có khả năng tương tác với nhau.

![Ví dụ lập trình hướng đối tượng](https://user-images.githubusercontent.com/29374426/130178941-fc8cbd22-d121-48e0-a260-7b580e4d1298.png)

## Đối tượng

Tại cơ bản, OOP xoay quanh hai khái niệm quan trọng: **đối tượng** và **lớp**.

**Đối tượng** là một thực thể cụ thể trong thế giới thực, có các đặc điểm cụ thể và có thể thực hiện các hành động. Mỗi đối tượng có hai thành phần chính:

- **Thuộc tính**: Đây là các thông tin và đặc điểm của đối tượng. Ví dụ, một đối tượng "Người" có thể có thuộc tính như tên, tuổi, địa chỉ.

- **Phương thức**: Đây là các hành động mà đối tượng có thể thực hiện. Ví dụ, đối tượng "Người" có thể có phương thức như đi, nói, ăn, uống.

## Lớp

**Lớp** là một khuôn mẫu hoặc một mô tả trừu tượng của các đối tượng. Nó định nghĩa các thuộc tính và phương thức mà tất cả các đối tượng thuộc về lớp đó sẽ có. Một lớp là một cách để tạo ra các đối tượng có cấu trúc và hành vi tương tự.

Ví dụ, nếu chúng ta định nghĩa lớp "Học sinh," thì tất cả các đối tượng thuộc lớp này sẽ có các thuộc tính như tên, tuổi, và các phương thức như học bài, nộp bài tập.

## Sự khác biệt giữa đối tượng và lớp

Để hiểu rõ hơn sự khác biệt giữa đối tượng và lớp, hãy xem xét ví dụ về "Xe hơi." Lớp "Xe hơi" có thể định nghĩa các thuộc tính như màu sắc, thương hiệu và model của xe hơi. Một đối tượng cụ thể của lớp "Xe hơi" có thể là chiếc xe cụ thể, chẳng hạn một chiếc xe màu đỏ, thương hiệu Toyota, model Camry.

![Sự khác nhau giữa đối tượng và lớp](https://user-images.githubusercontent.com/29374426/130180243-66b064c8-cb08-46b4-80e2-145972a20fbb.png)

Sự khác biệt giữa đối tượng và lớp giúp tổ chức mã nguồn và quản lý dự án phần mềm một cách hiệu quả. Lớp định nghĩa cấu trúc và hành vi chung, trong khi đối tượng thể hiện các phiên bản cụ thể của lớp đó.

## Các ưu điểm của lập trình hướng đối tượng

Lập trình hướng đối tượng mang lại nhiều lợi ích quan trọng:

1. **Tái sử dụng mã nguồn**: Bằng cách sử dụng lớp và đối tượng, bạn có thể tái sử dụng mã nguồn dễ dàng. Điều này giúp giảm sự lặp lại trong mã và tạo ra mã dễ bảo trì hơn.

2. **Tính đa hình**: OOP cho phép bạn sử dụng tính đa hình, nghĩa là bạn có thể sử dụng các đối tượng cùng một lớp một cách đa dạng. Ví dụ, bạn có thể sử dụng một phương thức "di chuyển" cho nhiều loại đối tượng khác nhau, như "Người" và "Xe hơi."

3. **Tính bảo mật và đóng gói**: OOP cho phép bạn ẩn thông tin cần thiết và chỉ tiết lộ thông qua các phương thức công khai. Điều này giúp bảo vệ dữ liệu và ngăn chặn truy cập trực tiếp đến các thuộc tính của đối tượng.

4. **Mô hình hóa thế giới thực**: OOP cho phép biểu diễn thế giới thực trên máy tính một cách tự nhiên hơn bằng cách sử dụng các đối tượng và lớp tương ứng với các thực thể và khái niệm trong thế giới thực.

Lập trình hướng đối tượng là một phần quan trọng của phát triển phần mềm hiện đại và cung cấp một cách cấu trúc hóa và quản lý mã nguồn mạnh mẽ, giúp tạo ra các ứng dụng phức tạp và dễ bảo trì.

Bạn có thể xem thêm 4 tính chất của lập trình hướng đối tượng dưới đây

- [Tính đóng gói](/bai-viet/java/tinh-dong-goi-trong-oop)
- [Tính thừa kế](/bai-viet/java/tinh-thua-ke-trong-oop)
- [Tính đa hình](/bai-viet/java/tinh-da-hinh-trong-oop)
- [Tính trừu tượng](/bai-viet/java/tinh-truu-tuong-trong-oop)
