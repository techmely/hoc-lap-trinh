---
title: "Các phương thức của kiểu dữ liệu nguyên thủy trong Javascript"
description: "JavaScript cho phép bạn sử dụng kiểu nguyên thủy giống như object. Nghĩa là bạn có thể gọi các phương thức của kiểu nguyên thủy giống như gọi với object."
keywords: [
  "Các phương thức của kiểu dữ liệu nguyên thủy trong Javascript",
  "cac kieu du lieu trong javascript",
  "kieu du lieu nguyen thuy trong javascript",
  "lay kieu du lieu trong javascript",
  "cau nao khong phai la kieu du lieu nguyen thuy cua javascript",
  "Các kiểu dữ liệu trong JavaScript",
  "Ép kiểu dữ liệu trong Javascript",
  "Lấy kiểu dữ liệu trong JavaScript",
  "Kiểu dữ liệu nguyên thủy trong Javascript"
]
chapter:
  name: "Kiểu dữ liệu trong Javascript"
  slug: "chuong-04-kieu-du-lieu-trong-javascript"
category:
  name: "Javascript"
  slug: "javascript"
image: https://user-images.githubusercontent.com/29374426/168241439-75b68bba-22a5-4a2c-a3a1-727cd6cb9839.png
position: 1
---

JavaScript cho phép bạn sử dụng kiểu nguyên thủy giống như object. Nghĩa là bạn có thể **gọi các phương thức của kiểu nguyên thủy** giống như gọi với object.

<img width="600" alt="Các phương thức của kiểu dữ liệu nguyên thủy trong Javascript" src="https://user-images.githubusercontent.com/29374426/168241439-75b68bba-22a5-4a2c-a3a1-727cd6cb9839.png">

Nghe có vẻ vô lý nhưng đúng là như vậy. Trước khi đi vào chi tiết, bạn cần phân biệt rõ kiểu nguyên thủy và object.

## Phân biệt kiểu nguyên thủy và object

► **[Kiểu nguyên thủy](/bai-viet/javascript/cac-kieu-du-lieu-trong-javascript):**

- Có 7 kiểu dữ liệu nguyên thủy là: **string, number, bigint, boolean, symbol, null và undefined**.
- Chỉ lưu một giá trị nguyên thủy.

► **[Object](/bai-viet/javascript/object-la-gi-object-trong-javascript):**

- Là tập hợp của các cặp **key-value**.
- Có thể khởi tạo object bằng cặp dấu `{}`, ví dụ `{ x: 1, y: 2 }`.
- Một số loại object đặc biệt trong JavaScript như: [`function`](/bai-viet/javascript/ham-trong-javascript/), `Date`, [`Set`](/bai-viet/javascript/set-trong-javascript), [`Map`](/map-trong-javascript),...

Điều đặc biệt nhất của object là bạn có thể **lưu hàm thành một thuộc tính** trong object. Hàm đó gọi là **[phương thức](/phuong-thuc-trong-javascript/)** của object, ví dụ:

```js
let p = {
  x: 1,
  y: 2,
  displayLog() {
    console.log(`{x: ${this.x}, y: ${this.y}}`);
  },
};

p.displayLog(); // {x: 1, y: 2}
```

Có nhiều object mặc định của JavaScript giúp bạn thao tác với ngày tháng, trình duyệt, xử lý lỗi,... Mỗi đối tượng có những thuộc tính và phương thức khác nhau.

Điều này giúp việc lập trình trở nên dễ dàng hơn. Nhưng ngược lại, **object tốn nhiều tài nguyên để lưu trữ hơn**.

Trên đây là sự khác nhau giữa kiểu nguyên thủy và object. Vậy **sử dụng các phương thức của kiểu nguyên thủy** nghĩa là thế nào?

## Các phương thức của kiểu nguyên thủy

Một nghịch lý khi tạo ra JavaScript là:

- Có nhiều thứ cần làm với kiểu nguyên thủy - string và number. Nghĩa là cần có các phương thức để làm việc với kiểu nguyên thủy.
- Nhưng kiểu nguyên thủy phải **đơn giản nhất có thể** - nhẹ nhất và nhanh nhất.

Để giải quyết vấn đề này, JavaScript thực hiện như sau:

- Kiểu nguyên thủy vẫn chỉ **lưu một giá trị duy nhất** mà **không lưu trữ các phương thức** nào khác.
- Khi gọi phương thức của kiểu nguyên thủy, thực chất là JavaScript engine tự động tạo ra một "wrapper object" - đối tượng đóng gói. Object này chứa giá trị kiểu nguyên thủy và phương thức cần gọi. Sau khi gọi xong phương thức, "wrapper object" sẽ được giải phóng.

Những "wrapper object" ứng với các kiểu dữ liệu nguyên thủy là: `Number`, `String`, `BigInt`, `Boolean`, `Symbol`. Những đối tượng này cung cấp các phương thức khác nhau để bạn làm việc với kiểu nguyên thủy.

