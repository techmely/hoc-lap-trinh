---
title: "Cơ chế render trong Reactjs"
description: "Trước khi các thành phần của bạn được hiển thị trên màn hình, chúng phải được render bởi React. Hiểu các bước trong quá trình này sẽ giúp bạn suy nghĩ về cách mã của bạn thực thi và giải thích hành vi của nó."
chapter:
  name: "Tương tác trong Reactjs"
  slug: "chuong-04-tuong-tac-trong-reactjs"
image: https://kungfutech.edu.vn/thumbnail.png
position: 3
---

Trước khi các thành phần của bạn được hiển thị trên màn hình, chúng phải được render bởi React. Hiểu các bước trong quá trình này sẽ giúp bạn suy nghĩ về cách mã của bạn thực thi và giải thích hành vi của nó.

Hãy tưởng tượng rằng các thành phần của bạn giống như những đầu bếp trong nhà bếp, tạo ra các món ngon từ các thành phần. Trong tình huống này, React là người phục vụ nhận yêu cầu từ khách hàng và mang đồ ăn đến cho họ. Quá trình này bao gồm ba bước:

1. **Kích hoạt một lần render** (đặt đơn hàng của khách hàng đến bếp).
2. **Render thành phần** (chuẩn bị món ăn trong nhà bếp).
3. **Commit vào DOM** (đặt đơn hàng lên bàn).

## Bước 1: Kích hoạt một lần render

Có hai lý do khiến một thành phần cần phải render:

- Đó là lần render ban đầu của thành phần.
- Trạng thái của thành phần (hoặc của một trong các thành phần cha của nó) đã được cập nhật.

**Lần render ban đầu**
Khi ứng dụng của bạn khởi đầu, bạn cần kích hoạt lần render ban đầu. Các framework và môi trường thường che giấu mã này, nhưng nó được thực hiện bằng cách gọi `createRoot` với nút DOM mục tiêu và sau đó gọi phương thức `render` của nó với thành phần của bạn:

```jsx
import Image from "./Image.js";
import { createRoot } from "react-dom/client";

const root = createRoot(document.getElementById("root"));
root.render(<Image />);
```

## Bước 2: React render các thành phần của bạn

Sau khi bạn kích hoạt lần render, React sẽ gọi các thành phần của bạn để xác định nội dung hiển thị trên màn hình. "Render" là việc React gọi các thành phần của bạn.

- Trong lần render ban đầu, React sẽ gọi thành phần gốc.
- Đối với các lần render sau, React sẽ gọi thành phần hàm mà trạng thái đã được cập nhật gây ra sự thay đổi.

Quá trình này là đệ quy: nếu thành phần được cập nhật trả về một thành phần khác, React sẽ render thành phần đó tiếp theo, và nếu thành phần đó cũng trả về một cái gì đó, thì React sẽ render thành phần đó tiếp theo, và cứ thế cho đến khi không còn thành phần lồng nhau nữa và React biết chính xác nên hiển thị gì trên màn hình.

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

Trong lần render ban đầu, React sẽ tạo ra các nút DOM cho `<section>`, `<h1>`, và ba thẻ `<img>`. Trong lần render sau đó, React sẽ tính toán xem các thuộc tính của chúng, nếu có, đã thay đổi so với lần render trước đó. React sẽ không thực hiện bất kỳ thay đổi nào với thông tin đó cho đến bước tiếp theo, bước commit.

::alert{type="warning"}

**Lưu ý**: Quá trình render phải luôn là một tính toán thuần túy: Cùng một đầu vào sẽ cho ra cùng một đầu ra. Nếu đưa cùng một đầu vào, một thành phần phải luôn trả về JSX giống nhau. Ngoài ra, nó phải giữ nguyên các đối tượng hoặc biến tồn tại trước khi render. Nếu không, bạn có thể gặp phải các lỗi khó hiểu và hành vi không đoán trước khi mã nguồn của bạn phức tạp lên. Khi phát triển trong "Strict Mode", React sẽ gọi mỗi hàm thành phần hai lần, điều này có thể giúp phát hiện các lỗi do hàm không thuần túy gây ra.

::

## Bước 3: React áp dụng thay đổi vào DOM

Sau quá trình render (gọi) các thành phần của bạn, React sẽ chỉnh sửa DOM.

- Đối với lần render ban đầu, React sử dụng API DOM `appendChild()` để đưa tất cả các nút DOM mà nó đã tạo lên màn hình.
- Đối với các lần render sau, React sẽ áp dụng các thao tác cần thiết nhất (được tính toán trong quá trình render!) để làm cho DOM phù hợp với đầu ra render gần nhất.

React chỉ thay đổi các nút DOM nếu có sự khác biệt giữa các lần render. Ví dụ, dưới đây là một thành phần mà trong đó có các thuộc tính khác nhau được truyền từ thành phần cha mỗi giây. Lưu ý là bạn có thể thêm văn bản vào `<input>`, cập nhật giá trị của nó, nhưng văn bản không biến mất khi thành phần render lại:

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

**Kết luận: Sơn trạng thái trình duyệt**
Sau khi quá trình render hoàn thành và React cập nhật DOM, trình duyệt sẽ vẽ lại màn hình. Mặc dù quá trình này được gọi là "sơn trình duyệt", chúng tôi sẽ gọi nó là "sơn" để tránh nhầm lẫn trong toàn bộ tài liệu.

::alert{type="success"}

- Mọi cập nhật màn hình trong ứng dụng React đều xảy ra trong ba bước: Kích hoạt, Render, Commit.
- Bạn có thể sử dụng Chế độ nghiêm ngặt (Strict Mode) để tìm lỗi trong các thành phần của bạn.
- React không can thiệp vào DOM nếu kết quả render giống với lần render trước.

::
