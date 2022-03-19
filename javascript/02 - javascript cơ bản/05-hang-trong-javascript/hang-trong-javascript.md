---
title: "Tìm hiểu hằng trong JavaScript"
description: "Tìm hiểu về hằng trong JavaScript"
keywords:
  [
    "khoá học javascript",
    "tìm hiểu hằng trong JavaScript",
    "khai bao hang so trong javascript",
    "hằng số trong JavaScript",
    "hằng số trong javascript cơ bản",
    "hằng số trong javascript dùng để làm gì",
    "hằng số trong javascript gồm",
    "Khai báo hằng số trong Javascript",
    "hang javascript code",
    "hang so la gi",
  ]
chapter:
  name: "Javascript cơ bản"
  slug: "chuong-02-javascript-co-ban"
category:
  name: "Javascript"
  slug: "javascript"
image: https://kungfutech.edu.vn/thumbnail.png
position: 5
---

Tương tự như [biến](/bai-viet/khoa-hoc-javascript/bien-trong-javascript/), hằng cũng là một thành phần quan trọng trong lập trình JavaScript. Sau đây, mình sẽ tìm hiểu xem hằng là gì, cách khai báo hằng trong JavaScript, cách đặt tên hằng. Đồng thời, mình so sánh sự khác nhau giữa hằng và biến trong JavaScript.

## Hằng trong Javascript là gì?

Hằng là "tên biểu tượng" đại diện cho một giá trị không thay đổi trong chương trình.

