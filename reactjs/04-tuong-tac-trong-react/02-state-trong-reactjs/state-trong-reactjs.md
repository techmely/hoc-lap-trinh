---
title: "State trong Reactjs"
description: "Trong thế giới của ReactJS, JSX là một phần quan trọng và không thể thiếu. JSX viết tắt của JavaScript XML là một cú pháp mở rộng cho ngôn ngữ JavaScript, cho phép chúng ta mô tả giao diện người dùng (UI) một cách dễ dàng và rõ ràng hơn"
chapter:
  name: "Tương tác trong Reactjs"
  slug: "chuong-04-tuong-tac-trong-reactjs"
image: https://kungfutech.edu.vn/thumbnail.png
position: 2
---

Trong ReactJS, khi bạn xây dựng ứng dụng, các thành phần thường cần thay đổi nội dung trên màn hình dựa vào tương tác của người dùng. Ví dụ, việc nhập dữ liệu vào một biểu mẫu sẽ cập nhật trường nhập, nhấp vào "tiếp theo" trên một carousel hình ảnh sẽ thay đổi hình ảnh hiển thị, nhấp vào "mua" sẽ đặt sản phẩm vào giỏ hàng. Để làm được điều này, các thành phần cần "ghi nhớ" những điều quan trọng như giá trị hiện tại của trường nhập, hình ảnh hiện tại, giỏ hàng của mua sắm. Trong React, loại "bộ nhớ" riêng của thành phần này được gọi là **state**.

## Điểm khởi đầu

Để hiểu rõ hơn về cách làm việc với state trong React, hãy xem xét một ví dụ cụ thể. Dưới đây là một thành phần React đơn giản, thể hiện một hình ảnh điêu khắc. Bằng cách nhấp vào nút "Next," chúng ta muốn chuyển đổi hiển thị hình điêu khắc tiếp theo bằng cách thay đổi chỉ số index từ 0 lên 1, sau đó 2, và cứ tiếp tục như vậy:

```jsx
import { sculptureList } from "./data.js";

export default function Gallery() {
  let index = 0;

  function handleClick() {
    index = index + 1;
  }

  let sculpture = sculptureList[index];
  return (
    <>
      <button onClick={handleClick}>Next</button>
      <h2>
        <i>{sculpture.name} </i>
        by {sculpture.artist}
      </h2>
      <h3>
        ({index + 1} of {sculptureList.length})
      </h3>
      <img src={sculpture.url} alt={sculpture.alt} />
      <p>{sculpture.description}</p>
    </>
  );
}
```

Tuy nhiên, cách làm này sẽ không hoạt động vì một số lý do:

1. **Biến local không tồn tại giữa các lần render**: Biến `index` ở đây là biến local và không tồn tại qua các lần render khác nhau của thành phần. Khi React render lại thành phần này lần thứ hai, nó sẽ xem xét thành phần này từ đầu mà không xem xét bất kỳ thay đổi nào đối với biến local.
2. **Thay đổi biến local không gây render lại**: Các thay đổi đối với biến local không thông báo cho React cần render lại thành phần với dữ liệu mới.

Để cập nhật một thành phần với dữ liệu mới, bạn cần thực hiện hai điều sau:

1. **Lưu giữ dữ liệu qua các lần render**: Bạn cần giữ lại dữ liệu qua các lần render của thành phần.
2. **Thông báo cho React render lại thành phần**: Khi có thay đổi, bạn cần báo cho React biết để nó vẽ lại thành phần với dữ liệu mới.

## Hook `useState` giúp giải quyết vấn đề

Hook `useState` cung cấp cả hai yếu tố cần thiết để giải quyết vấn đề này:

1. **Biến state để lưu trữ dữ liệu qua các lần render**: Hook `useState` giúp bạn tạo ra biến state để lưu trữ dữ liệu qua các lần render.
2. **Hàm setter state để cập nhật biến state và thông báo render lại**: Nó cung cấp hàm setter state, khi gọi, nó không chỉ cập nhật biến state mà còn thông báo cho React render lại thành phần với dữ liệu mới.

## Thêm một biến `state` trong Reactjs

Để thêm một biến state, bạn cần import `useState` từ React và sử dụng nó trong thành phần của bạn. Dưới đây là cách bạn thay thế biến `index` trong ví dụ trước bằng một biến state:

```jsx
import { useState } from "react";
import { sculptureList } from "./data.js";

export default function Gallery() {
  const [index, setIndex] = useState(0);

  function handleClick() {
    setIndex(index + 1);
  }

  let sculpture = sculptureList[index];
  return (
    <>
      <button onClick={handleClick}>Next</button>
      <h2>
        <i>{sculpture.name} </i>
        by {sculpture.artist}
      </h2>
      <h3>
        ({index + 1} of {sculptureList.length})
      </h3>
      <img src={sculpture.url} alt={sculpture.alt} />
      <p>{sculpture.description}</p>
    </>
  );
}
```

Bây giờ, `index` đã trở thành một biến state và `setIndex` là hàm setter state. Sử dụng hàm setter `setIndex` trong `handleClick` sẽ cập nhật biến state `index` và kích hoạt React render lại thành phần với dữ liệu mới.

## Sử dụng Hook đầu tiên của bạn

Trong React, `useState`, cùng với một số Hook khác, được gọi là "Hook." Hooks là các hàm đặc biệt chỉ có sẵn trong quá trình React render (chúng ta sẽ tìm hiểu thêm về điều này sau). Chúng cho phép bạn "kết nối" vào các tính năng khác nhau của React.

::alert{type="warning"}

**Lưu ý**: Các Hook, các hàm bắt đầu bằng "use," chỉ có thể được gọi ở cấp độ cao nhất của các thành phần của bạn hoặc trong các Hook tùy chỉnh của riêng bạn. Bạn không thể gọi Hook bên trong điều kiện, vòng lặp hoặc các hàm lồng nhau khác. Các Hook là hàm, nhưng nó hữu ích khi bạn xem nó như là các khai báo về nhu cầu của thành phần của bạn. Bạn "sử dụng" các tính năng React ở cấp đầu của thành phần tương tự như cách bạn "import" các module ở đầu tệp.

::

## Cấu trúc của `useState` trong Reactjs

Khi bạn gọi `useState`, bạn đang báo cho React rằng bạn muốn thành phần này "ghi nhớ" một điều gì đó. Dưới đây là cấu trúc cơ bản của việc sử dụng `useState`:

```jsx
const [stateVariable, setStateVariable] = useState(initialValue);
```

- `stateVariable` là biến state bạn muốn sử dụng.
- `setStateVariable` là hàm setter state, nó sẽ cập nhật biến state và kích hoạt React render lại thành phần.
- `initialValue` là giá trị ban đầu của biến state.

Lưu ý: Quy ước là đặt tên cho cặp này giống như `const [điều_gì_đó, setĐiều_gì_đó]`. Bạn có thể đặt tên bất kỳ, nhưng việc tuân theo quy ước này làm cho mã dễ đọc hơn khi làm việc với React.

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
