---
title: "Native Prototype trong JavaScript"
description: " Native prototype là các hàm khởi tạo sẵn có khác cũng sử dụng thuộc tính prototype "
keywords: [
"Native Prototype trong JavaScript",
"Native Prototype trong JavaScript là gì",
"Native Prototype trong JavaScript dùng để làm gì",
"Cách sử dụng Native Prototype trong JavaScript",
"khi nào cần Native Prototype trong JavaScript",
"vi du ve prototype trong javascript",
"Sự kế thừa trong javascript",
"kế thừa và prototype trong javascript"
]
chapter:
  name: "Prototype và thừa kế prototype"
  slug: "chuong-07-prototype-va-thua-ke-prototype"
category:
  name: "Javascript"
  slug: "javascript"
image: https://kungfutech.edu.vn/thumbnail.png
position: 3
---

Thuộc tính [prototype](/bai-viet/javascript/prototype-trong-javascript) thường được sử dụng nhiều trong **JavaScript core**. Ngoài ra, các hàm khởi tạo sẵn có khác cũng sử dụng thuộc tính này, tạm gọi là **native prototype**.

Sau đây, mình sẽ tìm hiểu chi tiết về native prototypes và cách để thêm các tính năng cho chúng.

## Object.prototype

Hãy xem ví dụ sau:

```js
let obj = {};
alert(obj); // "[object Object]"
```

Rõ ràng, `obj` là một **đối tượng rỗng**. Vậy thì đoạn code tạo ra `"[object Object]"` nằm ở đâu?

Kết quả trên được tạo ra từ phương thức `toString`.

Thực chất, `obj = {}` tương đương với `obj = new Object()`, với `Object` là một **hàm khởi tạo sẵn có** trong JavaScript. Và hàm khởi tạo `Object` có `prototype` chứa phương thức `toString`.

Khi `new Object()` được gọi, thuộc tính `[[Prototype]]` của đối tượng mới tạo ra được gán bằng `Object.prototype`.

Khi gọi `obj.toString()`, đầu tiên JavaScript sẽ tìm kiếm trong `obj`, nhưng không tồn tại `toString` nên JavaScript tự động tìm kiếm trong prototype của `obj`.

Bạn có thể kiểm tra lại bằng cách sau:

```js
let obj = {};

console.log(obj.__proto__ === Object.prototype); // true
console.log(obj.toString === obj.__proto__.toString); // true
console.log(obj.toString === Object.prototype.toString); // true
```

**Chú ý:** không tồn tại prototype của `Object.prototype`:

```js
console.log(Object.prototype.__proto__); // null
```

## Native prototypes của các kiểu dữ liệu khác

Các kiểu dữ liệu khác như `Array`, `Date`, `Function`,... cũng có các phương thức ở native prototypes.

Ví dụ, khi tạo mảng `[1, 2, 3]` thì JavaScript sẽ gọi hàm khởi tạo `new Array()`. Vì vậy, `Array.prototype` cũng trở thành prototype của mảng được tạo ra.

Nhờ đó mà bạn có thể sử dụng các phương thức với mảng như `forEach`, `map`, `filter`,...

<content-warning>

**Chú ý:** các kiểu dữ liệu sẵn có trong JavaScript đều có `Object.prototype` ở **top của chuỗi prototype**. Nói cách khác, tất cả các **kiểu dữ liệu tham chiếu** đều kế thừa từ object

</content-warning>

Ví dụ:

```js
let arr = [1, 2, 3];

// mảng arr kế thừa prototype từ Array.prototype
console.log(arr.__proto__ === Array.prototype); // true

// sau đó prototype trên lại kế thừa từ Object.prototype
console.log(arr.__proto__.__proto__ === Object.prototype); // true

// cuối cùng là null
console.log(arr.__proto__.__proto__.__proto__); // null
```

Một vài phương thức trong chuỗi prototype **có thể trùng tên nhau**.

Ví dụ `Object.prototype` có phương thức `toString` và `Array.prototype` cũng có phương thức `toString` riêng. Tuy nhiên, prototype nào gần hơn thì sẽ được sử dụng.

```js
let arr = [1, 2, 3];
alert(arr); // 1,2,3 <-- kết quả từ Array.prototype.toString
```

Trong ví dụ trên, kết quả `1, 2, 3` được tạo ra từ `Array.prototype.toString`.

## Kiểu dữ liệu nguyên thủy

Trong các ví dụ trên, mình mới chỉ đề cập tới **kiểu dữ liệu tham chiếu**, với [kiểu dữ liệu nguyên thủy](/bai-viet/javascript/cac-kieu-du-lieu-trong-javascript) thì sao?

Rõ ràng, kiểu dữ liệu nguyên thủy **không phải object**. Nhưng khi bạn truy cập vào các thuộc tính, phương thức của kiểu dữ liệu nguyên thủy thì JavaScript sẽ tự động tạo ra một **wrapper object** từ các hàm khởi tạo `String`, `Number` và `Boolean`.

Đây là **object tạm** dùng để đóng gói lấy kiểu dữ liệu nguyên thủy. Và sau khi JavaScript sử dụng xong thì wrapper object sẽ được giải phóng.

Phương thức của các **đối tượng tạm** trên cũng nằm trong prototype, cụ thể là: `String.prototype`, `Number.prototype` và `Boolean.prototype`.

<content-warning>

