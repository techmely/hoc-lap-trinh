---
title: "Cập nhật state hàng loạt trong Reactjs"
description: "Đôi khi bạn có thể muốn thực hiện nhiều hoạt động trên giá trị state trước khi kích hoạt lần render tiếp theo. Để thực hiện điều này, bạn cần hiểu cách React thực hiện "batching" (gom nhóm) các cập nhật state"
chapter:
  name: "Tương tác trong Reactjs"
  slug: "chuong-04-tuong-tac-trong-reactjs"
image: https://kungfutech.edu.vn/thumbnail.png
position: 5
---

Khi làm việc với ReactJS, bạn thường sử dụng state để theo dõi và quản lý trạng thái của ứng dụng của bạn. Một điểm cơ bản cần biết là việc thiết lập một biến state sẽ kích hoạt một lần render mới. Tuy nhiên, đôi khi bạn có thể muốn thực hiện nhiều hoạt động trên giá trị state trước khi kích hoạt lần render tiếp theo. Để thực hiện điều này, bạn cần hiểu cách React thực hiện "batching" (gom nhóm) các cập nhật state.

## Batching là gì và cách React sử dụng nó để xử lý nhiều cập nhật state

Có thể bạn đã nghĩ rằng khi nhấp vào nút "+3", biến đếm sẽ tăng ba lần vì nó gọi setNumber(number + 1) ba lần:

```jsx
import { useState } from "react";

export default function Counter() {
  const [number, setNumber] = useState(0);

  return (
    <>
      <h1>{number}</h1>
      <button
        onClick={() => {
          setNumber(number + 1);
          setNumber(number + 1);
          setNumber(number + 1);
        }}
      >
        +3
      </button>
    </>
  );
}
```

Tuy nhiên, như bạn có thể nhớ từ phần trước, giá trị state của mỗi lần render đều là cố định, vì vậy giá trị của `number` trong trình xử lý sự kiện của lần render đầu tiên luôn luôn là 0, bất kể bạn gọi `setNumber(1)` bao nhiêu lần:

```jsx
setNumber(0 + 1);
setNumber(0 + 1);
setNumber(0 + 1);
```

Tuy nhiên, còn một yếu tố khác đang ảnh hưởng ở đây. React đợi cho đến khi tất cả mã trong trình xử lý sự kiện đã được thực hiện xong trước khi xử lý các cập nhật state của bạn. Điều này giống như một người phục vụ chờ bạn hoàn thành việc đặt hàng tại nhà hàng. Người phục vụ không chạy vào bếp ngay khi bạn đặt món đầu tiên! Thay vào đó, họ để bạn hoàn thành đơn hàng, để bạn thay đổi đơn hàng nếu cần, thậm chí nhận đơn hàng từ những người khác ngồi cùng bàn.

React xử lý các cập nhật `state` theo cách tương tự. Sau khi bạn gọi `setState()` nhiều lần, React sẽ xem xét tất cả các cập nhật này trước khi thực hiện bất kỳ cập nhật state nào. Điều này cho phép bạn cập nhật nhiều biến state, thậm chí từ nhiều thành phần khác nhau, mà không gây ra quá nhiều lần render. Nhưng điều này cũng đồng nghĩa với việc giao diện người dùng sẽ không được cập nhật cho đến sau khi trình xử lý sự kiện của bạn và bất kỳ mã nào trong đó hoàn thành. Hành vi này, còn được gọi là "batching" (gom nhóm), giúp ứng dụng React của bạn hoạt động nhanh hơn và tránh các trường hợp `render` "chưa hoàn thành" khó hiểu, trong đó chỉ một số biến đã được cập nhật.

**React không gom nhóm các sự kiện click riêng biệt**, điều này đảm bảo rằng React chỉ gom nhóm khi nó làm cho ứng dụng an toàn. Ví dụ, nếu lần nhấp đầu tiên vô hiệu hóa một biểu mẫu, lần nhấp thứ hai sẽ không gửi biểu mẫu đó đi nữa.

## Cách áp dụng nhiều cập nhật cho cùng một biến state liên tiếp

Mặc dù không phải là trường hợp sử dụng phổ biến, nhưng nếu bạn muốn cập nhật cùng một biến state nhiều lần trước lần render tiếp theo, thay vì truyền giá trị state mới vào như `setNumber(number + 1)`, bạn có thể truyền một hàm tính toán giá trị state mới dựa trên giá trị trước đó trong hàng đợi, như sau: `setNumber(n => n + 1)`. Điều này là cách để cho React biết "làm điều gì đó với giá trị state" thay vì chỉ đơn giản thay thế nó.

Hãy thử tăng giá trị đếm bằng cách sử dụng cách này:

```jsx
import { useState } from "react";

export default function Counter() {
  const [number, setNumber] = useState(0);

  return (
    <>
      <h1>{number}</h1>
      <button
        onClick={() => {
          setNumber((n) => n + 1);
          setNumber((n) => n + 1);
          setNumber((n) => n + 1);
        }}
      >
        +3
      </button>
    </>
  );
}
```

