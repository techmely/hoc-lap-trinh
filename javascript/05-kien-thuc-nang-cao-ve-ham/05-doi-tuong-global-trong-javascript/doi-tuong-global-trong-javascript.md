---
title: "Đối tượng global trong Javascript"
description: "Đối tượng global trong JavaScript cung cấp các biến và hàm được sử dụng ở mọi nơi trong chương trình."
keywords: [
"Đối tượng global trong Javascript",
"Thêm sửa xoá trong Javascript",
"Sự kiện trong JavaScript",
"classname trong javascript",
"dung javascript xu ly su kien",
"Đối tượng global trong Javascript là gì",
"Cách sử dụng đối tượng global trong Javascript",
"scope trong javascript",
"global trong javascript"
]
chapter:
  name: "Kiến thức nâng cao về hàm"
  slug: "chuong-05-kien-thuc-nang-cao-ve-ham"
category:
  name: "Javascript"
  slug: "javascript"
image: https://kungfutech.edu.vn/thumbnail.png
position: 5
---

Bài viết này giúp bạn tìm hiểu về đối tượng global trong JavaScript. Qua đây, bạn biết khi nào nên sử dụng đối tượng global.

## Đối tượng global là gì?

**Đối tượng global trong JavaScript** cung cấp các biến và hàm được sử dụng ở mọi nơi trong chương trình.

- Trên trình duyệt, đó là đối tượng `window`.
- Trong Node.js, đó là đối tượng `global`.
- Trong môi trường khác thì có thể là đối tượng với tên khác.

Gần đây, đối tượng `globalThis` mới được thêm vào JavaScript. Đây là tên chuẩn được dùng cho đối tượng global ở tất cả các môi trường và tất cả các trình duyệt khác nhau.

<content-warning>

**Chú ý:** trong bài viết này, mình chủ yếu dùng `window` khi nói về đối tượng global trong JavaScript.

</content-warning>

Vì mình giả sử rằng, bạn đang đọc và thử nghiệm code ngay trên [Dev Tool](/bai-viet/javascript/dev-tools-la-gi/) của trình duyệt. Nếu bạn chạy code trên môi trường khác thì có thể thay thế `window` bằng `globalThis`.

Tất cả các thuộc tính của đối tượng global trong JavaScript có thể được truy cập ở mọi nơi:

```js
console.log("Hello");

// tương đương với
window.console.log("Hello");
```

Trên trình duyệt, hàm và biến toàn cục được khai báo với `var` (không phải `let/const`) đều trở thành thuộc tính của global object:

```js
// khai báo biến với var
var gVar = 6;
console.log(window.gVar); // 6
// gVar trở thành thuộc tính của đối tượng global

// khai báo hàm với function
function sayHi() {
  console.log("Hi!");
}
window.sayHi(); // Hi!
// hàm sayHi cũng trở thành thuộc tính của window
```

Nếu bạn sử dụng `let` để khai báo biến thì biến đó không trở thành thuộc tính của đối tượng global trong JavaScript:

```js
// khai báo biến với let
let gLet = 6;
console.log(window.gLet); // undefined
```

Nếu một biến quan trọng và bạn thật sự muốn sử dụng biến đó ở mọi nơi trong chương trình. Bạn nên chủ động gán biến đó vào đối tượng global như sau:

```js
// tạo đối tượng global: currentUser
window.currentUser = {
  name: "Alex",
};

// sử dụng ở nơi nào đó trong code
console.log(currentUser.name); // Alex

// hoặc nếu bạn có biến cục bộ nào đó trùng tên
// bạn nên chủ động gọi thông qua window
console.log(window.currentUser.name); // Alex
```

Nhìn chung, bạn không nên sử dụng biến toàn cục. Việc sử dụng biến toàn cục nhiều sẽ khiến bạn khó theo dõi logic code khi số lượng code bắt đầu nhiều lên.

## Sử dụng polyfills

Bạn có thể sử dụng global object để kiểm tra xem một tính năng có đang được hỗ trợ hay không.

Ví dụ, bạn muốn kiểm tra đối tượng `Promise` có tồn tại trên `window` hay không (chú ý đối tượng `Promise` không tồn tại ở trình duyệt cũ):

```js
if (!window.Promise) {
  console.log("You're using an old browser!");
}
```

Nếu đối tượng `Promise` thật sự không tồn tại trên `window`, bạn có thể tạo **polyfills** để thay thế `Promise`. Việc này giúp code của bạn hoạt động được trên các phiên bản trình duyệt khác nhau:

```js
if (!window.Promise) {
  window.Promise = ... // triển khai Promise nếu trình duyệt chưa hỗ trợ
}
```

## Tổng kết

Đối tượng global chứa các biến và hàm có thể sử dụng ở mọi nơi trong chương trình. Bao gồm các kiểu dữ liệu đặc biệt và có sẵn như `Array`, `Map`, `Set`,... và một số giá trị của môi trường như `window.innerHeight` - chiều cao của window trên trình duyệt...

Gần đây, đối tượng `globalThis` được thêm vào JavaScript, trở thành tên tiêu chuẩn cho đối tượng global. Đối tượng `globalThis` tồn tại trên các môi trường khác nhau và các trình duyệt khác nhau.

Tuy nhiên, có thể mọi người vẫn hay sử dụng tên cũ hơn, đó là `window` trên trình duyệt và `global` trong Node.js.

Trên trình duyệt, trừ khi bạn đang **sử dụng module**, các hàm và biến toàn cục được khai báo với `var` đều trở thành thuộc tính của đối tượng global.

Để code dễ hiểu hơn, khi truy cập vào các thuộc tính của đối tượng global, bạn nên chủ động sử dụng đối tượng global, ví dụ `window.x`.

Nhìn chung, bạn nên hạn chế sử dụng biến toàn cục. Vì sử dụng biến toàn cục khiến logic chương trình trở nên khó theo dõi và khó debug khi có lỗi xảy ra.

Hãy chỉ sử dụng đối tượng global trong JavaScript khi thực sự cần thiết.

Tham khảo: [Global object](https://javascript.info/global-object)