**Chú ý:** hai kiểu dữ liệu `null` và `undefined` không có **wrapper object**. Do đó, hai kiểu dữ liệu này không có phương thức nào đi cùng.

</content-warning>

## Thay đổi native prototypes

Native prototypes **có thể thay đổi được**. Giả sử bạn thêm một phương thức cho `String.prototype` thì phương thức này có thể được dùng ở mọi string:

```js
String.prototype.show = function () {
  console.log(this);
};

"AHA".show(); // AHA!
```

Trong quá trình phát triển phần mềm, bạn có thể sẽ muốn **thêm phương thức** cho các kiểu dữ liệu. Và giả sử, bạn thêm chúng vào native prototypes.

Cách này đúng nhưng không phải là một ý tưởng tốt. Bởi vì prototypes là **global**.

Nếu hai thư viện cùng thêm phương thức `String.prototype.show` thì một trong hai sẽ bị ghi đè, dẫn đến xung đột code.

<content-warning>

**Chú ý:** chỉ có một trường hợp bạn nên thêm phương thức vào native prototypes, đó là **polyfilling**.

</content-warning>

Polyfilling nghĩa là bạn thêm một phương thức vào kiểu dữ liệu sẵn có trong JavaScript. Phương thức này tồn tại trong **mô tả của ngôn ngữ JavaScript** nhưng lại chưa được hỗ trợ ở một JavaScript engine hoặc một phiên bản trình duyệt cũ, ví dụ:

```js
// Nếu như String chưa có phương thức `String.prototype.repeat`
if (!String.prototype.repeat) {
  // Triển khai phương thức repeat
  String.prototype.repeat = function (n) {
    // phương thức repeat lặp lại string với số lần là n
    return new Array(n + 1).join(this);
  };
}

console.log("Ha".repeat(3)); // HaHaHa
```

## Mượn các phương thức từ prototypes

Trong bài viết về [decorator và forwarding của hàm trong JavaScript](/bai-viet/javascript/decorator-forwarding-cua-ham-trong-javascript), mình đã nói về vấn đề **mượn phương thức**.

Đó là khi mình muốn mượn phương thức từ một object và sao chép sang object khác.

Ví dụ, để tạo ra một array-object, bạn có thể sao chép các phương thức của `Array.prototype` sang object như sau:

```js
let obj = {
  0: "Hello",
  1: "world!",
  length: 2,
};

obj.join = Array.prototype.join;
console.log(obj.join(",")); // Hello,world!
```

Cách trên hoạt động chính xác vì phương thức `Array.prototype.join` chỉ quan tâm tới **chỉ số** và thuộc tính `length`.

Ngoài ra, để sao chép tất cả các phương thức của `Array.prototype` sang object, bạn có thể làm như sau:

```js
let obj = {
  0: "Hello",
  1: "world!",
  length: 2,
};

obj.__proto__ = Array.prototype;
console.log(obj.join(",")); // Hello,world!
```

<content-warning>

**Chú ý:** cách làm như trên không chính xác nếu object đã kế thừa prototype từ một object khác. Thực tế là chỉ kế thừa được **một object tại một thời điểm**.

</content-warning>

## Tổng kết

Tất cả **đối tượng sẵn có trong JavaScript** đều có dạng như sau:

- Các phương thức được lưu trong native prototypes, ví dụ: `Array.prototype`, `Date.prototype`, `Function.prototype`,...
- Bản thân object chỉ lưu dữ liệu, ví dụ: mảng các phần tử, ngày tháng năm,...

Các kiểu dữ liệu nguyên thủy cũng có các phương thức ở **wrapper object** là: `String.prototype`, `Number.prototype` và `Boolean.prototype`.

Prototype có thể thay đổi hoặc thêm mới các phương thức. Tuy nhiên, việc này không được khuyến khích.

Chỉ có **một trường hợp** bạn nên thêm phương thức vào prototype. Đó là khi phương thức được định nghĩa trong mô tả của ngôn ngữ JavaScript nhưng **chưa được hỗ trợ** ở một số JavaScript Engine hoặc trình duyệt nhất định.

## Thực hành

### Bài 1

Thêm vào prototype của tất cả các hàm phương thức `defer(ms)` - thực thi hàm sau `ms` mili giây, ví dụ:

```js
function f() {
  console.log("Hello!");
}

f.defer(1000); // hiển thị "Hello!" sau 1 giây
```

Xem đáp án

```js
Function.prototype.defer = function (ms) {
  setTimeout(this, ms);
};
function f() {
  console.log("Hello!");
}

f.defer(1000); // hiển thị "Hello!" sau 1 giây
```

### Bài 2

Thêm vào prototype của tất cả các hàm phương thức `defer(ms)` - trả về một hàm wrapper giúp trì hoãn việc thực thi hàm sau `ms` mili giây, ví dụ:

```js
function f(a, b) {
  console.log(a + b);
}

f.defer(1000)(1, 2); // hiển thị 3 sau 1 giây
```

Xem đáp án

```js
Function.prototype.defer = function (ms) {
  // lưu lại hàm
  let f = this;
  return function () {
    setTimeout(() => f.apply(this, [...arguments]), ms);
  };
};
function f(a, b) {
  console.log(a + b);
}

f.defer(1000)(1, 2); // hiển thị 3 sau 1 giây
```

Tham khảo: [Native prototypes](https://javascript.info/native-prototypes)
