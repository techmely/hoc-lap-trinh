---
title: "Tất tần tật về hàm trong Javascript"
description: "Tất tần tật về hàm trong Javascript"
keywords: ["khoá học javascript",
"Tất tần tật về hàm trong Javascript",
"hàm trong javascript",
"tat ca cac ham trong javascript",
"cac loai function trong javascript",
"cach goi ham trong javascript",
"Tất cả các hàm trong JavaScript",
"ham trong javascript là gì",
"các hàm có sẵn trong javascript",
"hàm trong js"
]
chapter:
  name: "Javascript cơ bản"
  slug: "chuong-02-javascript-co-ban"
category:
  name: "Javascript"
  slug: "javascript"
image: https://kungfutech.edu.vn/thumbnail.png
position: 16
---

Function JavaScript (hàm trong JavaScript) là một thành phần không thể thiếu trong cấu trúc chương trình.

Hàm giúp chương trình trở nên rõ ràng, dễ hiểu bằng cách gộp những đoạn code lặp lại. Nhờ vậy mà việc bảo trì phần mềm cũng dễ dàng hơn.

Ngoài ra, một hàm tốt (độc lập và thực hiện một chức năng nhất định) có thể tái sử dụng trong nhiều dự án khác nhau. Điều này giúp nâng cao hiệu suất công việc của lập trình viên.

> 💡 Trong bài viết về [tương tác người dùng với: alert, confirm và prompt](/bai-viet/khoa-hoc-javascript/ham-tuong-tac-voi-nguoi-dung-alert-confirm-prompt) bạn đã biết về các hàm có sẵn như: `alert()`, `confirm()` và `prompt()`.

Sau đây, mình sẽ giới thiệu những thành phần cơ bản của hàm trong JavaScript. Qua đó, bạn sẽ hiểu hàm là gì, cách xây dựng hàm và ứng dụng hàm vào các dự án.

## Hàm trong Javascript là gì?

Hàm trong JavaScript là một chương trình con giúp thực thi một công việc cụ thể. Để định nghĩa hàm trong JavaScript, bạn sử dụng từ khoá `function` với cú pháp là:

```js
function functionName([parameter1], [parameter2],...) {
  statement1;
  statement2;
  ...
}
```

Trong đó:

- `function`: là một từ khóa trong JavaScript dùng để định nghĩa hàm.
- **functionName**: là tên của hàm (tên tự đặt).
- `([parameter1], [parameter2],...)`: danh sách các tham số của hàm (không bắt buộc).
- Cuối cùng là **thân hàm**, bao gồm một hoặc nhiều câu lệnh nằm trong cặp dấu ngoặc `{}`.

Ví dụ hàm `sayHello()`:

```js
function sayHello() {
  console.log("Hello from completejavascript.com");
}
```

Để gọi hàm, bạn sử dụng tên hàm:

```js
function sayHello() {
  console.log("Hello from completejavascript.com");
}

sayHello();
sayHello();
// Hello from completejavascript.com
// Hello from completejavascript.com
```

Khi gọi hàm, đoạn code bên trong thân hàm sẽ được thực thi. Trong ví dụ trên, đoạn code `console.log` được thực hiện hai lần (ứng với hai lần gọi hàm).

Bạn có thể thấy rằng, hàm giúp tránh lặp lại code. Giả sử bạn cần thay đổi nội dung với `console.log` trên, bạn chỉ cần thay đổi **một chỗ** (bên trong thân hàm).

Đến đây chắc bạn đã phần nào hiểu được hàm là gì rồi phải không? Sau đây, mình sẽ đi vào chi tiết các đặc điểm của hàm trong JavaScript.

## Biến cục bộ trong hàm

Một [biến](/bai-viet/khoa-hoc-javascript/bien-trong-javascript) được khai báo bên trong hàm, chỉ sử dụng được bên trong thân hàm đó. Biến này gọi là **biến cục bộ** (hay **biến địa phương**).

Ví dụ về biến cục bộ trong JavaScript:

```js
function sayHello() {
  const message = "Hello from completejavascript.com";
  console.log(message);
}

sayHello(); // Hello from completejavascript.com

console.log(message); // Uncaught ReferenceError: message is not defined
```

Trong ví dụ trên, biến `message` là biến cục bộ bên trong hàm `sayHello`. Tức là biến `message` chỉ dùng được ở trong thân hàm `sayHello`.

Khi bạn cố gắng truy cập vào biến `message` ở ngoài hàm, bạn sẽ bị lỗi **Uncaught ReferenceError: message is not defined**.

## Biến ngoài hàm trong JavaScript

Một hàm trong JavaScript có thể truy cập vào biến được khai báo bên ngoài hàm, ví dụ:

```js
let message = "Hello from completejavascript.com";
function sayHello() {
  console.log(message);
}

sayHello(); // Hello from completejavascript.com
```

