---
title: "Content Projection trong Angular"
description: "Có những khi trong quá trình phát triển ứng dụng với Angular chúng ta có thể sẽ gặp một số dạng component giống nhau về phần layout chẳng hạn, điểm khác biệt chỉ là một số label, content bên trong nó. Lúc này rất dễ để các bạn có thể tạo một component có nhận vào các Input, và render dựa vào các Input đó."
keywords:
  [
    "Content Projection trong Angular",
    "Sử dụng multiple ng-content được không?",
    "ng-content và selector trong angular",
    "ng-content và ngProjectAs trong angular",
  ]
chapter:
  name: "Nhập môn Angular"
  slug: "chuong-02-nhap-mon-angular"
category:
  name: "Angular"
  slug: "angular"
image: https://kungfutech.edu.vn/thumbnail.png
position: 11
---

### Làm thế nào để sử dụng ng-content?

Giả sử trong ứng dụng của chúng ta sẽ sử dụng lại component Toggle từ những buổi học trước để làm phần khảo sát khách hàng. Các câu hỏi sẽ ở dạng Yes/No, và nội dung label sẽ khác nhau cho từng câu hỏi. Vậy làm thế nào để chúng ta biến component Toggle trở nên linh động hơn mà không cần thêm Input nào. Có thể sử dụng ngay content được truyền vào (_project_) ở giữa cặp thẻ mở/đóng được không?

Đó là một perfect use-case cho `ng-content` có thể được sử dụng. Bạn chỉ cần đặt `ng-content` vào bất kỳ đâu trong template của component là được.

```html
<!-- toggle.component.html -->
<div
  class="toggle-wrapper"
  [class.checked]="checked"
  tabindex="0"
  (click)="toggle()"
>
  <div class="toggle"></div>
</div>
<div class="toogle-label">
  <ng-content></ng-content>
</div>
```

```html
<!-- app.component.html -->
<app-toggle [(checked)]="questions.question1">
  <span>Question 1</span>
</app-toggle>

<app-toggle [(checked)]="questions.question2">
  <span>Question 2</span>
</app-toggle>
```

### Sử dụng multiple ng-content được không?

Bạn có thể nghĩ rằng nếu mình đặt `ng-content` hai lần ở trên template thì sẽ thế nào? liệu nó có hiển thị gấp đôi số phần tử hay không?

```html
<!-- toggle.component.html -->
<div class="toggle-label">
  <div>content 1</div>
  <ng-content></ng-content>
</div>

<div class="toggle-label">
  <div>content 2</div>
  <ng-content></ng-content>
</div>
```

Khi nhìn vào kết quả render, chúng ta sẽ thấy chỉ có `content 2` là được hiển thị với label mà chúng ta truyền vào. Như vậy nếu sử dụng nhiều lần `ng-content` sẽ dẫn đến kết quả có thể không như chúng ta mong muốn. Điều này là hoàn toàn bình thường, giống như bao thẻ html khác như `header`, chúng ta chỉ có duy nhất 1 `slot` để hiển thị. Vậy nên đối với `ng-content` ở dạng trên, chúng ta chỉ nên có một tag duy nhất.

