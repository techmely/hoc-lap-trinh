---
title: "Các phương thức với prototype trong JavaScript"
description: "Tất cả các object trong javascript đều có một prototype, và các object này kế thừa các thuộc tính (properties) cũng như phương thức (methods) từ prototype của mình."
keywords: [
"Prototype trong JavaScript",
"Prototype trong JavaScript là gì",
"Prototype trong JavaScript dùng để làm gì",
"Cách sử dụng Prototype trong JavaScript",
"khi nào cần Prototype trong JavaScript",
"vi du ve prototype trong javascript",
"Sự kế thừa trong javascript",
"kế thừa và prototype trong javascript",
"Các phương thức với prototype trong JavaScript là gì",
"Cách hoạt động của các phương thức prototype"
]
chapter:
  name: "Prototype và thừa kế prototype"
  slug: "chuong-07-prototype-va-thua-ke-prototype"
category:
  name: "Javascript"
  slug: "javascript"
image: https://kungfutech.edu.vn/thumbnail.png
position: 4
---

Trong bài viết [Prototype là gì? Prototype trong JavaScript](/bai-viet/javascript/prototype-trong-javascript), mình nói rằng `__proto__` đã lỗi thời và bạn nên dùng các phương thức [Object.getPrototypeOf](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Object/getPrototypeOf) và [Object.setPrototypeOf](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Object/setPrototypeOf) để thay thế.

Vì vậy, bài viết này mình sẽ tập trung vào tìm hiểu về các phương thức với prototype trong JavaScript.

## Phương thức của prototype

---

Các phương thức của prototype trong JavaScript bao gồm:

- [Object.create(proto, \[descriptors\])](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Object/create): tạo một object rỗng với giá trị của `[[Prototype]]` là `proto` và đối tượng mô tả thuộc tính là `descriptors`.
- [Object.getPrototypeOf(obj)](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Object/getPrototypeOf): trả về `[[Prototype]]` của object.
- [Object.setPrototypeOf(obj, proto)](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Object/setPrototypeOf): gán giá trị `proto` cho `[[Prototype]]` của object.

Ví dụ về các phương thức của prototype:

```js
let animal = {
  eats: true,
};

// tạo đối tượng với với prototype là animal
let rabbit = Object.create(animal);
console.log(rabbit.eats); // true

console.log(Object.getPrototypeOf(rabbit) === animal); // true
Object.setPrototypeOf(rabbit, {}); // thay đổi prototype của rabbit thành {}
```

Đối tượng mô tả thuộc tính `descriptors` giống như mình đã giới thiệu trong bài viết về [writable, enumerable và configurable](/bai-viet/javascript/writable-enumerable-configurable-cua-object).

Bạn có thể sử dụng `Object.create` để [clone object](/bai-viet/javascript/copy-object-trong-javascript) thay vì cách sử dụng vòng lặp `for...in`:

```js
let clone = Object.create(
  Object.getPrototypeOf(obj),
  Object.getOwnPropertyDescriptors(obj)
);
```

Câu lệnh trên **copy object một cách hoàn toàn**, bao gồm tất cả các thuộc tính (enumerable và non-enumberable), getters/setters,... với giá trị chính xác của `[[Prototype]]`.

## Object thuần

Như bạn đã biết, **object thuần** thường dùng để lưu các cặp **key-value**, với key là **string** hoặc [**symbol**](/bai-viet/javascript/symbol-trong-javascript). Và một điều thú vị, **key** có thể là bất kỳ string nào, ngoại trừ `"__proto__"`, ví dụ:

```js
let obj = {};
let key = "__proto__";

obj[key] = "some value";
console.log(obj[key].toString()); // "[object Object]" không phải "some value".
```

Trong ví dụ trên, mình muốn lưu trữ cặp key-value với giá trị của key là `"__proto__"`. Tuy nhiên, key này bị **bỏ qua**. Bởi vì, `"__proto__"` là một thuộc tính đặc biệt có giá trị `null` hoặc một **object**.

**Làm sao để giải quyết vấn đề này?**

► **Cách 1**: bạn có thể chuyển qua sử dụng [Map](/bai-viet/javascript/map-trong-javascript) thay vì sử dụng object thuần như sau:

```js
let obj = new Map();
let key = "__proto__";

obj.set(key, "some value");
console.log(obj.get(key).toString()); // "some value"
```

► **Cách 2**: sử dụng `Object.create(null)`, ví dụ:

```js
let obj = Object.create(null);
let key = "__proto__";

obj[key] = "some value";
console.log(obj[key].toString()); // "some value"
```

Bởi vì, `__proto__` không phải một thuộc tính trong object, mà chỉ là **getter/setter** cho `[[Prototype]]`.

