---
title: "Cập nhật state của Mảng (Array) trong Reactjs"
description: "Tương tự như với các đối tượng (objects), khi bạn muốn cập nhật một mảng được lưu trữ trong state, bạn cần tạo ra một mảng mới (hoặc sao chép một mảng hiện có), sau đó thiết lập state để sử dụng mảng mới đó."
chapter:
  name: "Tương tác trong Reactjs"
  slug: "chuong-04-tuong-tac-trong-reactjs"
image: https://kungfutech.edu.vn/thumbnail.png
position: 6
---

Trong JavaScript, mảng (array) là một cấu trúc dữ liệu có khả năng thay đổi (mutable), nhưng khi bạn lưu trữ chúng trong state của ứng dụng React, bạn nên xem xét chúng như là bất biến (immutable). Tương tự như với các đối tượng (objects), khi bạn muốn cập nhật một mảng được lưu trữ trong state, bạn cần tạo ra một mảng mới (hoặc sao chép một mảng hiện có), sau đó thiết lập state để sử dụng mảng mới đó.

## Cập nhật mảng mà không gây thay đổi

Trong JavaScript, mảng chỉ là một loại đối tượng khác. Tương tự như với các đối tượng, bạn nên xem xét các mảng trong state của React như là chỉ đọc (read-only). Điều này có nghĩa là bạn không nên gán lại các phần tử trong một mảng như `arr[0] = 'bird'`, và bạn cũng không nên sử dụng các phương thức gây thay đổi mảng như `push()` và `pop()`.

Thay vào đó, mỗi khi bạn muốn cập nhật một mảng, bạn nên truyền một mảng mới cho hàm thiết lập state của bạn. Để làm điều này, bạn có thể tạo ra một mảng mới từ mảng gốc trong state của bạn bằng cách gọi các phương thức không gây thay đổi mảng như `filter()` và `map()`. Sau đó, bạn có thể thiết lập state của bạn để sử dụng mảng mới đã tạo.

Dưới đây là một bảng tham khảo về các hoạt động phổ biến trên mảng. Khi làm việc với mảng trong state của React, bạn nên tránh sử dụng các phương thức ở cột bên trái, và thay vào đó ưa thích sử dụng các phương thức ở cột bên phải:

| Tránh sử dụng (gây thay đổi mảng)            | Ưa thích sử dụng (trả về mảng mới)                            |
| -------------------------------------------- | ------------------------------------------------------------- |
| Thêm phần tử: `push()`, `unshift()`          | Thêm phần tử: `concat()`, `[...arr]` (sử dụng toán tử Spread) |
| Xóa phần tử: `pop()`, `shift()`, `splice()`  | Xóa phần tử: `filter()`, `slice()`                            |
| Thay đổi phần tử: `splice()`, `arr[i] = ...` | Thay đổi phần tử: `map()`                                     |
| Sắp xếp: `reverse()`, `sort()`               | Sắp xếp: Sao chép mảng trước (để sau đó sử dụng `sort()`)     |

Một cách khác, bạn có thể sử dụng thư viện Immer để sử dụng các phương thức từ cả hai cột.

### Lỗi tiềm ẩn

Rất tiếc, `slice` và `splice` có tên giống nhau nhưng khác nhau một cách rõ rệt:

- `slice` cho phép bạn sao chép một mảng hoặc một phần của nó.
- `splice` gây thay đổi mảng (để chèn hoặc xóa các phần tử).

Trong React, bạn sẽ sử dụng `slice` (không có "p!") nhiều hơn vì bạn không muốn thay đổi các đối tượng hoặc mảng trong state. Lý thuyết về việc cập nhật đối tượng giải thích sự thay đổi và tại sao không khuyến nghị thay đổi state.

## Thêm phần tử vào mảng trong state của React

Phương thức `push()` sẽ thay đổi mảng mà bạn không muốn:

```javascript
import { useState } from "react";

let nextId = 0;

export default function List() {
  const [name, setName] = useState("");
  const [artists, setArtists] = useState([]);

  return (
    <>
      <h1>Những nghệ sĩ điêu khắc đầy cảm hứng:</h1>
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

Thay vào đó, hãy tạo ra một mảng mới chứa các phần tử hiện có và một phần tử mới ở cuối. Có nhiều cách để làm điều này, nhưng cách dễ nhất là sử dụng cú pháp toán tử spread (`...`) cho mảng:

```javascript
setArtists([...artists, { id: nextId++, name: name }]);
```

## Xóa phần tử khỏi mảng trong state của React

Cách dễ nhất để xóa một phần tử khỏi một mảng là sử dụng phương thức `filter()`. Nói cách khác, bạn sẽ tạo ra một mảng mới không chứa phần tử đó. Để làm điều này, bạn có thể sử dụng phương thức `filter`, ví dụ:

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
      <h1>Những nghệ sĩ điêu khắc đầy cảm hứng:</h1>
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

Ở đây, `artists.filter(a => a.id !== artist.id)` có nghĩa là "tạo ra một mảng chứa những nghệ sĩ có ID khác với `artist.id`". Nói cách khác, nút "Xóa" của từng nghệ sĩ sẽ lọc ra nghệ sĩ đó khỏi mảng và sau đó yêu cầu một lần render lại với mảng kết quả mới. Lưu ý rằng `filter` không thay đổi mảng gốc.

## Biến đổi mảng trong state của React

Nếu bạn muốn thay đổi một số hoặc tất cả các phần tử trong một mảng, bạn có thể sử dụng `map()` để tạo ra một mảng mới. Hàm mà bạn sẽ truyền vào `map` có thể quyết định xem làm gì với từng phần tử dựa trên dữ liệu hoặc chỉ mục của nó (hoặc cả hai).

Trong ví dụ sau đây, một mảng chứa tọa độ của hai hình tròn và một hình vuông. Khi bạn nhấn nút, nó chỉ di chuyển các hình tròn xuống 50 pixel. Điều này được thực hiện bằng cách tạo ra một mảng dữ liệu mới sử dụng `map()`:

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

Thường xuyên, bạn muốn thay thế một hoặc nhiều phần tử trong một mảng. Gán giá trị như `arr[0] = 'bird'` đang làm thay đổi mảng gốc, vì vậy thay vào đó bạn nên sử dụng `map` để làm điều này.

Để thay thế một phần tử, bạn nên tạo ra một mảng mới với `map`. Bên trong cuộc gọi `map` của bạn, bạn sẽ nhận được chỉ mục phần tử là đối số thứ hai. Sử dụng nó để quyết định liệu có trả lại phần tử ban đầu (đối số thứ nhất) hoặc một cái gì khác:

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

## Chèn vào một mảng trong state của React

Đôi khi, bạn có thể muốn chèn một phần tử vào một vị trí cụ thể không phải ở đầu hoặc cuối cùng. Để làm điều này, bạn có thể sử dụng cú pháp `...` kết hợp với phương thức `slice()`. Phương thức `slice()` cho phép bạn cắt một "lát mảng". Để chèn một phần tử, bạn sẽ tạo ra một mảng bằng cách sử dụng cú pháp `...` để chứa lát trước điểm chèn, sau đó là phần tử mới và sau đó là phần còn lại của mảng gốc.

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
      <h1>Những nghệ sĩ điêu khắc đầy cảm hứng:</h1>
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

## Sử dụng thư viện Immer để làm việc với mảng dễ dàng hơn

Thư viện Immer giúp làm việc với các cấu trúc dữ liệu bất biến (như mảng và đối tượng) trở nên dễ dàng hơn bằng cách cho phép bạn thực hiện các thay đổi "như gây biến đổi" trên chúng. Thay vì phải sao chép mảng hoặc đối tượng và sau đó thay đổi chúng, bạn có thể sử dụng Immer để thực hiện các thay đổi trực tiếp trên một phiên bản tạm thời của cấu trúc dữ liệu và sau đó tự động tạo ra một phiên bản mới, không gây biến đổi.

Để sử dụng Immer trong ứng dụng React, bạn cần cài đặt thư viện và sử dụng hàm `produce()` từ Immer để tạo ra phiên bản mới của state. Dưới đây là một ví dụ về cách sử dụng Immer để cập nhật một mảng:

```javascript
import { useState } from 'react';
import produce from 'immer';

let nextId = 3;
const initialArtists = [
  { id: 0, name: 'Marta Colvin Andrade' },
  { id: 1, name: 'Lamidi Olonade Fakeye'},
  { id: 2, name: 'Louise Nevelson'},
];

export default function List() {
  const [name, setName] = useState('');
  const [artists, setArtists] = useState(initialArtists);

  function handleClick() {
    setArtists(prevArtists => {
      return produce(prevArtists, draftArtists => {
        draftArtists.push({ id: nextId++, name: name });
      });
    });
    setName('');
  }

  return (
    <>
      <h1>Những nghệ sĩ điêu khắc đầy cảm hứng:</h1>
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

Trong ví dụ này, chúng ta đã thay đổi phần `handleClick` để sử dụng Immer. Chúng ta gọi `produce()` từ Immer và truyền mảng cần thay đổi `prevArtists` vào hàm này. Sau đó, chúng ta có thể thực hiện các thay đổi trên `draftArtists`, phiên bản tạm thời của mảng. Immer sẽ tự động tạo ra một phiên bản mới của mảng không gây biến đổi sau khi bạn hoàn tất các thay đổi trên `draftArtists`.

Immer giúp giảm bớt việc bạn phải sao chép và quản lý các phiên bản của mảng hoặc đối tượng, làm cho mã của bạn trở nên dễ đọc hơn và ít dễ bị lỗi hơn khi làm việc với trạng thái trong React.

::alert{type="success"}

Khi làm việc với mảng trong React, hãy xem xét chúng như là bất biến (immutable) và tránh gây biến đổi trực tiếp. Thay vào đó, sử dụng các phương thức không gây biến đổi như `map()`, `filter()`, `concat()`, và `...` để tạo ra mảng mới hoặc thay đổi mảng hiện có. Nếu bạn cần thực hiện các thay đổi phức tạp hơn, bạn có thể sử dụng thư viện Immer để làm cho quá trình này dễ dàng hơn và giảm bớt rủi ro lỗi.

::
