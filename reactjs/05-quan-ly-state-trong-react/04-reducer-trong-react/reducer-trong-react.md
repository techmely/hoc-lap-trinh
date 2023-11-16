---
title: "Reducer trong React"
description: "Trong bài viết này, chúng ta sẽ tìm hiểu về cách sử dụng một kỹ thuật gọi là reducer để tối ưu hóa việc quản lý state trong React"
chapter:
  name: "Quản lý state trong React"
  slug: "chuong-05-quan-ly-state-trong-react"
image: https://kungfutech.edu.vn/thumbnail.png
position: 4
---

Trong React, [state](/bai-viet/reactjs/state-trong-reactjs) là một khái niệm quan trọng giúp bạn lưu trữ và quản lý dữ liệu trong các `component`. State giúp bạn theo dõi các thay đổi và cập nhật giao diện người dùng dựa trên sự tương tác của người dùng hoặc dữ liệu từ máy chủ. Tuy nhiên, khi các `component` phức tạp và nhiều tương tác, việc quản lý `state` có thể trở nên lộn xộn và khó kiểm soát thì chúng ta có thể nghĩ đến việc sử dụng Reducer

![Reducer trong React](https://github.com/techmely/hoc-lap-trinh/assets/29374426/323678bc-4348-40fd-b32e-e7f6c55ac819)

Trong bài viết này, chúng ta sẽ tìm hiểu về cách sử dụng một kỹ thuật gọi là "reducer" để tối ưu hóa việc quản lý `state` trong React.

## Reducer là gì?

Một reducer là một hàm JavaScript đơn giản nhận vào hai đối số chính: `state` và một đối tượng hành động (action). Nó sau đó trả về `state` mới dựa trên hành động đó. Ví dụ:

```jsx
function reducer(state, action) {
  // Xử lý hành động và trả về `state` mới
  return newState;
}
```

## Chuyển từ `useState` sang `useReducer`

Khi bạn phải quản lý nhiều `state` và có nhiều tương tác khác nhau trong một `component`, việc sử dụng `useState` có thể dẫn đến việc `state` và logic xử lý trải rải rác trong code. Điều này có thể khiến code trở nên khó hiểu và bảo trì.

Thay vì sử dụng `useState`, bạn có thể chuyển sang sử dụng `useReducer`. Quy trình chuyển đổi từ `useState` sang `useReducer` bao gồm các bước sau:

### Bước 1: Chuyển từ việc thiết lập `state` sang việc gửi các hành động

Thay vì thiết lập `state` trực tiếp trong các xử lý sự kiện, bạn sẽ gửi các hành động thông qua một hàm gọi là `dispatch`. Ví dụ:

Trước đây:

```jsx
const [count, setCount] = useState(0);

function increment() {
  setCount(count + 1);
}
```

Sau khi chuyển sang `useReducer`:

```jsx
const initialState = 0;

function reducer(state, action) {
  switch (action.type) {
    case "INCREMENT":
      return state + 1;
    default:
      return state;
  }
}

const [count, dispatch] = useReducer(reducer, initialState);

function increment() {
  dispatch({ type: "INCREMENT" });
}
```

### Bước 2: Viết một reducer function

Bạn cần viết một reducer function để xử lý các hành động mà bạn muốn thực hiện trên `state`. Trong ví dụ trên, reducer function xử lý hành động** "INCREMENT"** bằng cách tăng giá trị `state` lên 1.

### Bước 3: Sử dụng `useReducer` trong `component` của bạn

Cuối cùng, bạn sẽ sử dụng `useReducer` trong `component` của bạn để quản lý `state` và gửi các hành động khi cần thiết.

## Tại sao sử dụng Reducer trong React?

Sử dụng `reducer` có một số ưu điểm sau:

1. **Dễ quản lý:** Reducer giúp bạn tạo một trung tâm xử lý `state` trong ứng dụng của bạn. Tất cả các thay đổi `state` đều được quản lý tập trung trong reducer, làm cho code trở nên dễ đọc và dễ bảo trì hơn.
2. **Tích hợp:** Với reducer, bạn có thể tích hợp tất cả các hành động xử lý liên quan đến `state` vào một nơi duy nhất. Điều này giúp bạn dễ dàng kiểm soát các hành động và giảm nguy cơ xảy ra lỗi.
3. **Dễ test:** Reducer là các hàm JavaScript, có thể dễ dàng test độc lập. Bạn có thể viết các unit test cho reducer của bạn để đảm bảo tính chính xác và tạo code ổn định hơn.
4. **Mở rộng:** Khi ứng dụng của bạn phát triển và có thêm các hành động phức tạp, reducer giúp bạn mở rộng một cách dễ dàng bằng cách thêm các trường hợp xử lý hành động mới.

## Ví dụ về sử dụng Reducer trong React

Dưới đây là một ví dụ đơn giản về việc sử dụng reducer trong React để quản lý `state` của một đếm số:

```jsx
import React, { useReducer } from "react";

// Khởi tạo `state` ban đầu
const initialState = { count: 0 };

// Hàm reducer xử lý các hành động
function reducer(state, action) {
  switch (action.type) {
    case "INCREMENT":
      return { count: state.count + 1 };
    case "DECREMENT":
      return { count: state.count - 1 };
    default:
      return state;
  }
}

function Counter() {
  // Sử dụng useReducer với reducer và initialState
  const [state, dispatch] = useReducer(reducer, initialState);

  return (
    <div>
      <p>Count: {state.count}</p>
      <button onClick={() => dispatch({ type: "INCREMENT" })}>Increment</button>
      <button onClick={() => dispatch({ type: "DECREMENT" })}>Decrement</button>
    </div>
  );
}

export default Counter;
```

::alert{type="success"}
Khi bạn cần quản lý `state` phức tạp hoặc khi muốn tối ưu hóa việc quản lý `state` trong React, việc sử dụng reducer là một lựa chọn tối ưu. Bằng cách gửi các hành động thông qua reducer, bạn có thể kiểm soát `state` của ứng dụng một cách rõ ràng và hiệu quả. Việc này giúp code dễ đọc, dễ bảo trì và dễ kiểm tra.
::
