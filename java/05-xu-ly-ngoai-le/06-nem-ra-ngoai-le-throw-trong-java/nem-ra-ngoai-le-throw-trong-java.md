---
title: "Ném ra ngoại lệ throw trong Java"
description: "Từ khóa throw trong Java được sử dụng để ném ra một exception tường minh, chúng ta có thể ném hoặc Checked Exception hoặc Unchecked Exception trong Java bởi từ khóa throw"
chapter:
  name: "Xử lý ngoại lệ"
  slug: "chuong-05-xu-ly-ngoai-le"
image: https://help.sap.com/doc/saphelp_nw75/7.5.5/en-US/0e/cf95afe85a470193719866cabd50db/loioc52db5d8c14148c2adec3d36716dea51_LowRes.png
position: 6
---

Từ khóa `throw` trong Java được sử dụng để ném ra một `exception` tường minh. Chúng ta có thể ném cả `Checked Exception` và `Unchecked Exception` trong Java bằng từ khóa `throw`. Từ khóa `throw` thường được sử dụng để ném các `Custom Exception` (là các exception được định nghĩa bởi lập trình viên).

## Cú Pháp `throw` trong Java

Cú pháp `throw` trong Java như sau:

```java
throw exception;
```

Ví dụ về việc sử dụng `throw` để ném ra một `IOException`:

```java
throw new IOException("File không tồn tại");
```

## Ví Dụ về Từ Khóa `throw` trong Java

### Ví Dụ 1: Ném Ra Ngoại Lệ và Không Xử Lý

Trong ví dụ này, chúng ta tạo một phương thức `validate()` nhận một tham số là giá trị tuổi. Nếu tuổi dưới 18, chúng ta ném ra một ngoại lệ `ArithmeticException`, nếu không, chúng ta in ra một thông báo "welcome".

```java
public class TestThrow1 {
    static void validate(int age) {
        if (age < 18)
            throw new ArithmeticException("not valid");
        else
            System.out.println("welcome");
    }

    public static void main(String args[]) {
        validate(13);
        System.out.println("rest of the code...");
    }
}
```

::result

Exception in thread "main" java.lang.ArithmeticException: not valid

::

### Ví Dụ 2 Ném Ra Ngoại Lệ và Xử Lý

Trong ví dụ này, chúng ta sử dụng `throw` để ném ra một `ArithmeticException`, nhưng chúng ta cũng có một khối `catch` để xử lý ngoại lệ này.

```java
public class TestThrow2 {
    static void validate(int age) {
        try {
            if (age < 18)
                throw new ArithmeticException("not valid");
            else
                System.out.println("welcome");
        } catch (ArithmeticException ex) {
            System.out.println(ex.getMessage());
        }
    }

    public static void main(String args[]) {
        validate(13);
        System.out.println("rest of the code...");
    }
}
```

::result

not valid
rest of the code...

::

Trong cả hai ví dụ trên, chúng ta đã sử dụng từ khóa `throw` để tạo ra một ngoại lệ và quyết định cách xử lý nó. Việc sử dụng `throw` cho phép chúng ta tạo ra và quản lý các tình huống ngoại lệ một cách tường minh trong chương trình Java của mình.
