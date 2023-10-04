---
title: "Context trong React"
description: "Context cho phép component cha làm cho một số thông tin trở nên có sẵn cho bất kỳ component nào trong cây component dưới nó - bất kể có bao nhiêu lớp, mà không cần truyền thông tin đó một cách tường minh qua props"
chapter:
  name: "Quản lý state trong React"
  slug: "chuong-05-quan-ly-state-trong-react"
image: https://kungfutech.edu.vn/thumbnail.png
position: 6
---

Trong React, thường thì bạn sẽ truyền thông tin từ một `component` cha đến một `component` con thông qua `props`. Nhưng việc truyền props có thể trở nên phức tạp và bất tiện khi bạn phải truyền chúng qua nhiều `component` ở giữa, hoặc khi nhiều `component` trong ứng dụng của bạn cần cùng một thông tin. Context cho phép `component` cha làm cho một số thông tin trở nên có sẵn cho bất kỳ `component` nào trong cây `component` dưới nó - bất kể có bao nhiêu lớp, mà không cần truyền thông tin đó một cách tường minh qua props.

## Vấn đề với việc truyền props

Truyền `props` là một cách tuyệt vời để truyền dữ liệu qua cây UI của bạn đến các `component` sử dụng nó. Tuy nhiên, khi bạn cần truyền một props sâu qua cây, hoặc khi nhiều `component` cần cùng một props, việc này có thể trở nên phức tạp và gây phiền hà. Khi `component` gần nhất chung có thể ở xa so với các `component` cần dữ liệu, và việc đưa `state` lên cao đến mức đó có thể dẫn đến tình huống gọi là "prop drilling" (khoan lỗ props).

## Lifting state up (Đưa `state` lên cao)

Một trong những cách để giải quyết vấn đề "prop drilling" là đưa `state` lên cao, tức là đưa dữ liệu vào `component` cha gần nhất mà tất cả các `component` cần dữ liệu đó đều là con của nó. Tuy nhiên, việc làm này có thể dẫn đến việc truyền `state` qua nhiều lớp `component` và làm mã nguồn trở nên khó hiểu và khó bảo trì.

## Giới thiệu về Context trong React

`Context` là một tính năng của React cho phép một `component` cha cung cấp dữ liệu cho toàn bộ cây `component` bên dưới nó. Context có nhiều ứng dụng khác nhau. Ví dụ: bạn có một `component` "Heading" (tiêu đề) có thuộc tính "level" để xác định kích thước của tiêu đề. Bạn muốn các tiêu đề trong cùng một phần luôn có cùng kích thước.

## Sử dụng Context

Để sử dụng Context trong React, bạn cần thực hiện ba bước:

### Bước 1: Tạo Context

Trước hết, bạn cần tạo một Context bằng cách sử dụng hàm `createContext` từ thư viện React:

```jsx
import { createContext } from "react";

export const LevelContext = createContext(1);
```

### Bước 2: Sử dụng Context

Sử dụng Hook `useContext` để đọc dữ liệu từ Context trong `component` con. Ví dụ, trong `component` "Heading", bạn có thể sử dụng Context để lấy giá trị "level" mà không cần phải truyền nó qua props:

```jsx
import { useContext } from "react";
import { LevelContext } from "./LevelContext.js";

export default function Heading({ children }) {
  const level = useContext(LevelContext);
  // ...
}
```

### Bước 3: Cung cấp Context

Thành phần cha (ví dụ: "Section") cung cấp Context bằng cách sử dụng một Provider:

```jsx
import { LevelContext } from "./LevelContext.js";

export default function Section({ level, children }) {
  return (
    <section className="section">
      <LevelContext.Provider value={level}>{children}</LevelContext.Provider>
    </section>
  );
}
```

## Các trường hợp sử dụng Context

Context rất hữu ích trong nhiều trường hợp, bao gồm:

- Đổi giao diện (theming): Cho phép bạn thay đổi giao diện ứng dụng, ví dụ như chế độ ban đêm (dark mode).
- Thông tin tài khoản hiện tại: Cho biết `component` hiện tại đang đăng nhập bằng tài khoản nào.
- Định tuyến (routing): Sử dụng bởi các giải pháp định tuyến để xác định đường dẫn hiện tại.
- Quản lý `state`: Khi ứng dụng phức tạp hơn và cần quản lý `state` phức tạp qua nhiều `component`.

Context cũng có thể được kết hợp với `state` (state) để quản lý `state` ứng dụng một cách hiệu quả.

## Khi nào nên sử dụng Context

Context là một công cụ hữu ích, nhưng bạn nên xem xét các lựa chọn khác trước khi sử dụng nó. Trước tiên, hãy cân nhắc truyền props. Nếu `component` của bạn không đơn giản, việc truyền nhiều props qua nhiều lớp `component` không phải lúc nào cũng là một giải pháp tốt. Điều này làm cho luồng dữ liệu rõ ràng hơn và dễ bảo trì.

Hãy xem xét việc tách `component` và truyền JSX thông qua các con của chúng. Nếu bạn truyền dữ liệu qua nhiều lớp `component` trung gian không sử dụng dữ liệu đó (chỉ truyền nó xuống phía dưới), thường điều này có nghĩa là bạn đã quên tách một số `component` dọc đường. Thay vì truyền dữ liệu dưới dạng props cho các `component` không cần nó trực tiếp, hãy tách chúng ra và sử dụng JSX như một phần tử con của `component`. Điều này giúp giảm số lớp giữa `component` xác định dữ liệu và `component` cần nó.

Chỉ khi cả hai phương pháp trên không thích hợp, bạn mới nên xem xét việc sử dụng Context.

::alert{type="success"}

- Context trong React cho phép bạn truyền dữ liệu từ `component` cha xuống toàn bộ cây `component` dưới nó, giúp giải quyết vấn đề truyền props sâu và giúp làm cho mã nguồn dễ bảo trì và dễ đọc hơn. Tuy nhiên, bạn nên cân nhắc sử dụng Context khi không có cách nào tốt hơn để truyền dữ liệu qua cây `component` của bạn.
- Lưu ý rằng Context không giới hạn với các giá trị tĩnh. Nếu bạn truyền giá trị khác nhau trong lần render tiếp theo, React sẽ cập nhật tất cả các `component` sử dụng Context dưới đây. Context thường được sử dụng kết hợp với `state` (state) để quản lý `state` ứng dụng.
- Trước khi sử dụng Context, hãy xem xét các phương án khác nhau, bao gồm việc truyền props và việc truyền JSX thông qua các `component` con, để đảm bảo rằng bạn đang sử dụng Context một cách hiệu quả và hợp lý cho ứng dụng của bạn.

::
