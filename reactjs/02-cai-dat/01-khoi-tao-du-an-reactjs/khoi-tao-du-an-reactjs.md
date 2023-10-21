---
title: "Khởi tạo dự án với ReactJs"
description: "Nếu bạn muốn xây dựng một ứng dụng hoặc trang web hoàn toàn bằng React, chúng tôi đề xuất bạn nên chọn một trong các framework sử dụng React phổ biến trong cộng đồng"
chapter:
  name: "Cài đặt"
  slug: "chuong-02-cai-dat-reactjs"
image: https://kungfutech.edu.vn/thumbnail.png
position: 1
---

Bạn muốn bắt đầu học ReactJS và tạo dự án đầu tiên của mình? Bài hướng dẫn này là điểm khởi đầu hoàn hảo! Trong bài này, chúng ta sẽ cùng nhau tìm hiểu quy trình khởi tạo dự án ReactJS từ đầu. Chúng ta sẽ chọn một môi trường phát triển và bắt đầu một ứng dụng React đơn giản

## Thử nghiệm đầu tiên với React Component

::alert{type="infor"}
Truy cập vào ứng dụng [https://codepen.io/pen/](https://codepen.io/pen/) để thực hiện live code
::

Ta có một ứng dụng cơ bản như sau:

```html
<div id="app">
  <div class="card">
    <div class="name">Name: Alice</div>
    <div class="age">Age: 20</div>
  </div>
  <div class="card">
    <div class="name">Name: Bob</div>
    <div class="age">Age: 20</div>
  </div>
  <div class="card">
    <div class="name">Name: Cris</div>
    <div class="age">Age: 20</div>
  </div>
</div>
```

```css
.card {
  width: 200px;
  border: 1px solid black;
  padding: 20px;
  border-radius: 10px;
  font-family: sans-serif;
  margin: 5px
}

.name {
  font-size: 20px;
  font-weight: bold;
}

.age {
  font-size: 14px;
  font-style: italic;
}
```

Khi chạy ứng dụng, chúng ta sẽ nhận được kế quả như hình dưới đây:

![Thử nghiệm đầu tiên với React Component](https://github.com/techmely/hoc-lap-trinh/assets/29374426/54b7e9e3-7e67-4296-90aa-9f6ef1ecbd3b)


Đây là cách tiếp cận ứng dụng theo cách thông thường. Ba phần tử trong danh sách là ba phần khác nhau trong HTML. Với các ứng dụng đơn giản thì hoàn toàn bình thường. Tuy nhiên nó cũng bộc lộ một vài điểm yếu sau:

- Khi muốn thêm một phần tử mới vào danh sách, chúng ta cần copy lại HTML và sửa lại nội dung tên, tuổi tương ứng
- Khi thêm trường "Address", chúng ta sẽ cần phải thêm vào cả 3 phần tử trong danh sách.
- Tương tự với việc sửa dữ liệu, chúng ta sẽ phải làm với cả 3 phần tử

Và vấn đề sẽ trở nên phức tạp hơn khi chúng ta có nhiều phần tử hơn!
Với ReactJS, ta có đoạn code như sau:

```js
function NameCard(props) {
  return (
    <div className="card">
      <div className="name">Name: {props.name}</div>
      <div className="age">Age: {props.age}</div>
    </div>
  )
}

ReactDOM.render(<div>
  <NameCard name="Alice" age="20" />
  <NameCard name="Bob" age="20" />
  <NameCard name="Cris" age="20" />
</div>, document.getElementById("app"))
```

Với ReactJS ta có thể thấy các đặc điểm sau:

- Function `NameCard` nhận vào một tham số đầu vào là “props”, và trả ra kết quả là một đoạn “HTML”? Là một cú pháp không tồn tại trong Javascript thông thường
- `class` được thay thế bằng `className`
- Một cú pháp đặc biệt `{}` để chèn nội dung từ JS vào trong HTML

Để có thể chạy được đoạn code trên, chúng ta cần thay đổi một vài cài đặt trong codepen:
- Click vào biểu tượng gear icon của phần JS
- Phần JavaScript Preprocessor: chọn `Babel`
- Phần `Add External Scripts/Pens`, chọn thêm 2 thư viện là `react` và `react-dom`

![khoá học reactjs](https://github.com/techmely/hoc-lap-trinh/assets/29374426/31e6699d-46bc-4591-b70f-c368d9447fa0)

`NameCard` chính là một component trong React. Và sau khi có component đó, chúng ta có thể bắt đầu "tái sử dụng" nó bằng việc tạo ra 3 `NameCard` với các thuộc tính khác nhau. Cú pháp để  sử dụng là  `<NameCard ... />` , giống như việc sử dụng HTML. Đó cũng chính là cách React hoạt động: viết ra các component cũng chính là tạo ra các "thẻ HTML" tuỳ chỉnh và tái sử dụng chúng.

## Khởi tạo ứng dụng React ở trên máy tính

Để có thể cài đặt được ứng dụng ReactJS trên máy tính, máy tính sẽ cần phải được cài đặt các công cụ sau:

- [NodeJS](https://nodejs.org/en/)
- `npm  & npx` (sẽ được cài đặt cùng với NodeJS)

::alert{type="infor"}
💡 Để kiểm tra NodeJS & npx đã được cài đặt ở trên máy tính hay chưa, chúng ta có thể sử dụng câu lệnh `node --version` và `npx --version` . Máy tính sẽ hiển thị phiên bản được cài đặt. Nếu nhìn thấy có lỗi xảy ra, không hiển thị phiên bản, hãy thử khởi động lại ứng dụng / máy tính.
::

Các bước để khởi tạo một ứng dụng React có tên là `hello-world`:

1. Tạo một thư mục trên máy tính
2. Mở cửa sổ dòng lệnh bên trong thư mục đó
3. Chạy câu lệnh `npx create-react-app hello-world` . Sau đó đợi để ứng dụng được khởi tạo
4. Sau khi đã khởi tạo thành công, di chuyển vào bên trong thư mục “hello-world” vừa được tạo bằng câu lệnh `cd hello-world` .
5. Khởi chạy ứng dụng bằng câu lệnh `npm start` .
6. Trình duyệt có thể sẽ tự động mở ra, và ứng dụng đã được khởi tạo thành công

Trong quá trình phát triển ứng dụng, cửa sổ dòng lệnh cần phải được giữ nguyên và không được tắt ứng dụng đang chạy trên cửa sổ đó. Để tắt ứng dụng đó trên cửa sổ dòng lệnh, có thể sử dụng tổ hợp phím `Ctrl + C` .

Để chạy lại ứng dụng, hãy mở cửa sổ dòng lệnh trong thư mục “hello-world” và sử dụng câu lệnh `npm start`

### Cấu trúc dự án của React

Trong dự án React, chúng ta cần quan tâm một vài file và thư mục sau:

- `package.json`
- `node_modules`
- `public`
- `src`

File `package.json` là file cấu hình cho dự án. File này đóng vai trò quan trọng, giúp chúng ta tuỳ chỉnh các cấu hình, cài và xoá các thư viện khác nhau. Các thành phần cần chú ý là `dependencies` và `scripts`

Thư mục `node_modules` là thư mục chứa các thư viện được tải xuống từ bên ngoài được cấu hình bên trong `package.json`. Thư mục này có thể được cài lại thông qua câu lệnh `npm install`

Thư mục `public` là thư mục chứa file HTML duy nhất của dự án React, nơi mà các component sẽ được render.

Thư mục `src` là thư mục chứa toàn bộ source code của ứng dụng. Đây sẽ là thư mục chúng ta viết các components bên trong.

## Các framework React phổ biến nhất

::alert{type="warning"}
Bạn cần cài đặt Node.js để phát triển ứng dụng React.
::

### Next.js

![Next.js](https://github.com/techmely/hoc-lap-trinh/assets/29374426/1068a801-b2f7-49d3-b121-b49798837846)

Next.js là một framework React toàn diện. Nó linh hoạt và cho phép bạn tạo ứng dụng React từ nhỏ đến lớn - từ một blog tĩnh đến một ứng dụng phức tạp. Để tạo dự án Next.js mới, chỉ cần chạy lệnh sau trong dòng lệnh:

```shell
npx create-next-app
```

Nếu bạn mới làm quen với Next.js, [hãy xem hướng dẫn Next.js](https://nextjs.org/).

Next.js được duy trì bởi Vercel, bạn có thể triển khai ứng dụng Next.js lên bất kỳ máy chủ Node.js hoặc dịch vụ serverless nào hoặc máy chủ của riêng bạn. Ứng dụng Next.js hoàn toàn tĩnh có thể triển khai lên bất kỳ dịch vụ hosting tĩnh nào.

### Remix

![Remix](https://github.com/techmely/hoc-lap-trinh/assets/29374426/0bc53679-1e8f-4ccc-a2fe-ce9f25e1beef)


Remix là một framework React toàn diện với định tuyến lồng nhau. Nó cho phép bạn chia ứng dụng thành các phần lồng nhau có thể tải dữ liệu song song và làm mới dựa trên hành động của người dùng. Để tạo dự án Remix mới, hãy chạy lệnh sau:

```shell
npx create-remix
```

Nếu bạn mới làm quen với Remix, [hãy xem hướng dẫn Remix](https://remix.run/)

Remix được duy trì bởi Shopify, khi bạn tạo dự án Remix, bạn cần chọn mục tiêu triển khai của mình. Bạn có thể triển khai ứng dụng Remix lên bất kỳ máy chủ Node.js hoặc dịch vụ serverless nào bằng cách sử dụng hoặc viết một adapter.

### Gatsby

![Gatsby framework](https://github.com/techmely/hoc-lap-trinh/assets/29374426/5267b331-bb45-47bc-9c3a-b95e82cc7700)

Gatsby là một framework React giúp tạo trang web nhanh hỗ trợ bởi hệ thống quản lý nội dung (CMS). Hệ sinh thái plugin đa dạng và lớp dữ liệu GraphQL của nó giúp đơn giản hóa việc tích hợp nội dung, API và dịch vụ vào một trang web duy nhất. Để tạo dự án Gatsby mới, hãy chạy lệnh sau:

```shell
npx create-gatsby
```

Nếu bạn mới làm quen với Gatsby, [hãy xem hướng dẫn Gatsby](https://www.gatsbyjs.com/).

Gatsby được duy trì bởi Netlify, bạn có thể triển khai một trang web Gatsby hoàn toàn tĩnh lên bất kỳ dịch vụ hosting tĩnh nào. Nếu bạn chọn sử dụng các tính năng chỉ chạy trên máy chủ, hãy đảm bảo nhà cung cấp hosting của bạn hỗ trợ chúng cho Gatsby.

### Expo (dành cho ứng dụng di động)

![Expo](https://github.com/techmely/hoc-lap-trinh/assets/29374426/0cca8ee3-f02c-4037-9ac7-b66902ebf5b4)


Expo là một framework React cho phép bạn tạo ứng dụng Android, iOS và web có giao diện người dùng như native. Nó cung cấp một SDK cho React Native giúp việc sử dụng các phần native dễ dàng hơn. Để tạo dự án Expo mới, hãy chạy lệnh sau:

```shell
npx create-expo-app
```

Nếu bạn mới làm quen với Expo, [hãy xem hướng dẫn Expo](https://expo.dev/).

Expo được duy trì bởi Expo (công ty). Xây dựng ứng dụng với Expo là miễn phí và bạn có thể đăng ký chúng lên cửa hàng ứng dụng Google và Apple mà không bị hạn chế. Expo cung cấp thêm các dịch vụ đám mây có thể chọn tham gia với phí.

