---
title: "Hàm setTimeout trong Javascript"
description: "Hàm setTimeout() dùng để thiết lập một khoảng thời gian nào đó sẽ thực hiện một nhiệm vụ nào đó."
keywords: [
"setTimeout trong js",
"Hàm setTimeout trong Javascript",
"Hàm setTimeout trong Javascript là gì",
"Hàm setTimeout trong Javascript để làm gì",
"Hàm setTimeout trong Javascript có tác dụng gì",
"setTimeout trong javascript",
"setTimeout trong javascript dùng để làm gì",
"setInterval trong Javascript",
"cách sử dụng hàm setTimeout trong Javascript"
]
chapter:
  name: "Kiến thức nâng cao về hàm"
  slug: "chuong-05-kien-thuc-nang-cao-ve-ham"
category:
  name: "Javascript"
  slug: "javascript"
image: https://kungfutech.edu.vn/thumbnail.png
position: 8
---

Đôi khi bạn cần phải thực hiện hành động **sau một khoảng thời gian** nhất định. Để thực hiện điều này, bạn có thể sử dụng phương thức `setTimeout`. Sau đây là cách khai báo và sử dụng **setTimeout trong JavaScript**.

## Hàm setTimeout trong JavaScript

Cú pháp hàm `setTimeout` là:

```js
  let timerId = setTimeout(func|code, [delay], [arg1], [arg2], ...)
```

Trong đó:

- `func|code`: là hàm hoặc string mô tả code để thực thi. Cách sử dụng thông thường là **hàm**. Cách sử dụng **string** được phép nhưng không khuyến khích.
- `delay`: là **thời gian trì hoãn** trước khi hành động được thực hiện, tính theo **mili giây**. Giá trị mặc định của `delay` là `0`.
- `arg1, arg2,...`: là danh sách các tham số truyền vào hàm.

Ví dụ đoạn code sau gọi hàm `sayHi` sau 1 giây:

```js
function sayHi() {
  console.log("Hello");
}

setTimeout(sayHi, 1000); // Hello
```

Ví dụ với tham số truyền vào hàm:

```js
function sayHi(message, who) {
  console.log(`${message}, ${who}`);
}

setTimeout(sayHi, 1000, "Hello", "Alex"); // Hello, Alex
```

Nếu **tham số đầu tiên là string**, JavaScript engine sẽ [tạo hàm từ string](/bai-viet/javascript/cu-phap-new-function-trong-javascript) đó để thực thi, ví dụ:

```js
setTimeout("console.log('Hello')", 1000);
```

Tuy nhiên, cách sử dụng **string** là không được khuyến khích, bạn có thể thay thế bằng [**arrow function**](/bai-viet/javascript/arrow-function-trong-javascript) như sau:

```js
setTimeout(() => console.log("Hello"), 1000);
```

**Chú ý:** Tham số đầu tiên là **hàm**, chứ **không phải kết quả của việc gọi hàm**, nhiều bạn hay bị nhầm lẫn như sau:

```js
// gọi hàm sayHi() thay vì truyền vào hàm sayHi
setTimeout(sayHi(), 1000);
```

Khi gọi hàm `sayHi()` như trên, kết quả của hàm `sayHi()` được truyền vào hàm `setTimeout`. Mà hàm `setTimeout` chỉ chấp nhận truyền vào là function. Do đó, đoạn code trên sẽ không thực hiện gì sau 1 giây.

## Xóa hành động với clearTimeout

Khi bạn gọi hàm **setTimeout trong JavaScript**, kết quả trả về là một số nguyên `timerId` - định danh cho hành động với timeout. Để hủy bỏ hành động, bạn chỉ cần gọi `clearTimeout` như sau:

```js
let timerId = setTimeout(...);
    clearTimeout(timerId);
```

Ví dụ bạn dự định gọi một hàm sau khoảng thời gian delay là 1 giây. Nhưng sau đó, bạn lại hủy bỏ hành động này:

```js
let timerId = setTimeout(() => console.log("sẽ không được gọi"), 1000);
console.log(timerId); // định danh cho timer

clearTimeout(timerId);
console.log(timerId); // timerId không đổi sau khi clearTimeout
```

## Hàm setInterval trong JavaScript

Hàm `setInterval` có cú pháp tương tự như hàm `setTimeout`:

```js
let timerId = setInterval(func|code, [delay], [arg1], [arg2], ...)
```

Trong đó, tất cả tham số đều có ý nghĩa giống với hàm `setTimeout`.

Nhưng khác với hàm `setTimeout` là chỉ thực hiện hành động **một lần**, hàm `setInterval` sẽ gọi hàm thường xuyên sau **mỗi khoảng thời gian delay**.

Để dừng hành động, bạn chỉ cần gọi hàm `clearInterval(timerId)`.

Ví dụ sau hiển thị `"Hello"` sau mỗi 2 giây và sau đó 5 giây thì dừng lại:

```js
// lặp lại với thời gian là 2000 ms (2 giây)
let timerId = setInterval(() => console.log("Hello"), 2000);

// sau 5 giây thì dừng lại
setTimeout(() => {
  clearInterval(timerId);
  console.log("stop");
}, 5000);
```

