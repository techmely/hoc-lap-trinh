---
title: "State trong Reactjs"
description: "State về cơ bản là một giá trị biến đặc biệt trong React. Nó là giá trị mà khi thay đổi, React sẽ tiến hành việc tính toán lại kết quả của component, và từ đó cập nhật lại giao diện. Để sử dụng được state, chúng ta cần import một function từ trong thư viện React là useState. useState và một số function khác trong thư viện được gọi là các “hooks”. Chúng ta sẽ biết tới các hooks khác của React ở những bài sau"
chapter:
  name: "Tương tác trong Reactjs"
  slug: "chuong-04-tuong-tac-trong-reactjs"
image: https://kungfutech.edu.vn/thumbnail.png
position: 2
---

State về cơ bản là một giá trị biến đặc biệt trong React. Nó là giá trị mà khi thay đổi, React sẽ tiến hành việc tính toán lại kết quả của component, và từ đó cập nhật lại giao diện. Để sử dụng được state, chúng ta cần import một function từ trong thư viện React là useState. useState và một số function khác trong thư viện được gọi là các “hooks”.

Xét ví dụ sau:

```js
const App = () => {
	let count = 0;

	const handleClick = () => {
		count = count + 1;
		console.log("count: ", count)
	}

	return (
		<div>
			<span>{count}</span>
			<button onClick={handleClick}>Increase</button>
		</div>
	)
}
```

Với ví dụ trên, khi ta click vào button, giá trị của biến `count` sẽ được thay đổi. Khi chúng ta mở màn hình console cũng sẽ nhận được giá trị của `count` in ra màn hình. Và chúng ta cũng sẽ mong đợi rằng component `App` sẽ thực hiện việc tính toán lại để thay đổi giá trị trong cặp thẻ `<span>`. Từ đó, giao diện sẽ được cập nhật.

Tuy nhiên thì giao diện sẽ **không** được cập nhật!

Thực tế, các biến thông thường như `count` trong ví dụ trên sẽ không làm cho React thực hiện việc tính toán lại dữ liệu và cập nhật giao diện. React sẽ hoàn toàn bỏ qua sự thay đổi của các biến đó. Khi chúng ta muốn cho React biết rằng nó cần tính toán lại giao diện, chúng ta cần sử dụng một khái niệm đặc biệt từ React: **“State”**

## Sử dụng state với React hooks

**State** về cơ bản là một giá trị biến đặc biệt trong React. Nó là giá trị mà khi thay đổi, React sẽ tiến hành việc tính toán lại kết quả của component, và từ đó cập nhật lại giao diện. Để sử dụng được state, chúng ta cần import một function từ trong thư viện React là `useState`. `useState` và một số function khác trong thư viện được gọi là các “hooks”. Chúng ta sẽ biết tới các hooks khác của React ở những bài sau.

Cú pháp cơ bản của `useState` như sau:

`const <tên_biến_state> = useState(<giá_trị_ban_đầu_của_state>)`

`useState` trong React là một function với đặc điểm sau:

- Tham số đầu vào là một giá trị trong JS, đây cũng là giá trị khởi đầu cho state đó.
- Kết quả trả về là một **array**. Trong đó có 2 phần tử: phần tử thứ nhất là giá trị của state đó, phần tử thứ hai là một function khác.

Xem ví dụ dưới đây:

```jsx
import {useState} from 'react'

const App = () => {
	const countState = useState(10)
	
	console.log("count: ", countState[0]);

	return <div>{countState[0]}</div>
}:
```

Trong ví dụ, trên, chúng ta khởi tạo một biến là `countState` với giá trị ban đầu bằng 10. `countState` có giá trị là một mảng gồm 2 phần tử. Phần tử ở vị trí 0 của `countState` chính là giá trị của state. Ở trong ví dụ trên thì giá trị của nó ban đầu là 10. Do đó, chúng ta sẽ nhìn thấy số 10 được in ra trên màn hình.

Giá trị state đặc biệt hơn các biến thông thường khác: khi thay đổi, React sẽ tiến hành việc tính toán lại kết quả của [component](/bai-viet/reactjs/component-trong-react-la-gi) và cập nhật lại giao diện. Để có thể cập nhật được giá trị của state. Ta cần sử dụng một function đặc biệt, đó là tham số thứ hai của `countState`:

```jsx
import {useState} from 'react'

const App = () => {
	const countState = useState(10)
	const count = countState[0]
	const setCount = countState[1]

	const onIncreaseClick = () => {
		setCount(count + 1)
	}	

	return (
		<div>
			<span>{count}</span>
			<button onClick={onIncreaseClick}>Increase</button>
		</div>
	)
}
```

Function `setCount` nhận vào một tham số là giá trị tiếp theo mà state đó sẽ nhận. Như ở ví dụ trên, ban đầu, giá trị của `count` là 10. Sau khi click vào button “Increase”, giá trị của mới của `count` sẽ bằng giá trị cũ của nó cộng thêm 1 đơn vị.

::alert{type="infor"}
📌 Trong thực tế, người ta thường sử dụng cú pháp destructuring để khai báo biến `state` và `setState`. Cú pháp như sau:
`const [count, setCount] = useState(10)`. Trong các phần sau, chúng ta sẽ chủ yếu sử dụng cú pháp này.
::

## Cấu trúc của `useState` trong Reactjs

Khi bạn gọi `useState`, bạn đang báo cho React rằng bạn muốn thành phần này "ghi nhớ" một điều gì đó. Dưới đây là cấu trúc cơ bản của việc sử dụng `useState`:

