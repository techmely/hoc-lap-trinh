---
title: "Tìm hiểu biến trong JavaScript"
description: "Tìm hiểu về biến trong JavaScript"
keywords:
  [
    "khoá học javascript",
    "bien trong javascript",
    "cac kieu du lieu trong javascript",
    "khai bao bien",
    "quy tac dat ten bien trong javascript",
    "Lấy giá trị của biến trong JavaScript",
    "khai bao bien trong javascript",
    "Kiểu dữ liệu trong JavaScript",
    "so sanh bien trong javascript",
    "Lấy giá trị của biến trong JavaScript",
  ]
chapter:
  name: "Javascript cơ bản"
  slug: "chuong-02-javascript-co-ban"
category:
  name: "Javascript"
  slug: "javascript"
image: https://kungfutech.edu.vn/thumbnail.png
position: 4
---

Nếu như trong toán học có khái niệm [biến số](https://vi.wikipedia.org/wiki/Bi%E1%BA%BFn_s%E1%BB%91) thì trong lập trình cũng có khái niệm biến. Đây là một thành phần không thể thiếu trong lập trình. Vì vậy, bài viết này mình sẽ tập trung vào tìm hiểu xem biến là gì, cách khai báo biến trong JavaScript và quy tắc đặt tên biến.

## Biến là gì?

Biến là "tên biểu tượng" dùng để đại diện cho một giá trị. Và giá trị của biến có thể thay đổi trong chương trình.

![Biến trong JavaScript](https://user-images.githubusercontent.com/29374426/156797884-2817ae97-98cc-4748-829d-aafee9886aa1.png)

Biến là "tên biểu tượng" dùng để đại diện cho một giá trị. Và giá trị của biến có thể thay đổi trong chương trình.

Giả sử `x`là số lượng người đang đọc bài viết này, thì `x` chính là một biến. Ví dụ giá trị của biến `x` bây giờ là 100. Nhưng năm phút sau, số lượng người đọc bài viết tăng lên thành 150. Lúc này, giá trị của biến `x` sẽ là 150.

## Cách khai báo biến trong JavaScript

Để khai báo biến trong JavaScript, bạn dùng từ khóa `let` (từ khóa `var` đã lỗi thời và không nên sử dụng).

Cú pháp khai báo biến như sau:

```js
let <tên biến>;
```

Ví dụ câu lệnh sau khai báo một biến số có tên là "language":

```js
let language;
```

Bây giờ, bạn có thể gán giá trị cho biến "language" sử dụng toán tử gán (`=`):

```js
let language;

language = "JavaScript";
```

Nghĩa là biến "language" đang liên kết đến vùng nhớ có giá trị là "JavaScript". Và bạn có thể truy cập đến vùng nhớ bằng cách sử dụng tên của biến như sau:

```js
let language;

language = "JavaScript";

console.log(language); // Kết quả hiển thị trên console là: "JavaScript"
```

Để ngắn gọn, bạn có thể khai báo biến và gán giá trị cho biến trên cùng một dòng:

```js
let language = "JavaScript";
console.log(language); // JavaScript
```

Để khai báo nhiều biến, bạn có thể dùng dấu phẩy (`,`) để ngăn cách các biến trên cùng một dòng:

```js
let language = "JavaScript",
  message = "Hello",
  date = "Monday";
```

Ngoài ra, bạn cũng có thể viết như sau:

```js
let language = "JavaScript",
  message = "Hello",
  date = "Monday";
```

Hoặc cho dấu phẩy lên đầu:

```js
let language = "JavaScript",
  message = "Hello",
  date = "Monday";
```

Tuy nhiên, mình thấy khai báo mỗi biến trên một dòng là dễ nhìn hơn cả:

```js
let language = "JavaScript";
let message = "Hello";
let date = "Monday";
```

Về cơ bản thì các cách trên đều giống nhau, tùy thuộc thói quen và sở thích của bạn mà lựa chọn cho phù hợp.

## Cách thay đổi giá trị của biến số

Để thay đổi giá trị của biến, bạn chỉ cần gán giá trị mới cho nó, ví dụ:

```js
// Khai báo biến và gán giá trị ban đầu
let language = "JavaScript";
console.log(language); // JavaScript

// Thay đổi giá trị của biến
language = "React";
console.log(language); // React
```

Hoặc bạn cũng có thể gán giá trị của biến số này cho biến số khác, ví dụ:

```js
// Khai báo biến và gán giá trị ban đầu
let language1 = "JavaScript";
console.log(language1); // JavaScript

// Khai báo biến số 2
let language2;

// Gán giá trị của biến language1 cho biến language2
language2 = language1;
console.log(language2); // JavaScript

// Giá trị của biến language1 vẫn không đổi
console.log(language1); // JavaScript
```

## Quy tắc đặt tên biến trong JavaScript

Quy tắc đặt tên biến trong JavaScript như sau:

- Bắt đầu bằng chữ cái, dấu gạch dưới (`_`) hoặc kí tự "đô la" (`$`).
- Sau kí tự đầu tiên, ngoài những kí tự trên, bạn có thể sử dụng thêm số (0-9).
- Không sử dụng từ khoá và từ dự trữ.

Từ khoá (**keywords**) là những từ mang ý nghĩa đặc biệt. Từ **let** là một từ khoá, với ý nghĩa là để khai báo biến.

Từ dự trữ (**reserved words**) là những từ sẽ được dùng làm từ khoá cho những phiên bản sau của JavaScript. Bạn không thể sử dụng từ khoá hay từ dự trữ để đặt tên cho biến số.

Danh sách những từ khoá và những từ dự trữ:

`break` `case` `catch` `class` `const` `continue` `debugger` `default` `delete` `do` `else` `enum` `export` `extends` `false` `finally` `for` `function` `if` `implements` `import` `in` `instanceof` `interface` `let` `new` `null` `package` `private` `protected` `public` `return` `static` `super` `switch` `this` `throw` `true` `try` `typeof` `var` `void` `while` `with` `yield`

Ví dụ những tên biến hợp lệ:

```js
let temp = 100;
let _result3 = 10;
let $_$ = "hehehe";
let I_AM_HUNGRY = true;
let dientichao = 999;
```

Ví dụ những tên biến không hợp lệ:

```js
let point% = 50;       // sử dụng kí tự đặc biệt %
let 2you = 'passtion'; // bắt đầu bằng số
let null = 'oh no';    // sử dụng từ khoá "null"
```

<content-info>
📝 Một số **chú ý** khi đặt tên biến:

<ul>
<li>Tên biến trong JavaScript có phân biệt **CHỮ HOA** và **chữ thường**. Ví dụ hai biến language và LanGuage là hai biến khác nhau.</li>
<li>Bạn có thể sử dụng những chữ cái không phải chữ cái Latinh để đặt tên biến. Nhưng điều này là không nên. Bạn nên sử dụng chữ cái Latinh (a-z) để đặt tên biến.</li>
<li>Tốt nhất là đặt theo chuẩn tiếng Anh để mọi người trên thế giới có thể hiểu code của bạn.</li>
</ul>
</content-info>

## Chuẩn hóa cách đặt tên biến

Về cơ bản, bạn có thể đặt tên biến là bất kỳ thứ gì, miễn là tuân theo quy tắc trên. Tuy nhiên, bạn nên đặt tên biến theo đúng chuẩn thì tốt hơn.

Mục đích là để bạn hoặc đồng nghiệp khi đọc code thì dễ dàng hiểu được mỗi biến dùng để làm gì, ví dụ:

- Biến lưu tên: `name`.
- Biến lưu tuổi: `age`.
- Biến lưu địa chỉ: `address`.
- ...

Có nhiều trường hợp dùng một từ không thể hiện được ý nghĩa của biến, bạn có thể dùng nhiều từ tùy ý, ví dụ:

- Biến lưu tổng số học sinh: `totalStudent`.
- Biến lưu số lượng xe máy trong bãi: `numberOfMotobike`.
- ...

Trong ví dụ trên, bạn thấy mình viết hoa chữ cái đầu tiên của các từ phía sau. Điều này giúp việc đọc tên biến dễ dàng hơn. Cách đặt tên biến này gọi là: **camelCase**.

![đặt tên biến trong javascript](https://user-images.githubusercontent.com/29374426/156797653-ec5d868e-37e2-4038-8006-3f914b22a160.png)

Ngoài cách trên, bạn có thể sử dụng **snake_case** với dấu gạch dưới (`_`) để ngăn cách các từ như sau:

- Biến lưu tổng số học sinh: **total_student**.
- Biến lưu số lượng xe máy trong bãi: **number_of_motobike**.

Còn nhiều cách đặt tên khác nữa (PascalCase, CONSTANT_CASE, flatcase,...). Bạn có thể chọn một cách bất kỳ. Miễn sao bạn đặt tên biến dễ nhìn và thống nhất một kiểu đặt tên biến trong toàn bộ dự án.

> 💡 Đối với lập trình JavaScript, mình thấy đặt tên biến theo kiểu **camelCase** là phổ biến hơn cả. Và mình cũng sử dụng cách này khi lập trình JavaScript.

## Một số lỗi với biến trong JavaScript

Khai báo và gán giá trị cho biến tưởng chừng là đơn giản. Nhưng đôi khi bạn cũng có thể mắc các lỗi sau đây.

### Khai báo biến nhiều lần

Một biến số chỉ được khai báo một lần, nếu bạn khai báo lại biến đó thì sẽ bị lỗi cú pháp, ví dụ:

```js
let language = "JavaScript";

let language = "React";
```

Bạn sẽ bị lỗi: `Uncaught SyntaxError: Identifier 'language' has already been declared` (biến "language" đã được định nghĩa rồi).

### Gán giá trị cho biến trước khi khai báo

Thực tế, bạn vẫn có thể gán giá trị cho biến mà không cần khai báo.

```js
message = "hello";
console.log(message); // hello
```

Tuy nhiên, nếu bạn sử dụng chế độ code nghiêm ngặt [`"use strict"`](/bai-viet/khoa-hoc-javascript/use-strict-trong-js/) thì bạn sẽ bị lỗi.

```js
"use strict";

message = "hello";
console.log(message);
```

Lỗi cụ thể là: `Uncaught ReferenceError: message is not defined` (biến "message" chưa được định nghĩa).

## Tổng kết

Sau đây là tóm tắt những kiến thức cần nhớ về biến là gì, cách khai báo biến trong JavaScript và quy tắc đặt tên biến:

- Biến là "tên biểu tượng" dùng để đại diện cho một giá trị. Và giá trị của biến có thể thay đổi trong chương trình.
- Để khai báo biến, bạn dùng từ khóa `let` với cú pháp: `let <tên biến>;`.
- Có thể thay đổi giá trị của biến bằng cách gán giá trị mới cho biến, hoặc gán bằng giá trị của biến khác.
- Quy tắc đặt tên biến:
  - Bắt đầu bằng chữ cái, dấu gạch dưới (`_`) hoặc kí tự "đô la" (`$`).
  - Sau kí tự đầu tiên, ngoài những kí tự trên, bạn có thể sử dụng thêm số (0-9).
  - Không sử dụng từ khoá và từ dự trữ.
- Tên biến phân biệt chữ hoa và thường
- Nên đặt tên biến dễ nhìn, dễ đọc và thống nhất theo một chuẩn.

## Thực hành

### Bài 1: Các tên biến sau đúng hay sai?

```js
let num = 100;
let _result3@ = "haha";
let $_$ = "hehehe";
let 2me = 'love';
let I_WANT_TO_EAT = "just eat it";
let dientihinhvuong = 999;
let a%b = 50;
let var = 'oh no';
```

Và chỉ ra chính xác lỗi sai là gì?

Đáp án:

```js
let num = 100; // Đúng
let _result3@ = "haha"; // Sai: vì sử dụng kí tự đặc biệt @
let имя_abc = "hehehe"; // Đúng: được phép sử dụng kí tự không phải Latinh
let 2me = 'love'; // Sai: vì bắt đầu bằng số
let I_WANT_TO_EAT = "just eat it"; // Đúng
let _dientihinhvuong = 10000; // Đúng: được phép bắt đầu dấu _
let a%b = 50; // Sai: vì có kí tự đặc biệt %
let var = 'oh no'; // Sai: vì tên biến trùng từ khóa var
```

### Bài 2: Khai báo và gán giá trị cho biến

1.  Khai báo hai biến **message** và **name**.
2.  Gán giá trị cho biến **name** là tên của bạn, ví dụ: "Lam".
3.  Gán giá trị của biến **name** cho biến **message**.
4.  In ra console giá trị của biến **message** (kết quả phải là giá trị từ bước 2).

Đáp án

```js
// 1. Khai báo hai biến "message" và "name".
let message;
let name;

// 2. Gán giá trị cho biến "name" là tên của bạn, ví dụ: "Lam".
name = "Lam";

// 3. Gán giá trị của biến "name" cho biến "message".
message = name;

// 4. In ra console giá trị của biến "message" (kết quả phải là giá trị từ bước 2).
console.log(message); // Lam
```

### Bài 3: Hoán đổi giá trị hai biến

1.  Khai báo và gán giá trị cho hai biến **x** và **y** (với giá trị là chuỗi ký tự tùy ý).
2.  Hoán đổi giá trị của hai biến **x** và **y** cho nhau.
3.  In ra console giá trị hai biến **x** và **y** sau khi hoán đổi.

Ví dụ: ban đầu `x = "hello"` và `y = "world"`. Sau khi hoán đổi thì `x = "world"` và `y = "hello"`.

Đáp án

```js
// 1. Khai báo và gán giá trị cho hai biến "x" và "y" (giá trị là chuỗi ký tự tùy ý).
let x = "hello";
let y = "world";

// 2. Hoán đổi giá trị của hai biến "x" và "y" cho nhau.
// - Bạn cần khai báo thêm một biến trung gian để lưu giá trị của một biến.
// - Giả sử là biến x:
let z = x;

// - Sau đó, gán giá trị của biến y cho biến x.
x = y;

// - Cuối cùng, gán giá trị của biến z cho biến y. Lúc này, ta đã hoán đổi xong rồi.
y = z;

// 3. In ra console giá trị hai biến "x" và "y" sau khi hoán đổi.
console.log(x); // world
console.log(y); // hello
```
