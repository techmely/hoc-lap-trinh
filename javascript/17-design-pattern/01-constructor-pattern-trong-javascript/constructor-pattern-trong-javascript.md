---
title: "Constructor pattern trong JavaScript"
description: ""
keywords: []
chapter:
  name: "Design pattern"
  slug: "17-design-pattern"
category:
  name: "Javascript"
  slug: "javascript"
image: https://kungfutech.edu.vn/thumbnail.png
position: 1
---

Đối với [lập trình hướng đối tượng trong JavaScript](/cac-khia-canh-lap-trinh-huong-doi-tuong-trong-javascript/), cách đơn giản nhất để tạo mới một object là sử dụng function kết hợp với từ khoá **new**. Bên trong hàm khởi tạo này, từ khoá **this** dùng để chỉ tới đối tượng mới. Thông thường, hàm khởi tạo được viết hoa chữ cái đầu tiên, dùng để phân biệt với các [hàm số](/bai-viet/javascript/ham-trong-javascript) thông thường. Sau đây, chúng ta sẽ cùng nhau tìm hiểu về một vài Constructor Pattern trong JavaScript.

## Constructor Pattern cơ bản

    function Animal(name, leg) {
      this.name = name;
      this.leg = leg;
      this.about = function () {
        return this.name + " has " + this.leg + " legs";
      };
    }

    // Usage:
    var dog = new Animal("Dog", 4);
    var bird = new Animal("Bird", 2);
    console.log(dog.about()); // => Dog has 4 legs
    console.log(bird.about()); // => Bird has 2 legs

Trong ví dụ trên, [đối tượng](/bai-viet/javascript/object-la-gi-object-trong-javascript) sử dụng hàm khởi tạo **Animal** sẽ có 2 thuộc tính (_name_, _leg_) và 1 phương thức (_about_). Tuy nhiên, cách trên có nhược điểm là khó để kế thừa và phương thức _about_ sẽ phải định nghĩa lại đối với mỗi đối tượng. Để khắc phục nhược điểm trên, ta có cách thứ hai là sử dụng **Prototypes**.

## Constructor Pattern với Prototypes

Trong JavaScript, mọi object (bao gồm **function**) đều tồn tại thuộc tính **prototype** - cũng là một object. Khi sử dụng hàm khởi tạo để tạo mới một object, mọi thuộc tính trong **prototype** đều được [kế thừa](/cac-khia-canh-lap-trinh-huong-doi-tuong-trong-javascript/) cho các đối tượng mới.

    function Animal(name, leg) {
      this.name = name;
      this.leg = leg;
    }
    Animal.prototype.about = function () {
      return this.name + " has " + this.leg + " legs";
    };

    // Usage:
    var dog = new Animal("Dog", 4);
    var bird = new Animal("Bird", 2);
    console.log(dog.about()); // => Dog has 4 legs
    console.log(bird.about()); // => Bird has 2 legs

## Constructor Pattern với từ khoá class

Từ khoá **class** thực chất là một hàm số đặc biệt. Sử dụng **class** cho phép khởi tạo đối tượng mới một cách trực quan, và gần với khái niệm _class_ trong các ngôn ngữ lập trình khác như C++, Java,...

Một điểm khác giữa **class** và **function** là **function** thuộc dạng **hoisting**, còn **class** thì không. Nghĩa là bạn có thể sử dụng hàm số trước khi khai báo hàm. Trong khi nếu bạn sử dụng class trước khi khai báo class thì bạn sẽ nhận được [thông báo lỗi](/bai-viet/javascript/mo-so-loi-loi-strict-mode) **ReferenceError**.

    class Animal {
      constructor(name, leg) {
        this.name = name;
        this.leg = leg;
      }

      about() {
        return this.name + " has " + this.leg + " legs";
      }
    }

    // Usage:
    var dog = new Animal("Dog", 4);
    var bird = new Animal("Bird", 2);
    console.log(dog.about()); // => Dog has 4 legs
    console.log(bird.about()); // => Bird has 2 legs

Trong class, có một hàm duy nhất và đặc biệt là **constructor**, đây là hàm khởi tạo của class. Trong hàm này bạn có thể định nghĩa các thuộc tính (_name_, _leg_) giống như sử dụng function và phương thức (_about_). Ngoài ra, bạn có thể định nghĩa các **getter**, **setter** và các hàm **static**.

Trên đây là một số Constructor Pattern cơ bản. Tiếp theo, mình sẽ giới thiệu với các bạn về Module Pattern.

Xin chào và hẹn gặp lại ở [bài viết tiếp theo](/js-pattern-2-module-pattern/), thân ái!

## Tham khảo

- [Learning JavaScript Design Patterns](https://addyosmani.com/resources/essentialjsdesignpatterns/book/#constructorpatternjavascript)
- [Classes - JavaScript | MDN](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Classes)
