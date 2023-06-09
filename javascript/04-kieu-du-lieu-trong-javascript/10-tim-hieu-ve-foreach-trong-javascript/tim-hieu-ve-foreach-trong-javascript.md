---
title: "Tìm hiểu về forEach trong Javascript"
description: "forEach là một phương thức có sẵn của array, để duyệt qua mỗi phần tử của mảng và thực hiện một hành động nào đó."
keywords: [
"foreach javascript dùng như thế nào",
"cách sử dụng foreach javascript",
"foreach javascript là gì",
"forEach object js",
"foreach mang trong javascript",
"for in javascript",
"array foreach trong javascript",
"hàm foreach trong javascript",
"cách sử dụng hàm foreach trong javascript"
]
chapter:
  name: "Kiểu dữ liệu trong Javascript"
  slug: "chuong-04-kieu-du-lieu-trong-javascript"
category:
  name: "Javascript"
  slug: "javascript"
image: https://user-images.githubusercontent.com/29374426/168243187-23ec7564-4b55-402b-8663-06ebc2d677f6.png
position: 10
---

Trong JavaScript, để duyệt [array](/bai-viet/javascript/mang-array-trong-javascript) thì **forEach** là một hàm rất hay. Vậy hàm forEach trong JavaScript cụ thể là như thế nào? Cách sử dụng forEach JavaScript ra sao? Mình hãy cùng tìm hiểu để làm chủ forEach js nhé!

