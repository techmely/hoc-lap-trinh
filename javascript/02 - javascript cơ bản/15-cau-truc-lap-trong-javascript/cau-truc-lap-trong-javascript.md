---
title: "Cấu trúc lặp trong Javascript"
description: "Cấu trúc lặp trong Javascript"
keywords: [
  "khoá học javascript",
"Cấu trúc lặp trong Javascript",
"vong lap for trong javascript",
"vong lap foreach trong javascript",
"vong lap while trong javascript",
"cu phap vong lap",
"Vòng lặp trong Java",
"cach su dung cau truc lap trong javascript",
"Cách sử dụng cấu trúc lặp"
]
chapter:
  name: "Javascript cơ bản"
  slug: "chuong-02-javascript-co-ban"
category:
  name: "Javascript"
  slug: "javascript"
image: https://kungfutech.edu.vn/thumbnail.png
position: 15
---

Đôi khi bạn cần phải lặp lại một hành động với số lần cho trước. Thay vì phải viết lại code giống nhau cho mỗi lượt lặp, JavaScript cung cấp cho bạn một **cấu trúc lặp** hay gọi cách khác là **vòng lặp trong JavaScript**.

Có ba vòng lặp trong JavaScript là:

- Vòng lặp while.
- Vòng lặp do...while.
- Vòng lặp for.

## Vòng lặp while

Cú pháp của vòng lặp while là:

```js
while (condition) {
  // code
}
```

Trong đó:

- **Condition** là điều kiện thực hiện vòng lặp.
- Khi **condition** có giá trị [truthy](/bai-viet/khoa-hoc-javascript/toan-tu-logic-trong-javascript/) thì **code** được thực thi. Ngược lại, khi **condition** là **falsy** thì vòng lặp kết thúc.

Ví dụ **vòng lặp while** sau đây in ra các số từ 1 đến 3:

```js
let count = 1;

while (count <= 3) {
  console.log(count);
  count++;
}

// 1
// 2
// 3
```

Đoạn code trên diễn tả bằng lời như sau:

_Khởi tạo biến `count` bằng `1`. Kiểm tra điều kiện nếu `count <= 3` đúng thì ghi ra `console.log` số `count`. Sau đó, tăng `count` lên 1 đơn vị. Tiếp tục quá trình kiểm tra điều kiện, ghi log và tăng `count` cho đến khi `count <= 3` sai thì dừng lại._

Trong đoạn code trên, nếu bạn không có `count++` thì giá trị của biến `count` mãi mãi là `1`. Nói cách khác, giá trị của `count <= 3` luôn luôn là `true`. Do đó, vòng lặp sẽ **lặp vô hạn** và không bao giờ dừng lại.

<content-info>

thành phần **condition** có thể là biểu thức hoặc biến.

</content-info>

Ví dụ đoạn code in ra các số từ 3 về 1:

```js
let n = 3;

// Khi n === 0 thì n là falsy, suy ra vòng lặp kết thúc.
while (n) {
  console.log(n);
  n--; // Giá trị của n giảm đi 1 đơn vị sau mỗi lượt lặp
}

// 3
// 2
// 1
```

- Nếu đoạn code bên trong vòng lặp chỉ là **một câu lệnh** thì bạn có thể bỏ qua cặp dấu `{}`.

Ví dụ vòng lặp while chỉ có một câu lệnh ở thân vòng lặp:

```js
let n = 3;
while (n) console.log(n--);
// 3
// 2
// 1
```

## Vòng lặp do...while

Vòng lặp do...while tương tự như vòng lặp while, chỉ khác là điều kiện vòng lặp được chuyển xuống cuối cấu trúc lặp.

Cú pháp vòng lặp `do...while` như sau:

```js
do {
  // code
} while (condition);
```

Khác với vòng lặp while, vòng lặp `do...while` luôn thực hiện **ít nhất một lượt lặp**. Sau đó mới kiểm tra điều kiện lặp.

Nếu **condition** có giá trị **truthy** thì tiếp tục cấu trúc lặp. Ngược lại, khi **condition** là **falsy** thì vòng lặp do...while kết thúc.

Ví dụ **vòng lặp do...while** in ra các số từ 1 đến 3:

```js
let count = 1;

do {
  console.log(count);
  count++;
} while (count <= 3);

// 1
// 2
// 3
```

## Vòng lặp for

