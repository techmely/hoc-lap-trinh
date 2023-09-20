---
title: "Giới thiệu về Dependency Injection (DI) và IoC"
description: "Dependency Injection (DI) và Inversion of Control (IoC) là hai khái niệm quan trọng trong lập trình Java. DI giúp giảm sự phụ thuộc giữa các thành phần trong ứng dụng, tạo tính linh hoạt và tùy biến."
chapter:
  name: "Các khái niệm cơ bản về Spring"
  slug: "chuong-02-cac-khai-niem-co-ban"
category:
  name: "Spring Boot"
  slug: "spring-boot"
image: https://kungfutech.edu.vn/thumbnail.png
position: 7
---

Trong thế giới phức tạp của lập trình, Dependency Injection (DI) và Inversion of Control (IoC) là hai khái niệm quan trọng, giúp bạn quản lý phụ thuộc giữa các thành phần trong ứng dụng một cách hiệu quả. Trong bài viết này, chúng ta sẽ giải thích DI và IoC một cách dễ hiểu, đồng thời cung cấp các ví dụ trong ngôn ngữ Java.

## Dependency Injection (DI)

**Dependency Injection** là một mô hình lập trình và thiết kế phần mềm, không chỉ áp dụng cho Java mà còn cho nhiều ngôn ngữ khác. Đây là một phương pháp giúp giảm sự phụ thuộc giữa các thành phần (hoặc lớp) trong ứng dụng.

Trong DI, các phụ thuộc của một đối tượng không được tạo bên trong đối tượng đó, mà được cung cấp từ bên ngoài. Cụ thể, DI thường được thực hiện thông qua ba cách chính: Constructor Injection, Setter Injection và Interface Injection.

### Ví dụ về Dependency Injection (DI) trong Java

Giả sử bạn có một lớp `Girl` và một giao diện `Outfit`:

```java
public interface Outfit {
    void wear();
}

public class Bikini implements Outfit {
    public void wear() {
        System.out.println("Đã mặc Bikini");
    }
}

public class Girl {
    private Outfit outfit;

    public Girl(Outfit outfit) {
        this.outfit = outfit;
    }

    public void dressUp() {
        outfit.wear();
    }
}
```

Trong ví dụ này, lớp `Girl` không tạo ra một `Outfit` mà nó cần. Thay vào đó, nó chấp nhận một `Outfit` thông qua constructor của nó. Điều này làm giảm sự phụ thuộc của `Girl` vào một cụ thể `Outfit`, tạo điều kiện cho tính linh hoạt và tùy biến.

### Các cách thực hiện Dependency Injection

1. **Constructor Injection**: Dependency được tiêm vào thông qua constructor của lớp.

2. **Setter Injection**: Dependency được tiêm vào thông qua các phương thức setter.

3. **Interface Injection**: Các lớp cần dependency phải implement một giao diện có phương thức để tiêm dependency.

## Inversion of Control (IoC)

**Inversion of Control (IoC)** là một nguyên tắc lập trình, trong đó luồng điều khiển trong ứng dụng không được quyết định bởi ứng dụng mà được quyết định bởi một framework hoặc container bên ngoài.

IoC thường đi kèm với DI, nơi các dependency được quản lý và cung cấp bởi một framework hoặc container. Framework sẽ quản lý việc tạo và quản lý các đối tượng và phụ thuộc.

### Ví dụ về Inversion of Control (IoC) trong Java

Spring Framework là một ví dụ điển hình của IoC trong Java. Spring quản lý các đối tượng và dependency của bạn và cung cấp chúng khi bạn cần.

```java
public class Girl {
    private Outfit outfit;

    public Girl(Outfit outfit) {
        this.outfit = outfit;
    }

    public void dressUp() {
        outfit.wear();
    }
}

public static void main(String[] args) {
    ApplicationContext context = new ClassPathXmlApplicationContext("applicationContext.xml");
    Girl girl = context.getBean(Girl.class);
    girl.dressUp();
}
```

Trong ví dụ này, Spring Framework quản lý việc tạo ra đối tượng `Girl` và cung cấp `Outfit` thông qua DI. Bạn không cần tự tạo đối tượng `Girl`, Spring sẽ làm điều đó và cung cấp `Outfit` cho bạn.


::alert{type="success"}
Dependency Injection (DI) và Inversion of Control (IoC) là hai khái niệm quan trọng trong lập trình Java. DI giúp giảm sự phụ thuộc giữa các thành phần trong ứng dụng, tạo tính linh hoạt và tùy biến. IoC cho phép framework quản lý việc tạo và cung cấp dependency, tạo điều kiện cho việc quản lý phức tạp hóa ứng dụng. Hi vọng bài viết này đã giúp bạn hiểu rõ hơn về DI và IoC trong Java.
::
