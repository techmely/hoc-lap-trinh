---
title: "Thuộc tính writable, enumerable và configurable của object trong Javascript"
description: "Writable, enumerable và configurable là những cờ quan trọng để cấu hình cho thuộc tính trong Javascript."
keywords: [
"Thuộc tính writable, enumerable và configurable của object trong Javascript",
"writable trong Javascript",
"enumerable trong Javascript",
"configurable trong Javascript",
"Thuộc tính trong Javascript",
"object defineproperty trong Javascript la gi",
"them thuoc tinh vao object trong Javascript",
"writable là gì",
"enumerable là gì",
"configurable là gì"
]
chapter:
  name: "Cấu hình thuộc tính object"
  slug: "chuong-06-cau-hinh-thuoc-tinh-object"
category:
  name: "Javascript"
  slug: "javascript"
image: https://kungfutech.edu.vn/thumbnail.png
position: 1
---

Trong các bài viết trước, bạn mới chỉ biết [thuộc tính của object](/bai-viet/javascript/object-la-gi-object-trong-javascript) trong JavaScript có dạng **key-value**. Thực tế thì thuộc tính trong object có nhiều tính chất khác nữa. Trong đó, **writable, enumerable và configurable** là những cờ quan trọng để cấu hình cho thuộc tính.

## Các cờ cho thuộc tính

Writable, enumerable và configurable là **ba cờ đặc biệt trong object**, trong đó:

- `writable`: nếu là `true` thì giá trị `value` của thuộc tính **có thể thay đổi**. Ngược lại, thuộc tính gọi là **read-only** (thuộc tính chỉ đọc).
- `enumerable`: nếu là `true` thì thuộc tính xuất hiện trong **[vòng lặp](/bai-viet/javascript/vong-lap-trong-javascript)**, ngược lại thì không.
- `configurable`: nếu là `true` thì **thuộc tính có thể xóa** và **các cờ khác có thể thay đổi**, ngược lại thì không.

Khi bạn **khởi tạo đối tượng theo cách thông thường** thì các cờ này **không xuất hiện** và có giá trị mặc định là `true`.

Để lấy thông tin của các cờ này, bạn có thể dùng phương thức [`Object.getOwnPropertyDescriptor`](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Object/getOwnPropertyDescriptor) với cú pháp cơ bản là:

```js
let descriptor = Object.getOwnPropertyDescriptor(obj, propertyName);
```

Trong đó:

- `obj`: là object để lấy thông tin.
- `propertyName`: tên của thuộc tính trong object cần lấy thông tin.

Giá trị trả về của phương thức trên gọi là object **property descriptor** (tạm hiểu là "đối tượng mô tả thuộc tính") - chứa thông tin về `value` và các cờ `writable`, `enumerable`, `configurable`, ví dụ:

```js
let user = {
  name: "Alex",
};

let descriptor = Object.getOwnPropertyDescriptor(user, "name");

console.log(JSON.stringify(descriptor, null, 2));

/*
    {
      "value": "Alex",
      "writable": true,
      "enumerable": true,
      "configurable": true
    }
    */
```

Để thay đổi giá trị của các cờ `writable`, `enumerable`, `configurable`, bạn có thể sử dụng phương thức [`Object.defineProperty`](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Object/defineProperty) với cú pháp:

```js
Object.defineProperty(obj, propertyName, descriptor);
```

Trong đó:

- `obj`: là đối tượng cần thay đổi.
- `propertyName`: tên của thuộc tính trong object cần thay đổi.
- `descriptor`: object chứa thông tin "descriptor" mới để thay đổi.

Nếu thuộc tính `propertyName` tồn tại thì phương thức trên sẽ **cập nhật giá trị** của các cờ theo `descriptor`, ngược lại thì tạo thuộc tính mới. Trong trường hợp một cờ nào đó không được cung cấp thì **giá trị mặc định** của cờ là `false`.

Ví dụ sau tạo thuộc tính `name` với các cờ `writable`, `enumerable`, `configurable` đều là `false`:

