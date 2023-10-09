---
title: "Cài đặt trình soạn thảo cho React"
description: "Việc cấu hình một trình soạn thảo đúng cách có thể giúp mã của bạn dễ đọc hơn và viết nhanh hơn. Nó còn có thể giúp bạn phát hiện lỗi khi bạn viết mã! Nếu đây là lần đầu bạn cài đặt một trình soạn thảo hoặc bạn đang muốn điều chỉnh trình soạn thảo hiện tại của mình, chúng tôi có một số khuyến nghị dưới đây"
chapter:
  name: "Cài đặt"
  slug: "chuong-02-cai-dat-reactjs"
image: https://kungfutech.edu.vn/thumbnail.png
position: 3
---

Việc cấu hình một trình soạn thảo đúng cách có thể giúp mã của bạn dễ đọc hơn và viết nhanh hơn. Nó còn có thể giúp bạn phát hiện lỗi khi bạn viết mã! Nếu đây là lần đầu bạn cài đặt một trình soạn thảo hoặc bạn đang muốn điều chỉnh trình soạn thảo hiện tại của mình, chúng tôi có một số khuyến nghị dưới đây.

## Những gì bạn sẽ học

1. Các trình soạn thảo phổ biến nhất là gì?
2. Làm thế nào để tự động định dạng mã của bạn.

## Trình soạn thảo của bạn

VS Code là một trong những trình soạn thảo phổ biến nhất được sử dụng ngày nay. Nó có một thị trường lớn về các tiện ích mở rộng và tích hợp tốt với các dịch vụ phổ biến như GitHub. Hầu hết các tính năng được liệt kê dưới đây có thể được thêm vào VS Code dưới dạng các tiện ích mở rộng, giúp nó trở nên có khả năng tùy chỉnh cao!

Các trình soạn thảo văn bản phổ biến khác được sử dụng trong cộng đồng React bao gồm:

1. WebStorm là một môi trường phát triển tích hợp được thiết kế đặc biệt cho JavaScript.
2. Sublime Text hỗ trợ JSX và TypeScript, có sẵn tô đậm cú pháp và tự động hoàn thiện.
3. Vim là một trình soạn thảo văn bản có thể tùy chỉnh mạnh mẽ được thiết kế để tạo và thay đổi bất kỳ loại văn bản nào một cách hiệu quả. Nó được bao gồm dưới dạng "vi" trong hầu hết các hệ thống UNIX và trên Apple OS X.

## Các tính năng trình soạn thảo được khuyến nghị

Một số trình soạn thảo có sẵn những tính năng này sẵn có, nhưng một số khác có thể yêu cầu thêm tiện ích mở rộng. Hãy kiểm tra xem trình soạn thảo bạn chọn hỗ trợ những tính năng nào!

### Kiểm tra lỗi (Linting)

Các công cụ kiểm tra mã sẽ tìm ra các vấn đề trong mã của bạn khi bạn viết, giúp bạn sửa chúng sớm. ESLint là một công cụ kiểm tra mã phổ biến và mã nguồn mở cho JavaScript.

Hãy cài đặt ESLint với cấu hình được khuyến nghị cho React (hãy chắc chắn bạn đã cài đặt Node!)

1. Cài đặt ESLint:

   ```shell
   npm install eslint --save-dev
   ```

2. Cài đặt cấu hình cho React:

   ```shell
   npx eslint --init
   ```

3. Integrate ESLint trong VSCode với tiện ích mở rộng chính thức.

4. Đảm bảo bạn đã bật tất cả các quy tắc của eslint-plugin-react-hooks cho dự án của bạn. Chúng quan trọng và giúp phát hiện các lỗi nghiêm trọng nhất sớm. Cấu hình gợi ý eslint-config-react-app đã bao gồm chúng.

### Định dạng mã (Formatting)

Điều cuối cùng bạn muốn khi chia sẻ mã với người đóng góp khác là rơi vào cuộc thảo luận về tab hoặc khoảng trắng! May mắn thay, Prettier sẽ làm cho mã của bạn trở nên đẹp hơn bằng cách định dạng nó để tuân thủ các quy tắc được cấu hình trước đó. Chạy Prettier, và tất cả tab của bạn sẽ được chuyển thành khoảng trắng - và định dạng, dấu ngoặc kép, v.v. cũng sẽ được thay đổi để tuân thủ cấu hình. Trong thiết lập lý tưởng, Prettier sẽ chạy khi bạn lưu tệp, nhanh chóng thực hiện những chỉnh sửa này cho bạn.

Bạn có thể cài đặt tiện ích mở rộng Prettier trong VSCode bằng cách thực hiện các bước sau:

1. Khởi động VS Code.
2. Sử dụng Quick Open (nhấn `Ctrl/Cmd+P`).
3. Dán `ext install esbenp.prettier-vscode` vào ô tìm kiếm.
4. Nhấn Enter để cài đặt.

### Định dạng tự động khi lưu (Formatting on Save)

Lý tưởng, bạn nên định dạng mã của bạn mỗi khi lưu. VS Code có các thiết lập cho điều này!

1. Trong VS Code, nhấn `CTRL/CMD + SHIFT + P`.
2. Gõ "settings".
3. Nhấn `Enter`.
4. Trong thanh tìm kiếm, gõ "format on save".
5. Hãy chắc chắn rằng tùy chọn "format on save" đã được chọn!
