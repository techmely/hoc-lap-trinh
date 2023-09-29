---
title: "Rendering list trong React"
description: "Rendering list trong React"
chapter:
  name: "Giao diện trong ReactJs"
  slug: "chuong-03-giao-dien-trong-reactjs"
image: https://kungfutech.edu.vn/thumbnail.png
position: 7
---

Khi bạn phải hiển thị nhiều thành phần tương tự từ một bộ dữ liệu, bạn có thể sử dụng các phương thức của mảng JavaScript để thao tác trên mảng dữ liệu đó. Trong bài viết này, bạn sẽ tìm hiểu cách sử dụng `filter()` và `map()` của JavaScript cùng với React để lọc và biến đổi mảng dữ liệu thành một mảng các thành phần.

## Hiển thị dữ liệu từ mảng

Hãy tưởng tượng bạn có một danh sách các nội dung như sau:

```html
<ul>
  <li>Creola Katherine Johnson: nhà toán học</li>
  <li>Mario José Molina-Pasquel Henríquez: nhà hóa học</li>
  <li>Mohammad Abdus Salam: nhà vật lý</li>
  <li>Percy Lavon Julian: nhà hóa học</li>
  <li>Subrahmanyan Chandrasekhar: nhà thiên văn học</li>
</ul>
```

Các mục trong danh sách này chỉ khác nhau về nội dung. Trong thực tế, khi bạn xây dựng giao diện, bạn thường phải hiển thị nhiều phiên bản của cùng một thành phần với dữ liệu khác nhau, chẳng hạn như danh sách bình luận hoặc thư viện hình ảnh cá nhân. Trong các tình huống như vậy, bạn có thể lưu trữ dữ liệu đó trong các đối tượng và mảng JavaScript, sau đó sử dụng các phương thức như `map()` và `filter()` để hiển thị danh sách các thành phần từ chúng.

Dưới đây là một ví dụ đơn giản về cách tạo danh sách các mục từ một mảng:

1. Đưa dữ liệu vào một mảng:

```javascript
const people = [
  "Creola Katherine Johnson: nhà toán học",
  "Mario José Molina-Pasquel Henríquez: nhà hóa học",
  "Mohammad Abdus Salam: nhà vật lý",
  "Percy Lavon Julian: nhà hóa học",
  "Subrahmanyan Chandrasekhar: nhà thiên văn học",
];
```

2. Sử dụng `map()` để tạo một mảng mới của các phần tử JSX, ví dụ `listItems`:

```javascript
const listItems = people.map((person) => <li>{person}</li>);
```

3. Trả về `listItems` từ thành phần React của bạn bên trong một thẻ `<ul>`:

```javascript
return <ul>{listItems}</ul>;
```

Dưới đây là kết quả:

```jsx
<ul>
  <li>Creola Katherine Johnson: nhà toán học</li>
  <li>Mario José Molina-Pasquel Henríquez: nhà hóa học</li>
  <li>Mohammad Abdus Salam: nhà vật lý</li>
  <li>Percy Lavon Julian: nhà hóa học</li>
  <li>Subrahmanyan Chandrasekhar: nhà thiên văn học</li>
</ul>
```

## Lọc các thành phần từ mảng

Dữ liệu có thể được cấu trúc một cách tốt hơn như sau:

```javascript
const people = [
  {
    id: 0,
    name: "Creola Katherine Johnson",
    profession: "nhà toán học",
  },
  {
    id: 1,
    name: "Mario José Molina-Pasquel Henríquez",
    profession: "nhà hóa học",
  },
  {
    id: 2,
    name: "Mohammad Abdus Salam",
    profession: "nhà vật lý",
  },
  {
    id: 3,
    name: "Percy Lavon Julian",
    profession: "nhà hóa học",
  },
  {
    id: 4,
    name: "Subrahmanyan Chandrasekhar",
    profession: "nhà thiên văn học",
  },
];
```

Giả sử bạn muốn hiển thị chỉ các thành phần có chuyên ngành là 'nhà hóa học'. Bạn có thể sử dụng phương thức `filter()` của JavaScript để chỉ trả về những người đó. Phương thức này nhận một mảng các phần tử, đi qua chúng qua một "kiểm tra" (một hàm trả về true hoặc false), và trả về một mảng mới chứa chỉ những phần tử đã vượt qua kiểm tra đó (trả về true).

