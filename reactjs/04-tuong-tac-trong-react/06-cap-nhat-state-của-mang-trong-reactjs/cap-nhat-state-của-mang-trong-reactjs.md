---
title: "Cập nhật state của Mảng (Array) trong Reactjs"
description: "Tương tự như với các đối tượng (objects), khi bạn muốn cập nhật một mảng được lưu trữ trong state, bạn cần tạo ra một mảng mới (hoặc sao chép một mảng hiện có), sau đó thiết lập state để sử dụng mảng mới đó."
chapter:
  name: "Tương tác trong Reactjs"
  slug: "chuong-04-tuong-tac-trong-reactjs"
image: https://kungfutech.edu.vn/thumbnail.png
position: 6
---

Trong JavaScript, [mảng](/bai-viet/javascript/mang-array-trong-javascript) là một cấu trúc dữ liệu có khả năng thay đổi (mutable), nhưng khi bạn lưu trữ chúng trong [state](/bai-viet/reactjs/state-trong-reactjs) của ứng dụng React, bạn nên xem xét chúng như là bất biến (immutable). Tương tự như với các đối tượng (objects), khi bạn muốn cập nhật một mảng được lưu trữ trong `state`, bạn cần tạo ra một mảng mới (hoặc sao chép một mảng hiện có), sau đó cập nhật state để sử dụng mảng mới đó.

