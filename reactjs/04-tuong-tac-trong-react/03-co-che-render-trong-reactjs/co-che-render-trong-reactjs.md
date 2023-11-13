---
title: "Cơ chế render trong Reactjs"
description: "Trước khi các thành phần của bạn được hiển thị trên màn hình, chúng phải được render bởi React. Hiểu các bước trong quá trình này sẽ giúp bạn suy nghĩ về cách mã của bạn thực thi và giải thích hành vi của nó."
chapter:
  name: "Tương tác trong Reactjs"
  slug: "chuong-04-tuong-tac-trong-reactjs"
image: https://kungfutech.edu.vn/thumbnail.png
position: 3
---

Trước khi các [component](/bai-viet/reactjs/component-trong-react-la-gi) của bạn được hiển thị trên màn hình, chúng phải được render bởi React. Hiểu các bước trong quá trình này sẽ giúp bạn hiểu rõ cách thực thi và giải thích hành vi của nó.

![Cơ chế render trong Reactjs](https://github.com/techmely/hoc-lap-trinh/assets/29374426/beedf71a-17a4-4788-a6cc-144494c59f48)

Hãy tưởng tượng rằng các thành phần của bạn giống như những đầu bếp trong nhà bếp, tạo ra các món ngon từ các component. Trong tình huống này, React là người phục vụ nhận yêu cầu từ khách hàng và mang đồ ăn đến cho họ. Quá trình này bao gồm ba bước:

1. **Kích hoạt render lần đầu tiên** (đặt đơn hàng của khách hàng đến bếp).
2. **Render thành phần** (chuẩn bị món ăn trong nhà bếp).
3. **Commit vào DOM** (đặt đơn hàng lên bàn).

## Bước 1: Kích hoạt render lần đầu tiên

Khi ứng dụng của bạn được khởi tạo, bạn cần kích hoạt lần render ban đầu. Nó được thực hiện bằng cách gọi `createRoot` với nút DOM mục tiêu và sau đó gọi phương thức `render` của nó với thành phần của bạn:

```jsx
import Image from "./Image.js";
import { createRoot } from "react-dom/client";

const root = createRoot(document.getElementById("root"));
root.render(<Image />);
```

## Bước 2: React render các component của bạn

Sau khi bạn kích hoạt lần render đầu tiên, React sẽ gọi các component của bạn để xác định nội dung hiển thị trên màn hình. "Render" là việc React gọi các component của bạn.

- Trong lần render đầu tiên, React sẽ gọi component gốc tới các component con.
- Đối với các lần render sau, React sẽ gọi component hàm mà setState được cập nhật gây ra sự thay đổi.

**Ví dụ:**

```jsx
export default function Gallery() {
  return (
    <section>
      <h1>Inspiring Sculptures</h1>
      <Image />
      <Image />
      <Image />
    </section>
  );
}

function Image() {
  return (
    <img
      src="https://i.imgur.com/ZF6s192.jpg"
      alt="'Floralis Genérica' by Eduardo Catalano: a gigantic metallic flower sculpture with reflective petals"
    />
  );
}
```

Trong lần render đầu tiên, React sẽ tạo ra các nút DOM cho `<section>`, `<h1>`, và ba thẻ `<img>`. Trong lần render sau đó, React sẽ tính toán các [state](/bai-viet/reactjs/state-trong-reactjs) của chúng, nếu có sự thay đổi so với lần render trước đó nó sẽ render lại component

## Bước 3: React áp dụng thay đổi vào DOM

Sau quá trình render (gọi) các component của bạn, React sẽ chỉnh sửa DOM.

- Đối với lần render đầu tiên, React sử dụng API DOM `appendChild()` để đưa tất cả các nút DOM mà nó đã tạo lên màn hình.
- Đối với các lần render sau, React sẽ áp dụng các thao tác cần thiết nhất (được tính toán trong quá trình render!) để làm cho DOM phù hợp với đầu ra render gần nhất.

React chỉ thay đổi các nút DOM nếu có sự khác biệt giữa các lần render. Ví dụ, dưới đây là một component mà trong đó có các thuộc tính khác nhau được truyền từ thành phần cha mỗi giây. Lưu ý là bạn có thể thêm văn bản vào `<input>`, cập nhật giá trị của nó, nhưng văn bản không biến mất khi component render lại:

```jsx
export default function Clock({ time }) {
  return (
    <>
      <h1>{time}</h1>
      <input />
    </>
  );
}
```

Điều này hoạt động vì trong bước cuối cùng này, React chỉ cập nhật nội dung của `<h1>` với thời gian mới. Nó thấy rằng `<input>` xuất hiện trong JSX cùng vị trí như lần trước, vì vậy React không chạm vào `<input>` - hoặc giá trị của nó!
