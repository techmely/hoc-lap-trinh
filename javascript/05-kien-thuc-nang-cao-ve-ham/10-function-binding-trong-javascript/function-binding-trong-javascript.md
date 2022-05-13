---
title: "Function binding trong Javascript"
description: "Tìm hiểu cách sử dụng hàm bind trong Javascript, phân tích cách khắc phục đối tượng this trong hàm closure bằng cách sử dụng hàm bind trong Javascript."
keywords: [
"Function binding trong Javascript",
"Function binding trong Javascript là gì",
"Function binding trong Javascript dùng làm gì",
"function binding trong javascript",
"bind javascript",
"Bind trong JavaScript",
"Bind trong JavaScript để làm gì",
"hàm bind javascript",
"function binding trong javascript là gì"
]
chapter:
  name: "Kiến thức nâng cao về hàm"
  slug: "chuong-05-kien-thuc-nang-cao-ve-ham"
category:
  name: "Javascript"
  slug: "javascript"
image: https://kungfutech.edu.vn/thumbnail.png
position: 10
---

Khi sử dụng [phương thức của object](/bai-viet/javascript/phuong-thuc-trong-javascript) làm hàm callback, ví dụ sử dụng với hàm [`setTimeout`](/bai-viet/javascript/ham-settimeout-trong-javascript), thường xảy ra vấn đề là: "mất giá trị `this`".

Sau đây, mình sẽ cùng tìm hiểu cách sử dụng **function binding** để khắc phục tình trạng này.

## Vấn đề mất `this`

Ví dụ sử dụng hàm `setTimeout` như sau:

```js
let user = {
  firstName: "Alex",
  sayHi() {
    console.log(`Hello, ${this.firstName}!`);
  },
};

setTimeout(user.sayHi, 1000); // Hello, undefined! (*)
```

Kết quả hiển thị sau 1000ms là `Hello, undefined!`.

Đó là bởi vì hàm `setTimeout` sử dụng hàm `sayHi` một cách độc lập với đối tượng `user`. Dòng `(*)` có thể viết lại tương đương là:

```js
let func = user.sayHi;
setTimeout(func, 1000); // mất context của `this`
```

Đối với trình duyệt, hàm `setTimeout` gán giá trị `this=window` khi gọi hàm callback. Vì vậy, `this.firstName` trở thành `window.firstName`. Mà đối tượng `window` không chứa thuộc tính `firstName`, dẫn đến kết quả là `undefined`.

Vậy câu hỏi đặt ra là: làm sao truyền phương thức của object vào phương thức khác mà vẫn giữ nguyên context `this`?

## Giải pháp sử dụng hàm wrapper

Cách đơn giản nhất để tránh mất this là **sử dụng hàm wrapper**:

```js
let user = {
  firstName: "Alex",
  sayHi() {
    console.log(`Hello, ${this.firstName}!`);
  },
};

setTimeout(function () {
  user.sayHi(); // Hello, Alex!
}, 1000);
```

Kết quả hiển thị đã chính xác như mong muốn. Bởi vì khi `setTimeout` gọi hàm callback, giá trị của `user` được lấy từ phạm vi bên ngoài, rồi gọi phương thức `sayHi` của `user` như bình thường.

Ngoài ra, bạn có thể sử dụng [arrow function](/bai-viet/javascript/arrow-function-trong-javascript) cho ngắn gọn:

```js
setTimeout(() => user.sayHi(), 1000); // Hello, Alex!
```

Nhìn chung, cách sử dụng hàm wrapper này khá đơn giản và dễ hiểu. Tuy nhiên, cách này lại tiểm ẩn khả năng xảy ra lỗi.

Giả sử, trước khi hàm `setTimeout` gọi hàm callback mà giá trị của `user` lại bị thay đổi thì kết quả hiển thị sẽ không đúng như mong đợi:

```js
let user = {
  firstName: "Alex",
  sayHi() {
    alert(`Hello, ${this.firstName}!`);
  },
};

// delay 1 giây
setTimeout(() => user.sayHi(), 1000);

// trong lúc đó, giá trị của `user` thay đổi
user = {
  sayHi() {
    console.log("User khác được dùng trong setTimeout!");
  },
};

// User khác được dùng trong setTimeout!
```

