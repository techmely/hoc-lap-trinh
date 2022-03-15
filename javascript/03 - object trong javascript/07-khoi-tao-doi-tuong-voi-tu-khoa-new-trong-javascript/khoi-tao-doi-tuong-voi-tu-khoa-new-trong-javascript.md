---
title: "Khởi tạo đối tượng với từ khóa new trong javascript có tác dụng gì"
description: "Trong hướng dẫn này, mình sẽ giúp bạn tìm hiểu về cách sử dụng từ khóa new để tạo một đối tượng."
keywords: [
"đối tượng trong javascript",
"object trong javascript",
"từ khóa New trong Javascript",
"new trong javascript",
"new in javascript",
"tu khoa new trong javascript là gì",
"cach su dung tu khoa new trong javascript",
"từ khóa new trong javascript có tác dụng gì",
"từ khóa new trong javascript cơ bản",
"từ khóa new trong javascript nghĩa là gì"
]
chapter:
  name: "Object trong Javascript"
  slug: "chuong-03-object-trong-javascript"
category:
  name: "Javascript"
  slug: "javascript"
image: https://kungfutech.edu.vn/thumbnail.png
position: 7
---

Trong các bài viết trước, mình chủ yếu dùng cú pháp `{...}` để [khởi tạo object](/bai-viet/javascript/object-la-gi-object-trong-javascript/). Tuy nhiên, cách này chỉ dùng để **khởi tạo một object riêng lẻ**.

Nếu mình muốn khởi tạo **nhiều object tương tự nhau** thì sao?

Để giải quyết vấn đề này, bạn có thể sử dụng toán tử `new` trong JavaScript kết hợp với một [hàm](/bai-viet/javascript/ham-trong-javascript/) khởi tạo.

## Hàm khởi tạo và new trong JavaScript là gì?

Hàm khởi tạo về bản chất là **một hàm bình thường**, nhưng dùng để **khởi tạo object**.

Một số đặc điểm của hàm khởi tạo là:

- Hàm khởi tạo thường được **viết hoa chữ cái đầu** (không bắt buộc) để dễ dàng phân biệt với các hàm bình thường.
- Hàm khởi tạo **chỉ nên sử dụng** với toán tử `new` trong JavaScript.

Ví dụ:

```js
function Point(x, y) {
  this.x = x;
  this.y = y;
}

let root = new Point(0, 0);
console.log(root.x, root.y); // 0 0
```

Khi một hàm được gọi với toán tử `new`, JavaScript Engine sẽ xử lý các bước như sau:

1.  Khởi tạo object rỗng và gán cho [`this`](/bai-viet/javascript/this-trong-javascript/).
2.  Các câu lệnh trong thân hàm được thực thi, thường là cập nhật `this` hoặc thêm các thuộc tính cho `this`.
3.  Trả về giá trị của `this`.

Nói cách khác, cú pháp `new Point(...)` thực hiện:

```js
function Point(x, y) {
  // this = {}; // ngầm định khởi tạo object rỗng
  this.x = x;
  this.y = y;

  // return this; // ngầm định trả về this}
}
```

Như vậy, `new Point(0,0)` tương đương với cách khởi tạo object là:

```js
let root = {
  x: 0,
  y: 0,
};
```

Bây giờ, nếu bạn muốn tạo ra các **point** khác, bạn chỉ cần gọi `new p1(1, 2)`, `new p2(2, 3)`,... thay vì phải sử dụng cú pháp `{...}` nhiều lần (và dài dòng hơn).

<content-warning>

📝 **Chú ý:**

**Mục đích chính của hàm khởi tạo** là để dễ dàng **tái sử dụng code**.

[Arrow function](/bai-viet/javascript/arrow-function-la-gi-arrow-function-trong-js/) không có `this` nên không được dùng làm hàm khởi tạo.

</content-warning>

Nếu hàm khởi tạo không có tham số thì bạn có thể bỏ qua cặp dấu ngoặc đơn `()`, ví dụ:

```js
function Point() {
  this.x = 0;
  this.y = 0;
}

let root = new Point();
console.log(root.x, root.y); // 0
```

