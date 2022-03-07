---
title: "Lệnh và khối lệnh trong Java"
description: "Lệnh hay câu lệnh là tập hợp các từ khóa, tập ký tự trong java và được kết thúc bởi dấu chấm phẩy"
keywords:
  [
    "câu lệnh java cơ bản",
    "câu lệnh trong java",
    "câu lệnh và khối lệnh",
    "lệnh và câu lệnh java bị lỗi",
    "lệnh và câu lệnh java fpt",
  ]
chapter:
  name: "Nhập môn Java"
  slug: "chuong-02-nhap-mon-java"
category:
  name: "Java"
  slug: "java"
image: https://upload.wikimedia.org/wikipedia/commons/2/29/Linux_command-line._Bash._GNOME_Terminal._screenshot.png
position: 4
---

## Lệnh / câu lệnh trong Java

Lệnh hay câu lệnh là tập hợp các từ khóa, tập ký tự trong java và được kết thúc bởi dấu chấm phẩy `;`

<div class="example"></div>

```java
int tuoi = 12; // đây là một dòng lệnh
String ten = "Thaycacac" // đây là dòng lệnh
```

## Khối lệnh trong Java

Một khối lệnh là đoạn chương trình gồm hai lệnh trở lên và được bắt đầu bằng dấu mở ngoặc nhọn `{` và kết thúc bằng dấu đóng ngoặc nhọc `}`.

Bên trong một khối lệnh có thể chứa một hay nhiều lệnh hoặc chứa các khối lệnh khác.

```java
{ // khối 1
  { // khối 2
    lệnh 2.1;
    lệnh 2.2;
    ...
  } // kết thúc khối lệnh 2
  lệnh 1.1;
  lệnh 1.2;
  ...
} // kết thúc khối lệnh 1
{ // bắt đầu khối lệnh 3
  // Các lệnh thuộc khối lệnh 3
  // ...
} // kết thúc thối lệnh 3
```
