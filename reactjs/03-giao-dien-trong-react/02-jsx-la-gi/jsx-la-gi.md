---
title: "JSX là gì?"
description: "Trong thế giới của ReactJS, JSX là một phần quan trọng và không thể thiếu. JSX viết tắt của JavaScript XML là một cú pháp mở rộng cho ngôn ngữ JavaScript, cho phép chúng ta mô tả giao diện người dùng (UI) một cách dễ dàng và rõ ràng hơn"
chapter:
  name: "Giao diện trong ReactJs"
  slug: "chuong-03-giao-dien-trong-reactjs"
image: https://kungfutech.edu.vn/thumbnail.png
position: 2
---

Trong thế giới của ReactJS, JSX (JavaScript XML) là một cú pháp mở rộng cho ngôn ngữ JavaScript, cho phép bạn viết markup giống HTML bên trong một tệp JavaScript. Mặc dù có cách khác để viết các thành phần, hầu hết các nhà phát triển React ưa chuộng sự ngắn gọn của JSX, và hầu hết các dự án mã nguồn mở sử dụng nó.

## Tại sao React kết hợp markup với logic hiển thị?

Trước đây, web được xây dựng dựa trên HTML, CSS và JavaScript. Trong nhiều năm, những nhà phát triển web đã giữ nội dung trong HTML, thiết kế trong CSS và logic trong JavaScript - thường là trong các tệp tin riêng biệt! Nội dung được đánh dấu trong HTML trong khi logic của trang web tồn tại riêng lẻ trong JavaScript.

Nhưng khi web trở nên tương tác hơn, logic ngày càng quyết định nội dung. JavaScript đã tiếp quản HTML! Điều này làm cho React, logic hiển thị và markup sống cùng nhau trong cùng một nơi - các thành phần.

### JSX: Đặt markup vào JavaScript

Mỗi thành phần React là một hàm JavaScript có thể chứa một số markup mà React sẽ hiển thị trên trình duyệt. Các thành phần React sử dụng một cú pháp mở rộng gọi là JSX để đại diện cho markup đó. JSX trông khá giống HTML, nhưng nó khá nghiêm ngặt hơn và có thể hiển thị thông tin động. Cách tốt nhất để hiểu điều này là chuyển đổi một số markup HTML thành markup JSX.

_Chú ý: JSX và React là hai thứ riêng biệt. Thường, chúng được sử dụng cùng nhau, nhưng bạn có thể sử dụng chúng độc lập. JSX là một cú pháp mở rộng, trong khi React là một thư viện JavaScript._

### Chuyển đổi HTML thành JSX

Hãy giả sử bạn có một đoạn mã HTML (hợp lệ):

```html
<h1>Todos của Hedy Lamarr</h1>
<img src="https://i.imgur.com/yXOvdOSs.jpg" alt="Hedy Lamarr" class="photo" />
<ul>
  <li>Phát minh đèn giao thông mới</li>
  <li>Luyện tập một cảnh phim</li>
  <li>Cải thiện công nghệ phổ</li>
</ul>
```

Và bạn muốn đặt nó vào thành phần của bạn:

```javascript
export default function TodoList() {
  return (
    // ???
  )
}
```

Nếu bạn sao chép và dán nó như vậy, nó sẽ không hoạt động:

```javascript
export default function TodoList() {
  return (
    // Đoạn mã này không hoạt động!
    <h1>Todos của Hedy Lamarr</h1>
    <img
      src="https://i.imgur.com/yXOvdOSs.jpg"
      alt="Hedy Lamarr"
      class="photo"
    >
    <ul>
      <li>Phát minh đèn giao thông mới
      <li>Luyện tập một cảnh phim
      <li>Cải thiện công nghệ phổ
    </ul>
  );
}
```

Điều này xảy ra vì JSX nghiêm ngặt hơn và có một số quy tắc nhiều hơn so với HTML! Nếu bạn đọc thông báo lỗi ở trên, chúng sẽ hướng dẫn bạn cách sửa markup hoặc bạn có thể làm theo hướng dẫn dưới đây.

::alert{type="warning"}
Chú ý: Hầu hết thời gian, các thông báo lỗi trên màn hình của React sẽ giúp bạn tìm đúng vị trí của vấn đề. Hãy đọc chúng nếu bạn gặp khó khăn!
::

### Quy tắc của JSX

#### Trả về một phần tử gốc duy nhất

