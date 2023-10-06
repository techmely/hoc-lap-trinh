---
title: "Tìm hiểu Refs và useRef trong React"
description: "Khi bạn muốn một component React gắn nhớ một số thông tin, nhưng bạn không muốn thông tin đó gây ra việc render lại mới, bạn có thể sử dụng Refs."
chapter:
  name: "React nâng cao"
  slug: "chuong-06-react-nang-cao"
image: https://kungfutech.edu.vn/thumbnail.png
position: 1
---

Khi bạn muốn một component React "gắn nhớ" một số thông tin, nhưng bạn không muốn thông tin đó gây ra việc render lại mới, bạn có thể sử dụng Refs.

## Cách thêm một Ref vào component

Bạn có thể thêm một Ref vào component của bạn bằng cách import Hook `useRef` từ React:

```javascript
import { useRef } from "react";
```

Trong component của bạn, gọi Hook `useRef` và truyền giá trị ban đầu mà bạn muốn tham khảo như là đối số duy nhất. Ví dụ, đây là một Ref đến giá trị 0:

```javascript
const ref = useRef(0);
```

`useRef` trả về một đối tượng như sau:

```javascript
{
  current: 0; // Giá trị bạn đã truyền cho useRef
}
```

Bạn có thể truy cập giá trị hiện tại của Ref đó thông qua thuộc tính `ref.current`. Giá trị này có ý nghĩa được thay đổi có ý đồ, có nghĩa bạn có thể đọc và ghi vào nó. Nó giống như một khe bí mật của component của bạn mà React không theo dõi. Điều này làm cho nó trở thành một "cửa thoát" từ quy trình dữ liệu một chiều của React.

## Ví dụ sử dụng Ref trong React

Dưới đây là một ví dụ về việc sử dụng Ref trong một ứng dụng React:

```javascript
import { useRef } from "react";

export default function Counter() {
  let ref = useRef(0);

  function handleClick() {
    ref.current = ref.current + 1;
    alert("Bạn đã nhấp chuột " + ref.current + " lần!");
  }

  return <button onClick={handleClick}>Nhấp vào tôi!</button>;
}
```

Ref này trỏ đến một số, nhưng giống như state, bạn có thể trỏ đến bất cứ thứ gì: một chuỗi, một đối tượng, hoặc thậm chí một hàm. Khác với state, Ref là một đối tượng JavaScript thuần túy có thuộc tính hiện tại (`current`) mà bạn có thể đọc và sửa đổi.

## Sử dụng Refs và state cùng lúc

Dưới đây là một ví dụ về việc kết hợp Refs và state trong một component React. Hãy tạo một đồng hồ bấm giờ mà người dùng có thể bắt đầu hoặc dừng bằng cách nhấn một nút. Để hiển thị thời gian đã trôi qua kể từ khi người dùng nhấn "Bắt đầu", bạn cần theo dõi thời điểm người dùng đã nhấn "Bắt đầu" và thời gian hiện tại. Thông tin này được sử dụng để hiển thị và do đó bạn sẽ lưu nó trong state:

```javascript
import { useState } from "react";

export default function Stopwatch() {
  const [startTime, setStartTime] = useState(null);
  const [now, setNow] = useState(null);

  function handleStart() {
    // Bắt đầu đếm.
    setStartTime(Date.now());
    setNow(Date.now());

    setInterval(() => {
      // Cập nhật thời gian hiện tại mỗi 10ms.
      setNow(Date.now());
    }, 10);
  }

  let secondsPassed = 0;
  if (startTime != null && now != null) {
    secondsPassed = (now - startTime) / 1000;
  }

  return (
    <>
      <h1>Thời gian đã trôi qua: {secondsPassed.toFixed(3)} giây</h1>
      <button onClick={handleStart}>Bắt đầu</button>
    </>
  );
}
```

Khi người dùng nhấn "Dừng", bạn cần hủy bỏ khoảng thời gian hiện tại để ngừng cập nhật biến state `now`. Bạn có thể làm điều này bằng cách gọi `clearInterval`, nhưng bạn cần phải cung cấp cho nó ID của khoảng thời gian đã được trả về trước đó khi người dùng nhấn "Bắt đầu". Bạn cần phải lưu ID khoảng thời gian này ở một nơi nào đó. Vì ID khoảng thời gian không được sử dụng cho việc hiển thị, bạn có thể lưu nó trong một Ref:

```javascript
import { useState, useRef } from "react";

export default function Stopwatch() {
  const [startTime, setStartTime] = useState(null);
  const [now, setNow] = useState(null);
  const intervalRef = useRef(null);

  function handleStart() {
    setStartTime(Date.now());
    setNow(Date.now());

    clearInterval(intervalRef.current);
    intervalRef.current = setInterval(() => {
      setNow(Date.now());
    }, 10);
  }

  function handleStop() {
    clearInterval(intervalRef.current);
  }

  let secondsPassed = 0;
  if (startTime != null && now != null) {
    secondsPassed = (now - startTime) / 1000;
  }

  return (
    <>
      <h1>Thời g ian đã trôi qua: {secondsPassed.toFixed(3)} giây</h1>
      <button onClick={handleStart}>Bắt đầu</button>
      <button onClick={handleStop}>Dừng</button>
    </>
  );
}
```

Khi một thông tin nào đó chỉ cần thiết cho các xử lý sự kiện và việc thay đổi nó không yêu cầu việc render lại, sử dụng Ref có thể hiệu quả hơn.

## Sự khác biệt giữa Refs và State

Dưới đây là một so sánh giữa Refs và state:

| Refs                                                                                          | State                                                                                                                    |
| --------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------ |
| `useRef(initialValue)` trả về `{ current: initialValue }`                                     | `useState(initialValue)` trả về giá trị hiện tại của biến state và một hàm setter state ( `[value, setValue]`)           |
| Không gây ra việc render lại khi bạn thay đổi nó                                              | Gây ra việc render lại khi bạn thay đổi nó                                                                               |
| Có thể thay đổi - bạn có thể sửa đổi và cập nhật giá trị `current` bên ngoài quá trình render | "Bất biến" - bạn phải sử dụng hàm setter state để sửa đổi biến state và gây ra việc render lại.                          |
| Bạn không nên đọc (hoặc viết) giá trị `current` trong quá trình render                        | Bạn có thể đọc state bất kỳ lúc nào. Tuy nhiên, mỗi lần render có một bản sao riêng biệt của state và nó không thay đổi. |

### Khi nào nên sử dụng Refs trong React

Thường thì bạn sẽ sử dụng Refs khi component của bạn cần "bước ra ngoài" React và giao tiếp với các API bên ngoài - thường là một API trình duyệt không ảnh hưởng đến giao diện của component. Dưới đây là một số tình huống hiếm khi bạn cần làm điều này:

- Lưu trữ ID của thời gian chờ (timeout IDs).
- Lưu trữ và thao tác các phần tử DOM, mà chúng tôi sẽ giới thiệu ở trang tiếp theo.
- Lưu trữ các đối tượng khác không cần thiết cho việc tính toán JSX.

Nếu component của bạn cần lưu trữ một số giá trị, nhưng nó không ảnh hưởng đến logic render, hãy chọn sử dụng Refs.

### Một số chú ý khi làm việc với Refs trong React

Tuân theo những nguyên tắc sau đây sẽ giúp component của bạn trở nên dễ dự đoán hơn:

- Xem xử lý Refs như một "cửa thoát". Refs hữu ích khi bạn làm việc với các hệ thống bên ngoài hoặc các API trình duyệt. Nếu hầu hết logic ứng dụng của bạn và luồng dữ liệu dựa vào Refs, bạn có thể muốn xem xét lại cách tiếp cận của bạn.
- Không đọc hoặc viết vào `ref.current` trong quá trình render. Nếu một số thông tin cần thiết trong quá trình render, hãy sử dụng state thay vì Refs. Vì React không biết khi `ref.current` thay đổi, thậm chí việc đọc nó trong quá trình render cũng làm cho hành vi của component trở nên khó dự đoán. (Ngoại lệ duy nhất cho điều này là mã như `if (!ref.current) ref.current = new Thing()` chỉ đặt giá trị `ref` một lần trong lần render đầu tiên.)
- Giới hạn của state React không áp dụng cho Refs. Ví dụ, state hoạt động như một bản chụp cho mỗi lần render và không cập nhật đồng bộ. Nhưng khi bạn thay đổi giá trị hiện tại của một Ref, nó thay đổi ngay lập tức. Điều này xảy ra vì Ref chính nó là một đối tượng JavaScript thông thường, và do đó nó hoạt động như một đối tượng JavaScript.

::alert{type="success"}

Refs là một cửa thoát để lưu trữ các giá trị mà không được sử dụng để render. Bạn không cần chúng thường xuyên. Ref là một đối tượng JavaScript thông thường với một thuộc tính duy nhất là `current`, mà bạn có thể đọc hoặc đặt. Bạn có thể sử dụng Hook `useRef` để yêu cầu React cung cấp cho bạn một Ref. Không giống như state, việc đặt giá trị hiện tại của Ref không gây ra việc render lại. Đừng đọc hoặc viết giá trị `ref.current` trong quá trình render. Điều này làm cho hành vi của component của bạn khó dự đoán.

::
