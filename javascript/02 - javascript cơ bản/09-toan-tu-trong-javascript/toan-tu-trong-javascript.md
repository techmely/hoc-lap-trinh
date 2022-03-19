---
title: "Các toán tử trong Javascript"
description: "Toán tử trong Javascript"
keywords:
  [
    "khoá học javascript",
    "toán tử trong Javascript",
    "toán tử Javascript",
    "tinh toan trong javascript",
    "toan tu so sanh",
    "Phép chia trong JavaScript",
    "Các toán tử trong Javascript",
    "các toán tử trong javascript cơ bản",
    "các toán tử trong javascript dùng để làm gì",
    "cach su dung toan tu trong javascript",
  ]
chapter:
  name: "Javascript cơ bản"
  slug: "chuong-02-javascript-co-ban"
category:
  name: "Javascript"
  slug: "javascript"
image: https://kungfutech.edu.vn/thumbnail.png
position: 9
---

Trong toán học, bạn đã biết về các toán tử cơ bản như: cộng (`+`), trừ (`-`), nhân (`*`) và chia (`/`),... Trong JavaScript cũng có những toán tử như vậy và thêm nhiều toán tử khác nữa. Sau đây, mình sẽ cùng tìm hiểu xem toán tử là gì, các toán tử trong JavaScript và thứ tự ưu tiên của các toán tử trong JS.

## Toán tử là gì?

**Toán tử** là một công cụ để thao tác với dữ liệu. Khi đó, đối tượng mà toán tử thao tác đến gọi là **toán hạng**. Tùy thuộc vào số lượng **toán hạng** mà JavaScript chia ra thành:

- Toán tử một ngôi (**unary**): có một toán hạng
- Toán tử hai ngôi (**binary**): có hai toán hạng
- Toán tử ba ngôi (**ternary**): có ba toán hạng
- Toán tử đa ngôi (**n-ary**): có trên ba toán hạng

## Các toán tử JavaScript

Nếu chia theo chức năng thì JavaScript có các loại toán tử cơ bản sau đây:

- Toán tử số học
- Toán tử gán
- Toán tử bitwise
- Toán tử dấu phẩy
- [Toán tử so sánh](/bai-viet/khoa-hoc-javascript/so-sanh-trong-javascript/)
- [Toán tử logic](/bai-viet/khoa-hoc-javascript/toan-tu-logic-trong-javascript/)
- [Toán tử điều kiện rẽ nhánh `?:`](/bai-viet/khoa-hoc-javascript/cau-truc-re-nhanh-trong-javascript/)
- [Toán tử "Nullish Coalescing" `??`](/bai-viet/khoa-hoc-javascript/toan-tu-nullish-coalescing-trong-javascript/)

Để tìm hiểu hết về những loại toán tử này, mình sẽ chia thành các bài viết khác nhau. Bài này chủ yếu tập trung vào các toán tử dùng cho việc tính toán như: **toán tử số học, toán tử gán, toán tử bitwise và toán tử dấu phẩy**.

### Toán tử số học

Toán tử số học là toán tử dùng để thực hiện các phép toán số học. Các toán tử số học trong JavaScript bao gồm:

- Toán tử cộng (`+`)
- Toán tử trừ (`-`)
- Toán tử nhân (`*`)
- Toán tử chia (`/`)
- Toán tử chia lấy dư (`%`)
- Toán tử lũy thừa (`**`)

Vì là toán tử số học, nên toán hạng ứng với các toán tử này **thường** là [số](/bai-viet/khoa-hoc-javascript/cac-kieu-du-lieu-trong-javascript/):

```js
console.log(5 + 2); // 7
console.log(5 - 2); // 3
console.log(5 * 2); // 10
console.log(5 / 2); // 2.5
console.log(5 % 2); // 1 (số dư)
console.log(5 ** 2); // 25 (5 lũy thừa 2)
```

**Nếu các toán hạng không phải là số thì sao?**

Sẽ có rất nhiều trường hợp xảy ra. Có thể JavaScript sẽ tự chuyển đổi kiểu dữ liệu thành **number** để tính toán số học.

Trường hợp, không thể chuyển đổi kiểu dữ liệu thành **number** được thì kết quả có thể sẽ là **string** hoặc **NaN**:

