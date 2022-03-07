---
title: "String (chuỗi) trong Java"
description: "String trong java là một object immutable, nghĩa là bạn khônng thể thay đổi giá trị của String khi nó đã được khởi tạo."
keywords:
  [
    "biến string trong java",
    "chuyen doi string sang int trong java",
    "chuyen int thanh string trong java",
    "chuyển int sang string trong java",
    "chuyển kiểu date sang string trong java",
    "chuyển string sang date trong java",
    "chuyển string thành date trong java",
    "chuyển string thành int trong java",
    "chuyển từ double sang string trong java",
    "chuỗi string trong java",
    "code string trong java",
    "compare string trong java",
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
image: https://i.ytimg.com/vi/r3DBIDyzLUI/maxresdefault.jpg
position: 23
---

String là một chuỗi các ký tự kết hợp lại. Ví dụ "thaycacac" là một chuỗi gồm 9 ký tự 't', 'h', 'a', 'y', 'c', 'a', 'c', 'a', 'c' kết hợp lại.

String trong java là một **object immutable**, nghĩa là bạn khônng thể thay đổi giá trị của String khi nó đã được khởi tạo.

## Khởi tạo String trong java

Trong java chúng ta có 2 cách để tạo một chuỗi

- Chuỗi ký tự
- Sử dụng từ khoá `new`

### Tạo string bằng một chuỗi ký tự

<div class="example">khởi tạo 2 chuỗi string1 và string2 với giá trị giống nhau</div>

```java
public class Main {
  public static void main(String[] args) {
    String string1 = "Thaycacac";
    String string2 = "Thaycacac";
  }
}
```

Sau khi khởi tạo string1 thì chuỗi "Thaycacac" sẽ được lưu vào vùng nhớ heap tại `string pool`. Đến khi khởi tạo khởi string2, việc đầu tiên là tìm kiếm trong `string2`, nếu đã có chuỗi tương tự thì sẽ không cần khởi tạo thêm mà gán thẳng cho string2, nếu không thì mới bắt đầu khởi tạo.

Mình sẽ giải thích đoạn code này sẽ diễn ra như sau:

- **Bước 1:** string1 = "Thaycacac" => JVM thấy rằng trong `string pool` chưa có object string nào có giá trị tương tự cho nên trình biên dịch sẽ tiến hành tạo ra object string (`new String("Thaycacac")`) và gán cho string1.
- **Bước 2:** string2 = "Thaycacac" => JVM thấy rằng trong `string pool` đã có sẵn object string có giá trị tương tự nên trình biên dịch sẽ gán thẳng cho string2 mà không khởi tạo nữa.

### Khởi tạo string bằng từ khoá new

Đây là cách chính thống đây các bạn, sử dụng từ khoá `new`. Lưu ý nếu như chúng ta khởi tạo chuỗi bằng từ khoá `new` thì trình biên dịch sẽ không tiến hành kiểm tra trong `string pool` có tồn tại object nào có giá trị như vậy chưa mà nó sẽ tiến hành khởi tạo cả 2 object cho dù nó có cùng giá trị nhé.

```java
public class Main {
  public static void main(String[] args) {
    String str1 = new String("thaycacac");
    String str2 = new String("thaycacac");
  }
}
```

Với đoạn code trên thì chúng ta sẽ được 2 object riêng biệt không liên quan gì nhau hết nha các bạn

## String là object immutable

Như đã đề cập ở trên `object immutable` thì chúng ta sẽ không thể thay đổi khi nó đã được khỏi tạo. Chúng ta cùng xem ví dụ sau:

<div class="example"></div>

```java
public class Main {
  public static void main(String[] args) {
    String str = "hello";
    System.out.println(str);
    str = "hello thaycacac";
    System.out.println(str);
  }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>hello</code><br/>
    <code>hello thaycacac</code>
  </div>
</div>

Sao nói rằng object string không thể thay đổi sau khi nó đã được khởi tạo thì đáng lẽ chúng ra phải nhận output là **hello** chứ nhỉ!

Thật ra là khi bạn gán str = "hello" trình biên dịch sẽ tiến hành khởi tạo object string và gán cho str. Đến khi bạn lại gán str = "hello thaycacac" như đúng bản chất nó không thay đổi giá trị object "hello" mà nó sẽ tạo tạo một object mới với giá trị chuỗi là "hello thaycacac" và gán lại cho str. Đó là lý do chúng ta có output như trên.

## Các hàm thường sử dụng của String

**int length():** Trả về số lượng ký tự trong chuỗi

```java
String s = "kungfutech.edu.vn";
System.out.println(s.charAt(10)); // return "."
```

**String substring(int i):** Trả về chuỗi con bắt đầu tại vị trí i đến cuối chuỗi

```java
String s = "kungfutech.edu.vn";
System.out.println(s.substring(10)); // return "edu.vn"
```

**String substring(int begin, int end):** Trả về chuỗi con từ vị trí begin đến end

```java
String s = "kungfutech.edu.vn";
System.out.println(s.substring(10, 14)); // return "edu"
```

**String concat(String s):** Nối chuối s vào cuối chuỗi

```java
String s = "kungfutech.edu.vn";
System.out.println(s.indexOf("edu")); // return 11
```

**indexOf(String str, int fromIndex):** Trả về vị trí xuất hiện đầu tiên của str bắt đầu từ vị trí `fromIndex`

```java
String s = "kungfutech.edu.vn";
System.out.println(s.indexOf("h", 5)); // return 9
```

**lastIndexOf(String str)**: Trả về vị trí xuất hiện cuối cùng của str

```java
String s = "kungfutech.edu.vn";
System.out.println(s.lastIndexOf("g")); // return 15
```

**lastIndexOf(String str, int fromIndex):** Trả về vị trí cuối cùng xuất hiện của chuỗi str trong khoảng 0 đến fromIndex

```java
String s = "kungfutech.edu.vn";
System.out.println(s.lastIndexOf("h", 5)); // return 9
```

**boolean equals(Object obj):** So sánh với string obj

```java
String s = "kungfutech.edu.vn";
System.out.println(s.equals("kungfutech.edu.vn")); // return true
```

**boolean equalsIgnoreCase(String str):** So sánh với chuỗi str, bỏ qua ký tự hoa thường

```java
System.out.println(s.equalsIgnoreCase("kungfutech.EDU.VN")); // return true
System.out.println(s.equalsIgnoreCase("Kungfutech.edu.vn")); // return true
```

**String toLowerCase():** Chuyển tất cả các ký tự thành ký tự thường.

```java
String s = "KUNGFUTECH.EDU.VN";
System.out.println(s.toLowerCase()); // return "kungfutech.edu.vn"
```

**String toUpperCase():** Chuyển tất cả các ký tự thành ký tự hoa

```java
String s = "kungfutech.edu.vn";
System.out.println(s.toUpperCase()); // return "KUNGFUTECH.EDU.VN"
```

**String trim():** Xoá các khoảng trắng ở đầu và cuối chuỗi

```java
String s = "  kungfutech.edu.vn  ";
System.out.println(s.trim()); // return "kungfutech.edu.vn"
```

**String replace(char old, char new):** thay thế các ký tự old thành new

```java
String s = "kungfutech.edu.vn";
System.out.println(s.replace("g", "*")); // return "kun*futech.edu.vn"
```

Ở trên là các method chúng ta thường sử dụng trong `String`, ngoài ra nó còn có rất nhiều phương thức khác nữa nhé.
