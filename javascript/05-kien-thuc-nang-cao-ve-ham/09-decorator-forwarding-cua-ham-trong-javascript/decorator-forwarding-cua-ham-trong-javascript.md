---
title: "Decorator, forwarding của hàm Javascript"
description: "JavaScript giúp bạn xử lý hàm rất linh động. Bạn có thể truyền hàm vào hàm khác qua tham số hoặc sử dụng hàm như object. Và sau đây, mình sẽ giới thiệu về kỹ thuật decorator và forwarding hàm trong JavaScript."
keywords: [
"decorator forwarding cua ham javascript là gì",
"decorator forwarding cua ham javascript của hàm",
"forwarding của hàm Javascript",
"forwarding của hàm Javascript là gì",
"forwarding của hàm Javascript để làm gì",
"Decorator của hàm Javascript",
"Decorator của hàm Javascript là gì",
"Decorator của hàm Javascript để làm gì",
"Cách sử dụng Decorator của hàm Javascript",
"Cách sử dụng forwarding của hàm Javascript"
]
chapter:
  name: "Kiến thức nâng cao về hàm"
  slug: "chuong-05-kien-thuc-nang-cao-ve-ham"
category:
  name: "Javascript"
  slug: "javascript"
image: https://kungfutech.edu.vn/thumbnail.png
position: 9
---

JavaScript giúp bạn xử lý hàm rất linh động. Bạn có thể **truyền hàm vào hàm khác qua tham số** hoặc **sử dụng hàm như object**. Và sau đây, mình sẽ giới thiệu về kỹ thuật decorator và forwarding hàm trong JavaScript.

## Caching hàm trong JavaScript

Giả sử bạn có một hàm khá nặng `slow(x)` - tốn nhiều CPU khi chạy. Tuy nhiên, kết quả của hàm lại **ổn định**. Nghĩa là với mỗi giá trị của tham số `x` giống nhau thì kết quả trả về của hàm `slow(x)` cũng giống nhau.

Nếu hàm `slow(x)` được gọi thường xuyên, bạn có thể sẽ muốn **cache** (ghi nhớ) kết quả để tránh việc phải tính toán lại.

Thay vì phải sửa logic của hàm `slow(x)`, bạn có thể tạo ra một **hàm wrapper**. Hàm này nhận hàm `slow()` làm tham số và xử lý thêm phần caching, ví dụ:

```js
function slow(x) {
  // có thể có các tác vụ nặng, tốn CPU
  console.log(`Đã được gọi với ${x}`);
  return x;
}

// hàm wrapper
function cachingDecorator(func) {
  let cache = new Map(); // tạo map để cache

  return function (x) {
    if (cache.has(x)) {
      // nếu tồn tại key là x thì trả về kết quả đã tương ứng
      return cache.get(x);
    }

    let result = func(x); // ngược lại thì gọi hàm

    cache.set(x, result); // thêm kết quả vào cache

    return result; // trả về kết quả
  };
}

slow = cachingDecorator(slow);

console.log(slow(1)); // cache lại kết quả của slow(1) rồi trả về kết quả
console.log("Gọi lại: " + slow(1)); // kết quả của slow(1) được lấy từ cache

console.log(slow(2)); // cache lại kết quả của slow(2) rồi trả về kết quả
console.log("Gọi lại: " + slow(2)); // kết quả của slow(1) được lấy từ cache
```

<content-result>

<code>Đã được gọi với 1</code>
<code>1</code>
<code>Gọi lại: 1</code>
<code>Đã được gọi với 2</code>
<code>2</code>
<code>Gọi lại: 2</code>

</content-result>

Trong ví dụ trên, hàm `cachingDecorator` được gọi là **decorator** - một hàm đặc biệt, nhận tham số đầu vào là một hàm khác và bổ sung thêm các tính năng.

Ý tưởng ở đây là bạn có thể gọi hàm `cachingDecorator` với bất kỳ hàm nào và trả về một hàm wrapper đã có tính năng cache. Bởi vì thực tế, bạn sẽ có nhiều hàm cần sử dụng tính năng caching này.

Những lợi ích của việc sử dụng hàm `cachingDecorator` là:

- Hàm `cachingDecorator` có thể tái sử dụng. Bạn có thể **tách ra thành thư viện** rồi sử dụng lại với nhiều hàm và nhiều nơi khác nhau.
- Logic caching được tách riêng, tránh làm tăng độ phức tạp của hàm `slow()`.
- Có thể kết hợp nhiều decorator khi cần.

## Sử dụng `func.call`

Thực tế, cách triển khai hàm `cachingDecorator` như trên là không phù hợp với [phương thức của object](/bai-viet/javascript/phuong-thuc-trong-javascript), ví dụ:

```js
"use strict";

// hàm slow là phương thức của object worker
let worker = {
  someMethod() {
    return 1;
  },
  slow(x) {
    // có thể có thao tác tốn CPU
    console.log("Được gọi với " + x);
    return x * this.someMethod(); // (*)  },
};
}
// code giống như trên
function cachingDecorator(func) {
  let cache = new Map();
  return function (x) {
    if (cache.has(x)) {
      return cache.get(x);
    }
    let result = func(x); // (**)    cache.set(x, result);
    return result;
  };
}
console.log(worker.slow(1)); // gọi code bình thường vẫn đúng
worker.slow = cachingDecorator(worker.slow); // khi sử dụng với caching
console.log(worker.slow(2));
// Lỗi:
// Cannot read properties of undefined (reading 'someMethod')
```

Lỗi trên xảy ra ở `(*)` khi gọi `this.someMethod`. Bởi vì ở `(**)`, hàm `cachingDecorator` gọi hàm `func(x)` theo cách này thì giá trị của `this` sẽ là `undefined`.

Bạn có thể thấy lỗi tương tự nếu làm như sau:

```js
let func = worker.slow;
func(2);
```

Nguyên nhân gây ra lỗi trên là vì hàm wrapper đã gọi hàm gốc mà không có biến context `this`.

Để giải quyết vấn đề trên, bạn có thể sử dụng phương thức `func.call(context,...args)`. Phương thức này cho phép truyền vào giá trị của `this` với cú pháp đầy đủ là:

```js
func.call(context, arg1, arg2, ...)
```

Phương thức `func.call` gọi hàm `func` với tham số đầu tiên tương ứng giá trị của `this` và theo sau là danh sách các tham số của hàm, ví dụ:

```js
func(1, 2, 3);
func.call(obj, 1, 2, 3);
```

Hai cách gọi hàm trên **cơ bản giống nhau**, chỉ khác ở cách gọi `func.call` thì giá trị của `this` bằng `obj`.

Ví dụ hàm `sayHi` sau đây được gọi với hai ngữ cảnh `this` khác nhau:

```js
function sayHi() {
  console.log(this.name);
}

let user = { name: "Alex" };
let admin = { name: "Admin" };

// gọi hàm sayHi với giá trị của `this` khác nhau
sayHi.call(user); // Alex
sayHi.call(admin); // Admin
```

Quay lại ví dụ về caching trên, bây giờ bạn có thể áp dụng phương thức `func.call` như sau:

```js
"use strict";

// hàm slow là phương thức của object worker
let worker = {
  someMethod() {
    return 1;
  },
  slow(x) {
    // có thể có thao tác tốn CPU
    console.log("Được gọi với " + x);
    return x * this.someMethod(); // (*)  },
  },
};
// code giống như trên
function cachingDecorator(func) {
  let cache = new Map();
  return function (x) {
    if (cache.has(x)) {
      return cache.get(x);
    }
    let result = func.call(this, x); // (**)    cache.set(x, result);
    return result;
  };
}

worker.slow = cachingDecorator(worker.slow);
console.log(worker.slow(2));
console.log(worker.slow(2));
```

Bây giờ, mọi thứ đã bình thường và không có lỗi xảy ra. Và đoạn code trên có thể hiểu như sau:

- Sau hàm `cachingDecorator`, hàm `worker.slow` được gán bằng hàm wrapper `function(){...}`.
- Vì vậy, khi gọi `worker.slow(2)`, hàm wrapper nhận `2` là tham số truyền vào và `this=worker` vì `worker` là object trước dấu chấm `.`.

## Caching hàm với nhiều tham số

Cách triển khai hàm `cachingDecorator` như trên chỉ áp dụng được với **hàm có 1 tham số đầu vào**. Giả sử, mình muốn sử dụng `cachingDecorator` với nhiều tham số thì sao?

