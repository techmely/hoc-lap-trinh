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

Tính trừu tượng (Abstraction) là một trong những khía cạnh quan trọng nhất của Lập Trình Hướng Đối Tượng (OOP). Nó cho phép bạn tạo ra các lớp và đối tượng trừu tượng, tập trung vào các tính năng quan trọng mà bạn quan tâm và che giấu chi tiết phức tạp bên trong. Chúng ta sẽ tìm hiểu về tính trừu tượng thông qua ví dụ thực tế và sử dụng Java để minh họa.

## Tại sao cần tính trừu tượng?

Tính trừu tượng giúp bạn tạo ra mã nguồn dễ bảo trì và dễ mở rộng. Nó cho phép bạn tạo các lớp trừu tượng và định nghĩa các giao diện để đảm bảo rằng các đối tượng sẽ tuân thủ một số quy tắc và chuẩn cố định.

## Ví dụ với Java

Hãy xem xét ví dụ về tính trừu tượng trong Java với một lớp trừu tượng "Động Vật" và các lớp con "Chó" và "Mèo."

```java
// Lớp trừu tượng "Động Vật"
abstract class Animal {
    abstract void sound(); // Phương thức trừu tượng
}

// Lớp con "Chó" kế thừa từ "Động Vật"
class Dog extends Animal {
    void sound() {
        System.out.println("Gâu gâu!");
    }
}

// Lớp con "Mèo" kế thừa từ "Động Vật"
class Cat extends Animal {
    void sound() {
        System.out.println("Meo meo!");
    }
}
```

Trong ví dụ này, lớp cha "Động Vật" là một lớp trừu tượng, nghĩa là nó chứa ít nhất một phương thức trừu tượng (`sound`). Các lớp con "Chó" và "Mèo" kế thừa từ lớp cha và phải triển khai phương thức `sound` dựa trên bản chất riêng của mỗi loài.

**Sử dụng tính trừu tượng:**

```java
Animal myDog = new Dog();
Animal myCat = new Cat();

myDog.sound(); // In ra "Gâu gâu!"
myCat.sound(); // In ra "Meo meo!"
```

Dù bạn tạo các đối tượng `myDog` và `myCat` kiểu "Động Vật," nhưng khi bạn gọi phương thức `sound`, Java tự động gọi phương thức tương ứng của lớp con. Điều này cho phép bạn tập trung vào tính năng quan trọng mà là tiếng kêu của động vật mà không quan tâm đến chi tiết bên trong mỗi loài.

## Ưu điểm của tính trừu tượng

- **Tập trung vào tính năng quan trọng**: Tính trừu tượng giúp bạn tập trung vào các tính năng và hành vi quan trọng mà đối tượng nên có mà không bị phân tâm bởi chi tiết triển khai.

- **Bảo trì và mở rộng dễ dàng**: Bằng cách tạo lớp trừu tượng và định nghĩa giao diện, bạn có thể đảm bảo rằng các đối tượng tuân thủ các quy tắc cố định và dễ mở rộng tính năng trong tương lai.

- **Che giấu chi tiết phức tạp**: Tính trừu tượng cho phép bạn che giấu chi tiết triển khai bên trong các lớp con, giúp làm cho mã nguồn trở nên dễ đọc và dễ bảo trì.

Tính trừu tượng là một trong những nguyên tắc quan trọng của OOP, giúp bạn tạo ra mã nguồn linh hoạt và dễ bảo trì bằng cách tập trung vào các tính năng quan trọng và che giấu chi tiết bên trong.
