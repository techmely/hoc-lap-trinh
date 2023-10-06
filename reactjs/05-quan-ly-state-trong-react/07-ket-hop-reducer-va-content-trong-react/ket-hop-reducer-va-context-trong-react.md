---
title: "Kết hợp Reducer và Context trong React"
description: "Bài viết này sẽ hướng dẫn bạn cách kết hợp Reducer và Context để quản lý state của một màn hình phức tạp mà không cần truyền state và hàm điều khiển qua props"
chapter:
  name: "Quản lý state trong React"
  slug: "chuong-05-quan-ly-state-trong-react"
image: https://kungfutech.edu.vn/thumbnail.png
position: 1
---

Trong React, Reducer (bộ giảm) là một công cụ mạnh mẽ để tối ưu hóa quy trình quản lý `state` của các `component`. Context cho phép bạn truyền thông tin từ `component` gốc đến các `component` khác sâu bên trong ứng dụng. Bài viết này sẽ hướng dẫn bạn cách kết hợp Reducer và Context để quản lý `state` của một màn hình phức tạp mà không cần truyền `state` và hàm điều khiển qua props.

## Kết hợp Reducer với Context

Kết hợp Reducer và Context trong React cho phép bạn quản lý `state` của ứng dụng một cách hiệu quả và tránh việc truyền `state` và hàm điều khiển qua nhiều `component` con. Điều này trở nên quan trọng khi ứng dụng phức tạp và có nhiều `component` ở giữa cây `component`.

### Bước 1: Tạo Context

Trước tiên, bạn cần tạo Context bằng cách sử dụng hàm `createContext` từ thư viện React. Trong ví dụ này, chúng ta sẽ tạo hai Context: `TasksContext` để cung cấp danh sách các công việc và `TasksDispatchContext` để cung cấp hàm điều khiển để thay đổi danh sách này.

```jsx
import { createContext } from "react";

export const TasksContext = createContext(null);
export const TasksDispatchContext = createContext(null);
```

### Bước 2: Đặt `state` và hàm điều khiển vào Context

Bây giờ, bạn có thể nhập cả hai Context này vào `component` `TaskApp`. Trong ví dụ này, `state` `tasks` và hàm `dispatch` được quản lý bởi Reducer sẽ được cung cấp cho toàn bộ cây `component` dưới đó.

```jsx
import { TasksContext, TasksDispatchContext } from "./TasksContext.js";

export default function TaskApp() {
  const [tasks, dispatch] = useReducer(tasksReducer, initialTasks);

  return (
    <TasksContext.Provider value={tasks}>
      <TasksDispatchContext.Provider value={dispatch}>
        {/* Các `component` con ở đây */}
      </TasksDispatchContext.Provider>
    </TasksContext.Provider>
  );
}
```

### Bước 3: Sử dụng Context trong cây `component`

Bây giờ, bạn không cần phải truyền danh sách công việc và các hàm điều khiển xuống cây `component` nữa. Thay vào đó, bất kỳ `component` con nào cần đọc danh sách công việc có thể sử dụng `TasksContext` để truy cập nó.

```jsx
export default function TaskList() {
  const tasks = useContext(TasksContext);
  // ...
}

function Task({ task }) {
  const [isEditing, setIsEditing] = useState(false);
  const dispatch = useContext(TasksDispatchContext);
  // ...
}
```

## Tách mọi thứ vào một tệp duy nhất

Để làm cho mã nguồn dễ quản lý hơn, bạn có thể tách cả Reducer và Context vào một tệp duy nhất. Trong ví dụ này, tệp `TasksContext.js` chứa cả hai Context và Reducer, cùng với một `component` `TasksProvider` để quản lý `state` và cung cấp Context.

```jsx
// TasksContext.js

import { createContext, useReducer, useContext } from "react";

// Khởi tạo Context
export const TasksContext = createContext(null);
export const TasksDispatchContext = createContext(null);

// Reducer và khởi tạo `state` ban đầu
const initialTasks = [];
const tasksReducer = (state, action) => {
  // Xử lý các hành động
};

// Thành phần cung cấp Context và Reducer
export function TasksProvider({ children }) {
  const [tasks, dispatch] = useReducer(tasksReducer, initialTasks);

  return (
    <TasksContext.Provider value={tasks}>
      <TasksDispatchContext.Provider value={dispatch}>
        {children}
      </TasksDispatchContext.Provider>
    </TasksContext.Provider>
  );
}

// Các hàm tùy chỉnh để đọc Context
export function useTasks() {
  return useContext(TasksContext);
}

export function useTasksDispatch() {
  return useContext(TasksDispatchContext);
}
```

Bây giờ, mã nguồn của các `component` trở nên gọn gàng và không còn phải quan tâm đến việc truyền `state` và hàm điều khiển qua props.

::alert{type="success"}

Kết hợp Reducer và Context trong React giúp bạn quản lý `state` của ứng dụng một cách hiệu quả và tối ưu hóa quy trình làm việc. Bằng cách tạo các Context cho `state` và hàm điều khiển, bạn có thể truy cập chúng từ bất kỳ `component` nào trong cây `component` mà không cần truyền chúng qua props. Điều này giúp làm cho mã nguồn dễ đọc và bảo trì hơn khi ứng dụng của bạn phức tạp lên.

::
