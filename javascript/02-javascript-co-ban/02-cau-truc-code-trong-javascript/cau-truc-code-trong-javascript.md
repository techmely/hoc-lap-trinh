---
title: "Cấu trúc code trong Javascript"
description: "Bài này chúng ta sẽ cùng nhau tìm hiểu về câu lệnh và comment trong Javascript"
keywords:
  [
    "cấu trúc code trong javascript",
    "comment trong javascript",
    "câu lệnh trong javascript",
    "khoá học javascript cơ bản",
    "cau truc javascript",
    "Cấu trúc JavaScript",
    "comment trong javascript",
    "câu lệnh Javascript",
    "cac cau lenh trong javascript",
    "Cú pháp JavaScript"
  ]
chapter:
  name: "Javascript cơ bản"
  slug: "chuong-02-javascript-co-ban"
category:
  name: "Javascript"
  slug: "javascript"
image: https://kungfutech.edu.vn/thumbnail.png
position: 2
---

Chương trình là tập hợp của các câu lệnh. Hay nói cách khác, câu lệnh trong JavaScript là đơn vị cơ bản xây dựng nên một chương trình. Vì vậy, câu lệnh là khái niệm đầu tiên mà mình cần nắm vững khi học lập trình JavaScript.

## Câu lệnh trong JavaScript

Câu lệnh là đơn vị cơ bản của một ngôn ngữ lập trình, đưa ra hướng dẫn cho máy tính để thực hiện một hành động.

Trong bài viết về [chương trình JavaScript đầu tiên](/bai-viet/khoa-hoc-javascript/chuong-trinh-javascript-dau-tien/), bạn đã thấy mình sử dụng hai câu lệnh:

- `console.log("Hello World")`: in ra tab console của [Dev Tools](/bai-viet/khoa-hoc-javascript/dev-tools-la-gi/) trên trình duyệt dòng chữ "Hello World".
- `alert("Hello World")`: hiển thị dạng hộp thoại (dialog) dòng chữ "Hello World".

Đó là những câu lệnh rất cơ bản.

Và trong một chương trình, bạn có thể viết nhiều câu lệnh tùy thích. Mỗi câu lệnh trong JavaScript thường được ngăn cách nhau bởi dấu chấm phẩy (`;`).

Ví dụ hiển thị dòng chữ trên bằng hai câu lệnh `console.log` khác nhau:

```
console.log("Hello");console.log("World");
```

Thông thường, mình sẽ viết mỗi câu lệnh trên một dòng cho dễ nhìn hơn:

```js
console.log("Hello");
console.log("World");
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>Hello</code><br/>
    <code>World</code><br/>
  </div>
</div>

## Dấu chấm phẩy trong JavaScript

Dấu chấm phẩy trong JavaScript thường có thể bỏ qua nếu bạn viết các câu lệnh trên nhiều dòng. Ở ví dụ trên, bạn bỏ qua dấu chấm phẩy như sau:

```js
console.log("Hello");
console.log("World");
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>Hello</code><br/>
    <code>World</code><br/>
  </div>
</div>

Nguyên nhân là do trình thông dịch **tự động thêm dấu chấm phẩy** dựa trên kí tự xuống dòng. Tuy nhiên, vẫn có nhiều trường hợp xuống dòng nhưng JavaScript vẫn hiểu đó là một câu lệnh, ví dụ:

```
console.log(1 +
1 +
1);
```

Ba dòng trên vẫn chỉ là một câu lệnh. Và kết quả thu được là: **3**.

Bởi vì, khi hết dòng đầu tiên, bạn thấy rằng vẫn thiếu dấu đóng ngoặc `)` cho câu lệnh `console.log()`.

Do đó, trình thông dịch hiểu rằng, đây là câu lệnh không đầy đủ, nên sẽ không chèn dấu chấm phẩy vào cuối dòng.

### Trình thông dịch JavaScript có thực sự thông minh như vậy?

Đúng là trình thông dịch JavaScript khá thông minh. Nhưng vẫn có nhiều trường hợp mà bạn sẽ nhận được một kết quả không như mong muốn.

Ví dụ một đoạn code chạy đúng:

```js
console.log("Hello world");
[1, 2].forEach(value => console.log(value));
```

Có thể bạn chưa hiểu về câu lệnh thứ hai (các bài viết sau bạn sẽ biết) - kết quả hiển thị là:

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>Hello world</code><br/>
    <code>1</code><br/>
    <code>2</code><br/>

  </div>
</div>

**Nhưng nếu bạn bỏ qua dấu chấm phẩy thì sao?**

```
console.log("Hello world")
    [1, 2].forEach((value) => console.log(value))
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Bạn sẽ bị lỗi cú pháp</span>
  </div>
  <div class="window-body">
    <code>Hello world</code><br/>
    <code>Uncaught TypeError: Cannot read properties of undefined (reading '2')</code><br/>
  </div>
</div>

Kì lạ phải không? 🤔

Đây là một trong số những thứ gây đau đầu nhất khi lập trình JavaScript. Vì vậy, lời khuyên cho bạn là:

<content-info>
  <p>Luôn luôn sử dụng dấu chấm phẩy để kết thúc một câu lệnh.</p>
</content-info>

## Comment code trong JavaScript

Theo thời gian, chương trình sẽ phức tạp dần lên. Số lượng câu lệnh JavaScript cũng sẽ tăng lên theo. Có nhiều câu lệnh mà khi xem lại, bạn sẽ không hiểu tại sao mình viết code như vậy.

Để tránh tình trạng này xảy ra, bạn nên viết lại chú thích (comment).

Có hai kiểu viết chú thích là:

- Chú thích một dòng: sử dụng `//`
- Chú thích nhiều dòng: sử dụng `/* */`

Ví dụ chú thích một dòng:

```js
// Đây là chú chích trên 1 dòng
console.log("Hello");

console.log("World"); // Đây cũng là chú thích 1 dòng nhưng ở cuối câu lệnh

// Tạm thời bỏ qua câu lệnh sau đây
//alert("Hello world");
```

Ví dụ chú thích trên nhiều dòng:

```js
 /* Đây là chú thích
    trên nhiều dòng
    */
    console.log("Hello");

    console.log("World"); /* Đây cũng là chú thích
    nhiều dòng nhưng ở cuối câu lệnh */

    /**
     * Tạm thời bỏ qua câu lệnh sau đây
     * alert("Hello world");
     * /
```

Khi chạy chương trình, JavaScript engine sẽ bỏ qua thành phần chú thích này.

<content-info>
  <p>Một vài trường hợp mình viết chú thích:</p>
  <ul>
    <li>Việc đặt tên biến không diễn tả được hết ý nghĩa của nó (muốn đầy đủ ý nghĩa thì nó lại quá dài).</li>
    <li>Sử một công thức đã được chứng minh (nếu không chú thích lại sẽ không biết công thức đó ở đâu ra).</li>
    <li>Giải thích ý nghĩa của một hàm (tại sao lại phải viết hàm này...).</li>
    <li>Tạm thời bỏ qua một vài đoạn code chưa dùng tới.</li>
    <li>Và nhiều trường hợp khác nữa...</li>
  </ul>
</content-info>

_Có một số khái niệm mới ở đây, mình sẽ trình bày ở các bài viết sau._

Dĩ nhiên, bạn cũng đừng sợ việc viết nhiều chú thích sẽ làm cho trang web nặng lên. Vì hiện giờ đã có rất nhiều công cụ hỗ trợ **bỏ hết chú thích** khi triển khai trang web ở môi trường thực tế.

## Tổng kết

- Câu lệnh là đơn vị cơ bản xây dựng nên chương trình.
- Các câu lệnh trong JavaScript thường được ngăn cách nhau bởi dấu chấm phẩy.
- Bạn có thể bỏ qua dấu chấm phẩy khi viết các câu lệnh JavaScript trên nhiều dòng. Tuy nhiên, tốt nhất là **nên sử dụng dấu chấm phẩy** để tránh bị lỗi không mong muốn.
- Bạn cũng nên viết chú thích cho code khi cần thiết. Chú thích giúp bạn hoặc đồng nghiệp hiểu rõ hơn ý nghĩa của các câu lệnh, đoạn code trong chương trình.
