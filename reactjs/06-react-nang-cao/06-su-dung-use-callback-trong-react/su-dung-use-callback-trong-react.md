---
title: "Sử dụng useCallback trong React"
description: "useCallback được sử dụng để tối ưu hóa quá trình render của các functional component trong React. Nó rất hữu ích khi một component thường xuyên bị re-render mà không cần thiết trong xử lý sự kiện người dùng, đặc biệt khi có hành vi chức năng phức tạp. Chúng ta sẽ xem qua một ví dụ đơn giản để hiểu rõ cách hook này có thể cải thiện hiệu suất render của component."
chapter:
  name: "React nâng cao"
  slug: "chuong-06-react-nang-cao"
image: https://kungfutech.edu.vn/thumbnail.png
position: 6
---

React Hooks là một cách mới để quản lý state trong các functional component, đã được giới thiệu từ phiên bản React v16.8. Với các hooks như `useState`, `useEffect`, và nhiều hooks khác, nhà phát triển cuối cùng có thể làm việc với các side effects trong các component function.

Trong bài viết này, chúng ta sẽ tìm hiểu về `useCallback`, một trong những hooks đặc biệt trong React, và làm thế nào để sử dụng nó một cách hiệu quả.

### Giới thiệu về useCallback

`useCallback` được sử dụng để tối ưu hóa quá trình render của các functional component trong React. Nó rất hữu ích khi một component thường xuyên bị re-render mà không cần thiết trong xử lý sự kiện người dùng, đặc biệt khi có hành vi chức năng phức tạp. Chúng ta sẽ xem qua một ví dụ đơn giản để hiểu rõ cách hook này có thể cải thiện hiệu suất render của component.

Lưu ý, React đã được tối ưu hóa tốt, nên chỉ nên sử dụng tối ưu hóa khi component có khả năng chậm, xử lý tác vụ nặng. Trong trường hợp đó, việc sử dụng `useCallback` có thể giúp tối ưu hiệu suất.

Hãy xem xét một ví dụ đơn giản với Component Counter:

```jsx
import React, { useState, useCallback } from "react";

function Counter() {
  const [count, setCount] = useState(0);
  const [countOther, setCountOther] = useState(0);

  const increase = () => setCount(count + 1);
  const decrease = () => setCount(count - 1);

  const increaseOther = () => setCountOther(countOther + 1);
  const decreaseOther = () => setCountOther(countOther - 1);

  return (
    <>
      <div>Count: {count}</div>
      <button onClick={increase}>+</button>
      <button onClick={decrease}>-</button>

      <div>Count other: {countOther}</div>
      <button onClick={increaseOther}>+</button>
      <button onClick={decreaseOther}>-</button>
    </>
  );
}

export default Counter;
```

Mỗi lần component Counter re-render, cả 4 hàm `increase`, `decrease`, `increaseOther`, và `decreaseOther` sẽ được tạo lại.

Để kiểm tra điều này, chúng ta có thể sử dụng Set để xem các hàm được thêm vào Set mỗi khi Counter re-render:

```jsx
import React, { useState, useCallback } from "react";

const storeSet = new Set();

function Counter() {
  // ... (cùng phần trên)

  storeSet.add(increase);
  storeSet.add(decrease);
  storeSet.add(increaseOther);
  storeSet.add(decreaseOther);

  console.log(storeSet);

  // ... (cùng phần trên)
}
```

Mỗi lần bạn thực hiện hành động (click vào nút tăng/giảm), giá trị trong storeSet sẽ tăng, cho thấy mỗi lần re-render sẽ tạo ra các hàm mới.

### Function Equality trong JavaScript

Chúng ta có thể thấy rằng mỗi hàm trong JavaScript chỉ có thể bằng chính nó. Hãy xem ví dụ sau:

```javascript
function factory() {
  return (a, b) => a + b;
}

const functionA = factory();
const functionB = factory();

console.log(functionA === functionB); // false
console.log(functionA === functionA); // true
```

Mỗi khi bạn tạo ra một hàm thông qua `factory()`, dù chúng có cùng thực hiện công việc, chúng vẫn là hai đối tượng khác nhau

. Điều tương tự cũng xảy ra với React: mỗi lần component re-render, các hàm bên trong nó sẽ được tạo lại.

### Sử dụng useCallback để memoize

Để giải quyết vấn đề trên, chúng ta có thể sử dụng `useCallback` để memoize (cache) lại các hàm giữa các lần render. Ví dụ:

```jsx
const increase = useCallback(() => setCount(count + 1), [count]);
const decrease = useCallback(() => setCount(count - 1), [count]);
const increaseOther = useCallback(
  () => setCountOther(countOther + 1),
  [countOther]
);
const decreaseOther = useCallback(
  () => setCountOther(countOther - 1),
  [countOther]
);
```

Như đã thấy, chúng ta chỉ cần pass vào mảng dependencies, nó sẽ giữ lại phiên bản memoized của hàm nếu các giá trị trong mảng dependencies không thay đổi giữa các lần render.

### Khi nào không nên sử dụng useCallback

Tuy nhiên, không phải mọi lúc và mọi nơi `useCallback` đều là lựa chọn tốt. Với các thành phần đơn giản hoặc khi có những trường hợp không cần thiết, việc thêm useCallback có thể làm mã của bạn trở nên phức tạp hơn và không hiệu quả.

```jsx
const ComponentA = () => {
  const [count, setCount] = useState(0);
  const handleClick = useCallback(() => setCount(count + 1), [count]);

  return <ButtonWrap onClick={handleClick} />;
};

const ButtonWrap = ({ children, ...props }) => {
  return <button {...props}>Button Children</button>;
};
```

Trong trường hợp này, việc sử dụng useCallback không mang lại nhiều lợi ích.

### Kết luận

`useCallback` là một hook mạnh mẽ giúp tối ưu hiệu suất của các component function phức tạp bằng cách memoize các hàm giữa các lần render.

Trước khi sử dụng useCallback, hãy xem xét các yếu tố sau:

- Tốc độ tăng có đảm bảo độ phức tạp vẫn ở mức cần thiết?
- Sử dụng useCallback có thực sự tăng tốc độ cho component của bạn?

Luôn luôn cân nhắc trước khi tối ưu hoá và đảm bảo rằng việc này đúng đắn với nhu cầu thực tế của dự án.
