---
title: "Thêm React vào ứng dụng của bạn"
description: "Nếu bạn muốn thêm tính năng tương tác vào dự án hiện tại của mình, bạn không cần phải viết lại nó bằng React. Hãy thêm React vào ngăn xếp công nghệ hiện tại của bạn và hiển thị các thành phần React tương tác bất cứ đâu"
chapter:
  name: "Cài đặt"
  slug: "chuong-02-cai-dat-reactjs"
image: https://kungfutech.edu.vn/thumbnail.png
position: 2
---

Nếu bạn muốn thêm tính năng tương tác vào dự án hiện tại của mình, bạn không cần phải viết lại nó bằng React. Hãy thêm React vào ngăn xếp công nghệ hiện tại của bạn và hiển thị các thành phần React tương tác bất cứ đâu.

::alert{type="warning"}

Bạn cần cài đặt Node.js để phát triển cục bộ. Mặc dù bạn có thể thử nghiệm React trực tuyến hoặc bằng một trang HTML đơn giản, nhưng thực tế là hầu hết các công cụ JavaScript mà bạn muốn sử dụng cho phát triển đòi hỏi Node.js.

::

## Sử dụng React cho một phần của trang web hiện tại của bạn

Hãy tưởng tượng bạn có một ứng dụng web hiện có tại example.com được xây dựng bằng một công nghệ máy chủ khác (ví dụ: Rails), và bạn muốn triển khai toàn bộ các đường dẫn bắt đầu bằng example.com/some-app/ bằng hoàn toàn với React.

Dưới đây là cách chúng tôi đề xuất để thiết lập nó:

1. Xây dựng phần React của ứng dụng của bạn bằng một trong các framework dựa trên React.
2. Xác định /some-app là đường dẫn cơ sở trong cấu hình framework của bạn (đây là cách làm: Next.js, Gatsby).
3. Cấu hình máy chủ của bạn hoặc một proxy để tất cả các yêu cầu dưới /some-app/ được xử lý bởi ứng dụng React của bạn.

Điều này đảm bảo phần React của ứng dụng của bạn có thể triển khai theo các thực hành tốt nhất tích hợp trong những framework đó.

Nhiều framework dựa trên React hỗ trợ toàn bộ ngăn xếp và cho phép ứng dụng React của bạn tận dụng máy chủ. Tuy nhiên, bạn có thể sử dụng cùng phương pháp này ngay cả khi bạn không thể hoặc không muốn chạy JavaScript trên máy chủ. Trong trường hợp này, hãy phục vụ tệp HTML/CSS/JS xuất (đầu ra next export cho Next.js, mặc định cho Gatsby) tại /some-app/ thay vì.

## Sử dụng React cho một phần của trang web hiện tại

Hãy tưởng tượng bạn có một trang web hiện có được xây dựng bằng một công nghệ khác (cả máy chủ như Rails hoặc máy khách như Backbone), và bạn muốn hiển thị các thành phần React tương tác ở một số nơi trên trang đó. Đó là một cách thông thường để tích hợp React - thực tế, đó là cách mà hầu hết sử dụng React nhìn ở Meta trong nhiều năm qua!

Bạn có thể làm điều này trong hai bước:

1. Thiết lập một môi trường JavaScript module hóa cho phép bạn sử dụng cú pháp JSX, chia mã của bạn thành các mô-đun với cú pháp import/export, và sử dụng các gói (ví dụ: React) từ npm package registry.
2. Hiển thị các thành phần React của bạn ở nơi bạn muốn thấy chúng trên trang.

Cách tiếp cận chính xác phụ thuộc vào cài đặt trang hiện có của bạn, vì vậy hãy đi vào một số chi tiết.

## Bước 1: Thiết lập môi trường JavaScript module hóa

Môi trường JavaScript module hóa cho phép bạn viết các thành phần React của bạn trong các tệp riêng lẻ, thay vì viết toàn bộ mã của bạn trong một tệp duy nhất. Nó cũng cho phép bạn sử dụng tất cả các gói tuyệt vời được xuất bản bởi các nhà phát triển khác trên npm registry - bao gồm cả React! Cách bạn thực hiện điều này phụ thuộc vào cài đặt hiện có của bạn:

- Nếu ứng dụng của bạn đã được chia thành các tệp sử dụng câu lệnh import, hãy thử sử dụng cài đặt bạn đã có. Kiểm tra xem việc viết `<div />` trong mã JS của bạn có gây ra lỗi cú pháp không. Nếu nó gây ra lỗi cú pháp, bạn có thể cần biến đổi mã JavaScript của mình bằng Babel và kích hoạt Babel React preset để sử dụng JSX.

- Nếu ứng dụng của bạn chưa có cài đặt hiện có cho việc biên dịch các module JavaScript, hãy thiết lập nó bằng Vite. Cộng đồng Vite duy trì nhiều tích hợp với các framework backend, bao gồm Rails, Django và Laravel. Nếu framework backend của bạn không được liệt kê, hãy tuân theo hướng dẫn này để tích hợp xây dựng Vite vào backend của bạn.

Để kiểm tra xem cài đặt của bạn có hoạt động không, hãy chạy lệnh sau trong thư mục dự án của bạn:

```bash
npm install react react-dom
```

Sau đó, thêm các dòng mã sau vào đầu tệp JavaScript chính của bạn (có thể được gọi là index.js hoặc main.js):

```javascript
import { createRoot } from "react-dom/client";

// Xóa nội dung HTML hiện có
document.body.innerHTML = '<div id="app"></div>';

// Hiển thị thành phần React của bạn thay vì
const root = createRoot(document.getElementById("app"));
root.render(<h1>Hello, world</h1>);
```

Nếu toàn bộ nội dung của trang của bạn bị thay thế bằng một "Hello, world!", điều đó có nghĩa là mọi thứ đã hoạt động! Hãy tiếp tục đọc.

## Bước 2: Hiển thị các thành phần React bất kỳ nơi nào trên trang

Trong bước trước, bạn đã đặt mã này ở đầu tệp chính của bạn:

```javascript
import { createRoot } from "react-dom/client";

// Xóa nội dung HTML hiện có
document.body.innerHTML = '<div id="app"></div>';

// Hiển thị thành phần React của bạn thay vì
const root = createRoot(document.getElementById("app"));
root.render(<h1>Hello, world</h1>);
```

Tất nhiên, bạn thực sự không muốn xóa nội dung HTML hiện có!

Hãy xóa mã này.

Thay vào đó, bạn có thể muốn hiển thị các thành phần React của bạn ở các vị trí cụ thể trong trang HTML của bạn. Mở trang HTML của bạn (hoặc các mẫu máy chủ tạo ra nó) và thêm một thuộc tính id duy nhất vào bất kỳ thẻ nào, ví dụ:

```html
<!-- ... đâu đó trong trang html của bạn ... -->
<nav id="navigation"></nav>
<!-- ... thêm nhiều html khác ... -->
```

Điều này cho phép bạn tìm thấy phần tử HTML đó bằng document.getElementById và truyền nó cho createRoot để bạn có thể hiển thị thành phần React của riêng bạn bên trong:

```javascript
import { createRoot } from "react-dom/client";

function NavigationBar() {
  // TODO: Thực sự triển khai thanh điều hướng
  return <h1>Hello from React!</h1>;
}

const domNode = document.getElementById("navigation");
const root = createRoot(domNode);
root.render(<NavigationBar />);
```

Lưu ý cách nội dung HTML gốc từ index.html được bảo toàn, nhưng thành phần React NavigationBar của bạn hiện xuất hiện trong `<nav id="navigation">` từ trang HTML của bạn. Đọc tài liệu sử dụng createRoot để tìm hiểu thêm về cách hiển thị các thành phần React bên trong trang HTML hiện có của bạn.

Khi bạn áp dụng React vào một dự án hiện có, điều phổ biến là bắt đầu bằng các thành phần tương tác nhỏ (như các nút), sau đó dần dần "di chuyển lên" cho đến cuối cùng trang web của bạn được xây dựng bằng React. Nếu bạn bao giờ đạt được điểm đó, chúng tôi đề xuất chuyển sang một framework React ngay sau đó để tận dụng tối đa tính năng của React.

## Sử dụng React Native trong ứng dụng di động native hiện có

React Native cũng có thể được tích hợp vào các ứng dụng native hiện có một cách tăng dần. Nếu bạn có ứng dụng native hiện có cho Android (Java hoặc Kotlin) hoặc iOS (Objective-C hoặc Swift), hãy làm theo hướng dẫn này để thêm một màn hình React Native vào đó.
