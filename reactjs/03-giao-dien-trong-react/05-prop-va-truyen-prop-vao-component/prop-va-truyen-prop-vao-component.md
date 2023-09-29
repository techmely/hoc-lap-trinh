---
title: "Prop và cách truyền prop vào component trong React"
description: "Prop và cách truyền prop vào component trong React"
chapter:
  name: "Giao diện trong ReactJs"
  slug: "chuong-03-giao-dien-trong-reactjs"
image: https://kungfutech.edu.vn/thumbnail.png
position: 5
---

Trong React, **props** (viết tắt của _properties_) được sử dụng để truyền thông tin giữa các component. Mọi component cha có thể truyền thông tin đến các component con của nó bằng cách cung cấp chúng props. Props có thể khiến bạn liên tưởng đến các thuộc tính HTML, nhưng bạn có thể truyền bất kỳ giá trị JavaScript nào thông qua chúng, bao gồm các đối tượng, mảng và hàm.

## Props Quen Thuộc

Props là thông tin bạn truyền vào một thẻ JSX. Ví dụ, `className`, `src`, `alt`, `width` và `height` là một số props bạn có thể truyền vào một thẻ `<img>`:

```javascript
function Avatar() {
  return (
    <img
      className="avatar"
      src="https://i.imgur.com/1bX5QH6.jpg"
      alt="Lin Lanying"
      width={100}
      height={100}
    />
  );
}

export default function Profile() {
  return <Avatar />;
}
```

Các props bạn có thể truyền vào thẻ `<img>` đã được định nghĩa trước (ReactDOM tuân thủ theo tiêu chuẩn HTML). Tuy nhiên, bạn có thể truyền bất kỳ props nào vào các component của bạn, chẳng hạn như `<Avatar>`, để tùy chỉnh chúng.

## Truyền Props Vào Một Component

Trong đoạn mã này, component Profile không truyền bất kỳ props nào vào component con của nó, Avatar:

```javascript
export default function Profile() {
  return <Avatar />;
}
```

Bạn có thể truyền các props vào Avatar theo hai bước.

### Bước 1: Truyền props vào component con

Đầu tiên, hãy truyền một số props vào Avatar. Ví dụ, hãy truyền hai props: person (một đối tượng) và size (một con số):

```javascript
export default function Profile() {
  return (
    <Avatar person={{ name: "Lin Lanying", imageId: "1bX5QH6" }} size={100} />
  );
}
```

Lưu Ý: Nếu cặp dấu ngoặc nhọn kép sau person= làm bạn bối rối, hãy nhớ rằng chúng chỉ là một đối tượng bên trong các dấu ngoặc nhọn JSX.

### Bước 2: Đọc props bên trong component con

Bạn có thể đọc các props này bằng cách liệt kê tên của chúng, ví dụ: person và size, được ngăn cách bằng dấu phẩy trong ({ và }) ngay sau hàm Avatar. Điều này cho phép bạn sử dụng chúng bên trong mã của component Avatar, giống như bạn thao tác với biến.

```javascript
function Avatar({ person, size }) {
  // person và size có sẵn ở đây
}
```

Thêm một số logic vào Avatar sử dụng các props person và size để render, và bạn đã xong.

Bây giờ bạn có thể cấu hình Avatar để render theo nhiều cách khác nhau với các props khác nhau. Hãy thử điều chỉnh các giá trị!

```javascript
import { getImageUrl } from "./utils.js";

function Avatar({ person, size }) {
  return (
    <img
      className="avatar"
      src={getImageUrl(person)}
      alt={person.name}
      width={size}
      height={size}
    />
  );
}

export default function Profile() {
  return (
    <div>
      <Avatar
        size={100}
        person={{
          name: "Katsuko Saruhashi",
          imageId: "YfeOqp2",
        }}
      />
      <Avatar
        size={80}
        person={{
          name: "Aklilu Lemma",
          imageId: "OKS67lh",
        }}
      />
      <Avatar
        size={50}
        person={{
          name: "Lin Lanying",
          imageId: "1bX5QH6",
        }}
      />
    </div>
  );
}
```

Props cho phép bạn suy nghĩ về các component cha và con độc lập. Ví dụ, bạn có thể thay đổi props person hoặc size bên trong Profile mà không cần suy nghĩ về cách Avatar sử dụng chúng. Tương tự, bạn có thể thay đổi cách Avatar sử dụng các props này mà không cần xem xét Profile.

Bạn có thể xem props như "núm điều chỉnh" bạn có thể điều chỉnh. Chúng phục vụ cùng một vai trò như đối số phục vụ cho các hàm - thực ra, props là đối số duy nhất cho component của bạn! Các hàm component React chấp nhận một đối số duy nhất, một đối tượng props:

```javascript
function Avatar(props) {
  let person = props.person;
  let size = props.size;
  // ...
}
```

Thường thì bạn không cần toàn bộ đối tượng props, vì vậy bạn tháo nó thành các props riêng lẻ.

**Lưu Ý:**
Đừng bỏ lỡ cặp dấu ngoặc nhọn `{ và }` bên trong `( và )` khi khai báo props:

```javascript
function Avatar({ person, size }) {
  // ...
}
```

Cú pháp này được gọi là "destructuring" và tương đương với việc đọc các thuộc tính từ một tham số hàm:

```javascript
function Avatar(props) {
  let person = props.person;
  let size = props.size;
  // ...
}
```

