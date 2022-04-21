---
title: "FPrototype của hàm trong JavaScript"
description: "FPrototype là khái niệm cốt lõi trong JavaScript và là cơ chế quan trọng trong việc thực thi mô hình OOP trong JavaScript. Là cơ chế mà các object trong javascript kế thừa các tính năng từ một object khác."
keywords: [
"FPrototype của hàm trong JavaScript",
"f prototype trong javascript",
"fprototype trong javascript la gi",
"fprototype javascript",
"prototype nghia la gi trong javascript",
"vi du ve prototype trogn javascript",
"cách sử dụng prototype trong javascript",
"prototype trong javascript dung de lam gi",
"prototype trong javascript va cach su dung",
"prototype design trong javascript"
]
chapter:
  name: "Prototype và thừa kế prototype"
  slug: "chuong-07-prototype-va-thua-ke-prototype"
category:
  name: "Javascript"
  slug: "javascript"
image: https://kungfutech.edu.vn/thumbnail.png
position: 2
---

Trong bài viết về [khởi tạo object với new trong JavaScript](/bai-viet/javascript/khoi-tao-doi-tuong-voi-tu-khoa-new-trong-javascript), bạn biết rằng một object có thể được tạo ra bằng cách sử dụng từ khóa `new` và hàm khởi tạo, ví dụ:

```js
let obj = new F();
```

Và đặc biệt, nếu `F.prototype` là một object thì toán tử `new` sẽ sử dụng thuộc tính đó để gán cho [`[[Prototype]]`](/bai-viet/javascript/prototype-trong-javascript) của đối tượng mới.

> **Chú ý:** với `F.prototype` thì `prototype` chính là **tên của một thuộc tính** trong `F`.

Ví dụ về `F.prototype` như sau:

```js
let animal = {
  eats: true,
};

function Rabbit(name) {
  this.name = name;
}

Rabbit.prototype = animal;

let rabbit = new Rabbit("White Rabbit"); //  rabbit.__proto__ == animal

console.log(rabbit.eats); // true
```

Trong ví dụ trên, câu lệnh `Rabbit.prototype = animal` gán giá trị `animal` cho thuộc tính `prototype` trong hàm khởi tạo `Rabbit`.

Điều này có ý nghĩa là: mỗi một đối tượng mới được tạo ra bởi `new Rabbit` thì đối tượng `animal` sẽ được gán cho `[[Prototype]]` của object.

## Đặc điểm của `F.prototype`

`F.prototype` chỉ được sử dụng **tại thời điểm** gọi `new F()`. Khi đó, giá trị `prototype` của hàm `F` sẽ được gán cho `[[Prototype]]` của object mới.

Nếu `F.prototype` bị thay đổi giá trị thì **đối tượng được tạo trước đó** vẫn giữ nguyên giá trị `[[Prototype]]` cũ, ví dụ:

```js
let animal = {
  eats: true,
};

function Rabbit(name) {
  this.name = name;
}

Rabbit.prototype = animal;

let rabbit = new Rabbit("White Rabbit"); //  rabbit.__proto__ == animal
console.log(rabbit.eats); // true

// Thay đổi giá trị của Rabbit.prototypeRabbit.prototype = {  legs: 4,};// prototype của đối tượng rabbit vẫn không đổiconsole.log(rabbit.eats); // trueconsole.log(rabbit.legs); // undefined
```

## Giá trị mặc định của prototype trong hàm

Mỗi hàm trong JavaScript đều có thuộc tính `prototype` kể cả khi bạn không định nghĩa.

Và giá trị mặc định của `prototype` là một object với **một thuộc tính duy nhất** `constructor` trỏ về chính **hàm** đó, ví dụ:

```js
function Rabbit() {}

/* prototype mặc định
    Rabbit.prototype = { constructor: Rabbit };
    */

console.log(Rabbit.prototype.constructor === Rabbit);
```

Vì giá trị của `Rabbit.prototype` sẽ được gán cho `[[Prototype]]` của mỗi object được tạo ra bởi việc gọi `new Rabbit()`, nên bạn có thể truy cập vào `constructor` từ mỗi đối tượng:

```js
function Rabbit() {}
// mặc định:
// Rabbit.prototype = { constructor: Rabbit }

let rabbit = new Rabbit(); // kế thừa prototype từ {constructor: Rabbit}

console.log(rabbit.constructor === Rabbit); // true
```

Và bạn có thể sử dụng giá trị `constructor` đó để khởi tạo đối tượng mới như sau:

```js
function Rabbit(name) {
  this.name = name;
}

let rabbit = new Rabbit("White Rabbit");
console.log(rabbit.name);

let rabbit2 = new rabbit.constructor("Black Rabbit");
console.log(rabbit2.name);
```

Tính năng này đặc biệt hữu ích khi bạn **không biết hàm khởi tạo** của một object (ví dụ đối tượng được tạo ra từ thư viện bên thứ 3).

<content-warning>

**Chú ý:** JavaScript không đảm bảo giá trị chính xác cho `constructor`. Thực chất, `constructor` là thuộc tính mặc định của mỗi hàm. Nhưng giá trị của `constructor` thì hoàn toàn có thể thay đổi được.

</content-warning>

Ví dụ thay đổi giá trị của `prototype`:

```js
function Rabbit() {}
Rabbit.prototype = {
  jumps: true,
};

let rabbit = new Rabbit();
console.log(rabbit.constructor === Rabbit); // false
```

Trong ví dụ trên, giá trị của `prototype` được gán bằng một object hoàn toàn mới và không chứa thuộc tính `constructor` nữa.

Để giữa lại giá trị mặc định của `constructor`, bạn chỉ cần **thêm/bớt** thuộc tính, thay vì gán object mới hoàn toàn cho `prototype` như sau:

```js
function Rabbit() {}

// thay vì ghi đè giá trị của prototype, bạn chỉ thêm thuộc tính mới
Rabbit.prototype.jumps = true;

// giá trị mặc định của Rabbit.prototype.constructor không đổi
console.log(Rabbit.prototype.constructor === Rabbit);
```

Hoặc chủ động gán lại giá trị cho thuộc tính `constructor`:

```js
Rabbit.prototype = {
  jumps: true,
  constructor: Rabbit,
};

// prototype được gán bằng object mới,
// nhưng constructor được tạo lại như mặc định
```

## Tổng kết

Sau đây là những kiến thức cơ bản cần nhớ về prototype của hàm trong JavaScript `F.prototype`:

- Thuộc tính `F.prototype` là một thuộc tính mặc định của mỗi hàm trong JavaScript dùng để gán giá trị cho `[[Prototype]]` trong mỗi object tạo ra từ cách gọi `new F()`.
- Giá trị của `F.prototype` chỉ có thể là một object hoặc `null`, các giá trị khác bị bỏ qua.
- Thuộc tính `prototype` chỉ được dùng tại thời điểm gọi `new F()`.

Trong đối tượng thông thường,`prototype` chỉ đơn giản là một thuộc tính mà không có ý nghĩa gì đặc biệt:

```js
let user = {
  name: "Alex",
  prototype: "abc",
};
```

Mặc định, mỗi hàm đều có `F.prototype = { constructor: F }`. Vì vậy, bạn có thể truy cập đến hàm khởi tạo của mỗi object thông qua giá trị của thuộc tính `constructor`.

Tham khảo: [F.prototype](https://javascript.info/function-prototype)
