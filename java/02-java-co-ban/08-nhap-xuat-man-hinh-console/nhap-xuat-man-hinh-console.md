---
title: "Nhập xuất màn hình console trong Java"
description: "Đối với những người mới bắt đầu học Java cơ bản, thì việc sử dụng nhập xuất trong màn hình console thông qua Scanner, Buffered Reader hay console là điều tất yếu để giải các bài tập"
chapter:
  name: "Nhập môn Java"
  slug: "chuong-02-nhap-mon-java"
category:
  name: "Java"
  slug: "java"
image: https://user-images.githubusercontent.com/29374426/128108517-2d46376d-f9e2-4075-b311-1e06ff63ffc5.png
position: 8
---

Đối với những người mới bắt đầu học Java cơ bản, việc sử dụng nhập xuất trong màn hình console là điều tất yếu để giải các bài tập và tương tác với người dùng. Trong Java, chúng ta có nhiều cách khác nhau để đọc và hiển thị dữ liệu trên màn hình console. Trong bài viết này, chúng ta sẽ tìm hiểu về cách sử dụng các lớp Scanner, BufferedReader và Console để thực hiện các thao tác nhập xuất cơ bản.

![Nhập xuất màn hình console trong Java](https://user-images.githubusercontent.com/29374426/128108517-2d46376d-f9e2-4075-b311-1e06ff63ffc5.png)

## Sử dụng lớp Scanner

Lớp Scanner cung cấp nhiều chức năng cho việc đọc dữ liệu từ màn hình console và có thể phân loại dữ liệu theo các kiểu khác nhau như số nguyên, số thực, chuỗi, và nhiều loại khác.

### Đọc chuỗi từ màn hình console

Để đọc một chuỗi từ màn hình console, chúng ta sử dụng phương thức `nextLine()` của lớp Scanner như sau:

```java
import java.util.Scanner;

public class NhapXuat {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Nhập tên của bạn: ");
        String name = scanner.nextLine();
        System.out.println("Tên của bạn là: " + name);
    }

}
```

::result
Nhập tên của bạn: John

Tên của bạn là: John
::

### Đọc số từ màn hình console

Để đọc các kiểu dữ liệu số từ màn hình console, chúng ta sử dụng các phương thức như `nextInt()` để đọc số nguyên, `nextDouble()` để đọc số thực, `nextFloat()` để đọc số thực dấu phẩy động, vv. Dưới đây là một ví dụ:

```java
import java.util.Scanner;

public class NhapXuat {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Nhập tuổi của bạn: ");
        int age = scanner.nextInt();
        System.out.println("Tuổi của bạn là: " + age);
        System.out.print("Nhập chiều cao của bạn: ");
        double height = scanner.nextDouble();
        System.out.println("Chiều cao của bạn là: " + height);
    }

}
```

::result
Nhập tuổi của bạn: 25

Tuổi của bạn là: 25

Nhập chiều cao của bạn: 175.5

Chiều cao của bạn là: 175.5
::

## Sử dụng lớp BufferedReader

Lớp BufferedReader cũng cho phép đọc dữ liệu từ màn hình console, nhưng nó cung cấp kiểm soát linh hoạt hơn đối với việc xử lý lỗi và ngoại lệ.

### Đọc chuỗi từ màn hình console

Để đọc một chuỗi từ màn hình console bằng lớp BufferedReader, chúng ta sử dụng phương thức `readLine()` như sau:

```java
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class NhapXuat {

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        System.out.print("Nhập tên của bạn: ");
        String name = reader.readLine();
        System.out.println("Tên của bạn là: " + name);
    }

}
```

::result
Nhập tên của bạn: Alice

Tên của bạn là: Alice
::

### Đọc số từ màn hình console

Để đọc các kiểu dữ liệu số từ màn hình console bằng lớp BufferedReader, chúng ta đọc chuỗi và sau đó chuyển đổi nó thành kiểu số tương ứng bằng cách sử dụng `Integer.parseInt()` hoặc `Double.parseDouble()`. Dưới đây là ví dụ:

```java
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class NhapXuat {

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        System.out.print("Nhập tuổi của bạn: ");
        int age = Integer.parseInt(reader.readLine());
        System.out.println("Tuổi của bạn là: " + age);
        System.out.print("Nhập chiều cao của bạn: ");
        double height = Double.parseDouble(reader.readLine());
        System.out.println("Chiều cao của bạn là: " + height);
    }

}
```

::result
Nhập tuổi của bạn: 30

Tuổi của bạn là: 30

Nhập chiều cao của bạn: 175.5

Chiều cao của bạn là: 175.5
::

## Sử dụng lớp Console

Lớp Console cung cấp một số tính năng tiện ích cho việc nhập xuất từ màn hình console và cho phép ẩn mật khẩu khi nhập.

```java
import java.io.Console;

public class NhapXuat {

    public static void main(String[] args) {
        Console console = System.console();
        if (console == null) {
            System.out.print("Console không sẵn sàng");
            return;
        }
        System.out.println("Nhập mật khẩu: ");
        char[] passwordChars = console.readPassword();
        String password = String.valueOf(passwordChars);
        System.out.println("Mật khẩu của bạn là: " + password);
    }

}
```

::result
Nhập mật khẩu:

Mật khẩu của bạn là: mySecretPassword
::

Lớp Console có thể được sử dụng để ẩn mật khẩu khi nhập, giúp bảo vệ thông tin mật khẩu của người dùng.

::alert{type="infor"}
Trong Java, bạn có thể sử dụng lớp Scanner, BufferedReader và Console để thực hiện các thao tác nhập xuất từ màn hình console. Sự lựa chọn giữa các lớp này phụ thuộc vào yêu cầu cụ thể của ứng dụng và cách bạn muốn xử lý dữ liệu nhập từ người dùng. Chúc bạn thành công trong việc sử dụng các phương thức này để tương tác với người dùng trong ứng dụng Java của bạn!
::