Hơn nữa, bạn có thể thay đổi giá trị của biến ngoài hàm từ trong thân hàm:

```js
let message = "Hello from completejavascript.com";
function sayHello() {
  message = "Hi!";
  console.log(message);
}

sayHello(); // Hi!
console.log(message); // Hi!
```

Tuy nhiên, nếu bên trong thân hàm **khai báo một biến trùng tên** với biến ngoài hàm thì biến ngoài hàm "bị bỏ qua":

```js
let message = "Hello from completejavascript.com";
function sayHello() {
  let message = "Hi!";
  console.log(message);
}

sayHello(); // Hi!
console.log(message); // Hello from completejavascript.com
```

📝 **Biến toàn cục**

- Một biến được khai báo ở ngoài tất cả các hàm, gọi là **biến toàn cục**.
- Biến toàn cục có thể được sử dụng và thay đổi giá trị ở mọi nơi trong chương trình. Vì vậy, bạn nên hạn chế sử dụng biến toàn cục.
- Điều này giúp hàm trở nên tốt hơn, dễ dàng tái sử dụng hơn (vì nó độc lập với các biến bên ngoài).

## Truyền tham số vào hàm

Trong trường hợp bạn muốn sử dụng giá trị của biến bên ngoài vào trong thân hàm, bạn có thể truyền tham số vào hàm (thay vì sử dụng biến toàn cục).

Ví dụ truyền tham số vào hàm:

```js
function sayHello(message) {
  console.log(message);
}

sayHello("Hello!"); // Hello!
sayHello("Hi!"); // Hi!
```

Khi hàm `sayHello` được gọi, giá trị [string](/bai-viet/khoa-hoc-javascript/cac-kieu-du-lieu-trong-javascript/) được sao chép (copy) vào biến cục bộ `message`. Trong thân hàm sẽ sử dụng biến cục bộ đó.

<content-info>

khi truyền tham số vào hàm (ngoại trừ object là kiểu dữ liệu tham chiếu), hàm trong JavaScript luôn thực hiện sao chép dữ liệu mà không làm thay đổi giá trị biến bên ngoài.

</content-info>

Ví dụ:

```js
let message = "Hello from completejavascript.com";
function sayHello(message) {
  message = "Hi!";
  console.log(message);
}

sayHello(); // Hi!
console.log(message); // Hello from completejavascript.com
```

Bạn thấy rằng là bên trong hàm đã gán giá trị `Hi!` cho biến `message`. Nhưng giá trị của biến `message` bên ngoài không hề thay đổi.

> 📝 Số lượng tham số của hàm là không giới hạn.

Ví dụ hàm có nhiều tham số:

```js
function sayHello(message, site) {
  console.log(message + " from " + site);
}

sayHello("Hello", "completejavascript.com"); // Hello from completejavascript.com
```

## Giá trị tham số mặc định

Đối với hàm có tham số mà khi gọi hàm, bạn không truyền giá trị vào thì giá trị của tham số đó là `undefined`, ví dụ:

```js
function sayHello(message, site) {
  console.log(message + " from " + site);
}

sayHello("Hello"); // Hello from undefined
```

Trong trường hợp này, bạn có thể định nghĩa "giá trị mặc định" cho tham số bằng cách sử dụng [toán tử](/bai-viet/khoa-hoc-javascript/toan-tu-trong-javascript) gán `=` như sau:

```js
function sayHello(message, site = "completejavascript.com") {
  console.log(message + " from " + site);
}

sayHello("Hello"); // Hello from completejavascript.com
```

Lúc này, nếu bạn không truyền giá trị vào tham số `site` thì giá trị của nó mặc định là `completejavascript.com`.

Trong ví dụ trên, giá trị mặc định chỉ là một giá trị `string`. Tuy nhiên, giá trị mặc định có thể là một **biểu thức** hoặc thậm chí là một **hàm khác**, ví dụ:

```js
function aFunction() {
  // code
}

function sayHello(message, site = aFunction()) {
  console.log(message + " from " + site);
}
```

Trong ví trên, hàm `aFunction()` chỉ được gọi khi bạn không truyền giá trị cho tham số `site`.

## Return trong JavaScript

Hàm trong JavaScript có thể trả về giá trị khi gọi hàm.

Ví dụ hàm tính tổng hai số:

```js
function sum(a, b) {
  return a + b;
}

const result = sum(1, 2);
console.log(result); // 3
```

Từ khóa `return` trong JavaScript có thể đặt ở bất kỳ đâu trong thân hàm. Khi gặp từ khóa `return`, hàm sẽ dừng lại và trả về giá trị sau `return`.

**Có thể dùng nhiều từ khóa `return` trong hàm:**

