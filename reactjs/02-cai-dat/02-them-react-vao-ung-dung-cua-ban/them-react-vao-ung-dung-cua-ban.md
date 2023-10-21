---
title: "Thêm React vào ứng dụng của bạn"
description: "Nếu bạn muốn thêm tính năng tương tác vào dự án hiện tại của mình, bạn không cần phải viết lại nó bằng React. Hãy thêm React vào ngăn xếp công nghệ hiện tại của bạn và hiển thị các thành phần React tương tác bất cứ đâu"
chapter:
  name: "Cài đặt"
  slug: "chuong-02-cai-dat-reactjs"
image: https://kungfutech.edu.vn/thumbnail.png
position: 2
---

::alert{type="infor"}
Nếu bạn chưa có trang web của mình hoặc bạn là người mới tiếp cận với Reactjs thì bạn có thể bỏ qua bài này!
::

Thông thường chúng ta hay [tạo một dự án ReactJS](/bai-viet/reactjs/khoi-tao-du-an-reactjs) riêng biệt để xây dựng một website hoàn chỉnh.

Tuy nhiên, bạn quên mất rằng, bản chất ReactJS chỉ là một thư viện front end, giúp xây dựng giao diện trang web được đơn giản hơn.

Do vậy, xét về khía cạnh tích hợp, việc sử dụng ReactJS hoàn toàn tương tự như cách mà bạn vẫn hay sử dụng các thư viện UI như `bootstrap`, `jQuery`… mà thôi.

Với một dự án rất lớn được xây dựng trên một công nghệ nào đó, ví dụ như `Asp.net`, `Java Spring`, hay `NodeJS`… Trong khi bạn muốn kiểm tra hoặc thêm giao diện cho một tính năng nào đó mà không làm ảnh hưởng tới toàn bộ dự án.

Trong trường hợp này, bạn có thể sử dụng ReactJS để xây dựng giao diện cho tính năng đó mà không ảnh hưởng tới phần còn lại. Thực chất, Reactjs ra đời là để giải quyết những vấn đề như thế này. Nên là, việc tích hợp rất là đơn giản.

## Sử dụng React cho một phần của trang web hiện tại của bạn

Để minh họa, giả sử chúng ta có một dự án web nhỏ với tính năng cho phép đăng bài viết và viết bình luận cho bài viết đó.

Đầu tiên, mình cứ tạo một file `index.html` trong thư mục dự án. Trong thực tế, `index.html` là file gốc của dự án nên có thể sẽ có nhiều mã html của những tính năng khác.

Giả sử index.html đã có mã nguồn như sau:

```html
<div class="post-container">
  <h1 class="post-header">T-shirt for sale</h1>
    <div class="post-body">
      <img src="t-shirt.jpg" alt="img" width="300px" height="300px" />
    </div>
</div>
```

## Tích hợp Reactjs vào trang web của bạn

Chỉ cần thêm một thẻ html với một unique ID, ví dụ:

```html
<div id="post-comments-root">
    <!--This is a react root node-->
</div>
```

Tiếp theo, chúng ta thêm thư viện ReactJS vào cuối của thẻ `<body>`. Khi nào deploy dự án, bạn nhớ thay `react.development.js` thành `react.production.js`

```js
<script src="https://unpkg.com/react@18/umd/react.development.js" crossorigin></script>
<script src="https://unpkg.com/react-dom@18/umd/react-dom.development.js" crossorigin></script>
```

Để có thể sử dụng được cú pháp JSX, bạn cần phải cài thêm thư viện babel. Nếu không, bạn sẽ phải sử dụng cú pháp ES5 thông thường, ví dụ: sử dụng `React.createElement()` để trả về một [react component](/bai-viet/reactjs/component-trong-react-la-gi).

```js
<script src="https://unpkg.com/@babel/standalone/babel.min.js"></script>
```

Như vậy là bạn đã cài đặt thư viện ReactJS vào dự án website có sẵn xong rồi đấy. Phần tiếp theo hoàn toàn tương tự như cách mà chúng ta vẫn thực hiện khi làm việc với ReactJS thôi. Đó là tạo một component.

Chúng ta sẽ tạo một `Post component` (đặt tên file là `post-comments.js`), sau đó chèn vào trong `index.html` là được.

```js
<script src="react/components/post-comments.js" type="text/babel"></script>
```

Phần nội dung của `Post component` cụ thể như nào thì mình không viết cụ thể ra đây nhé. Bài viết này mình chỉ tập trung vào cách tích hợp ReactJS mà thôi.

Sau khi hoàn thành viết code cho các component xong, truy xuất root React DOM trong `index.html` sử dụng id: `post-comments-root` và render root element sử dụng API: `createRoot()` tương tự như cách mà bạn vẫn làm trong các dự án React

```js
const domNode = document.getElementById("post-comments-root");
const root = ReactDOM.createRoot(domNode);
root.render(<PostComments />);
```

Như vậy là đã xong! Như vậy là bạn đã tích hợp xong React vào một dự án website đã có sẵn. Công việc tiếp theo thì bạn vẫn code React như bình thường thôi.