```js
let user = {};

Object.defineProperty(user, "name", {
  value: "Alex",
});

let descriptor = Object.getOwnPropertyDescriptor(user, "name");

console.log(JSON.stringify(descriptor, null, 2));
/*
    {
      "value": "Alex",
      "writable": false,
      "enumerable": false,
      "configurable": false
    }
     */
```

<content-warning>

Đối với cách tạo object thông thường thì các cờ `writable`, `enumerable`, `configurable` có giá trị mặc định là `true`.

</content-warning>

Trên đây là kiến thức chung về các cờ. Tiếp theo mình sẽ xem xét ý nghĩa của từng cờ.

## Thuộc tính chỉ đọc non-writable

Giả sử, mình muốn tạo thuộc tính `user.name` là thuộc tính chỉ đọc - **non-writable** hay **read-only** bằng cách set `writable=false` như sau:

```js
"use strict";

let user = {
  name: "Alex",
};

Object.defineProperty(user, "name", { writable: false });
user.name = "Anna";
// Error: Cannot assign to read only property 'name' of object '#<Object>'
```

Rõ ràng là mình không thể thay đổi giá trị của thuộc tính `name` khi `writable=false`.

<content-warning>

Lỗi trên chỉ được in ra khi sử dụng code ở [strict mode](/bai-viet/javascript/strict-mode-trong-javascript).

Đối với chế độ thông thường thì sẽ không có dòng lỗi trên, dù cho việc thay đổi giá trị của thuộc tính `name` vẫn không được phép.

</content-warning>

Tiếp theo là ví dụ tạo thuộc tính bằng phương thức `defineProperty`:

```js
"use strict";

let user = {};

Object.defineProperty(user, "name", {
  value: "Alex",
  enumerable: true,
  configurable: true,
});
console.log(user.name); // Alex
user.name = "Anna"; // Error
```

Trong ví dụ trên, cờ `writable` không được khai báo thì giá trị mặc định của cờ này là `false`. Do đó, thuộc tính `user.name` cũng là **non-writable**.

## Thuộc tính non-enumerable

Giả sử, mình thêm phương thức `toString` cho đối tượng `user` trên. Mặc định thì `toString` sẽ xuất hiện trong vòng lặp `for...in` như sau:

```js
let user = {
  name: "Alex",
  toString() {
    return this.name;
  },
};

for (let key in user) console.log(key); // name, toString
```

Nếu mình không muốn phương thức `toString` xuất hiện trong vòng lặp `for...in` thì có thể set `enumerable=false`:

```js
let user = {
  name: "Alex",
  toString() {
    return this.name;
  },
};
Object.defineProperty(user, "toString", { enumerable: false });
for (let key in user) console.log(key); // name
```

Bây giờ thì `toString` đã không xuất hiện trong vòng lặp `for...in`. Nói cách khác, `toString` trở thành thuộc tính **non-enumerable**.

Khi sử dụng phương thức [`Object.keys`](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Object/keys) để lấy **tất cả key** trong object, các thuộc tính **non-enumerable** cũng được bỏ qua:

```js
let user = {
  name: "Alex",
  toString() {
    return this.name;
  },
};

Object.defineProperty(user, "toString", {
  enumerable: false,
});

console.log(Object.keys(user)); // ['name']
```

## Thuộc tính non-configurable

Cờ **configurable** với `configurable=false` thường được set cho các thuộc tính của các **đối tượng sẵn có** trong JavaScript.

Khi đó, thuộc tính gọi là **non-configurable** - không thể xóa và các cờ khác không thể thay đổi.

Ví dụ `Math.PI` là **non-writable, non-enumerable and non-configurable**:

```js
let descriptor = Object.getOwnPropertyDescriptor(Math, "PI");

console.log(JSON.stringify(descriptor, null, 2));
/*
{
  "value": 3.141592653589793,
  "writable": false,
  "enumerable": false,
  "configurable": false
}
*/
```

Bạn không thể thay đổi giá trị của `PI`:

```js
Math.PI = 3; // => Lỗi, giá trị của PI không thể thay đổi
```

Và bạn cũng không thể thay đổi `PI` thành **writable**:

```js
Object.defineProperty(Math, "PI", { writable: true });
// Lỗi: Cannot redefine property: PI
```

