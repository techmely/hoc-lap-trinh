---
title: "Tính đa hình trong OOP"
description: "Bài này chúng ta sẽ tìm hiểu về Từ khóa final, tự học lập trình java, chia sẻ kiến thức về java"
chapter:
  name: "Lập trình hướng đối tượng"
  slug: "chuong-03-lap-trinh-huong-doi-tuong"
category:
  name: "Java"
  slug: "java"
image: https://user-images.githubusercontent.com/29374426/131280717-ae65a2c9-0e6d-4b34-9b60-e0ebdd61331b.png
position: 4
---

Đa hình (polymorphism) nghĩa là có nhiều hình thái khác nhau. Tiêu biểu là, đa hình xuất hiện khi có một cấu trúc cấp bậc của các lớp và chúng liên quan với nhau bởi [tính kế thừa](/bai-viet/java/tinh-thua-ke-trong-oop).

Bạn hãy thử tưởng tượng nếu bạn yêu cầu những người sau thực hiện hành động **"cắt"**:

- Bác sĩ phẫu thuật
- Nhà tạo mẫu tóc
- Diễn viên

Khi đó, chuyện gì sẽ xảy ra?

- Bác sĩ phẫu thuật sẽ bắt đầu rạch dao mổ.
- Nhà tạo mẫu sẽ bắt đầu cắt tóc cho một ai đó.
- Nam diễn viên sẽ ngừng diễn cảnh hiện tại, chờ đạo diễn hướng dẫn.

Ví dụ trên cho thấy bản chất của Tính đa hình. Nó tượng trưng cho việc cùng một tên gọi nhưng hành vi thì khác nhau.

## Tính đa hình (Polymorphism) trong lập trình hướng đối tượng

Tính đa hình là một hành động có thể được thực hiện bằng nhiều cách khác nhau. Đây lại là một tính chất có thể nói là chứa đựng hầu hết sức mạnh của lập trình hướng đối tượng.

Hiểu một cách đơn giản hơn: Đa hình là khái niệm mà hai hoặc nhiều lớp có những phương thức giống nhau nhưng có thể thực thi theo những cách thức khác nhau. Một ví dụ về đa hình khác trong thực tế đó là ta có 2 con vật: chó, mèo. Cả 2 con vật này đều là lớp động vật. Nhưng khi ta bảo cả 2 động vật kêu thì con chó sẽ kêu gâu gâu, con mèo sẽ kêu meo meo.

## Các loại đa hình trong lập trình hướng đối tượng

Tính đa hình chủ yếu được chia thành hai loại:

- Đa hình thời gian chạy (Runtime Polymorphism)
- Đa hình thời gian biên dịch (Compile Time Polymorphism)

![image](https://user-images.githubusercontent.com/29374426/131280717-ae65a2c9-0e6d-4b34-9b60-e0ebdd61331b.png)

### Đa hình thời gian chạy

Đa hình lúc runtime là quá trình gọi phương thức đã được ghi đè trong thời gian thực thi chương trình. Trong quá trình này, một phương thức được ghi đè được gọi thông qua biến tham chiếu của một lớp cha.

<div class="example">Chúng ta tạo hai lớp Bike và Car. Lớp Bike kế thừa lớp Car và ghi đè phương thức run() của nó. Chúng ta gọi phương thức run bởi biến tham chiếu của lớp cha. Khi nó tham chiếu tới đối tượng của lớp con và phương thức lớp con ghi đè phương thức của lớp cha, phương thức lớp con được gọi lúc runtime.</div>

```java
class Car {
    void run() {
        System.out.println("chạy");
    }
}

public class Bike extends Car {
    void run() {
        System.out.println("chạy với tốc độ 30km/h");
    }

    public static void main(String args[]) {
        Bike b = new Splender(); // upcasting
        b.run();
    }
}
```

::Result

    <code>chạy với tốc độ 30km/h</code>

::

<div class="example">Một ví dụ khác về tính đa hình</div>

```java
class Shape {
    void draw() {
        System.out.println("vẽ...");
    }
}

class Rectangle extends Shape {
    void draw() {
        System.out.println("vẽ hình chữ nhật...");
    }
}

class Circle extends Shape {
    void draw() {
        System.out.println("vẽ hình tròn...");
    }
}

class Triangle extends Shape {
    void draw() {
        System.out.println("vẽ hình tam giác...");
    }
}

class Main {
    public static void main(String args[]) {
        Shape s;
        s = new Rectangle();
        s.draw();
        s = new Circle();
        s.draw();
        s = new Triangle();
        s.draw();
    }
}
```

::Result

    <code>vẽ hình chữ nhật...</code><br/>
    <code>vẽ hình tròn...</code><br/>
    <code>vẽ hình tam giác...</code>

::

Tuy nhiên khi chúng ta truy cập thuộc tính của lớp con thì sẽ không bị ghi đè, mà nó sẽ truy cập thuộc tính của lớp cha.

```java
class Bike{
 int speedlimit = 90;
}

class Honda3 extends Bike {
 int speedlimit = 150;
}

public static void main(String args[]){
  Bike obj=new Honda3();
  System.out.println(obj.speedlimit);//90
}
```

::Result

    <code>90</code>

::

## Đa hình thời gian biên dịch

Đa hình thời gian biên dịch sử dụng phương thức nạp chồng. Do sử dụng chung một cái tên cho nhiều phương thức, nên ta phải cho java biết cần phải gọi phương thức nào để thực hiện, java dựa vào sự khác nhau về số lượng đối cũng như kiểu dữ liệu của các đối này để phân biệt các phương thức trùng tên đó..

```java
public class OverloadingOrder {
  static void print(String s, int i) {
    System.out.println("String: " + s + ", int: " + i);
  }

  static void print(int i, String s) {
    System.out.println("int: " + i +", String: " + s);
  }

  public static void main(String[] args) {
    print("String first", 11);
    print(99, "Int first");
  }
}
```

::Result

    <code>String: String first, int: 11</code></br>
    <code>int: 99, String: Int first</code>

::

::alert{type="infor"}

  <ul>
    <li>Nếu java không tìm thấy một hàm nạp chồng thích hợp thì nó sẽ đưa ra một thông báo lỗi</li>
    <li>Ta không thể sử dụng giá trị trả về của hàm để phân biệt sự khác nhau giữa 2 phương thức nạp chồng</li>
    <li>Không nên quá lạm dụng các phương thức nạp chồng vì trình biên dịch phải mất thời gian phán đoán để tìm ra hàm thích hợp, điều này đôi khi còn dẫn đến sai sót</li>
    <li>Khi gọi các hàm nạp chồng ta nên có lệnh chuyển kiểu tường minh để trình biên dịch tìm ra hàm phù hợp một cách nhanh nhất</li>
  <ul>
::
