---
title: "Ứng dụng đầu tiên với ReactJs"
description: "Các thành phần (components) là một trong những khái niệm cốt lõi của React. Chúng là nền tảng trên đó bạn xây dựng giao diện người dùng (UI), chính vì vậy chúng là nơi hoàn hảo để bạn bắt đầu hành trình với React!"
chapter:
  name: "Giao diện trong ReactJs"
  slug: "chuong-03-giao-dien-trong-reactjs"
image: https://kungfutech.edu.vn/thumbnail.png
position: 1
---

Các thành phần (components) là một trong những khái niệm cốt lõi của React. Chúng là nền tảng trên đó bạn xây dựng giao diện người dùng (UI), chính vì vậy chúng là nơi hoàn hảo để bạn bắt đầu hành trình với React!

## Thành phần: Các khối xây dựng giao diện người dùng (UI)

Trên web, HTML cho phép chúng ta tạo ra các tài liệu có cấu trúc với bộ các thẻ tích hợp như `<h1>` và `<li>`:

```html
<article>
  <h1>My First Component</h1>
  <ol>
    <li>Components: UI Building Blocks</li>
    <li>Defining a Component</li>
    <li>Using a Component</li>
  </ol>
</article>
```

Đoạn mã này đại diện cho một bài viết `<article>`, tiêu đề của nó `<h1>`, và một bảng mục lục (rút gọn) dưới dạng danh sách có thứ tự `<ol>`. Markup như thế này, kết hợp với CSS để thiết kế và JavaScript để tạo sự tương tác, là cơ sở của mọi sidebar, avatar, modal, dropdown - mọi phần giao diện người dùng mà bạn thấy trên web.

React cho phép bạn kết hợp markup, CSS và JavaScript của bạn thành "thành phần" tùy chỉnh, đó là các yếu tố giao diện người dùng có thể tái sử dụng cho ứng dụng của bạn. Đoạn mã bảng mục lục bạn thấy ở trên có thể được chuyển thành một thành phần `<TableOfContents />` mà bạn có thể hiển thị trên mọi trang. Bên trong, nó vẫn sử dụng các thẻ HTML giống như `<article>`, `<h1>`, v.v.

Tương tự như các thẻ HTML, bạn có thể sáng tạo, sắp xếp và lồng ghép các thành phần để thiết kế trang web hoàn chỉnh. Ví dụ, trang tài liệu bạn đang đọc được tạo ra từ các thành phần React:

```jsx
<PageLayout>
  <NavigationHeader>
    <SearchBar />
    <Link to="/docs">Docs</Link>
  </NavigationHeader>
  <Sidebar />
  <PageContent>
    <TableOfContents />
    <DocumentationText />
  </PageContent>
</PageLayout>
```

Khi dự án của bạn phát triển, bạn sẽ nhận thấy rằng nhiều thiết kế có thể được tạo bằng cách sử dụng lại các thành phần bạn đã viết, giúp tăng tốc quá trình phát triển. Bảng mục lục của chúng tôi ở trên có thể được thêm vào bất kỳ màn hình nào với `<TableOfContents />`! Bạn thậm chí có thể khởi đầu dự án của bạn với hàng ngàn thành phần được chia sẻ bởi cộng đồng mã nguồn mở React như Chakra UI và Material UI.

## Định nghĩa một thành phần

Truyền thống khi tạo trang web, các nhà phát triển web đánh dấu nội dung của họ và sau đó thêm tính năng tương tác bằng cách trải đều một số mã JavaScript. Điều này hoạt động tốt khi tương tác chỉ là một tính năng bổ sung trên web. Bây giờ, việc tương tác được mong đợi đối với nhiều trang web và tất cả các ứng dụng. React đặt tính tương tác lên hàng đầu trong khi vẫn sử dụng cùng một công nghệ: một thành phần React là một hàm JavaScript bạn có thể nhúng mã markup vào. Dưới đây là cách đó trông như thế nào:

```jsx
import React from "react";

function Profile() {
  return <img src="https://i.imgur.com/MK3eW3Am.jpg" alt="Katherine Johnson" />;
}

export default Profile;
```

### Bước 1: Xuất thành phần

