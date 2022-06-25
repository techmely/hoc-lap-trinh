---
title: "Singleton pattern trong JavaScript"
description: "Singleton hữu dụng khi sử dụng để quản lý các nguồn tài nguyên bị giới hạn hoặc theo dõi toàn bộ trạng thái của hệ thống."
keywords: [
"Singleton pattern trong JavaScript",
"Singleton pattern là gì trong JavaScript",
"Triển khai singleton pattern trên Javacript",
"Tìm hiểu design pattern và Singleton trong JavaScript",
"Singleton class JavaScript",
"singleton pattern trong javascript là gì"
]
chapter:
  name: "Design pattern"
  slug: "chuong-17-design-pattern"
category:
  name: "Javascript"
  slug: "javascript"
image: https://kungfutech.edu.vn/thumbnail.png
position: 3
---

Có thể bạn đã nghe quen về Singleton. Singleton Pattern giới hạn số lượng instance của một class là **một**. Trong JavaScript, bạn có thể triển khai Singleton Pattern theo cách sau.

## Singleton Pattern cơ bản

```js
var mySingleton = (function () {
  var instance;
  function init() {
    var number = 0;
    return {
      setNumber: function (x) {
        number = x;
      },
      getNumber: function () {
        return number;
      },
    };
  }

  return {
    getInstance: function () {
      if (!instance) instance = init();
      return instance;
    },
  };
})();

var instA = mySingleton.getInstance();
console.log("instance A: ", instA.getNumber()); // instance A: 0
instA.setNumber(10);
console.log("instance A: ", instA.getNumber()); // instance A: 10

var instB = mySingleton.getInstance();
console.log("instance B: ", instB.getNumber()); // instance B: 10

console.log(instA === instB); // true
```

### Giải thích

Các bạn có thể thấy, cách triển khai Singleton trên rất giống với **Module Pattern**. Chỉ có một chú ý là, mySingleton chỉ có một access point duy nhất là getInstance. Vậy tại sao khi sử dụng [function](/bai-viet/javascript/ham-trong-javascript) này thì ta chỉ thu được một instance duy nhất?

Đúng vậy, ban đầu khi chưa gọi getInstance lần nào thì biến instance sẽ là undefined. Lúc này, instance sẽ được khởi tạo bằng cách sử dụng hàm số init. Cuối cùng, hàm số trả về biến instance. Đối với các lần gọi getInstance tiếp theo, vì instance đã khác undefined nên nó sẽ không được tạo mới mà sẽ return ngay lập tức.

Như ví dụ trên, instA khi mới tạo ra thì getNumber sẽ trả về 0. Trong khi, instB khi mới tạo ra thì getNumber trả về 10 - giá trị này được set ở instA trước đó. Và quan trọng hơn, **instA === instB** trả về giá trị true. Như vậy, thực chất instB cũng chính là instA.

## Singleton with a cached static property

```js
function User() {
  // do we have an existing instance?
  if (typeof User.instance === "object") {
    return User.instance;
  }

  // proceed as normal
  this.firstName = "John";
  this.lastName = "Doe";

  // cache
  User.instance = this;

  /**
   * // implicit return
   * return this;
   */
}

// Usage:
var curUser = new User();
console.log(curUser.firstName, curUser.lastName); // John Doe

var other = new User();
console.log(other.firstName, other.lastName); // John Doe
console.log(other === curUser); // true
```

Cách này khi mới đọc thì sẽ thấy hơi ảo, ở chỗ là, trong hàm User ta lại sử dụng User.instance. Nhưng nếu nhìn theo khía cạnh, function cũng chính là một [object](/bai-viet/javascript/object-la-gi-object-trong-javascript) thì mọi chuyện sẽ trở nên đơn giản.

Như trong ví dụ trên, khi khởi tạo curUser (lần đầu tiên), User.instance đang có giá trị là undefined, nên mọi thứ được xử lý như bình thường. Khi kết thúc hàm, ta gán **User.instance = this** hay nói cách khác là **User.instance = curUser**. Đến khi khởi tạo đối tượng thứ hai là other, lúc này User.instance đã là curUser - một object, nên hàm trên sẽ return về User.instance (curUser). Đó, dù có gọi hàm khởi tạo bao nhiêu lần thì ta cũng chỉ thu được một đối tượng duy nhất.

## Tham khảo

- [Learning JavaScript Design Patterns](https://addyosmani.com/resources/essentialjsdesignpatterns/book/#singletonpatternjavascript)
- [JavaScript Design Pattern Singleton](http://robdodson.me/javascript-design-patterns-singleton/)
