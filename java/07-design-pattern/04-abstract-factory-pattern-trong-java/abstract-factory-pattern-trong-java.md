---
title: "Abstract Factory Pattern trong Java"
description: "FAbstract Factory Pattern, còn gọi là Factory of Factories, là một mẫu thiết kế tạo dựng (Creation Pattern). Nó tương tự như Factory Pattern, nhưng cung cấp một mức trừu tượng hơn để tạo ra các đối tượng liên quan đến nhau."
chapter:
  name: "Design Pattern"
  slug: "chuong-07-design-pattern"
category:
  name: "Java"
  slug: "java"
image: https://user-images.githubusercontent.com/29374426/146175674-fa7e09f7-4e42-485e-a2b5-8c664601b203.png
position: 4
---

**Abstract Factory Pattern**, còn gọi là **Factory of Factories**, là một mẫu thiết kế tạo dựng (Creation Pattern). Nó tương tự như **Factory Pattern**, nhưng cung cấp một mức trừu tượng hơn để tạo ra các đối tượng liên quan đến nhau.

## Abstract Factory Pattern

Nếu bạn đã quen thuộc với **Factory Pattern**, bạn biết rằng nó chỉ sử dụng một lớp Factory duy nhất để tạo ra các đối tượng con (sub-class) dựa trên đầu vào (thường sử dụng if-else hoặc switch để xác định lớp con nào sẽ được trả về).

**Abstract Factory Pattern** cũng liên quan đến việc tạo đối tượng, nhưng nó nâng cấp điểm yếu của **Factory Pattern**. Thay vì sử dụng if-else hoặc switch để xác định đối tượng con cụ thể, **Abstract Factory Pattern** sử dụng một cấu trúc dạng hình thức để quyết định đối tượng nào sẽ được tạo ra.

Một số ví dụ về **Abstract Factory Pattern** trong JDK (Java Development Kit) bao gồm:

- `javax.xml.parsers.DocumentBuilderFactory#newInstance()`
- `javax.xml.transform.TransformerFactory#newInstance()`
- `javax.xml.xpath.XPathFactory#newInstance()`

**Lợi ích của Abstract Factory Pattern**:

- Cung cấp hướng tiếp cận code thông qua giao diện (interface) thay vì sử dụng cài đặt cụ thể, giống với **Factory Pattern**.
- Có thể mở rộng dễ dàng bằng cách thêm các Factory và các đối tượng con mới mà không làm thay đổi code hiện tại.
- Giúp tránh việc sử dụng các điều kiện logic như if-else bên trong **Factory Pattern**.

## Abstract Factory Pattern UML Diagram

Cũng giống như [Factory Pattern](/bai-viet/java/factory-pattern-trong-java), chúng ta sẽ sử dụng các super class, sub-class

![Abstract Factory Pattern UML Diagram](https://github.com/techmely/hoc-lap-trinh/assets/29374426/be47b0a0-884b-44dd-aae0-e41532035360)

**Abstract Factory Pattern** sử dụng các lớp cha và lớp con, tương tự như **Factory Pattern**. Tuy nhiên, khác biệt quan trọng nằm ở việc có nhiều lớp Factory (ConcreteFactory_1, ConcreteFactory_2) cùng triển khai một Interface trừu tượng (AbstractFactory). Mỗi lớp Factory này sẽ trả về các đối tượng khác nhau.

## Ví dụ

Giả sử chúng ta có một class cha là `Computer` và hai class con là `Server` và `PC`. Chúng ta muốn tạo các đối tượng `Server` hoặc `PC` dựa trên dữ liệu đầu vào.

`ComputerAbstractFactory` là một interface cung cấp phương thức trả về đối tượng Computer.

`ServerFactory` và `PCFactory` sẽ cài đặt các phương thức của ComputerAbstractFactory.

`ComputerFactory` sẽ sử dụng `ComputerAbstractFactory` để tạo đối tượng Computer. (Trường hợp `ComputerAbstractFactory` là `ServerFactory` thì sẽ trả về đối tượng `Server`, trường hợp `ComputerAbstractFactory` là `PCFactory` thì sẽ trả về đối tượng PC)

![image](https://github.com/techmely/hoc-lap-trinh/assets/29374426/524ed915-bd7f-4c6b-b356-2c820853b341)


### Các Lớp

```java
// Lớp cha
public abstract class Computer {
    public abstract String getRAM();
    public abstract String getHDD();
    public abstract String getCPU();

    @Override
    public String toString(){
        return "RAM= " + this.getRAM() + ", HDD=" + this.getHDD() + ", CPU=" + this.getCPU();
    }
}

// Lớp con 1
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

// Lớp con 2
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

### Các Interface và Lớp Factory

```java
// Interface trừu tượng
public interface ComputerAbstractFactory {
    public Computer createComputer();
}

// Lớp Factory cho PC
public class PCFactory implements ComputerAbstractFactory {
    private String ram;
    private String hdd;
    private String cpu;

    public PCFactory(String ram, String hdd, String cpu){
        this.ram = ram;
        this.hdd = hdd;
        this.cpu = cpu;
    }

    @Override
    public Computer createComputer() {
        return new PC(ram, hdd, cpu);
    }
}

// Lớp Factory cho Server
public class ServerFactory implements ComputerAbstractFactory {
    private String ram;
    private String hdd;
    private String cpu;

    public ServerFactory(String ram, String hdd, String cpu){
        this.ram = ram;
        this.hdd = hdd;
        this.cpu = cpu;
    }

    @Override
    public Computer createComputer() {
        return new Server(ram, hdd, cpu);
    }
}
```

### Lớp Factory chính

```java
public class ComputerFactory {
    public static Computer getComputer(ComputerAbstractFactory factory){
        return factory.createComputer();
    }
}
```

### Demo

```java
public class TestDesignPatterns {
    public static void main(String[] args) {
        testAbstractFactory();
    }

    private static void testAbstractFactory() {
        Computer pc = ComputerFactory.getComputer(new PCFactory("2 GB","500 GB","2.4 GHz"));
        Computer server = ComputerFactory.getComputer(new ServerFactory("16 GB","1 TB","2.9 GHz"));

        System.out.println("AbstractFactory PC Config::" + pc);
        System.out.println("AbstractFactory Server Config::" + server);
    }
}
```

<content-result>
AbstractFactory PC Config::RAM= 2 GB, HDD=500 GB, CPU=2.4 GHz
AbstractFactory Server Config::RAM= 16 GB, HDD=1 TB, CPU=2.9 GHz
</content-result>

Bây giờ, nếu chúng ta muốn thêm một lớp con khác, ví dụ như `Laptop`, chúng ta chỉ cần tạo lớp `Laptop` và `LaptopFactory` tương ứng mà không cần sửa đổi code hiện tại.
