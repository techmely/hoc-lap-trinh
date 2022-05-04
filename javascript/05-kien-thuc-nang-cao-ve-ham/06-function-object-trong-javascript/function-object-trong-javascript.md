---
title: "Function trong Javascript"
description: "Function hay còn gọi là hàm, là tập hợp một đoạn code dùng để xử lý một nhiệm vụ nào đó. Code bên trong function không được biên dịch cho tới khi được gọi đến."
keywords: [
"goi function trong javascript",
"function trong javascript dung de lam gi",
"bai tap ve ham trong javascript",
"cach goi ham javascript trong html",
"arrow function trong javascript",
"Gọi function trong JavaScript",
"Function trong JavaScript dùng để làm gì",
"function javascript la gi",
"Cách sử dụng function trong javascript"
]
chapter:
  name: "Kiến thức nâng cao về hàm"
  slug: "chuong-05-kien-thuc-nang-cao-ve-ham"
category:
  name: "Javascript"
  slug: "javascript"
image: https://kungfutech.edu.vn/thumbnail.png
position: 6
---

Function trong JavaScript cũng là một loại object. Vì vậy, bạn có thể **thêm/xóa thuộc tính** vào function hoặc **truyền qua hàm khác bởi tham chiếu**,...

Sau đây là những kiến thức cơ bản về function object trong JavaScript.

## Thuộc tính `name`

Function object trong JavaScript có nhiều **thuộc tính hữu ích**. Trong đó, thuộc tính `name` trả về tên của hàm:

```js
function sayHi() {
  console.log("Hi");
}

console.log(sayHi.name); // sayHi
```

Kể cả khi bạn **khai báo và không đặt tên cho hàm** mà gán vào biến khác:

```js
let sayHi = function () {
  console.log("Hi");
};

console.log(sayHi.name); // sayHi
```

Hoặc khi phép gán được sử dụng thông qua việc **đặt giá trị mặc định** cho tham số hàm:

```js
function f(sayHi = function () {}) {
  console.log(sayHi.name); // sayHi
}

f();
```

Nhìn chung, khi một hàm không được đặt tên, sau đó phép gán được thực hiện thì giá trị của thuộc tính `name` được xác định dựa trên ngữ cảnh cụ thể:

```js
let user = {
  sayHi() {
    // ...
  },

  sayBye: function () {
    // ...
  },
};

console.log(user.sayHi.name); // sayHi
console.log(user.sayBye.name); // sayBye
```

Tuy nhiên, vẫn có những trường hợp không thể xác định được giá trị của thuộc tính `name`, ví dụ:

```js
// function được tạo ra bên trong mảng
let arr = [function () {}];

console.log(arr[0].name); // string rỗng
// JavaScript Engine không có cách nào để xác định giá trị cho `name`
```

## Thuộc tính `length`

Thuộc tính hữu ích khác của function object trong JavaScript là `length`.

Thuộc tính `length` trả về số lượng tham số được định nghĩa trong hàm, ví dụ:

```js
function f1(a) {}
function f2(a, b) {}
function many(a, b, ...more) {}

console.log(f1.length); // 1
console.log(f2.length); // 2
console.log(many.length); // 2
```

Trong ví dụ trên, bạn có thể thấy là [dấu ba chấm](/bai-viet/javascript/dau-ba-cham-trong-javascript/) `...` (dùng để xác định số lượng tham số còn lại của hàm) không được tính vào giá trị của `length`.

Giá trị của thuộc tính `length` thường được sử dụng để xử lý trường hợp mà số lượng tham số ảnh hưởng tới cách xử lý của hàm.

Ví dụ hàm `ask` sau đây nhận vào tham số kiểu string `question`, sau đó là số lượng tùy ý các hàm `handlers` để gọi lại.

Khi người dùng đưa ra câu trả lời, hàm `ask` sẽ gọi lại các hàm `handlers` với hai trường hợp xảy ra là:

- Hàm không tham số: chỉ được gọi khi người dùng **đồng ý**.
- Hàm có tham số: luôn được gọi và câu trả lời được trả về thông qua tham số.

Để phân biệt hai trường hợp trên, bạn có thể dùng giá trị của thuộc tính `length` như sau:

