---
title: "Ứng dụng reduce trong mảng"
description: "JavaScript Reduce là một phương thức có sẵn của array, được sử dụng để gọi một hàm lên các phần tử của mảng (từ trái sang phải) với một biến tích lũy. Kết quả trả về là một giá trị duy nhất, ứng với biến tích lũy."
keywords: ["Ứng dụng reduce trong mảng",
"reduce trong javascript",
"reduce javascript",
"reduce in es6 javascript",
"ham reduce trong javascript",
"ham reduce trong javascript la gi",
"ham reduce trong javascript co tac dung gi",
"cach su dung ham reduce trong javascript",
"cach su dung reduce trong javascript",
"Reduce anonystick trong javascript"
]
chapter:
  name: "Kiểu dữ liệu trong Javascript"
  slug: "chuong-04-kieu-du-lieu-trong-javascript"
category:
  name: "Javascript"
  slug: "javascript"
image: https://user-images.githubusercontent.com/29374426/168244791-cd8329c4-6a81-4801-b7ae-0846859d3912.png
position: 20
---

Trước khi bắt đầu, mình muốn bạn hiểu tại sao mình lại viết về phương thức Reduce trong JavaScript mà không phải là một phương thức nào khác.

![Ứng dụng reduce trong mảng](https://user-images.githubusercontent.com/29374426/168244791-cd8329c4-6a81-4801-b7ae-0846859d3912.png)


Bởi lẽ, reduce trong JS là một trong 3 phương thức quan trọng và thường **sử dụng trong lập trình hàm** - đó là [`arr.map()`](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array/map), [`arr.filter()`](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array/filter) và [`arr.reduce()`](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array/Reduce).

Việc sử dụng đúng `arr.reduce()` giúp code trở nên sáng sủa và ngắn gọn hơn rất nhiều.

> Có thể bạn quan tâm: [Các phương thức của mảng trong JavaScript](/bai-viet/javascript/phuong-thuc-trong-javascript).

## Cú pháp của `reduce` trong JavaScript

JavaScript Reduce là một phương thức có sẵn của array, được sử dụng để gọi một [hàm](/bai-viet/javascript/ham-trong-javascript) lên các phần tử của [mảng](/bai-viet/javascript/mang-array-trong-javascript) (từ trái sang phải) với **một biến tích lũy**.

Kết quả trả về là một giá trị duy nhất, ứng với biến tích lũy.

Cú pháp của reduce trong JS:

```js
    arr.reduce(callback[, initialValue])

```

Trong đó:

- `callback`: là hàm được gọi với mỗi phần tử của mảng, gồm 4 tham số:
  - `accumulator`: biến tích lũy, được trả về sau mỗi lần gọi hàm `callback`.
  - `currentValue`: phần tử của mảng đang được xử lý.
  - `currentIndex`: chỉ số của phần tử trong mảng đang được xử lý.
  - `array`: mảng hiện tại.
- `initialValue`: là giá trị khởi tạo cho biến tích lũy `accumulator` của hàm `callback` trong lần gọi đầu tiên. Nếu giá trị này **không được cung cấp** thì **giá trị phần tử đầu tiên** của mảng được sử dụng.
- **Giá trị trả về**: chính là giá trị của `accumulator` sau lần gọi hàm `callback` cuối cùng.

Trên đây là giới thiệu cơ bản về phương thức `arr.reduce()`. Tiếp theo, mình sẽ giới thiệu một số ứng dụng của Reduce trong JavaScript.

## Ứng dụng của Reduce trong JavaScript

Dưới đây là một số ứng cụng của Reduce trong JS.

### Chuyển mảng 2 chiều thành mảng 1 chiều

► **Đặt vấn đề**

Giả sử, mình có một mảng các chủ đề trên blog, với mỗi chủ đề lại chứa một mảng các bài viết như sau:

```js
const topics = [
  {
    topic: "ReactJS",
    posts: [
      { postID: "id1", title: "title1" },
      { postID: "id2", title: "title2" },
    ],
  },
  {
    topic: "Vue.js",
    posts: [
      { postID: "id3", title: "title3" },
      { postID: "id4", title: "title4" },
    ],
  },
];
```

Bây giờ, mình muốn có một **mảng các bài viết** để hiển thị thành một danh sách. Vậy mình phải làm sao?

► **Ứng dụng JavaScript Reduce để giải quyết vấn đề**

**Cách đầu tiên** mà mọi người thường suy nghĩ đến là sử dụng [vòng lặp for](/bai-viet/javascript/vong-lap-trong-javascript):

```js
// khai báo mảng rỗng để lưu kết quả
const allPosts = [];

// duyệt mảng các topics
for (let t = 0; t < topics.length; t++) {
  // lấy ra các posts với từng topic
  const posts = topics[t].posts;

  // sử dụng vòng lặp for để duyệt mảng posts
  for (let p = 0; p < posts.length; p++) {
    // lấy ra từng post
    const post = posts[p];

    // push vào mảng kết quả
    allPosts.push(post);
  }
}

// kết quả
console.log(allPosts);
/*
    [
        { postID: "id1", title: "title1" },
        { postID: "id2", title: "title2" },
        { postID: "id3", title: "title3" },
        { postID: "id4", title: "title4" }
    ]
    */
```

Cách làm trên là suy nghĩ logic cơ bản của hầu hết mọi người. Vì đó là **cách làm nguyên thủy** - chỉ dựa vào vòng lặp `for`.

Tuy nhiên, cách làm trên khá dài dòng. Thay vào đó, bạn có thể áp dụng reduce trong JS như sau:

```js
const allPosts = topics.reduce((acc, cur) => {
  // tại mỗi phần tử, lấy ra posts để chèn thêm vào mảng tích lũy
  // sử dụng cú pháp spread ...
  return [...acc, ...cur.posts];
}, []);
```

Trong đó, `initialValue` là một mảng rỗng `[]` (tương đương với mảng `allPosts = []` ở trên).

Và khi thực thi hàm `callback` với mỗi phần tử của mảng `topics` thì:

- Với lượt đầu tiên: `acc = []` và `cur` ứng với phần tử đầu tiên (về `ReactJS`) nên:

```js
// giá trị tích lũy là mảng rỗng
  acc = [];

  // phần tử đang duyệt là một mảng
  cur.posts = [
  { postID: 'id1', title: 'title1' },
  { postID: 'id2', title: 'title2' },
  ]

  // thêm các posts của phần tử đang duyệt
  // vào giá trị tích lũy hiện tại thành mảng mới
  // rồi gán lại cho biến tích lũy acc
  acc = [...acc, ...cur.posts] = [
  { postID: 'id1', title: 'title1' },
  { postID: 'id2', title: 'title2' },
  ]

- Với lượt tiếp theo:

  // giá trị tích lũy hiện tại
  acc = [
  { postID: 'id1', title: 'title1' },
  { postID: 'id2', title: 'title2' },
  ]

  // phần tử đang duyệt
  cur.posts = [
  { postID: 'id3', title: 'title3' },
  { postID: 'id4', title: 'title4' },
  ]

  // thêm các posts của phần tử đang duyệt
  // vào giá trị tích lũy hiện tại thành mảng mới
  // rồi gán lại cho biến tích lũy acc
  acc = [...acc, ...cur.posts] = [
  { postID: 'id1', title: 'title1' },
  { postID: 'id2', title: 'title2' },
  { postID: 'id3', title: 'title3' },
  { postID: 'id4', title: 'title4' },
  ]
```

**Chú ý:** cách viết `[...acc, ...cur.posts]` là cách ghép mảng sử dụng [cú pháp spread](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Operators/Spread_syntax) `...`.

Rõ ràng, nhờ ứng dụng của Reduce trong JavaScript mà code trở nên ngắn gọn hơn rất nhiều mà vẫn dễ hiểu.

### Chuyển array thành object theo giá trị của một thuộc tính

► **Đặt vấn đề**

Giả sử, mình có danh sách các bài viết như trên. Và mình muốn lấy tiêu đề bài viết (`title`) ứng với giá trị của một `postID` nào đó.

```js
const posts = [
  { postID: "id1", title: "title1" },
  { postID: "id2", title: "title2" },
  { postID: "id3", title: "title3" },
  { postID: "id4", title: "title4" },
];

const getPost = (postID, posts) => {
  // TODO: triển khai sau
};

// Thực hiện truy vấn
getPost("id1", posts).title; // title1
getPost("id2", posts).title; // title2
getPost("id3", posts).title; // title3
getPost("id4", posts).title; // title4
```

Vậy mình phải làm sao đây?

► **Ứng dụng JavaScript Reduce để giải quyết vấn đề**

Tiếp tục với cách suy nghĩ logic cơ bản là sử dụng vòng lặp `for`.

Với mỗi bài viết, mình so sánh `postID` với giá trị cần tìm. Mình sẽ duyệt lần lượt từng phần tử cho đến khi **tìm đúng bài viết** thì thôi.

```js
// hàm getPost
const getPost = (postID, posts) => {
  // dùng vòng lặp for để duyệt hết các bài viết
  for (let p = 0; p < posts.length; p++) {
    // lấy từng post
    const post = posts[p];

    // so sánh postID của từng post với tham số postID truyền vào
    if (post.postID === postID) {
      // nếu bằng thì trả về post hiện tại
      return post;
    }
  }

  // nếu không tìm thấy thì giá trị trả về mặc định là null
  return null;
};
```

Đây cũng là một cách làm hay và dễ hiểu bởi cách **suy nghĩ trực tiếp** vào bài toán.

Tuy nhiên, cách làm này có một vấn đề là: nếu mảng các bài viết không phải 4 phần tử mà là **hàng nghìn, hàng triệu phần tử** thì việc dùng vòng lặp `for` để duyệt mảng với mỗi lần truy vấn thật sự rất tốn thời gian - độ phức tạp thuật toán là **O(N)**.

Cách giải quyết cho vấn đề trên là: xây dựng một [object](/bai-viet/javascript/object-la-gi-object-trong-javascript) để map mỗi `postID` với giá trị tương ứng của bài viết.

Và khi đã có một object như vậy thì việc tìm kiếm sẽ vô cùng đơn giản.

```js
// Object để map mỗi postID với mỗi post tương ứng
const dictionary = {
  id1: { postID: "id1", title: "title1" },
  id2: { postID: "id2", title: "title2" },
  id3: { postID: "id3", title: "title3" },
  id4: { postID: "id4", title: "title4" },
};

const getPost = (postID, dictionary) => {
  return dictionary[postID];
};

// Thực hiện truy vấn
getPost("id1", dictionary).title; // title1
getPost("id2", dictionary).title; // title2
getPost("id3", dictionary).title; // title3
getPost("id4", dictionary).title; // title4
```

Vấn đề bây giờ là làm sao xây dựng được object `dictionary` như trên?

Dĩ nhiên, bạn vẫn có thể sử dụng vòng lặp `for` như sau:

```js
// object để lưu map các post
const dictionary = {};

// duyệt các posts
for (let p = 0; p < posts.length; p++) {
  // lấy ra post
  const post = posts[p];

  // lấy ra postID
  const postID = post.postID;

  // map postID -> post
  dictionary[postID] = post;
}
```

Khi ứng dụng reduce trong JS, cách làm sẽ **ngắn gọn hơn**:

```js
const dictionary = posts.reduce((acc, cur) => {
  // lấy ra postID của từng phần tử
  const postID = cur.postID;

  // sử dụng cú pháp spread (...)
  // để tạo object mới chứa object tích lũy acc
  // và thuộc tính mới [postID]: cur
  return { ...acc, [postID]: cur };
}, {});
```

Trong đó, `initialValue` là một object rỗng `{}`.

Và khi thực thi hàm callback với mỗi phần tử của mảng `posts` thì:

- Với lượt đầu tiên: `acc = {}` và `cur` ứng với post đầu tiên nên:

```js
// giá trị tích lũy đầu tiên là object rỗng
  acc = {};

  // phần tử hiện tại đang xét
  cur = { postID: "id1", title: "title1" };
  postID = cur.postID = "id1";

  // tạo object mới bằng cách sử dụng cú pháp spread (...)
  // để ghép object acc hiện tại và thuộc tính mới [postID]: cur
  acc = {...acc, [postID]: cur } = {
  'id1': { postID: 'id1', title: 'title1' }
  }
```

- Với lần thứ 2:

```js
// giá trị tích lũy hiện tại sau lần thứ nhất
  acc = {
  'id1': { postID: 'id1', title: 'title1' }
  };

  // phần tử đang xét
  cur = { postID: "id2", title: "title2" };
  postID = cur.postID = "id2";

  // tạo object mới bằng cách sử dụng cú pháp spread (...)
  // để ghép object acc hiện tại và thuộc tính mới [postID]: cur
  acc = {...acc, [postID]: cur } = {
  'id1': { postID: 'id1', title: 'title1' },
  'id2': { postID: 'id2', title: 'title2' }
  }
```

Cứ như vậy cho đến hết thì mình thu được kết quả như mong muốn là giá trị trả về của reduce.

## Tổng kết

Trên đây là một số ứng dụng của Reduce trong JavaScript:

- Chuyển mảng 2 chiều thành mảng một chiều
- Chuyển array thành object theo giá trị của một thuộc tính

Còn nhiều ứng dụng khác của array nữa mà bạn sẽ gặp trong thời gian lập trình với JavaScript.
