---
title: "Prop và cách truyền prop vào component trong React"
description: "Props là tham số đầu vào của các component trong React. Props là một trong những khái niệm cực kỳ quan trọng của React"
chapter:
  name: "Giao diện trong Reactjs"
  slug: "chuong-03-giao-dien-trong-reactjs"
image: https://kungfutech.edu.vn/thumbnail.png
position: 5
---

Trong React, **props** được sử dụng để truyền thông tin giữa các [component](/bai-viet/reactjs/component-trong-react-la-gi). Mọi component cha có thể truyền thông tin đến các component con của nó bằng cách cung cấp chúng `props`. Props có thể khiến bạn liên tưởng đến các thuộc tính HTML, nhưng bạn có thể truyền bất kỳ giá trị JavaScript nào thông qua chúng, bao gồm các đối tượng, mảng và hàm.

![Prop và cách truyền prop vào component trong React](https://github.com/techmely/hoc-lap-trinh/assets/29374426/fe8735ba-ad19-49de-8ce9-46a68b22aca7)

## Props trong React là gì?

Props là tham số đầu vào của các component trong React. Props là một trong những khái niệm cực kỳ quan trọng của React.

Liên tưởng đơn giản, props trong React chính là các thuộc tính trong HTML. Điểm khác biệt ở đây là chúng ta có thể tự định nghĩa những thuộc tính đó, thay vì với HTML, các thuộc tính được định nghĩa sẵn.

```jsx
const App = () => {
  const x = 1;
  const y = 2;
  return (
    <div>
      <Sum a={x} b={y} />
    </div>
  )
}

const Sum = (props) => {
  console.log(props) // {a: 1, b: 2}
  return <div>The value is: {props.a + props.b}</div>
}
```

Props có thể nhận giá trị thuộc tất cả các kiểu dữ liệu trong Javascript. Props chính là phương tiện để lưu chuyển dữ liệu bên trong React.

Props hoàn toàn do chúng ta tự định nghĩa. Các `components` do chúng ta định nghĩa không hiểu được các giá trị thuộc tính HTML như `src`, `id`, `className`. Chúng đơn thuần là các key trong một object props. Chúng ta sẽ cần gán lại cho các thẻ HTML tương ứng bên trong component.

```jsx
const App = () => {
  return (
    <div>
      <NameCard className="name-card" id="alice" />
    </div>
  )
}

const NameCard = (props) => {
  return (
    <div className={props.className}>
      <div id={props.id}>Name: Alice</div>
    </div>
  )
}
```

Props là `read-only`, nghĩa là chúng ta **không thể thay đổi** được giá trị props bên trong một component.

::alert{type="infor"}
📌 **Tầm quan trọng của props trong React**: props cho phép tạo ra các Component có khả năng tái sử dụng cao. Thay vì dữ liệu được hard-coded bên trong component, props cho phép component có thể nhận được dữ liệu đầu vào mỗi lần sử dụng nó. Đây chính là công cụ để kết nối các component lại với nhau. Vì vậy, props cho phép ứng dụng được chia nhỏ thành nhiều phần.
::

## Cách truyền props vào một component trong React

Trong đoạn code này, component `Profile` không truyền bất kỳ props nào vào component con của nó, `Avatar`:

```javascript
export default function Profile() {
  return <Avatar />;
}
```

Bạn có thể truyền các props vào `Avatar` theo hai bước.

### Bước 1: Truyền props từ component cha vào component con

Đầu tiên, hãy truyền một số `props` vào `Avatar`. Ví dụ, hãy truyền hai props: **person (một đối tượng)** và **size (một con số)**:

```javascript
export default function Profile() {
  return (
    <Avatar person={{ name: "Lin Lanying", imageId: "1bX5QH6" }} size={100} />
  );
}
```

::alert{type="warning"}
Lưu ý: Nếu cặp dấu ngoặc nhọn kép sau `person=` làm bạn bối rối, hãy nhớ rằng chúng chỉ là một đối tượng bên trong các dấu ngoặc nhọn JSX.
::

### Bước 2: Đọc props bên trong component con

Bạn có thể đọc các props này bằng cách liệt kê tên của chúng, ví dụ: `person` và `size`, được ngăn cách bằng dấu phẩy trong `({ và })` ngay sau hàm `Avatar`. Điều này cho phép bạn sử dụng chúng bên trong mã của component `Avatar`, giống như bạn thao tác với biến.

```javascript
function Avatar({ person, size }) {
  // person và size có sẵn ở đây
}
```

Thêm một số logic vào `Avatar` sử dụng các `props` **person** và **size** để render. Bây giờ bạn có thể cấu hình `Avatar` để render theo nhiều cách khác nhau với các `props` khác nhau. Hãy thử điều chỉnh các giá trị!

```javascript
import { getImageUrl } from "./utils.js";

function Avatar({ person, size }) {
  return (
    <img
      className="avatar"
      src={getImageUrl(person)}
      alt={person.name}
      width={size}
      height={size}
    />
  );
}

export default function Profile() {
  return (
    <div>
      <Avatar
        size={100}
        person={{
          name: "Katsuko Saruhashi",
          imageId: "YfeOqp2",
        }}
      />
      <Avatar
        size={80}
        person={{
          name: "Aklilu Lemma",
          imageId: "OKS67lh",
        }}
      />
      <Avatar
        size={50}
        person={{
          name: "Lin Lanying",
          imageId: "1bX5QH6",
        }}
      />
    </div>
  );
}
```

## Giá trị mặc định của props

Nếu bạn muốn đặt một giá trị mặc định cho props để sử dụng khi không có giá trị được chỉ định, bạn có thể làm điều này bằng cách đặt `=` và giá trị mặc định ngay sau tham số:

```javascript
function Avatar({ person, size = 100 }) {
  // ...
}
```

Bây giờ, nếu `<Avatar person={...} />` được render mà không có props `size`, `size` sẽ được đặt thành 100.

Giá trị mặc định chỉ được sử dụng khi props size bị thiếu hoặc nếu bạn truyền `size={undefined}`. Tuy nhiên, nếu bạn truyền `size={null}` hoặc `size={0}`, giá trị mặc định sẽ không được sử dụng.

## Chuyển tiếp toàn bộ props

Đôi khi, việc truyền `props` trở nên lặp đi lặp lại:

```javascript
function Profile({ person, size, isSepia, thickBorder }) {
  return (
    <div className="card">
      <Avatar
        person={person}
        size={size}
        isSepia={isSepia}
        thickBorder={thickBorder}
      />
    </div>
  );
}
```

Không có gì sai với mã lặp đi lặp lại - nó có thể dễ đọc hơn. Nhưng đôi khi bạn có thể muốn sự ngắn gọn, bạn có thể sử dụng cách sau:

```javascript
function Profile(props) {
  return (
    <div className="card">
      <Avatar {...props} />
    </div>
  );
}
```

Cú pháp này chuyển tiếp tất cả props của `Profile` cho `Avatar` mà không cần liệt kê từng tên `props`.

## Children props trong React

Các thẻ HTML có thể chứa bên trong nó các thẻ HTML khác, ví dụ như `div`, `p`, ... Tương tự như vậy, các thẻ “HTML” do chúng ta tự tạo cũng có thể làm được điều tương tự thông qua một giá trị props đặc biệt có tên là `children`. Xét ví dụ sau:

```jsx
import "./Card.css";

const Card = (props) => {
  return <div className="card">{props.children}</div>
}
```

```css
.card {
  padding: 10px;
  border: 1px solid black;
  border-radius: 8px;
  box-shadow: 0 4px 8px 0 rgba(0, 0, 0, 0.2), 0 6px 20px 0 rgba(0, 0, 0, 0.19);
}
```

```jsx
import Card from "./Card.js";

const App = () => {
  return (
    <Card>
      <div>Inside a card</div>
    </Card>
  )
}
```

Cũng tương tự như các props thông thường khác, `children` có thể nhận giá trị là bất cứ kiểu dữ liệu nào. Với ví dụ ở trên, children nhận vào giá trị là một React Element.

`children` props giúp chúng ta có khả năng “compose” các component lại với nhau. Thay vì cố định giá trị bên trong `Card`, lúc này `Card` có thể cho bất cứ component nào nằm trong nó có thêm các thuộc tính CSS ở trên.

## Smart & dump components

Xét 2 ví dụ sau:

```jsx
const Sum = () => {
	const x = 1
	const y = 2
	return <div>{x + y}</div>
}

<Sum />
<Sum />
<Sum />
```

```jsx
const Sum = (props) => {
	const {x, y} = props

	return <div>{x + y}</div>
}
 
<Sum x={1} y={2} />
<Sum x={2} y={3} />
<Sum x={7} y={5} />
```

Trong ví dụ trên thì bên trái, component `Sum` có xử lý logic bên trong, còn bên phải thì không.

Phần bên trái là một Smart Component, và phần bên phải là một Dump Component. Trong thực tế thì chúng ta viết càng nhiều dump component nghĩa là chúng ta càng smart 🙂

Ở ví dụ bên trái, smart component không thể tái sử dụng, vì mỗi lần chúng ta dùng nó, nó luôn cho kết quả là 3.

Ngược lại, với ví dụ bên phải, dump component có thể được sử dụng để in ra tổng 2 số bất kỳ khi chúng ta truyền giá trị vào bên trong.

Tuy nhiên, không phải lúc nào dump component cũng tốt. Vì nếu cho phép truyền quá nhiều props sẽ dẫn đến code khó đọc và khó bảo trì hơn do nhiều thành phần tham gia vào logic của component hơn. Việc quyết định “dump” / “smart” bao nhiêu là đủ còn tuỳ thuộc khá nhiều vào kinh nghiệm của lập trình viên và từng tình huống xử lý khác nhau
