---
title: "HTML template sang DOM"
description: "Như đã nói trong bài viết trước, bài này mình sẽ hướng dẫn các bạn chuyển HTML Template sang DOM Node. Với phương pháp này, bạn không cần phải sử dụng DOMParser nữa, mà sẽ sử dụng trực tiếp thẻ template của HTML."
keywords: [
"HTML template sang DOM trong javascript",
"dom element trong javascript",
"chuyển HTML Template sang DOM",
"chuyển HTML Template sang DOM như thế nào trong Javascript",
"chuyển HTML Template sang DOM là gì trong Javascript",
"HTML Template",
"HTML Template là gì",
"DOM trong Javascript",
"DOM trong Javascript là gì",
"Render HTML Template",
"Render HTML Template trong Javascript"
]
chapter:
  name: "DOM"
  slug: "chuong-13-dom"
category:
  name: "Javascript"
  slug: "javascript"
image: https://kungfutech.edu.vn/thumbnail.png
position: 4
---

Như đã nói trong [bài viết trước](/bai-viet/javascript/html-string-sang-dom-node-voi-dom-parser), bài này mình sẽ hướng dẫn các bạn chuyển HTML Template sang DOM Node. Với phương pháp này, bạn không cần phải sử dụng [DOMParser](https://developer.mozilla.org/en-US/docs/Web/API/DOMParser) nữa, mà sẽ sử dụng trực tiếp thẻ template của HTML.

## HTML Template

Khi sử dụng thẻ [template](https://developer.mozilla.org/en-US/docs/Web/HTML/Element/template) này, nội dung bên trong thẻ sẽ không được render sau khi load trang web. Thay vào đó, bạn sẽ sử dụng JavaScript để render nội dung này trong quá trình chạy.

Sau đây là một ví dụ sử dụng HTML template:

[Ví dụ](https://codepen.io/completejavascript/pen/MVyXyp)

Các bạn có thể thấy nội dung của thẻ template như sau:

```html
<template id="my-temp">
  <div>
    <span class="name">a name</span>
  </div>
  <div>
    <span class="comment">a comment</span>
  </div>
</template>
```

Trong đó, thẻ template có **id="my-temp"**, để sử dụng trong JavaScript sau này. Bên trong thẻ, sẽ là một đoạn code HTML - có cấu trúc khá rõ ràng, với một phần text là **name**, và phần còn lại là **comment** (phần này mô phỏng lại việc render mục bình luận trên một bài viết).

## Chuyển HTML Template sang DOM Node với JavaScript

### Kiểm tra trình duyệt hỗ trợ Template hay không?

Trước khi sử dụng template, bạn cần kiểm tra xem trình duyệt của mình có hỗ trợ template hay không.

```js
// Check whether browser supports template
if ("content" in document.createElement("template")) {
  console.log("Support Template");
} else {
  console.log("Not Support Template");
}
```

Template có một thuộc tính quan trọng là **content**. Khi bạn tạo mới một template sử dụng [createElement](https://developer.mozilla.org/en-US/docs/Web/API/Document/createElement), thì phần tử đó phải tồn tại thuộc tính content. Nghĩa là trình duyệt có hỗ trợ template, ngược lại thì không hỗ trợ.

Khi trình duyệt có hỗ trợ template rồi. Bạn có thể tiếp tục với bước sau.

### Lấy nội dung của HTML Template

HTML template đã có sẵn ID. Vì vậy, bạn có thể sử dụng phương thức [querySelector](https://developer.mozilla.org/en-US/docs/Web/API/Document/querySelector) (hoặc [getElementById](https://developer.mozilla.org/en-US/docs/Web/API/Document/getElementById)) để lấy ra phần tử [DOM](/bai-viet/javascript/dom-la-gi) của template đó, đồng thời trích xuất ra content - dạng [DocumentFragment](https://developer.mozilla.org/en-US/docs/Web/API/DocumentFragment).

```js
let templateFrag = document.querySelector("#my-temp").content;
```

DocumentFragment là một dạng document tối giản - không có parent. Vì vậy, bạn có thể trực tiếp thêm nó vào giao diện HTML của mình.

### Render HTML Template lên giao diện

Trong bước này, mình muốn mô phỏng lại việc render các bình luận trên một bài viết. Nội dung các bình luận là một [mảng](/bai-viet/javascript/mang-array-trong-javascript) của các [object](/bai-viet/javascript/object-la-gi-object-trong-javascript) - bao gồm 2 thuộc tính là name và comment.

```js
let data = [
  { name: "John", comment: "That is great" },
  { name: "Alex", comment: "It's helpful" },
  { name: "David", comment: "Thanks a lot" },
];
```

Khi người dùng nhấn vào button **Add**, mình sẽ sử dụng phương thức [forEach](/bai-viet/javascript/tim-hieu-ve-foreach-trong-javascript) để duyệt mảng trên. Với mỗi phần tử của mảng, ta [clone](https://developer.mozilla.org/en-US/docs/Web/API/DOMParser) lại template DocumentFragment trên để dùng lại sau này.

Tiếp theo, để apply nội dung của bình luận vào template, bạn có thể tiếp tục sử dụng phương thức querySelector để thay đổi nội dung trong span với class là name, content tương ứng với nội dung trong mảng, rồi thêm nó vào bên trong thẻ div với **id="container"**.

```js
btnAdd.addEventListener("click", () => {
  data.forEach((item) => {
    let tmpl = templateFrag.cloneNode(true);
    tmpl.querySelector(".name").innerText = item.name;
    tmpl.querySelector(".comment").innerText = item.comment;
    container.appendChild(tmpl);
  });
});
```

Cuối cùng, để xóa đi các thành phần [DOM](/bai-viet/javascript/dom-la-gi) mới thêm vào. Bạn có thể sử dụng vòng lặp, liên tục xóa đi phần tử con đầu tiên của container, cho đến khi container không còn node con nào nữa là hoàn thành nhiệm vụ.

```js
btnRm.addEventListener("click", () => {
  while (container.firstChild) {
    delete container.removeChild(container.firstChild);
  }
});
```

<content-warning>

**Chú ý:** Nhắc lại đối với các bạn chưa đọc bài viết trước của mình, nếu bạn chỉ sử dụng phương thức [removeChild](https://developer.mozilla.org/en-US/docs/Web/API/DOMParser) mà không delete thì sẽ dẫn đến leak memory.

</content-warning>

## Kết luận

Trên đây, mình đã giới thiệu với các bạn cách chuyển HTML Template sang DOM Node, đồng thời thay đổi nội dung của template ứng với data - lưu trong JavaScript. Hy vọng với phương pháp này, bạn có thể áp dụng template cho các project của mình. Bài viết sau, mình sẽ giới thiệu với các bạn một thư viện rất hay - chuyên dùng để render HTML template.

Hẹn gặp lại bạn ở [bài viết tiếp theo](/mustache-template-voi-jquery/), thân ái!
