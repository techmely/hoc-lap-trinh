---
title: "Xử lý ngoại lệ (Exception) trong Java"
description: "Exception là một tình trạng bất thường. Một exception (ngoại lệ) trong Java là một vấn đề xảy ra trong quá trình thực hiện của chương trình mà phá vỡ luồng chuẩn của chương trình."
chapter:
  name: "Xử lý ngoại lệ"
  slug: "chuong-05-xu-ly-ngoai-le"
category:
  name: "Java"
  slug: "java"
image: https://user-images.githubusercontent.com/29374426/142722429-d5b4a38c-448a-4aed-994b-52e06755bfea.png
position: 1
---

`Exception` là một tình trạng bất thường xảy ra trong quá trình thực thi chương trình, phá vỡ luồng chuẩn của chương trình. Trong Java, xử lý ngoại lệ là một khía cạnh quan trọng của lập trình, giúp chúng ta kiểm soát và xử lý các tình huống bất thường.

## Exception trong Java là gì?

Exception trong Java là một vấn đề xảy ra trong quá trình thực hiện của chương trình, phá vỡ luồng chuẩn của chương trình. Mô hình xử lý ngoại lệ của Java dựa trên ba hoạt động chính: đặc tả ngoại lệ, ném ra ngoại lệ và bắt ngoại lệ.

### Loại Exception trong Java

Trong Java, có hai loại chính của Exception:

1. `Checked Exception`: Đây là các ngoại lệ mà chúng ta phải kiểm tra tại thời điểm biên dịch. Checked Exception thường xảy ra do người dùng và không thể dự đoán được bởi lập trình viên. Ví dụ, `IOException`, `SQLException`.
2. `Unchecked Exception`: Đây là các ngoại lệ không cần kiểm tra tại thời điểm biên dịch và thường xảy ra do lỗi trong mã nguồn, chẳng hạn như `NullPointerException`, `ArithmeticException`.
3. `Error`: Là các ngoại lệ không thường được đặt bẫy, và chúng thường xảy ra do lỗi vượt quá tầm kiểm soát của lập trình viên, ví dụ như `OutOfMemoryError`, `StackOverflowError`.

## Xử Lý Ngoại Lệ trong Java

### Cấu trúc try-catch

Để xử lý ngoại lệ trong Java, chúng ta sử dụng cấu trúc try-catch. Trong khối try, chúng ta đặt các đoạn mã có thể gây ra ngoại lệ. Nếu ngoại lệ xảy ra, chúng ta sử dụng khối catch để xử lý ngoại lệ đó.

```java
try {
    // Đoạn mã có thể gây ra ngoại lệ
} catch (ExceptionType e) {
    // Xử lý ngoại lệ
}
```

Ví dụ:

```java
try {
    int result = 10 / 0; // Gây ra ArithmeticException
} catch (ArithmeticException e) {
    System.out.println("Lỗi chia cho 0: " + e.getMessage());
}
```

### Khối `finally`

Khối finally là một phần tử tùy chọn trong cấu trúc try-catch-finally. Khối này chứa các câu lệnh sẽ được thực thi sau cùng, bất kể có xảy ra ngoại lệ hay không.

```java
try {
    // Đoạn mã có thể gây ra ngoại lệ
} catch (ExceptionType e) {
    // Xử lý ngoại lệ
} finally {
    // Mã trong khối finally
}
```

Ví dụ:

```java
try {
    int result = 10 / 2;
} catch (ArithmeticException e) {
    System.out.println("Lỗi chia cho 0: " + e.getMessage());
} finally {
    System.out.println("Khối finally luôn được thực thi.");
}
```

### Sử dụng `throws` và `throw`

Khi bạn viết một phương thức và bạn biết rằng nó có thể gây ra một ngoại lệ nhất định, bạn có thể sử dụng từ khóa `throws` để khai báo ngoại lệ đó. Khi một phương thức được gọi, người gọi phải bắt buộc xử lý ngoại lệ này hoặc cũng sử dụng `throws` để truyền ngoại lệ cho phương thức gọi nó.

