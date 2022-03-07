---
title: "Từ khóa break và continue"
description: "Lệnh break sẽ chấm dứt quá trình lặp mà không thực hiện nốt phân còn lại của cấu trúc lặp, continue sẽ ngưng thực thi phần còn lại của thân vòng lặp và chuyển điều khiển về điểm bắt đầu của vòng lặp"
keywords:
  [
    "break continue java",
    "break và continue trong java",
    "break và continue trong java bị lỗi",
    "break và continue trong java code",
    "break và continue trong java edition",
    "break và continue trong java example",
    "break và continue trong java fpt",
    "break và continue trong java free",
    "break và continue trong java gì",
  ]
chapter:
  name: "Nhập môn Java"
  slug: "chuong-02-nhap-mon-java"
category:
  logo: "/language/java.png"
  name: "Java"
  slug: "java"
  description: "Học Java từ cơ bản đến thông thạo cho mọi đối tượng"
image: https://user-images.githubusercontent.com/29374426/127724374-6ceef48b-e07a-462b-b9b6-08eb9c293234.png
position: 22
---

Bên trong thân của các cấu trúc lặp ta có thể điều khiển luồng thực hiện bằng cách sử dụng lệnh `break` hoặc `continue`. Từ khóa `break` trong java dùng để thoát một vòng lặp, từ khóa `continue` được dùng để bỏ tiếp tục vòng lặp.

## Từ khóa break trong trong Java

Lệnh `break` sẽ chấm dứt quá trình lặp mà không thực hiện nốt phần còn lại của cấu trúc lặp.

![Từ khóa break trong trong Java](https://user-images.githubusercontent.com/29374426/127724374-6ceef48b-e07a-462b-b9b6-08eb9c293234.png)

<div class="example"></div>

```java
public class Thaycacac {
  public static void main(String[] args) {
    int x = 2;
    while (x < 15) {
      System.out.println("x = " + x);
      // Kiểm tra nếu x = 5 thì thoát ra khỏi vòng lặp.
      if (x == 5) {
          break;
      }
      x++;
      System.out.println("x after ++ = " + x);
    }
    System.out.println("Done!");
  }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>x = 2</code><br/>
    <code>x after ++ = 3</code><br/>
    <code>x = 3</code><br/>
    <code>x = 4</code><br/>
    <code>x after ++ = 5</code><br/>
    <code>x = 5</code><br/>
    <code>Done!</code>
  </div>
</div>

## Từ khóa continue trong Java

Lệnh `continue` có thể xuất hiện trong một vòng lặp, khi bắt gặp lệnh `continue` chương trình sẽ bỏ qua các dòng lệnh bên trong khối lệnh và phía dưới của `continue` và bắt đầu một bước lặp tiếp theo mới (Nếu các điều kiện vẫn đúng).

![Từ khóa continue trong Java](https://user-images.githubusercontent.com/29374426/127724876-382a6460-27c3-4bb0-9619-c734a072572e.png)

<div class="example"></div>

```java
public class Thaycacac {
  public static void main(String[] args) {
    int x = 2;
    while (x < 7) {
      System.out.println("x = " + x);
      // x = x + 1;
      x++;
      // Toán tử % là phép chia lấy số dư.
      // Nếu x chẵn, thì bỏ qua các dòng lệnh phía dưới của 'continue',
      // và tiếp tục bước lặp (iteration) mới (nếu điều kiện vẫn đúng).
      if (x % 2 == 0) {
          continue;
      }
      System.out.println("x after ++ = " + x);
    }
    System.out.println("Done!");
  }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>x = 2</code><br/>
    <code>x after ++ = 3</code><br/>
    <code>x = 3</code><br/>
    <code>x = 4</code><br/>
    <code>x after ++ = 5</code><br/>
    <code>x = 5</code><br/>
    <code>x = 6</code><br/>
    <code>x after ++ = 7</code><br/>
    <code>Done!</code>
  </div>
</div>