Nếu để ý các ví dụ ở trên thì bạn sẽ thấy rằng, cấu trúc lặp với các loại vòng lặp như sau:

- Khởi tạo giá trị biến đếm (`count = 1`).
- So sánh giá trị đếm với giá trị tối đa (`count <= 3`).
- Tăng giá trị đếm (`count++`).

Để ngắn gọn, JavaScript sinh ra vòng lặp for với cú pháp là:

```js
for([khởi tạo]; [điều kiện]; [cập nhật]){
      // code
    }
```

Trong đó:

- **\[Khởi tạo\]**: Thực hiện một lần lúc bắt đầu vòng lặp.
- **\[Điều kiện\]**: Kiểm tra trước mỗi vòng lặp.
- **\[Cập nhật\]**: Thực hiện ở cuối mỗi vòng lặp.

Ví dụ **vòng lặp for** dùng để in ra các số từ 1 đến 3:

```js
for (let count = 1; count <= 3; count++) {
  console.log(count);
}

// 1
// 2
// 3
```

Bạn có thể thấy là cấu trúc lặp vẫn được duy trì mà nhìn code gọn gàng hơn nhiều.

<content-info>

Biến `count` được khai báo bên trong vòng lặp for như trên thì **phạm vi của biến** chỉ là bên trong vòng lặp for. Do đó, bạn không thể sử dụng biến `count` trên ở bên ngoài vòng lặp for.

</content-info>

Ví dụ sau bị lỗi **Uncaught ReferenceError: count is not defined** khi cố gắng truy cập vào biến `count`:

```js
for (let count = 1; count <= 3; count++) {
  console.log(count);
}

console.log(count); // Uncaught ReferenceError: count is not defined
```

Để sử dụng được biến `count`, bạn cần khai báo biến `count` ở ngoài vòng lặp for:

```js
let count;
for (count = 1; count <= 3; count++) {
  console.log(count);
}

console.log(count); // 4
```

**Chú ý: bất kể phần nào trong vòng lặp for đều không bắt buộc.**

Ví dụ bỏ qua phần **khởi tạo**:

```js
let count = 1;

for (; count <= 3; count++) {
  console.log(count);
}

// 1
// 2
// 3
```

Ví dụ bỏ qua phần **cập nhật**:

```js
let count = 1;

for (; count <= 3; ) {
  console.log(count++);
}

// 1
// 2
// 3
```

Ví dụ bỏ qua phần **điều kiện** (trường hợp này sẽ **lặp vô hạn**):

```js
let count = 1;

for (;;) {
  console.log(count++);
}
```

## Thoát vòng lặp trong JavaScript

Các ví dụ trên luôn có điều kiện để thoát khỏi vòng lặp. Nghĩa là bất cứ khi nào **condition** có giá trị **falsy** thì vòng lặp sẽ dừng lại.

Tuy nhiên, bạn có thể chủ động dừng vòng lặp bất cứ khi nào bằng cách sử dụng từ khóa **break**.

> 💡 Bài viết trước mình có giới thiệu về tứ khóa **break** sử dụng trong [lệnh switch case](/bai-viet/khoa-hoc-javascript/switch-case-trong-javascsript).

