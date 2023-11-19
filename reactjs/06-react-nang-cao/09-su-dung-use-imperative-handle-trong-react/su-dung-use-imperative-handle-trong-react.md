---
title: "Sử dụng useImperativeHandle trong React"
description: "useImperativeHandle có lẽ là một trong những hook khó hiểu hơn vì nó hoạt động theo cách rất khác so với hầu hết các hooks. Bắt buộc phải đi ngược lại bản chất khai báo của React khiến nó trở nên khá đặc biệt. Do vậy, nó chỉ nên được sử dụng khi cần thiết. Tuy nhiên, có rất nhiều tình huống mà hook này lại là cần thiết"
chapter:
  name: "React nâng cao"
  slug: "chuong-06-react-nang-cao"
image: https://kungfutech.edu.vn/thumbnail.png
position: 9
---

`useImperativeHandle` có lẽ là một trong những hook khó hiểu hơn vì nó hoạt động theo cách rất khác so với hầu hết các hooks. Bắt buộc phải đi ngược lại bản chất khai báo của React khiến nó trở nên khá đặc biệt. Do vậy, nó chỉ nên được sử dụng khi cần thiết. Tuy nhiên, có rất nhiều tình huống mà hook này lại là cần thiết. Vì vậy, mình sẽ trình bày trong bài viết này cùng với phần giải thích về cách thức hoạt động của nó.