Trong trường hợp này, bạn chỉ muốn các phần tử có chuyên ngành là 'nhà hóa học'. Hàm kiểm tra cho việc này có thể được viết như sau: `(person) => person.profession === 'nhà hóa học'`.

Dưới đây là cách kết hợp các bước để hiển thị danh sách các 'nhà hóa học':

1. Tạo một mảng mới chỉ chứa 'nhà hóa học' bằng cách gọi `filter()` trên `people` với điều kiện `person.profession === 'nhà hóa học'`:

```javascript
const chemists = people.filter((person) => person.profession === "nhà hóa học");
```

2. Tiếp theo, sử dụng `map()` để tạo một mảng mới của các phần tử JSX từ `chemists`:

```javascript
const listItems = chemists.map((person) => (
  <li>
    <p>
      <b>{person.name}:</b> {person.profession}
    </p>
  </li>
));
```

3. Cuối cùng, trả về `listItems` từ thành phần React của bạn:

```javascript
return <ul>{listItems}</ul>;
```

Kết quả là danh sách các 'nhà hóa học':

```jsx
<ul>
  <li>
    <p>
      <b>Mario José Molina-Pasquel Henríquez:</b> nhà hóa học
    </p>
  </li>
  <li>
    <p>
      <b>Percy Lavon Julian:</b> nhà hóa học
    </p>
  </li>
</ul>
```

## Sử dụng khóa (keys) trong React

Lưu ý rằng trong ví dụ trên, bạn có thể thấy một cảnh báo trong console:

```bash
Warning: Each child in a list should have a unique "key" prop.
```

React yêu cầu mỗi thành phần trong một danh sách phải có một khóa (key) duy nhất. Khóa (key) này là một chuỗi hoặc một số duy nhất xác định thành phần đó trong danh sách. Điều này trở nên quan trọng khi các thành phần trong danh sách có thể thay đổi vị trí, bị chèn, hoặc bị xóa. Một khóa (key) được chọn tốt giúp React hiểu rõ điều gì đã xảy ra và cập nhật cây DOM đúng cách.

Thay vì tạo khóa (key) dựa trên tên và chức năng, bạn nên bao gồm nó trong dữ liệu của mình. Điều này giúp bạn duy trì tính độc đáo và ổn định của khóa (key) ngay cả khi dữ liệu thay đổi. Dưới đây là ví dụ:

```javascript
export const people = [
  {
    id: 0, // Được sử dụng trong JSX như một khóa (key)
    name: "Creola Katherine Johnson",
    profession: "nhà toán học",
  },
  // ...
];
```

Khi bạn hiển thị các thành phần trong một danh sách, hãy đảm bảo sử dụng `key` cho mỗi thành phần:

```javascript
const listItems = chemists.map((person) => (
  <li key={person.id}>{/* Nội dung của thành phần */}</li>
));
```

Dưới đây là tại sao bạn cần sử dụng khóa (keys) trong React:

- Khóa (keys) giúp React xác định một cách duy nhất mỗi thành phần trong danh sách, ngay cả khi vị trí hoặc dữ liệu của chúng thay đổi.
- Nếu bạn không xác định một khóa (key) hoặc sử dụng một khóa (key) không duy nhất, React có thể gặp khó khăn trong việc xác định các sự thay đổi và cập nhật DOM.
- Tạo khóa (key) dựa trên chỉ số trong mảng (ví dụ: `key={index}`) thường dẫn đến các lỗi khó xác định và khó hiểu.

::alert{type="success"}
Trong bài viết này, bạn đã tìm hiểu cách hiển thị danh sách các thành phần từ một mảng trong React. Bằng cách sử dụng `map()` và `filter()` của JavaScript, bạn có thể tạo ra các danh sách dựa trên dữ liệu mảng. Đồng thời, việc sử dụng khóa (keys) trong React là rất quan trọng để duy trì tính duy nhất của các thành phần trong danh sách và đảm bảo các cập nhật DOM đúng đắn.
::
