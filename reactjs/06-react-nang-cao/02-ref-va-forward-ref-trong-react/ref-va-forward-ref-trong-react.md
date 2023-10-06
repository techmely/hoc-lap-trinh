---
title: "Refs và forwardRef trong React"
description: "Đôi khi bạn có thể cần truy cập các phần tử DOM được quản lý bởi React, ví dụ như để làm trỏ chuột vào một node, cuộn đến nó hoặc đo kích thước và vị trí của nó. React không cung cấp cách tích hợp để thực hiện những công việc này, vì vậy bạn sẽ cần sử dụng một ref để truy cập đối tượng DOM"
chapter:
  name: "React nâng cao"
  slug: "chuong-06-react-nang-cao"
image: https://kungfutech.edu.vn/thumbnail.png
position: 2
---

Trong React, việc cập nhật DOM được thực hiện tự động, vì vậy các component của bạn thường không cần thao tác trực tiếp vào DOM. Tuy nhiên, đôi khi bạn có thể cần truy cập các phần tử DOM được quản lý bởi React, ví dụ như để làm trỏ chuột vào một node, cuộn đến nó hoặc đo kích thước và vị trí của nó. React không cung cấp cách tích hợp để thực hiện những công việc này, vì vậy bạn sẽ cần sử dụng một ref để truy cập đối tượng DOM.

## Khi nào cần sử dụng Refs?

`Refs` thường được sử dụng khi bạn cần "bước ra ngoài" React để tương tác với DOM hoặc thực hiện các thao tác không phải là render. Ví dụ, quản lý trạng thái `focus`, cuộn trang hoặc gọi các API trình duyệt mà React không tiếp cận. Dưới đây là một số tình huống thường gặp khi bạn cần sử dụng Refs:

- Quản lý focus.
- Cuộn trang.
- Đo lường kích thước và vị trí của phần tử.
- Gọi các API trình duyệt không được React tiếp cận.

## Nhận một Ref đến Node

Để truy cập một đối tượng DOM được quản lý bởi React, bạn cần làm như sau:

1. Import Hook `useRef` từ React:

```javascript
import { useRef } from "react";
```

2. Sử dụng nó để khai báo một ref trong component của bạn:

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
- Truyền nó dưới dạng `<input ref={inputRef}>`. Điều này cho biết cho React để đặt đối tượng DOM của ô nhập văn bản này vào `inputRef.current`.
- Trong hàm `handleClick`, đọc đối tượng DOM của ô nhập từ `inputRef.current` và gọi `focus()` lên nó bằng `inputRef.current.focus()`.
- Truyền hàm xử lý sự kiện `handleClick` cho `<button>` bằng cách sử dụng thuộc tính `onClick`.

Mặc dù thao tác DOM là tình huống phổ biến nhất khi sử dụng Refs, Hook `useRef` có thể được sử dụng để lưu trữ các giá trị khác bên ngoài React, chẳng hạn như ID của bộ đếm thời gian. Tương tự như state, các ref được duy trì giữa các lần render. Refs giống như các biến state mà không gây ra việc render lại khi bạn thiết lập chúng.

### Ví dụ scroll đến một phần tử

Bạn có thể có nhiều hơn một ref trong một component. Trong ví dụ này, có một carousel với ba hình ảnh. Mỗi nút sẽ căn giữa một hình ảnh bằng cách gọi phương thức `scrollIntoView()` trên đối tượng DOM tương ứng:

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

Bây giờ, chúng ta có thể truy cập và tập trung vào ô nhập một cách thành công.

### Những điều cần lưu ý khi sử dụng Refs

- Tránh thay đổi các nút DOM do React quản lý, trừ khi bạn biết chắc chắn bạn đang làm gì. Sửa đổi, thêm hoặc xóa các nút con từ các phần tử được quản lý bởi React có thể dẫn đến kết quả hình ảnh không nhất quán hoặc gây lỗi.
- Nếu bạn cần phải thay đổi các phần tử DOM do React quản lý, chỉ thay đổi các phần mà React không có lý do để cập nhật. Ví dụ, nếu một `<div>` luôn trống trong JSX, React sẽ không cần phải chạm vào danh sách con của nó. Do đó, bạn có thể an toàn thêm hoặc xóa các phần tử một cách thủ công ở đó.

::alert={type="success"}

Refs là một khái niệm phổ quát, nhưng trong hầu hết trường hợp, bạn sẽ sử dụng chúng để lưu trữ các đối tượng DOM.
Bạn sẽ chỉ định cho React để đặt đối tượng DOM vào `myRef.current` bằng cách truyền `<div ref={myRef}>`.
Thường thì, bạn sẽ sử dụng refs cho các thao tác không phải là phá hủy như tập trung, cuộn trang hoặc đo lường các phần tử DOM.
Mặc định, một component không tiết lộ các đối tượng DOM của nó. Bạn có thể kích hoạt việc tiết lộ đối tượng DOM bằng cách sử dụng `forwardRef` và chuyển ref từ component cha xuống một phần tử cụ thể.
Hãy tránh thay đổi các phần tử DOM do React quản lý một cách thận trọng. Nếu bạn làm việc này, chỉ thay đổi những phần mà React không cần phải cập nhật.

::