Nghĩa là việc tạo ra thuộc tính **non-configurable** là "một chiều". Bạn không thể thay đổi các cờ bằng phương thức `defineProperty` được nữa.

> **Chú ý:** việc gán `configurable=false` chỉ **ngăn chặn** việc thay đổi giá trị của các cờ và việc xóa thuộc tính. Tuy nhiên, giá trị của thuộc tính vẫn có thể thay đổi.

```js
"use strict";

let user = {
  name: "Alex",
};

Object.defineProperty(user, "name", {
  configurable: false,
});

user.name = "Anna";
console.log(user.name); // Anna

delete user.name;
// Lỗi: Cannot delete property 'name' of #<Object>
```

Trong ví dụ trên, giá trị của `user.name` có thể thay đổi, nhưng không thể bị xóa. Để ngăn chặn việc thay đổi giá trị của `user.name` giống như `Math.PI`, bạn có thể gán thêm `writable=false`:

```js
"use strict";

let user = {
  name: "Alex",
};

Object.defineProperty(user, "name", {
  writable: false,
  configurable: false,
});

user.name = "Anna";
// Lỗi: Cannot assign to read only property 'name' of object '#<Object>'

delete user.name;
// Lỗi: Cannot delete property 'name' of #<Object>
```

## Phương thức Object.defineProperties

Phương thức `Object.defineProperty` bên trên chỉ định nghĩa một thuộc tính.

Để **định nghĩa nhiều thuộc tính cùng một lúc**, bạn có thể sử dụng phương thức `Object.defineProperties` với cú pháp là:

```js
Object.defineProperties(obj, {
  prop1: descriptor1,
  prop2: descriptor2,
  // ...
});
```

Ví dụ:

```js
Object.defineProperties(user, {
  name: { value: "David", writable: false },
  surname: { value: "Walsh", writable: false },
});
```

## Phương thức Object.getOwnPropertyDescriptors

Để lấy tất cả các đối tượng "property descriptor" của một object, bạn có thể sử dụng phương thức `Object.getOwnPropertyDescriptors(obj)`.

Và khi kết hợp phương thức trên với `Object.defineProperties`, bạn có một cách để **clone object** như sau:

    let clone = Object.defineProperties({}, Object.getOwnPropertyDescriptors(obj));

Khi [clone object](/bai-viet/javascript/copy-object-trong-javascript), ta thường chỉ **copy giá trị các thuộc tính** như sau:

```js
for (let key in user) {
  clone[key] = user[key];
}
```

Tuy nhiên, cách làm trên không thực hiện copy giá trị các cờ `writable`, `enumerable` và `configurable`.

Do đó, nếu bạn muốn **clone object** tốt hơn (bao gồm giá trị của tất cả các cờ) thì cách làm trên là hoàn toàn phù hợp.

## Các phương thức khác

JavaScript cung cấp các phương thức giúp bạn thao tác với object giống như việc thay đổi giá trị cờ `writable`, `enumerable` và `configurable` nhưng dễ dàng hơn.

► [Object.preventExtensions(obj)](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Object/preventExtensions)

Giúp ngăn chặn việc **thêm các thuộc tính** vào object.

► [Object.seal(obj)](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Object/seal)

Giúp ngăn chặn việc **thêm/xóa** các thuộc tính. Tương đương với việc set `configurable: false` cho tất cả các thuộc tính.

► [Object.freeze(obj)](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Object/freeze)

Giúp ngăn chặn việc **thêm/xóa/thay đổi giá trị** các thuộc tính. Tương đương với việc set `configurable: false, writable: false` cho tất cả các thuộc tính.

► [Object.isExtensible(obj)](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Object/isExtensible)

Trả về `false` nếu việc **thêm các thuộc tính** vào object bị cấm, ngược lại trả về `true`.

► [Object.isSealed(obj)](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Object/isSealed)

Trả về `true` nếu việc **thêm/xóa** thuộc tính là bị cấm, ngược lại trả về `false`.

► [Object.isFrozen(obj)](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Object/isFrozen)

Trả về `true` nếu việc **thêm/xóa/thay đổi giá trị** các thuộc tính là bị cấm, ngược lại trả về `false`.

Tham khảo: [Property flags and descriptors](https://javascript.info/property-descriptors)
