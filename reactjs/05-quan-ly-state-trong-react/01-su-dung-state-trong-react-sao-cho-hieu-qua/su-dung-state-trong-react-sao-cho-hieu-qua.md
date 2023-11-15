---
title: "Sử dụng State trong React sao cho hiệu quả"
description: "Trong quá trình phát triển ứng dụng React, việc cấu trúc state một cách hiệu quả có thể tạo ra sự khác biệt lớn giữa một component dễ dàng chỉnh sửa và fix bug và một component rất khó để sửa chúng. Trong bài viết này, chúng ta sẽ khám phá một số lời khuyên quan trọng khi bạn cần cấu trúc state cho ứng dụng React của bạn"
chapter:
  name: "Quản lý state trong React"
  slug: "chuong-05-quan-ly-state-trong-react"
image: https://kungfutech.edu.vn/thumbnail.png
position: 1
---

Trong quá trình phát triển ứng dụng React, việc cấu trúc `state` một cách hiệu quả có thể giúp [component](/bai-viet/reactjs/component-trong-react-la-gi) của bạn dễ dàng chỉnh sửa và fix bug. Trong bài viết này, chúng ta sẽ khám phá một số lời khuyên quan trọng khi bạn cần cấu trúc `state` cho ứng dụng React của bạn.

![Sử dụng State trong React sao cho hiệu quả](https://github.com/techmely/hoc-lap-trinh/assets/29374426/df178bd4-b443-4df7-ba72-0e71d2f8125b)


## Nguyên tắc cho việc cấu trúc `state`

Khi bạn viết một `component` trong React chứa một số `state`, bạn cần cân nhắc về việc sử dụng bao nhiêu biến `state` và kiểu dữ liệu của chúng. Dưới đây là một số nguyên tắc có thể hướng dẫn bạn đưa ra các quyết định tốt hơn:

### Nhóm state có liên quan

Nếu bạn luôn cập nhật hai hoặc nhiều biến `state` cùng một lúc, hãy xem xét việc hợp nhất chúng thành một biến state duy nhất.

### Tránh sự không thống nhất trong `state`

Khi `state` được cấu trúc một cách mà nhiều phần `state` có thể mâu thuẫn và "trái ý" với nhau, bạn để lại khả năng xảy ra lỗi. Hãy cố gắng tránh điều này.

### Tránh `state` dư thừa

Nếu bạn có thể tính toán một số thông tin từ các `props` khác của `component` hoặc các biến `state` hiện có trong quá trình render, bạn không nên đặt thông tin đó vào `state` của `component`.

### Tránh sự trùng lặp trong `state`

Khi dữ liệu giống nhau được lặp lại giữa nhiều biến `state` hoặc trong các đối tượng lồng nhau, việc duy trì đồng bộ giữa chúng khó khăn. Hãy giảm sự trùng lặp khi có thể.

### Tránh `state` lồng nhau sâu

State có cấu trúc phân cấp sâu không tiện lợi cho việc cập nhật. Khi có thể, hãy ưu tiên cấu trúc `state` theo cách phẳng (ít lồng nhau).

## Ví dụ cách đặt state cho hiệu quả

### Ví dụ nhóm state có liên quan

Khi bạn đứng trước quyết định giữa việc sử dụng một biến `state` duy nhất hoặc nhiều biến `state` riêng biệt, hãy xem xét xem liệu hai biến `state` có thay đổi cùng một lúc hay không. Nếu có, hợp nhất chúng thành một biến state duy nhất sẽ giúp bạn tránh quên đồng bộ hóa chúng. Ví dụ:

```jsx
// Sử dụng nhiều biến state riêng biệt
const [x, setX] = useState(0);
const [y, setY] = useState(0);

// Hoặc hợp nhất chúng thành một biến state duy nhất
const [position, setPosition] = useState({ x: 0, y: 0 });
```

Trong ví dụ trên, nếu `x` và `y` luôn được cập nhật cùng nhau (ví dụ: tọa độ của con trỏ), thì sử dụng `position` có thể làm cho việc duy trì đồng bộ dễ dàng hơn.

### Ví dụ tránh sự không thống nhất trong `state`

Khi bạn có một `state` dẫn đến tình trạng mâu thuẫn hoặc không thống nhất, hãy cân nhắc cấu trúc lại state để tránh tình huống này. Ví dụ:

```jsx
// Trạng thái không thống nhất
const [isSending, setIsSending] = useState(false);
const [isSent, setIsSent] = useState(false);

// Thay bằng một biến state duy nhất
const [status, setStatus] = useState("typing"); // 'typing', 'sending', 'sent'
```

Trong ví dụ này, việc sử dụng một biến state `status` cho phép bạn theo dõi state của `component` một cách rõ ràng hơn và tránh tình trạng mâu thuẫn.

### Ví dụ tránh state dư thừa

Nếu bạn có thể tính toán thông tin nào đó từ các `props` của `component` hoặc từ `state` hiện có trong quá trình render, hãy tránh đặt thông tin đó vào state của component. Ví dụ:

```jsx
// Trạng thái có thông tin dư thừa
const [firstName, setFirstName] = useState("");
const [lastName, setLastName] = useState("");
const [fullName, setFullName] = useState("");

// Sử dụng tính toán trong quá trình render
const fullName = firstName + " " + lastName;
```

Trong ví dụ này, `fullName` là state dư thừa vì bạn có thể tính toán nó trong quá trình render dựa trên `firstName` và `lastName`.

### Ví dụ tránh `state` lồng nhau sâu

Khi `state` của bạn có cấu trúc phân cấp sâu, việc cập nhật nó có thể trở nên phức tạp. Nếu bạn gặp khó khăn trong việc cập nhật state lồng nhau, hãy xem xét cách làm phẳng `state`. Thay vì lồng nhiều đối tượng, bạn có thể sử dụng một cấu trúc phẳng dễ quản lý hơn. Ví dụ:

```jsx
// Cấu trúc state lồng nhau sâu
const initialTravelPlan = {
  id: 0,
  title: "(Root)",
  childPlaces: [
    {
      id: 1,
      title: "Earth",
      childPlaces: [
        {
          id: 2,
          title: "Africa",
          childPlaces: [
            {
              id: 3,
              title: "Botswana",
              childPlaces: [],
            },
            {
              id: 4,
              title: "Egypt",
              childPlaces: [],
            },
          ],
        },
      ],
    },
  ],
};

// Cấu trúc state phẳng
const initialTravelPlan = {
  0: {
    id: 0,
    title: "(Root)",
    childIds: [1],
  },
  1: {
    id: 1,
    title: "Earth",
    childIds: [2],
  },
  2: {
    id: 2,
    title: "Africa",
    childIds: [3, 4],
  },
  3: {
    id: 3,
    title: "Botswana",
    childIds: [],
  },
  4: {
    id: 4,
    title: "Egypt",
    childIds: [],
  },
};
```

Trong ví dụ này, việc cấu trúc state dưới dạng "phẳng" giúp việc cập nhật state trở nên dễ dàng hơn.

::alert{type="success"}

Việc cấu trúc state là một phần quan trọng của việc phát triển ứng dụng React hiệu quả. Bằng cách tuân theo những nguyên tắc cơ bản như nhóm `state` liên quan, tránh sự không thống nhất và state dư thừa, bạn có thể tạo ra các `component` dễ quản lý, dễ bảo trì và ít lỗi hơn trong ứng dụng của bạn.

::
