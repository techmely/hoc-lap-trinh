---
title: "Dấu ba chấm trong Javascript"
description: "Dấu ba chấm trong JavaScript được sử dụng trong rất nhiều hàm, cho phép truyền tham số vào hàm không giới hạn số lượng"
keywords: [
"dau 3 cham trong javascript",
"dau 3 cham trong javascript la gi",
"cach su dung dau 3 cham trong javascript",
"Dấu 3 chấm trong JavaScript là gì",
"Cách sử dụng dấu 3 chấm trong JavaScript",
"toan tu spread trong javascript",
"Toán tử spread trong JavaScript",
"Spread trong JavaScript",
"Dấu trong JavaScript"
]
chapter:
  name: "Kiến thức nâng cao về hàm"
  slug: "chuong-05-kien-thuc-nang-cao-ve-ham"
category:
  name: "Javascript"
  slug: "javascript"
image: https://user-images.githubusercontent.com/29374426/168245396-7febe5dc-f20f-485b-a96d-79801f6cbc05.png
position: 2
---

![Dấu ba chấm trong Javascript](https://user-images.githubusercontent.com/29374426/168245396-7febe5dc-f20f-485b-a96d-79801f6cbc05.png)


Rất nhiều hàm trong JavaScript hỗ trợ truyền vào **số lượng tham số không giới hạn**, ví dụ:

- `Math.max(arg1, arg2, ..., argN)`: trả về giá trị lớn nhất của các tham số truyền vào.
- `Object.assign(dest, src1, ..., srcN)`: [copy các thuộc tính](/bai-viet/javascript/copy-object-trong-javascript) từ object `src1...N` vào `dest`.
- ...

Để làm được điều đó, bạn có thể sử dụng **dấu ba chấm trong JavaScript**.

## Tham số còn lại của hàm `...args`

Trong JavaScript, một hàm có thể được gọi với **số lượng tham số truyền vào tùy ý**, bất kể hàm đó được định nghĩa như thế nào, ví dụ:

```js
// hàm tính tổng hai số
function sum(a, b) {
  return a + b;
}

// gọi hàm và truyền vào số lượng tham số lớn hơn định nghĩa
console.log(sum(1, 2, 3, 4, 5)); // 3
```

Hàm `sum` được định nghĩa gồm hai tham số `a` và `b`. Khi gọi hàm, mình đã **truyền vào số lượng tham số nhiều hơn** và không có lỗi xảy ra, mặc dù kết quả vẫn là tổng hai số đầu tiên.

Các tham số còn lại của hàm **có thể gom lại thành một mảng** bằng cách sử dụng **dấu ba chấm trong JavaScript**, theo sau bởi **tên của một mảng** chứa các tham số còn lại này.

Ví dụ sau gom hết các tham số vào mảng `args`:

```js
// hàm tính tổng tất cả các tham số truyền vào
function sumAll(...args) {
  let sum = 0;

  // duyệt mảng để tính tổng
  for (let arg of args) {
    sum += arg;
  }

  return sum;
}

console.log(sumAll(1)); // 1
console.log(sumAll(1, 2)); // 3
console.log(sumAll(1, 2, 3)); // 6
```

Ngoài ra, bạn cũng có thể lấy **một vài tham số đầu tiên** thông qua biến. Các tham số còn lại cho vào mảng.

Ví dụ sau lấy hai tham số đầu tiên cho vào biến, các tham số còn lại cho vào mảng:

```js
function showName(firstName, lastName, ...titles) {
  console.log(`${firstName} ${lastName}`); // Julius Caesar

  // các biến còn lại được đưa vào mảng
  // ví dụ mảng titles = ["Consul", "Imperator"]
  console.log(titles[0]); // Consul
  console.log(titles[1]); // Imperator
  console.log(titles.length); // 2
}

showName("Julius", "Caesar", "Consul", "Imperator");
```

<content-warning>

cú pháp dấu ba chấm trong JavaScript để lấy các tham số còn lại của hàm phải đặt ở **cuối danh sách các tham số**

</content-warning>

Ví dụ sau sử dụng cú pháp dấu ba chấm ở giữa nên bị lỗi:

```js
function func(arg1, ...rest, arg2) {
      //
    }

    // Uncaught SyntaxError: Rest parameter must be last formal parameter
```

## Đối tượng `arguments`

Trong hàm có một đối tượng đặc biệt là `arguments`. Đây là đối tượng kiểu **array-like** và **iterable** chứa tất cả các tham số của hàm xác định bởi chỉ số, ví dụ:

```js
function sumAll() {
  for (let i = 0; i < arguments.length; i++) {
    console.log(arguments[i]);
  }

  // có thể dùng for...of
  // for (let arg of arguments) {
  //   console.log(arg);
  // }
}

sumAll(1, 2, 3, 4, 5);

/*
    1
    2
    3
    4
    5
    */
```

Khi cú pháp dấu ba chấm trong JavaScript chưa xuất hiện thì `arguments` là cách được sử dụng để lấy tất cả tham số truyền vào hàm.

Tuy nhiên, cách sử dụng `arguments` có nhược điểm là:

- `arguments` là **array-like** nên bạn không thể sử dụng các phương thức của mảng như `arguments.map(...)`.
- `arguments` luôn chứa tất cả các tham số của hàm. Bạn không thể chỉ lưu một số tham số như cú pháp dấu ba chấm được.
- [Arrow function](/bai-viet/javascript/arrow-function-trong-javascript) không có đối tượng `arguments`.

# Cú pháp spread

---

Bên trên bạn đã biết cách sử dụng cú pháp dấu ba chấm để lấy một mảng các tham số còn lại trong hàm. Tuy nhiên, nhiều khi bạn cần phải làm **ngược lại**.

Ví dụ khi sử dụng hàm [Math.max](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Math/max) để trả về giá trị lớn nhất trong các tham số truyền vào:

```js
console.log(Math.max(4, 7, 5)); // 7
```

Giả sử, bạn có một mảng `[4, 7, 5]`. Làm sao để gọi phương thức `Math.max` với mảng trên?

Bạn không thể truyền thẳng một mảng vào hàm vì `Math.max` không nhận tham số là mảng:

```js
let arr = [4, 7, 5];

console.log(Math.max(arr)); // NaN
```

Dĩ nhiên, bạn có thể lấy từng phần tử của mảng để truyền vào hàm:

```js
let arr = [4, 7, 5];

console.log(Math.max(arr[0], arr[1], arr[2])); // 7
```

Nhưng vấn đề ở đây là bạn **không biết trước số lượng các phần tử của mảng**. Nên cách làm trên là không hợp lý.

Để giải quyết vấn đề này, bạn có thể sử dụng **cú pháp spread**.

### Cú pháp spread là gì?

Cú pháp spread cũng sử dụng ba dấu chấm giống như cú pháp lấy các tham số còn lại của hàm như trên, nhưng cách thực hiện ngược lại.

Khi biến `arr` được sử dụng trong lời gọi hàm, mảng `arr` được phân tách ra thành danh sách các tham số hàm.

Ví dụ với hàm `Math.max` trên:

```js
let arr = [4, 7, 5];

console.log(Math.max(...arr)); // 7
// vì mảng [4, 7, 5] được tách ra thành danh sách các tham số là 4, 7, 5
```

Bạn có thể truyền nhiều [iterable object](/bai-viet/javascript/iterable-trong-javascript) vào hàm với cú pháp spread:

```js
let arr1 = [3, 5, 1];
let arr2 = [4, 6, 2];

console.log(Math.max(...arr1, ...arr2)); // 6
// cả hai mảng arr1, arr2 được trải ra và ghép lại thành dạng
// Math.max(3, 5, 1, 4, 6, 2)
```

Bạn cũng có thể **kết hợp cú pháp spread với việc truyền tham số thông thường**:

```js
let arr1 = [3, 5, 1];
let arr2 = [4, 6, 2];

console.log(Math.max(5, ...arr1, 10, ...arr2)); // 10

// tương đương với:
// Math.max(5, 3, 5, 1, 10, 4, 6, 2)
```

💡 Với bài toán **tách mảng thành các tham số để truyền vào hàm**, bạn có thể sử dụng phương thức apply như sau:

```js
let arr = [4, 7, 5];
console.log(Math.max.apply(null, arr)); // 7
```

Trước khi cú pháp spread xuất hiện thì đây là cách đơn giản nhất để giải quyết bài toán này.

## Ứng dụng cú pháp spread để ghép mảng

Cú pháp spread có thể dùng để ghép mảng, ví dụ:

```js
let arr1 = [3, 5, 1];
let arr2 = [4, 6, 2];
let arr = [...arr1, ...arr2];

console.log(arr); // (6) [3, 5, 1, 4, 6, 2]
```

Trong các ví dụ trên, mình dùng mảng với cú pháp spread. Thực chất, bạn có thể sử dụng **bất kỳ iterable object** nào.

Ví dụ sử dụng cú pháp spread để biến string thành mảng các ký tự:

```js
let str = "Hello";

console.log([...str]); // (5) ['H', 'e', 'l', 'l', 'o']
```

> Cú pháp spread **sử dụng iterator** để lấy các phần tử, giống như cú pháp `for...of`.

```js
let str = "Hello";

for (let ch of str) {
  console.log(ch); // H, e, l, l, o
}
```

Với string, `for...of` trả về mảng các ký tự và `...str` trở thành chuỗi `'H', 'e', 'l', 'l', 'o'`. Sau đó, danh sách các kí tự này được truyền vào `[]` để tạo mảng mới `[...str]`.

Với bài toán này, bạn có thể dùng `Array.from(str)` cũng cho kết quả tương tự, vì `Array.from()` chuyển đối tượng iterable thành mảng.

```js
let str = "Hello";

console.log(Array.from(str)); // (5) ['H', 'e', 'l', 'l', 'o']
```

Tuy nhiên, `Array.from` và cú pháp spread có sự khác nhau là:

- `Array.from` áp dụng được cho cả **đối tượng array-like và iterable object**.
- Cú pháp spread chỉ dùng được với **iterable object**.

## Copy mảng và object

---

Trong bài viết [copy object trong JavaScript](/bai-viet/javascript/copy-object-trong-javascript), mình đã đề cập tới cách sử dụng `Object.assign()` để copy object.

Ngoài ra, bạn cũng có thể dùng cú pháp spread để copy object và mảng.

Ví dụ về copy mảng với cú pháp spread:

```js
let arr = [1, 2, 3];

let arrCopy = [...arr];
// cú pháp spread tách mảng thành danh sách các tham số
// rồi truyền vào mảng mới

// kiểm tra lại nội dung của hai array trên
console.log(JSON.stringify(arr) === JSON.stringify(arrCopy)); // true

// so sánh bằng thông qua tham chiếu
console.log(arr === arrCopy); // false - không cùng tham chiếu

// thay đổi mảng arr, nhưng mảng arrCopy không thay đổi
arr.push(4);
console.log(arr); // (4) [1, 2, 3, 4]
console.log(arrCopy); // (3) [1, 2, 3]
```

Ví dụ dùng cú pháp spread trong JavaScript để copy object:

```js
let obj = { a: 1, b: 2, c: 3 };

let objCopy = { ...obj };
// cú pháp spread tách đối tượng thành danh sách key-value
// rồi truyền vào object mới

// kiểm tra nội dung hai obj
console.log(JSON.stringify(obj) === JSON.stringify(objCopy)); // true

// so sánh qua tham chiếu
console.log(obj === objCopy); // false - vì không cùng tham chiếu

// sửa đối tượng obj, nhưng đối tượng objCopy không thay đổi
obj.d = 4;
console.log(JSON.stringify(obj)); // {"a":1,"b":2,"c":3,"d":4}
console.log(JSON.stringify(objCopy)); // {"a":1,"b":2,"c":3}
```

Rõ ràng, cách sử dụng cú pháp spread **ngắn gọn hơn** việc sử dụng `Object.assign` như sau:

```js
// copy object
let objCopy = Object.assign({}, obj);

// copy mảng
let arrCopy = Object.assign([], arr);
```

## Phân biệt 2 loại cú pháp dấu ba chấm

Như mình đã trình bày ở trên, cú pháp dấu ba chấm có thể dùng để:

- Lấy danh sách các tham số còn lại trong hàm
- Hoặc là cú pháp spread để tách mảng thành danh sách các tham số.

Cách phân biệt hai loại cú pháp trên là:

► Cú pháp lấy danh sách các tham số còn lại trong hàm

Dấu `...` được sử dụng ở **định nghĩa hàm** và luôn đặt cuối trong danh sách các tham số.

```js
// định nghĩa hàm
function fn1(arg1, arg2, ...args) {
  //
}

// gọi hàm
fn1(1, 2, 3, 4, 5, 6);
```

► Cú pháp spread

Dấu `...` được sử dụng ở **lời gọi hàm** (hoặc trong mảng, object) và có thể đặt ở bất kỳ đâu trong danh sách các tham số:

```js
// định nghĩa hàm
function fn1(arg1, arg2, arg3, arg4) {
  //
}

// gọi hàm
let arr = [1, 2, 3, 4];
fn1(...arr);
```

## Tổng kết

Cú pháp ba chấm trong JavaScript có thể là cú pháp để lấy tham số còn lại trong hàm hoặc cú pháp spread.

Cách đơn giản để phân biệt hai loại trên là:

- **Cú pháp để lấy tham số còn lại trong hàm**: dấu ba chấm `...` được dùng ở định nghĩa hàm và luôn đặt ở cuối danh sách tham số.
- **Cú pháp spread**: dấu ba chấm `...` được dùng ở lời gọi hàm (hoặc trong mảng, object) và có thể đặt ở bất kỳ đâu trong danh sách các tham số.

Ứng dụng:

- **Cú pháp để lấy tham số còn lại trong hàm**: được dùng để xây dựng hàm cho phép truyền vào số lượng tham số tùy ý.
- **Cú pháp spread**: được dùng để tách mảng thành danh sách các tham số truyền vào hàm hoặc ghép/copy mảng, ghép/copy object.
