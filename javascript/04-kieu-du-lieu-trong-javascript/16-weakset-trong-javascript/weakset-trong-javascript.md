---
title: "Weakset trong Javascript"
description: "WeakSet trong JavaScript cũng là một loại object đặc biệt, dùng để lưu trữ dữ liệu một cách duy nhất, không trùng lặp - tương tự như Set."
keywords: [
"WeakSet trong JavaScript",
"WeakSet trong JavaScript là gì",
"WeakSet trong JavaScript cách sử dụng",
"WeakSet JavaScript là gì",
"WeakSet JavaScript",
"Collection WeakSet trong ES6 javascript",
"Collection WeakSet trong ES6 là gì trong javascript",
"JavaScript Set và WeakSet ",
"JavaScript Set và WeakSet cách sử dụng",
"JavaScript Set và WeakSet là gì"
]
chapter:
  name: "Kiểu dữ liệu trong Javascript"
  slug: "chuong-04-kieu-du-lieu-trong-javascript"
category:
  name: "Javascript"
  slug: "javascript"
image: https://user-images.githubusercontent.com/29374426/168244102-624b9c52-c648-49d6-93ee-188e99530e1a.png
position: 16
---

WeakSet trong JavaScript cũng là một loại object đặc biệt, dùng để **lưu trữ dữ liệu một cách duy nhất**, không trùng lặp - tương tự như [Set](/bai-viet/javascript/set-trong-javascript/).

