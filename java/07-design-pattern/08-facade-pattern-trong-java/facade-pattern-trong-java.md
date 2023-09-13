---
title: "Facade Pattern trong Java"
description: "Facade Pattern được sử dụng để làm cho việc giao tiếp với hệ thống trở nên dễ dàng hơn đối với các ứng dụng client"
chapter:
  name: "Design Pattern"
  slug: "chuong-07-design-pattern"
category:
  name: "Java"
  slug: "java"
image: https://user-images.githubusercontent.com/29374426/146175674-fa7e09f7-4e42-485e-a2b5-8c664601b203.png
position: 8
---

**Facade Pattern** là một mẫu [design pattern](/bai-viet/java/design-pattern-la-gi-design-pattern-trong-java) trong lập trình Java.

## Facade Pattern là gì

**Facade Pattern** được sử dụng để làm cho việc giao tiếp với hệ thống trở nên dễ dàng hơn đối với các ứng dụng client. Thay vì phải tương tác trực tiếp với nhiều hệ thống hoặc module con, **Facade Pattern** giúp ứng dụng client chỉ cần giao tiếp với một hệ thống duy nhất thông qua một giao diện đơn giản.

Ví dụ: Khi bạn đăng ký một tài khoản trực tuyến, bạn cần nhập thông tin như tên đăng nhập, email, địa chỉ và số điện thoại. Thay vì phải nhập thông tin này trên nhiều trang khác nhau, **Facade Pattern** cho phép bạn gộp tất cả thông tin này vào một màn hình đơn giản, và bạn chỉ cần tương tác với màn hình đó.

## Facade Pattern UML Diagram

Bên dưới là một sơ đồ UML của **Facade Pattern**:

```scss
+----------------+        +------------------+
|   Client       |        |   Facade         |
+----------------+        +------------------+
|                |        | - subsystem1    |
|                |        | - subsystem2    |
|                |        | - subsystem3    |
|                |        |                |
|                |        | + operation1()  |
|                |        | + operation2()  |
|                |        | + operation3()  |
|                |        |                |
+----------------+        +------------------+
```

![Facade Pattern UML Diagram](https://github.com/techmely/hoc-lap-trinh/assets/29374426/e7179b15-94d1-4f04-966a-ff8600d4a74d)

## Ví dụ về Facade Pattern

![Ví dụ về Facade Pattern](https://github.com/techmely/hoc-lap-trinh/assets/29374426/31a38767-cc86-4776-821d-4411ee06d2b7)

Giả sử bạn có một hệ thống cũ gồm các lớp **Address**, **PhoneNumber**, và **Name**, và bạn muốn quản lý thông tin này thông qua một lớp **PersonFacade**.

### Các Lớp

```java
public class Name {
    // Các thuộc tính
    // Các getter và setter
    // ...
}

public class Address {
    // Các thuộc tính
    // Các getter và setter
    // ...
}

public class PhoneNumber {
    // Các thuộc tính
    // Các getter và setter
    // ...
}

public class PersonFacade {
    private Name name;
    private Address address;
    private PhoneNumber phoneNumber;

    // Các getter và setter cho name, address, phoneNumber
    // Các phương thức khác để hiển thị và quản lý thông tin
    // ...
}
```

### Sử dụng Facade Pattern

```java
public class MainApp {
    public static void main(String[] args) {
        PersonFacade person = new PersonFacade();
        person.setInformation();
        person.display();
    }
}
```

**Facade Pattern** giúp gói gọn thông tin quản lý người vào một lớp **PersonFacade**, giúp cho việc giao tiếp và quản lý thông tin trở nên dễ dàng hơn cho ứng dụng client.
