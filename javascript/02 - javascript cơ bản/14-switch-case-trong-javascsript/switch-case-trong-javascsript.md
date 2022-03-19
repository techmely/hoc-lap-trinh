---
title: "Switch case trong Javascript"
description: "Switch case trong Javascript"
keywords: [
"khoá học javascript",
"Switch case trong Javascript",
"Switch case trong Javascript cach su dung",
"lenh switch case trong javascript",
"lệnh switch case trong javascript",
"switch case trong js",
"câu lệnh switch case",
"switch case cơ bản trong javascript"
]
chapter:
  name: "Javascript cơ bản"
  slug: "chuong-02-javascript-co-ban"
category:
  name: "Javascript"
  slug: "javascript"
image: https://kungfutech.edu.vn/thumbnail.png
position: 14
---

Trong bài viết về [cấu trúc rẽ nhánh trong JavaScript](/bai-viet/khoa-hoc-javascript/cau-truc-re-nhanh-trong-javascript/), mình đã tìm hiểu về câu lệnh `if` và toán tử `?`. Ngoài ra, mình cũng có thể sử dụng **lệnh switch case** làm cấu trúc rẽ nhánh thay thế cho câu lệnh `if`.

Sau đây, mình cùng tìm hiểu về cách sử dụng câu lệnh switch - case trong JavaScript và khi nào thì nên sử dụng cấu trúc rẽ nhánh switch - case.

## Lệnh switch case là gì?

Câu lệnh switch - case trong JavaScript là một cấu trúc rẽ nhánh dùng để **xác định một danh sách các trường hợp và khối lệnh tương ứng với mỗi trường hợp**.

Khi giá trị đang xét **bằng nghiêm ngặt** (`===`) với trường hợp nào thì khối lệnh tương ứng bắt đầu từ trường hợp đó được thực thi.

## Cú pháp câu lệnh switch case

Lệnh switch case trong JS có cú pháp như sau:

```js
switch(x) {
  case 'value1':  // if (x === 'value1')
    ...
    [break]
  case 'value2':  // if (x === 'value2')
    ...
    [break]
  default:
    ...
    [break]
}
```

Trong đó:

- Giá trị `x` được kiểm tra **bằng nghiêm ngặt** lần lượt với các giá trị `value1`, `value2`,...
- Khi tìm thấy giá trị **value** thỏa mãn thì khối lệnh bắt đầu từ `case` đó được thực hiện cho đến khi gặp từ khóa `break` gần nhất, hoặc kết lúc lệnh switch case.
- Nếu không có trường hợp nào thỏa mãn thì khối lệnh ứng với `default` được thực thi.
- **Chú ý**: từ khóa `break` là không bắt buộc.

## Ví dụ lệnh switch case

Sau đây là ví dụ sử dụng lệnh switch case trong JavaScript:

```js
const x = 2 + 3;

switch (x) {
  case 4:
    console.log("Less than");
    break;
  case 5:
    console.log("Equal");
    break;
  case 6:
    console.log("Greater than");
    break;
  default:
    console.log("Don't know the answer");
}

// Equal
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>Equal</code>
  </div>
</div>

Giải thích:

- Lệnh `switch` so sánh bằng nghiêm ngặt giá trị của `x` với các `case` lần lượt là `4`, `5` và `6`.
- Với `case 4`: khác với giá trị của `x` (là `5`), nên quá trình so sánh tiếp tục.
- Với `case 5`: giá trị này bằng nghiêm ngặt với `x`, nên khối lệnh bắt đầu từ trường hợp này được thực thi. Vì vậy, giá trị `Equal` được in ra.
- Nhưng ngay sau đó là từ khóa `break`, nên lệnh switch case kết thúc.

**Nếu không có từ khóa `break` thì sao?**

Nếu không có từ khóa `break` thì toàn bộ khối lệnh phía sau `case 5` được thực thi.

```js
const x = 2 + 3;

switch (x) {
  case 4:
    console.log("Less than");
  case 5:
    console.log("Equal");
  case 6:
    console.log("Greater than");
  default:
    console.log("Don't know the answer");
}

// Equal
// Greater than
// Don't know the answer
```

<content-info>

`switch` và `case` đều có thể chứa biểu thức - không chỉ là [biến](/bai-viet/khoa-hoc-javascript/bien-trong-javascript/) hay [hằng](/bai-viet/khoa-hoc-javascript/hang-trong-javascript/).

</content-info>

Ví dụ lệnh switch case với biểu thức:

```js
let x = "3";
let v = 0;

switch (x - 1) {
  case v + 1:
    console.log("case 1");
    break;
  case v + 2:
    console.log("case 2");
    break;
  default:
    console.log("default");
}

