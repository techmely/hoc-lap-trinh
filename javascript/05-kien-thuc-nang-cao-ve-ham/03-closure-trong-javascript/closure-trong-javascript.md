---
title: "Closure trong Javascript"
description: "Closure là một chức năng có quyền truy cập vào phạm vi cha, ngay cả sau khi scope đã đóng."
keywords: [
"javascript closure là gì",
"Cách sử dụng closure trong javascript",
"truy cập biến của hàm bên ngoài trong javascript",
"Closure la gì trong javascript",
"Scope trong Javascript",
"ví dụ về Closure trong Javascript",
"hàm closure trong javascript",
"hàm closure trong javascript là gì",
"Cách sử dụng hàm closure trong javascript",
"hướng dẫn hàm closure trong javascript"
]
chapter:
  name: "Kiến thức nâng cao về hàm"
  slug: "chuong-05-kien-thuc-nang-cao-ve-ham"
category:
  name: "Javascript"
  slug: "javascript"
image: https://user-images.githubusercontent.com/29374426/168245638-7082c1ed-ea00-4de8-bedd-41d3cc39e12e.png
position: 3
---

Closure trong JS là một trong những **khái niệm quan trọng**. Việc nắm chắc JavaScript closure là gì và cách sử dụng closure trong JavaScript giúp bạn viết code tốt hơn.

