---
title: "Cấu trúc rẽ nhánh trong Javascript"
description: "Cấu trúc rẽ nhánh trong Javascript"
keywords: ["khoá học javascript",
"Cấu trúc rẽ nhánh trong Javascript",
"Cấu trúc rẽ nhánh",
"Câu lệnh rẽ nhánh không điều kiện",
"cau truc re nhanh trong javascript là gì",
"cú pháp câu lệnh rẽ nhánh",
"cấu trúc rẽ nhánh trong javascript cơ bản",
"cach su dung cau truc re nhanh trong javascript"
]
chapter:
  name: "Javascript cơ bản"
  slug: "chuong-02-javascript-co-ban"
category:
  name: "Javascript"
  slug: "javascript"
image: https://kungfutech.edu.vn/thumbnail.png
position: 12
---

Khi lập trình, bạn sẽ thường xuyên gặp tình huống là **chỉ thực hiện một hành động nếu một hoặc nhiều điều kiện thỏa mãn**. Để giải quyết vấn đề này, bạn cần phải biết về cấu trúc rẽ nhánh trong JavaScript.

Có hai cấu trúc rẽ nhánh trong JavaScript là:

- Câu lệnh điều kiện rẽ nhánh - **if/else**
- Toán tử rẽ nhánh - **?:**

## Câu lệnh rẽ nhánh trong JavaScript

Sau đây là những kiến thức cơ bản cần nhớ về câu lệnh rẽ nhánh `if` trong JavaScript.

### Câu lệnh `if`

Câu lệnh `if(...)` sẽ kiểm tra điều kiện biểu thức bên trong cặp dấu ngoặc đơn `()`. Nếu kết quả là `true` thì một khối code sẽ được thực thi.

Ví dụ về câu lệnh `if`:

```js
const x = 2;

if (x % 2 === 0) console.log("x is an even number");
```

Vì `x = 2` nên x chia 2 dư 0. Do đó, `x % 2 === 0` là `true`. Vì vậy, câu lệnh `console.log` trên được thực hiện.

Để thực hiện nhiều câu lệnh, bạn sử dụng cặp dấu `{}`:

```js
const x = 2;

if (x % 2 === 0) {
  console.log("x is an even number");
  console.log("done!");
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>x is an even number</code>
    <code>done!</code>
  </div>
</div>

💡 Theo mình, dù khối code sau câu lệnh `if` là một hay nhiều câu lệnh thì bạn cũng nên dùng cặp dấu `{}` để code dễ đọc hơn. Ngoài ra, mình cũng nhắc lại quy luật [chuyển đổi kiểu dữ liệu](/bai-viet/khoa-hoc-javascript/chuyen-doi-kieu-du-lieu-trong-javascript/) sang boolean như sau:

- Những giá trị "empty" như: số `0`, string rỗng `""`, `null`, `undefined` và `NaN` sẽ trở thành `false`.
- Những giá trị còn lại sẽ trở thành `true`.

Vì vậy, khối lệnh với điều kiện sau sẽ không bao giờ được thực thi:

```js
// 0 là giá trị falsy
if (0) {
  // các câu lệnh
}
```

Ngược lại, khối lệnh với điều kiện sau lại luôn luôn được thực thi:

```js
// 1 là giá trị truthy
if (1) {
  // các câu lệnh
}
```

Ngoài ra, bạn có thể tính toán giá trị của điều kiện trước khi dùng `if`:

```js
const x = 2;
const result = x % 2 === 0; // kết quả là true
if (result) {
  console.log("x is an even number"); // câu lệnh này được thực thi
}
```

### Mệnh đề `else`

Đi theo câu lệnh `if` còn có mệnh đề `else` - dùng để thực hiện một khối lệnh khi điều kiện trong `if` là giá trị `falsy`.

Tiếp theo ví dụ trên:

```js
const x = 3;

