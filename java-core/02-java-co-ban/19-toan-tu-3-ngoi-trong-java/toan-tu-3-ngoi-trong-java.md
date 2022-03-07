---
title: "Toán tử 3 ngôi trong Java"
description: "Toán tử ba ngôi là một toán tử dùng để đánh giá một biểu thức có giá trị boolean và sẽ gán giá trị dựa vào kết quả."
keywords:
  [
    "toán tử 3 ngôi",
    "toán tử 3 ngôi java",
    "toán tử 3 ngôi java book",
    "toán tử 3 ngôi java bị lỗi",
    "toán tử 3 ngôi java cơ bản",
    "toán tử ba ngôi",
    "toán tử ba ngôi java",
    "toán tử ba ngôi java fpt",
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
image: https://user-images.githubusercontent.com/29374426/127596066-fa46df01-982f-4a72-b6d1-f7d8f5c5a9b3.png
position: 19
---

Toán tử điều kiện là một loại toán tử đặc biệt vì nó gồm ba thành phần cấu thành biểu thức điều kiện, hay nói cách khác toán tử điều kiện là toán tử 3 ngôi.

## Toán tử 3 ngôi

![toan-tu-3-ngoi-trong-java](https://user-images.githubusercontent.com/29374426/127596066-fa46df01-982f-4a72-b6d1-f7d8f5c5a9b3.png)

**Cú pháp:**

```java
biến = Biểu thức logic ? Câu lệnh khi biểu thức trả về true : Câu lệnh khi biếu thức trả về false;
```

Trong đó:

- **Biểu thức logic**: là một biểu thức logic, nó trả trả về giá trị `true` hoặc `false`.
- **Câu lệnh khi biểu thức trả về true**: Giá trị trả về nếu Biểu thức logic nhận giá `true`.
- **Câu lệnh khi biếu thức trả về false**: Giá trị trả về nếu Biểu thức logic nhận giá `false`.

<div class="example"></div>

```java
String result = isTroiMua() === true ? System.out.println("Tôi sẽ nghỉ học") : System.out.println("Tôi sẽ đi học");
```

<div class="note">
  Kiểu giá trị của <b>Câu lệnh khi biểu thức trả về true</b> và <b>Câu lệnh khi biếu thức trả về false</b> phải tương thích với nhau.
</div>

<div class="example"> Đoạn biểu thức điều kiện sau trả về giá trị “a là số chẵn” nếu như giá trị của biến a là số chẵn, ngược lại trả về giá trị “a là số lẻ” nếu như giá trị của biến a là số lẻ.</div>

```java
String result = a % 2 == 0 ? "a là số chẵn" : "a là số lẻ";
```

## Một số ví dụ

Nếu như trước đây khi phải sử dụng với if – else ta sẽ có như thế này:

```java
int exp = 3;
int salary;

if (exp > 3) {
  salary = 1000;
} else {
  salary = 500;
}
```

Thì bây giờ chỉ còn:

```java
int exp = 1;
int salary = exp > 3 ? 1000 : 500;
```

Nếu như trước đây ta sẽ có :

```java
int exp = 2;
int salary;
if ( exp < 1 ) {
  salary = 1000;
} else if ( exp < 2 ) {
  salary = 1500;
} else if ( exp < 3 ) {
  salary = 2000;
} else {
  salary = 3000;
}
```

Thì bây giờ chỉ còn:

```java
int exp = 2;
int salary = exp < 1 ? 1000 :
  exp < 2 ? 1500 :
  exp < 3 ? 2000 : 3000
```