Khi gọi `Object.create(null)`, thực chất là bạn đang tạo một object không có `[[Prototype]]`. Do đó, `__proto__` cũng không trở thành **getter/setter**.

Vì vậy, `__proto__` có thể trở thành **thuộc tính bình thường** trong object như cách làm trên.

## Tổng kết

---

Các phương thức với prototype trong JavaScript là:

- [Object.create(proto, \[descriptors\])](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Object/create): tạo một object rỗng với giá trị của `[[Prototype]]` là `proto` và đối tượng mô tả thuộc tính là `descriptors`.
- [Object.getPrototypeOf(obj)](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Object/getPrototypeOf): trả về `[[Prototype]]` của object.
- [Object.setPrototypeOf(obj, proto)](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Object/setPrototypeOf): gán giá trị `proto` cho `[[Prototype]]` của object.

`__proto__` thực chất là **getter/setter** của `[[Prototype]]` trong object. Vì vậy, bạn không thể lưu **key-value** với giá trị của key là `__proto__`.

Để giải quyết vấn đề trên, bạn có thể sử dụng **Map** thay vì object thuần, hoặc dùng `Object.create(null)` để tạo ra object không có prototype.

Ngoài ra, `Object.create` còn được dùng để **clone object** như sau:

```js
let clone = Object.create(
  Object.getPrototypeOf(obj),
  Object.getOwnPropertyDescriptors(obj)
);
```

Các phương thức hữu ích khác:

- [Object.keys(obj)](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Object/keys): trả về mảng các **enumerable key** trong object.
- [Object.values(obj)](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Object/values): trả về mảng các **enumerable value** trong object.
- [Object.entries(obj)](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Object/entries): trả về mảng các **enumerable key-value** trong object.
- [Object.getOwnPropertySymbols(obj)](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Object/getOwnPropertySymbols): trả về mảng tất cả các **key kiểu symbol** trong object.
- [Object.getOwnPropertyNames(obj)](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Object/getOwnPropertyNames): trả về mảng tất cả các **key kiểu string** trong object.
- [Reflect.ownKeys(obj)](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Reflect/ownKeys): trả về mảng tất cả các **key** trong object.
- [obj.hasOwnProperty(key)](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Object/hasOwnProperty): trả về `true` nếu `obj` chứa `key` (không phải qua kế thừa prototype).

## Thực hành

### Bài 1

Cho đoạn code sau:

```js
let dictionary = Object.create(null);

// Thêm phương thức toString vào dictionary tại đây

// thêm data vào dictionary
dictionary.apple = "Apple";
dictionary.__proto__ = "test"; // __proto__ là một thuộc tính thường

// chỉ apple và __proto__ xuất hiện trong vòng lặp
for (let key in dictionary) {
  console.log(key); // "apple" rồi đến "__proto__"
}

// gọi dictionary.toString()
console.log(dictionary.toString()); // "apple,__proto__"
```

Hãy thêm phương thức `toString` vào `dictionary` để thỏa mãn đoạn code trên?

Xem đáp án

```js
let dictionary = Object.create(null);

// Thêm phương thức toString vào dictionary tại đây
Object.defineProperty(dictionary, "toString", {
  value: function () {
    return Object.keys(this).join(",");
  },
  enumberable: false,
});
// thêm data vào dictionary
dictionary.apple = "Apple";
dictionary.__proto__ = "test"; // __proto__ là một thuộc tính thường

// chỉ apple và __proto__ xuất hiện trong vòng lặp
for (let key in dictionary) {
  console.log(key); // "apple" rồi đến "__proto__"
}

// gọi dictionary.toString()
console.log(dictionary.toString()); // "apple,__proto__"
```

### Bài 2

Cho đoạn code sau:

```js
function Rabbit(name) {
  this.name = name;
}
Rabbit.prototype.sayHi = function () {
  console.log(this.name);
};

let rabbit = new Rabbit("Rabbit");
```

Các câu lệnh sau có giống nhau hay không?

```js
rabbit.sayHi(); // (1)
Rabbit.prototype.sayHi(); // (2)
Object.getPrototypeOf(rabbit).sayHi(); // (3)
rabbit.__proto__.sayHi(); // (4)
```

Xem đáp án

<content-result>

(1) - Rabbit
(2) - undefined
(3) - undefined
(4) - undefined

</content-result>

Câu lệnh `(1)` thì `this=rabbit`, bởi vì `rabbit` là object đứng trước `.`, nên đáp án đúng như trên.

Các câu lệnh `(2), (3), (4)` thì `this=Rabbit.prototype`. Mà trong `Rabbit.prototype` không có thuộc tính `name`.

Tham khảo: [Prototype methods, objects without `__proto__`](https://javascript.info/prototype-methods)
