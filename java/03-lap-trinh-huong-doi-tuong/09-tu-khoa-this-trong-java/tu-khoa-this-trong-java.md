---
title: "Từ khóa this trong Java"
description: "Từ khóa this trong java là một biến tham chiếu được sử dụng để tham chiếu tới đối tượng của lớp hiện tại. Biến this là một biến ẩn tồn tại trong tất cả các lớp trong ngông ngữ java"
chapter:
  name: "Lập trình hướng đối tượng"
  slug: "chuong-03-lap-trinh-huong-doi-tuong"
category:
  name: "Java"
  slug: "java"
image: https://user-images.githubusercontent.com/29374426/131205481-bc00bbd6-82c5-4e1f-b53d-c28d00e98e0f.png
position: 9
---

Từ khóa **this** trong java là một biến tham chiếu được sử dụng để tham chiếu tới đối tượng của lớp hiện tại. Biến **this** là một biến ẩn tồn tại trong tất cả các lớp trong ngông ngữ java. Một class trong Java luôn tồn tại một biến this.

![image](https://user-images.githubusercontent.com/29374426/131205481-bc00bbd6-82c5-4e1f-b53d-c28d00e98e0f.png)

## Tham chiếu tới biến instance của lớp hiện tại.

Từ khóa **this** trong java có thể được dùng để tham chiếu tới biến instance của lớp hiện tại. Sẽ rất phức tạp nếu như có một biến toàn cục và biến cục bộ trùng tên thì từ khóa **this** sẽ giúp bạn giải quyết vấn đề này.

<div class="example">thể hiện tham chiếu tới lớp</div>

```java
public class HocSinh {

    int id;
    String name;

    HocSinh(int id, String name) {
        id = id;
        name = name;
    }

    void hienThi() {
        System.out.println(id + " " + name);
    }

    public static void main(String args[]) {
        HocSinh s1 = new HocSinh(111, "Viet");
        HocSinh s2 = new HocSinh(222, "Nam");
        s1.hienThi();
        s2.hienThi();
    }
}
```

::Result

    <code>0 null</code><br/>
    <code>0 null </code>

::

Ở ví dụ này, tên của tham số của [constructor](/bai-viet/java/phuong-thuc-khoi-tao) `HocSinh()` trùng với tên của biến toàn cục đó là lý do tại sao cần phải sử dụng từ khóa this để phân biệt biến cục bộ và biến toàn cục. Từ khóa this sẽ giúp chúng ta giải quyết vấn đề này.

```java
public class HocSinh {

    int id;
    String name;

    HocSinh(int id, String name) {
        this.id = id;
        this.name = name;
    }

    void hienThi() {
        System.out.println(id + " " + name);
    }

    public static void main(String args[]) {
        HocSinh s1 = new HocSinh(111, "Viet");
        HocSinh s2 = new HocSinh(222, "Nam");
        s1.hienThi();
        s2.hienThi();
    }
}
```

::Result

    <code>111 Viet</code><br/>
    <code>222 Nam</code>

::

::alert{type="infor"}
Nếu biến cục bộ và biến toàn cục có tên khác nhau thì không cần sử dụng từ khóa this.
::

## Sử dụng this() gọi constructor của lớp hiện tại.

Phương thức `this()` có thể được sử dụng để gọi [constructor](/bai-viet/java/phuong-thuc-khoi-tao) của lớp hiện tại. Cách sử dụng này sẽ hữu dụng hơn nếu bạn có nhiều [constructor](/bai-viet/java/phuong-thuc-khoi-tao) trong một lớp và bạn muốn sử dụng lại.

```java
public class HocSinh2 {

    int id;
    String name;

    HocSinh2() {
        System.out.println("gọi constructor mặc định");
    }

    HocSinh2(int id, String name) {
        this(); // nó được sử dụng để gọi constructor của lớp hiện tại
        this.id = id;
        this.name = name;
    }

    void display() {
        System.out.println(id + " " + name);
    }

    public static void main(String args[]) {
        HocSinh2 e1 = new HocSinh2(111, "Viet");
        HocSinh2 e2 = new HocSinh2(222, "Nam");
        e1.display();
        e2.display();
    }
}
```

::Result

    <code>gọi Constructor mặc định</code><br/>
    <code>111 Viet</code><br/>
    <code>222 Nam</code>

::

`this()` được dùng để sự dụng lại [constructor](/bai-viet/java/phuong-thuc-khoi-tao) trong [constructor](/bai-viet/java/phuong-thuc-khoi-tao) khác. Nó sẽ thừa kế các thuộc tính của [constructor](/bai-viet/java/phuong-thuc-khoi-tao) được gọi.

```java
public class HocSinh3 {

    int id;
    String name;
    String city;

    HocSinh3(int id, String name) {
        this.id = id;
        this.name = name;
    }

    HocSinh3(int id, String name, String city) {
        this(id, name);// now no need to initialize id and name
        this.city = city;
    }

    void display() {
        System.out.println(id + " " + name + " " + city);
    }

    public static void main(String args[]) {
        HocSinh3 e1 = new HocSinh3(111, "Viet");
        HocSinh3 e2 = new HocSinh3(222, "Nam", "Ha Noi");
        e1.display();
        e2.display();
    }
}
```

::Result

    <code>111 Viet</code><br/>
    <code>222 Nam</code>

::

::alert{type="infor"}
this() phải được khai báo dòng lệnh đầu tiên trong Constructor.
::

### Gọi phương thức của lớp hiện tại

Bạn có thể sử dụng từ khóa `this` để gọi phương thức của lớp hiện tại. Nếu bạn không sử dụng từ khóa `this`, trình biên dịch sẽ tự động thêm từ khóa `this` cho việc gọi phương thức.

![image](https://user-images.githubusercontent.com/29374426/131204535-5cb697f9-425d-4019-af0f-e84ca1542234.png)

```java
public class HocSinh4 {

    void sayHello() {
        System.out.println("Hello Thaycacac");
    }

    void noiXinChao() {
        System.out.println("Xin chao Thaycacac");
        this.sayHello(); // bạn cũng có thể gọi thông qua biến this
    }

    void xinChao() {
        noiXinChao();// trình biên dịch sẽ thêm this để gọi phương thức noiXinChao()
    }

    public static void main(String args[]) {
        HocSinh4 hocSinh = new HocSinh4();
        hocSinh.xinChao();
    }
}
```

::Result

    <code>Xin chao Thaycacac</code><br/>
    <code>Hello Thaycacac</code>

::

## Sử dụng từ khóa this như một tham số của phương thức

Từ khóa `this` có thể được dùng như một tham số trong phương thức. Cách dùng này chủ yếu được sử dụng trong xử lý sự kiện.

```java
public class HocSinh5 {

    void m(HocSinh5 obj) {
        System.out.println("Hello Thaycacac");
    }

    void p() {
        m(this); // this lúc này là đối tượng học sinh
    }

    public static void main(String args[]) {
        HocSinh5 hocSinh = new HocSinh5();
        hocSinh.p();
    }
}
```

::Result

    <code>Hello Thaycacac</code>

::

Chúng ta cũng có thể truyền từ khóa `this` trong [constructor](/bai-viet/java/phuong-thuc-khoi-tao).Việc này rất hữu ích nếu chúng ta phải sử dụng một đối tượng trong nhiều lớp.

```java
class B {

    A4 obj;

    B(A4 obj) {
        this.obj = obj;
    }

    void display() {
        System.out.println(obj.data);// sử dụng biến thành viên cửa lớp A4
    }
}

class A4 {

    int data = 10;

    A4() {
        B b = new B(this);
        b.display();
    }

    public static void main(String args[]) {
        A4 a = new A4();
    }
}
```

::Result

    <code>10</code>

::

## Sử dụng từ khóa this để trả về instance của lớp hiện tại

Chúng ta có thể trả về instance của lớp hiện tại bằng cách sử dụng từ khóa this. Trong trường hợp này, kiểu trả về của phương thức phải là kiểu class (không là kiểu nguyên thủy).

```java
class A {
    A getA() {
        return this;
    }
    void msg() {
        System.out.println("Hello Thaycacac");
    }
}

class Test1 {
    public static void main(String args[]) {
        new A().getA().msg();
    }
}
```

::Result

    <code>Hello Thaycacac</code>

::