![Sử dụng useImperativeHandle trong React](https://github.com/techmely/hoc-lap-trinh/assets/29374426/089eb9eb-db99-42a9-8762-d46f9d7c2f60)

## Nhắc lại về React.forwardRef trong react

Trước khi chúng ta nói về `useImperativeHandle`, trước tiên cần hiểu cách refs hoạt động, đặc biệt là khi chuyển tiếp refs tới các thành phần tuỳ chỉnh. Nếu bạn đã quen thuộc với cách làm việc của refs và `React.forwardRef`, bạn có thể bỏ qua phần này. Nếu không, hãy tìm hiểu sơ về `useRef` trước khi tiếp tục bài viết này.

Hãy tưởng tượng chúng ta có đoạn code bên dưới.

```javascript
function App() {
  const [value, setValue] = useState("");
  const inputRef = useRef();

  return (
    <>
      <input
        type="text"
        ref={inputRef}
        value={value}
        onChange={(e) => setValue(e.target.value)}
      />
      <button onClick={() => inputRef.current.focus()}>Focus</button>
    </>
  );
}
```

Đây là một đoạn code đơn giản sử dụng ref để tham chiếu đến input và lắng nghe thao tác khi người dùng nhấn vào button, kích hoạt sự kiện native focus của input thông qua refs. Đây là phần cơ bản về `useRef`. Tuy nhiên, điều gì sẽ xảy ra nếu đầu vào của chúng ta là một thành phần tùy chỉnh.

```javascript
function App() {
  const [value, setValue] = useState("");
  const inputRef = useRef();

  return (
    <>
      <CustomInput
        ref={inputRef}
        value={value}
        onChange={(e) => setValue(e.target.value)}
      />
      <button onClick={() => inputRef.current.focus()}>Focus</button>
    </>
  );
}
```

Với đoạn code mới của chúng ta, ref sẽ không tự động liên kết với input bên trong `CustomInput` trừ khi chúng ta sử dụng `React.forwardRef` bên trong thành phần tuỳ chỉnh này để forward ref.

```javascript
function CustomInput(props, ref) {
  return <input ref={ref} style={{ backgroundColor: "red" }} {...props} />;
}

export default React.forwardRef(CustomInput);
```

Ở dòng cuối cùng của thành phần tuỳ chỉnh trên, chúng ta gọi `React.forwardRef` và truyền vào `CustomInput`. Bằng cách này, chúng ta đang nói với React rằng thành phần này có thể nhận ref và tham số thứ hai cho `CustomInput` của chúng ta sẽ là ref được truyền vào. Sau đó, tất cả những gì chúng ta cần làm là cho React biết phần tử nào mà ref sẽ trỏ đến trong `CustomInput` của chúng ta.

## useImperativeHandle trong React là gì

Bây giờ, chúng ta đã hiểu cơ bản về cách hoạt động của refs. Hãy trao đổi thêm về `useImperativeHandle`. Chúng ta sẽ chia thành 2 phần. Phần đầu tiên sẽ là ví dụ cơ bản về `useImperativeHandle` để bạn có thể hiểu nó hoạt động thế nào và khi nào chúng ta cần sử dụng. Phần thứ 2 sẽ về một ví dụ ứng dụng `useImperativeHandle` trong các kịch bản thực tế mà chúng ta cần đến hook này.

Trước khi đi đến phần ví dụ, `useImperativeHandle` được tạo ra để làm gì? Về bản chất, `useImperativeHandle` tạo ra các giá trị tuỳ chỉnh khi một thành phần kích hoạt ref. Tức là khi bạn truyền ref đến một thành phần tuỳ chỉnh nào đó, những gì bạn nhận lại là nh

ững gì thành phần đó cho phép bạn nhận thông qua việc sử dụng `useImperativeHandle`.

Từ `useImperativeHandle`, bạn có thể làm nhiều việc hơn là chỉ gán một yếu tố ref đến một phần tử.

## Ví dụ sử dụng useImperativeHandle

Để triển khai một `useImperativeHandle` hook trong thành phần tuỳ chỉnh như `CustomInput`, chúng ta cần:

```javascript
function CustomInput(props, ref) {
  useImperativeHandle(ref, () => {
    return { alertHi: () => alert("Hi") };
  });

  return <input style={{ backgroundColor: "red" }} {...props} />;
}

export default React.forwardRef(CustomInput);
```

Tại đây, trường hợp sử dụng cơ bản của `useImperativeHandle` hook có 2 tham số cần truyền vào. Tham số đầu tiên là tham số ref mà bạn muốn ghi đè lên và tham số thứ 2 là một callback trả về các giá trị mới mà bạn muốn ref của `CustomInput` nhận được và sử dụng nó. Trong trường hợp này, chúng ta trả về một object chứa hàm `alertHi`. Giờ hãy xem cách sử dụng nó sau khi triển khai ở thành phần `App`.

```javascript
function App() {
  const [value, setValue] = useState("");
  const inputRef = useRef();

  return (
    <>
      <CustomInput
        ref={inputRef}
        value={value}
        onChange={(e) => setValue(e.target.value)}
      />
      <button onClick={() => inputRef.current.alertHi()}>Alert</button>
    </>
  );
}
```

Như bạn đã thấy, thay đổi duy nhất chúng ta thấy ở đây là để gọi `alertHi` mà chúng ta đã khai báo trong `useImperativeHandle` trước đó, trong `App` chỉ cần gọi đến `ref.current.alertHi()`. Về cơ bản, đó là như vậy, hoặc có thể phức tạp hơn một chút.

```javascript
function CustomInput(props, ref) {
  useImperativeHandle(
    ref,
    () => {
      return { alertValue: () => alert(props.value) };
    },
    [props.value]
  );

  return <input ref={ref} style={{ backgroundColor: "red" }} {...props} />;
}

export default React.forwardRef(CustomInput);
```

Truyền vào một dependencies là một array tương tự với các hook khác như `useEffect`, `useMemo`,... để quyết định việc kích hoạt lại `useImperativeHandle` khi giá trị của props thay đổi, cập nhật lại giá trị mới nhất mà chúng ta cần để thực hiện các chức năng mà chúng ta cần.

::alert{type="success"}

- `useImperativeHandle` được tạo ra cho các kịch bản mà bạn quyết định refs sẽ có và được quyền truy cập gì từ một thành phần tuỳ chỉnh.
- `useImperativeHandle` giúp giới hạn khả năng truy cập đến tầng native của một Component hay một Element để tránh các trường hợp có mục đích xấu.

::
