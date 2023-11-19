---
title: "Sử dụng useExternalStore trong React"
description: "useSyncExternalStore là một hook tích hợp từ React 18 trở đi, cho phép bạn đăng ký theo dõi một dữ liệu lưu trữ bên ngoài, lắng nghe các thay đổi giá trị từ dữ liệu lưu trữ đó và kích hoạt cập nhật cho các component khi cần thiết"
chapter:
  name: "React nâng cao"
  slug: "chuong-06-react-nang-cao"
image: https://kungfutech.edu.vn/thumbnail.png
position: 8
---

Trong bài viết này, chúng ta sẽ cùng tìm hiểu về hook `useSyncExternalStore`. Đây là một công cụ hữu ích khi bạn muốn tích hợp quản lý trạng thái không phải của React vào ứng dụng của mình.

![Sử dụng useExternalStore trong React](https://github.com/techmely/hoc-lap-trinh/assets/29374426/871401dc-1c8d-40fe-b57d-17731fd7758b)

## hook `useSyncExternalStore` trong React là gì?

`useSyncExternalStore` là một hook tích hợp từ React 18 trở đi, cho phép bạn đăng ký theo dõi một dữ liệu lưu trữ bên ngoài, lắng nghe các thay đổi giá trị từ dữ liệu lưu trữ đó và kích hoạt cập nhật cho các component khi cần thiết.

Tên của hook đã phản ánh rõ:

- Quản lý trạng thái từ bên thứ ba không liên quan đến React
- Giao diện API cho phép theo dõi các thay đổi giá trị và đăng ký các sự kiện

Một số ví dụ về dữ liệu lưu trữ bên ngoài có thể bao gồm:

- Lịch sử trình duyệt (Browser history)
- `localStorage`
- Thư viện bên thứ ba

## Khi nào nên sử dụng `useSyncExternalStore`?

Theo tài liệu chính thức, hook này hữu ích khi bạn cần cập nhật lại các component khi giá trị của một dữ liệu nào đó thay đổi và khi bạn muốn tích hợp với các thư viện không phải của React.

Nếu không sử dụng `useSyncExternalStore`, bạn sẽ phải đăng ký theo dõi các dữ liệu lưu trữ bên ngoài một cách thủ công bằng cách sử dụng `useEffect`. Trong một số trường hợp, điều này có thể dẫn đến việc render lại các thành phần mà chúng ta không mong muốn. Do đó, việc sử dụng `useSyncExternalStore` sẽ tối ưu hơn.

## Cách sử dụng `useSyncExternalStore`

Dưới đây là một ví dụ đơn giản về cách sử dụng:

```javascript
const externalStore = useSyncExternalStore(
  subscribe,
  getSnapshot,
  getServerSnapshot
);
```

- **Subscribe**: Định nghĩa một callback sẽ được gọi khi component re-render. Nó cũng sẽ xử lý việc dọn dẹp subscription.
- **getSnapshot**: Lấy và trả về snapshot của dữ liệu đã đăng ký. Nếu giá trị trả về khác so với phiên bản trước đó, component sẽ được kích hoạt re-render.
- **getServerSnapshot**: Trả về snapshot ban đầu của dữ liệu và cung cấp snapshot trong quá trình server-side render.

## Ví dụ sử dụng `useSyncExternalStore`

Để hiểu cách hoạt động của `useSyncExternalStore`, chúng ta có thể xem một ví dụ cụ thể. Hãy giả định bạn muốn theo dõi các thay đổi trong `localStorage`.

```javascript
import { useSyncExternalStore } from "react";

const subscribe = (listener) => {
  window.addEventListener("storage", listener);

  return () => {
    window.removeEventListener("storage", listener);
  };
};

const getSnapshot = () => {
  return localStorage.getItem("myItem");
};

const value = useSyncExternalStore(subscribe, getSnapshot);
```

Đây là một ví dụ đơn giản nhưng sẽ giúp bạn hiểu cách hoạt động của hook. Hàm `subscribe` lắng nghe thay đổi trong `localStorage` và xử lý hủy đăng ký. Sau đó, `getSnapshot` lấy giá trị của dữ liệu.

Cuối cùng, chúng ta sử dụng `useSyncExternalStore` để đảm bảo rằng thành phần sẽ được kích hoạt re-render khi phát hiện thấy sự thay đổi từ `localStorage`.


::alert{type="success"}
`useSyncExternalStore` là một hook tuyệt vời và hữu ích cho React. Việc hiểu rõ cách triển khai và một số lưu ý của hook này có thể mất thời gian, nhưng bài viết này hy vọng là một điểm khởi đầu tốt cho bạn.
::