Tiền tố `export default` là một cú pháp JavaScript chuẩn (không riêng cho React). Nó cho phép bạn đánh dấu hàm chính trong một tệp để sau này bạn có thể nhập nó từ các tệp khác.

### Bước 2: Định nghĩa hàm

Với `function Profile() { }`, bạn định nghĩa một hàm JavaScript có tên là Profile.

### Bước 3: Thêm mã markup

Thành phần trả về một thẻ `<img />` với các thuộc tính `src` và `alt`. `<img />` được viết giống HTML, nhưng nó thực sự là JavaScript bên dưới! Cú pháp này được gọi là JSX và nó cho phép bạn nhúng mã markup vào trong JavaScript.

Câu lệnh `return` có thể được viết trên cùng một dòng, như trong thành phần này:

```jsx
return <img src="https://i.imgur.com/MK3eW3As.jpg" alt="Katherine Johnson" />;
```

Nhưng nếu mã markup của bạn

không nằm trên cùng một dòng với từ khóa `return`, bạn phải bọc nó trong một cặp dấu ngoặc đơn:

```jsx
return (
  <div>
    <img src="https://i.imgur.com/MK3eW3As.jpg" alt="Katherine Johnson" />
  </div>
);
```

## Sử dụng một thành phần

Bây giờ bạn đã định nghĩa thành phần Profile của mình, bạn có thể lồng nó vào bên trong các thành phần khác. Ví dụ, bạn có thể xuất một thành phần Gallery sử dụng nhiều thành phần Profile:

```jsx
import React from "react";

function Profile() {
  return <img src="https://i.imgur.com/MK3eW3As.jpg" alt="Katherine Johnson" />;
}

export default function Gallery() {
  return (
    <section>
      <h1>Amazing scientists</h1>
      <Profile />
      <Profile />
      <Profile />
    </section>
  );
}
```

Chú ý sự khác biệt trong việc viết hoa thường:

- `<section>` viết thường, vì vậy React biết chúng ta đang tham chiếu đến một thẻ HTML.
- `<Profile />` bắt đầu bằng chữ cái viết hoa, vì vậy React biết rằng chúng ta muốn sử dụng thành phần có tên Profile.
- Và Profile chứa thậm chí nhiều mã HTML hơn: `<img />`. Cuối cùng, đây là điều trình duyệt thấy:

```html
<section>
  <h1>Amazing scientists</h1>
  <img src="https://i.imgur.com/MK3eW3As.jpg" alt="Katherine Johnson" />
  <img src="https://i.imgur.com/MK3eW3As.jpg" alt="Katherine Johnson" />
  <img src="https://i.imgur.com/MK3eW3As.jpg" alt="Katherine Johnson" />
</section>
```

## Lồng và tổ chức các thành phần

Các thành phần là các hàm JavaScript thông thường, vì vậy bạn có thể giữ nhiều thành phần trong cùng một tệp. Điều này tiện lợi khi các thành phần có kích thước tương đối nhỏ hoặc liên quan mật thiết đến nhau. Nếu tệp này trở nên đông đúc, bạn luôn có thể di chuyển Profile vào một tệp riêng. Bạn sẽ tìm hiểu cách làm điều này trong thời gian tới trên trang về nhập (import).

Bởi vì các thành phần Profile được hiển thị trong Gallery - thậm chí nhiều lần! - nên chúng ta có thể nói rằng Gallery là một thành phần cha, hiển thị mỗi Profile như là một "con". Điều này là một phần của ma thuật của React: bạn có thể định nghĩa một thành phần một lần, sau đó sử dụng nó ở bất kỳ đâu và bao nhiêu lần bạn muốn.

::alert{type="success"}

Bạn vừa có cơ hội đầu tiên với React! Hãy tóm tắt một số điểm quan trọng.

- React cho phép bạn tạo thành phần, các yếu tố giao diện người dùng tái sử dụng cho ứng dụng của bạn.
- Trong ứng dụng React, mọi phần của giao diện người dùng là một thành phần.
- Các thành phần React là các hàm JavaScript thông thường, ngoại trừ:
  - Tên của chúng luôn bắt đầu bằng một chữ cái viết hoa.
  - Chúng trả về mã markup JSX.

::
