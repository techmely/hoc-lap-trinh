---
title: "Cập nhật state của Đối tượng (Object) trong Reactjs"
description: "Để cập nhật một đối tượng trong state, bạn cần tuân thủ một số quy tắc quan trọng để tránh các vấn đề về hiệu suất và độ tin cậy. Hãy cùng tìm hiểu cách cập nhật đối tượng trong state của React một cách đúng đắn"
chapter:
  name: "Tương tác trong Reactjs"
  slug: "chuong-04-tuong-tac-trong-reactjs"
image: https://kungfutech.edu.vn/thumbnail.png
position: 6
---

React là một thư viện JavaScript mạnh mẽ cho phát triển giao diện người dùng. Trong quá trình phát triển ứng dụng React, bạn thường sử dụng các biến state để theo dõi và quản lý trạng thái của các thành phần. Trong React, biến `state` có thể chứa bất kỳ loại giá trị JavaScript nào, bao gồm cả đối tượng (object). Tuy nhiên, để cập nhật một đối tượng trong `state`, bạn cần tuân thủ một số quy tắc quan trọng để tránh các vấn đề về hiệu suất và độ tin cậy. Hãy cùng tìm hiểu cách cập nhật đối tượng trong `state` của React một cách đúng đắn.

## Nhắc lại useState trong Reactjs

Trong React, bạn có thể sử dụng hook `useState` để tạo ra biến state. Ví dụ sau cho thấy cách bạn tạo một biến state và cập nhật nó:

```javascript
import { useState } from "react";

export default function Counter() {
  const [count, setCount] = useState(0);

  const increment = () => {
    setCount(count + 1); // Cập nhật giá trị biến count
  };

  return (
    <div>
      <p>Giá trị hiện tại: {count}</p>
      <button onClick={increment}>Tăng giá trị</button>
    </div>
  );
}
```

Ở đây, biến `count` đang chứa một giá trị số nguyên và bạn cập nhật nó bằng cách sử dụng `setCount`. Điểm quan trọng là giá trị của `count` chỉ được cập nhật thông qua `setCount`.

## `useState` trong Reactjs với object

Khi làm việc với đối tượng trong state của React, bạn không nên thay đổi trạng thái của đối tượng đó trực tiếp. Điều này áp dụng cho cả đối tượng và các đối tượng con (nested objects). Thay vào đó, bạn nên luôn luôn tạo ra một bản sao mới của đối tượng và sau đó cập nhật state bằng bản sao đó. Dưới đây là ví dụ minh họa:

```javascript
import { useState } from "react";

export default function UserProfile() {
  // Khởi tạo một đối tượng user trong state
  const [user, setUser] = useState({
    name: "John Doe",
    age: 30,
    email: "johndoe@example.com",
  });

  const updateUserEmail = (newEmail) => {
    // Không nên thay đổi trạng thái đối tượng user trực tiếp
    // Tạo một bản sao mới và cập nhật state
    const updatedUser = { ...user, email: newEmail };
    setUser(updatedUser);
  };

  return (
    <div>
      <p>Tên: {user.name}</p>
      <p>Tuổi: {user.age}</p>
      <p>Email: {user.email}</p>
      <button onClick={() => updateUserEmail("newemail@example.com")}>
        Đổi Email
      </button>
    </div>
  );
}
```

Trong ví dụ trên, khi bạn muốn thay đổi email của người dùng, bạn không thay đổi trạng thái của `user` trực tiếp. Thay vào đó, bạn tạo ra một bản sao của `user` và chỉ cập nhật email trong bản sao đó, sau đó gán lại cho `user` bằng `setUser`. Việc này đảm bảo rằng React sẽ phát hiện và xử lý sự thay đổi trạng thái một cách chính xác.

## Sử dụng toán tử Spread

Trong React, bạn có thể tạo ra một bản sao của đối tượng bằng cách sử dụng toán tử Spread (`...`). Toán tử Spread sẽ sao chép tất cả các thuộc tính và giá trị từ đối tượng gốc và cho phép bạn cập nhật một số thuộc tính cụ thể trong bản sao mới mà không làm thay đổi đối tượng gốc. Ví dụ sau minh họa cách bạn sử dụng toán tử Spread để sao chép và cập nhật đối tượng:

```javascript
import { useState } from "react";

export default function UpdateObject() {
  const [person, setPerson] = useState({
    firstName: "John",
    lastName: "Doe",
    age: 30,
  });

  const updateFirstName = (newFirstName) => {
    // Tạo bản sao mới của đối tượng person và chỉ cập nhật firstName
    const updatedPerson = { ...person, firstName: newFirstName };
    setPerson(updatedPerson);
  };

  return (
    <div>
      <p>Họ: {person.lastName}</p>
      <p>Tên: {person.firstName}</p>
      <p>Tuổi: {person.age}</p>
      <button onClick={() => updateFirstName("Alice")}>
        Đổi tên thành Alice
      </button>
    </div>
  );
}
```

Trong ví dụ này, toán tử Spread được sử dụng để tạo ra một bản sao của đối tượng `person` và sau đó cập nhật thuộc tính `firstName` trong bản sao đó.

## Xử lý đối tượng lồng ghép (Nested Objects)

Khi bạn làm việc với các đối tượng lồng ghép, bạn cần đảm bảo rằng bạn đã tạo bản sao cho tất cả các đối tượng con và đối tượng gốc mà bạn muốn cập nhật. Toán tử Spread cũng có thể được sử dụng để sao chép các đối tượng con. Dưới đây là một ví dụ minh họa:

```javascript
import { useState } from "react";

export default function UpdateNestedObject() {
  const [person, setPerson] = useState({
    name: "Alice",
    address: {
      street: "123 Main St",
      city: "New York",
    },
  });

  const updateCity = (newCity) => {
    // Tạo một bản sao của đối tượng address và chỉ cập nhật thành phố
    const updatedAddress = { ...person.address, city: newCity };
    // Tạo một bản sao mới của đối tượng person và cập nhật đối tượng address
    const updatedPerson = { ...person, address: updatedAddress };
    setPerson(updatedPerson);
  };

  return (
    <div>
      <p>Tên: {person.name}</p>
      <p>
        Địa chỉ: {person.address.street}, {person.address.city}
      </p>
      <button onClick={() => updateCity("Los Angeles")}>
        Đổi thành phố thành Los Angeles
      </button>
    </div>
  );
}
```

Trong ví dụ này, toán tử Spread được sử dụng để tạo bản sao của đối tượng `address` và sau đó tạo bản sao mới của đối tượng `person`, cập nhật đối tượng `address` trong bản sao đó.

## Sử dụng thư viện Immer

Nếu ứng dụng React của bạn có cấu trúc dữ liệu phức tạp và bạn muốn viết mã ngắn gọn hơn khi cập nhật state, bạn có thể sử dụng thư viện Immer. Thư viện này cho phép bạn viết mã giống như bạn đang thay đổi trạng thái một cách trực tiếp (mutable) mà không cần sao chép thủ công đối tượng. Immer sẽ tự động tạo các bản sao và đảm bảo tính bất biến của state.

Dưới đây là một ví dụ về cách bạn sử dụng Immer để cập nhật đối tượng:

```javascript
import { useImmer } from "use-immer";

export default function UpdateWithImmer() {
  const [person, updatePerson] = useImmer({
    name: "Alice",
    address: {
      street: "123 Main St",
      city: "New York",
    },
  });

  const updateCity = (newCity) => {
    updatePerson((draft) => {
      draft.address.city = newCity;
    });
  };

  return (
    <div>
      <p>Tên: {person.name}</p>
      <p>
        Địa chỉ: {person.address.street}, {person.address.city}
      </p>
      <button onClick={() => updateCity("Chicago")}>
        Đổi thành phố thành Chicago
      </button>
    </div>
  );
}
```

Trong ví dụ này, `useImmer` cho phép bạn sử dụng một hàm `updatePerson` để cập nhật trạng thái, và bạn có thể truyền một hàm callback với biến `draft` để thay đổi đối tượng. Immer sẽ tự động xử lý việc tạo bản sao và cập nhật trạng thái một cách bảo đảm tính bất biến.

Những quy tắc và ví dụ trên đảm bảo rằng bạn có khả năng cập nhật đối tượng trong state của React một cách đúng đắn và an toàn. Bằng cách sử dụng toán tử Spread hoặc thư viện `Immer`, bạn có thể viết mã ngắn gọn hơn và duy trì tính bất biến của state, giúp ứng dụng của bạn hoạt động mượt mà và đáng tin cậy hơn.
