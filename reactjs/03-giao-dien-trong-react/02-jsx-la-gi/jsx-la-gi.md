---
title: "JSX là gì?"
description: "Trong thế giới của ReactJS, JSX là một phần quan trọng và không thể thiếu. JSX viết tắt của JavaScript XML là một cú pháp mở rộng cho ngôn ngữ JavaScript, cho phép chúng ta mô tả giao diện người dùng (UI) một cách dễ dàng và rõ ràng hơn"
chapter:
  name: "Giao diện trong Reactjs"
  slug: "chuong-03-giao-dien-trong-reactjs"
image: https://kungfutech.edu.vn/thumbnail.png
position: 2
---

## JSX là gì?

Cú pháp trông giống như HTML mà chúng ta sử dụng trong các component thực sự không phải HTML thông thường. Đó là một cú pháp mới có tên là JSX - Javascript XML. JSX là cú pháp do đội ngũ React phát triển, sử dụng chủ yếu trong React. Tuy nhiên vẫn có thể sử dụng JSX cho một vài công cụ khác như VueJS.

![JSX là gì?](https://github.com/techmely/hoc-lap-trinh/assets/29374426/b2e491d5-f7cf-4301-8fad-fc52122c3030)

Mục đích của JSX được tạo ra để có thể tạo ra các element một cách tường minh và đơn giản. JSX cho phép developer có thể tạo ra các đoạn HTML nhanh chóng, kèm với khả năng có thể chèn các giá trị JS vào bên trong để tạo ra trang web có nội dung động.

## Bạn có thể không cần dùng JSX với React

ReactJS có thể hoạt động mà không cần tới cú pháp JSX. React có sẵn một function giúp chúng ta có thể tạo ra phần `view`. Xét 2 ví dụ sau:

```jsx
function App() {
	return (
		<div className="app">
			<h1>Hello, World!</h1>
		</div>
	)	
}
```

```jsx
import React from 'react'

function App() {
	return React.createElement(
		"div",
		{className: "app"},
		React.createElement("h1", {}, "Hello, World!")
	)
}
```

Hai ví dụ này sẽ cho kết quả giống nhau. Tuy nhiên, dễ thấy cách viết thứ hai khó hơn khá nhiều. Và với những component có nhiều giao diện, cách viết thứ 2 sẽ trở nên rất khó bảo trì sau này. Vì vậy, mặc dù JSX là không hoàn toàn bắt buộc với React, tuy nhiên gần như toàn bộ tất cả các dự án React đều sử dụng JSX.

::alert{type="infor"}
💡 Thực tế thì JSX sau cùng sẽ được biến đổi thành `React.createElement` nhờ một công cụ là Babel. Đó là lý do tại sao ở ví dụ với CodePen ở bài trước, chúng ta cần chọn Babel làm JS Pre-processor.
::

---

## JSX không phải là HTML

JSX mặc dù có cú pháp trông rất giống HTML, tuy nhiên nó có một vài đặc điểm khác biệt so với HTML thông thường

1. Single parent root: Các component React cần phải return một thẻ bao ngoài duy nhất hoặc một array, không thể trả về nhiều hơn hai thẻ.
2. `className` thay vì `class`. Đây là một lý do kĩ thuật. `class` là một từ khoá trong JS. Vì vậy, đội ngũ React đã sử dụng `className` thay vì `class` để tránh các lỗi.
3. `style` nhận giá trị là một object, thay vì là cú pháp CSS thông thường
4. Các thuộc tính HTML sẽ được đổi tên theo kiểu `camelCase`
5. Đối với các đoạn JSX nằm trên nhiều dòng, JSX cần phải được bọc bên trong cặp ngoặc tròn `()`
6. Component do chúng ta viết buộc phải được sử dụng ở dưới dạng tên viết hoa.

Chúng ta sẽ đi sâu vào các thành phần trên ở các phần dưới.

---

## Render giá trị JS với JSX

JSX cho phép chúng ta có thể output các giá trị Javascript trực tiếp vào bên trong. Cú pháp để làm điều này là sử dụng dấu ngoặc nhọn `{}`. Xét ví dụ sau:

```jsx
const App = () => {
	const randomAge = Math.floor(Math.random() * 10)
	const imgSrc = "https://upload.wikimedia.org/wikipedia/commons/thumb/b/b6/Image_created_with_a_mobile_phone.png/640px-Image_created_with_a_mobile_phone.png"	
	return (
		<div>
			Hello, my name is MindX. I'm {randomAge} years old.
			<img src={imgSrc} />
		</div>
  )
}
```

Bằng cách này, chúng ta có thể dễ dàng tạo ra các trang web có nội dung động, có thể hiển thị ra màn hình các giá trị JS cần thiết.

Một điểm lưu ý là các giá trị JS có thể được chèn vào các thuộc tính của các thẻ HTML. Như ở ví dụ trên, ta thấy thẻ `img` với thuộc tính `src` đã nhận vào giá trị là `imgSrc` có kiểu dữ liệu là `string`.

::alert{type="warning"}
Không phải tất cả các kiểu dữ liệu đều có thể được **render** trong JSX. Kiểu dữ liệu object dạng `key-value` không thể được render vì nó không phải là một “React child” hợp lệ. Có thể biến object thành một string và sau đó render bằng function `toString`
::

🧑‍💻 Các bạn có thể thử với array, function và các kiểu dữ liệu nguyên thuỷ khác và theo dõi output. Có thể thực thi một số câu lệnh bên trong JSX, miễn sao chúng có kết quả là một **giá trị JS.** Xem ví dụ dưới đây:

```jsx
const weekday = [
	"Sunday",
  "Monday",
	"Tuesday",
	"Wednesday",
	"Thursday",
	"Friday",
	"Saturday"
];

const App = () => {
	return <div>Today is {weekday[new Date().getDay()]}</div>
}
```

Ở trong ví dụ trên, `weekday[new Date().getDay()]` sẽ trả ra kết quả là một `string` nên có thể được hiển thị trên màn hình. Tuy nhiên, chúng ta không thể sử dụng những câu lệnh `if`, `for`, `while` bên trong JSX, vì chúng không phải là các giá trị trong JS.

## JSX với styling:

Có nhiều cách để có thể style với JSX trong React, tương tự với HTML. Cơ bản sẽ có hai kiểu như sau:

1. Style với file CSS bên ngoài, sử dụng HTML `class` và `id`
2. Inline style

Với cách thứ nhất, cách viết CSS không có gì khác biệt. Điểm khác biệt ở đây là chúng ta cần dùng `className` thay cho `class` thông thường. Điểm khác biệt ở đây là chúng ta có thể import file css vào bên trong component với cú pháp `import "<file>.css"`. Xét ví dụ sau:

```css
.App {
	text-align: center;
  font-weight: bold;
}
```

```jsx
import "./App.css"

const App = () => {
	return (
    <div className="App">
			Hello, world!
    </div>
	)
}
```

Đối với inline-style, đây là một điểm khác biệt tương đối lớn so với HTML thông thường:

- `style` trong JSX nhận giá trị là một **object (key-value)**
- Các key CSS phải được viết dưới dạng `camelCase`
- Các value CSS cần phải được viết dưới dạng `string` hoặc `number`

::alert{type="infor"}
💡 `camelCase` là một quy ước đặt tên phổ biến. Đặc điểm của `camelCase` là từ đầu tiên sẽ bắt đầu với chữ thường, các từ tiếp theo sẽ được viết hoa chữ cái đầu tiên. Một vài ví dụ với `camelCase` là `totalValue`, `aboutUs`, `tenBien`... Với JS, quy ước đặt tên tiêu chuẩn là `camelCase`
::

Xét ví dụ `inline-style` sau:

```jsx
const App = () => {
	return (
		<div style={{backgroundColor: 'yellow', fontSize: 18}}>Hello, World!</div>
	)
}
```

Một điều lưu ý ở đây là với các giá trị CSS nhận vào là số, đơn vị được sử dụng sẽ là `px`. Nếu muốn đơn vị khác, chúng ta cần chuyển giá trị thành string và thêm đơn vị đo vào sau giá trị đó.

::alert{type="warning"}
📌 Cần lưu ý phân biệt hai dấu ngoặc nhọn ở trong ví dụ trên: dấu ngoặc nhọn thứ nhất là ký hiệu đánh dấu việc chúng ta chèn biến Javascript vào trong, dấu ngoặc nhọn thứ hai là ký hiệu bắt đầu của một object javascript.
::

## Quy tắc của JSX

### Trả về một phần tử gốc duy nhất

Để trả về nhiều phần tử từ một thành phần, bạn cần bọc chúng trong một thẻ cha duy nhất. Ví dụ, bạn có thể sử dụng một thẻ `<div>`:

```javascript
<div>
  <h1>Todos của Hedy Lamarr</h1>
  <img
    src="https://i.imgur.com/yXOvdOSs.jpg"
    alt="Hedy Lamarr"
    class="photo"
  >
  <ul>
    ...
  </ul>
</div>
```

Nếu bạn không muốn thêm một thẻ `<div>` thừa vào trong markup của bạn, bạn có thể sử dụng `<>` và `</>` thay thế:

```javascript
<>
  <h1>Todos của Hedy Lamarr</h1>
  <img
    src="https://i.imgur.com/yXOvdOSs.jpg"
    alt="Hedy Lamarr"
    class="photo"
  >
  <ul>
    ...
  </ul>
</>
```

Thẻ rỗng này được gọi là `Fragment`. `Fragment` cho phép bạn nhóm các phần tử mà không để lại bất kỳ dấu vết nào trong cây HTML của trình duyệt.

### Đóng tất cả các thẻ

JSX yêu cầu bạn phải đóng tất cả các thẻ rõ ràng: các thẻ tự đóng như `<img>` phải trở thành `<img />`, và các thẻ bao bọc như `<li>` phải được viết như `<li>Công việc</li>`.

Dưới đây là cách đóng thẻ hình ảnh của Hedy Lamarr và các mục danh sách:

```javascript
<>
  <img src="https://i.imgur.com/yXOvdOSs.jpg" alt="Hedy Lamarr" class="photo" />
  <ul>
    <li>Phát minh đèn giao thông mới</li>
    <li>Luyện tập một cảnh phim</li>
    <li>Cải thiện công nghệ phổ</li>
  </ul>
</>
```

::alert{type="success"}
Với JSX, bạn có thể kết hợp một cách dễ dàng markup giống HTML vào mã JavaScript của mình, tạo ra các thành phần React phong cách và mạnh mẽ. Hãy bắt đầu sử dụng JSX trong dự án React của bạn và trải nghiệm sự mạnh mẽ của nó.
::