Ví dụ in ra [bội số](https://vi.wikipedia.org/wiki/B%E1%BB%99i_s%E1%BB%91) nhỏ nhất của 7 bắt đầu từ 8 (hay số nhỏ nhất chia hết cho 7 bắt đầu từ số 8):

```js
for (let number = 8; ; number++) {
  if (number % 7 === 0) {
    console.log(number);
    break;
  }
}

// 14
```

Trong vòng lặp for trên, mình bỏ qua phần điều kiện. Nghĩa là không kiểm tra điều kiện trước khi thực hiện vòng lặp. Hay vòng lặp luôn luôn được thực hiện.

Trong mỗi vòng lặp, mình kiểm tra xem nếu giá trị `number` chia hết cho 7 (tức số dư của `number` khi chia cho 7 bằng 0) thì đó chính là số cần tìm.

Cuối cùng, mình dùng từ khóa `break` để thoát khỏi vòng lặp.

> 💡 Tương tự, bạn cũng có thể sử dụng từ khoá `break` đối với vòng lặp while và vòng lặp do...while.

## Từ khóa `continue` trong JavaScript

Từ khoá `continue` gần giống từ khóa `break`. Nếu như từ khóa `break` dùng để thoát khỏi vòng lặp thì từ khóa `continue` dùng để dừng **lượt lặp hiện tại** và chuyển tới lượt lặp tiếp theo.

Ví dụ tìm **số lẻ** là bội số nhỏ nhất của 7 và bắt đầu từ số 8:

```js
for (let number = 8; ; number++) {
  if (number % 2 === 0) continue;
  if (number % 7 === 0) {
    console.log(number);
    break;
  }
}

// 21
```

Khác ví dụ trước, ví dụ này cần tìm ra bội số là **số lẻ**. Do đó, mình phải kiểm tra xem số hiện tại là chẵn hay lẻ trước.

Nếu `number % 2 === 0` là `true` thì suy ra đó là số chẵn. Vì không phải là số lẻ, nên mình dừng lại lượt lặp này để chuyển sang lượt tiếp theo, bằng cách dùng từ khóa `continue`.

Cho đến khi `number` bằng `21`. Đây là số lẻ nên `number % 2 === 0` là `false`. Mà `21` chia hết cho `7`. Nên `number % 7 === 0` trả về `true`.

Vì vậy, `21` là số cần tìm và cuối cùng là `break` - dừng lại vòng lặp for.

> 💡 Từ khóa `continue` giúp làm giảm mức độ code lồng nhau.

Ví dụ in ra các số chẵn trong đoạn từ 1 đến 5 mà **không** dùng từ khóa `continue`:

```js
for (let number = 1; number <= 5; number++) {
  if (number % 2 === 0) {
    console.log(number);
  }
}

// 2
// 4
```

Ví dụ in ra các số chẵn trong đoạn từ 1 đến 5 **có** dùng từ khóa `continue`:

```js
for (let number = 1; number <= 5; number++) {
  if (number % 2 !== 0) continue;
  console.log(number);
}

// 2
// 4
```

Bạn thấy rằng kết quả hai cách làm trên là như nhau, nhưng cách làm sử dụng từ khóa `continue` giúp làm giảm một mức độ code lồng nhau.

<content-info>từ khóa `continue` (và từ khóa `break`) không thể dùng trong toán tử `?`.</content-info>

Ví dụ sau bị lỗi cú pháp:

```js
for (let number = 1; number <= 5; number++) {
      number % 2 === 0 ? console.log(number) : continue;}

    // Uncaught SyntaxError: Unexpected token 'continue'
```

## Sử dụng label với `break` và `continue`

Nhiều khi mình cần phải thoát khỏi nhiều vòng lặp lồng nhau, ví dụ:

```js
let done = false;

for (let i = 0; i < 3; i++) {
  if (done) {
    break;
  }
  for (let j = 0; j < 3; j++) {
    if (i * j >= 4) {
      done = true;
      break;
    }

    console.log(i, j);
  }
}
```

Trong đoạn trên, mình cần sử dụng thêm biến `done` để kiểm tra điều kiện kết thúc.

Vì một từ khóa `break` chỉ có tác dụng trong phạm vi một vòng lặp, nên mình cần gán giá trị `true` cho biến `done` ở vòng lặp bên trong.

Rồi ở vòng lặp ngoài, kiểm tra khi nào `done` là `true` thì `break` luôn khỏi vòng lặp ngoài.

**Rõ ràng, code trên khá dài dòng. Để giải quyết vấn đề này, bạn có thể dùng "label", với cú pháp như sau:**

```js
labelName: for (...) {
      // code
      break labelName;
    }
```

Câu lệnh `break labelName` giúp "thoát khỏi code" ứng với label.

Đoạn code trên viết lại với label như sau:

```js
outer: for (let i = 0; i < 3; i++) {
  for (let j = 0; j < 3; j++) {
    if (i * j >= 4) {
      break outer;
    }

    console.log(i, j);
  }
}
```

**Từ khóa `break` phải nằm trong một "khối code" - "block code".**

> Khối code có thể hiểu là đoạn code nằm trong cặp dấu `{}` ứng với các vòng lặp for, vòng lặp while, vòng lặp do...while, hàm,...).

Ví dụ sau bị lỗi cú pháp vì dùng `break` ở ngoài khối code:

```js
let x = 1;

    if (x === 1) {  break;}
    // Uncaught SyntaxError: Illegal break statement
```

Với từ khóa `continue`, cách sử dụng từ label cũng giống từ khóa `break`.

## Tổng kết