## Hàm setTimeout lồng nhau

Ngoài cách sử dụng `setInterval` để thực hiện một hành động lặp đi lặp lại, bạn có thể sử dụng hàm **setTimeout trong JavaScript** theo cách lồng nhau như sau:

```js
/** thay vì:
    let timerId = setInterval(() => console.log('Hello'), 2000);
    */

let timerId = setTimeout(function sayHi() {
  console.log("Hello");
  timerId = setTimeout(sayHi, 2000); // (*)
}, 2000);
```

Trong ví dụ trên, cứ sau mỗi 2 giây thì hàm `sayHi` sẽ được gọi. Mà ở cuối hàm `sayHi` mình lại gọi tiếp `setTimeout` với hàm `sayHi` - tương tự cách gọi [hàm đệ quy](/bai-viet/javascript/ham-de-quy-trong-javascript).

Cách gọi hàm `setTimeout` lồng nhau như trên giúp bạn xử lý `delay` linh hoạt hơn so với cách dùng `setInterval`. Vì bạn có thể tùy chỉnh thời gian `delay` cho mỗi lần lặp.

Giả sử bạn cần tạo request lên server sau mỗi 5 giây để cập nhật dữ liệu. Tuy nhiên, server có thể bị quá tải. Dựa vào trạng thái server hiện tại, bạn có thể tăng thời gian delay lên 10, 20, 30, giây... cho phù hợp, ví dụ:

```js
let delay = 5000;

let timerId = setTimeout(function request() {
  /*... gửi request lên server...*/

  if (/* mã lỗi trả về liên quan đến server quá tải */) {
    // tăng delay lên hai lần
    delay *= 2;
  }

    // chạy lại setTimeout với giá trị delay mới
    timerId = setTimeout(request, delay);

}, delay); // -> giá trị delay ban đầu là 5000 ms
```

► **Cách sử dụng `setTimeout` lồng nhau cho phép `delay` chính xác hơn giữa mỗi lần thực hiện hành động so với cách dùng `setInterval`.**

Ví dụ dùng `setInterval`:

```js
let i = 1;
setInterval(function () {
  func(i++);
}, 100);
```

Ví dụ dùng `setTimeout` lồng nhau:

```js
let i = 1;
setTimeout(function run() {
  func(i++);
  setTimeout(run, 100);
}, 100);
```

Hàm `setInterval` thực hiện hành động `func(i++)` sau mỗi 100ms. Tuy nhiên, hành động `func(i++)` cũng chiếm thời gian. Do đó, thời gian thực tế giữa hai lần chạy `func(i++)` là **nhỏ hơn 100ms**.

Thậm chí là thời gian chạy `func(i++)` có thể nhiều hơn 100ms thì lần chạy `func(i++)` tiếp theo sẽ được gọi ngay lập tức sau lần gọi trước. Nói cách khác là **không có thời gian delay** giữa hai lần chạy `func(i++)`.

Nhưng với cách sử dụng hàm `setTimeout` lồng nhau thì khác. Với cách này, hàm `setTimeout` tiếp theo chỉ được gọi khi hàm `func(i++)` thực hiện xong. Nghĩa là thời gian giữa hai lần chạy `func(i++)` sẽ **đảm bảo khoảng 100ms**.

## Vấn đề garbage collection

Như mình đã nói trong bài viết về [garbage collection trong JavaScript](/bai-viet/javascript/garbage-collection-trong-javascript), khi một giá trị là không thể tiếp cận thì nó sẽ được giải phóng khỏi bộ nhớ.

Đối với hàm truyền vào `setTimeout/setInterval`, JavaScript engine sẽ tạo một tham chiếu nội bộ tới hàm thực thi để đảm bảo hàm này không bị giải phóng.

Với hàm `setTimeout`, hàm truyền vào sẽ được giữ trong bộ nhớ cho tới khi hàm được gọi:

```js
// hàm được giữ trong bộ nhớ cho tới khi thực thi xong
setTimeout(function() {...}, 100);
```

Với hàm `setInterval`, hàm truyền vào được giải phóng khỏi bộ nhớ sau khi gọi `clearInterval`.

Giả sử hàm truyền vào `setInterval` tham chiếu đến biến bên ngoài. Vì hàm này luôn tồn tại cho đến khi gọi `clearInterval`, nên biến được tham chiếu đến cũng sẽ **không được giải phóng**.

<content-info>

Khi không thực sự cần thiết, hãy gọi hàm `clearInterval` để giải phóng bộ nhớ.

</content-info>

## Hàm setTimeout với thời gian delay bằng 0

Có một trường hợp đặc biệt với hàm `setTimeout` là thời gian `delay` bằng 0.

Theo lý thuyết, khi `delay = 0` thì hành động được thực hiện ngay lập tức. Nhưng thực tế, hành động sẽ được thực hiện ngay khi code luồng chính thực hiện xong, ví dụ:

```js
setTimeout(() => console.log("World"));

console.log("Hello");
// Hello
// World
```

