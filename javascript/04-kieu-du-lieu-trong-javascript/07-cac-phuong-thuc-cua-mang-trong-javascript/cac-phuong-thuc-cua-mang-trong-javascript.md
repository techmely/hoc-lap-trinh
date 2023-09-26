---
title: "Các phương thức của mảng trong Javascript"
description: "Trong bài viết này, chúng ta sẽ cùng tìm hiểu về một số phương thức của mảng trong Javascript có thể giúp bạn thao tác với dữ liệu của mình đúng cách."
chapter:
  name: "Kiểu dữ liệu trong Javascript"
  slug: "chuong-04-kieu-du-lieu-trong-javascript"
image: https://user-images.githubusercontent.com/29374426/168242680-a06573d8-935e-4e59-8933-7a46204eb822.png
position: 7
---

Có rất nhiều phương thức của mảng trong JavaScript. Nhờ đó, việc xử lý mảng trở nên dễ dàng hơn. Sau đây, mình sẽ tìm hiểu chi tiết về các phương thức xử lý mảng phổ biến nhất.

![Các phương thức của mảng trong Javascript](https://user-images.githubusercontent.com/29374426/168242680-a06573d8-935e-4e59-8933-7a46204eb822.png)

## Các phương thức thêm/xóa phần tử mảng

Trong bài viết [Array là gì? Array trong JavaScript](/bai-viet/javascript/mang-array-trong-javascript), mình đã giới thiệu 4 phương thức cơ bản của mảng là:

- Phương thức `arr.push(...items)`: thêm một hoặc nhiều phần tử vào cuối mảng.
- Phương thức `arr.pop()`: lấy ra và trả về phần tử cuối cùng của mảng.
- Phương thức `arr.shift()`: lấy ra và trả về phần tử đầu tiên của mảng.
- Phương thức `arr.unshift(...items)`: thêm một hoặc nhiều phần tử vào đầu mảng.

Ngoài ra, còn nhiều phương thức của mảng trong JavaScript nữa.

### Phương thức `splice`

Làm sao để xóa phần tử bất kỳ trong mảng?

Dĩ nhiên, mảng trong JavaScript cũng là [object](/bai-viet/javascript/object-la-gi-object-trong-javascript). Nghĩa là bạn có thể dùng `delete` để xóa một phần tử bất kỳ trong mảng dựa vào chỉ số.

```js
let letters = ["a", "b", "c"];

delete letters[1]; // xóa phần tử "b"
console.log(letters[1]); // undefined

console.log(letters.length); // 3
```

Vấn đề xảy ra là: mặc dù bạn đã xóa một phần tử trong mảng, nhưng độ dài của mảng `length` vẫn không đổi (bằng 3). Bởi vì, `delete obj.key` chỉ xóa giá trị của thuộc tính `key` trong object.

Cái chúng ta mong muốn là: khi xóa phần tử của mảng thì độ dài mảng phải giảm đi. Đó chính là lý do phương thức `splice` ra đời.

Phương thức [`arr.splice`](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array/splice) có thể **xóa, thêm hoặc thay thế** phần tử của mảng. Cú pháp phương thức `splice` là:

```js
arr.splice(start[, deleteCount, elem1,..., elemN]);
```

Phương thức `splice` xử lý mảng tại vị trí có chỉ số `start` bằng cách: xóa đi `deleteCount` phần tử, rồi chèn thêm các phần tử `elem1,... elemN` vào đúng vị trí đó. Sau đó, trả về mảng của những phần tử bị xóa.

Ví dụ xóa đi 1 phần tử tại vị trí 1:

```js
let letters = ["a", "b", "c"];

// từ vị trí có chỉ số 1, xóa đi 1 phần tử
letters.splice(1, 1);

console.log(letters); // (2) ['a', 'c']
```

Ví dụ xóa đi 3 phần tử tại vị trí đầu tiên và thêm 2 phần tử khác:

```js
let letters = ["a", "b", "c"];

// từ vị trí có chỉ số 0, xóa đi 3 phần tử, rồi thêm vào 2 phần tử
letters.splice(0, 3, "d", "e");

console.log(letters); // (2) ['d', 'e']
```

Ví dụ trả về mảng các phần tử bị xóa:

```js
let letters = ["a", "b", "c"];

// từ vị trí có chỉ số 1, xóa đi 2 phần tử là "b", "c"
// rồi thêm vào 1 phần tử "d"
let arr = letters.splice(1, 2, "d");

console.log(letters); // (2) ['a', 'd']
console.log(arr); // (2) ['b', 'c'] -> mảng các phần tử bị xóa
```

Phương thức `splice` cũng có thể **thêm phần tử vào mảng mà không cần xóa đi phần tử nào**, bằng cách truyền vào giá trị `deleteCount` bằng 0.

```js
let letters = ["a", "b", "c"];

letters.splice("1", 0, "d", "e");
console.log(letters); // (5) ['a', 'd', 'e', 'b', 'c']
```

Phương thức `splice` chấp nhận **chỉ số âm**. Nếu chỉ số âm thì **thứ tự đếm là từ cuối lên đầu**, ví dụ:

```js
let letters = ["a", "b", "c"];

// chỉ số bằng -1 tức đếm 1 đơn vị từ cuối lên
// xóa đi 0 phần tử
// rồi chèn thêm 2 phần tử "d" và "e"
letters.splice(-1, 0, "d", "e");
console.log(letters); // (5) ['a', 'b', 'd', 'e', 'c']
```

### Phương thức `slice`

Phương thức [`arr.slice`](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array/slice) đơn giản hơn phương thức `arr.splice`.

Cú pháp phương thức `slice` là:

```js
arr.slice([start], [end]);
```

Phương thức này **trả về mảng mới** bằng cách copy mảng ban đầu từ vị trí `start` đến vị trí `end` (không bao gồm `end`). Cả hai giá trị `start` và `end` đều có thể âm, khi đó việc đếm được tính từ cuối của mảng.

Phương thức của array `arr.slice` tương tự như phương thức của string `str.slice`, chỉ khác là trả về **subarray** chứ không phải là **substring**.

```js
let letters = ["a", "b", "c", "d"];

// copy mảng letters từ vị trí 1 đến vị trí 3
let arr1 = letters.slice(1, 3);
console.log(arr1); // (2) ['b', 'c']

// copy mảng letters từ vị trí số 2 từ cuối lên đến cuối mảng
let arr2 = letters.slice(-2);
console.log(arr2); // (2) ['c', 'd']
```

### Phương thức `concat`

Phương thức [`arr.concat`](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array/concat) trả về array mới bao gồm các giá trị của `arr` ban đầu, cộng thêm giá trị các phần tử trong array thêm vào hoặc các giá trị khác.

Cú pháp phương thức `arr.concat` là:

```js
arr.concat(arg1, arg2,...)
```

Phương thức này chấp nhận **số lượng tham số tùy ý**. Và giá trị của `arg1, arg2,...` có thể là mảng hoặc giá trị khác.

Giả sử phần tử `argN` là mảng thì tất cả các phần tử trong mảng `argN` được sao chép. Ngược lại, nếu giá trị của `argN` không phải mảng thì giá trị của chính nó được copy vào mảng, ví dụ:

```js
let arr1 = [1, 2];

// tạo mảng mới từ mảng arr1 và mảng [3, 4]
let arr2 = arr1.concat([3, 4]);
console.log(arr2); // (4) [1, 2, 3, 4]

// tạo mảng mới từ mảng arr1 và mảng [3, 4] và [5, 6]
let arr3 = arr1.concat([3, 4], [5, 6]);
console.log(arr3); // (6) [1, 2, 3, 4, 5, 6]

// tạo mảng mới từ mảng arr1 và mảng [3, 4] cùng với các giá trị 5, 6
let arr4 = arr1.concat([3, 4], 5, 6);
console.log(arr4); // (6) [1, 2, 3, 4, 5, 6]
```

Bình thường, phương thức `concat` chỉ copy các phần tử từ mảng. Nhưng với các object khác, thậm chí là dạng **array-like** (có **chỉ số** và thuộc tính `length`) thì giá trị của object cũng được copy vào:

```js
let arr = [1, 2];

let arrayLike = {
  0: "hello",
  length: 1,
};

// copy toàn bộ object vào mảng
console.log(arr.concat(arrayLike)); // (3) [1, 2, {...}]
```

Nhưng nếu object **array-like** đó có **thuộc tính đặc biệt** là `Symbol.isConcatSpreadable` thì cách xử lý hoàn toàn giống như của mảng bình thường:

```js
let arr = [1, 2];

let arrayLike = {
  0: "hello",
  1: "hi",
  length: 2,
  [Symbol.isConcatSpreadable]: true,
};

// từng phần tử của mảng được copy vào mảng arr
console.log(arr.concat(arrayLike)); // (4) [1, 2, "hello", "hi"]
```

## Phương thức duyệt mảng trong JavaScript

Phương thức của mảng trong JavaScript giúp duyệt tất cả các phần tử là: [`forEach`](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array/forEach).

Phương thức này cho phép bạn thực hiện một [hàm](/bai-viet/javascript/ham-trong-javascript/) trên mỗi phần tử trong mảng với cú pháp:

```js
arr.forEach(function (item, index, array) {
  // code xử lý trong đây
});
```

Trong đó:

- `item`: là phần tử đang duyệt.
- `index`: chỉ số của phần tử đang duyệt.
- `array`: chính là `arr`.

Ví dụ:

```js
["a", "b", "c"].forEach(function (item, index, array) {
  console.log(`item ${item} at index ${index} in array ${array}`);
});
```

::result

item a at index 0 in array a,b,c
item b at index 1 in array a,b,c
item c at index 2 in array a,b,c

::

Để hiểu hơn về `forEach`, bạn có thể đọc thêm bài viết: [JavaScript forEach là cái quái gì?](/bai-viet/javascript/tim-hieu-ve-foreach-trong-javascript)

## Các phương thức tìm kiếm trong mảng

Sau đây mình sẽ tìm hiểu về các phương thức của mảng trong JavaScript giúp tìm kiếm.

### Phương thức `indexOf`, `lastIndexOf` và `includes`

Các phương thức [`indexOf`](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array/indexOf), [`lastIndexOf`](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array/lastIndexOf) và [`includes`](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array/includes) có cú pháp và cách sử dụng tương tự như các phương thức cùng tên trong string.

- Phương thức `arr.indexOf(item, from)`: tìm kiếm `item` trong mảng, bắt đầu từ vị trí `from` và trả về **chỉ số** vị trí tìm thấy, ngược lại thì trả về `-1`.
- Phương thức `arr.lastIndexOf(item, from)`: tương tự phương thức `indexOf` là tìm kiếm `item` trong mảng và bắt đầu từ vị trí `from` nhưng thứ tự tìm kiếm **từ phải sang trái**.
- Phương thức `arr.includes(item, from)`: tìm kiếm `item` trong mảng từ vị trí `from`, và trả về `true` nếu tìm thấy, ngược lại trả về `false`.

Các ví dụ:

```js
let arr = [1, 0, 1, false];

console.log(arr.indexOf(0)); // 1
console.log(arr.indexOf(false)); // 3
console.log(arr.indexOf(null)); // -1

console.log(arr.indexOf(1)); // 0
console.log(arr.lastIndexOf(1)); // 2

console.log(arr.includes(1)); // true
```

**Chú ý:** các phương thức trên thường **sử dụng toán tử so sánh bằng nghiêm ngặt** `===` để kiểm tra.

Nếu bạn tìm kiếm `false` thì kết quả trả về là vị trí chính xác của `false` chứ không phải `0`.

Nếu bạn muốn kiểm tra sự tồn tại mà **không quan tâm đến chỉ số** thì nên dùng `arr.includes`.

Một điểm khác nhau giữa `arr.includes` với `arr.indexOf` và `arr.lastIndexOf` là `arr.includes` có thể tìm chính xác `NaN`.

```js
let arr = [NaN];

console.log(arr.includes(NaN)); // true
console.log(arr.indexOf(NaN)); // -1
console.log(arr.lastIndexOf(NaN)); // -1
```

### Phương thức `find` và `findIndex`

Giả sử bạn có một mảng các object. Làm sao để tìm kiếm object trong mảng thỏa mãn một số điều kiện cho trước?

Để giải quyết vấn đề này, bạn có thể dùng phương thức [`arr.find`](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array/find) hoặc [`arr.findIndex`](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array/find).

Phương thức `arr.find(fn)` có cú pháp là:

```js
let result = arr.find(function (item, index, array) {
  // code xử lý
});
```

Trong đó:

- `item`: là phần tử đang duyệt.
- `index`: chỉ số của phần tử đang duyệt.
- `array`: chính là `arr`.

Phương thức `arr.find(fn)` tìm kiếm một phần tử trong mảng thỏa mãn hàm `fn` (nói cách khác là hàm `fn` trả về `true`) và trả về phần tử tìm được, ngược lại thì trả về `undefined`.

Ví dụ tìm kiếm user có `id === 2` trong một mảng:

```js
let users = [
  { id: 1, name: "Alex" },
  { id: 2, name: "John" },
  { id: 3, name: "Anna" },
];

let user = users.find((item) => item.id === 2);

console.log(user.name); // John
```

Trong ví dụ trên, hàm cung cấp cho phương thức `find` là [arrow function](/bai-viet/javascript/arrow-function-trong-javascript) `(item) => item.id === 2` với một tham số `item` (các tham số còn lại không sử dụng).

Phương thức `arr.findIndex` có cú pháp hoàn toàn giống với `arr.find`. Chỉ khác là, `arr.findIndex` trả về chỉ số của phần tử tìm thấy, ngược lại thì trả về `-1`, ví dụ:

```js
let users = [
  { id: 1, name: "Alex" },
  { id: 2, name: "John" },
  { id: 3, name: "Anna" },
];

let index = users.findIndex((item) => item.id === 2);
console.log(index); // 1
```

### Phương thức `filter`

Phương thức `arr.find` và `arr.findIndex` chỉ tìm kiếm phần tử đầu tiên thỏa mãn. Để **tìm kiếm nhiều phần tử thỏa mãn**, bạn có thể dùng phương thức [`arr.filter`](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array/filter).

Cú pháp của `arr.filter` tương tự như `arr.find` và `arr.findIndex`:

```js
let results = arr.filter(function (item, index, array) {
  // code kiểm tra
});
```

Phương thức `arr.filter` trả về một mảng các phần tử thỏa mãn, ngược lại thì trả về mảng rỗng:

```js
let users = [
  { id: 1, name: "Alex" },
  { id: 2, name: "John" },
  { id: 3, name: "Anna" },
];

let results = users.filter((item) => item.id <= 2);
console.log(results.length); // 2

let others = users.filter((item) => item.id > 5);
console.log(others.length); // 0
```

## Các phương thức biến đổi mảng

Sau đây là các phương thức của mảng trong JavaScript giúp **tạo mảng mới từ một mảng gốc** hoặc **thay đổi thứ tự của mảng gốc**.

### Phương thức `map`

Phương thức [`arr.map`](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array/map) là một trong những phương thức phổ biến nhất của mảng.

Phương thức này thực hiện một hàm trên mỗi phần tử của mảng và trả về một mảng các kết quả với cú pháp là:

```js
let result = arr.map(function (item, index, array) {
  // trả về giá trị mới từ mỗi item
});
```

Ví dụ từ mảng các string, suy ra mảng các độ dài tương ứng là:

```js
let lengths = ["Dog", "Fish", "Elephant"].map((item) => item.length);
console.log(lengths); // (3) [3, 4, 8]
```

### Phương thức `sort`

Phương thức [`arr.sort`](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array/sort) sắp xếp các phần tử trong mảng theo thứ tự.

Phương thức này trả về mảng đã được sắp xếp. Tuy nhiên, mình thường bỏ qua giá trị trả về. Vì thực chất là chính `arr` đã bị thay đổi.

Ví dụ:

```js
let arr = [1, 2, 15];
arr.sort();
console.log(arr); // (3) [1, 15, 2]
```

Kết quả trả về là mảng `[1, 15, 2]`. Bạn có thấy điểm bất thường gì ở đây không?

::alert{type="infor"}

💡 Mặc định các phần tử được sắp xếp theo thứ tự string.

::

Trong ví dụ trên, các phần tử được [chuyển đổi kiểu dữ liệu](/bai-viet/javascript/chuyen-doi-kieu-du-lieu-trong-javascript) về **string** để so sánh. Mà `"1" < "2"` là `true`. Nên kết quả như trên là đúng.

Để sắp xếp theo tứ tự mong muốn, bạn cần truyền vào một hàm để so sánh.

Ví dụ một hàm so sánh:

```js
function compare(a, b) {
  if (a > b) return 1; // a đứng sau b
  if (a == b) return 0; // a, b bằng nhau
  if (a < b) return -1; // a đứng trước b
}
```

Áp dụng hàm so sánh vào phương thức `arr.sort` để sắp xếp mảng số:

```js
let arr = [1, 2, 15];

arr.sort(function (a, b) {  if (a > b) return 1; // a đứng sau b  if (a == b) return 0; // a, b bằng nhau  if (a < b) return -1; // a đứng trước b});
console.log(arr); // (3) [1, 2, 15]
```

Kết quả bây giờ đã đúng như mong muốn.

### Phương thức `reverse`

Phương thức [`arr.reverse`](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array/reverse) giúp đảo ngược mảng gốc, ví dụ:

```js
let arr = [1, 2, 3, 4, 5];

arr.reverse();

console.log(arr); // (5) [5, 4, 3, 2, 1]
```

### Phương thức `split` và `join`

Phương thức [`arr.split(delim)`](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/String/split) giúp tách string thành một mảng với giá trị dùng để phân tách là `delim`.

Ví dụ phân tách string thành mảng dựa trên dấu phẩy `,`:

```js
let str = "a,b,c,d";

let arr = str.split(",");

console.log(arr); // (4) [a, b, c, d]
```

Phương thức `arr.split` còn có tham số thứ hai dùng để giới hạn chiều dài của mảng:

```js
let str = "a,b,c,d";

// giới hạn số phần tử của mảng là 2
let arr = str.split(",", 2);

console.log(arr); // (2) [a, b]
```

Phương thức `arr.join` xử lý ngược lại với phương thức `arr.split`. Phương thức này trả về một string bằng cách ghép các phần tử mảng với "một kí tự kết nối".

Ví dụ ghép các phần tử mảng bởi dấu `,`:

```js
let arr = ["a", "b", "c", "d"];

// ghép các phần tử mảng bằng kí tự ,
let str = arr.join(",");

console.log(str); // a,b,c,d
```

### Phương thức `reduce` và `reduceRight`

Phương thức [`arr.reduce`](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array/reduce) và [`arr.reduceRight`](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array/reduceRight) dùng để tính toán và trả về một giá trị duy nhất từ các phần tử mảng.

Cú pháp phương thức `reduce` là:

```js
let value = arr.reduce(
  function (accumulator, item, index, array) {
    // code xử lý
  },
  [initial]
);
```

Trong đó:

- `initial`: giá trị khởi tạo, mặc định là `0`.
- `function` là hàm xử lý mỗi phần tử của mảng và trả về giá trị tích lũy, với các tham số:
  - `accumulator`: giá trị tích lũy sau lần duyệt phần tử phía trước và trong lần đầu tiên thì `accumulator` bằng giá trị khởi tạo `initial`.
  - `item`: phần tử hiện tại đang duyệt.
  - `index`: chỉ số của phần tử đang duyệt.
  - `array`: mảng đang duyệt, chính là `arr`.

Kết quả trả về của phương thức `reduce` chính là giá trị cuối cùng của `accumulator`.

Ví dụ tính tổng các phần tử trong mảng:

```js
let arr = [1, 2, 3, 4, 5];

// giá trị khởi tạo không truyền nên mặc định là 0
// tại mỗi lần duyệt, giá trị tích lũy được cộng với giá trị phần tử hiện tại
let result = arr.reduce((sum, current) => sum + current);

console.log(result); // 15
```

Phương thức [`arr.reduceRight`](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array/reduceRight) tương tự như phương thức `arr.reduce`, chỉ khác là thứ tự duyệt từ phải sang trái.

Để biết thêm về `arr.reduce`, mời bạn tham khảo bài viết: [Ứng dụng reduce trong mảng](/bai-viet/javascript/ung-dung-cua-reduce-trong-mang).

## Cách kiểm tra giá trị là mảng

Vì array bản chất là object, nên bạn không thể dùng `typeof` để xác định array.

```js
let arr = [];
let obj = {};

console.log(typeof arr); // object
console.log(typeof obj); // object
```

Để giải quyết vấn đề trên, bạn có thể sử dụng phương thức [`Array.isArray(value)`](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array/isArray). Phương thức này trả về `true` nếu `value` là mảng, ngược lại thì trả về `false`.

```js
let arr = [];
let obj = {};

console.log(Array.isArray(arr)); // true
console.log(Array.isArray(obj)); // false
```

## Tham số `thisArg`

Hầu hết các phương thức của mảng trong JavaScript đều có tham số cuối cùng là `thisArg`.

::alert{type="infor"}

Tham số này không bắt buộc và ít sử dụng nên mình không nói đến trong các phần trên.

::

Cú pháp đầy đủ các phương thức với `thisArg` là:

```js
arr.find(func, thisArg);
arr.filter(func, thisArg);
arr.map(func, thisArg);
// ...
// thisArg là tham số cuối cùng và không bắt buộc phải có
```

Giá trị của `thisArg` chính là giá trị của `this` ở trong hàm `func`.

Ví dụ lọc các giá trị của mảng nằm trong đoạn từ `min` đến `max`:

```js
// mảng ban đầu
let arr = [1, 3, 5, 2, 6, 10, 4];

// object điều kiện
let boundary1 = {
  min: 1,
  max: 5,
};

let boundary2 = {
  min: 3,
  max: 8,
};

// filter function
// giá trị của this là object ứng với thisArg
function filterFunc(item) {
  return item >= this.min && item <= this.max;
}

// filter
let ret1 = arr.filter(filterFunc, boundary1);
let ret2 = arr.filter(filterFunc, boundary2);

// kết quả
console.log(ret1); // (5) [1, 3, 5, 2, 4]
console.log(ret2); // (4) [3, 5, 6, 4]
```

## Tổng kết

Sau đây là tổng kết một số phương thức của mảng trong JavaScript:

- Thêm/xóa phần tử mảng:
  - `push(...items)`: thêm một hay nhiều phần tử vào cuối mảng.
  - `pop()`: lấy ra và trả về phần từ cuối cùng của mảng.
  - `shift()`: lấy ra và trả về phần tử đầu tiên của mảng.
  - `unshift(...items)`: thêm vào một hay nhiều phần tử vào đầu mảng.
  - `splice(pos, deleteCount, ...items)`: tại vị trí `pos`, xóa `deleteCount` phần tử rồi chèn thêm vào đó các `items`.
  - `slice(start, end)`: tạo mảng mới bằng cách copy các phần tử của mảng từ vị trí `start` đến `end` (không bao gồm `end`).
  - `concat(...items)`: trả về mảng mới bằng cách copy tất cả các phần tử của mảng hiện tại, rồi chèn thêm các `items` phía sau. Nếu `items` là một mảng thì các phần tử của mảng sẽ được copy, ngược lại thì copy cả `items`.
- Tìm kiếm trong mảng:
  - `indexOf(item, pos)`: tìm phần tử `item` trong mảng bắt đầu từ vị trí `pos` và trả về chỉ số vị trí tìm thấy, ngược lại trả về `-1`.
  - `lastIndexOf(item, pos)`: tương tự như phương thức `indexOf(item, pos)` nhưng thứ tự tìm kiếm là từ phải sang trái.
  - `includes(value)`: trả về `true` nếu mảng chứa giá trị `value`, ngược lại thì trả về `false`.
  - `find(func)`: tìm và trả về phần tử đầu tiên trong mảng thỏa mãn hàm `func` (tức hàm `func` trả về `true`).
  - `filter(func)`: tìm và trả về tất cả các phần tử trong mảng thỏa mãn hàm `func` (tức hàm `func` trả về `true`).
  - `findIndex(func)`: tương tự phương thức `find(func)` nhưng giá trị trả về là chỉ số.
- Duyệt mảng:
  - `forEach(func)`: gọi hàm `func` ứng với mỗi phần tử của mảng và không trả về giá trị nào.
- Biến đổi mảng:
  - `map(func)`: tạo mảng mới từ kết quả của việc gọi hàm `func` ứng với mỗi phần tử mảng.
  - `sort(func)`: sắp xếp mảng hiện tại theo thứ tự.
  - `reverse()`: đảo ngược thứ tự mảng hiện tại.
  - `split(delim)`: tách string thành mảng với giá trị phân tách là `delim`.
  - `join(delim)`: ghép các phần tử mảng với giá trị kết nối là `delim` và trả về string sau khi kết nối.
  - `reduce(func, initial)`: tính toán và trả về một giá trị duy nhất bằng cách gọi hàm `func` với mỗi phần tử mảng. Kết quả của mỗi lượt duyệt sẽ được tích lũy và truyền vào lượt tiếp theo.
  - `reduceRight(func, initial)`: tương tự như `reduce` nhưng thứ tự duyệt là từ phải sang trái.

Để kiểm tra một giá trị là mảng, bạn sử dụng phương thức `Array.isArray(value)`.

Trên đây là các phương thức của mảng trong JavaScript mà mình thấy hay sử dụng nhất. Dĩ nhiên, còn nhiều phương thức khác nữa, bạn có thể tự tìm hiểu thêm tại các bài viết sau:

- [MDN Array](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array)
