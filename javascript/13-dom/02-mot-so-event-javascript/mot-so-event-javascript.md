---
title: "Một số event trong Javascript"
description: "Event là sự tương tác của JavaScript với HMTL được xử lý thông qua các sự kiện xảy ra khi người sử dụng hoặc trình duyệt thao tác một trang."
keywords: [
"Một số event trong Javascript",
"event target javascript",
"event target trong javascript",
"event trong javascript",
"all event javascript",
"dom event javascript",
"dom event trong javascript",
"bat su kien enter trong javascript",
"mot so event javascript là gì",
"mot so event javascript trong javascript",
"DOM Event trong JavaScript"
]
chapter:
  name: "DOM"
  slug: "chuong-13-dom"
category:
  name: "Javascript"
  slug: "javascript"
image: https://kungfutech.edu.vn/thumbnail.png
position: 2
---

Đối với mỗi trang web, đặc biệt là những trang web có sự tương tác với người dùng, việc xử lý sự kiện chuột và bàn phím là không thể thiếu. Vì vậy, bài viết này mình sẽ giới thiệu với bạn cách xử lý một số Event JavaScript cơ bản. Qua đó, bạn có thể tiếp tục tìm hiểu và làm chủ về JS event.

## Cách đăng ký và huỷ đăng ký Event JavaScript

### Đăng ký Event JavaScript

Ở bài viết trước về [DOM](/bai-viet/javascript/dom-la-gi), bạn biết rằng mỗi phần tử trên trang web là một node. Và chúng ta có thể đăng ký nhận sự kiện cho mỗi node này bằng cách sử dụng phương thức **addEventListener** như sau:

```js
Node.addEventListener('tên sự kiện', hàm xử lý);
```

Trong đó:

- Node: là một phần tử DOM như: _document, body, h1, p, img, button_,... Nếu bạn không ghi gì thì mặc node đó là _document_.
- Tên sự kiện: ứng với sự kiện mà bạn muốn nhận như: _click, mousedown, mouseup, mousemove, keydown, keyup, keypress,..._
- Hàm xử lý: là hàm được gọi khi sự kiện bạn đăng ký xảy với node trên.

**Chú ý**: với một JS event, bạn có thể đăng ký nhiều hàm xử lý. Khi đó, hàm đăng ký trước sẽ được gọi trước.

Ví dụ:

```js
function func1() {
  console.log("function 1");
}
function func2() {
  console.log("function 2");
}
addEventListener("click", func1);
addEventListener("click", func2);
```

Trong ví dụ trên, mình đã đăng kí sự kiện _click_ cho d*ocument* với hai hàm xử lý là _func1_ và _func2_. Từ nay, mỗi khi bạn click chuột trái vào trang web thì hàm _func1_ sẽ được gọi trước, sau đó đến hàm _func2_.

### Huỷ đăng ký Event JavaScript

Tương tự, để huỷ event trong JavaScript đã đăng ký, bạn có thể sử dụng phương thức **removeEventListener** như sau:

```js
Node.removeEventListener('tên sự kiện', hàm xử lý);
```

Ví dụ:

```js
function func1() {
  console.log("function 1");
}
function func2() {
  console.log("function 2");
}
addEventListener("click", func1);
addEventListener("click", func2);

removeEventListener("click", func1);
```

Tiếp theo ví dụ trên, nếu mình huỷ đăng ký sự kiện _click_ trên _document_ với hàm _func1_ bằng phương thức sau:

```js
removeEventListener("click", func1);
```

Thì bây giờ, mỗi khi bạn click chuột trái vào trang web, chỉ có hàm _func2_ được gọi.

### Đăng ký event cho nhiều node dựa trên đối tượng event

Bình thường để đăng ký event trong JavaScript cho nhiều node bạn có thể sử dụng phương thức **_addEventListener_** cho mỗi node. Tuy nhiên, bạn có thể chỉ cần sử dụng phương thức trên 1 lần và sử dụng thuộc tính target của [đối tượng](/bai-viet/javascript/object-la-gi-object-trong-javascript) event để phân biệt node được gọi.

Hãy xem ví dụ sau:

```html
<button>A</button>
<button>B</button>
<button>C</button>
<p>Hello</p>
<script>
  document.body.addEventListener("click", function (event) {
    if (event.target.nodeName == "BUTTON")
      console.log("Clicked", event.target.textContent);
    else if (event.target.nodeName == "P")
      console.log("Paragraph clicked", event.target.textContent);
  });
</script>
```

