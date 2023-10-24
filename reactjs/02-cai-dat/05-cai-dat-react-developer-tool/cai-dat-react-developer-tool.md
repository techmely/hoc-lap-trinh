---
title: "Cài đặt React Developer Tool"
description: "React Developer Tools là một công cụ mạnh mẽ giúp bạn kiểm tra, chỉnh sửa các thành phần React, quản lý props và state, cũng như xác định vấn đề về hiệu suất của ứng dụng React của bạn"
chapter:
  name: "Cài đặt"
  slug: "chuong-02-cai-dat-reactjs"
image: https://kungfutech.edu.vn/thumbnail.png
position: 5
---

React Developer Tools là một công cụ mạnh mẽ giúp bạn kiểm tra, chỉnh sửa các thành phần React, quản lý props và state, cũng như xác định vấn đề về hiệu suất của ứng dụng React của bạn. Trong bài viết này, chúng ta sẽ hướng dẫn bạn cách cài đặt React Developer Tools để sử dụng dễ dàng trong quá trình phát triển ứng dụng React của bạn.

![Cài đặt React Developer Tool](https://github.com/techmely/hoc-lap-trinh/assets/29374426/59a326d1-b2ab-430b-bcc8-8cb6958caa25)


## Bước 1: Cài đặt Tiện ích Mở rộng Trình duyệt

Cách đơn giản và nhanh chóng nhất để gỡ lỗi các trang web được xây dựng bằng React là cài đặt tiện ích mở rộng trình duyệt React Developer Tools. Hiện tại, nó có sẵn cho một số trình duyệt phổ biến như Chrome, Firefox và Edge.

### Đối với Chrome

1. Bước đầu tiên, hãy truy cập trình duyệt Chrome của bạn.
2. Sau đó, bạn sẽ cần cài đặt tiện ích mở rộng React Developer Tools từ Chrome Web Store. Bạn có thể tìm kiếm "React Developer Tools" trong cửa sổ tiện ích mở rộng hoặc truy cập vào liên kết sau và nhấn nút "Add to Chrome" để cài đặt:
   [React Developer Tools - Chrome Web Store](https://chrome.google.com/webstore/detail/react-developer-tools/fmkadmapgofadopljbjfkapdkoienihi)
3. Khi cài đặt hoàn tất, bạn sẽ thấy biểu tượng React Developer Tools xuất hiện ở góc trình duyệt.
4. Bây giờ, khi bạn truy cập một trang web được xây dựng bằng React, hãy mở Developer Tools của Chrome và chuyển đến tab "Components" để bắt đầu kiểm tra các thành phần React của trang web.

### Đối với Firefox

1. Mở trình duyệt Firefox.
2. Truy cập trang cài đặt tiện ích mở rộng của Firefox.
3. Tìm "React Developer Tools" và nhấn nút "Add to Firefox" để cài đặt tiện ích mở rộng.
4. Sau khi cài đặt xong, bạn sẽ thấy biểu tượng React Developer Tools xuất hiện trên thanh công cụ của Firefox.
5. Khi bạn truy cập một trang web React, mở Developer Tools và chuyển đến tab "Components" để sử dụng công cụ này.

### Đối với Edge

1. Mở trình duyệt Edge.
2. Truy cập Microsoft Edge Add-ons Store.
3. Tìm "React Developer Tools" và nhấn nút "Get" để cài đặt tiện ích mở rộng.
4. Khi cài đặt xong, bạn sẽ thấy biểu tượng React Developer Tools xuất hiện trên thanh công cụ của Edge.
5. Khi bạn truy cập một trang web React, mở Developer Tools và chuyển đến tab "Components" để sử dụng công cụ này.

## Bước 2: Cài đặt React Developer Tools cho Trình duyệt Khác

Nếu bạn đang sử dụng một trình duyệt khác như Safari hoặc muốn cài đặt React Developer Tools trực tiếp từ npm, hãy làm theo hướng dẫn sau:

### Cài đặt qua `npm`

1. Mở cửa sổ Terminal trên máy tính của bạn.
2. Sử dụng npm hoặc Yarn để cài đặt gói `react-devtools` toàn cục:

   ```shell
   # Yarn
   yarn global add react-devtools

   # npm
   npm install -g react-devtools
   ```

### Kết nối với trang web của bạn

1. Sau khi cài đặt xong, mở cửa sổ Terminal và chạy lệnh sau để khởi động React Developer Tools:

   ```shell
   react-devtools
   ```

2. Bây giờ, bạn cần kết nối trang web của mình với React Developer Tools. Để làm điều này, thêm đoạn mã sau vào phần `<head>` của trang web của bạn:

   ```html
   <html>
     <head>
       <script src="http://localhost:8097"></script>
     </head>
     <!-- Các phần khác của trang web -->
   </html>
   ```

3. Lưu lại và tải lại trang web của bạn trong trình duyệt. Trang web sẽ kết nối với React Developer Tools qua cổng 8097.

::alert{type="success"}
Việc cài đặt React Developer Tools là một bước quan trọng trong quá trình phát triển ứng dụng React của bạn. Nó giúp bạn dễ dàng kiểm tra và gỡ lỗi các thành phần React, theo dõi props và state, và xác định các vấn đề về hiệu suất. Hãy sử dụng công cụ này để nâng cao chất lượng và hiệu suất của ứng dụng React của bạn.
::
