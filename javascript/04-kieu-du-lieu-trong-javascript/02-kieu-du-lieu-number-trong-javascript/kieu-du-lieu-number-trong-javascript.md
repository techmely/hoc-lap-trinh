---
title: "Kiểu dữ liệu number trong Javascript"
description: "Number trong JavaScript dùng cho cả số nguyên (integer) và số thực (float), và luôn là số có dấu (signed). Kiểu dữ liệu được xác định trên giá trị gán cho nó (value) chứ không cần chỉ định rõ ràng. Vì không phân biệt số nguyên và số thực, nên có thể viết số nguyên dạng có chấm hoặc không chấm như nhau."
keywords: [
"cac kieu du lieu trong javascript",
"Kiểu dữ liệu number trong Javascript",
"kiem tra kieu du lieu trong javascript",
"kiểu dữ liệu javascript",
"kieu du lieu javascript",
"Các kiểu dữ liệu trong JavaScript",
"kiểu dữ liệu trong javascript",
"number trong javascript",
"int trong savascript",
"float trong javascript"
]
chapter:
  name: "Kiểu dữ liệu trong Javascript"
  slug: "chuong-04-kieu-du-lieu-trong-javascript"
category:
  name: "Javascript"
  slug: "javascript"
image: https://user-images.githubusercontent.com/29374426/168241811-a6e5438e-3e6f-4e15-b87b-ab20aaba0691.png
position: 2
---

