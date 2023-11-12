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

### Truyền thuộc tính chuỗi vào JSX

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

### Sử Dụng Cặp Dấu Ngoặc Nhọn: Cửa Sổ Tới Thế Giới JavaScript

JSX là một cách đặc biệt để viết JavaScript. Điều đó có nghĩa là bạn có thể sử dụng JavaScript bên trong JSX - với cặp dấu ngoặc nhọn `{}`. Ví dụ dưới đây trước tiên khai báo tên của nhà khoa học, name, sau đó nhúng nó bằng cặp dấu ngoặc nhọn bên trong thẻ `<h1>`:

```javascript
import React from "react";

export default function TodoList() {
  const name = "Gregorio Y. Zara";
  return <h1>{name}'s Danh Sách Công Việc</h1>;
}
```

Hãy thử thay đổi giá trị của name từ 'Gregorio Y. Zara' thành 'Hedy Lamarr'. Bạn sẽ thấy tiêu đề danh sách thay đổi ngay lập tức.

Bất kỳ biểu thức JavaScript nào cũng sẽ hoạt động bên trong cặp dấu ngoặc nhọn, bao gồm cả việc gọi hàm như formatDate():

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

### Nơi Sử Dụng Cặp Dấu Ngoặc Nhọn

Bạn chỉ có thể sử dụng cặp dấu ngoặc nhọn trong JSX theo hai cách:

1. Như văn bản trực tiếp bên trong một thẻ JSX: `<h1>{name}'s Danh Sách Công Việc</h1>` hoạt động, nhưng <{tag}>Danh Sách Công Việc Của Gregorio Y. Zara</{tag}> sẽ không hoạt động.
2. Là thuộc tính ngay sau dấu =: src={avatar} sẽ đọc biến avatar, nhưng src="{avatar}" sẽ truyền chuỗi "{avatar}".

### Sử Dụng "Cặp Dấu Ngoặc Nhọn Gấp Đôi": CSS Và Các Đối Tượng Khác Trong JSX

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

Hãy thử thay đổi giá trị của backgroundColor và color.

Khi bạn viết như sau, bạn có thể thấy đối tượng JavaScript bên trong cặp dấu ngoặc nhọn một cách rõ ràng hơn:

```javascript
<ul style={
  {
    backgroundColor: 'black',
    color: 'pink'
  }
}>
```

Khi bạn thấy {{ và }} trong JSX, hãy biết rằng đó chỉ là một đối tượng bên trong cặp dấu ngoặc nhọn JSX, không có cú pháp đặc biệt.

### Thêm Vui Vẻ Với Đối Tượng JavaScript Và Cặp Dấu Ngoặc Nhọn

Bạn có thể đặt nhiều biểu thức vào một đối tượng và tham chiếu đến chúng trong JSX bên trong cặp dấu ngoặc nhọn:

```javascript
import React from "react";

const person = {
  name: "Gregorio Y. Zara",
  theme: {
    backgroundColor: "black",
    color: "pink",
  },
};

export default function TodoList() {
  return (
    <div style={person.theme}>
      <h1>{person.name}'s Danh Sách Công Việc</h1>
      <img
        className="avatar"
        src="https://i.imgur.com/7vQD0fPs.jpg"
        alt="Gregorio Y. Zara"
      />
      <ul>
        <li>Cải thiện videophone</li>
        <li>Chuẩn bị bài giảng về aeronautics</li>
        <li>Làm việc trên động cơ chạy bằng cồn</li>
      </ul>
    </div>
  );
}
```

Trong ví dụ này, đối tượng JavaScript person chứa một chuỗi name và một đối tượng theme:

```javascript
const person = {
  name: "Gregorio Y. Zara",
  theme: {
    backgroundColor: "black",
    color: "pink",
  },
};
```

Thành phần có thể sử dụng các giá trị từ person như sau:

```javascript
<div style={person.theme}>
  <h1>{person.name}'s Danh Sách Công Việc</h1>
```

JSX rất tối giản như một ngôn ngữ mẫu bởi vì nó cho phép bạn tổ chức dữ liệu và logic bằng JavaScript.

::alert{type="success"}

Bây giờ bạn đã biết gần như mọi thứ về JSX:

- Các thuộc tính JSX trong dấu ngoặc kép được truyền dưới dạng chuỗi.
- Cặp dấu ngoặc nhọn cho phép bạn đưa logic và biến JavaScript vào trong markup của bạn.
- Chúng hoạt động bên trong nội dung thẻ JSX hoặc ngay sau dấu = trong thuộc tính.
- `{{ và }}` không phải là cú pháp đặc biệt: đó chỉ là một đối tượng JavaScript bên trong cặp dấu ngoặc nhọn JSX.

::
