---
title: "Tương tác với giao diện qua State"
description: "Hướng dẫn cách sử dụng React để quản lý trạng thái và tương tác với giao diện người dùng một cách dễ hiểu. Bài viết này giúp bạn hiểu sự khác biệt giữa lập trình UI bằng cách tường minh (declarative) và lập trình UI bằng cách mệnh lệnh (imperative)"
chapter:
  name: "Quản lý state trong React"
  slug: "chuong-05-quan-ly-state-trong-react"
image: https://kungfutech.edu.vn/thumbnail.png
position: 1
---

React cung cấp một cách tường minh để thay đổi giao diện người dùng. Thay vì điều khiển từng phần của giao diện một cách trực tiếp, bạn mô tả các trạng thái (state) khác nhau mà component của bạn có thể có, và chuyển đổi giữa chúng dựa trên dữ liệu người dùng cung cấp. Điều này tương tự cách các nhà thiết kế nghĩ về giao diện người dùng.

## Lập trình UI tường minh so với lập trình UI mệnh lệnh

### Lập trình UI mệnh lệnh

Khi thực hiện lập trình giao diện người dùng (UI) theo cách mệnh lệnh, bạn cần phải viết các hướng dẫn cụ thể để thay đổi giao diện. Ví dụ, khi bạn thay đổi một trạng thái của ứng dụng dựa trên hành động của người dùng, bạn phải viết các hướng dẫn cụ thể để làm điều đó. Điều này giống như bạn đang điều khiển một người lái xe để quyết định nơi họ nên rẽ.

Chẳng hạn, trong ví dụ dưới đây, chúng ta sử dụng lập trình mệnh lệnh để xây dựng một biểu mẫu mà không sử dụng React, chỉ sử dụng DOM của trình duyệt:

```javascript
async function handleFormSubmit(e) {
  e.preventDefault();
  disable(textarea);
  disable(button);
  show(loadingMessage);
  hide(errorMessage);
  try {
    await submitForm(textarea.value);
    show(successMessage);
    hide(form);
  } catch (err) {
    show(errorMessage);
    errorMessage.textContent = err.message;
  } finally {
    hide(loadingMessage);
    enable(textarea);
    enable(button);
  }
}
```

Như bạn có thể thấy, chúng ta phải viết các hướng dẫn cụ thể để vô hiệu hóa hoặc hiển thị các phần tử của giao diện dựa trên tình huống.

### Lập trình UI tường minh

React giúp bạn lập trình UI một cách tường minh hơn. Thay vì điều khiển giao diện người dùng từng phần tử một, bạn mô tả rõ ràng những gì bạn muốn hiển thị và React sẽ tự động cập nhật giao diện dựa trên mô tả của bạn. Điều này giống như bạn lên một chiếc taxi và chỉ cần nói với tài xế nơi bạn muốn đến, chứ không phải chỉ dẫn từng bước rõ ràng.

Chẳng hạn, trong ví dụ sau, chúng ta sử dụng React để xây dựng một biểu mẫu:

```javascript
import { useState } from "react";

export default function Form() {
  const [answer, setAnswer] = useState("");
  const [error, setError] = useState(null);
  const [status, setStatus] = useState("typing");

  if (status === "success") {
    return <h1>Đúng rồi!</h1>;
  }

  async function handleSubmit(e) {
    e.preventDefault();
    setStatus("submitting");
    try {
      await submitForm(answer);
      setStatus("success");
    } catch (err) {
      setStatus("typing");
      setError(err);
    }
  }

  function handleTextareaChange(e) {
    setAnswer(e.target.value);
  }

  return (
    <>
      <h2>Trò chơi về thành phố</h2>
      <p>Thành phố nào có bảng quảng cáo biến không khí thành nước uống?</p>
      <form onSubmit={handleSubmit}>
        <textarea
          value={answer}
          onChange={handleTextareaChange}
          disabled={status === "submitting"}
        />
        <br />
        <button disabled={status === "empty" || status === "submitting"}>
          Gửi
        </button>
        {status === "error" && (
          <p className="Error">
            Chắc chắn là một câu trả lời tốt nhưng không chính xác. Hãy thử lại!
          </p>
        )}
      </form>
    </>
  );
}
```

Trong đoạn mã trên, chúng ta mô tả rõ ràng trạng thái của biểu mẫu và các thành phần của nó. Khi người dùng tương tác, React sẽ tự động cập nhật giao diện mà không cần phải chỉ dẫn từng bước cụ thể.

## Làm việc với React một cách tường minh

### Xác định các state

