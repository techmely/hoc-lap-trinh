---
title: "Map trong Javascript"
description: "Javascript map là một hàm dành cho đối tượng mảng trong javascript, hàm này có công dụng tương tự như vòng lăp forEach. Cú pháp chung của hàm map()."
keywords: [
"Map trong Javascript",
"map trong javascript là gì",
"hàm map trong javascript",
"cách sử dụng hàm map trong javascript",
"cách sử dụng hàm map trong js",
"new map trong javascript",
"hashmap trong javascript",
"map object trong javascript",
"map key value javascript",
"map() javascript",
"Map Object trong JavaScript",
"Map key, value JavaScript"
]
chapter:
  name: "Kiểu dữ liệu trong Javascript"
  slug: "chuong-04-kieu-du-lieu-trong-javascript"
category:
  name: "Javascript"
  slug: "javascript"
image: https://user-images.githubusercontent.com/29374426/168243549-4803ac2f-e047-4230-8cad-6a059f529826.png
position: 12
---

![Map trong Javascript](https://user-images.githubusercontent.com/29374426/168243549-4803ac2f-e047-4230-8cad-6a059f529826.png)


**Map trong JavaScript** là một loại object cho phép lưu trữ dữ liệu theo kiểu **key-value**.

Nghe qua thì Map có vẻ giống với [object](/bai-viet/javascript/object-la-gi-object-trong-javascript) bình thường. Nhưng không phải tự nhiên mà người ta **tạo thêm kiểu dữ liệu Map**.

Thực tế, Map có **những đặc điểm riêng biệt** so với object thông thường. Sau đây, mình cùng tìm hiểu về Map trong JavaScript nhé!

## Map trong JavaScript là gì?

Nói một cách đầy đủ, Map trong JavaScript là một **cấu trúc dữ liệu** cho phép lưu trữ dữ liệu theo kiểu **key-value**, tương tự như object. Tuy nhiên, chúng khác nhau ở chỗ là:

- Object chỉ cho phép sử dụng [String](/bai-viet/javascript/cac-kieu-du-lieu-trong-javascript) hay [Symbol](/bai-viet/javascript/symbol-trong-javascript) làm key.
- Map cho phép mọi kiểu dữ liệu (String, Number, Boolean, NaN, Object,...) có thể làm key.

<content-warning>

để tránh hiểu lầm, mỗi khi mình dùng từ **object** thì bạn hiểu đó là **object thông thường** mà từ trước đến giờ bạn vẫn sử dụng, không phải **Map**.

</content-warning>

```js
const map1 = new Map();
console.log(typeof map1); // object
```

## Khởi tạo Map trong JavaScript

Cú pháp khởi tạo Map trong JavaScript là:

```js
new Map([iterable]);
```

Bạn có thể truyền vào một [iterable object](/bai-viet/javascript/iterable-trong-javascript) để khởi tạo Map. Khi đó, mỗi phần tử của iterable object sẽ tương ứng với một phần tử của Map.

Dĩ nhiên, tham số `iterable` là **không bắt buộc**. Khi bạn không truyền vào `iterable`, Map sẽ rỗng và không có phần tử nào.

> **Chú ý**: vì Map lưu trữ dữ liệu theo kiểu **key-value** nên mỗi phần tử của iterable object phải là một **[mảng](/bai-viet/javascript/mang-array-trong-javascript) gồm 2 phần tử** có dạng: `[key, value]`.

Một số ví dụ:

- `[1, 2, 3, 4]`: là một iterable object, nhưng mỗi phần tử của nó là **number** (1, 2, 3, 4). Suy ra, đây **không phải là tham số hợp lệ** để khởi tạo map.
- `[[1, 2], [3, 4]]`: là một **tham số hợp lệ**. Vì nó là iterable object mà mỗi phần tử lại là một mảng 2 phần tử - `[1, 2]` và `[3, 4]`. Khi đó:
  - `1` là key - `2` là value
  - `3` là key - `4` là value.

Dựa vào những đặc điểm nêu trên, mình có thể khởi tạo Map trong JavaScript theo những cách sau đây.

### Khởi tạo Map rỗng

Để khởi tạo Map rỗng, bạn chỉ cần **không truyền vào tham số** cho hàm khởi tạo:

```js
const map1 = new Map();
console.log(map1);
// Map(0) {}
```

### Khởi tạo Map từ array

Array hợp lệ để khởi tạo Map là các phần tử của array phải là **một mảng hai phần tử**.

```js
// Trường hợp hợp lệ:
// Mỗi phần tử của mảng đầu vào là một mảng hai phần tử
const map2 = new Map([
  [1, "a"],
  [2, "b"],
]);
console.log(map2);
// Map(2) {1 => "a", 2 => "b"}

// Trường hợp KHÔNG hợp lệ:
// Mỗi phần tử của mảng đầu vào không phải mảng hai phần tử
const map3 = new Map([1, "a", 2, "b"]);
// Uncaught TypeError: Iterator value 1 is not an entry object
```

### Khởi tạo Map từ `arguments`

Đối tượng arguments là đối tượng có sẵn trong hàm, dùng để lưu trữ mảng các tham số truyền vào.

```js
function func4() {
  const map4 = new Map(arguments);
  console.log(map4);
}

func4(["one", 1], ["two", 2], ["three", 3]);
// Map(3) {"one" => 1, "two" => 2, "three" => 3}
```

### Khởi tạo Map từ Map

Bạn có thể khởi tạo Map từ một Map khác:

```js
// Khởi tạo map thứ nhất
const map6 = new Map([
  ["a", 1],
  ["b", 2],
]);
console.log(map6);
// => Map(2) {"a" => 1, "b" => 2}

// Khởi tạo map thứ hai từ map thứ nhất
const map6_clone = new Map(map6);
console.log(map6_clone);
// Map(2) {"a" => 1, "b" => 2}
```

### Khởi tạo Map từ Set

Ngoài ra, bạn có thể khởi tạo Map từ [Set](/bai-viet/javascript/set-trong-javascript/):

```js
// Khởi tạo Set
const set5 = new Set([
  ["a", 1],
  ["b", 2],
]);
console.log(set5);
// Set(2) {Array(2), Array(2)}

const map5 = new Map(set5);
console.log(map5);
// Map(2) {"a" => 1, "b" => 2}
```

Trên đây là một số cách để khởi tạo Map trong JavaScript. Tiếp theo, mình sẽ tìm hiểu về cách để thêm phần tử vào Map.

## Thêm phần tử vào Map

Để thêm phần tử vào Map trong JavaScript, bạn có thể sử dụng phương thức `set`, với cú pháp:

```js
map.set(key, value);
```

Phương thức này gán giá trị `value` cho khoá `key` bên trong Map.

Nếu **`key` chưa tồn tại** thì Map tạo mới phần tử với `key` tương ứng. Ngược lại, nếu **`key` đã tồn tại** thì Map sẽ gán giá trị mới cho nó.

**Vấn đề làm sao biết được `key` đã tồn tại hay chưa?**

Map sử dụng thuật toán [SameValueZero](https://tc39.github.io/ecma262/#sec-samevaluezero) để **so sánh giá trị** của các key với nhau.

Thuật toán **SameValueZero** về cơ bản là giống với việc sử dụng toán tử `===` để so sánh. Chỉ khác là **SameValueZero** coi `NaN` là giống nhau, mặc dù `NaN !== NaN` là `true`.

Ví dụ:

```js
// Khởi tạo Map rỗng.
const map7 = new Map();

// Thêm phần tử "a" -> 1 vào map.
map7.set("a", 1);
// Map(1) {"a" => 1}

// Thêm phần tử "b" -> 2 vào map, "b" !== "a" nên Map tạo phần tử mới.
map7.set("b", 2);
// Map(2) {"a" => 1, "b" => 2}

// Thêm phần tử [1] -> 3 vào map, [1] đều khác "a" và "b".
map7.set([1], 3);
// Map(3) {"a" => 1, "b" => 2, [1] => 3}

// Thêm phần tử "a" -> 4 vào map, tuy nhiên key "a" đã tồn tại.
// => cập nhật vào phần tử cũ - số lượng phần tử không đổi
map7.set("a", 4);
// Map(3) {"a" => 4, "b" => 2, [1] => 3}

// Thêm phần tử [1] -> 5 vào map.
// Trong map đã có phần tử với key [1], tuy nhiên mảng là kiểu tham chiếu.
// Vì vậy [1] !== [1]. Do đó, phần tử mới được thêm vào map.
map7.set([1], 5);
// Map(4) {"a" => 4, "b" => 2, [1] => 3, [1] => 5}

// Thêm phần tử NaN -> 6 vào map.
// NaN khác các giá trị key đã có, nên phần tử mới được thêm vào map.
map7.set(NaN, 6);
// Map(5) {"a" => 4, "b" => 2, [1] => 3, [1] => 5, NaN => 6}
```

Khi sử dụng [toán tử so sánh](/toan-tu-so-sanh-trong-javascript/) bằng nghiêm ngặt `===` thì `[1] === [1]` là `false`. Vì vậy, Map trên tồn tại 2 cặp phần tử với key là `[1]` với value lần lượt là `3` và `5`.

Ngoài ra, phương thức `set` còn trả về chính đối tượng Map. Nên mình có thể áp dụng kỹ thuật Method Chaining ở đây, sẽ giúp cho code trở nên ngắn gọn hơn.

Đoạn code trên có thể trở nên gọn hơn bằng cách:

```js
const map7 = new Map();
map7.set("a", 1).set("b", 2).set([1], 3).set("a", 4).set([1], 5).set(NaN, 6);
// Map(5) {"a" => 4, "b" => 2, [1] => 3, [1] => 5, NaN => 6}
```

## Lấy giá trị của phần tử trong Map

Để lấy `value` tương ứng với `key` của map trong JavaScript, bạn có thể sử dụng phương thức `map.get(key)` như sau:

```js
const map7 = new Map([
  ["a", 1],
  ["b", 1],
]);

console.log(map7.get("a")); // 1
console.log(map7.get("c")); // undefined
```

Nếu `key` tồn tại trong Map thì phương thức `map.get(key)` trả về `value` tương ứng, ngược lại thì trả về `undefined`.

## Lấy số lượng phần tử trong Map

Để lấy ra **số lượng các phần tử** của Map trong JavaScript, bạn sử dụng phương thức `map.size`, ví dụ:

```js
const map8 = new Map();
console.log(map8.size);
// 0 - mảng rỗng

map8.set("a", 1).set("b", 2);
console.log(map8.size);
// 2 - mảng có 2 phần tử
```

## Kiểm tra phần tử tồn tại trong Map

Để kiểm tra xem **một phần tử đã tồn tại** trong Map hay chưa - thực chất là kiểm tra xem một giá trị `key` đã tồn tại hay chưa, bạn có thể dùng phương thức `has` như sau:

```js
map.has(key);
```

Nếu trong Map tồn tại `key` thì phương thức `map.has(key)` trả về `true`, ngược lại thì trả về `false`.

```js
const map9 = new Map([
  ["a", 1],
  [1, 2],
  [[2], 3],
  [NaN, 4],
]);

console.log(map9.has("a")); // true
console.log(map9.has("1")); // false
console.log(map9.has(1)); // true
console.log(map9.has([2])); // false - vì [2] !== [2]
console.log(map9.has(NaN)); // true
```

> Bạn nhớ là Map sử dụng thuật toán **SameValueZero** để so sánh nhé!

## Xoá một phần tử trong Map

Để **xóa một phần tử** trong Map, bạn sử dụng phương thức `delete`:

```js
map.delete(key);
```

Nếu trong Map tồn tại `key` thì phần tử ứng với `key` sẽ bị xóa khỏi Map. Phương thức `map.delete(key)` trả về `true` nếu `key` tồn tại, ngược lại thì trả về `false`.

```js
const map10 = new Map([
  ["one", 1],
  ["two", 2],
  ["three", 3],
]);
console.log(map10);
// Map(3) {"one" => 1, "two" => 2, "three" => 3}

// xóa phần tử với key là "two" - tồn tại
console.log(map10.delete("two"));
// true

// sau khi xóa, map còn lại 2 phần tử
console.log(map10);
// {"one" => 1, "three" => 3}
```

## Xoá tất cả phần tử trong Map

Phía trên là cách xóa **một phần tử** khỏi Map. Để xóa hết **tất cả các phần tử** khỏi Map, bạn sử dụng phương thức `clear`:

```js
const map11 = new Map([
  ["a", 1],
  ["b", 2],
  ["c", 3],
]);
console.log(map11);
// Map(3) {"a" => 1, "b" => 2, "c" => 3}

// xóa hết các phần tử
map11.clear();

// map trở thành empty
console.log(map11);
// Map(0) {}
```

## Duyệt qua các phần tử trong Map

Sau đây là các cách để duyệt qua các phần tử của Map trong JavaScript.

### Sử dụng `for...of`

Map là [iterable object](/bai-viet/javascript/iterable-trong-javascript). Do đó, bạn có thể sử dụng `for...of` để duyệt qua các phần tử của Map.

```js
const map12 = new Map([
  [1, "a"],
  [2, "b"],
  [3, "c"],
]);

for (const item of map12) {
  console.log(item);
}
/*
 * [1, "a"]
 * [2, "b"]
 * [3, "c"]
 */
```

### Sử dụng phương thức `forEach`

Bạn cũng có thể sử dụng `forEach` duyệt qua các phần tử của map như sau:

```js
const map13 = new Map([
  [1, "a"],
  [2, "b"],
  [3, "c"],
]);

map13.forEach((value, key, map) => {
  console.log(value, key, map);
});
/*
 * a 1 Map(3) {1 => "a", 2 => "b", 3 => "c"}
 * b 2 Map(3) {1 => "a", 2 => "b", 3 => "c"}
 * c 3 Map(3) {1 => "a", 2 => "b", 3 => "c"}
 */
```

Bạn chú ý **hàm callback**:

- Tham số đầu tiên là `value` ứng với phần tử đang duyệt.
- Tiếp theo mới là `key` của phần tử đang duyệt.
- Cuối cùng là `map` đang duyệt.

Cú pháp này tương tự với của [forEach khi duyệt mảng](/bai-viet/javascript/tim-hieu-ve-foreach-trong-javascript):

```js
arr.forEach(function (value, index, arr) {
  // code xử lý
});
```

► Phương thức `map.keys()`

Trả về một iterable object chứa giá trị `key` của các phần tử theo thứ tự chèn vào.

```js
const map14 = new Map([
  [1, "a"],
  ["b", 2],
  [3, "c"],
]);

for (const key of map14.keys()) {
  console.log(key);
}
/*
 * 1
 * b
 * 3
 */
```

► Phương thức `map.values()` trả về một iterable object chứa giá trị `value` của các phần tử theo thứ tự chèn vào.

```js
const map14 = new Map([
  [1, "a"],
  ["b", 2],
  [3, "c"],
]);

for (const value of map14.values()) {
  console.log(value);
}
/*
 * a
 * 2
 * c
 */
```

► Phương thức `map.entries()` trả về một iterable object mà mỗi phần tử tương ứng là một mảng `[key, value]`.

```js
const map14 = new Map([
  [1, "a"],
  ["b", 2],
  [3, "c"],
]);

for (const item of map14.entries()) {
  console.log(item);
}
/*
 * [1, "a"]
 * ["b", 2]
 * [3, "c"]
 */
```

## Chuyển Map thành Array

Sau đây là một số cách chuyển map trong JavaScript thành array sử dụng [cú pháp spread](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Operators/Spread_syntax).

### Chuyển Map keys thành Array

```js
const map15 = new Map([
  [1, "a"],
  ["b", 2],
  [3, "c"],
]);

const keys = [...map15.keys()];
console.log(keys);
// [1, "b", 3]
```

### Chuyển Map values thành Array

```js
const map16 = new Map([
  [1, "a"],
  ["b", 2],
  [3, "c"],
]);

const values = [...map16.values()];
console.log(values);
// ["a", 2, "c"]
```

## Tổng kết

Map trong JavaScript là một loại object dùng để lưu trữ dữ liệu theo kiểu **key-value**, nhưng Map khác object ở một số điểm sau:

- Map cho phép **key** thuộc bất kỳ kiểu dữ liệu nào.
- Map có thuộc tính **size** và một số phương thức đặc trưng.

Một số phương thức và thuộc tính của Map:

- `new Map([iterable])`: khởi tạo Map với tham số là một iterable object (không bắt buộc) với mỗi phần tử có dạng `[key, value]`.
- `map.set(key, value)`: lưu `value` bởi `key` và trả về `map`.
- `map.get(key)`: trả về `value` bởi `key`, nếu `key` không tồn tại thì trả về `undefined`.
- `map.has(key)`: trả về `true` nếu `key` tồn tại, ngược lại thì trả về `false`.
- `map.delete(key)`: xóa giá trị ứng với `key` và trả về `true` nếu `key` tồn tại, ngược lại thì trả về `false`.
- `map.clear()`: xóa tất cả các phần tử trong `map`.
- `map.size`: trả về số phần tử hiện tại có trong `map`.

**Tham khảo**:

- [Map - MDN](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Map)
- [The Map JavaScript Data Structure](https://flaviocopes.com/javascript-data-structures-map/)