Cách thứ hai sau đây sẽ đảm bảo tình trạng này không xảy ra.

## Sử dụng function binding trong JavaScript

Function trong JavaScript có sẵn một phương thức là `bind` cho phép không làm thay đổi giá trị của `this`, với cú pháp cơ bản như sau:

```js
let boundFunc = func.bind(context);
```

Kết quả của `func.bind(context)` là một **đối tượng đặc biệt**. Đối tượng này có thể được gọi như hàm và luôn cố định giá trị `this=context`, ví dụ:

```js
let user = {
  firstName: "Alex",
};

function func() {
  console.log(this.firstName);
}

let funcUser = func.bind(user);
funcUser(); // Alex
```

Trong ví dụ trên, `func.bind(user)` cố định giá trị của `this=user`.

Ngoài ra, `func.bind` có thể sử dụng với hàm có tham số như sau:

```js
let user = {
  firstName: "Alex",
};

function func(message) {
  console.log(message + ", " + this.firstName);
}

// bind `this` với user
let funcUser = func.bind(user);

funcUser("Hello"); // Hello, Alex (message="Hello" và this=user)
```

Bây giờ, hãy thử binding function với phương thức của object:

```js
let user = {
  firstName: "Alex",
  sayHi() {
    console.log(`Hello, ${this.firstName}!`);
  },
};

let sayHi = user.sayHi.bind(user); // (*)
// có thể gọi hàm mà không cần object
sayHi(); // Hello, Alex!

setTimeout(sayHi, 1000); // Hello, Alex!

// thậm chí là khi giá trị của user thay đổi
// sayHi vẫn tham chiếu tới giá trị user lúc được bind
user = {
  sayHi() {
    console.log("User đã thay đổi!");
  },
};
```

Tại `(*)`, phương thức `user.sayHi` đã bind giá trị `this=user`. Kết quả trả về là hàm `sayHi` - có thể gọi độc lập và giá trị `this` luôn bằng `user` tại thời điểm bind.

## Partial function

Mình mới đề cập tới vấn đề binding function với `this`. Thực tế, bạn có thể thực hiện binding cả tham số. Cú pháp đầy đủ của binding function là:

```js
let bound = func.bind(context, [arg1], [arg2],...);
```

Phương thức `bind` cho phép bind giá trị `this=context` và sau đó là các tham số của hàm.

Ví dụ mình có hàm tính tích hai số như sau:

```js
function mul(a, b) {
  return a * b;
}
```

Bây giờ, mình có thể sử dụng `bind` để tạo ra hàm **nhân đôi**:

```js
function mul(a, b) {
  return a * b;
}

let double = mul.bind(null, 2);
console.log(double(3)); // = mul(2, 3) = 6
console.log(double(4)); // = mul(2, 4) = 8
console.log(double(5)); // = mul(2, 5) = 10
```

Trong ví dụ trên `mul.bind(null, 2)` tạo ra hàm mới `double` với giá trị `this=null` và `a=2`. Khi gọi hàm với `double`, bạn chỉ cần truyền vào giá trị của tham số `b`.

Cách này gọi **partial function**.

<content-warning>

hàm `double` không sử dụng `this`. Tuy nhiên, hàm `bind` lại yêu cầu `this`. Vì vậy, tham số đầu tiên mình để `null`.

</content-warning>

Tương tự, mình có thể tạo ra hàm nhân ba `triple` như sau:

```js
function mul(a, b) {
  return a * b;
}

let triple = mul.bind(null, 3);
console.log(triple(3)); // = mul(3, 3) = 9
console.log(triple(4)); // = mul(3, 4) = 12
console.log(triple(5)); // = mul(3, 5) = 15
```

**Tại sao lại sử dụng partial function?**

Lợi ích của việc sử dụng partial function là mình có các hàm với tên dễ hiểu `double`, `triple`.