![multiple ng-content](https://user-images.githubusercontent.com/29374426/235444477-549b737d-7323-4878-b1a8-cb40bfae94e7.png)

### ng-content và selector trong angular

Khi để ý thẻ `table` của html các bạn sẽ thấy rằng, dù `thead`, `tbody`, `tfoot` có đặt ở bất kỳ thứ tự nào trong thẻ `table`, nó đều được đưa về đúng thứ tự là `thead` rồi đến `tbody`, sau cùng là `tfoot`. Điều này các bạn cũng có thể làm tương tự với `ng-content` kết hợp **selector**. Ngoài việc **project** có thứ tự ra, nó còn cho phép chúng ta dùng nhiều `ng-content`.

What? Bên trên chúng ta mới bảo không nên dùng nhiều `ng-content` cơ mà.

Đúng vậy, nhưng không phải là `ng-content` ở dạng _select all_ như trên.

Các dạng của selector có thể bao gồm:

- Tag selector: `<ng-content select="some-component-selector-or-html-tag"></ng-content>`
- CSS Class selector: `<ng-content select=".some-class"></ng-content>`
- Attribute selector: `<ng-content select="[some-attr]"></ng-content>`
- Combine nhiều selectors: `<ng-content select="some-component-selector-or-html-tag[some-attr]"></ng-content>`

Ví dụ với Toggle component:

```html
<!-- toggle.component.html -->
<header>
  <ng-content select=".toogle-header"></ng-content>
</header>
<div
  class="toggle-wrapper"
  [class.checked]="checked"
  tabindex="0"
  (click)="toggle()"
>
  <div class="toggle"></div>
</div>
<div class="toggle-label">
  <ng-content select="label"></ng-content>
</div>

<div class="toggle-content">
  <ng-content></ng-content>
</div>
```

```html
<!-- app.component.html -->
<app-toggle [(checked)]="questions.question1">
  <h3 class="toggle-header">Header 1</h3>
  <label>Question 1</label>
  <span>Some paragraph</span>
</app-toggle>
```

Và dù ở **app.component.html** chúng ta có đặt sai thứ tự thì Toggle component vẫn sẽ hiển thị như những gì chúng ta mong muốn.

```html
<app-toggle [(checked)]="questions.question2">
  <h3 class="toggle-header">Header 2</h3>
  <span>Some paragraph 2</span>
  <label>Question 2</label>
</app-toggle>
```

> Lưu ý: khi sử dụng _selector_ nếu chúng ta project vào nhiều elements thỏa mãn _selector_ đó thì `ng-content select` sẽ nhận hết tất cả các elements.

### ng-content và ngProjectAs trong angular

Giả sử Toggle component mong muốn nhận vào một component có selector là `app-label`, và chúng ta sẽ cung cấp một component `app-label` với nhiều tính năng rất xịn xò.

```html
<div class="toggle-label">
  <ng-content select="app-label"></ng-content>
</div>
```

Nhưng người khác khi sử dụng Toggle component lại muốn sử dụng một component label khác, hay đơn giản chỉ là dùng tag label của HTML, hoặc component `app-label` không phải là con trực tiếp của `app-toggle` mà nó bị wrap bởi một thẻ `div` chẳng hạn.

Lúc này, selector kia của chúng ta sẽ không thể nhận dạng được. Vậy có cách nào để báo cho Angular biết rằng chúng ta đang mong muốn project content này hay không?

Cứu cánh chính là `ngProjectAs`, nó là một cách khai báo tường minh để Angular biết lối mà xử lý.

```html
<!-- app.component.html -->
<app-toggle [(checked)]="questions.question1">
  <h3 class="toogle-header">Header 1</h3>
  <label ngProjectAs="app-label">Question 1</label>
  <span>Some paragraph</span>
</app-toggle>
```

Có khá nhiều library cũng sử dụng kỹ thuật này để cho phép người dùng customize nhiều hơn. Ví dụ như [ngx-dropzone](https://github.com/peterfreeman/ngx-dropzone)

## Lời kết

Đây là ngày đầu tiên chúng ta tìm hiểu về `ng-content` hay một số framework/web component có một concept tương tự là `slot`. Nó giúp chúng ta tạo những component có thể dễ dàng tái sử dụng hơn. Ngày hôm nay là một buổi giới thiệu về `ng-content` nên hi vọng các bạn có thể hiểu hơn về nó mà không thấy quá nhàm chán.
Còn để có thể hiểu tường tận về `ng-content` sẽ còn nhiều nội dung khác nữa, nên chúng ta sẽ còn gặp lại nó trong thời gian sắp tới.
