---
title: "Javascript Web worker api là gì"
description: "Web Workers là một API JavaScript, cho phép bạn chạy các script trong một thread riêng biệt từ một trang chính."
keywords: [
"Javascript Web worker api là gì",
"Cơ bản về Web Workers trong javascript",
"Javascript Web worker là gì",
"Web Workers là gì trong javascript ",
"Web worker và service worker trong javascript",
"Simple web worker trong javascript",
"Thành phần của WebWorker trong javascript",
"HTML Web Workers API trong javascript"
]
chapter:
  name: "Javascript worker"
  slug: "chuong-16-javascript-worker"
category:
  name: "Javascript"
  slug: "javascript"
image: https://kungfutech.edu.vn/thumbnail.png
position: 1
---

Có thể bạn thừa biết, JavaScript là một ngôn ngữ chạy [đơn luồng](https://www.red-gate.com/simple-talk/dotnet/asp-net/javascript-single-threaded). Điều đó có nghĩa là nếu bạn thực hiện một tác vụ quá lớn trên giao diện chính thì khả năng cao là giao diện sẽ bị đơ. Để giải quyết vấn đề này, JavaScript đã đưa ra một khái niệm là Worker. Vậy JavaScript Web Worker là gì và dùng nó như thế nào? Chúng ta sẽ cùng nhau tìm hiểu sau đây.

## JavaScript Web Worker là gì?

Web Worker là một phương tiện đơn giản giúp cho trang web có thể chạy JavaScipt ở background. Luồng này có thể chạy mà không can thiệp gì đến giao diện chính. Một khi đã được khởi tạo, Worker có thể giao tiếp với luồng chính thông qua việc gửi và nhận message.

Vì vậy, khi áp dụng JavaScript Web Worker một cách chính xác và phù hợp, trang web của bạn sẽ hoạt động mượt mà hơn rất nhiều.

## Cách sử dụng JavaScript Web Worker

### Kiểm tra trình duyệt có hỗ trợ Web Worker hay không

Để kiểm tra xem trình duyệt bạn đang sử dụng có hỗ trợ JavaScript Web Worker hay không, bạn có thể sử dụng **typeof**:

```js
if (typeof Worker !== "undefined") {
  // Có hỗ trợ JavaScript Web Worker
} else {
  // Không hỗ trợ JavaScript Web Worker
}
```

### Tạo file JavaScript cho Web Worker

Một ví dụ đơn giản cho file JavaScript Web Worker:

```js
for (var i = 0; i < 10000000000; i++) {
  if (i % 1000000000 == 0) postMessage(i);
}

self.onmessage = function (msg) {
  // Được gọi khi có message gửi từ luồng chính
};
```

### Khởi tạo Web Worker

Giả sử bạn đã tạo một file **web_worker.js**. Để khởi tạo Web Worker, bạn làm như sau:

```js
var w;

function startWorker() {
  // Kiểm tra xem trình duyệt có hỗ trợ JavaScript Web Worker
  if (typeof Worker !== "undefined") {
    // Kiểm tra đối tượng Web Worker đã được khởi tạo hay chưa
    if (typeof w == "undefined") {
      // Khởi tạo Web Worker
      w = new Worker("web_worker.js");
    }
    w.onmessage = function (event) {
      // Được gọi khi có message từ Web Worker gửi đến
    };
    w.onerror = function () {
      // Khi có lỗi xảy ra với Web Worker
    };
  } else {
    // Trình duyệt không hỗ trợ JavaScript Web Worker
  }
}
```

Bạn thấy sau khi khởi tạo JavaScript Web Worker, ta có thể implement hai [function](/bai-viet/javascript/ham-trong-javascript) quan trọng là [Worker.onmessage](https://developer.mozilla.org/en-US/docs/Web/API/Worker/onmessage) và [Worker.onerror](https://developer.mozilla.org/en-US/docs/Web/API/AbstractWorker/onerror) để xử lý [event](/bai-viet/javascript/mot-so-event-javascript).

Trong đó, **Worker.onerror** được gọi khi có lỗi với Web Worker sau khi khởi tạo. Và **Worker.onmessage** được gọi khi có message từ Worker Thread lên giao diện chính.

### Dừng Web Worker

Sau khi khởi tạo Web Worker thì code JavaScript ở background sẽ chạy. Để dừng Web Worker lại, bạn có thể sử dụng phương thức **terminate()**.

```js
w.terminate();
```

### Giao tiếp giữa Web Worker ở luồng chính và background

Để có thể thực hiện được điều này, bạn có thể sử dụng phương thức [**postMessage()**](https://developer.mozilla.org/en-US/docs/Web/API/Window/postMessage), ở cả hai phía luồng chính và background. Khi đó, hàm **onmessage()** sẽ được gọi ở đầu còn lại.

Đối với hàm **postMessage()** sẽ có hai cách sử dụng:

- Truyền đi message thông thường.
- Sử dụng Transferable Object

#### Truyền Message thông thường

Trong phương pháp này, tham số truyền vào sẽ là một [object](/bai-viet/javascript/object-la-gi-object-trong-javascript). Dữ liệu sẽ được copy từ phía gửi sang phía nhận.

Ví dụ như sau:

```js
function startWorker() {
  if (typeof myWorker != "undefined") {
    myWorker.postMessage({ cmd: "start", msg: "hello" });
  } else {
    console.log("[Main]", "Worker is undefined.");
  }
}
```

Ở đây object gửi đi sẽ là **{cmd : 'start', msg : 'hello'}**. Thực tế, object ở đây có thể là bất kì kiểu dữ liệu nào: [Number, String, Boolean](/bai-viet/javascript/cac-kieu-du-lieu-trong-javascript), [Array](/bai-viet/javascript/mang-array-trong-javascript).

Và ở Worker Thread, hàm **onmessage** sẽ được gọi:

```js
self.onmessage = function (event) {
  handleMessage(event);
};

function handleMessage(event) {
  console.log(
    "[Worker]",
    "Worker Thread receives command: ",
    event.data.cmd,
    event.data.msg
  );
  if (event.data.cmd == "start") {
    for (var i = 0; i <= 10000000000; i++) {
      if (i % 1000000000 == 0) postMessage({ cmd: "resp", msg: i });
    }
  } else if (event.data.cmd == "stop") {
    postMessage({ cmd: "stop", msg: "Good Bye!" });
    self.close();
  }
}
```

Object nhận được từ phía giao diện chính sẽ được lấy từ **data** trong **event**.

```js
console.log(
  "[Worker]",
  "Worker Thread receives command: ",
  event.data.cmd,
  event.data.msg
);
// => [Worker] Worker Thread receives command: start hello
```

Để test chức năng này, mình có chuẩn bị một ví dụ nhỏ trên [Github](https://github.com/completejavascript/web-worker-test) và [codepen](https://codepen.io/completejavascript/pen/vpRvgm) mà bạn có thể tham khảo.

Cách này có một nhược điểm là nếu như bạn gửi dữ liệu lớn, chẳng hạn 500MB, thì sau khi gửi đi, nó sẽ được sao chép. Vì vậy, tổng dữ liệu chiếm sẽ là 500MB + 500MB = 1GB. Điều đó có thể dẫn đến hết bộ nhớ cho phép. Để khắc phục tình trạng này, ta có thể sử dụng Transferable Object như sau.

#### Sử dụng Transferable Object

Khi sử dụng [Transferable Object](https://developers.google.com/web/updates/2011/12/Transferable-Objects-Lightning-Fast), dữ liệu được chuyển toàn bộ từ phía gửi sang phía nhận. Dung lượng dữ liệu phía gửi sẽ bị xóa về 0.

[Ví dụ](https://github.com/completejavascript/web-worker-transferable-object):

Phía Main Thread:

```js
function startWorker() {
  if (typeof myWorker != "undefined") {
    var arrBuf1 = new ArrayBuffer(1000);
    var arrBuf2 = new ArrayBuffer(100000);

    console.log("[Main]", "Before Transfering:");
    console.log("[Main]", "Length of Array Buffer 1:", arrBuf1.byteLength);
    console.log("[Main]", "Length of Array Buffer 2:", arrBuf2.byteLength);

    myWorker.postMessage({ cmd: "start", buf1: arrBuf1, buf2: arrBuf2 }, [
      arrBuf1,
      arrBuf2,
    ]);

    console.log("[Main]", "After Transfering:");
    console.log("[Main]", "Length of Array Buffer 1:", arrBuf1.byteLength);
    console.log("[Main]", "Length of Array Buffer 2:", arrBuf2.byteLength);
  } else {
    console.log("[Main]", "Worker is undefined.");
  }
}
```

Phía Worker Thread:

```js
self.onmessage = function (event) {
  handleMessage(event);
};

function handleMessage(event) {
  console.log("[Worker]", "Worker Thread receives command: ", event.data.cmd);

  if (event.data.cmd == "start") {
    console.log(
      "[Worker]",
      "Length of Array Buffer 1:",
      event.data.buf1.byteLength
    );

    console.log(
      "[Worker]",
      "Length of Array Buffer 2:",
      event.data.buf2.byteLength
    );
  }
}
```

Ở đây, Transferable Object là [ArrayBuffer](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/ArrayBuffer).

Kết quả:

<content-result>

[Main] Init Web Worker
[Main] Before Transfering:
[Main] Length of Array Buffer 1: 1000
[Main] Length of Array Buffer 2: 100000
[Main] After Transfering:
[Main] Length of Array Buffer 1: 0
[Main] Length of Array Buffer 2: 0
// Độ dài của Array Buffer sau khi gửi sẽ là 0
// vì nó được chuyển sang phía Worker Thread.

[Worker] Worker Thread receives command: start
[Worker] Length of Array Buffer 1: 1000
[Worker] Length of Array Buffer 2: 100000

</content-result>

**Chú ý:**

- Việc thực hiện lệnh tại **onmessage** sẽ được thực hiện tuần tự. Nghĩa là khi bạn gửi 10 lệnh **postMessage**, thì ở phía nhận, nó sẽ thực hiện lần lượt từng lệnh một, hết lệnh này mới đến lệnh khác.
- Worker Thread có thể tự đóng nó bằng cách gọi: **self.close()**.

Bài viết hôm nay dừng lại tại đây. Để tìm hiểu thêm về JavaScript Web Worker thì bạn có thể tìm hiểu thêm ở những link phía dưới đây.

## Xem thêm

- [HTML5 Web Worker](https://www.w3schools.com/html/html5_webworkers.asp)
- [Using Web Worker](https://developer.mozilla.org/en-US/docs/Web/API/Web_Workers_API/Using_web_workers)
- [The basics of Web Worker](https://www.html5rocks.com/en/tutorials/workers/basics/)
- [Web Worker Test](https://github.com/completejavascript/web-worker-test)
- [Inline Web Worker](https://github.com/completejavascript/inline-web-worker)
- [Web Worker using Transferable Object.](https://github.com/completejavascript/web-worker-transferable-object)
