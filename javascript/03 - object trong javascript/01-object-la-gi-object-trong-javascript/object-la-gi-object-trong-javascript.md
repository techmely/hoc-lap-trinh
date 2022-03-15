---
title: "Object là gì? Object trong Javascript"
description: "Trong JavaScript, một object là một thực thể độc lập, với thuộc tính và kiểu. Khái niệm của objects trong JavaScript có thể được hiểu như những đối tượng thực tế trong đời thực."
keywords: [
"đối tượng trong javascript",
"object trong javascript",
"mang object trong javascript",
"kieu du lieu object trong javascript",
"object js",
"object trong javascript là gì",
"xử lý object trong javascript",
"so sánh object trong javascript",
"kiểu object trong javascript",
"kiểm tra object trong javascript",
"đối tượng trong javascript là gì"
]
chapter:
  name: "Object trong Javascript"
  slug: "chuong-03-object-trong-javascript"
category:
  name: "Javascript"
  slug: "javascript"
image: https://kungfutech.edu.vn/thumbnail.png
position: 1
---

Như mình đã nói trong bài [các kiểu dữ liệu trong JavaScript](/bai-viet/javascript/cac-kieu-du-lieu-trong-javascript), JavaScript có **7 kiểu dữ liệu nguyên thủy** và **1 kiểu dữ liệu dạng tham chiếu**. Đó là object trong JavaScript.

Để hiểu object (đối tượng) là gì, mình sẽ đưa ra một ví dụ về máy tính. Cụ thể, máy tính của mình có những đặc điểm sau:

- Loại: laptop
- Hãng: Sony
- Hệ điều hành: Windows 7
- Card đồ hoạ: NVIDIA
- ...

Ở đây, _máy tính của mình_: chính là một **JavaScript object**. Đối tượng này có các **thuộc tính** (properties): _loại, hãng, hệ điều hành, card đồ hoạ_ với các giá trị tương ứng là _laptop, Sony, Windows 7, NVIDIA_.

