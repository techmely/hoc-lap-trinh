---
title: "Javascript Service Worker là gì"
description: "Service Worker là một script mà trình duyệt chạy ở dưới background, tách khỏi trang web và giúp thực hiện các tính năng không cần đến trang web, hay tương tác người dùng."
keywords: [
"Javascript Service worker là gì trong javascript",
"Tìm hiểu về service worker trong javascript",
"Giới thiệu về Service Worker trong javascript",
"làm việc với service worker trong javascript",
"Service provider worker là gì trong javascript",
"Service Worker, Progressive Web Apps là gì trong javascript",
"Javascript Service Worker là gì"
]
chapter:
  name: "Javascript worker"
  slug: "chuong-16-javascript-worker"
category:
  name: "Javascript"
  slug: "javascript"
image: https://kungfutech.edu.vn/thumbnail.png
position: 2
---

Xin chào bạn! Không biết bạn đã từng nghe về **Offline Web App** chưa? Có thể bạn đã biết hoặc chưa. Hiểu một cách đơn giản, Offline Web App là một ứng dụng web có thể chạy ngay cả khi không có kết nối internet. Bây giờ, mình phân tích chút xíu nhé. Có 2 thứ cần thiết để web app có thể chạy được là: resources (html, js, css, ảnh,...) và định tuyến. Thì thằng mà chúng ta sẽ tìm hiểu sau đây là **JavaScript Service Worker** có thể đáp ứng được cả hai việc đó. Vậy...

## JavaScript Service Worker là gì?

Service Worker là một script mà trình duyệt chạy ở dưới background, tách khỏi trang web và giúp thực hiện các tính năng không cần đến trang web, hay tương tác người dùng.

Service Worker có một số đặc điểm quan trọng là:

- Không liên kết với một trang cụ thể
- Không truy cập đến [DOM](/bai-viet/javascript/dom-la-gi)
- Có thể dừng khi không sử dụng và chạy khi cần thiết.
- Chỉ hỗ trợ HTTPS

Với Service Worker chúng ta có thể:

- Làm cho trang web chạy nhanh hơn và có thể chạy offline
- Thực hiện một số tính năng ở background như: [push message](https://developers.google.com/web/updates/2015/03/push-notificatons-on-the-open-web) và [background synchronization](https://developers.google.com/web/updates/2015/12/background-sync).

Có lẽ đến đây thì bạn đã hiểu phần nào về JavaScript Service Worker rồi. Tiếp theo, chúng ta sẽ tìm hiểu về cách sử dụng nó.

## Đăng ký JavaScript Service Worker

Giả sử, mình có một trang web đơn giản và cấu trúc các tệp tin như sau:

```md
index.html;
service_worker.js;
main.js;
style.css;
```

Lúc này, mình sẽ đăng ký Service Worker trong file **main.js**:

```js
if ("serviceWorker" in navigator) {
  navigator.serviceWorker
    .register("service_worker.js")
    .then((reg) => {
      console.log("Registered service worker");
    })
    .catch((err) => {
      console.log("Register service worker failed", err);
    });
}
```

Có một số lưu ý quan trọng khi đăng ký Service Worker là:

- Vị trí của file **service_worker.js** quyết định đến URL của các trang mà nó điều khiển. Ở đây, mình đặt file **service_worker.js** cùng thư mục với **index.html**. Có nghĩa là Service Worker sẽ quản lý URL của toàn bộ trang web. Ngược lại, nếu mình đặt nó ở một thư mục khác, giả sử là: **/apps/service_worker.js** thì Service Worker sẽ chỉ quản lý các URL bắt đầu từ **/apps/**.
- Hàm đăng ký **.register** trả về một [Promise](https://www.tutorialspoint.com/es6/es6_promises.htm).
- Trang đăng ký Service Worker phải là HTTPS.
- Service Worker phải nằm trên cùng trang web đăng ký nó (same origin). Vì vậy, bạn không thể đặt file **service_worker.js** ở một nơi khác, rồi sử dụng [importScripts()](https://developer.mozilla.org/en-US/docs/Web/API/WorkerGlobalScope/importScripts) được.

Mình có tham khảo được một ví dụ mẫu về cách triển khai JavaScript Service Worker như sau (mình không nhớ mình tham khảo được ở đâu, chỉ nhớ là của Google, nên mong tác giả của script thông cảm):

```js
/*
 * Names of the two caches used in this version of the service worker.
 * Change to v2, etc. when you update any of the local resources, which will
 * in turn trigger the install event again.
 */
const PRECACHE = "my-precache-v1";
const RUNTIME = "my-runtime";

// A list of local resources we always want to be cached.
const PRECACHE_URLS = [
  "index.html",
  "./", // Alias for index.html
  "style.css",
  "main.js",
];

// The install handler takes care of precaching the resources we always need.
self.addEventListener("install", (event) => {
  event.waitUntil(
    caches
      .open(PRECACHE)
      .then((cache) => cache.addAll(PRECACHE_URLS))
      .then(self.skipWaiting())
  );
});

// The activate handler takes care of cleaning up old caches.
self.addEventListener("activate", (event) => {
  const currentCaches = [PRECACHE, RUNTIME];
  event.waitUntil(
    caches
      .keys()
      .then((cacheNames) => {
        return cacheNames.filter(
          (cacheName) => !currentCaches.includes(cacheName)
        );
      })
      .then((cachesToDelete) => {
        return Promise.all(
          cachesToDelete.map((cacheToDelete) => {
            return caches.delete(cacheToDelete);
          })
        );
      })
      .then(() => self.clients.claim())
  );
});

/*
 * The fetch handler serves responses for same-origin resources from a cache.
 * If no response is found, it populates the runtime cache with the response
 * from the network before returning it to the page.
 */
self.addEventListener("fetch", (event) => {
  // Skip cross-origin requests, like those for Google Analytics.
  if (event.request.url.startsWith(self.location.origin)) {
    event.respondWith(
      caches.match(event.request).then((cachedResponse) => {
        if (cachedResponse) {
          return cachedResponse;
        }

        return caches.open(RUNTIME).then((cache) => {
          return fetch(event.request).then((response) => {
            // Put a copy of the response in the runtime cache.
            return cache.put(event.request, response.clone()).then(() => {
              return response;
            });
          });
        });
      })
    );
  }
});
```

Sau khi đăng ký thành công, Service Worker sẽ được download về phía client và thực hiện những việc sau đây.

## JavaScript Service Worker - Install

Đoạn code dùng để install Service Worker:

```js
const PRECACHE = "my-precache-v1";
const RUNTIME = "my-runtime"; // A list of local resources want to be cached.
const PRECACHE_URLS = [
  "index.html",
  "./", // Alias for index.html
  "style.css",
  "main.js",
];

// The install handler takes care of precaching the resources we always need.
self.addEventListener("install", (event) => {
  event.waitUntil(
    caches
      .open(PRECACHE)
      .then((cache) => cache.addAll(PRECACHE_URLS))
      .then(self.skipWaiting())
  );
});
```

Mục đích của của việc **install** là để lưu một số resources được định nghĩa ở [array](/bai-viet/javascript/mang-array-trong-javascript) **PRECACHE_URLS** vào bộ nhớ đệm **cache** với tên định nghĩa bởi **PRECACHE**.

Sau khi lưu xong hết tất cả các resources cần thiết, hàm [self.skipWaiting()](https://developer.mozilla.org/en-US/docs/Web/API/ServiceWorkerGlobalScope/skipWaiting) dùng để dừng công việc hiện tại lại và chuyển ngay sang công việc tiếp theo.

## JavaScript Service Worker - activate

Đoạn code dùng để active Service Worker là:

```js
// The activate handler takes care of cleaning up old caches.
self.addEventListener("activate", (event) => {
  const currentCaches = [PRECACHE, RUNTIME];
  event.waitUntil(
    caches
      .keys()
      .then((cacheNames) => {
        return cacheNames.filter(
          (cacheName) => !currentCaches.includes(cacheName)
        );
      })
      .then((cachesToDelete) => {
        return Promise.all(
          cachesToDelete.map((cacheToDelete) => {
            return caches.delete(cacheToDelete);
          })
        );
      })
      .then(() => self.clients.claim())
  );
});
```

Mục đích của công việc **activate** này là để xóa đi bộ nhớ đệm **cache** cũ, và giữ lại **cache** mới nhất, cuối cùng là kích hoạt Service Worker.

Giả sử ban đầu bạn có hai cache là: **PRECACHE = my-precache-v1** và **RUNTIME**. Bây giờ, bạn muốn thay đổi resources.

**Làm sao để cập nhật được những resources mới này vào cache?**

Bạn cần thay đổi tên của **PRECACHE**, ví dụ là: **my-precache-v2**. Lúc này **currentCaches = \['my-precache-v2', RUNTIME\]**. Bây giờ chỉ cần dùng [filter](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array/filter) để lọc ra tên của cache không có trong **currentCaches**:

```js
cacheNames.filter((cacheName) => !currentCaches.includes(cacheName));
```

Đó chính là **my-precache-v1**. Tiếp theo, xóa cache này đi:

```js
.then(cachesToDelete => {
  return Promise.all(cachesToDelete.map(cacheToDelete => {
    return caches.delete(cacheToDelete);
  }));
}
```

Cuối cùng là kích hoạt Service Worker sử dụng [self.clients.claim()](https://developer.mozilla.org/en-US/docs/Web/API/Clients/claim).

Bạn có thể kiểm tra lại bằng cách nhấn **Ctrl Shift I** hoặc **F12** (tùy thuộc trình duyệt) để vào phần Công cụ dành cho nhà phát triển:

![Google Dev Tool - Check Service Worker](/static/a7c767f4cee9b8f41b639b1d619a79d5/7c811/google-dev-tool-service-worker-check.png "Google Dev Tool - Check Service Worker")

Theo như hình trên thì bạn có thể thấy là Service Worker đã được kích hoạt (**activated**) và đang chạy (**running**).

## JavaScript Service Worker - fetch

Đoạn code xử lý lệnh fetch:

```js
/*
 * The fetch handler serves responses for same-origin resources from a cache.
 * If no response is found, it populates the runtime cache with the response
 * from the network before returning it to the page.
 */
self.addEventListener("fetch", (event) => {
  // Skip cross-origin requests, like those for Google Analytics.
  if (event.request.url.startsWith(self.location.origin)) {
    event.respondWith(
      caches.match(event.request).then((cachedResponse) => {
        if (cachedResponse) {
          return cachedResponse;
        }

        return caches.open(RUNTIME).then((cache) => {
          return fetch(event.request).then((response) => {
            // Put a copy of the response in the runtime cache.
            return cache.put(event.request, response.clone()).then(() => {
              return response;
            });
          });
        });
      })
    );
  }
});
```

Đoạn code trên có thể mô tả thành lời như sau:

**Bước 1:** Khi có request từ phía client (trình duyệt): Nếu url không thuộc cùng origin (không cùng trang web) thì bỏ qua.

**Bước 2:** Ngược lại, kiểm tra trong bộ nhớ đệm cache xem đã có response tương ứng với request chưa. Nếu tồn tại, thì trả về response đó cho trình duyệt.

**Bước 3:** Ngược lại, gửi request đó lên server, rồi lấy response trả về.

**Bước 4:** Clone response đó và lưu vào **RUNTIME** cache để phục vụ cho lần request tiếp theo, rồi sau đó trả về response đó cho trình duyệt.

## Kết luận

Trên đây là những kiến thức cơ bản về JavaScript Service Worker mà mình tìm hiểu được, và còn rất nhiều vấn đề liên quan khác cần nghiên cứu thêm.

Đến đây có thể đã giải đáp được cho vấn đề đưa ra ở đầu bài viết: c*ó 2 thứ cần thiết để web app có thể chạy được là: resources (html, js, css, ảnh,...) và định tuyến*.

- Dùng listener **install** và **activate** để lưu resources vào bộ nhớ đệm cache.
- Dùng listener **fetch** để định tuyến.

Nếu bạn có **thắc mắc** gì, vui lòng để lại bình luận để mọi người có thể cùng trao đổi. Mình không hứa là sẽ giải đáp ngay cho bạn. Nhưng mình hứa sẽ tìm hiểu để giải quyết cùng bạn.

## Tham khảo

- [Service Worker API](https://developer.mozilla.org/en-US/docs/Web/API/Service_Worker_API)
- [Using Service Workers](https://developer.mozilla.org/en-US/docs/Web/API/Service_Worker_API/Using_Service_Workers)
- [Service Workers: an Introduction](https://developers.google.com/web/fundamentals/primers/service-workers/)
- [Introduction to Service Worker](https://developers.google.com/web/ilt/pwa/introduction-to-service-worker)
- [Service Worker CookBook](https://serviceworke.rs/)
- [Adding a Service Worker and Offline into your Web App](https://developers.google.com/web/fundamentals/codelabs/offline/)
- [Service Worker Explainer](https://github.com/w3c/ServiceWorker/blob/master/explainer.md)
