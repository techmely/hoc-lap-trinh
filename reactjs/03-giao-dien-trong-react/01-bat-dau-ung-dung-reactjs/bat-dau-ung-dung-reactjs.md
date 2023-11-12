---
title: "Ứng dụng đầu tiên với ReactJs"
description: "Dưới đây là một bài viết Ứng dụng đầu tiên với ReactJS giúp người mới học ReactJS"
chapter:
  name: "Giao diện trong Reactjs"
  slug: "chuong-03-giao-dien-trong-reactjs"
image: https://kungfutech.edu.vn/thumbnail.png
position: 1
---

::alert{type="warning"}
Trước khi đọc bài này, bạn cần [khởi tạo dự án ReactJs](/bai-viet/reactjs/khoi-tao-du-an-reactjs)
::

ReactJS là một thư viện JavaScript phổ biến được sử dụng để xây dựng giao diện người dùng (UI) tương tác. Trong bài viết này, chúng ta sẽ tạo một ứng dụng đơn giản sử dụng ReactJS để hiển thị danh sách công việc.

![Ứng dụng đầu tiên với ReactJs](https://github.com/techmely/hoc-lap-trinh/assets/29374426/d42aeace-486f-460d-a1ac-4c605cf62d7a)

## Bước 1: Chuẩn Bị Môi Trường

Đầu tiên, hãy chắc chắn bạn đã cài đặt Node.js trên máy tính của mình. Sau đó, sử dụng npm để cài đặt Create React App, công cụ giúp chúng ta nhanh chóng khởi tạo một dự án React.

```bash
npx create-react-app my-first-react-app
cd my-first-react-app
npm start
```

## Bước 2: Hiển Thị Danh Sách Công Việc

Mở file `src/App.js` và sửa nội dung như sau:

```jsx
import React from 'react';

function App() {
  const tasks = ['Learn React', 'Build an App', 'Enjoy Coding'];

  return (
    <div>
      <h1>My To-Do List</h1>
      <ul>
        {tasks.map((task, index) => (
          <li key={index}>{task}</li>
        ))}
      </ul>
    </div>
  );
}

export default App;
```

Ở đây, chúng ta đã tạo một mảng `tasks` và sử dụng phương thức `map` để render danh sách công việc.

## Bước 3: Chạy Ứng Dụng

Quay lại terminal và chạy ứng dụng React bằng lệnh:

```bash
npm start
```

Mở trình duyệt và truy cập [http://localhost:3000](http://localhost:3000), bạn sẽ thấy ứng dụng React của mình hiển thị danh sách công việc.

::alert{type="success"}

Chúc mừng bạn đã tạo thành công ứng dụng ReactJS đầu tiên của mình! Đây chỉ là một bước nhỏ trong hành trình học React, nhưng đồng thời là một bước quan trọng để làm quen với cách React hoạt động.

::
