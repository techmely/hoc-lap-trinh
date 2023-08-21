---
title: "Vòng lặp trong Thymeleaf"
description: "Thymeleaf cung cấp cho bạn vòng lặp 'each', và bạn có thể sử dụng nó thông qua thuộc tính (attribue) th:each. Đây là vòng lặp duy nhất được hỗ trợ trong Thymeleaf."
keywords:
  [
    "khóa học Spring cơ bản",
    "vòng lặp trong Thymeleaf",
    "vòng lặp each trong Thymeleaf",
    "vòng lặp trong Thymeleaf là gì",
    "hướng dẫn sử dụng vòng lặp each trong Thymeleaf",
    "ví dụ về vòng lặp each trong Thymeleaf",
    "cơ bản về vòng lặp trong Thymelead",
    "vòng lặp trong spring mvc",
    "Thymeleaf vòng lặp th:each",
    "spring thymeleaf vòng lặp là gì",
  ]
chapter:
  name: "Thymeleaf"
  slug: "chuong-05-thymeleaf"
category:
  name: "Spring Boot"
  slug: "spring-boot"
image: https://kungfutech.edu.vn/thumbnail.png
position: 10
---

### Định nghĩa

`Thymeleaf` cung cấp cho bạn vòng lặp **'each'**, và bạn có thể sử dụng nó thông qua thuộc tính (attribue) `th:each`. Đây là vòng lặp duy nhất được hỗ trợ trong `Thymeleaf`.

Vòng lặp này chấp nhận một vài loại dữ liệu như:

- Các đối tượng implements interface **java.util.Iterable**.
- Các đối tượng implements interface **java.util.Map**.
- Các mảng (**Arrays**)

### Cú pháp

Mình sẽ giới thiệu đến các bạn 2 loại cú pháp vòng lặp của `Thymeleaf`:

#### Cú pháp 1

```java
<someHtmlTag th:each="item : ${items}">
     ...
</someHtmlTag>
```

Thẻ `<th:block>` là một thẻ ảo trong `Thymeleaf`, nó không tương ứng với bất kỳ thẻ nào của **HTML**, nhưng nó rất có ích trong nhiều trường hợp, chẳng hạn bạn có thể đặt thuộc tính (attribute) `th:each` trong thẻ này.

```java
<th:block th:each="item : ${items}">
     ....
</th:block>
```

Ví dụ đơn giản với vòng lặp `th:each`:
<content-example>

```html
<h1>th:each</h1>
<ul>
  <th:block th:each="member : ${techmely}">
    //String[] techmely = new String[] {"thaycacac","tony hoang","Harry Tran"};
    <li th:utext="${member}">..</li>
  </th:block>
</ul>
```

</content-example>

**_Kết quả:_**

```html
<!DOCTYPE html>
<html>
  <head>
    <meta charset="UTF-8" />
    <title>Loop</title>
  </head>
  <body>
    <h1>th:each</h1>
    <ul>
      <li>thaycacac</li>
      <li>tony hoang</li>
      <li>Harry Tran</li>
    </ul>
  </body>
</html>
```

#### Cú pháp 2

Cú pháp đầy đủ của `th:each` bao gồm 2 biến, **biến phần tử** (item variable) và **biến trạng thái** (state variable).

```html
<someHtmlTag th:each="item, iState : ${items}"> ..... </someHtmlTag>

<!-- OR: -->

<th:block th:each="item, iState : ${items}"> ..... </th:block>
```

**Biến trạng thái** là một đối tượng hữu ích, nó chứa các thông tin cho bạn biết trạng thái hiện tại của vòng lặp, chẳng hạn như số phần tử của vòng lặp, chỉ số hiện tại của vòng lặp,...

Dưới đây là danh sách các _thuộc tính_ của **biến trạng thái**:

> - **index**: Chỉ số hiện tại của phép lặp (iteration), bắt đầu với số 0.
> - **count**: Số phần tử đã được xử lý cho tới hiện tại.
> - **size**: Tổng số phần tử trong danh sách.
> - **even/odd**: Kiểm tra xem chỉ số (index) hiện tại của phép lặp (iteration) là chẵn hay lẻ.
> - **first**: Kiểm tra xem lần lặp hiện tại là lần lặp đầu tiên hay không?
> - **last**: Kiểm tra xem lần lặp hiện tại là lần lặp cuối hay không?

Ví dụ khác với `th:each` và **biến trạng thái**:

```java
@RequestMapping("/loop-example")
public String loopExample(Model model) {
    String[] flowers = new String[] { "Rose", "Lily", "Tulip", "Carnation", "Hyacinth" };
    model.addAttribute("flowers", flowers);
    return "loop-example";
}
```

```html
<!DOCTYPE html>
<html xmlns:th="http://www.thymeleaf.org">
  <head>
    <meta charset="UTF-8" />
    <title>Loop</title>
    <style>
      table th,
      table td {
        padding: 5px;
      }
    </style>
  </head>
  <body>
    <h1>th:each</h1>
    <table border="1">
      <tr>
        <th>index</th>
        <th>count</th>
        <th>size</th>
        <th>even</th>
        <th>odd</th>
        <th>first</th>
        <th>last</th>
        <th>Flower Name</th>
      </tr>
      <tr th:each="flower, state : ${flowers}">
        <td th:utext="${state.index}">index</td>
        <td th:utext="${state.count}">count</td>
        <td th:utext="${state.size}">size</td>
        <td th:utext="${state.even}">even</td>
        <td th:utext="${state.odd}">odd</td>
        <td th:utext="${state.first}">first</td>
        <td th:utext="${state.last}">last</td>
        <td th:utext="${flower}">Flower Name</td>
      </tr>
    </table>
  </body>
</html>
```

**_Kết quả:_**

![vong-lap-thymeleaf](https://github.com/techmely/hoc-lap-trinh/assets/29374426/db9c0fad-a492-42cb-b19e-bd4675479dcf)
