---
title: "Sự kiện (event) trong Reactjs"
description: "Trong React, bạn có thể thêm các xử lý sự kiện (event handlers) vào JSX của bạn. Các xử lý sự kiện là các hàm của riêng bạn sẽ được kích hoạt khi có sự tương tác như nhấp chuột, di chuột qua, tập trung vào đầu vào biểu mẫu và nhiều tương tác khác"
chapter:
  name: "Tương tác trong Reactjs"
  slug: "chuong-04-tuong-tac-trong-reactjs"
image: https://kungfutech.edu.vn/thumbnail.png
position: 1
---

Trong React, bạn có thể thêm các xử lý sự kiện (event handlers) vào JSX của bạn. Các event handlers là các hàm sẽ được kích hoạt khi có sự tương tác như nhấp chuột, di chuột qua, ,... và nhiều tương tác khác.

![Sự kiện (event) trong Reactjs](https://github.com/techmely/hoc-lap-trinh/assets/29374426/f34befbd-0e11-4f26-a7a3-cf6f1cd7887b)

## Thêm xử lý sự kiện trong Reactjs

Để thêm một xử lý sự kiện, đầu tiên bạn sẽ cần định nghĩa một hàm và sau đó truyền nó như một [prop](/bai-viet/reactjs/prop-va-truyen-prop-vao-component) cho thẻ JSX tương ứng. Ví dụ, dưới đây là một nút không làm gì cả:

```jsx
import React from "react";

export default function Button() {
  return <button>Tôi không làm gì cả</button>;
}
```

Bạn có thể làm cho nút này hiển thị một thông báo khi người dùng nhấp chuột bằng cách làm theo ba bước sau:

1. Định nghĩa một hàm gọi là `handleClick` trong thành phần `Button`.
2. Thực hiện logic trong hàm này (sử dụng `alert` để hiển thị thông báo).
3. Thêm `onClick={handleClick}` vào thẻ `<button>`.

Dưới đây là mã ví dụ:

```jsx
import React from "react";

export default function Button() {
  function handleClick() {
    alert("Bạn đã click chuột vào tôi!");
  }

  return <button onClick={handleClick}>Nhấp chuột vào tôi</button>;
}
```

Trong ví dụ trên, chúng ta đã định nghĩa hàm `handleClick` và sau đó truyền nó như một prop cho `<button>` bằng cách sử dụng `onClick={handleClick}` - `handleClick` là một xử lý sự kiện. Thông thường, các hàm xử lý sự kiện được định nghĩa bên trong [component](/bai-viet/reactjs/component-trong-react-la-gi) của bạn và có tên bắt đầu bằng `handle`, tiếp theo là tên của sự kiện. Theo quy ước, bạn thường thấy `onClick={handleClick}`, `onMouseEnter={handleMouseEnter}`, và nhiều sự kiện khác tương tự.

Ngoài ra, bạn cũng có thể định nghĩa một xử lý sự kiện trực tiếp trong JSX:

```jsx
<button onClick={function handleClick() {
  alert('Bạn đã nhấp chuột vào tôi!');
}}>
```

Hoặc ngắn gọn hơn, bạn có thể sử dụng hàm mũi tên:

```jsx
<button onClick={() => {
  alert('Bạn đã nhấp chuột vào tôi!');
}}>
```

Tất cả các cách trên đều tương đương.

**Lưu ý quan trọng**

Hàm được truyền vào xử lý sự kiện phải được truyền, không được gọi. Ví dụ:

- Đúng: `<button onClick={handleClick}>` - trong ví dụ này, hàm `handleClick` được truyền làm xử lý sự kiện `onClick`. Điều này cho biết cho React để nhớ nó và chỉ gọi hàm của bạn khi người dùng nhấp vào `button`
- Sai: `<button onClick={handleClick()}>` - trong ví dụ này, dấu ngoặc `()` ở cuối của `handleClick()` sẽ kích hoạt hàm ngay lập tức trong quá trình `rendering`, mà không cần có sự kiện nhấp chuột. Điều này xảy ra vì mã JavaScript bên trong `{}` được thực thi ngay lập tức.

## Đọc `props` trong xử lý sự kiện trong Reactjs

Vì xử lý sự kiện được định nghĩa bên trong một component, nó có quyền truy cập vào `props` của component đó. Dưới đây là ví dụ về một `button`, khi nhấp vào, sẽ hiển thị một thông báo với `props` message của nó:

```jsx
import React from "react";

function AlertButton({ message, children }) {
  return <button onClick={() => alert(message)}>{children}</button>;
}

export default function Toolbar() {
  return (
    <div>
      <AlertButton message="Bắt đầu phát!">Phát phim</AlertButton>
      <AlertButton message="Đang tải lên!">Tải lên hình ảnh</AlertButton>
    </div>
  );
}
```

Điều này cho phép hai nút này hiển thị các thông báo khác nhau. Bạn có thể thay đổi thông điệp được truyền vào để thay đổi nội dung thông báo.

## Truyền xử lý sự kiện như `props` trong Reactjs

Thường thì bạn muốn cho phép component cha chỉ định một xử lý sự kiện cho thành phần con của nó.

Để làm điều này, bạn có thể truyền một `prop` mà thành phần con nhận được từ thành phần cha và sử dụng nó như một xử lý sự kiện. Dưới đây là ví dụ:

```jsx
import React from "react";

function Button({ onClick, children }) {
  return <button onClick={onClick}>{children}</button>;
}

function PlayButton({ movieName }) {
  function handlePlayClick() {
    alert(`Bắt đầu phát "${movieName}"!`);
  }

  return <Button onClick={handlePlayClick}>Phát "${movieName}"</Button>;
}

function UploadButton() {
  return (
    <Button onClick={() => alert("Đang tải lên!")}>Tải lên hình ảnh</Button>
  );
}

export default function Toolbar() {
  return (
    <div>
      <PlayButton movieName="Kiki's Delivery Service" />
      <UploadButton />
    </div>
  );
}
```

Ở đây, component `Toolbar` hiển thị component `PlayButton` và component `UploadButton`. `PlayButton` truyền `handlePlayClick` như là `onClick` cho component `Button` bên trong nó, trong khi `UploadButton` truyền một hàm vô danh để hiển thị thông báo khi người dùng nhấp vào.

Cuối cùng, component `Butto`n của bạn chấp nhận một `prop` gọi là `onClick` và truyền nó trực tiếp cho thẻ `<button>` của trình duyệt với `onClick={onClick}`. Điều này cho biết cho React gọi hàm đã truyền khi người dùng click chuột.

## Đặt tên `props` của xử lý sự kiện trong Reactjs

Các thành phần tích hợp sẵn như `<button>` và `<div>` chỉ hỗ trợ các tên sự kiện trình duyệt mặc định như `onClick`. Tuy nhiên, khi bạn xây dựng các thành phần của riêng mình, bạn có thể đặt tên các `prop` của xử lý sự kiện bằng bất kỳ cách nào bạn muốn.

Theo quy ước, các `prop` của xử lý sự kiện nên bắt đầu bằng "on" sau đó là một chữ cái viết hoa. Ví dụ, `prop` `onClick` của thành phần Button có thể được gọi là `onSmash`:

```jsx
import React from "react";

function Button({ onSmash, children }) {
  return <button onClick={onSmash}>{children}</button>;
}
```

Ở ví dụ này, `<button onClick={onSmash}>` cho thấy rằng thẻ `<button>` (viết thường) của trình duyệt vẫn cần một `prop` gọi là `onClick`, nhưng tên `prop` nhận được bởi component `Button` của bạn hoàn toàn do bạn quyết định!

Khi component của bạn hỗ trợ nhiều tương tác, bạn có thể đặt tên các `prop` của xử lý sự kiện cho các khái niệm cụ thể cho ứng dụng. Ví dụ, thành phần `Toolbar` này nhận các xử lý sự kiện `onPlayMovie` và `onUploadImage`:

```jsx
import React from "react";

export default function Toolbar({ onPlayMovie, onUploadImage }) {
  return (
    <div>
      <Button onClick={onPlayMovie}>Phát phim</Button>
      <Button onClick={onUploadImage}>Tải lên hình ảnh</Button>
    </div>
  );
}
```

## Lan truyền sự kiện trong Reactjs

Các xử lý sự kiện cũng sẽ xử lý sự kiện từ bất kỳ component con nào mà thành phần của bạn có. Chúng ta nói rằng một sự kiện "lan truyền" hoặc "nổi lên" theo cây component: nó bắt đầu từ nơi sự kiện xảy ra và sau đó đi lên cây component.

Dưới đây là một ví dụ về một `<div>` chứa hai nút. Cả `<div>` và từng nút đều có các xử lý sự kiện riêng của họ. Bạn nghĩ rằng những xử lý sự kiện nào sẽ được kích hoạt khi bạn nhấp vào một nút?

```jsx
import React from "react";

export default function Toolbar() {
  return (
    <div
      className="Toolbar"
      onClick={() => {
        alert("Bạn đã nhấp chuột vào thanh công cụ!");
      }}
    >
      <button onClick={() => alert("Bắt đầu phát!")}>Phát phim</button>
      <button onClick={() => alert("Đang tải lên!")}>Tải lên hình ảnh</button>
    </div>
  );
}
```

Nếu bạn nhấp vào bất kỳ nút nào, xử lý `onClick` của nút đó sẽ chạy đầu tiên, tiếp theo là xử lý `onClick` của `<div>` cha. Vì vậy, hai thông báo sẽ xuất hiện. Nếu bạn click vào thanh công cụ chính, chỉ xử lý `onClick` của `<div>` cha sẽ chạy.

::alert{type="warning"}
**Lưu ý**: Tất cả các sự kiện đều lan truyền trong React ngoại trừ `onScroll`, chỉ hoạt động trên thẻ JSX bạn gắn nó.
::

## Ngừng lan truyền sự kiện trong Reactjs

Các xử lý sự kiện nhận một đối tượng sự kiện làm đối số duy nhất. Theo quy ước, thường gọi đối tượng này là `e`, viết tắt của "event". Bạn có thể sử dụng đối tượng này để đọc thông tin về sự kiện.

Đối tượng sự kiện cũng cho phép bạn ngăn chặn lan truyền. Nếu bạn muốn ngăn một sự kiện không được lan truyền đến các thành phần cha, bạn cần gọi `e.stopPropagation()` như trong thành phần Button dưới đây:

```jsx
import React from "react";

function Button({ onClick, children }) {
  return (
    <button
      onClick={(e) => {
        e.stopPropagation();
        onClick();
      }}
    >
      {children}
    </button>
  );
}

export default function Toolbar() {
  return (
    <div
      className="Toolbar"
      onClick={() => {
        alert("Bạn đã nhấp chuột vào thanh công cụ!");
      }}
    >
      <Button onClick={() => alert("Bắt đầu phát!")}>Phát phim</Button>
      <Button onClick={() => alert("Đang tải lên!")}>Tải lên hình ảnh</Button>
    </div>
  );
}
```

Khi bạn click vào một button:

1. React sẽ gọi xử lý `onClick` được truyền vào `<button>`.
2. Xử lý này, được định nghĩa trong Button, thực hiện hai việc sau:

   - Gọi `e.stopPropagation()`, ngăn sự kiện không lan truyền nữa.
   - Gọi hàm `onClick()` được truyền vào từ thành phần cha.

3. Hàm này, được định nghĩa trong component `Toolbar`, hiển thị thông báo của button riêng của nó. Nhờ `e.stopPropagation()`, xử lý `onClick` của `<div>` cha không chạy. Kết quả là sau khi ngăn chặn lan truyền, chỉ có một thông báo xuất hiện (từ `<button>`) thay vì hai thông báo (từ `<button>` và `<div>` cha). Việc ngăn chặn lan truyền là hợp lý với giao diện người dùng này vì việc nhấp vào các nút không giống nhau so với click vào thanh công cụ xung quanh chúng.

::alert{type="success"}
Xử lý sự kiện là một phần quan trọng của phát triển ứng dụng React. Bằng cách biết cách thêm xử lý sự kiện, truyền chúng giữa các component, và kiểm soát sự kiện lan truyền, bạn có thể tạo ra các ứng dụng React phức tạp và tương tác một cách hiệu quả.
::