```js
function sum(a, b) {
  if (a === null || a === undefined) {
    console.log("Tham số không hợp lệ!");
    return;
  }

  if (b === null || b === undefined) {
    console.log("Tham số không hợp lệ!");
    return;
  }

  return a + b;
}

const result1 = sum(); // Tham số không hợp lệ!
```

Ví dụ trên, mình kiểm tra điều kiện cho `a` và `b`. Nếu chúng bằng `null` hoặc `undefined` thì sẽ `return` luôn mà không thực hiện tính tổng.

Bạn cũng thấy rằng, hai vị trí `return` đầu tiên không có giá trị nào theo sau. Khi đó, giá trị trả về mặc định là `undefined`:

```js
function sum(a, b) {
  return;
}

let r = sum(1, 2);
console.log(r); // undefined
```

Ngoài ra, nếu hàm không có `return` thì giá trị trả về cũng là `undefined`:

```js
function sum(a, b) {}

let r = sum(1, 2);
console.log(r); // undefined
```

<content-info>

không được xuống dòng ngay sau `return`. Vì JavaScript sẽ hiểu là bạn không `return` giá trị nào cả.

</content-info>

Ví dụ:

```js
function sum(a, b) {
  return;
  a + b;
}

const result = sum(1, 2);
console.log(result); // undefined
```

Trình thông dịch JavaScript sẽ tự động thêm dấu `;` ngay sau `return`. Do đó, giá trị trả về của hàm trên là `undefined`. Và thành phần `a + b` phía dưới sẽ không bao giờ được chạy tới.

Nếu cần xuống dòng thì bạn phải đưa giá trị trả về vào trong cặp dấu ngoặc đơn `()` như sau:

```js
function sum(a, b) {
  return a + b;
}

const result = sum(1, 2);
console.log(result); // 3
```

## Cách đặt tên hàm trong JavaScript

Quy tắc đặt tên hàm trong JavaScript cũng giống như quy tắc đặt tên biến hay hằng trong JavaScript:

- Bắt đầu bằng chữ cái, dấu gạch dưới (`_`) hoặc kí tự "đô la" (`$`).
- Sau kí tự đầu tiên, ngoài những kí tự trên, bạn có thể sử dụng thêm số (0-9).
- Không sử dụng từ khoá và từ dự trữ.

**Chuẩn hóa cách đặt tên hàm**

Vì hàm ứng với một hành động, nên tên hàm chuẩn thường bắt đầu bằng một **động từ**.

Ví dụ một số động từ hay dùng để đặt tên hàm:

- `get...` - trả về một giá trị.
- `set...` - gán giá trị cho một biến.
- `check...` - kiểm tra một số thứ và trả về giá trị `boolean`.
- `display...` - hiển thị một số thứ.
- ...

Dĩ nhiên, JavaScript không quy định bạn phải đặt tên như vậy. Bạn chỉ cần đặt tên đúng theo quy tắc phía trên là đủ.

Nhưng rõ ràng là nếu bạn đặt tên đúng chuẩn thì đồng nghiệp hoặc chính bản thân bạn khi đọc code sẽ dễ dàng hiểu được ý nghĩa của từng hàm.

## Sự phát sinh hàm trong chương trình

Khi lập trình, thông thường sẽ có hai trường hợp mà bạn nên viết hàm:

- Một đoạn chương trình được lặp đi, lặp lại nhiều lần. Việc gom chúng lại thành một hàm sẽ giúp chương trình ngắn gọn hơn, dễ hiểu hơn. Và khi cần thay đổi, bạn chỉ cần sửa một lần trong nội dung hàm, thay vì phải sửa nhiều chỗ.
- Bạn cần tách toàn bộ chương trình thành những phần nhỏ hơn. Hay còn gọi là **module hoá**. Lúc này, bạn có thể xây dựng logic cho toàn bộ chương trình trước khi thật sự định nghĩa nội dung từng hàm. Cách tiếp cận này gọi là "top-down".

Với những dự án lớn, mỗi thành viên thường chỉ được làm những module nhỏ trong toàn bộ một project lớn.

Sau đó khi các module nhỏ hoàn thành, sẽ có người ghép những module nhỏ đó thành một chương trình hoàn chỉnh.

Do đó, việc phân chia chương trình thành những hàm tốt là vô cùng quan trọng.

**Như thế nào là một hàm tốt?**

Đây là một câu hỏi rất khó để trả lời. Theo mình, hàm tốt là hàm thỏa mãn một số điều kiện sau:

- Một hàm chỉ thực hiện một chức năng duy nhất
- Độc lập với các yếu tố bên ngoài (biến toàn cục, môi trường thực thi,...)
- Dễ dàng tái sử dụng

Tuy nhiên, không phải lúc nào bạn cũng có thể thoả mãn những yêu cầu trên. Hoặc không nhất thiết phải thoả mãn tất cả những yêu cầu trên.

