---
title: "Khối finally trong Java"
description: "Khi một ngoại lệ xuất hiện, phương thức đang được thực thi có thể bị dừng mà không được hoàn thành. Nếu điều này xảy ra, thì các đoạn mã phía sau (ví dụ như đoạn mã có chức năng thu hồi tài nguyên, như các lệnh đóng tập viết ở cuối phương thức) sẽ không bao giờ được gọi. Java cung cấp khối finally để giải quyết việc này"
chapter:
  name: "Xử lý ngoại lệ"
  slug: "chuong-05-xu-ly-ngoai-le"
category:
  name: "Java"
  slug: "java"
image: https://user-images.githubusercontent.com/29374426/126114810-e1c61816-0531-42a8-b493-7232c4d2fcbc.png
position: 4
---

Khi một ngoại lệ xuất hiện, phương thức đang được thực thi có thể bị dừng mà không được hoàn thành. Nếu điều này xảy ra, thì các đoạn mã phía sau (ví dụ như đoạn mã có chức năng thu hồi tài nguyên, như các lệnh đóng tập viết ở cuối phương thức) sẽ không bao giờ được gọi. Java cung cấp khối finally để giải quyết việc này. Thông thường khối `finally` chứa các câu lệnh mang tính chất dọn dẹp như: đóng kết nối CSDL, đóng tệp tin,…

Khối lệnh finally trong java luôn được thực thi cho dù có ngoại lệ xảy ra hay không hoặc gặp lệnh `return` trong khối `try`.

## Cấu trúc khối `finally` trong Java

```java
try{
  //Các lệnh có khả năng ném ra ngoại lệ
} catch(Exception1 ex1){
…
} catch(Exception2 ex2){
…
} catch(Exception exn){
…
} finally{
//Mã lệnh dọn dẹp
}
```

Khối `finally` là tuỳ chọn, không bắt buộc phải có. Khối này được đặt sau khối `catch` cuối cùng. Chương trình sẽ thực thi câu lệnh đầu tiên của khối `finally` ngay sau khi gặp câu lệnh `return` hay lệnh `break` trong khối `try`.

Khối `finally` bảo đảm lúc nào cũng được thực thi, bất chấp có ngoại lệ xảy ra hay không. Hình minh họa sự thực hiện của các khối `try`, `catch` và `finally`

![Cấu trúc khối finally trong Java](https://user-images.githubusercontent.com/29374426/126114810-e1c61816-0531-42a8-b493-7232c4d2fcbc.png)

## Ví dụ finally trong Java

Ví dụ sử dụng khối lệnh finally nơi ngoại lệ không xảy ra.

```java
public class TestFinallyBlock {
    public static void main(String args[]) {
        try {
            int data = 25 / 5;
            System.out.println(data);
        } catch (NullPointerException e) {
            System.out.println(e);
        } finally {
            System.out.println("finally block is always executed");
        }
        System.out.println("rest of the code...");
    }
}
```

::result

5<br/>
finally block is always executed<br/>
rest of the code...

::

Ví dụ sử dụng khối lệnh `finally` nơi ngoại lệ xảy ra nhưng không xử lý.

```java
public class TestFinallyBlock1 {
    public static void main(String args[]) {
        try {
            int data = 25 / 0;
            System.out.println(data);
        } catch (NullPointerException e) {
            System.out.println(e);
        } finally {
            System.out.println("finally block is always executed");
        }
        System.out.println("rest of the code...");
    }
}
```

::result
finally block is always executed<br/>
Exception in thread "main" java.lang.ArithmeticException: / by zero
::

Ví dụ sử dụng khối lệnh finally nơi ngoại lệ xảy ra và được xử lý.

```java
public class TestFinallyBlock2 {
    public static void main(String args[]) {
        try {
            int data = 25 / 0;
            System.out.println(data);
        } catch (ArithmeticException e) {
            System.out.println(e);
        } finally {
            System.out.println("finally block is always executed");
        }
        System.out.println("rest of the code...");
    }
}
```

::result

java.lang.ArithmeticException: / by zero<br/>
finally block is always executed<br/>
rest of the code...

::

Ví dụ sử dụng khối lệnh finally trong trường hợp trong khối try có lệnh return.

```java
public class TestFinallyBlock3 {
    public static void main(String args[]) {
        try {
            int data = 25;
            if (data % 2 != 0) {
             System.out.println(data + " is odd number");
             return;
            }
        } catch (ArithmeticException e) {
            System.out.println(e);
        } finally {
            System.out.println("finally block is always executed");
        }
        System.out.println("rest of the code...");
    }
}
```

::result
25 is odd number<br/>
finally block is always executed
::
