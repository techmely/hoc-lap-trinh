---
title: "Định danh và quy tắc định danh trong java"
description: "Trong ngôn ngữ lập trình, định danh được sử dụng với mục đích nhận biết, phân biệt. Trong Java, một định danh có thể là tên một class, tên một phương thức, tên một biến"
keywords:
  [
    "định danh trong java bị lỗi",
    "định danh trong java developer",
    "định danh trong java download",
    "định danh trong java ebook",
    "định danh trong java eclipse",
    "định danh trong java example",
    "định danh trong java extension",
    "định danh trong java",
    "dinh danh trong java",
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
image: https://user-images.githubusercontent.com/29374426/126279862-b529dc33-71d9-4346-afb0-9a33a01cbb63.png
position: 3
---

Trong ngôn ngữ lập trình, định danh được sử dụng với mục đích nhận biết, phân biệt. Trong Java, một định danh có thể là tên một `class` (sẽ tìm hiểu ở các bài sau), tên một phương thức, tên một biến...

![dinh-danh-va-quy-tac-dinh-danh-trong-java](https://user-images.githubusercontent.com/29374426/126279862-b529dc33-71d9-4346-afb0-9a33a01cbb63.png)

## Định danh là gì và ví dụ

Hiểu đơn giản định danh là mình đặt tên để xác định duy nhất một đại lượng trong chương trình. Đừng lo lắng nếu các bạn không hiểu những gì dưới đây, chúng ta sẽ tìm hiểu chúng ở các bài sau nhé.

```java
import stackjava.com.demo

public class Thaycacac {
  public static void main(String[] args) {
    System.out.println("Hello");
  }
}
```

Trong đoạn code trên ta có các định danh sau:

- `stackjava.com.demo`: tên package
- `Thaycacac`: tên class
- `args`: tên biến
- `String`: tên kiểu dữ liệu
- `main`: tên phương thức

## Quy tắc định danh

Trong java tên được đặt theo quy tắc sau:

- Không trùng với từ khoá
- Không bắt đầu bằng một số, tên phải bắt đầu bằng kí tự hoặc bắt đầu bằng kí tự $,\_
- Không chứa dấu cách, các kí tự toán học như +, -, \*,/, %..
- Không trùng với một định danh khác trong cùng một phạm vi

<div class="note">
<ul>
  <li>
  Tên nên đặt sao cho có thể mô tả được đối tượng trong thực tế
  </li>
  <li>Java có phân biệt chữ hoa chữ thường</li>
  <li>Trong java ta có thể đặt tên với độ dài tuỳ ý</li>
  <li>Ta có thể sử dụng các kí tự tiếng việt để đặt tên</li>
<ul>
</div>

## Quy ước về đặt tên trong java

Ta nên đặt tên biến, hằng, lớp, phương thức sao cho nghĩa của chúng rõ ràng, dễ hiểu, khoa học và mang tính ước lệ quốc tế. Do java có phân biệt chữ hoa, chữ thường nên ta phải cẩn thận và chú ý.

Sau đây là quy ước đặt tên trong java (chú ý đây chỉ là quy ước nên không bắt buộc phải tuân theo quy ước này):

- Đối với biến và phương thức thì tên bao giờ cũng bắt đầu bằng ký tự thường, nếu tên có nhiều từ thì ghép lại thì: ghép tất cả các từ thành một, ghi từ đầu tiên chữ thường, viết hoa kí tự đầu tiên của mỗi từ theo sau trong tên, ví dụ `area`, `radius`, `readInteger`, …
- Đối với tên lớp, giao diện ta viết hoa các kí tự đầu tiên của mỗi từ trong tên, ví dụ lớp WhileTest, Circle
- Tên hằng bao giờ cũng viết hoa, nếu tên gồm nhiều từ thì chúng được nối với hau bởi kí tự ghạch dưới ‘\_’, ví dụ `PI`, `MAX_VALUE`
