---
title: "Tagged template ES6 trong Javascript"
description: "Tagged template ES6 cho phép bạn xử lý template string với một hàm."
keywords: ["tagged template literals trong js",
"Tagged template ES6 trong Javascript là gì",
"Tagged template ES6 trong Javascript dùng để làm gì",
"Tagged template ES6 trong Javascript có tác dụng",
"tagged template ES6 Javascript",
"Cách sử dụng tagged template ES6 trong Javascript",
"Tagged template javascript",
"Tagged template là gì trong javascript",
"Tagged template dùng để làm gì trong javascript",
"cách sử dụng Tagged template trong javascript"
]
chapter:
  name: "Kiểu dữ liệu trong Javascript"
  slug: "chuong-04-kieu-du-lieu-trong-javascript"
category:
  name: "Javascript"
  slug: "javascript"
image: https://user-images.githubusercontent.com/29374426/168242173-f4c90841-cb1f-4f3f-b978-286dbc7fbd1e.png
position: 5
---

Trong bài viết về [sử dụng ES6 Template String có gì hay](/bai-viet/javascript/es6-template-string-trong-javascript), mình đã giới thiệu với bạn về ES6 Template String là gì, cũng như cách dùng và ứng dụng của nó.

https://user-images.githubusercontent.com/29374426/168242173-f4c90841-cb1f-4f3f-b978-286dbc7fbd1e.png

Tuy nhiên, có một tính năng mà mình chưa đề cập đến là: **Tagged template**. Sau đây, mình sẽ tìm hiểu xem rốt cuộc Tagged template ES6 là gì và sử dụng Tagged template như thế nào nhé.

## Cơ bản về Tagged template ES6

Cú pháp về Tagged template:

```js
func`template string with ${expression}`;
```

Tagged template ES6 cho phép bạn **xử lý template string** với một [hàm](/bai-viet/javascript/ham-trong-javascript/).

Trong đó, `func` chính là function mà bạn tự định nghĩa. Tiếp sau là một đoạn template string có thể chứa một hoặc nhiều `expression` (biểu thức).

Ở đây, `func` nhận tham số đầu tiên là [mảng](/bai-viet/javascript/mang-array-trong-javascript) các string (sử dụng trong template string). Các tham số tiếp theo là các biểu thức trong template string.

Kết quả trả về của Tagged template là kết quả của hàm `func`. Đó có thể là bất cứ kiểu dữ liệu nào tùy thích. Chứ không phải luôn luôn là string!

Đọc đến đây có thể bạn vẫn chưa hiểu được cách sử dụng của Tagged template ES6. Do đó, mình sẽ tìm hiểu nó qua một ví dụ cụ thể phía dưới.

## Ví dụ sử dụng Tagged template ES6

Xem xét đoạn code sau:

```js
// func
const math = ([x, y], op) => op(Number(x), Number(y));

// expression
const plus = (x, y) => x + y;

// tagged template string
const result = math`6 ${plus} 3`;

// kết quả
console.log(result); // 9
```

Trong đó:

- `func` chính là hàm `math`.
- `expression` là hàm `plus`.
- Template string là `6 ${plus} 3`.

Đối với hàm `math()`, tham số đầu tiên là **mảng của các string** được sử dụng trong template string.

Do đó, mảng này gồm 2 phần tử là: `['6 ', ' 3']` (chú ý sự tồn tại của dấu cách trong các string nhé).

Tham số tiếp theo của hàm `math()` chính là hàm **plus()**.

Như vậy, bên trong hàm `math()`:

```js
x = '6 ' => Number(x) = 6
y = ' 3' => Number(y) = 3
op = plus

=> op(Number(x), Number(y)) = plus(6, 3) = 9
```

Cuối cùng kết quả của biến `result` bằng `9`.

Có lẽ bạn đã phần nào mường tượng ra cách sử dụng của Tagged template ES6 rồi. Tuy nhiên, mình tiếp tục nghiên cứu thêm một ví dụ nữa để hiểu hơn về nó.

## Ví dụ khác của Tagged template ES6

Giả sử trường hợp template string với expression **ở đầu hoặc/và ở cuối**:

```js
// func
const func = (arr, expr1, expr2) => {
  console.log(arr); // (1)
  console.log(expr1, expr2); // (2)
  return { x: "1" };
};

// expression
const a = 1;
const b = 2;

// tagged template
const result = func`${a} and then ${b}`;

// kết quả
console.log(result); // (3)

// (1) - mảng các string: ["", " and then ", ""]
// (2) - các expression: 1 2
// (3) - kết quả: { x: "1" }
```

Đây chỉ là một ví dụ để minh họa. Và qua ví dụ này, bạn biết thêm một số vấn đề về tagged template như sau:

- Tagged template ES6 sử dụng các expression để phân tách ra mảng các string. Do đó, nếu có expression ở đầu hay cuối thì mảng các string cũng có string rỗng ở đầu và cuối.
- Nếu có nhiều expression thì chúng sẽ được điền kế tiếp nhau trong hàm, phía sau phần tử đầu tiên, các expression sau cách nhau bởi dấu phẩy.
- Kết quả trả về của **func** có thể là bất cứ thứ gì. Do đó, kết quả của Tagged template ES6 cũng có thể là bất cứ thứ gì.

## Tổng kết

Trên đây là một số ví dụ cơ bản giúp bạn hiểu về Tagged template ES6.

Vậy theo bạn, ứng dụng thực tế của Tagged template ES6 là gì? Chia sẻ quan điểm của bạn trong phần bình luận phía dưới nhé!
