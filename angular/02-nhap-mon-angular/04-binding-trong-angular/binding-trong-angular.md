---
title: "Binding trong Angular"
description: "Attribute directive là gì, nó có khác gì Structure directive mà chúng ta đã gặp qua như NgIf, NgForOf không? Đối với Structure directive, nó có thể thêm, xóa, thay đổi cấu trúc cây DOM. Còn một Attribute directive sẽ có thể thay đổi cách hiển thị (style) hoặc hành vi của một DOM element/Component/Directive khác. Đấy chính là sự khác biệt giữa chúng."
chapter:
  name: "Nhập môn Angular"
  slug: "chuong-02-nhap-mon-angular"
category:
  name: "Angular"
  slug: "angular"
image: https://kungfutech.edu.vn/thumbnail.png
position: 4
---

## Class binding trong angular

Trong các ứng dụng thực tế, có thể chúng ta cần thay đổi (thêm, xóa) một số class tùy thuộc vào một số điều kiện nào đó.
Ví dụ, nếu chúng ta đang chọn một tab nào đó để hiển thị, thì tab đó sẽ có thêm class tab-active, các tab khác sẽ không có. Lúc này chúng ta sẽ sử dụng cú pháp:

```html
<div [class.tab-active]="isTabActive">some content</div>
```

Nhìn qua thì nó chỉ là property binding, với giá trị của isTabActive trả về true thì classList của div đó sẽ tồn tại class tab-active, còn nếu trả về false thì sẽ không tồn tại.
Ngoài cú pháp trên chúng ta có thể dùng:

```html
[class]="classExpr"
```

Với classExpr có thể là string, array string hoặc object – nếu key nào của object là truthy thì sẽ thêm vào, nếu falsy thì sẽ xóa đi.
Ví dụ các dạng của classExpr:

| Type         | Value                                |
| ------------ | ------------------------------------ |
| String       | `"my-class-1 my-class-2 my-class-3"` |
| Array String | `['foo', 'bar']`                     |
| Object       | `{foo: true, bar: false}`            |

Tương tự với class binding chúng ta có thể sử dụng ngClass, nhưng hiện tại cũng có thể nói rằng ngClass không có gì khác biệt với [class]=”classExpr”. Và cách sử dụng Class Binding vẫn được khuyến cao sử dụng hơn ngClass

## Style binding trong angular

Có thể khi cần thiết, chúng ta cần binding cho style property (inline style), lúc này chúng ta có thể sử dụng Style binding.
Cấu trúc của style binding như sau:
[style.property]=”expression”
Với expression sẽ tính toán về các giá trị kiểu string | undefined | null
Ví dụ:

```html
<div [style.width]="”someValue”"></div>
```

Tiếp theo là cú pháp kèm theo unit: `[style.property.unit]=”expression”`

Với expression sẽ tính toán về các giá trị kiểu `number | undefined | null`
Ví dụ:
`[style.height.%]=”containerHeight”`

Cuối cùng là cú pháp dạng:
`[style]=”styleExpr”`

Với styleExpr là một trong các dạng:

| Type         | Value                                                                                        |
| ------------ | -------------------------------------------------------------------------------------------- |
| String       | `"width: 100%; height: 100%"`                                                                |
| Array String | `['width', '100px']`                                                                         |
| Object       | `{[key: string]: string &#x7c; undefined &#x7c; null} như {width: '100px', height: '100px'}` |

Có một directive tương tự là ngStyle với cách dùng gấn giống thế, trong hầu hết các trường hợp, chúng ta được khuyến cáo sử dụng style binding thay thế.

::alert{type="warning"}
Lưu ý rằng, một style property có thể dùng cả kiểu `dash-key` hoặc `camelCase`, ví dụ `font-size` hoặc `fontSize` đều được.
::

## Lời kết

Như vậy trong Day 6, chúng ta cần tìm hiểu được cách dùng của 2 built-in attribute directive là class và style để có thể style được một phần tử tùy theo một dữ liệu nào đó trong component.
