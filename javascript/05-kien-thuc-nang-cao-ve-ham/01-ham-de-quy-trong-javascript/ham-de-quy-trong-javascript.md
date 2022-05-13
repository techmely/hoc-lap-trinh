---
title: "Hàm đệ quy trong Javascript"
description: "Một hàm đệ quy là một hàm gọi chính nó cho đến khi không thể gọi. Kỹ thuật này được gọi là Đệ quy (Recursion)."
keywords: [
"Hàm đệ quy trong Javascript",
"Return trong đệ quy javascript",
"đệ quy trong Javascript",
"đệ quy trong Javascript là gì",
"đệ quy trong Javascript sử dụng như thế nào",
"cách viết hàm đệ quy trong Javascript",
"Hàm đệ quy trong Javascript để làm gì",
"đệ quy trong Javascript có tác dụng gì",
"de quy trong javascript",
"đệ quy là gì",
"de quy la gi"
]
chapter:
  name: "Kiến thức nâng cao về hàm"
  slug: "chuong-05-kien-thuc-nang-cao-ve-ham"
category:
  name: "Javascript"
  slug: "javascript"
image: https://user-images.githubusercontent.com/29374426/168244997-b83b39b6-4985-4b14-9b2e-b3e9b7a7c977.png
position: 1
---

Hàm đệ quy trong JavaScript chính là **một hàm tự gọi lại chính nó**.

