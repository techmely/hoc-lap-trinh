---
title: "ES6 Modules trên trình duyệt"
description: "ES Modules với JavaScript thông thường. Bởi vì, ES Modules là một tính năng mới (từ ES6) dành cho các trình duyệt hiện đại."
keywords: [
"es6 modules tren trinh duyet",
"es6 modules tren trinh duyet la gi",
"Module trong JavaScript",
"Module trong JavaScript la gi",
"Module trong JavaScript co y nghia như thế nào",
"import trong es6 trong javascript",
"es6 modules tren trinh duyet trong javascript"
]
chapter:
  name: "ES6 Modules"
  slug: "chuong-10-es6-modules-tren-trinh-duyet"
category:
  name: "Javascript"
  slug: "javascript"
image: https://kungfutech.edu.vn/thumbnail.png
position: 1
---

Hiện tại, **ES Modules** đã được [support bởi khá nhiều các trình duyệt](https://caniuse.com/#feat=es6-module). Điều đó nghĩa là bạn có thể sử dụng ES Modules trực tiếp trên trình duyệt mà không cần phải cài đặt Node.js cùng với các công cụ như [Browserify](http://browserify.org/), [RequireJS](https://requirejs.org/), [Webpack](https://webpack.js.org/),...

Sau đây, mình sẽ tìm hiểu về ES Modules và cách sử dụng nó trực tiếp trên trình duyệt. Mời bạn theo dõi bài viết!

## Cơ bản về ES Modules

ES Modules (hay còn gọi là "JavaScript Modules", "JS Modules" hay "ECMAScript modules") là một tính năng mới của trình duyệt cho phép bạn làm việc với modules. Nhờ vậy, bạn có thể chia nhỏ chương trình ra thành các modules, với mỗi module có một chức năng riêng biệt.

Trong một module, bạn có thể sử dụng từ khoá [export](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Statements/export) để export bất kỳ kiểu dữ liệu nào như: biến số với var, let hay const, class, [function](/bai-viet/javascript/ham-trong-javascript),... Sau đó, bạn sử dụng từ khoá [import](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Statements/import) để sử dụng chúng ở một file khác.

Sử dụng ES Modules có một số lợi ích như:

- Giúp module hoá chương trình. Qua đó, việc xây dựng, kiểm thử và bảo trì code sẽ tốt hơn.
- Hỗ trợ **dynamic import()** giúp download modules khi cần thiết. Nhờ vậy, thời gian load trang sẽ giảm xuống.

Nói vậy thì cách sử dụng ES Modules có gì khác với JavaScript thông thường?

## ES Modules với JavaScript thông thường

Bởi vì, ES Modules là một tính năng mới (từ ES6) dành cho các trình duyệt hiện đại. Do đó, nó luôn luôn được sử dụng ở chế độ [Strict mode](/bai-viet/javascript/mo-so-loi-loi-strict-mode).

Tiếp theo, comment code theo kiểu HTML không được support ở modules, mặc dù nó vẫn hợp lệ ở JS thông thường. Ví dụ:

```js
/*
* Sử dụng comment kiểu HTML trong JavaScript thông thường,
* không sai, nhưng không nên dùng.
*/
const x = 42; <!-- TODO: Rename x to y.
// Cách sử dụng comment chuẩn
const x = 42; // TODO: Rename x to y.
```

Modules có phạm vi "lexical top-level". Nghĩa là khi bạn chạy `var foo = 42;` trong modules, JS sẽ không tạo ra một biến ở global với tên _foo_. Hay nói cách khác là `window.foo` sẽ trả về **undefined**.

Cuối cùng, từ khoá _export_ và _import_ chỉ sử dụng được ở modules mà không gọi được ở JavaScript thông thường.

Với những sự khác nhau trên, rõ ràng trình duyệt cần phải phân biệt được: đâu là JavaScript cho ES Modules và đâu là JavaScript thông thường để có thể xử lý cho đúng.

Vì vậy, phần dưới đây sẽ trình bày cách sử dụng ES Modules trên trình duyệt.

## Cách sử dụng ES Modules trên trình duyệt

Để khai báo một script là ES Modules, bạn phải thêm **attribute** cho nó là: `type="module"`.

```js
<script type="module" src="main.js"></script>
```

Nghĩa là với những trình duyệt hiện đại, nó sẽ hiểu được thuộc tính này. Và trình duyệt sẽ xử lý file _main.js_ theo kiểu của module.

**Nói vậy, đối với những trình duyệt cũ, không support ES modules thì sao?**

Để chương trình có thể chạy được ở cả trình duyệt cũ và mới thì mình phải định nghĩa thêm như này:

```js
<script type="module" src="main.js"></script>
<script nomodule src="fallback.js"></script>
```

Khi đó, đối với trình duyệt mới (support modules): nó sẽ hiểu thuộc tính `type="module"` và bỏ qua _script_ với thuộc tính **nomodule**. Hay nói cách khác, chương trình sẽ nhận _main.js_ và bỏ qua _fallback.js_.

Với trình duyệt cũ (không support modules): nó không hiểu thuộc tính `type="module"` mà chỉ hiểu thuộc tính `type="text/javascript"` hoặc trường hợp không khai báo thuộc tính _type_ thì mặc định vẫn là `type="text/javascript"`. Do đó, chương trình sẽ bỏ qua _main.js_ và chỉ nhận _fallback.js_.

**Chú ý:** 2 file _main.js_ và _fallback.js_ có ý nghĩa tương đương nhau, chỉ khác nhau về cú pháp, cách viết.

## Ví dụ đơn giản về chương trình sử dụng ES Modules

Mình sẽ demo một chương trình cực kỳ đơn giản sử dụng Modules với các file là: _index.html_, _main.js_ và _lib.js_.

**index.html**:

```html
<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="UTF-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <meta http-equiv="X-UA-Compatible" content="ie=edge" />
    <title>Document</title>
  </head>
  <body>
    <script type="module" src="./main.js"></script>
  </body>
</html>
```

**main.js**:

```js
import { repeat, shout } from "./lib.js";

console.log("main.js");
console.log(repeat("hello"));
console.log(shout("Modules in action"));
```

**lib.js**:

```js
export const repeat = (string) => `${string} ${string}`;

export function shout(string) {
  return `${string.toUpperCase()}!`;
}
```

Trong file, _index.html_ mình khai báo script với `type="module"` và nội dung file là _main.js_. Tức file _main.js_ đóng vai trò là ES Modules. Trong file này, mình có sử dụng từ khoá _import_ để import nội dung từ một file modules khác _lib.js_. Dĩ nhiên, file _lib.js_ cũng là một ES Modules. Trong file này, mình sử dụng từ khoá _export_ để export ra 2 hàm cho _main.js_ sử dụng.

Kết quả hiện thị ra console là:

```sh
/*
* => main.js
* => hello hello
* => MODULES IN ACTION
*/
```

## Cú pháp cơ bản của ES Modules

Khi sử dụng modules, mình phải quan tâm đến cả phần _export_ (tạo modules) và _import_ (sử dụng modules). Có 2 kiểu export modules:

- **named** (theo tên): dùng để export nhiều giá trị trong một modules. Và khi import, bắt buộc phải sử dụng đúng tên đã export.
- **default** (mặc định): mỗi module chỉ cho phép export **default** một giá trị.

### Export, import theo tên

#### Export theo tên

Bạn có thể export bất kỳ kiểu dữ liệu nào với từ khoá export đặt trước khai báo biến:

```js
export let x = 1;
export var y = "a";
export const z = { x: 1, y: 2 };
export function add(a, b) {
  return a + b;
}
export class Utils {
  print(text) {
    console.log(text);
  }
}
```

Hoặc gộp chúng vào thành 1 [object](/bai-viet/javascript/object-la-gi-object-trong-javascript) với một từ khoá _export_:

```js
let x = 1;
var y = "a";
const z = { x: 1, y: 2 };
function add(a, b) {
  return a + b;
}
class Utils {
  print(text) {
    console.log(text);
  }
}

export { x, y, z, add, Utils };
```

Hoặc cũng có thể đổi tên chúng khi export:

```js
export { x as publicX, y as publicY, z as publicZ, add as sum, Utils as Tools };
```

#### Import theo tên

Mình phải import theo đúng tên đã export:

```js
import { x, y, z, add, Utils } from "./lib.js";

console.log(x); // 1
console.log(y); // a
console.log(z); // {x: 1, y: 2}
console.log(add(1, 2)); // 3
console.log(new Utils().print("hi")); // hi
```

Bên trên, mình `import` hết tất cả các giá trị. Tuy nhiên, bạn có thể chỉ `import` những thứ cần để sử dụng:

```js
import { x, y, z } from "./lib.js";

console.log(x); // 1
console.log(y); // a
console.log(z); // {x: 1, y: 2}
```

Ngoải ra, để tránh trường hợp trùng tên với biến khác, bạn có thể `import` và đồng thời đặt tên mới cho biến:

```js
import { x as newX, y as newY, z as newZ } from "./lib.js";

console.log(newX); // 1
console.log(newY); // a
console.log(newZ); // {x: 1, y: 2}
```

Hoặc import tất cả các giá trị ứng với một object với tên mới:

```js
import * as myModule from "./lib.js";

console.log(myModule.x); // 1
console.log(myModule.y); // a
console.log(myModule.z); // {x: 1, y: 2}
console.log(myModule.add(1, 2)); // 3
console.log(new myModule.Utils().print("hi")); // hi
```

<content-warning>

**Chú ý**: Trong trường hợp này, module export và import luôn luôn là một object.

</content-warning>

### Export, import default

Khác với trường hợp trên, trường hợp này luôn export và import trực tiếp với bất kỳ kiểu giá trị nào. Nghĩa là bạn export function thì khi import cũng là function,...

Vì khi export default, mỗi file sẽ chỉ cho phép export default 1 giá trị, nên mình sẽ lấy ví dụ đồng thời cho cả export và import luôn.

#### Export, import default biến

```js
// export ở file lib.js
let x = 1;
export default x;

// import ở file main.js
import variable from "./lib.js";
console.log(variable); // 1
```

Khi bạn import, giá trị của variable sẽ tương ứng với giá trị export default. Do đó, variable tương ứng với x, nên có giá trị là 1.

#### Export, import default function

```js
// export ở file lib.js
export default function(a, b) {
  return a + b;
}

// hoặc
function add(a, b) {
  return a + b;
}
export default add;

// import ở file main.js
import func from './lib.js';
console.log(func(1, 2));         // 3
```

#### Export, import default class

```js
// export ở file lib.js
export default class Utils {
  print(text) {
    console.log(text);
  }
}

// hoặc
class Utils {
  print(text) {
    console.log(text);
  }
}
export default Utils;

// import ở file main.js
import Tools from './lib.js';
console.log(new Tools().print("hi")); // hi
```

### Kết hợp export, import theo tên và default

Bên trên, mình ví dụ tách biệt 2 kiểu export, import. Nhưng thực tế, bạn có thể sử dụng kết hợp chúng:

```js
export let x = 1;
export var y = "a";
export const z = { x: 1, y: 2 };
export function add(a, b) {
  return a + b;
}
export default class Utils {
  print(text) {
    console.log(text);
  }
}
```

Bên trên, mình chỉ export default Utils, còn lại là export thông thường. Khi đó, mình sẽ import như sau:

```js
import Tools, { x, y, z, add } from "./lib.js";

console.log(x); // 1
console.log(y); // a
console.log(z); // {x: 1, y: 2}
console.log(add(1, 2)); // 3
console.log(new Tools().print("hi")); // hi
```

### Dynamic import

Thực tế, cách import bên trên là **static**. Nghĩa là đoạn code liên quan đến module luôn luôn load ngay từ thời điểm đầu. Tuy nhiên, bạn cũng có thể import theo kiểu **dynamic**. Tức là bạn sẽ chỉ load script khi nào cần thiết.

Ví dụ export:

```js
export let x = 1;
export var y = "a";
export const z = { x: 1, y: 2 };
export function add(a, b) {
  return a + b;
}
export class Utils {
  print(text) {
    console.log(text);
  }
}
```

Khi đó, cách dynamic import là:

```js
setTimeout(async () => {
  let { x, y, z, add, Utils } = await import("./lib.js");

  console.log(x); // 1
  console.log(y); // a
  console.log(z); // {x: 1, y: 2}
  console.log(add(1, 2)); // 3
  console.log(new Utils().print("hi")); // hi
}, 2000);
```

<content-warning>

**Chú ý**: hàm **setTimeout** trên chỉ là ví dụ để thể hiện việc delay khi load module.

</content-warning>

Với cách **dynamic import** này, **import** sẽ trả về một Promise. Do đó, bạn có thể sử dụng kết hợp với **async/await** như trên.

## Lời kết

Như vậy là mình đã trình bày xong những kiến thức cơ bản về ES Modules, cũng như cách sử dụng nó ngay trên trình duyệt.

Theo bạn, việc sử dụng ES Modules trực tiếp trên trình duyệt có thực sự cần thiết? Để lại quan điểm của bạn xuống phần bình luận nhé!

Xin chào và hẹn gặp lại, thân ái!

Tham khảo:

- [Using JavaScript modules on the web](https://developers.google.com/web/fundamentals/primers/modules)
- [Introduction to ES Modules](https://flaviocopes.com/es-modules/)