Trong ví dụ trên, mình chỉ cần gọi phương thức **addEventListener** một lần. Sau đó, mình chỉ cần sử dụng _event.target.nodeName_ để biết được node nào thật sự được _click_.

### Huỷ hàm thực hiện mặc định với JS event

Một số Event JavaScript có sẵn hàm thực hiện mặc định. Ví dụ: khi bạn click vào một link thì bạn sẽ được chuyển hướng đến trang của link đó, hay khi bạn click chuột phải thì sẽ có một context menu hiện ra,...

Tuy nhiên, nếu bạn không muốn thực hiện những hàm mặc định đó thì bạn có thể sử dụng phương thức **preventDefault**.

Ví dụ:

```html
<a href="https://developer.mozilla.org/">MDN</a>
<script>
  var link = document.querySelector("a");
  link.addEventListener("click", function (event) {
    console.log("Nope.");
    event.preventDefault();
  });
</script>
```

Trong ví dụ trên, khi bạn nhấn vào link thì bạn sẽ không được chuyển đến trang [https://developer.mozilla.org](https://developer.mozilla.org).

## Một số Event JavaScript cơ bản

### Key event

Key event là sự kiện khi bạn nhấn vào một key trên bàn phím. Có 3 sự kiện với key là:

- keydown: được gọi khi bạn nhấn xuống một key
- keyup: được gọi khi bạn nhả key đó ra
- keypress: được gọi khi bạn nhấn và giữ key
- ...

Ví dụ:

```js
addEventListener("keydown", function (event) {
  console.log("keydown", event.keyCode);
});
addEventListener("keyup", function (event) {
  console.log("keyup", event.keyCode);
});
addEventListener("keypress", function (event) {
  console.log("keypress", event.keyCode);
});
```

Trong ví dụ này, mình ghi ra giá trị _keyCode_ của phím được nhấn dựa vào đối tượng _event (keyEvent_ ở đây là giá trị số nguyên của từng phím trong bảng mã Unicode).

**Chú ý:** với sự kiện _keydown_ và _keyup_ thì giá trị sẽ ứng với chữ cái thường, trong khi sự kiện _keypress_ thì ta sẽ có giá trị của chữ cái viết hoa. Tức là nếu bạn nhấn phím 'a' thì kết quả sẽ là:

```js
keydown 65
keypress 97
keyup 65
```

Ngoài ra bạn có thể xử lý việc nhấn tổ hợp phím như ví dụ sau:

```js
addEventListener("keydown", function (event) {
  if (event.ctrlKey) console.log("keydown", "ctrlKey", event.keyCode);
});
addEventListener("keydown", function (event) {
  if (event.shiftKey) console.log("keydown", "shiftKey", event.keyCode);
});
addEventListener("keydown", function (event) {
  if (event.altKey) console.log("keydown", "altKey", event.keyCode);
});
```

### Mouse Event

Mouse event là sự kiện khi bạn nhấn hay di chuyển chuột. Một số sự kiện với chuột là:

- click: được gọi khi bạn nhấn chuột 1 lần
- dblclick: được gọi khi bạn nhấn chuột nhanh 2 lần
- mousedown: được gọi khi bạn nhấn chuột xuống
- mouseup: được gọi khi bạn nhả chuột ra
- mousemove: được gọi khi bạn nhấn và kéo chuột
- ...

Đối với sự kiện nhấn chuột, có nhiều bài toán mà bạn sẽ cần phải xác định vị trí nhấn chuột, kéo chuột,... mình sẽ giới thiệu với bạn ở một bài viết khác sau.

## Kết luận

Trên đây là một số cách xử lý Event JavaScript cơ bản. Mình có thể tóm tắt lại như sau:

- addEventListener : đăng ký sự kiện
- removeEventListener : huỷ đăng ký sự kiện
- preventDefault: bỏ đi hàm xử lý mặc định với sự kiện
- Một số sự kiện với key: keydown, keyup, keypress,...
- Một số sự kiện với mouse: click, dbclick, mousedown, mouseup, mousemove,...

Hy vọng bạn có thể nắm được những kiến thức cơ bản về JS event.

## Tham khảo

- [Handling Events](https://eloquentjavascript.net/15_event.html)
