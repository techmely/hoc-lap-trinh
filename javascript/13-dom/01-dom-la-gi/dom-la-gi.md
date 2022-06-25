---
title: "DOM là gì? Tìm hiểu về DOM"
description: "DOM là một giao diện lập trình ứng dụng (API). DOM được dùng để truy xuất các tài liệu dạng HTML và XML, có dạng một cây cấu trúc dữ liệu, và thông thường mô hình DOM độc lập với hệ điều hành và dựa theo kỹ thuật lập trình hướng đối tượng để mô tả tài liệu"
keywords: [
"DOM là gì? Tìm hiểu về DOM  trong javascript",
"dom va sub nghia la gi  trong javascript",
"dom nghia la gi  trong javascript",
"DOM là gì trong javascript",
"Document Object Model là gì trong javascript"
]
chapter:
  name: "DOM"
  slug: "chuong-13-dom"
category:
  name: "Javascript"
  slug: "javascript"
image: https://kungfutech.edu.vn/thumbnail.png
position: 1
---

Những bài viết trước, mình đã giới thiệu với bạn kiến thức cơ bản về mặt _ngôn ngữ_ của [JavaScript](/bai-viet/javascript/gioi-thieu-javascript). Bài viết này mình sẽ giới thiệu sự liên kết của JavaScript với trình duyệt. Và cái đầu tiên mà mình muốn nói đến, chính là **DOM**. Vậy DOM là gì? Cách sử dụng DOM trong JavaScript thế nào? Sau đây là câu trả lời.

## DOM là gì?

DOM là viết tắt của Document Object Model - một thành phần javascript cơ bản. Hiểu đơn giản thì DOM trong JavaScript chính là những phần tử biểu diễn cấu trúc dữ liệu của một trang web.

Hãy xem xét một ví dụ đơn giản sau:

```html
<!DOCTYPE html>
<html>
  <head>
    <title>My home page</title>
  </head>
  <body>
    <h1>My home page</h1>
    <p>Hello, I am Marijn and this is my home page.</p>
    <p>
      I also wrote a book! Read it
      <a href="http://eloquentjavascript.net">here</a>.
    </p>
  </body>
</html>
```

Đây là cấu trúc đơn giản của một trang web.

![Cơ bản về DOM JavaScript 1 ](/static/cd58ce377a07064c9a0d8d912f6f68cb/2bbac/Co-ban-ve-DOM-JavaScript-1-completejavascript.com_.png "Cơ bản về DOM JavaScript 1 ")

Ở đây, mỗi hình vuông cùng với nội dung bên trong nó chính là DOM.

## Cấu trúc biểu diễn DOM JavaScript

Thực tế, cấu trúc dữ liệu của một trang web được biểu diễn dạng cây (tree). Trong đó, mỗi node sẽ tương ứng với một DOM.

Mỗi DOM node sẽ có thuộc tính _nodeType_ - là một số nguyên - để biểu diễn kiểu của node, với giá trị như sau:

- `document.ELEMENT_NODE (1)` : node thông thường như **html, head, body, title, h1, p,...**
- `document.TEXT_NODE (3)` : thành phần text trên trang web
- `document.COMMENT_NODE (8)` : thành phần comment.

Ví dụ trên được biểu diễn dạng cây:

![Cơ bản về DOM JavaScript 2](/static/5226983d9e40bacfef6528123117edb9/09261/Co-ban-ve-DOM-JavaScript-2-completejavascript.com_.png "Cơ bản về DOM JavaScript 2 ")

## Liên kết giữa các DOM node trong cây

Mỗi DOM node luôn chứa rất nhiều liên kết đến các DOM node khác.

![Cơ bản về DOM JavaScript](/static/ac6f0844db7cb0f3c6b352a47055820f/55493/Co-ban-ve-DOM-JavaScript-3-completejavascript.com_.png "Cơ bản về DOM JavaScript ")

### [Node.parentNode](https://developer.mozilla.org/en-US/docs/Web/API/Node/parentNode)

trỏ đến node cha của một node.

Nếu một node không có node cha (_document_) thì parentNode là null.

Ví dụ: với mỗi node _p_ và _h1_ thì _parentNode_ là _body_.

### [Node.childNodes](https://developer.mozilla.org/en-US/docs/Web/API/Node/childNodes)

trỏ đến một [đối tượng](/bai-viet/javascript/object-la-gi-object-trong-javascript) gần giống với [array](/array-la-gi-array-trong-javascript/), chứa những node con của một node.

Tại sao lại là "gần giống với array" ?

Vì đối tượng này không chứa các method như _slice, [forEach](/bai-viet/javascript/tim-hieu-ve-foreach-trong-javascript)_.

Ví dụ: với node _body_, _childNodes_ là một danh sách với các node con là _h1, p, p_.

