---
title: "Từ khóa throws trong Java"
description: "Từ khóa throws trong java được sử dụng để khai báo một ngoại lệ, nó thể hiện thông tin cho lập trình viên rằng có thể xảy ra một ngoại lệ, vì vậy nó là tốt hơn cho các lập trình viên để cung cấp các mã xử lý ngoại lệ để duy trì luồng bình thường của chương trình."
chapter:
  name: "Xử lý ngoại lệ"
  slug: "chuong-05-xu-ly-ngoai-le"
image: https://shareprogramming.net/wp-content/uploads/2020/01/throw-1.jpg
position: 7
---

Từ khóa `throws` trong Java được sử dụng để khai báo một ngoại lệ. Nó cung cấp thông tin cho lập trình viên rằng có thể xảy ra một ngoại lệ trong phương thức, và do đó, nó yêu cầu lập trình viên cung cấp mã xử lý ngoại lệ để duy trì luồng bình thường của chương trình.

## Cú Pháp của Từ Khóa "throws"

```java
return_type method_name() throws exception_class_name {
    // Mã thực hiện của phương thức
}
```

- `return_type`: Kiểu dữ liệu của giá trị mà phương thức trả về (ví dụ: `int`, `String`, `void`,...).
- `method_name`: Tên của phương thức.
- `exception_class_name`: Tên của lớp ngoại lệ mà phương thức có thể ném ra.

Chỉ nên khai báo các ngoại lệ kiểu "checked" bằng từ khóa "throws", vì các ngoại lệ "unchecked" (như `NullPointerException`) thường là lỗi của lập trình viên mà anh ta không thể kiểm tra trước khi sử dụng code.

## Lợi Ích của Từ Khóa "throws" trong Java

1. **Xử Lý Ngoại Lệ Checked**: Từ khóa "throws" thường được sử dụng để xử lý các ngoại lệ "checked". Điều này cho phép lập trình viên bắt buộc xử lý các ngoại lệ có thể xảy ra.

2. **Cung Cấp Thông Tin Cho Caller**: Bằng cách sử dụng "throws", phương thức cung cấp thông tin cho caller của nó về các ngoại lệ mà nó có thể gặp phải, giúp caller chuẩn bị và xử lý chúng một cách thích hợp.

## Ví Dụ về Sử Dụng Từ Khóa "throws" trong Java

Dưới đây là một ví dụ minh họa về cách sử dụng từ khóa "throws" trong Java:

```java
import java.io.IOException;

public class TestThrows {
    void m() throws IOException {
        throw new IOException("Lỗi thiết bị"); // Ngoại lệ kiểu checked
    }

    void n() throws IOException {
        m();
    }

    void p() {
        try {
            n();
        } catch (Exception e) {
            System.out.println("Ngoại lệ được xử lý");
        }
    }

    public static void main(String args[]) {
        TestThrows obj = new TestThrows();
        obj.p();
        System.out.println("Luồng bình thường...");
    }
}
```

::result
Ngoại lệ được xử lý</br>
Luồng bình thường...
::

Trong ví dụ này, phương thức `m()` khai báo sử dụng từ khóa "throws" để báo cho caller rằng nó có thể ném ra ngoại lệ kiểu checked `IOException`. Trong phương thức `main()`, chúng ta gọi phương thức `p()` để thực hiện cuộc gọi phương thức nội tuyến, và ngoại lệ được xử lý bằng cách sử dụng khối `try-catch`.

**Trường hợp xử lý ngoại lệ với try/catch:**

```java
import java.io.IOException;

class M {
    void method() throws IOException {
        throw new IOException("Lỗi thiết bị"); // Ngoại lệ kiểu checked
    }
}

public class TestThrows {
    public static void main(String args[]) {
        try {
            M m = new M();
            m.method();
        } catch (Exception e) {
            System.out.println("Ngoại lệ được xử lý");
        }

        System.out.println("Luồng bình thường...");
    }
}
```

::result
Ngoại lệ được xử lý</br>
Luồng bình thường...
::

Trong trường hợp này, ngoại lệ đã được xử lý bởi khối `catch`, và chương trình tiếp tục thực hiện luồng bình thường sau khi xử lý ngoại lệ.