![Hàm đệ quy trong Javascript](https://user-images.githubusercontent.com/29374426/168244997-b83b39b6-4985-4b14-9b2e-b3e9b7a7c977.png)


Ví dụ sau in ra **Hello world!** `n` lần sử dụng hàm đệ quy:

```js
function sayHello(count) {
  if (count <= 0) {
    return;
  }

  console.log("Hello world!");
  sayHello(count - 1);
}

// sayHello 5 lần
sayHello(5);
```

<content-result>

<p>Hello world!</p>
<p>Hello world!</p>
<p>Hello world!</p>
<p>Hello world!</p>
<p>Hello world!</p>

</content-result>

Đây chỉ là ví dụ minh họa về **hàm đệ quy trong JavaScript**. Thực tế, bạn có thể sử dụng [vòng lặp `for`](/bai-viet/javascript/vong-lap-trong-javascript) để giải quyết bài toán trên:

```js
function sayHello(count) {
  for (let i = 0; i < count; i++) {
    console.log("Hello world!");
  }
}

sayHello(5);
```

Kết quả hoàn toàn tương đương. Tuy nhiên, có rất nhiều trường hợp việc sử dụng hàm đệ quy lại giúp code trở nên **ngắn gọn, rõ ràng và dễ bảo trì** hơn sử dụng vòng lặp.

Vì vậy, mình hãy cùng tìm hiểu về hàm đệ quy trong JavaScript để biết cách áp dụng khi cần thiết.

## Các thành phần cơ bản của hàm đệ quy

---

Hàm đệ quy nói chung và hàm đệ quy trong JavaScript nói riêng, có **hai thành phần đặc trưng**:

- **Phần cơ sở**: điều kiện để thoát đệ quy.
- **Phần đệ quy**: gọi lại chính nó.

```js
function sayHello(count) {
  // phần cơ sở: điều kiện thoát đệ quy là biến count <= 0
  if (count <= 0) {
    return;
  }

  // xử lý logic cơ bản
  console.log("Hello world!");

  // phần đệ quy: gọi lại chính hàm sayHello
  sayHello(count - 1);
}
```

Cũng tương tự như điều kiện để thoát vòng lặp, nếu **không có điều kiện cơ sở** thì hàm đệ quy sẽ không bao giờ dừng lại (đệ quy vô hạn), dẫn đến **tràn stack**.

Ví dụ **bỏ qua điều kiện cơ cở** của hàm đệ quy trên:

```js
function sayHello(count) {
  // // phần cơ sở: điều kiện thoát đệ quy là biến count <= 0
  // if (count <= 0) {
  //   return;
  // }

  console.log("Hello world!");

  // phần đệ quy: gọi lại chính hàm sayHello
  sayHello(count - 1);
}

sayHello();
```

Kết quả là **Hello world!** được in ra khoảng hơn `10000` lần thì bị lỗi **tràn stack**, cụ thể: **Uncaught RangeError: Maximum call stack size exceeded**.

<content-result>

Hello world!
Hello world!
...
Hello world!

Uncaught RangeError: Maximum call stack size exceeded

</content-result>

> **Chú ý:** con số `10000` trên chỉ là tương đối, phụ thuộc vào từng [JavaScript Engine](/bai-viet/javascript/gioi-thieu-javascript)

## Call stack là gì?

- **Call**: là lời gọi hàm.
- **Stack**: là [ngăn xếp](https://vi.wikipedia.org/wiki/Ng%C4%83n_x%E1%BA%BFp), hoạt động theo nguyên tắc "vào sau ra trước", tiếng anh là **Last In First Out** - LIFO.

Khi gọi hàm, JavaScript Engine đưa các lời gọi hàm vào trong một ngăn xếp.

- Hàm gọi sau được đưa lên đầu ngăn xếp, đến khi gọi xong thì đưa hàm ra khỏi ngăn xếp.
- Cứ như vậy đến khi **ngăn xếp trống** thì nghĩa là đã gọi xong hàm.

Việc lưu lời gọi hàm vào ngăn xếp là **tốn bộ nhớ**. Vì vậy, JavaScript Engine sẽ giới hạn kích thước của ngăn xếp (khoảng `10000` hoặc hơn, tùy thuộc vào engine).

Khi sử dụng hàm đệ quy trong JavaScript, bạn cần chú ý đến điều kiện cơ sở để thoát đệ quy, tránh đệ quy vô hạn dẫn đến tràn stack như ví dụ trên.

## Sử dụng hàm đệ quy khi nào?

Khi một bài toán có thể **chia ra thành nhiều bài toán con** và bài toán con **có dạng tương tự** như bài toán cha thì bạn có thể sử dụng hàm đệ quy.

Ví dụ bài toán tính giá trị của lũy thừa `a^b` (a mũ b) với định nghĩa toán học là:

```js
a^b = 1, nếu b = 0
a^b = a * a^(b-1), nếu b > 0
```

Theo định nghĩa trên, bài toán cha là tính `a^b` lại dựa trên bài toán con `a^(b-1)`. Vì vậy, bạn có thể áp dụng hàm đệ quy để tính giá trị `a^b` như sau:

```js
function power(a, b) {
  // điều kiện dừng đệ quy
  if (b === 0) {
    return 1;
  }

  // gọi lại chính nó
  return a * power(a, b - 1);
}

console.log(power(2, 0)); // 1
console.log(power(2, 1)); // 2
console.log(power(2, 2)); // 4
console.log(power(2, 3)); // 8
```

## So sánh hàm đệ quy và vòng lặp

Bài toán tính lũy thừa trên có thể giải quyết bằng cách sử dụng vòng lặp:

```js
function power(a, b) {
  let ret = 1;

  for (let i = 0; i < b; i++) {
    ret *= a;
  }

  return ret;
}

console.log(power(2, 0)); // 1
console.log(power(2, 1)); // 2
console.log(power(2, 2)); // 4
console.log(power(2, 3)); // 8
```

Đa số các bài toán **có thể sử dụng hàm đệ quy** thì đều có thể giải bằng cách **sử dụng vòng lặp**.

Việc sử dụng vòng lặp nhìn chung là **chạy nhanh và tiết kiệm bộ nhớ** hơn cách sử dụng hàm đệ quy. Vì sử dụng vòng lặp chỉ đưa lời gọi hàm vào call stack **1 lần** - không mất **thời gian và không gian bộ nhớ** như đệ quy.

Ngược lại, cách sử dụng hàm đệ quy lại giúp code trở nên **ngắn gọn và rõ ràng hơn** sử dụng vòng lặp.

<content-info>

Đối với một số bài toán **có thể giải bằng hai cách** mà **không quá quan trọng thời gian và không gian bộ nhớ** thì mình sẽ ưu tiên sử dụng **hàm đệ quy** trong JavaScript.

</content-info>

## Tổng kết

Hàm đệ quy trong JavaScript là hàm gọi lại chính nó, với hai thành phần cơ bản là:

- **Phần cơ sở**: điều kiện để thoát đệ quy. Nếu điều kiện cơ sở không chính xác thì có thể dẫn tới đệ quy vô hạn, gây ra lỗi **tràn stack**.
- **Phần đệ quy**: gọi lại chính nó.

Đa số các bài toán **có thể sử dụng hàm đệ quy** thì đều có thể giải bằng cách **sử dụng vòng lặp**. Tùy thuộc vào yêu cầu của từng bài toán mà bạn lựa chọn cách làm phù hợp:

- Nếu bạn cần tối ưu thời gian, không gian bộ nhớ thì sử dụng vòng lặp.
- Nếu bạn ưu tiên tính ngắn ngọn, dễ bảo trì thì có thể sử dụng hàm đệ quy.

## Thực hành

### Bài 1

Viết hàm `sumTo(n)` để tính tổng các số từ 1 đến n: `1 + 2 + ... + n`, ví dụ:

```js
sumTo(1) = 1
    sumTo(2) = 2 + 1 = 3
    sumTo(3) = 3 + 2 + 1 = 6
    sumTo(4) = 4 + 3 + 2 + 1 = 10
    ...
    sumTo(100) = 100 + 99 + ... + 2 + 1 = 5050
```

Triển khai hàm `sumTo(n)` theo 3 cách khác nhau:

- Sử dụng vòng lặp.
- Sử dụng đệ quy.
- Sử dụng công thức toán học.

Xem đáp án

► Cách 1: sử dụng vòng lặp

```js
function sumTo(n) {
  let sum = 0;

  for (i = 0; i <= n; i++) {
    sum += i;
  }

  return sum;
}
```

► Cách 2: sử dụng đệ quy

```js
function sumTo(n) {
  if (n === 1) return 1;

  return n + sumTo(n - 1);
}
```

► Cách 3: sử dụng công thức toán học

```js
function sumTo(n) {
  return (n * (n + 1)) / 2;
}
```

### Bài 2

Viết hàm `factorial(n)` tính n giai thừa: `n! = (n) * (n-1) * (n-2) * ... * 1`, ví dụ:

```js
1! = 1
2! = 2 * 1 = 2
3! = 3 * 2 * 1 = 6
4! = 4 * 3 * 2 * 1 = 24
5! = 5 * 4 * 3 * 2 * 1 = 120
```

Triển khai hàm `factorial(n)` theo hai cách:

- Sử dụng vòng lặp.
- Sử dụng đệ quy.

Xem đáp án

► Cách 1: sử dụng vòng lặp

```js
function factorial(n) {
  let ret = 1;

  for (let i = 1; i <= n; i++) {
    ret *= i;
  }

  return ret;
}
```

► Cách 2: sử dụng đệ quy

```js
function factorial(n) {
  if (n === 0) return 1;

  return n * factorial(n - 1);
}
```

### Bài 3

Viết hàm `fibonacci(n)` tính số fibonacci theo công thức:

```js
fibonacci(n) = n nếu n = 0 hoặc n = 1
fibonacci(n) = fibonacci(n - 1) + fibonacci(n - 2)
```

Ví dụ:

```js
fibonacci(0) = 0
fibonacci(1) = 1
fibonacci(2) = 1 + 0 = 1
fibonacci(3) = 1 + 1 = 2
fibonacci(4) = 2 + 1 = 3
fibonacci(5) = 3 + 2 = 5
```

Xem đáp án

```js
function fibonacci(n) {
  if (n === 0 || n === 1) return n;

  return fibonacci(n - 1) + fibonacci(n - 2);
}
```

### Bài 4

Cho danh sách liên kết đơn như sau:

```js
let list = {
  value: 1,
  next: {
    value: 2,
    next: {
      value: 3,
      next: {
        value: 4,
        next: null,
      },
    },
  },
};
```

Viết hàm `printList(singleLinkedList)` để in ra các phần tử của list theo hai cách:

- Sử dụng vòng lặp.
- Sử dụng hàm đệ quy.

Kết quả hiển thị trên console là:

<content-result>

<p>1</p>
<p>2</p>
<p>3</p>
<p>4</p>

</content-result>

Xem đáp án

► Cách 1: sử dụng vòng lặp

```js
function printList(singleLinkedList) {
  let p = singleLinkedList;

  while (p) {
    console.log(p.value);
    p = p.next;
  }
}
```

► Cách 2: sử dụng đệ quy

```js
function printList(singleLinkedList) {
  if (singleLinkedList === null) return;

  console.log(singleLinkedList.value);
  printList(singleLinkedList.next);
}
```

### Bài 5

Cho danh sách liên kết đơn như sau:

```js
let list = {
  value: 1,
  next: {
    value: 2,
    next: {
      value: 3,
      next: {
        value: 4,
        next: null,
      },
    },
  },
};
```

Viết hàm `printReverseList(singleLinkedList)` để in ra các phần tử của list theo thứ tự ngược lại với bài 4 bằng hai cách:

- Sử dụng vòng lặp.
- Sử dụng hàm đệ quy.

Kết quả hiển thị trên console là:

<content-result>

<p>4</p>
<p>3</p>
<p>2</p>
<p>1</p>

</content-result>

Xem đáp án

► Cách 1: sử dụng vòng lặp

```js
function printReverseList(singleLinkedList) {
  let arr = [];

  let p = singleLinkedList;
  while (p) {
    arr.push(p.value);
    p = p.next;
  }

  for (let i = arr.length - 1; i >= 0; i--) {
    console.log(arr[i]);
  }
}
```

► Cách 2: sử dụng đệ quy

```js
function printReverseList(singleLinkedList) {
  if (singleLinkedList.next) {
    printReverseList(singleLinkedList.next);
  }

  console.log(singleLinkedList.value);
}
```
