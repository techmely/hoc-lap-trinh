---
title: "Thuộc tính và phương thức static của class trong Javascript"
description: "Static là một từ khóa giúp ta khai báo những phương thức tĩnh hoặc thuộc tính tĩnh trong các class của javascript. Khi được khai báo static thì phương thức / thuộc tính đó có thể được gọi đến mà không cần phải sử dụng từ khóa new để khởi tạo đối tượng."
keywords: [
"Thuộc tính và phương thức static của class trong Javascript",
"class trong Javascript",
"phương thức static của class trong Javascript",
"phương thức static của class trong Javascript là gì",
"phương thức static của class trong Javascript dùng làm gì",
"static trong Javascript",
"static trong Javascript là gì",
"static trong Javascript dùng làm gì",
"cách sử dụng static trong Javascript",
"ví dụ về static trong Javascript"
]
chapter:
  name: "ES6 Class"
  slug: "chuong-08-es6-class"
category:
  name: "Javascript"
  slug: "javascript"
image: https://kungfutech.edu.vn/thumbnail.png
position: 3
---

Bạn có thể gán một phương thức trực tiếp cho class mà không phải `prototype`. Phương thức khi đó được gọi là **static**.

## Phương thức static

Đối với class trong JavaScript, bạn chỉ cần thêm từ khóa `static` trước phương thức như sau:

```js
class User {
  static staticMethod() {
    console.log(this === User);
  }
}

User.staticMethod(); // true
```

Cách này hoàn toàn tương tự việc định nghĩa thuộc tính trực tiếp trong class:

```js
class User {}

User.staticMethod = function () {
  console.log(this === User);
};

User.staticMethod(); // true
```

Giá trị của `this` trong `User.staticMethod()` chính là **hàm khởi tạo** của class `User`.

Thông thường, phương thức static được sử dụng để triển khai các **hàm thuộc về class** nói chung mà không phải ở bất kỳ một object nào.

Ví dụ, bạn có các đối tượng `Article` và cần một hàm để **so sánh chúng**. Và bạn có thể định nghĩa một phương thức static `Article.compare` như sau:

```js
class Article {
  constructor(title, date) {
    this.title = title;
    this.date = date;
  }

  static compare(articleA, articleB) {
    return articleA.date - articleB.date;
  }
}

// sử dụng
let articles = [
  new Article("HTML", new Date(2019, 1, 1)),
  new Article("CSS", new Date(2019, 0, 1)),
  new Article("JavaScript", new Date(2019, 11, 1)),
];

articles.sort(Article.compare);
console.log(articles[0].title); // CSS
```

Trong ví dụ trên, `Article.compare` không thuộc bất kỳ một đối tượng article nào cả, mà thuộc về class `Article`.

Còn một ví dụ khác mà mọi người hay gọi là **phương thức factory** hay **factory pattern**. Tưởng tượng, bạn cần một vài cách để khởi tạo đối tượng article như:

- Tạo article bởi các tham số truyền vào (`title` và `date`).
- Tạo một article trống với `date` là **ngày hôm nay**.
- ... hoặc một cách nào khác.

Cách đầu tiên có thể triển khai thông qua hàm khởi tạo. Với cách thứ hai, bạn có thể viết một phương thức static của class `Article`.

Ví dụ phương thức `Artice.createTodays()`:

```js
class Article {
  constructor(title, date) {
    this.title = title;
    this.date = date;
  }

  static createTodays() {
    // Chú ý: this = Article    return new this("Today's digest", new Date());  }}

    let article = Article.createTodays();
    console.log(article.title); // Today's digest
  }
}
```

Mỗi khi cần tạo một article cho **ngày hôm nay**, bạn có thể gọi `Article.createTodays()`.

Ngoài ra, phương thức static còn được dùng trong các class liên quan đến **database** để thực hiện các thao tác như **tìm kiếm, lưu, xóa dự liệu** trong database, ví dụ:

```js
// Xóa một article với id = 12345 trong database ứng với Article
Article.remove({ id: 12345 });
```

## Thuộc tính static

---

Bạn cũng có thể định nghĩa thuộc tính static trong class như sau:

```js
class Article {
  static publisher = "Lam P.";
}

console.log(Article.publisher); // Lam P.
```

Cách trên hoàn toàn giống với cách gán trực tiếp thuộc tính cho class:

```js
Article.publisher = "Lam P.";
```

## Kế thừa thuộc tính và phương thức static

---

Thuộc tính và phương thức static của class trong JavaScript **đều có thể [kế thừa](/bai-viet/javascript/ke-thua-class-trong-javascript)**.

Ví dụ, `Animal.compare` và `Animal.planet` ở đoạn code sau được kế thừa, sử dụng như là `Rabbit.compare` hay `Rabbit.planet`:

```js
class Animal {
  static planet = "Earth";
  constructor(name, speed) {
    this.speed = speed;
    this.name = name;
  }

  run(speed = 0) {
    this.speed += speed;
    console.log(`${this.name} runs with speed ${this.speed}.`);
  }

  static compare(animalA, animalB) {
    return animalA.speed - animalB.speed;
  }
}

// Kế thừa từ Animal
class Rabbit extends Animal {
  hide() {
    console.log(`${this.name} hides!`);
  }
}

let rabbits = [new Rabbit("White Rabbit", 10), new Rabbit("Black Rabbit", 5)];

rabbits.sort(Rabbit.compare);
rabbits[0].run(); // Black Rabbit runs with speed 5.

console.log(Rabbit.planet); // Earth
```

Trong ví dụ trên, khi gọi `Rabbit.compare` thì hàm được kế thừa là `Animal.compare` sẽ được gọi.

Nguyên nhân là khi kế thừa với class, `Rabbit extends Animal` thực sự tạo ra **hai tham chiếu** của `[[Prototype]]` như sau:

- Các hàm trong `Rabbit` kế thừa các hàm từ `Animal`.
- Các hàm trong `Rabbit.prototype` kế thừa các hàm từ `Animal.prototype`.

Bạn có thể xem ví dụ sau để thấy rõ điều đó:

```js
class Animal {}
class Rabbit extends Animal {}

// phương thức static
console.log(Rabbit.__proto__ === Animal); // true

// phương thức thông thường
console.log(Rabbit.prototype.__proto__ === Animal.prototype); // true
```

## Tổng kết

---

Các phương thức static trong class thuộc về chính class đó mà không phải ở bất kỳ một đối tượng nào.

Ví dụ phương thức so sánh `Article.compare(article1, article2)` hay phương thức khởi tạo **factory** như `Article.createTodays()`.

Các phương thức static được định nghĩa trong class bằng cách sử dụng từ khóa `static` đằng trước.

Các thuộc tính static cũng tương tự như phương thức static, chúng tồn tại trong chính class.

Cú pháp cơ bản để định nghĩa thuộc tính và phương thức static trong class là:

```js
class MyClass {
  static property = ...;
  static method() {
    ...
  }
}
```

Về cơ bản, cách định nghĩa thuộc tính static và phương thức static trong class giống với cách gán trực tiếp cho class như sau:

```js
MyClass.property = ...
MyClass.method = ...
```

Thuộc tính hay phương thức static đều có thể **kế thừa**.

Ví dụ khi `class B extends A`, prototype của `B` được gán bằng `A` như sau: `B.[[Prototype]] = A`. Do đó, nếu một phương thức hay thuộc tính static không được tìm thấy ở `B` thì JavaScript sẽ tìm kiếm trong `A`.

Tham khảo: [Static properties and methods](https://javascript.info/static-properties-methods)
