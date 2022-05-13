---
title: "Weakmap trong Javascript"
description: "WeakMap trong JavaScript là cũng là một loại object, cho phép lưu trữ dữ liệu dạng key-value.Nhưng WeakMap có nhiều điểm khác với Map."
keywords: [
"Weakmap  trong JavaScript",
"Weakmap  trong JavaScript là gì",
"Weakmap  trong JavaScript cách sử dụng",
"Weakmap  JavaScript là gì",
"Weakmap  JavaScript",
"Collection Weakmap trong ES6 javascript",
"Collection Weakmap  trong ES6 là gì trong javascript",
"JavaScript Map và Weakmap ",
"JavaScript Map và Weakmap cách sử dụng",
"JavaScript Map và Weakmap là gì"
]
chapter:
  name: "Kiểu dữ liệu trong Javascript"
  slug: "chuong-04-kieu-du-lieu-trong-javascript"
category:
  name: "Javascript"
  slug: "javascript"
image: https://user-images.githubusercontent.com/29374426/168243960-1fc99145-3e3b-4bb8-b829-b5233a336e90.png
position: 15
---

WeakMap trong JavaScript là cũng là **một loại object**. WeakMap có những đặc điểm giống và khác Map như thế nào?

![Weakmap trong Javascript](https://user-images.githubusercontent.com/29374426/168243960-1fc99145-3e3b-4bb8-b829-b5233a336e90.png)


Sau đây, mình sẽ cùng tìm hiểu về WeakMap trong JavaScript.

## WeakMap trong JavaScript là gì?

**WeakMap trong JavaScript** là một cấu trúc cho phép lưu trữ dữ liệu theo kiểu **key-value** tương tự như [Map](/bai-viet/javascript/map-trong-javascript), [Object](/bai-viet/javascript/object-la-gi-object-trong-javascript) với cú pháp khởi tạo là:

```js
new WeakMap([iterable]);
```

Trong đó:

- Tham số `iterable` là [iterable object](/bai-viet/javascript/iterable-trong-javascript) (không bắt buộc) với mỗi phần tử là mảng hai chiều dạng `[key, value]`.
- Thuộc tính trong WeakMap `key` **chỉ có thể là object**.

```js
let obj = { x: 1 };
let weakMap = new WeakMap();

weakMap.set(obj, 1); // OK - key là object
weakMap.set("a", 1); // Lỗi: Invalid value used as weak map key - key là string
```

## Các phương thức của WeakMap

Sau đây là các phương thức của WeakMap trong JavaScript.

► Phương thức `weakMap.set(key, value)`:

Dùng để lưu giá trị `value` bởi thuộc tính `key` và trả về chính WeakMap. Trong đó, `key` phải là một object, ngược lại thì báo lỗi.

```js
let obj1 = { x: 1 };
let obj2 = { x: 2 };

let weakMap = new WeakMap();
weakMap.set(obj1, 1).set(obj2, 2);
```

► Phương thức `weakMap.get(key)`:

Trả về giá trị của thuộc tính `key`, nếu `key` không tồn tại thì trả về `undefined`.

```js
let obj1 = { x: 1 };
let obj2 = { x: 2 };

let weakMap = new WeakMap();
weakMap.set(obj1, 1).set(obj2, 2);

console.log(weakMap.get(obj1)); // 1console.log(weakMap.get({ x: 1 })); // undefined - vì {x:1} !== {x:1}
```

► Phương thức `weakMap.delete(key)`:

Xóa thuộc tính `key` trong WeakMap, và trả về `true` nếu `key` tồn tại, ngược lại thì trả về `false`.

```js
let obj1 = { x: 1 };
let obj2 = { x: 2 };

let weakMap = new WeakMap();
weakMap.set(obj1, 1).set(obj2, 2);

console.log(weakMap.delete(obj1)); // trueconsole.log(weakMap.delete({ x: 1 })); // false - vì {x:1} !== {x:1}
```

► Phương thức `weakMap.has(key)`:

Trả về `true` nếu `key` tồn tại trong WeakMap, ngược lại thì trả về `false`.

```js
let obj1 = { x: 1 };
let obj2 = { x: 2 };

let weakMap = new WeakMap();
weakMap.set(obj1, 1).set(obj2, 2);

console.log(weakMap.has(obj1)); // trueconsole.log(weakMap.has({ x: 1 })); // false - vì {x:1} !== {x:1}
```

## So sánh WeakMap và Map

Sau đây là một số đặc điểm khác nhau giữa WeakMap và Map.

### Kiểu dữ liệu của key

Đối với Map, key có thể thuộc bất kỳ kiểu dữ liệu nào. Nhưng đối với WeakMap thì ngược lại, key chỉ có thể là object.

```js
let map = new Map();
let weakMap = new WeakMap();

map.set(1, "one"); // OK
weakMap.set(1, "one"); // Lỗi - Invalid value used as weak map key
```

### Tính chất của iterable object

Map là iterable object. Do đó, bạn có thể duyệt qua hết tất cả các phần tử trong Map.

WeakMap không phải là iterable object. Bạn không có cách nào để duyệt hết tất cả các phần tử của WeakMap.

```js
// khởi tạo map
let map = new Map();
map.set(1, "a").set(2, "b");

// duyệt qua các phần tử của map
for (let item of map) {
  console.log(item);
  /**
   * [1, 'a']
   * [2, 'b']
   */
}

// khởi tạo weakmap
let obj1 = { x: 1 };
let obj2 = { x: 2 };
let weakMap = new WeakMap();
weakMap.set(obj1, "a").set(obj2, "b");

// duyệt qua các phần tử của weakmap
for (let item of weakMap) {
  console.log(item);
}
/**
 * Lỗi: weakMap is not iterable
 */
```

### Vấn đề garbage collection

Như mình đã đề cập ở bài viết [garbage collection trong JavaScript](/bai-viet/javascript/garbage-collection-trong-javascript) thì JavaScript engine giữ một giá trị trong bộ nhớ khi giá trị đó "có thể tiếp cận".

Ví dụ về garbage collection:

```js
let alex = { name: "Alex" };

// object { name: "Alex" } có thể được truy cập bởi biến alex

// ghi đè giá trị của biến alex
alex = null;

// object bị hủy vì không có tham chiếu tới nó
```

Thông thường, thuộc tính của object hoặc phần tử trong mảng,... được coi là "có thể tiếp cận" và giữ lại trong bộ nhớ nếu object hoặc mảng chứa chúng vẫn tồn tại.

Ví dụ, mình đẩy một object vào mảng. Và khi mảng đó vẫn tồn tại thì object trong mảng cũng sẽ tồn tại, mặc dù không còn biến tham chiếu đến object.

```js
let alex = { name: "Alex" };

// đẩy object vào mảng
let arr = [alex];

// ghi đè giá trị của biến alex
alex = null;

// mặc dù alex bị gán bằng null, nhưng object vẫn tồn tại trong mảng
console.log(arr[0]); // {name: "Alex"}
```

Tương tự, nếu mình sử dụng **object** làm key cho Map thì khi Map tồn tại, **object** cũng sẽ tồn tại và không bị giải phóng.

```js
let alex = { name: "Alex" };

// khai báo map và sử dụng biến alex làm key cho map
let map = new Map();
map.set(alex, "1");

// ghi đè giá trị của biến alex
alex = null;

// mặc dù biến alex bị gán bằng null, nhưng object alex vẫn tồn tại trong map
console.log(map.size); // 1
for (let item of map) {
  console.log(item);
  /**
   * [{name: 'Alex'}, '1']
   */
}
```

Nhưng với **WeakMap thì khác**, khi không còn biến tham chiếu đến object thì object đó sẽ bị hủy, ví dụ:

```js
let alex = { name: "Alex" };

// khai báo map và sử dụng biến alex làm key cho weakMap
let weakMap = new WeakMap();
weakMap.set(alex, "1");

// ghi đè giá trị của biến alex
alex = null;
```

Sau khi biến `alex` bị gán bằng `null`, không còn cách nào có thể truy cập vào phần tử với key là `alex` trước đó. Vì vậy, object với `alex` sẽ bị hủy.

Trên đây là một số điểm khác nhau khi so sánh Map và WeakMap trong JavaScript. Tiếp theo, mình sẽ tìm hiểu một ứng dụng thực tế của WeakMap.

## Ứng dụng của WeakMap trong lưu trữ dữ liệu

Ví dụ bạn muốn lưu thông tin **số lần truy cập** của một đối tượng `user`. Thông tin này được lưu trữ trong một **map** với key là đối tượng `user` và giá trị là số lượt truy cập.

Khi user rời đi, đối tượng `user` bị giải phóng và mong muốn là **không lưu trữ** thông tin số lần truy cập với đối tượng `user` nữa.

Ví dụ module dùng để lưu trữ và xử lý số lượt truy cập nằm trong file thư viện `library.js`:

library.js

```js
// khai báo Map để lưu trữ thông tin số lượt truy cập
let visitsCountMap = new Map();

// tăng số lượt truy cập với tham số user
function countUser(user) {
  // lấy số lượt truy cập hiện tại
  // nếu user chưa có trong map thì visitsCountMap.get(user) trả về undefined
  // khi đó, giá trị mặc định là 0
  let count = visitsCountMap.get(user) || 0;

  // tăng giá trị count lên 1 đơn vị và lưu lại vào thuộc tính user
  visitsCountMap.set(user, count + 1);
}
```

Đoạn code sử dụng:

main.js

```js
let alex = { name: "Alex" };

// Cập nhật số lượt truy cập với biến alex
countUser(alex);
// Khi user rời đi, gán biến alex = null
alex = null;
```

Khi `alex` gán bằng `null`, object `{ name: "Alex" }` nên được giải phòng. Nhưng thực tế thì object `alex` vẫn tồn tại trong map `visitsCountMap`.

Để giải phòng bộ nhớ, bạn cần chủ động gọi `visitsCountMap.delete(alex)` để xóa thuộc tính `alex` khỏi map, ngược lại object `alex` vẫn sẽ được giữ lại.

Tuy nhiên, việc gọi `delete` là khó khăn vì code xử lý đang nằm trong một file khác. Để tránh việc này, bạn chỉ cần chuyển Map thành WeakMap trong file `library.js` là xong:

library.js

```js
// khai báo WeakMap để lưu trữ thông tin số lượt truy cập
let visitsCountMap = new WeakMap();
// tăng số lượt truy cập với tham số user
function countUser(user) {
  // lấy số lượt truy cập hiện tại
  // nếu user chưa có trong map thì visitsCountMap.get(user) trả về undefined
  // khi đó, giá trị mặc định là 0
  let count = visitsCountMap.get(user) || 0;

  // tăng giá trị count lên 1 đơn vị và lưu lại vào thuộc tính user
  visitsCountMap.set(user, count + 1);
}
```

Lúc này, khi biến `alex` được gán bằng `null` thì object `{ name: "Alex" }` cũng sẽ bị hủy, vì không có cách nào truy cập đến object đó nữa.

## Ứng dụng của WeakMap trong caching

Ví dụ bạn muốn **lưu kết quả của một lần gọi hàm** để lần sau nếu có gọi lại thì trả về luôn kết quả trước đó.

Cách sử dụng Map thông thường:

cache.js

```js
// khởi tạo Map để làm cache
let cache = new Map();

// tính toán và lưu lại kết quả
function process(obj) {
  // kiểm tra xem trong cache đã có obj chưa
  if (!cache.has(obj)) {
    // nếu chưa có thì tính toán để ra kết quả
    let result = /* tính toán để ra kết quả với obj */ obj;

    // lưu lại kết quả vào cache với key là obj và value là result
    cache.set(obj, result);
  }

  // trả về kết quả ứng với key là obj trong cache
  return cache.get(obj);
}
```

Sử dụng trong file `main.js`:

main.js

```js
// objec bất kỳ
let obj = {};

// tính toán với obj được kết quả result1
let result1 = process(obj);

// sau đó ở một đoạn code khác, tính toán với obj để được result2
let result2 = process(obj);

// khi không dùng obj nữa thì gán obj bằng null
obj = null;

// tuy nhiên, kích thước của cache vẫn là 1
// vì object lưu vào cache chưa bị giải phòng
console.log(cache.size); // 1
```

Để giải phóng `cache`, bạn phải chủ động gọi `cache.delete(obj)`. Tuy nhiên để đơn giản, bạn chỉ cần chuyển Map thành WeakMap đối với biến `cache` là xong:

cache.js

```js
// khởi tạo WeakMap để làm cache
let cache = new WeakMap();
// tính toán và lưu lại kết quả
function process(obj) {
  // kiểm tra xem trong cache đã có obj chưa
  if (!cache.has(obj)) {
    // nếu chưa có thì tính toán để ra kết quả
    let result = /* tính toán để ra kết quả với obj */ obj;

    // lưu lại kết quả vào cache với key là obj và value là result
    cache.set(obj, result);
  }

  // trả về kết quả ứng với key là obj trong cache
  return cache.get(obj);
}
```

Khi đó, nếu `obj` bị gán bằng `null` thì không còn cách nào để truy cập vào object trong `cache`, nên object đó sẽ bị giải phóng.

## Tổng kết

WeakMap trong JavaScript tương tự như Map, cho phép lưu trữ dữ liệu theo kiểu `key-value`. Tuy nhiên, WeakMap chỉ chấp nhận object làm key.

Và khi object bị hủy, object tương ứng trong WeakMap sẽ bị giải phóng vì không còn cách nào để truy cập vào object đó nữa.

Các phương thức của WeakMap là:

- `weakMap.set(key, value)`: lưu giá trị `value` vào thuộc tính `key` và trả về chính WeakMap.
- `weakMap.get(key)`: trả về giá trị của thuộc tính `key`, nếu `key` không tồn tại thì trả về `undefined`.
- `weakMap.delete(key)`: xóa thuộc tính `key` trong WeakMap, nếu `key` tồn tại thì trả về `true`, ngược lại thì trả về `false`.
- `weakMap.has(key)`: trả về `true` nếu `key` tồn tại trong `weakMap`, ngược lại thì trả về `false`.

WeakMap không phải iterable object nên không có cách nào để duyệt hết các phần tử trong WeakMap (như cách dùng `for...of` với Map).

Tham khảo:

- [Difference between Map and WeakMap in JavaScript](https://www.mattzeunert.com/2017/01/31/weak-maps.html)
- [Difference between "Map" and "WeakMap" in JavaScript](http://qnimate.com/difference-between-map-and-weakmap-in-javascript/)
- [WeakMap](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/WeakMap)
