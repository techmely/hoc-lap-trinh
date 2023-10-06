---
title: "useEffect trong React"
description: "useEffect là một trong những hooks quan trọng và phổ biến trong thư viện React. Nó cho phép bạn thực hiện các tác vụ phụ sau mỗi lần kết xuất của một component React"
chapter:
  name: "React nâng cao"
  slug: "chuong-06-react-nang-cao"
image: https://kungfutech.edu.vn/thumbnail.png
position: 3
---

`useEffect` là một trong những hooks quan trọng và phổ biến trong thư viện React. Nó cho phép bạn thực hiện các tác vụ phụ sau mỗi lần kết xuất của một component React. Điều này rất hữu ích khi bạn cần đồng bộ hóa component của mình với các hệ thống bên ngoài như API, kết nối máy chủ, hoặc thậm chí là cài đặt các lắng nghe sự kiện.

## Effects là gì và sự khác biệt so với sự kiện?

Trước khi tìm hiểu về Effects, hãy hiểu về hai loại logic trong component React:

- Mã kết xuất (Rendering code): Đây là nơi bạn nhận `props` và `state`, biến đổi chúng và trả về JSX bạn muốn hiển thị trên màn hình. Mã kết xuất phải là hàm tĩnh, giống như một công thức toán, nó chỉ tính toán kết quả mà không thực hiện bất kỳ điều gì khác.
- Xử lý sự kiện (Event handlers): Đây là các hàm lồng nhau trong component của bạn thực hiện các hành động thay vì chỉ tính toán chúng. Một xử lý sự kiện có thể cập nhật một trường nhập, gửi yêu cầu `HTTP POST` để mua một sản phẩm hoặc điều hướng người dùng đến màn hình khác.

Tuy nhiên, đôi khi điều này chưa đủ. Hãy xem xét một ví dụ về component ChatRoom mà phải kết nối với máy chủ chat mỗi khi nó hiển thị trên màn hình. Kết nối với máy chủ không phải là một tính toán tĩnh (nó là một hiệu ứng phụ), vì vậy nó không thể xảy ra trong quá trình kết xuất. Tuy nhiên, không có một sự kiện cụ thể nào giống như một cú nhấp chuột mà khiến ChatRoom xuất hiện.

Effects cho phép bạn chỉ định các hiệu ứng phụ được gây ra bởi việc kết xuất chính nó, chứ không phải là do một sự kiện cụ thể nào đó. Việc gửi một tin nhắn trong cuộc trò chuyện là một sự kiện vì nó được gây ra trực tiếp bởi người dùng nhấp vào một nút cụ thể. Tuy nhiên, thiết lập kết nối máy chủ là một Effect vì nó nên xảy ra dù làm thế nào mà người dùng tương tác với component.

`useEffect` giúp bạn quản lý hiệu suất của ứng dụng và đảm bảo rằng các tác vụ không liên quan đến mã kết xuất chính của bạn vẫn được thực hiện một cách đáng tin cậy. Bạn có thể xác định điều kiện chạy Effect và cũng có thể làm sạch nó sau khi không cần thiết.

Trong đoạn mã React, bạn có thể gọi `useEffect` và truyền một hàm vào đó để định nghĩa các tác vụ cụ thể mà bạn muốn thực hiện. Điều này giúp bạn tách biệt logic của bạn ra khỏi mã kết xuất chính và giữ cho mã của bạn dễ đọc và dễ bảo trì.

## Khi nào bạn không cần Effects?

Không nên vội vàng thêm Effects vào các component của bạn. Hãy nhớ rằng Effects thường được sử dụng để "thoát ra" khỏi mã React của bạn và đồng bộ hóa với một số hệ thống bên ngoài như các API trình duyệt, tiện ích của bên thứ ba hoặc mạng và vân vân. Nếu Effects của bạn chỉ điều chỉnh trạng thái dựa trên trạng thái khác, bạn có thể không cần Effects.

## Cách viết một Effect

Để viết một Effect, bạn thực hiện ba bước sau:

### Bước 1: Khai báo một Effect

Để khai báo một Effect trong component của bạn, bạn cần import `useEffect` từ React và sau đó gọi nó ở cấp độ hàng đầu của component của bạn và đặt mã của bạn vào bên trong Effect như sau:

```jsx
import { useEffect } from "react";

function MyComponent() {
  useEffect(() => {
    // Mã ở đây sẽ chạy sau mỗi lần kết xuất
  });
  return <div />;
}
```

Mỗi khi component của bạn được kết xuất hoặc trạng thái của nó thay đổi, mã bên trong Effect sẽ chạy.

