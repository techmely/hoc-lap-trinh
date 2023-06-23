---
title: "Xử lý bất đồng bộ với callback, promise, async/await"
description: "Xử lý bất đồng bộ là cơ chế xử lý không thể thiếu trong JavaScript. Cùng xem cách triển khai nó với callback, promise và async/await trong javascript."
keywords: [
"Xử lý bất đồng bộ với callback, promise, async/await",
"Xử lý bất đồng bộ với callback, promise, async/await như thế nào",
"bất đồng bộ trong javascript",
"callback trong javascript",
"promise trong javascript",
"async/await trong javascript",
"callback trong javascript là gì",
"promise trong javascript là gì",
"async/await trong javascript là gì",
"Xử lí bất đồng bộ trong javascript",
"thế nào là bất đồng bộ trong javascript"
]
chapter:
  name: "Callback, Promise, async/await"
  slug: "chuong-09-callback-promise-asyn-await"
category:
  name: "Javascript"
  slug: "javascript"
image: https://kungfutech.edu.vn/thumbnail.png
position: 1
---

Khi lập trình JavaScript, bạn sẽ thường xuyên phải thực hiện các công việc mất thời gian như: request lên server, lấy dữ liệu từ database, đọc/ghi file,... Nếu bạn chỉ xử lý đồng bộ thôi thì chắc chắn sẽ rất mất thời gian. Để giải quyết vấn đề này, JavaScript cung cấp một số công cụ hỗ trợ bạn **xử lý bất đồng bộ** rất tốt như sử dụng **callback**, promise hay **async/await**.

Trong bài viết này, mình sẽ cùng nhau tìm hiểu xem xử lý bất đồng bộ là gì? Tại sao phải xử lý bất đồng bộ? Và các cách để xử lý bất đồng bộ trong JavaScript. Mời bạn theo dõi bài viết!

## Cơ bản về xử lý bất đồng bộ

Giả sử bạn có một nhiệm vụ bao gồm 2 công việc tốn thời gian, tạm gọi là A và B.

### Xử lý đồng bộ

Đối với xử lý đồng bộ, bạn sẽ thực hiện công việc A; đợi A hoàn thành xong thì sẽ thực hiện B; rồi lại đợi B hoàn thành thì nhiệm vụ cuối cùng mới coi như xong.

