---
title: "Debug Javascript dễ hay khó"
description: "Chúng ta sẽ cùng nhau tìm hiểu về debug trong JavaScript sau đây."
keywords: [
"Debug Javascript dễ hay khó",
"Debug Javascript là gì",
"Debug trong Javascript",
"Debug trong Javascrip để làm gì",
"Cách debug trong Javascript",
"Debug trong Javascript như thế nào",
"cach debug javascript tren chrome",
"Cách debug javascript trên Chrome",
"Debug js vscode"
]
chapter:
  name: "Kiểm thử và đảm bảo chất lượng code"
  slug: "chuong-11-kiem-thu-va-dam-bao-chat-luong-code"
category:
  name: "Javascript"
  slug: "javascript"
image: https://kungfutech.edu.vn/thumbnail.png
position: 1
---

Với mọi ngôn ngữ lập trình, debug là một hoạt động khó và mất nhiều thời gian nhất. Trong đó, debug [JavaScript](/bai-viet/javascript/gioi-thieu-javascript) là khó khăn hơn cả. Tại sao vậy?

Chúng ta sẽ cùng nhau tìm hiểu về debug trong JavaScript sau đây.

## Khái niệm chung về bug và debug

Bug là lỗi của chương trình. Nhìn chung, chúng ta có 2 loại bug: lỗi **ngữ pháp** và lỗi **ngữ nghĩa**.

- Lỗi ngữ pháp: nghĩa là bạn viết sai cú pháp, sai kiểu dữ liệu hay thậm chí là sai chính tả... Đối với những ngôn ngữ lập trình như C/C++ hay Java, bạn sẽ dễ dàng phát hiện và sửa lỗi này vì IDE và trình biên dịch sẽ chỉ ra vị trí lỗi để bạn sửa. Còn đối với JavaScript, bạn sẽ chỉ được thông báo lỗi khi chương trình chạy đến phần đó - vì JavaScript là ngôn ngữ kịch bản, không biên dịch.
- Lỗi ngữ nghĩa: có thể hiểu là bạn sai về logic, thuật toán hay bị lỗi khi tương tác với hệ thống dẫn đến kết quả bị sai khác so với mong đợi. Lỗi này thì luôn luôn khó phát hiện và bạn sẽ phải kiểm tra lại thật kĩ từng phần trong code để tìm ra vị trí mắc lỗi.

Nếu như bug là lỗi thì debug hay debugging chính là quá trình tìm ra bug.

<content-info>

Debugging khó gấp 2 lần việc bạn viết ra code. Nếu viết code thông minh quá mức, bạn sẽ không đủ thông minh để debug nó - Brian Kernighan và P.J. Plauger, The Elements of Programming Style.

</content-info>

## Strict mode trong JavaScript

Trong con mắt của nhiều lập trình viên, JavaScript là một thứ vô cùng lộn xộn. Lập trình JavaScript chẳng khác nào cực hình.

Tuy nhiên, JavaScript có cung cấp cho lập trình viên chế độ "use strict". Bằng việc khai báo và sử dụng chế độ này, JavaScript sẽ trở nên chính xác và nghiêm ngặt hơn. Do đó, bạn sẽ không thể viết code bừa bãi trong chế độ này.

Ví dụ 1: Không sử dụng strict mode

```js
x = 10;
var Infinity = 10;
delete Object.prototype;
```

Ví dụ 2: Sử dụng strict mode

```js
"use strict";
x = 10;
// Uncaught ReferenceError: x is not defined
var Infinity = 10;
// Uncaught TypeError: Cannot assign to read only property 'Infinity' of object '#<Window>'
delete Object.prototype;
// Uncaught TypeError: Cannot delete property 'prototype' of function Object() { [native code] }
```

Qua hai ví dụ trên, ta thấy rằng: khi sử dụng 'use strict', bạn sẽ không thể sử dụng [biến](/bai-viet/javascript/cac-kieu-du-lieu-trong-javascript) mà không cần khai báo, không thể gán giá trị cho thuộc tính read-only, không thể delete thuộc tính [prototype](/cac-khia-canh-lap-trinh-huong-doi-tuong-trong-javascript/) của đối tượng [object](/bai-viet/javascript/object-la-gi-object-trong-javascript). Và còn nhiều cái **KHÔNG** nữa. Vì vậy, mình quyết định sẽ viết một bài chi tiết hơn về strict mode sau.

Như vậy, việc sử dụng strict mode trong lập trình JavaScript sẽ làm giảm thiểu đáng kể những lỗi không mong muốn.

## Testing trước khi debug JavaScript

Khi mà việc sử dụng strict mode hay trình duyệt không thể giúp bạn tìm ra lỗi thì đây là lúc mà bạn cần phải testing - kiểm thử chương trình.

