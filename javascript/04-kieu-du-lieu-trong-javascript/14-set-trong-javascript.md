---
title: "Set trong Javascript"
description: ""
keywords: []
chapter:
  name: "Kiểu dữ liệu trong Javascript"
  slug: "chuong-04-kieu-du-lieu-trong-javascript"
category:
  name: "Javascript"
  slug: "javascript"
image: https://kungfutech.edu.vn/thumbnail.png
position: 14
---

Mình đã tìm hiểu về [Map](/map-trong-javascript-thi-sao/) trong JavaScript rồi. Bài viết này mình tiếp tục tìm hiểu về một loại **object đặc biệt** nữa. Đó là Set trong Javascript

[](#set-trong-javascript-l%C3%A0-g%C3%AC)Set trong JavaScript là gì?
--------------------------------------------------------------------

**Set trong Javascript** là một loại [object](/object-la-gi-object-trong-javascript/) cho phép bạn lưu trữ dữ liệu một cách duy nhất, không trùng lặp.

Có 2 điều bạn cần chú ý ở đây.

### [](#set-l%C3%A0-m%E1%BB%99t-lo%E1%BA%A1i-object)Set là một loại object

Vì vậy mà `typeof set` sẽ trả về string `object`.

    const set1 = new Set();
    console.log(typeof set1);
    // object

### [](#d%E1%BB%AF-li%E1%BB%87u-trong-set-l%C3%A0-duy-nh%E1%BA%A5t-kh%C3%B4ng-tr%C3%B9ng-l%E1%BA%B7p)Dữ liệu trong Set là duy nhất, không trùng lặp

Hiểu thế nào là **duy nhất, không trùng lặp**?

Đơn giản là "giá trị" của các phần tử không được giống nhau. Thực chất, Set sử dụng thuật toán [SameValueZero](https://tc39.github.io/ecma262/#sec-samevaluezero) để so sánh giá trị của các phần tử.

> Thuật toán **SameValueZero** tương tự như việc sử dụng toán tử so sánh bằng nghiêm ngặt `===` để so sánh giá trị. Chỉ khác ở chỗ thuật toán này coi `NaN` là giống nhau (mặc dù `NaN !== NaN` là `true`).

Vì vậy, điều mình nói ở trên chỉ đúng với [number và string](/kieu-du-lieu-trong-javascript/), còn đối với object thì khác. Bởi 2 object nhìn giống nhau nhưng rõ ràng chúng không bằng nhau:

    const obj1 = { x: 1, y: 2 };
    const obj2 = { x: 1, y: 2 };
    
    console.log(obj1 === obj2);
    // false
    
    const set1 = new Set([obj1, obj2]);
    console.log(set1.size);
    // 2

Ngoài ra, bạn cũng có thể lưu `NaN` và `undefined` vào Set trong JavaScript.

    const set2 = new Set([NaN, undefined, NaN]);
    console.log(set2);
    // Set(2) {NaN, undefined}

Đọc đến đây chắc bạn đã hiểu cơ bản về Set rồi phải không?

Sau đây là những thứ bạn có thể làm với Set trong JavaScript.

[](#kh%E1%BB%9Fi-t%E1%BA%A1o-set-trong-javascript)Khởi tạo Set trong JavaScript
-------------------------------------------------------------------------------

Khởi tạo Set là điều đầu tiên bạn cần làm nếu muốn sử dụng Set. Cú pháp khởi tạo Set trong Javascript là:

    new Set([iterable]);

Trong đó:

*   Tham số [iterable](/iterable-la-gi-iterable-trong-javascript/) là không bắt buộc. Nếu bạn **không truyền tham số** vào hàm khởi tạo thì Set sẽ rỗng - không có phần tử nào.
*   Ngược lại, nếu bạn truyền vào một iterable object thì **tất cả các phần tử** của object sẽ được thêm vào Set.

> **Chú ý:** bạn có thể truyền vào **iterable object**, chứ không chỉ có array (vì array chỉ là một loại iterable object).

Sau đây là các ví dụ khởi tạo Set trong JavaScript.

### [](#kh%E1%BB%9Fi-t%E1%BA%A1o-set-r%E1%BB%97ng)Khởi tạo Set rỗng

Khởi tạo Set rỗng bằng cách không truyền tham số vào hàm khởi tạo.

    const set1 = new Set();
    console.log(set1);
    // Set(0) {}

### [](#kh%E1%BB%9Fi-t%E1%BA%A1o-set-t%E1%BB%AB-array)Khởi tạo Set từ Array

Array là một loại iterable object.

    const set2 = new Set([1, 2, "a", "b", 1]);
    console.log(set2);
    // Set(4) {1, 2, "a", "b"}

### [](#kh%E1%BB%9Fi-t%E1%BA%A1o-set-t%E1%BB%AB-string)Khởi tạo Set từ String

String cũng là một loại iterable object.

    const set3 = new Set("abcba");
    console.log(set3);
    // Set(3) {"a", "b", "c"}

### [](#kh%E1%BB%9Fi-t%E1%BA%A1o-set-t%E1%BB%AB-arguments)Khởi tạo Set từ arguments

Đối tượng [`arguments`](/object-la-gi-object-trong-javascript/#%C4%91%E1%BB%91i-t%C6%B0%E1%BB%A3ng-arguments) là đối tượng có sẵn trong hàm, dùng để lưu trữ mảng các tham số truyền vào.

    function func4() {
      const set4 = new Set(arguments);
      console.log(set4);
    }
    
    func4("a", "b", "c", "b", 0, 1);
    // Set(5) {"a", "b", "c", 0, 1}

### [](#kh%E1%BB%9Fi-t%E1%BA%A1o-set-t%E1%BB%AB-nodelist)Khởi tạo Set từ NodeList

Kết quả của các phương thức liên quan đến `DOM` khi thao tác với trình duyệt như: [document.querySelectorAll()](https://developer.mozilla.org/en-US/docs/Web/API/Document/querySelectorAll), [document.getElementsByClassName()](https://developer.mozilla.org/en-US/docs/Web/API/Document/getElementsByClassName),... đều trả về `NodeList`.

Ví dụ:

    // tìm tất cả các phần tử với thẻ head
    const head = document.querySelectorAll("head");
    const set1 = new Set(head);
    console.log(set1);
    // Set(1) {head}

### [](#kh%E1%BB%9Fi-t%E1%BA%A1o-set-t%E1%BB%AB-typedarray)Khởi tạo Set từ TypedArray

[TypedArray](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/TypedArray) là một kiểu object tương tự như Array. Và bạn cũng có thể sử dụng **TypedArray** để khởi tạo Set như sau:

    const typedArray1 = new Int8Array(2);
    typedArray1[0] = 12;
    typedArray1[1] = 34;
    
    const set1 = new Set(typedArray1);
    console.log(set1);
    // Set(2) {12, 34}

### [](#kh%E1%BB%9Fi-t%E1%BA%A1o-set-t%E1%BB%AB-map)Khởi tạo Set từ Map

Bạn có thể khởi tạo Set từ Map như sau:

    const map1 = new Map();
    map1.set("one", 1);
    map1.set("two", 2);
    
    const set1 = new Set(map1);
    console.log(set1);
    // Set(2) {Array(2), Array(2)}
    
    for (const x of set1) {
      console.log(x);
    }
    /*
     * ["one", 1]
     * ["two", 2]
     */

### [](#kh%E1%BB%9Fi-t%E1%BA%A1o-set-t%E1%BB%AB-set)Khởi tạo Set từ Set

Bạn cũng có thể khởi tạo Set từ một Set khác.

    const set1 = new Set([1, 2]);
    const set2 = new Set(set1);
    console.log(set2);
    // Set(2) {1, 2}

Trên đây là một số cách để khởi tạo Set trong JavaScript. Tiếp theo đây là cách để thêm phần tử vào Set.

[](#th%C3%AAm-ph%E1%BA%A7n-t%E1%BB%AD-v%C3%A0o-set)Thêm phần tử vào Set
-----------------------------------------------------------------------

Để thêm phần tử vào Set trong JavaScript, bạn có thể sử dụng phương thức `add` như sau:

    set.add(value);

Trong đó:

*   Nếu Set không có phần tử `value` thì phương thức `set.add(value)` sẽ thêm `value` vào Set và trả về chính Set đó.
*   Nếu `value` đã tồn tại thì phương thức `set.add(value)` sẽ bỏ qua và cũng trả về chính Set đó.

Ví dụ thêm phần tử vào Set:

    // khởi tạo set rỗng
    const set1 = new Set();
    
    // thêm phần tử 1
    set1.add(1);
    console.log(set1);
    // Set(1) {1}
    
    // thêm phần tử 2 (khác 1)
    set1.add(2);
    console.log(set1);
    // Set(2) {1, 2}
    
    // thêm phần tử 3 (khác 1 và 2)
    set1.add(1).add(2).add(3);
    console.log(set1);
    // Set(3) {1, 2, 3}

Việc trả về chính đối tượng Set sau khi `add` giúp code trở trên ngắn gọn hơn nhiều.

Xem thêm: [Tìm hiểu kĩ thuật Method Chaining cơ bản](/tim-hieu-ki-thuat-method-chaining-co-ban/)

[](#l%E1%BA%A5y-s%E1%BB%91-l%C6%B0%E1%BB%A3ng-ph%E1%BA%A7n-t%E1%BB%AD-trong-set)Lấy số lượng phần tử trong Set
--------------------------------------------------------------------------------------------------------------

Để lấy được số lượng phần tử của Set trong JavaScript, bạn có thể sử dụng thuộc tính `set.size`.

    const set1 = new Set(["a", "b", "a"]);
    console.log(set1.size);
    // 2 - vì set chỉ có hai phần tử ["a", "b"]

[](#ki%E1%BB%83m-tra-ph%E1%BA%A7n-t%E1%BB%AD-t%E1%BB%93n-t%E1%BA%A1i-trong-set)Kiểm tra phần tử tồn tại trong Set
-----------------------------------------------------------------------------------------------------------------

Để kiểm tra một phần tử có tồn tại trong Set hay không, bạn có thể sử dụng phương thức `set.has()`.

    const set1 = new Set([1, "a", [1, 2]]);
    
    console.log(set1.has(1)); // true
    console.log(set1.has("1")); // false
    console.log(set1.has("a")); // true
    console.log(set1.has("b")); // false
    console.log(set1.has([1, 2])); // false - vì [1, 2] !== [1, 2]

Kết quả trên là hoàn toàn dễ hiểu phải không?

Mình chỉ muốn nhắc lại là Set sẽ sử dụng **toán tử so sánh bằng nghiêm ngặt** `===` để so sánh các giá trị, do đó:

    console.log(1 === 1); // true
    console.log(1 === "1"); // false
    console.log("a" === "a"); // true
    console.log([1, 2] === [1, 2]); // false

[](#xo%C3%A1-m%E1%BB%99t-ph%E1%BA%A7n-t%E1%BB%AD-trong-set)Xoá một phần tử trong Set
------------------------------------------------------------------------------------

Để xóa một phần tử của Set trong JavaScript, bạn sử dụng phương thức `set.delete(value)`:

    const set1 = new Set("abcdcba");
    console.log(set1); // Set(4) {a, b, c, d}
    
    set1.delete("a");
    console.log(set1); // Set(4) {b, c, d}
    
    set1.delete("d");
    console.log(set1); // Set(2) {b, c}

[](#xo%C3%A1-t%E1%BA%A5t-c%E1%BA%A3-ph%E1%BA%A7n-t%E1%BB%AD-trong-set)Xoá tất cả phần tử trong Set
--------------------------------------------------------------------------------------------------

Để xóa tất cả các phần tử trong Set, bạn sử dụng phương thức `set.clear()`. Sau đó, Set sẽ trở thành rỗng.

    const set1 = new Set([1, 2, 3]);
    console.log(set1); // Set(3) {1, 2, 3}
    
    set1.clear();
    console.log(set1); // Set(0) {}

[](#duy%E1%BB%87t-qua-c%C3%A1c-ph%E1%BA%A7n-t%E1%BB%AD-trong-set)Duyệt qua các phần tử trong Set
------------------------------------------------------------------------------------------------

Set hỗ trợ một số cách để duyệt qua các phần tử như sau.

### [](#s%E1%BB%AD-d%E1%BB%A5ng-forof)Sử dụng `for...of`

Ví dụ sử dụng `for...of` để duyệt qua các phần tử:

    const set1 = new Set(["a", { x: 1 }, 1]);
    
    for (const x of set1) {
      console.log(x);
    }
    /*
     * a
     * { x : 1}
     * 1
     */

### [](#s%E1%BB%AD-d%E1%BB%A5ng-foreach)Sử dụng `forEach`

Sử dụng `set.forEach()` cũng tương tự như [forEach trong Array](/javascript-foreach-la-cai-quai-gi/).

    const set1 = new Set(["a", "b", "c"]);
    console.log(set1);
    // Set(3) {"a", "b", "c"}
    
    set1.forEach(function (value) {
      console.log(value);
    });
    /*
     * a
     * b
     * c
     */

### [](#s%E1%BB%AD-d%E1%BB%A5ng-ph%C6%B0%C6%A1ng-th%E1%BB%A9c-keys-values-entries)Sử dụng phương thức `keys()`, `values()`, `entries()`

Ba phương thức `set.keys()`, `set.values()` và `set.entries()` đều trả về iterable object, với mỗi phần tử tương ứng với một phần tử trong Set (theo thứ tự mà mình chèn vào).

    // khởi tạo set
    const set1 = new Set(["a", { x: 1 }, 1]);
    
    // duyệt qua các keys trong set
    for (const x of set1.keys()) {
      console.log(x);
    }
    /*
     * a
     * { x : 1}
     * 1
     */
    
    // duyệt qua các values trong set
    for (const x of set1.values()) {
      console.log(x);
    }
    /*
     * a
     * { x : 1}
     * 1
     */
    
    // duyệt qua các cặp [key, value] trong set
    for (const x of set1.entries()) {
      console.log(x);
    }
    
    /*
     * ["a", "a"]
     * [{ x : 1}, { x : 1}]
     * [1, 1]
     */

Bạn thấy rằng, các phương thức trên đều có đặc điểm là: `key` và `value` giống nhau. Việc để `key` và `value` bằng nhau để tương đồng với kiểu dữ liệu Map.

[](#chuy%E1%BB%83n-set-th%C3%A0nh-array-v%C3%A0-ng%C6%B0%E1%BB%A3c-l%E1%BA%A1i)Chuyển Set thành Array và ngược lại
------------------------------------------------------------------------------------------------------------------

Mình có thể sử dụng phương thức `forEach` của Set trong JavaScript, tương tự như Array. Nhưng còn các phương thức khác như: `map`, `filter`,... thì sao?

Thực tế, Set không hỗ trợ những phương thức này.

Nhưng bạn hoàn toàn có thể **chuyển Set thành Array** để sử dụng các phương thức của Array. Rồi sau đó, bạn chuyển Array ngược lại thành Set.

Để chuyển Set thành Array, bạn có thể sử dụng [Array.from](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array/from) hoặc sử dụng [toán tử spread](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Operators/Spread_syntax), ví dụ:

    // khởi tạo set
    const set1 = new Set([1, 2, 3, 4, 5]);
    
    // chuyển set thành array sử dụng Array.from
    const arr1 = Array.from(set1);
    console.log(arr1);
    // [1, 2, 3, 4, 5]
    
    // chuyển set thành array sử dụng cú pháp spread (...)
    const arr2 = [...set1];
    console.log(arr2);
    // [1, 2, 3, 4, 5]

Giả sử, mình sử dụng phương thức [`filter`](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array/filter) để lọc lấy những phần tử là số chẵn.

    const arr3 = arr1.filter((x) => x % 2 === 0);
    console.log(arr3);
    // (2) [2, 4]

Bây giờ, mình chuyển Array ngược lại thành Set - sử dụng công thức phần khởi tạo Set:

    const set2 = new Set(arr3);
    console.log(set2);
    // Set(2) {2, 4}

Toàn bộ quá trình trên có thể viết gọn lại thành:

    const set1 = new Set([1, 2, 3, 4, 5]);
    console.log(set1);
    // Set(5) {1, 2, 3, 4, 5}
    
    const filteredArray = [...set1].filter((x) => x % 2 == 0);
    const set2 = new Set(filteredArray);
    console.log(set2);
    // Set(2) {2, 4}

Khi đã chuyển Set thành Array rồi, bạn có thể sử dụng bất kỳ [phương thức](/phuong-thuc-cua-mang-trong-javascript/) nào mà Array hỗ trợ.

[](#m%E1%BB%99t-v%C3%AD-d%E1%BB%A5-th%E1%BB%B1c-t%E1%BA%BF-s%E1%BB%AD-d%E1%BB%A5ng-set)Một ví dụ thực tế sử dụng Set
--------------------------------------------------------------------------------------------------------------------

Trong bài viết về [tạo blog với Gatsby.js](/tao-trang-blog-voi-gatsby-js/), mình đã nói về vấn đề tạo danh sách các **thẻ**, **chuyên mục**. Đó chính là một ví dụ thực tế sử dụng Set.

Vì mình cần phải lưu lại danh sách các thẻ, chuyên mục với các phần tử là duy nhất, rồi sau đó **hiển thị danh sách** này lên sidebar.

Ví dụ mỗi bài viết có một mảng lưu các thẻ tag:

    const post1 = ["tag1", "tag2", "tag4"];
    const post2 = ["tag3", "tag4"];

Sau đó, tạo ra mảng các thẻ tag duy nhất bằng Set như sau:

    let arrTag = [];
    
    arrTag = Array.from(new Set([...arrTag, ...post1]));
    arrTag = Array.from(new Set([...arrTag, ...post2]));
    
    console.log(arrTag);
    // (4) ["tag1", "tag2", "tag4", "tag3"]

Giả sử tạo thêm một bài viết mới với mảng các thẻ tag là:

    const post3 = ["tag1", "tag3", "tag5"];

Để cập nhật danh sách thẻ tag, mình có thể làm như sau:

    arrTag = Array.from(new Set([...arrTag, ...post3]));
    // (5) ["tag1", "tag2", "tag4", "tag3", "tag5"]

Mỗi khi thêm một bài viết mới, mình chỉ cần làm theo cách trên là cập nhật được danh sách các thẻ mà không bị trùng lặp.

[](#t%E1%BB%95ng-k%E1%BA%BFt)Tổng kết
-------------------------------------

Set trong JavaScript là một loại object dùng để lưu trữ dữ liệu mà không trùng lặp.

Các phương thức của Set là:

*   `new Set(iterable)`: khởi tạo Set bằng cách truyền vào một iterable object (không bắt buộc), trường hợp không truyền vào tham số nào thì Set sẽ rỗng.
*   `set.add(value)`: thêm phần tử `value` vào Set và trả về chính Set đó.
*   `set.delete(value)`: xóa một phần tử trong Set và trả về `true` nếu giá trị `value` tồn tại trong Set, ngược lại trả về `false`.
*   `set.has(value)`: trả về `true` nếu giá trị `value` tồn tại trong Set, ngược lại thì trả về `false`.
*   `set.clear()`: xóa tất cả các phần tử trong Set.
*   `set.size`: trả về số lượng phần tử trong Set.

**Tham khảo:**

*   [Set - MDN](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Set)
*   [The Set JavaScript Data Structure](https://flaviocopes.com/javascript-data-structures-set/)