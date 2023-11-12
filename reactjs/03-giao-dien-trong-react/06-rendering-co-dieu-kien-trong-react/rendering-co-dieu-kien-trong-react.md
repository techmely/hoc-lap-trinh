---
title: "Rendering có điều kiện trong React"
description: "Trong React, props (viết tắt của properties) được sử dụng để truyền thông tin giữa các component. Mọi component cha có thể truyền thông tin đến các component con của nó bằng cách cung cấp chúng props"
chapter:
  name: "Giao diện trong Reactjs"
  slug: "chuong-03-giao-dien-trong-reactjs"
image: https://kungfutech.edu.vn/thumbnail.png
position: 6
---

Khi bạn phát triển ứng dụng React, thường xuyên bạn cần hiển thị các nội dung khác nhau dựa trên các điều kiện khác nhau. Trong React, bạn có thể hiển thị JSX có điều kiện bằng cách sử dụng cú pháp JavaScript như câu lệnh `if`, toán tử `&&`, và `? :`.

![Rendering có điều kiện trong React](https://github.com/techmely/hoc-lap-trinh/assets/29374426/971caeb4-73a1-43c3-879f-a12309b32fbb)


## Trả về JSX dựa trên điều kiện

Hãy tưởng tượng bạn có một component `Item` hiển thị danh sách hàng hóa trong một danh sách đóng gói, và mỗi hàng hóa có thể được đánh dấu là đã đóng gói hoặc chưa đóng gói. Ví dụ dưới đây minh họa điều này:

```jsx
function Item({ name, isPacked }) {
  if (isPacked) {
    return <li className="item">{name} ✔</li>;
  }
  return <li className="item">{name}</li>;
}
```

Ở đây, chúng ta kiểm tra giá trị của prop `isPacked`. Nếu `isPacked` là `true`, chúng ta hiển thị một biểu tượng **checkmark (✔)** sau tên hàng hóa. Nếu không, chúng ta hiển thị tên hàng hóa mà không có checkmark.

## Sử dụng `null` để không hiển thị gì cả

Trong một số trường hợp, bạn có thể không muốn hiển thị bất kỳ thứ gì cả. Ví dụ, bạn muốn ẩn các mục đã đóng gói hoàn toàn. Trong trường hợp này, bạn có thể trả về `null`:

```jsx
function Item({ name, isPacked }) {
  if (isPacked) {
    return null;
  }
  return <li className="item">{name}</li>;
}
```

Nếu `isPacked` là `true`, component sẽ trả về `null`, nghĩa là không có gì được hiển thị. Nếu không, nó sẽ hiển thị JSX như bình thường.

Trong thực tế, trả về `null` từ một component không phải lúc nào cũng phổ biến vì điều này có thể làm cho việc sử dụng component trở nên khó khăn cho những người đọc mã nguồn. Thay vào đó, bạn thường sủ dụng điều kiện để hiển thị hoặc ẩn component trong JSX của component cha, và chúng ta sẽ thảo luận về điều này ở phần sau.

## Hiển thị JSX dựa trên điều kiện

Trong ví dụ trước, bạn đã kiểm tra điều kiện và trả về JSX khác nhau dựa trên điều kiện đó. Nó ổn, nhưng có thể dẫn đến sự trùng lặp trong mã nguồn, nếu bạn muốn thay đổi lớp CSS của các mục, bạn cần phải thay đổi chúng ở cả hai nơi. Thay vì vậy, bạn có thể hiển thị JSX dựa trên điều kiện bằng cách sử dụng các phím tắt cú pháp phổ biến sau đây.

### Toán tử điều kiện (Ternary Operator)

JavaScript có một cú pháp gọn để viết biểu thức điều kiện, được gọi là toán tử điều kiện hoặc **"ternary operator"** hay còn gọi là [toán tử rẽ nhánh](/bai-viet/javascript/cau-truc-re-nhanh-trong-javascript). Thay vì sử dụng câu lệnh `if`, bạn có thể sử dụng toán tử này:

```jsx
return <li className="item">{isPacked ? name + " ✔" : name}</li>;
```

Cú pháp này có thể đọc là "nếu `isPacked` đúng, thì hiển thị `name + ' ✔'`, ngược lại hiển thị `name`".

Ví dụ trên sử dụng toán tử điều kiện để hiển thị checkmark nếu `isPacked` là `true`, và hiển thị tên hàng hóa nếu không.

### Toán tử logic AND (`&&`)

Một phím tắt cú pháp khác mà bạn thường gặp trong React là toán tử logic AND (`&&`). Trong component React, bạn thường gặp nó khi bạn muốn hiển thị một phần của JSX nếu một điều kiện đúng và không hiển thị gì nếu điều kiện sai. Với `&&`, bạn có thể hiển thị checkmark chỉ khi `isPacked` là `true`:

```jsx
return (
  <li className="item">
    {name} {isPacked && "✔"}
  </li>
);
```

Bạn có thể đọc cú pháp này là "nếu `isPacked`, thì hiển thị checkmark, ngược lại, không hiển thị gì".

Toán tử `&&` trong JavaScript trả về giá trị bên phải của nó (trong trường hợp này, là dấu checkmark) nếu giá trị bên trái (điều kiện) là đúng. Nếu điều kiện sai, toàn bộ biểu thức trở thành sai và React không hiển thị bất kỳ điều gì thay thế.

::alert{type="warning"}
Không nên đặt các số bên trái của toán tử `&&`. JavaScript sẽ tự động chuyển đổi giá trị bên trái thành kiểu `boolean`, nhưng nếu giá trị đó là `0`, toàn bộ biểu thức sẽ trả về `0`. Ví dụ: `messageCount && <p>Tin nhắn mới</p>` có thể hiểu lầm rằng nó sẽ không hiển thị gì nếu `messageCount` là `0`, nhưng thực tế nó sẽ hiển thị số `0`.
::

## Cấu trúc `if`, `if - else` thông thường

Khi các cú pháp viết tắt trở nên rối và khó đọc, bạn có thể sử dụng câu lệnh `if` và một biến để gán JSX vào biến đó dựa trên điều kiện. Bắt đầu bằng cách khai báo nội dung mặc định bạn muốn hiển thị, tức là tên hàng hóa:

```jsx
let itemContent = name;
```

Sử dụng câu lệnh `if` để gán một biểu thức JSX vào `itemContent` nếu `isPacked` là `true`:

```jsx
if (isPacked) {
  itemContent = name + " ✔";
}
```

Rồi bạn có thể nhúng biến này bằng cặp dấu ngoặc nhọn vào trong JSX:

```jsx
<li className="item">{itemContent}</li>
```

Phong cách này tương đối dài nhưng cũng linh hoạt nhất. Bạn có thể sử dụng nó không chỉ cho văn bản mà còn cho JSX bất kỳ.

**Tóm tắt**

- Trong React, bạn có thể điều khiển logic điều kiện bằng JavaScript.
- Bạn có thể trả về biểu thức JSX dựa trên một điều kiện bằng câu lệnh `if`.
- Bạn có thể gán một phần của JSX vào biến và sau đó bao gồm nó trong JSX khác bằng cách sử dụng dấu ngoặc nhọn.
- Trong JSX, `{condition ? <A /> : <B />}` có nghĩa là "nếu `condition`, hiển thị `<A />`, ngược lại hiển thị `<B />"`.
- Trong JSX, `{condition && <A />}` có nghĩa là "nếu `condition`, hiển thị `<A />`, ngược lại không hiển thị gì".

Những phím tắt này phổ biến trong React và giúp bạn kiểm soát dễ dàng việc hiển thị JSX dựa trên điều kiện. Hãy chọn phong cách mà bạn thấy thoải mái và sử dụng nó trong mã nguồn của bạn.
