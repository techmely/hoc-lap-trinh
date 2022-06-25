---
title: "Clipboard với exec command"
description: "Copy nội dung trên web page vào clipboard."
keywords: [
"Clipboard với exec command trong javascript",
"clipboard voi exec command line trong javascript",
"Copy nội dung trên web page vào clipboard trong javascript",
"Giao tiếp với clipboard sử dụng execCommand trong javascript",
"tao nut copy trong html trong javascript",
"Sao chép vào clipboard trong javascript"
]
chapter:
  name: "DOM"
  slug: "chuong-13-dom"
category:
  name: "Javascript"
  slug: "javascript"
image: https://kungfutech.edu.vn/thumbnail.png
position: 5
---

Khi nói đến việc copy dữ liệu vào clipboard thì không thể không kể đến thư viện [clipboard.js](https://clipboardjs.com/) - với hơn [24000 star trên Github](https://github.com/zenorocha/clipboard.js/), dung lượng sau nén khoảng 3kb, không phụ thuộc vào Flash và bất kỳ một framework nào, thì đây đúng là một thư viện rất đáng để sử dụng. Tuy nhiên, bạn cũng vẫn có thể trực tiếp giao tiếp với clipboard sử dụng execCommand một cách đơn giản.

Thực tế, [Document.execCommand()](https://developer.mozilla.org/en-US/docs/Web/API/Document/execCommand) hỗ trợ rất nhiều các command khác nhau như: _copy, cut, paste, bold, italic, createLink, fontName, fontSize,..._ Tuy nhiên, bài viết này mình sẽ chỉ đề cập vào 2 phương thức chính giao tiếp với clipboard là: _copy, cut_ (phương thức _paste_ hiện tại không support trên web nên mình sẽ không trình bày).

## Ví dụ giao tiếp với clipboard sử dụng execCommand

[](https://codepen.io/completejavascript/pen/mQWJWj)

Trong ví dụ trên, bạn có thể copy dữ liệu bằng cách nhấn vào button **Copy Text**. Sau đó, nội dung dòng text sẽ được copy vào clipboard. Tiếp theo bạn có thể test bằng cách nhấn tổ hợp **Ctrl + V** vào bất cứ chỗ nào cho phép gõ text như: phần textarea trong demo, thanh ghi địa chỉ address của trình duyệt, notepad,...

Với **Cut Text**, bạn cũng có thể làm tương tự để test.

Sau khi đã chạy thử demo xong, dưới đây là phần giải thích chi tiết từng phần.

## Copy dữ liệu vào Clipboard

Nội dung phần **html**:

```html
<h3>Copy</h3>
<p id="content-copy">This text will be inserted into the clipboard.</p>
<button id="button-copy">Copy Text</button>
```

Trong đó, thẻ _p_ với id _content-copy_ là thành phần chứa nội dung mình muốn copy; button với id _button-copy_ để kích hoạt lệnh _copy_ khi người dùng click vào.

<content-warning>

**Chú ý**: bạn có thể copy dữ liệu từ hầu hết các phần tử như: _thẻ p, span, div, input, textarea,..._ Nhưng trong ví dụ này, mình chỉ demo với thẻ _p_.

</content-warning>

Tiếp theo, mình dùng [querySelector](https://developer.mozilla.org/en-US/docs/Web/API/Document/querySelector) để lưu lại [DOM node](/bai-viet/javascript/dom-la-gi) của các phần tử:

```js
const $ = document.querySelector.bind(document);
const contentCopyElm = $("#content-copy"),
  buttonCopyElm = $("#button-copy");
```

Sau đó, định nghĩa một [hàm số](/bai-viet/javascript/ham-trong-javascript) để kiểm tra xem command mình sử dụng có được support hay không, thông qua phương thức [document.queryCommandSupported()](https://developer.mozilla.org/en-US/docs/Web/API/Document/queryCommandSupported):

```js
const isSupported = (cmd) => {
  return document.queryCommandSupported(cmd);
};
```

Cuối cùng, xử lý khi người dùng click vào button **Copy Text**:

```js
buttonCopyElm.addEventListener("click", () => {
  // Khai báo đối tượng range và selection.
  const range = document.createRange(),
    selection = window.getSelection();

  // Xoá bỏ các vùng chọn hiện tại
  selection.removeAllRanges();

  // Mô phỏng việc select - bôi đen nội dung của phần tử contentCopyElm
  range.selectNodeContents(contentCopyElm);

  // Thêm range trên vào selection
  selection.addRange(range);

  // Thử lệnh copy
  try {
    if (isSupported("copy")) document.execCommand("copy");
    else alert(`execCommand("copy") is not supported in your browser.`);
  } catch (e) {
    console.log(e);
  }

  // Sau khi copy dữ liệu xong thì xoá bỏ các vùng chọn hiện tại
  selection.removeAllRanges();
});
```

<content-warning>

**Chú ý**: phần trên chỉ áp dụng cho các thẻ có text content như thẻ: _p, span, div,..._ Các thẻ không có text content như: _input, textarea,..._ sẽ được áp dụng giống như phần **cut dữ liệu vào clipboard** dưới đây.

</content-warning>

## Cut dữ liệu vào Clipboard

Khác với **copy** (có thể copy dữ liệu trong nhiều loại phần tử khác nhau), **cut** chỉ cho phép bạn thực hiện trên các phần tử như: _input (text), textarea,..._. Vì vậy, trong phần này mình sẽ demo với thẻ _input_.

Nội dung phần **html**:

```html
<h3>Cut</h3>
<input
  id="content-cut"
  type="text"
  value="This text will be cut, then inserted into the clipboard."
/>
<button id="button-cut">Cut Text</button>
```

Tiếp theo là phần xử lý trong **js** khi người dùng click vào button **Cut Text**:

```js
buttonCutElm.addEventListener("click", () => {
  // Tạo select nội dung của input
  inputCutElm.select();

  // Thử cut nội dung của input
  try {
    if (isSupported("cut")) document.execCommand("cut");
    else alert(`execCommand("cut") is not supported in your browser.`);
  } catch (e) {
    console.log(e);
  }
});
```

Cách tạo vùng chọn trong phần này dễ hơn so với phần trước vì đối tượng DOM node ứng với **input** đã hỗ trợ sẵn phương thức **select()**.

## Demo một số chức năng khác với execCommand

Như mình đã nói ở trên, `document.execCommand()` cho phép bạn thực hiện rất nhiều command khác ngoài _copy, cut_.

Dưới đây là một demo đơn giản sử dụng `document.execCommand()` để chỉnh sửa nội dung - tương tự như một **Text Editor**:

[](https://codepen.io/completejavascript/pen/ZmKKwW)

Trong ví dụ trên, bạn có thể thử bôi đen text, sau đó nhấn vào các button để test các chức năng của nó. Dĩ nhiên, các chức năng mình lấy ra làm ví dụ vẫn chưa đầy đủ hết so với khả năng hỗ trợ của `document.execCommand()`. Nhưng nó cũng phần nào giúp bạn thấy được khả năng của phương thức này.

## Lời kết

Trên đây là cách giao tiếp với clipboard sử dụng execCommand. Hy vọng bài viết này hữu ích với bạn. Và nếu có gì thắc mắc hoặc góp ý thì bạn có thể để lại bình luận xuống phía dưới. Mình sẽ cố gắng giải đáp.

Xem thêm:

- [Interact with the clipboard](https://developer.mozilla.org/en-US/docs/Mozilla/Add-ons/WebExtensions/Interact_with_the_clipboard)
- [Copying to Clipboard Using Vanilla JavaScript](https://alligator.io/js/copying-to-clipboard/)
- [Quick Tip: Accessing The Clipboard With JavaScript](https://tutorialzine.com/2016/10/quick-tip-accessing-the-clipboard-with-javascript)
- [Use execCommands to edit HTML content in your browser](https://codepen.io/chrisdavidmills/full/gzYjag/)
