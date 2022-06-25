---
title: "Method chaining trong Javascript"
description: "Đơn giản thì Method Chainning là một kỹ thuật được sử dụng để viết code một cách ngắn gọn và đơn giản hơn trong việc gọi các hàm liên tiếp trên cùng một đối tượng."
keywords: [
"Method chaining trong Javascript",
"Tìm hiểu kĩ thuật Method Chaining",
"tìm hiểu Method Chainning trong Javascript",
"Promises Chaining Trong JavaScript",
"Optional chaining trong Javascript",
"Chaining là gì",
"Optional chaining JavaScript",
"method chaining trong javascript là gì"
]
chapter:
  name: "Design pattern"
  slug: "chuong-17-design-pattern"
category:
  name: "Javascript"
  slug: "javascript"
image: https://kungfutech.edu.vn/thumbnail.png
position: 5
---

Trong lập trình nói chung và lập trình JavaScript nói riêng, có một kĩ thuật khá hay với tên gọi trong tiếng Anh là: **Method Chaining**, **Function Chaining** hoặc **Cascading**. Vậy kĩ thuật này có gì hay và cách sử dụng nó như thế thế nào? Mời bạn theo dõi bài viết!

## Kĩ thuật Method Chaining có gì hay?

Kĩ thuật Method Chaining giúp code trở nên ngắn gọn, dễ theo dõi và hạn chế việc sử dụng các biến tạm.

Ví dụ: khi sử dụng jQuery, bạn có thể dễ dàng nhìn thấy những đoạn code như sau:

```js
$(".myClass").addClass("bird").show().animate({
  /* some animation */
});
```

Nếu không sử dụng kĩ thuật Method Chaining thì đoạn code trên sẽ khá dài dòng:

```js
const $myClass = $(".myClass");
$.addClass($myClass, "bird");
$.show($myClass);
$.animate($myClass, {
  /* some animation */
});
```

Bạn có thể thấy rằng, khi sử dụng Method Chaining, bạn hầu như chỉ cần viết các đoạn code trên cùng 1 dòng.

Thực tế, kĩ thuật này đã và đang được sử dụng rất nhiều trong hầu hết các thư viện, Framework JavaScript.

## Cách sử dụng kĩ thuật Method Chaining cơ bản

Trong bài viết này, mình sẽ chỉ giới thiệu một cách cơ bản về kĩ thuật Method Chaining. Hy vọng qua đó bạn có thể tự tìm hiểu thêm sau này.

### Ví dụ khi không sử dụng Method Chaining

```js
class Number {
  constructor(value) {
    this.value = value;
  }
  add(value) {
    this.value += value;
  }
  sub(value) {
    this.value -= value;
  }
  mul(value) {
    this.value *= value;
  }
  div(value) {
    this.value /= value;
  }
}

let num = new Number(10);
num.add(5); // 10 + 5 => 15
num.sub(3); // 15 - 3 => 12
num.mul(2); // 12 * 2 => 24
num.div(8); // 24 / 8 => 3

console.log(num.value);
// => 3
```

Ví dụ trên xây dựng class _Number_ với 4 phương thức _add_, _sub_, _mul_, _div_. Và bạn có thể thấy với mỗi phương thức được gọi, bạn phải lặp lại biến _num_ và mỗi câu lệnh thường viết trên 1 dòng.

Như vậy khá dài dòng phải không bạn?

### Ví dụ khi sử dụng Method Chaining

```js
class Number {
  constructor(value) {
    this.value = value;
  }
  add(value) {
    this.value += value;
    return this;
  }
  sub(value) {
    this.value -= value;
    return this;
  }
  mul(value) {
    this.value *= value;
    return this;
  }
  div(value) {
    this.value /= value;
    return this;
  }
}

let num = new Number(10);
num.add(5).sub(3).mul(2).div(8);
console.log(num.value);
```

Trong đoạn code trên, mình đã triển khai các phương thức theo Method Chaining. Nhờ vậy mà mình có thể gọi liên tiếp các phương thức trên cùng 1 dòng.

Cách thực hiện ở đây rất đơn giản là: mình chỉ cần thêm _**return this**_ vào cuối mỗi phương thức.

_This_ ở đây đại diện cho [object](/bai-viet/javascript/object-la-gi-object-trong-javascript) được tạo ra (_num_) sau khi sử dụng từ khóa _new_.

Rất dễ hiểu phải không bạn?

## Kết luận

Trên đây là những thông tin cơ bản về kĩ thuật Method Chaining. Để hiểu thêm về kĩ thuật này, bạn có thể đọc thêm trong các bài viết ở phần tham khảo dưới đây.

## Tham khảo

- [Native Function Chaining in JavaScript. What We Can Learn From jQuery](https://medium.com/@saginadir/native-function-chaining-in-javascript-what-we-can-learn-from-jquery-3b42d5d4a0d)
- [Javascript Cascade Design Pattern](https://medium.com/tiny-code-lessons/javascript-cascade-design-pattern-990b1a761ff4)
- [Beautiful JavaScript: Easily Create Chainable (Cascading) Methods for Expressiveness](http://javascriptissexy.com/beautiful-javascript-easily-create-chainable-cascading-methods-for-expressiveness/)
