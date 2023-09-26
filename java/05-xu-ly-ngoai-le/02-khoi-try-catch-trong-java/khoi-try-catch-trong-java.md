---
title: "Khối try-catch trong Java"
description: "Khối try-catch trong Java được sử dụng để xử lý các ngoại lệ (exceptions) trong chương trình. Khi một ngoại lệ xảy ra trong khối try, nó sẽ được bắt bởi khối catch tương ứng, giúp chương trình không bị dừng đột ngột."
chapter:
  name: "Xử lý ngoại lệ"
  slug: "chuong-05-xu-ly-ngoai-le"
image: https://help.sap.com/doc/saphelp_nw75/7.5.5/en-US/0e/cf95afe85a470193719866cabd50db/loioc52db5d8c14148c2adec3d36716dea51_LowRes.png
position: 2
---

Khối `try-catch` trong Java được sử dụng để xử lý các ngoại lệ (exceptions) trong chương trình. Khi một ngoại lệ xảy ra trong khối try, nó sẽ được bắt bởi khối catch tương ứng, giúp chương trình không bị dừng đột ngột. Trong bài viết này, chúng ta sẽ tìm hiểu về cách sử dụng khối try-catch trong Java, cùng với ví dụ minh họa.

## Khi nào cần sử dụng try-catch trong Java

Khối `try-catch` trong Java nên được sử dụng khi có khả năng xảy ra các ngoại lệ trong chương trình. Các trường hợp phù hợp để sử dụng `try-catch` bao gồm:

1. **Lỗi logic**: Khi bạn không thể kiểm soát toàn bộ dữ liệu đầu vào và có thể xảy ra lỗi logic, bạn nên sử dụng try-catch để bắt và xử lý ngoại lệ một cách kiểm soát.
2. **Chia cho 0**: Khi có phép chia cho 0, Java sẽ ném ra một ngoại lệ `ArithmeticException`. Bằng cách sử dụng try-catch, bạn có thể xử lý trường hợp này mà không làm dừng chương trình.
3. **Kết nối cơ sở dữ liệu**: Trong quá trình làm việc với cơ sở dữ liệu, có thể xảy ra các lỗi kết nối. Try-catch giúp bạn xử lý các trường hợp này một cách an toàn.

## Cú pháp của try-catch trong Java

Cú pháp cơ bản của try-catch trong Java như sau:

```java
try {
    // Mã lệnh có thể gây ra ngoại lệ
} catch (Exception_Type e) {
    // Xử lý ngoại lệ ở đây
}
```

- **try**: Khối mã lệnh mà bạn muốn kiểm tra ngoại lệ.

- **catch**: Khối mã lệnh sẽ được thực thi nếu ngoại lệ xảy ra. Exception_Type là kiểu ngoại lệ mà bạn muốn bắt.

## Ví dụ minh họa sử dụng try-catch trong Java

Dưới đây là một số ví dụ minh họa về việc sử dụng try-catch trong Java:

### Ví dụ 1: Xử lý chia cho 0

```java
public class Example1 {
    public static void main(String[] args) {
        try {
            int result = 50 / 0; // Sẽ ném ra ArithmeticException
        } catch (ArithmeticException e) {
            System.out.println("Lỗi chia cho 0: " + e.getMessage());
        }
        System.out.println("Chương trình tiếp tục chạy...");
    }
}
```

::result

Lỗi chia cho 0: / by zero
Chương trình tiếp tục chạy...

::

### Ví dụ 2: Xử lý nhập sai định dạng số

```java
import java.util.Scanner;

public class Example2 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        try {
            System.out.print("Nhập một số nguyên: ");
            int number = Integer.parseInt(scanner.next()); // Có thể ném ra NumberFormatException
            System.out.println("Số bạn vừa nhập: " + number);
        } catch (NumberFormatException e) {
            System.out.println("Sai định dạng số: " + e.getMessage());
        }
        scanner.close();
    }
}
```

Trong ví dụ này, nếu người dùng nhập một chuỗi không phải là số nguyên, chương trình sẽ xử lý ngoại lệ `NumberFormatException`.

::result

Nhập một số nguyên: abc
Sai định dạng số: For input string: "abc"

::

### Ví dụ 3: Xử lý ngoại lệ tự định nghĩa

```java
public class Example3 {
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

Trong ví dụ này, chúng ta tự định nghĩa một ngoại lệ `IllegalArgumentException` và ném nó ra khi tuổi là một giá trị âm.

::result

Lỗi: Tuổi không được âm!

::

::alert{type="success"}
Khối try-catch trong Java là một công cụ mạnh mẽ để xử lý ngoại lệ và giúp chương trình không bị dừng đột ngột khi có lỗi. Bằng cách sử dụng try-catch, bạn có thể kiểm soát và xử lý các trường hợp không mong muốn trong chương trình của mình, làm cho ứng dụng trở nên ổn định và an toàn hơn.
::
