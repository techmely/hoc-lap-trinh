---
title: "Từ khóa final trong Java"
description: "Từ khoá final trong java có nhiều nghĩa khác nhau, nghĩa của nó tuỳ thuộc vào ngữ cảnh cụ thể, nhưng nói chung nó muốn nói cái này không thể thay đổi được"
chapter:
  name: "Lập trình hướng đối tượng"
  slug: "chuong-03-lap-trinh-huong-doi-tuong"
category:
  name: "Java"
  slug: "java"
image: https://user-images.githubusercontent.com/29374426/131223902-8d3449d5-dd79-4043-9490-129f9ae37aaa.png
position: 10
---

Từ khoá final trong java có nhiều nghĩa khác nhau, nghĩa của nó tuỳ thuộc vào ngữ cảnh cụ thể, nhưng nói chung nó muốn nói **cái này không thể thay đổi được**.

- **Biến final**: bạn không thể thay đổi giá trị của biến final (nó sẽ là hằng số).
- **Phương thức final**: bạn không thể ghi đè phương thức final.
- **Lớp final**: bạn không thể kế thừa lớp final.
- **Biến static final trống**: Một biến final mà không được khởi tạo tại thời điểm khai báo được gọi là biến final trống.

![image](https://user-images.githubusercontent.com/29374426/131223902-8d3449d5-dd79-4043-9490-129f9ae37aaa.png)

## Biến final trong Java

Nếu bạn tạo bất cứ biến nào là `final`, bạn không thể thay đổi giá trị của biến này (nó sẽ là hằng số). Giả sử có một biến final là `PI`. Bạn cố ý thay đổi giá trị của biến này nhưng nó không bị thay đổi, bởi vì biến final một khi được gán giá trị thì không bao giờ thay đổi được.

<content-example />

```java
public class Thaycacac {
    final int PI = 3.14159265; // biến final là hằng số và không thể thay đổi

    void run() {
        PI = 22;
    }

    public static void main(String args[]) {
        Thaycacac obj = new Thaycacac();
        obj.run();
    }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả sẽ hiển thị thông báo lỗi</span>
  </div>
  <div class="window-body">
    <code>Compile Time Error Exception in thread "main" java.lang.Error: Unresolved compilation problem: The final field Thaycacac.PI cannot be assigned</code>
  </div>
</div>

<content-info>
<ul>
  <li>Khi đã khai báo một thuộc tính là final thì thuộc tính này la hăng, do vậy ta không thể thay đổi giá trị của nó</li>
  <li>Khi khai báo một thuộc tính là final thì ta phải cung cấp giá trị ban đầu cho nó</li>
  <li>Nếu một thuộc tính vừa là final vừa là static thì nó chỉ có một vùng nhớ chung duy nhất cho cả lớp</li>
</ul>
</content-info>

## Phương thức final trong Java

Một phương thức bình thường có thể bị ghi đè ở lớp con, đôi khi ta không muốn lớp con bị ghi đè ở lớp con vì lý do gì đó, mục đích chủ yếu của các phương thức final là tránh ghi đè, tuy nhiên ta thấy rằng các phương thức private sẽ tự động là final vì chúng không thể thấy được trong lớp con nên chúng không thể bị ghi đè, nên cho dù bạn có cho một phương thức private là final thì bạn cũng chả thấy thay đổi nào.

<content-example />

```java
class Bike {
    final void run() {
        System.out.println("running");
    }
}

public class SH extends Bike {
    void run() {
        System.out.println("Chay an toan voi 150km/h");
    }

    public static void main(String args[]) {
        SH sh = new SH();
        sh.run();
    }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả sẽ hiển thị thông báo lỗi</span>
  </div>
  <div class="window-body">
    <code>Exception in thread "main" java.lang.VerifyError: class vn.viettuts.keywords.SH overrides final method run.()</code>
  </div>
</div>

## Lớp final trong Java

Nếu bạn không muốn người khác kế thừa từ lớp của bạn, thì bạn hãy dùng từ khoá final để ngăn cản bất cứ ai muốn kế thừa từ lớp này.

<content-example />

```java
final class Bike {
}

public class SH1 extends Bike {
    void run() {
        System.out.println("Chay an toan voi 150km/h");
    }

    public static void main(String args[]) {
        SH1 sh = new SH1();
        sh.run();
    }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả sẽ hiển thị thông báo lỗi</span>
  </div>
  <div class="window-body">
    <code>Compile Time Error</code>
  </div>
</div>

_Chú ý:_ do một lớp là final (tức không thể kế thừa )do vậy ta không thể nào ghi đè các phương thức của lớp này, do vậy đừng cố gắng cho một phương thức của lớp final là final

## Biến static final trống trong Java

Một biến static final mà không được khởi tạo tại thời điểm khai báo thì đó là biến static final trống. Nó chỉ có thể được khởi tạo trong khối static.

<content-example />

```java
public class A {
    static final int data; // biến static final trống
    static {
        data = 50;
    }

    public static void main(String args[]) {
        System.out.println(A.data);
    }
}
```

## Đối số final trong Java

Java cho phép ta tạo ra các đối final bằng việc khai báo chúng như vậy bên trong danh sách đối, nghĩa là bên trong thân của phương pháp này, bất cứ cố gắng nào để thay đổi giá trị của đối đều gây ra lỗi lúc dịch Ví dụ sau bị báo lỗi lúc dịch vì nó cố gắng thay đổi giá trị của đối final

```java
public class A {

  static public void thu ( final int i ) {
    i=i+1; // không cho phép thay đổi giá trị của tham số final
    System.out.println ( i );;
  }

  public static void main ( String arg[] ) {
    int i = 100; thu ( i );
  }
}
```

Chương trình sẽ in ra lỗi

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>"A.java": variable i might already have been assigned to at line 5, column 9</code>
  </div>
</div>
