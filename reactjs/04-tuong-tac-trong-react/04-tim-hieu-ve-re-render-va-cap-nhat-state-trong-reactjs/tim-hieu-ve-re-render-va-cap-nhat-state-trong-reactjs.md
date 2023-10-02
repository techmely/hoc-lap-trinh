---
title: "Tìm hiểu về re-render và cập nhật state trong Reactjs"
description: "Biến state có vẻ giống như các biến JavaScript thông thường mà bạn có thể đọc và ghi dữ liệu vào. Tuy nhiên, state hoạt động giống như một bản chụp. Việc thiết lập nó không làm thay đổi biến state bạn đã có, mà thay vào đó kích hoạt một quá trình gọi là re-render"
chapter:
  name: "Tương tác trong Reactjs"
  slug: "chuong-04-tuong-tac-trong-reactjs"
image: https://kungfutech.edu.vn/thumbnail.png
position: 4
---

Biến state có vẻ giống như các biến JavaScript thông thường mà bạn có thể đọc và ghi dữ liệu vào. Tuy nhiên, state hoạt động giống như một bản chụp. Việc thiết lập nó không làm thay đổi biến state bạn đã có, mà thay vào đó kích hoạt một quá trình gọi là re-render.

## Khi thiết lập `state`, gây ra re-render

Bạn có thể nghĩ rằng giao diện người dùng của bạn thay đổi trực tiếp dựa trên sự kiện của người dùng như một lần nhấp chuột. Trong React, nó hoạt động khác so với mô hình tư duy này. Trên trang trước, bạn đã thấy rằng việc thiết lập state yêu cầu một yêu cầu re-render từ React. Điều này có nghĩa là để giao diện phản ánh sự kiện, bạn cần phải cập nhật state.

**Ví dụ:**

```jsx
import { useState } from "react";

export default function Form() {
  const [isSent, setIsSent] = useState(false);
  const [message, setMessage] = useState("Hi!");
  if (isSent) {
    return <h1>Your message is on its way!</h1>;
  }
  return (
    <form
      onSubmit={(e) => {
        e.preventDefault();
        setIsSent(true);
        sendMessage(message);
      }}
    >
      <textarea
        placeholder="Message"
        value={message}
        onChange={(e) => setMessage(e.target.value)}
      />
      <button type="submit">Send</button>
    </form>
  );
}

function sendMessage(message) {
  // ...
}
```

Khi bạn nhấn "Gửi", `setIsSent(true)` cho biết cho React cần phải re-render giao diện người dùng.

## Re-render lấy một bản chụp tại thời điểm

"Re-render" có nghĩa là React gọi chức năng của bạn, đó là một hàm. JSX bạn trả về từ hàm đó giống như một bản chụp của giao diện người dùng tại một thời điểm. Các props, các trình xử lý sự kiện và biến cục bộ của nó đều được tính toán bằng cách sử dụng trạng thái của nó tại thời điểm render.

Không giống như một bức ảnh hoặc một khung hình phim, "bản chụp" của giao diện người dùng bạn trả về có thể tương tác. Nó bao gồm logic như trình xử lý sự kiện định rõ điều gì xảy ra khi có dữ liệu đầu vào. React cập nhật màn hình để phù hợp với "bản chụp" này và kết nối các trình xử lý sự kiện. Kết quả là việc nhấn một nút sẽ kích hoạt trình xử lý nhấp chuột từ JSX của bạn.

Khi React thực hiện lại việc render một thành phần:

1. React gọi lại hàm của bạn.
2. Hàm của bạn trả về một bản chụp JSX mới.
3. Sau đó, React cập nhật màn hình để phù hợp với bản chụp mà hàm của bạn trả về.

Như là một bộ nhớ của thành phần, state không giống như một biến thông thường biến mất sau khi hàm của bạn kết thúc. State thực sự "sống" trong React, như là nằm trên một kệ! Bên ngoài hàm của bạn. Khi React gọi thành phần của bạn, nó cung cấp cho bạn một bản chụp của state cho lần render đó. Thành phần của bạn trả về một bản chụp của giao diện người dùng với một bộ props và trình xử lý sự kiện mới trong JSX của nó, tất cả được tính toán bằng các giá trị state từ lần render đó!

**Bạn chỉ cần cho React biết cập nhật state**
Ở bước này, bạn cho biết React cần cập nhật state:

1. Bạn gọi hàm cập nhật state (ví dụ: `setNumber(number + 1)`).
2. React cập nhật giá trị state.
3. React chuyển một bản chụp của giá trị state vào thành phần của bạn.

**Ví dụ thực hiện:**

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

Lưu ý rằng số `number` chỉ tăng lên một lần sau mỗi lần nhấp!

Thiết lập state chỉ thay đổi nó cho lần render tiếp theo. Trong lần render đầu tiên, số `number` là 0. Đây là lý do tại lần render này, giá trị của `number` vẫn là 0 ngay cả sau khi đã gọi `setNumber(number + 1)`:

```jsx
<button
  onClick={() => {
    setNumber(number + 1);
    setNumber(number + 1);
    setNumber(number + 1);
  }}
>
  +3
</button>
```

Dưới đây là những gì trình xử lý sự kiện của nút này khiến React thực hiện:

- `setNumber(number + 1)`: `number` là 0, vì vậy `setNumber(0 + 1)`.
- React chuẩn bị thay đổi `number` thành 1 trong lần render tiếp theo.
- `setNumber(number + 1)`: `number` là 0, vì vậy `setNumber(0 + 1)`.
- React chuẩn bị thay đổi `number` thành 1 trong lần render tiếp theo.
- `setNumber(number + 1)`: `number` là 0, vì vậy `setNumber(0 + 1)`.
- React chuẩn bị thay đổi `number` thành 1 trong lần render tiếp theo.

Dù bạn đã gọi `setNumber(number + 1)` ba lần, trong trình xử lý sự kiện này, `number` luôn luôn là 0, vì vậy bạn đã thiết lập state thành 1 ba lần trong cùng một lần render. Đó là lý do sau khi trình xử lý sự kiện của bạn kết thúc, React sẽ thực hiện re-render thành phần với `number` bằng 1 thay vì 3.

Bạn có thể tưởng tượng điều này bằng cách thay thế biến state bằng giá trị của nó trong mã của bạn. Vì `number` state là 0 cho lần render này, trình xử lý sự kiện của nó trông như sau:

```jsx
<button
  onClick={() => {
    setNumber(0 + 1);
    setNumber(0 + 1);
    setNumber(0 + 1);
  }}
>
  +3
</button>
```

Đối với lần render tiếp theo, `number` là 1, vì vậy trình xử lý sự kiện của lần render này trông như sau:

```jsx
<button
  onClick={() => {
    setNumber(1 + 1);
    setNumber(1 + 1);
    setNumber(1 + 1);
  }}
>
  +3
</button>
```

## Biến state qua thời gian

Hãy thử đoán xem khi bạn nhấp vào nút này, thông báo sẽ hiển thị gì:

```jsx
import { useState } from "react";

export default function Counter() {
  const [number, setNumber] = useState(0);

  return (
    <>
      <h1>{number}</h1>
      <button
        onClick={() => {
          setNumber(number + 5);
          alert(number);
        }}
      >
        +5
      </button>
    </>
  );
}
```

Nếu bạn sử dụng phương pháp thay thế từ trước, bạn có thể đoán rằng thông báo sẽ hiển thị "0":

```jsx
setNumber(0 + 5);
alert(0);
```

Nhưng nếu bạn đặt một hẹn giờ trên thông báo, để nó chỉ kích hoạt sau khi thành phần đã render lại, liệu nó sẽ hiển thị "0" hay "5"? Hãy đoán!

```jsx
import { useState } from "react";

export default function Counter() {
  const [number, setNumber] = useState(0);

  return (
    <>
      <h1>{number}</h1>
      <button
        onClick={() => {
          setNumber(number + 5);
          setTimeout(() => {
            alert(number);
          }, 3000);
        }}
      >
        +5
      </button>
    </>
  );
}
```

Bất ngờ chưa? Nếu bạn sử dụng phương pháp thay thế, bạn có thể thấy "bản chụp" của state được truyền vào thông báo.

```jsx
setNumber(0 + 5);
setTimeout(() => {
  alert(0);
}, 3000);
```

Giá trị state được lưu trữ trong React có thể đã thay đổi sau khi thông báo chạy, nhưng nó đã được lên lịch sử dụng "bản chụp" của state tại thời điểm người dùng tương tác với nó!

Giá trị của biến state không thay đổi trong một lần render, ngay cả khi mã xử lý sự kiện của nó là không đồng bộ. Trong trường hợp này, giá trị của `number` vẫn là 0 ngay sau khi gọi `setNumber(number + 5)`. Giá trị này đã được "cố định" khi React "lấy bản chụp" của giao diện người dùng bằng cách gọi thành phần của bạn.

**Kết luận**

1. Thiết lập state yêu cầu một lần render mới.
2. React lưu trữ state bên ngoài thành phần của bạn, giống như nó nằm trên một kệ.
3. Khi bạn gọi `useState`, React cung cấp cho bạn một bản chụp của state cho lần render đó.
4. Các biến và trình xử lý sự kiện không "tồn tại" qua các lần render khác nhau. Mỗi lần render có các trình xử lý sự kiện riêng.
5. Mỗi lần render (và các hàm trong đó) luôn "nhìn thấy" bản chụp của state mà React đã cung cấp cho lần render đó.
6. Bạn có thể tưởng tượng thay thế state trong các trình xử lý sự kiện, tương tựnhư cách bạn nghĩ về JSX đã render. 7. Các trình xử lý sự kiện được tạo trong quá khứ sẽ có các giá trị state từ lần render mà chúng đã được tạo ra.

::alert{type="success"}

Như vậy, bạn đã hiểu cách state và re-render hoạt động trong Reactjs. Chúc bạn thành công trong việc phát triển ứng dụng React của mình!

::
