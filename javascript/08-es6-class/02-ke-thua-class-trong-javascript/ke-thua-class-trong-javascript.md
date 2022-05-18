---
title: "Kế thừa trong Javascript"
description: "Kế thừa là một khái niệm quan trọng trong lập trình hướng đối tượng. Một đối tượng kế thừa một đối tượng khác thì nó sẽ có thuộc tính và phương thức có sẵn của đối tượng mà nó kế thừa."
keywords: [
"thừa kế trong javascript",
"kế thừa trong javascript",
"super trong javascript",
"overriding trong js",
"extends trong javascript",
"ke thua trong javascript",
"Super() trong JavaScript",
"Ghi đè trong JavaScript",
"Kế thừa trong Javascript",
"Kế thừa trong Javascript là gì",
"Cách sử dụng kế thừa trong Javascript",
"extend javascript",
"extend javascript là gì"
]
chapter:
  name: "ES6 Class"
  slug: "chuong-08-es6-class"
category:
  name: "Javascript"
  slug: "javascript"
image: https://kungfutech.edu.vn/thumbnail.png
position: 2
---

Kế thừa class trong JavaScript là cách để **tạo ra một class** thông qua việc **sử dụng mà mở rộng class khác**. Nhờ đó, bạn có thể tạo thêm các tính năng mới mà vẫn giữ nguyên những tính năng hiện tại.

## Từ khóa `extend` khi kế thừa class

Giả sử mình có class `Animal` như sau:

```js
class Animal {
  constructor(name) {
    this.speed = 0;
    this.name = name;
  }
  run(speed) {
    this.speed = speed;
    console.log(`${this.name} runs with speed ${this.speed}.`);
  }
  stop() {
    this.speed = 0;
    console.log(`${this.name} stands still.`);
  }
}

let animal = new Animal("My animal");
```

Tiếp theo, mình muốn tạo thêm class khác là `Rabbit`. Mà `Rabbit` thực chất cũng là `Animal`, nên class `Rabbit` nên được kế thừa từ class `Animal` để có thể sử dụng các phương thức trong đó.

Nói cách khác, mỗi object tạo bởi `Rabbit` có thể làm được những thứ mà `Animal` có thể làm. Đó chính là **bản chất của kế thừa.**

Cú pháp để kế thừa class trong JavaScript là: `class Child extends Parent`. Do đó, class `Rabbit` có thể được viết như sau:

```js
class Rabbit extends Animal {
  hide() {
    console.log(`${this.name} hides!`);
  }
}

let rabbit = new Rabbit("White Rabbit");

rabbit.run(5); // White Rabbit runs with speed 5.
rabbit.hide(); // White Rabbit hides!
```

Bạn thấy rằng, object tạo bởi `Rabbit` có thể đồng thời sử dụng phương thức trong `Rabbit` là `rabbit.hide()` và phương thức trong `Animal` là `rabbit.run()`.

Về bản chất, từ khóa `extends` sử dụng cơ chế [kế thừa prototype](/bai-viet/javascript/native-prototype-trong-javascript) thông qua việc gán `Rabbit.prototype.[[Prototype]]` bằng `Animal.prototype`. Nghĩa là nếu một phương thức không được tìm thấy trong `Rabbit.animal` thì JavaScript sẽ tự động tìm kiếm trong `Animal.prototype`.

Ví dụ để tìm phương thức `rabbit.run`, JavaScript engine sẽ thực hiện tìm kiếm như sau:

1.  Tìm trong đối tượng `rabbit` - không có `run`.
2.  Tìm trong prototype của `rabbit`, đó là `Rabbit.prototype` - cũng không có `run`.
3.  Tìm trong prototype của `Rabbit.prototype`, đó là `Animal.prototype` - có phương thức `run`.

**Chú ý:** Đằng sau từ khóa `extends` không chỉ là class mà còn có thể là **một biểu thức**.

Ví dụ [một hàm trả về một class](/bai-viet/javascript/cu-phap-co-ban-cua-class-trong-javascript) như sau:

```js
function f(message) {
  return class {
    sayHi() {
      console.log(message);
    }
  };
}

class User extends f("Hello") {}
new User().sayHi(); // Hello
```

Trong ví dụ trên, class `User` kế thừa từ một class là kết quả của việc gọi hàm `f("Hello")`.

## Ghi đè phương thức

Khi kế thừa class trong JavaScript, tất cả các phương thức không được định nghĩa trong class con `Rabbit` sẽ được tìm và lấy ở class cha `Animal` để sử dụng.

Nhưng ở khía cạnh ngược lại, nếu mình **định nghĩa lại một phương thức** của class `Animal` trong class `Rabbit`, giả sử là phương thức `stop`. Khi đó, phương thức `stop` trong `Rabbit` sẽ được sử dụng:

```js
class Rabbit extends Animal {
  stop() {
    // phương thức này được sử dụng khi gọi `rabbit.stop()`
    // thay vì phương thức `stop` trong class Animal.
  }
}
```

Đó chính là **ghi đè thuộc tính** khi kế thừa class trong JavaScript.

Tuy nhiên, chúng ta thường **không muốn thay thế hoàn toàn phương thức cha** mà sẽ dựa trên đó và rồi thực hiện thêm một số tác vụ. Nghĩa là mình sẽ làm một thứ gì đó, nhưng vẫn gọi đến phương thức cha **trước hoặc sau công việc kia**.