![Cập nhật state của Mảng (Array) trong Reactjs](https://github.com/techmely/hoc-lap-trinh/assets/29374426/c0961478-8dbc-4a35-abae-213476120182)

## Cập nhật mảng mà không gây thay đổi

Trong JavaScript, mảng tương tự như đối tượng - bạn nên xem xét các mảng trong `state` của React như là chỉ đọc (read-only). Điều này có nghĩa là bạn không nên gán lại các phần tử trong một mảng như `arr[0] = 'bird'`, và bạn cũng không nên sử dụng các phương thức gây thay đổi mảng như `push()` và `pop()`.

Thay vào đó, mỗi khi bạn muốn cập nhật một mảng, bạn nên truyền một mảng mới cho hàm `setState` của bạn. Để làm điều này, bạn có thể tạo ra một mảng mới từ mảng gốc trong `state` bằng cách gọi các phương thức không gây thay đổi mảng như `filter()` và `map()`. Sau đó, bạn có thể cập nhật `state` của bạn để sử dụng mảng mới đã tạo.

Dưới đây là một bảng tham khảo về các hoạt động phổ biến trên mảng. Khi làm việc với mảng trong `state` của React, bạn nên tránh sử dụng các phương thức ở cột bên trái, và thay vào đó khuyến khích sử dụng các phương thức ở cột bên phải:

| Tránh sử dụng (gây thay đổi mảng)            | Khuyến khích sử dụng (trả về mảng mới)                            |
| -------------------------------------------- | ------------------------------------------------------------- |
| Thêm phần tử: `push()`, `unshift()`          | Thêm phần tử: `concat()`, `[...arr]` (sử dụng toán tử Spread) |
| Xóa phần tử: `pop()`, `shift()`, `splice()`  | Xóa phần tử: `filter()`, `slice()`                            |
| Thay đổi phần tử: `splice()`, `arr[i] = ...` | Thay đổi phần tử: `map()`                                     |
| Sắp xếp: `reverse()`, `sort()`               | Sắp xếp: Sao chép mảng trước (để sau đó sử dụng `sort()`)     |

## Thêm phần tử vào mảng trong state của React

Nếu bạn sử dụng phương thức `push()`, state sẽ không được cập nhật mạc dù mảng đã bị thay đổi

```javascript
import { useState } from "react";

let nextId = 0;

export default function List() {
  const [name, setName] = useState("");
  const [artists, setArtists] = useState([]);

  return (
    <>
      <h1>Danh sách nghệ sĩ:</h1>
      <input value={name} onChange={(e) => setName(e.target.value)} />
      <button
        onClick={() => {
          artists.push({
            id: nextId++,
            name: name,
          });
        }}
      >
        Thêm
      </button>
      <ul>
        {artists.map((artist) => (
          <li key={artist.id}>{artist.name}</li>
        ))}
      </ul>
    </>
  );
}
```

Thay vào đó, hãy tạo ra một mảng mới chứa các phần tử hiện và một phần tử mới ở cuối. Có nhiều cách để làm điều này, nhưng cách dễ nhất là sử dụng cú pháp toán tử spread (`...`) cho mảng:

```javascript
setArtists([...artists, { id: nextId++, name: name }]);
```

## Xóa phần tử khỏi mảng trong state của React

Cách dễ nhất để xóa một phần tử khỏi một mảng là sử dụng phương thức `filter()`. Nói cách khác, bạn sẽ tạo ra một mảng mới không chứa phần tử đó. Để sử dụng cách này, bạn có thể sử dụng phương thức `filter`, ví dụ:

```javascript
import { useState } from "react";

let initialArtists = [
  { id: 0, name: "Marta Colvin Andrade" },
  { id: 1, name: "Lamidi Olonade Fakeye" },
  { id: 2, name: "Louise Nevelson" },
];

export default function List() {
  const [artists, setArtists] = useState(initialArtists);

  return (
    <>
      <h1>Danh sách nghệ sĩ:</h1>
      <ul>
        {artists.map((artist) => (
          <li key={artist.id}>
            {artist.name}{" "}
            <button
              onClick={() => {
                setArtists(artists.filter((a) => a.id !== artist.id));
              }}
            >
              Xóa
            </button>
          </li>
        ))}
      </ul>
    </>
  );
}
```

Bấm vào nút "Xóa" một vài lần và theo dõi xử lý sự kiện của nó:

```javascript
setArtists(artists.filter((a) => a.id !== artist.id));
```

Ở đây, `artists.filter(a => a.id !== artist.id)` có nghĩa là "tạo ra một mảng chỉ bao gồm các nghệ sĩ có ID khác với `artist.id`". Nói cách khác, nút "Xóa" của từng nghệ sĩ sẽ lọc ra nghệ sĩ đó khỏi mảng và sau đó yêu cầu một lần render lại với mảng kết quả mới.

## Biến đổi mảng trong state

Nếu bạn muốn thay đổi một số hoặc tất cả các phần tử trong một mảng, bạn có thể sử dụng `map()` để tạo ra một mảng mới.

Trong ví dụ dưới đây, một mảng chứa tọa độ của hai hình tròn và một hình vuông. Khi bạn nhấn nút, nó chỉ di chuyển các hình tròn xuống 50 pixel. Điều này được thực hiện bằng cách tạo ra một mảng dữ liệu mới sử dụng `map()`:

```javascript
import { useState } from 'react';

let initialShapes = [
  { id: 0, type: 'circle', x: 50, y: 100 },
  { id: 1, type: 'square', x: 150, y: 100 },
  { id: 2, type: 'circle', x: 250, y: 100 },
];

export default function ShapeEditor() {
  const [shapes, setShapes] = useState(
    initialShapes
  );

  function handleClick() {
    const nextShapes = shapes.map(shape => {
      if (shape.type === 'square') {
        // Không thay đổi
        return shape;
      } else {
        // Trả về một hình tròn mới 50 pixel bên dưới
        return {
          ...shape,
          y: shape.y + 50,
        };
      }
    });
    // Render lại với mảng mới
    setShapes(nextShapes);
  }

  return (
    <>
      <button onClick={handleClick}>
        Di chuyển hình tròn xuống!
      </button>
      {shapes.map(shape => (
        // Render các hình ở đây
      ))}
    </>
  );
}
```

## Thay thế phần tử trong mảng trong state của React

Đôi khi bạn muốn thay thế một hoặc nhiều phần tử trong một mảng. Gán giá trị như `arr[0] = 'bird'` - điều này sẽ làm thay đổi mảng gốc mà lại không cập nhật state (sẽ không gây re-render)

Để thay thế một phần tử, bạn nên tạo ra một mảng mới với `map`, hoặc cập nhật mảng gốc và phải set lại state mảng mới

```javascript
import { useState } from "react";

let initialCounters = [0, 0, 0];

export default function CounterList() {
  const [counters, setCounters] = useState(initialCounters);

  function handleIncrementClick(index) {
    const nextCounters = counters.map((c, i) => {
      if (i === index) {
        // Tăng giá trị của counter đã nhấp
        return c + 1;
      } else {
        // Các phần tử khác không thay đổi
        return c;
      }
    });
    setCounters(nextCounters);
  }

  return (
    <ul>
      {counters.map((counter, i) => (
        <li key={i}>
          {counter}
          <button
            onClick={() => {
              handleIncrementClick(i);
            }}
          >
            +1
          </button>
        </li>
      ))}
    </ul>
  );
}
```

## Chèn phần tử vào mảng trong state của React

Đôi khi, bạn muốn chèn một phần tử vào một vị trí cụ thể không phải ở đầu hoặc cuối cùng. Để làm điều này, bạn có thể sử dụng cú pháp `...` kết hợp với phương thức `slice()`.

Trong ví dụ sau đây, nút "Thêm" luôn chèn ở chỉ mục 1:

```javascript
import { useState } from 'react';

let nextId = 3;
const initialArtists = [
  { id: 0, name: 'Marta Colvin Andrade' },
  { id: 1, name: 'Lamidi Olonade Fakeye'},
  { id: 2, name: 'Louise Nevelson'},
];

export default function List() {
  const [name, setName] = useState('');
  const [artists, setArtists] = useState(
    initialArtists
  );

  function handleClick() {
    const insertAt = 1; // Có thể là bất kỳ chỉ mục nào
    const nextArtists = [
      // Các phần tử trước điểm chèn:
      ...artists.slice(0, insertAt),
      // Phần tử mới:
      { id: nextId++, name: name },
      // Các phần tử sau điểm chèn:
      ...artists.slice(insertAt)
    ];
    setArtists(nextArtists);
    setName('');
  }

  return (
    <>
      <h1>Danh sách nghệ sĩ:</h1>
      <input
        value={name}
        onChange={e => setName(e.target.value)}
      />
      <button onClick={handleClick}>Thêm</button>
      <ul>
        {artists.map(artist => (
          // Render các nghệ sĩ ở đây
        ))}
      </ul>
    </>
  );
}
```

## Thực hiện các thay đổi khác trong mảng

Có một số thứ bạn không thể làm với cú pháp `...` và các phương thức không gây biến đổi như `map()` và `filter()` một mình. Ví dụ, bạn có thể muốn đảo ngược hoặc sắp xếp một mảng. Phương thức JavaScript `reverse()` và `sort()` đang gây biến đổi cho mảng gốc, vì vậy bạn không thể sử dụng chúng trực tiếp.

Tuy nhiên, bạn có thể sao chép mảng trước, sau đó thực hiện các thay đổi trên nó.

Ví dụ:

```javascript
import { useState } from 'react';

let nextId = 3;
const initialList = [
  { id: 0, title: 'Big Bellies' },
  { id: 1, title: 'Lunar Landscape' },
  { id: 2, title: 'Terracotta Army' },
];

export default function List() {
  const [list, setList] = useState(initialList);

  function handleClick() {
    const nextList = [...list];
    nextList.reverse();
    setList(nextList);
  }

  return (
    <>
      <button onClick={handleClick}>
        Đảo ngược
      </button>
      <ul>
        {list.map(artwork => (
          // Render các tác phẩm ở đây
        ))}
      </ul>
    </>
  );
}
```

Ở đây, bạn sử dụng cú pháp `...list` để tạo một bản sao của mảng gốc trước. Bây giờ bạn đã có một bản sao, bạn có thể sử dụng các phương thức gây biến đổi như `nextList.reverse()` hoặc `nextList.sort()`, hoặc thậm chí gán các phần tử cụ thể với `nextList[0] = "something"`.

Tuy nhiên, ngay cả khi bạn sao chép một mảng, bạn không thể gây biến đổi cho các phần tử hiện có bên trong nó trực tiếp. Điều này bởi vì sao chép là "nông" - mảng mới sẽ chứa các phần tử giống với mảng gốc. Vì vậy, nếu bạn sửa đổi một đối tượng bên trong mảng đã sao chép, bạn đang gây biến đổi cho trạng thái hiện có. Ví dụ, mã như sau là một vấn đề:

```javascript
const nextList = [...list];
nextList[0].seen = true; // Vấn đề: gây biến đổi cho list[0]
setList(nextList);
```

Mặc dù `nextList` và `list` là hai mảng khác nhau, `nextList[0]` và `list[0]` trỏ đến cùng một đối tượng. Vì vậy, khi bạn thay đổi `nextList[0].seen`, bạn cũng đang thay đổi `list[0].seen`. Điều này có thể dẫn đến sự không nhất quán và lỗi không mong muốn.
