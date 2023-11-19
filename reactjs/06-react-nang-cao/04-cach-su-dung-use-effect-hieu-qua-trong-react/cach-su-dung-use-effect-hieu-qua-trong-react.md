---
title: "Cách sử dụng useEffect hiệu quả trong React"
description: "Trong React, useEffect là một trong những Hook quan trọng nhất giúp bạn quản lý các tác vụ không đồng bộ và tương tác với nhiều khía cạnh khác nhau của ứng dụng của bạn"
chapter:
  name: "React nâng cao"
  slug: "chuong-06-react-nang-cao"
image: https://kungfutech.edu.vn/thumbnail.png
position: 4
---

Trong React, [useEffect](/bai-viet/reactjs/use-effect-trong-react) là một trong những Hook quan trọng nhất giúp bạn quản lý các tác vụ không đồng bộ và tương tác với nhiều khía cạnh khác nhau của ứng dụng của bạn. Tuy nhiên, việc sử dụng `useEffect` một cách hiệu quả và đúng cách có thể không dễ dàng, và có thể dẫn đến những lỗi hoặc hiệu năng không tốt.

![Cách sử dụng useEffect hiệu quả trong React](https://github.com/techmely/hoc-lap-trinh/assets/29374426/5ec007e5-23dc-40a7-8100-cfd661477b10)

Trong bài viết này, chúng ta sẽ tìm hiểu về cách sử dụng `useEffect` một cách đúng đắn để đảm bảo rằng ứng dụng React của bạn hoạt động tốt, đơn giản hóa mã nguồn và tránh các lỗi phổ biến.

## Tại sao sử dụng `useEffect` trong React?

Trước khi chúng ta bắt đầu, hãy hiểu tại sao chúng ta cần sử dụng `useEffect` trong React:

- **Xử lý các tác vụ không đồng bộ**: `useEffect` cho phép bạn thực hiện các tác vụ không đồng bộ, chẳng hạn như gọi API, thao tác với DOM, hoặc làm bất kỳ việc nào mà cần thời gian để hoàn thành.
- **Synchronize với các thay đổi state hoặc props**: Bạn có thể sử dụng `useEffect` để thực hiện hành động khi `state` hoặc `props` của component thay đổi.

## Ví dụ về `useEffect` trong React

Trước tiên, hãy xem xét cách `useEffect` hoạt động trong React:

```jsx
import React, { useEffect, useState } from "react";

function ExampleComponent() {
  const [count, setCount] = useState(0);

  useEffect(() => {
    // Code trong useEffect sẽ thực hiện sau mỗi lần render
    document.title = `Count: ${count}`;
  }, [count]);

  return (
    <div>
      <p>Count: {count}</p>
      <button onClick={() => setCount(count + 1)}>Increase Count</button>
    </div>
  );
}

export default ExampleComponent;
```

Trong ví dụ trên, chúng ta đã sử dụng `useEffect` để cập nhật tiêu đề trang mỗi khi giá trị của `count` thay đổi. Tham số thứ hai của `useEffect` là một mảng `dependencies` (các phụ thuộc), trong đó chúng ta chỉ định rằng `useEffect` nên chạy lại chỉ khi `count` thay đổi.

## Cách sử dụng `useEffect` một cách hiệu quả

### Xử lý các tác vụ không đồng bộ

Khi bạn cần thực hiện các tác vụ không đồng bộ như gọi API, bạn nên đặt code này trong `useEffect`. Điều này đảm bảo rằng tác vụ này không ảnh hưởng đến quá trình render ban đầu và có thể thực hiện sau khi component đã được hiển thị trên giao diện người dùng.

```jsx
import React, { useEffect, useState } from "react";

function UserData() {
  const [user, setUser] = useState(null);

  useEffect(() => {
    // Gọi API để lấy thông tin người dùng
    fetch("https://api.example.com/user")
      .then((response) => response.json())
      .then((data) => setUser(data))
      .catch((error) => console.error("Error:", error));
  }, []);

  if (!user) {
    return <div>Loading...</div>;
  }

  return (
    <div>
      <h1>{user.name}</h1>
      <p>Email: {user.email}</p>
    </div>
  );
}

export default UserData;
```

### Synchronize với các thay đổi state hoặc props

Khi bạn muốn thực hiện hành động nào đó sau khi [state](/bai-viet/reactjs/state-trong-reactjs) hoặc [props](/bai-viet/reactjs/prop-va-truyen-prop-vao-component) của component thay đổi, bạn sử dụng `useEffect` với một danh sách `dependencies` (phụ thuộc) để chỉ định khi nào code nên được thực thi.

```jsx
import React, { useEffect, useState } from "react";

function ExampleComponent({ data }) {
  const [processedData, setProcessedData] = useState(null);

  useEffect(() => {
    // Xử lý dữ liệu mỗi khi `data` thay đổi
    if (data) {
      const processed = processData(data);
      setProcessedData(processed);
    }
  }, [data]);

  return (
    <div>
      {/* Hiển thị dữ liệu đã được xử lý */}
      {processedData && <p>{processedData}</p>}
    </div>
  );
}

export default ExampleComponent;
```

### Tránh việc gọi `setState` trong `useEffect`

Một lưu ý quan trọng là tránh việc gọi `setState` trong `useEffect` mà không sử dụng dependencies thích hợp. Nếu bạn không cẩn thận, điều này có thể dẫn đến vòng lặp vô tận và gây ra sự cố hiệu năng.

```jsx
import React, { useEffect, useState } from '

react';

function ExampleComponent() {
  const [count, setCount] = useState(0);

  useEffect(() => {
    // Gây ra vòng lặp vô tận! Không bao giờ làm như vậy.
    setCount(count + 1);
  }, []); // Dependency array rỗng

  return (
    <div>
      <p>Count: {count}</p>
    </div>
  );
}

export default ExampleComponent;
```

### Xử lý dọn dẹp

Trong một số trường hợp, bạn có thể muốn thực hiện một số tác vụ dọn dẹp khi `component unmount` hoặc khi `dependencies` thay đổi. Điều này có thể được thực hiện bằng cách trả về một hàm từ `useEffect`:

```jsx
import React, { useEffect, useState } from "react";

function ExampleComponent() {
  const [data, setData] = useState(null);

  useEffect(() => {
    // Khởi tạo và thiết lập sự kiện khi component được mount
    fetchData();

    // Cleanup function: Được gọi khi component unmount hoặc dependencies thay đổi
    return () => {
      // Hủy đăng ký sự kiện hoặc thực hiện các công việc dọn dẹp khác
      cleanup();
    };
  }, [data]);

  const fetchData = async () => {
    // Gọi API hoặc thực hiện các công việc không đồng bộ khác
    const result = await fetch("https://api.example.com/data");
    const data = await result.json();
    setData(data);
  };

  const cleanup = () => {
    // Thực hiện các công việc dọn dẹp ở đây
  };

  return (
    <div>
      {/* Hiển thị dữ liệu */}
      {data && <p>{data}</p>}
    </div>
  );
}

export default ExampleComponent;
```
