---
title: "Side Effect là gì và useEffect trong React"
description: "useEffect là một trong những hooks quan trọng và phổ biến trong thư viện React. Nó cho phép bạn thực hiện các tác vụ phụ sau mỗi lần kết xuất của một component React"
chapter:
  name: "React nâng cao"
  slug: "chuong-06-react-nang-cao"
image: https://kungfutech.edu.vn/thumbnail.png
position: 3
---

`useEffect` là một trong những hooks quan trọng và phổ biến trong thư viện React. Nó cho phép thực hiện `side effect` bên trong các `function component`, còn side effect là gì thì chúng ta sẽ cùng nhau tìm hiểu trong bài này.

::alert{type="infor"}
Có thể bạn chưa biết: hooks là một tính năng mới được thêm vào React 16.8. Nó cho phép bạn có thể sử dụng state và các chứ năng khác của React mà không cần khởi tạo Class, điều đó có nghĩa là có thể sử dụng state trong functional component.
::

## Side Effect là gì

![Side Effect là gì](https://github.com/techmely/hoc-lap-trinh/assets/29374426/9aaac367-2f3d-443f-9cbb-76a0095467d5)

Nhiệm vụ của các component và React chủ yếu là tạo ra giao diện người dùng. React đảm bảo việc thay đổi các dữ liệu trên màn hình dựa vào dữ liệu và các tương tác với ứng dụng từ phía người dùng.

Tuy nhiên có rất nhiều những tương tác từ ứng dụng web tới nhiều thành phần khác nhau. Một vài ví dụ có thể kể ra là:

- Xử lý HTTP request, response
- Tương tác với Local Storage, Session Storage.
- Xử lý timer (`setTimeout`, `setInterval`)
- Thực hiện subscribes / unsubscribes các dịch vụ bên ngoài.
- Tương tác trực tiếp với DOM

Những logic được thực thi bên ngoài phạm vi của component đều được gọi là các “side effect”. Các side effect có thể cập nhật lại giao diện ứng dụng ở một thời điểm khác nhau.

Xét một ví dụ đơn giản như sau:

1. Người dùng tiến hành đăng nhập. Khi click vào button “Login”, tiến hành gửi thông tin user lên server.
2. Nếu người dùng nhập chính xác, tiến hành điều hướng về trang chủ.
3. Nếu người dùng nhập không chính xác, tiến hành hiển thị lỗi yêu cầu người dùng nhập lại.

Ở trong ví dụ trên, bước 1 là công việc của component. Tuy nhiên, bước 2 hoặc bước 3 sẽ được thực hiện dựa vào thông tin kết quả trả về. Đó có thể coi là các side effect, khi việc cập nhật giao diện ứng dụng sẽ phụ thuộc vào kết quả từ bên ngoài.

::alert{type="success"}
💡 Side effect là một khái niệm trong các ứng dụng nói chung, không chỉ riêng với React. Mỗi một công cụ sẽ có những cách khác nhau để xử lý các side effect. Vì vậy, việc hiểu rõ side effect là một điều quan trọng trong việc xây dựng các ứng dụng hiện đại.
::

</aside>

## Cách viết một Effect

Để xử lý các logic bên ngoài component, React cung cấp một function hook đặc biệt là `useEffect`. Cú pháp cơ bản của useEffect như sau:

`useEffect(() => { /* effect here */ })`

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

Mỗi khi component của bạn được render hoặc state của nó thay đổi, code bên trong Effect sẽ chạy.

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

Một số hiệu ứng cần phải "làm sạch" sau khi chạy. Điều này có thể là việc hủy các kết nối, gỡ bỏ các sự kiện, hoặc thực hiện bất kỳ hành động nào khác để đảm bảo rằng Effect không còn ảnh hưởng đến component của bạn sau khi nó đã được gọi.

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

Hãy xem xét một ví dụ cụ thể khi bạn muốn làm sạch `Effect` sau khi thay đổi trang.

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

1. **Mount và update:** Effects sẽ chạy sau mỗi lần render (mount và update), điều này bao gồm cả lần đầu tiên khi component được mount (kết xuất lần đầu tiên) và sau mỗi lần `state` hoặc `props` của `component` thay đổi.
2. **Khởi tạo (Initialization):** Effects cũng sẽ chạy sau lần đầu tiên component được mount, điều này có thể dẫn đến việc chúng chạy hai lần: lần đầu khi component được khởi tạo và lần thứ hai khi nó được render lại để cập nhật.

Để xác định lý do Effects chạy, bạn có thể sử dụng một điều kiện trong Effect hoặc truyền một mảng thứ hai chứa các phụ thuộc (dependencies). Nếu bạn chỉ muốn chạy Effect một lần sau khi component được mount, bạn có thể truyền một mảng rỗng như sau:

```jsx
useEffect(() => {
  // code ở đây sẽ chạy sau khi component được mount
}, []);
```

Nếu bạn muốn Effect chạy sau mỗi lần `userId` thay đổi, bạn có thể truyền `userId` vào mảng dependencies:

```jsx
useEffect(() => {
  // code ở đây sẽ chạy sau mỗi lần userId thay đổi
}, [userId]);
```

Nếu bạn để trống mảng dependencies hoặc không truyền nó, Effect sẽ chạy sau mỗi lần render (mount và update). Điều này có thể gây ra việc chạy Effects không cần thiết và làm tăng tải cho ứng dụng của bạn.