```js
function ask(question, ...handlers) {
  // dùng hàm confirm để hỏi người dùng
  let isYes = confirm(question);

  // duyệt tất cả các handler sử dụng for...of
  for (let handler of handlers) {
    if (handler.length === 0) {
      // trường hợp hàm handler không có tham số
      if (isYes) handler();
    } else {
      // trường hợp hàm handler có tham số
      handler(isYes);
    }
  }
}

// hàm không tham số được gọi chỉ khi câu trả lời là đồng ý.
// hàm có tham số luôn luôn được gọi.
ask(
  "Câu hỏi?",
  () => alert("Đáp án là yes"), // hàm không tham số
  (result) => alert(`Đáp án là ${result}`) // hàm có tham số
);
```

## Thêm thuộc tính vào function object

Bạn có thể tùy ý thêm thuộc tính vào function object trong JavaScript.

Ví dụ thêm thuộc tính `counter` vào hàm để đếm số lần gọi hàm:

```js
function sayHi() {
      console.log("Hi");

      // đếm số lần gọi hàm  sayHi.counter++;}

    sayHi.counter = 0; // giá trị mặc định

    sayHi(); // Hi
    sayHi(); // Hi

    console.log(`Hàm sayHi được gọi với số lần là: ${sayHi.counter}`);
    // Hàm sayHi được gọi với số lần là: 2
```

<content-warning>

**Chú ý:** việc thêm thuộc tính vào hàm **không định nghĩa thêm biến local** trong phạm vi hàm. Nói cách khác, `sayHi.counter` khác với `let counter`.

</content-warning>

Việc thêm thuộc tính vào hàm đôi khi có thể thay thế được [**closure**](/bai-viet/javascript/closure-trong-javascript/).

Ví dụ sử dụng closure như sau:

```js
function makeCounter() {
  // ban đầu counter bằng 0
  let count = 0;

  // trả về một hàm khác
  // hàm này return về counter rồi tăng biến counter lên 1 đơn vị
  return function () {
    return count++;
  };
}

// sử dụng -> counter chính là nested function
let counter = makeCounter();

// sau mỗi lần gọi hàm counter() thì giá trị count tăng lên 1
console.log(counter()); // 0
console.log(counter()); // 1
```

Thay vào đó, bạn có thể sử dụng thuộc tính của hàm như sau:

```js
function makeCounter() {
  // ban đầu counter bằng 0
  // let count = 0;
  function counter() {
    return counter.count++;
  }
  counter.count = 0;
  return counter;
}

// sử dụng
let counter = makeCounter();

// sau mỗi lần gọi hàm counter() thì giá trị count tăng lên 1
console.log(counter()); // 0
console.log(counter()); // 1
```

Về cơ bản thì hai cách trên **khá giống nhau**, chỉ khác một chỗ. Với cách sử dụng thuộc tính hàm thì biến `count` có thể được truy cập trực tiếp từ bên ngoài.

```js
function makeCounter() {
  function counter() {
    return counter.count++;
  }

  counter.count = 0;

  return counter;
}

let counter = makeCounter();

counter.count = 10;
console.log(counter()); // 10
```

Nói chung, mỗi cách có một đặc điểm riêng. Tùy thuộc vào mục đích mà bạn quyết định xem nên lựa chọn cách nào.

## Biểu thức hàm được đặt tên

Biểu thức hàm được đặt tên, hay tiếng anh là **Named Function Expression** - NFE, được hiểu là bạn định nghĩa [biểu thức hàm](/bai-viet/javascript/function-expression-trong-javascript) và đặt tên cho nó.

Ví dụ biểu thức hàm ban đầu như sau:

```js
let sayHi = function (who) {
  console.log(`Hello, ${who}`);
};
```

Sau đó, bạn thêm tên cho hàm:

```js
let sayHi = function func(who) {
  console.log(`Hello, ${who}`);
};
```

► **Việc thêm tên hàm `func` có ý nghĩa gì?**

Vệc bạn thêm tên hàm `func` không làm thay đổi cấu trúc hàm. Hàm `sayHi` vẫn là biểu thức hàm và vẫn có thể gọi bình thường:

```js
let sayHi = function func(who) {
  console.log(`Hello, ${who}`);
};

sayHi("Alex"); // Hello, Alex
```

Thực tế, việc thêm tên cho biểu thức hàm có hai lợi ích là:

- Cho phép gọi hàm ngay trong thân hàm.
- Tên biểu thức hàm không nhìn thấy được từ bên ngoài.

Ví dụ, hàm `sayHi` gọi lại chính nó với tham số `"Guest"` nếu như không truyền tham số vào hàm:

