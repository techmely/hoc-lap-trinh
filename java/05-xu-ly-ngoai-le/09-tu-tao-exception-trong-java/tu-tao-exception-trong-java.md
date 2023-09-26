---
title: "Tự tạo exception trong Java"
description: "Tự tạo exception (Custom Exception) là một loại ngoại lệ do bạn tự định nghĩa hoặc tạo riêng cho ứng dụng của mình. Custom Exception trong Java được sử dụng để tùy biến ngoại lệ theo yêu cầu của người dùng. Bằng cách tạo ngoại lệ tùy chỉnh, bạn có thể xác định kiểu ngoại lệ cũng như thông điệp ngoại lệ riêng cho ứng dụng của bạn."
chapter:
  name: "Xử lý ngoại lệ"
  slug: "chuong-05-xu-ly-ngoai-le"
image: http://3.bp.blogspot.com/-q1b3Acf-2P8/VfaC9Ut1ZiI/AAAAAAAAHgk/Ex0j4ze5FSk/s1600/ExceptionClassHierarchy.png
position: 9
---

Tự tạo exception (Custom Exception) là một loại ngoại lệ do bạn tự định nghĩa hoặc tạo riêng cho ứng dụng của mình. Custom Exception trong Java được sử dụng để tùy biến ngoại lệ theo yêu cầu của người dùng. Bằng cách tạo ngoại lệ tùy chỉnh, bạn có thể xác định kiểu ngoại lệ cũng như thông điệp ngoại lệ riêng cho ứng dụng của bạn.

## Tại sao cần sử dụng Custom Exception?

Khi bạn phát triển một ứng dụng Java phức tạp, có thể bạn muốn xử lý các tình huống đặc biệt mà các lớp ngoại lệ có sẵn trong Java không đáp ứng. Trong trường hợp này, việc tạo một ngoại lệ tùy chỉnh sẽ giúp bạn:

1. Định rõ tình huống đặc biệt mà bạn muốn xử lý.
2. Cung cấp thông điệp ngoại lệ riêng để ghi log hoặc hiển thị cho người dùng cuối.
3. Tùy chỉnh cách xử lý ngoại lệ để phù hợp với logic ứng dụng của bạn.

## Ví dụ Tạo Một Custom Exception

Để tạo một Custom Exception trong Java, bạn cần tạo một lớp kế thừa từ lớp `Exception` hoặc các lớp con của nó. Dưới đây là một ví dụ về cách tạo một Custom Exception có tên là `InvalidAgeException`:

```java
// File: InvalidAgeException.java
class InvalidAgeException extends Exception {
    InvalidAgeException(String s) {
        super(s);
    }
}
```

Ở đây, chúng ta đã tạo một lớp `InvalidAgeException` kế thừa từ `Exception`. Lớp này có một constructor để truyền thông điệp ngoại lệ.

## Sử dụng Custom Exception

Bây giờ, chúng ta có thể sử dụng Custom Exception trong ứng dụng của mình. Dưới đây là một ví dụ:

```java
// File: TestCustomException1.java
class TestCustomException1 {

    static void validate(int age) throws InvalidAgeException {
        if (age < 18)
            throw new InvalidAgeException("Tuổi không hợp lệ");
        else
            System.out.println("Chào mừng bạn đã đủ tuổi bầu cử");
    }

    public static void main(String args[]) {
        try {
            validate(13);
        } catch (InvalidAgeException e) {
            System.out.println("Xảy ra ngoại lệ: " + e.getMessage());
        }

        System.out.println("Phần còn lại của mã...");
    }
}
```

Trong ví dụ này, chúng ta đã tạo một phương thức `validate` kiểm tra tuổi và ném ngoại lệ `InvalidAgeException` nếu tuổi không hợp lệ. Trong `main` method, chúng ta đã bắt ngoại lệ và hiển thị thông điệp ngoại lệ.

::result
Xảy ra ngoại lệ: Tuổi không hợp lệ</br>
Phần còn lại của mã...
::

Custom Exception cho phép bạn tạo ra các tình huống xử lý ngoại lệ đặc biệt trong ứng dụng của bạn và làm cho mã của bạn dễ đọc và dễ bảo trì hơn.
