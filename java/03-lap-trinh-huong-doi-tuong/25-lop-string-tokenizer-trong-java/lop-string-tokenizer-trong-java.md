---
title: "Lớp StringTokenizer trong Java"
description: "Bài này chúng ta sẽ tìm hiểu về Lớp StringTokenizer, một lớp StringTokenizer có thể sử dụng để tách một chuỗi thành các phần tử (token) nhỏ hơn"
chapter:
  name: "Lập trình hướng đối tượng"
  slug: "chuong-03-lap-trinh-huong-doi-tuong"
image: https://user-images.githubusercontent.com/29374426/132615693-8f5ee9cf-9046-4f78-bffc-6f59a5312a82.png
position: 25
---

Lớp `StringTokenizer` trong Java là một công cụ mạnh mẽ cho việc phân tách chuỗi thành các phần tử riêng lẻ dựa trên các dấu phân cách hoặc ký tự `delimiters`. Trong bài viết này, chúng ta sẽ tìm hiểu cách khởi tạo lớp `StringTokenizer`, cách sử dụng các phương thức của nó và cách áp dụng trong các ví dụ thực tế.

![image](https://user-images.githubusercontent.com/29374426/132615693-8f5ee9cf-9046-4f78-bffc-6f59a5312a82.png)

## Khởi tạo một đối tượng `StringTokenizer`

Lớp `StringTokenizer` cung cấp ba cách để khởi tạo đối tượng:

1. `StringTokenizer(String str)`: Tạo một đối tượng `StringTokenizer` mới dựa trên chuỗi `str` và sử dụng các dấu phân cách mặc định (khoảng trắng, tab, và các ký tự xuống dòng) để tách chuỗi.

2. `StringTokenizer(String str, String delim)`: Tạo một đối tượng `StringTokenizer` mới dựa trên chuỗi `str` và sử dụng các ký tự trong chuỗi `delim` làm dấu phân cách để tách chuỗi.

3. `StringTokenizer(String str, String delim, boolean returnDelims)`: Tạo một đối tượng `StringTokenizer` mới dựa trên chuỗi `str`, sử dụng các ký tự trong chuỗi `delim` làm dấu phân cách để tách chuỗi, và thiết lập cờ `returnDelims` để xác định liệu dấu phân cách có được bao gồm trong danh sách kết quả hay không (`true` nếu cần bao gồm, `false` nếu không).

Ví dụ:

```java
StringTokenizer st1 = new StringTokenizer("A Stream of words");
StringTokenizer st2 = new StringTokenizer("4*3/2-1+4", "+-*/", true);
StringTokenizer st3 = new StringTokenizer("aaa,bbbb,ccc", ",");
```

Trong ví dụ trên, `st1` sử dụng dấu phân cách mặc định (khoảng trắng) để tách chuỗi. `st2` sử dụng các ký tự "+-\*/" làm dấu phân cách và bao gồm dấu phân cách trong danh sách kết quả. `st3` sử dụng dấu phẩy làm dấu phân cách.

## Các phương thức của lớp `StringTokenizer`

Lớp `StringTokenizer` cung cấp các phương thức sau:

- `countTokens()`: Trả về số lượng các token còn lại trong danh sách.
- `hasMoreElements()`: Trả về `true` nếu còn các token đang được đánh dấu trong chuỗi (tương đương với `hasMoreTokens()`).
- `hasMoreTokens()`: Trả về `true` nếu còn các token đang được đánh dấu trong chuỗi (tương đương với `hasMoreElements()`).
- `nextElement()`: Trả về token kế tiếp trong danh sách (tương đương với `nextToken()`).
- `nextToken()`: Trả về token kế tiếp trong danh sách (tương đương với `nextElement()`).
- `nextToken(String delim)`: Thay đổi dấu phân cách hiện tại bằng chuỗi `delim`, sau đó trả về token kế tiếp trong danh sách.

Hãy xem xét ví dụ sau:

```java
import java.util.StringTokenizer;

public class StringTokenizerExample {
    public static void main(String[] args) {
        // Tạo một đối tượng StringTokenizer với chuỗi và dấu phân cách mặc định (khoảng trắng).
        StringTokenizer st1 = new StringTokenizer("A Stream of words");

        // Hiển thị số lượng token còn lại trong danh sách.
        System.out.println("Total tokens in st1: " + st1.countTokens());

        // Duyệt qua và hiển thị các token trong danh sách.
        System.out.println("Tokens in st1:");
        while (st1.hasMoreTokens()) {
            System.out.println(st1.nextToken());
        }

        // Tạo một đối tượng StringTokenizer với chuỗi và dấu phân cách là "+-*/".
        StringTokenizer st2 = new StringTokenizer("4*3/2-1+4", "+-*/", true);

        // Hiển thị số lượng token còn lại trong danh sách.
        System.out.println("Total tokens in st2: " + st2.countTokens());

        // Duyệt qua và hiển thị các token trong danh sách.
        System.out.println("Tokens in st2:");
        while (st2.hasMoreTokens()) {
            System.out.println(st2.nextToken());
        }
    }
}
```

Kết quả của chương trình trên sẽ hiển thị số lượng token còn lại trong danh sách và danh sách các token tương ứng.

::Result

Total tokens in st1: 4
Tokens in st1:
A
Stream
of
words
Total tokens in st2: 9
Tokens in st2:
4

-

3
/
2

- 1

* 4

::

Lớp `StringTokenizer` là một công cụ hữu ích cho việc phân tích và xử lý chuỗi trong Java, đặc biệt khi bạn cần tách chuỗi thành các phần tử riêng lẻ dựa trên các dấu phân cách hoặc ký tự delimiters.
