---
title: "Lớp String trong Java"
description: "Bài này chúng ta sẽ tìm hiểu về Lớp StringTokenizer, tự học lập trình java, chia sẻ kiến thức về java"
chapter:
  name: "Lập trình hướng đối tượng"
  slug: "chuong-03-lap-trinh-huong-doi-tuong"
category:
  name: "Java"
  slug: "java"
image: https://user-images.githubusercontent.com/29374426/132494584-b9f248b5-258d-4760-9d5a-150a366f05e8.png
position: 23
---

Việc xử lý các xâu ký tự trong Java được hỗ trợ bởi hai lớp **String** và **StringBuffer**. Lớp **String** dùng cho những xâu ký tự bất biến, nghĩa là những xâu chỉ đọc và sau khi được khởi tạo giá trị thì nội dung bên trong xâu không thể thay đổi được. Lớp **StringBuffer** được sử dụng đối với những xâu ký tự động, tức là có thể thay đổi được nội dung bên trong của xâu. Trong bài viết này, chúng ta sẽ tìm hiểu về cách khởi tạo một đối tượng `String`, các phương thức quan trọng của lớp `String`, và ví dụ cụ thể trong ngôn ngữ Java.

![image](https://user-images.githubusercontent.com/29374426/132494584-b9f248b5-258d-4760-9d5a-150a366f05e8.png)

## Khởi tạo một đối tượng String

Để khởi tạo một đối tượng `String` trong Java, bạn có thể sử dụng các constructor sau:

1. `String()`: Khởi tạo một đối tượng `String` trống.

2. `String(String s)`: Khởi tạo một đối tượng `String` từ một chuỗi có sẵn.

3. `String(char[] ch)`: Khởi tạo một đối tượng `String` từ một mảng ký tự.

4. `String(char[] ch, int startIndex, int length)`: Khởi tạo một đối tượng `String` từ một phần của mảng ký tự, bắt đầu từ chỉ số `startIndex` và có độ dài `length`.

Ví dụ:

```java
String str1 = new String(); // str1 chứa một chuỗi rỗng.

String str2 = new String("Hello World"); // str2 chứa "Hello World".

char[] charArray = {'A', 'B', 'C', 'D', 'E'};
String str3 = new String(charArray); // str3 chứa "ABCDE".

String str4 = new String(charArray, 0, 2); // str4 chứa "AB".
```

Bạn cũng có thể nối các chuỗi bằng cách sử dụng toán tử `+` hoặc phương thức `concat()`.

```java
String strFirst = "Charlie";
String strSecond = "Chaplin";
String strFinal = strFirst + strSecond; // Nối chuỗi bằng toán tử +
String strConcat = strFirst.concat(strSecond); // Nối chuỗi bằng phương thức concat()
```

## Các phương thức của lớp String

### char charAt(int index)

Phương thức `charAt(int index)` trả về ký tự ở vị trí `index` trong chuỗi.

```java
String name = "Java Language";
char ch = name.charAt(5); // chứa ký tự 'L'
```

### boolean startsWith(String prefix)

Phương thức `startsWith(String prefix)` kiểm tra xem chuỗi có bắt đầu bằng chuỗi con `prefix` không và trả về `true` nếu có, ngược lại trả về `false`.

```java
String strName = "Java Language";
boolean startsWithJava = strName.startsWith("Java"); // true
```

### boolean endsWith(String suffix)

Phương thức `endsWith(String suffix)` kiểm tra xem chuỗi có kết thúc bằng chuỗi con `suffix` không và trả về `true` nếu có, ngược lại trả về `false`.

```java
String strName = "Java Language";
boolean endsWithJava = strName.endsWith("Java"); // false
```

### String toUpperCase() và String toLowerCase()

Phương thức `toUpperCase()` trả về một bản sao của chuỗi với tất cả các ký tự được chuyển thành chữ hoa, trong khi `toLowerCase()` trả về một bản sao với tất cả các ký tự được chuyển thành chữ thường.

```java
String lower = "Good Morning";
String upper = "JAVA";
String upperCaseString = lower.toUpperCase(); // "GOOD MORNING"
String lowerCaseString = upper.toLowerCase(); // "java"
```

### int indexOf(String subString)

Phương thức `indexOf(String subString)` trả về vị trí đầu tiên của chuỗi con `subString` trong chuỗi gốc, hoặc -1 nếu không tìm thấy.

```java
String day = "Sunday";
int index1 = day.indexOf('n');     // 2
int index2 = day.indexOf("Sun");   // 0
int index3 = day.indexOf('z', 2);  // -1
```

### String trim()

Phương thức `trim()` loại bỏ các khoảng trắng ở đầu và cuối chuỗi.

```java
String space = "   Spaces   ";
String trimmed = space.trim(); // "Spaces"
```

### boolean equals(String anotherString)

Phương thức `equals(String anotherString)` so sánh hai chuỗi để kiểm tra xem chúng có giống nhau hay không.

```java
String name1 = "Java";
String name2 = "JAVA";
boolean areEqual = name1.equals(name2); // false
```

## Phương thức `valueOf()`

Lớp `String` cung cấp phương thức `valueOf()` để chuyển đổi các giá trị khác thành chuỗi:

```java
String stringValue = String.valueOf(123); // "123"
String booleanValue = String.valueOf(true); // "true"
String charValue = String.valueOf('A'); // "A"
```

Phương thức `valueOf()` cho phép bạn chuyển đổi số nguyên, số thực, boolean, ký tự và các đối tượng thành chuỗi.
