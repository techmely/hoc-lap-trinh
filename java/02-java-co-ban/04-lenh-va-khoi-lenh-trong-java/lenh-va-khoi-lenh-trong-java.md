---
title: "Lệnh và khối lệnh trong Java"
description: "Lệnh hay câu lệnh là tập hợp các từ khóa, tập ký tự trong java và được kết thúc bởi dấu chấm phẩy"
chapter:
  name: "Nhập môn Java"
  slug: "chuong-02-nhap-mon-java"
category:
  name: "Java"
  slug: "java"
image: https://upload.wikimedia.org/wikipedia/commons/2/29/Linux_command-line._Bash._GNOME_Terminal._screenshot.png
position: 4
---

Trong lập trình Java, "lệnh" và "khối lệnh" là hai khái niệm cơ bản giúp bạn xây dựng các chương trình Java phức tạp hơn. Hãy cùng tìm hiểu về chúng để có cái nhìn rõ ràng hơn về cách thực hiện các hành động và kiểm soát luồng trong mã Java của bạn.

## Lệnh trong Java

Lệnh (statement) trong Java là một dòng mã thực hiện một tác vụ cụ thể. Chúng có thể là gán giá trị cho biến, thực hiện phép tính, gọi phương thức, và nhiều tác vụ khác. Lệnh được kết thúc bằng dấu chấm phẩy `;`. Dưới đây là một số ví dụ về lệnh trong Java:

```java
int tuoi = 12;               // Gán giá trị cho biến tuoi
String ten = "Thaycacac";    // Gán giá trị cho biến ten
System.out.println("Hello"); // Gọi phương thức in ra màn hình
```

Lệnh giúp bạn thực hiện các nhiệm vụ cụ thể và là thành phần cơ bản trong việc viết mã Java.

## Khối Lệnh trong Java

Một khối lệnh (block statement) là một tập hợp các lệnh hoặc khối lệnh khác được nhóm lại trong dấu ngoặc nhọn `{}`. Khối lệnh được sử dụng để tạo một phạm vi cục bộ (local scope) cho các biến và để kiểm soát luồng chương trình.

Dưới đây là ví dụ về khối lệnh trong Java:

```java
{ // Bắt đầu khối lệnh 1
  int x = 5;       // Biến x trong phạm vi của khối lệnh 1
  System.out.println(x);
  { // Bắt đầu khối lệnh 2
    int y = 10;    // Biến y trong phạm vi của khối lệnh 2
    System.out.println(x + y);
  } // Kết thúc khối lệnh 2
  // Các lệnh khác trong khối lệnh 1
} // Kết thúc khối lệnh 1
```

Khối lệnh cho phép bạn quản lý phạm vi của biến và tạo cấu trúc phức tạp hơn trong mã Java. Chúng cũng thường được sử dụng trong cấu trúc điều kiện (if, else, switch) và vòng lặp (for, while) để xác định phạm vi thực hiện của các lệnh.

Trong Java, lệnh và khối lệnh là những yếu tố quan trọng giúp bạn xây dựng các chương trình mạnh mẽ và có cấu trúc. Việc hiểu và sử dụng chúng một cách hiệu quả sẽ giúp bạn trở thành một lập trình viên Java thành thạo.