<content-warning>

Kiểu dữ liệu `null` và `undefined` không có "wrapper object

</content-warning>

Ví dụ một phương thức của string là [`str.toUpperCase()`](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/String/toUpperCase). Phương thức này trả về giá trị string với **các kí tự đều viết hoa**.

```js
let name = "Alex";
console.log(name.toUpperCase()); // ALEX
```

Quá trình xử lý hiểu đơn giản là:

- Ban đầu khởi tạo biến `name` với giá trị kiểu string.
- Khi gọi `name.toUpperCase()`, JavaScript tạo một "wrapper object" chứa giá trị của `name` và phương thức `toUpperCase`.
- Phương thức `toUpperCase()` gọi xong trả về giá trị string mới (với tất cả các chữ cái được viết hoa), rồi hiển thị ra console.
- Sau đó, "wrapper object" được giải phóng, lúc này chỉ còn biến `name` - kiểu nguyên thủy.

Đó là cách gọi phương thức của kiểu nguyên thủy mà vẫn đảm bảo kiểu nguyên thủy đơn giản và nhẹ nhất có thể.

## Một số chú ý về các "wrapper object"

Các hàm khởi tạo `Number`, `String` và `Boolean` được JavaScript Engine sử dụng nội bộ.

Bạn có thể chủ động sử dụng các hàm khởi tạo này với [toán tử `new`](/bai-viet/javascript/khoi-tao-doi-tuong-voi-tu-khoa-new-trong-javascript) để tạo ra "wrapper object". Nhưng thực tế là bạn **không nên**, vì có nhiều trường hợp gây khó hiểu.

```js
let zero = 0;
console.log(typeof zero); // number

let objZero = new Number(0);
console.log(typeof objZero); // object
```

Bạn thấy rằng, `0` là kiểu **number** nhưng `new Number(0)` lại là kiểu **object**. Mà object thì luôn là **[truthy](/bai-viet/javascript/toan-tu-logic-trong-javascript)**.

Ví dụ sử dụng `new Number(0)` với [câu lệnh `if`](/bai-viet/javascript/cau-truc-re-nhanh-trong-javascript/):

```js
let objZero = new Number(0);

if (objZero) {
  console.log("zero là truthy!"); // zero là truthy!
}
```

Điều này đôi khi khá khó hiểu và dễ gây nhầm lẫn.

Vì vậy, lời khuyên là bạn không nên dùng `Number()`, `String()` hay `Boolean()` với toán `new` để khởi tạo.

**Nhưng nếu sử dụng các hàm này mà không dùng toán tử `new` thì sao?**

Việc không sử dụng toán tử `new` với các hàm trên lại khá hữu ích. Chúng sẽ [chuyển đổi kiểu dữ liệu](/bai-viet/javascript/chuyen-doi-kieu-du-lieu-trong-javascript) về kiểu nguyên thủy tương ứng.

Ví dụ sử dụng hàm `Number()` để chuyển đổi kiểu dữ liệu về number:

```js
let num = Number("123");
console.log(num); // 123
console.log(typeof num); // number
```

<content-warning>

 Không gọi được phương thức ứng với kiểu `null` và `undefined`.

 </content-warning>

<content-example>

  Gọi phương thức của `null` và `undefined` đều bị lỗi như sau:

</content-example>

```js
console.log(null.toUpperCase());
// Uncaught TypeError:
// Cannot read properties of null (reading 'toUpperCase')

console.log(undefined.toUpperCase());
// Uncaught TypeError:
// Cannot read properties of undefined (reading 'toUpperCase')
```

## Tổng kết

Có thể gọi phương thức của kiểu nguyên thủy (trừ `null` và `undefined`).

Cơ chế hoạt động là: JavaScript tạo ra một "wrapper object" chứa giá trị nguyên thủy và phương thức sử dụng. Sau khi phương thức gọi xong thì "wrapper object" được giải phóng.

Các bài viết sau mình sẽ đi vào chi tiết các phương thức hữu ích của: `Number()` và `String()`.

## Thực hành

Cho đoạn code sau:

```js
let str = "Hello";
str.prop = 1;
console.log(str.prop);
```

Kết quả hiển thị là gì?

Xem đáp án

Kết quả là: `undefined`.

Giải thích:

- Khi gọi `str.prop = 1`, JavaScript tạo ra một "wrapper object" chứa giá trị `str` và thuộc tính mới thêm vào `prop`.
- Nhưng sau câu lệnh đó, "wrapper object" bị hủy và chỉ còn lại giá trị nguyên thủy `str`.
- Vì vậy, kết quả là `undefined`.

**Chú ý:**

Nếu sử dụng [strict mode](/bai-viet/javascript/strict-mode-trong-javascript) thì bạn sẽ bị lỗi **Uncaught TypeError: Cannot create property 'prop' on string 'Hello'**

Tham khảo: [Methods of primitives](https://javascript.info/primitives-methods).