## Chỉ Định Giá Trị Mặc Định Cho Props

Nếu bạn muốn đặt một giá trị mặc định cho props để sử dụng khi không có giá trị được chỉ định, bạn có thể làm điều này bằng cách đặt = và giá trị mặc định ngay sau tham số:

```javascript
function Avatar({ person, size = 100 }) {
  // ...
}
```

Bây giờ, nếu `<Avatar person={...} />` được render mà không có props size, size sẽ được đặt thành 100.

Giá trị mặc định chỉ được sử dụng khi props size bị thiếu hoặc nếu bạn truyền size={undefined}. Tuy nhiên, nếu bạn truyền size={null} hoặc size={0}, giá trị mặc định sẽ không được sử dụng.

## Chuyển Tiếp Props Với Cú Pháp Truyền JSX

Đôi khi, việc truyền props trở nên lặp đi lặp lại:

```javascript
function Profile({ person, size, isSepia, thickBorder }) {
  return (
    <div className="card">
      <Avatar
        person={person}
        size={size}
        isSepia={isSepia}
        thickBorder={thickBorder}
      />
    </div>
  );
}
```

Không có gì sai với mã lặp đi lặp lại - nó có thể dễ đọc hơn. Nhưng đôi khi bạn có thể muốn sự ngắn gọn. Một số component chuyển tiếp tất cả props của họ cho các component con của họ, giống như cách Profile này làm với Avatar. Bởi vì họ không sử dụng bất kỳ props nào của họ trực tiếp, việc sử dụng cú pháp "truyền" ngắn gọn hơn có thể hợp lý:

```javascript
function Profile(props) {
  return (
    <div className="card">
      <Avatar {...props} />
    </div>
  );
}
```

Cú pháp này chuyển tiếp tất cả props của Profile cho Avatar mà không cần liệt kê từng tên props.

Hãy sử dụng cú pháp truyền đàn hồi một cách thận trọng. Nếu bạn sử dụng nó trong mọi component, điều đó có nghĩa có điều gì đó không ổn. Thường thì nó cho thấy bạn nên chia nhỏ các component của bạn và truyền children dưới dạng JSX. Sẽ còn nhiều điều về điều đó ở phần sau!

## Truyền JSX Như Children

Thường xuyên, bạn sẽ lồng các thẻ tích hợp sẵn trong HTML:

```javascript
<div>
  <img />
</div>
```

Đôi khi bạn muốn lồng các component của riêng bạn theo cách tương tự:

```javascript
<Card>
  <Avatar />
</Card>
```

Khi bạn lồng nội dung vào bên trong một thẻ JSX, component cha sẽ nhận nội dung đó dưới dạng props có tên là children. Ví dụ, component Card dưới đây sẽ nhận một props children được đặt thành `<Avatar />` và render nó trong một thẻ div gói:

```javascript
import Avatar from "./Avatar.js";

function Card({ children }) {
  return <div className="card">{children}</div>;
}

export default function Profile() {
  return (
    <Card>
      <Avatar
        size={100}
        person={{
          name: "Katsuko Saruhashi",
          imageId: "YfeOqp2",
        }}
      />
    </Card>
  );
}
```

Hãy thử thay thế `<Avatar>` bên trong `<Card>` bằng một số văn bản để xem cách Card có thể bao quanh bất kỳ nội dung lồng trong nó. Nó không cần "biết" điều gì đang được render bên trong nó. Mẫu linh hoạt này sẽ xuất hiện trong nhiều nơi.

Bạn có thể nghĩ về một component có một props children như một "lỗ" có thể "được lấp đầy" bởi các component cha của nó bằng JSX tùy ý. Bạn thường sử dụng props children cho các bao bọc hình dạng: các panel, lưới, v.v.

## Cách Props Thay Đổi Theo Thời Gian

Component Clock dưới đây nhận hai props từ component cha của nó: `color` và `time`. (Mã của component cha đã được loại bỏ vì nó sử dụng state, mà chúng ta sẽ không nói đến lúc này.)

Hãy thử thay đổi màu trong hộp chọn dưới đây:

```javascript
export default function Clock({ color, time }) {
  return <h1 style={{ color: color }}>{time}</h1>;
}
```

Ví dụ này minh họa rằng một component có thể nhận các props khác nhau theo thời gian. Props không phải lúc nào cũng là tĩnh! Ở đây, props time thay đổi mỗi giây và props color thay đổi khi bạn chọn một màu khác. Props phản ánh dữ liệu của component tại bất kỳ thời điểm nào, chứ không chỉ trong bắt đầu.

Tuy nhiên, props là không thể thay đổi (_immutable_) - một thuật ngữ từ khoa học máy tính có nghĩa là "không thể thay đổi". Khi một component cần thay đổi props của nó (ví dụ: do phản ứng của người dùng hoặc dữ liệu mới), nó sẽ "yêu cầu" component cha của nó chuyển cho nó các props khác - một đối tượng props mới! Props cũ sau đó sẽ được bỏ qua, và cuối cùng bộ máy JavaScript sẽ thu hồi lại bộ nhớ được sử dụng bởi chúng.

**Đừng cố gắng "thay đổi props".** Khi bạn cần phản hồi đối với đầu vào của người dùng (như thay đổi màu được chọn), bạn sẽ cần "đặt state", điều mà bạn có thể tìm hiểu thêm về trong "Trạng thái: Bộ nhớ của một Component".
