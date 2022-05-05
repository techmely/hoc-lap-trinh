---
title: "Cú pháp new Function trong Javascript"
description: "Là một cách khác để định nghĩa hàm. Cách này ít khi được sử dụng, nhưng đôi khi lại rất hữu ích."
keywords: [
"Cú pháp new Function trong Javascript",
"new Function trong Javascript",
"new Function trong Javascript dùng để làm gì",
"cách sử dụng new Function trong Javascript",
"ham trong ham javascript",
"cach tao ham moi trong javascript",
"cu phap new function trong javascript làm gì",
"function trong javascript",
"từ khoá new trong javascript"
]
chapter:
  name: "Kiến thức nâng cao về hàm"
  slug: "chuong-05-kien-thuc-nang-cao-ve-ham"
category:
  name: "Javascript"
  slug: "javascript"
image: https://kungfutech.edu.vn/thumbnail.png
position: 7
---

Cú pháp `new Function` trong JavaScript là một cách khác để định nghĩa hàm. Cách này ít khi được sử dụng, nhưng đôi khi lại rất hữu ích.

## Cú pháp new Function

Cú pháp `new Function` để định nghĩa hàm như sau:

```js
let func = new Function([arg1, arg2, ...argN], functionBody);
```

Trong đó:

- `[arg1, arg2, ...argN]`: là danh sách các tham số truyền vào hàm.
- `functionBody`: là **string** dùng để mô tả hàm.

Ví dụ **hàm tính tổng** sau nhận vào hai số `a` và `b` rồi trả về tổng `a + b`:

```js
let sum = new Function("a", "b", "return a + b");

console.log(sum(1, 2)); // 3
```

Hoặc **hàm không có tham số** truyền vào:

```js
let sayHi = new Function('console.log("Hello")');

sayHi(); // Hello
```

**Điểm khác nhau quan trọng** giữa cú pháp `new Function` trong JavaScript với các cách định nghĩa hàm khác là:

- Cú pháp `new Function` sử dụng **string** để định nghĩa thân hàm.
- Quá trình định nghĩa hàm được thực hiện **runtime** (trong thời điểm chạy chương trình).

Với tất cả các cách khác, bạn phải định nghĩa hàm ngay từ đầu. Nhưng cú pháp `new Function` lại có thể chuyển **string** thành hàm.

Điều này cho phép bạn định nghĩa hàm bằng cách nhận **string từ server** (hoặc nguồn khác) rồi thực thi hàm:

```js
let str = /*... nhận được từ server ...*/

// khởi tạo hàm từ string nhận được trên
let func = new Function(str);

// thực thi hàm
func();
```

## Mối liên quan với closure

Thông thường, một hàm trong JavaScript sẽ lưu những thông tin của môi trường - nơi mà hàm được tạo ra, đó chính là **Lexical Environment**.

Nếu một hàm được định nghĩa thông qua cú pháp `new Function` thì lại khác. Hàm này không lưu thông tin của môi trường nơi hàm tạo ra mà lại lưu thông tin của [môi trường global](/bai-viet/javascript/doi-tuong-global-trong-javascript), ví dụ:

```js
window.value = "test from window";

function getFunc() {
  let value = "test from getFunc";

  let func = new Function("console.log(value)");

  return func;
}

getFunc()(); // test from window
```

Trong ví dụ trên, hàm `func` được tạo ra bên trong hàm `getFunc` nhưng lại không nhìn thấy biến `value` bên ngoài.

Nói cách khác, biến `value` ở câu lệnh `console.log(value)` sẽ được tham chiếu đến đối tượng global (với trình duyệt thì đó là đối tượng `window`).

So sánh với cách định nghĩa hàm thông thường:

```js
window.value = "test from window";

function getFunc() {
  let value = "test from getFunc";

  let func = function () {
    console.log(value);
  };

  return func;
}

getFunc()(); // "test from getFunc" - giá trị của value lấy ở bên ngoài
```

Đặc điểm trên của cú pháp `new Function` trong JavaScript có vẻ lạ, nhưng lại rất hợp lý.

Tưởng tượng bạn cần phải tạo một hàm từ string. Mà nội dung của hàm lại **không biết trước** nên không thể định nghĩa hàm theo cách thông thường.

Giả sử hàm mới này cần tương tác với mã nguồn chính, cụ thể là **đọc giá trị của một biến**.

Vấn đề xảy ra ở đây là: trước khi triển khai web lên môi trường thật, mã nguồn thường được **nén lại** để giảm thiểu dung lượng.

Cụ thể là chương trình nén sẽ **xóa bỏ dấu cách**, **ghi chú code** và đặc biệt là **đổi tên biến thành dạng ngắn gọn hơn**. Ví dụ biến `userName` được đổi thành `a` chẳng hạn.

Nếu hàm tạo bởi `new Function` muốn đọc giá trị của biến `userName` thì sẽ sinh ra lỗi, vì không tìm thấy biến `userName` nữa.

<content-info>

Để đọc giá trị của biến bên ngoài với cú pháp `new Function`, bạn hãy truyền giá trị của biến đó vào hàm thông qua tham số.

</content-info>

## Tổng kết

Cú pháp `new Function` trong JavaScript là:

```js
let func = new Function([arg1, arg2, ...argN], functionBody);
```

Bạn có thể truyền tham số vào hàm theo các cách khác nhau như sau:

```js
// cú pháp cơ bản
new Function("a", "b", "return a + b");

// các tham số cách nhau bởi dấu phẩy
new Function("a,b", "return a + b");

// các tham số cách nhau bởi dấu phẩy và có dấu cách
new Function("a , b", "return a + b");
```

Hàm tạo bởi `new Function` không tham chiếu tới môi trường nơi hàm được tạo ra, mà tham chiếu đến đối tượng global.

Vì vậy, hàm này không thể đọc được giá trị của biến ngoài hàm. Điều này là tốt vì nó giúp tránh được nhiều lỗi.

Để đọc giá trị của biến trong hàm `new Function`, hãy truyền giá trị của biến vào hàm thông qua tham số.

Tham khảo: [The "new Function" syntax](https://javascript.info/new-function)
