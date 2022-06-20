---
title: "ES6 template string trong Javascript"
description: "ES6 Template String tạm gọi là một cú pháp, cho phép bạn viết biểu thức ngay bên trong string."
keywords: ["template string trong javascript",
"ES6 template string trong Javascript",
"string template javascript",
"ES6 trong javascript",
"template javascript",
"template string trong es6 javascript",
"template literals trong es6 javascript"
]
chapter:
  name: "Kiểu dữ liệu trong Javascript"
  slug: "chuong-04-kieu-du-lieu-trong-javascript"
category:
  name: "Javascript"
  slug: "javascript"
image: https://user-images.githubusercontent.com/29374426/168242173-f4c90841-cb1f-4f3f-b978-286dbc7fbd1e.png
position: 4
---

Có thể bạn thừa biết, phiên bản ES6 của JavaScript đã giới thiệu rất nhiều những [tính năng hay hấp dẫn](https://webapplog.com/es6/) của ngôn ngữ lập trình này. Một trong số đó là **Template literals** hay **Template String**. Nếu vậy thì sử dụng ES6 Template String có gì hay hơn so với string thông thường? Sau đây, mình và bạn sẽ cùng nhau tìm hiểu.

![ES6 template string trong Javascript](https://user-images.githubusercontent.com/29374426/168242173-f4c90841-cb1f-4f3f-b978-286dbc7fbd1e.png)


## ES6 Template String là gì?

ES6 Template String tạm gọi là một cú pháp, cho phép bạn viết biểu thức ngay bên trong [string](/bai-viet/javascript/cac-kieu-du-lieu-trong-javascript). Trong đó, thay vì sử dụng cặp dấu nháy đơn `''` hay nháy kép `""`, bạn sử dụng cặp dấu **backtick** hay **backqoute**, để biểu diễn string.

Ví dụ biểu diễn string sử dụng dấu backtick:

```js
`string`;
```

Khi đó, biểu thức bên trong template string sẽ được biểu diễn với cú pháp: `${expression}`, ví dụ:

```js
let name = "Lam Pham";
let greeting = `I'm ${name}`;

console.log(greeting); // I'm Lam Pham
```

Ở ví dụ này, biến `name` biểu diễn string thông thường và biến `greeting` biểu diễn template string.

Đến đây có lẽ bạn đã mường tượng ra cách sử dụng của Template String rồi và đang tự hỏi: **vậy thì template string có ưu điểm gì hơn so với việc sử dụng string thông thường không?**

## Những ưu điểm nổi bật của ES6 Template String

### Ghép nối string

Thông thường để ghép nối string trong JavaScript bạn có thể sử dụng phương thức [`concat`](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/String/concat) hoặc toán tử `+`.

**Ví dụ sử dụng phương thức `concat`:**

```js
let intro = "Hello everyone, I'm";
let firstName = "Lam";
let lastName = "Pham";

let full1 = intro.concat(" ", firstName, " ", lastName, ".");
console.log(full1); // Hello everyone, I'm Lam Pham.
```

**Ví dụ sử dụng toán tử `+`:**

```js
let intro = "Hello everyone, I'm";
let firstName = "Lam";
let lastName = "Pham";

let full2 = intro + " " + firstName + " " + lastName + ".";
console.log(full2); // Hello everyone, I'm Lam Pham.
```

Cả hai cách trên đều cho ra kết quả như mong muốn. Tuy nhiên, cách viết lại không trực quan và đôi khi còn khó theo dõi.

Trong khi đó, nếu sử dụng ES6 Template String thì bạn sẽ thấy cách viết **gọn gàng, dễ nhìn và đẹp hơn nhiều**.

```js
let intro = "Hello everyone, I'm";
let firstName = "Lam";
let lastName = "Pham";

let full3 = `${intro} ${firstName} ${lastName}.`;
console.log(full3); // Hello everyone, I'm Lam Pham.
```

### Sử dụng đồng thời nháy đơn và nháy kép

Để sử dụng **dấu nháy đơn hoặc nháy kép** trong string, bạn có thể sử dụng các cách sau đây:

► Sử dụng kí tự backslash `\`:

`let str = 'I\'m a "JavaScript Lover".'; console.log(str); // I'm a "JavaScript Lover".`

► Nếu muốn hiển thị **nháy đơn**, bạn có thể sử dụng **nháy kép** để biểu diễn string:

`let str = "I'm Lam Pham."; console.log(str); // I'm Lam Pham.`

► Nếu muốn hiển thị **nháy kép**, bạn có thể sử dụng **nháy đơn** để biểu diễn string:

`let str = 'Call me "JavaScript Lover"'; console.log(str); // Call me "JavaScript Lover"`

Nếu so sánh với những ngôn ngữ khác, việc JavaScript hỗ trợ sử dụng **nháy đơn hoặc nháy kép** để biểu diễn string đã tiện lợi hơn rất nhiều rồi.

Hơn nữa, khi sử dụng ES6 Template String, bạn chẳng cần phải quan tâm đến vấn đề này nữa, vì bạn đã có cặp dấu **backtick** rồi.

`let str = `I'm a "JavaScript Lover".`; console.log(str); // I'm a "JavaScript Lover".`

Với template string, bạn vừa có thể hiển thị dấu **nháy đơn và dấu nháy kép** mà không cần sử dụng đến kí tự `\`.

### Viết string trên nhiều dòng

Thông thường, để viết string trên nhiều dòng, bạn có thể sử dụng kí tự `\n` - **newline**.

```js
let str =
  "Hello everyone!\n" +
  "This is line 1 of multiline string example.\n" +
  "This is line 2 of multiline string example.";

console.log(str);
/*
    Hello everyone!
    This is line 1 of multiline string example.
    This is line 2 of multiline string example.
    */
```

Khi sử dụng ES6 Template String, bạn không cần dùng kí tự đó nữa:

```js
let str = `Hello everyone!
    This is line 1 of multiline string example.
    This is line 2 of multiline string example.`;

console.log(str);
/*
    Hello everyone!
    This is line 1 of multiline string example.
    This is line 2 of multiline string example.
    */
```

### Viết biểu thức toán học hoặc hàm ngay trong string

Cách thông thường:

```js
let x = 1;
let y = 2;
let sum = (x, y) => x + y;

console.log("Sum of x and y is: " + (x + y)); // Sum of x and y is: 3

console.log("Sum of x and y is: " + sum(x, y)); // Sum of x and y is: 3
```

Khi sử dụng ES6 Template String:

```js
let x = 1;
let y = 2;
let sum = (x, y) => x + y;

console.log(`Sum of x and y is: ${x + y}`); // Sum of x and y is: 3

console.log(`Sum of x and y is: ${sum(x, y)}`); // Sum of x and y is: 3
```

## Tổng kết

Sau đây là những kiến thức cần nhớ để sử dụng ES6 template string trong JavaScript:

- ES6 template string sử dụng dấu **backtick** để biểu diễn.
- ES6 template string giúp ghép nối string đơn giản hơn, không cần phải sử dụng toán tử `+` hay phương thức `concat` nữa.
- ES6 template string giúp sử dụng đồng thời dấu nháy đơn và nháy kép mà không cần dùng kí tự `\`.
- ES6 template string giúp viết string trên nhiều dòng đơn giản hơn.
- ES6 template cho phép viết biểu thức hoặc gọi hàm ngay trong string.

Trên đây là một số tính năng mình thấy rất hữu ích của ES6 Template String. Ngoài ra, mình cũng có một số bài viết khác về template string:

- [Tagged Template Literals](/bai-viet/javascript/tagged-template-es6-trong-javascript/)
