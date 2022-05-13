---
title: "Prototype trong JavaScript"
description: "Prototype là khái niệm cốt lõi trong JavaScript và là cơ chế quan trọng trong việc thực thi mô hình OOP trong JavaScript."
keywords: [
"prototype trong javascript",
"prototype trong javascript la gi",
"prototype trong javascript dung de lam gi",
"cach su dung prototype trong javascript",
"prototype va oop trong javascript",
"object prototype trong javascript",
"object prototype trong javascript la gi",
"khi nao can dung prototype trong javascript",
"prototype trong javascript là gì",
"cách sử dụng prototype trong javascript",
"tìm hiểu prototype trong javascript"
]
chapter:
  name: "Prototype và thừa kế prototype"
  slug: "chuong-07-prototype-va-thua-ke-prototype"
category:
  name: "Javascript"
  slug: "javascript"
image: https://user-images.githubusercontent.com/29374426/168246011-4f728c59-d02c-47df-9c65-50ea792567d8.png
position: 1
---

![Prototype trong JavaScript](https://user-images.githubusercontent.com/29374426/168246011-4f728c59-d02c-47df-9c65-50ea792567d8.png)

Khi lập trình, mọi người thường mong muốn có thể **tái sử dụng code và mở rộng thêm các tính năng**.

Ví dụ, bạn có một đối tượng `user` với các thuộc tính và phương thức. Sau đó, bạn muốn tạo đối tượng mới là `admin` và `guest` dựa trên đối tượng `user`, nhưng không phải **copy-paste** lại code mà chỉ sử dụng lại những thứ mà `user` có, rồi tạo thêm thuộc tính hoặc phương thức mới.

Để làm được điều đó, bạn có thể sử dụng **prototype trong JavaScript** để kế thừa lại object `user`. Vậy **prototype là gì** và cách sử dụng prototype như thế nào?

# Prototype trong JavaScript

JavaScript object có một thuộc tính đặc biệt là `[[Prototype]]` với giá trị có thể là `null` hoặc một **object**. Và object đó gọi là một **prototype**.

Khi bạn truy cập vào một thuộc tính từ object, nếu thuộc tính đó không tồn tại thì JavaScript sẽ **tự động tìm kiếm trong prototype**. Trong lập trình, điều này gọi là **kế thừa prototype**.

`[[Prototype]]` là một **thuộc tính ẩn**, nhưng có nhiều cách để **cài đặt thuộc tính này**. Và một trong những cách phổ biến nhất là sử dụng `__proto__` như sau:

```js
let animal = {
  eats: true,
};
let rabbit = {
  jumps: true,
};

rabbit.__proto__ = animal; // gán rabbit.[[Prototype]] = animal
```

Nếu bạn đọc một thuộc tính trong `rabbit` và thuộc tính đó không tồn tại thì JavaScript sẽ tìm kiếm trong `animal`.

```js
let animal = {
  eats: true,
};
let rabbit = {
  jumps: true,
};

rabbit.__proto__ = animal; // (*)
console.log(rabbit.eats); // true (**)console.log(rabbit.jumps); // true
```

Tại dòng `(*)`, đối tượng `animal` được gán làm prototype cho đối tượng `rabbit`.

Khi đọc thuộc tính `rabbit.eats` tại `(**)`, thuộc tính `eats` không tồn tại trong `rabbit` nên JavaScript tìm kiếm trong `animal`. Dẫn đến kết quả là `true` như trên.

Bạn có thể gọi `animal` là một prototype của `rabbit` hoặc `rabbit` kế thừa prototype từ `animal`.

Khi đó, nếu `animal` có nhiều **thuộc tính và phương thức hữu ích** thì chúng cũng truy cập được từ `rabbit`. Đó chính là lợi ích của kế thừa trong lập trình.

Ví dụ một phương thức trong `animal` có thể gọi từ `rabbit`:

```js
let animal = {
  eats: true,
  walk() {
    console.log("Animal walk");
  },
};

let rabbit = {
  jumps: true,
  __proto__: animal,
};

// phương thức walk() được lấy thông qua prototype
rabbit.walk(); // Animal walk
```

Ngoài ra, prototype có thể **kế thừa móc nối nhau** qua nhiều object như sau:

```js
let animal = {
  eats: true,
  walk() {
    console.log("Animal walk");
  },
};

let rabbit = {
  jumps: true,
  __proto__: animal,
};

let longEar = {
  earLength: 10,
  __proto__: rabbit,
};

// walk() được lấy thông qua các prototype móc nối nhau
longEar.walk(); // Animal walk
console.log(longEar.jumps); // true (lấy từ rabbit)
```

Trong ví dụ trên, `animal` là prototype của `rabbit` và `rabbit` là prototype của `longEar`.

Nếu bạn truy cập vào một thuộc tính hoặc phương thức trong `longEar` và chúng không tồn tại thì JavaScript sẽ tự động tìm kiếm ở `rabbit`, rồi đến `animal`.

# Giới hạn của prototype trong JavaScript

Prototype trong JavaScript có một số giới hạn là:

► **Không được phép kế thừa prototype vòng tròn.**

```js
let animal = {
  eats: true,
};
let rabbit = {
  jumps: true,
};

// gán animal là prototype của rabbitrabbit.__proto__ = animal;// gán rabbit là prototype của animalanimal.__proto__ = rabbit;
// Lỗi: Cyclic __proto__ value
```

► **Giá trị của `__proto__` có thể là `null` hoặc là một object, nhưng [các kiểu dữ liệu khác](/bai-viet/javascript/cac-kieu-du-lieu-trong-javascript) đều bị bỏ qua.**

```js
let rabbit = {
  jumps: true,
  __proto__: 1, // bị bỏ qua};
};
```

► **Prototype không hỗ trợ thay đổi giá trị thuộc tính.**

Prototype chỉ **hỗ trợ việc đọc dữ liệu**, còn việc **thay đổi giá trị của thuộc tính** hay **xóa thuộc tính** không được thực hiện trực tiếp prototype, ví dụ:

```js
let animal = {
  eats: true,
  walk() {
    console.log("Animal walk");
  }
};

let rabbit = {
  jumps: true,
  __proto__: animal, // gán animal là prototype của rabbit};

  // định nghĩa giá trị mới cho rabbit.walkrabbit.walk = function () {  console.log("Rabbit walk");};
  rabbit.walk(); // Rabbit walk - giá trị mớianimal.walk(); // Animal walk - giá trị cũ
}
```

Trong ví dụ trên, `rabbit` kế thừa prototype của `animal`. Nhưng khi bạn gán `rabbit.walk` bằng một hàm mới thì `animal.walk` vẫn không thay đổi.

<content-note>

thuộc tính `__proto__` không hoàn toàn giống như `[[Prototype]]` mà đây chỉ là một [`getter/setter`](/bai-viet/javascript/getter-va-setter-trong-javascript) cho `[[Prototype]]`.

</content-note>

Hiện tại, `__proto__` đã lỗi thời và bạn nên dùng các phương thức [`Object.getPrototypeOf`](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Object/getPrototypeOf) và [`Object.setPrototypeOf`](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Object/setPrototypeOf) để thay thế.

Tuy nhiên, để đơn giản thì mình vẫn dùng `__proto__` làm minh họa cho các ví dụ.

## Giá trị `this` khi kế thừa prototype

Giá trị [`this`](/bai-viet/javascript/phuong-thuc-trong-javascript) là một giá trị đặc biệt trong object.

Câu hỏi đặt ra là: **khi kế thừa prototype, giá trị của `this` bị ảnh hưởng như thế nào?**

Sau đây là một ví dụ:

```js
// đối tượng animal với các phương thức
let animal = {
  walk() {
    if (!this.isSleeping) {
      console.log(`I walk`);
    }
  },
  sleep() {
    this.isSleeping = true;
  },
};

// đối tượng rabbit kế thừa prototype của animal
let rabbit = {
  name: "White Rabbit",
  __proto__: animal,
};

// thay đổi giá trị rabbit.isSleeping
rabbit.sleep();

// kết quả
console.log(rabbit.isSleeping); // true
console.log(animal.isSleeping); // undefined
```

Trong ví dụ trên, đối tượng `rabbit` kế thừa prototype của `animal`. Khi gọi `rabbit.sleep()`, JavaScript tìm phương thức `sleep()` trong `rabbit` nhưng không có, nên tự động tìm kiếm ở `animal`.

Khi câu lệnh `this.isSleeping = true` xảy ra, **đối tượng đang gọi phương thức** `sleep()` là `rabbit` nên giá trị của `this` tham chiếu đến `rabbit`. Nghĩa là `rabbit.isSleeping` bằng `true`.

Còn đối với `animal`, do chưa gọi `animal.sleep()` nên thuộc tính `isSleeping` cũng chưa tồn tại trong `animal`. Dẫn đến kết quả là `animal.isSleeping` bằng `undefined`.

<content-warning>

💡 **Chú ý:** việc kế thừa prototype không ảnh hưởng tới `this`. Giá trị của `this` luôn được **xác định lúc chạy** và bằng đối tượng gọi phương thức - đối tượng đứng trước toán tử `.`.

</content-warning>

## Vòng lặp `for...in` khi kế thừa prototype

[Vòng lặp `for...in`](/bai-viet/javascript/vong-lap-trong-javascript) lặp qua tất cả các thuộc tính có trong object cũng như thuộc tính kế thừa qua prototype, ví dụ:

```js
let animal = {
  eats: true,
};

let rabbit = {
  jumps: true,
  __proto__: animal,
};

for (let prop in rabbit) console.log(prop);
// jumps
// eats
```

Nếu bạn chỉ muốn duyệt qua các thuộc tính trong object và **bỏ qua các thuộc tính kế thừa** thì có thể dùng một trong hai cách sau:

► **Sử dụng phương thức `Object.keys()`**

Phương thức [`Object.keys()`](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Object/keys) trả về mảng chứa tất cả các key của object, bỏ qua các thuộc tính kế thừa.

```js
let animal = {
  eats: true,
};

let rabbit = {
  jumps: true,
  __proto__: animal,
};

console.log(Object.keys(rabbit)); // ['jumps']
```

► **Sử dụng `obj.hasOwnProperty(key)` để kiểm tra**

Phương thức `obj.hasOwnProperty(key)` trả về `true` nếu `key` đúng là thuộc tính của `obj` (không phải qua kế thừa), ngược lại thì trả về `false`.

```js
let animal = {
  eats: true,
};

let rabbit = {
  jumps: true,
  __proto__: animal,
};

for (let prop in rabbit) {
  let isOwn = rabbit.hasOwnProperty(prop);
  if (isOwn) {
    console.log(`Our: ${prop}`); // Our: jumps
  } else {
    console.log(`Inherited: ${prop}`); // Inherited: eats
  }
}
```

Có thể bạn đang thắc là: **phương thức `hasOwnProperty` ở đâu ra?**

Thực tế, phương thức `hasOwnProperty` được kế thừa thông qua prototype của `Object`, cụ thể là `Object.prototype.hasOwnProperty`. Nói cách khác, mọi object đều có thể truy cập được đến phương thức `hasOwnProperty`.

**Nhưng tại sao phương thức `hasOwnProperty` lại không xuất hiện trong vòng lặp `for...in`?**

Bởi vì phương thức `hasOwnProperty` có cờ [`enumerable:false`](/bai-viet/javascript/writable-enumerable-configurable-cua-object), tức là không xuất hiện trong vòng lặp.

## Tổng kết

Sau đây là những kiến thức cơ bản cần nhớ về prototype trong JavaScript:

- Trong JavaScript, tất cả các object đều có thuộc tính ẩn `[[Prototype]]` với giá trị là `null` hoặc kiểu object.
- Bạn có thể sử dụng `obj.__proto__` như là một **getter/setter** để truy cập vào `[[Prototype]]`.
- Object ứng với `[[Prototype]]` được gọi là một prototype.
- Khi truy cập một thuộc tính hay phương thức trong object mà nó không tồn tại thì JavaScript sẽ tự động tìm kiếm trong prototype.
- Prototype chỉ hỗ trợ việc đọc, không hỗ trợ ghi/xóa thuộc tính trực tiếp trên prototype.
- Khi bạn gọi `obj.method()` và `method()` được lấy từ prototype, giá trị của `this` vẫn tham chiếu đến `obj` chứ không phải prototype.
- Vòng lặp `for...in` duyệt tất cả các thuộc tính trong object và thuộc tính của prototype thông qua kế thừa.

## Thực hành

### Bài 1

Cho đoạn code sau:

```js
let animal = {
  jumps: null,
};
let rabbit = {
  __proto__: animal,
  jumps: true,
};

console.log(rabbit.jumps); // ? (1)

delete rabbit.jumps;
console.log(rabbit.jumps); // ? (2)

delete animal.jumps;
console.log(rabbit.jumps); // ? (3)
```

Hỏi kết quả tại `(1)`, `(2)` và `(3)` là gì?

Xem đáp án

Kết quả:

- `(1)`: `true` vì trong `rabbit` có thuộc tính `jumps`.
- `(2)`: `null` vì sau khi `delete rabbit.jumps`, thuộc tính `jumps` không tồn tại trong `rabbit` nữa nên JavaScript tự động tìm kiếm `jumps` ở `animal`. Và kết quả là `null`.
- `(3)`: `undefined` vì tương tự như `(2)`, JavaScript tự động tìm kiếm `jumps` ở `animal`, nhưng sau khi `delete animal.jumps` thì kết quả là `undefined`.

### Bài 2

Cho các object sau:

```js
let head = {
  glasses: 1,
};

let table = {
  pen: 3,
};

let bed = {
  sheet: 1,
  pillow: 2,
};

let pockets = {
  money: 2000,
};
```

Sử dụng `__proto__` để gán prototype cho các object sao cho việc tìm kiếm thuộc tính luôn được thực hiện theo thứ tự: `pockets` -> `bed` -> `table` -> `head`.

Ví dụ `pockets.pen` có kết quả là `3` (tìm thấy ở `table`) và `bed.glasses` bằng `1` (tìm thấy ở `head`).

Xem đáp án

```js
let head = {
  glasses: 1,
};

let table = {
  pen: 3,
  __proto__: head,
};

let bed = {
  sheet: 1,
  pillow: 2,
  __proto__: table,
};

let pockets = {
  money: 2000,
  __proto__: bed,
};
```

### Bài 3

Ví dụ `rabbit` kế thừa từ `animal` như sau:

```js
let animal = {
  eat() {
    this.full = true;
  },
};

let rabbit = {
  __proto__: animal,
};

rabbit.eat();
```

Nếu gọi `rabbit.eat()` thì object nào nhận thuộc tính `full`?

Xem đáp án

Đáp án là `rabbit`.

Vì khi kế thừa prototype, giá trị của `this` vẫn tham chiếu đến đối tượng gọi phương thức, tức là `rabbit`.

Tham khảo: [Prototypal inheritance](https://javascript.info/prototype-inheritance)