Trong ví dụ trên, câu lệnh `console.log("Hello")` được thực hiện trước. Và ngay sau khi câu lệnh này thực hiện xong thì câu lệnh `console.log("World")` được thực hiện.

<content-warning>

thời gian delay trên trình duyệt không hoàn toàn bằng `0`.

</content-warning>

Đối với cách gọi hàm `setTimeout` lồng nhau, sau 5 lần gọi hàm, thời gian delay sẽ được set bằng 4ms, ví dụ:

```js
let start = Date.now();
let times = [];

setTimeout(function run() {
  // tính toán thời gian delay so với ban đầu
  times.push(Date.now() - start);

  // sau 100ms tính từ thời điểm bắt đầu thì sẽ in ra log và dừng lại
  if (Date.now() > start + 100) {
    console.log(times);
  } else {
    setTimeout(run); // tiếp tục setTimeout
  }
});

// kết quả cuối cùng:
// (22) [12,14,16,18,25,30,34,38,42,46,51,55,59,63,69,74,79,83,87,92,96,101]
```

Xem kết quả trên, bạn thấy rằng thời gian delay giữa mỗi lần gọi trong 5 lần đầu tiên là khoảng 2ms. Nhưng sau 5 lần thì thời gian delay tăng lên là khoảng 4ms.

Đây chính là giới hạn của hàm `setTimeout` trên trình duyệt. Và giới hạn này cũng gặp phải khi sử dụng hàm `setInterval`.

Ở môi trường khác như phía server, giới hạn này không gặp phải vì trên Node.js có hàm [setImmediate](https://nodejs.org/api/timers.html#timers_setimmediate_callback_args).

## Tổng kết setTimeout trong JavaScript

Hàm `setTimeout(func, delay, ...args)` trong JavaScript cho phép thực hiện hàm `func` **một lần** sau một khoảng thời gian `delay` với các tham số truyền vào là `args`.

Hàm `setInterval(func, delay, ...args)` cũng tương tự như hàm `setTimeout`, nhưng hàm `func` được thực hiện sau **mỗi lần** `delay`.

Để hủy bỏ không gọi hàm `func` nữa, bạn có thể gọi hàm `clearTimeout(timerId)` hoặc `clearInterval(timerId)` với `timerId` là kết quả trả về sau khi gọi hàm `setTimeout` hoặc `setInterval`.

Việc gọi hàm `setTimeout` lồng nhau giúp bạn xử lý linh hoạt giá trị `delay` hơn so với cách sử dụng `setInterval`.

Trường hợp gọi hàm `setTimeout(func, 0)` với giá trị `delay = 0`, tương đương với `setTimeout(func)` sẽ thực hiện hàm `func` ngay sau khi luồng code chính thực hiện xong.

Đối với trình duyệt, sau 5 lần gọi hàm `setTimeout(func)` lồng nhau hoặc với `setInterval(func)` thì thời gian delay được set khoảng **4ms**.

## Thực hành

### Bài 1

Viết hàm `printNumbers(start, end)` để in ra một số từ `start` đến `end` sau mỗi 1 giây theo hai cách:

1.  Sử dụng `setInterval`.
2.  Sử dụng `setTimeout`.

Xem đáp án

► **Cách 1: sử dụng `setInterval`**

```js
function printNumbers(start, end) {
  let timerId = setInterval(function run() {
    if (start > end) {
      clearInterval(timerId);
      return;
    }

    console.log(start++);
  }, 1000);
}

printNumbers(1, 5);
// 1, 2, 3, 4, 5
```

► **Cách 2: sử dụng `setTimeout`**

```js
function printNumbers(start, end) {
  setTimeout(function run() {
    if (start > end) {
      return;
    }

    console.log(start++);
    setTimeout(run, 1000);
  }, 1000);
}

printNumbers(1, 5);
// 1, 2, 3, 4, 5
```

### Bài 2

Trong đoạn code sau, hàm `setTimeout` được gọi với thời gian delay là 100ms.

Sau đó là một [vòng lặp `for`](/bai-viet/javascript/vong-lap-trong-javascript) với số lần lặp khoảng 100000000 lần. Mà thời gian thực hiện vòng lặp lớn này thường hơn 100ms.

Hỏi hàm với `setTimeout` được gọi khi nào?

1.  Sau vòng lặp.
2.  Trước vòng lặp.
3.  Trong khi vòng lặp đang chạy.

```js
let i = 0;

setTimeout(() => console.log(i), 100); // ?

// giả sử thời gian thực hiện vòng lặp lớn hơn 100ms
console.log("trước vòng lặp");
for (let j = 0; j < 100000000; j++) {
  i++;
}
console.log("sau vòng lặp");
```

Xem đáp án

<content-result>

<code>trước vòng lặp</code>
<code>sau vòng lặp</code>
<code>100000000</code>

</content-result>

Nghĩa là hàm với `setTimeout` được gọi ngay sau vòng lặp.

Tham khảo:

- [Scheduling: setTimeout and setInterval](https://javascript.info/settimeout-setinterval)
- [Timers](https://html.spec.whatwg.org/multipage/timers-and-user-prompts.html#timers)
