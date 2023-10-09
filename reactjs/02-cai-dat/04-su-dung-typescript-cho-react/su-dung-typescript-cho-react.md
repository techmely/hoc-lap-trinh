---
title: "Sử dụng Typescript cho React"
description: "Sử dụng Typescript cho React"
chapter:
  name: "Cài đặt"
  slug: "chuong-02-cai-dat-reactjs"
image: https://kungfutech.edu.vn/thumbnail.png
position: 4
---

TypeScript là một cách phổ biến để thêm các định nghĩa kiểu cho các dự án mã JavaScript. Mặc định, TypeScript hỗ trợ JSX và bạn có thể có sự hỗ trợ hoàn chỉnh cho React Web bằng cách thêm `@types/react` và `@types/react-dom` vào dự án của bạn.

## Cài đặt typescript trong React

Tất cả các framework React chất lượng sản phẩm đều hỗ trợ việc sử dụng TypeScript. Hãy tuân theo hướng dẫn cụ thể của từng framework để cài đặt:

1. Next.js
2. Remix
3. Gatsby
4. Expo

### Thêm TypeScript vào dự án React hiện có

Để cài đặt phiên bản mới nhất của định nghĩa kiểu của React:

```shell
npm install @types/react @types/react-dom
```

Các tùy chọn biên dịch sau cần phải được thiết lập trong tệp `tsconfig.json` của bạn:

- `dom` phải được bao gồm trong `lib` (Lưu ý: Nếu không có tùy chọn `lib` được chỉ định, `dom` sẽ được bao gồm mặc định).
- `jsx` phải được đặt thành một trong các tùy chọn hợp lệ. `preserve` có thể là đủ cho hầu hết các ứng dụng. Nếu bạn đang xuất bản một thư viện, hãy tìm hiểu tài liệu về `jsx` để biết giá trị nào phù hợp.

## TypeScript với Các Thành Phần React

Lưu ý: Mọi tệp chứa JSX phải sử dụng phần mở rộng tệp .tsx. Đây là một phần mở rộng cụ thể cho TypeScript để nó biết tệp này chứa JSX.

Việc viết TypeScript với React rất giống việc viết JavaScript với React. Sự khác biệt chính khi làm việc với một thành phần là bạn có thể cung cấp kiểu cho các thuộc tính của thành phần của bạn. Các kiểu này có thể được sử dụng để kiểm tra tính chính xác và cung cấp tài liệu trực tiếp trong trình soạn thảo.

Ví dụ, với thành phần MyButton từ Hướng dẫn Nhanh, chúng ta có thể thêm một kiểu mô tả tiêu đề cho nút:

```jsx
function MyButton({ title }: { title: string }) {
  return <button>{title}</button>;
}

export default function MyApp() {
  return (
    <div>
      <h1>Welcome to my app</h1>
      <MyButton title="I'm a button" />
    </div>
  );
}
```

Kiểu mô tả cho các props của thành phần của bạn có thể đơn giản hoặc phức tạp tùy thuộc vào nhu cầu của bạn, nhưng chúng nên là kiểu đối tượng được mô tả bằng kiểu dữ liệu hoặc giao diện.

## Ví dụ về Các Hooks

Các định nghĩa kiểu từ `@types/react` bao gồm các kiểu cho các hooks tích hợp, vì vậy bạn có thể sử dụng chúng trong các thành phần của bạn mà không cần cài đặt thêm.

**useState:** Hook useState sẽ tái sử dụng giá trị được truyền vào làm trạng thái ban đầu để

xác định kiểu của giá trị đó. Ví dụ:

```jsx
// Xác định kiểu là "boolean" tự động
const [enabled, setEnabled] = useState(false);
```

Nếu bạn muốn cung cấp một kiểu tường minh cho trạng thái, bạn có thể làm như sau:

```jsx
// Xác định kiểu tường minh là "boolean"
const [enabled, setEnabled] = useState < boolean > false;
```

Điều này có ích khi bạn muốn định kiểu cho một kiểu hợp nhất hoặc mô tả các trạng thái khác nhau của một thành phần.

**useReducer:** Hook useReducer phức tạp hơn và yêu cầu bạn định kiểu cho trạng thái ban đầu. Ví dụ:

```jsx
import { useReducer } from "react";

interface State {
  count: number;
}

type CounterAction =
  | { type: "reset" }
  | { type: "setCount", value: State["count"] };

const initialState: State = { count: 0 };

function stateReducer(state: State, action: CounterAction): State {
  switch (action.type) {
    case "reset":
      return initialState;
    case "setCount":
      return { ...state, count: action.value };
    default:
      throw new Error("Unknown action");
  }
}

export default function App() {
  const [state, dispatch] = useReducer(stateReducer, initialState);

  const addFive = () => dispatch({ type: "setCount", value: state.count + 5 });
  const reset = () => dispatch({ type: "reset" });

  return (
    <div>
      <h1>Welcome to my counter</h1>

      <p>Count: {state.count}</p>
      <button onClick={addFive}>Add 5</button>
      <button onClick={reset}>Reset</button>
    </div>
  );
}
```

