---
title: "Định nghĩa và khai báo lớp"
description: "Lớp là khái niệm trọng tâm của lập trình hướng đối tượng, java là ngôn ngữ lập trình hướng đối tượng, một chương trình java gồm một tập các đối tượng, các đối tượng này phối hợp với nhau để tạo thành một ứng dụng hoàn chỉnh."
keywords:
  [
    "biến lớp trong java",
    "class là gì trong java",
    "class trong java là gì",
    "code lớp trong java",
    "các lớp trong java",
    "cách khai báo lớp",
    "cách viết lớp trong java",
    "khai báo lớp",
    "khởi tạo lớp trong java cơ bản",
    "khởi tạo lớp trong java fpt",
  ]
chapter:
  name: "Lập trình hướng đối tượng"
  slug: "chuong-03-lap-trinh-huong-doi-tuong"
category:
  name: "Java"
  slug: "java"
image: https://user-images.githubusercontent.com/29374426/130742965-1f138a2b-3612-4150-884c-fdd62de6c00e.png
position: 6
---

Lớp là khái niệm trọng tâm của lập trình hướng đối tượng, java là ngôn ngữ lập trình hướng đối tượng, một chương trình java gồm một tập các đối tượng, các đối tượng này phối hợp với nhau để tạo thành một ứng dụng hoàn chỉnh.

## Khái niệm lớp và đối tượng

Chắc các bạn vẫn nhớ môn sinh học chúng ta có học về các lớp như lớp thú, lớp bò sát, lớp chim,…

