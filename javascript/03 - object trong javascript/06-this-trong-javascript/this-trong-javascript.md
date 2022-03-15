---
title: "This trong Javascript"
description: "Trong bài viết này, mình sẽ bạn sẽ tìm hiểu về giá trị "this" trong JavaScript và hiểu nó rõ ràng trong các ngữ cảnh khác nhau."
keywords: [
"đối tượng trong javascript",
"object trong javascript",
"This trong Javascript",
"this value trong javascript",
"con tro this trong arrow function javascript",
"this trong class javascript",
"tu khoa this trong javascript the hien",
"từ khóa this trong javascript",
"this trong javascript dùng để làm gì",
"this trong javascript là gì",
"this trong javascript cách sử dụng",
"hàm this trong javascript"
]
chapter:
  name: "Object trong Javascript"
  slug: "chuong-03-object-trong-javascript"
category:
  name: "Javascript"
  slug: "javascript"
image: https://kungfutech.edu.vn/thumbnail.png
position: 6
---

Trong bài viết này, mình sẽ bạn sẽ tìm hiểu về giá trị `this` trong JavaScript và hiểu nó rõ ràng trong các ngữ cảnh khác nhau.

`this` chính là bối cảnh(context) của nơi mà hàm chứa từ this được gọi. Bạn hãy nhớ từ `this` tham chiếu tới cái vùng không gian mà hàm chứa từ `this` được gọi. Chỉ có 2 loại context đối với `this` là `object` chứa method được gọi hoặc global , ngoài ra không có loại khác. Khi gặp từ `this` , chỉ quan tâm tới cái nơi gọi hàm chứa nó chứ không được dịch `this` là nội hàm hiện tại.

## this trong ngữ cảnh toàn cục

Trong ngữ cảnh toàn cục (global context), `this` tham chiếu đến đối tượng toàn cục, là đối tượng `window` trên trình duyệt web hoặc đối tượng global trên Node.js.

Hành vi này nhất quán cho dù chế độ nghiêm ngặt có được áp dụng hay không, ví dụ thử gọi câu lệnh này trong phạm vi cao nhất:

```js
console.log(this === window); // true
```

Nếu bạn gán một thuộc tính cho đối tượng `this` trong ngữ cảnh toàn cục, JavaScript sẽ thêm thuộc tính vào đối tượng toàn cục như trong ví dụ sau:

```js
this.color = "Red";
console.log(window.color); // 'Red'
```

## this trong ngữ cảnh hàm

Trong JavaScript, bạn có thể gọi một hàm theo những cách sau:

- Gọi hàm thông thường
- Gọi phương thức
- Gọi hàm khởi tạo
- Gọi hàm gián tiếp

Mỗi lời gọi hàm xác định ngữ cảnh riêng của nó, do đó, this có thể hoạt động khác với những gì bạn nghĩ

### this trong lời gọi hàm thông thường

#### Trong chế độ không nghiêm ngặt

Trong chế độ không nghiêm ngặt (non-strict mode), `this` tham chiếu đến đối tượng toàn cục khi hàm được gọi như sau:

```js
function run() {
  console.log(this === window); // true
}

run();
```

Khi bạn gọi hàm `run()`, this tham chiếu đến đối tượng toàn cục, là đối tượng `window` trên trình duyệt web và là đối tượng global trên Node.js.

Do đó, lệnh gọi hàm `run()` ở trên cũng tương đương như sau:

```js
window.run();
```

#### Trong chế độ nghiêm ngặt

Trong chế độ nghiêm ngặt (strict mode), để hạn chế hành vi không rõ ràng, lời gọi hàm như vậy sẽ được JavaScript đặt giá trị this thành `undefined`.

Ví dụ:

```js
"use strict"; // Khai báo strict mode

function run() {
  console.log(this === undefined); // true
}

run();
```

<content-info>
<ul>
  <li>Để thiết lập chế độ nghiêm ngặt, bạn có thể sử dụng chỉ thị "use strict" ở đầu tệp.</li>
  <li>Nếu bạn chỉ muốn áp dụng chế độ nghiêm ngặt cho một hàm cụ thể, bạn đặt nó ở đầu thân hàm.</li>
</ul>
</content-info>

### this trong gọi phương thức

Khi bạn gọi một phương thức của một đối tượng, JavaScript sẽ đặt `this` cho đối tượng sở hữu phương thức.

Xem đối tượng person sau:

```js
let person = {
  name: "Thaycacac",
  getName: function () {
    return this.name;
  },
};

console.log(person.getName()); // Thaycacac
```

Trong ví dụ này, đối tượng `this` trong phương thức `getName()` tham chiếu đến đối tượng `person`.

Và vì một phương thức là thuộc tính của một đối tượng, cũng là một giá trị, thế nên bạn có thể lưu trữ nó trong một biến như thế này:

```js
const name = person.getBrand;
```

Và sau đó, gọi phương thức thông qua biến rất bình thường như sau:

```js
console.log(brand()); // undefined
```

Kết quả, bạn nhận được `undefined` thay vì `Thaycacac` như mong đợi