Để trả về nhiều phần tử từ một thành phần, bạn cần bọc chúng trong một thẻ cha duy nhất. Ví dụ, bạn có thể sử dụng một thẻ `<div>`:

```javascript
<div>
  <h1>Todos của Hedy Lamarr</h1>
  <img
    src="https://i.imgur.com/yXOvdOSs.jpg"
    alt="Hedy Lamarr"
    class="photo"
  >
  <ul>
    ...
  </ul>
</div>
```

Nếu bạn không muốn thêm một thẻ `<div>` thừa vào trong markup của bạn, bạn có thể sử dụng `<>` và `</>` thay thế:

```javascript
<>
  <h1>Todos của Hedy Lamarr</h1>
  <img
    src="https://i.imgur.com/yXOvdOSs.jpg"
    alt="Hedy Lamarr"
    class="photo"
  >
  <ul>
    ...
  </ul>
</>
```

Thẻ rỗng này được gọi là Fragment. Fragment cho phép bạn nhóm các phần tử mà không để lại bất kỳ dấu vết nào trong cây HTML của trình duyệt.

#### Đóng tất cả các thẻ

JSX yêu cầu bạn phải đóng tất cả các thẻ rõ ràng: các thẻ tự đóng như `<img>` phải trở thành `<img />`, và các thẻ bao bọc như `<li>` phải được viết như `<li>Công việc</li>`.

Dưới đây là cách đóng thẻ hình ảnh của Hedy Lamarr và các mục danh sách:

```javascript
<>
  <img src="https://i.imgur.com/yXOvdOSs.jpg" alt="Hedy Lamarr" class="photo" />
  <ul>
    <li>Phát minh đèn giao thông mới</li>
    <li>Luyện tập một cảnh phim</li>
    <li>Cải thiện công nghệ phổ</li>
  </ul>
</>
```

#### Sử dụng camelCase cho hầu hết mọi thứ!

JSX biến thành JavaScript và các thuộc tính được viết trong JSX trở thành các khóa của các đối tượng JavaScript. Trong các thành phần của bạn, bạn thường muốn đọc các thuộc tính đó vào các biến. Tuy nhiên, JavaScript có hạn chế về tên biến. Ví dụ, tên biến không thể chứa dấu gạch ngang hoặc là từ khoá có sẵn như `class`.

Đây là lý do tại sao, trong React, nhiều thuộc tính HTML và SVG được viết theo kiểu camelCase. Ví dụ, thay vì viết `stroke-width`, bạn sử dụng `strokeWidth`. Vì `class` là từ khoá đã được dùng, trong React bạn viết `className` thay thế, lấy theo tên tương ứng của thuộc tính DOM:

```javascript
<img
  src="https://i.imgur.com/yXOvdOSs.jpg"
  alt="Hedy Lamarr"
  className="photo"
/>
```

Bạn có thể tìm tất cả các thuộc tính này trong danh sách các thuộc tính của thành phần DOM. Nếu bạn viết sai một trong số chúng, đừng lo - React sẽ in ra một thông báo với gợi ý sửa lỗi có thể trong console trình duyệt.

::alert{type="infor"}
Gợi ý: Sử dụng công cụ chuyển đổi JSX để giúp bạn chuyển đổi HTML và SVG hiện có sang JSX. Công cụ chuyển đổi rất hữu ích trong thực tế, nhưng hiểu rõ về cách thức hoạt động sẽ giúp bạn tự tin viết JSX một cách dễ dàng.
::

Dưới đây là kết quả cuối cùng của bạn:

```javascript
export default function TodoList() {
  return (
    <>
      <h1>Todos của Hedy Lamarr</h1>
      <img
        src="https://i.imgur.com/yXOvdOSs.jpg"
        alt="Hedy Lamarr"
        className="photo"
      />
      <ul>
        <li>Phát minh đèn giao thông mới</li>
        <li>Luyện tập một cảnh phim</li>
        <li>Cải thiện công nghệ phổ</li>
      </ul>
    </>
  );
}
```

::alert{type="success"}
Với JSX, bạn có thể kết hợp một cách dễ dàng markup giống HTML vào mã JavaScript của mình, tạo ra các thành phần React phong cách và mạnh mẽ. Hãy bắt đầu sử dụng JSX trong dự án React của bạn và trải nghiệm sự mạnh mẽ của nó.
::
