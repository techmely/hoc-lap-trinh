---
title: "Ném ra ngoại lệ throw trong Java"
description: "Từ khóa throw trong Java được sử dụng để ném ra một exception tường minh, chúng ta có thể ném hoặc Checked Exception hoặc Unchecked Exception trong Java bởi từ khóa throw"
chapter:
  name: "Xử lý ngoại lệ"
  slug: "chuong-05-xu-ly-ngoai-le"
category:
  name: "Java"
  slug: "java"
image: https://help.sap.com/doc/saphelp_nw75/7.5.5/en-US/0e/cf95afe85a470193719866cabd50db/loioc52db5d8c14148c2adec3d36716dea51_LowRes.png
position: 6
---

Từ khóa `throw` trong Java được sử dụng để ném ra một `exception` tường minh. Chúng ta có thể ném hoặc `Checked Exception` hoặc `Unchecked Exception` trong Java bởi từ khóa `throw`. Từ khóa `throw` được sử dụng chủ yếu để ném các `Custom Exception` (là các exception được định nghĩa bởi lập trình viên).

Cú pháp từ khóa throw:

```java
throw exception;
```

Ví dụ về throw `IOException`.

```java

throw new IOException("File không tồn tại");
```

## Ví dụ về từ khóa throw trong java

Ví dụ `throw` ra ngoại lệ nhưng không xử lý: Trong ví dụ này, chúng ta tạo ra phương thức `validate()` với tham số truyền vào là giá trị integer. Nếu tuổi dưới 18, chúng ta ném ra ngoại lệ `ArithmeticException` nếu không in ra một thông báo "welcome".</div>

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

Exception in thread "main" java.lang.ArithmeticException: not valid<br/>

::

Ví dụ `throw` ra ngoại lệ nhưng có xử lý

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

not valid<br/>
rest of the code...

::
