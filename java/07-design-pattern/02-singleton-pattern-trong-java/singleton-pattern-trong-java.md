---
title: "Singleton Pattern trong Java"
description: "Singleton Pattern là một mẫu thiết kế tạo dựng (Creation Pattern) quan trọng trong lập trình phần mềm. Nó được sử dụng để đảm bảo rằng chỉ có một thể hiện duy nhất của một lớp (class) tồn tại trong môi trường chạy của Java, đảm bảo tính duy nhất và toàn vẹn của đối tượng."
chapter:
  name: "Design Pattern"
  slug: "chuong-07-design-pattern"
image: https://user-images.githubusercontent.com/29374426/146175674-fa7e09f7-4e42-485e-a2b5-8c664601b203.png
position: 2
---

**Singleton Pattern** là một **mẫu thiết kế tạo dựng (Creation Pattern)** quan trọng trong lập trình phần mềm. Nó được sử dụng để đảm bảo rằng chỉ có một thể hiện duy nhất của một lớp (class) tồn tại trong môi trường chạy của Java, đảm bảo tính duy nhất và toàn vẹn của đối tượng.

## Singleton Pattern là gì?

**Singleton Pattern** được áp dụng khi bạn muốn đảm bảo rằng một lớp sẽ chỉ có một thể hiện duy nhất và cung cấp một điểm truy cập global để lấy ra được thể hiện đó. Điều này hữu ích trong nhiều tình huống, bao gồm:

- **Logging**: Để đảm bảo việc ghi log chỉ diễn ra một cách đồng bộ và duy nhất.
- **Các đối tượng kết nối cơ sở dữ liệu (Database connection pool)**: Để tiết kiệm tài nguyên và quản lý kết nối một cách hiệu quả.
- **Caching**: Để lưu trữ dữ liệu tạm thời và chia sẻ chúng giữa nhiều phần của ứng dụng.
- **Thread Pools**: Để quản lý pool các luồng (threads) và chia sẻ chúng giữa các nhiệm vụ.

Các class trong **Java core** như `java.lang.Runtime` và `java.awt.Desktop` đều là ví dụ điển hình của **Singleton Pattern**, bởi vì chúng đảm bảo rằng luôn chỉ có một thể hiện của chúng tồn tại.

## Singleton Pattern UML Diagram

Một Singleton Pattern thường là 1 class (Class Singleton) có các đặc điểm:

- Hàm khởi tạo private để ngăn cản việc tạo thể hiện của class từ các class khác
- Biến private static của class, nó là thể hiện duy nhất của class.
- Method public static để trả về thể hiện của class.

![Singleton Pattern UML Diagram](https://github.com/techmely/hoc-lap-trinh/assets/29374426/b9223257-a50f-48fd-b8b5-a76f4a025635)

## Cách Tạo Một Singleton Pattern

Có nhiều cách để tạo một **Singleton Pattern** trong Java, nhưng dưới đây là một số cách phổ biến:

### Cách 1: Eager Initialization

Trong cách này, thể hiện **Singleton** được tạo ngay lúc class được tải. Điều này đơn giản nhất nhưng có nhược điểm là thể hiện được tạo ngay cả khi nó không cần thiết và không thể bắt được ngoại lệ trong quá trình khởi tạo.

```java
public class EagerInitializedSingleton {
    private static final EagerInitializedSingleton instance = new EagerInitializedSingleton();

    private EagerInitializedSingleton() {}

    public static EagerInitializedSingleton getInstance() {
        return instance;
    }
}
```

### Cách 2: Static Block Initialization

Cách này cũng khởi tạo thể hiện bằng cách sử dụng **static block**, nhưng nó có khả năng bắt ngoại lệ trong quá trình khởi tạo thể hiện đầu tiên.

```java
public class StaticBlockSingleton {
    private static StaticBlockSingleton instance;

    private StaticBlockSingleton() {}

    static {
        try {
            instance = new StaticBlockSingleton();
        } catch (Exception e) {
            throw new RuntimeException("Exception occurred in creating singleton instance");
        }
    }

    public static StaticBlockSingleton getInstance() {
        return instance;
    }
}
```

### Cách 3: Lazy Initialization

Cách này tạo thể hiện của **Singleton** trong method truy cập (lazy initialization). Tuy nhiên, nó không hoạt động chính xác trong trường hợp có nhiều thread, có thể dẫn đến việc tạo nhiều thể hiện khác nhau.

```java
public class LazyInitializedSingleton {
    private static LazyInitializedSingleton instance;

    private LazyInitializedSingleton() {}

    public static LazyInitializedSingleton getInstance() {
        if (instance == null) {
            instance = new LazyInitializedSingleton();
        }
        return instance;
    }
}
```

### Cách 4: Thread Safe Singleton

Cách này tương tự như cách thứ 3, nhưng method `getInstance()` được đánh dấu là `synchronized`, đảm bảo rằng chỉ có duy nhất một thread được phép gọi nó vào một thời điểm.

```java
public class ThreadSafeSingleton {
    private static ThreadSafeSingleton instance;

    private ThreadSafeSingleton() {}

    public static synchronized ThreadSafeSingleton getInstance() {
        if (instance == null) {
            instance = new ThreadSafeSingleton();
        }
        return instance;
    }
}
```

### Cách 5: Bill Pugh Singleton Implementation

Cách này tạo thể hiện của **Singleton** bằng cách sử dụng **static inner class**. Khi lớp **Singleton** được tải, lớp **SingletonHelper** vẫn không được tải vào bộ nhớ cho đến khi method `getInstance()` được gọi. Cách này cũng không yêu cầu đồng bộ hóa.

```java
public class BillPughSingleton {
    private BillPughSingleton() {}

    private static class SingletonHelper {
        private static final BillPughSingleton INSTANCE = new BillPughSingleton();
    }

    public static BillPughSingleton getInstance() {
        return SingletonHelper.INSTANCE;
    }
}
```

### Cách 6: Sử Dụng Enum

```java
public enum EnumSingleton {
    INSTANCE;

    public static void doSomething() {
        // Thực hiện một số công việc
    }
}
```

**Singleton Pattern** là một trong những **mẫu thiết kế (Design Pattern)** quan trọng nhất trong lập trình phần mềm. Điều này giúp đảm bảo tính duy nhất và toàn vẹn của đối tượng trong ứng dụng, giúp bạn quản lý tài nguyên hiệu quả và đảm bảo tính nhất quán trong dự án của bạn.
