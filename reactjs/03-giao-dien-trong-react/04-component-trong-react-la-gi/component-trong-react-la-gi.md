---
title: "Component trong React là gì?"
description: "Component (các thành phần) là một trong những khái niệm cốt lõi của React. Chúng là nền tảng để bạn xây dựng giao diện người dùng (UI), điều này biến chúng trở thành nơi tuyệt vời để bạn bắt đầu hành trình với React!"
chapter:
  name: "Giao diện trong Reactjs"
  slug: "chuong-03-giao-dien-trong-reactjs"
image: https://kungfutech.edu.vn/thumbnail.png
position: 4
---

**Components (các thành phần)** là một trong những khái niệm cốt lõi của React. Chúng là nền tảng để bạn xây dựng giao diện người dùng (UI), điều này biến chúng trở thành nơi tuyệt vời để bạn bắt đầu hành trình với React!

## Components: Những Khối Xây Dựng Giao Diện Người Dùng

Trên web, HTML cho phép chúng ta tạo ra các tài liệu có cấu trúc phong phú với các thẻ tích hợp như `<h1>` và `<li>`:

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

Markup này đại diện cho bài viết này `<article>`, tiêu đề của nó `<h1>`, và một bảng mục lục (rút gọn) dưới dạng danh sách đã sắp xếp `<ol>`. Markup như vậy, kết hợp với CSS để thiết kế và JavaScript để tương tác, đứng đằng sau mọi thanh bên, hình đại diện, hộp thoại modal, menu thả xuống - mọi thành phần giao diện người dùng bạn thấy trên web.

React cho phép bạn kết hợp markup, CSS và JavaScript của bạn thành các "component" (thành phần) tùy chỉnh, các phần tử giao diện người dùng có thể sử dụng lại trong ứng dụng của bạn. Mã của bảng mục lục bạn thấy ở trên có thể được chuyển thành một `<TableOfContents />` component mà bạn có thể render ở mọi trang. Bên trong, nó vẫn sử dụng các thẻ HTML giống như `<article>`, `<h1>`, vv.

Tương tự như với các thẻ HTML, bạn có thể xây dựng và lồng ghép các component để thiết kế toàn bộ trang web. Ví dụ, trang tài liệu bạn đang đọc được tạo ra từ các component React:

```javascript
<PageLayout>
  <NavigationHeader>
    <SearchBar />
    <Link to="/docs">Tài liệu</Link>
  </NavigationHeader>
  <Sidebar />
  <PageContent>
    <TableOfContents />
    <DocumentationText />
  </PageContent>
</PageLayout>
```

Khi dự án của bạn phát triển, bạn sẽ nhận thấy rằng nhiều thiết kế của bạn có thể được tạo bằng cách sử dụng lại các component bạn đã viết, giúp tăng tốc quá trình phát triển. Bảng mục lục của chúng ta ở trên có thể được thêm vào bất kỳ màn hình nào với `<TableOfContents />`! Bạn cũng có thể khởi đầu dự án của mình với hàng ngàn component được chia sẻ bởi cộng đồng mã nguồn mở React như Chakra UI và Material UI.

## Định Nghĩa Một Component

Truyền thống khi tạo trang web, các nhà phát triển web đánh dấu nội dung của họ sau đó thêm tính năng tương tác thông qua JavaScript. Điều này hoạt động tốt khi tương tác chỉ là một lợi ích thêm vào trang web. Nhưng bây giờ nó được mong đợi trong nhiều trang web và tất cả các ứng dụng. React đặt tính tương tác lên hàng đầu trong khi vẫn sử dụng cùng một công nghệ: một React component là một hàm JavaScript mà bạn có thể nhúng mã markup vào. Dưới đây là ví dụ (bạn có thể chỉnh sửa ví dụ dưới đây):

```javascript
export default function Profile() {
  return <img src="https://i.imgur.com/MK3eW3Am.jpg" alt="Katherine Johnson" />;
}
```

Và đây là cách xây dựng một component:

### Bước 1: Xuất Component

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

## Sử Dụng Một Component

Bây giờ khi bạn đã định nghĩa component Profile của mình, bạn có thể lồng nó vào bên trong các component khác. Ví dụ, bạn có thể xuất một component Gallery sử dụng nhiều component Profile:

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
- `<Profile />` bắt đầu bằng chữ cái viết hoa, vì vậy React biết rằng chúng ta muốn sử dụng component của mình có tên là Profile.
- Và Profile chứa thậm chí nhiều HTML hơn: `<img />`. Cuối cùng, đây là điều trình duyệt thấy:

```html
<section>
  <h1>Các nhà khoa học tuyệt vời</h1>
  <img src="https://i.imgur.com/MK3eW3As.jpg" alt="Katherine Johnson" />
  <img src="https://i.imgur.com/MK3eW3As.jpg" alt="Katherine Johnson" />
  <img src="https://i.imgur.com/MK3eW3As.jpg" alt="Katherine Johnson" />
</section>
```

## Lồng Và Tổ Chức Các Component

Các component là các hàm JavaScript thông thường, vì vậy bạn có thể chứa nhiều component trong cùng một tệp. Điều này tiện lợi khi các component tương đối nhỏ hoặc liên quan chặt chẽ đến nhau. Nếu tệp trở nên đông đúc, bạn luôn có thể di chuyển component Profile của mình vào một tệp riêng. Bạn sẽ học cách làm điều này sớm trong phần về nhập.

Bởi vì các component Profile được render bên trong Gallery - thậm chí có thể là nhiều lần! - chúng ta có thể nói rằng Gallery là một component cha, render từng Profile như một "con". Điều này là một phần của ma thuật của React: bạn có thể định nghĩa một component một lần, và sau đó sử dụng nó ở bất kỳ đâu và bất kỳ khi nào bạn muốn.

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

::alert{type="warning"}
Lưu ý: khi một component con cần một số dữ liệu từ một component cha, hãy truyền nó qua props thay vì lồng định nghĩa.
::