Trước tiên, bạn cần xác định tất cả các state khác nhau của giao diện mà người dùng có thể thấy. Điều này tương tự như việc thiết kế các trạng thái trực quan của giao diện trước khi thêm logic.

Ví dụ:

- Trạng thái Rỗng: Form có nút "Gửi" bị vô hiệu hóa.
- Trạng thái Gõ: Form có nút "Gửi" đã được kích hoạt.
- Trạng thái Đang Gửi: Form hoàn toàn bị vô hiệu hóa và hiển thị biểu tượng vòng quay.
- Trạng thái Thành Công: Thay vì form, hiển thị thông báo "Cảm ơn bạn!"
- Trạng thái Lỗi: Giống Trạng thái Gõ, nhưng có thông báo lỗi thêm vào.

### Xác định nguồn gốc của thay đổi state

Sau đó, bạn cần xác định các sự kiện nào sẽ chuyển đổi giữa các trạng thái này. Có hai loại sự kiện chính:

- Sự kiện từ người dùng: Như nhấn nút, nhập văn bản, điều hướng.
- Sự kiện từ máy tính: Như kết quả mạng, hoàn thành đợi, tải hình ảnh.

Cần xác định trạng thái nào sẽ được thay đổi bằng cách nào.

### Đại diện cho trạng thái trong bộ nhớ bằng `useState`

Sử dụng useState để biểu diễn các trạng thái trực quan của thành phần. Bạn cần phải biểu diễn trạng thái một cách đơn giản và hiệu quả. Bắt đầu bằng việc xác định trạng thái bắt buộc.

- Ví dụ, bạn cần lưu trạng thái của input và lỗi (nếu có):

```javascript
const [answer, setAnswer] = useState("");
const [error, setError] = useState(null);
```

- Tiếp theo, bạn cần một biến state để biểu diễn trạng thái trực quan. Chúng ta có thể sử dụng một chuỗi với các giá trị 'typing', 'submitting' hoặc 'success':

```javascript
const [status, setStatus] = useState("typing");
```

- Loại bỏ các state không cần thiết:

Chúng ta nên loại bỏ các state không cần thiết để tránh sự trùng lặp và làm cho mã nguồn trở nên dễ đọc hơn. Sau quá trình này, bạn chỉ cần ba state:

```javascript
const [answer, setAnswer] = useState("");
const [error, setError] = useState(null);
const [status, setStatus] = useState("typing");
```

### Kết nối các bộ xử lý sự kiện để cập nhật trạng thái

Cuối cùng, bạn cần tạo các bộ xử lý sự kiện để cập nhật trạng thái khi có sự tương tác. Dưới đây là phiên bản cuối cùng của biểu mẫu, trong đó đã kết nối các bộ xử lý sự kiện:

```javascript
import { useState } from "react";

export default function Form() {
  const [answer, setAnswer] = useState("");
  const [error, setError] = useState(null);
  const [status, setStatus] = useState("typing");

  if (status === "success") {
    return <h1>Đúng rồi!</h1>;
  }

  async function handleSubmit(e) {
    e.preventDefault();
    setStatus("submitting");
    try {
      await submitForm(answer);
      setStatus("success");
    } catch (err) {
      setStatus("typing");
      setError(err);
    }
  }

  function handleTextareaChange(e) {
    setAnswer(e.target.value);
  }

  return (
    <>
      <h2>Trò chơi về thành phố</h2>
      <p>Thành phố nào có bảng quảng cáo biến không khí thành nước uống?</p>
      <form onSubmit={handleSubmit}>
        <textarea
          value={answer}
          onChange={handleTextareaChange}
          disabled={status === "submitting"}
        />
        <br />
        <button disabled={status === "empty" || status === "submitting"}>
          Gửi
        </button>
        {status === "error" && (
          <p className="Error">
            Chắc chắn là một câu trả lời tốt nhưng không chính xác. Hãy thử lại!
          </p>
        )}
      </form>
    </>
  );
}
```

Mặc dù mã nguồn này dài hơn ví dụ mệnh lệnh ban đầu, nhưng nó ít dễ bị lỗi hơn và cho phép bạn thêm các trạng thái mới mà không làm hỏng các trạng thái hiện có.

::alert{type="success"}

React cung cấp một cách tường minh và dễ quản lý hơn để làm việc với giao diện người dùng bằng cách mô tả trạng thái và xác định các sự kiện gây ra sự thay đổi trạng thái. Điều này giúp tránh sự phức tạp và giảm rủi ro lỗi trong quá trình phát triển ứng dụng React.

::
