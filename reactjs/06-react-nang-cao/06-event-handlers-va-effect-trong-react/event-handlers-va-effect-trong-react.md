---
title: "Event Handlers và Effect trong React"
description: "Trong React, việc quản lý sự kiện và effects là một phần quan trọng để tạo ra các component (components) đáp ứng và tương tác tốt. Một sự khác biệt quan trọng giữa sự kiện (event handlers) và effects (effects) là cách chúng re-run trong các tình huống khác nhau"
chapter:
  name: "React nâng cao"
  slug: "chuong-06-react-nang-cao"
image: https://kungfutech.edu.vn/thumbnail.png
position: 6
---

Trong React, việc quản lý sự kiện và effects là một phần quan trọng để tạo ra các component đáp ứng và tương tác tốt. Một sự khác biệt quan trọng giữa sự kiện (event handlers) và effects là cách chúng re-run trong các tình huống khác nhau.

Trong bài viết này, chúng ta sẽ thảo luận về cách tách biệt sự kiện và effects trong React, lý do tại sao effects có tính phản ứng (reactive), trong khi sự kiện không có, và cách sử dụng Effect Events để kết hợp cả hai hành vi này.

## Hiểu về event handlers và effects

Trước khi đi sâu vào cách tách biệt chúng, hãy xem xét sự khác biệt cơ bản giữa sự kiện (event handlers) và effects (effects) trong React.

### Sự kiện (Event Handlers)

Sự kiện là các hàm hoặc xử lý chạy dựa trên các tương tác cụ thể từ người dùng. Chúng chỉ chạy khi có sự tương tác xảy ra, ví dụ: khi người dùng nhấp chuột, nhập dữ liệu vào một ô input, hoặc thao tác với các phần tử giao diện người dùng. Sự kiện luôn phản ứng dựa trên các tương tác cụ thể từ người dùng.

### Hiệu ứng (Effects)

Hiệu ứng, hay Effects, là các khối mã chạy để đảm bảo đồng bộ hóa với các giá trị như prop hoặc biến trạng thái (state) đã thay đổi. Hiệu ứng chạy không phụ thuộc vào sự tương tác của người dùng, mà dựa vào sự thay đổi của các giá trị đã đọc từ props hoặc state.

## Chọn giữa sự kiện và hiệu ứng

Để chọn giữa sự kiện và effects, bạn cần xác định tại sao mã cần chạy. Hãy xem xét ví dụ về một component phòng chat:

1. Thành phần của bạn cần tự động kết nối vào phòng chat được chọn.
2. Khi người dùng nhấp vào nút "Gửi", nó sẽ gửi một tin nhắn vào cuộc trò chuyện.

Nơi nào bạn nên đặt mã cho các yêu cầu này, bằng sự kiện hay effects? Luôn cân nhắc tại sao mã cần chạy.

### Sự kiện chạy dựa trên tương tác cụ thể

Sự kiện chạy khi có các tương tác cụ thể từ người dùng. Ví dụ, khi người dùng nhấp chuột vào nút "Gửi", hành động này sẽ chạy một sự kiện. Sự kiện giúp bạn xử lý các tương tác cụ thể như vậy. Dưới đây là một ví dụ:

```jsx
function ChatRoom({ roomId }) {
  const [message, setMessage] = useState("");

  function handleSendClick() {
    sendMessage(message);
  }

  return (
    <>
      <input value={message} onChange={(e) => setMessage(e.target.value)} />
      <button onClick={handleSendClick}>Gửi</button>
    </>
  );
}
```

Với sự kiện, bạn có thể đảm bảo rằng `sendMessage(message)` chỉ chạy khi người dùng nhấp vào nút "Gửi".

### Hiệu ứng chạy khi cần đồng bộ hóa

Hiệu ứng, ngược lại, chạy khi cần đảm bảo đồng bộ hóa với các giá trị như prop hoặc state đã thay đổi. Ví dụ, khi bạn cần duy trì kết nối tới phòng chat đã chọn, bạn sử dụng effects:

```jsx
function ChatRoom({ roomId }) {
  useEffect(() => {
    const connection = createConnection(serverUrl, roomId);
    connection.connect();
    return () => connection.disconnect();
  }, [roomId]);
}
```

Trong ví dụ này, effects đảm bảo rằng luôn có kết nối đến máy chủ phòng chat đã chọn, dựa vào giá trị của `roomId`.

## Cách Sự Kiện và Hiệu ứng Phản ứng Với Dữ Liệu

### Giá trị Phản ứng và Logic Phản ứng

Để hiểu cách sự kiện và effects phản ứng với dữ liệu, chúng ta nên nắm vững một số khái niệm:

- Props, state và biến được khai báo trong phần thân của component của bạn được gọi là các giá trị phản ứng. Ví dụ: `roomId` và `message` là giá trị phản ứng trong ví dụ của chúng ta.

- Logic nằm trong sự kiện (event handler) không phản ứng. Nó sẽ không chạy lại trừ khi người dùng thực hiện cùng một tương tác (ví dụ: một lần nhấp chuột) một lần nữa. Sự kiện có thể đọc các giá trị phản ứng mà không phản ứng với sự

thay đổi của chúng.

- Logic nằm trong effects (effect) là phản ứng. Nếu effects đọc một giá trị phản ứng, bạn phải xác định giá trị đó là một phụ thuộc. Khi giá trị phụ thuộc thay đổi sau khi render, React sẽ chạy lại logic của effects với giá trị mới.

### Logic không phản ứng trong sự kiện

Hãy xem xét ví dụ sau để minh họa sự khác biệt:

```jsx
function ChatRoom({ roomId }) {
  const [message, setMessage] = useState("");

  // ...
  function handleSendClick() {
    sendMessage(message);
  }
  // ...
}
```

Từ góc độ của người dùng, thay đổi `message` không đồng nghĩa với việc muốn gửi một tin nhắn. Điều này chỉ đơn giản là người dùng đang nhập dữ liệu. Vì vậy, logic để gửi tin nhắn không nên phản ứng. Nó chỉ cần chạy khi người dùng nhấp vào nút "Gửi". Sự kiện không phản ứng, vì vậy `sendMessage(message)` sẽ chỉ chạy khi người dùng nhấp vào nút "Gửi".

### Logic phản ứng trong effects

Bây giờ hãy quay lại đoạn mã sau:

```jsx
function ChatRoom({ roomId }) {
  useEffect(() => {
    const connection = createConnection(serverUrl, roomId);
    connection.connect();
    return () => {
      connection.disconnect();
    };
  }, [roomId]);
}
```

Từ góc độ của người dùng, thay đổi `roomId` đồng nghĩa với việc muốn kết nối vào một phòng khác. Vì vậy, logic kết nối vào phòng cần phản ứng với thay đổi của `roomId`. Với mã này, bạn có thể đảm bảo luôn có một kết nối hoạt động đến máy chủ phòng chat được chọn.

## Sử dụng Effect Events

Tình huống trở nên phức tạp hơn khi bạn muốn kết hợp logic phản ứng với logic không phản ứng. Ví dụ, bạn muốn hiển thị thông báo khi người dùng kết nối vào cuộc trò chuyện và đọc chủ đề hiện tại từ props để có thể hiển thị thông báo trong màu sắc đúng:

```jsx
function ChatRoom({ roomId, theme }) {
  useEffect(() => {
    const connection = createConnection(serverUrl, roomId);
    connection.on("connected", () => {
      showNotification("Kết nối thành công!", theme);
    });
    connection.connect();
    // ...
  }, [roomId, theme]); // ✅ Đã khai báo tất cả các phụ thuộc
  // ...
}
```

Tuy nhiên, `theme` là một giá trị phản ứng (vì nó có thể thay đổi khi `theme` props thay đổi), và tất cả giá trị phản ứng được đọc bởi effects phải được khai báo là phụ thuộc. Điều này đồng nghĩa rằng effects của bạn sẽ chạy lại mỗi khi `theme` thay đổi. Điều này không phải lúc nào cũng mong muốn.

### Tách Biệt Logic Không Phản ứng

Để giải quyết vấn đề này, bạn có thể sử dụng Effect Events. Effect Events là một Hook đặc biệt, cho phép bạn tách biệt logic không phản ứng ra khỏi effects:

```jsx
import { useEffect, useEffectEvent } from "react";

function ChatRoom({ roomId, theme }) {
  const onConnected = useEffectEvent(() => {
    showNotification("Kết nối thành công!", theme);
  });

  useEffect(() => {
    const connection = createConnection(serverUrl, roomId);
    connection.on("connected", () => {
      onConnected();
    });
    connection.connect();
    return () => {
      connection.disconnect();
    };
  }, [roomId]); // ✅ Đã khai báo tất cả các phụ thuộc
  // ...
}
```

Trong ví dụ này, `onConnected` là một Effect Event. Nó là một phần của logic của effects nhưng hoạt động giống như một sự kiện, không phản ứng với thay đổi của giá trị `theme`. Bây giờ bạn có thể gọi `onConnected()` từ trong effects mà không cần đặt `theme` làm phụ thuộc của effects. Effect Events không phản ứng, vì vậy bạn không cần khai báo chúng là phụ thuộc.

## Đọc Các Giá Trị Mới Nhất từ Props và State Bằng Effect Events