![Tìm hiểu về forEach trong Javascript](https://user-images.githubusercontent.com/29374426/168243187-23ec7564-4b55-402b-8663-06ebc2d677f6.png)


## Đặt bài toán

Cho một mảng `numbers= [1, 2, 3, 4, 5, 6,7, 8, 9, 10]`. Hãy tính tổng các số trong mảng và hiển thị ra **console**.

Khi mới học JavaScript, mình giải bài toán này như sau:

```js
const numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
let sum = 0;

// duyệt từng phần tử của mảng để cộng dồn vào biến sum
for (let i = 0; i < numbers.length; i++) {
  sum += numbers[i];
}

console.log(sum); // 55
```

Cách giải trên khá dễ hiểu. Mình duyệt tất cả các phần tử mảng bằng [vòng lặp for với chỉ số](/bai-viet/javascript/vong-lap-trong-javascript). Tại mỗi lượt lặp, mình lấy phần tử đang duyệt cộng dồn với biến `sum`.

Có một vấn đề với cách này, đó là việc sử dụng chỉ số `i` có thể khiến bạn bị nhầm với một biến trước đó. Dẫn đến những lỗi sai không đoán trước được.

Lúc này, **forEach** JavaScript xuất hiện giúp bạn giải quyết vấn đề trên.

### Cách triển khai hàm forEach JavaScript

Một cách đơn giản để triển khai hàm forEach như sau:

```js
function forEach(array, action) {
  for (let i = 0; i < array.length; i++) {
    action(array[i]);
  }
}
```

Hàm `forEach` trên nhận đầu vào là một mảng `array` và một hàm `action` - thực hiện hành động với mỗi phần tử của mảng `array[i]`.

### Áp dụng hàm forEach để giải quyết bài toán trên

```js
const numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
let sum = 0;

forEach(numbers, function (element) {
  sum += element;
});
console.log(sum);
// 55
```

Mình có thể diễn giải thuật toán trên bằng lới như sau: _Với mỗi phần tử trong mảng `numbers`, mình lấy nó ra và cộng dồn với biến sum. Kết quả thu được, sẽ ghi ra console._

Nếu so sánh với cách làm trước thì cách này rõ ràng là dài hơn. Tuy nhiên, đây chỉ là một ví dụ cơ bản, nên mình sẽ không bàn về **độ dài, ngắn** của code.

Vấn đề nên quan tâm trước tiên đó là: **code-đọc-dễ-hiểu**.

Theo quan điểm cá nhân mình, việc sử dụng hàm **forEach** giúp code gần giống với ngôn ngữ tự nhiên hơn. Quan điểm của bạn về vấn đề này thế nào?

## Giới thiệu hàm forEach trong JavaScript

Hàm forEach là gì? Hay vòng lặp forEach trong JavaScript là gì?

Trả lời: **forEach** là một phương thức có sẵn của [array](/bai-viet/javascript/sap-xep-mang-trong-javascript), để duyệt qua mỗi phần tử của mảng và thực hiện một hành động nào đó.

### Cú pháp

```js
arr.forEach(function callback(currentValue, index, array) {
  // code xử lý
}[, thisArg]);
```

### Giải thích

- `callback`: Hàm callback là hàm để thực hiện với mỗi phần tử của mảng, bao gồm 3 tham số:
  - `currentValue`: phần tử hiện tại đang được xử lý của array.
  - `index`: chỉ số của phần tử hiện tại đang được xử lý của array.
  - `array`: mảng hiện tại đang gọi hàm forEach.
- `thisArg`: giá trị được sử dụng như là [`this`](/bai-viet/javascript/object-la-gi-object-trong-javascript) - tham chiếu tới đối tượng khi thực hiện hàm `callback`.

**Chú ý**:

- Nếu `thisArg` bị bỏ qua thì mặc định giá trị đó là `undefined`.
- Bạn có thể bỏ qua tên hàm `callback`.

```js
arr.forEach(function(currentValue, index, array) { // code xử lý
  }[, thisArg]);
```

### Ví dụ in ra nội dung của mảng

```js
function printContentArray(array) {
  array.forEach(function print(element) {
    console.log(element);
  });
}

printContentArray([1, 3, 5]);
```

<content-result>

<p>1</p>
<p>3</p>
<p>5</p>

</content-result>

### Ví dụ sử dụng `thisArg`

```js
function Counter() {
      this.sum = 0;
      this.count = 0;

      this.add = function(array) {
        array.forEach(function(item) {
          this.sum += item;
          ++this.count;
        }, this); // this chính là đối tượng tạo new Counter  }
    }

    const obj = new Counter();
    obj.add([2, 5, 9]);

    console.log(obj.count); // 3
    console.log(obj.sum); // 16
```

## Ưu, nhược điểm của việc sử dụng forEach

Bất cứ thứ gì cũng có hai mặt, **forEach** JavaScript cũng không ngoại lệ. Sau đây là một số ưu, nhược điểm của phương thức `forEach`:

### Ưu điểm

- Code rõ ràng, gần với ngôn ngữ tự nhiên.
- Trong nhiều trường hợp sẽ ngắn gọn hơn việc sử dụng vòng lặp `for` hay `while`.

### Nhược điểm

- Code thường sẽ chạy chậm hơn so với việc sử dụng vòng lặp (tuy nhiên không đáng kể).
- Không giống các ngôn ngữ lập trình khác như C/C++, Java (hầu như chỉ sử dụng vòng lặp).

Trên đây là một số ưu, nhược điểm của việc sử dụng `forEach`. Mình không khuyên bạn **nên hay không nên** sử dụng phương thức này.

Đây chỉ đơn giản là một cách thức để duyệt mảng, bạn có thể sử dụng nó hoặc bạn chỉ cần sử dụng vòng lặp.

> It's the choice.

## Một số từ khóa trong vòng lặp forEach JS

Khi so sánh với các **vòng lặp khác, ngôn ngữ lập trình khác**, bạn sẽ thấy một số từ khóa hay sử dụng trong vòng lặp như: `return`, `break` và `continue`.

Câu hỏi đặt ra là liệu những từ khóa này có sử dụng được trong vòng lặp forEach JavaScript hay không? Cách sử dụng của chúng có giống hay không?

Sau đây là câu trả lời.

### Từ khóa return trong forEach

Từ khóa `return` dùng để dừng lại một hàm và trả về giá trị từ hàm đó.

Giả sử, bạn cần viết một hàm tìm **vị trí của số chẵn đầu tiên** trong một mảng. Nếu không tìm thấy thì trả về giá trị `-1`.

Sau đây là code sử dụng **vòng lặp for** thông thường:

```js
function findFirstEvenIndex(arr) {
  for (let i = 0; i < arr.length; i++) {
    if (arr[i] % 2 === 0) return i;
  }

  return -1;
}

// Ví dụ
const arr = [1, 2, 3, 4, 5];
const ret = findFirstEvenIndex(arr);

console.log("ret=", ret);
// ret= 1
```

Chuyển đoạn code trên sang forEach như sau:

```js
function findFirstEvenIndex(arr) {
  arr.forEach(function (item, i) {
    if (arr[i] % 2 === 0) return i;
  });

  return -1;
}

// Ví dụ
const arr = [1, 2, 3, 4, 5];
const ret = findFirstEvenIndex(arr);

console.log("ret=", -1);
// ret= -1
```

Tại sao kết quả lại là **\-1**?

Tại vì từ khóa `return` trong forEach chỉ có tác dụng để **thoát khỏi hàm callback** bên trong forEach mà thôi. Do đó, kết quả của hàm trên là giá trị của câu lệnh `return -1` cuối cùng.

Dể giải quyết bài toán này, mình khuyên bạn không nên dùng `forEach`. Thay vào đó bạn có thể dùng vòng lặp for thông thường như trên, hoặc sử dụng vòng lặp **for...in** như sau:

```js
function findFirstEvenIndex(arr) {
  for (let i in arr) {
    if (arr[i] % 2 === 0) return i;
  }

  return -1;
}

// Ví dụ
const arr = [1, 2, 3, 4, 5];
const ret = findFirstEvenIndex(arr);

console.log("ret=", ret);
// ret= 1
```

<content-info>

vòng lặp `for...in` chỉ nên dùng với **array**, không nên sử dụng với đối tượng `array-like`.

</content-info>

### Từ khóa break trong forEach

Từ khóa `break` thường dùng để thoát khỏi [câu lệnh `switch`](/bai-viet/javascript/switch-case-trong-javascript) hoặc thoát khỏi vòng lặp (`for`, `while`, `do...while`, `for...in`).

Ví dụ đoạn code sau dùng để thoát khỏi vòng lặp for khi `i` bằng `3`:

```js
const arr = [1, 2, 3, 4, 5];

for (let i = 0; i < arr.length; i++) {
  if (i === 3) break;
  console.log("i=", i);
}

/* Kết quả trên console:
    i= 0
    i= 1
    i= 2
    */
```

Nếu sử dụng từ khóa `break` với forEach thì sao?

```js
const arr = [1, 2, 3, 4, 5];

    arr.forEach((item, i) => {
      if (i === 3) break;
      console.log("i=", i);
    });

    /* Kết quả trên console:
    Uncaught SyntaxError: Illegal break statement
    */
```

Đúng vậy, bạn sẽ bị lỗi cú pháp **Illegal break statement** vì từ khóa break là không hợp lệ với forEach JS.

Nghĩa là bạn không thể sử dụng từ khóa break với forEach. Thay vào đó bạn có thể sử dụng vòng lặp **for** như trên hoặc dùng phương thức [`arr.some()`](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array/some) để thay thế:

```js
const arr = [1, 2, 3, 4, 5];

arr.some(function (item, index) {
  if (index === 3) return true;
  console.log("i=", index);
});

/* Kết quả trên console:
    i= 0
    i= 1
    i= 2
    */
```

### Từ khóa continue trong forEach

Từ khóa `continue` thường dùng để **bỏ qua một lượt lặp** trong vòng lặp.

Ví dụ đoạn code sau dùng để bỏ qua lượt lặp khi `i` bằng `3`:

```js
const arr = [1, 2, 3, 4, 5];

for (let i = 0; i < arr.length; i++) {
  if (i === 3) continue;
  console.log("i=", i);
}

/* Kết quả trên console:
    i= 0
    i= 1
    i= 2
    i= 4
    */
```

Nếu chuyển sang dùng với `forEach`:

```js
const arr = [1, 2, 3, 4, 5];

    arr.forEach(function(item, i) {
      if (i === 3) continue;
      console.log("i=", i);
    });

    /* Kết quả trên console:
    Uncaught SyntaxError:
    Illegal continue statement: no surrounding iteration statement
    */
```

Bạn sẽ bị lỗi **Illegal continue statement: no surrounding iteration statement**. Vì từ khóa `continue` không hợp lệ với forEach JavaScript.

Nghĩa là bạn cũng không thể dùng `continue` bên trong `forEach` được. Thay vào đó, bạn có thể dùng **vòng lặp for** như trên hoặc sử dụng từ khóa `return` như sau:

```js
const arr = [1, 2, 3, 4, 5];

arr.forEach(function (item, i) {
  if (i === 3) return;
  console.log("i=", i);
});

/* Kết quả trên console:
    i= 0
    i= 1
    i= 2
    i= 4
    */
```

## Từ JavaScript forEach đến các phương thức khác

Ngoài forEach, JavaScript còn cung cấp một số phương thức khác, tương tự dành cho array. Đó là: _entries, every, filter, find, findIndex, keys, map, reduce, reduceRight, some, values._

###

Trả về một mảng đối tượng mới, chứa **key/value** cho mỗi phần tử trong array.

```js
a.entries();
```

Để duyệt mảng đối tượng mới này, mình sử dụng vòng lặp `for...of`:

```js
const a = ["a", "b", "c"];
const iterator = a.entries();

for (let e of iterator) {
  console.log(e);
}
/*
 * [0, 'a']
 * [1, 'b']
 * [2, 'c']
 */
```

Trả về `true` nếu như tất cả các phần tử trong mảng thoả mãn 1 hàm kiểm tra, ngược lại trả về `false`.

```js
  arr.every(callback[, thisArg])
```

Tham số truyền vào giống với hàm `forEach`.

Ví dụ sau trả về `true` nếu tất cả các phần tử trong mảng thoả mãn đều lớn hơn hoặc bằng 10:

```js
function isBigEnough(element, index, array) {
  return element >= 10;
}

console.log([12, 5, 8, 130, 44].every(isBigEnough)); // false
console.log([12, 54, 18, 130, 44].every(isBigEnough)); // true
```

Giống như cái tên của nó, phương thức này dùng để **lọc ra các phần tử trong mảng thoả mãn một điều kiện** cho trước và trả về một mảng mới chứa những phần tử đó.

```js
  let newArray = arr.filter(callback[, thisArg])
```

Tham số truyền vào giống với hàm `forEach`.

Ví dụ sau lọc ra những phần tử trong mảng có giá trị lớn hơn hoặc bằng 10:

```js
function isBigEnough(value) {
  return value >= 10;
}

const filtered = [12, 5, 8, 130, 44].filter(isBigEnough);
console.log(filtered);
// [12, 130, 44]
```

Trả về giá trị của **phần tử đầu tiên** trong mảng thoả mãn điều kiện cho trước, nếu không tìm thấy thì trả về `undefined`.

```js
    let var1 = arr.find(callback[, thisArg])
```

Tham số truyền vào cũng giống như hàm `forEach`.

Ví dụ sau tìm ra một [object](/bai-viet/javascript/object-la-gi-object-trong-javascript) với `name` thoả mãn điều kiện cho trước:

```js
const inventory = [
  { name: "apples", from: "usa" },
  { name: "bananas", from: "vietnam" },
  { name: "cherries", from: "usa" },
  { name: "cherries", from: "china" },
];

function findCherries(fruit) {
  return fruit.name === "cherries";
}

console.log(inventory.find(findCherries));
// {name: 'cherries', from: 'usa'}
```

Trả về **chỉ số đầu tiên** của phần tử thoả mãn điều kiện cho trước, ngược lại trả về `-1`.

```js
let id = arr.findIndex(callback[, thisArg])
```

Tham số truyền vào cũng giống như hàm `forEach`.

Ví dụ sau tìm ra chỉ số object với `name` thoả mãn điều kiện cho trước:

```js
const inventory = [
  { name: "apples", from: "usa" },
  { name: "bananas", from: "vietnam" },
  { name: "cherries", from: "usa" },
  { name: "cherries", from: "china" },
];

function findCherries(fruit) {
  return fruit.name === "cherries";
}

console.log(inventory.findIndex(findCherries));
// 2
```

Trả về mảng mới với mỗi phần tử là kết quả của việc gọi hàm callback với mỗi phần tử của mảng ban đầu.

```js
    let new_array = arr.map(callback[, thisArg])

```

Tham số truyền vào cũng giống như hàm `forEach` JavaScript.

Ví dụ sau trả về mảng mới, mà mỗi phần tử của mảng mới là **căn bậc hai** của phần tử tương ứng trong mảng ban đầu:

```js
const numbers = [1, 4, 9];
const roots = numbers.map(Math.sqrt);

console.log(roots); // [1, 2, 3]
console.log(numbers); // [1, 4, 9]
```

Những phương thức còn lại bạn có thể tham khảo thêm tại bài viết: [Các phương thức của mảng trong JavaScript](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array).

## Thực hành

### 1\. Flattening

Cho một mảng hai chiều, hãy chuyển mảng đó thành mảng một chiều, ví dụ:

```js
let arrays = [[1, 2, 3], [4, 5], [6]];
/*
 * Code xử lý
 *
 * Đáp án: [1, 2, 3, 4, 5, 6]
 */
```

► Sử dụng phương thức `arr.reduce()` và `arr.concat()`.

Đáp án

```js
const arrays = [[1, 2, 3], [4, 5], [6]];
const newArray = arrays.reduce(function (a, b) {
  return a.concat(b);
});
console.log(newArray);
// => [1, 2, 3, 4, 5, 6]
```

► Sử dụng [vòng lặp for, while](/bai-tap/javascript/vong-lap-trong-javascript) thông thường.

```js
const arrays = [[1, 2, 3], [4, 5], [6]];
const newArray = [];
for (let i = 0; i < arrays.length; i++) {
  const subArray = arrays[i];
  for (let j = 0; j < subArray.length; j++) newArray.push(subArray[j]);
}
console.log(newArray);
// => [1, 2, 3, 4, 5, 6]
```

### 2\. Every and some

Hãy viết hàm `every()` và `some()` thoả mãn:

- `every(arr, func)`: trả về `true` khi **tất cả** các phần tử của mảng `arr` làm hàm `func` trả về `true`, ngược lại thì trả về `false`.
- `some(arr, func)`: trả về `true` khi **ít nhất một** phần tử của mảng `arr` làm hàm `func` trả về `true`, ngược lại thì trả về `false`.

```js
console.log(every([NaN, NaN, NaN], isNaN));
// true
console.log(every([NaN, NaN, 4], isNaN));
// false
console.log(some([NaN, 3, 4], isNaN));
// true
console.log(some([2, 3, 4], isNaN));
// false
```

Xem đáp án:

- Hàm every

```js
function every(array, action) {
  for (let i = 0; i < array.length; i++) if (!action(array[i])) return false;
  return true;
}

console.log(every([NaN, NaN, NaN], isNaN));
// => true
console.log(every([NaN, NaN, 4], isNaN));
// => false
```

- Hàm some

```js
function some(array, action) {
  for (let i = 0; i < array.length; i++) if (action(array[i])) return true;
  return false;
}

console.log(some([NaN, 3, 4], isNaN));
// => true
console.log(some([2, 3, 4], isNaN));
// => false
```

## Tổng kết

Trên đây là một số kiến thức cơ bản về forEach trong JavaScript.

Hy vọng qua bài viết này bạn hiểu được forEach JavaScript là gì? Cách sử dụng forEach và khi nào nên sử dụng forEach JS.

Tham khảo: [Higher-Order Functions](https://eloquentjavascript.net/05_higher_order.html)