```java
void divide(int a, int b) throws ArithmeticException {
    if (b == 0) {
        throw new ArithmeticException("Lỗi chia cho 0");
    }
    int result = a / b;
}
```

Ví dụ:

```java
public class Main {
    public static void main(String[] args) {
        try {
            divide(10, 0);
        } catch (ArithmeticException e) {
            System.out.println("Bắt ngoại lệ: " + e.getMessage());
        }
    }

    static void divide(int a, int b) throws ArithmeticException {
        if (b == 0) {
            throw new ArithmeticException("Lỗi chia cho 0");
        }
        int result = a / b;
        System.out.println("Kết quả: " + result);
    }
}
```

## Hệ thống cấp bậc của các lớp ngoại lệ trong Java

Tất cả các lớp exception đều là lớp con của lớp `java.lang.Exception`. Lớp exception là lớp con của lớp Throwable. Một loại lớp exception khác là `Error` cũng là lớp con của lớp `Throwable`.

![Hệ thống cấp bậc của các lớp ngoại lệ trong Java](https://user-images.githubusercontent.com/29374426/142722321-fc300efc-3618-44d7-8334-0ee0ad988471.png)

`Error` không thường được đặt bẫy bởi các chương trình Java. Error thường được tạo ra để thể hiện lỗi trong môi trường runtime. Ví dụ: JVM hết bộ nhớ. Thông thường các chương trình không thể khôi phục từ các lỗi.

## Các kiểu ngoại lệ phổ biến

| Phương thức                | Miêu tả                                                                                                                            |
| -------------------------- | ---------------------------------------------------------------------------------------------------------------------------------- |
| `IOException`              | Trả về một message cụ thể về `exception` đã xảy ra. Message này được khởi tạo bởi phương thức `constructor` của Throwable          |
| `SQLException`             | Ngoại lệ liên quan đến cú pháp SQL                                                                                                 |
| `DataAccessException`      | Ngoại lệ liên quan đến việc truy cập CSDL                                                                                          |
| `ClassNotFoundException`   | Bị ném khi JVM không thể tìm thấy một lớp mà nó cần, do lỗi dòng lệnh, sự cố đường dẫn hoặc tệp, class bị thiếu...                 |
| `InstantiationException`   | Ngoại lệ khi cố gắng tạo đối tượng của một abstract class hoặc interface                                                           |
| `NullPointerException`     | Ngoại lệ bị ném ra khi cố gắng truy cập một đối tượng có biến tham chiếu có giá trị hiện tại là null                               |
| `ArrayIndexOutOfBound`     | Ngoại lệ khi cố gắng truy cập một phần tử vượt quá độ dài của mảng                                                                 |
| `IllegalArgumentException` | Ngoại lệ bị ném ra khi một phương thức nhận được một đối số được định dạng khác với phương thức mong đợi.                          |
| `IllegalStateException`    | Ngoại lệ bị ném ra khi trạng thái của môi trường không phù hợp với hoạt động cố gắng thực hiện, ví dụ: Sử dụng Scanner đã bị đóng. |
| `NumberFormatException`    | Ngoại lệ bị ném khi một phương thức chuyển đổi một Chuỗi thành số nhưng không thể chuyển đổi.                                      |
| `ArithmeticException`      | Lỗi số học, chẳng hạn như chia cho 0.                                                                                              |

::alert{type="success"}
Xử lý ngoại lệ trong Java là một phần quan trọng của việc phát triển phần mềm. Nó cho phép bạn kiểm soát và xử lý các tình huống bất thường trong chương trình của bạn, giúp đảm bảo tính ổn định và an toàn của ứng dụng. Sử dụng cấu trúc `try-catch`, khối finally, `throws`, và `throw` là những công cụ quan trọng để xử lý ngoại lệ một cách hiệu quả trong Java.
::
