---
title: "Kế thừa built-in class trong Javascript"
description: ""
keywords: []
chapter:
  name: "ES6 Class"
  slug: "chuong-08-es6-class"
category:
  name: "Javascript"
  slug: "javascript"
image: https://kungfutech.edu.vn/thumbnail.png
position: 5
---

Bạn có thể kế thừa built-in class trong JavaScript như **Array, Map**,...

> Built-in class là các class được định nghĩa bởi JavaScript.

## Ví dụ kế thừa class Array

Sau đây, mình sẽ tạo class `MyArray` kế thừa từ class `Array` và bổ sung thêm phương thức `isEmpty()` như sau:

    class MyArray extends Array {
      isEmpty() {
        return this.length === 0;
      }
    }

    let arr = new MyArray(1, 2, 5, 3, 4);
    console.log(arr.isEmpty()); // false

    let filteredArr = arr.filter((item) => item >= 3);
    console.log(filteredArr); // 5, 3, 4
    console.log(filteredArr.isEmpty()); // false

Một điều cần **chú ý** trong ví dụ trên là phương thức `filter` trả về đối tượng kiểu `MyArray` chứ không phải `Array`.

Bởi phương thức `filter` sử dụng `arr.constructor` để khởi tạo đối tượng trả về.

    class MyArray extends Array {
      isEmpty() {
        return this.length === 0;
      }
    }

    let arr = new MyArray(1, 2, 5, 3, 4);
    console.log(arr.constructor); // MyArray

Như bạn thấy rằng, giá trị của `arr.constructor` là `MyArray`. Do đó, kết quả trả về đúng kiểu `MyArray`.

Ngoài ra, bạn có thể tùy biến kiểu giá trị trả về bằng cách sử dụng một [Symbol](/tim-hieu-ve-symbol-trong-javascript/) đặc biệt là `Symbol.species` như sau:

    class MyArray extends Array {
      isEmpty() {
        return this.length === 0;
      }

      static get [Symbol.species]() {    return Array;  }}

    let arr = new MyArray(1, 2, 5, 3, 4);
    let filteredArr = arr.filter((item) => item >= 3);
    console.log(filteredArr); // 5, 3, 4
    console.log(filteredArr.isEmpty());// Lỗi: filteredArr.isEmpty is not a function

Trong ví dụ trên, bạn gặp lỗi `filteredArr.isEmpty is not a function` bởi vì kết quả trả về lúc này thuộc kiểu `Array` chứ không phải `MyArray`. Mà trong class `Array` thì không tồn tại hàm `isEmpty`.

## Static không được kế thừa với built-in classes

Như bạn đã biết trong bài [thuộc tính và phương thức static của class trong JavaScript](/thuoc-tinh-phuong-thuc-static-class-trong-javascript/), các thuộc tính và phương thức static của class được kế thừa khi sử dụng từ khóa `extends`.

Tuy nhiên, với các built-in classes thì **không**.

Ví dụ như class `Object` có phương thức static là [`Object.keys()`](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Object/keys) dùng để trả về **các thuộc tính enumerable** trong object.

Trong khi đó, class `Array` kế thừa từ class `Object` nhưng lại không có phương thức này:

    console.log(Object.keys); // ƒ keys() { [native code] }
    console.log(Array.keys); // undefined

Nguyên nhân là vì, chỉ có `Array.prototype` kế thừa `Object.prototype` chứ `Array` không kế thừa `Object`:

    console.log(Date.__proto__.__proto__ === Object.prototype); // true

Đó là điểm khác biệt của kế thừa giữa các built-in classes so với kế thừa các class thông thường dùng từ khóa `extends`.

Tham khảo: [Extending built-in classes](https://javascript.info/extend-natives)
