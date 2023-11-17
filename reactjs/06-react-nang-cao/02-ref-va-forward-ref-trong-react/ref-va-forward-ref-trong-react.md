---
title: "Refs và forwardRef trong React"
description: "Đôi khi bạn có thể cần truy cập các phần tử DOM được quản lý bởi React, ví dụ như để làm trỏ chuột vào một node, cuộn đến nó hoặc đo kích thước và vị trí của nó. React không cung cấp cách tích hợp để thực hiện những công việc này, vì vậy bạn sẽ cần sử dụng một ref để truy cập đối tượng DOM"
chapter:
  name: "React nâng cao"
  slug: "chuong-06-react-nang-cao"
image: https://kungfutech.edu.vn/thumbnail.png
position: 2
---

Trong React, việc cập nhật DOM được thực hiện tự động, vì vậy các [component](/bai-viet/reactjs/component-trong-react-la-gi) của bạn thường không cần thao tác trực tiếp vào DOM. Tuy nhiên, đôi khi bạn có thể cần truy cập các phần tử DOM được quản lý bởi React, ví dụ như để cuộn đến một phần tử hoặc đo kích thước và vị trí của nó. React không cung cấp cách trực tiếp để thực hiện những công việc này, vì vậy bạn sẽ cần sử dụng một `ref` để truy cập đối tượng DOM.

## Khi nào cần sử dụng Refs trong react?

`Refs` thường được sử dụng khi bạn cần tương tác với DOM hoặc thực hiện các thao tác không phải là render. Ví dụ, quản lý trạng thái `focus`, cuộn trang hoặc gọi các API trình duyệt mà React không hỗ trợ. Dưới đây là một số tình huống thường gặp khi bạn cần sử dụng Refs:

- Quản lý trạng thái `focus`.
- Cuộn trang.
- Đo kích thước và vị trí của phần tử.
- Gọi các API trình duyệt không được React hỗ trợ.

## Nhận một Ref đến Node

Để truy cập một đối tượng DOM được quản lý bởi React, bạn cần làm như sau:

1. Import Hook `useRef` từ React:

```javascript
import { useRef } from "react";
```

2. Sử dụng nó để khai báo một `ref` trong component của bạn:

```javascript
const myRef = useRef(null);
```

3. Cuối cùng, truyền `ref` của bạn dưới dạng thuộc tính `ref` cho thẻ JSX mà bạn muốn có đối tượng DOM:

```javascript
<div ref={myRef}>
```

Hook `useRef` trả về một đối tượng với một thuộc tính duy nhất là `current`. Ban đầu, `myRef.current` sẽ là `null`. Khi React tạo ra một đối tượng DOM cho phần tử `<div>` này, React sẽ đặt một tham chiếu đến đối tượng này vào `myRef.current`. Sau đó, bạn có thể truy cập đối tượng DOM này từ các xử lý sự kiện và sử dụng các API trình duyệt tích hợp trên nó.

## Ví dụ sử dụng Ref để truy xuất vào DOM

Dưới đây là một ví dụ, khi bạn nhấp vào nút, ô nhập văn bản sẽ được focus vào:

```javascript
import { useRef } from "react";

export default function Form() {
  const inputRef = useRef(null);

  function handleClick() {
    inputRef.current.focus();
  }

  return (
    <>
      <input ref={inputRef} />
      <button onClick={handleClick}>Tập trung vào ô nhập</button>
    </>
  );
}
```

Để thực hiện điều này:

- Khai báo `inputRef` bằng Hook `useRef`.
- Truyền nó dưới dạng `<input ref={inputRef}>`, khúc này là để ref nó sẽ được trỏ vào phần tử input
- Trong hàm `handleClick`, lấy đối tượng DOM và gọi `focus()` bằng cách `inputRef.current.focus()`.
- Truyền hàm xử lý sự kiện `handleClick` cho `<button>` bằng cách sử dụng thuộc tính `onClick`.

