---
title: "Lớp StringTokenizer trong Java"
description: "Bài này chúng ta sẽ tìm hiểu về Lớp StringTokenizer, một lớp StringTokenizer có thể sử dụng để tách một chuỗi thành các phần tử (token) nhỏ hơn"
chapter:
  name: "Lập trình hướng đối tượng"
  slug: "chuong-03-lap-trinh-huong-doi-tuong"
category:
  name: "Java"
  slug: "java"
image: https://user-images.githubusercontent.com/29374426/132615693-8f5ee9cf-9046-4f78-bffc-6f59a5312a82.png
position: 25
---

Một lớp **StringTokenizer** có thể sử dụng để tách một chuỗi thành các phần tử (token) nhỏ hơn. Ví dụ, mỗi từ trong một câu có thể coi như là một token. Tuy nhiên, lớp **StringTokenizer** đã đi xa hơn việc phân tách các từ trong câu. Để tách ra các thành token ta có thể tuỳ biến chỉ ra một tập dấu phân cách các token khi khởi tạo đối tượng **StringTokenizer**. Nếu ta không chỉ ra tập dấu phân cách thì mặc định là dấu trắng (space, tab, ...). Ta cũng có thể sử dụng tập các toán tử toán học (+, \*, /, và -) trong khi phân tích một biểu thức

![image](https://user-images.githubusercontent.com/29374426/132615693-8f5ee9cf-9046-4f78-bffc-6f59a5312a82.png)

## Khởi tạo một lớp StringTokenizer

| Phương thức xây dựng                     | Ý nghĩa                                                                                                                                                                            |
| ---------------------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| StringTokenizer(String)                  | Tạo ra một đối tượng StringTokenizer mới dựa trên chuỗi được chỉ định.                                                                                                             |
| StringTokenizer(String, String)          | Tạo ra một đối tượng StringTokenizer mới dựa trên (String, String) chuỗi được chỉ định và một tập các dấu phân cách.                                                               |
| StringTokenizer(String, String, boolean) | Tạo ra một đối tượng StringTokenizer dựa trên chuỗi được chỉ định, một tập các dấu phân cách, và một cờ hiệu cho biết nếu các dấu phân cách sẽ được trả về như cáctoken hay không. |

Các phương thức khởi tạo ở trên được minh họa trong các ví dụ sau:

<content-example />

```java
StringTokenizer st1 = new StringTokenizer("A Stream of words"A Stream of words);
StringTokenizer st2 = new StringTokenizer("4*3/2-1+4", "+-*/", true);
StringTokenizer st3 = new StringTokenizer("aaa,bbbb,ccc", ",");
```

Trong câu lệnh đầu tiên, **StringTokenizer** của `st1` sẽ được xây dựng bằng cách sử dụng các chuỗi được cung cấp và dấu phân cách mặc định. Dấu phân cách mặc định là khoảng trắng, tab, các ký tự xuống dòng. Các dấu phân cách này thì chỉ sử dụng khi phân tách văn bản, như với `st1`.

Câu lệnh thứ hai trong ví dụ trên xây dựng một đối tượng **StringTokenizer** cho các biểu thức toán học bằng cách sử dụng các ký hiệu \*, +, /, và -.

Câu lệnh thứ 3, StringTokenizer của `st3` sử dụng dấu phẩy như một dấu phân cách.

Lớp StringTokenizer cài đặt [interface](/bai-viet/java/interface-trong-java) Enumeration. Vì thế, nó bao gồm các phương thức `hasMoreElements()` và` nextElement()`. Các phương thức có thể sử dụng của lớp **StringTokenizer** được tóm tắt trong bảng sau:

| Phương thức       | Mục đích                                                                                         |
| ----------------- | ------------------------------------------------------------------------------------------------ |
| countTokens()     | Trả về số các token còn lại.                                                                     |
| hasMoreElements() | Trả về True nếu còn có token đang được đánh dấu trong chuỗi. Nó thì giống hệt như hasMoreTokens. |
| hasMoreTokens()   | Trả về True nếu còn có token đang được đánh dấu trong chuỗi. Nó giống hệt như hasMoreElements.   |
| nextElement()     | Trả về token kế tiếp trong chuỗi. Nó thì giống như nextToken.                                    |
| nextToken()       | Trả về Token kế tiếp trong chuỗi. Nó thì giống như nextElement.                                  |
| nextToken(String) | Thay đổi bộ dấu phân cách bằng chuỗi được chỉ định, và sau đó trả về token kế tiếp trong chuỗi.  |

Hãy xem xét chương trình đã cho ở bên dưới. Trong ví dụ này, hai đối tượng StringTokenizer đã được tạo ra. Đầu tiên, “st1” được sử dụng để phân tách một biểu thức toán học. Thứ hai, “st2” phân tách một dòng của các trường được phân cách bởi dấu phẩy. Cả hai tokenizer, phương thức `hasMoreTokens()` và `nextToken()` được sử dụng đế duyệt qua tập các token, và hiển thị các token.

<content-example />

```java
import java.util.*;

public class StringTokenizerImplementer{
  public static void main(String args[]){
    // đặt một biểu thức toán học và tạo một tokenizer cho chuỗi đó.
    String mathExpr = "4*3+2/4";
    StringTokenizer st1 = new StringTokenizer(mathExpr,"*+/-", true);

    //trong khi vẫn còn các token, hiển thị
    System.out.println("Tokens of mathExpr: ");
    while(st1.hasMoreTokens())
      System.out.println(st1.nextToken());

    //tạo một chuỗi của các trường được phân cách bởi dấu phẩy và tạo //một tokenizer cho chuỗi.
    String commas = "field1,field2,field3,and field4";
    StringTokenizer st2 = new StringTokenizer(commas,",",false);
    //trong khi vẫn còn token, hiển thị.
    System.out.println("Comma-delimited tokens: ");
    while (st2.hasMoreTokens())
      System.out.println(st2.nextToken());
  }
}
```

Kết quả chạy chương trình được mô tả như hình dưới.

![image](https://user-images.githubusercontent.com/29374426/125595022-e9935883-42ab-4a8f-aca2-9a2f34c07ed6.png)
