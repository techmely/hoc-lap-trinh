---
title: "Render các element trong React"
description: "Bài viết này sẽ hướng dẫn bạn cách render các phần tử trong React bằng JSX và cách sử dụng cặp dấu ngoặc nhọn {} để tích hợp mã JavaScript vào trong JSX"
chapter:
  name: "Giao diện trong Reactjs"
  slug: "chuong-03-giao-dien-trong-reactjs"
image: https://kungfutech.edu.vn/thumbnail.png
position: 3
---

[JSX](/bai-viet/reactjs/jsx-la-gi) cho phép bạn viết markup giống HTML bên trong tệp JavaScript, giúp giữ logic hiển thị và nội dung ở cùng một nơi. Đôi khi bạn sẽ muốn thêm một chút logic JavaScript hoặc tham chiếu đến một thuộc tính động bên trong markup đó. Trong tình huống này, bạn có thể sử dụng cặp dấu ngoặc nhọn trong JSX để mở cửa sổ tới JavaScript.

### Sử dụng biến để truyền vào JSX

Khi bạn muốn truyền một thuộc tính chuỗi vào JSX, bạn đặt nó trong dấu ngoặc kép hoặc ngoặc đơn:

```javascript
import React from "react";

export default function Avatar() {
  return (
    <img
      className="avatar"
      src="https://i.imgur.com/7vQD0fPs.jpg"
      alt="Gregorio Y. Zara"
    />
  );
}
```

Ở đây, "https://i.imgur.com/7vQD0fPs.jpg" và "Gregorio Y. Zara" đều được truyền dưới dạng chuỗi.

Nhưng nếu bạn muốn chỉ định động `src` hoặc `alt` text, bạn có thể sử dụng một giá trị từ JavaScript bằng cách thay `" và "` bằng `{ và }`:

```javascript
import React from "react";

export default function Avatar() {
  const avatar = "https://i.imgur.com/7vQD0fPs.jpg";
  const description = "Gregorio Y. Zara";
  return <img className="avatar" src={avatar} alt={description} />;
}
```

Ở đây, chúng ta sử dụng cặp ngoặc nhọn để đọc giá trị từ biến JavaScript, ví dụ: `src={avatar}` và `alt={description}`.

### Sử dụng hàm để truyền vào JSX

Bất kỳ biểu thức JavaScript nào cũng sẽ hoạt động bên trong cặp dấu ngoặc nhọn, bao gồm cả việc gọi hàm như `formatDate()`:

```javascript
import React from "react";

const today = new Date();

function formatDate(date) {
  return new Intl.DateTimeFormat("en-US", { weekday: "long" }).format(date);
}

export default function TodoList() {
  return <h1>Danh Sách Công Việc Cho Ngày {formatDate(today)}</h1>;
}
```

### Sử dụng CSS để truyền vào JSX

Ngoài chuỗi, số và biểu thức JavaScript khác, bạn có thể truyền đối tượng trong JSX. Đối tượng cũng được đánh dấu bằng cặp dấu ngoặc nhọn, ví dụ như `{ name: "Hedy Lamarr", inventions: 5 }`. Do đó, để truyền một đối tượng JS trong JSX, bạn phải bọc đối tượng trong một cặp dấu ngoặc nhọn khác: `person={{ name: "Hedy Lamarr", inventions: 5 }}`.

Bạn có thể thấy điều này trong các kiểu CSS nội tuyến trong JSX. React không yêu cầu bạn phải sử dụng kiểu nội tuyến (lớp CSS hoạt động tốt cho hầu hết các trường hợp). Nhưng khi bạn cần một kiểu nội tuyến, bạn truyền một đối tượng cho thuộc tính style:

```javascript
import React from "react";

export default function TodoList() {
  return (
    <ul
      style={{
        backgroundColor: "black",
        color: "pink",
      }}
    >
      <li> Cải thiện videophone</li>
      <li> Chuẩn bị bài giảng về aeronautics</li>
      <li> Làm việc trên động cơ chạy bằng cồn</li>
    </ul>
  );
}
```

Hãy thử thay đổi giá trị của `backgroundColor` và `color`.

Khi bạn viết như sau, bạn có thể thấy đối tượng JavaScript bên trong cặp dấu ngoặc nhọn một cách rõ ràng hơn:

```javascript
<ul style={
  {
    backgroundColor: 'black',
    color: 'pink'
  }
}>
```

Khi bạn thấy `{{ và }}` trong JSX, hãy biết rằng đó chỉ là một đối tượng bên trong cặp dấu ngoặc nhọn JSX, không có cú pháp đặc biệt.


::alert{type="success"}

Bây giờ bạn đã biết gần như mọi thứ về JSX:

- Các thuộc tính JSX trong dấu ngoặc kép được truyền dưới dạng chuỗi.
- Cặp dấu ngoặc nhọn cho phép bạn đưa logic và biến JavaScript vào trong markup của bạn.
- Chúng hoạt động bên trong nội dung thẻ JSX hoặc ngay sau dấu = trong thuộc tính.
- `{{ và }}` không phải là cú pháp đặc biệt: đó chỉ là một đối tượng JavaScript bên trong cặp dấu ngoặc nhọn JSX.

::