## Pure function và non-pure function

Nhìn chung, có hai loại hàm trong JavaScript là **pure** function (hàm thuần khiết) và **non-pure** function (hàm không thuần khiết).

**Hàm thuần khiết** là hàm không phụ thuộc vào yếu tố bên ngoài (biến toàn cục, môi trường thực thi,...). Bất cứ khi nào bạn gọi hàm thuần khiết với cùng một đối số thì kết quả trả về luôn giống nhau.

Do đó, pure function rất dễ để sử dụng, tái sử dụng hay bảo trì,... Theo mình, hàm thuần khiết là một hàm tốt.

Ví dụ hàm thuần khiết:

```js
function pureFunc(number, factor) {
  return number * factor;
}

let ret = pureFunc(2, 10);
console.log(ret); // 20
```

Bạn thấy rằng, với cùng một giá trị truyền vào là `2` và `10` thì kết quả luôn là `20`. Do đó, hàm trên là **hàm thuần khiết**.

Ngược lại với hàm thuần khiết, **hàm không thuần khiết** là hàm phụ thuộc vào biến toàn cục hay môi trường thực thi.

Vì vậy, khi bạn gọi cùng một hàm với cùng một đối số, nhưng kết quả lại có thể khác nhau.

```js
let factor = 10;

function nonPureFunc(number) {
  return number * factor;
}

let ret = nonPureFunc(2);
console.log(ret); // 20

factor = 11;
ret = nonPureFunc(2);
console.log(ret); // => 22
```

Rõ ràng, hàm `nonPureFunc` không phải là hàm thuần khiết. Vì hàm này phụ thuộc vào biến ngoài hàm là `factor`.

Nghĩa là khi giá trị của biến `factor` thay đổi, kết quả trả về của hàm cũng thay đổi (dù cho cùng giá trị truyền vào là `2`).

## Tổng kết

Vậy hàm là gì?

Hàm trong JavaScript là một chương trình con giúp thực thi một công việc cụ thể với cú pháp là:

```js
function functionName([parameter1], [parameter2],...) {
      statement1;
      statement2;
      ...
    }
```

Trong đó:

- Tham số truyền vào hàm được sao chép vào biến cục bộ bên trong hàm.
- Trường hợp không truyền giá trị vào thì giá trị của tham số là `undefined`. Bạn có thể sử dụng toán tử `=` để khai báo giá trị mặc định cho tham số trong hàm.
- Biến cục bộ khai báo bên trong hàm chỉ dùng được ở thân hàm. Code bên ngoài không thể truy cập vào biến cục bộ trong hàm.
- Hàm có thể đọc và cập nhật giá trị của biến ngoài hàm. Nhưng khi bên trong hàm có khai báo một biến cùng tên với biến ngoài hàm thì biến ngoài hàm bị "bỏ qua".
- Hàm có thể trả về giá trị bằng cách dùng từ khóa `return`. Có thể có nhiều từ khóa `return` trong thân hàm. Khi gặp từ khóa `return`, hàm sẽ dừng lại ngay lập tức và trả về giá trị sau `return`.
- Nếu không có giá trị, biểu thức,... nào sau `return`, hoặc không có từ khóa `return` thì giá trị trả về của hàm là `undefined`.

Quy tắc đặt tên hàm cũng giống quy tắc đặt tên biến và hằng. Và tên hàm nên bắt đầu bằng một động từ.

Nên ưu tiên viết hàm **thuần khiết** để dễ dàng tái sử dụng, dễ dàng kiểm thử và tránh lỗi.

## Thực hành

### Bài 1

Viết hàm trả về giá trị nhỏ nhất của hai số (giả sử giá trị truyền nào luôn là số).

Xem đáp án

```js
function min(a, b) {
  return a < b ? a : b;
}

min(2, 5); // 2
min(4, -1); // -1
min(3, 3); // 3
```

Trường hợp hai số truyền vào bằng nhau thì dĩ nhiên kết quả là giá trị của hai số đó.

### Bài 2

Viết hàm kiểm tra xem một số có phải là số nguyên tố hay không. Nếu là số nguyên tố thì trả về `true`. Ngược lại, trả về `false`.

Xem đáp án

```js
function isPrime(number) {
  if (isNaN(number)) return false;

  if (number < 2) return false;
  if (number === 2) return true;

  for (i = 2; i * i <= number; i++) {
    if (number % i === 0) return false;
  }

  return true;
}

// Ví dụ:
isPrime("abc"); // false
isPrime(0); // false
isPrime(2); // true
isPrime(5); // true
isPrime(6); // false
```

Trong đó, hàm `isNaN(number)` dùng để kiểm tra giá trị của biến `number` xem có phải là `NaN` hay không. Nói cách khác, nếu `isNaN(number)` trả về `false` thì giá trị của `number` là số.
