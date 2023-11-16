---
title: "Kiểm soát State trong React"
description: "State là một khái niệm quan trọng trong React, và nó được quản lý một cách cẩn thận giữa các component. React theo dõi xem state nào thuộc về component nào dựa trên vị trí của chúng trong cây giao diện người dùng (UI). Bạn có thể kiểm soát khi nào không thay đổi state và khi nào thay đổi lại nó giữa các lần render"
chapter:
  name: "Quản lý state trong React"
  slug: "chuong-05-quan-ly-state-trong-react"
image: https://kungfutech.edu.vn/thumbnail.png
position: 3
---

`State` là một khái niệm quan trọng trong React, và nó được quản lý một cách cẩn thận giữa các `component`. React theo dõi xem `state` nào thuộc về `component` nào dựa trên vị trí của chúng trong UI Tree (cây giao diện người dùng). Bạn có thể kiểm soát khi nào không thay đổi `state` và khi nào thay đổi lại nó giữa các lần render.

## Cây giao diện người dùng (UI tree) là gì

Trình duyệt web sử dụng cấu trúc cây để mô hình hóa giao diện người dùng. DOM đại diện cho các phần tử `HTML`, `CSSOM` thực hiện công việc tương tự cho CSS.

![Kiểm soát State trong React](https://github.com/techmely/hoc-lap-trinh/assets/29374426/35802ffd-d1fc-4b51-8076-95311c9f9467)

React cũng sử dụng các cấu trúc cây để quản lý và mô hình hóa giao diện người dùng bạn tạo. React tạo ra các cây giao diện người dùng từ JSX của bạn. Sau đó, React DOM cập nhật các phần tử DOM trình duyệt để phù hợp với cây giao diện người dùng đó.

Trong cây UI tree, mỗi `component` có `state` hoàn toàn độc lập. Ví dụ, nếu bạn render hai component `<Counter>` cạnh nhau, mỗi `component` sẽ có `state` `score` và `hover` riêng biệt của riêng nó.

Hãy thử click vào cả hai `component` và chú ý rằng chúng không ảnh hưởng đến nhau:

```jsx
import { useState } from "react";

export default function App() {
  return (
    <div>
      <Counter />
      <Counter />
    </div>
  );
}

function Counter() {
  const [score, setScore] = useState(0);
  const [hover, setHover] = useState(false);

  let className = "counter";
  if (hover) {
    className += " hover";
  }

  return (
    <div
      className={className}
      onPointerEnter={() => setHover(true)}
      onPointerLeave={() => setHover(false)}
    >
      <h1>{score}</h1>
      <button onClick={() => setScore(score + 1)}>Add one</button>
    </div>
  );
}
```

Như bạn có thể thấy, khi bạn cập nhật một `component`, chỉ `state` của `component` đó được cập nhật.

React sẽ giữ nguyên `state` cho đến khi bạn render cùng một `component` ở cùng một vị trí. Nếu bạn loại bỏ nó hoặc render một `component` khác ở cùng một vị trí, React sẽ hủy bỏ `state` của nó.

## Cách không thay đổi `state`

Trong React, để không thay đổi `state` giữa các lần render, cấu trúc của cây của bạn cần "phù hợp". Nếu cấu trúc khác nhau, `state` sẽ bị hủy bỏ, bất kể bạn đã thay đổi gì trong `state` đó.

Điều này có nghĩa là bạn nên tránh việc thay đổi cấu trúc DOM của mình một cách ngẫu nhiên giữa các lần render. Thay vào đó, bạn nên giữ cho cấu trúc giống nhau và chỉ thay đổi dữ liệu.

### Sử dụng `keys` trong React

`Keys` là một thuộc tính đặc biệt bạn có thể đưa cho một phần tử trong một danh sách React. Nếu bạn cung cấp một key cho một `component`, React sẽ sử dụng `key` đó để xác định xem liệu `component` đó đã thay đổi hay không giữa các lần render.

`Keys` nên là một giá trị duy nhất trong phạm vi danh sách. Ví dụ, nếu bạn có một danh sách các mục dựa trên một mảng dữ liệu, bạn có thể sử dụng một thuộc tính độc nhất của mỗi mục làm `key`.

```jsx
const items = [
  { id: 1, name: "Item 1" },
  { id: 2, name: "Item 2" },
  { id: 3, name: "Item 3" },
];

function ItemList() {
  return (
    <ul>
      {items.map((item) => (
        <li key={item.id}>{item.name}</li>
      ))}
    </ul>
  );
}
```

### Sử dụng kiểu dữ liệu không thay đổi (immutable data)

Sử dụng kiểu dữ liệu không thay đổi (immutable data) giúp bạn tránh thay đổi `state` một cách ngẫu nhiên. Khi bạn tạo ra một bản sao của `state`, React có thể dễ dàng so sánh nó với phiên bản trước đó để xác định xem liệu `state` đã thay đổi hay không.

```jsx
import { useState } from "react";

function Counter() {
  const [count, setCount] = useState(0);

  const increment = () => {
    setCount(count + 1); // Sử dụng dữ liệu không thay đổi
  };

  return (
    <div>
      <p>Count: {count}</p>
      <button onClick={increment}>Increment</button>
    </div>
  );
}
```

## Khi nào React thay đổi lại `state`

React có một số tình huống mà nó sẽ tự động thay đổi lại `state` của một `component`:

1. **Thay đổi key:** Nếu bạn thay đổi key của một `component`, React sẽ hiểu đó là một `component` khác và thay đổi lại `state` của nó.
2. **Thay đổi kiểu `component`:** Nếu bạn thay đổi kiểu của một `component`, React sẽ hiểu đó là một `component` khác và thay đổi lại `state` của nó.
3. **Thay đổi props:** Nếu bạn thay đổi props của một `component`, React sẽ không tự động thay đổi lại `state` của nó. Tuy nhiên, bạn có thể thực hiện việc này bằng cách sử dụng `componentDidUpdate`.

```jsx
class MyComponent extends React.Component {
  componentDidUpdate(prevProps) {
    if (this.props.someValue !== prevProps.someValue) {
      // Thay đổi `state` ở đây nếu cần
    }
  }

  render() {
    return <div>{this.props.someValue}</div>;
  }
}
```

4. **Thay đổi `state` của cha:** Khi `state` của cha thay đổi, React sẽ xem xét lại toàn bộ cây con của nó và thay đổi lại `state` của tất cả các `component` con.
