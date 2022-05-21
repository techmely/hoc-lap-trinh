---
title: "Thủ thuật sử dụng console.log hiệu quả"
description: "log để debug, kiểm tra lỗi là việc thường xuyên đối với hầu hết các lập trình viên JavaScript. Tuy nhiên, không phải ai cũng thực sự biết cách tối ưu cách sử dụng. Cùng tìm hiểu!"
keywords: [
"Thủ thuật sử dụng console.log hiệu quả",
"sử dụng console.log hiệu quả trong javascript",
"console.log hiệu quả trong javascript",
"console.log trong javascript",
"cách dùng console.log hiệu quả trong javascript",
"tối ưu sử dụng console.log hiệu quả trong javascript",
"console.log trong javascript",
"console.log trong javascript là gì"
]
chapter:
  name: "Kiểm thử và đảm bảo chất lượng code"
  slug: "chuong-11-kiem-thu-va-dam-bao-chat-luong-code"
category:
  name: "Javascript"
  slug: "javascript"
image: https://kungfutech.edu.vn/thumbnail.png
position: 3
---

Có thể nói, sử dụng **console.log** để [debug](/bai-viet/javascript/debug-javascript-de-hay-kho), kiểm tra lỗi là việc thường xuyên đối với hầu hết các lập trình viên JavaScript. Tuy nhiên, không phải ai cũng thực sự biết cách sử dụng công cụ này. Vì vậy, bài viết này mình sẽ chia sẻ với bạn một số thủ thuật sử dụng console hiệu quả mà mình mới học được. Mời bạn theo dõi bài viết!

## Sử dụng console.log

### Cú pháp console.log

**Console.log** là hàm cơ bản nhất mà hầu như lập trình viên nào cũng dùng. Và hàm này có 2 cách sử dụng cơ bản như sau.

#### Cách 1

    console.log(obj1 [, obj2, ..., objN]);

Đối với cách 1, bạn liệt kê các giá trị, [object](/bai-viet/javascript/object-la-gi-object-trong-javascript) cách nhau bởi dấu phẩy, ví dụ:

    const foo = 1;
    const bar = "bar";
    const baz = { name: "John", age: "30", gender: "male" };

    console.log(foo, bar, baz);
    // => 1 "bar" {name: "John", age: "30", gender: "male"}

Theo mình đây là cách cơ bản mà hầu như lập trình viên nào cũng sử dụng. Bởi vì, cách này khá đơn giản và nhanh gọn.

#### Cách 2

    console.log(msg [, subst1, ..., substN]);

Đối với cách 2, bạn hiển thị [string](/bai-viet/javascript/cac-kieu-du-lieu-trong-javascript) cùng với các tham số truyền vào. Mình chưa biết nói sao cho chuẩn. Tuy nhiên, nó khá giống với việc sử dụng hàm **printf()** trong lập trình C, ví dụ:

    const foo = 1;
    const bar = "bar";
    const baz = { name: "John", age: "30", gender: "male" };

    console.log("Log: %d, %s and %o", foo, bar, baz);
    // => Log: 1, bar and {name: "John", age: "30", gender: "male"}

Trong đó, phần string hiển thị có 3 tham số cần truyền vào ứng với **%d**, **%s** và **%o**. Và giá trị của nó sẽ được lấy từ 3 thành phần tiếp theo, cách nhau bởi dấu phẩy.

**Chú ý:**

- **%o** hoặc **%O**: đại diện cho Object
- **%d** hoặc **%i**: đại diện cho số nguyên
- **%f**: đại diện cho số thực
- **%s**: đại diện cho string

Bạn cần sử dụng ký tự đại diện sao cho đúng với kiểu dữ bạn muốn hiển thị. Ngược lại, bạn sẽ thu được kết quả hiển thị không như mong muốn, ví dụ:

    const foo = 1;
    const bar = "bar";
    const baz = { name: "John", age: "30", gender: "male" };

    console.log("Log: %d, %s and %s", foo, bar, baz);
    // => Log: 1, bar and Object

Trong ví dụ trên, mặc dù tham số thứ 3 bạn truyền vào là một object. Và bạn cũng muốn hiển thị đầy đủ nội dung của object. Tuy nhiên, nếu bạn sử dụng **%s** thì kết quả thu được sẽ chỉ là một string "Object".

Cách này mình cũng mới biết, vì thực tế chưa sử dụng nó bao giờ. Theo mình thấy cách này không phổ biến, bởi lẽ nó khá lằng nhằng. Và bạn phải ghi nhớ kí tự đại diện nào thì tương ứng với kiểu dữ liệu nào.

### Sử dụng console.log hiệu quả

Trên đây, mình nhắc lại 2 cú pháp cơ bản sử dụng console.log rồi. Quay lại với chủ đề chính của bài viết hôm nay là làm sao sử dụng console.log cho hiệu quả.

