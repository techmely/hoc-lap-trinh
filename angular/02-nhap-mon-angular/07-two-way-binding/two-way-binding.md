---
title: "Two-way binding trong angular"
description: "Trong các ngày trước chúng ta đã tìm hiểu về Two-way binding ở trong Angular. Ngoài ra chúng ta cũng đã biết cách để truyền @Input và @Output cho component. Vậy có cách nào để chúng ta tự tạo Custom Two-way binding hay không? Câu trả lời chính là từ cặp input-ouput ngModel và ngModelChange."
chapter:
  name: "Nhập môn Angular"
  slug: "chuong-02-nhap-mon-angular"
category:
  name: "Angular"
  slug: "angular"
image: https://kungfutech.edu.vn/thumbnail.png
position: 7
---

## Giới thiệu lại `ngModel`

Như chúng ta đã biết, `ngModel` được cung cấp là một directive ở trong NgModule có tên là `FormsModule`, vậy nên để sử dụng được nó chúng ta sẽ cần imports FormsModule vào NgModule quản lý component hiện tại. Hay nói cách khác, nếu component của bạn muốn sử dụng NgModel thì bạn phải imports `FormsModule` và NgModule quản lý component đó.

Ví dụ, chúng ta có `AppComponent` và nó được quản lý bởi `AppModule`, vậy nên chúng ta sẽ imports `FormsModule` vào `AppModule` như sau.

```ts
import { NgModule } from "@angular/core";
import { BrowserModule } from "@angular/platform-browser";
import { FormsModule } from "@angular/forms";

import { AppComponent } from "./app.component";

@NgModule({
  imports: [BrowserModule, FormsModule],
  declarations: [AppComponent],
  bootstrap: [AppComponent],
})
export class AppModule {}
```

Như thế là chúng ta có thể sử dụng được `ngModel` ở template, và sử dụng cú pháp vuông vuông tròn tròn `[(ngModel)]` để có được Two-way binding.

```html
<!-- app.component.html -->
<p>Your name: {{ name }}</p>

<input type="text" [(ngModel)]="name" />
```

```ts
// app.component.ts
@Component({
  selector: "my-app",
  templateUrl: "./app.component.html",
  styleUrls: ["./app.component.css"],
})
export class AppComponent {
  name = "Tiep Phan";
}
```

Giờ đây mỗi lần bạn thay đổi giá trị của input thì thẻ `p` sẽ hiển thị tên được sync tương ứng.

Thực chất cách viết trên là viết tắt của property binding và event binding như sau:

```html
<input type="text" [ngModel]="name" (ngModelChange)="name = $event" />
```

Vậy nên để tạo custom Two-way binding thì bạn chỉ cần tạo @Input và @Output với @Output có suffix là change là được, ví dụ `value` và `valueChange`.

## Toggle Component support Two-way binding

Chúng ta sẽ khởi tạo một component mới để minh họa, component có tên là toggle component:

```sh
ng g c toggle
```

Phần code của component sẽ được implement như sau:

```ts
// toggle.component.ts
import { Component, OnInit, Input, Output, EventEmitter } from "@angular/core";

@Component({
  selector: "app-toggle",
  templateUrl: "./toggle.component.html",
  styleUrls: ["./toggle.component.css"],
})
export class ToggleComponent implements OnInit {
  @Input() checked = false;
  @Output() checkedChange = new EventEmitter<boolean>();

  constructor() {}

  ngOnInit() {}

  toggle() {
    this.checked = !this.checked;
    this.checkedChange.emit(this.checked);
  }
}
```

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
```

```css
/* toggle.component.css */
.toggle-wrapper {
  display: flex;
  align-items: center;
  justify-content: center;
  cursor: pointer;
  transition: all 0.2s;
  width: 100px;
  height: 100px;
  border-radius: 50%;
  background-color: #fe4551;
  box-shadow: 0 20px 20px 0 rgba(#fe4551, 0.3);
}

.toggle-wrapper:active {
  width: 95px;
  height: 95px;
  box-shadow: 0 15px 15px 0 rgba(#fe4551, 0.5);
}
.toggle-wrapper .toggle {
  height: 17px;
  width: 17px;
}

.toggle {
  transition: all 0.2s ease-in-out;
  height: 20px;
  width: 20px;
  background-color: transparent;
  border: 10px solid #fff;
  border-radius: 50%;
  cursor: pointer;
  animation: red 0.7s linear forwards;
}

.toggle-wrapper.checked {
  background-color: #48e98a;
  box-shadow: 0 20px 20px 0 rgba(#48e98a, 0.3);
}

.toggle-wrapper.checked:active {
  box-shadow: 0 15px 15px 0 rgba(#48e98a, 0.5);
}

.toggle-wrapper.checked .toggle {
  width: 0;
  background-color: #fff;
  border-color: transparent;
  border-radius: 30px;
  animation: green 0.7s linear forwards !important;
}
```

Component trên của chúng ta không có quá khác biệt so với những component trước đây, nó đều sử dụng những concept cơ bản như @Input, @Output, class binding, style css.

Chỉ với việc sử dụng suffix `change` cho property `checked` chúng ta có thể sử dụng component này ở bất cứ đâu với cách dùng giống như `ngModel`:

```html
<app-toggle [(checked)]="checked"></app-toggle>
```

![Toggle](https://github.com/techmely/hoc-lap-trinh/assets/29374426/8275610a-f3a2-43ad-b777-1aa43882fa2e)

## Lời kết

Như vậy trong bài này, chúng ta sẽ phải tìm hiểu cách để tạo ra custom Two-way binding bằng cách kết hợp giữa @Input và @Output. Ngoài ra chúng ta còn thực hành một số bài học trước đây như class binding. Hi vọng những bài viết dưới đây sẽ giúp ích cho các bạn tìm hiểu chi tiết hơn.