![Object là gì? Object trong Javascript](https://user-images.githubusercontent.com/29374426/157916139-559c45a7-19df-48ce-b34d-ec07b6ab920b.png)

## Vậy object trong JavaScript là gì?

> **Object trong JavaScript** là một khái niệm trừu tượng dùng để biểu diễn một vật thể (cụ thể). Trong đó, các thuộc tính dùng để miêu tả đặc điểm, tính chất của đối tượng.

Về bản chất, object là tập hợp của các **key** và **value**. Với **key** gọi là thuộc tính, còn **value** là giá trị tương ứng của thuộc tính.

<content-info>

- Object có thể không chứa thuộc tính nào, được gọi là **object rỗng**.
- Object phải là một danh từ **riêng**, không phải danh từ **chung**. Trong ví dụ trên, nếu chỉ nói **máy tính** thì đó không phải đối tượng, mà phải là **máy tính của mình**.

</content-info>

## Biểu diễn object trong JavaScript

JavaScript object sử dụng cặp dấu ngoặc `{}` để biểu diễn:

```js
{
  key1: value1,
  key2: value2,
  key3: value3,
  ...
}
```

Trong đó:

- _key1, key2, key3,..._: là tên thuộc tính, có kiểu dữ liệu là **string** hoặc [**symbol**](/bai-viet/javascript/symbol-trong-javascript).
- _value1, value2, value3,..._: là giá trị tương ứng của các thuộc tính. Value có thể thuộc bất kỳ kiểu dữ liệu nào (kể cả **object**).
- Các cặp **key-value** ngăn cách nhau bởi dấu phẩy `,`.

Áp dụng cho ví dụ trên:

```js
let myComputer = {
  type: "laptop",
  brand: "Sony",
  os: "Windows 7",
  graphicCard: "NVIDIA",
};
```

> 💡 **Chú ý**: Cặp **key-value** cuối cùng không nhất thiết phải có dấu phẩy `,`. Nhưng để đảm bảo tính đồng nhất thì bạn nên thêm vào dấu phẩy `graphicCard: "NVIDIA",`.
>
> Đặc điểm này được gọi là [trailing comma](https://int3ractive.com/blog/2019/why-trailing-comma-in-js-is-a-good-idea/) hay "dấu phẩy đuôi".

Ngoài ra, để khai báo **object rỗng** bạn có thể sử dụng một trong hai cách sau:

```js
// Objec rỗng không có thuộc tính nào
let myComputer = {};

// Hoặc sử dụng hàm khởi tạo object
let yourComputer = new Object();
```

Trong đó, `new Object()` là cú pháp [hàm](/bai-viet/javascript/ham-trong-javascript/) khởi tạo của **object**. Cách này ít sử dụng hơn cách đầu tiên.

## Cách sử dụng object trong JavaScript

Khi đã khởi tạo được object rồi thì vấn đề tiếp theo là làm sao sử dụng được object. Cụ thể là cách thức để truy cập vào thuộc tính của object.

Có 2 cách để lấy ra giá trị của một thuộc tính trong object:

- Sử dụng toán tử **chấm** `.` theo sau là tên thuộc tính.
- Sử dụng toán tử **ngoặc vuông** `[]`, bên trong là tên thuộc tính.

Ví dụ mô tả cách truy cập thuộc tính object:

```js
let myComputer = {
  type: "laptop",
  brand: "Sony",
  os: "Windows 7",
  graphicCard: "NVIDIA",
};

console.log(myComputer.type); // laptop
console.log(myComputer.brand); // Sony
console.log(myComputer.os); // Windows 7
console.log(myComputer.graphicCard); // NVIDIA

console.log(myComputer["type"]); // => laptop
console.log(myComputer["brand"]); // => Sony
console.log(myComputer["os"]); // => Windows 7
console.log(myComputer["graphicCard"]); // => NVIDIA
```

Đặc biệt, toán tử `.` chỉ dùng được trong trường hợp tên thuộc tính không có kí tự đặc biệt (ngoại trừ kí tự `_` và `$`).

Khi **key** chứa dấu cách, hoặc các ký tự đặc biệt khác thì bạn bắt buộc phải sử dụng toán tử `[]`.

Ví dụ:

```js
let myComputer = {
  _type: "laptop",
  $brand: "Sony",
  "operating system": "Windows 7",
  "graphic card": "NVIDIA",
};

console.log(myComputer._type); // laptop
console.log(myComputer.$brand); // Sony
console.log(myComputer["operating system"]); // Windows 7
console.log(myComputer.operating system); // ERROR -> lỗi cú pháp
```

> 📝 Khi **key** chứa dấu cách hoặc các ký tự đặc biệt (khác `_` và `$`), bạn cần phải để **key** bên trong cặp dấu nháy kép `""` hoặc nháy đơn `''`.

<content-warning>

**Chú ý:** Trong các ví dụ trên, mình in ra giá trị từng thuộc tính của object để minh họa. Thực tế, bạn có thể dùng [`console.log`](/bai-viet/javascript/nhap-xuat-man-hinh-console) để in ra toàn bộ object.

</content-warning>

```js
let myComputer = {
  type: "laptop",
  brand: "Sony",
  os: "Windows 7",
  graphicCard: "NVIDIA",
};

console.log(myComputer);
```

Kiểm tra trên [Dev Tools](/bai-viet/javascript/dev-tools-la-gi/), bạn sẽ thấy toàn bộ object được in ra.

## Cập nhật JavaScript object

Để **thay đổi giá trị thuộc tính** của object, bạn chỉ cần sử dụng cách truy cập ở trên và gán giá trị mới cho thuộc tính đó.

```js
let myComputer = {
  type: "laptop",
  brand: "Sony",
  "operating system": "Windows 7",
  "graphic card": "NVIDIA",
};

myComputer.type = "desktop";
myComputer["operating system"] = "Ubuntu";
console.log(myComputer.type); // => desktop
console.log(myComputer["operating system"]); // => Ubuntu
```

Bạn cũng có thể **thêm thuộc tính cho object** như sau:

```js
let myComputer = {
  type: "laptop",
  brand: "Sony",
  "operating system": "Windows 7",
  "graphic card": "NVIDIA",
};

myComputer.status = "sleep";
myComputer["it is good"] = true;
console.log(myComputer.status); // sleep
console.log(myComputer["it is good"]); // => true
```

Để **xóa một thuộc tính của object** trong JavaScript, bạn sử dụng toán tử `delete`:

```js
let myComputer = {
  type: "laptop",
  brand: "Sony",
  "operating system": "Windows 7",
  "graphic card": "NVIDIA",
};

delete myComputer.brand;
delete myComputer["graphic card"];
console.log(myComputer.brand); // undefined
console.log(myComputer["graphic card"]); // undefined
```

Khi bạn đã xóa thuộc tính `brand` và `"graphic card"` thì các thuộc tính này không tồn tại trong object nữa, hay giá trị của chúng trở thành `undefined`.

Nói cách khác, giá trị của một thuộc tính không tồn tại trong object là `undefined`, ví dụ:

```js
let myComputer = {
  type: "laptop",
  brand: "Sony",
  "operating system": "Windows 7",
  "graphic card": "NVIDIA",
};

console.log(myComputer.status); // undefinedconsole.log(myComputer["it is good"]); // undefined
```

## Toán tử ngoặc vuông `[]` trong object JS

JavaScript cho phép bạn truy cập vào thuộc tính với giá trị của **key** là [biến](/bai-viet/javascript/bien-trong-javascript/) hoặc biểu thức.

Khi đó, giá trị của **key** sẽ được tính toán trong thời gian chạy (**runtime**), ví dụ:

```js
let myComputer = {
  type: "laptop",
  brand: "Sony",
  "operating system": "Windows 7",
  "graphic card": "NVIDIA",
};

// sử dụng biến
let operatingSystem = "operating system";
console.log(myComputer[operatingSystem]); // Windows 7
// sử dụng biểu thức
console.log(myComputer["graphic" + " " + "card"]); // NVIDIA
```

<content-warning>

**Chú ý**: bạn không thể sử dụng toán tử `.` theo cách tương tự trên.

</content-warning>

```js
let myComputer = {
  type: "laptop",
  brand: "Sony",
  "operating system": "Windows 7",
  "graphic card": "NVIDIA",
};

const operatingSystem = "operating system";
console.log(myComputer.operatingSystem); // undefined
```

Trong trường hợp `myComputer.operatingSystem`, JavaScript hiểu là bạn đang muốn truy cập vào thuộc tính `operatingSystem` mà trong object `myComputer` lại không có thuộc tính nào như vậy.

## Khởi tạo thuộc tính runtime cho object

Không chỉ dừng lại ở việc truy cập thuộc tính runtime, bạn cũng có thể dùng toán tử `[]` để khởi tạo object trong JavaScript như sau:

```js
let t = "type";
const operatingSystem = "operating system";

let myComputer = {
  [t]: "laptop",
  brand: "Sony",
  [operatingSystem]: "Windows 7",
  ["graphic" + " " + "card"]: "NVIDIA",
};

console.log(myComputer.type); // "laptop"
console.log(myComputer["operating system"]); // Windows 7
console.log(myComputer["graphic card"]); // NVIDIA
```

## Cú pháp rút gọn thuộc tính khi khởi tạo object

Khi lập trình, bạn sẽ gặp trường hợp là: bạn muốn sử dụng tên biến làm thuộc tính cho object, ví dụ:

```js
function makeComputer(type, brand, os, graphicCard) {
  return {
    type: type,
    brand: brand,
    os: os,
    graphicCard: graphicCard,
  };
}

// Ví dụ
let myComputer = makeComputer("laptop", "Sony", "Windows 7", "NVIDIA");
console.log(myComputer.type); // laptop
console.log(myComputer.brand); // Sony
console.log(myComputer.os); // Windows 7
console.log(myComputer.graphicCard); // NVIDIA
```

Trong ví dụ trên, bạn thấy rằng các thuộc tính trùng với tên của tham số truyền vào hàm: `type: type`, `brand: brand`, `os: os` và `graphicCard: graphicCard`.

Để tránh phải viết lặp lại như vậy, JavaScript cung cấp cú pháp rút gọn như sau:

```js
function makeComputer(type, brand, os, graphicCard) {
  return {
    type,
    brand,
    os,
    graphicCard,
  };
}

// Ví dụ
let myComputer = makeComputer("laptop", "Sony", "Windows 7", "NVIDIA");
console.log(myComputer.type); // laptop
console.log(myComputer.brand); // Sony
console.log(myComputer.os); // Windows 7
console.log(myComputer.graphicCard); // NVIDIA
```

## Giới hạn về tên thuộc tính của object trong JS

Như bạn đã biết, bạn không được phép sử dụng **từ khóa và từ dữ trữ** để đặt tên biến trong JavaScript, ví dụ như: "var", "const", "let", "for", "while",...

Nhưng với thuộc tính trong object khác, bạn không bị giới hạn này:

```js
let obj = {
  var: 1,
  let: "a",
  for: null,
  while: NaN,
};

console.log(obj.var); // 1
console.log(obj.let); // a
console.log(obj.for); // null
console.log(obj.while); // NaN
```

Tên của thuộc tính có thể là bất kỳ string nào (hoặc symbol). Với những giá trị không phải string thì JavaScript sẽ tự [chuyển đổi kiểu dữ liệu](/bai-viet/javascript/chuyen-doi-kieu-du-lieu-trong-javascript) sang string.

Ví dụ số `0` được chuyển về string `"0"`:

```js
let obj = {
  0: "Zero",
};

// Hai cách truy cập sau đây tương đương nhau
console.log(obj[0]); // Zero
console.log(obj["0"]); // Zero
```

<content-warning>

**Chú ý:** object trong JavaScript có một thuộc tính mặc định đặc biệt là `__proto__`. Bạn không thể gán giá trị khác object cho thuộc tính này:

</content-warning>

```js
let obj = {
  x: 1,
};

console.log(obj.__proto__); // [object Object]

obj.__proto__ = "string";
console.log(obj.__proto__); // [object Object] - giống như cũ
```

Đây là thuộc tính đặc biệt trong JavaScript mà mình sẽ giới thiệu sau.

## Cách kiểm tra tính tồn tại của thuộc tính

Như mình đã nói ở trên, nếu một thuộc tính không tồn tại trong object thì giá trị của nó là `undefined`.

Nhưng bạn không thể dùng cách này để kiểm tra tính tồn tại của thuộc tính trong object được. Vì rất có thể, giá trị của thuộc tính được chủ động gán cho `undefined`.

```js
let user = {
  name: undefined,
};

console.log(user.name); // undefined
console.log(user.age); // undefined
```

Cả hai trường hợp trên đều cho kết quả là `undefined`. Nhưng rõ ràng là thuộc tính `name` có tồn tại trong object, còn thuộc tính `age` thì không tồn tại.

Để giải quyết vấn đề này, bạn có thể dùng toán tử `in` với cú pháp là:

`"key" in object;`

Ví dụ sử dụng `in`:

```js
let user = {
  name: undefined,
};

console.log("name" in user); // true
console.log("age" in user); // false
```

<content-warning>

**Chú ý**: thành phần bên trái toán tử `in` là tên thuộc tính, thường đặt trong cặp dấu `""` hoặc `''`. Kết quả trả về là giá trị **boolean** ứng với `true` là có tồn tại, `false` là không tồn tại.

</content-warning>

## Cách duyệt tất cả các thuộc tính của object

Để duyệt tất cả các thuộc tính của object, bạn có thể sử dụng vòng lặp `for...in` - khác với vòng lặp `for(;;)` đã tìm hiểu ở bài [vòng lặp trong JavaScript](/bai-viet/javascript/vong-lap-trong-javascript/).

```js
let myComputer = {
  type: "laptop",
  brand: "Sony",
  "operating system": "Windows 7",
  "graphic card": "NVIDIA",
};

for (let prop in myComputer) {
  console.log(prop, ":", myComputer[prop]);
}

// type : laptop
// brand : Sony
// operating system : Windows 7
// graphic card : NVIDIA
```

Khi đó biến `prop` sẽ chạy hết tất cả các thuộc tính của object `myComputer`.

## Thứ tự các thuộc tính của object trong JavaScript

Khi duyệt tất cả các thuộc tính của object trong JavaScript thì có hai trường hợp xảy ra:

- Đối với thuộc tính kiểu số nguyên không dấu: thứ tự được sắp xếp theo chiều tăng dần (từ số nhỏ đến số lớn).
- Đối với thuộc tính kiểu dữ liệu còn lại: thứ tự giống với thứ tự thêm vào object.

Ví dụ:

```js
let numbers = {
  "-21": "minus two",
  "-1": "minus one",
  0: "zero",
  10: "ten",
  2: "two",
  a: "abc",
  "-3": "minus three",
  4: "four",
  3: "three",
  6: "six",
};

for (let n in numbers) {
  console.log(n);
}

// 0
// 2
// 3
// 4
// 6
// 10
// -21
// -1
// a
// -3
```

Trong ví dụ trên, các thuộc tính với số không dấu được đưa lên đầu và sắp xếp theo tứ tự từ số nhỏ đến số lớn. Các thuộc tính còn lại được xếp sau và giống với thứ tự thêm vào object.

## Một số đối tượng sẵn có trong JavaScript

JavaScript cung cấp sẵn một số đối tượng giúp công việc lập trình trở nên dễ dàng hơn.

### Đối tượng Arguments

Mỗi khi hàm được gọi, có một biến số đặc biệt tên là `arguments` được thêm vào bên trong phạm vi của function. Biến số này chứa một thuộc tính là `length`, để xác định số lượng tham số truyền vào.

Bởi vì, bạn có thể truyền vào nhiều hơn, hay ít hơn số lượng tham số của hàm. Nên việc biết số lượng tham số truyền vào là vô cùng cần thiết trong lập trình JavaScript.

Ví dụ sau miêu tả cách sử dụng `arguments` để xác định số lớn nhất trong tất cả các số truyền vào:

```js
function maxOf() {
  let max = -1;

  for (let i = 0; i < arguments.length; i++) {
    if (arguments[i] > max) max = arguments[i];
  }

  return max;
}

console.log(maxOf(1, 2));
// 2

console.log(maxOf(1, 2, 6, 4, 7, 3, 5));
// 7
```

Rõ ràng, hàm `maxOf` ở trên không chứa một tham số nào. Nhưng khi sử dụng, mình lại truyền vào tham số với số lượng tuỳ ý.

### Đối tượng Math

Cái tên đã nói lên tất cả. Đúng vậy, đối tượng `Math` chứa các hàm phục vụ cho tính toán số học như:

- `Math.min`: Tìm giá trị nhỏ nhất.
- `Math.max`: Tìm giá trị lớn nhất.
- `Math.sqrt`: Tìm giá trị căn bậc hai.
- `Math.abs`: Tìm giá trị tuyệt đối.
- ...

Sử dụng `Math` giúp giảm thiểu đáng kể thời gian viết code, vì bạn không phải viết lại những hàm cực kì cơ bản.

> Bạn có thể tham khảo thêm về [Math](https://www.w3schools.com/js/js_math.asp).

### Đối tượng Global

Trên với trình duyệt, object lớn nhất chính là `window`. Mọi biến global đều thuộc đối tượng này.

```js
var x = 6; // khai báo biến sử dụng var như này thì x thuộc window
console.log("x" in window);
// true

console.log(window.x);
// 6
```

## Tổng kết

Bản chất object trong JavaScript là tập hợp của các **key-value**, trong đó:

- Kiểu dữ liệu của **key** là string hoặc symbol.
- Giá trị **value** ứng với **key** có thể là bất kỳ kiểu dữ liệu nào.

Có hai cách để truy cập vào thuộc tính của object:

- Sử dụng toán tử chấm `.`, ví dụ: `object.property`.
- Sử dụng dấu ngoặc vuông `[]`, ví dụ: `object["property"]`. Toán tử `[]` chấp nhận giá trị của `key` là từ bất kỳ kiểu dữ liệu nào như biến hoặc biểu thức.

Một số toán tử liên quan:

- Toán tử `delete`: dùng để xóa thuộc tính trong object, ví dụ: `delete object.property`.
- Toán tử `in`: dùng để kiểm tra xem một thuộc tính có thuộc object hay không, ví dụ: `"key" in object`.

Để duyệt tất cả các thuộc tính trong object, bạn dùng vòng lặp `for...in` dạng như: `for(let key in obj)`.

## Thực hành

Viết code theo các yêu cầu sau:

1.  Tạo object rỗng `point`.
2.  Thêm thuộc tính `x` với giá trị `2`.
3.  Thêm thuộc tính `y` với giá trị `3`.
4.  Thêm thuộc tính `z index` với giá trị `1000`.
5.  Tính tổng giá trị các thuộc tính (kết quả phải bằng `1005`).
6.  Thay đổi giá trị ứng với thuộc tính `x` thành `1`.
7.  Xóa thuộc tính `y` khỏi `point`.

Xem đáp án

```js
// 1. Tạo object rỗng `point`.
let point = {};

// 2. Thêm thuộc tính `x` với giá trị `2`.
point.x = 2;

// 3. Thêm thuộc tính `y` với giá trị `3`.
point.y = 3;

// 4. Thêm thuộc tính `z index` với giá trị `1000`.
point["z-index"] = 1000;

// 5. Tính tổng giá trị các thuộc tính.
let sum = 0;
for (let key in point) {
  sum += point[key];
}
console.log(sum); // 1005

// 6. Thay đổi giá trị ứng với thuộc tính `x` thành `1`.
point.x = 1;

// 7. Xóa thuộc tính `y` khỏi `point`.
delete point.y;
```
