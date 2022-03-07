---
title: "Nhập xuất màn hình console trong Java"
description: "Đối với những người mới bắt đầu học Java cơ bản, thì việc sử dụng nhập xuất trong màn hình console thông qua Scanner, Buffered Reader hay console là điều tất yếu để giải các bài tập"
keywords:
  [
    "console trong java",
    "cách nhập dữ liệu từ bàn phím trong java",
    "câu lệnh nhập xuất trong java",
    "hàm nhập xuất trong java",
    "khai báo nhập xuất trong java",
    "lệnh nhập xuất trong java",
    "lỗi nhập xuất trong java",
    "nhập dữ liệu từ bàn phím trong java",
    "nhập và xuất mảng trong java",
    "nhập xuất chuỗi trong java",
    "nhập xuất console trong java code",
    "nhập xuất console trong java fpt",
    "nhập xuất dữ liệu trong java",
  ]
author:
  fullname: Techmely Team
  username: Techmely Team
  avatar: "/configs/author/logo.jpg"
chapter:
  name: "Nhập môn Java"
  slug: "chuong-02-nhap-mon-java"
category:
  logo: "/language/java.png"
  name: "Java"
  slug: "java"
  description: "Học Java từ cơ bản đến thông thạo cho mọi đối tượng"
image: https://user-images.githubusercontent.com/29374426/128108517-2d46376d-f9e2-4075-b311-1e06ff63ffc5.png
position: 8
---

Đối với những người mới bắt đầu học Java cơ bản, thì việc sử dụng nhập xuất trong màn hình `console` là điều tất yếu để giải các bài tập. Trong java chúng ta có nhiều cách khác nhau để đọc dữ từ màn hình console, chúng ta sẽ đi qua từng cách ở phần sau.

![nhap-xuat-man-hinh-console](https://user-images.githubusercontent.com/29374426/128108517-2d46376d-f9e2-4075-b311-1e06ff63ffc5.png)

## Sử dụng Scanner class

Đây có lẽ là cách mà mọi người thường hay dùng nhất. `Scanner` cung cấp nhiều chức năng hơn và chúng có thể phân loại từng kiểu dữ liệu mà người dùng nhập vào như kiểu số nguyên, số thực, chuỗi,...

### Đọc chuỗi từ màn hình console

Để đọc một chuỗi trong Scanner chúng ta sử dụng method `readLine()`.

<div class="example"></div>

```java
import java.util.Scanner;

/**
 *
 * @author Thaycacac <kungfutech.edu.vn>
 */
public class NhapXuat {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Nhập tên của bạn: ");
        String name = scanner.nextLine();
        System.out.println("Tên của bạn là: " + name);
    }

}

```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>Nhập tên của bạn:<b>thaycacac</b></code><br/>
    <code>Tên của bạn là: <b>thaycacac</b></code>
  </div>
</div>

### Đọc số trong màn hình console

Để nhập xuất kiểu số, chúng ta sử dụng `nextInt()` để đọc số Integer, `nextDouble()` để đọc số Double, `nextFloat()` để đọc số float etc.

<div class="example"></div>

```java
import java.util.Scanner;

/**
 *
 * @author Thaycacac <kungfutech.edu.vn>
 */
public class NhapXuat {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Nhập tuổi của bạn: ");
        int name = scanner.nextInt();
        System.out.println("Tuổi của bạn là: " + name);
        System.out.print("Nhập chiều cao của bạn: ");
        double height = scanner.nextDouble();
        System.out.println("Chiều cao của bạn là: " + height);
    }

}

```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>Nhập tuổi của bạn: <b>18</b></code><br/>
    <code>Tuổi của bạn là: <b>18</b></code><br/>
    <code>Nhập chiều cao của bạn: <b>18.22</b></code><br/>
    <code>Chiều cao của bạn là: <b>18.22</b></code>
  </div>
</div>

## Sử dụng Buffered Reader Class

### Đọc chuỗi từ màn hình console

Sử dụng `readLine()` để đọc một chuỗi từ màn hình console

<div class="example"></div>

```java
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Thaycacac
{
  public static void main(String[] args) throws IOException {
    BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    System.out.print("Nhập tên của bạn: ");
    String name = reader.readLine();
    System.out.println("Tên của bạn là: " + name);
  }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>Nhập tên của bạn: <b>thaycacac</b></code><br/>
    <code>Tên của bạn là: <b>thaycacac</b></code>
  </div>
</div>

### Đọc số trong màn hình console

Để đọc số trong màn hình console chúng ta sử dụng `readLine()` kết hợp với `Double.parse()` hoặc `Integer.parse()` để đọc kiểu dữ liệu tương ứng.

<div class="example"></div>

```java
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Thaycacac {
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

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>Nhập tuổi của bạn: <b>18</b></code><br/>
    <code>Tuổi của bạn là: <b>18</b></code><br/>
    <code>Nhập chiều cao của bạn: <b>18.22</b></code><br/>
    <code>Chiều cao của bạn là: <b>18.22</b></code>
  </div>
</div>

## Sử dụng console class

Sử dụng Console class cũng là một trong những cách thường dùng, đặc biệt nó có thể dùng để đọc password thứ mà không hiện thị lên màn hình console mà chỉ đọc ngầm bên dưới.

<div class="example"></div>

```java
import java.io.Console;

class ReadPassword {
  public static void main(String args[]) {
    Console con = System.console();
    if (con == null) {
      System.out.print("Console không sẵn sàng");
      return;
    }
    System.out.println("Nhập mật khẩu: ");
    char[] ch = con.readPassword();
    String pass = String.valueOf(ch);
    System.out.println("Mật khẩu của bạn là: " + pass);
  }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>Nhập mật khẩu: <b>@myPassword</b></code><br/>
    <code>Mật khẩu của bạn là: <b>@myPassword</b></code>
  </div>
</div>