```jsx
const [stateVariable, setStateVariable] = useState(initialValue);
```

- `stateVariable` là biến state bạn muốn sử dụng.
- `setStateVariable` là hàm setter state, nó sẽ cập nhật biến state và kích hoạt React render lại thành phần.
- `initialValue` là giá trị ban đầu của biến state.

Lưu ý: Quy ước là đặt tên cho cặp này giống như `const [điều_gì_đó, set Điều_gì_đó]`. Bạn có thể đặt tên bất kỳ, nhưng việc tuân theo quy ước này làm cho mã dễ đọc hơn khi làm việc với React.

Mỗi khi thành phần của bạn được render, `useState` sẽ trả về một mảng chứa hai giá trị:

1. Biến state hiện tại với giá trị bạn lưu trữ.
2. Hàm setter state (ví dụ: `setIndex`) cho biến state đó.

Sau đó, mỗi lần thành phần của bạn render, `useState` sẽ trả về `[stateHiệnTại, hàmSetter]`. React sẽ nhớ giá trị của `stateHiệnTại` và cập nhật nó khi bạn gọi `hàmSetter`. Điều này đảm bảo rằng dữ liệu của bạn luôn được cập nhật đúng cách và gửi vào việc render lại thành phần.

## Các ví dụ về component trong Reactjs

### Sử dụng nhiều biến `state`

Một thành phần có thể có nhiều biến state với nhiều kiểu dữ liệu khác nhau. Ví dụ dưới đây hiển thị một ví dụ về việc sử dụng hai biến state, một để lưu trữ số index và một để lưu trữ một giá trị boolean:

```jsx
import { useState } from "react";
import { sculptureList } from "./data.js";

export default function Gallery() {
  const [index, setIndex] = useState(0);
  const [showMore, setShowMore] = useState(false);

  function handleNextClick() {
    setIndex(index + 1);
  }

  function handleMoreClick() {
    setShowMore(!showMore);
  }

  let sculpture = sculptureList[index];
  return (
    <>
      <button onClick={handleNextClick}>Next</button>
      <h2>
        <i>{sculpture.name} </i>
        by {sculpture.artist}
      </h2>
      <h3>
        ({index + 1} of {sculptureList.length})
      </h3>
      <button onClick={handleMoreClick}>
        {showMore ? "Hide" : "Show"} details
      </button>
      {showMore && <p>{sculpture.description}</p>}
      <img src={sculpture.url} alt={sculpture.alt} />
    </>
  );
}
```

Cách này cho phép bạn quản lý nhiều biến state trong một thành phần. Điều quan trọng là bạn nên sử dụng nhiều biến state nếu chúng không có mối quan hệ với nhau. Trong ví dụ trên, `index` và `showMore` không có liên quan đến nhau, vì vậy việc sử dụng nhiều biến state là hợp lý.

Nếu bạn thấy mình thường xuyên cần phải thay đổi hai biến state cùng một lúc, thì việc kết hợp chúng thành một biến state duy nhất có thể làm cho mã của bạn trở nên thuận tiện hơn.

## State là sự riêng tư

State trong React là riêng tư và cục bộ cho từng phiên bản của thành phần. Điều này có nghĩa là nếu bạn render cùng một thành phần hai lần, mỗi phiên bản sẽ có state riêng biệt và độc lập. Những thay đổi trong một phiên bản sẽ không ảnh hưởng đến phiên bản khác.

Ví dụ, ở ví dụ dưới đây, thành phần Gallery được render hai lần mà không có sự th

ay đổi trong logic. Bạn có thể thử nhấn vào các nút trong mỗi phiên bản và thấy rằng state của chúng là độc lập:

```jsx
import Gallery from "./Gallery.js";

export default function Page() {
  return (
    <div className="Page">
      <Gallery />
      <Gallery />
    </div>
  );
}
```

Điều này làm cho `state` khác biệt với các biến thông thường mà bạn có thể định nghĩa ở đầu tệp mã. State không liên quan đến cuộc gọi hàm hoặc vị trí trong mã, mà nó "cục bộ" đối với mỗi phiên bản cụ thể trên màn hình.

Đồng thời, bạn có thể thấy rằng thành phần cha không "biết" gì về state của thành phần con hoặc thậm chí không biết liệu nó có sử dụng state hay không. Khác với props, state là hoàn toàn riêng tư đối với thành phần khai báo nó. Thành phần cha không thể thay đổi state của thành phần con. Điều này cho phép bạn thêm state vào bất kỳ thành phần nào hoặc loại bỏ nó mà không ảnh hưởng đến các thành phần khác.

::alert{type="success"}

Trong bài viết này, bạn đã tìm hiểu về cách làm việc với state trong ReactJS sử dụng Hook `useState`. Dưới đây là những điểm quan trọng bạn đã học:

- Sử dụng biến state khi cần "ghi nhớ" thông tin giữa các lần render của thành phần.
- Khai báo biến state bằng cách gọi Hook `useState`.
- Hook là các hàm đặc biệt trong React và bắt đầu bằng "use," chúng chỉ có sẵn trong quá trình React render.
- Hook chỉ có thể được gọi ở cấp độ cao nhất của thành phần hoặc trong các Hook tùy chỉnh của riêng bạn.
- Hook `useState` trả về một cặp giá trị: biến state hiện tại và hàm setter state để cập nhật biến state và kích hoạt React render lại thành phần.
- Bạn có thể có nhiều biến state khác nhau trong cùng một thành phần.
- State là riêng tư và cục bộ cho từng phiên bản của thành phần.

::