![Kiểu dữ liệu number trong Javascript](https://user-images.githubusercontent.com/29374426/168241811-a6e5438e-3e6f-4e15-b87b-ab20aaba0691.png)

Có hai kiểu dữ liệu liên quan đến **number trong JavaScript** là: number thông thường và bigInt.

1.  Number thông thường được lưu dưới dạng **số thực dấu phẩy động** theo chuẩn [IEEE-754](https://vi.wikipedia.org/wiki/S%E1%BB%91_th%E1%BB%B1c_d%E1%BA%A5u_ph%E1%BA%A9y_%C4%91%E1%BB%99ng#IEEE_754:_chu%E1%BA%A9n_d%E1%BA%A5u_ph%E1%BA%A9y_%C4%91%E1%BB%99ng_trong_m%C3%A1y_t%C3%ADnh_ng%C3%A0y_nay) với **độ chính xác kép**.
2.  BigInt là kiểu dữ liệu dùng để biểu diễn **số nguyên với độ dài tùy ý**. Số bigInt được sử dụng trong một số trường hợp cần biểu diễn số nguyên lớn. Vì số thông thường không thể lớn hơn `253` và nhỏ hơn `-253`.

Kiểu **bigInt** là kiểu số đặc biết nên mình sẽ tìm hiểu sau. Bài viết này chỉ tập trung vào **number thông thường**.

## Cách khác để biểu diễn number trong JavaScript

Giả sử bạn cần biểu diễn số 1 tỷ:

```js
let oneBillion = 1000000000;
```

Nếu bạn chỉ nhìn qua thì rất khó nhận biết đó là số 1 tỷ. Có thể bạn sẽ phải **đếm xem có bao nhiêu số 0** trong đó.

Thay vì phải đếm như vậy, JavaScript cho phép bạn sử dụng kí tự gạch chân `_` để phân tách các chữ số:

```js
let oneBillion = 1_000_000_000;
```

Rõ ràng cách viết này **dễ nhìn hơn**. Và kết quả thì vẫn không thay đổi. Vì JavaScript engine sẽ bỏ qua, không xử lý kí tự `_` trong number.

Trong thực tế cuộc sống, chúng ta thường không muốn viết hết các chữ số `0` mà thường viết tắt, ví dụ: 1000 thành 1K, 1000000 thành 1M,...

Với JavaScript cũng vậy, bạn có thể dùng chữ cái `e` để biểu diễn số lượng chữ số `0`, ví dụ:

```js
let a = 1e3; // 1_000 - 1 nghìn
let b = 1e6; // 1_000_000 - 1 triệu
let c = 1e9; // 1_000_000_000 - 1 tỷ
let d = 4.6e9; // 4_600_000_000 - 4.6 tỷ
```

Nói cách khác, `eN` thực hiện **nhân số** (trước `e`) bởi với số **10 mũ N**.

```js
1e3 === 1 * 1000; // e3 tương đương *1000
1.23e4 === 1.23 * 10000; // e4 tương đương *10000
```

Tương tự, bạn cũng có thể dùng `e` để biểu diễn những số rất nhỏ bằng cách thay `N` ở trên bằng số âm:

```js
0.000001 === 1e-6;
```

Nói cách khác, `e-N` thực hiện **chia số** (trước `e`) bởi số **10 mũ N**.

```js
1e-3 === 1 / 1000; // e3 tương đương /1000
1.23e-4 === 1.23 / 10000; // e4 tương đương /10000
```

### Biểu diễn số ở hệ cơ số 16, 8 và 2

Các số mình thường viết trên đây là biểu diễn ở hệ thập phân (cơ số 10). Ngoài ra, bạn có thể biểu diễn number trong JavaScript ở hệ thập lục phân (cơ số 16), bát phân (cơ số 8) và nhị phân (cơ số 2).

- Hệ thập lục phân sử dụng tiền tố là `0x`.
- Hệ bát phân sử dụng tiền tố là `0o`.
- Hệ nhị phân sử dụng tiền tố là `0b`.

<content-example>

biểu diễn số ở hệ 16, 8 và 2 là:

</content-example>

```js
// Hệ cơ số 16
console.log(0xff); // 255
console.log(0xff); // 255 - không phân biệt hoa thường

// Hệ cơ số 8
console.log(0o377); // 255

// Hệ cơ số 2
console.log(0b11111111); // 255
```

Phương thức `num.toString(base)` trả về string biểu diễn số `num` ở hệ cơ số `base`, ví dụ:

```js
let num = 255;

// chuyển sang hệ cơ số 16
console.log(num.toString(16)); // ff

// chuyển sang hệ cơ số 2
console.log(num.toString(2)); // 11111111
```

Trong đó, `base` có giá trị nằm trong đoạn **từ 2 đến 36**. Mặc định, `base` là **10**.

Một số trường hợp phổ biến:

- `base=16` hay dùng để biểu diễn **mã màu hexa**, string đã được encode,... với các chữ số từ `0..9` hoặc `A-F` (không phân biệt hoa thường).
- `base=2` thường dùng để debug các số sử dụng trong [toán tử bitwise](/bai-viet/javascript/toan-tu-trong-javascript)... với các chữ số là `0` hoặc `1`.
- `base=36` là giá trị lớn nhất, thường được dùng để biểu diễn các số dài thành dạng ngắn gọn hơn, với các chữ số từ `0..9` và `A..Z`, ví dụ:

```js
console.log((1234567890).toString(36)); // kf12oi
```

<content-warning>

cách viết dùng hai dấu chấm `..` như trên **không phải lỗi chính tả**. Nếu bạn muốn gọi [phương thức của number](/bai-viet/javascript/phuong-thuc-cua-kieu-nguyen-thuy), ví dụ `toString()`, bạn cần phải dùng **hai dấu chấm**

</content-warning>

Nếu bạn dùng **một dấu chấm** thì sẽ có lỗi cú pháp:

```js
console.log(1234567890.toString(36));
    // Uncaught SyntaxError: Invalid or unexpected token
```

Bởi vì, JavaScript hiểu rằng sau dấu `.` đầu tiên là **phần thập phân** của số thực. Mà đằng sau `.` lại là `toString` thì chắc chắn sai cú pháp.

Ngược lại, khi bạn viết hai dấu chấm `..`, JavaScript ngầm định phần thập phân là **rỗng**, rồi sau đó đến phương thức.

Nói cách khác, cách viết hai dấu chấm `..` tương đương với cách viết sử dụng `()` như sau:

```js
//console.log(1234567890..toString(36)); // kf12oi
console.log((1234567890).toString(36)); // kf12oi
```

<content-info>

Để code rõ ràng và an toàn hơn, bạn nên sử dụng `()`

</content-info>

## Làm tròn number trong JavaScript

Một trong những phép toán **hay sử dụng với number** trong JavaScript nhất là **làm tròn số**. JavaScript có sẵn một số hàm giúp bạn làm tròn số như:

► `Math.floor`:

Từ **floor** dịch ra là **sàn nhà** - suy ra hàm `Math.floor` dùng để **làm tròn xuống**. Ví dụ: `3.1` trở thành `3` và `-1.1` trở thành `-2`.

► `Math.ceil`:

Từ **ceil** dịch ra là **trần nhà** - suy ra hàm `Math.ceil` dùng để **làm tròn lên**. Ví dụ: `3.1` trở thành `4` và `-1.1` trở thành `-1`.

► `Math.round`:

Hàm này trả về **số nguyên gần nhất** (có thể làm tròn lên hoặc làm tròn xuống). Ví dụ: `3.1` trả về `3`, `3.6` trở thành `4` và giá trị ở giữa `3.5` cũng trở thành `4`.

► `Math.trunc` (không hỗ trợ bởi trình duyệt **IE**):

Hàm này trả về số nguyên bằng cách xóa bỏ đi tất cả thành phần sau dấu phẩy. Ví dụ: `3.1` trở thành `3` và `-1.1` trở thành `-1`.

Trên đây là những hàm giúp **làm tròn thành số nguyên**. Vậy làm sao để **làm tròn thành số thực** với chính xác `n` chữ số sau dấu phẩy.

<content-example>

làm sao để làm tròn số `1.2345` thành `1.23` (2 chữ số sau dấu phẩy)?

</content-example>

Có **hai cách** để giải quyết vấn đề trên.

1.  Phương pháp **nhân-rồi-chia**:

Ví dụ để làm tròn 2 chữ số sau dấu phẩy, bạn nhân số ban đầu với `100` (2 chữ số `0`). Sau đó, bạn dùng `Math.round` để làm tròn kết quả về số nguyên gần nhất. Cuối cùng, bạn chia kết quả cho `100` sẽ thu được kết quả như mong muốn.

```js
let a = 1.2345;

// a nhân với 100
let b = a * 100; // 123.45

// làm tròn b với Math.round
let c = Math.round(b); // 123

// chia c cho 100
let d = c / 100; // bằng 123 / 100

console.log(d); // 1.23
```

2.  Sử dụng phương thức `toFixed(n)`:

Phương thức này sẽ làm tròn số và **trả về string** với chính xác `n` chữ số sau dấu phẩy.

```js
let a = 1.2345;
let b = a.toFixed(2);
console.log(b); // "1.23"
```

Trường hợp phần thập phân không đủ `n` chữ số thì phương thức `toFixed(n)` tự động thêm các chữ số `0` phía sau cho đủ `n` chữ số.

```js
let a = 1.2345;
let b = a.toFixed(6);
console.log(b); // "1.234500"
```

Để [chuyển đổi kiểu dữ liệu](/bai-viet/javascript/chuyen-doi-kieu-du-lieu-trong-javascript) string về number, bạn có thể dùng hàm `Number()` hoặc toán tử một ngôi `+`, ví dụ:

```js
let a = 1.2345;
let b = a.toFixed(2); // "1.23"

let c = Number(b);
console.log(c, typeof c); // 1.23 number
```

## Sai số với number trong JavaScript

Trong JavaScript, số thông thường được biểu diễn dưới dạng số thực dấu phẩy động theo chuẩn **IEEE-754**. Định dạng này sử dụng **64 bit** để lưu trữ một số, trong đó:

- **52 bit** dùng để lưu trữ các chữ số phần nguyên.
- **11 bit** để lưu trữ phần thập phân.
- **1 bit** để lưu trữ dấu (`0` - số dương và `1` - số âm).

Nếu một số quá lớn, **vượt ngoài khả năng biểu diễn của 64 bit** thì sẽ trở thành `Infinity` hoặc `-Infinity`:

```js
console.log(1e500); // Infinity
console.log(-1e500); // -Infinity
```

Đối với các số thực, một vấn đề thường xuyên xảy ra là **sự sai số**.

Một ví dụ kinh điển:

```js
console.log(0.1 + 0.2 === 0.3); // false
```

Kết quả là `false` vì thực tế `0.1 + 0.2` bằng số khác:

```js
console.log(0.1 + 0.2); // 0.30000000000000004
```

Hiểu đơn giản là: khi **biểu diễn số thực dưới dạng nhị phân** trong máy tính, không có cách nào để biểu diễn chính xác số `0.1` và `0.2`. Dẫn đến kết quả bị sai số như trên.

Ví dụ mình sử dụng phương thức `toFixed(20)` để xem giá trị thực sự của các số thế nào:

```js
console.log((0.1).toFixed(20)); // 0.10000000000000000555
console.log((0.2).toFixed(20)); // 0.20000000000000001110
```

Rõ ràng là chúng không thực sự bằng `0.1` và `0.2`.

Để giải quyết vấn đề này, bạn có thể sử dụng phương pháp **nhân-rồi-chia** hoặc phương thức `toFixed(1)` như mình đã đề cập ở trên:

```js
let a = 0.1;
let b = 0.2;

// Sử dụng nhân-rồi-chia
let sum1 = (a * 10 + b * 10) / 10;
console.log(sum1); // 0.3

// Sử dụng toFixed(1)
let sum2 = (a + b).toFixed(1);
console.log(sum2); // 0.3
```

## Kiểm tra số với `isNaN` và `isFinite`

Để kiểm tra number trong JavaScript, bạn có thể dùng một trong hai hàm là: `isNaN` hoặc `isFinite`.

► Hàm`isNaN(value)`:

Hàm này chuyển đổi `value` thành dạng số rồi kiểm tra xem có bằng `NaN` hay không.

```js
console.log(isNaN(NaN)); // true
console.log(isNaN(1)); // false
console.log(isNaN("1")); // false - "1" chuyển sang số thành 1
console.log(isNaN("abc")); // true - "abc" không thể chuyển thành số
```

Vấn đề là hàm `isNaN` có thật sự cần thiết hay không?

Câu trả lời là **CÓ**. Bởi vì giá trị `NaN` là duy nhất. `NaN` không bằng bất kỳ giá trị nào khác:

```js
let a = NaN;
let b = NaN;

console.log(a === a); // false
console.log(a === b); // false
```

Nghĩa là bạn không thể dùng toán tử so sánh bằng `===` để so sánh số với `NaN`.

► Hàm `isFinite(value)`:

Hàm này chuyển đổi giá trị `value` thành dạng số và trả về `true` nếu số đó khác `Infinity`, `-Infinity` và `NaN`, ngược lại thì trả về `false`.

```js
console.log(isFinite("1")); // true - "1" chuyển thành 1
console.log(isFinite("abc")); // false - "abc" chuyển sang số thành NaN
console.log(isFinite(1e500)); // false - 1e500 bằng Infinity
```

Hàm `isFinite(value)` cũng thường dùng để kiểm tra một giá trị string có phải là số bình thường hay không.

Ví dụ khi nhập vào một số với [hàm `prompt`](/bai-viet/javascript/ham-tuong-tac-voi-nguoi-dung-alert-confirm-prompt):

```js
let num = +prompt("Nhập vào một số:", "");

// trả về true
// trừ khi người dùng nhập vào Infinity, -Infinity hoặc không phải number
console.log(isFinite(num));
```

<content-info>

**String rỗng hoặc string toàn dấu cách** chuyển sang dạng số thành số `0`.

Để so sánh hai number trong JavaScript, bạn cũng có thể dùng phương thức [`Object.is`](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Object/is):

1.  Phương thức này sử dụng được với `NaN`: `Object.is(NaN,NaN)` bằng `true`.
2.  Hai giá trị `0` và `-0` là khác nhau: `Object.is(0,-0)` bằng `false`. Bởi vì JavaScript sử dụng 1 bit để biểu diễn dấu (`0` - số dương và `1` - số âm), nên hai giá trị `0` và `-0` khác nhau.

Trong hầu hết các trường hợp, phương thức `Object.is` tương đương với so sánh bằng nghiêm ngặt `===`.

</content-info>

## Hàm `parseInt` và hàm `parseFloat`

Có thể bạn đã biết hai cách để chuyển đổi string thành dạng số là:

- Sử dụng hàm `Number()`.
- Sử dụng toán tử một ngôi `+`.

<content-example/>

```js
console.log(Number("1.23")); // 1.23
console.log(+"1.23"); // 1.23
```

Tuy nhiên, nếu trong string chứa kí tự không phải dạng số thì kết quả là `NaN`:

```js
console.log(Number("100px")); // NaN
console.log(+"100px"); // NaN
```

Thực tế, có một số trường hợp string chứa **cả số và đơn vị** phía sau như `100px`, `10rem`, `1.1em`,... Làm sao để tách lấy phần số từ các string này?

Trong JavaScript, bạn có thể sử dụng hai hàm `parseInt` và `parseFloat`. Hai hàm này sẽ đọc string từ trái sang phải cho đến khi gặp kí tự không thỏa mãn thì dừng lại.

- Hàm `parseInt` tách lấy số nguyên.
- Hàm `parseFloat` tách lấy số thực.

Một số ví dụ:

```js
console.log(parseInt("100px")); // 100
console.log(parseFloat("1.1em")); // 1.1

console.log(parseInt("1.2")); // 1
console.log(parseFloat("1.2.3")); // 1.2
```

Nếu không thể tách được số nào thì `parseInt` và `parseFloat` trả về `NaN`:

```js
console.log(parseInt("$100")); // NaN
console.log(parseFloat("$100")); // NaN
```

<content-warning>

hàm `parseInt(value, radix)` có tham số thứ hai `radix` biểu diễn hệ cơ số (từ `2` đến `36`)

</content-warning>

Ví dụ tách lấy số nguyên ở các hệ cơ số khác nhau:

```js
console.log(parseInt("0xff", 16)); // 255
console.log(parseInt("ff", 16)); // 255 - có thể bỏ qua phần tiền tố

console.log(parseInt("kf12oi", 36)); // 1234567890
console.log(parseInt("100", 2)); // 4
```

## Một số hàm toán học

Ngoài các phương thức `Math.floor`, `Math.ceil`, `Math.round` và `Math.trunc` đã trình bày ở trên, đối tượng `Math` còn có các phương thức khác giúp bạn thực hiện một số hàm toán học.

► `Math.random()`

Phương thức này trả về một giá trị ngẫu nhiên từ `0` đến `1` (không bao gồm `1`), ví dụ:

```js
console.log(Math.random()); // 0.7097565480172887
console.log(Math.random()); // 0.6064789549780443
console.log(Math.random()); // 0.730830858416105
```

► `Math.max(a, b, c,...)` và `Math.min(a, b, c,...)`

Hai phương thức này trả về giá trị lớn nhất (nhỏ nhất) từ một dãy số đầu vào.

```js
console.log(Math.max(1, 3.2, -1, 10, 4)); // 10
console.log(Math.min(1, 3.2, -1, 10, 4)); // -1
```

► `Math.pow(n, base)`

Trả về số `n` mũ `base`.

```js
console.log(Math.pow(2, 3)); // 8 - vì bằng 2 mũ 3
```

Đối tượng `Math` còn rất nhiều phương thức hữu ích khác. Bạn có thể tham khảo thêm tại bài viết: [Math](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Math).

## Tổng kết

Sau đây là một số kiến thức về number trong JavaScript.

Bạn có thể dùng kí tự `_` để ngăn cách các chữ số cho dễ nhìn. Ví dụ `1_000_000_000` tương đương `1000000000`.

Trường hợp có nhiều chữ số `0` đằng sau, bạn có thể dùng kí tự `e` theo sau là một số `N` để biểu diễn:

- Với `N` dương thì `eN` tương đương nhân với **10 mũ N**, ví dụ: `2e6` bằng `2000000`.
- Với `N` âm thì `eN` tương đương chia cho **10 mũ N**, ví dụ: `2e-6` bằng `0.000002`.

JavaScript hỗ trợ biểu diễn số ở hệ cơ số khác:

- Hệ cơ số 16 sử dụng tiền tồ `0x`.
- Hệ cơ số 8 sử dụng tiền tố `0o`.
- Hệ cơ số 2 sử dụng tiền tố `0b`.

Để chuyển một số sang string với hệ cơ số tương ứng, bạn dùng `num.toString(base)`, với `base` là hệ cơ số có giá trị từ `2` đến `36`.

Để kiểm tra xem một số có phải `NaN` hay không, bạn dùng hàm `isNaN`. Hàm `isNaN(value)` chuyển giá trị `value` thành dạng số, rồi trả về `true` nếu số đó là `NaN`, ngược lại thì trả về `false`.

Để kiểm tra xem một số có phải số thông thường hay không, bạn dùng `isFinite`. Hàm `isFinite(value)` chuyển giá trị `value` thành dạng số, rồi trả về `true` nếu số đó khác `Infinity`, `-Infinity` và `NaN`.

Để chuyển đổi string thành dạng số, bạn có thể dùng hàm `parseInt` hoặc hàm `parseFloat`. Cả hai hàm này đều đọc string từ trái sang phải cho đến khi gặp kí tự không thỏa mãn thì dừng lại:

- Hàm `parseInt`: tách lấy phần số nguyên.
- Hàm `parseFloat`: tách lấy phần số thực.

Đối tượng `Math` có các phương thức giúp bạn thực hiện các phép toán số học với number trong JavaScript như:

- Làm tròn số: `Math.floor`, `Math.ceil`, `Math.round` và `Math.trunc`.
- Tìm số ngẫu nhiên: `Math.random`.
- Tìm giá trị lớn nhất / nhỏ nhất: `Math.max`, `Math.min`.
- Tính lũy thừa: `Math.pow`.
- ...

## Thực hành

### Bài 1

Viết code thực hiện yêu cầu sau:

1.  Dùng hàm [`prompt`](/bai-viet/javascript/ham-tuong-tac-voi-nguoi-dung-alert-confirm-prompt) yêu cầu người dùng nhập vào hai số.
2.  Tính và hiển thị tổng hai số.

Xem đáp án

```js
// 1. Dùng hàm `prompt` yêu cầu người dùng nhập vào hai số.
let a = +prompt("Nhập vào số thứ nhất:", 0);
let b = +prompt("Nhập vào số thứ hai:", 0);

// 2. Tính và hiển thị tổng hai số.
console.log(a + b);
```

### Bài 2

Viết hàm `readNumber` thực hiện yêu cầu sau:

1.  Dùng hàm `prompt` hỏi người dùng để nhập vào số.
2.  Nếu người dùng nhập vào số bình thường thì dừng lại và trả về số đó.
3.  Ngược lại, nếu người dùng không nhập vào số bình thường thì tiếp tục hỏi.

Xem đáp án

```js
// định nghĩa hàm
function readNumber() {
  while (true) {
    // yêu cầu người dùng nhập vào số
    let n = prompt("Nhập vào số:", 0);

    // kiểm tra điều kiện không phải số bình thường
    if (n === "" || n === null || n === undefined || !isFinite(n)) {
      continue;
    }

    return +n;
  }
}

// gọi hàm
let n = readNumber();
console.log(n);
```

Tham khảo:

- [Numbers](https://javascript.info/number)
- [Số thực dấu phẩy động IEEE-7554](https://vi.wikipedia.org/wiki/S%E1%BB%91_th%E1%BB%B1c_d%E1%BA%A5u_ph%E1%BA%A9y_%C4%91%E1%BB%99ng#IEEE_754:_chu%E1%BA%A9n_d%E1%BA%A5u_ph%E1%BA%A9y_%C4%91%E1%BB%99ng_trong_m%C3%A1y_t%C3%ADnh_ng%C3%A0y_nay)
