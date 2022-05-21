---
title: "Một số lỗi khi sử dụng Strict mode JavaScript"
description: "Một số lỗi phổ biến khi sử dụng Strict mode trong JavaScript để giảm thiểu những sai sót ngớ ngẩn của lập trình viên khi lập trình JavaScript."
keywords: [
"Một số lỗi khi sử dụng Strict mode JavaScript",
"strict mode javascript là gì",
"strict mode javascript để làm gì",
"Strict trong javascript",
"Strict trong javascrip dùng để làm gì",
"Strict trong javascrip có tác dụng như thế nào",
"Strict javascrip",
"javascrip Strict mode là gì",
"cách dùng javascrip Strict mode"
]
chapter:
  name: "Kiểm thử và đảm bảo chất lượng code"
  slug: "chuong-11-kiem-thu-va-dam-bao-chat-luong-code"
category:
  name: "Javascript"
  slug: "javascript"
image: https://kungfutech.edu.vn/thumbnail.png
position: 2
---

Trong [bài viết trước](/bai-viet/javascript/debug-javascript-de-hay-kho), mình có đề cập tới việc sử dụng Strict mode trong JavaScript để giảm thiểu những lỗi ngớ ngẩn của lập trình viên khi lập trình JavaScript. Như đã hứa, mình sẽ đưa ra một số lỗi phổ biến khi sử dụng chế độ này.

## Sử dụng biến không khai báo

Bình thường khi bạn đưa ra một biến mà không khai báo thì mặc định biến đó sẽ trở thành một thuộc tính của đối tượng global. Đối với browser thì đối tượng global đó chính là **window**.

```js
x = 10;
console.log(window.x);
// => 10
```

Ở strict mode, bạn sẽ bị lỗi _x chưa được định nghĩa_: **Uncaught ReferenceError: x is not defined**

```js
x = 10;
console.log(window.x);
// => Uncaught ReferenceError: x is not defined
```

## Gán giá trị cho biến global, thuộc tính chỉ đọc, thuộc tính getter

Ở chế độ bình thường, việc gán giá trị cho biến Global như Infinity, NaN,... hay những thuộc tính chỉ đọc,... sẽ không có thông báo lỗi. Mặc dù việc gán giá trị này là hoàn toàn sai và không có ý nghĩa.

```js
var undefined = 5;
console.log(undefined);
// => undefined

var NaN = 10;
console.log(NaN);
// => NaN

var Infinity = 11;
console.log(Infinity);
// => Infinity

var obj = {};
Object.defineProperty(obj, "x", { value: 42, writable: false });
obj.x = 9;
console.log(obj.x);
// => 42

var obj = {
  get x() {
    return 15;
  },
};
obj.x = 10;
console.log(obj.x);
// => 15

var fixed = {};
Object.preventExtensions(fixed);
fixed.x = 10;
console.log(fixed.x);
// => undefined
```

Khi ở strict mode, bạn chắc chắn sẽ nhận được lỗi như:

```js
- Uncaught TypeError: Cannot assign to read only property 'undefined' of object '#<Window>'
- Uncaught TypeError: Cannot assign to read only property 'NaN' of object '#<Window>'
- Uncaught TypeError: Cannot assign to read only property 'Infinity' of object '#<Window>'
- Uncaught TypeError: Cannot assign to read only property 'x' of object '#<Object>'
- Uncaught TypeError: Cannot set property x of #<Object> which has only a getter
- Uncaught TypeError: Cannot add property x, object is not extensible

  var undefined = 5;
  console.log(undefined);
  // => Uncaught TypeError:
  // Cannot assign to read only property 'undefined' of object '#<Window>'

  var NaN = 10;
  console.log(NaN);
  // => Uncaught TypeError:
  // Cannot assign to read only property 'NaN' of object '#<Window>'

  var Infinity = 11;
  console.log(Infinity);
  // => Uncaught TypeError:
  // Cannot assign to read only property 'Infinity' of object '#<Window>'

  var obj = {};
  Object.defineProperty(obj, "x", { value: 42, writable: false });
  obj.x = 9;
  console.log(obj.x);
  // => Uncaught TypeError:
  // Cannot assign to read only property 'x' of object '#<Object>'

  var obj = {
  get x() {
  return 15;
  },
  };
  obj.x = 10;
  console.log(obj.x);
  // => Uncaught TypeError:
  // Cannot set property x of #<Object> which has only a getter

  var fixed = {};
  Object.preventExtensions(fixed);
  fixed.x = 10;
  console.log(fixed.x);
  // => Uncaught TypeError:
  // Cannot add property x, object is not extensible
```

