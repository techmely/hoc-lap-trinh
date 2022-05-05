---
title: "Var trong Javascript và cách sử dụng IIFE"
description: "Var trong JavaScript là một cách cũ để khai báo biến. Và bạn không nên sử dụng var nữa, mà thay vào đó là sử dụng let hoặc const."
keywords: [
"Var trong Javascript và cách sử dụng IIFE",
"iife trong javascript dung de lam gi",
"iife trong javascript la gi",
"Iife trong Javascript dụng để làm gì",
"cách sử dụng Iife trong Javascript",
"Iife trong Javascript có ý nghĩa gì",
"ví dụ về Iife trong Javascript",
"iife trong Javascript"
]
chapter:
  name: "Kiến thức nâng cao về hàm"
  slug: "chuong-05-kien-thuc-nang-cao-ve-ham"
category:
  name: "Javascript"
  slug: "javascript"
image: https://kungfutech.edu.vn/thumbnail.png
position: 4
---

Var trong JavaScript là một **cách cũ** để khai báo biến. Và bạn không nên sử dụng `var` nữa, mà thay vào đó là sử dụng `let` hoặc `const`.

Tuy nhiên, `var` vẫn tồn tại trong nhiều mã nguồn cũ. Việc nghiên cứu về `var` giúp bạn hiểu được những mã nguồn này. Qua đó, bạn biết cách để có thể chuyển từ `var` sang `let/const`.

Sau đây là những đặc điểm cơ bản của `var` trong JavaScript.

## `var` không có phạm vi block

Biến được khai báo bằng `var`, hoặc là có **phạm vi toàn cục** hoặc là có **phạm vi hàm**, khác với [**phạm vi block**](/bai-viet/javascript/closure-trong-javascript/) của biến sử dụng `let/const`.

Ví dụ sử dụng var trong JavaScript:

```js
if (true) {
  var test = true; // sử dụng "var" thay vì "let"}

  console.log(test); // true - biến test vẫn nhìn thấy ở ngoài if
}
```

Trong ví dụ trên, biến khai báo với `var` có **phạm vi toàn cục** và được nhìn thấy ở ngoài block.

Nếu bạn sử dụng `let test` thay vì `var test`, thì biến `test` chỉ được nhìn thấy trong block của câu lệnh `if`:

```js
if (true) {
  let test = true; // sử dụng "let" thay vì "var"}

  console.log(test); // Uncaught ReferenceError: test is not defined
}
```

Tương tự khi sử dụng `var` trong [vòng lặp `for`](/bai-viet/javascript/vong-lap-trong-javascript):

```js
for (var i = 0; i < 10; i++) {
  var a = 1; // ...
}

console.log(i); // 10, biến i vẫn được nhìn thấy sau for, i là biến toàn cục
console.log(a); // 1, biến a vẫn được nhìn thấy sau for, a là biến toàn cục
```

Nếu **khối code nằm trong hàm** thì biến khai báo sử dụng `var` có **phạm vi hàm**, ví dụ:

```js
function sayHi() {
  if (true) {
    var message = "Hello";
  }

  console.log(message); // Hello
}

sayHi();
console.log(message); // Uncaught ReferenceError: message is not defined
```

Trong ví dụ trên, biến `message` được khai báo sử dụng `var`. Biến này có thể nhìn thấy sau khối code của `if` nhưng không được nhìn thấy ở ngoài hàm `sayHi`.

Nói cách khác, biến `message` chỉ có phạm vi hàm.

## Có thể khai báo lại biến với `var`

---

Nếu bạn **khai báo biến hai lần** với `let` ở cùng một phạm vi thì sẽ có lỗi xảy ra:

```js
let user;
let user; // SyntaxError: 'user' has already been declared
```

Với `var` thì khác, bạn có thể **khai báo lại biến với số lần tùy ý**:

```js
var user = "Alex";
var user = "Anna";

console.log(user); // Anna
```

## Có thể sử dụng biến trước khi khai báo với `var`

---

Biến khai báo sử dụng `var` được xử lý khi hàm bắt đầu (hoặc bắt đầu chương trình với phạm vi toàn cục), ví dụ:

```js
function sayHi() {
  message = "Hello";

  console.log(message);

  var message;
}

sayHi(); // Hello
```

Đoạn code trên không có lỗi và tương đương với cách viết sau:

```js
function sayHi() {
  var message;
  message = "Hello";

  console.log(message);
}

sayHi(); // Hello
```

Hoặc thậm chí là (nhớ rằng biến với `var` không có phạm vi block):

```js
function sayHi() {
  message = "Hello";

  if (false) {
    var message;
  }

  console.log(message);
}

sayHi(); // Hello
```

