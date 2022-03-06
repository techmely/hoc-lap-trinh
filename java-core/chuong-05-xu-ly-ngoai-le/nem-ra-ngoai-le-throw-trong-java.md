---
title: "Ném ra ngoại lệ throw trong Java"
description: "Từ khóa throw trong Java được sử dụng để ném ra một exception tường minh, chúng ta có thể ném hoặc Checked Exception hoặc Unchecked Exception trong Java bởi từ khóa throw"
keywords:
  [
    "cách sử dụng try catch trong java",
    "cấu trúc try catch trong java",
    "lệnh try catch trong java",
    "try catch throw trong java",
    "try catch trong java",
  ]
author:
  fullname: Techmely Team
  username: Techmely Team
  avatar: "/configs/author/logo.jpg"
chapter:
  name: "Xử lý ngoại lệ"
  slug: "chuong-05-xu-ly-ngoai-le"
category:
  logo: "/language/java.png"
  name: "Java"
  slug: "java"
  description: "Học Java từ cơ bản đến thông thạo cho mọi đối tượng"
image: https://help.sap.com/doc/saphelp_nw75/7.5.5/en-US/0e/cf95afe85a470193719866cabd50db/loioc52db5d8c14148c2adec3d36716dea51_LowRes.png
position: 6
---

Từ khóa `throw` trong Java được sử dụng để ném ra một `exception` tường minh. Chúng ta có thể ném hoặc `Checked Exception` hoặc `Unchecked Exception` trong Java bởi từ khóa `throw`. Từ khóa `throw` được sử dụng chủ yếu để ném các `Custom Exceptio`n (là các exception được định nghĩa bởi lập trình viên).

Cú pháp từ khóa throw:

```java
throw exception;
```

Ví dụ về throw `IOException`.

```java

throw new IOException("File không tồn tại");
```

## Ví dụ về từ khóa throw trong java

<div class="example">throw ra ngoại lệ nhưng không xử lý: Trong ví dụ này, chúng ta tạo ra phương thức validate() với tham số truyền vào là giá trị integer. Nếu tuổi dưới 18, chúng ta ném ra ngoại lệ ArithmeticException nếu không in ra một thông báo "welcome".</div>

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

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>Exception in thread "main" java.lang.ArithmeticException: not valid</code><br/>
  </div>
</div>

<div class="example">throw ra ngoại lệ nhưng có xử lý</div>

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

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>not valid</code><br/>
    <code>rest of the code...</code>
  </div>
</div>
