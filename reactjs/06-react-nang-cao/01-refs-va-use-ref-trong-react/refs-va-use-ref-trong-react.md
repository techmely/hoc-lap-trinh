---
title: "Tìm hiểu Refs và useRef trong React"
description: "Khi bạn muốn một component React gắn nhớ một số thông tin, nhưng bạn không muốn thông tin đó gây ra việc render lại mới, bạn có thể sử dụng Refs."
chapter:
  name: "React nâng cao"
  slug: "chuong-06-react-nang-cao"
image: https://kungfutech.edu.vn/thumbnail.png
position: 1
---

Trong data flow của React, `props` là cách để các parent [component](/bai-viet/reactjs/component-trong-react-la-gi) tương tác với các child component. Để updated child componnent, bạn cần re-render nó với các props mới. Nhưng sẽ có một số trường hợp cần bắt buộc phải cập nhật các child component bên ngoài data flow của React. Cho những trường hợp này, chúng ta có thể sử dụng react Refs.

## React ref là gì?

React Ref (React reference) hiểu đơn giản là một đối tượng tham chiếu đến một biến, một component giữ cho giá trị của nó không thay đổi giữa các lần render và truy xuất các giá trị đó thông qua key current.

![Tìm hiểu Refs và useRef trong React](https://github.com/techmely/hoc-lap-trinh/assets/29374426/51c18fb7-fcd3-4fcc-a2d8-4c91c2a9c712)

## Cách thêm một Ref vào component

Bạn có thể thêm một Ref vào component của bạn bằng cách import Hook `useRef` từ React:

```javascript
import { useRef } from "react";
```

Trong component của bạn, gọi Hook `useRef` và truyền giá trị ban đầu mà bạn muốn , ví dụ đây là một `Ref` đến giá trị 0:

```javascript
const ref = useRef(0);
```

`useRef` trả về một đối tượng như sau:

```javascript
{
  current: 0; // Giá trị bạn đã truyền cho useRef
}
```

Bạn có thể truy cập giá trị hiện tại của Ref đó thông qua thuộc tính `ref.current`. Giá trị này có ý nghĩa được thay đổi, có nghĩa bạn có thể đọc và ghi vào nó.

## Truy xuất giá trị và cập nhật giá trị cho ref

Sau khi khởi tạo, bạn chỉ việc truy xuất key `current` để lấy giá trị hoặc gán cho ref một giá trị mà cần giữ cho nó không thay đổi giữa các lần render

```jsx
import { useRef } from "react";

function MyComponent() {
  const myRef = useRef(null);
  useEffect(() => {
    myRef.current = "Hello world";
  }, []);

  console.log(myRef.current);

  return <div>Demo</div>;
}

// Result 1: null
// Result 2: Hello world
```

::alert{type="warning"}
Nhưng có một lưu ý mà đã được nhắc từ đầu về ref nó sẽ không trigger render lại component. Vì thế, nếu không sử dụng state hoặc một số kỹ thuật khác để trigger render lại component. Bạn sẽ không thấy được giá trị của ref thay đổi trên giao diện.
::

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

## Sự khác biệt giữa Refs và State

Dưới đây là một so sánh giữa Refs và state:

| Refs                                                                                          | State                                                                                                                    |
| --------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------ |
| `useRef(initialValue)` trả về `{ current: initialValue }`                                     | `useState(initialValue)` trả về giá trị hiện tại của biến state và một hàm setter state ( `[value, setValue]`)           |
| Không gây ra việc render lại khi bạn thay đổi nó                                              | Gây ra việc render lại khi bạn thay đổi nó                                                                               |
| Có thể thay đổi - bạn có thể sửa đổi và cập nhật giá trị `current` bên ngoài quá trình render | "Bất biến" - bạn phải sử dụng hàm setter state để sửa đổi biến state và gây ra việc render lại.                          |
| Bạn không nên đọc (hoặc viết) giá trị `current` trong quá trình render                        | Bạn có thể đọc state bất kỳ lúc nào. Tuy nhiên, mỗi lần render có một bản sao riêng biệt của state và nó không thay đổi. |

## Khi nào nên sử dụng Refs trong React

Có rất nhiều trường hợp ở đây, xem qua thử nhé.

Tham chiếu đến real DOM Elements - trong trường hợp này, bạn có thể đặt `ref` cho các thể jsx như sau

```jsx
function MyComp() {
  const inputRef = useRef(null);

  return <input type="text" ref={inputRef} />;
}
```

Sau đó, bạn có thể thử truy cập DOM element bằng `inputRef.current`

Cho một ví dụ như sau

```jsx
function MyComp() {
  const inputRef = useRef(null);

  const onSubmitForm = (e) => {
    e.preventDefault();
    console.log(inputRef.current.value);
  };

  return (
    <form onSubmit={onSubmitForm}>
      <input type="text" ref={inputRef} />
      <button htmlType="submit">Submit</button>
    </form>
  );
}
```

Việc này sẽ giảm thiểu được lượng lớn lần re-render lại component nếu chúng ta sử dụng các thông thường bằng cách đặt và thay đổi state của input.

::alert{type="warning"}
Lưu ý: Nếu phần tử được hiển thị có điều kiện, bạn có thể thích sử dụng callback kết hợp với ref
::

```jsx
function MyComp() {
  const [isShowingForm, setShowingForm] = useState(false);
  const inputRef = useRef(null);

  const refCallback = useCallback((node) => {
    console.log(node);
  }, []);

  const onSubmitForm = (e) => {
    e.preventDefault();

    console.log(inputRef.current.value);
  };

  return (
    <>
      <button htmlType="button" onClick={() => setShowingForm(!isShowingForm)}>
        {isShowingForm ? "To Off" : "To On"}
      </button>

      {isShowingForm && (
        <form onSubmit={onSubmitForm}>
          <input type="text" ref={refCallback} />
          <button htmlType="submit">Submit</button>
        </form>
      )}
    </>
  );
}
```

::alert{type="warning"}
Lưu ý rằng: Bạn có thể thấy sử dụng phải sử dụng useCallback bên trong ref. Nếu không useCallback sẽ được gọi lại ở mỗi lần hiển thị, điều này sẽ ảnh hưởng không tốt đến tính nhất quán.
::

}

```

```