![Weakset trong Javascript](https://user-images.githubusercontent.com/29374426/168244102-624b9c52-c648-49d6-93ee-188e99530e1a.png)


Tuy nhiên, cũng giống như [WeakMap](/bai-viet/javascript/weakmap-trong-javascript), WeakSet chỉ cho phép lưu trữ dữ liệu kiểu [object](/bai-viet/javascript/object-la-gi-object-trong-javascript) (không chấp nhận kiểu nguyên thủy).

## Cú pháp khởi tạo WeakSet

Để khởi tạo WeakSet trong JavaScript, bạn sử dụng hàm khởi tạo như sau:

```js
new WeakSet([iterable]);
```

Trong đó:

- Tham số `iterable` là một [iterable object](/bai-viet/javascript/iterable-trong-javascript) (không bắt buộc), với mỗi phần tử là một object.
- Nếu không truyền tham số vào hàm khởi tạo thì WeakSet sẽ rỗng.

Ví dụ:

```js
// khởi tạo WeakSet rỗng
let ws1 = new WeakSet(); // OK

// khởi tạo WeakSet với iterable object với mỗi phần tử là object
let obj1 = { x: 1 };
let ws2 = new WeakSet([obj1]); // OK

// khởi tạo WeakSet với iterable object nhưng mỗi phần tử không phải object
let ws3 = new WeakSet([1, "2"]); // Lỗi: Invalid value used in weak set
```

## Các phương thức của WeakSet

Sau đây là các phương thức của WeakSet trong JavaScript.

► Phương thức `weakSet.add(value)`:

Thêm giá trị `value` vào WeakSet và trả về chính WeakSet đó.

```js
let obj1 = { x: 1 };
let obj2 = { x: 2 };

let ws = new WeakSet();
ws.add(obj1).add(obj2).add(obj1); // OK
// Add value không phải là object vào set
ws.add(1); // Lỗi: Invalid value used in weak set
```

► Phương thức `weakSet.has(value)`:

Trả về `true` nếu giá trị `value` có tồn tại trong WeakSet, ngược lại thì trả về `false`.

```js
let obj1 = { x: 1 };
let obj2 = { x: 2 };

let ws = new WeakSet();
ws.add(obj1).add(obj2).add(obj1);

console.log(ws.has(obj1)); // trueconsole.log(ws.has(obj2)); // trueconsole.log(ws.has({ x: 1 })); // false
```

Vì object là kiểu dữ liệu tham chiếu nên `{x: 1} !== {x: 1}`. Do đó, câu lệnh `ws.has({ x: 1 })` trả về `false`.

► Phương thức `weakSet.delete(value)`:

Xóa giá trị `value` khỏi WeakSet và trả về `true` nếu giá trị đó tồn tại, ngược lại thì trả về `false`.

```js
let obj1 = { x: 1 };
let obj2 = { x: 2 };

let ws = new WeakSet();
ws.add(obj1).add(obj2).add(obj1);

console.log(ws.delete(obj1)); // trueconsole.log(ws.delete(obj2)); // trueconsole.log(ws.delete({ x: 1 })); // falseconsole.log(ws.delete(obj1)); // false
```

Tương tự như trên, vì object là kiểu dữ liệu tham chiếu nên `{x: 1} !== {x: 1}`. Do đó, câu lệnh `ws.delete({ x: 1 })` trả về `false`.

Câu lệnh cuối cùng `ws.delete(obj1)` cũng trả về `false` vì trước đó mình đã xóa giá trị `obj1` ra khỏi `ws` rồi.

## So sánh WeakSet và Set

Sau đây là một số đặc điểm khác nhau giữa Set và WeakSet trong JavaScript.

### Kiểu dữ liệu của key

Đối với Set, key có thể thuộc bất kỳ kiểu dữ liệu nào. Nhưng đối với WeakSet thì ngược lại, key **chỉ có thể là object**.

```js
let set = new Set();
let weakSet = new WeakSet();

set.add(1); // OK
weakSet.add(1); // Lỗi - Invalid value used in weak set
```

### Tính chất của iterable object

Set là iterable object. Do đó, bạn có thể duyệt qua hết tất cả các phần tử trong Set.

WeakSet không phải là iterable object. Bạn không có cách nào để duyệt hết tất cả các phần tử của WeakSet.

```js
// khởi tạo set
let set = new Set();
set.add(1).add("b");

// duyệt qua các phần tử của set
for (let item of set) {
  console.log(item);
  /**
   * 1
   * 'b'
   */
}

// khởi tạo weakSet
let obj1 = { x: 1 };
let obj2 = { x: 2 };
let weakSet = new WeakSet();
weakSet.add(obj1).add(obj2);

// duyệt qua các phần tử của weakSet
for (let item of weakSet) {
  console.log(item);
}
/**
 * Lỗi: weakSet is not iterable
 */
```

### Vấn đề garbage collection

Khi một biến là object được lưu vào Set, dù biến đó có bị gán bằng `null` thì object vẫn tồn tại trong Set.

```js
// khởi tạo object
let obj1 = { x: 1 };

// khởi tạo set và thêm object trên vào set
let set = new Set();
set.add(obj1);

// gán obj1 bằng null
obj1 = null;

// mặc dù obj1 được gán thành null, nhưng object vẫn tồn tại trong set
console.log(set.size); // 1
for (let item of set) {
  console.log(item); // {x: 1}
}
```

Đối với WeakSet thì ngược lại, một khi biến object được gán bằng `null` thì không có cách nào truy cập vào phần tử đó trong Set. Do đó, object sẽ được giải phóng.

## Tổng kết

WeakSet trong JavaScript tương tự như Set, cho phép **lưu trữ dữ liệu một cách duy nhất**, không trùng lặp. Tuy nhiên, WeakSet chỉ chấp nhận phần tử kiểu object.

Và khi object bị hủy, object tương ứng trong WeakSet sẽ bị giải phóng vì không còn cách nào để truy cập vào object đó nữa.

Các phương thức của WeakSet là:

- `weakSet.add(value)`: lưu giá trị `value` vào WeakSet và trả về chính WeakSet.
- `weakSet.delete(value)`: xóa phần tử `value` trong WeakSet, nếu `value` tồn tại thì trả về `true`, ngược lại thì trả về `false`.
- `weakSet.has(value)`: trả về `true` nếu `value` tồn tại trong `weakSet`, ngược lại thì trả về `false`.

WeakSet không phải iterable object nên không có cách nào để duyệt hết các phần tử trong WeakSet (như cách dùng `for...of` với Set).

Tham khảo: [WeakMap and WeakSet](https://javascript.info/weakmap-weakset)
