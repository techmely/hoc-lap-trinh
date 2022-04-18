---
title: "Module pattern trong JavaScript"
description: ""
keywords: []
chapter:
  name: "Design pattern"
  slug: "17-design-pattern"
category:
  name: "Javascript"
  slug: "javascript"
image: https://kungfutech.edu.vn/thumbnail.png
position: 2
---

Module pattern là một loại pattern khá mạnh và được sử dụng rất phổ biến, với một số các đặc điểm sau:

- Sử dụng Object Literals ({})
- Cung cấp khả năng đóng gói dữ liệu với cả thuộc tính và phương thức dạng **public/private**, giúp tránh xung đột về tên đối với các [function](/bai-viet/javascript/ham-trong-javascript) ở các script khác trên trang web.

## Ví dụ sử dụng Module Pattern

    var countModule = (function () {
      var count = 0;
      var log = function (funcName) {
        console.log(funcName, count);
      };
      return {
        increase: function () {
          count++;
          log("increase");
        },
        decrease: function () {
          count--;
          log("decrease");
        },
        reset: function () {
          count = 0;
          log("reset");
        },
      };
    })();

    // Usage:
    countModule.increase(); // increase 1
    countModule.increase(); // increase 2
    countModule.decrease(); // increase 1
    countModule.reset(); // reset 0

### Giải thích

Ví dụ trên định nghĩa một module tên là: **countModule**. Có thể bạn sẽ thắc mắc về cú pháp sau:

    var countModule = (function () {})();

Thực chất, đoạn code trên có thể tách ra làm 2 phần: Khai báo hàm và gọi hàm.

    // Khai báo hàm
    var funcModule = function () {};
    // Gọi hàm
    var countModule = funcModule();

Do đó, nếu muốn truyền tham số vào function (chẳng hạn như **jQuery**) thì bạn có thể viết như sau:

    var countModule = (function (jQ) {})(jQuery);

Theo cách phân tích trên, thực chất **countModule** là thành phần **return** của function - dạng [object](/object-la-gi-object-trong-javascript/) ({}). Do đó, ta chỉ có thể truy cập đến những thuộc tính bên trong object này là: **_increase, decrease, reset_**. Hay nói cách khác, những hàm số này thuộc dạng **public**.

Ngược lại, biến số **count**, **log** chỉ truy cập được ở trong hàm số trên, nên thuộc dạng **private**.

## Revealing Module Pattern

**Module Pattern** có một nhược điểm là khó theo dõi các phương thức được public. Sau đây là cách sử dụng **Revealing Module Pattern** để khắc phục nhược điểm này:

    var countModule = (function () {
      var count = 0;
      var log = function (funcName) {
        console.log(funcName, count);
      };
      function increaseFunc() {
        count++;
        log("increase");
      }
      function decreaseFunc() {
        count--;
        log("decrease");
      }
      function resetFunc() {
        count = 0;
        log("reset");
      }
      return {
        increase: increaseFunc,
        decrease: decreaseFunc,
        reset: resetFunc,
      };
    })();

    // Usage:
    countModule.increase(); // increase 1
    countModule.increase(); // increase 2
    countModule.decrease(); // increase 1
    countModule.reset(); // reset 0

Bây giờ, ta có thể dễ dàng thấy rằng **countModule** có 3 phương thức được public là: **increase, decrease, reset**.

Hy vọng với sự giải thích ngắn gọn trên, bạn có thể hiểu và áp dụng được Module Pattern.

Xin chào và hẹn gặp lại bạn ở [bài viết tiếp theo](/js-pattern-3-singleton-pattern/), thân ái!

## Tham khảo

- [Learning JavaScript Design Patterns](https://addyosmani.com/resources/essentialjsdesignpatterns/book/#modulepatternjavascript)