Effect Events cung cấp một cách tiện lợi để đọc các giá trị mới nhất từ props và state trong các effects.

Giả sử bạn có một effects để ghi lại các lượt truy cập trang:

```jsx
function Page({ url }) {
  useEffect(() => {
    logVisit(url);
  }, [url]);
  // ...
}
```

Sau đó, bạn thêm nhiều đường dẫn vào trang của bạn, và component `Page` nhận được một prop `url` mới cho mỗi lần thay đổi trang. Bạn muốn truyền giá trị `url` này vào `logVisit`, nhưng linter đòi hỏi bạn phải đặt `url` làm phụ thuộc:

```jsx
function Page({ url }) {
  const { items } = useContext(ShoppingCartContext);
  const numberOfItems = items.length;

  useEffect(() => {
    logVisit(url, numberOfItems);
  }, [url]); // 🔴 React Hook useEffect có một phụ thuộc bị thiếu: 'url'
  // ...
}
```

Tuy nhiên, bạn không muốn cuộc gọi `logVisit` phản ứng với `numberOfItems`. Nếu người dùng thêm sản phẩm vào giỏ hàng và `numberOfItems` thay đổi, điều này không có nghĩa là họ đã truy cập lại trang. Vì vậy, bạn muốn loại bỏ `numberOfItems` khỏi danh sách các phụ thuộc.

```jsx
function Page({ url }) {
  const { items } = useContext(ShoppingCartContext);
  const numberOfItems = items.length;

  const onVisit = useEffectEvent((visitedUrl) => {
    logVisit(visitedUrl, numberOfItems);
  });

  useEffect(() => {
    onVisit(url);
  }, [url]); // ✅ Đã khai báo tất cả các phụ thuộc
  // ...
}
```

Trong ví dụ này, `onVisit` là một Effect Event. Mã bên trong nó không phản ứng. Bây giờ bạn có thể sử dụng `numberOfItems` (hoặc bất kỳ giá trị phản ứng nào khác) mà không cần quan tâm rằng nó sẽ làm cho mã xung quanh nó chạy lại khi thay đổi.

Tóm lại, Effect Events giúp bạn tách biệt logic không phản ứng từ các effects, và cung cấp một cách thuận tiện để đọc giá trị mới nhất từ props và state trong các effects.

## Giới hạn của Effect Events

Effect Events có một số hạn chế:

- Chỉ gọi chúng từ bên trong các effects.
- Không bao giờ truyền chúng cho các component hoặc Hook khác.

Ví dụ, không nên khai báo và truyền một Effect Event như sau:

```jsx
function Timer() {
  const [count, setCount] = useState(0);

  const onTick = useEffectEvent(() => {
    setCount(count + 1);
  });

  useTimer(onTick, 1000); // 🔴 Tránh: Truyền Effect Events

  return <h1>{count}</h1>;
}

function useTimer(callback, delay) {
  useEffect(() => {
    const id = setInterval(() => {
      callback();
    }, delay);
    return () => {
      clearInterval(id);
    };
  }, [delay, callback]); // Cần phải xác định "callback" trong danh sách phụ thuộc
}
```

Thay vào đó, hãy luôn khai báo Effect Events trực tiếp kế bên các effects sử dụng chúng:

```jsx
function Timer() {
  const [count, setCount] = useState(0);
  useTimer(() => {
    setCount(count + 1);
  }, 1000);
  return <h1>{count}</h1>;
}

function useTimer(callback, delay) {
  const onTick = useEffectEvent(() => {
    callback();
  });

  useEffect(() => {
    const id = setInterval(() => {
      onTick(); // ✅ Tốt: Chỉ gọi nó cục bộ trong một effects
    }, delay);
    return () => {
      clearInterval(id);
    };
  }, [delay]); // Không cần phải xác định "onTick" (một Effect Event) là phụ thuộc
}
```

Effect Events là những phần không phản ứng của mã effects của bạn. Chúng nên được đặt ngay bên cạnh các effects sử dụng chúng.

::alert{type="success"}

- Xử lý sự kiện chạy dựa trên cách người dùng tương tác cụ thể.
- Hiệu ứng chạy mỗi khi cần đồng bộ hóa.
- Mã trong xử lý sự kiện không phản ứng và chỉ chạy lại nếu người dùng thực hiện cùng một tương tác.
- Mã trong effects là phản ứng và chạy lại nếu các giá trị phản ứng mà nó đọc thay đổi.
- Effect Events cho phép bạn di chuyển logic không phản ứng ra khỏi effects.
- Effect Events chỉ nên được gọi từ bên trong các effects và không được chuyển cho các component hoặc Hook khác.

::