```js
let sayHi = function func(who) {
  if (who) {
    console.log(`Hello, ${who}`);
  } else {
    func("Guest"); // gọi lại chính nó với tham số "Guest"  }
  }

  sayHi(); // Hello, Guest

  func(); // Uncaught ReferenceError: func is not defined
};
```

► **Tại sao lại sử dụng `func`, trong khi bạn có thể gọi lại hàm thông qua tên `sayHi`?**

```js
let sayHi = function func(who) {
  if (who) {
    console.log(`Hello, ${who}`);
  } else {
    sayHi("Guest"); // gọi lại chính nó với tham số "Guest"  }
  }

  sayHi(); // Hello, Guest
};
```

Đoạn code trên vẫn hoạt động bình thường. Nhưng vấn đề xảy ra là nếu biến `sayHi` được gán bằng giá trị khác thì việc gọi hàm như trên sẽ bị lỗi:

```js
let sayHi = function func(who) {
  if (who) {
    console.log(`Hello, ${who}`);
  } else {
    sayHi("Guest"); // gọi lại chính nó với tham số "Guest"  }
  }

  let sayHello = sayHi;
  sayHi = null;
  sayHello(); // Uncaught TypeError: sayHi is not a function
};
```

Lỗi trên xảy ra là vì giá trị của `sayHi` được lấy ở phạm vi ngoài hàm. Mà tại thời điểm gọi hàm, giá trị của `sayHi` là `null`.

Để giải quyết vấn đề trên, bạn chỉ cần sử dụng tên của biểu thức hàm `func` như sau:

```js
let sayHi = function func(who) {
  if (who) {
    console.log(`Hello, ${who}`);
  } else {
    func("Guest"); // gọi lại chính nó với tham số "Guest"  }
  }

  let sayHello = sayHi;
  sayHi = null;

  sayHello(); // Hello, Guest
};
```

Đoạn code này không lỗi vì `func` là tên cục bộ trong hàm. Tên `func` không được nhìn thấy bên ngoài hàm, nhưng bạn có thể gọi `func` thoải mái từ trong biểu thức hàm.

## Tổng kết

Function là một loại object.

Function object trong JavaScript có hai thuộc tính hữu ích là:

- Thuộc tính `name`: trả về tên của hàm. Giá trị của thuộc tính `name` thường được lấy khi khai báo hàm. Nếu không có thì JavaScript sẽ cố gắng lấy `name` từ ngữ cảnh cụ thể (ví dụ phép gán).
- Thuộc tính `length`: trả về số lượng tham số của hàm, không bao gồm tham số còn lại của hàm với dấu ba chấm `...`.

Nếu một hàm được định nghĩa bởi biểu thức hàm đi kèm với một tên thì hàm đó gọi là **Named Function Expression** hay **NFE**.

Tên của biểu thức hàm có thể được sử dụng để gọi lại tới chính nó, bên trong thân hàm.

Function object trong JavaScript có thể thêm nhiều thuộc tính khác tùy ý.

## Thực hành

Viết hàm `makeCounter()` thực hiện những yêu cầu sau:

1.  `counter()`: trả về giá trị `count` hiện tại, sau đó tăng `count` lên 1 đơn vị.
2.  `counter.set(value)`: gán giá trị `value` cho `counter`.
3.  `counter.decrease()`: giảm giá trị của `counter` đi 1 đơn vị.

Xem đáp án

Kết hợp closure và thuộc tính của function object trong JavaScript như sau:

- Khai báo biến `count` là biến cục bộ của hàm `makeCounter` để không thể truy cập trực tiếp từ bên ngoài.
- Định nghĩa hai hàm `set` và `decrease` sử dụng thuộc tính của function object.

```js
function makeCounter() {
  // ban đầu counter bằng 0
  let count = 0;

  // trả về một hàm khác
  // hàm này return về counter rồi tăng biến counter lên 1 đơn vị
  return function counter() {
    // 1. hàm set(value) - gán giá trị value cho count
    counter.set = function (value) {
      count = value;
    };

    // 2. hàm decrease() - giảm giá trị của count đi 1 đơn vị
    counter.decrease = function () {
      count--;
    };

    return count++;
  };
}

let counter = makeCounter();
console.log(counter()); // 0
console.log(counter()); // 1
console.log(counter()); // 2

// set giá trị mới cho count
counter.set(5);
console.log(counter()); // 5

// sau lần gọi này, giá trị của count đang là 6

// giảm giá trị của count đi 1
counter.decrease();
console.log(counter()); // 5
```

Tham khảo: [Function object, NFE](https://javascript.info/function-object)