Vòng lặp trong JavaScript có ba loại là:

- Vòng lặp while: kiểm tra **điều kiện trước** mỗi lượt lặp.
- Vòng lặp do...while: kiểm tra **điều kiện cuối** mỗi lượt lặp.
- Vòng lặp for: kiểm tra **điều kiện trước** mỗi lượt lặp và thêm **một số cài đặt** khác.

Nếu điều kiện lặp luôn có giá trị **truthy** thì cấu trúc lặp sẽ lặp vô hạn.

Để chủ động thoát khỏi vòng lặp, bạn dùng từ khóa `break`. Và để thoát khỏi một lượt lặp, bạn dùng từ khóa `continue`.

Từ khóa `break` và từ khóa `continue` có hỗ trợ label, giúp thoát khỏi các vòng lặp lồng nhau dễ dàng hơn.

## Thực hành

### Bài 1:

Sử dụng [`console.log`](/bai-viet/khoa-hoc-javascript/dev-tools-la-gi/) để in ra hình tam giác như sau:

```js
#
##
###
####
#####
######
#######
```

Xem đáp án

```js
let row = "";
for (var i = 1; i <= 7; i++) {
  row += "#";
  console.log(row);
}
```

### Bài 2:

Sử dụng [`prompt`](/ham-tuong-tac-nguoi-dung-alert-confirm-prompt/) để yêu cầu người dùng nhập vào một số.

- Nếu người dùng nhập vào không phải là số thì hiển thị ra thông báo: "Bạn nhập vào không phải là số".
- Nếu người dùng nhập vào là số thì hiển thị ra thông báo: "Số bạn nhập vào quá nhỏ" khi số đó nhỏ hơn 10, ngược lại thì dừng thông báo.

Xem đáp án

```js
while (true) {
  const input = prompt("Enter a number:");
  const number = Number(input);

  if (isNaN(number)) {
    alert("It's not a number.");
  } else if (number < 10) {
    alert("It's too small.");
  } else {
    break;
  }
}
```

Trong đó, hàm `isNaN(number)` dùng để kiểm tra giá trị của biến `number` xem có phải là `NaN` hay không. Nói cách khác, nếu `isNaN(number)` trả về `false` thì giá trị của `number` là số.

### Bài 3:

1.  Sử dụng `console.log` để in ra hình bàn cờ vua kích thước (8 x 8) như sau:

```js
#_#_#_#_ _#_#_#_# #_#_#_#_ _#_#_#_# #_#_#_#_ _#_#_#_# #_#_#_#_ _#_#_#_#
```

Xem đáp án

```js
for (let row = 0; row < 8; row++) {
  let str = "";
  for (let col = 0; col < 8; col++) {
    if (row % 2 === col % 2) {
      str += "#";
    } else {
      str += "_";
    }
  }
  console.log(str);
}
```

2.  Yêu cầu người dùng nhập vào một số **size** (size là số dương). Sau đó hiển thị ra hình bàn cờ vua như trên với kích thước là **size x size**.

Xem đáp án

```js
let size; // Nhập số dươngwhile (true) {  size = Number(prompt("Enter a positive number:"));  if (!isNaN(size) && size > 0) break;}
// In ra màn hình
for (let row = 0; row < size; row++) {
  let str = "";
  for (let col = 0; col < size; col++) {
    if (row % 2 === col % 2) {
      str += "#";
    } else {
      str += "_";
    }
  }
  console.log(str);
}
```

### Bài 4:

Yêu cầu người dùng nhập vào một số. Nếu người dùng nhập vào một số dương thì hiển thị ra thông báo xem số đó có phải số nguyên tố hay không.

Xem đáp án

```js
let number;

// Nhập số dương
while (true) {
  number = Number(prompt("Enter a positive number:"));
  if (!isNaN(number) && number > 0) break;
}

// Kiểm tra số nguyên tốif (number < 2) {  alert("It's not a prime number.");} else if (number === 2) {  alert("It's a prime number.");} else {  let isPrimeNumber = true;  for (let i = 2; i < number; i++) {    if (number % i === 0) {      isPrimeNumber = false;      break;    }  }  if (isPrimeNumber) alert("It's a prime number.");  else alert("It's not a prime number.");}
```

<content-info>số nguyên tố là số nguyên dương lớn hơn hoặc bằng 2 thỏa mãn điều kiện chỉ chia hết cho 1 và chính nó.</content-info>