## Xoá thuộc tính của đối tượng Global

Bình thường, bạn sẽ không thể xoá thuộc tính của một đối tượng Global, mặc dù không có thông báo lỗi nào. Khi ở strict mode, bạn sẽ bị lỗi nếu cố gắng xoá một thuộc tính của đối tượng Global:

Ví dụ: Uncaught TypeError: Cannot delete property 'prototype' of function Object() { \[native code\] }

```js
"use strict";
delete Object.prototype;
// Uncaught TypeError:
// Cannot delete property 'prototype' of function Object() { [native code] }
```

## Tên tham số trùng nhau ở khai báo hàm

Strict mode JavaScript yêu cầu các tham số phải có tên khác nhau. Ngược lại thì bạn sẽ gặp lỗi:

Uncaught SyntaxError: Duplicate parameter name not allowed in this context

```js
function sum(a, a, c) {
  "use strict";
  return a + b + c;
}
// => Uncaught SyntaxError:
// Duplicate parameter name not allowed in this context
```

## Thêm thuộc tính cho những giá trị nguyên thuỷ

Như bạn đã biết, giá trị nguyên thuỷ bao gồm: [number, string, boolean](/bai-viet/javascript/cac-kieu-du-lieu-trong-javascript). Ngược lại, bạn sẽ bị lỗi như:

```js
- Uncaught TypeError: Cannot create property 'true' on boolean 'false'
- Uncaught TypeError: Cannot create property 'sailing' on number '14'
- Uncaught TypeError: Cannot create property 'you' on string 'with'

  "use strict";
  false.true = false;
  // => Uncaught TypeError:
  // Cannot create property 'true' on boolean 'false'

  (14).sailing = "home";
  // => Uncaught TypeError:
  // Cannot create property 'sailing' on number '14'

  "with".you = "far away";
  // => Uncaught TypeError:
  // Cannot create property 'you' on string 'with'
```

## Xoá một biến thông thường ở Strict mode trong JavaScript

Strict mode cấm bạn xoá tên biến. Ngược lại, bạn sẽ bị lỗi là:

Uncaught SyntaxError: Delete of an unqualified identifier in strict mode.

```js
"use strict";

var x = 10;
delete x;
// => Uncaught SyntaxError:
// Delete of an unqualified identifier in strict mode.
```

## Đặt tên biến trùng với từ dự trữ

Ngoài từ khoá, [JavaScript](/bai-viet/javascript/gioi-thieu-javascript) quy định danh sách những từ dự trữ - những từ sẽ được sử dụng làm từ khoá ở những phiên bản tiếp theo, như: implements, interface, let, package, private, protected, public, static, và yield.

Do đó, strict mode nghiêm cấm bạn đặt tên biến số trùng với những từ này. Nếu bạn đặt tên biến trùng với từ dự trữ thì bạn sẽ bị lỗi như sau:

```js
Uncaught SyntaxError: Unexpected strict mode reserved word

"use strict";
var implements = 10;
// => Uncaught SyntaxError: Unexpected strict mode
```

## Kết luận

Trên đây là một số lỗi thường gặp phải khi bạn sử dụng JavaScript strict mode. Nói vậy, không có nghĩa là mình khuyên bạn tránh sử dụng strict mode. Ngược lại, chế độ này giúp bạn dễ dàng [phát hiện lỗi](/bai-viet/javascript/debug-javascript-de-hay-kho). Và đây là sự đảm bảo cho code bạn không bị xung đột với những phiên bản JavaScript mới hơn sau này.

Bài viết này sẽ dừng lại ở đây.

Xin chào và hẹn gặp lại bạn ở [bài viết tiếp theo](/bai-viet/javascript/tim-hieu-regex-javascript), thân ái!

## Tham khảo

- [Strict mode](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Strict_mode)
