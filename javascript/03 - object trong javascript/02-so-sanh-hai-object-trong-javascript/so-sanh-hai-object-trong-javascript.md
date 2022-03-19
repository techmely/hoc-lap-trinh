---
title: "So sánh hai object trong Javascript"
description: "Hướng dẫn cách so sánh object trong JavaScript. Bạn sẽ học được các cách so sánh 2 object trong JavaScript sau bài học này."
keywords: [
"đối tượng trong javascript",
"object trong javascript",
"So sánh hai object trong Javascript",
"So sánh 2 object trong JavaScript",
"Cách so sánh 2 object trong JavaScript",
"so sánh 2 object trong javascript dùng để",
"so sánh 2 object trong javascript hay",
"so sánh 2 object trong javascript là gì"
]
chapter:
  name: "Object trong Javascript"
  slug: "chuong-03-object-trong-javascript"
category:
  name: "Javascript"
  slug: "javascript"
image: https://kungfutech.edu.vn/thumbnail.png
position: 2
---

Điều cơ bản khác nhau giữa object và các [kiểu dữ liệu nguyên thủy](/bai-viet/javascript/cac-kieu-du-lieu-trong-javascript/) khác là object lưu trữ dữ liệu theo kiểu [tham chiếu](<https://vi.wikipedia.org/wiki/Tham_chi%E1%BA%BFu_(khoa_h%E1%BB%8Dc_m%C3%A1y_t%C3%ADnh)>). Nên việc so sánh 2 object trong JavaScript là **theo địa chỉ** (chứ không phải theo giá trị).

Vì vậy, trước khi tìm hiểu chi tiết về việc so sánh giữa hai object, mình cần hiểu cơ bản về kiểu dữ liệu tham chiếu.

## Kiểu dữ liệu tham chiếu

Khi gán một object cho một biến, thực chất là biến đó đang **lưu địa chỉ** trong bộ nhớ của object.

Khi ta truy cập vào một thuộc tính của object, trình thông dịch sẽ dựa theo **địa chỉ đã lưu** để truy xuất đúng giá trị cần lấy trong bộ nhớ.

Ví dụ về object:

```js
let p1 = { x: 1, y: 2 };
let p2 = p1;

p2.x = 2;
console.log(p2.x); // 2
console.log(p1.x); // 2
```

Trong ví dụ trên, mình [khởi tạo object](/bai-viet/javascript/object-la-gi-object-trong-javascript/) `p1`. Tiếp theo, mình khởi tạo `p2` và gán bằng `p1`. Sau đó, mình thay đổi giá trị thuộc tính `x` trong `p2`. Nhưng thấy kết quả là `p1.x` và `p2.x` đều thay đổi.

Điều này cho thấy là `p2` và `p1` đang cùng trỏ vào một **vùng nhớ giống nhau** trong bộ nhớ.

Đây chính là đặc điểm cơ bản của kiểu dữ liệu tham chiếu. Sau đây, mình sẽ tìm hiểu kỹ hơn về cách để so sánh 2 object trong JavaScript.

Sau đây, mình sẽ tìm hiểu các phương diện so sánh 2 object trong JavaScript là:

- So sánh object bằng tham chiếu.
- So sánh object qua giá trị cách thủ công.
- So sánh nông (shallow equality).
- So sánh sâu (deep equality).

## So sánh 2 object bằng tham chiếu

JavaScript cung cấp hai [toán tử so sánh](/bai-viet/javascript/toan-tu-trong-javascript/) là `==` và `===`, trong đó:

- Toán tử `===` ("bằng nghiêm ngặt") trả về `true` khi và chỉ khi hai biến có `cùng kiểu dữ liệu` và `cùng giá trị`, ngược lại thì trả về `false`.
- Toán tử `==` trả về `true` khi hai biến có `cùng giá trị` và có thể **khác kiểu dữ liệu** (JavaScript sẽ [chuyển về cùng kiểu dữ liệu](/bai-viet/javascript/chuyen-doi-kieu-du-lieu-trong-javascript/) để so sánh), ngược lại thì trả về `false`.

> **Đối với so sánh object bằng tham chiếu:** hai object được gọi là bằng nhau khi và chỉ khi chúng cùng tham chiếu đến cùng một địa chỉ bộ nhớ. Hay nói ngắn gọn là chúng hoàn toàn giống nhau.

Ví dụ hai object bằng nhau theo tham chiếu:

```js
let x = {};
let y = x;

console.log(y == x); // true
console.log(y === x); // true
```

Trong ví dụ trên, hai object `x` và `y` đang cùng tham chiếu tới một địa chỉ. Vì vậy, chúng hoàn toàn bằng nhau.

Ngược lại, hai object độc lập sẽ không bao giờ bằng nhau, mặc dù trông có vẻ giống nhau:

```js
let x = {};
let y = {}; // khởi tạo object độc lập
console.log(y == x); // false
console.log(y === x); // false
```

Hai object `y` và `x` đều là **object rỗng** nhưng chúng đang tham chiếu tới hai địa chỉ khác nhau, nên không bằng nhau.

Ngoài hai toán tử trên, bạn có thể dùng hàm [`Object.is(value1, value2)`](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Object/is) để so sánh 2 object trong JavaScript bằng tham chiếu.

```js
let x = {};
let y = x; // object cùng tham chiếu
let z = {}; // object độc lập

console.log(Object.is(y, x)); // true
console.log(Object.is(z, x)); // false
```

## So sánh 2 object qua giá trị cách thủ công

Đôi khi mình muốn so sánh thủ công **từng giá trị** ứng với **từng thuộc tính** của object. Và mình coi hai object bằng nhau khi chúng có cùng thuộc tính và cùng giá trị với từng thuộc tính.

Ví dụ xây dựng bài toán vẽ hình, khi đó mỗi điểm trên màn hình là một **point** với tọa độ **(x,y)**. Khi đó, hai **point** bằng nhau khi chúng có cùng tọa độ **(x,y)**, ví dụ:

```js
let point1 = { x: 1, y: 2 };
let point2 = { x: 1, y: 2 };
let point3 = { x: 2, y: 3 };
```

Rõ ràng, `point2` và `point1` có cùng tọa độ nên trùng nhau. Trong khi đó, `point3` có tọa độ khác với `point1` và `point2`.

**Làm sao để so sánh các point trên?**

Đơn giản là mình sẽ truy cập giá trị của hai thuộc tính `x` và `y` trong từng object rồi so sánh chúng với nhau.

```js
let point1 = { x: 1, y: 2 };
let point2 = { x: 1, y: 2 };
let point3 = { x: 2, y: 3 };

if (point2.x === point1.x && point2.y === point1.y) {
  console.log("point2 bằng point1");
} else {
  console.log("point2 khác point1");
}

if (point3.x === point1.x && point3.y === point1.y) {
  console.log("point3 bằng point1");
} else {
  console.log("point3 khác point1");
}

// point2 bằng point1
// point3 khác point1
```

Kết quả hoàn toàn như mong đợi rồi đúng không?

Nhưng vấn đề là đoạn code kiểm tra điều kiện đang bị lặp lại. Do đó, khi bạn muốn thay đổi định nghĩa về **hai point bằng nhau** thì bạn phải sửa đoạn code trên ở mọi nơi sử dụng.

> Don't repeat yourself!

Để giải quyết vấn đề trên, mình viết lại điều kiện trên thành hàm kiểm tra như sau:

```js
function isPointEqual(p1, p2) {
  return p1.x === p2.x && p1.y === p2.y;
}
let point1 = { x: 1, y: 2 };
let point2 = { x: 1, y: 2 };
let point3 = { x: 2, y: 3 };

console.log(isPointEqual(point1, point2)); // trueconsole.log(isPointEqual(point1, point3)); // false
```

Đến đây cũng khá ổn rồi... nhưng lại có một vấn đề khác: nếu object không chỉ có hai thuộc tính mà có **rất nhiều thuộc tính** thì sao?

Thậm chí là số lượng thuộc tính không biết trước thì bạn không thể dùng cách trên được.

Để giải quyết bài toán số lượng các thuộc tính trong object nhiều hoặc không biết trước, bạn có thể sử dụng [vòng lặp `for...in`](/bai-viet/javascript/cau-truc-lap-trong-javascript) để duyệt hết các thuộc tính của object.

Mình đã viết một [hàm](/bai-viet/javascript/ham-trong-javascript/) để so sánh từng thuộc tính và giá trị của object như sau:

```js
function isShallowEqual(obj1, obj2) {
  for (let prop in obj1) {
    if (obj1[prop] !== obj2[prop]) return false;
  }

  for (let prop in obj2) {
    if (obj2[prop] !== obj1[prop]) return false;
  }

  return true;
}

let point1 = { x: 1, y: 2 };
let point2 = { x: 1, y: 2 };
let point3 = { x: 2, y: 3 };

console.log(isShallowEqual(point1, point2)); // true
console.log(isShallowEqual(point1, point3)); // false
```

Ý tưởng của thuật toán trên là: **duyệt tất cả các thuộc tính** của một object và so sánh giá trị tương ứng trong hai object. Nếu hai giá trị khác nhau thì kết luận là hai object không bằng nhau.

Nếu hai trường hợp `return false` không xảy ra thì nghĩa là hai point bằng nhau, nên cuối cùng `return true`.

**Thuật toán so sánh nông trông có vẻ tốt, nhưng liệu có vấn đề gì với nó không?**

Câu trả lời là: **CÓ**.

Hãy xem ví dụ sau:

```js
function isShallowEqual(obj1, obj2) {
  for (let prop in obj1) {
    if (obj1[prop] !== obj2[prop]) return false;
  }

  for (let prop in obj2) {
    if (obj2[prop] !== obj1[prop]) return false;
  }

  return true;
}

let point1 = { x: 1, y: 2, metadata: { type: "point" } };
let point2 = { x: 1, y: 2, metadata: { type: "point" } };
console.log(isShallowEqual(point1, point2)); // false
```

Bây giờ, kết quả so sánh `point1` và `point2` lại trả về `false`. Nguyên nhân là thuộc tính `metadata` có giá trị kiểu **object**. Nên khi so sánh hai `metadata` cho nhau, chúng sẽ khác nhau.

Kết quả là hai object trên lại "không bằng nhau".

> **Kết luận**: thuật toán **so sánh nông** chỉ đúng khi giá trị các thuộc tính trong object có kiểu dữ liệu nguyên thủy.

##

So sánh sâu khá tương đồng với so sánh nông. Nhưng thay vì duyệt một cấp, so sánh sâu duyệt tất cả các cấp của object (trường hợp object lồng nhau).

Để triển khai thuật toán này, bạn cần phải biết về [thuật toán đệ quy](https://vi.wikipedia.org/wiki/%C4%90%E1%BB%87_quy). Do đó, mình sẽ không giải thích chi tiết trong bài viết này.

Sau đây là thuật toán so sánh sâu cho bạn tham khảo:

```js
// Hàm kiểm tra một giá trị là object
function isObject(obj) {
  return obj != null && typeof obj === "object";
}

// Hàm so sánh sâu
function isDeepEqual(obj1, obj2) {
  const keys1 = Object.keys(obj1); // trả về mảng các thuộc tính của obj1
  const keys2 = Object.keys(obj2); // trả về mảng các thuộc tính của obj2

  // nếu số lượng keys khác nhau thì chắc chắn khác nhau
  if (keys1.length !== keys2.length) {
    return false;
  }

  for (const key of keys1) {
    const val1 = obj1[key];
    const val2 = obj2[key];

    // kiểm tra xem hai giá trị có cùng là object hay không
    const areObjects = isObject(val1) && isObject(val2);

    // nếu cùng là object thì phải gọi đệ quy để so sánh 2 object
    if (areObjects && !isDeepEqual(val1, val2)) {
      return false;
    }

    // nếu không cùng là object thì so sánh giá trị
    if (!areObjects && val1 !== val2) {
      return false;
    }
  }

  return true;
}

let point1 = { x: 1, y: 2, metadata: { type: "point" } };
let point2 = { x: 1, y: 2, metadata: { type: "point" } };

console.log(isDeepEqual(point1, point2)); // true
```

Trên đây là thuật toán để so sánh sâu. Bạn có thể tham khảo để rèn luyện tư duy logic.

Còn trong dự án thực tế, bạn có thể sử dụng hàm thư viện [`_.isEqual`](https://docs-lodash.com/v4/is-equal/) để giải quyết bài toán nhanh hơn, tránh mất công sinh ra lỗi sau này.

## Tổng kết

Object lưu trữ dữ liệu theo kiểu tham chiếu. Vì vậy, việc so sánh 2 object trong JavaScript là dựa trên địa chỉ của object.

Một số cách so sánh 2 object trong JavaScript là:

- So sánh object bằng tham chiếu: sử dụng toán tử `==`, `===` hoặc hàm `Object.is`.
- So sánh object qua giá trị cách thủ công: so sánh giá trị từng thuộc tính giữa hai object.
- So sánh nông (shallow equality): duyệt tất cả các thuộc tính trong mỗi object để so sánh giá trị tương ứng theo một cấp độ.
- So sánh sâu (deep equality): duyệt tất cả các thuộc tính trong mỗi object theo tất cả các cấp độ (sử dụng thuật toán đệ quy) để so sánh giá trị ứng với các thuộc tính.