Bởi vì, khi bạn gọi một phương thức mà không chỉ định đối tượng của nó, JavaScript sẽ đặt `this` thành đối tượng toàn cục ở chế độ không nghiêm ngặt và `undefined` trong chế độ nghiêm ngặt.

Để xử lý tình huống này, bạn có thể sử dụng phương thức `bind() ` mình sẽ đề cập ở bài khác. Bạn có thể xem ví dụ giới đây để có thể biết cách xử lý

```js
let name = person.getName.bind(person);
console.log(name()); // Thaycacac
```

Trong ví dụ trên, khi bạn gọi phương thức `name()`, từ khóa `this` được liên kết với đối tượng `person` bởi `bind()`

### this trong lời gọi hàm khởi tạo

Khi bạn sử dụng từ khóa `new` để tạo một thể hiện của một đối tượng hàm, bạn sử dụng hàm như một phương thức khởi tạo (constructor).

Ví dụ sau khai báo một hàm `Person`, sau đó gọi nó như một hàm tạo:

```js
function Person(name) {
  this.name = name;
}

Person.prototype.getName = function () {
  return this.name;
};

var name = new Person("Thaycacac");
console.log(name.getName());
```

Biểu thức `new Person('Thaycacac')` là một lệnh gọi hàm tạo của hàm `Person`.

JavaScript tạo một đối tượng mới và đặt đối tượng `this` thành đối tượng mới được tạo (Cách này hoạt động tốt nhưng có một vấn đề tiềm ẩn)

Bây giờ, bạn có thể gọi `Person()` dưới dạng một hàm hoặc như một phương thức khởi tạo.

```js
var girl = Person("Huyen");
console.log(girl.name);
// TypeError: Cannot read property 'name' of undefined
```

Vì giá trị `this` trong `Person()` được đặt thành đối tượng toàn cục, do đó `girl.name` trả về không xác định.

Để đảm bảo rằng hàm `Person()` luôn được gọi bằng cách gọi hàm tạo, bạn thêm kiểm tra vào đầu hàm `Person()` như sau:

```js
function Person(name) {
  if (!(this instanceof Person)) {
    throw Error("Phải sử dụng từ khóa new");
  }
  this.name = name;
}
```

ES6 đã giới thiệu một thuộc tính meta có tên `new.target` cho phép bạn phát hiện xem một hàm được gọi như một lời gọi hàm đơn giản hay như một hàm tạo.

Bạn có thể sửa đổi hàm `Person()` sử dụng `new.target` như sau:

```js
function Person(name) {
  if (!new.target) {
    throw Error("Phải sử dụng từ khóa new");
  }
  this.name = name;
}
```

### this trong lời gọi hàm gián tiếp

Trong JavaScript, các hàm là first-class citizens. Nói cách khác, các hàm là các đối tượng, là các thể hiện của kiểu `Function`.

Kiểu Function có hai phương thức: `call()` và `apply()`. Các phương thức này cho phép bạn đặt giá trị `this` khi gọi một hàm. Phần này chúng ta sẽ tìm hiểu ở bài bind, call, aplly

## this trong Arrow Function

ES6 đã giới thiệu một khái niệm mới có tên là Arrow Function, bạn cũng có thể gọi đến `this` trong đó.

Tuy nhiên, arrow function không tạo bối cảnh thực thi của riêng nó, mà kế thừa `this` từ hàm bên ngoài nơi arrow function được định nghĩa.

Ví dụ:

```js
let getThis = () => this;
console.log(getThis() === window); // true
```

Trong ví dụ này, giá trị `this` được đặt thành đối tượng toàn cục, tức là `window` trong trình duyệt web.

Và vì một hàm mũi tên không tạo ngữ cảnh thực thi của riêng nó, nên việc xác định một phương thức bằng arrow function sẽ gây ra sự cố.

```js
function Person() {
  this.name = "Thaycacac";
}

// Thêm vào đối tượng Person một hàm
// bằng arrow function
Person.prototype.getName = () => {
  return this.name;
};

var person = new Person();
person.getName(); // TypeError
```

Bên trong phương thức `getName()`, giá trị `this` tham chiếu đến đối tượng toàn cục, không phải đối tượng Person.

Do đó, lời gọi `person.getName()` gây ra lỗi vì đối tượng toàn cục không có thuộc tính `name`.

## this trong callback của hàm setTimeout

`this` trong hàm ẩn danh(anonymous function) luôn là global.

Không thể tham chiếu tới chính function trong callback của hàm `setTimeout` vì nó là anonymous function.

Ví dụ:

```js
var a = 10;
setTimeout(function () {
  // anonymous function (no name)
  var a = 20;
  console.log(this.a); // 10
}, 1000);
```

## this trong DOM event handler

```html
<button onclick="console.log(this)">Click me</button>
```

`this` khi event được trigger chính là `button` chứa event đó. Nhưng nếu bạn khai báo một hàm trong event handler thì `this` sẽ là `global`(window trong browser) vì `this` đã nằm trong hàm ẩn danh.

```html
<button onclick="console.log(myFunction())">Click me</button>

<script>
  function myFunction() {
    return this;
  }
</script>
```

hoặc

```html
<button onclick="console.log((function(){return this})());">Click me</button>
```
