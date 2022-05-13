---
title: "Kiểu dữ liệu string trong Javascript"
description: "String là kiểu dữ liệu chứa dữ liệu dưới dạng text(chữ). Kiểu string trong JavaScript cho phép bạn sử dụng cả ngoặc đơn và ngoặc kép để biểu diễn nó."
keywords: [
"kieu du lieu trong javascript",
"object trong javascript",
"kieu du lieu trong javascript",
"kieu du lieu string trong javascript",
"kieu du lieu text trong javascript",
"text trong javascript",
"thao tac voi text trong java script",
"Kiểu dữ liệu string trong Javascript là gì",
"Kiểu dữ liệu string trong Javascrip dùng như thế nào"
]
chapter:
  name: "Kiểu dữ liệu trong Javascript"
  slug: "chuong-04-kieu-du-lieu-trong-javascript"
category:
  name: "Javascript"
  slug: "javascript"
image: https://user-images.githubusercontent.com/29374426/168241987-e96c8d4c-c105-49ff-a02b-d9e4c27bf4ce.png
position: 3
---

Kiểu dữ liệu string trong JavaScript dùng để **lưu trữ giá trị dạng text**. Và không có kiểu dữ liệu đặc biệt nào cho một ký tự.

![Kiểu dữ liệu string trong Javascript](https://user-images.githubusercontent.com/29374426/168241987-e96c8d4c-c105-49ff-a02b-d9e4c27bf4ce.png)

Có **ba loại kí tự** dùng để biểu diễn string trong JavaScript là: dấu nháy đơn, dấu nháy kép và dấu "backtick", ví dụ:

```js
let singleQuote = "hello";
let doubleQuote = "hello";
let backticks = `hello`;
```

Trong đó, dấu nháy đơn và dấu nháy kép **hoàn toàn tương đương**. Còn dấu "backtick" thì khác hơn. Dấu "backtick" cho phép bạn viết biểu thức hoặc gọi hàm bên trong `${...}`, ví dụ:

```js
function add(a, b) {
  return a + b;
}

console.log(`Sum of 1 and 2 is ${add(1, 2)}`); // 3
```

Ứng dụng khác của dấu "backtick" là cho phép bạn viết string trên nhiều dòng:

```js
let userList = `Users:
    + Alex
    + John
    + Anna
    `;

console.log(userList);
```

Nếu viết string trên nhiều dòng với **dấu nháy đơn hoặc dấu nháy kép** theo cách tương tự thì bạn sẽ bị lỗi:

```js
let userList = "Users:
    + Alex
    + John
    + Anna
    ";

    // Uncaught SyntaxError: Invalid or unexpected token
```

## Biểu diễn kí tự đặc biệt

Thực tế, bạn vẫn có thể biểu diễn string trên nhiều dòng với **dấu nháy đơn hoặc dấu nháy kép** bằng cách sử dụng kí tự **newline** `\n`:

```js
let userList = "Users: \n+ Alex \n+ John \n+ Anna";

console.log(userList);

/*
    Users:
    + Alex
    + John
    + Anna
    */
```

Kí tự `\n` là một kí tự đặc biệt, có nghĩa là **newline** (dòng mới).

Sau đây là tổng hợp một số kí tự đặc biệt:

- `\n`: dòng mới
- `\r`: hệ điều hành Windows sử dụng tổ hợp `\r\n` để thể hiện **xuống dòng**. Trong khi các hệ điều hành khác Windows chỉ sử dụng kí tự `\n`.
- `\'` hoặc `\"`: dấu nháy đơn hoặc dấu nháy kép.
- `\\`: dấu backslash.
- `\t`: dấu tab.
- `\xXX`: biểu diễn kí tự unicode, trong đó `XX` là mã unicode ở hệ thập lục phân. Ví dụ: `\x7A` tương đương với `z`.
- `\uXXXX`: biểu diễn symbol unicode, trong đó `XXXX` là mã unicode ở hệ thập lục phân của symbol với UTF-16. Ví dụ: `\u00A9` tương đương với biểu tượng copyright `©`.
- `\u{X..XXX}` (từ 1 đến 6 kí tự): biểu diễn symbol unicode, trong đó `X..XXX` là mã unicode ở hệ thập lục phân của symbol với UTF-32.

Một vài ví dụ với unicode:

```js
console.log("\u00A9"); // ©
console.log("\u{20331}"); // 佫
console.log("\u{1F60D}"); // 😍
```

Tất cả các kí tự đặc biệt đều bắt đầu bằng kí tự `\`.

Ví dụ sử dụng dấu nháy đơn trong string:

```js
console.log("I'm a js dev"); // I'm a js dev
```

Dĩ nhiên, bạn có thể **kết hợp** các dấu nháy với nhau để tránh sử dụng kí tự `\`:

```js
console.log("I'm a js dev"); // I'm a js dev
```

Với cách viết này, string trở nên rõ ràng và trực quan hơn rất nhiều.

## Độ dài string trong JavaScript

Để lấy độ dài của string trong JavaScript, bạn sử dụng thuộc tính `length`:

```js
console.log(`Me\n`.length); // 3
```

<content-warning>

Kí tự `\n` là kí tự đặc biệt. Nên string `Me\n` chỉ có độ dài bằng 3, chứ không phải bằng 4.

`length` là thuộc tính chứ không phải phương thức. Vì vậy, nếu bạn gọi `"str".length()` thì sẽ bị lỗi **"str ".length is not a function**.

</content-warning>

## Truy cập các kí tự của string trong JavaScript

Để lấy giá trị của kí tự ở vị trí `position` trong string, bạn có thể dùng `str[position]` hoặc `str.charAt(position)` (vị trí bắt đầu là `0`):

```js
let str = "hello";

// Lấy kí tự đầu tiên
console.log(str[0]); // h

// Lấy kí tự cuối cùng
console.log(str[str.length - 1]); // o
```

Cách sử dụng `[]` là cách mới, trong khi cách dùng `charAt` là một cách cũ.

Điểm khác nhau giữa hai cách này là: nếu không tìm thấy vị trí `position` thì `[position]` trả về `undefined`, còn `charAt(position)` trả về string rỗng.

```js
let str = "hello";

console.log(str[1000]); // undefined
console.log(str.charAt(1000)); // ""
```

Để duyệt hết các kí tự trong string, bạn có thể dùng [vòng lặp for bình thường](/bai-viet/javascript/vong-lap-trong-javascript):

```js
let str = "hello";

for (let i = 0; i < str.length; i++) {
  console.log(str[i]);
}
```

Kết quả:

    h
    e
    l
    l
    o

Hoặc sử dụng vòng lặp `for...of` để ngắn gọn hơn:

```js
let str = "hello";

for (let c of str) {
  console.log(c);
}
```

## String trong JavaScript là bất biến

String trong JavaScript là **bất biến** vì bạn không thể thay đổi kí tự trong string.

```js
let str = "hello";
str[0] = "H";
console.log(str); // hello - string không thay đổi
```

Để giải quyết vấn đề này, bạn **bắt buộc phải tạo một string mới**.

Sau đây, mình sẽ tìm hiểu kỹ hơn về bài toán này.

## Thay đổi chữ hoa và thường

Có một số [phương thức](/bai-viet/javascript/phuong-thuc-cua-kieu-nguyen-thuy) giúp thay đổi chữ hoa và chữ thường của string trong JavaScript.

Phương thức [`toLowerCase()`](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/String/toLowerCase) trả về string mới với **tất cả các kí tự đều viết thường**:

```js
console.log("Hello".toLowerCase()); // hello
```

Phương thức [`toUpperCase()`](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/String/toUpperCase) trả về string mới với **tất cả các kí tự đều viết hoa**:

```js
console.log("Hello".toUpperCase()); // HELLO
```

## Tìm kiếm substring

Có nhiều cách để tìm kiếm substring (string con) trong một string.

► Phương thức [`str.indexOf(substr, pos)`](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/String/indexOf):

Phương thức này tìm kiếm `substr` bên trong string `str` bắt đầu từ vị trí `pos`. Kết quả trả về là vị trí của substring (vị trí kí tự đầu tiên) nếu tìm thấy, ngược lại thì trả về -1, ví dụ:

```js
let str = "I am a js dev";

console.log(str.indexOf("js")); // 7
console.log(str.indexOf("JS")); // -1 vì không tìm thấy
console.log(str.indexOf("a")); // 2 - vị trí đầu tiên tìm thấy
```

Tham số thứ hai `pos` cho phép bạn xác định vị trí bắt đầu tìm kiếm:

```js
let str = "I am a js dev";
console.log(str.indexOf("a", 3)); // 5 - vị trí đầu tiên tìm thấy bắt đầu từ 3
```

Nếu bạn muốn **tìm tất cả vị trí của substring**, bạn có thể sử dụng vòng lặp. Khi tìm thấy một vị trí, bạn lưu lại ví trí đó để sử dụng cho lần lặp tiếp theo. Cho đến khi kết quả là `-1` thì dừng lại.

```js
let str = "I am a js dev";
let target = "a";

let pos = 0;
while (true) {
  let foundPos = str.indexOf(target, pos);
  if (foundPos === -1) break;

  console.log("found pos:", foundPos);
  pos = foundPos + 1;
}
```

► Phương thức [`str.lastIndexOf(substr, pos)`](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/String/lastIndexOf)

Tương tự như phương thức `str.indexOf(substr, pos)` nhưng thực hiện **tìm kiếm từ cuối lên đầu**, ví dụ:

```js
let str = "I am a js dev";
console.log(str.lastIndexOf("a")); // 5 - vị trí đầu tiên tìm thấy tính từ cuối
```

► Phương thức [`str.includes(substr, pos)`](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/String/includes)

Phương thức này cũng tìm `substr` trong `str`, nhưng thay vì trả về vị trí thì phương thức này trả về `true` nếu tìm thấy và trả về `false` nếu không tìm thấy.

Phương thức này đặc biệt hữu ích khi bạn cần kiểm tra tính tồn tại của substring mà không quan tâm vị trí:

```js
let str = "I am a js dev";
console.log(str.includes("js")); // true
console.log(str.includes("JS")); // false
```

Tham số thứ hai `pos` cho phép bạn kiểm tra tính tồn tại bắt đầu từ vị trí `pos`:

```js
let str = "I am a js dev";
console.log(str.includes("js", 1)); // true
console.log(str.includes("js", 9)); // false
```

► Phương thức [`str.startsWith(substr)`](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/String/startsWith)

Trả về `true` nếu `str` **bắt đầu** bằng `substr`, ngược lại trả về `false`.

```js
let str = "I am a js dev";
console.log(str.startsWith("I am")); // true
console.log(str.startsWith("js")); // false
```

► Phương thức [`str.endsWith(substr)`](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/String/endsWith)

Trả về `true` nếu `str` **kết thúc** bằng `substr`, ngược lại trả về `false`.

```js
let str = "I am a js dev";
console.log(str.endsWith("I am")); // false
console.log(str.endsWith("dev")); // true
```

## Lấy giá trị substring trong string

Có **ba phương thức** để lấy giá trị substring của string trong JavaScript.

► Phương thức [`str.slice(start [, end])`](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/String/slice)

Trả về substring bắt đầu từ vị trí `start` đến vị trí `end` (không bao gồm vị trí `end` và `start` luôn phải nhỏ hơn `end`), ví dụ:

```js
let str = "I am a js dev";
console.log(str.slice(2, 4)); // am
```

Nếu không truyền vào giá trị `end` thì phương thức này sẽ lấy đến cuối string:

```js
let str = "I am a js dev";
console.log(str.slice(2)); // am a js dev
```

Trường hợp giá trị của `start` và `end` là số âm thì vị trí được đếm từ cuối lên đầu (vị trí cuối cùng ứng với `-1`):

```js
let str = "I am a js dev";
console.log(str.slice(-3, -1)); // de
```

► Phương thức [`str.substring(start [, end])`](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/String/substring)

Trả về substring trong string giữa vị trí `start` và vị trí `end` (không bao gồm vị trí `end`).

Phương thức này gần giống phương thức `str.slice(start, [, end])` chỉ khác ở chỗ là: phương thức `substring` cho phép `start` có thể lớn hơn `end` và `substring` không áp dụng được cho trường hợp `start`, `end` có giá trị âm, ví dụ:

```js
let str = "I am a js dev";

// trường hợp bình thường
console.log(str.substring(2, 4)); // am

// trường hợp không có end
console.log(str.substring(2)); // am a js dev

// trường hợp start lớn hơn end
console.log(str.substring(4, 2)); // am
```

► Phương thức [`str.substr(start [, length])`](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/String/substr)

Trả về substring bắt đầu từ vị trí `start` và lấy số kí tự là `length`.

```js
let str = "I am a js dev";
console.log(str.substr(2, 2)); // am - bắt đầu từ vị trí 2, lấy 2 kí tự
```

Trường hợp không có giá trị `length` thì trả về đến string:

```js
let str = "I am a js dev";
console.log(str.substr(2)); // am a js dev - trả về đến hết string
```

Nếu giá trị `start` là âm, thì việc lấy substring được tính từ cuối (vị trí kí tự cuối cùng là `-1`):

```js
let str = "I am a js dev";
console.log(str.substr(-2, 2)); // ev
```

<content-info>

💡 Trong ba phương thức trên thì phương thức `slice` có vẻ linh động hơn cả, vì nó ngắn gọn, dễ nhớ và hỗ trợ tham số âm.

Phương thức `substr` thì đã bị lỗi thời.

</content-info>

## So sánh string trong JavaScript

So sánh string thực hiện so sánh từng kí tự từ trái sang phải. Và khi so sánh string, bạn thấy rằng **kí tự viết thường** lớn hơn **kí tự viết hoa**, ví dụ:

```js
console.log("a" > "A"); // true
```

**Tại sao lại như vậy?**

Vì string trong JavaScript được encode bằng UTF-16. Nghĩa là mỗi kí tự tương ứng với một số.

Sau đây là những phương thức giúp bạn chuyển đổi string sang số unicode và ngược lại.

► Phương thức [`str.codePointAt(pos)`](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/String/codePointAt)

Trả về mã code (số) tương ứng với kí tự tại vị trí `pos`, ví dụ:

```js
console.log("a".codePointAt(0)); // 97
console.log("A".codePointAt(0)); // 65
```

Bạn thấy rằng mã code ứng với `"a"` (bằng `97`) lớn hơn của `"A"` (bằng 65).

► Phương thức [`String.fromCodePoint(code)`](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/String/fromCodePoint)

Trả về kí tự ứng với mã code, ví dụ:

```js
console.log(String.fromCodePoint(97)); // a
console.log(String.fromCodePoint(65)); // A
```

Bạn cũng có thể sử dụng mã Unicode bằng cách thêm kí tự `\u` trước mã hexa:

```js
console.log("\u0061"); // a - mã hexa của a là 61
console.log("\u0041"); // A - mã hexa của A là 41
```

Thực tế, việc so sánh string phức tạp hơn nhiều vì nó còn phụ thuộc vào ngôn ngữ vùng miền.

Ví dụ so sánh tiếng việt:

```js
let str1 = "Hải Dương";
let str2 = "Hòa Bình";

console.log(str1 > str2); // true
```

Theo ví dụ trên, kết quả `str1 > str2` bằng `true`. Nghĩa là `str1` lớn hơn `str2`.

Nhưng theo thực tế khi sắp xếp Tiếng Việt, chữ cái `a` bao giờ cũng đứng trước chữ cái `o`. Nói cách khác **Hải Dương** phải nhỏ hơn **Hòa Bình**.

Để giải quyết vấn đề này, bạn có thể dùng phương thức [`localeCompare`](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/String/localeCompare).

Đối với `str1.localeCompare(str2)`, có ba trường hợp xảy ra là:

- Nếu kết quả trả về nhỏ hơn `0` thì `str1` nhỏ hơn `str2`.
- Nếu kết quả trả về lớn hơn `0` thì `str1` lớn hơn `str2`.
- Nếu kết quả trả về bằng `0` thì `str1` bằng `str2`.

Áp dụng `localeCompare` với ví dụ trên:

```js
let str1 = "Hải Dương";
let str2 = "Hòa Bình";

console.log(str1.localeCompare(str2)); // -1
```

Kết quả là `-1` (nhỏ hơn `0`). Nói cách khác, `str1` nhỏ hơn `str2`.

## Tổng kết

Sau đây là những kiến thức cơ bản về string trong JavaScript:

- Có **ba loại kí tự** dùng để biểu diễn string trong JavaScript là: nháy đơn, nháy kép và "backtick".

```js
"hello"; // nháy đơn
"hello"; // nháy kép
`hello`; // backtick
```

- String trong JavaScript được encode bởi mã UTF-16.
- Bạn có thể sử dụng kí tự đặc biệt trong string bằng cách thêm kí tự `\` phía trước.
- Để truy cập vào kí tự ở vị trí `pos` trong string, bạn có thể dùng `str[pos]` hoặc `str.charAt(pos)`.
- Để trả về string gồm các kí tự viết thường (hoặc viết hoa), bạn dùng `str.toLowerCase` (hoặc `str.toUpperCase`).
- Để lấy substring, bạn sử dụng `slice` hoặc `substring`.
- Để tìm kiếm substring trong string, bạn dùng `indexOf`.
- Để kiểm tra tính tồn tại của substring, bạn sử dụng `includes`, `startsWith` hoặc `endsWith`.
- Để so sánh string dựa trên đặc trưng ngôn ngữ vùng miền, bạn có thể dùng `localeCompare`. Nếu so sánh string bình thường thì kết quả chỉ dựa trên mã unicode tương ứng.

Ngoài ra, string còn nhiều phương thức khác nữa. Bạn có thể tham khảo thêm tại:

- [MDN String](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/String)
- [Strings](https://javascript.info/string)

## Thực hành

### Bài 1

Viết hàm `upperFirst(str)` nhận vào tham số là string `str` và trả về string mới với kí tự đầu tiên được viết hoa, ví dụ:

```js
let s = upperFirst("hello");
console.log(s); // Hello
```

Xem đáp án

```js
// định nghĩa hàm
function upperFirst(str) {
  // nếu tham số truyền vào là empty thì trả về chính nó
  if (!str) return str;

  return str[0].toUpperCase() + str.slice(1);
}

let s = upperFirst("hello");
console.log(s); // Hello
```

### Bài 2

Viết hàm `extractMoney(value)` nhận vào `value` là string biểu diễn tiền với đơn vị đô la `$` ở đầu (ví dụ `"$1000"`) và trả về số tiền (ví dụ `1000`).

Xem đáp án

```js
// định nghĩa hàm
function extractMoney(str) {
  if (!str) return 0;

  return +str.slice(1);
}

let money = extractMoney("$1000");
console.log(money); // 1000
```
