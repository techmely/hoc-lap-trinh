---
title: "Component trong React là gì?"
description: "Component (thành phần) là một trong những khái niệm cốt lõi của React. Chúng là nền tảng để bạn xây dựng giao diện người dùng (UI), điều này biến chúng trở thành nơi tuyệt vời để bạn bắt đầu hành trình với React!"
chapter:
  name: "Giao diện trong Reactjs"
  slug: "chuong-03-giao-dien-trong-reactjs"
image: https://kungfutech.edu.vn/thumbnail.png
position: 4
---

**Component (thành phần)** là một trong những khái niệm cốt lõi của React. Chúng là nền tảng để bạn xây dựng giao diện người dùng (UI)!

## Ví dụ về component trong React

Như ví dụ dưới đây, giao diện người dùng đã được chia nhỏ thành các phần riêng lẻ

![Ví dụ về component trong React](https://github.com/techmely/hoc-lap-trinh/assets/29374426/046f2612-9e8f-4346-8262-c45313af9087)

Phần Google Custom Search, thanh điều hướng, thanh bên, danh sách các bài báo,... đều được coi là một thành phần riêng lẻ. Chúng ta có thể thực hiện hợp nhất tất cả các thành phần này để tạo thành một giao diện chính, là giao diện người dùng cuối cùng cho trang chủ.

Khi dự án phát triển, bạn sẽ nhận thấy rằng nhiều phần thiết kế có thể tái sử dụng component bạn đã viết, giúp tăng tốc quá trình phát triển.

## Component trong React là gì?

Components là những thành phần giao diện (UI) được định nghĩa độc lập, có thể tái sử sụng và hoàn toàn tách biệt nhau.

Chúng ta có thể hiểu component là một hàm trong javascript. Chúng nhận bất kỳ đầu vào nào (hay còn gọi là “props“) và trả về các React elements thể hiện những gì được hiển thị trên trình duyệt. Vì vậy, việc sử dụng và chia nhỏ component hiệu quả sẽ giúp các lập trình viên trở nên chuyên nghiệp và giúp xây dựng một application tốt hơn.

## Các bước tạo component trong React

Dưới đây là các bước giúp tạo tạo một component trong React (ở đây là component `Profile`)

```javascript
export default function Profile() {
  return <img src="https://i.imgur.com/MK3eW3Am.jpg" alt="Katherine Johnson" />;
}
```

### Bước 1: Xuất component

Tiền tố `export default` là một cú pháp JavaScript tiêu chuẩn (không riêng cho React). Nó cho phép bạn đánh dấu hàm chính trong một tệp để sau đó bạn có thể nhập nó từ các tệp khác.

### Bước 2: Định nghĩa hàm

Với `function Profile() { }`, bạn định nghĩa một hàm JavaScript với tên Profile.

::alert{type="warning"}
Lưu ý: các component React là các hàm JavaScript thông thường, nhưng tên của chúng phải bắt đầu bằng một chữ cái viết hoa hoặc chúng sẽ không hoạt động!
::

### Bước 3: Thêm mã Markup

Component trả về một thẻ `<img />` với các thuộc tính src và alt. `<img />` được viết giống HTML, nhưng bản chất là JavaScript bên trong! Cú pháp này được gọi là JSX, và nó cho phép bạn nhúng mã markup vào bên trong JavaScript.

Câu lệnh `return` có thể được viết trên cùng một dòng, như trong component này:

```javascript
return <img src="https://i.imgur.com/MK3eW3As.jpg" alt="Katherine Johnson" />;
```

Nhưng nếu mã markup của bạn không nằm trên cùng một dòng như từ khóa `return`, bạn phải bọc nó trong một cặp dấu ngoặc đơn:

```javascript
return (
  <div>
    <img src="https://i.imgur.com/MK3eW3As.jpg" alt="Katherine Johnson" />
  </div>
);
```

::alert{type="warning"}
Lưu ý: mà không có dấu ngoặc đơn, bất kỳ mã nào trên các dòng sau `return` sẽ bị bỏ qua!
::

## Cách sử dụng một component trong React

Bây giờ khi bạn đã định nghĩa component `Profile` của mình, bạn có thể lồng nó vào bên trong các component khác. Ví dụ, bạn có thể xuất một component Gallery sử dụng nhiều component Profile:

```javascript
function Profile() {
  return <img src="https://i.imgur.com/MK3eW3As.jpg" alt="Katherine Johnson" />;
}

export default function Gallery() {
  return (
    <section>
      <h1>Các nhà khoa học tuyệt vời</h1>
      <Profile />
      <Profile />
      <Profile />
    </section>
  );
}
```

Nhìn vào trình duyệt, hãy chú ý đến sự khác biệt về kiểu chữ:

- `<section>` viết thường, vì vậy React biết rằng chúng ta đang đề cập đến một thẻ HTML.
- `<Profile />` bắt đầu bằng chữ cái viết hoa, vì vậy React biết rằng chúng ta muốn sử dụng component của mình có tên là `Profile`.
- Và `Profile` chứa thậm chí nhiều HTML hơn: `<img />`. Cuối cùng, đây là điều trình duyệt thấy:

```html
<section>
  <h1>Các nhà khoa học tuyệt vời</h1>
  <img src="https://i.imgur.com/MK3eW3As.jpg" alt="Katherine Johnson" />
  <img src="https://i.imgur.com/MK3eW3As.jpg" alt="Katherine Johnson" />
  <img src="https://i.imgur.com/MK3eW3As.jpg" alt="Katherine Johnson" />
</section>
```

## Lồng và tổ chức các component

Các component là các hàm JavaScript thông thường, vì vậy bạn có thể chứa nhiều component trong cùng một tệp. Điều này tiện lợi khi các component tương đối nhỏ hoặc liên quan chặt chẽ đến nhau.

Bởi vì các component `Profile` được render bên trong `Gallery` - thậm chí có thể là nhiều lần! - chúng ta có thể nói rằng `Gallery` là một component cha, render từng `Profile` như một component "con".

::alert{type="warning"}
Các component có thể render các component khác, nhưng bạn không bao giờ nên lồng định nghĩa của chúng:
::

```javascript
export default function Gallery() {
  // 🔴 Không bao giờ định nghĩa một component bên trong component khác!
  function Profile() {
    // ...
  }
  // ...
}
```

Đoạn mã trên rất chậm và gây ra lỗi. Thay vào đó, định nghĩa mọi component ở cấp độ cao nhất:

```javascript
export default function Gallery() {
  // ...
}

// ✅ Khai báo các component ở cấp độ cao nhất
function Profile() {
  // ...
}
```