![Closure trong Javascript](https://user-images.githubusercontent.com/29374426/168245638-7082c1ed-ea00-4de8-bedd-41d3cc39e12e.png)


## JavaScript closure là gì?

---

JavaScript closure là tập hợp bao gồm một hàm và **môi trường** nơi hàm đó được khai báo, gọi là **lexical environment**.

Trong đó, **lexical environment** được hiểu là tất cả những biến cục bộ trong hàm và trạng thái của các biến ở phạm vi ngoài hàm.

Closure trong JS có thể truy cập [biến](/bai-viet/javascript/bien-trong-javascript) ở **3 phạm vi** khác nhau là:

- Biến toàn cục (global)
- Biến được khai báo ở ngoài hàm (outer function)
- Biến ở trên trong hàm closure (local)

Ví dụ về các phạm vi biến:

```js
// biến global
let YEAR = "2021";

function greet(name) {
  // biến local trong hàm greet
  // đồng thời là biến ngoài hàm sayHello
  let intro = "Hello";

  function sayHello() {
    // biến local của hàm sayHello
    let message = `${intro} ${name} in ${YEAR}`;
    console.log(message);
  }

  sayHello();
}

greet("Dev");
// Hello Dev in 2021
```

Để hiểu hơn về phạm vi của biến, sau đây mình sẽ tìm hiểu về khái niệm "khối code" hay tiếng anh là **code block**.

<content-warning>

📝 **Chú ý:** các ví dụ sau đây chỉ áp dụng cho cách khai báo biến với `let/const`. Cách khai báo biến với `var` đã lỗi thời và `var` có logic riêng.

</content-warning>

## Code block là gì?

Nếu một biến được khai báo **bên trong một code block** `{...}` thì biến "chỉ được nhìn thấy" ở khối code đó.

Ví dụ về code block:

```js
// sau đây là một khối code
{
  let message = "Hi"; // biến message chỉ được nhìn thấy ở trong block
  console.log(message); // Hi
}

console.log(message); // Error: message is not defined
```

Bạn có thể ứng dụng code block để tạo ra các đoạn code riêng biệt mà không sợ bị **xung đột về tên biến**.

```js
// block 1
{
  let message = "Hi";
  console.log(message); // Hi
}

// block 2
{
  let message = "Hello";
  console.log(message); // Hello
}
```

Nếu không có code block thì sẽ xảy ra lỗi "biến đã được khai báo":

```js
let message = "Hi";
console.log(message); // Hi

let message = "Hello";
// Uncaught SyntaxError: Identifier 'message' has already been declared
```

Ví dụ về `if`, `for`, `while`,... các biến được khai báo bên trong `{...}` cũng chỉ được nhìn thấy bên trong:

```js
if (true) {
  let message = "hello";
  console.log(message); // hello
}

console.log(message); // Uncaught ReferenceError: message is not defined
```

Sau [câu lệnh rẽ nhánh `if`](/bai-viet/javascript/cau-truc-re-nhanh-trong-javascript), biến `message` không được nhìn thấy, nên đã có lỗi "message is not defined".

Tương tự với [vòng lặp `for`](/bai-viet/javascript/vong-lap-trong-javascript):

```js
for (let i = 0; i < 3; i++) {
  // biến i chỉ được nhìn thấy bên trong for
  console.log(i); // 0, 1, 2
}

console.log(i); // Uncaught ReferenceError: i is not defined
```

Trong ví dụ trên, bạn đấy `let i` không nằm trong `{...}`. Tuy nhiên, vòng lặp `for` là một cú pháp đặc biệt.

Biến được khai báo bên trong `for(...)` là biến cục bộ bên trong code block `{...}` của `for`.

## Hàm lồng nhau

Hàm lồng nhau được hiểu là **một hàm được khai báo bên trong hàm khác**, tiếng anh là **nested function**, ví dụ:

```js
function sayHiBye(firstName, lastName) {
  // getFullName là nested function
  function getFullName() {
    return `${firstName} ${lastName}`;
  }

  console.log("Hello, " + getFullName());
  console.log("Bye, " + getFullName());
}
```

Trong ví dụ trên, hàm `getFullName` là một nested function được khai báo bên trong hàm `sayHiBye`.

Hàm `getFullName` có thể truy cập tới biến ngoài hàm `firstName`, `lastName` và trả về giá trị "fullName".

Điều đặc biệt ở đây là bạn có thể "return" về nested function. Sau đó, bạn có thể **sử dụng hàm trả về ở bất kỳ đâu** mà vẫn có thể truy cập được vào biến ngoài hàm (outer function) một cách giống nhau.

Ví dụ hàm `makeCounter` trả về giá trị `count` tiếp theo sau mỗi lần gọi:

```js
function makeCounter() {
  // ban đầu counter bằng 0
  let count = 0;

  // trả về một hàm khác
  // hàm này return về counter rồi tăng biến counter lên 1 đơn vị
  return function () {
    return count++;
  };
}

// sử dụng -> counter chính là nested function
let counter1 = makeCounter();

// sau mỗi lần gọi hàm counter1() thì giá trị count tăng lên 1
console.log(counter1()); // 0
console.log(counter1()); // 1
console.log(counter1()); // 2

// tạo counter2, giá trị count độc lập với counter1
let counter2 = makeCounter();

// khi gọi counter2(), giá trị count vẫn bắt đầu từ 0, chứ không phải 2
console.log(counter2()); // 0
console.log(counter2()); // 1
console.log(counter2()); // 2
```

## Đặc điểm của closure trong JS

Nếu bạn muốn hiểu sâu và vận dụng được JavaScript closure thì sau đây là những đặc điểm quan trọng mà bạn cần nắm vững.

► **Hàm closures có thể truy cập tới biến của hàm chứa nó, dù cho hàm đó đã return**

Thông thường, khi một hàm đã **return** thì biến cục bộ trong hàm đó cũng được giải phóng.

Nhưng với closure trong JS thì khác, bạn vẫn có thể truy cập đến những biến cục bộ đó ngay cả khi outer function đã thực hiện xong.

```js
function adder(n) {
  let intro = "This answer is ";
  let local = n;

  return function (number) {
    let result = number + local;
    console.log(intro + result);
  };
}

let adder2 = adder(2);
adder2(10);
// This answer is 12
```

Trong ví dụ trên, hàm closures là một hàm không tên `function(number)`. Hàm closures này sử dụng biến cục bộ của outer function là `intro` và `local`.

Khi mình gọi hàm `adder(2)`, hàm này thực hiện và kết quả trả về được gán vào biến `adder2`. Nói cách khác, `adder2` chứa **nested function** được trả về từ việc gọi hàm `adder(2)`.

Sau đó, mình gọi `adder2(10)` và kết quả trả về là `12`.

Chứng tỏ, hàm closures vẫn có thể truy cập tới biến cục bộ của outer function là `intro`, `local` ngay cả khi hàm outer `adder2` đã thực hiện xong.

► **Hàm closures lưu trữ biến của outer function theo kiểu tham chiếu**

Xét ví dụ dưới đây:

```js
function ObjId() {
  let id = 1;

  return {
    getId: function () {
      return id;
    },
    setId: function (_id) {
      id = _id;
    },
  };
}

let myObject = ObjId();
console.log(myObject.getId()); // 1

myObject.setId(10);
console.log(myObject.getId()); // 10
```

Hàm khởi tạo `ObjId` trả về một đối tượng bao gồm 2 hàm closures là `getId` và `setId`. Các hàm closures này sử dụng chung một biến cục bộ là `id`.

Ban đầu, mình gọi `myObject.getId()` thì kết quả trả về là `1` (giá trị của biến cục bộ). Sau đó, mình gọi `myObject.setId(10)` để cập nhật giá trị của `id`.

Nếu closure trong JS chỉ **lưu biến cục bộ theo giá trị** thì suy ra giá trị của biến cục bộ `id` sẽ không thay đổi. Nhưng khi mình gọi tiếp `myObject.getId()` thì giá trị trả về là `10`.

Chứng tỏ, hàm closures phải **lưu biến cục bộ theo kiểu tham chiếu**.

## Thực hành

---

### Bài 1

Cho đoạn code sau:

```js
let name = "Alex";

function sayHi() {
  console.log("Hi, " + name);
}

name = "Anna";

sayHi();
```

Hỏi kết quả khi gọi `sayHi()` là "Alex" hay "Anna"?

Xem đáp án

<content-result>

Anna

</content-result>

Biến `name` là biến toàn cục. Khi hàm `sayHi` được gọi, giá trị của `name` là giá trị mới nhất.

### Bài 2

Cho đoạn code sau:

```js
function makeWorker() {
  let name = "Alex";

  return function () {
    console.log(name);
  };
}

let name = "Anna";

// tạo một function mới
let work = makeWorker();

// gọi hàm
work();
```

Hỏi kết quả của `worker()` là "Alex" hay "Anna"?

Xem đáp án

<content-result>

Alex

</content-result>

Nested function bên trong hàm `makeWorker` truy cập tới biến ngoài hàm là `name = "Alex"`.

Dù sau đó, mình có khai báo biến toàn cục `let name = "Anna"` thì biến `name` này ở phạm vi khác với biến `name` trong hàm closure.

### Bài 3

Cho đoạn code sau:

```js
"use strict";

let message = "Hello";

if (true) {
  let user = "Alex";

  function sayHi() {
    console.log(`${message}, ${user}`);
  }
}

sayHi();
```

Kết quả sau khi gọi `sayHi()` là gì?

Xem đáp án

<content-result>

Uncaught ReferenceError: sayHi is not defined

</content-result>

Hàm `sayHi` được khai báo trong `if`, nên chỉ được nhìn thấy trong block code của `if`.

### Bài 4

Viết hàm `sum(a)(b)` trả về tổng `a + b`, ví dụ:

```js
sum(1)(2) = 3
sum(2)(-1) = 1
```

Xem đáp án

Để gọi hàm được theo cách `sum(a)(b)` thì phải sử dụng closure trong JS:

```js
function sum(a) {
  return function (b) {
    return a + b;
  };
}

console.log(sum(1)(2)); // 3
console.log(sum(2)(-1)); // 1
```

### Bài 5

Cho đoạn code sau:

```js
let x = 1;

function func() {
  console.log(x); // (*)
  let x = 2;
}

func();
```

Kết quả `(*)` là gì?

Xem đáp án

<content-result>

Uncaught ReferenceError: Cannot access 'x' before initialization

</content-result>

Vì trong hàm có `let x = 2`, nghĩa là biến `x` có tồn tại trong phạm vi của hàm `func`. Nhưng bạn không thể truy cập đến biến `x` trước câu lệnh `let x`.

Trường hợp trong hàm `func` không có `let x = 2` thì giá trị của `x` là giá trị của biến `x` bên ngoài hàm.

### Bài 6

Cho mảng `users` sau:

```js
let users = [
  { name: "Alex", age: 28 },
  { name: "Pete", age: 20 },
  { name: "Ann", age: 24 },
];
```

Ví dụ sắp xếp mảng theo `name` và `age`:

```js
// theo `name` (Alex, Ann, Pete)
users.sort((a, b) => (a.name > b.name ? 1 : -1));

// theo `age` (Pete, Ann, Alex)
users.sort((a, b) => (a.age > b.age ? 1 : -1));
```

Thay vì phải viết code lặp lại như trên, hãy viết hàm `byField(fieldName)` để có thể sử dụng với `sort` như sau:

```js
users.sort(byField("name"));
users.sort(byField("age"));
```

Xem đáp án

Để viết hàm `byField`, bạn có thể sử dụng closure trong JS để trả về nested function ứng với mỗi `fieldName` như sau:

```js
function byField(fieldName) {
  return (a, b) => (a[fieldName] > b[fieldName] ? 1 : -1);
}
```

Tham khảo:

- [Closures](https://developer.mozilla.org/en/docs/Web/JavaScript/Closures/)
- [Understand JavaScript Closures With Ease](http://javascriptissexy.com/understand-javascript-closures-with-ease/)
- [Variable scope, closure](https://javascript.info/closure)