Đồng thời, mình có thể gọi các hàm này một cách độc lập và không cần phải gọi hàm `mul` với giá trị tham số đầu tiên luôn luôn cố định bằng `2` với `double` hoặc bằng `3` với `triple`.

## Partial function không cố định context

Giả sử mình cần cố định một vài tham số của hàm, ngoại trừ context, ví dụ khi hàm là phương thức của object.

Phương thức `func.bind` không cho phép bạn làm điều đó. Vì bạn **không thể bỏ qua context** rồi nhảy ngay đến các tham số. Bởi lẽ, `func.bind` luôn hiểu tham số đầu tiên là context cho `this`.

Để giải quyết vấn đề này bạn có thể triển khai hàm `partial` như sau:

```js
function partial(func, ...argsBound) {
  return function (...args) {
    return func.call(this, ...argsBound, ...args);
  };
}
// Sử dụng:
let user = {
  firstName: "Alex",
  say(time, message) {
    console.log(`[${time}] ${this.firstName}: ${message}!`);
  },
};

// tạo phương thức partial với giá trị của `time` cố định
user.sayNow = partial(
  user.say,
  new Date().getHours() + ":" + new Date().getMinutes()
);

user.sayNow("Hello");
// Kết quả có dạng như sau: [10:00] Alex: Hello!
```

Trong ví dụ trên, kết quả của việc gọi hàm `partial` là một hàm wrapper với:

- Giá trị của `this` được lấy lúc gọi hàm. Ví dụ khi gọi `user.sayNow` thì `this=user`.
- `...argsBound` là tham số từ hàm `partial`, giả sử là `"10:00"`.
- `...args` là tham số của hàm wrapper, ví dụ là `"Hello"`.

## Tổng kết

Phương thức `func.bind(context, ...args)` trả về một hàm đặc biệt với việc cố định giá trị `this=context` và các tham số đầu tiên (nếu có).

Khi một vài tham số đầu tiên được cố định, thì kết quả trả về được gọi là **partial function**.

Partial functions hữu ích khi bạn **không muốn lặp lại việc truyền các tham số giống nhau** ở các lần gọi hàm.

## Thực hành

### Bài 1

Cho đoạn code sau, hỏi kết quả trả về là gì?

```js
"use strict";

function f() {
  console.log(this); // ?
}

let user = {
  g: f.bind(null),
};

user.g();
```

<content-result>

null

</content-result>

Phương thức `user.g` được gán bằng `f.bind(null)`. Nghĩa là giá trị của `this` trong hàm `f` luôn là `null`.

### Bài 2

Khi gọi `bind` nhiều lần, giá trị của `this` có thay đổi không?

```js
function f() {
  console.log(this.name);
}

f = f.bind({ name: "Alex" }).bind({ name: "Anna" });

f(); // (*)
```

Kết quả `(*)` là gì?

<content-result>
Alex
</content-result>

Khi gọi `f.bind(context)`, kết quả trả về là một đối tượng đặc biệt. Đối tượng này ghi nhớ giá trị của `this=context` tại thời điểm bind và không thể bị thay đổi.

Do đó, lần gọi `bind` thứ hai là không có tác dụng.

### Bài 3

Giả sử hàm có chứa một thuộc tính. Hỏi sau khi `bind`, giá trị của thuộc tính như thế nào?

```js
function sayHi() {
  console.log(this.name);
}

// thuộc tính của hàm
sayHi.test = 5;

// gọi bind
let bound = sayHi.bind({
  name: "Alex",
});

console.log(bound.test); // (*)
```

Kết quả `(*)` là gì?

<content-result>
undefined
</content-result>

Bởi vì kết quả của `bind` là một đối tượng khác. Và đối tượng này không chứa thuộc tính `test`.

Tham khảo:

- [Function binding](https://javascript.info/bind)
- [Decorator, forwarding của hàm trong JS](/bai-viet/javascript/decorator-forwarding-cua-ham-trong-javascript)
- [Phân biệt call, apply và bind trong JavaScript](/phan-biet-call-apply-va-bind-trong-javascript/)