**useContext:** Hook useContext là một kỹ thuật để truyền dữ liệu xuống cây thành phần mà không cần truyền props qua các thành phần. Kiểu của giá trị được cung cấp bởi context sẽ được suy luận từ giá trị được chuyển vào hàm createContext.

```jsx
import { createContext, useContext, useState } from "react";

type Theme = "light" | "dark" | "system";
const ThemeContext = createContext < Theme > "system";

const useGetTheme = () => useContext(ThemeContext);

export default function MyApp() {
  const [theme, setTheme] = useState < Theme > "light";

  return (
    <ThemeContext.Provider value={theme}>
      <MyComponent />
    </ThemeContext.Provider>
  );
}

function MyComponent() {
  const theme = useGetTheme();

  return (
    <div>
      <p>Current theme: {theme}</p>
    </div>
  );
}
```

**useMemo và useCallback:** Hook useMemo và useCallback cho phép bạn tạo/mở lại giá trị được ghi nhớ từ cuộc gọi hàm, chạy lại hàm chỉ khi các phụ thuộc truyền vào dưới dạng tham số thứ hai thay đổi. Kết quả từ cuộc gọi hook này được suy luận từ giá trị trả về từ hàm trong tham số đầu tiên. Bạn có thể làm cho việc định kiểu tường minh hơn bằng cách cung cấp một kiểu thông qua tham số cho hook.

Ví dụ:

```jsx
// Xác định kiểu của visibleTodos từ kết quả trả về của filterTodos
const visibleTodos = useMemo(() => filterTodos(todos, tab), [todos, tab]);

// Xác định kiểu của handleClick từ tham số của React.ChangeEvent<HTMLInputElement>
const handleClick =
  useCallback <
  React.ChangeEventHandler <
  HTMLInputElement >>
    ((event) => {
      // ...
    },
    [todos]);
```

## Các Kiểu Hữu Ích

Có một loạt các kiểu định nghĩa từ gói `@types/react`, và nó rất đáng đọc khi bạn đã thoải mái với cách React và TypeScript tương tác. Bạn có thể tìm thấy chúng trong thư mục React trong DefinitelyTyped. Dưới đây là một số ví dụ về các kiểu phổ biến hơn.

**Sự kiện DOM (DOM Events):** Khi làm việc với các sự kiện DOM trong React, loại sự kiện có thể được suy luận từ bộ xử lý sự kiện. Tuy nhiên, khi bạn muốn trích xuất một hàm để truyền vào một bộ xử lý sự kiện, bạn cần thiết lập kiểu của sự kiện một cách tường minh.

```jsx
import { useState } from "react";

export default function Form() {
  const [value, setValue] = useState("Change me");

  function handleChange(event: React.ChangeEvent<HTMLInputElement>) {
    setValue(event.currentTarget.value);
  }

  return (
    <>
      <input value={value} onChange={handleChange} />
      <p>Value: {value}</p>
    </>
  );
}
```

**Children:** Có hai cách thường được sử dụng để mô tả children của một thành phần. Cách đầu tiên là sử dụng kiểu `React.ReactNode`, đây là một liên minh của tất cả các kiểu có thể được truyền làm children trong JSX. Cách thứ hai là sử dụng kiểu `React.ReactElement`, đây chỉ là các phần tử JSX và không phải là các nguyên thủy JavaScript như chuỗi hoặc số.

**Style Props:** Khi sử dụng kiểu dạng nội tuyến trong React, bạn có thể sử dụng `React.CSSProperties` để mô tả đối tượng được truyền vào prop style. Kiểu này là một liên minh của tất cả các thuộc tính CSS có thể được sử dụng và là một cách tốt để đảm bảo bạn đang truyền các thuộc tính CSS hợp lệ vào prop style và có được tính năng tự động hoàn chỉnh trong trình soạn thảo.

```jsx
interface MyComponentProps {
  style: React.CSSProperties;
}
```

::alert{type="success"}

Bài này đã giới thiệu các cơ bản của việc sử dụng TypeScript với React, nhưng còn rất nhiều thứ để học. Trang tài liệu chính thức của TypeScript, Handbook, bao gồm hướng dẫn về hầu hết các tính năng quan trọng của ngôn ngữ TypeScript.

::
