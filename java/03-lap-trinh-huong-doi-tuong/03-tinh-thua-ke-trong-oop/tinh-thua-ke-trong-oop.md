---
title: "Tính kế thừa trong lập trình hướng đối tượng(OOP)"
description: "Tính kế thừa trong lập trình hướng đối tượng cho phép xây dựng một lớp mới dựa trên các định nghĩa của lớp đã có"
chapter:
  name: "Lập trình hướng đối tượng"
  slug: "chuong-03-lap-trinh-huong-doi-tuong"
image: https://user-images.githubusercontent.com/29374426/131276922-2608f214-0690-4eb4-96e3-b7384d4b2df3.png
position: 3
---

Kế thừa (Inheritance) là một trong những khía cạnh quan trọng nhất của Lập Trình Hướng Đối Tượng (OOP). Nó cho phép bạn tạo ra các lớp mới bằng cách sử dụng thông tin và hành vi từ các lớp đã tồn tại. Hãy tìm hiểu về tính kế thừa thông qua ví dụ thực tế và sử dụng Java để minh họa.

## Tại sao cần tính kế thừa?

Tính kế thừa giúp tái sử dụng mã nguồn và tạo ra cấu trúc phân cấp cho các lớp. Điều này cho phép bạn xây dựng các lớp mới trên cơ sở của các lớp đã có, tiết kiệm thời gian và công sức, đồng thời duy trì tính nhất quán trong mã nguồn.

## Ví dụ với Java

Hãy xem xét ví dụ về tính kế thừa trong Java sử dụng lớp "Động Vật" và lớp con "Chó."

```java
// Lớp cha "Động Vật"
class Animal {
    void eat() {
        System.out.println("Động vật đang ăn...");
    }
}

// Lớp con "Chó" kế thừa từ lớp "Động Vật"
class Dog extends Animal {
    void bark() {
        System.out.println("Chó sủa...");
    }
}
```

Trong ví dụ này, lớp "Chó" (Dog) kế thừa từ lớp "Động Vật" (Animal). Điều này có nghĩa là lớp "Chó" có mọi thông tin và hành vi của lớp "Động Vật," và nó cũng có thể có các phương thức và thuộc tính riêng của nó.

**Sử dụng tính kế thừa:**

```java
Dog dog = new Dog();
dog.eat(); // Gọi phương thức từ lớp cha
dog.bark(); // Gọi phương thức từ lớp con
```

Lúc này, bạn có thể thấy rằng lớp "Chó" đã kế thừa phương thức `eat` từ lớp "Động Vật," và nó cũng có thêm phương thức `bark` riêng của nó. Điều này cho phép bạn tận dụng lại mã nguồn của lớp "Động Vật" mà không cần viết lại từ đầu.

## Ưu điểm của tính kế thừa

- **Tái sử dụng mã nguồn**: Tính kế thừa cho phép bạn sử dụng lại mã nguồn đã tồn tại trong các lớp cha, giúp giảm lặp lại mã và tiết kiệm thời gian lập trình.

- **Tạo cấu trúc phân cấp**: Bằng cách xây dựng các lớp con trên cơ sở của các lớp cha, bạn có thể tạo ra cấu trúc phân cấp cho các đối tượng, làm cho mã nguồn trở nên dễ quản lý hơn.

- **Mở rộng tính năng**: Bạn có thể thêm các phương thức và thuộc tính mới vào lớp con mà không làm ảnh hưởng đến lớp cha, giúp bạn mở rộng tính năng của ứng dụng một cách dễ dàng.

Tính kế thừa là một trong những nguyên tắc quan trọng của OOP, cho phép bạn tận dụng lại và mở rộng mã nguồn một cách hiệu quả, giúp phát triển ứng dụng dễ bảo trì và mở rộng.