![khái niệm về lớp trong hướng đối tượng](https://user-images.githubusercontent.com/29374426/130742965-1f138a2b-3612-4150-884c-fdd62de6c00e.png)

Trong mỗi lớp đó có các tính chất, đặc điểm riêng như lớp thú gồm nhiều bộ, môi trường sinh sống đa dạng và là động vật hằng nhiệt còn lớp bò sát thì bao gồm 4 bộ, sống cả ở nước và ở cạn, và cũng là động vật hằng nhiệt,...

![khái niệm về lớp trong hướng đối tượng](https://user-images.githubusercontent.com/29374426/130743146-518e205e-6410-4040-b6ae-6c534eefdde5.png)

**Vậy thế nào được gọi là một lớp?**

Lớp các bạn hiểu đó là một khái niệm bao quát nói lên những đặc điểm chung nhất của các phần tử, các thành viên trong lớp đó.

**Còn thế nào là đối tượng?**

Đối tượng chính là một phần tử, một thành viên cụ thể nào đó trong lớp. Ví dụ như con chó ở nhà chúng ta là một đối tượng, đối tượng này thuộc vào lớp thú vì nó sẽ có những đặc điểm của lớp thú như là động vật hằng nhiệt, môi trường sông đa dạng,.... Mỗi đối tượng người ta cũng gọi là một thể hiện của lớp vì thông qua đối tượng đó chúng ta biết được những tính chất chung nhất của lớp.

![image](https://user-images.githubusercontent.com/29374426/130745801-ed5702c5-c481-4372-b6a3-394ad4b52e19.png)

## Khai báo lớp

Một lớp được định nghĩa theo mẫu sau:

```java
[public][abstract][final] class [<Tên lớp>]
  [extends <Tên lớp cha>] [implements <Tên giao diện>] {
  Các thuộc tính của lớp
  Các Phương thức của lớp
}
```

Sau đâu là ví dụ đơn giản định nghĩa lớp ngăn xếp

![image](https://user-images.githubusercontent.com/29374426/125044954-b208ce00-e0c6-11eb-8026-4c9fd59e7a29.png)

_Trong đó:_

- **public**: dùng để khai báo nếu muốn gói khác có thể sử dụng lớp này.
- **abstract** là bổ từ cho java biết đây là một lớp trừu tượng, do vậy ta không thể tạo ra một thể hiện của lớp này.
- **final** là bổ từ cho java biết đây là một lớp không thể kế thừa.
- **class** là từ khoá cho chương trình biết ta đang khai báo một lớp, ví dụ class _LopThu_ thì lớp này có tên là _LopThu_
- **extends** là từ khoá cho java biết lớp này này được kế thừa từ lớp khác
- **implements** là từ khoá cho java biết lớp này sẽ triển khai giao diện `Interfaces`, đây là một dạng tương tự như kế thừa bội của java.

<div class="note">
  <ul>
    <li>Thuộc tính của lớp là một biến có kiểu dữ liệu bất kỳ, nó có thể lại là một biến có kiểu là chính lớp đó</li>
    <li>Khi khai báo các thành phần của lớp (thuộc tính và phương thức) có thể dùng một trong các từ khoá private, public, protected để giứo hạn sự truy cập đến thành phần đó</li>
    <li>Các thành phần private chỉ có thể sử dụng được ở bên trong lớp, ta không thể truy cập vào các thành phần private từ bên ngoài lớp</li>
    <li>Các thành phần public có thể truy cập được cả bên trong lớp lẫn bên ngoài lớp.</li>
    <li>Các thành phần protected tương tự như các thành phần private, nhưng có thể truy cập được từ bất cứ lớp con nào kế thừa từ nó.</li>
    <li>Nếu một thành phần của lớp khi khai báo mà không sử dụng một trong 3 bổ từ protected, private, public thì sự truy cập là bạn bè, tức là thành phần này có thể truy cập được từ bất cứ lớp nào trong cùng gói với lớp đó.</li>
    <li>Các thuộc tính nên để mức truy cập private để đảm bảo tính dấu kín và lúc đó để bên ngoài phạm vi của lớp có thể truy cập được đến thành phần private này ta phải tạo ra các phương thức phương thức get và set.</li>
    <li>Các phương thức thường khai báo là public, để chúng có thể truy cập từ bất cứ đâu.</li>
    <li>Trong một tệp chương trình (hay còn gọi là một đơn vị biên dịch) chỉ có một lớp được khai báo là public, và tên lớp public này phải trùng với tên của tệp kể cả chữ hoa, chữ thường</li>
  </ul>
</div>

## Khai báo thuộc tính

Một ví dụ khai báo thuộc tính như sau:

```java
public class LopThu {
  private String moiTruongSong;
  private boolean laDongVatHangNhiet;
  ...
}
```

Trong lớp **LopThu** trên ta có thể tổng quát việc khai báo thuộc tính như sau:

```java
[Access Level] [Static] [Type]  [<Tên thuộc tính>];
```

_Trong đó:_

- **Access Level** có thể là một trong các từ `public`, `private`, `protected` hoặc có thể bỏ trống (protected), ý nghĩa của các bổ từ này được mô tả ở phần trên
- **Static** là từ khoá báo rằng đây là một thuộc tính lớp, nó là một thuộc tính sử dụng chung cho cả lớp, nó không là của riêng một đối tượng nào.
- **Type** là một kiểu dữ liệu nào đó
- **<Tên thuộc tính>** là tên của thuộc tính

<div class="note">
Ta phải phân biệt được việc khai báo như thế nào là khai báo thuộc tính, khai báo thế nào là khai báo biến thông thường? Câu trả lời là tất cả các khai báo bên trong thân của một lớp và bên ngoài tất cả các phương thức và hàm tạo thì đó là khai báo thuộc tính, khai báo ở những chỗ khác sẽ cho ta biến.
</div>

## Khai báo phương thức

Một ví dụ khai báo phương thức như sau:

```java
public class LopThu {
  private String moiTruongSong;
  private boolean laDongVatHangNhiet;


  private void noiXinChao() {
    System.out.println("Xin chào mọi người");
  }
}
```

Trong lớp **LopThu** trên ta có phương thức **noiXinChao** dùng để in ra dòng chứ **Xin chào mọi người** ra màn hình console

Chi tiết của phần khai báo phương thức chúng ta sẽ tìm hiểu ở bài sau nhé
