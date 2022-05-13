---
title: "Tìm hiểu về iterable trong Javascript"
description: "Iterable là khả năng cho phép các đối tượng trong Javascript sử dụng các kỹ thuật xử lý dữ liệu như for of loop."
keywords: [
"Iterable trong Javascript",
"Iterable trong Javascript là gì",
"iterable trong Javascript dùng để làm gì",
"iterable Javascript",
"iterator object la gi trong javascript",
"cách sử dụng Iterable trong Javascript",
"Iterable trong Javascript hoạt động như thế nào",
"Iterable javascript",
"Iterable javascript là gì",
"iterable trong js"
]
chapter:
  name: "Kiểu dữ liệu trong Javascript"
  slug: "chuong-04-kieu-du-lieu-trong-javascript"
category:
  name: "Javascript"
  slug: "javascript"
image: https://user-images.githubusercontent.com/29374426/168243321-75764d51-b0a0-46f4-8bf6-0f24980c1c99.png
position: 11
---

**Iterable trong JavaScript** là một khái niệm liên quan đến array. Một object gọi là **iterable** nếu object đó sử dụng được với [vòng lặp `for...of`](/bai-viet/javascript/mang-array-trong-javascript).

![Tìm hiểu về iterable trong Javascript](https://user-images.githubusercontent.com/29374426/168243321-75764d51-b0a0-46f4-8bf6-0f24980c1c99.png)


Dĩ nhiên, array là iterable. Ngoài ra, JavaScript còn có nhiều kiểu object khác cũng **iterable**, ví dụ: [Set](/bai-viet/javascript/set-trong-javascript), [Map](/bai-viet/javascript/map-trong-javascript), String,...

```js
// array là iterable
let arr = [1, 2, 3];
for (let it of arr) {
  console.log(it); // Kết quả lần lượt là: 1, 2, 3
}

// string là iterable
let str = "hello";
for (let ch of str) {
  console.log(ch); // Kết quả lần lượt là: h, e, l, l, o
}
```

Sau đây, mình hãy cùng tìm hiểu xem **iterable trong JavaScript** hoạt động thế nào nhé!

## Symbol.iterator

Để hiểu rõ về iterable trong JavaScript, mình sẽ thử **tự triển khai iterable**.

Ví dụ object `range` sau đây (mặc định không dùng được với `for...of`):

```js
let range = {
  from: 1,
  to: 5,
};

for (let num of range) {
  console.log(num);
}

// Uncaught TypeError: range is not iterable
```

Để object `range` trên trở nên **iterable**, mình cần triển khai một [phương thức](/bai-viet/javascript/phuong-thuc-trong-javascript/) với key là `Symbol.iterator`. Đây là một [Symbol](/bai-viet/javascript/symbol-trong-javascript) đặc biệt và sẵn có trong JavaScript.

Khi đó, quá trình xử lý của `for...of` như sau:

1.  Ban đầu, `for...of` gọi phương thức `Symbol.iterator`. Nếu phương thức **không tồn tại thì báo lỗi**, ngược lại thì trả về một object, gọi là `iterator` - object có phương thức `next`.
2.  Tiếp theo, `for...of` hoạt động hoàn toàn dựa trên đối tượng `iterator` trên.
3.  Khi `for...of` muốn giá trị tiếp theo, nó chỉ cần gọi phương thức `next` của iterator.
4.  Kết quả của `next` phải là một object có dạng `{done: Boolean, value: any}`. Nếu `done=true` thì quá trình xử lý kết thúc, ngược lại thì `value` chính là giá trị tiếp theo.

Sau đây là cách triển khai phương thức `Symbol.iterator` cho đối tượng `range` trên:

```js
let range = {
  from: 1,
  to: 5,

  // phương thức `Symbol.iterator`
  [Symbol.iterator]() {
    // phương thức này trả về một iterator object - object có phương thức next
    return {
      current: this.from,
      last: this.to,

      // khi for...of cần giá trị tiếp theo thì nó sẽ gọi phương thức next
      next() {
        // phương thức next trả về object dạng: {done:..., value:...}
        if (this.current <= this.last) {
          // done=false là chưa kết thúc
          return { done: false, value: this.current++ };
        } else {
          // done=true là kết thúc
          return { done: true };
        }
      },
    };
  },
};

// Bây giờ thì range có thể hoạt động được với for...of
for (let num of range) {
  console.log(num); // 1, 2, 3, 4, 5
}
```

Đó chính là cách triển khai một object iterable trong JavaScript.

## Gọi iterator trực tiếp

Để hiểu rõ hơn về iterable trong JavaScript, mình sẽ thử **gọi iterator trực tiếp** mà không sử dụng `for...of`.

Ví dụ sau đây duyệt hết các kí tự ở string:

```js
let str = "Hello";

// gọi phương thức [Symbol.iterator]()
// phương thức này trả về đối tượng iterator chứa phương thức next()
let iterator = str[Symbol.iterator]();

// sử dụng vòng lặp while(true) để duyệt
while (true) {
  // gọi phương thức next() để lấy giá trị kế tiếp
  // phương thức next() trả về đối tượng có dạng {done:..., value:...}
  let result = iterator.next();

  // kiểm tra nếu done=true thì break để kết thúc
  if (result.done) break;

  // ngược lại thì in ra giá trị value
  console.log(result.value);
}
```

<content-result>

<p>H</p>
<p>e</p>
<p>l</p>
<p>l</p>
<p>o</p>

</content-result>

Trên đây là cách hoạt động của iterable trong JavaScript.

Mặc dù, việc gọi trực tiếp như này hầu như không bao giờ áp dụng trong thực tế. Nhưng qua đó, bạn hiểu được **cách hoạt động của iterable object** khi duyệt với `for...of`.

## So sánh iterable trong JavaScript và array-like

Đây là hai khái niệm **khá giống nhau** nhưng thật sự rất khác biệt.

- Iterable object là object có phương thức `Symbol.iterator` (như miêu tả bên trên).
- Array-like là object có chứa **chỉ số** và thuộc tính `length` (giống mảng).

Trong JavaScript có nhiều object - có thể là iterable hoặc array-like hoặc cả hai.

Ví dụ, string vừa là **iterable** (hoạt động được với `for...of`) và vừa là **array-like** (có chỉ số và thuộc tính `length`).

Nhìn chung, **iterable và array-like không phải array** nên chúng không có các [phương thức của mảng](/bai-viet/javascript/cac-phuong-thuc-cua-mang-trong-javascript) như `push`, `pop`, `forEach`,...

Để giải quyết vấn đề này, bạn cần phải **chuyển đổi kiểu dữ liệu** từ iterable hoặc array-like sang array.

## Phương thức `Array.from`

Phương thức [`Array.from`](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array/from) nhận đầu vào là iterable object hoặc array-like và trả về một array.

Ví dụ tạo array từ array-like:

```js
let arrayLike = {
  0: "a",
  1: "b",
  length: 2,
};

let arr = Array.from(arrayLike);
console.log(arr.pop()); // b
```

Ví dụ tạo array từ iterable `range` bên trên:

```js
let range = {
  from: 1,
  to: 5,

  // phương thức `Symbol.iterator`
  [Symbol.iterator]() {
    // phương thức này trả về một iterator object - object có phương thức next
    return {
      current: this.from,
      last: this.to,

      // khi for...of cần giá trị tiếp theo thì nó sẽ gọi phương thức next
      next() {
        // phương thức next trả về object dạng: {done:..., value :...}
        if (this.current <= this.last) {
          // done=false là chưa kết thúc
          return { done: false, value: this.current++ };
        } else {
          // done=true là kết thúc
          return { done: true };
        }
      },
    };
  },
};

let arr = Array.from(range);
console.log(arr); // (5) [1, 2, 3, 4, 5]
```

Cú pháp đầy đủ của `Array.from` cho phép bạn truyền vào một hàm "mapping":

```js
Array.from(obj[, mapFn, thisArg]);
```

Tham số thứ hai `mapFn` là một hàm được sử dụng để **gọi với mỗi phần tử** trước khi đưa vào mảng. Và `thisArg` tương ứng với `this` trong hàm `mapFn`. ví dụ:

```js
// đối tượng range được định nghĩa như ví dụ trên

// hàm mapping trả về bình phương của số num
let arr = Array.from(range, (num) => num * num);

// kết quả
console.log(arr); // (5) [1, 4, 9, 16, 25]
```

## Tổng kết

**Iterable trong JavaScript** là object có thể sử dụng được với vòng lặp `for...of`.

- Về cơ bản, iterable object phải có phương thức `Symbol.iterator`.
  - Kết quả của việc gọi phương thức `obj[Symbol.iterator]()` là một object **iterator**. Đây là object chịu tránh nhiệm trong việc **duyệt iterable object**.
  - **Iterator object** phải có phương thức `next`. Và phương thức `next()` trả về đối tượng có dạng `{done: Boolean, value: Any}`. Với `done=true` khi kết thúc quá trình duyệt, ngược lại thì `value` là giá trị kế tiếp.
- Phương thức `Symbol.iterator` được gọi từ `for...of`, nhưng cũng có thể gọi trực tiếp không qua `for...of`.
- **Iterable và array-like khá giống nhau**, nhưng đều không phải là `array`.
- Có thể dùng phương thức `Array.from` để tạo array mới từ iterable object hoặc array-like.

Tham khảo:

- [Iteration protocols](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Iteration_protocols)
