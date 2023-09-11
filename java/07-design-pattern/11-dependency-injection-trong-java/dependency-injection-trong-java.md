---
title: "Dependency Injection trong Java"
description: "Dependency Injection (DI) là một kỹ thuật hoặc một design pattern trong lập trình, giúp quản lý các phụ thuộc (dependencies) trong một ứng dụng một cách linh hoạt và dễ quản lý. "
chapter:
  name: "Design Pattern"
  slug: "chuong-07-design-pattern"
category:
  name: "Java"
  slug: "java"
image: https://user-images.githubusercontent.com/29374426/146175674-fa7e09f7-4e42-485e-a2b5-8c664601b203.png
position: 11
---

**Bridge Pattern** là một mẫu cấu trúc (Structural Pattern) trong lập trình Java.

## Bridge Pattern là gì

**Bridge Pattern** được sử dụng khi bạn muốn tách biệt sự phân cấp trong một thành phần giao diện (interface) và sự phân cấp trong việc thực hiện nó. Nó giúp bạn loại bỏ sự phụ thuộc giữa các lớp giao diện và các lớp cụ thể.

## Bridge Pattern UML Diagram

Dưới đây là sơ đồ UML của **Bridge Pattern**:

```scss
+---------------------+         +------------------+
|      Abstraction    |         |   Implementor   |
+---------------------+         +------------------+
| + operation()       |         | + implement()   |
|                     |         |                  |
|                     |         |                  |
|    +---------------+|         |    +-----------+ |
|    |               ||         |    |           | |
|    |               ||         |    |           | |
|    |               ||         |    |           | |
+----|------------   ||         +----|-----------| |
     |               ||              |           | |
     +---------------+|              +-----------+ |
                      |                            |
                      +----------------------------+
                           AbstractionRefined
```

- **Abstraction**: Đây là một lớp trừu tượng chứa một đối tượng của **Implementor** và định nghĩa các phương thức giao diện (interface) mà các lớp con của nó phải triển khai. **Abstraction** cung cấp một cách tiếp cận thông qua các phương thức của nó để giao tiếp với **Implementor**.
- **Implementor**: Đây là một giao diện (interface) hoặc lớp trừu tượng mà các lớp cụ thể triển khai. Nó định nghĩa các phương thức mà **Abstraction** sử dụng để thực hiện các hoạt động cụ thể.
- **AbstractionRefined**: Đây là các lớp con của **Abstraction** và được sử dụng để triển khai các chi tiết cụ thể của phương thức được định nghĩa trong **Abstraction**.

## Ví dụ về Bridge Pattern

Giả sử bạn cần xử lý việc ghi log của tin nhắn, và bạn muốn có khả năng lựa chọn giữa việc ghi log ra màn hình hoặc ghi log vào tệp tin, đồng thời bạn cũng muốn lựa chọn giữa việc log dưới dạng văn bản thô hoặc văn bản đã mã hóa.

### Các Lớp

```java
public interface MessageLogger {
  public void log(String msg);
}

public class ConsoleLogger implements MessageLogger {
  @Override
  public void log(String msg) {
    System.out.println(msg);
  }
}

public class FileLogger implements MessageLogger {
  @Override
  public void log(String msg) {
    // Ghi tin nhắn ra file log.txt
    // ...
  }
}

public abstract class Message {
  MessageLogger messageLogger;

  public Message() {}

  public Message(MessageLogger messageLogger) {
    this.messageLogger = messageLogger;
  }

  public abstract void log(String msg);
}

public class TextMessage extends Message {
  public TextMessage() {}

  public TextMessage(MessageLogger messageLogger) {
    super(messageLogger);
  }

  @Override
  public void log(String msg) {
    this.messageLogger.log(msg);
  }
}

public class EncryptedMessage extends Message {
  public EncryptedMessage() {}

  public EncryptedMessage(MessageLogger messageLogger) {
    super(messageLogger);
  }

  @Override
  public void log(String msg) {
    // Mã hóa tin nhắn và sau đó ghi log
    // ...
  }
}
```

### Sử dụng Bridge Pattern

```java
public class MainApp {
  public static void main(String[] args) {
    // Chọn log kiểu hiển thị ra màn hình
    MessageLogger messageLogger = new ConsoleLogger();

    // Chọn cách thức hiển thị kiểu mã hóa
    Message message1 = new EncryptedMessage(messageLogger);

    // Chọn cách thức hiển thị kiểu văn bản thô
    Message message2 = new TextMessage(messageLogger);

    // Thực thi phương thức log
    message1.log("stackjava.com");
    message2.log("stackjava.com");
  }
}
```

**Bridge Pattern** cho phép bạn tách biệt việc ghi log (loggers) và kiểu log (plaintext hoặc encrypted) một cách linh hoạt mà không phải thay đổi mã nguồn của các lớp tin nhắn (Messages) hay các lớp ghi log (Loggers).
