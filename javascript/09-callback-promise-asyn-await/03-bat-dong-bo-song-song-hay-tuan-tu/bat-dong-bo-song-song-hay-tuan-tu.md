---
title: "Bất đồng bộ song song hay tuần tự?"
description: "Khi bạn có một chuỗi các hành động thì câu hỏi đặt ra là: bạn sẽ xử lý chúng như thế nào? Bạn quyết định xử lý bất đồng bộ song song hay tuần tự."
keywords: [
"Bất đồng bộ song song hay tuần tự?",
"Bất đồng bộ song song hay tuần tự là gì trong javascript",
"Bất đồng bộ là gì trong javascript",
"Bất đồng bộ trong javascript",
"tuần tự là gì trong javascript",
"Thế nào là tuần tự là gì trong javascript",
"Xử lí bất đồng bộ song song trong javascript",
"async await trong javascript",
"xu ly bat dong bo asyncawait trong javascript",
"xử lý song song",
"xử lý tuần tự"
]
chapter:
  name: "Callback, Promise, async/await"
  slug: "chuong-09-callback-promise-asyn-await"
category:
  name: "Javascript"
  slug: "javascript"
image: https://kungfutech.edu.vn/thumbnail.png
position: 3
---

Có thể bạn đã quen với việc [xử lý bất đồng bộ](/bai-viet/javascript/bat-dong-bo-voi-callback-promise-asyn-await) trong JavaScript với Promise hoặc Async/await rồi. Tuy nhiên, khi bạn có một chuỗi các hành động thì câu hỏi đặt ra là: bạn sẽ xử lý chúng như thế nào? Bạn quyết định xử lý bất đồng bộ song song hay tuần tự?

Câu trả lời có lẽ sẽ phụ thuộc vào từng trường hợp. Tuy nhiên, để biết được nên lựa chọn cách nào thì bạn cần phải biết ý nghĩa và cách triển khai của từng trường hợp.

Bài viết này sẽ giới thiệu với bạn về 2 cách xử lý bất đồng bộ. Mời bạn theo dõi bài viết!

## Định nghĩa bài toán

Giả sử, mình có **một công việc** bất đồng bộ là: lấy thông tin bài viết (**getPost**). Công việc này bao gồm **3 hành động** bất đồng bộ là:

- Lấy nội dung bài viết (**getContent**)
- Lấy nội dung phần bình luận (**getComments**)
- Lấy danh sách các bài viết liên quan (**getRelatedPosts**)

```js
const wait = (ms) => {
  return new Promise((res) => setTimeout(res, ms));
};

const getContent = async () => {
  await wait(1000);
  return "This is content";
};

const getComments = async () => {
  await wait(1500);
  return ["comment 1", "comment 2"];
};

const getRelatedPosts = async () => {
  await wait(2000);
  return ["post 2", "post 3", "post 4"];
};

const getPost = async () => {
  // TODO: Implement later
};
```

Với công việc như trên, mình sẽ thử triển khai theo cách xử lý bất đồng bộ tuần tự và cách xử lý bất đồng bộ song song, sau đó sẽ kiểm tra xem cách nào tốt hơn nhé!

## Xử lý bất đồng bộ tuần tự

Với cách này, 3 hành động **getContent**, **getComments** và **getRelatedPosts** sẽ thực hiện tuần tự nhau. Nếu sử dụng async/await thì kết quả sẽ như sau:

```js
const getPost = async () => {
  console.time("time");

  const content = await getContent();
  const comments = await getComments();
  const relatedPosts = await getRelatedPosts();

  console.log(`Post Info: `, { content, comments, relatedPosts });
  console.timeEnd("time");
};

getPost();
/*
    Post Info:
    {
      comments:  ["comment 1", "comment 2"]
      content: "This is content"
      relatedPosts: ["post 2", "post 3", "post 4"]
    }
    time: 4504.9638671875ms
    */
```

Trong ví dụ trên, mình sử dụng [console.time và console.timeEnd](/bai-viet/javascript/su-dung-console-hieu-qua) để tính toán thời gian thực hiện. Kết quả thu được cỡ **4500 ms**. Đó chính là **tổng thời gian thực hiện của 3 hành động**.

**Cụ thể:**

```js
time(getPost) = time(getContent) + time(getComments) + time(getRelatedPosts)
    = 1000 + 1500 + 2000
    = 4500 (ms)
```

## Xử lý bất đồng bộ song song

Với cách này, 3 hành động **getContent**, **getComments** và **getRelatedPosts** sẽ thực hiện gần như là song song với nhau. Để thực hiện việc này, mình sẽ áp dụng [Promise.all](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Promise/all) vào đây và kết quả thu được như sau:

```js
const getPost = async () => {
  console.time("time");

  const [content, comments, relatedPosts] = await Promise.all([
    getContent(),
    getComments(),
    getRelatedPosts(),
  ]);

  console.log(`Post Info: `, { content, comments, relatedPosts });
  console.timeEnd("time");
};

/*
    Post Info:
    {
      comments:  ["comment 1", "comment 2"]
      content:  "This is content"
      relatedPosts:  ["post 2", "post 3", "post 4"]
    }
    time: 2001.398193359375ms
    */
```

Trong ví dụ trên, mình đưa 3 hành động bất đồng bộ vào một [mảng](/bai-viet/javascript/mang-array-trong-javascript), rồi truyền nó vào Promise.all. Tiếp theo, mình thực hiện **await** với phương thức này để đợi kết quả trả về.

Sau khi hàm trên kết thúc, mình dùng [Destructuring Assignment](/bai-viet/javascript/destructuring-assignment-trong-javascript) để lấy ra kết quả như mong muốn, theo đúng thứ tự truyền vào của các hành động bên trong Promise.all.

Với cách này, thời gian thực hiện cỡ **2000 ms**. Đó chính là **thời gian thực hiện lớn nhất của 3 hành động**.

**Cụ thể:**

```js
time(getPost) = Max of [time(getContent), time(getComments), time(getRelatedPosts)]
    = Max of [1000, 1500, 2000]
    = 2000
```

## Lời kết

Trên đây mình đã giới thiệu với bạn 2 cách xử lý bất đồng bộ song song và tuần tự rồi. Trong bài toán trên, 3 hành động là hoàn toàn độc lập nhau. Do đó, nếu làm thực tế thì mình sẽ lựa chọn xử lý bất đồng bộ song song. Vì thời gian thực hiện là ngắn hơn đáng kể so với cách xử lý bất đồng bộ tuần tự. Ngược lại, chỉ khi nào các hành động phụ thuộc lẫn nhau thì mình mới sử dụng cách xử lý bất đồng bộ tuần tự mà thôi.

_Bạn đã biết cách xử lý bất đồng bộ song song chưa? Và nếu bạn đã từng làm nó rồi thì cách thực hiện của bạn là gì? Ngoài cách sử dụng Promise.all như trên thì còn cách nào nữa không? Chia sẻ với mình và mọi người trong phần bình luận nhé!_

Xin chào và hẹn gặp lại, thân ái!