Và để tránh phát sinh lỗi khi chương trình mở rộng ra, bạn nên kiểm tra kĩ mỗi khi viết thêm một module, hay một [function](/bai-viet/javascript/ham-trong-javascript).

Giả sử mình có đoạn chương trình sau:

```js
function Vector(x, y) {
  this.x = x;
  this.y = y;
}
Vector.prototype.plus = function (other) {
  return new Vector(this.x + other.x, this.y + other.y);
};
```

Bây giờ mình sẽ viết một đoạn chương trình khác để kiểm tra xem đối tượng Vector có hoạt động đúng như mong đợi hay không:

```js
function testVector() {
  var p1 = new Vector(10, 20);
  var p2 = new Vector(-10, 5);
  var p3 = p1.plus(p2);

  if (p1.x !== 10) return "fail: x property";
  if (p1.y !== 20) return "fail: y property";
  if (p2.x !== -10) return "fail: negative x property";
  if (p3.x !== 0) return "fail: x from plus";
  if (p3.y !== 25) return "fail: y from plus";
  return "everything ok";
}
console.log(testVector());
// => everything ok
```

Việc viết test như trên gọi là viết **unit test**. Tuy nhiên, thực tế chúng ta sẽ có những framework hỗ trợ viết unit test chuyên nghiệp hơn, nhanh gọn hơn.

## Debugging - Debug JavaScript

Một khi đã xác định được chương trình có bug, công việc tiếp theo là tìm ra vị trí gây ra bug và sửa nó.

Ví dụ chương trình sau sẽ chuyển một số _n_, cơ số _base_ thành [string](/bai-viet/javascript/cac-kieu-du-lieu-trong-javascript):

```js
function numberToString(n, base) {
  var result = "",
    sign = "";
  if (n < 0) {
    sign = "-";
    n = -n;
  }
  do {
    result = String(n % base) + result;
    n /= base;
  } while (n > 0);
  return sign + result;
}
console.log(numberToString(13, 10));
// => 1.5e-3231.3e-3221.3e-3211.3e-3201.3e-3191.3e-3181.3…
```

Rõ ràng là chương trình hoạt động không đúng mong đợi. Bây giờ ta sẽ phải tìm ra đoạn gây ra lỗi và sửa nó.

Chiến lược hiệu quả trong trường hợp này là ta sẽ ghi ra log kết quả sau từng đoạn con của chương trình, để xem đoạn bắt đầu gây ra lỗi.

```js
function numberToString(n, base) {
  var result = "",
    sign = "";
  if (n < 0) {
    sign = "-";
    n = -n;
  }
  console.log("sign:", sign);
  console.log("n:", n);
  do {
    result = String(n % base) + result;
    console.log("result:", result);
    n /= base;
    console.log("n", n);
  } while (n > 0);
  return sign + result;
}
console.log(numberToString(13, 10));
```

Kết quả ta có log như sau:

<content-result>

sign:
n: 13
result: 3
n 1.3
result: 1.33
n 0.13
result: 0.131.33
...

</content-result>

Bạn đã thấy sự bất ổn chưa? Giá trị log thứ 3 cho thấy n /= base => 1.3. Trong khi giá trị mong đợi phải là 1. À thì ra JavaScript khác với C/C++ và Java. Nếu như trong C/C++, Java, 13/10 = 1 thì trong JavaScript 13/10=1.3. Do đó, ta phải sửa thành n = Math.floor(n/base). Chương trình sẽ hoạt động đúng.

```js
function numberToString(n, base) {
  var result = "",
    sign = "";
  if (n < 0) {
    sign = "-";
    n = -n;
  }
  do {
    result = String(n % base) + result;
    n = Math.floor(n / base);
  } while (n > 0);
  return sign + result;
}
console.log(numberToString(13, 10));
// => 13
```

Đó chính là một cách mà mình thường làm khi debug JS.

Ngoài cách viết log, bạn cũng có thể set breakpoint giống như bạn debug trên IDE khi lập trình C/C++ hay Java. Đây cũng là một cách debug trong JavaScript khá hay mà mình mới biết, nên chắc chắn sẽ thử cách này.

## Kết luận

Trên đây là một số cách giúp bạn debug JavaScript. Mình có thể tóm tắt ngắn ngọn như sau:

- Sử dụng strict mode giúp giảm thiểu những lỗi không mong muốn.
- Testing - unit test giúp kiểm tra từng thành phần trong chương trình.
- Debugging bằng cách ghi ra log hoặc set breakpoint giúp bạn xác định chính xác vị trí lỗi và sửa nó.

Hy vọng qua bài viết này bạn sẽ thấy rằng debug JS không phải là một công việc quá khó khăn. Nó cũng chỉ giống như mọi ngôn ngữ lập trình khác thôi.

## Tham khảo

- [Bugs and Errors](https://eloquentjavascript.net/08_error.html)
- [Strict mode](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Strict_mode)