### [Node.firstChild](https://developer.mozilla.org/en/docs/Web/API/Node/firstChild)

trỏ đến node con đầu tiên của một node trong _childNodes_.

Ví dụ: với node _body_, _firstChild_ là _h1_.

### [Node.lastChild](https://developer.mozilla.org/en/docs/Web/API/Node/lastChild)

trỏ đến node con cuối cùng của một node trong _childNodes_.

Ví dụ: với node _body_, _lastChild_ là _p_ (thứ 2).

### [Node.previousSibling](https://developer.mozilla.org/en/docs/Web/API/Node/previousSibling)

trỏ đến node liền kề phía trước (có cùng _parentNode_).

Ví dụ: với node _p_ (thứ nhất), _previousSibling_ là _h1_.

### [Node.nextSibling](https://developer.mozilla.org/en/docs/Web/API/Node/nextSibling)

trỏ đến node liền kề phía sau (có cùng _parentNode_).

Ví dụ: với node _p_ (thứ nhất), _nextSibling_ là \_p \_(thứ 2).

## Một số phương thức phổ biến khi sử dụng DOM

### [Node.getElementsByTagName('tagName')](https://developer.mozilla.org/en/docs/Web/API/Document/getElementsByTagName)

trả về một danh sách các node con, cháu của một node với tag là 'tagName'.

Ở đây, _tagName_ có thể là _body, h1, p, img, ..._

### [Node.getElementsByClassName('className')](https://developer.mozilla.org/en/docs/Web/API/Document/getElementsByClassName)

Tương tự như phương thức trên, phương phức này trả về một danh sách các node con, cháu của một node với thuộc tính class = 'className'.

### [Node.getElementById('id')](https://developer.mozilla.org/en-US/docs/Web/API/Document/getElementById)

trả về node có thuộc tính id = 'id'.

### [Node.removeChild(child)](https://developer.mozilla.org/en-US/docs/Web/API/Node/removeChild)

bỏ đi node _child_ của một node và trả về node bị bỏ đi.

### [Node.appendChild(child)](https://developer.mozilla.org/en/docs/Web/API/Node/appendChild)

thêm node _child_ vào cuối danh sách _childNodes_ của một node.

### [Node.insertBefore(newNode, referenceNode)](https://developer.mozilla.org/en-US/docs/Web/API/Node/insertBefore)

chèn thêm node _newNode_ vào phía trước node _referenceNode_.

### [Node.replaceChild(newChild, oldChild)](https://developer.mozilla.org/en-US/docs/Web/API/Node/replaceChild)

thay thế node _oldChild_ bằng node _newChild_.

### [Document.createTextNode(data)](https://developer.mozilla.org/en-US/docs/Web/API/Document/createTextNode)

Tạo ra một node kiểu text với giá trị text là _data_.

### [Document.createElement(tagName)](https://developer.mozilla.org/en-US/docs/Web/API/Document/createElement)

Tạo ra một node mới có kiểu là _tagName_ (_h1, h2, p, img, div,..._)

### [Document.querySelector(selectors)](https://developer.mozilla.org/en-US/docs/Web/API/Document/querySelector)

Trả về node đầu tiên thoả mãn _selectors_. Trong đó, _selectors_ là một string chứa một hay nhiều [CSS-selector](https://developer.mozilla.org/en-US/docs/Learn/CSS/Introduction_to_CSS/Selectors) phân cách nhau bằng dấu phẩy.

### [Document.querySelectorAll(selectors)](https://developer.mozilla.org/en-US/docs/Web/API/Document/querySelectorAll)

Trả về danh sách các node thoả mãn _selectors_, theo thứ tự sử dụng thuật toán DFS.

![Perfect practice makes perfect - Complete JavaScript - completejavascript.com](/static/bb6b968cfe13d231995307e6efd5045a/7c811/only-perfect-practice-makes-perfect-completejavascript.com_.png "Perfect practice makes perfect - Complete JavaScript - completejavascript.com")

## Ví dụ sử dụng DOM trong JavaScript

"Cách học tốt nhất là học từ thực hành". Sau đây là một số bài tập thực hành sử dụng DOM và các phương thức trên mà mình đã thực hiện (phần đề bài ở trang mà mình đã tham khảo, xem phía dưới).

### Build a table

Tham khảo code tại [đây](https://github.com/completejavascript/practical-javascript/blob/master/DOM_basic/build_a_table_completejavascript.com.js).

### Elements by Tag Name

Tham khảo code tại [đây](https://github.com/completejavascript/practical-javascript/blob/master/DOM_basic/elements_by_tag_name_completejavascript.com.js).

### The cat's hat

Tham khảo code tại [đây](https://github.com/completejavascript/practical-javascript/blob/master/DOM_basic/cat_hat.completejavascript.com.js).

## Tham khảo

[The Document Object Model](http://eloquentjavascript.net/14_dom.html)
