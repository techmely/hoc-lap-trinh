---
title: "Builder Pattern trong Java"
description: "Builder Pattern, hay còn gọi là Mẫu Thiết Kế Builder, là một trong các mẫu thiết kế tạo dựng (Creation Pattern). Builder Pattern được tạo ra để giải quyết một số nhược điểm của Factory Pattern và Abstract Factory Pattern khi làm việc với các đối tượng có nhiều thuộc tính."
chapter:
  name: "Design Pattern"
  slug: "chuong-07-design-pattern"
category:
  name: "Java"
  slug: "java"
image: https://user-images.githubusercontent.com/29374426/146175674-fa7e09f7-4e42-485e-a2b5-8c664601b203.png
position: 5
---

**Builder Pattern**, hay còn gọi là **Mẫu Thiết Kế Builder**, là một trong các mẫu thiết kế tạo dựng (Creation Pattern). Builder Pattern được tạo ra để giải quyết một số nhược điểm của **Factory Pattern** và **Abstract Factory Pattern** khi làm việc với các đối tượng có nhiều thuộc tính.

## Builder Pattern là gì

**Builder Pattern** được sử dụng để giải quyết các vấn đề phát sinh khi tạo đối tượng với nhiều thuộc tính. Có ba vấn đề chính khi làm việc với **Factory Pattern** và **Abstract Factory Pattern** khi đối tượng có nhiều thuộc tính:

1. **Quá nhiều tham số cần truyền vào từ client đến Factory Class**: Khi một đối tượng có nhiều thuộc tính, việc truyền đủ số lượng tham số vào hàm tạo (constructor) từ phía client trở nên khó khăn.

2. **Một số tham số có thể là tùy chọn**: Trong trường hợp một số thuộc tính là tùy chọn, trong **Factory Pattern**, chúng ta vẫn phải truyền tất cả tham số, và các tham số tùy chọn thường được thiết lập là `null` hoặc giá trị mặc định.

3. **Việc tạo đối tượng phức tạp**: Khi đối tượng có nhiều thuộc tính, việc tạo nó từng bước một trở nên phức tạp và dễ gây lỗi.

**Builder Pattern** giải quyết các vấn đề này bằng cách cung cấp cách xây dựng đối tượng từng phần và cung cấp một phương thức để trả về đối tượng hoàn chỉnh.

Một số ví dụ về việc sử dụng **Builder Pattern** trong JDK (Java Development Kit) bao gồm:

- `java.lang.StringBuilder#append()` (không đồng bộ)
- `java.lang.StringBuffer#append()` (đồng bộ)

## Builder Pattern UML Diagram

![Builder Pattern UML Diagram](https://github.com/techmely/hoc-lap-trinh/assets/29374426/54337bb9-ab4d-4cad-98da-bda397a7f7d9)

**Builder Pattern** sử dụng các lớp sau:

- **Product**: Đối tượng cần được xây dựng (có nhiều thuộc tính).
- **Builder**: Một lớp trừu tượng hoặc interface khai báo phương thức để xây dựng đối tượng.
- **ConcreteBuilder**: Lớp này thừa kế từ Builder và cài đặt cách xây dựng đối tượng.
- **Director**: Lớp này là nơi gọi các phương thức của Builder để xây dựng đối tượng.

Thường, trong các trường hợp đơn giản, Builder và ConcreteBuilder có thể được gom lại thành một lớp tĩnh (nested class) bên trong Product.

## Ví dụ về Builder Pattern

Hãy xem xét một ví dụ đơn giản về cách sử dụng **Builder Pattern** để xây dựng một đối tượng `Computer` với nhiều thuộc tính khác nhau.

### Các Lớp

```java
public class Computer {
    // Thuộc tính bắt buộc
    private String HDD;
    private String RAM;

    // Thuộc tính tùy chọn
    private boolean isGraphicsCardEnabled;
    private boolean isBluetoothEnabled;

    // Các getter (trình xem) cho thuộc tính
    // ...

    // Constructor riêng tư để chỉ được sử dụng bởi lớp Builder
    private Computer(ComputerBuilder builder) {
        this.HDD = builder.HDD;
        this.RAM = builder.RAM;
        this.isGraphicsCardEnabled = builder.isGraphicsCardEnabled;
        this.isBluetoothEnabled = builder.isBluetoothEnabled;
    }

    // Các method khác của Computer
    // ...

    // Builder Class
    public static class ComputerBuilder {
        // Thuộc tính bắt buộc
        private String HDD;
        private String RAM;

        // Thuộc tính tùy chọn, mặc định là false
        private boolean isGraphicsCardEnabled = false;
        private boolean isBluetoothEnabled = false;

        // Constructor của Builder với các thuộc tính bắt buộc
        public ComputerBuilder(String hdd, String ram) {
            this.HDD = hdd;
            this.RAM = ram;
        }

        // Setter cho các thuộc tính tùy chọn
        public ComputerBuilder setGraphicsCardEnabled(boolean isGraphicsCardEnabled) {
            this.isGraphics

CardEnabled = isGraphicsCardEnabled;
            return this;
        }

        public ComputerBuilder setBluetoothEnabled(boolean isBluetoothEnabled) {
            this.isBluetoothEnabled = isBluetoothEnabled;
            return this;
        }

        // Phương thức build để tạo đối tượng Computer cuối cùng
        public Computer build() {
            return new Computer(this);
        }
    }
}
```

### Sử Dụng Builder Pattern

```java
public class DemoBuilderPattern {
    public static void main(String[] args) {
        // Sử dụng Builder để tạo đối tượng Computer một cách dễ dàng và linh hoạt
        Computer comp = new Computer.ComputerBuilder("500 GB", "2 GB")
            .setBluetoothEnabled(true)
            .setGraphicsCardEnabled(true)
            .build();

        System.out.println(comp);
    }
}
```

::result

Computer [HDD=500 GB, RAM=2 GB, isGraphicsCardEnabled=true, isBluetoothEnabled=true]

::

Như bạn có thể thấy, **Builder Pattern** cho phép xây dựng đối tượng `Computer` một cách dễ dàng và linh hoạt. Nếu bạn muốn thêm thuộc tính hoặc thay đổi các thuộc tính tùy chọn, bạn chỉ cần gọi các phương thức setter tương ứng và sau đó gọi phương thức `build()` để có được đối tượng cuối cùng.
