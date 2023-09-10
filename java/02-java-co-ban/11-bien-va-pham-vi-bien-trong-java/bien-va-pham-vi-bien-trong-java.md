---
title: "Biến và phạm vi biến trong Java"
description: "Trong java, biến là tên của vùng nhớ được lưu trong bộ nhớ stack. Có 3 kiểu biến trong java, bao gồm biến cục bộ (hay còn gọi là biến local), biến toàn cục (biến instance) và biến tĩnh(biến static)."
chapter:
  name: "Nhập môn Java"
  slug: "chuong-02-nhap-mon-java"
category:
  name: "Java"
  slug: "java"
image: https://user-images.githubusercontent.com/29374426/126464912-683c218b-737b-4076-abaa-6b6e406b8121.png
position: 11
---

Trong java, biến là một liên kết tới một vị trí trên bộ nhớ (memory) để chứa dữ liệu. Có 3 kiểu biến trong java, bao gồm biến cục bộ (hay còn gọi là biến local), biến toàn cục (biến instance) và biến tĩnh(biến static).

- Giá trị trên bộ nhớ mà biến liên kết tới chính là giá trị của biến.
- Kiểu dữ liệu của biến cũng chính là kiểu dữ liệu lưu trên bộ nhớ đó.

![bien-va-pham-vi-bien-trong-java](https://user-images.githubusercontent.com/29374426/126464912-683c218b-737b-4076-abaa-6b6e406b8121.png)

## Khai báo biến

Cú pháp khai báo biến:

```java
kieu_du_lieu ten_bien = gia_tri;
```

_Trong đó:_

- **kieu_du_lieu**: là kiểu dữ liệu mà biến có thể lưu trữ (kiểu số, kiểu văn bản…) tương ứng với int, long, String… trong Java
- **ten_bien** là tên của biến, tên biến là một xâu kí tự được đặt theo quy tắc đặt tên của java
- **InitValue** là giá trị khởi tạo cho biến, đây là phần tuỳ chọn, nếu bỏ qua phần này thì giá trị ban đầu của biến được khởi tạo giá trị mặc định. Ví dụ kieu_du_lieu là `int` thì `gia_tri` phải là kiểu số nguyên và nằm trong phạm vi từ -2,147,483,648 đến 2,147,483,647

::alert{type="infor"}

<p>Nếu cần khai báo nhiều biến có cùng một kiểu dữ liệu ta có thể đặt các khai báo các biến trên một dòng, các biến này được phân cách nhau bởi dấu phảy. Java sẽ xử lý các biến không được khởi đầu giá trị như sau:</p>
  <ul>
    <li>Giá trị 0 cho kiểu dữ liệu số</li>
    <li>false cho kiểu logic</li>
    <li>Kí tự null (mã 0) cho kí tự</li>
    <li>Giá trị null cho kiểu đối tượng</li>
    <li>Đối với các biến cục bộ thì biến không được khới gán giá trị mặc định, tuy nhiên Java sẽ báo lỗi nếu ta sử dụng một biến chưa được nhận giá trị</li>
  </ul>
::

## Phạm vi Biến

Mỗi biến được khai báo ra có một phạm vi hoạt động, phạm vi của biến là nơi mà biến có thể được truy cập, điều này xác định cả tính thấy được và thời gian sống của biến

![bien-va-pham-vi-bien-trong-java](https://user-images.githubusercontent.com/29374426/124429210-caf84300-dd97-11eb-8136-6282d64bb1ad.png)

### Biến local trong java

- Biến cục bộ được khai báo trong các phương thức, hàm `contructor` hoặc trong các block.
- Biến cục bộ được tạo bên trong các phương thức, `contructor`, block và sẽ bị phá hủy khi kết thúc các phương thức, `contructor` và block.
- Các biến cục bộ sẽ nằm trên vùng bộ nhớ stack của bộ nhớ.
- Bạn cần khởi tạo giá trị mặc định cho biến cục bộ trước khi có thể sử dụng.
- Không được sử dụng `access modifier` khi khai báo biến cục bộ.

<div class="example">Khởi tạo biến local:</div>

```java
public class Bien {

    public void sayHello() {
        int n = 10; // Đây là biến local
        System.out.println("Gia tri cua n la: " + n);
    }

    public static void main(String[] args) {
        Bien bienLocal = new Bien();
        bienLocal.sayHello();
    }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>Giá trị của n là: 10</code>
  </div>
</div>

```java
public class Bien {

    public void sayHello() {
        int n;                 // Đây là biến local
        System.out.println("Gia tri cua n la: " + n);
    }

    public static void main(String[] args) {
        Bien bienLocal = new Bien();
        bienLocal.sayHello();
    }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>Exception in thread "main" java.lang.Error: Unresolved compilation problem: The local variable n may not have been initialized</code>
  </div>
</div>

### Biến biến instance (biến toàn cục) trong java

- Biến instance được khai báo trong một lớp(class), bên ngoài các phương thức, constructor và các block.
- Biến instance được lưu trong bộ nhớ heap.
- Biến instance được tạo khi một đối tượng được tạo bằng việc sử dụng từ khóa `new` và sẽ bị phá hủy khi đối tượng bị phá hủy.
- Biến instance có thể được sử dụng bởi các phương thức, `constructor`, block, ... Nhưng nó phải được sử dụng thông qua một đối tượng cụ thể.
- Biến instance có giá trị mặc định phụ thuộc vào kiểu dữ liệu của nó.
- Bên trong class mà bạn khai báo biến instance, bạn có thể gọi nó trực tiếp bằng tên khi sử dụng ở khắp nới bên trong class đó.
- Bạn được phép sử dụng `access modifier` khi khai báo biến instance, mặc định là `default`.

<content-example />

```java
public class SinhVien {
    // biến instance "ten" kiểu String, có giá trị mặc định là null
    public String ten;

    // biến instance "tuoi" kiểu Integer, có giá trị mặc định là 0
    private int tuoi;

    // sử dụng biến ten trong một constructor
    public Sinhvien(String ten) {
        this.ten = ten;
    }

    // sử dụng biến tuoi trong phương thức setTuoi
    public void setTuoi(int tuoi) {
        this.tuoi = tuoi;
    }

    public void showStudent() {
        System.out.println("Ten  : " + ten);
        System.out.println("Tuoi : " + tuoi);
    }

    public static void main(String args[]) {
        Sinhvien sv = new Sinhvien("Thaycacac");
        sv.setTuoi(21);
        sv.showStudent();
    }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>Ten  : Thaycacac</code><br/>
    <code>Tuoi : 21</code>
  </div>
</div>

### Biến static trong java

- Biến static được khai báo trong một class với từ khóa `static`, phía bên ngoài các phương thức, `constructor` và block.
- Sẽ chỉ có duy nhất một bản sao của các biến static được tạo ra, dù bạn tạo bao nhiêu đối tượng từ lớp tương ứng.
- Biến static được lưu trữ trong bộ nhớ static riêng.
- Biến static được tạo khi chương trình bắt đầu chạy và chỉ bị phá hủy khi chương trình dừng.
- Giá trị mặc định của biến static phụ thuộc vào kiểu dữ liệu bạn khai báo tương tự biến instance.
- Biến static được truy cập thông qua tên của class chứa nó, với cú pháp: `TenClass.tenBien`.
- Trong class, các phương thức sử dụng biến static bằng cách gọi tên của nó khi phương thức đó cũng được khai báo với từ khóa `static`.

<content-example />

```java
public class Sinhvien {
    // biến static 'ten'
    public static String ten = "Thaycacac";

    // biến static 'tuoi'
    public static int tuoi = 21;

    public static void main(String args[]) {
        // Sử dụng biến static bằng cách gọi trực tiếp
        System.out.println("Ten : " + ten);

        // Sử dụng biến static bằng cách gọi thông qua tên class
        System.out.println("Ten : " + Sinhvien.tuoi);
    }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>Ten  : Thaycacac</code><br/>
    <code>Tuoi : 21</code>
  </div>
</div>