### Bước 2: Xác định điều kiện chạy

Nếu bạn muốn chỉ chạy Effect trong một số trường hợp cụ thể, bạn có thể truyền một mảng thứ hai là danh sách các biến hoặc giá trị phụ thuộc vào Effect. Effect sẽ chỉ chạy lại nếu bất kỳ biến nào trong danh sách thay đổi.

Ví dụ, nếu bạn muốn chỉ gửi yêu cầu API lại khi `userId` thay đổi, bạn có thể làm như sau:

```jsx
import { useEffect, useState } from "react";

function UserProfile({ userId }) {
  const [user, setUser] = useState(null);

  useEffect(() => {
    // Gửi yêu cầu API và cập nhật user
  }, [userId]);

  // ...
}
```

### Bước 3: Làm sạch Effect

Một số hiệu ứng cần phải "làm sạch" sau khi chạy. Điều này có thể là việc hủy các kết nối, gỡ bỏ các lắng nghe sự kiện, hoặc thực hiện bất kỳ hành động nào khác để đảm bảo rằng Effect không còn ảnh hưởng đến component của bạn sau khi nó đã được gọi.

Bạn có thể thực hiện các công việc này bằng cách trả về một hàm từ Effect:

```jsx
import { useEffect } from "react";

function MyComponent() {
  useEffect(() => {
    // Mã ở đây sẽ chạy sau mỗi lần kết xuất

    return () => {
      // Mã để làm sạch Effect ở đây
    };
  });
  return <div />;
}
```

Hãy xem xét một ví dụ cụ thể khi bạn muốn làm sạch Effect sau khi thay đổi trang.

```jsx
import { useEffect } from "react";

function MyComponent() {
  useEffect(() => {
    document.title = "Trang chủ";

    return () => {
      document.title = "Ứng dụng React"; // Đặt lại tiêu đề sau khi rời khỏi trang
    };
  }, []); // Truyền mảng rỗng để chỉ chạy một lần sau khi mount

  return <div />;
}
```

## Lý do Effects chạy hai lần trong quá trình phát triển và cách sửa lỗi

Một điều quan trọng để hiểu về Effects trong React là chúng có thể chạy hai lần trong quá trình phát triển. Điều này thường xảy ra trong hai tình huống sau:

1. **Mount và update:** Effects sẽ chạy sau mỗi lần kết xuất (mount và update). Điều này bao gồm cả lần đầu tiên khi component được mount (kết xuất lần đầu tiên) và sau mỗi lần trạng thái hoặc props của component thay đổi.
2. **Khởi tạo (Initialization):** Effects cũng sẽ chạy sau lần đầu tiên component được mount. Điều này có thể dẫn đến việc chúng chạy hai lần: lần đầu khi component được khởi tạo và lần thứ hai khi nó được render lại để cập nhật.

Để xác định lý do Effects chạy, bạn có thể sử dụng một điều kiện trong Effect hoặc truyền một mảng thứ hai chứa các phụ thuộc (dependencies). Nếu bạn chỉ muốn chạy Effect một lần sau khi component được mount, bạn có thể truyền một mảng rỗng như sau:

```jsx
useEffect(() => {
  // Mã ở đây sẽ chạy sau khi component được mount
}, []);
```

Nếu bạn muốn Effect chạy sau mỗi lần `userId` thay đổi, bạn có thể truyền `userId` vào mảng dependencies:

```jsx
useEffect(() => {
  // Mã ở đây sẽ chạy sau mỗi lần userId thay đổi
}, [userId]);
```

Nếu bạn để trống mảng dependencies hoặc không truyền nó, Effect sẽ chạy sau mỗi lần kết xuất (mount và update). Điều này có thể gây ra việc chạy Effects không cần thiết và làm tăng tải cho ứng dụng của bạn.

::alert{type="success"}

- Effects trong ReactJS cho phép bạn đồng bộ hóa component của mình với các hệ thống bên ngoài và thực hiện các tác vụ phụ sau mỗi lần kết xuất. Điều này giúp bạn quản lý các tác vụ như gọi API, kết nối máy chủ, hoặc thậm chí cài đặt các lắng nghe sự kiện.
- Hãy nhớ rằng không phải tất cả các tác vụ đều cần Effects. Bạn nên sử dụng Effects khi bạn muốn thực hiện các tác vụ không liên quan đến mã kết xuất chính của bạn và cần đảm bảo rằng chúng được đồng bộ hóa với trạng thái của bạn. Điều này giúp bạn quản lý hiệu suất của ứng dụng và tránh chạy lại mã không cần thiết.

::
