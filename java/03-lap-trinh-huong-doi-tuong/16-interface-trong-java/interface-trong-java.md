---
title: "Interface trong Java"
description: "Interface trong Java là một bản thiết kế của một lớp, nó chỉ có các phương thức trừu tượng"
chapter:
  name: "Lập trình hướng đối tượng"
  slug: "chuong-03-lap-trinh-huong-doi-tuong"
category:
  name: "Java"
  slug: "java"
image: https://user-images.githubusercontent.com/29374426/131247022-a3c4f998-873e-4274-a244-83f4913ca5aa.png
position: 16
---

Một giao diện (Interface) trong Java là một bản thiết kế của một lớp, nó chỉ có các phương thức trừu tượng. Interface là một kỹ thuật để thu được tính trừu tượng hoàn toàn và đa kế thừa trong Java. Nó không thể được khởi tạo giống như lớp trừu tượng.

Một Interface trong Java là một tập hợp các phương thức trừu tượng (abstract). Một class khi triển khai (implement) một interface sẽ kế thừa các phương thức của interface.

![image](https://user-images.githubusercontent.com/29374426/131247022-a3c4f998-873e-4274-a244-83f4913ca5aa.png)

## Interface trong Java là gì

Từ khoá interface đã đưa khái niệm abstract đi xa thêm một bước nữa. Ta có thể nghĩ nó như là một lớp abstract **"thuần tuý"**, nó cho phép ta tạo ra một lớp thuần ảo, lớp này chỉ gồm tập các giao diện cho các lớp muốn dẫn xuất từ nó, một interface cũng có thể có các trường, tuy nhiên java tự động làm các trường này thành [static](/bai-viet/java/tu-khoa-static-trong-java) và [final](/bai-viet/java/tu-khoa-final-trong-java)

Để tạo ra một interface, ta dùng từ khoá interface thay vì từ khoá `class`. Một interface gồm có 2 phần: phần khai báo và phần thân:

- Phần khai báo cho biết một số thông tin như: tên của interface, nó có kế thừa từ một giao diện khác hay không.
- Phần thân chứa các khai báo hằng, khai báo phương thức. Giống như một lớp ta cũng có thể thêm bổ từ public vào trước định nghĩa của interface.

<div class="example">ví dụ dưới đây Printable Interface chỉ có một phương thức, trình triển khai của nó được cung cấp bởi lớp A.</div>

```java
interface printable {
  void print();
}

class A6 implements printable {
    public void print() {
        System.out.println("In");
    }

    public static void main(String args[]){
        A6 obj = new A6();
        obj.print();
    }
}
```

Khi ghi đè các phương thức được định nghĩa trong interface:

- Các phần kiểm tra exception không nên được khai báo trong phương thức triển khai (implements), thay vào đó nó nên được khai báo trong phương thức interface hoặc các lớp phụ được khai báo bởi phương thức interface.
- Kiểu trả về của phương thức interface và khi ghi đè phương thức (overriding method) phải giống nhau.
- Một lớp triển khai chính nó có thể là `abstract` và vì thế các phương thức interface không cần được triển khai.

Khi triển khai interface:

- Một lớp có thể triển khai một hoặc nhiều interface tại một thời điểm.
- Một lớp chỉ có thể kế thừa một lớp khác, nhưng được triển khai nhiều interface.
- Một interface có thể kế thừa từ một interface khác, tương tự cách một lớp có thể kế thừa lớp khác.

| Một interface tương tự với một class                                                                              | Một interface khác với một class                                                |
| ----------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------- |
| Một interface được viết trong một file với định dạng .java, với tên của interface giống tên của file.             | Bạn không thể khởi tạo một interface                                            |
| Bytecode của interface được lưu trong file có định dạng .class.                                                   | Một interface không chứa bất cứ hàm Contructor nào.                             |
| Khai báo interface trong một package, những file bytecode tương ứng cũng có cấu trúc thư mục có cùng tên package. | Tất cả các phương thức của interface đều là abstract.                           |
|                                                                                                                   | Một interface không thể chứa một trường nào trừ các trường vừa static và final. |
|                                                                                                                   | Một interface không thể kế thừa từ lớp, nó được triển khai bởi một lớp.         |
|                                                                                                                   | Một interface có thể kế thừa từ nhiều interface khác.                           |

## Đa kế thừa trong Java bởi Interface

Nếu một lớp triển khai (implements) nhiều interface, hoặc một Interface kế thừa từ nhiều Interface khác thì đó là đa kế thừa.

```java
interface Printable {
    void print();
}

interface Showable{
    void show();
}

class A4 implements Printable, Showable {

    public void print() {
        System.out.println("In");
    }
    public void show() {
        System.out.println("Hiển thị");
    }

    public static void main(String args[]){
        A4 obj = new A4();
        obj.print();
        obj.show();
    }
}
```

## Interface kế thừa Interface trong Java

Một Interface cũng có thể kế thừa từ các Interface khác.

```java
interface Printable{
    void print();
}
interface Showable extends Printable{
    void show();
}
class A3 implements Showable{

    public void print() {
        System.out.println("In");
    }
    public void show() {
        System.out.println("Hiển thị");
    }

    public static void main(String args[]){
        A3 obj = new A3();
        obj.print();
        obj.show();
    }
}
```

## Marker Interface trong Java là gì?

Một Interface mà không có thành viên nào thì được gọi là Marker Interface. Ví dụ: `Serializable`, `Cloneable`, `Remote`, … Chúng được sử dụng để cung cấp một số thông tin thiết yếu tới JVM để mà JVM có thể thực hiện một số hoạt động hữu ích.

```java
public interface Serializable {
}
```

## Interface lồng nhau trong Java

Một Interface có thể có Interface khác, đó là lồng Interface.

```java
interface printable{
    void print();
    interface MessagePrintable{
       void msg();
    }
}
```
