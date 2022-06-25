---
title: "Local storage thay cho Index DB"
description: "LocalStorage cho phép web dev lưu dữ liệu dưới dạng key-value trên máy của user. Việc lưu dữ liệu như vậy sẽ giúp cải thiện performance khi mà số lượng request database phía server được giảm đi, từ đó giảm chi phí hạ tầng server."
keywords: [
"Javascript IndexedDB là gì",
"IndexedDB trong javascript",
"tim hieu javascript indexeddb la gi trong javascript",
"indexeddb co tac dung gi trong javascript",
"IndexedDB vs localStorage trong javascript",
"IndexedDB max size trong javascript",
"kho lưu trữ dữ liệu trong javascript",
"JavaScript IndexedDB",
"Local storage trong javascript",
"Local storage la gi trong javascript",
"luu tru du lieu voi Local storage trong javascript"
]
chapter:
  name: "Lưu trữ dữ liệu"
  slug: "chuong-15-luu-tru-du-lieu"
category:
  name: "Javascript"
  slug: "javascript"
image: https://kungfutech.edu.vn/thumbnail.png
position: 2
---

[IndexedDB](/bai-viet/javascript/indexed-db-trong-javascript) là một local database dạng NoSQL cho phép lưu trữ dữ liệu ngay trên trình duyệt. Nó cho phép lưu trữ một lượng dữ liệu lớn với các kiểu dữ liệu khác nhau (bao gồm cả file/blob); hỗ trợ trên nhiều trình duyệt và cung cấp khả năng truy cập nhanh. Qua đó, IndexedDB giúp cho web app có khả năng hoạt động offline một cách mượt mà.