```js
let worker = {
  slow(min, max) {
    // giả sử có thao tác tốn CPU
    return min + max;
  },
};

// ghi nhớ kết quả với các tham số truyền vào
worker.slow = cachingDecorator(worker.slow);
```

Với hàm một tham số `x`, bạn có thể sử dụng `cache.set(x, result)` để lưu kết quả và dùng `cache.get(x)` để lấy kết quả đã cache.

Nhưng với trường hợp bạn cần ghi nhớ hai tham số `(min, max)` thì cách trên lại không dùng được ngay. Vì [kiểu dữ liệu Map](/bai-viet/javascript/map-trong-javascript) chỉ áp dụng được với **1 key**.

Có nhiều cách để giải quyết vấn đề này:

1.  Triển khai (hoặc dùng thư viện) kiểu dữ liệu **map-like** hỗ trợ nhiều key.
2.  Sử dụng **Map lồng nhau**: ví dụ sử dụng `cache.set(min, value)` trong đó `value` ứng với cặp `(max, result)`. Để lấy kết quả, bạn chỉ cần dùng `cache.get(min).get(max)`.
3.  Ghép các giá trị thành một: ví dụ bạn dùng một string `min,max` để biểu diễn cho cặp giá trị `(min,max)`. Và để linh động hơn, bạn có thể cho phép cung cấp hàm `hash` vào hàm decorator làm nhiệm vụ **chuyển đổi nhiều giá trị thành một giá trị**.

Ví dụ cách sử dụng hàm `hash` như sau:

```js
let worker = {
  slow(min, max) {
    console.log(`Được gọi với ${min},${max}`);
    return min + max;
  },
};

function cachingDecorator(func, hash) {
  let cache = new Map();
  return function () {
    let key = hash(arguments); // (*)    if (cache.has(key)) {
    return cache.get(key);
  };

  let result = func.call(this, ...arguments); // (**)
  cache.set(key, result);
  return result;
}

function hash(args) {
  return args[0] + "," + args[1];
}

worker.slow = cachingDecorator(worker.slow, hash);

console.log(worker.slow(3, 5)); // hoạt động bình thường
console.log("Gọi lại " + worker.slow(3, 5)); // kết quả từ cache
```

Ví dụ trên có hai thay đổi là:

- Ở `(*)`: `key` là kết quả của việc gọi hàm `hash(arguments)`. Hàm `hash` đơn giản là ghép hai tham số thành một string bằng dấu phẩy `,`.
- Sau đó ở `(**)`: sử dụng `func.call(this, ...arguments)` để truyền vào cả giá trị `this` và tất cả các tham số qua cú pháp spread `...`.

## Sử dụng `func.apply`

Thay vì sử dụng cú pháp `func.call(this, ...arguments)`, bạn có thể dùng `func.apply(this, arguments)` với cú pháp đầu đủ là:

```js
func.apply(context, args);
```

Phương thức trên gọi hàm `func` với `this=context` và tham số đầu vào là `args` có kiểu dữ liệu **array-like**.

Khác nhau cơ bản giữa `func.apply` và `func.call` là ở cách truyền tham số:

- `func.apply`: nhận tham số đầu vào dạng **array-like**.
- `func.call`: nhận vào là một danh sách các tham số.

```js
func.call(context, ...args);
func.apply(context, args);
```

Trong hai cách gọi trên, `func.apply` có vẻ nhanh hơn, bởi vì JavaScript Engine tối ưu cách này hơn.

Ngoài ra, cách chuyển hết các tham số từ hàm này sang hàm khác gọi là **kỹ thuật forwarding**, ví dụ:

```js
let wrapper = function () {
  return func.apply(this, arguments);
};
```

Khi hàm `wrapper` được gọi, thực chất hàm này lại chuyển hết tham số sang hàm `func` để gọi hàm `func`.

## Kỹ thuật mượn phương thức

Hàm `hash` bên trên đang chỉ xử lý trường hợp có **hai tham số đầu vào**.

```js
function hash(args) {
  return args[0] + "," + args[1];
}
```

Nhưng tốt hơn hết là hàm `hash` hoạt động được với **số lượng tham số tùy ý**. Và cách sử dụng cơ bản nhất là sử dụng phương thức [`arr.join`](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array/join).

```js
function hash(args) {
  return args.join();
}
```

