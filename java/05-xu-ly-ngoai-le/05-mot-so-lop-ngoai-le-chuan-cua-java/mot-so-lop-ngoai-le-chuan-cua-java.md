---
title: "Một số lớp ngoại lệ chuẩn của Java"
description: "Trong Java, ngoại lệ là một tình huống xảy ra trong quá trình thực thi chương trình, và chúng có thể gây ra sự cố hoặc làm dừng chương trình. Java cung cấp nhiều lớp ngoại lệ chuẩn để xử lý các tình huống khác nhau. "
chapter:
  name: "Xử lý ngoại lệ"
  slug: "chuong-05-xu-ly-ngoai-le"
category:
  name: "Java"
  slug: "java"
image: https://help.sap.com/doc/saphelp_nw75/7.5.5/en-US/0e/cf95afe85a470193719866cabd50db/loioc52db5d8c14148c2adec3d36716dea51_LowRes.png
position: 5
---

Trong Java, ngoại lệ là một tình huống xảy ra trong quá trình thực thi chương trình, và chúng có thể gây ra sự cố hoặc làm dừng chương trình. Java cung cấp nhiều lớp ngoại lệ chuẩn để xử lý các tình huống khác nhau. Trong bài viết này, chúng ta sẽ tìm hiểu về một số lớp ngoại lệ chuẩn trong Java và cách chúng có thể được sử dụng.

Dưới đây là một số lớp ngoại lệ chuẩn quan trọng trong Java:

## 1. `Throwable`

- **Ý nghĩa**: Đây là lớp cha của mọi lớp ngoại lệ trong Java.

## 2. `Exception`

- **Ý nghĩa**: Là lớp con trực tiếp của lớp `Throwable`, mô tả một ngoại lệ tổng quát có thể xảy ra trong ứng dụng.

## 3. `RuntimeException`

- **Ý nghĩa**: Lớp cơ sở cho nhiều ngoại lệ trong `java.lang`.

## 4. `ArithmeticException`

- **Ý nghĩa**: Xảy ra khi có lỗi về số học, ví dụ như chia cho 0.

**Ví dụ sử dụng `ArithmeticException`:**

```java
public class ExampleArithmeticException {
    public static void main(String[] args) {
        try {
            int result = 50 / 0; // Xảy ra ArithmeticException
        } catch (ArithmeticException e) {
            System.out.println("Lỗi chia cho 0: " + e.getMessage());
        }
    }
}
```

::result

Lỗi chia cho 0: / by zero

::

## 5. `IllegalAccessException`

- **Ý nghĩa**: Xảy ra khi không thể truy cập một lớp.

## 6. `IllegalArgumentException`

- **Ý nghĩa**: Xảy ra khi đối số không hợp lệ.

**Ví dụ sử dụng `IllegalArgumentException`:**

```java
public class ExampleIllegalArgumentException {
    public static void main(String[] args) {
        try {
            int age = -5;
            if (age < 0) {
                throw new IllegalArgumentException("Tuổi không được âm!");
            }
            System.out.println("Tuổi của bạn: " + age);
        } catch (IllegalArgumentException e) {
            System.out.println("Lỗi: " + e.getMessage());
        }
    }
}
```

::result

Lỗi: Tuổi không được âm!

::

## 7. `ArrayIndexOutOfBoundsException`

- **Ý nghĩa**: Xảy ra khi truy cập ra ngoài mảng.

## 8. `NullPointerException`

- **Ý nghĩa**: Xảy ra khi truy cập một đối tượng null.

## 9. `SecurityException`

- **Ý nghĩa**: Xảy ra khi cơ chế bảo mật không cho phép thực hiện một thao tác.

## 10. `ClassNotFoundException`

- **Ý nghĩa**: Xảy ra khi không thể nạp lớp yêu cầu.

## 11. `NumberFormatException`

- **Ý nghĩa**: Xảy ra khi chuyển đổi từ chuỗi sang số không thành công.

**Ví dụ sử dụng `NumberFormatException`:**

```java
public class ExampleNumberFormatException {
    public static void main(String[] args) {
        try {
            int number = Integer.parseInt("abc"); // Xảy ra NumberFormatException
            System.out.println("Số bạn vừa nhập: " + number);
        } catch (NumberFormatException e) {
            System.out.println("Sai định dạng số: " + e.getMessage());
        }
    }
}
```

::result

Sai định dạng số: For input string: "abc"

::

## 12. `AWTException`

- **Ý nghĩa**: Đây là một lớp ngoại lệ liên quan đến AWT (Abstract Window Toolkit).

## 13. `IOException`

- **Ý nghĩa**: Là lớp cha của các lớp ngoại lệ liên quan đến I/O (Input/Output).

## 14. `FileNotFoundException`

- **Ý nghĩa**: Xảy ra khi không thể định vị tập tin.

## 15. `EOFException`

- **Ý nghĩa**: Xảy ra khi kết thúc một tập tin.

## 16. `NoSuchMethodException`

- **Ý nghĩa**: Xảy ra khi phương thức yêu cầu không tồn tại.

## 17. `InterruptedException`

- **Ý nghĩa**: Xảy ra khi một luồng bị ngắt.

Danh sách này chỉ là một phần nhỏ của các lớp ngoại lệ chuẩn trong Java. Mỗi lớp ngoại lệ phù hợp với một tình huống cụ thể, và việc hiểu và xử lý các ngoại lệ này rất quan trọng để viết các ứng dụng Java ổn định và an toàn.