Tuy nhiên, IndexedDB lại có nhược điểm lớn là nó chỉ cung cấp API cấp thấp. Khi sử dụng IndexedDB bạn phải quan tâm đến những thứ như: transaction, objectStore, cursor,... và nó còn không hỗ trợ [Promise](https://developer.mozilla.org/docs/Web/JavaScript/Reference/Global_Objects/Promise). Điều này làm cho việc sử dụng IndexedDB trở nên khá khó khăn và phức tạp.

May mắn thay, [localForage](https://localforage.github.io/localForage) đã ra đời và giúp cho việc sử dụng IndexedDB trở nên đơn giản hơn rất nhiều.

## LocalForage là gì?

LocalForage là một thư viện JavaScript mã nguồn mở, giúp cho việc giao tiếp với database trên trình duyệt (đặc biệt là IndexedDB) trở nên đơn giản hơn và tiện lợi hơn với những đặc điểm:

- API gần giống với [localStorage](https://developer.mozilla.org/en-US/docs/Web/API/Window/localStorage) bao gồm: _setItem()_, _getItem()_, _removeItem()_, _clear()_ và thêm một số API khác nữa.
- Hỗ trợ ES6 Promise API
- Hỗ trợ sử dụng IndexedDB và [Web SQL](https://en.wikipedia.org/wiki/Web_SQL_Database). Tuy nhiên, nếu browser không hỗ trợ thì localForage sẽ quay về sử dụng localStorage.
- [Hỗ trợ trên nhiều trình duyệt khác nhau](https://caniuse.com/#feat=indexeddb) như: Chrome, Firefox, IE, và Safari (bao gồm cả Safari Mobile).

## Cài đặt

Việc cài đặt localForage khá đơn giản. Bạn có thể sử dụng thông qua CDN và chèn thẳng vào HTML như sau:

```html
<script src="https://unpkg.com/localforage@1.7.3/dist/localforage.min.js"></script>
```

Hoặc tải [phiên bản release mới nhất](https://github.com/mozilla/localForage/releases) trên Github về rồi sử dụng luôn:

```html
<script src="localforage.js"></script>
<script>
  console.log("localforage is: ", localforage);
</script>
```

mà không cần phải **init** hay chờ các sự kiện như **onready**.

Ngoài ra, bạn cũng có thể cài đặt localForage thông qua npm hoặc bower như sau:

```sh
# Cài đặt qua npm:
npm install localforage

# Hoặc cài đặt qua bower:
bower install localforage
```

Và sử dụng nó với các bundler (như Webpack) bằng cách:

```js
import localforage from "localforage";
localforage.setItem("key", "value");
```

## Cách sử dụng một số API của localForage

### setItem()

Như mình đã nói ở trên, với `localForage` bạn không cần phải cài đặt, init database nên có thể ghi dữ liệu ngay lập tức với phương thức _setItem()_.

Cú pháp:

```js
// Sử dụng callback
localforage.setItem(key, value, successCallback);

// Hoặc sử dụng promise
localforage
  .setItem(key, value)
  .then(function (value) {
    // Xử lý khi việc lưu key-value thành công
    console.log(value);
  })
  .catch(function (err) {
    // Xử lý khi việc lưu key-value bị lỗi
    console.log(err);
  });
```

Trong đó:

- **key**: là string, phân biệt hoa-thường và được sử dụng để lấy giá trị ra sau này.
- **value**: là dữ liệu tương ứng với key. Nhưng nếu như localStorage chỉ cho phép lưu value dạng string thì localForage cho phép value với bất kì kiểu dữ liệu nào ([number, string](/bai-viet/javascript/cac-kieu-du-lieu-trong-javascript), [array](/bai-viet/javascript/mang-array-trong-javascript), [object](/bai-viet/javascript/object-la-gi-object-trong-javascript), [file/blob](https://developer.mozilla.org/en-US/docs/Web/API/Blob)).

Ví dụ:

```js
localforage
  .setItem("my point", { x: 1, y: 2 })
  .then(function (value) {
    console.log(value);
    // => {x: 1, y: 2}
  })
  .catch(function (err) {
    console.log(err);
  });
```

<content-warning>

**Chú ý**: nếu bạn sử dụng _setItem()_ lại một lần nữa với key đã tồn tại thì giá trị của nó sẽ bị ghi đè.

</content-warning>

### getItem()

Sau khi sử dụng _setItem()_ để ghi dữ liệu, bạn có thể dùng _getItem()_ để lấy dữ liệu ra, với cú pháp như sau:

```js
// Sử dụng callback
localforage.getItem(key, successCallback);

// Hoặc sử dụng promise
localforage
  .getItem(key)
  .then(function (value) {
    // Xử lý khi việc lấy giá trị với key thành công
    console.log(value);
  })
  .catch(function (err) {
    // Xử lý khi việc lấy giá trị với key bị lỗi
    console.log(err);
  });
```

Ví dụ:

```js
localforage
  .getItem("my point")
  .then(function (value) {
    console.log(value.x, value.y);
    // => 1 2
  })
  .catch(function (err) {
    console.log(err);
  });
```

<content-warning>

**Chú ý:** nếu bạn sử dụng _getItem()_ với key chưa tồn tại thì promise vẫn trả về trường hợp thành công, nhưng lúc này giá trị của value là **null**.

</content-warning>

```js
localforage
  .getItem("her point")
  .then(function (value) {
    console.log(value);
    // => null
  })
  .catch(function (err) {
    console.log(err);
  });
```

### removeItem()

Phương thức này dùng để loại bỏ cặp key-value ra khỏi database.

Cú pháp:

```js
// Sử dụng callback
localforage.removeItem(key, successCallback);

// Hoặc sử dụng promise
localforage
  .removeItem(key)
  .then(function () {
    // Xử lý khi việc remove thành công
    console.log("Key is cleared!");
  })
  .catch(function (err) {
    // Xử lý khi việc remove bị lỗi
    console.log(err);
  });
```

Ví dụ:

```js
localforage
  .removeItem("my point")
  .then(function () {
    console.log("Key is cleared!");
    // => Key is cleared!
  })
  .catch(function (err) {
    console.log(err);
  });
```

<content-warning>

**Chú ý**: nếu bạn _removeItem()_ với key không tồn tại, thì phương thức này vẫn coi như thành công.

</content-warning>

```js
localforage
  .removeItem("her point")
  .then(function () {
    console.log("Key is cleared!");
    // => Key is cleared!
  })
  .catch(function (err) {
    console.log(err);
  });
```

### clear()

Phương thức _clear()_ sẽ xoá bỏ toàn bộ cặp key-value tồn tại trong database.

Cú pháp:

```js
// Sử dụng callback
localforage.clear(successCallback);

// Hoặc sử dụng promise
localforage
  .clear()
  .then(function () {
    // Xử lý khi xoá database thành công
    console.log("Database is now empty.");
  })
  .catch(function (err) {
    // Xử lý khi việc xoá bị lỗi.
    console.log(err);
  });
```

<content-warning>

**Chú ý:** khi sử dụng phương thức này đồng nghĩa với toàn bộ dữ liệu trong database sẽ bị xoá. Vì vậy, bạn cần phải cẩn trọng khi sử dụng phương thức này.

</content-warning>

### Một số API khác

Ngoài 4 API giống với localStorage như trên ra, localForage còn hỗ trợ một số API khác như:

- `length(successCallback)`: trả về số lượng cặp key-value trong database.
- `keys(successCallback)`: trả về một mảng chứa các key trong database.
- `iterate(iteratorCallback, successCallback)`: dùng để duyệt hết các cặp key-value trong database, hoạt động tương tự như phương thức [forEach](/bai-viet/javascript/tim-hieu-ve-foreach-trong-javascript).
- key(keyIndex, successCallback): trả về tên của key tương ứng với ID của nó.

## Cấu hình localForage

Mặc dù, bạn không cần phải cài đặt gì vẫn có thể sử dụng localForage (như trên). Tuy nhiên, localForage cũng hỗ trợ bạn cấu hình những thông tin quan trọng cho nó.

### setDriver()

Phương thức này dùng để xác định loại storage sẽ được sử dụng cho localForage.

Mặc định, nếu sử dụng như trên mà không dùng _setDriver()_ thì localForage sẽ sử dụng các loại storage mặc định theo thứ tự là: **IndexedDB**, **WebSQL**, **localStorage**. Nghĩa là localForage sẽ ưu tiên dùng IndexedDB trước; nếu trình duyệt không hỗ trợ thì chuyển sang dùng WebSQL; nếu trình duyệt cũng không hỗ trợ WebSQL nữa thì chuyển sang dùng localStorage.

Cú pháp của phương thức này là:

```js
setDriver(driverName);

// Hoặc
setDriver([driverName, nextDriverName]);
```

Trong đó, các tham số của phương thức nhận một trong 3 giá trị là:

- _localforage.INDEXEDDB_
- _localforage.WEBSQL_
- _localforage.LOCALSTORAGE_

Ví dụ:

```js
// Yêu cầu localForage sử dụng localStorage
localforage.setDriver(localforage.LOCALSTORAGE);

// Yêu cầu localForage ưu tiên sử dụng WebSQL rồi mới đến IndexedDB
localforage.setDriver([localforage.WEBSQL, localforage.INDEXEDDB]);
```

### config()

Phương thức này dùng để cài đặt một số thông tin như: _driver, name, size, storeName, version, description_.

Cú pháp:

```js
localforage.config({
  driver,
  name,
  size,
  storeName,
  version,
  description,
});
```

**Chú ý:** khác với hầu hết các API của localForage - là bất đồng bộ, thì phương thức _config()_ lại xử lý đồng bộ.

## Sử dụng nhiều database

Mặc định như trên, localForage sẽ lưu dữ liệu ở một nơi gọi là **global store** (toàn cục). Tuy nhiên, nhiều khi bạn muốn lưu trữ dữ liệu thành nhiều store khác nhau để quản lý cho dễ, lúc này bạn có thể sử dụng phương thức _createInstance()_.

Ví dụ mình tạo ra 2 instance của localForage để lưu trữ toạ độ điểm ở không gian 2 chiều và 3 chiều:

```js
let twoDStore = localforage.createInstance({
  name: "2-D",
});

let threeDStore = localforage.createInstance({
  name: "3-D",
});
```

Khi đó dữ liệu ở mỗi instance sẽ không liên quan đến nhau (kể cả khi chúng có cùng key):

```js
twoDStore.setItem("a", { x: 1, y: 2 });
threeDStore.setItem("a", { x: 1, y: 2, z: 3 });

twoDStore.getItem("a").then((value) => {
  console.log(value);
  // => {x: 1, y: 2}
});

threeDStore.getItem("a").then((value) => {
  console.log(value);
  // => {x: 1, y: 2, z: 3}
});
```

## Lời kết

Trên đây là những kiến thức cơ bản về localForage. Theo mình, đây là một trong những công cụ tốt nhất để quản lý dữ liệu database phía client.

Còn theo bạn, việc sử dụng localForage là dễ hay khó? Và bạn thường sử dụng công cụ nào để quản lý database phía trình duyệt? Để lại bình luận phía dưới để chia sẻ ý kiến của mình nhé!

Để xem thêm các API khác của localForage, bạn có thể xem thêm tại:

- [Trang chủ](https://localforage.github.io/localForage/).
- [localForage trên Github](https://github.com/localForage/localForage/).
