---
title: "Vòng đời của useEffect trong React"
description: "Trong React, effect (Effects) có vòng đời riêng biệt so với các component. Các component có thể được gắn kết (mount), cập nhật (update), hoặc bị gỡ bỏ (unmount), trong khi một effect chỉ có thể thực hiện hai việc"
chapter:
  name: "React nâng cao"
  slug: "chuong-06-react-nang-cao"
image: https://kungfutech.edu.vn/thumbnail.png
position: 5
---

Trong React, effect có vòng đời riêng biệt so với các component. Các component có thể được gắn kết (mount), cập nhật (update), hoặc bị gỡ bỏ (unmount), trong khi một effect chỉ có thể thực hiện hai việc: bắt đầu đồng bộ hóa một cái gì đó và sau đó dừng việc đồng bộ hóa đó. Quy trình này có thể xảy ra nhiều lần nếu effect của bạn phụ thuộc vào các thuộc tính (props) và trạng thái (state) mà thay đổi theo thời gian. React cung cấp một quy tắc lập trình để kiểm tra xem bạn đã chỉ định đúng các phụ thuộc của effect hay chưa. Điều này giúp effect của bạn luôn đồng bộ với các props và state mới nhất.

## Vòng đời của effect

Mỗi component React đều trải qua cùng một vòng đời cơ bản:

1. Thành phần được gắn kết khi nó được thêm vào màn hình.
2. Thành phần được cập nhật khi nó nhận được props hoặc state mới, thường là do tương tác của người dùng.
3. Thành phần bị gỡ bỏ khi nó bị xóa khỏi màn hình.

Đây là một cách tốt để xem xét vòng đời của các component, nhưng không áp dụng cho effect. Thay vào đó, hãy cố gắng xem xét mỗi effect một cách độc lập khỏi vòng đời của component của bạn. Một effect mô tả cách đồng bộ hóa một hệ thống bên ngoài với props và state hiện tại của bạn. Khi mã của bạn thay đổi, việc đồng bộ hóa sẽ cần xảy ra thường xuyên hơn hoặc ít hơn.

Hãy xem xét ví dụ sau để minh họa điều này. Dựa trên đoạn mã React sử dụng thư viện React Router:

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

## Tại sao cần phải đồng bộ lại hiệu ứng?

Sự cần thiết của việc đồng bộ hóa hiệu ứng nảy sinh khi bạn cần theo kịp các thay đổi trong `props` hoặc `state`. Hãy xem xét ví dụ sau:

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

Trong ví dụ này, effect `useEffect` sử dụng `count` như một phụ thuộc. Nếu `count` thay đổi, effect sẽ thực hiện việc cập nhật `message` để hiển thị giá trị mới của `count`. Nếu bạn loại bỏ `count` khỏi danh sách phụ thuộc của effect, thì effect sẽ không bao giờ được đồng bộ hóa khi `count` thay đổi, và bạn sẽ không thể nhìn thấy sự thay đổi trong giao diện người dùng.

## Cách xác định các phụ thuộc của effect

Để xác định các phụ thuộc của effect, bạn cần hiểu rõ các giá trị mà effect của bạn đọc và sử dụng. Mỗi giá trị đó cần phải được xem xét là một phụ thuộc của effect. Trong

React, bạn chỉ cần liệt kê các phụ thuộc này trong mảng phụ thuộc của `useEffect`.

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

Trong ví dụ này, `count` là một phụ thuộc của effect. Nó được sử dụng bên trong effect để tính toán `message`. Vì vậy, chúng ta đưa `count` vào mảng phụ thuộc của `useEffect` để đảm bảo rằng effect sẽ được đồng bộ hóa mỗi khi `count` thay đổi.

## Ý nghĩa của giá trị phản ứng

Khi bạn đưa các phụ thuộc vào mảng phụ thuộc của `useEffect`, React sẽ theo dõi các giá trị đó. Khi một hoặc nhiều trong số các giá trị phụ thuộc thay đổi giữa các lần render, effect sẽ được kích hoạt để đồng bộ hóa. Điều này có nghĩa rằng mã trong effect sẽ chạy lại với các giá trị mới của các phụ thuộc.

Trong ví dụ trước, khi `count` thay đổi, effect sẽ chạy lại và cập nhật `message` để hiển thị giá trị mới của `count`.

## Danh sách phụ thuộc trống

Có trường hợp bạn muốn effect chỉ chạy một lần sau khi component được gắn kết, và sau đó không cần thiết phải chạy lại khi bất kỳ giá trị nào thay đổi. Trong trường hợp này, bạn có thể đặt mảng phụ thuộc rỗng (`[]`) để chỉ định rằng effect không có phụ thuộc nào và chỉ cần chạy một lần sau khi component được gắn kết.

Ví dụ:

```jsx
import { useEffect } from "react";

function WelcomeMessage() {
  useEffect(() => {
    alert("Welcome to the website!");
  }, []);

  return <div>Welcome!</div>;
}
```

Trong ví dụ này, effect chỉ chạy một lần sau khi component `WelcomeMessage` được gắn kết, và sau đó không cần thiết phải chạy lại.

## Quy tắc lập trình cho phụ thuộc

React cung cấp một quy tắc lập trình cho việc xác định các phụ thuộc của effect. Quy tắc này giúp bạn đảm bảo rằng effect của bạn sẽ đồng bộ với các props và state mới nhất, và không chạy một cách không cần thiết.

Quy tắc lập trình là:

1. Xác định tất cả các giá trị mà effect của bạn đọc và sử dụng.
2. Liệt kê tất cả các giá trị đó trong mảng phụ thuộc của `useEffect`.

Việc này đảm bảo rằng effect sẽ chạy lại khi bất kỳ giá trị phụ thuộc nào thay đổi, và không chạy lại khi không có giá trị phụ thuộc nào thay đổi.

## Xử lý khi bạn không đồng tình với quy tắc lập trình

Mặc dù quy tắc lập trình trên giúp bạn đảm bảo tính đúng đắn và hiệu suất của effect, có những trường hợp bạn muốn effect chạy lại mỗi khi component render mà không quan tâm đến giá trị props hoặc state cụ thể nào. Trong trường hợp này, bạn có thể bỏ qua mảng phụ thuộc hoàn toàn (để mảng phụ thuộc là `null`) để effect luôn chạy lại sau mỗi lần render.

Ví dụ:

```jsx
import { useEffect } from "react";

function AlwaysRerunEffect() {
  useEffect(() => {
    console.log("This effect runs on every render.");
  }, null);

  return <div>Hello!</div>;
}
```

Trong ví dụ này, effect sẽ chạy lại sau mỗi lần `AlwaysRerunEffect` render, ngay cả khi không có phụ thuộc cụ thể nào được xác định.

::alert{type="success"}

- Trong React, effect (Effects) có vòng đời riêng biệt so với các component (components). Để đảm bảo effect của bạn đồng bộ với các props và state mới nhất, bạn cần xác định các phụ thuộc của effect và liệt kê chúng trong mảng phụ thuộc của `useEffect`. Quy tắc lập trình này giúp bạn duy trì tính chính xác và hiệu suất của ứng dụng React của bạn.
- Hãy luôn xem xét cẩn thận các phụ thuộc của effect và quyết định xem liệu effect cần chạy lại khi có sự thay đổi trong các phụ thuộc đó hay không. Điều này sẽ giúp bạn kiểm soát cách effect hoạt động trong ứng dụng của bạn.

::