Hãy thử xem ví dụ về cách sử dụng console.log sau đây:

    const foo = { name: "Alex", age: "26", gender: "male" };
    const bar = { name: "Jenifer", age: "18", gender: "female" };
    const baz = { name: "John", age: "30", gender: "male" };

    console.log(foo, bar, baz);

    /*
     * {name: "Alex", age: "26", gender: "male"}
     * {name: "Jenifer", age: "18", gender: "female"}
     * {name: "John", age: "30", gender: "male"}
     */

Cách sử dụng console.log như trên có một vấn đề là: bạn không trực tiếp thấy được mỗi giá trị tương ứng với biến nào. Khi xem log, bạn phải quay lại code để xem thứ tự các biến là gì. Như vậy, chẳng phải là rất mất thời gian hay sao?

Có 2 giải pháp cho vấn đề trên.

- **Giải pháp 1**: Viết thêm nội dung miêu tả

  const foo = { name: "Alex", age: "26", gender: "male" };
  const bar = { name: "Jenifer", age: "18", gender: "female" };
  const baz = { name: "John", age: "30", gender: "male" };

  console.log("foo", foo);
  console.log("bar", bar);
  console.log("baz", baz);

  /\*

  - foo {name: "Alex", age: "26", gender: "male"}
  - bar {name: "Jenifer", age: "18", gender: "female"}
  - baz {name: "John", age: "30", gender: "male"}
    \*/

Rõ ràng, bây giờ chỉ cần xem log là biết mỗi giá trị tương ứng với biến nào rồi phải không? Cách này khá ổn, tuy nhiên vẫn hơi mất công.

- **Giải pháp 2**: Đóng gói các biến thành object và sử dụng cú pháp khai báo rút gọn của [ES6](/tag/es6/)

  const foo = { name: "Alex", age: "26", gender: "male" };
  const bar = { name: "Jenifer", age: "18", gender: "female" };
  const baz = { name: "John", age: "30", gender: "male" };

  console.log({ foo, bar, baz });

  /_
  {
  bar: {name: "Jenifer", age: "18", gender: "female"},
  baz: {name: "John", age: "30", gender: "male"},
  foo: {name: "Alex", age: "26", gender: "male"},
  }
  _/

Cách này mình thấy khá sáng tạo và thú vị. Bởi cách viết rất ngắn gọn. Mà nội dung hiển thị ra lại đầy đủ và chi tiết.

## Sử dụng console.table hiển thị thông tin trực quan hơn

Tiếp tục với ví dụ bên trên, mình có thể sử dụng **console.table** để hiển thị các giá trị thành dạng bảng như sau:

    const foo = { name: "Alex", age: "26", gender: "male" };
    const bar = { name: "Jenifer", age: "18", gender: "female" };
    const baz = { name: "John", age: "30", gender: "male" };

    console.table([foo, bar, baz]);

Kết quả:

![Sử dụng console.table](/static/294104b1dcb11c330b2642ea537d7023/7c811/su-dung-console.table-completejavascript.com_.png "Sử dụng console.table")

## Sử dụng console.time và console.timeEnd

Trong 2 bài viết là: [Triển khai Stack trong JavaScript với Array, Object hay Map](/trien-khai-stack-trong-javascript-voi-array-object-hay-map/) và [Triển khai Queue trong JavaScript](/trien-khai-queue-trong-javascript/), mình có sử dụng [performance.now()](https://developer.mozilla.org/en-US/docs/Web/API/Performance/now) để tính toán thời gian thực hiện.

Trong đó, cách sử dụng của mình như sau:

    let start = performance.now();

    let i = 0;
    while (i < 1000000) {
      i++;
    }

    let end = performance.now();

    console.log(`looper: ${end - start}ms`);
    // => looper: 5.25999999808846ms

Ở đây, mình phải lấy thời điểm sau và thời điểm trước rồi trừ cho nhau để suy ra thời gian thực hiện của vòng lặp.

Tuy nhiên, nếu sử dụng **console.time** và **console.timeEnd** thì sẽ đơn giản hơn như sau:

    console.time("looper");

    let i = 0;
    while (i < 1000000) {
      i++;
    }

    console.timeEnd("looper");
    // => looper: 5.14501953125ms

## Lời kết

Trên đây là một số thủ thuật sử dụng console hiệu quả mà mình mới học được. Theo bạn thì những thủ thuật trên có thật sự cần thiết hay không?

Ngoài ra, bạn còn biết những thủ thuật, tiện ích nào với console hay không? Chia sẻ với mình và mọi người trong phần bình luận phía dưới nhé!

Xin chào và hẹn gặp lại, thân ái!

Tham khảo:

- [Console.log()](https://developer.mozilla.org/en-US/docs/Web/API/Console/log)
- [Output text to the console](https://developer.mozilla.org/en-US/docs/Web/API/console#Outputting_text_to_the_console)
- [Console.table()](https://developer.mozilla.org/en-US/docs/Web/API/Console/table)
- [Console.time()](https://developer.mozilla.org/en-US/docs/Web/API/Console/time)