> Tuy nhiên, mình khuyên bạn nên sử dụng cách gọi hàm khởi tạo với cặp dấu ng`()`, vì nó chuẩn hơn và **đúng với cú pháp gọi hàm**.

Bạn có thể khai báo, đồng thời khởi tạo object ngay với cú pháp `new function(){...}` như sau:

```js
let root = new (function () {
  this.x = 1;
  this.y = 2;

  /*
   * Code xử lý khác tại đây
   */
})();

console.log(root.x, root.y); // 1 2
```

Cú pháp này gọi là [IFFE](https://en.wikipedia.org/wiki/Immediately_invoked_function_expression).

Khi tạo object theo cách này, hàm khởi tạo sẽ chỉ được gọi một lần (vì bản chất hàm khởi tạo **không được lưu vào biến nào**).

Vì vậy, mục đích của cách khai báo này **không phải để tái sử dụng**, mà để đóng gói code liên quan trong một hàm khởi tạo.

## Kiểm tra hàm khởi tạo được gọi với new trong JavaScript

Để kiểm tra hàm khởi tạo có được gọi với new trong JavaScript hay không, bạn sử dụng thuộc tính đặc biệt là `new.target`.

Nếu hàm được gọi theo cách thông thường thì `new.target` sẽ bằng `undefined`, ngược lại `new.target` bằng chính function:

```js
function Point() {
  console.log(new.target);
}

Point(); // undefined
new Point(); // ƒ Point() { console.log(new.target); }
```

Thuộc tính đặc biệt này có thể được áp dụng để kiểm tra xem hàm khởi tạo có được gọi với `new` hay không.

Trường hợp hàm khởi tạo không được gọi với `new`, mình có thể xử lý thêm để trả về giống cách gọi hàm với `new`:

```js
function Point(x, y) {
  if (!new.target) {
    return new Point(x, y);
  }
  this.x = x;
  this.y = y;
}

let root = Point(0, 0);
console.log(root.x, root.y); // 0 0
```

Với cách viết như này, bạn có thể khởi tạo object với `new` hoặc không có `new` thì đều cho kết quả giống nhau.

<content-warning>

💡 **Chú ý:**

`new.target` ít được sử dụng trong thực tế.

Việc khởi tạo object **nên luôn luôn sử dụng từ khóa `new`** để đảm bảo code rõ ràng và dễ hiểu nhất.

</content-warning>

## Trả về giá trị từ hàm khởi tạo

Thông thường, hàm khởi tạo không có từ khóa `return` vì JavaScript Engine ngầm định sẽ trả về `this`. Tuy nhiên, bạn có thể sử dụng `return` trong hàm khởi tạo với quy tắc như sau:

- Nếu `return` được gọi với **object** thì giá trị trả về của hàm khởi tạo là object chứ không phải `this`.
- Nếu `return` được gọi với giá trị nguyên thủy, `return` sẽ bị bỏ qua.

Nói cách khác, `return` với một object sẽ trả về object đó, ngược lại thì trả về `this`.

Ví dụ hàm khởi tạo trả về một object khác `this`:

```js
function Point(x, y) {
  this.x = x;
  this.y = y;

  return { x: 100, y: 100 }; // trả về object này thay vì this}
}

let p = new Point(0, 0);
console.log(p.x, p.y); // 100 100
```

Ví dụ hàm khởi tạo trả về giá trị nguyên thủy:

```js
function Point(x, y) {
  this.x = x;
  this.y = y;

  return 1; // return trả về giá trị nguyên thủy bị bỏ qua}
}
let p = new Point(0, 0);
console.log(p.x, p.y); // 0 0
```

## Định nghĩa phương thức trong hàm khởi tạo

Object không chỉ có thuộc tính mà còn có cả [phương thức](/bai-viet/javascript/phuong-thuc-trong-javascript/).

Và dĩ nhiên, bạn có thể **định nghĩa phương thức trong hàm khởi tạo** của object, ví dụ:

```js
function Point(x, y) {
  this.x = x;
  this.y = y;

  this.printLog = function () {
    console.log(this.x, this.y);
  };
}

let root = new Point(0, 0);
root.printLog(); // 0 0
```

Để tạo nhiều object phức tạp hơn, bạn có thể sử dụng cú pháp nâng cao hơn như **prototype** hay **class** (sẽ được giới thiệu sau).

## Tổng kết

Sau đây là những kiến thức cơ bản cần nhớ về khởi tạo object với toán tử `new` trong JavaScript:

- Hàm khởi tạo là một hàm thông thường nhưng được dùng để khởi tạo object.
- Hàm khởi tạo thường viết hoa chữ cái đầu tiên.
- Hàm khởi tạo chỉ nên sử dụng với toán tử `new`. Khi đó, JavaScript ngầm định tạo ra một object rỗng ở đầu hàm và gán cho `this`. Sau đó, cuối hàm sẽ `return` về `this`.
- Arrow function không có `this` nên không được dùng làm hàm khởi tạo.
- Bạn có thể khai báo và gọi hàm ngay lập tức với cú pháp IFFE `new function(){...}`
- Thường hàm khởi tạo không có `return`. Nếu hàm khởi tạo có `return` thì quy tắc là: `return` với một object sẽ trả về object đó, ngược lại thì trả về `this`.
- Bạn có thể định nghĩa phương thức trong hàm khởi tạo.

## Thực hành

### Bài 1

Cho đoạn code sau:

```js
function A() { ... }
    function B() { ... }

    let a = new A;
    let b = new B;

    console.log(a === b); // true
```

Có cách nào để tạo hàm `A` và `B` sao cho `new A() === new B()`?

Xem đáp án

Đáp án là: **Có**.

Để `new A() === new B()` là `true` thì hàm khởi tạo `A` và `B` phải trả về cùng một object.

```js
let obj = {};
function A() {
  return obj;
}
function B() {
  return obj;
}
let a = new A();
let b = new B();

console.log(a === b); // true
```

### Bài 2

Viết hàm khởi tạo object `Calculator` với ba phương thức:

- `read()`: sử dụng hàm [`prompt`](/bai-viet/javascript/ham-tuong-tac-voi-nguoi-dung-alert-confirm-prompt/) đọc hai giá trị và lưu vào hai thuộc tính của object (giả sử người dùng nhập vào là số).
- `add()`: trả về tổng của hai số đã nhập.
- `mul()`: trả về tích của hai số đã nhập.

Ví dụ:

```js
let calculator = new Calculator();
calculator.read();
console.log(calculator.sum());
console.log(calculator.mul());
```

Xem đáp án

```js
function Calculator() {
  // Phương thức read()
  this.read = function () {
    this.a = +prompt("Nhập vào số a:", 0);
    this.b = +prompt("Nhập vào số b:", 0);
  };

  // Phương thức add()
  this.add = function () {
    return this.a + this.b;
  };

  // Phương thức mul()
  this.mul = function () {
    return this.a * this.b;
  };
}

let calculator = new Calculator();
calculator.read();
console.log(calculator.add());
console.log(calculator.mul());
```

**Chú ý:** hàm `prompt` trả về kết quả là string. Vì vậy, mình thêm toán tử `+` đằng trước để [chuyển đổi kiểu dữ liệu](/bai-viet/javascript/chuyen-doi-kieu-du-lieu-trong-javascript/) về number, trước khi gán cho `this.a` và `this.b`.

### Bài 3

Viết hàm khởi tạo `Counter(startValue)` (giả sử `startValue` là số).

Object tạo ra có những đặc điểm sau:

- Giá trị `startValue` được lưu vào thuộc tính `value`.
- Phương thức `read()` sử dụng hàm `prompt()` để yêu cầu người dùng nhập vào một số. Sau đó, giá trị số người dùng nhập sẽ được cộng dồn vào thuộc tính `value`.

Ví dụ:

```js
let counter = new Counter(1);

counter.read();
counter.read();

console.log(counter.value); // giá trị hiện tại của value
```

Xem đáp án

```js
function Counter(startValue) {
  this.value = startValue;

  this.read = function () {
    this.value += +prompt("Nhập vào một số:", 0);
  };
}

let counter = new Counter(1);

counter.read();
counter.read();

console.log(counter.value); // giá trị hiện tại của value
```
