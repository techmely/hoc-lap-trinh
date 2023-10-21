---
title: "Thêm React vào ứng dụng của bạn"
description: "Nếu bạn muốn thêm tính năng tương tác vào dự án hiện tại của mình, bạn không cần phải viết lại nó bằng React. Hãy thêm React vào ngăn xếp công nghệ hiện tại của bạn và hiển thị các thành phần React tương tác bất cứ đâu"
chapter:
  name: "Cài đặt"
  slug: "chuong-02-cai-dat-reactjs"
image: https://kungfutech.edu.vn/thumbnail.png
position: 2
---

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

## Bước 1: Thiết lập môi trường JavaScript module hóa

Môi trường JavaScript module hóa cho phép bạn viết các thành phần React của bạn trong các tệp riêng lẻ, thay vì viết toàn bộ mã của bạn trong một tệp duy nhất. Nó cũng cho phép bạn sử dụng tất cả các gói tuyệt vời được xuất bản bởi các nhà phát triển khác trên npm registry - bao gồm cả React! Cách bạn thực hiện điều này phụ thuộc vào cài đặt hiện có của bạn:

- Nếu ứng dụng của bạn đã được chia thành các tệp sử dụng câu lệnh import, hãy thử sử dụng cài đặt bạn đã có. Kiểm tra xem việc viết `<div />` trong mã JS của bạn có gây ra lỗi cú pháp không. Nếu nó gây ra lỗi cú pháp, bạn có thể cần biến đổi mã JavaScript của mình bằng Babel và kích hoạt Babel React preset để sử dụng JSX.

- Nếu ứng dụng của bạn chưa có cài đặt hiện có cho việc biên dịch các module JavaScript, hãy thiết lập nó bằng Vite. Cộng đồng Vite duy trì nhiều tích hợp với các framework backend, bao gồm Rails, Django và Laravel. Nếu framework backend của bạn không được liệt kê, hãy tuân theo hướng dẫn này để tích hợp xây dựng Vite vào backend của bạn.

Để kiểm tra xem cài đặt của bạn có hoạt động không, hãy chạy lệnh sau trong thư mục dự án của bạn:

```bash
npm install react react-dom
```

Sau đó, thêm các dòng mã sau vào đầu tệp JavaScript chính của bạn (có thể được gọi là index.js hoặc main.js):

```javascript
import { createRoot } from "react-dom/client";

// Xóa nội dung HTML hiện có
document.body.innerHTML = '<div id="app"></div>';

// Hiển thị thành phần React của bạn thay vì
const root = createRoot(document.getElementById("app"));
root.render(<h1>Hello, world</h1>);
```

Nếu toàn bộ nội dung của trang của bạn bị thay thế bằng một "Hello, world!", điều đó có nghĩa là mọi thứ đã hoạt động! Hãy tiếp tục đọc.

## Bước 2: Hiển thị các thành phần React bất kỳ nơi nào trên trang

Trong bước trước, bạn đã đặt mã này ở đầu tệp chính của bạn:

```javascript
import { createRoot } from "react-dom/client";

// Xóa nội dung HTML hiện có
document.body.innerHTML = '<div id="app"></div>';

// Hiển thị thành phần React của bạn thay vì
const root = createRoot(document.getElementById("app"));
root.render(<h1>Hello, world</h1>);
```

Tất nhiên, bạn thực sự không muốn xóa nội dung HTML hiện có!

Hãy xóa mã này.

Thay vào đó, bạn có thể muốn hiển thị các thành phần React của bạn ở các vị trí cụ thể trong trang HTML của bạn. Mở trang HTML của bạn (hoặc các mẫu máy chủ tạo ra nó) và thêm một thuộc tính id duy nhất vào bất kỳ thẻ nào, ví dụ:

```html
<!-- ... đâu đó trong trang html của bạn ... -->
<nav id="navigation"></nav>
<!-- ... thêm nhiều html khác ... -->
```

Điều này cho phép bạn tìm thấy phần tử HTML đó bằng document.getElementById và truyền nó cho createRoot để bạn có thể hiển thị thành phần React của riêng bạn bên trong:

```javascript
import { createRoot } from "react-dom/client";

function NavigationBar() {
  // TODO: Thực sự triển khai thanh điều hướng
  return <h1>Hello from React!</h1>;
}

const domNode = document.getElementById("navigation");
const root = createRoot(domNode);
root.render(<NavigationBar />);
```

Lưu ý cách nội dung HTML gốc từ index.html được bảo toàn, nhưng thành phần React NavigationBar của bạn hiện xuất hiện trong `<nav id="navigation">` từ trang HTML của bạn. Đọc tài liệu sử dụng createRoot để tìm hiểu thêm về cách hiển thị các thành phần React bên trong trang HTML hiện có của bạn.

Khi bạn áp dụng React vào một dự án hiện có, điều phổ biến là bắt đầu bằng các thành phần tương tác nhỏ (như các nút), sau đó dần dần "di chuyển lên" cho đến cuối cùng trang web của bạn được xây dựng bằng React. Nếu bạn bao giờ đạt được điểm đó, chúng tôi đề xuất chuyển sang một framework React ngay sau đó để tận dụng tối đa tính năng của React.

## Sử dụng React Native trong ứng dụng di động native hiện có

React Native cũng có thể được tích hợp vào các ứng dụng native hiện có một cách tăng dần. Nếu bạn có ứng dụng native hiện có cho Android (Java hoặc Kotlin) hoặc iOS (Objective-C hoặc Swift), hãy làm theo hướng dẫn này để thêm một màn hình React Native vào đó.
