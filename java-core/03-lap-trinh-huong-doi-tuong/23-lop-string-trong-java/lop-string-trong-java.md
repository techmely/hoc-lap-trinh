---
title: "Lớp String trong Java"
description: "Bài này chúng ta sẽ tìm hiểu về Lớp StringTokenizer, tự học lập trình java, chia sẻ kiến thức về java"
keywords:
  [
    "class string java",
    "hàm string trong java",
    "lớp chuỗi trong java",
    "lớp string trong java",
    "lớp string trong java là",
    "public class trong java",
    "string class trong java fpt",
    "string class trong java free",
  ]
chapter:
  name: "Lập trình hướng đối tượng"
  slug: "chuong-03-lap-trinh-huong-doi-tuong"
category:
  name: "Java"
  slug: "java"
image: https://user-images.githubusercontent.com/29374426/132494584-b9f248b5-258d-4760-9d5a-150a366f05e8.png
position: 23
---

Việc xử lý các xâu ký tự trong Java được hỗ trợ bởi hai lớp **String** và **StringBuffer**. Lớp **String** dùng cho những xâu ký tự bất biến, nghĩa là những xâu chỉ đọc và sau khi dược khởi tạo giá trị thì nội dung bên trong xâu không thể thay đổi được. Lớp **StringBuffer** được sử dụng đối với những xâu ký tự động, tức là có thể thay đổi được nội dung bên trong của xâu.

![image](https://user-images.githubusercontent.com/29374426/132494584-b9f248b5-258d-4760-9d5a-150a366f05e8.png)

## Khởi tạo một lớp String

Chuỗi là một dãy các ký tự. Lớp String cung cấp các phương thức để thao tác với các chuỗi. Nó cung cấp các phương thức khởi tạo (constructor) khác nhau:

```java
String str1 = new String(); // str1 chứa một chuỗi rống.

String str2 = new String("Hello World"); // str2 chứa "Hello World"

char ch[] = {'A','B','C','D','E'};
String str3 = new String(ch); // str3 chứa "ABCDE"

String str4 = new String(ch,0,2); // str4 chứa "AB" vì 0- tính từ ký tự bắt đầu, 2- là số lượng ký tự kể từ ký tự bắt đầu.
```

Toán tử "+" được sử dụng để cộng chuỗi khác vào chuỗi đang tồn tại. Toán tử "+" này được gọi như là **nối chuỗi**. Ở đây, nối chuỗi được thực hiện thông qua lớp **StringBuffer**. Chúng ta sẽ thảo luận về lớp này trong phần sau. Phương thức `concat()` của lớp String cũng có thể thực hiện việc nối chuỗi. Không giống như toán tử `+`, phương thức này không thường xuyên nối hai chuỗi tại vị trí cuối cùng của chuỗi đầu tiên. Thay vào đó, phương thức này trả về một chuỗi mới, chuỗi mới đó sẽ chứa giá trị của cả hai. Điều này có thể được gán cho chuỗi đang tồn tại.

<content-example />

```java
String strFirst, strSecond, strFinal; StrFirst = "Charlie";

StrSecond = "Chaplin";

// bằng cách sử dụng phương thức concat() để gán với một chuỗi đang tồn tại.

StrFinal = strFirst.concat(strSecond);
```

Phương thức `concat()` chỉ làm việc với hai chuỗi tại một thời điểm.

## Các phương thức của lớp String

- `char charAt(int index)`: Phương thức này trả về một ký tự tại vị trí index trong chuỗi.

<content-example />

```java
String name = new String("Java Language"); char ch = name.charAt(5);
```

Biến "ch" chứa giá trị "L", từ đó vị trí các số bắt đầu từ 0.

- `boolean startsWith(String s)`: Phương thức này trả về giá trị kiểu logic (Boolean), phụ thuộc vào chuỗi có bắt đầu với một chuỗi con cụ thể nào đó không

<content-example />

```java
String strname = "Java Language";
boolean flag = strname.startsWith("Java");
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>true</code>
    </div>
</div>

- `boolean endsWith(String s)`: Phương thức này trả về một giá trị kiểu logic (boolean), phụ thuộc vào chuỗi kết thúc bằng một chuỗi con nào đó không

<content-example />

```java
String strname = "Java Language";
boolean flag = strname.endsWith("Java");
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>false</code>
    </div>
</div>

- `String copyValueOf()`: Phương thức này trả về một chuỗi được rút ra từ một mảng ký tự được truyền như một đối số. Phương thức này cũng lấy hai tham số nguyên. Tham số đầu tiên chỉ định vị trí từ nơi các ký tự phải được rút ra, và tham số thứ hai chỉ định số ký tự được rút ra từ mảng

<content-example />

```java
char name[] = {'L','a','n','g','u','a','g','e'};
String subname = String .copyValueOf(name,5,2);
```

Bây giờ biến "subname" chứa chuỗi "ag".

- `char [] toCharArray()`: Phương thức này chuyển chuỗi thành một mảng ký tự.

<content-example />

```java
String text = new String("Hello World");
char textArray[] = text.toCharArray();
```

- `int indexOf(String sunString)`: Phương thức này trả về thứ tự của một ký tự nào đó, hoặc một chuỗi trong phạm vi một chuỗi. Các câu lệnh sau biểu diễn các cách khác nhau của việc sử dụng hàm.

<content-example />

```java
String day = new String("Sunday"); int index1 = day.indexOf('n');
//chứa 2
int index2 = day.indexOf('z',2);

//chứa –1 nếu "z" không tìm thấy tại vị trí 2.

int index3 = day.indexOf("Sun");
//chứa mục 0
```

- `String toUpperCase()`: Phương thức này trả về chữ hoa của chuỗi.

<content-example />

```java
String lower = new String("good morning");
System.out.println("Uppercase: "+lower.toUpperCase( ));
```

- `String toLowerCase()`: Phương thức này trả về chữ thường của chuỗi.

<content-example />

```java
String upper = new String("JAVA");
System.out.println("Lowercase: "+upper.toLowerCase( ));
```

- `String trim()`: Phương thức này cắt bỏ khoảng trắng hai đầu chuỗi. Hãy thử đoạn mã sau để thấy sự khác nhau trước và sau khi cắt bỏ khoảng trắng.

<content-example />

```java
String space = new String("Spaces");
System.out.println(space);
System.out.println(space.trim()); //Sau khi cắt bỏ khoảng trắng
```

- `boolean equals(String s)`: Phương thức này so sánh nội dung của hai đối tượng chuỗi

<content-example />

```java
String name1 = "Java", name2 = "JAVA";
boolean flag = name1.equals(name2);
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>false</code>
  </div>
</div>

- `valueOf()`: Được nạp chồng để cho phép chuyển một giá trị thành xâu

<content-example />

```java
static String valueOf(Object obj)//Chuyển một đối tượng thành xâu, bẳng cách gọi đến phương thức toString của đối tượng obj
static String valueOf(char[] characters)//Chuyển mảng các ký tự thành xâu. static String valueOf(boolean b)//Chuyển một giá trị logic thành xâu, xâu nhận được là "true" hoặc "false" tương ứng với giá trị true hoặc false của b
static String valueOf(char c)//Chuyển kí tự thành xâu
static String valueOf(int i)//chuyển một số nguyên thành xâu static String valueOf(long l)//Chuyển một giá trị long thành xâu static String valueOf(float f)//chuyển một giá trị float thành xâu
static String valueOf(double d)//chuyển một giá trị double thành xâu
```