Để giải quyết vấn đề này, class cung cấp từ khóa `super` với cách sử dụng như sau:

- `super.method()`: gọi đến phương thức cha.
- `super(...)`: gọi đến hàm khởi tạo của class cha (chỉ sử dụng trong hàm khởi tạo).

Ví dụ, class `Rabbit` kế thừa class `Animal` và ghi đè phương thức `stop`:

```js
class Animal {
  constructor(name) {
    this.speed = 0;
    this.name = name;
  }

  run(speed) {
    this.speed = speed;
    console.log(`${this.name} runs with speed ${this.speed}.`);
  }

  stop() {
    this.speed = 0;
    console.log(`${this.name} stands still.`);
  }
}

class Rabbit extends Animal {
  hide() {
    console.log(`${this.name} hides!`);
  }

  stop() {
    super.stop(); // gọi đến phương thức stop của Animal    this.hide(); // và rồi gọi phương thức hide của chính nó.  }}

    let rabbit = new Rabbit("White Rabbit");

    rabbit.run(5);
    // White Rabbit runs with speed 5.

    rabbit.stop();
    // White Rabbit stands still.
    // White Rabbit hides!
  }
}
```

Trong ví dụ trên, `Rabbit` đã có phương thức `stop` riêng. Và phương thức này gọi đến phương thức `stop` của class cha `Animal` là `super.stop()`.

**Chú ý:** [arrow function](/bai-viet/javascript/arrow-function-trong-javascript) không có `super`. Dó đó, `super` sẽ được tham chiếu đến hàm bên ngoài, ví dụ:

```js
class Rabbit extends Animal {
  stop() {
    setTimeout(() => {
      super.stop(); // gọi đến hàm stop của class Animal sau 1000ms
    }, 1000);
  }
}
```

Ở ví dụ trên, `super` trong arrow function là **hoàn toàn tương đương** với `super` trong hàm `stop`. Vì vậy, kết quả thực hiện hoàn toàn chính xác như mong muốn.

Tuy nhiên, nếu thay arrow function bằng hàm thông thường thì kết quả sẽ khác:

```js
setTimeout(function () {
  super.stop(); // kết quả không như mong muốn
}, 1000);
```

## Ghi đè hàm khởi tạo

Khi kế thừa class trong JavaScript, việc **ghi đè hàm khởi tạo phức tạp hơn** so với việc ghi đè phương thức thông thường.

Trong các ví dụ trên, class `Rabbit` chưa có hàm khởi tạo. Do đó, JavaScript engine sẽ tự động tạo một **hàm khởi tạo trống** như sau:

    class Rabbit extends Animal {
      constructor(...args) {    super(...args);  }}

Hàm khởi tạo của `Rabbit` không thực hiện thêm gì ngoài việc gọi hàm khởi tạo của class cha `Animal` thông qua câu lệnh `super(...args)`.

Bây giờ, mình sẽ thay đổi hàm khởi tạo của `Rabbit`, bằng cách truyền thêm tham số `earLength` bên cạnh `name` như sau:

```js
class Animal {
  constructor(name) {
    this.speed = 0;
    this.name = name;
  }
  // ...
}

class Rabbit extends Animal {
  constructor(name, earLength) {
    this.speed = 0;
    this.name = name;
    this.earLength = earLength;
  } // ...
}

// Sử dụng
let rabbit = new Rabbit("White Rabbit", 10);
// Lỗi:
// Uncaught ReferenceError: Must call super constructor in derived class
// before accessing 'this' or returning from derived
```

Với cách làm trên thì đã có lỗi xảy ra. Và lỗi này được hiểu là: Phải gọi hàm khởi tạo của class cha trước khi truy cập vào `this` hoặc kết thúc hàm khởi tạo.

Vì vậy, mình sẽ sửa lại đoạn code trên như sau:

```js
class Animal {
  constructor(name) {
    this.speed = 0;
    this.name = name;
  }
  // ...
}

class Rabbit extends Animal {
  constructor(name, earLength) {
    super(name);
    this.earLength = earLength;
  }
  // ...
}

// Sử dụng:let rabbit = new Rabbit("White Rabbit", 10);console.log(rabbit.name); // White Rabbitconsole.log(rabbit.earLength); // 10
```

## Tổng kết

---

Những kiến thức cơ bản cần nhớ về kế thừa class trong JavaScript là:

1. Cú pháp kế thừa class trong JavaScript: `class Child extends Parent`.

- Bản chất câu lệnh trên thực hiện gán `Child.prototype.__proto__` bằng `Parent.prototype`.
- Khi một phương thức không được tìm thấy trong class `Child` thì JavaScript sẽ tự động tìm kiếm trong class `Parent`.

2. Khi ghi đè hàm khởi tạo:

- Phải gọi đến hàm khởi tạo của class cha thông qua `super()` trước khi sử dụng `this`.

3. Khi ghi đè các phương thức khác:

- Bạn có thể sử dụng `super.method()` trong class `Child` để gọi đến phương thức `method` trong class `Parent`.

**Chú ý:** arrow function không có `this` cũng như `super`. Vì vậy, chúng sẽ được tham chiếu đến hàm bên ngoài.

Tham khảo: [Class inheritance](https://javascript.info/class-inheritance)
