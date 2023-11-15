---
title: "Chia sẻ state giữa các component trong React"
description: ""
chapter:
  name: "Quản lý state trong React"
  slug: "chuong-05-quan-ly-state-trong-react"
image: https://kungfutech.edu.vn/thumbnail.png
position: 2
---

Trong quá trình phát triển ứng dụng React, có lúc bạn muốn `state` của hai `component` luôn thay đổi cùng nhau. Để làm điều này, bạn cần loại bỏ `state` khỏi cả hai `component`, di chuyển nó đến `component` cha chung gần nhất của chúng, sau đó truyền nó xuống cho chúng thông qua `props`. Đây được gọi là việc "nâng state lên" và đây là một trong những điều phổ biến nhất bạn sẽ thực hiện khi viết mã React.

## Chuyển `state` lên component cha

Trong ví dụ sau, chúng ta có một `component` cha `Accordion` và hai `component` con `Panel`:

```jsx
import { useState } from "react";

function Panel({ title, children }) {
  const [isActive, setIsActive] = useState(false);
  return (
    <section className="panel">
      <h3>{title}</h3>
      {isActive ? (
        <p>{children}</p>
      ) : (
        <button onClick={() => setIsActive(true)}>Show</button>
      )}
    </section>
  );
}

export default function Accordion() {
  return (
    <>
      <h2>Almaty, Kazakhstan</h2>
      <Panel title="About">
        Với dân số khoảng 2 triệu người, Almaty là thành phố lớn nhất của
        Kazakhstan. Từ năm 1929 đến năm 1997, nó là thủ đô của đất nước này.
      </Panel>
      <Panel title="Etymology">
        Tên gọi này xuất phát từ từ <span lang="kk-KZ">алма</span>, từ Kazakh có
        nghĩa là "táo" và thường được dịch là "đầy táo". Trong thực tế, vùng
        xung quanh Almaty được cho là quê hương của cây táo, và loài{" "}
        <i lang="la">Malus sieversii</i> hoang dã được coi là một ứng cử viên có
        thể là tổ tiên của táo trong thời đại hiện đại.
      </Panel>
    </>
  );
}
```

Ban đầu, mỗi `Panel` có một `state` boolean `isActive` xác định liệu nội dung của nó có hiển thị hay không. Nhấn nút "Show" cho cả hai `Panel`, bạn sẽ thấy rằng chúng hoàn toàn độc lập.

Nhưng giờ, nếu bạn muốn chỉ một `Panel` được mở rộng vào một thời điểm, việc mở rộng `Panel` thứ hai sẽ làm thu nhỏ `Panel` thứ nhất. Làm thế nào bạn có thể làm điều đó?

Để điều phối hai `Panel` này, bạn cần "nâng `state` của chúng lên" đến một `component` cha, bằng ba bước sau đây:

### Bước 1: Loại bỏ `state` khỏi các `component` con

Chuyển quyền kiểm soát của `isActive` từ `Panel` đến `component` cha của nó. Bắt đầu bằng việc loại bỏ dòng mã sau khỏi `Panel`:

```jsx
const [isActive, setIsActive] = useState(false);
```

Thay vào đó, thêm `isActive` vào danh sách props của `Panel`:

```jsx
function Panel({ title, children, isActive }) {
  // ...
}
```

Như vậy, `Panel` cha giờ có thể kiểm soát `isActive` bằng cách truyền nó xuống như một props.

### Bước 2: Truyền dữ liệu cố định từ `component` cha chung:

Để "nâng `state` lên," bạn cần xác định `component` cha chung gần nhất của hai `component` con mà bạn muốn điều phối. Trong ví dụ này, đó là `component` `Accordion`. Vì nó nằm trên cả hai `Panel` và có thể kiểm soát props của chúng, nó sẽ trở thành "nguồn thông tin" cho việc xác định `Panel` nào đang hoạt động. Hãy làm cho `component` `Accordion` truyền giá trị `isActive` (ví dụ: true) xuống cho cả hai `Panel`:

```jsx
export default function Accordion() {
  return (
    <>
      <h2>Almaty, Kazakhstan</h2>
      <Panel title="About" isActive={true}>
        // Nội dung Panel 1
      </Panel>
      <Panel title="Etymology" isActive={true}>
        // Nội dung Panel 2
      </Panel>
    </>
  );
}
```

### Bước 3: Thêm `state` vào `component` cha chung:

Với việc `state` được nâng lên, bạn cần thay đổi bản chất của nó. Trong trường hợp này, chỉ một `Panel` nên được mở rộng vào một thời điểm. Điều này có nghĩa là `component` cha chung `Accordion` cần theo dõi `Panel` nào đang hoạt động. Thay vì sử dụng giá trị boolean, bạn có thể sử dụng một số làm chỉ số của `Panel` đang hoạt động trong biến `state`:

```jsx
const [activeIndex, setActiveIndex] = useState(0);
```

Khi `activeIndex` là 0, `Panel` đầu tiên được mở rộng, và khi là 1, `Panel` thứ hai được mở rộng.

::alert{type="success"}

Khi bạn muốn điều phối hai hoặc nhiều `component` trong React, hãy di chuyển `state` của chúng lên `component` cha chung và truyền thông tin xuống cho các `component` con thông qua props. Điều này giúp bạn duy trì một nguồn thông tin duy nhất cho mỗi `state` và đảm bảo rằng các `component` hoạt động cùng nhau một cách đồng nhất.

Lưu ý rằng trong quá trình phát triển ứng dụng React, bạn có thể thay đổi vị trí của `state` để đảm bảo rằng mỗi `state` có một "nguồn thông tin duy nhất". Điều này giúp bạn quản lý `state` một cách hiệu quả trong ứng dụng của mình.

::
