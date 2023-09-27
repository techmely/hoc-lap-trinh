---
title: "Đa khối lệnh catch trong Java"
description: "Nếu bạn phải thực hiện các tác vụ khác nhau mà ở đó có thể xảy ra các ngoại lệ khác nhau, hãy sử dụng đa khối lệnh catch trong java, bài này chúng ta cùng nhau tìm hiểu về đa khối lệnh catch trong java"
chapter:
  name: "Xử lý ngoại lệ"
  slug: "chuong-05-xu-ly-ngoai-le"
image: https://help.sap.com/doc/saphelp_nw75/7.5.5/en-US/0e/cf95afe85a470193719866cabd50db/loioc52db5d8c14148c2adec3d36716dea51_LowRes.png
position: 3
---

Trong Java, khi bạn cần thực hiện các tác vụ khác nhau mà ở đó có thể xảy ra các ngoại lệ khác nhau, bạn có thể sử dụng đa khối lệnh `catch`. Điều này cho phép bạn xử lý từng loại ngoại lệ một, giúp tăng tính linh hoạt và kiểm soát trong việc xử lý ngoại lệ.

## Cú Pháp của Đa Khối Lệnh Catch

Cú pháp cơ bản của đa khối lệnh `catch` trong Java như sau:

```java
try {
   // Mã lệnh bảo vệ
} catch (ExceptionType1 e1) {
   // Xử lý ngoại lệ kiểu 1
} catch (ExceptionType2 e2) {
   // Xử lý ngoại lệ kiểu 2
} catch (ExceptionType3 e3) {
   // Xử lý ngoại lệ kiểu 3
}
```

Khi sử dụng đa khối lệnh `catch`, các khối `catch` sẽ được kiểm tra tuần tự. Khối `catch` đầu tiên mà phù hợp với ngoại lệ được ném ra sẽ được thực thi, và các khối `catch` sau đó sẽ bị bỏ qua.

## Ví dụ Sử Dụng Đa Khối Lệnh Catch trong Java

Dưới đây là một ví dụ minh họa:

```java
public class TestMultipleCatchBlock {

    public static void main(String args[]) {
        try {
            int a[] = new int[5];
            a[5] = 30 / 0; // Sẽ ném ra ArithmeticException
        } catch (ArithmeticException e) {
            System.out.println("task1 is completed");
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("task2 is completed");
        } catch (Exception e) {
            System.out.println("common task completed");
        }

        System.out.println("rest of the code...");
    }
}
```

::result

task1 is completed
rest of the code...

::

Trong ví dụ trên, khi chúng ta chia một số cho 0, ngoại lệ `ArithmeticException` được ném ra và khối `catch` thứ nhất phù hợp với ngoại lệ này, vì vậy "task1 is completed" được in ra. Các khối `catch` sau đó không được thực thi.

Tuy nhiên, khi sử dụng đa khối lệnh `catch`, bạn cần lưu ý rằng các khối `catch` phải được sắp xếp từ loại ngoại lệ cụ thể đến loại ngoại lệ chung. Nếu bạn đặt khối `catch` cho `Exception` ở đầu, các khối `catch` cụ thể sẽ không bao giờ được thực thi, như ví dụ sau:

```java
public class TestMultipleCatchBlock1 {

    public static void main(String args[]) {
        try {
            int a[] = new int[5];
            a[5] = 30 / 0; // Sẽ ném ra ArithmeticException
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

::result

Compile-time error

::

Chương trình trên bị lỗi tại compile-time vì các khối lệnh `catch (ArithmeticException e)` và `catch (ArrayIndexOutOfBoundsException e)` sẽ không bao giờ được thực thi khi đã có một khối `catch (Exception e)` bắt tất cả các ngoại lệ.