Ở đây, `n => n + 1` được gọi là một hàm cập nhật. Khi bạn truyền nó vào trình đặt state:

- React đưa hàm này vào hàng đợi để xử lý sau khi tất cả mã trong trình xử lý sự kiện đã chạy xong.
- Trong lần render tiếp theo, React duyệt qua hàng đợi và truyền giá trị state cuối cùng đã được cập nhật.
  - `setNumber(n => n + 1);`
  - `setNumber(n => n + 1);`
  - `setNumber(n => n + 1);`

Dưới đây là cách React thực hiện các dòng mã này trong khi thực hiện trình xử lý sự kiện:

- `setNumber(n => n + 1)`: `n => n + 1` là một hàm. React đưa nó vào hàng đợi.
- `setNumber(n => n + 1)`: `n => n + 1` là một hàm. React đưa nó vào hàng đợi.
- `setNumber(n => n + 1)`: `n => n + 1` là một hàm. React đưa nó vào hàng đợi.

Khi bạn gọi `useState` trong lần render tiếp theo, React duyệt qua hàng đợi. Giá trị state trước đó là 0, vì vậy đó là giá trị mà React truyền vào hàm cập nhật đầu tiên như là đối số `n`. Sau đó, React lấy giá trị trả về của hàm cập nhật trước đó và truyền nó vào hàm cập nhật tiếp theo như `n`, và cứ tiếp tục như vậy:

- Cập nhật đã được xếp hàng: `"replace with 5"` với `n` là 0 (không sử dụng), trả về 5.
- `n => n + 1`: với `n` là 5, trả về 5 + 1 = 6.
- `n => n + 1`: với `n` là 6, trả về 6 + 1 = 7.
- React lưu giá trị 7 là kết quả cuối cùng và trả nó từ `useState`.

Điều này làm cho việc nhấp vào "+3" trong ví dụ trên sẽ tăng giá trị thêm 3.

## Cập Nhật State Sau Khi Thay Thế Nó

Xem xét trường hợp sau, trong trường hợp này, bạn nghĩ `number` sẽ là gì trong lần render tiếp theo?

```jsx
<button onClick={() => {
  setNumber(number + 5);
  setNumber(n => n + 1);
}}>
```

Ở đây, trình xử lý sự kiện này yêu cầu React thực hiện các việc sau:

- `setNumber(number + 5)`: `number` là 0, vì vậy `setNumber(0 + 5)`. React đưa "thay thế bằng 5" vào hàng đợi.
- `setNumber(n => n + 1)`: React đưa hàm `n => n + 1` vào hàng đợi.

Trong lần render tiếp theo, React duyệt qua hàng đợi:

- Cập nhật trong hàng đợi: `"thay thế bằng 5"` với `n` là 0 (không sử dụng), trả về 5.
- `n => n + 1`: với `n` là 5, trả về 5 + 1 = 6.

Sau đó, React lưu giá trị 6 là kết quả cuối cùng và trả nó từ `useState`.

Để tóm tắt, đây là cách bạn có thể nghĩ về những gì bạn đang truyền cho hàm đặt state `setNumber`:

- Một hàm cập nhật (ví dụ: `n => n + 1`) được thêm vào hàng đợi.
- Bất kỳ giá trị nào khác (ví dụ: 5) đều thêm "thay thế bằng X" vào hàng đợi, bất kể cái gì đã được xếp hàng.

Sau khi trình xử lý sự kiện hoàn thành, React sẽ kích hoạt lần render mới. Trong lần render này, React sẽ xử lý hàng đợi. Hàm cập nhật được thực hiện trong quá trình render, vì vậy chúng phải là hàm thuần túy và chỉ trả về kết quả. Đừng thử cố gắng đặt state từ bên trong chúng hoặc chạy các tác động phụ khác. Trong Chế Độ Nghiêm Ngặt (Strict Mode), React sẽ chạy mỗi hàm cập nhật hai lần (nhưng bỏ kết quả thứ hai) để giúp bạn tìm ra lỗi.

### Quy tắc đặt tên

Thường thì bạn nên đặt tên đối số của hàm cập nhật bằng các chữ cái đầu tiên của biến state tương ứng:

- `setEnabled(e => !e);`
- `setLastName(ln => ln.reverse());`
- `setFriendCount(fc => fc * 2);`

Nếu bạn muốn viết mã dễ đọc hơn, một quy tắc thường thấy là lặp lại tên biến state đầy đủ, chẳng hạn như `setEnabled(enabled => !enabled)`, hoặc sử dụng một tiền tố như `setEnabled(prevEnabled => !prevEnabled)`.

::alert{type="success"}

Tóm tắt:

- Đặt state không thay đổi biến trong lần render hiện tại, mà yêu cầu một lần render mới.
- React xử lý các cập nhật state sau khi trình xử lý sự kiện đã hoàn thành. Điều này gọi là "batching" (gom nhóm).
- Để cập nhật một số state nhiều lần trong một sự kiện, bạn có thể sử dụng hàm cập nhật như `setNumber(n => n + 1)`.

::