```js
console.log("5" + 2); // "52"
console.log("5" - 2); // 3
console.log("5" * 2); // 10
console.log("5" / 2); // 2.5
console.log("5a" % "2"); // NaN
console.log("5b" ** "2"); // NaN
```

Chuyển đổi kiểu dữ liệu là một thứ **khá xoắn não** khi học lập trình JavaScript. Bạn có thể đọc bài viết [chuyển đổi kiểu dữ liệu trong JavaScript](/bai-viet/khoa-hoc-javascript/chuyen-doi-kieu-du-lieu-trong-javascript/) để hiểu kỹ hơn về vấn đề chuyển đổi kiểu dữ liệu.

Trong ví dụ `"5" + 2` trên, bạn thấy kết quả là `52`. Lúc này, `+` không còn là toán tử số học nữa mà nó trở thành toán tử ghép string.

### Toán tử ghép string (`+`)

Khi một trong hai toán hạng của toán tử `+` có kiểu dữ liệu là string thì toán hạng còn lại sẽ bị chuyển thành kiểu string.

Và toán tử `+` sẽ thực hiện việc ghép nối hai string với nhau:

```js
console.log("hello" + " javascript"); // hello javascript
console.log(1 + "2"); // 12
console.log("1" + true); // 1true
```

### Toán tử chuyển đổi kiểu dữ liệu thành number (`+`)

Trong các phần trên, toán tử `+` đang đóng vai trò là **toán tử hai ngôi**. Nhưng khi `+` là **toán tử một ngôi** thì toán tử `+` sẽ thực hiện việc chuyển đổi kiểu dữ liệu của toán hạng thành number.

```js
// Không ảnh hưởng đến số
console.log(+1); // 1

// Chuyển đổi các kiểu dữ liệu khác thành số
console.log(+true); // 1
console.log(+false); // 0
console.log(+"abc"); // NaN
console.log(+""); // 0
console.log(+undefined); // NaN
console.log(+null); // 0
console.log(+{ x: 1 }); // NaN
```

<content-info>📝 Trong trường hợp biểu thức có **nhiều toán tử**, bạn cần phải biết thứ tự ưu tiên của từng toán tử để biết chính xác thứ tự thực hiện các phép tính.</content-info>

Trong toán học, chắc bạn đã nghe câu "nhân chia trước, cộng trừ sau" rồi phải không?

Ý là phép nhân, chia có độ ưu tiên cao hơn phép cộng và phép trừ. Nên phép nhân, chia sẽ được thực hiện trước.

Và khi hai toán tử có cùng độ ưu tiên thì sẽ thực hiện tính toán từ trái sang phải.

