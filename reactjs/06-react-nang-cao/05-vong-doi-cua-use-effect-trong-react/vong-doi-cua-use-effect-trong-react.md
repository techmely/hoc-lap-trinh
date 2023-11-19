---
title: "Vòng đời của useEffect trong React"
description: "Trong React, effect (Effects) có vòng đời riêng biệt so với các component. Các component có thể được gắn kết (mount), cập nhật (update), hoặc bị gỡ bỏ (unmount), trong khi một effect chỉ có thể thực hiện hai việc"
chapter:
  name: "React nâng cao"
  slug: "chuong-06-react-nang-cao"
image: https://kungfutech.edu.vn/thumbnail.png
position: 5
---

Trong React, [effect](/bai-viet/reactjs/use-effect-trong-react) có vòng đời riêng biệt so với các [component](/bai-viet/reactjs/component-trong-react-la-gi). Các component có thể được gắn kết (mount), cập nhật (update), hoặc bị gỡ bỏ (unmount), trong khi một effect chỉ có thể thực hiện hai việc: **bắt đầu đồng bộ hóa một cái gì đó** và sau đó **dừng việc đồng bộ hóa đó**. Quy trình này có thể xảy ra nhiều lần nếu effect của bạn dependencies vào các props và state.

## Vòng đời của effect

Mỗi `component` React đều trải qua cùng một vòng đời cơ bản:

1. Component được gắn kết (mount) khi nó được thêm vào màn hình.
2. Component được cập nhật khi nó nhận được `props` hoặc `state` mới, thường là do tương tác của người dùng.
3. Component bị gỡ bỏ (unmount) khi nó bị xóa khỏi màn hình.

Đây là một vòng đời của các component, nhưng không áp dụng cho effect. Thay vào đó, hãy cố gắng xem xét mỗi effect một cách độc lập khỏi vòng đời của component của bạn. Một effect mô tả cách **đồng bộ hóa** một hệ thống bên ngoài với `props` và `state` hiện tại của bạn. Khi code của bạn thay đổi, việc đồng bộ hóa sẽ cần xảy ra thường xuyên hơn hoặc ít hơn.

![image](https://github.com/techmely/hoc-lap-trinh/assets/29374426/7624b5c0-70f4-4349-987b-a076109bd6ad)

Hãy xem xét ví dụ sau để minh họa điều này. Dựa trên đoạn code React sử dụng thư viện `React Router`:

```jsx
import { useEffect } from "react";
import { useLocation } from "react-router-dom";

function ScrollToTop() {
  const location = useLocation();

  useEffect(() => {
    window.scrollTo(0, 0);
  }, [location.pathname]);

  return null;
}

export default ScrollToTop;
```

Trong ví dụ này, `ScrollToTop` là một effect được sử dụng để đảm bảo rằng khi người dùng chuyển đổi giữa các trang, cửa sổ trình duyệt sẽ được cuộn lên đầu trang. effect này chỉ quan tâm đến thay đổi trong `location.pathname`, và nó sẽ chạy lại mỗi khi giá trị này thay đổi.

## Tại sao cần phải đồng bộ lại effect?

Sự cần thiết của việc đồng bộ hóa effect nảy sinh khi bạn cần theo kịp các thay đổi trong `props` hoặc `state`. Hãy xem xét ví dụ sau:

```jsx
import { useEffect, useState } from "react";

function Example({ count }) {
  const [message, setMessage] = useState("");

  useEffect(() => {
    if (count === 0) {
      setMessage("Count is zero.");
    } else {
      setMessage(`Count is ${count}.`);
    }
  }, [count]);

  return (
    <div>
      <p>{message}</p>
    </div>
  );
}
```

Trong ví dụ này, effect `useEffect` sử dụng `count` như một dependencies. Nếu `count` thay đổi, effect sẽ thực hiện việc cập nhật `message` để hiển thị giá trị mới của `count`. Nếu bạn loại bỏ `count` khỏi danh sách dependencies của effect, thì effect sẽ không bao giờ được đồng bộ hóa khi `count` thay đổi, và bạn sẽ không thể nhìn thấy sự thay đổi trong giao diện người dùng.

## Cách xác định các dependencies của effect

Để xác định các dependencies của effect, bạn cần hiểu rõ các giá trị mà effect của bạn đọc và sử dụng. Mỗi giá trị đó cần phải được xem xét là một dependencies của effect. Trong React, bạn chỉ cần liệt kê các dependencies này trong mảng dependencies của `useEffect`.

Hãy xem xét ví dụ sau:

```jsx
import { useEffect, useState } from "react";

function Example({ count }) {
  const [message, setMessage] = useState("");

  useEffect(() => {
    if (count === 0) {
      setMessage("Count is zero.");
    } else {
      setMessage(`Count is ${count}.`);
    }
  }, [count]);

  return (
    <div>
      <p>{message}</p>
    </div>
  );
}
```

Trong ví dụ này, `count` là một dependencies của effect. Nó được sử dụng bên trong effect để tính toán `message`. Vì vậy, chúng ta đưa `count` vào mảng dependencies của `useEffect` để đảm bảo rằng effect sẽ được đồng bộ hóa mỗi khi `count` thay đổi.

Trong ví dụ này, effect sẽ chạy lại sau mỗi lần `AlwaysRerunEffect` render, ngay cả khi không có dependencies cụ thể nào được xác định.
