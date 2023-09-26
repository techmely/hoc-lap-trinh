---
title: "Tính đóng gói trong lập trình hướng đối tượng(OOP)"
description: "Tính đóng gói trong java là kỹ thuật ẩn giấu thông tin không liên quan và hiện thị ra thông liên quan. Mục đích chính của đóng gói trong java là giảm thiểu mức độ phức tạp phát triển phần mềm"
chapter:
  name: "Lập trình hướng đối tượng"
  slug: "chuong-03-lap-trinh-huong-doi-tuong"
image: https://user-images.githubusercontent.com/29374426/130181521-4a08856a-756f-46f4-94f4-6ff1a0a90f18.png
position: 2
---

Tính đóng gói (Encapsulation) là một trong những nguyên tắc quan trọng trong Lập Trình Hướng Đối Tượng (OOP). Nguyên tắc này đề cập đến việc che giấu thông tin và hành vi bên trong đối tượng, chỉ tiết lộ những gì cần thiết và quy định cách truy cập thông qua các phương thức công khai. Chúng ta sẽ tìm hiểu về tính đóng gói thông qua ví dụ thực tế và sử dụng Java để minh họa.

## Tại sao cần tính đóng gói?

Trong lập trình, tính đóng gói giúp bảo vệ dữ liệu và tránh truy cập trực tiếp đến các thuộc tính của đối tượng từ bên ngoài. Điều này có ích trong việc quản lý và bảo vệ dữ liệu, đồng thời cho phép kiểm soát cách các thành phần khác nhau tương tác với đối tượng đó.

## Ví dụ với Java

Chúng ta hãy tưởng tượng một lớp đại diện cho một người trong Java. Chúng ta sẽ sử dụng tính đóng gói để bảo vệ thông tin cá nhân như tên và tuổi của người đó.

```java
public class Person {
    private String name;  // Thuộc tính name là private
    private int age;      // Thuộc tính age là private

    // Phương thức khởi tạo
    public Person(String name, int age) {
        this.name = name;
        this.age = age;
    }

    // Phương thức công khai để lấy tên
    public String getName() {
        return name;
    }

    // Phương thức công khai để lấy tuổi
    public int getAge() {
        return age;
    }

    // Phương thức công khai để thay đổi tuổi
    public void setAge(int age) {
        if (age >= 0) {
            this.age = age;
        }
    }
}
```

Trong ví dụ này, thuộc tính `name` và `age` được khai báo là private, nghĩa là chúng không thể truy cập trực tiếp từ bên ngoài lớp `Person`. Để lấy hoặc thay đổi giá trị của chúng, chúng ta sử dụng các phương thức công khai `getName`, `getAge`, và `setAge`.

**Lấy thông tin:**

```java
Person person = new Person("John", 30);
String name = person.getName();
int age = person.getAge();
System.out.println("Name: " + name);
System.out.println("Age: " + age);
```

**Thay đổi tuổi:**

```java
person.setAge(31); // Tuổi mới
int newAge = person.getAge(); // Lấy tuổi sau khi thay đổi
System.out.println("New Age: " + newAge);
```

Như bạn thấy, thông tin cá nhân của người được che giấu bên trong lớp `Person`, và bạn chỉ có thể truy cập thông qua các phương thức công khai. Điều này giúp đảm bảo rằng dữ liệu của người không bị sửa đổi hoặc truy cập một cách không kiểm soát.

Tính đóng gói là một nguyên tắc mạnh mẽ trong OOP, giúp tạo ra mã nguồn dễ bảo trì và an toàn hơn bằng cách quản lý truy cập đến thông tin của đối tượng.
