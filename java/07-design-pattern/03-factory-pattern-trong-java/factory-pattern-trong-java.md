---
title: "Factory Pattern trong Java"
description: "Factory Pattern, hoặc còn được gọi là Factory Method Pattern, là một trong những mẫu thiết kế quan trọng trong lập trình phần mềm. Factory Pattern rất phổ biến trong JDK (Java Development Kit) và các framework như Spring và Struts"
chapter:
  name: "Design Pattern"
  slug: "chuong-07-design-pattern"
category:
  name: "Java"
  slug: "java"
image: https://user-images.githubusercontent.com/29374426/146175674-fa7e09f7-4e42-485e-a2b5-8c664601b203.png
position: 3
---

**Factory Pattern**, hoặc còn được gọi là **Factory Method Pattern**, là một trong những mẫu thiết kế quan trọng trong lập trình phần mềm. Chúng ta thường sử dụng nó khi muốn tạo ra các đối tượng một cách linh hoạt, dựa trên một số điều kiện hoặc đầu vào cụ thể. **Factory Pattern** rất phổ biến trong JDK (Java Development Kit) và các framework như Spring và Struts.

## Factory Pattern là gì?

**Factory Pattern** thuộc loại **mẫu thiết kế tạo dựng (Creation Pattern)**. Nó giúp chúng ta tạo ra đối tượng dựa trên một class cha (super class) và nhiều class con (sub-class) tương ứng với các tình huống khác nhau. Thông qua **Factory Pattern**, chúng ta có thể tạo ra một đối tượng mà không cần biết cụ thể nó được tạo ra từ class con nào.

Lợi ích của **Factory Pattern**:

1. Cung cấp một giao diện (interface) thay vì các cài đặt cụ thể, giúp code dễ dàng mở rộng và bảo trì.

2. Cho phép mở rộng code dễ dàng bằng cách thêm mới các class con mà không làm thay đổi code hiện tại.

Ví dụ, một số class và method trong JDK sử dụng **Factory Pattern**:

- `java.util.Calendar`, `ResourceBundle`, và `NumberFormat` là các class sử dụng **Factory Pattern**.
- Method `valueOf()` trong các wrapper class như `Boolean`, `Integer`, `Double`.

## UML Diagram của Factory Pattern

![UML Diagram của Factory Pattern](https://github.com/techmely/hoc-lap-trinh/assets/29374426/bd9af382-4097-48cd-9115-e1cc7357fbdb)

- `Creator`: Interface khai báo factory method để tạo ra đối tượng cha (super class).
- `ConcreteCreator`: Class thực hiện cài đặt factory method để tạo ra các đối tượng con (sub-class).
- `ParrentClass`: Super class hoặc interface đại diện cho đối tượng cha (super class).
- `SubClass_1`, `SubClass_2`: Các class con (sub-class) tạo ra từ factory method.

## Ví dụ về Factory Pattern

![Ví dụ Về Factory Pattern](https://github.com/techmely/hoc-lap-trinh/assets/29374426/f45e4b5c-c295-4c33-8958-af306234004b)

Giả sử chúng ta có một class cha là `Computer` và hai class con là `Server` và `PC`. Chúng ta muốn tạo ra các đối tượng `Server` hoặc `PC` dựa trên dữ liệu đầu vào.

```java
// Super class
public abstract class Computer {
    public abstract String getRAM();
    public abstract String getHDD();
    public abstract String getCPU();

    @Override
    public String toString(){
        return "RAM= " + this.getRAM() + ", HDD=" + this.getHDD() + ", CPU=" + this.getCPU();
    }
}

// Class con 1
public class PC extends Computer {
    private String ram;
    private String hdd;
    private String cpu;

    public PC(String ram, String hdd, String cpu){
        this.ram = ram;
        this.hdd = hdd;
        this.cpu = cpu;
    }

    @Override
    public String getRAM() {
        return this.ram;
    }

    @Override
    public String getHDD() {
        return this.hdd;
    }

    @Override
    public String getCPU() {
        return this.cpu;
    }
}

// Class con 2
public class Server extends Computer {
    private String ram;
    private String hdd;
    private String cpu;

    public Server(String ram, String hdd, String cpu){
        this.ram = ram;
        this.hdd = hdd;
        this.cpu = cpu;
    }

    @Override
    public String getRAM() {
        return this.ram;
    }

    @Override
    public String getHDD() {
        return this.hdd;
    }

    @Override
    public String getCPU() {
        return this.cpu;
    }
}
```

Chúng ta sử dụng **Factory Pattern** để tạo đối tượng `Computer` mà không cần biết cụ thể nó là `Server` hay `PC`. Dưới đây là một ví dụ về cách sử dụng **Factory Pattern**:

```java
public class TestFactory {
    public static void main(String[] args) {
        Computer pc = ComputerFactory.getComputer("pc", "2 GB", "500 GB", "2.4 GHz");
        Computer server = ComputerFactory.getComputer("server", "16 GB", "1 TB", "2.9 GHz");

        System.out.println("Factory PC Config::" + pc);
        System.out.println("Factory Server Config::" + server);
    }
}
```

<content-result>
Factory PC Config::RAM= 2 GB, HDD=500 GB, CPU=2.4 GHz
Factory Server Config::RAM= 16 GB, HDD=1 TB, CPU=2.9 GHz
</content-result>

**Factory Pattern** giúp tạo đối tượng một cách linh hoạt, bảo toàn tính nhất quán trong dự án và giúp code dễ dàng mở rộng.
