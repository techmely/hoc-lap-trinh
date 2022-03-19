---
title: "Đối tượng bất biến trong Javascript"
description: "Khi làm việc với javascript, hẳn mọi người đã nghe đến tính bất biến của dữ liệu (immutability). Đặc tính này, nói một cách đơn giản, là khả năng giá trị của dữ liệu không bị thay đổi sau khi đã được khai báo."
keywords: [
"đối tượng trong javascript",
"object trong javascript",
"Đối tượng bất biến trong Javascript",
"Đối tượng bất biến trong Javascript là gì",
"Bất biến trong javascript",
"tính bất biến của dữ liệu trong javascript",
"bat bien trong javascript là gì",
"đảm bảo tính bất biến trong JavaScript",
"bat bien javascript",
"tinh bat bien javascript",
"tinh bat bien javascript la gi"
]
chapter:
  name: "Object trong Javascript"
  slug: "chuong-03-object-trong-javascript"
category:
  name: "Javascript"
  slug: "javascript"
image: https://kungfutech.edu.vn/thumbnail.png
position: 8
---

Thông thường, [object](/bai-viet/javascript/object-la-gi-object-trong-javascript/) trong JavaScript là **mutable** - nghĩa là trạng thái của object có thể thay đổi được. Nói cách khác là **giá trị các thuộc tính trong Object có thể thay đổi được**, ví dụ:

```js
let obj = {}; // khởi tạo object rỗng

obj.a = 1; // thêm thuộc tính a và gán giá trị 1
obj["a"] = 2; // cập nhật giá trị thuộc tính a bằng 2

console.log(obj.a); // 2
```

Có nhiều trường hợp bạn muốn object đó là **immutable** - trạng thái không thể thay đổi được. Sau đây, mình sẽ giới thiệu với bạn **2 cách tạo immutable object** trong JavaScript.

## Tạo immutable object sử dụng `Object.defineProperty`

[`Object.defineProperty()`](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Object/defineProperty) **định nghĩa một thuộc tính mới** hoặc **cập nhật thuộc tính có sẵn** trên object.

### Cách sử dụng `Object.defineProperty`

Để tạo immutable object sử dụng `Object.defineProperty`, bạn chỉ cần định nghĩa property với thuộc tính `writable` (có thể ghi đè) là `false`, ví dụ:

```js
let obj = {};

    // định nghĩa thuộc tính a trong obj
    Object.defineProperty(obj, "a", {
      value: 1, // giá trị là 1
      writable: false, // writable: false - nghĩa là không thể ghi đè});

    obj.a = 2; // thử ghi đè giá trị khác vào a
    console.log(obj.a); // 1 - kết quả giá trị của a vẫn không đổi
```

Bạn thấy rằng giá trị của `obj.a` không thay đổi so với giá trị ban đầu, vẫn là `1`. Đó chính là **tính bất biến**.

Nếu sử dụng ở [strict mode](/bai-viet/javascript/strict-mode-trong-javascript/) thì đoạn code trên sẽ sinh ra lỗi:

```js
"use strict";
let obj = {};

// định nghĩa thuộc tính a trong obj
Object.defineProperty(obj, "a", {
  value: 1, // giá trị là 1
  writable: false, // writable: false - nghĩa là không thể ghi đè
});

obj.a = 2;
// Uncaught TypeError:// Cannot assign to read only property 'a' of object '#<Object>'
console.log(obj.a);
```

Đúng vậy, nếu `writable` bằng `false` thì thuộc tính gọi là **read only** (thuộc tính chỉ đọc).

Thực tế, giá trị mặc định của thuộc tính `writable` là `false`, nên bạn có thể bỏ qua thuộc tính này:

```js
let obj = {};
Object.defineProperty(obj, "a", { value: 1 });
obj.a = 2;
console.log(obj.a); // 1
```

### Thay đổi giá trị `writable` với `Object.defineProperty`

Câu hỏi đặt ra là: **nếu mình muốn thay đổi giá trị của `writable` từ `false` thành `true` có được không?**

Câu trả lời: **mặc định là KHÔNG**.

Khi định nghĩa thuộc tính bằng `Object.defineProperty`, ngoài `writable` ra thì còn có `configurable` (có thể chỉnh sửa).

Mặc định, giá trị của `configurable` là `false`, nên đoạn code sau sẽ bị lỗi: **TypeError: Cannot redefine property: a** (không thể định nghĩa lại thuộc tính a).

```js
let obj = {};
Object.defineProperty(obj, "a", { value: 1, writable: false });
Object.defineProperty(obj, "a", { writable: true }); // => TypeError: Cannot redefine property: a
```

Để giải quyết vấn đề này, bạn phải sửa `configurable` thành `true`:

```js
let obj = {};

Object.defineProperty(obj, "a", {
  value: 1,
  writable: false,
  configurable: true,
});

Object.defineProperty(obj, "a", { writable: true });
obj.a = 2;
console.log(obj.a); // 2 - giá trị của thuộc tính a đã thay đổi
```

Nghĩa là bạn có thể biến **immutable object** thành **mutable object** được bằng cách này.

## Tạo immutable object sử dụng `Object.freeze`

Phương thức [Object.freeze()](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Object/freeze) làm cho object không thể thay đổi, bao gồm:

- **Không thể thêm thuộc tính mới** vào object.
- Thuộc tính đã có thì **không thể cập nhật** và **không thể bị xoá bỏ**.

> `Object.freeze()` có thể dịch ra là "đóng băng object".

### Cách sử dụng `Object.freeze`

Ví dụ sử dụng `Object.freeze()` để tạo immutable object:

```js
let obj = { a: 1 };

Object.freeze(obj); // đóng băng object
obj.a = 2; // cập nhật thuộc tính đã có
obj.b = 3; // thêm thuộc tính mới

console.log(obj); // { a: 1 }
```

Bạn thấy rằng `obj` vẫn không hề thay đổi.

Nếu sử dụng ở **strict mode** thì đoạn code sau sẽ bị lỗi:

```js
"use strict";
let obj = { a: 1 };

Object.freeze(obj); // đóng băng object

obj.a = 2;
// Uncaught TypeError:
// Cannot assign to read only property 'a' of object '#<Object>'
```

Vì khi sử dụng `Object.freeze()`, tất cả các thuộc tính trong object đều trở thành **read-only**.

### Cách để unfreeze object

Tương tự như câu hỏi ở trên.

**Nếu mình muốn unfreeze object, để biến immutable object thành mutable object thì có được không?**

Câu trả lời là **KHÔNG**.

Bạn **không thể unfreeze object** một khi nó đã freeze.

## Tổng kết

Trên đây là 2 cách tạo immutable object trong JavaScript.

- Sử dụng `Object.defineProperty` bằng cách set `writable` thành `false`.
- Sử dụng `Object.freeze`.

Mỗi cách đều có những ưu, nhược điểm riêng. Tuỳ vào từng yêu cầu cụ thể mà bạn lựa chọn cách làm hợp lý.

Liên quan đến chủ đề immutable object, có một bài viết khá hay mà bạn có thể tham khảo thêm: [Tuyệt chiêu đảm bảo tính bất biến trong JavaScript](https://ehkoo.com/bai-viet/array-object-immutability-javascript).
