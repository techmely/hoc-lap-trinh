---
title: "Kết thúc Promise chaining trong JavaScript"
description: "Trong trường hợp thực hiện nhiều Promise liên tiếp nhau mà bạn muốn dừng giữa chừng thì sao? Hay nói cách khác là làm sao để kết thúc sớm Promise chaining trong JavaScript?"
keywords: [
"Kết thúc Promise chaining trong JavaScript",
"Kết thúc Promise chaining trong JavaScript là gì",
"promise chain la gi trong javascript",
"promise chain có ý nghĩa gì trong javascript",
"Xử lý tuần tự JavaScript",
"chaining trong JavaScript"
]
chapter:
  name: "Callback, Promise, async/await"
  slug: "chuong-09-callback-promise-asyn-await"
category:
  name: "Javascript"
  slug: "javascript"
image: https://kungfutech.edu.vn/thumbnail.png
position: 2
---

Có thể bạn đã quen với việc sử dụng [Promise](https://developer.mozilla.org/vi/docs/Web/JavaScript/Reference/Global_Objects/Promise) để xử lý bất đồng bộ trong JavaScript. Tuy nhiên, trong trường hợp thực hiện nhiều Promise liên tiếp nhau ([Promise chaining](https://javascript.info/promise-chaining)) mà bạn muốn dừng giữa chừng thì sao? Hay nói cách khác là làm sao để kết thúc sớm Promise chaining trong JavaScript?

## Bài toán thực tế

Thử xét một bài toán thực tế khi mà việc kết thúc sớm Promise chaining là cần thiết. Đó là khi triển khai API để đăng ký User qua Email. Mình có thể tóm tắt lại các bước thực hiện như sau:

```js
Tìm kiếm User qua email
  .then(
    Nếu email đã tồn tại thì sẽ kết thúc sớm Promise chaining.
    Ngược lại sẽ thực hiện bước tiếp theo.
  )
  .then(
    Hash mật khẩu.
  )
  .then(
    Tạo User và lưu vào cơ sở dữ liệu.
  )
  .catch(
    Xử lý khi có bất kỳ lỗi gì xảy ra.
  )
```

Bạn thấy đó, ngay tại bước _then_ đầu tiên, nếu email đã tồn tại thì mình sẽ kết thúc sớm Promise chaining. Có thể bạn sẽ triển khai API để đăng ký User qua Email theo cách khác của mình. Tuy nhiên, đây chỉ là một ví dụ dùng để minh hoạ mà thôi.

Vậy làm sao để kết thúc sớm Promise chaining trong JavaScript?

Dưới đây, mình sẽ xem xét một bài phi thực tế để biết cách triển khai code như thế nào nhé!

## Bài toán ví dụ

### Giới thiệu bài toán

Giả sử mình có đoạn code dưới đây:

```js
const increase = (x) => {
  console.log(x);
  return x + 1;
};

const run = (x) => {
  new Promise((resolve, reject) => {
    resolve(x);
  })
    .then((res) => increase(res))
    .then((res) => increase(res))
    .then((res) => increase(res))
    .catch((err) => console.log("Catched: " + err));
};
```

Trong đó:

- [Hàm](/bai-viet/javascript/ham-trong-javascript) _increase_ sẽ trả về giá trị của đầu vào + 1.
- Hàm _run_ sẽ thực hiện một Promise chaining, với mỗi mắt xích sẽ gọi hàm _increase_.

Với hàm _run_ như trên thì với mọi giá trị của x, 3 cái _then_ trên luôn được thực hiện. Ví dụ với x = 4 thì kết quả thu được là:

```js
run(4);
/*
 * 4
 * 5
 * 6
 */
```

Nếu mình muốn kết thúc sớm Promise chaining ngay tại _then_ đầu tiên khi giá trị của _res_ lớn hơn 3 thì sao?

Có 2 cách để giải quyết bài toán này, đó là: **không thực hiện return** hoặc **sử dụng [Promise.reject()](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Promise/reject)**

### Kết thúc sớm Promise chaining bằng cách không return

Bình thường, khi thực hiện _return_, giá trị _return_ sẽ được đưa đến mắt xích tiếp theo của chuỗi Promise để xử lý. Và nếu bạn không _return_ thì giá trị đó sẽ được hiểu là **undefined**. Dựa vào đặc điểm này, mình sẽ thay đổi đoạn code trên như sau:

```js
const increase = (x) => {
  console.log(x);
  return x + 1;
};

const run = (x) => {
  new Promise((resolve, reject) => {
    resolve(x);
  })
    .then((res) => {
      if (res <= 3) return increase(res);
    })
    .then((res) => {
      if (res !== undefined) return increase(res);
    })
    .then((res) => {
      if (res !== undefined) return increase(res);
    })
    .catch((err) => console.log("Catched: " + err));
};

run(3);
/*
 * 3
 * 4
 * 5
 */

run(4);
// Nothing
```

Với **x = 3**: giá trị của _res_ tại _then_ đầu tiên là 3, thoả mãn `res <= 3` nên đoạn code đó trả về `increase(res)`. Dẫn đến, giá trị của _res_ tại các _then_ tiếp theo lần lượt là 4, 5.

Với **x = 4**: ngay tại _then_ đầu tiên _res_ sẽ bằng 4, không thoả mãn `res <= 3` nên đoạn code `return increase(res)` sẽ không được thực hiện. Dẫn đến, đoạn _then_ này sẽ trả về **undefined**. Do đó các _then_ tiếp theo, giá trị của _res_ sẽ là _undefined_. Mà mình đã kiểm tra nếu `res !== undefined` thì mới thực hiện. Tóm lại, mình đã kết thúc sớm Promise chaining ngay tại _then_ đầu tiên rồi.

Tuy nhiên, nếu để ý kĩ thì bạn sẽ thấy cách này chỉ giải quyết được về mặt kết quả. Còn về hình thức thì các mắt xích của chuỗi Promise vẫn được nhảy đến. Điều này có thể tiềm ẩn nhiều **Bug** sau này. Vì vậy, cái mà mình mong muốn thực sự là việc kết thúc sớm Promise chaining sẽ giúp thoát khỏi chuỗi Promise một cách hoàn toàn.

Đúng vậy, việc sử dụng _Promise.reject()_ sẽ giúp bạn kết thúc sớm Promise chaining bằng cách nhảy thẳng đến phần _catch_. Khi đó, đoạn code trên sẽ trở thành:

```js
const increase = (x) => {
  console.log(x);
  return x + 1;
};

const run = (x) => {
  new Promise((resolve, reject) => {
    resolve(x);
  })
    .then((res) => {
      if (res <= 3) return increase(res);
      return Promise.reject(res);
    })
    .then((res) => increase(res))
    .then((res) => increase(res))
    .catch((err) => console.log("Catched: " + err));
};

run(3);
/*
 * 3
 * 4
 * 5
 */
run(4);
// Catched: 4
```

Trong trường hợp này, mình chỉ cần thêm phần xử lý tại _then_ đầu tiên.

Với **x = 3**: Kết quả vẫn như phần trên.

Với **x = 4**: Tại _then_ đầu tiên, _res_ bằng 4, không thoả mãn `res <= 3` nên đoạn đó sẽ thực hiện `return Promise.reject(res)`. Điều này dẫn đến các đoạn _then_ tiếp theo sẽ bị bỏ qua mà nhảy thẳng đến đoạn _catch_. Tại đây, giá trị của _err_ bằng giá trị của _res_ đã bị _reject_ bên trên, nên bằng 4.

Rõ ràng, việc sử dụng _Promise.reject()_ đã giúp kết thúc sớm Promise chaining một cách hoàn toàn rồi.

## Lời kết

Như vậy là mình đã giới thiệu với bạn 2 cách để kết thúc sớm Promise chaining trong JavaScript. Nếu bạn biết thêm cách nào khác để thực hiện việc này thì hãy chia sẻ với mình trong phần bình luận phía dưới nhé!

Xin chào và hẹn gặp lại!
