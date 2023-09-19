---
title: "Exception handling với overriding method"
description: "Trong Java, khi bạn ghi đè một phương thức của lớp cha trong lớp con, có một số quy tắc liên quan đến xử lý ngoại lệ (exception handling) mà bạn cần phải tuân theo. Trong bài viết này, chúng ta sẽ tìm hiểu về cách xử lý ngoại lệ khi ghi đè phương thức trong Java."
chapter:
  name: "Xử lý ngoại lệ"
  slug: "chuong-05-xu-ly-ngoai-le"
category:
  name: "Java"
  slug: "java"
image: https://miro.medium.com/max/1200/1*jJK-9alfR2vnBbXgkDMmkw.png
position: 8
---

Trong Java, khi bạn ghi đè một phương thức của lớp cha trong lớp con, có một số quy tắc liên quan đến xử lý ngoại lệ (exception handling) mà bạn cần phải tuân theo. Trong bài viết này, chúng ta sẽ tìm hiểu về cách xử lý ngoại lệ khi ghi đè phương thức trong Java.

## Nếu phương thức của lớp cha không khai báo một exception

Nếu phương thức của lớp cha không khai báo một exception (ngoại lệ), thì phương thức ghi đè của lớp con không thể khai báo `Checked Exception` (ngoại lệ kiểm tra) nào cả. Dưới đây là một ví dụ:

```java
import java.io.*;

class Parent {
  void msg() {
    System.out.println("parent");
  }
}

class TestExceptionChild extends Parent {
  void msg() throws IOException { // Compile Time Error: Cannot throw more general exception
    System.out.println("TestExceptionChild");
  }

  public static void main(String args[]) {
    Parent p = new TestExceptionChild();
    p.msg();
  }
}
```

::result

Compile Time Error: Cannot throw more general exception

::

Trong ví dụ này, phương thức `msg()` của lớp cha `Parent` không khai báo exception nào, nhưng phương thức `msg()` của lớp con `TestExceptionChild` cố gắng khai báo `IOException` (một checked exception). Điều này dẫn đến lỗi tại thời điểm biên dịch.

Tuy nhiên, trong trường hợp này, lớp con có thể khai báo `Unchecked Exception`, như `ArithmeticException`.

```java
import java.io.*;

class Parent {
  void msg() {
    System.out.println("parent");
  }
}

class TestExceptionChild1 extends Parent {
  void msg() throws ArithmeticException { // OK to throw Unchecked Exception
    System.out.println("child");
  }

  public static void main(String args[]) {
    Parent p = new TestExceptionChild1();
    p.msg();
  }
}
```

::result

child

::

## Nếu phương thức lớp cha khai báo một exception

Nếu phương thức lớp cha khai báo một exception, thì phương thức ghi đè của lớp con có thể khai báo cùng `exception` đó, `exception` của lớp con, hoặc không khai báo `exception` nào. Nhưng nó không thể khai báo `exception` cha. Dưới đây là một số ví dụ:

### Phương thức ghi đè của lớp con khai báo `exception` cha

```java
import java.io.*;

class Parent {
  void msg() throws ArithmeticException {
    System.out.println("parent");
  }
}

class TestExceptionChild2 extends Parent {
  void msg() throws Exception { // Compile Time Error: Exception is broader than ArithmeticException
    System.out.println("child");
  }

  public static void main(String args[]) {
    Parent p = new TestExceptionChild2();
    try {
      p.msg();
    } catch (Exception e) {}
  }
}
```

::result

Compile Time Error: Exception is broader than ArithmeticException

::

### Phương thức ghi đè của lớp con khai báo `exception` của lớp con

```java
import java.io.*;

class Parent {
  void msg() throws Exception {
    System.out.println("parent");
  }
}

class TestExceptionChild4 extends Parent {
  void msg() throws ArithmeticException {
    System.out.println("child");
  }

  public static void main(String args[]) {
    Parent p = new TestExceptionChild4();
    try {
      p.msg();
    } catch (Exception e) {}
  }
}
```

**Kết quả:**

::result

child

::

### Phương thức ghi đè của lớp con không khai báo `exception` nào

```java
import java.io.*;

class Parent {
  void msg() throws Exception {
    System.out.println("parent");
  }
}

class TestExceptionChild5 extends Parent {
  void msg() {
    System.out.println("child");
  }

  public static void main(String args[]) {
    Parent p = new TestExceptionChild5();
    try {
      p.msg();
    } catch (Exception

 e) {}
  }
}
```

::result

child

::

Trong trường hợp này, phương thức ghi đè của lớp con không khai báo bất kỳ exception nào, và việc sử dụng `try...catch` trong `main` là để bắt và xử lý các exception (nếu có) từ phương thức của lớp cha.