if (x % 2 === 0) {
  console.log("x is an even number");
} else {  console.log("x is an odd number"); // câu lệnh này được thực thi}
```

Vì `x = 3` nên x chia 2 dư 1. Do đó, `x % 2 === 0` là `false`. Vì vậy, khối lệnh sau `else` được thực thi.

### Nhiều mệnh đề `else if` nối tiếp

Trong trường hợp, bạn cần kiểm tra nhiều điều kiện liên tiếp nhau thì có thể dùng nhiều mệnh đề `else if` nối tiếp nhau.

<content-example />

```js
const age = 24;

if (age < 18) {
  console.log("Too young!");
} else if (age > 50) {
  console.log("Too old!");
} else {
  console.log("OK!");
}
// OK!
```

Đoạn code trên kiểm tra điều kiện `age < 18` đầu tiên. Nếu đúng thì câu lệnh `console.log` đầu tiên được thực thi. Nếu sai thì kiểm tra tiếp đến điều kiện `age > 50`. Nếu đúng thì câu lệnh `console.log` thứ hai được thực thi. Nếu vẫn sai thì câu lệnh `console.log` cuối cùng được thực thi.

Ở đây, `age = 24` nên `age < 18` và `age > 50` đều là `false`. Vì vậy, câu lệnh `console.log` cuối cùng được thực thi.

**Chú ý**: _Mệnh đề `else` cuối cùng không bắt buộc phải có._

Ví dụ trên khi bỏ mệnh đề `else` cuối cùng:

```js
const age = 24;

if (age < 18) {
  console.log("Too young!");
} else if (age > 50) {
  console.log("Too old!");
}
```

Lần này, không có điều kiện nào thỏa mãn, nên không câu lệnh `console` nào được thực thi.

## Toán tử rẽ nhánh

Sau đây là những kiến thức cơ bản cần nhớ về toán tử rẽ nhánh `?` trong JavaScript.

### Toán tử rẽ nhánh `?`

Trong nhiều trường hợp, bạn cần gán giá trị cho một biến dựa trên một điều kiện, ví dụ:

```js
const age = 24;

let enoughAge;
if (age < 18) {
  enoughAge = false;
} else {
  enoughAge = true;
}

console.log(enoughAge); // true
```

Để đơn giản hơn, bạn có thể dùng toán tử rẽ nhánh `?` (hoặc có thể gọi là **toán tử dấu hỏi**), với cú pháp:

```js
const result = condition ? value1 : value2;
```

Đây là toán tử ba ngôi với ba thành phần:

- "condition": điều kiện cần kiểm tra
- "value1": giá trị trả về nếu điều kiện "condition" là `truthy`.
- "value2": giá trị trả về nếu điều kiện "condition" là `falsy`.

Ví dụ trên trở thành:

```js
const age = 24;

const enoughAge = age < 18 ? false : true;
console.log(enoughAge); // true
```

Ngoài ra, bạn có thể dùng cặp dấu ngoặc đơn `()` cho dễ nhìn (và chắc chắn hơn - khi bạn không rõ về thứ tự ưu tiên của các toán tử):

```js
const age = 24;

const enoughAge = age < 18 ? false : true;
console.log(enoughAge); // true
```

Đây chỉ là ví dụ minh họa. Thực tế trong trường hợp này, bạn có thể code đơn giản hơn như sau:

```js
const age = 24;
const enoughAge = age >= 18;
console.log(enoughAge); // true
```

### Nhiều toán tử `?`

Cùng xem lại ví dụ về nhiều mệnh đề `else if` bên trên:

```js
const age = 24;

if (age < 18) {
  console.log("Too young!");
} else if (age > 50) {
  console.log("Too old!");
} else {
  console.log("OK!");
}
```

Bạn có thể sửa lại bằng cách sử dụng nhiều toán tử `?` như sau:

```js
const age = 24;

const message = age < 18 ? "Too young!" : age > 50 ? "Too old!" : "OK!";
console.log(message); // OK!
```

Thoạt nhìn thì có vẻ phức tạp, nhưng bạn có thể phân tích kỹ ra như sau sẽ hiểu:

- Dấu `?` đầu tiên kiểm tra điều kiện `age < 18`.
  - Nếu đúng thì trả về `"Too young!"`.
  - Nếu sai thì tiếp tục xử lý thành phần sau dấu `:` đầu tiên.
- Tiếp tục, dấu `?` thứ hai kiểm tra điều kiện `age > 50`.
  - Nếu đúng thì trả về `"Too old!"`.
  - Nếu sai thì tiếp tục xử lý thành phần sau dấu `:` thứ hai.
- Cuối cùng, khi các điều kiện trên đều `false` thì sẽ trả về `"OK!"`.

### Sử dụng toán tử `?` thay câu lệnh `if`

Bạn có thể dùng toán tử `?` để kiểm tra điều kiện và thực hiện một câu lệnh thay cho câu lệnh `if`, ví dụ:

```js
const x = 2;

x % 2 === 0 ? console.log("even number") : console.log("odd number"); // even number
```

Mặc dù, đoạn code trên là đúng. Nhưng theo mình thì không nên code như vậy. Vì code như vậy khá khó nhìn và không trực quan.

Bạn nên sử dụng đúng mục đích của câu lệnh `if` và toán tử `?`. Với đoạn code trên, bạn nên sử dụng câu lệnh `if` như sau:

```js
const x = 2;

if (x % 2 === 0) {
  console.log("even number");
} else {
  console.log("odd number");
}
// even number
```

## Tổng kết về cấu trúc rẽ nhánh

Có hai cấu trúc rẽ nhánh trong JavaScript là:

- Câu lệnh điều kiện rẽ nhánh - **if/else**
- Toán tử rẽ nhánh - **?:**

Câu lệnh `if(...)` sẽ kiểm tra điều kiện biểu thức bên trong cặp dấu ngoặc đơn `()`.

- Nếu kết quả là `true` thì một khối code sẽ được thực thi.
- Nếu kết quả là `false` thì bạn có thể dùng mệnh đề `else` để thực thi một khối lệnh tương ứng khác.

Toán tử `?` thường chỉ dùng để gán giá trị cho một biến dựa trên một điều kiện. Bạn nên sử dụng đúng mục đích của toán tử `?` để code rõ ràng và dễ hiểu hơn.

## Thực hành

### Bài 1

Sử dụng [hàm `prompt`](/ham-tuong-tac-nguoi-dung-alert-confirm-prompt/), hiển thị nội dung yêu cầu người dùng nhập vào một số nguyên dương chẵn.

Nếu người dùng nhập vào đúng số chẵn thì hiển thị **Bạn đã nhập đúng!**. Ngược lại, hiển thị **Bạn đã nhập sai!**.

_Giả sử, người dùng luôn nhập vào số nguyên dương._

Xem đáp án

```html
<html>
  <body>
    <script>
      const value = prompt("Nhập vào số nguyên dương chẵn:", 0);
      if (value % 2 === 0) {
        alert("Bạn đã nhập đúng!");
      } else {
        alert("Bạn đã nhập sai!");
      }
    </script>
  </body>
</html>
```

### Bài 2

Sử dụng toán tử `?` thay cho câu lệnh `if`:

```js
let a = 10;
let b = 20;
let result;

if (a + b < 10) {
  result = "Small";
} else {
  result = "Big";
}

console.log(result);
```

Xem đáp án

```js
let a = 10;
let b = 20;
let result;

result = a + b < 10 ? "Small" : "Big";
console.log(result);
```
