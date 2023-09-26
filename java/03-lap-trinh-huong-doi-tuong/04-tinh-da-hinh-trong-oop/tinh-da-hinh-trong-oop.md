---
title: "Tính đa hình trong lập trình hướng đối tượng(OOP)"
description: "Bài này chúng ta sẽ tìm hiểu về Từ khóa final, tự học lập trình java, chia sẻ kiến thức về java"
chapter:
  name: "Lập trình hướng đối tượng"
  slug: "chuong-03-lap-trinh-huong-doi-tuong"
image: https://user-images.githubusercontent.com/29374426/131280717-ae65a2c9-0e6d-4b34-9b60-e0ebdd61331b.png
position: 4
---

Tính đa hình (Polymorphism) là một khía cạnh quan trọng trong Lập Trình Hướng Đối Tượng (OOP). Nó cho phép bạn thực hiện cùng một hành động trên các đối tượng khác nhau mà không cần quan tâm đến loại đối tượng cụ thể. Chúng ta sẽ tìm hiểu về tính đa hình thông qua ví dụ thực tế và sử dụng Java để minh họa.

## Tại sao cần tính đa hình?

Tính đa hình giúp tạo ra mã nguồn linh hoạt và dễ bảo trì. Nó cho phép bạn viết các phương thức chung mà có thể được sử dụng trên nhiều lớp khác nhau, giúp giảm sự lặp lại mã và tạo ra mã nguồn dễ mở rộng.

## Ví dụ với Java

Hãy xem xét ví dụ về tính đa hình trong Java sử dụng lớp cha "Hình" và các lớp con "Hình Tròn" và "Hình Vuông."

```java
// Lớp cha "Hình"
class Shape {
    void draw() {
        System.out.println("Vẽ hình...");
    }
}

// Lớp con "Hình Tròn"
class Circle extends Shape {
    void draw() {
        System.out.println("Vẽ hình tròn...");
    }
}

// Lớp con "Hình Vuông"
class Square extends Shape {
    void draw() {
        System.out.println("Vẽ hình vuông...");
    }
}
```

Trong ví dụ này, lớp cha "Hình" có một phương thức `draw` mà các lớp con "Hình Tròn" và "Hình Vuông" ghi đè (override). Điều này có nghĩa là mỗi lớp con có cùng tên phương thức `draw`, nhưng chúng thực hiện hành động riêng biệt.

**Sử dụng tính đa hình:**

```java
Shape shape1 = new Circle();
Shape shape2 = new Square();

shape1.draw(); // Gọi phương thức draw() của lớp Circle
shape2.draw(); // Gọi phương thức draw() của lớp Square
```

Dù bạn gán các đối tượng cho biến `shape1` và `shape2` kiểu lớp cha "Hình," nhưng khi bạn gọi phương thức `draw`, Java sẽ tự động gọi phương thức tương ứng của lớp con. Điều này chính là tính đa hình.

## Ưu điểm của tính đa hình

- **Tái sử dụng mã nguồn**: Bạn có thể sử dụng lại mã nguồn của các phương thức chung trên nhiều lớp con khác nhau.

- **Mã nguồn linh hoạt**: Tính đa hình cho phép bạn thay đổi hành vi của các đối tượng mà không cần thay đổi mã nguồn của các lớp khác.

- **Tạo cấu trúc phân cấp**: Bằng cách sử dụng tính đa hình, bạn có thể tạo ra các cấu trúc phân cấp cho các đối tượng trong ứng dụng của bạn, làm cho mã nguồn trở nên dễ bảo trì hơn.

Tính đa hình là một trong những khía cạnh quan trọng của OOP, giúp bạn viết mã nguồn dễ đọc, dễ bảo trì và linh hoạt hơn bằng cách cho phép bạn thực hiện cùng một hành động trên các đối tượng khác nhau một cách tự nhiên.