![Xử lý đồng bộ trong javascript](https://github.com/techmely/hoc-lap-trinh/assets/29374426/5c04d42e-aaa1-4fb4-b884-4d365f31040f)


Nghĩa là thời gian để hoàn thành nhiệm vụ là tổng của thời gian hoàn thành A và B. Hơn nữa, trong khoảng thời gian này bạn sẽ không thể thực hiện thêm 1 hành động nào khác (như bắt các [sự kiện](/bai-viet/javascript/mot-so-event-javascript) với chuột và bàn phím của người dùng...). Điều này rõ ràng làm giảm hiệu năng và trải nghiệm người dùng đối với chương trình.

### Xử lý đa luồng

Để khắc phục tình trạng này, các ngôn ngữ lập trình như C/C++, Java,... sẽ sử dụng **cơ chế đa luồng (multi-thread)**. Nghĩa là mỗi công việc tốn thời gian sẽ được thực hiện trên một thread riêng biệt mà không can thiệp vào thread chính. Bạn vẫn có thể thực hiện các công việc tốn thời gian mà vẫn có thể bắt các sự kiện ở thread chính.

![Xử lý đa luồng trong javascript](https://github.com/techmely/hoc-lap-trinh/assets/29374426/2d00583b-30cf-4b6f-97e2-b4b500614c78)

Với ví dụ trên, thời gian để hoàn thành nhiệm vụ sẽ chỉ bằng thời gian hoàn thành của A hoặc B. Cái nào thực hiện xong trước sẽ đợi cái còn lại hoàn thành thì nhiệm vụ sẽ kết thúc.

### Xử lý bất đồng bộ

Tuy nhiên, JavaScript lại là một câu chuyện khác. Hai nền tảng quan trọng với JavaScript (trình duyệt và Nodejs đều là **single-thread**. Chính vì vậy, bạn không thể xử lý đa luồng với JavaScript được mà phải sử dụng cơ chế **xử lý bất đồng bộ**.

![Xử lý bất đồng bộ](https://github.com/techmely/hoc-lap-trinh/assets/29374426/d0c4ff10-c464-4eb6-a84f-58ffcab8ec6c)

Với cách xử lý bất đồng bộ, khi A bắt đầu thực hiện, chương trình tiếp tục thực hiện B mà không đợi A kết thúc. Việc mà bạn cần làm ở đây là cung cấp một phương thức để chương trình thực hiện khi A hoặc B kết thúc.

Cơ chế giúp bạn thực hiện việc này trong JavaScript có thể là sử dụng **Callback**, **Promise** hoặc **Async/await**.

## Sử dụng Callback để xử lý bất đồng bộ

**Sử dụng Callback** có thể nói là cách đầu tiên và dễ nhất giúp bạn xử lý bất đồng bộ. Khi định nghĩa một [function](/bai-viet/javascript/ham-trong-javascript) thực hiện một nhiệm vụ tốn thời gian, bạn cần truyền thêm tham số vào hàm - đóng vai trò là **hàm callback**.

Khi hành động bắt đầu, rồi khi nó kết thúc, hàm callback sẽ được gọi ngay sau đó.

Ví dụ dưới đây sẽ thực hiện một **GET** [request](/bai-viet/javascript/network-requests). Thông thường, việc này sẽ tốn thời gian (ít hay nhiều tuỳ thuộc vào tốc độ mạng):

```js
function doAsync(url, onSuccess, onError) {
  const xhr = new XMLHttpRequest();
  xhr.open("GET", url);
  xhr.onload = () => onSuccess(xhr.responseText);
  xhr.onerror = () => onError(xhr.statusText);
  xhr.send();
}
// Usage:
doAsync(
  "https://something.com",
  (value) => {
    // 'value' is corresponding with 'xhr.responseText'
  },
  (error) => {
    // 'error' is corresponding with 'xhr.statusText'
  }
);
```

Ở đây, hàm **doAsync** là một hàm bất đồng bộ với 2 hàm callback là: **onSuccess** và **onError**. Khi request trên thành công thì hàm _onSuccess_ sẽ được gọi, ngược lại hàm _onError_ sẽ được gọi. Khá dễ hiểu và dễ triển khai phải không?

Tuy nhiên, thử tưởng tượng bạn phải thực hiện 2 request liên tiếp, với request thứ 2 chỉ thực hiện khi request thứ nhất thực hiện xong:

```js
// Usage:
    doAsync(
      "https://something.com",
      (value) => {
        // 'value' is corresponding with 'xhr.responseText' (1)

        doAsync(
          "https://other.com",
          (value) => {
            // 'value' is corresponding with 'xhr.responseText' (2)
          },
          (error) => {
            // 'error' is corresponding with 'xhr.statusText' (2)
          }
        );
      },
      (error) => {
        // 'error' is corresponding with 'xhr.statusText' (1)
      }
    );
```

Bắt đầu phức tạp rồi nhỉ? Và nếu bạn phải thực hiện thêm vài request khác nữa thì kết quả chắc chắn sẽ còn kinh khủng hơn rất nhiều. Trường hợp này gọi là **Callback Hell**.

Để tránh Callback Hell, bạn có thể sử dụng một cơ chế khác. Đó là Promise.

## Sử dụng Promise để xử lý bất đồng bộ

Cú pháp cơ bản của **Promise** là:

```js
let promise = new Promise(function (resolve, reject) {
  // Code here
});
```

Trong đó, hàm được truyền vào **new Promise** gọi là **executor**.

Ban đầu, Promise có state là _pending_ và kết quả _value_ là **undefined**. Khi executor kết thúc công việc, nó sẽ gọi đến 1 trong 2 hàm được truyền vào:

- **resolve(value)**: để xác định rằng công việc đã thực hiện thành công
  - state chuyển thành _fulfilled_
  - kết quả là _value_
- **reject(error)**: để xác định rằng đã có lỗi xảy ra
  - state chuyển thành _rejected_
  - kết quả là _error_

Khi sử dụng Promise, ví dụ phía trên sẽ trở thành:

```js
function doAsync(url) {
      return new Promise((resolve, reject) => {
        const xhr = new XMLHttpRequest();
        xhr.open("GET", url);
        xhr.onload = () => resolve(xhr.responseText);
        xhr.onerror = () => reject(xhr.statusText);
        xhr.send();
      });
    }

    // Usage:
    doAsync("https://something.com")
      .then((value) => {
        // 'value' is corresponding with 'xhr.responseText'
      })
      .catch((error) => {
        // 'error' is corresponding with 'xhr.statusText'
      });
```

Và khi bạn muốn thực hiện 2 request liên tiếp:

```js
 // Usage:
    doAsync("https://something.com")
      .then((value) => {
        /*
         * 'value' is corresponding with 'xhr.responseText'
         * from 'https://something.com'
         */
        return doAsync("https://other.com");
      })
      .then((value) => {
        /*
         * 'value' is corresponding with 'xhr.responseText'
         * from 'https://other.com'
         */
      })
      .catch((error) => {
        /*
         * 'error' is corresponding with 'xhr.statusText'
         * from either 'https://something.com' or 'https://other.com'
         */
      });
```

Rõ ràng, cấu trúc chương trình đã trở nên rõ ràng hơn. Không còn hiện tượng nhiều mức lồng nhau như khi sử dụng callback nữa rồi.

## Sử dụng Async/await để xử lý bất đồng bộ

**Async/await** là một cú pháp đặc biệt giúp bạn làm việc với Promise dễ dàng hơn. Khi sử dụng async/await, cấu trúc chương trình xử lý bất đồng bộ sẽ giống với chương trình xử lý đồng bộ hơn.

Với ví dụ sử dụng Promise bên trên, mình có thể áp dụng async/await như sau:

```js
function doAsync(url) {
      return new Promise((resolve, reject) => {
        const xhr = new XMLHttpRequest();
        xhr.open("GET", url);
        xhr.onload = () => resolve(xhr.responseText);
        xhr.onerror = () => reject(xhr.statusText);
        xhr.send();
      });
    }

    // Usage:
    async function run() {
      let responseText1, responseText2;

      try {
        responseText1 = await doAsync("https://something.com");
        responseText2 = await doAsync("https://other.com");
      } catch (error) {
        /*
         * 'error' is corresponding with 'xhr.statusText'
         * from either 'https://something.com' or 'https://other.com'
         */
      }
    }

    run();
```

Nếu xử lý theo cách này thì dù bạn có thực hiện thêm nhiều request nữa, cấu trúc chương trình vẫn rất rõ ràng và mạch lạc phải không?

Và theo mình, đây có lẽ là cách tốt nhất để xử lý bất đồng bộ trong JavaScript, theo quan điểm của bạn thì sao nhỉ?

## Lời kết

Trên đây là một số kiến thức cơ bản về xử lý bất đồng bộ trong JavaScript với callback, promise và async/await. Bài này không viết chi tiết về Promise hay async/await mà chỉ giúp bạn thấy được cách sử dụng cơ bản, cũng như ưu điểm của chúng so với việc sử dụng callback thông thường.

Để biết thêm về Promise và async/await, bạn có thể tham khảo thêm trong các bài viết dưới đây:

- [Asynchronous Programming](https://eloquentjavascript.net/11_async.html)
- [Promise - MDN](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Promise)
- [Promise - Javascript.info](https://javascript.info/promise-basics)
- [Async/await](https://javascript.info/async-await)
- [Async function](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Statements/async_function)
- [Await](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Operators/await)

Xin chào và hẹn gặp lại, thân ái!
