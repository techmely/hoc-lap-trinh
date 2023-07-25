---
title: "JavaServer Pages Standard Tag Library (JSTL)"
description: "JavaServer Pages Standard Tag Library (JSTL) là một tập hợp các thẻ JSP hữu ích, mà gói các tính năng lõi phổ biến tới các ứng dụng JSP."
keywords:
  [
    "khóa học Spring cơ bản",
    "jstl là gì",
    "khái niệm jstl",
    "thư viện jstl",
    "JavaServer Pages Standard Tag Library là gì",
    "jstl viết tắt",
    "core tag là gì",
    "formatting tag là gì",
    "phân loại jstl tag",
    "custom tag trong jstl",
  ]
chapter:
  name: "Form"
  slug: "chuong-04-form"
category:
  name: "Spring Boot"
  slug: "spring-boot"
image: https://kungfutech.edu.vn/thumbnail.png
position: 8
---

![jstl](https://github.com/techmely/hoc-lap-trinh/assets/29374426/55145b25-44d7-41ff-8e8b-90108d7a6f59)

## JSTL là gì?

**JavaServer Pages Standard Tag Library (JSTL)** là một tập hợp các thẻ **JSP** hữu ích, mà gói các tính năng lõi phổ biến tới các ứng dụng **JSP**.

**JSTL** hỗ trợ tới các tác vụ phổ biến và có tính cấu trúc, ví dụ như các tính lặp và điều kiện, các thẻ để thao tác tài liệu **XML**, các thẻ đa ngôn ngữ, và các thẻ SQL. Nó cũng cung cấp **Framework** để tích hợp các **Custom Tags** với các thẻ **JSTL**.

## Phân Loại

Các thẻ **JSTL** có thể được phân loại, theo tính năng của nó, thành các nhóm thư viện thẻ **JSTL** sau, mà có thể được sử dụng khi tạo một **JSP** page:

- `Core Tags`: Nhóm thẻ cơ bản
- `Formatting Tags`: Nhóm thẻ định dạng
- `SQL Tags`: Nhóm thẻ SQL
- `XML Tags`: Nhóm thẻ XML
- `JSTL Functions`: Nhóm hàm JSTL

Tuy nhiên vì `Core Tags` và `Formatting Tags` được sử dụng nhiều nhất nên ở bài này mình sẽ tập trung vào 2 loại tag này.

### Core Tags

Nhóm `Core Tags` là các thẻ **JSTL** được sử dụng phổ biến nhất. Sau đây là cú pháp đơn giản để bao thư viện **JSTL Core** trong **JSP** của bạn:

```java
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/html/core" %>
```

Bảng dưới đây là các thẻ có trong `Core Tags`, các bạn có thể đọc để hiểu rõ hơn nhé:

![core-tag](https://github.com/techmely/hoc-lap-trinh/assets/29374426/ad0f4546-8d71-45db-b18b-bf1263417311)

### Formatting Tags

Nhóm `Formatting Tags` trong **JSTL** được sử dụng để định dạng và hiển thị text, date, time và số ngôn ngữ trong Website. Sau đây là cú pháp cơ bản để include thư viện `Formatting Tags` trong **JSP** của bạn.

```java
<%@ taglib prefix="fmt" uri="http://java.sun.com/jsp/html/fmt" %>
```

Dưới đây là các thẻ trong nhóm `Formatting Tags`:

![formatting-tags](https://github.com/techmely/hoc-lap-trinh/assets/29374426/65eb34a5-3335-44ba-a15c-767d278f330d)
