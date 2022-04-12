---
title: "So sánh map và object trong Javascript"
description: ""
keywords: []
chapter:
  name: "Kiểu dữ liệu trong Javascript"
  slug: "chuong-04-kieu-du-lieu-trong-javascript"
category:
  name: "Javascript"
  slug: "javascript"
image: https://kungfutech.edu.vn/thumbnail.png
position: 13
---

Có thể bạn đã quen với việc sử dụng Object trong JavaScript. Trong khi đó, Map là một kiểu dữ liệu mới xuất hiện trong ES6. Map có những đặc điểm **giống và khác** so với Object. Cụ thể là như thế nào? Sau đây, mình sẽ so sánh Map với Object trong JavaScript.

[](#nh%E1%BA%AFc-l%E1%BA%A1i-kh%C3%A1i-ni%E1%BB%87m-map-v%C3%A0-object)Nhắc lại khái niệm Map và Object
-------------------------------------------------------------------------------------------------------

► **[Object](/object-la-gi-object-trong-javascript/)** là một khái niệm trừu tượng dùng để biểu diễn một vật thể (cụ thể). Trong đó, các thuộc tính dùng để miêu tả đặc điểm, tính chất của đối tượng. Và các phương thức dùng để chỉ các hoạt động của đối tượng.

► **[Map](/map-trong-javascript-thi-sao/)** là một cấu trúc dữ liệu cho phép lưu trữ dữ liệu theo kiểu **key-value**, tương tự như object.

[](#so-s%C3%A1nh-map-v%E1%BB%9Bi-object-trong-javascript)So sánh Map với Object trong JavaScript
------------------------------------------------------------------------------------------------

Sau đây là một số đặc điểm **giống nhau và khác nhau** giữa Map và Object.

### [](#gi%E1%BB%91ng-nhau)Giống nhau

*   Đều cho phép lưu trữ dữ liệu theo kiểu **key-value**.
*   Đều cho phép lấy dữ liệu theo key, xoá key, kiểm tra xem 1 key đã tồn tại hay chưa.

### [](#kh%C3%A1c-nhau)Khác nhau

Trước khi Map xuất hiện, người ta vẫn thường sử dụng Object cho việc lưu trữ dữ liệu dạng **key-value**.

Tuy nhiên, khái niệm Object lại quá rộng, mọi thứ đều có thể là Object. Còn Map thì hướng nhiều hơn đến việc **lưu trữ dữ liệu**.

**Vậy Map khác Object như thế nào?**

#### [](#ki%E1%BB%83u-d%E1%BB%AF-li%E1%BB%87u-c%E1%BB%A7a-key)Kiểu dữ liệu của key

Object chỉ cho phép kiểu dữ liệu của **key** là [String](/kieu-du-lieu-trong-javascript/) hoặc [Symbol](https://developer.mozilla.org/vi/docs/Web/JavaScript/Reference/Global_Objects/Symbol).

    const symbol1 = Symbol(1);
    
    const obj = {
      x: 1,
      "a b": 2,
      symbol1: 3,
    };
    
    console.log(obj);
    // {x: 1, a b: 2, symbol1: 3}

Ngược lại, Map cho phép **mọi kiểu dữ liệu** có thể làm key, kể cả [number](/kieu-du-lieu-trong-javascript/), `NaN`, [function](/ham-la-gi-ham-trong-javascript/), object,...

    const fun = function () {};
    
    const map = new Map();
    map.set(NaN, 1).set(1, 2).set("a", 3).set([2], 4).set({ x: 3 }, 5).set(fun, 6);
    
    // Map(7) {
    //  NaN => 1, 1 => 2, "a" => 3, [2] => 4, {x:3} => 5, function() {} => 6
    // }

#### [](#th%E1%BB%A9-t%E1%BB%B1-c%E1%BB%A7a-key)Thứ tự của key

Map **duy trì thứ tự của key** giống như khi chúng được thêm vào.

    const map = new Map();
    map.set("xyz", 1);
    map.set("b", 2);
    map.set("1", 4);
    
    for (const key of map.keys()) {
      console.log(key);
    }
    /*
     * xyz
     * b
     * 1
     */

Object thì không đảm bảo thứ tự các key.

    const obj = { xyz: 1 };
    obj.b = 2;
    obj["1"] = 4;
    
    for (const key in obj) {
      console.log(key);
    }
    
    /*
     * 1
     * xyz
     * b
     */

#### [](#x%C3%A1c-%C4%91%E1%BB%8Bnh-k%C3%ADch-th%C6%B0%E1%BB%9Bc)Xác định kích thước

Bạn có thể lấy kích thước của Map thông qua thuộc tính `size`.

    const map = new Map();
    map.set("xyz", 1);
    map.set("b", 2);
    map.set("1", 4);
    
    console.log(map.size);
    // 3

Đối với Object, bạn phải **đếm số lượng các thuộc tính thủ công**. Hoặc bạn tính số lượng này một cách **gián tiếp**, thông qua phương thức [Object.keys()](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Object/keys).

Bởi lẽ, phương thức `Object.keys()` trả về một mảng chứa các **key** của Object. Lúc này, bạn chỉ cần sử dụng thuộc tính `length` của [array](/array-la-gi-array-trong-javascript/) là được.

    const obj = { xyz: 1 };
    obj.b = 2;
    obj["1"] = 4;
    
    // sử dụng vòng lặp for...in
    let size = 0;
    for (const key in obj) size++;
    console.log(size);
    // 3
    
    // sử dụng Object.keys
    console.log(Object.keys(obj).length);
    // 3

#### [](#ki%E1%BB%83m-tra-t%C3%ADnh-t%E1%BB%93n-t%E1%BA%A1i-c%E1%BB%A7a-key)Kiểm tra tính tồn tại của key

Để kiểm tra xem một **key** tồn tại trong Map hay chưa, bạn có thể dùng phương thức `map.has`.

    const map = new Map([
      ["a", 1],
      ["b", 2],
    ]);
    
    console.log(map.has("a")); // true
    console.log(map.has("c")); // false

Đối với Object, bạn sử dụng gián tiếp thông qua phương thức `Object.keys()` như trên.

    const obj = { a: 1, b: 2 };
    const hasKey = (obj, key) => Object.keys(obj).indexOf(key) !== -1;
    
    console.log(hasKey(obj, "a")); // true
    console.log(hasKey(obj, "c")); // false

Trong đó, `hasKey` là hàm tự định nghĩa. Và bạn thấy là `Object.keys(obj)` trả về một mảng chứa các key của `obj`.

Tiếp theo, mình sử dụng phương thức [arr.indexOf()](https://developer.mozilla.org/vi/docs/Web/JavaScript/Reference/Global_Objects/Array/indexOf) để kiểm tra xem **key đã tồn tại trong mảng hay chưa**.

Phương thức `arr.indexOf()` trả về giá trị **index đầu tiên thoả mãn**, ngược lại thì trả về `-1`. Nói cách khác, nếu index tìm được mà khác `-1` thì key đang tìm tồn tại trong Object.

#### [](#duy%E1%BB%87t-qua-c%C3%A1c-ph%E1%BA%A7n-t%E1%BB%AD)Duyệt qua các phần tử

Bạn có thể duyệt qua các phần tử của Map (để lấy `key`, `value` hoặc `[key, value]`) một cách trực tiếp thông qua `for...of`.

    const map = new Map([
      ["a", 1],
      ["b", 2],
    ]);
    
    // duyệt các keys
    for (const key of map.keys()) {
      console.log(key);
    }
    /*
     * a
     * b
     */
    
    // duyệt các values
    for (const value of map.values()) {
      console.log(value);
    }
    /*
     * 1
     * 2
     */
    
    // duyệt các cặp [key, value]
    for (const [key, value] of map) {
      console.log(key, value);
    }
    /*
     * a 1
     * b 2
     */

Với Object, bạn chỉ có thể duyệt qua các `key`, sau đó lấy `value` thông qua `key` (vì object mặc định **không phải [iterable](/iterable-la-gi-iterable-trong-javascript/)** nên không dùng được với `for...of`).

    const obj = { a: 1, b: 2 };
    
    for (const key in obj) {
      console.log(key, obj[key]);
    }
    /*
     * a 1
     * b 2
     */

[](#l%E1%BB%9Di-k%E1%BA%BFt)Lời kết
-----------------------------------

Như vậy là mình đã so sánh Map với Object. Qua đây, mình thấy rằng Map đúng là rất phù hợp với các yêu cầu liên quan đến lưu trữ dữ liệu.

Vì nó hỗ trợ sẵn các phương thức liên quan đến việc **thêm, sửa, xoá** dữ liệu dựa theo **key**. Còn đối với các yêu cầu khác thì mình vẫn phải/nên sử dụng Object.

Các bạn thấy Map và Object giống và khác nhau ở những điểm nào nữa không? Nếu biết thì chia sẻ trong phần bình luận nhé!

**Tham khảo:**

*   [Map - JavaScript](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Map)
*   [Object - JavaScript](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Object)
*   [Out Of Order Keys in ES6 Objects](https://hackernoon.com/out-of-order-keys-in-es6-objects-d5cede7dc92e)