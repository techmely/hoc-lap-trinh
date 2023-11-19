---
title: "Sử dụng useMemo trong React"
description: "useMemo trong React là một hook giúp ghi nhớ kết quả của một hàm. Nó cho phép bạn truyền vào hai tham số: callback và dependencies. Khi gọi useMemo, nó sẽ gọi hàm và trả về giá trị của nó. Mỗi khi dependencies thay đổi, useMemo sẽ kiểm tra và gọi lại callback để tính toán giá trị mới"
chapter:
  name: "React nâng cao"
  slug: "chuong-06-react-nang-cao"
image: https://kungfutech.edu.vn/thumbnail.png
position: 7
---

Khi ứng dụng của bạn mở rộng, vấn đề về hiệu suất trở nên ngày càng quan trọng hơn. Mặc dù React đã tối ưu và nhanh chóng, việc hiểu và sử dụng các công cụ để làm cho mã của bạn chạy nhanh hơn là điều cần thiết. Một trong số các công cụ này là `useMemo` hook và [useCallback](/bai-viet/reactjs/su-dung-use-callback-trong-react).

![Sử dụng useMemo trong React](https://github.com/techmely/hoc-lap-trinh/assets/29374426/be1e7d07-b4f9-49ab-a848-8519c3ee9643)

## `useMemo` giải quyết vấn đề gì?

`useMemo` trong React là một hook giúp ghi nhớ kết quả của một hàm. Nó cho phép bạn truyền vào hai tham số: callback và dependencies. Khi gọi `useMemo`, nó sẽ gọi hàm và trả về giá trị của nó. Mỗi khi dependencies thay đổi, `useMemo` sẽ kiểm tra và gọi lại callback để tính toán giá trị mới.

Tóm lại, nếu các giá trị dependencies thay đổi, hàm callback sẽ được gọi lại để thực hiện logic bên trong. Đó là cách hoạt động của `useMemo`.

## Sử dụng `useMemo` như thế nào?

Trước khi sử dụng `useMemo`, bạn cần import nó từ thư viện React:

```javascript
import React, { useMemo } from "react";
```

Khi bạn cần tính toán một giá trị phức tạp hoặc truy cập API nhiều lần, `useMemo` là lựa chọn tốt. Nó giúp bạn lưu lại kết quả tính toán khi dependencies không thay đổi.

Ví dụ, bạn có thể sử dụng `useMemo` như sau:

```javascript
const memoizedValue = useMemo(() => expensiveOperation(param), [param]);
```

Nếu `expensiveOperation` tốn nhiều công sức tính toán và bạn muốn lưu kết quả khi `param` thay đổi, `useMemo` sẽ giúp lưu lại kết quả này.

## Khi nào nên sử dụng `useMemo`?

Đầu tiên, đảm bảo mã của bạn không phụ thuộc hoàn toàn vào `useMemo`. Nói cách khác, hãy viết mã mà không cần sử dụng `useMemo` trước tiên và chỉ thêm nó khi cần thiết.

Ví dụ, giả sử chúng ta có một ứng dụng nhập số và hiển thị danh sách các số từ 0 đến số đó:

```javascript
import React, { useState } from "react";

function App() {
  const [length, setLength] = useState(0);

  return (
    <div>
      <input
        type="text"
        placeholder="Nhập số"
        value={length}
        onChange={(e) => setLength(Number(e.target.value))}
      />

      <ListedAllNumber length={length} />
    </div>
  );
}

function ListedAllNumber({ length }) {
  console.log("calculating...");

  let numbers = [];

  for (let i = 0; i < length; i++) {
    numbers.push(i);
  }

  return <p>Listed number: {numbers.join(",")}</p>;
}
```

Nhưng nếu số nhập vào lớn, việc tính toán danh sách này sẽ tốn thời gian. Đây là một ví dụ rõ ràng khi cần sử dụng `useMemo` để cache kết quả tính toán này:

```javascript
function ListedAllNumber({ length }) {
  console.log("calculating...");

  let numbers = useMemo(() => {
    let results = [];
    for (let i = 0; i < length; i++) {
      results.push(i);
    }
    return results;
  }, [length]);

  return <p>Listed number: {numbers.join(",")}</p>;
}
```

## Đừng lạm dụng `useMemo`

Mặc dù tối ưu hiệu suất là mục tiêu quan trọng, hãy cân nhắc các tác động phụ và khả năng tác động của nó. Điều quan trọng cần lưu ý:

- **Overhead**: `useMemo` là một logic phức tạp và có thể tạo ra vấn đề về hiệu suất hơn là giải quyết vấn đề. Đừng sử dụng nó trừ khi thực sự cần thiết. Đánh giá mức độ cần thiết trước khi sử dụng.
- **No guarantees**: Mặc dù `useMemo` chỉ gọi lại callback khi dependencies thay đổi, điều này không đảm bảo. Ứng dụng của bạn vẫn cần hoạt động tốt ngay cả khi `useMemo` gọi lại mỗi lần render.

::alert{type="success"}
Mục tiêu tối ưu hiệu suất là quan trọng, nhưng cần phải cân nhắc và đánh giá cẩn thận trước khi áp dụng các công cụ như `useMemo`. Bạn cần phải hiểu rõ tác động của nó vào mã của bạn và xác định xem nó có cần thiết không.
::
