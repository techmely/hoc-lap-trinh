---
title: "Từ khóa thows trong Java"
description: "Từ khóa throws trong java được sử dụng để khai báo một ngoại lệ, nó thể hiện thông tin cho lập trình viên rằng có thể xảy ra một ngoại lệ, vì vậy nó là tốt hơn cho các lập trình viên để cung cấp các mã xử lý ngoại lệ để duy trì luồng bình thường của chương trình."
chapter:
  name: "Xử lý ngoại lệ"
  slug: "chuong-05-xu-ly-ngoai-le"
category:
  name: "Java"
  slug: "java"
image: https://shareprogramming.net/wp-content/uploads/2020/01/throw-1.jpg
position: 7
---

Từ khóa `throws` trong java được sử dụng để khai báo một ngoại lệ. Nó thể hiện thông tin cho lập trình viên rằng có thể xảy ra một ngoại lệ, vì vậy nó là tốt hơn cho các lập trình viên để cung cấp các mã xử lý ngoại lệ để duy trì luồng bình thường của chương trình.

`Exception Handling` chủ yếu được sử dụng để xử lý ngoại lệ `checked`. Nếu xảy ra bất kỳ ngoại lệ `unchecked` như `NullPointerException`, đó là lỗi của lập trình viên mà anh ta không thực hiện kiểm tra trước khi code được sử dụng.

Cú pháp từ khóa throws:

```java
return_type method_name() throws exception_class_name {
    / /method code
}
```

Chỉ những ngoại lệ checked nên được khai báo bởi vì **ngoại lệ unchecked**: nằm trong sự kiểm soát của bạn. Còn **error** nằm ngoài sự kiểm soát của bạn, ví dụ bạn sẽ không thể làm được bất kì điều gì khi các lỗi `VirtualMachineError` hoặc `StackOverflowError` xảy ra.

## Lợi ích của từ khóa throws trong java

- Ngoại lệ checked có thể được ném ra ngoài và được xử lý ở một hàm khác.
- Cung cấp thông tin cho caller của phương thức về các ngoại lệ.

## Ví dụ về từ khóa throws trong java

<content-example />

```java
import java.io.IOException;

public class TestThrows1 {
    void m() throws IOException {
        throw new IOException("Loi thiet bi");// checked exception
    }

    void n() throws IOException {
        m();
    }

    void p() {
        try {
            n();
        } catch (Exception e) {
            System.out.println("ngoai le duoc xu ly");
        }
    }

    public static void main(String args[]) {
        TestThrows1 obj = new TestThrows1();
        obj.p();
        System.out.println("luong binh thuong...");
    }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>ngoai le duoc xu ly</code><br/>
    <code>luong binh thuong...</code><br/>
  </div>
</div>

**Trường hợp xử lý ngoại lệ với try/catch**

<div class="example">Trong trường hợp bạn xử lý ngoại lệ, code sẽ được thực thi tốt cho dù ngoại lệ có xuất hiện trong chương trình hay không.</div>

```java
import java.io.IOException;

class M {
    void method() throws IOException {
        throw new IOException("Loi thiet bi");
    }
}

public class TestThrows2 {
    public static void main(String args[]) {
        try {
            M m = new M();
            m.method();
        } catch (Exception e) {
            System.out.println("Ngoai le duoc xu ly");
        }

        System.out.println("Luong binh thuong...");
    }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>Ngoai le duoc xu ly</code><br/>
    <code>Luong binh thuong...</code><br/>
  </div>
</div>

**Khai báo throws ngoại lệ**

<div class="example">Trong trường hợp bạn khai báo throws ngoại lệ, nếu ngoại lệ không xảy ra, code sẽ được thực hiện tốt.</div>

```java
import java.io.IOException;

class M {
    void method() throws IOException {
        System.out.println("Thiet bi dang hoat dong tot");
    }
}

public class TestThrows2 {
    public static void main(String args[]) throws IOException {
        M m = new M();
        m.method();
        System.out.println("Luong binh thuong...");
    }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>Thiet bi dang hoat dong tot</code><br/>
    <code>Luong binh thuong...</code><br/>
  </div>
</div>

 <div class="example">Trong trường hợp bạn khai báo throws ngoại lệ, nếu ngoại lệ xảy ra, một ngoại lệ sẽ được ném ra tại runtime vì throws nên không xử lý ngoại đó.</div>

```java
import java.io.IOException;

class M {
    void method() throws IOException {
        throw new IOException("Thiet bi");
    }
}

public class TestThrows2 {
    public static void main(String args[]) throws IOException {
        M m = new M();
        m.method();
        System.out.println("Luong binh thuong...");
    }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>Exception in thread "main" java.io.IOException: Thiet bi</code>
  </div>
</div>
