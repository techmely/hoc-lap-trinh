---
title: "Custom Hooks trong ReactJS"
description: "React đi kèm với một số Hooks tích hợp sẵn như useState, useContext và useEffect. Tuy nhiên, đôi khi bạn có thể muốn một Hook cho một mục đích cụ thể hơn: ví dụ, để tải dữ liệu, để theo dõi trạng thái trực tuyến của người dùng hoặc để kết nối với phòng trò chuyện. Bạn có thể không tìm thấy những Hook này trong React, nhưng bạn có thể tạo ra các Custom Hooks riêng cho nhu cầu ứng dụng của bạn"
chapter:
  name: "React nâng cao"
  slug: "chuong-06-react-nang-cao"
image: https://kungfutech.edu.vn/thumbnail.png
position: 8
---

React đi kèm với một số Hooks tích hợp sẵn mà chúng ta đã tìm hiểu ở chương này. Tuy nhiên, đôi khi bạn muốn tự tạo một Hook cho một mục đích cụ thể hơn: ví dụ, để tải dữ liệu, để theo dõi trạng thái trực tuyến của người dùng hoặc để kết nối với phòng trò chuyện. Bạn có thể không tìm thấy những Hook này trong React, nhưng bạn có thể tạo ra các Custom Hooks riêng cho nhu cầu ứng dụng của bạn.

![Custom Hooks trong ReactJS](https://github.com/techmely/hoc-lap-trinh/assets/29374426/05cada96-472e-4f27-a675-d36ca499b59b)

## Tại sao cần Custom hook?

Ví dụ bạn muốn kiểm tra tình trạng kết nối mạng của người dùng và cảnh báo họ khi không thể kết nối mạng trong quá trình sửa dụng ứng dụng của bạn. Để làm điều này, bạn sẽ cần thực hiện hai việc sau trong component:

1. Một phần state để theo dõi xem mạng có trực tuyến không.
2. Một Effect để đăng ký sự kiện trực tuyến và ngoại tuyến để cập nhật trạng thái.

Bạn có thể bắt đầu bằng một đoạn mã như sau:

```jsx
import { useState, useEffect } from "react";

export default function StatusBar() {
  const [isOnline, setIsOnline] = useState(true);
  useEffect(() => {
    function handleOnline() {
      setIsOnline(true);
    }
    function handleOffline() {
      setIsOnline(false);
    }
    window.addEventListener("online", handleOnline);
    window.addEventListener("offline", handleOffline);
    return () => {
      window.removeEventListener("online", handleOnline);
      window.removeEventListener("offline", handleOffline);
    };
  }, []);

  return <h1>{isOnline ? "✅ Trực Tuyến" : "❌ Ngắt Kết Nối"}</h1>;
}
```

Tuy nhiên, giả sử bạn muốn sử dụng cùng logic trong một component khác. Bạn muốn thực hiện một nút **"Lưu"** sẽ bị tắt và hiển thị **"Đang kết nối..."** thay vì **"Lưu"** khi mạng bị ngắt kết nối.

Để bắt đầu, bạn có thể sao chép và dán state `isOnline` và `Effect` vào `SaveButton` như sau:

```jsx
import { useState, useEffect } from "react";

export default function SaveButton() {
  const [isOnline, setIsOnline] = useState(true);
  useEffect(() => {
    function handleOnline() {
      setIsOnline(true);
    }
    function handleOffline() {
      setIsOnline(false);
    }
    window.addEventListener("online", handleOnline);
    window.addEventListener("offline", handleOffline);
    return () => {
      window.removeEventListener("online", handleOnline);
      window.removeEventListener("offline", handleOffline);
    };
  }, []);

  function handleSaveClick() {
    console.log("✅ Tiến trình đã được lưu");
  }

  return (
    <button disabled={!isOnline} onClick={handleSaveClick}>
      {isOnline ? "Lưu tiến trình" : "Đang kết nối..."}
    </button>
  );
}
```

Nhưng việc này sẽ làm code chúng ta bị trùng lặp? Bạn đang tạo ra 2 state khác nhau, làm cách nào để chúng ta có thể tái sử dụng logic giữa chúng.

## Cách tạo ra custom hook trong React

Hãy tưởng tượng rằng, tương tự như `useState` và `useEffect`, có một Hook tích hợp sẵn là `useOnlineStatus`. Sau đó, cả hai component này có thể được đơn giản hóa và bạn có thể loại bỏ sự trùng lặp giữa chúng:

```javascript
function StatusBar() {
  const isOnline = useOnlineStatus();
  return <h1>{isOnline ? "✅ Trực Tuyến" : "❌ Ngắt Kết Nối"}</h1>;
}

function SaveButton() {
  const isOnline = useOnlineStatus();

  function handleSaveClick() {
    console.log("✅ Tiến trình đã được lưu");
  }

  return (
    <button disabled={!isOnline} onClick={handleSaveClick}>
      {isOnline ? "Lưu tiến trình" : "Đang kết nối..."}
    </button>
  );
}
```

Tuyệt nhiên, không có sẵn một Hook như vậy, nhưng bạn vẫn có thể tự viết nó. Hãy khai báo một hàm gọi là `useOnlineStatus` và di chuyển logic liên quan đến mạng vào đó:

```javascript
import { useState, useEffect } from "react";

function useOnlineStatus() {
  const [isOnline, setIsOnline] = useState(true);

  useEffect(() => {
    function handleOnline() {
      setIsOnline(true);
    }
    function handleOffline() {
      setIsOnline(false);
    }
    window.addEventListener("online", handleOnline);
    window.addEventListener("offline", handleOffline);
    return () => {
      window.removeEventListener("online", handleOnline);
      window.removeEventListener("offline", handleOffline);
    };
  }, []);

  return isOnline;
}
```

Bây giờ bạn có một Custom Hook có tên là `useOnlineStatus` chứa logic liên quan đến mạng. Bạn có thể sử dụng nó trong bất kỳ [component](/bai-viet/reactjs/component-trong-react-la-gi) nào bạn muốn theo dõi trạng thái trực tuyến của mạng.. Bằng cách tách logic thành các Custom Hooks, bạn có thể tận dụng lại nó trong nhiều component khác nhau mà không cần sao chép và dán code. Điều này giúp mã của bạn trở nên dễ quản lý, dễ bảo trì và giảm thiểu lỗi.

::alert{type="warning"}
Lưu ý rằng bạn có thể đặt tên cho Custom Hooks của bạn bất kỳ cách nào bạn muốn, nhưng việc đặt tên có ý nghĩa và dễ đọc sẽ giúp đồng đội của bạn hiểu rõ mục đích của Hook.
::
