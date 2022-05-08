---
title: "Getter và setter trong JavaScript"
description: "Getters và Setters là các hàm hoặc phương thức được sử dụng để lấy và đặt các giá trị của các biến. Khái niệm getters và setters rất phổ biến trong lập trình."
keywords: [
"Getter và setter trong JavaScript",
"Getter và setter trong JavaScript dùng để làm gì",
"getter setter javascript",
"Hàm Set trong JavaScript",
"Hàm Get trong JavaScript",
"Getter và setter là gì trong javascript",
"Getter và setter cách sử dụng",
"khai báo getter và setter",
"getter trong javascript",
"setter trong javascript"
]
chapter:
  name: "Cấu hình thuộc tính object"
  slug: "chuong-06-cau-hinh-thuoc-tinh-object"
category:
  name: "Javascript"
  slug: "javascript"
image: https://kungfutech.edu.vn/thumbnail.png
position: 2
---

Ngoài thuộc tính và phương thức thông thường, object còn có **getter và setter**. Getter trong JavaScript và setter trong JavaScript **thực chất là các phương thức**. Tuy nhiên, cách sử dụng của chúng lại **giống như thuộc tính**.

Sau đây mình sẽ cùng tìm hiểu về định nghĩa và cách sử dụng của getter, setter trong JavaScript.

## Định nghĩa getter và setter

Để định nghĩa getter trong JavaScript, bạn sử dụng từ khóa `get`. Và để định nghĩa setter trong JavaScript thì bạn dùng từ khóa `set`, ví dụ:

```js
let obj = {
  // getter
  get propName() {
    // code trả về obj.propName
  },

  // setter
  set propName(value) {
    // code gán giá trị value cho obj.propName
  },
};
```

Hàm getter `obj.propName()` được dùng để **đọc giá trị** của thuộc tính. Và hàm setter `obj.propName(value)` dùng để **gán giá trị** cho thuộc tính.

Ví dụ tiếp theo, giả sử đối tượng `user` có hai thuộc tính là `name` và `surname`:

```js
let user = {
  name: "David",
  surname: "Walsh",
};
```

Và bạn cần thêm thuộc tính `fullName` với giá trị là `"David Walsh"`.

Nếu bạn không muốn **copy-paste** lại giá trị `name` và `surname` trên thì có thể viết hàm getter như sau:

```js
let user = {
  name: "David",
  surname: "Walsh",
  get fullName() {
    return `${this.name} ${this.surname}`;
  },
};

console.log(user.fullName); // David Walsh
```

Rõ ràng, `fullName` được viết như một phương thức, nhưng cách sử dụng `user.fullName` thì lại giống việc **truy cập giá trị** của thuộc tính trong object.

Trong ví dụ trên, `fullName` đang chỉ là hàm **getter**. Do đó, nếu bạn gán giá trị cho `fullName` thì sẽ có lỗi:

```js
"use strict";
let user = {
  name: "David",
  surname: "Walsh",
  get fullName() {
    return `${this.name} ${this.surname}`;
  },
};

user.fullName = "Lam Pham"; // Cannot set property fullName of #<Object> which has only a getter
```

<content-warning>

lỗi trên chỉ được in ra khi chạy code ở [strict mode](/bai-viet/javascript/strict-mode-trong-javascript).

</content-warning>

Để tránh lỗi trên, bạn cần viết thêm hàm **setter** cho `fullName` như sau:

```js
"use strict";

let user = {
  name: "David",
  surname: "Walsh",
  get fullName() {
    return `${this.name} ${this.surname}`;
  },
  set fullName(value) {
    [this.name, this.surname] = value.split(" ");
  },
};

user.fullName = "Lam Pham";
console.log(user.fullName);
```

Với cách triển khai như trên, đối tượng `user` đã có thêm một **thuộc tính ảo** là `fullName`.

## Đối tượng mô tả thuộc tính cho getter và setter

Mỗi thuộc tính của object trong JavaScript đều có một **đối tượng mô tả thuộc tính**, bao gồm giá trị `value` và các cờ là [writable/enumerable/configurable](/bai-viet/javascript/writable-enumerable-configurable-cua-object).

Nhưng với getter trong JavaScript và setter trong JavaScript thì khác.

Đối tượng mô tả thuộc tính cho getter và setter không có giá trị `value` và cờ `writable`, thay vào đó là hai phương thức `get` và `set`, cụ thể là:

- `get`: hàm không có tham số, được dùng khi **đọc giá trị** của thuộc tính.
- `set`: hàm có một tham số, được dùng để **gán giá trị** cho thuộc tính.
- `enumerable`: giống như thuộc tính thông thường.
- `configurable`: giống như thuộc tính thông thường.

Ví dụ tạo getter và setter cho `user.fullName` với phương thức `defineProperty` như sau:

```js
let user = {
  name: "David",
  surname: "Walsh",
};

Object.defineProperty(user, "fullName", {
  get() {
    return `${this.name} ${this.surname}`;
  },
  set(value) {
    [this.name, this.surname] = value.split(" ");
  },
});
console.log(user.fullName); // David Walsh

for (let key in user) console.log(key); // name, surname
```

**Chú ý:** một thuộc tính trong object có thể là **getter/setter** hoặc là **thuộc tính bình thường**, nhưng không được phép tồn tại cả hai.

Nói cách khác, nếu bạn định nghĩa cả hàm `get/set` và thuộc tính `value` trong cùng một **đối tượng mô tả thuộc tính** thì sẽ có lỗi:

```js
Object.defineProperty({}, "prop", {
  get() {
    return 0;
  },
  value: 5,
});

// Lỗi:
// Invalid property descriptor.
// Cannot both specify accessors and a value or writable attribute, #<Object>
```

## Ứng dụng của getter và setter

Getter trong JavaScript và setter trong JavaScript có thể dùng làm "wrapper" cho thuộc tính.

Ví dụ, bạn muốn chặn việc **gán giá trị quá ngắn** cho tên của `user`. Bạn có thể viết hàm setter `user.name` và lưu giá trị thật vào thuộc tính `user._name`.

```js
let user = {
  get name() {
    return this._name;
  },

  set name(value) {
    if (value.length < 4) {
      console.log("Tên quá ngắn, tối thiểu là 4 chữ cái.");
      return;
    }
    this._name = value;
  },
};

user.name = "Alex";
console.log(user.name); // Alex
user.name = ""; // Tên quá ngắn, tối thiểu là 4 chữ cái.
```

Trong ví dụ trên, tên của `user` được **lưu thật sự** trong thuộc tính `user._name`, còn việc truy cập vào tên thì **thông qua getter và setter** `user.name`.

Thực tế, bạn có thể **truy cập trực tiếp** vào thuộc tính `user._name`. Tuy nhiên, cách viết thuộc tính **bắt đầu bằng dấu gạch dưới** là một quy ước ngầm rằng, thuộc tính `user._name` là **private** và không nên truy cập trực tiếp từ bên ngoài.

## Sử dụng getter và setter giúp tương thích ngược

Lợi ích lớn nhất của việc dùng getter và setter trong JavaScript là cách sử dụng giống như thuộc tính thông thường. Nghĩa là bạn có thể **biến thuộc tính thông thường thành getter/setter** bất kỳ lúc nào.

Ví dụ bạn có đối tượng `user` với hai thuộc tính là `name` và `age`:

```js
function User(name, age) {
  this.name = name;
  this.age = age;
}

let alex = new User("Alex", 28);
console.log(alex.age); // 28
```

Nhưng sau đó, bạn quyết định thay đổi. Và bạn muốn lưu thông tin `birthday` thay vì `age`:

```js
function User(name, birthday) {
  this.name = name;
  this.birthday = birthday;
}

let alex = new User("Alex", new Date(1993, 6, 6));
```

**Chuyện gì sẽ xảy ra với những code cũ - đang sử dụng thuộc tính `age`?**

Bạn có thể **tìm tất cả** những chỗ có sử dụng `user.age` để sửa lại cho đúng. Tuy nhiên, nếu code của bạn được sử dụng bởi nhiều người và ở nhiều nơi khác nhau thì cách làm trên là **bất khả thi**.

Cách đơn giản để giải quyết vấn đề trên là biến thuộc tính `age` thành **getter/setter** như sau:

```js
function User(name, birthday) {
  this.name = name;
  this.birthday = birthday;

  // tính toán age dựa trên birthday và năm hiện tại  Object.defineProperty(this, "age", {    get() {      let todayYear = new Date().getFullYear();      return todayYear - this.birthday.getFullYear();    },  });}
  let alex = new User("Alex", new Date(1993, 6, 6));
  console.log(alex.birthday); // Tue Jul 06 1993 00:00:00 GMT+0700 (Indochina Time)
  console.log(alex.age); // 29
}
```

Với cách làm trên, code cũ đảm bảo là vẫn chạy như bình thường.

Tham khảo: [Property getters and setters](https://javascript.info/property-accessors).
