---
title: "Set trong Javascript"
description: "Set là một bổ sung hữu ích cho bộ công cụ JavaScript của bạn, đặc biệt để làm việc với các giá trị trùng lặp trong dữ liệu."
keywords: [
"Set trong Javascript",
"Set trong Javascript là gì",
"Set trong Javascript cách sử dụng",
"New Set(array javascript)",
"get set trong javascript",
"map và set trong javascript",
"settimeout trong javascript",
"settimeout trong javascript la gi",
"setattribute trong javascript",
"dùng settimeout trong javascript",
"setcookie trong javascript"
]
chapter:
  name: "Kiểu dữ liệu trong Javascript"
  slug: "chuong-04-kieu-du-lieu-trong-javascript"
category:
  name: "Javascript"
  slug: "javascript"
image: https://user-images.githubusercontent.com/29374426/168243792-6464321c-f082-4646-bac9-4edf0441231b.png
position: 14
---

Mình đã tìm hiểu về [Map](/bai-viet/javascript/map-trong-javascript) trong JavaScript rồi. Bài viết này mình tiếp tục tìm hiểu về một loại **object đặc biệt** nữa. Đó là Set trong Javascript

![Set trong Javascript](https://user-images.githubusercontent.com/29374426/168243792-6464321c-f082-4646-bac9-4edf0441231b.png)


## Set trong JavaScript là gì?

**Set trong Javascript** là một loại [object](/bai-viet/javascript/object-la-gi-object-trong-javascript) cho phép bạn lưu trữ dữ liệu một cách duy nhất, không trùng lặp.

Có 2 điều bạn cần chú ý ở đây.

### Set là một loại object

Vì vậy mà `typeof set` sẽ trả về string `object`.

```js
const set1 = new Set();
console.log(typeof set1);
// object
```

### Dữ liệu trong Set là duy nhất, không trùng lặp

Hiểu thế nào là **duy nhất, không trùng lặp**?

Đơn giản là "giá trị" của các phần tử không được giống nhau. Thực chất, Set sử dụng thuật toán [SameValueZero](https://tc39.github.io/ecma262/#sec-samevaluezero) để so sánh giá trị của các phần tử.

> Thuật toán **SameValueZero** tương tự như việc sử dụng toán tử so sánh bằng nghiêm ngặt `===` để so sánh giá trị. Chỉ khác ở chỗ thuật toán này coi `NaN` là giống nhau (mặc dù `NaN !== NaN` là `true`).

Vì vậy, điều mình nói ở trên chỉ đúng với [number và string](/bai-viet/javascript/cac-kieu-du-lieu-trong-javascript), còn đối với object thì khác. Bởi 2 object nhìn giống nhau nhưng rõ ràng chúng không bằng nhau:

```js
const obj1 = { x: 1, y: 2 };
const obj2 = { x: 1, y: 2 };

console.log(obj1 === obj2);
// false

const set1 = new Set([obj1, obj2]);
console.log(set1.size);
// 2
```

Ngoài ra, bạn cũng có thể lưu `NaN` và `undefined` vào Set trong JavaScript.

```js
const set2 = new Set([NaN, undefined, NaN]);
console.log(set2);
// Set(2) {NaN, undefined}
```

Đọc đến đây chắc bạn đã hiểu cơ bản về Set rồi phải không?

Sau đây là những thứ bạn có thể làm với Set trong JavaScript.

## Khởi tạo Set trong JavaScript

Khởi tạo Set là điều đầu tiên bạn cần làm nếu muốn sử dụng Set. Cú pháp khởi tạo Set trong Javascript là:

```js
new Set([iterable]);
```

Trong đó:

- Tham số [iterable](/bai-viet/javascript/iterable-trong-javascript) là không bắt buộc. Nếu bạn **không truyền tham số** vào hàm khởi tạo thì Set sẽ rỗng - không có phần tử nào.
- Ngược lại, nếu bạn truyền vào một iterable object thì **tất cả các phần tử** của object sẽ được thêm vào Set.

> **Chú ý:** bạn có thể truyền vào **iterable object**, chứ không chỉ có array (vì array chỉ là một loại iterable object).

Sau đây là các ví dụ khởi tạo Set trong JavaScript.

### Khởi tạo Set rỗng

Khởi tạo Set rỗng bằng cách không truyền tham số vào hàm khởi tạo.

```js
const set1 = new Set();
console.log(set1);
// Set(0) {}
```

### Khởi tạo Set từ Array

Array là một loại iterable object.

```js
const set2 = new Set([1, 2, "a", "b", 1]);
console.log(set2);
// Set(4) {1, 2, "a", "b"}
```

### Khởi tạo Set từ String

String cũng là một loại iterable object.

```js
const set3 = new Set("abcba");
console.log(set3);
// Set(3) {"a", "b", "c"}
```

### Khởi tạo Set từ arguments

Đối tượng [`arguments`](/bai-viet/javascript/object-la-gi-object-trong-javascript) là đối tượng có sẵn trong hàm, dùng để lưu trữ mảng các tham số truyền vào.

```js
function func4() {
  const set4 = new Set(arguments);
  console.log(set4);
}

func4("a", "b", "c", "b", 0, 1);
// Set(5) {"a", "b", "c", 0, 1}
```

### Khởi tạo Set từ NodeList

Kết quả của các phương thức liên quan đến `DOM` khi thao tác với trình duyệt như: [document.querySelectorAll()](https://developer.mozilla.org/en-US/docs/Web/API/Document/querySelectorAll), [document.getElementsByClassName()](https://developer.mozilla.org/en-US/docs/Web/API/Document/getElementsByClassName),... đều trả về `NodeList`.

Ví dụ:

```js
// tìm tất cả các phần tử với thẻ head
const head = document.querySelectorAll("head");
const set1 = new Set(head);
console.log(set1);
// Set(1) {head}
```

### Khởi tạo Set từ TypedArray

[TypedArray](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/TypedArray) là một kiểu object tương tự như Array. Và bạn cũng có thể sử dụng **TypedArray** để khởi tạo Set như sau:

```js
const typedArray1 = new Int8Array(2);
typedArray1[0] = 12;
typedArray1[1] = 34;

const set1 = new Set(typedArray1);
console.log(set1);
// Set(2) {12, 34}
```

### Khởi tạo Set từ Map

Bạn có thể khởi tạo Set từ Map như sau:

```js
const map1 = new Map();
map1.set("one", 1);
map1.set("two", 2);

const set1 = new Set(map1);
console.log(set1);
// Set(2) {Array(2), Array(2)}

for (const x of set1) {
  console.log(x);
}
/*
 * ["one", 1]
 * ["two", 2]
 */
```

### Khởi tạo Set từ Set

Bạn cũng có thể khởi tạo Set từ một Set khác.

```js
const set1 = new Set([1, 2]);
const set2 = new Set(set1);
console.log(set2);
// Set(2) {1, 2}
```

Trên đây là một số cách để khởi tạo Set trong JavaScript. Tiếp theo đây là cách để thêm phần tử vào Set.

## Thêm phần tử vào Set

Để thêm phần tử vào Set trong JavaScript, bạn có thể sử dụng phương thức `add` như sau:

```js
set.add(value);
```

Trong đó:

- Nếu Set không có phần tử `value` thì phương thức `set.add(value)` sẽ thêm `value` vào Set và trả về chính Set đó.
- Nếu `value` đã tồn tại thì phương thức `set.add(value)` sẽ bỏ qua và cũng trả về chính Set đó.

Ví dụ thêm phần tử vào Set:

```js
// khởi tạo set rỗng
const set1 = new Set();

// thêm phần tử 1
set1.add(1);
console.log(set1);
// Set(1) {1}

// thêm phần tử 2 (khác 1)
set1.add(2);
console.log(set1);
// Set(2) {1, 2}

// thêm phần tử 3 (khác 1 và 2)
set1.add(1).add(2).add(3);
console.log(set1);
// Set(3) {1, 2, 3}
```

Việc trả về chính đối tượng Set sau khi `add` giúp code trở trên ngắn gọn hơn nhiều.

## Lấy số lượng phần tử trong Set

Để lấy được số lượng phần tử của Set trong JavaScript, bạn có thể sử dụng thuộc tính `set.size`.

```js
const set1 = new Set(["a", "b", "a"]);
console.log(set1.size);
// 2 - vì set chỉ có hai phần tử ["a", "b"]
```

## Kiểm tra phần tử tồn tại trong Set

Để kiểm tra một phần tử có tồn tại trong Set hay không, bạn có thể sử dụng phương thức `set.has()`.

```js
const set1 = new Set([1, "a", [1, 2]]);

console.log(set1.has(1)); // true
console.log(set1.has("1")); // false
console.log(set1.has("a")); // true
console.log(set1.has("b")); // false
console.log(set1.has([1, 2])); // false - vì [1, 2] !== [1, 2]
```

Kết quả trên là hoàn toàn dễ hiểu phải không?

Mình chỉ muốn nhắc lại là Set sẽ sử dụng **toán tử so sánh bằng nghiêm ngặt** `===` để so sánh các giá trị, do đó:

```js
console.log(1 === 1); // true
console.log(1 === "1"); // false
console.log("a" === "a"); // true
console.log([1, 2] === [1, 2]); // false
```

## Xoá một phần tử trong Set

Để xóa một phần tử của Set trong JavaScript, bạn sử dụng phương thức `set.delete(value)`:

```js
const set1 = new Set("abcdcba");
console.log(set1); // Set(4) {a, b, c, d}

set1.delete("a");
console.log(set1); // Set(4) {b, c, d}

set1.delete("d");
console.log(set1); // Set(2) {b, c}
```

## Xoá tất cả phần tử trong Set

Để xóa tất cả các phần tử trong Set, bạn sử dụng phương thức `set.clear()`. Sau đó, Set sẽ trở thành rỗng.

```js
const set1 = new Set([1, 2, 3]);
console.log(set1); // Set(3) {1, 2, 3}

set1.clear();
console.log(set1); // Set(0) {}
```

## Duyệt qua các phần tử trong Set

Set hỗ trợ một số cách để duyệt qua các phần tử như sau.

### Sử dụng `for...of`

Ví dụ sử dụng `for...of` để duyệt qua các phần tử:

```js
const set1 = new Set(["a", { x: 1 }, 1]);

for (const x of set1) {
  console.log(x);
}
/*
 * a
 * { x : 1}
 * 1
 */
```

### Sử dụng `forEach`

Sử dụng `set.forEach()` cũng tương tự như [forEach trong Array](/bai-viet/javascript/tim-hieu-ve-foreach-trong-javascript).

```js
const set1 = new Set(["a", "b", "c"]);
console.log(set1);
// Set(3) {"a", "b", "c"}

set1.forEach(function (value) {
  console.log(value);
});
/*
 * a
 * b
 * c
 */
```

Ba phương thức `set.keys()`, `set.values()` và `set.entries()` đều trả về iterable object, với mỗi phần tử tương ứng với một phần tử trong Set (theo thứ tự mà mình chèn vào).

```js
// khởi tạo set
const set1 = new Set(["a", { x: 1 }, 1]);

// duyệt qua các keys trong set
for (const x of set1.keys()) {
  console.log(x);
}
/*
 * a
 * { x : 1}
 * 1
 */

// duyệt qua các values trong set
for (const x of set1.values()) {
  console.log(x);
}
/*
 * a
 * { x : 1}
 * 1
 */

// duyệt qua các cặp [key, value] trong set
for (const x of set1.entries()) {
  console.log(x);
}

/*
 * ["a", "a"]
 * [{ x : 1}, { x : 1}]
 * [1, 1]
 */
```

Bạn thấy rằng, các phương thức trên đều có đặc điểm là: `key` và `value` giống nhau. Việc để `key` và `value` bằng nhau để tương đồng với kiểu dữ liệu Map.

## Chuyển Set thành Array và ngược lại

Mình có thể sử dụng phương thức `forEach` của Set trong JavaScript, tương tự như Array. Nhưng còn các phương thức khác như: `map`, `filter`,... thì sao?

Thực tế, Set không hỗ trợ những phương thức này.

Nhưng bạn hoàn toàn có thể **chuyển Set thành Array** để sử dụng các phương thức của Array. Rồi sau đó, bạn chuyển Array ngược lại thành Set.

Để chuyển Set thành Array, bạn có thể sử dụng [Array.from](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array/from) hoặc sử dụng [toán tử spread](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Operators/Spread_syntax), ví dụ:

```js
// khởi tạo set
const set1 = new Set([1, 2, 3, 4, 5]);

// chuyển set thành array sử dụng Array.from
const arr1 = Array.from(set1);
console.log(arr1);
// [1, 2, 3, 4, 5]

// chuyển set thành array sử dụng cú pháp spread (...)
const arr2 = [...set1];
console.log(arr2);
// [1, 2, 3, 4, 5]
```

Giả sử, mình sử dụng phương thức [`filter`](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array/filter) để lọc lấy những phần tử là số chẵn.

```js
const arr3 = arr1.filter((x) => x % 2 === 0);
console.log(arr3);
// (2) [2, 4]
```

Bây giờ, mình chuyển Array ngược lại thành Set - sử dụng công thức phần khởi tạo Set:

```js
const set2 = new Set(arr3);
console.log(set2);
// Set(2) {2, 4}
```

Toàn bộ quá trình trên có thể viết gọn lại thành:

```js
const set1 = new Set([1, 2, 3, 4, 5]);
console.log(set1);
// Set(5) {1, 2, 3, 4, 5}

const filteredArray = [...set1].filter((x) => x % 2 == 0);
const set2 = new Set(filteredArray);
console.log(set2);
// Set(2) {2, 4}
```

Khi đã chuyển Set thành Array rồi, bạn có thể sử dụng bất kỳ [phương thức](/bai-viet/javascript/phuong-thuc-trong-javascript) nào mà Array hỗ trợ.

## Một ví dụ thực tế sử dụng Set

Vì mình cần phải lưu lại danh sách các thẻ, chuyên mục với các phần tử là duy nhất, rồi sau đó **hiển thị danh sách** này lên sidebar.

Ví dụ mỗi bài viết có một mảng lưu các thẻ tag:

```js
const post1 = ["tag1", "tag2", "tag4"];
const post2 = ["tag3", "tag4"];
```

Sau đó, tạo ra mảng các thẻ tag duy nhất bằng Set như sau:

```js
let arrTag = [];

arrTag = Array.from(new Set([...arrTag, ...post1]));
arrTag = Array.from(new Set([...arrTag, ...post2]));

console.log(arrTag);
// (4) ["tag1", "tag2", "tag4", "tag3"]
```

Giả sử tạo thêm một bài viết mới với mảng các thẻ tag là:

```js
const post3 = ["tag1", "tag3", "tag5"];
```

Để cập nhật danh sách thẻ tag, mình có thể làm như sau:

```js
arrTag = Array.from(new Set([...arrTag, ...post3]));
// (5) ["tag1", "tag2", "tag4", "tag3", "tag5"]
```

Mỗi khi thêm một bài viết mới, mình chỉ cần làm theo cách trên là cập nhật được danh sách các thẻ mà không bị trùng lặp.

## Tổng kết

Set trong JavaScript là một loại object dùng để lưu trữ dữ liệu mà không trùng lặp.

Các phương thức của Set là:

- `new Set(iterable)`: khởi tạo Set bằng cách truyền vào một iterable object (không bắt buộc), trường hợp không truyền vào tham số nào thì Set sẽ rỗng.
- `set.add(value)`: thêm phần tử `value` vào Set và trả về chính Set đó.
- `set.delete(value)`: xóa một phần tử trong Set và trả về `true` nếu giá trị `value` tồn tại trong Set, ngược lại trả về `false`.
- `set.has(value)`: trả về `true` nếu giá trị `value` tồn tại trong Set, ngược lại thì trả về `false`.
- `set.clear()`: xóa tất cả các phần tử trong Set.
- `set.size`: trả về số lượng phần tử trong Set.

**Tham khảo:**

- [Set - MDN](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Set)
- [The Set JavaScript Data Structure](https://flaviocopes.com/javascript-data-structures-set/)