Đây là bảng thứ tự ưu tiên của các toán tử: [Operator precedence](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Operators/Operator_Precedence#table).

### Toán tử gán

**Toán tử gán** dùng để gán giá trị cho một [biến](/bai-viet/khoa-hoc-javascript/bien-trong-javascript/) (hoặc [hằng](/bai-viet/khoa-hoc-javascript/hang-trong-javascript/)).

```js
let x = 1; // gán giá trị cho biến
const message = "Hello"; // gán giá trị cho hằng
```

Bạn có thể gán giá trị cho biến bằng kết quả của một biểu thức:

```js
let result = 1 + 2 + 3 - 4;
console.log(result); // 2
```

Ngoài ra, bạn có thể gán cùng giá trị cho nhiều biến trên cùng một dòng lệnh:

```js
let x, y, z, t;
x = y = z = t = "hello";
console.log(x); // hello
console.log(y); // hello
console.log(z); // hello
console.log(t); // hello
```

Bạn cũng có thể thay đổi giá của một biến và gán lại cho chính nó:

```js
let n = 1;
n = n + 5; // n = 1 + 5 = 6n = n - 2; // n = 6 - 2 = 4n = n * 3; // n = 4 * 3 = 12n = n / 2; // n = 12 / 2 = 6n = n % 5; // n = 6 % 5 = 1n = n ** 2; // n = 1 ** 2 = 1console.log(n); // 1
```

Để thực hiện việc này, có một cú pháp rút gọn khác như sau:

```js
let n = 1;
n += 5; // n = 1 + 5 = 6n -= 2; // n = 6 - 2 = 4n *= 3; // n = 4 * 3 = 12n /= 2; // n = 12 / 2 = 6n %= 5; // n = 6 % 5 = 1n **= 2; // n = 1 ** 2 = 1console.log(n); // 1
```

Tương tự hai toán tử `+=` và `-=`, nếu bạn muốn tăng / giảm **1 đơn vị** thì JavaScript có toán tử khác tương đương sau đây.

### Toán tử tăng 1 đơn vị (`++`) và giảm 1 đơn vị (`--`)

Toán tử `++` làm tăng giá trị 1 đơn vị. Toán tử `--` làm giảm giá trị 1 đơn vị, ví dụ:

```js
let n = 1;
n++; // tương đương với n += 1 hay n = n + 1.n--; // tương đương với n -= 1 hay n = n - 1.
```

<content-info>

toán tử `++` và `--` chỉ dùng được với biến. Nếu bạn dùng nó trực tiếp với giá trị, kiểu như `4++` hay `--3` thì bạn sẽ bị lỗi cú pháp.

</content-info>

Ví dụ sau lỗi cú pháp:

```js
4++; // Uncaught SyntaxError: Invalid left-hand side expression in postfix operation
    --3; // Uncaught SyntaxError: Invalid left-hand side expression in postfix operation
```

Toán tử `++` và `--` có hai dạng:

- Đặt trước biến `++a`, `--a`
- Đặt sau biến `a++`, `a--`

**Hai dạng trên có gì khác nhau?**

Nếu bạn sử dụng các toán tử trên một cách độc lập thì hai cách viết là hoàn toàn giống nhau.

Nhưng nếu bạn sử dụng chúng để gán giá trị cho một biến, hoặc sử dụng các toán tử trên trong một biểu thức thì sẽ có sự khác biệt.

Hãy xem hai ví dụ sau.

**Ví dụ 1**: sử dụng `++a`

```js
let a = 2;
let x = ++a;
console.log(a); // 3
console.log(x); // 3
```

**Ví dụ 2**: sử dụng `a++`

```js
let a = 2;
let x = a++;
console.log(a); // 3
console.log(x); // 2
```

Bạn thấy rằng đáp án của hai ví dụ trên là khác nhau:

- Ví dụ 1, `++a` - tức là `a` được cộng thêm 1 đơn vị trước thành `3`, sau đó `x = a` thực hiện sau nên x có giá trị bằng 3.
- Ví dụ 2, `a--` - tức là `a` được cộng thêm 1 đơn vị sau. Hay nói cách khác `x = a` thực hiện trước. Nên x có giá trị bằng 2. Sau đó, a mới được tăng lên 1 đơn vị thành 3.

**Trong có vẻ khá phức tạp phải không?**

Thực ra, hai cách trên bạn có thể viết tách biệt thành các câu lệnh khác nhau.

Ví dụ 1 trở thành:

```js
let a = 2;
a++;
let x = a;
console.log(a); // 3
console.log(x); // 3
```

Ví dụ 2 trở thành:

```js
let a = 2;
let x = a;
a++;
console.log(a); // 3
console.log(x); // 2
```

Cách này dài hơn có một dòng thôi. Nhưng rõ ràng là code dễ hiểu hơn rất nhiều. Qua đó, bạn sẽ tránh được những lỗi logic liên quan đến thứ tự thực hiện của các toán tử `++` và `--`.

### Toán tử bitwise

**Toán tử bitwise** là các toán tử áp dụng trên đối tượng **bit** (toán tử bitwise thao tác trên số tự nhiên 32 bit).

Đây không phải là những toán tử riêng của JavaScript. Hầu hết các ngôn ngữ lập trình đều có toán tử bitwise.

Các toán tử bitwise bao gồm:

- Toán tử AND (`&`)
- Toán tử OR (`|`)
- Toán tử NOT (`~`)
- Toán tử XOR (`^`)
- Toán tử dịch trái (`<<`)
- Toán tử dịch phải (`>>`)
- Toán tử dịch phải (chèn thêm số `0` ở đầu) (`>>>`)

<content-info>

Trong lập trình web thông thường, mình hầu như không dùng các toán tử bitwise. Bạn có thể đọc thêm bài viết [phép toán thao tác bit](https://vi.wikipedia.org/wiki/Ph%C3%A9p_to%C3%A1n_thao_t%C3%A1c_bit) để hiểu hơn về các toán này và sử dụng khi cần.

</content-info>

### Toán tử dấu phẩy

**Toán tử dấu phẩy** cho phép thực hiện một vài biểu thức (cách nhau bằng dấu phẩy), nhưng kết quả thì chỉ lấy ở biểu thức cuối cùng.

Ví dụ:

```js
let a = 1;
let x = ((a = a + 1), a + 4);
console.log(a); // 2
console.log(x); // 6
```

Bạn thấy ở câu lệnh `let x = ((a = a + 1), a + 4)`, thành phần `a = a + 1` sẽ thực hiện trước. Sau câu lệnh này, a bằng `1+1` bằng 2.

Tiếp theo, `a + 4` bằng `2 + 4` bằng 6. Kết quả này được gán cho biến x. Do đó, mình có kết quả như trên.

Toán tử này cũng rất ít khi sử dụng. Vì mình có thể thay thế nó bằng các câu lệnh riêng rẽ như sau:

```js
let a = 1;
a = a + 1;
let x = a + 4;
console.log(a); // 2
console.log(x); // 6
```

## Tổng kết

Vậy toán tử là gì?

**Toán tử** là một công cụ để thao tác với dữ liệu.

Khi đó, đối tượng mà toán tử thao tác đến gọi là **toán hạng**. Tùy thuộc vào số lượng **toán hạng** mà JavaScript chia ra thành:

- Toán tử một ngôi (**unary**): có một toán hạng
- Toán tử hai ngôi (**binary**): có hai toán hạng
- Toán tử ba ngôi (**ternary**): có ba toán hạng
- Toán tử đa ngôi (**n-ary**): có trên ba toán hạng

Nếu chia theo chức năng thì có một số toán tử cơ bản trong JavaScript là:

- Toán tử số học
- Toán tử gán
- Toán tử bitwise
- Toán tử dấu phẩy
- Toán tử so sánh
- Toán tử logic
- Toán tử điều kiện rẽ nhánh `?:`
- Toán tử "Nullish coalescing" `??`

Mỗi toán tử có độ ưu tiên riêng. Toán tử với độ ưu tiên cao hơn sẽ thực hiện trước. Trường hợp các toán tử có cùng độ ưu tiên thì thứ tự thực hiện các phép toán là từ trái sang phải.

## Thực hành

### Bài 1: Cho đoạn code sau:

```js
let a = 1;
let b = 2;

const c = a++; // (1)
const d = --b; // (2)
const e = c + d + "n"; // (3)
```

Giá trị của `a`, `b`, `c`, `d` và `e` sau đoạn code là gì?

Xem đáp án

Giải thích:

- (1): `c = a` thực hiện trước nên c bằng 1. Sau đó, `a++` thực hiện, nên a bằng 2
- (2): `--b` thực hiện trước nên `b = 2 - 1 = 1`. Sau đó, `d = b` thực hiện, nên d bằng 1
- (3): biếu thức `c + d + "n"` chỉ toàn phép cộng nên sẽ thực hiện từ trái sang phải. Đầu tiên, `c + d` thực hiện bằng `1 + 1 = 2`. Sau đó, `2 + "n"` thực hiện. Số `2` sẽ bị chuyển thành kiểu **string**, nên kết quả `e = 2n`

Kết quả:

- `a = 2`
- `b = 1`
- `c = 1`
- `d = 1`
- `e = "2n"`

### Bài 2: Cho đoạn code sau:

```js
let x = 10;

let y = 1 + (x *= 2);
```

Hỏi giá trị của `x` và `y` sau đoạn code trên là gì?

Xem đáp án

Giải thích:

- `x *= 2` thực hiện trước, suy ra `x = x * 2 = 10 * 2 = 20`.
- Sau đó, `y = 1 + 20 = 21`.

Kết quả:

- `x = 20`
- `y = 21`
