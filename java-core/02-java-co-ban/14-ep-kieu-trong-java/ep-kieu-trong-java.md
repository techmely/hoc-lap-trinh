---
title: "Ép kiểu trong Java"
description: "Ép kiểu trong java là việc gán giá trị của một biến có kiểu dữ liệu này tới biến khác có kiểu dữ liệu khác"
keywords:
  [
    "cách ép kiểu trong java",
    "ép kiểu char sang int trong java",
    "ép kiểu class trong java",
    "ép kiểu dữ liệu trong java",
    "ép kiểu int sang float trong java",
    "ép kiểu int sang string trong java",
    "ép kiểu int trong java",
    "ép kiểu java",
    "ép kiểu object trong java",
    "ép kiểu string trong java",
  ]
chapter:
  name: "Nhập môn Java"
  slug: "chuong-02-nhap-mon-java"
category:
  name: "Java"
  slug: "java"
image: https://user-images.githubusercontent.com/29374426/137243394-f31122f7-8b8c-4d1b-a194-9a0a4a679c61.png
position: 14
---

Trong lập trình ta sẽ gặp một số trường hợp là ban đầu ta khai báo biến ở kiểu dữ liệu này, nhưng sau đó ta cần chuyển nó sang kiểu dữ liệu khác để phù hợp trong tính toán. Vì vậy, bài viết này [KungFu Tech](https://kungfutech.edu.vn/) sẽ hướng dẫn các bạn cách ép kiểu trong Java.

Ép kiểu trong java là việc gán giá trị của một biến có kiểu dữ liệu này tới biến khác có kiểu dữ liệu khác, chú ý là trong bài này chỉ nói đến ép kiểu dữ liệu đối với [dữ liệu nguyên thủy](/bai-viet/java/cac-kieu-du-lieu-trong-java). Có 2 kiểu ép kiểu (chuyển đổi kiểu) đó là

- Ép kiểu không tường minh
- Ép kiểu tường minh

## Ép kiểu không tường minh

Việc ép kiểu thường được diễn ra một cách tự động trong trường hợp biểu thức gồm nhiều toán hạng có kiểu dữ liệu khác nhau. Điều này đôi khi làm cho bạn khá ngạc nhiên vì nhận được một kết quả không theo ý muốn.

<content-example />

```java
int two=2, three=3;
float result= 1.5 + three/two;
```

Kết quả nhận được của result là _2.5_. Điều mà bạn mong muốn là _3.0_ chứ không phải là _2.5_. Kết quả _2.5_ nhận được là do `three` và `two` là hai giá trị nguyên nên kết quả của phép chia `three/two` cho ta một giá trị nguyên bằng 1 chứ không phải là _1.5_. Để nói rằng kết quả của phép chia `three/two` là một giá trị thực chứ không phải là một giá trị nguyên thì một trong hai toán hạng của phép chia này phải là một số thực. Do vậy ta cần phải chuyển kiểu của một trong hai toán hạng này hoặc cả hai thành số thực. Để nhận được kết quả đúng trong trường hợp này bạn cần viết như sau:

```java
float result=1.5 + (float) three/two; // hoặc
float result=1.5 + three/(float)two; // hoặc
float result=1.5 +(float)three/(float)two;
```

Lý do mà ta viết như trên là nếu trong một phép toán có sự tham gia của nhiều toán hạng có kiểu khác nhau thì java sẽ chuyển kiểu tự động cho các toán hạng một cách tự động theo quy tắc sau:

![quy tắc ép kiểu trong java](https://user-images.githubusercontent.com/29374426/137243394-f31122f7-8b8c-4d1b-a194-9a0a4a679c61.png)

## Ép kiểu tường minh

Để chuyển đổi kiểu một cách tường minh ta sử dụng cú pháp sau:

```java
([kiểu dữ liệu muốn chuyển đổi]) [biểu thức];
```

Khi gặp câu lệnh này java sẽ tính toán giá trị của biểu thức sau đó chuyển đổi kiểu giá trị của biểu thức thành kiểu **kiểu dữ liệu muốn chuyển đổi**

```java
(int) 2.5 * 2 = 4
(int) 2.5 * 2.5 = 5
(int)(2.5 * 2.5) = 6
1 + (float) 5 / 2 = 1 + 5 / (float)2 =1 + (float)5 / (float)2 = 3.5
```

<content-info>
  <ul>
    <li>Phép toán chuyển kiểu là phép toán có độ ưu tiên cao, nên (int)3.5*2(int)(3.4*2)</li>
    <li>Cần chú ý khi chuyển một biểu thức kiểu dữ liệu có miền giá trị lớn sang một kiểu có miền giá trị nhỏ hơn. Trong trường hợp này có thể bạn sẽ bị mất thông tin.</li>
  </ul>
</content-info>
