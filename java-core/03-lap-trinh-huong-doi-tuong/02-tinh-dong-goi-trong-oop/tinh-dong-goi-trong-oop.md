---
title: "Tính đóng gói trong OOP"
description: "Tính đóng gói trong java là kỹ thuật ẩn giấu thông tin không liên quan và hiện thị ra thông liên quan. Mục đích chính của đóng gói trong java là giảm thiểu mức độ phức tạp phát triển phần mềm"
keywords:
  [
    "tính đóng gói java",
    "tính đóng gói trong java",
    "tính đóng gói trong java book",
    "tính đóng gói trong java code",
    "tính đóng gói trong java cơ bản",
    "tính đóng gói trong java ebook",
    "tính đóng gói trong java fpt",
    "tính đóng gói trong java free",
    "tính đóng gói trong java hay",
  ]
chapter:
  name: "Lập trình hướng đối tượng"
  slug: "chuong-03-lap-trinh-huong-doi-tuong"
category:
  name: "Java"
  slug: "java"
image: https://user-images.githubusercontent.com/29374426/130181521-4a08856a-756f-46f4-94f4-6ff1a0a90f18.png
position: 2
---

Tính đóng gói trong java là kỹ thuật ẩn giấu thông tin không liên quan và hiện thị ra thông liên quan. Mục đích chính của đóng gói trong java là giảm thiểu mức độ phức tạp phát triển phần mềm.

### Tính đóng gói (Encapsulation)

Ví dụ đối với ô tô thì một số thuộc tính ở bên ngoài như xi nhan, đèn. bánh xe là những thuộc tính công khai (public) người khác xem được. nhưng đối với các thuộc tính bên trong như đồ đạc trong cốp xe thì bị giấu đi (private).

![Tính đóng gói (Encapsulation)](https://user-images.githubusercontent.com/29374426/130181521-4a08856a-756f-46f4-94f4-6ff1a0a90f18.png)

Các dữ liệu và phương thức có liên quan với nhau được đóng gói thành các lớp để tiện cho việc quản lý và sử dụng. Tức là mỗi lớp được xây dựng để thực hiện một nhóm chức năng đặc trưng của riêng lớp đó. Ngoài ra, đóng gói còn để che giấu một số thông tin và chi tiết cài đặt nội bộ để bên ngoài không thể nhìn thấy. Tính đóng gói được thể hiện qua [cấp độ truy cập trong java](/bai-viet/java/cap-do-truy-cap-trong-java)

## Lợi ích của đóng gói trong java

- Bạn có thể tạo lớp read-only hoặc write-only bằng việc cài đặt phương thức setter hoặc getter.
- Bạn có thể kiểm soát đối với dữ liệu. Giả sử bạn muốn đặt giá trị của id chỉ lớn hơn 100 bạn có thể viết logic bên trong lớp setter.

<div class="example">Ví dụ tính đóng gói trong java</div>

Hãy xem ví dụ sau về đóng gói trong java với một lớp chỉ có một trường và các phướng thức setter và getter của nó.

```java
public class Person {
    // khai báo các thuộc tính của đối tượng là private
    private String cmnd;
    private String hoTen;

    // tạo các phương thức getter/setter
    // 2 phương thức getCmnd() và getHoTen() là phương thức getter
    // dùng để trả về số chứng minh nhân dân và họ tên của đối tượng
    // và kiểu trả về của hai phương thức này tương ứng với kiểu dữ liệu của thuộc tính
    // 2 phương thức setCmnd() và setHoTen() là phương thức setter
    // dùng để gán giá trị cho thuộc tính chứng minh nhân dân và họ tên của đối tượng
    // trong đó tham số truyền vào của 2 phương thức này được gọi là tham số (biến cục bộ)
    // và có kiểu dữ liệu tương ứng với kiểu dữ liệu của thuộc tính (biến đối tượng)
    public String getCmnd() {
        return cmnd;
    }

    // this là từ khóa có ý nghĩa là một tham chiếu đặc biệt
    // chiếu tới đối tượng chủ của phương thức hiện hành
    // this có thể được dùng để truy cập biến đối tượng (instance variable)
    // hoặc gọi phương thức đối với đối tượng hiện hành.
    // Thông thường, công dụng này của this chỉ có ích
    // khi tên biến đối tượng bị trùng với tham số (biến cục bộ - local variable) của phương thức
    public void setCmnd(String cmnd) {
        this.cmnd = cmnd;
    }
    public String getHoTen() {
        return hoTen;
    }
    public void setHoTen(String hoTen) {
        this.hoTen = hoTen;
    }

}

package vidu;

public class TestPerson {

    public static void main(String[] args) {
        Person person = new Person();

        // gán giá trị họ tên cho đối tượng person vừa tạo thông qua setHoTen()
        // và gán số chứng minh nhân dân thông qua setCmnd()
        person.setHoTen("Thaycacac");
        person.setCmnd("123456");

        // truy cập đến tên của đối tượng person thông qua phương thức getHoten()
        // và số chứng minh nhân dân thông qua phương thức getCmnd()
        System.out.println("Tên: " + person.getHoTen() + ", CMND: " + person.getCmnd());
    }

}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>Tên: Thaycacac, CMND: 123456</code>
  </div>
</div>