Việc có thể sử dụng biến với `var` trước khi khai báo được gọi là **hoisting**. Nghĩa là tất cả biến được khai báo với `var` sẽ được đưa lên đầu của hàm.

Trong đoạn code trên, nhánh `if (false)` không bao giờ được thực hiện. Nhưng câu lệnh khai báo `var message` vẫn được đưa lên đầu hàm. Do đó, việc sử dụng biến `message` không bị lỗi.

**Chú ý:** Khai báo biến với `var` được **hoisted** nhưng lệnh gán thì không, ví dụ:

```js
function sayHi() {
  console.log(message);

  var message = "Hello";
}

sayHi(); // undefined
```

Dòng `var message = "Hello"` thực hiện hai hành động:

- Khai báo biến `var message`.
- Gán giá trị cho biến `message = "Hello"`.

Phần khai báo biến được đưa lên đầu hàm, nhưng phần gán giá trị của biến vẫn giữ nguyên vị trí. Đó là lý do tại sao kết quả in ra là `undefined`.

Đoạn code trên tương đương với:

```js
function sayHi() {
  var message;
  console.log(message);

  message = "Hello";
}

sayHi(); // undefined
```

## Cách sử dụng IIFE trong JavaScript

Trước đây, JavaScript chỉ dùng `var` để khai báo biến. Mà biến khai báo với `var` lại không có phạm vi block. Vì vậy, người ta đã phát minh ra cách để mô phỏng phạm vi block này.

Và cách đó gọi là **IIFE**, viết tắt của **immediately-invoked function expressions**.

Ví dụ một đoạn code sử dụng IIFE như sau:

```js
(function () {
  var message = "Hello";

  console.log(message); // Hello
})();
```

Trong ví dụ trên, một [biểu thức hàm](/bai-viet/javascript/function-expression-trong-javascript) được **tạo ra và thực hiện ngay lập tức**. Khi đoạn code trên thực hiện xong, không có cách nào để truy cập vào biến `message` từ phạm vi bên ngoài.

Đó chính là lợi ích khi sử dụng IFFE.

Với IFFE, biểu thức hàm được **đặt trong cặp dấu ngoặc đơn** `(function(){...})`. Bởi vì, [JavaScript Engine](/bai-viet/javascript/gioi-thieu-javascript#javascript-engine-l%C3%A0-g%C3%AC) hiểu từ khóa `function` dùng để khai báo hàm. Mà khai báo hàm thì cần phải có tên.

Do đó, khi mình bỏ dấu ngoặc đơn để khai báo IFFE thì sẽ bị lỗi:

```js
// Định nghĩa IFFE mà không dùng dấu ngoặc đơn -> lỗi:
function() { // <-- SyntaxError: Function statements require a function name
  var message = "Hello";
  console.log(message);
}();
```

Thậm chí là khi **viết thêm tên** vào thì vẫn sẽ có lỗi:

```js
function sayHi() {
  var message = "Hello";
  console.log(message);
}(); // -> JS không cho phép gọi hàm ngay khi khai báo
```

Việc đặt biểu thức hàm bên trong cặp dấu `()` để JavaScript hiểu rằng hàm được tạo ra ở một biểu thức khác. Vì vậy, biểu thức hàm trong trường hợp này **không cần tên và có thể gọi ngay lập tức**.

Ngoài ra, có một vài cách khác để khai báo IFFE như sau:

```js
(function () {
  console.log("Dấu ngoặc đơn bao quanh function");
})();

(function () {
  console.log("Dấu ngoặc đơn bao quanh tất cả");
})();

!(function () {
  console.log("Toán tử bitwise ! bắt đầu hàm");
})();

+(function () {
  console.log("Toán tử + bắt đầu hàm");
})();
```

📝 **Chú ý:** với cú pháp JS hiện đại, bạn không nên (không cần thiết) viết code theo cú pháp như này.

Những cách viết trên chỉ nhằm mục đích giúp bạn hiểu về `var`, cách sử dụng `var` và IFFE trong JavaScript.

Để khi bạn gặp phải những mã nguồn cũ sử dụng `var` và IFFE, bạn vẫn có thể hiểu được logic chương trình và dễ dàng chuyển sang sử dụng `let/const` khi cần thiết.

## Tổng kết

Có hai điểm chính khác nhau giữa `var` và `let/const` là:

- Biến khai báo với `var` không có phạm vi block mà có phạm vi hàm hoặc toàn cục (nếu khai báo bên ngoài hàm).
- Việc khai báo biến với `var` được thực hiện khi hàm bắt đầu (hoặc khi bắt đầu chương trình với biến toàn cục).

Điểm khác nhau khiến `var` trở nên lỗi thời và không được sử dụng trong lập trình JavaScript hiện đại.
