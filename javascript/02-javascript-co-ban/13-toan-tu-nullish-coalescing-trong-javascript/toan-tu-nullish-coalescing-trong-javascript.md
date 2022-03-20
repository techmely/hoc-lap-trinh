---
title: "Toán tử ?? trong JavaScript"
description: "Toán tử ?? trong JavaScript"
keywords: ["khoá học javascript",
"Toán tử ?? trong JavaScript",
"Toán tử ??",
"cach su dung toan tu ?? trong javascript",
"Cách sử dụng toán tử Nullish Coalescing",
"toán tử js",
"Nullish Coalescing",
"Nullish Coalescing la gi"
]
chapter:
  name: "Javascript cơ bản"
  slug: "chuong-02-javascript-co-ban"
category:
  name: "Javascript"
  slug: "javascript"
image: https://kungfutech.edu.vn/thumbnail.png
position: 13
---

Toán tử Nullish Coalescing ký hiệu `??` (toán tử hai dấu chấm hỏi) là toán tử mới trong JavaScript.

Sau đây, mình sẽ cùng tìm hiểu xem toán tử Nullish Coalescing là gì và ứng dụng của toán tử này trong JavaScript như thế nào.

## Toán tử Nullish Coalescing là gì?

Toán tử Nullish Coalescing là toán tử hai ngôi `a ?? b`, với định nghĩa là:

- Nếu `a` khác `null` và `undefined` thì kết quả của `a ?? b` là `a`.
- Ngược lạị, nếu `a` bằng `null` hoặc `undefined` thì kết quả của `a ?? b` là `b`.

<content-example />

```js
result = a ?? b;
```

Nếu a khác `null` và `undefined` thì `r` sẽ bằng `a`. Ngược lại, `r` bằng `b`.

Đọc đến đây chắc bạn có liên tưởng đến [toán tử `?`](/bai-viet/khoa-hoc-javascript/cau-truc-re-nhanh-trong-javascript). Vì mình có thể viết lại `result = a ?? b` bằng cách sử dụng toán tử `?` như sau:

```js
result = a !== null && a !== undefined ? a : b;
```

Tuy nhiên, nếu so sánh đoạn code này với đoạn code trên (sử dụng toán tử `??`) thì rõ ràng việc sử dụng toán tử `??` là ngắn gọn hơn.

## Ứng dụng của toán tử Nullish Coalescing

Toán tử Nullish Coalescing thường dùng để cung cấp giá trị mặc định cho một biến có thể `null` hoặc `undefined`.

Ví dụ với biến có giá trị `undefined`:

```js
let name;

console.log(name ?? "Người dùng ẩn danh"); // Người dùng ẩn danh
```

Ví dụ với biến có giá trị khác `undefined` và `null`:

```js
let name = "jsDev";

console.log(name ?? "Người dùng ẩn danh"); // jsDev
```

Ngoài ra, bạn có thể sử dụng nhiều toán tử `??` liên tiếp nhau:

```js
let fullName;
let nickName = "jsDev";

const displayName = fullName ?? nickName ?? "Người dùng ẩn danh";
console.log(displayName); // jsDev
```

## So sánh toán tử `??` và toán tử `||`

Trong bài viết [toán tử logic trong JavaScript](/bai-viet/khoa-hoc-javascript/toan-tu-logic-trong-javascript), mình cũng đã giới thiệu về toán tử `||` với ứng dụng tương tự như ví dụ trên:

```js
let fullName;
let nickName = "jsDev";

const displayName = fullName || nickName || "Người dùng ẩn danh";
console.log(displayName); // jsDev
```

Bạn thấy rằng kết quả là như nhau.

**Vậy toán tử `??` khác với toán tử `||` như thế nào?**

Cụ thể:

- Toán tử `??` trả về giá trị khác `null` và `undefined` đầu tiên.
- Toán tử `||` trả về giá trị **truthy** đầu tiên.

Hay nói cách khác, toán tử `||` không phân biệt được các giá trị `false`, `0`, string rỗng `""` với `null`/`undefined`. Vì chúng đều là các giá trị **falsy**.

Đôi khi bạn chỉ muốn sử dụng giá trị mặc định khi biến có giá trị `null` hoặc `undefined`, ví dụ:

```js
let length = 0;

console.log(length || 10); // 10
console.log(length ?? 10); // 0
```

Trong ví dụ trên:

- `length = 0` nên `length` là giá trị **falsy**. Vì vậy, đáp án câu lệnh `console.log` đầu tiên là `10`.
- Và cũng vì `length = 0` nên `length` khác `null` và `undefined`. Do đó, đáp án câu lệnh `console.log` thứ hai là `0`.

> 💡 Ví dụ trên sử dụng toán tử `??` phù hợp hơn. Vì thực tế, số `0` cũng là giá trị hợp lệ đối với biến `length`.

## Thứ tự ưu tiên của toán tử `??`

Toán tử `??` có [thứ tự ưu tiên](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Operators/Operator_Precedence#table) gần tương đương (thấp hơn một chút) so với toán tử `||`.

Nghĩa là toán tử Nullish Coalescing được thực hiện trước toán tử gán `=`, toán tử dấu hỏi `?` và thực hiện sau so với các toán tử khác, như toán tử số học `+`, `*`,...

Nếu bạn không chắc chắn về thứ tự ưu tiên thì nên sử dụng cặp dấu ngoặc đơn `()`, ví dụ:

```js
let x;
let y;

const sum = (x ?? 2) * (y ?? 3); // => 2 * 3console.log(sum); // 6
```

Trong ví dụ trên, nếu bạn không sử dụng cặp dấu ngoặc đơn `()` thì kết quả sẽ khác:

```js
let x;
let y;

const sum = x ?? 2 * y ?? 3;
console.log(sum); // NaN
```

Bởi vì, toán tử `*` có độ ưu tiên cao hơn toán tử `??` nên phép tính `2 * y` được thực hiện trước. Mà `y` có giá trị `undefined` nên `2 * y` bằng `NaN`.

Mà `NaN` lại khác `null` và `undefined` nên kết quả của `x ?? NaN ?? 3` là `NaN`.

## Sử dụng toán tử `??` cùng với toán tử `&&` hoặc `||`

Vì lý do an toàn nên JavaScript cấm sử dụng toán tử `??` với toán tử `&&` hoặc `||` - trừ khi sử dụng cùng với cặp dấu ngoặc đơn `()`.

Ví dụ sau đây sẽ bị lỗi:

```js
let x = 1 && 2 ?? 3; // Uncaught SyntaxError: Unexpected token '??'
```

Để tránh lỗi, bạn phải sử dụng cặp dấu ngoặc đơn `()`:

```js
let x = (1 && 2) ?? 3; // => 2 ?? 3
console.log(x); // 2

let y = 1 && (2 ?? 3); // => 1 && 2
console.log(y); // 2
```

## Tổng kết

Toán tử Nullish Coalescing `??` là toán tử hai ngôi, dùng để trả về giá trị khác `null` và `undefined` đầu tiên.

Toán tử `??` thường dùng để gán giá trị mặc định cho biến (có thể `null` hoặc `undefined`).

Toán tử `??` có độ ưu tiên cao hơn toán tử gán `=` và toán tử dấu hỏi `?`, nhưng thấp hơn hầu hết các toán tử còn lại. Vì vậy, bạn nên sử dụng cặp dấu ngoặc đơn `()` để tránh mắc lỗi không mong muốn.

JavaScript cấm sử dụng toán tử `??` trực tiếp với toán tử `||` hoặc toán tử `&&` - trừ khi sử dụng cùng với cặp dấu ngoặc đơn `()`.