// case 2
```

Vì `x = "3"` nên ta có `x - 1` bằng `"3" - 1`. Trường hợp này là phép trừ hai giá trị khác kiểu dữ liệu, nên kí tự `"3"` được [chuyển đổi về dạng số](/chuyen-doi-kieu-du-lieu-trong-javascript/) thành số `3`. Vì vậy, `x - 1` sẽ bằng `2`.

Mà ta có `v = 0`, nên `v + 1` bằng `1` và `v + 2` bằng `2`. Suy ra, trường hợp `case v + 2` thỏa mãn. Do đó, `case 2` được in ra.

## Nhóm các `case`

Hãy xem ví dụ sau:

```js
const n = 5;

switch (n) {
  case 3:
    console.log("Hi!");
    break;
  case 4:
    console.log("Hello!");
    break;
  case 5:
    console.log("Hi!");
    break;
  default:
    console.log("Bye!");
}

// Hi!
```

Với đoạn code trên, bạn thấy rằng `case 3` và `case 5` xử lý giống nhau.

Khi đó, thay vì viết tường minh như trên, bạn có thể gộp hai trường hợp này với nhau bằng cách bỏ qua từ khóa `break`:

```js
const n = 5;

switch (n) {
  case 4:
    console.log("Hello!");
    break;
  case 3:
  case 5:
    console.log("Hi!");
    break;
  default:
    console.log("Bye!");
}

// Hi!
```

Chạy thử với hai trường hợp `n = 5` và `n = 3`, bạn sẽ thấy kết quả hiển thị giống nhau là `Hi!`.

Vì khi bỏ qua từ khóa `break`, toàn bộ khối lệnh bắt đầu từ `case` hợp lệ được thực hiện cho đến khi gặp từ khóa `break` gần nhất hoặc kết thúc lệnh switch case.

## Vấn đề so sánh bằng nghiêm ngặt

Mình muốn nhấn mạnh rằng lệnh switch case sử dụng **so sánh bằng nghiêm ngặt** `===`. Nghĩa là các giá trị **phải cùng kiểu dữ liệu**.

Ví dụ:

```js
let x = 3;

switch (x) {
  case "3":
    console.log("string");
    break;
  case 3:
    console.log("number");
    break;
  default:
    console.log("unknown");
    break;
}

// number
```

## Tổng kết

Sau đây là những kiến thức cơ bản cần nhớ về lệnh switch case trong JavaScript:

- Lệnh switch case là cấu trúc rẽ nhánh dùng để **xác định một danh sách các trường hợp và khối lệnh tương ứng với mỗi trường hợp**.
- Lệnh switch case sử dụng so sánh bằng nghiêm ngặt `===`.
- Khi tìm thấy trường hợp thỏa mãn, toàn bộ khối lệnh từ `case` thỏa mãn được thực thi cho đến khi gặp từ khóa `break` gần nhất hoặc kết thúc lệnh switch case.
- Nếu không có trường hợp thỏa mãn, khối lệnh tương ứng với `default` được thực thi.
- Bạn có thể nhóm các `case` lại với nhau bằng cách bỏ qua từ khóa `break`.

## Thực hành

### Bài 1

Sử dụng `if..else` để viết đoạn code tương ứng với đoạn code sau:

```js
let browser = "Chrome";

switch (browser) {
  case "IE":
    console.log("Not support!");
    break;
  case "Chrome":
  case "Firefox":
  case "Safari":
  case "Edge":
    console.log("Support!");
    break;
  default:
    console.log("Unknown browser!");
}

// Support!
```

Xem đáp án

```js
let browser = "Chrome";

if (browser === "IE") {
  console.log("Not support!");
} else if (
  browser === "Chrome" ||
  browser === "Firefox" ||
  browser === "Safari" ||
  browser === "Edge"
) {
  console.log("Support!");
} else {
  console.log("Unknown browser!");
}

// Support!
```

Mặc dù trông code có vẻ tương đương, nhưng theo mình thấy thì dùng lệnh switch case sẽ **dễ nhìn hơn**.

## Bài 2

Sử dụng lệnh switch case viết đoạn code tương ứng với đoạn code sau:

```js
let x = 2;

if (x === 1) {
  console.log("x KHÔNG LÀ số nguyên tố");
} else if (x === 2) {
  console.log("x LÀ số nguyên tố");
} else if (x === 3) {
  console.log("x LÀ số nguyên tố");
} else if (x === 4) {
  console.log("x KHÔNG LÀ số nguyên tố");
} else if (x === 5) {
  console.log("x LÀ số nguyên tố");
} else if (x === 6) {
  console.log("x KHÔNG LÀ số nguyên tố");
} else {
  console.log("CHƯA RÕ!");
}
```

Xem đáp án

Bạn thấy rằng, có một vài trường hợp xử lý giống nhau. Nên mình có thể nhóm các `case` lại như sau:

```js
let x = 2;

switch (x) {
  case 2:
  case 3:
  case 5:
    console.log("x LÀ số nguyên tố");
    break;
  case 1:
  case 4:
  case 6:
    console.log("x KHÔNG LÀ số nguyên tố");
    break;
  default:
    console.log("CHƯA RÕ!");
}
```