Tuy nhiên, cách trên lại không dùng được. Bởi vì cách gọi `hash(arguments)` trước đó lại truyền vào tham số `arguments` vừa là [iterable object](/bai-viet/javascript/iterable-trong-javascript) và vừa là array-like, nhưng **không phải array**.

```js
function hash() {
  console.log(arguments.join());
}

hash(1, 2);

// Uncaught TypeError: arguments.join is not a function
```

Để giải quyết vấn đề trên, bạn có thể sửa lại như sau:

```js
function hash() {
      console.log([].join.call(arguments)); // 1,2}

    hash(1, 2);
```

Cách trên gọi là **kỹ thuật mượn phương thức** - borrowing method.

Cụ thể là mình đã mượn phương thức `[].join` của mảng `[]` và sử dụng `[].join.call` với context là `this=arguments`.

## Decorator và thuộc tính của hàm

Nhìn chung, việc sử dụng decorator thể thay thế hàm hoặc phương thức của object là an toàn, ngoại trừ một trường hợp. Nếu hàm gốc sử dụng kiểu [function object](/bai-viet/javascript/function-object-trong-javascript), nghĩa là có thuộc tính, kiểu `func.calledCount`.

Nếu truyền hàm `func` trên qua decorator thì hàm wrapper sẽ không có thuộc tính `calledCount`. Vì thực chất là decorator đã tạo ra một hàm mới.

## Tổng kết

**Kĩ thuật decorator** là cách tạo ra hàm wrapper chứa hàm gốc và bổ sung thêm một số tính năng khác, với ưu điểm:

- Thêm các tính năng vào hàm gốc mà không làm phức tạp logic của hàm gốc.
- Có thể tách biệt code để sử dụng lại.
- Và có thể kết hợp nhiều hàm decorator với nhau.

Để triển khai decorator, bạn có thể sử dụng các phương thức:

- `func.call(context, ...args)` để gọi hàm `func` với `this=context` và các tham số `args`.
- `func.apply(context, args)` để gọi hàm `func` với `this=context` và tham số `args` kiểu array-like.

**Kỹ thuật forwarding** là cách chuyển toàn bộ tham số từ hàm này sang hàm khác:

```js
let wrapper = function () {
  return original.apply(this, arguments);
};
```

**Kỹ thuật mượn phương thức** là cách mượn phương thức của một object và gọi nó với object khác. Phổ biến nhất là cách lấy các phương thức hàm để áp dụng cho kiểu array-like như đối tượng `arguments`.

## Thực hành

### Bài 1

Viết hàm decorator `spy(func)` trả về hàm wrapper giúp lưu lại tất cả các tham số của các lời gọi hàm, ví dụ:

```js
function work(a, b) {
  console.log(a + b);
}

work = spy(work);
work(1, 2); // 3
work(4, 5); // 9

for (let args of work.calls) {
  console.log("call:" + args.join()); // "call:1,2", "call:4,5"
}
```

Xem đáp án

```js
function work(a, b) {
  console.log(a + b);
}

function spy(func) {
  function f() {
    // push vào mảng các tham số    f.calls.push([...arguments]);    // forwarding lại về hàm func    return func.apply(this, arguments);  }  // khai báo thuộc tính hàm  f.calls = [];  return f;}
    work = spy(work);

    work(1, 2); // 3
    work(4, 5); // 9

    for (let args of work.calls) {
      console.log("call:" + args.join()); // "call:1,2", "call:4,5"
    }
  }
}
```

### Bài 2

Viết hàm decorator `delay(f, ms)` trì hoãn lại gọi hàm `f` sau `ms` mili giây, ví dụ:

```js
function f(x) {
  console.log(x);
}

// hàm wrapper
let f1000 = delay(f, 1000);
let f1500 = delay(f, 1500);
f1000("test"); // hiển thị "test" sau 1000ms
f1500("test"); // hiển thị "test" sau 1500ms
```

Xem đáp án

```js
function f(x) {
  console.log(x);
}

function delay(func, ms) {
  return function () {
    setTimeout(() => func.apply(this, arguments), ms);
  };
}
// hàm wrapper
let f1000 = delay(f, 1000);
let f1500 = delay(f, 1500);

f1000("test"); // hiển thị "test" sau 1000ms
f1500("test"); // hiển thị "test" sau 1500ms
```

Tham khảo: [Decorators and forwarding, call/apply](https://javascript.info/call-apply-decorators)