Mặc dù thao tác DOM là trường hợp phổ biến nhất khi sử dụng `Refs`, Hook `useRef` có thể được sử dụng để lưu trữ các giá trị khác bên ngoài React, chẳng hạn như ID của bộ đếm thời gian. Tương tự như `state`, các ref được duy trì giữa các lần render. Refs giống như các biến state mà không gây ra việc render lại khi bạn thiết lập chúng.

### Ví dụ scroll đến một phần tử

Bạn có thể có nhiều hơn một ref trong một component. Trong ví dụ này, có một `carousel` với ba hình ảnh, mỗi nút sẽ căn giữa một hình ảnh bằng cách gọi phương thức `scrollIntoView()` trên đối tượng DOM tương ứng:

```javascript
import { useRef } from "react";

export default function CatFriends() {
  const firstCatRef = useRef(null);
  const secondCatRef = useRef(null);
  const thirdCatRef = useRef(null);

  function handleScrollToFirstCat() {
    firstCatRef.current.scrollIntoView({
      behavior: "smooth",
      block: "nearest",
      inline: "center",
    });
  }

  // ... (Các hàm xử lý sự kiện khác)

  return (
    <>
      <nav>
        <button onClick={handleScrollToFirstCat}>Tom</button>
        {/* ... (Các nút và hình ảnh khác) */}
      </nav>
    </>
  );
}
```

## Truy cập đối tượng DOM của một component khác

Mặc định, React không cho phép một component truy cập các đối tượng DOM của các component khác, ngay cả đối với các component con của nó. Điều này xảy ra để đảm bảo tính ổn định và độ tin cậy của ứng dụng. Bạn có thể sử dụng Refs để truy cập các đối tượng DOM của các component con, nhưng cần tuân thủ một số quy tắc.

**Quy tắc:**

- Mặc định, một component không thể truy cập các đối tượng DOM của component khác.
- Bạn có thể tạo một "lỗ thoát" bằng cách sử dụng `React.forwardRef()` để cho phép component con tiếp nhận ref từ component cha và chuyển nó xuống đối tượng DOM phù hợp.

## Truy cập đối tượng DOM của một component con Khác

Trong ví dụ này, chúng ta có một component `<MyInput />` tự tạo và muốn truy cập đối tượng DOM của nó bằng một ref. Mặc dù chúng ta đã sử dụng ref, mặc định React sẽ trả về `null` cho ref này. Điều này dẫn đến việc nhấp vào nút không tập trung vào ô nhập:

```javascript
import { useRef } from "react";

function MyInput(props) {
  return <input {...props} />;
}

export default function MyForm() {
  const inputRef = useRef(null);

  function handleClick() {
    inputRef.current.focus();
  }

  return (
    <>
      <MyInput ref={inputRef} />
      <button onClick={handleClick}>Tập trung vào ô nhập</button>
    </>
  );
}
```

## Sử Dụng `React.forwardRef()` trong React

![Sử Dụng React.forwardRef trong React](https://github.com/techmely/hoc-lap-trinh/assets/29374426/e0fcc717-c8dd-4961-82c3-b9e8eebe09fa)

Để cho phép component con tiếp nhận ref từ component cha và chuyển nó xuống đối tượng DOM phù hợp, chúng ta có thể sử dụng `React.forwardRef()` như sau:

```javascript
import { forwardRef, useRef } from "react";

const MyInput = forwardRef((props, ref) => {
  return <input {...props} ref={ref} />;
});

export default function Form() {
  const inputRef = useRef(null);

  function handleClick() {
    inputRef.current.focus();
  }

  return (
    <>
      <MyInput ref={inputRef} />
      <button onClick={handleClick}>Tập trung vào ô nhập</button>
    </>
  );
}
```

Bây giờ, chúng ta có thể truy cập và focus vào ô input một cách thành công.