![Hằng trong Javascript](https://user-images.githubusercontent.com/29374426/156800339-c6d77de6-1f94-4755-8319-28be171e50ab.png)

**Ví dụ**: gọi PI là [số Pi](https://vi.wikipedia.org/wiki/Pi) trong toán học, có giá trị không đổi là **3.14159**. Khi đó, PI gọi là hằng số.

## Cách khai báo hằng trong JavaScript

Để khai báo hằng trong JavaScript, bạn dùng từ khóa `const`, với cú pháp như sau:

```js
const <tên hằng> = <giá trị của hằng>;
```

Ví dụ với số PI trên:

```js
const PI = 3.14159;
```

Để truy cập giá trị của hằng, bạn dùng trực tiếp tên của hằng:

```js
const PI = 3.14159;

console.log(PI); // Kết quả hiển trị trên console: 3.14159
```

Để khai báo nhiều hằng số, bạn có thể sử dụng dấy phẩy (`,`) để ngăn cách các hằng trên cùng một dòng:

```js
const PI = 3.141519,
  MAX_ITEM = 1000000000,
  MIN_ITEM = 0;
```

Hoặc bạn cũng có thể viết như sau:

```js
const PI = 3.141519,
  MAX_ITEM = 1000000000,
  MIN_ITEM = 0;
```

Hoặc viết với dấu phẩy trên đầu:

```js
const PI = 3.141519,
  MAX_ITEM = 1000000000,
  MIN_ITEM = 0;
```

Tuy nhiên, mình thấy việc khai báo mỗi hằng số trên một dòng là dễ nhìn hơn cả:

```js
const PI = 3.141519;
const MAX_ITEM = 1000000000;
const MIN_ITEM = 0;
```

Về cơ bản, các cách trên là giống nhau. Tùy thuộc sở thích của bạn mà lựa chọn sao cho phù hợp.

## Quy tắc đặt tên hằng trong JavaScript

Quy tắc đặt tên hằng trong JS cũng giống quy tắc đặt tên biến trong JavaScript. Sau đây, mình nhắc lại các quy tắc đặt tên cho bạn tiện theo dõi:

- Bắt đầu bằng chữ cái, dấu gạch dưới (`_`) hoặc kí tự "đô la" (`$`).
- Sau kí tự đầu tiên, ngoài những kí tự trên, bạn có thể sử dụng thêm số (0-9).
- Không sử dụng từ khoá và từ dự trữ.

Từ khoá (**keywords**) là những từ mang ý nghĩa đặc biệt. Từ **const** là một từ khoá, với ý nghĩa là để khai báo hằng.

Từ dự trữ (**reserved words**) là những từ sẽ được dùng làm từ khoá cho những phiên bản sau của JavaScript. Bạn không thể sử dụng từ khoá hay từ dự trữ để đặt tên cho hằng số.

Danh sách những từ khoá và những từ dự trữ:

`break` `case` `catch` `class` `const` `continue` `debugger` `default` `delete` `do` `else` `enum` `export` `extends` `false` `finally` `for` `function` `if` `implements` `import` `in` `instanceof` `interface` `let` `new` `null` `package` `private` `protected` `public` `return` `static` `super` `switch` `this` `throw` `true` `try` `typeof` `var` `void` `while` `with` `yield`

<div class="example">những tên hằng hợp lệ:</div>

```js
const temp = 1000;
const _result2 = 99;
const $___$ = "hehehe";
const I_AM_STRONG = true;
const dientichhinhvuong = 6996;
```

<div class="example">những tên hằng không hợp lệ:</div>

```js
const vertex% = 50;     // sử dụng kí tự đặc biệt %
    const 4me = 'passion';  // bắt đầu bằng số
    const while = 'coding'; // sử dụng từ khoá "while"
```

<content-info>
📝 Một số **chú ý** khi đặt tên biến:

<ul>
<li>Tên biến trong JavaScript có phân biệt **CHỮ HOA** và **chữ thường**. Ví dụ hai biến language và LanGuage là hai biến khác nhau.</li>
<li>Bạn có thể sử dụng những chữ cái không phải chữ cái Latinh để đặt tên biến. Nhưng điều này là không nên. Bạn nên sử dụng chữ cái Latinh (a-z) để đặt tên biến.</li>
<li>Tốt nhất là đặt theo chuẩn tiếng Anh để mọi người trên thế giới có thể hiểu code của bạn.</li>
</ul>
</content-info>

## Chuẩn hóa cách đặt tên hằng số

Cũng lại tương tự như biến, bạn chỉ cần đặt tên hằng đúng theo quy tắc trên là đủ. Tuy nhiên, nếu nói về chuẩn hóa thì mình thấy có hai cách đặt tên hằng phổ biến như sau.

**Cách 1: Đối với những hằng số biết trước khi lập trình**

<div class="example">Bạn cần lưu mã màu của một số màu thường dùng trong dự án:</div>

```js
const COLOR_BLACK = "#000000";
const COLOR_WHITE = "#FFFFFF";
const COLOR_RED = "#FF0000";
const COLOR_GREEN = "#00FF00";
const COLOR_BLUE = "#0000FF";
```

Đối với những hằng số kiểu này, bạn **VIẾT IN HOA** toàn bộ các chữ cái và sử dụng dấu gạch dưới (`_`) để ngăn cách các từ cho dễ đọc.

**Cách 2: Đối với những hằng số được sinh ra trong quá trình chạy**

<div class="example">Bạn cần lưu thời gian tải trang:</div>

```js
const timeToLoadPage = /* Xử lý một số thứ để tính ra thời gian tải trang */
```

Rõ ràng bạn không thể biết **chính xác** thời gian tải trang lúc lập trình nên trang web. Vì thời gian tải trang chính xác phụ thuộc vào các yếu tố bên ngoài như: tốc độ mạng, khả năng xử lý của server,...

Nhưng một khi trang web đã tải xong rồi thì giá trị này lại không thay đổi trong toàn bộ chương trình.

Đối với những hằng số kiểu này, bạn sử dụng cách đặt tên theo **camelCase** (viết thường từ đầu tiên, và viết hoa chữ cái đầu của các từ tiếp theo).

## Lợi ích của việc sử dụng hằng số

➤ Có thể nhiều bạn đặt câu hỏi: **Tại sao có biến rồi lại còn sinh ra hằng làm gì?**

Trong lập trình, luôn có những giá trị không bao giờ thay đổi trong toàn bộ chương trình.

Nếu chỉ sử dụng biến thì rất có thể bạn hoặc đồng nghiệp sẽ vô tình thay đổi giá trị của biến. Điều này dẫn đến những lỗi sai mà không thể lường trước được.

➤ Hoặc có bạn bảo rằng: **Tại sao không sử dụng trực tiếp giá trị của hằng số luôn?**

Trong ví dụ về màu trên, giả sử bạn không khai báo hằng `COLOR_BLACK` mà sử dụng trực tiếp `#000000`. Kiểu này trong lập trình gọi là **hard-coded**.

Cách này **thường không tốt**.

Nếu bạn sử dụng `#000000` ở một chỗ thì không sao. Nhưng nếu bạn dùng ở nhiều nơi và giả sử mình muốn thay đổi mã màu đen thành `#111111` thì mình phải tìm kiếm tất cả những chỗ sử dụng `#000000` để đổi thành `#111111`.

Việc làm này rất dễ **bỏ sót** một vài chỗ, dẫn đến bug chương trình. Ngược lại, nếu mình sử dụng hằng `COLOR_BLACK` thì mình chỉ cần sửa đúng một chỗ.

Ngoài ra, bạn có thể thấy:

- Việc đọc `COLOR_BLACK` dễ hơn `#000000` rất nhiều mà lại tránh nhầm lẫn.
- Thêm nữa `COLOR_BLACK` có ý nghĩa hơn `#000000`. Vì với `COLOR_BLACK`, bạn biết ngay đó là màu đen. Còn với `#000000`, bạn có thể không biết đó là màu gì trong lần đầu tiên tiếp xúc.

## Một số lỗi với hằng trong JavaScript

Khi sử dụng hằng trong JavaScript, bạn có thể mắc phải một số lỗi như sau.

### Không gán ngay giá trị cho hằng khi khởi tạo

Bạn có thể thấy sự khác biệt giữa hằng và biến trong việc khai báo.

Đối với biến trong JS, bạn có thể khai báo biến trước rồi gán giá trị cho biến sau.

Đối với hằng trong JS, bạn phải **gán ngay giá trị** cho hằng sau khi khai báo. Ngược lại, bạn sẽ bị lỗi:

```js
const PI;
    // Uncaught SyntaxError: Missing initializer in const declaration
```

### Thay đổi giá trị của hằng

Hằng số không thể thay đổi giá trị trong toàn bộ chương trình. Việc bạn thay đổi giá trị của hằng sẽ dẫn đến lỗi như sau:

```js
const PI = 3.14159;

PI = 100; // Uncaught TypeError: Assignment to constant variable.
```

## Tổng kết

Vậy hằng là gì?

- Hằng là "tên biểu tượng" đại diện cho một giá trị không thay đổi trong chương trình.
- Để khai báo hằng trong JavaScript, bạn dùng từ khóa **const** với cú pháp: `const <tên hằng> = <giá trị của hằng>;`.
- Với **chú ý** là: bạn bắt buộc phải gán giá trị cho hằng ngay khi khai báo.
- Quy tắc đặt tên hằng cũng giống như quy tắc đặt tên biến trong JavaScript:
  - Bắt đầu bằng chữ cái, dấu gạch dưới (`_`) hoặc kí tự "đô la" (`$`).
  - Sau kí tự đầu tiên, ngoài những kí tự trên, bạn có thể sử dụng thêm số (0-9).
  - Không sử dụng từ khoá và từ dự trữ.
- Tên hằng phân biệt chữ hoa và thường
- Nên đặt tên hằng dễ nhìn, dễ đọc và thống nhất theo một chuẩn.
  - Với những hằng biết trước trong lúc lập trình: viết hoa các chữ cái và dùng dấu gạch dưới (`_`) để ngăn cách các từ (ví dụ `COLOR_BLACK`).
  - Với những hằng sinh ra trong quá trình chạy: đặt tên theo **camelCase** (ví dụ `timeToLoadPage`).

## Thực hành

### Bài 1: Các tên hằng sau đúng hay sai?

```js
const value = 111;
const _ret100@ = "lalala";
const $$__abc = "xyz";
const 1point = '2d';
const MAX_NUMBER = 1000000000;
const chu_vi_hinh_tron = 400;
const x*b = 404;
const if = true;
```

Và chỉ ra chính xác lỗi sai là gì?

Đáp án

```js
const value = 111; // Đúng
const _ret100^ = "lalala"; // Sai vì dùng kí tự đặc biệt ^
const $$__abc = "xyz"; // Đúng
const 1point = '2d'; // Sai vì bắt đầu bằng số
const MAX_NUMBER = 1000000000; // Đúng
const chu_vi_hinh_tron = 400; // Đúng
const x*b = 404; // Sai vì dùng kí tự đặc biệt *
const if = true; // Sai vì dùng từ khóa
```

### Bài 2: Khai báo và in ra giá trị của hằng

1.  Khai báo hai hằng **COLOR_ORANGE** và **COLOR_YELLOW** lần lượt là mã màu cam và màu vàng.
2.  In ra giá trị của hai hằng số trên ra [console.log](/bai-viet/khoa-hoc-javascript/dev-tools-la-gi/).
3.  Khai báo biến **currentColor** với giá trị bằng **COLOR_ORANGE**.
4.  In ra console giá trị của biến **currentColor** (kết quả phải là giá trị của hằng **COLOR_ORANGE**).

Đáp án

```js
// 1. Khai báo hai hằng "COLOR_ORANGE" và "COLOR_YELLOW"
const COLOR_ORANGE = "#FFA500";
const COLOR_YELLOW = "#FFFF00";

// 2. In ra giá trị của hai hằng số trên ra console.log.
console.log(COLOR_ORANGE); // #FFA500
console.log(COLOR_YELLOW); // #FFFF00

// 3. Khai báo biến "currentColor" với giá trị bằng "COLOR_ORANGE".
let currentColor = COLOR_ORANGE;

// 4. In ra console giá trị của biến "currentColor"
console.log(currentColor); // #FFA500
```
