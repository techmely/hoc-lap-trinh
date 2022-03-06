---
title: "Đa khối lệnh catch trong Java"
description: "Nếu bạn phải thực hiện các tác vụ khác nhau mà ở đó có thể xảy ra các ngoại lệ khác nhau, hãy sử dụng đa khối lệnh catch trong java, bài này chúng ta cùng nhau tìm hiểu về đa khối lệnh catch trong java"
keywords:
  [
    "cách dùng try catch trong java",
    "cách sử dụng try catch trong java",
    "cấu trúc try catch trong java",
    "hàm try catch trong java",
    "lệnh try catch trong java",
    "sử dụng try catch trong java",
    "try catch trong java",
    "đa khối lệnh try catch trong java 8",
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
position: 3
---

Nếu bạn phải thực hiện các tác vụ khác nhau mà ở đó có thể xảy ra các ngoại lệ khác nhau, hãy sử dụng đa khối lệnh `catch` trong java. Khi sử dụng các `try` lồng nhau, khối `try` bên trong được thi hành đầu tiên. Bất kỳ ngoại lệ nào bị chặn trong khối `try` sẽ bị bắt giữ trong các khối catch theo sau. Nếu khối `catch` thích hợp không được tìm thấy thì các khối `catch` của các khối `try` bên ngoài sẽ được xem xét. Nếu không, Java Runtime Environment xử lý các ngoại lệ.

Cú pháp:

```java
try {
   // Protected code
} catch (ExceptionType1 e1) {
   // Catch block
} catch (ExceptionType2 e2) {
   // Catch block
} catch (ExceptionType3 e3) {
   // Catch block
}
```

<div class="example"></div>

```java
public class TestMultipleCatchBlock {

    public static void main(String args[]) {
        try {
            int a[] = new int[5];
            a[5] = 30 / 0;
        } catch (ArithmeticException e) {
            System.out.println("task1 is completed");
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("task 2 completed");
        } catch (Exception e) {
            System.out.println("common task completed");
        }

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
    <code>task1 is completed</code><br/>
    <code>rest of the code...</code>
  </div>
</div>

<div class="example"></div>

```java
public class TestMultipleCatchBlock1 {

    public static void main(String args[]) {
        try {
            int a[] = new int[5];
            a[5] = 30 / 0;
        } catch (Exception e) {
            System.out.println("common task completed");
        } catch (ArithmeticException e) {
            System.out.println("task1 is completed");
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("task2 is completed");
        }
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
    <code>Compile-time error</code>
  </div>
</div>

Chương trình trên bị lỗi tại compile-time là vì khi có ngoại lệ xảy ra thì các khối lệnh catch (ArithmeticException e) và catch (ArrayIndexOutOfBoundsException e) không bao giờ được thực thi, do khối catch (Exception e) đã bắt tất cả các ngoại lệ rồi.
