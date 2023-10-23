---
title: "Cài đặt môi trường phát triển React"
description: "Việc cấu hình một trình soạn thảo đúng cách có thể giúp mã của bạn dễ đọc hơn và viết nhanh hơn. Nó còn có thể giúp bạn phát hiện lỗi khi bạn viết mã! Nếu đây là lần đầu bạn cài đặt một trình soạn thảo hoặc bạn đang muốn điều chỉnh trình soạn thảo hiện tại của mình, chúng tôi có một số khuyến nghị dưới đây"
chapter:
  name: "Cài đặt"
  slug: "chuong-02-cai-dat-reactjs"
image: https://kungfutech.edu.vn/thumbnail.png
position: 3
---

Dưới đây là những công cụ cần thiết để bạn phát triển ứng dụng Reactjs trên máy bạn

- Visual Studio Code (VS Code): Đây chắc chắn không phải là một yêu cầu để tạo các ứng dụng React, nhưng nó là một editor khá dễ sử dụng và hỗ trợ nhiều cho việc phát triển, việc sử dụng vscode sẽ làm cho công việc phát triển trở nên thú vị hơn nhiều.
- Node.js: Môi trường thời gian chạy JavaScript, facebook gợi ý rằng nên sử dụng phiên bản NodeJS mới nhất khi tạo các ứng dụng ReactJS
- npm: trình quản lý gói Node. Điều này được sử dụng cùng với Node để chúng ta có thể dễ dàng chia sẻ các mô-đun mã được đóng gói.

## Cài đặt các ứng dụng cần thiết phát triển ứng dụng React

### Cài đặt VS Code

Visual Studio Code (VSCode) là một trình soạn thảo mã nguồn mở và miễn phí được phát triển bởi Microsoft. Nó là một trong các môi trường phát triển tích hợp (IDE) phổ biến cho nhiều ngôn ngữ lập trình khác nhau và được sử dụng rộng rãi trong cộng đồng phát triển phần mềm. Dưới đây là một số điểm nổi bật và tính năng của Visual Studio Code:

1. **Mã nguồn mở và Miễn phí**: VSCode là một ứng dụng mã nguồn mở và hoàn toàn miễn phí. Bạn có thể tải và sử dụng nó mà không phải trả tiền.
2. **Hỗ trợ nhiều ngôn ngữ lập trình**: VSCode hỗ trợ nhiều ngôn ngữ lập trình khác nhau, bao gồm JavaScript, Python, Ruby, C++, Java, và nhiều ngôn ngữ khác. Bạn có thể cài đặt các tiện ích mở rộng (extensions) để mở rộng khả năng hỗ trợ ngôn ngữ.
3. **Khả năng mở rộng**: VSCode có một cộng đồng sáng tạo và phong phú, cho phép bạn cài đặt và tạo các tiện ích mở rộng (extensions) để mở rộng tính năng của trình soạn thảo. Có hàng ngàn tiện ích mở rộng có sẵn cho các mục đích khác nhau.
4. **Debugging tích hợp**: VSCode có khả năng debugging tích hợp cho nhiều ngôn ngữ lập trình. Bạn có thể tạo và quản lý các điểm dừng (breakpoints) và xem giá trị biến trong quá trình chạy mã.
5. **Git Integration**: VSCode tích hợp sâu với Git, giúp bạn quản lý phiên bản mã nguồn dễ dàng, theo dõi thay đổi và commit.
6. **Autocompletion**: VSCode cung cấp khả năng tự động hoàn thành mã (autocompletion) để giúp bạn viết mã nhanh hơn và tránh sai sót cú pháp.
7. **Làm việc trên nhiều hệ điều hành**: VSCode có phiên bản cho Windows, macOS và Linux, giúp bạn làm việc trên nhiều hệ điều hành khác nhau mà không cần thay đổi quá nhiều.
8. **Hỗ trợ Terminal tích hợp**: Bạn có thể mở terminal trực tiếp trong VSCode, giúp bạn thực hiện các lệnh hệ thống và quản lý dự án một cách dễ dàng.
9. **Cộng đồng lớn và sự phát triển liên tục**: VSCode có một cộng đồng đông đảo, và Microsoft liên tục cập nhật và cải tiến ứng dụng, đảm bảo tính ổn định và tính năng mới.

Visual Studio Code là một công cụ phát triển mạnh mẽ và đa năng, phù hợp cho lập trình viên ở nhiều mức độ và cho nhiều loại dự án phát triển phần mềm.

Bạn có thể tải VSCode [tại đây](https://code.visualstudio.com/)

### Cài đặt NodeJS

Node.js là một môi trường chạy mã JavaScript phía máy chủ, được xây dựng trên JavaScript Engine V8 của Google Chrome. Nó cho phép bạn thực hiện mã JavaScript không chỉ trên trình duyệt mà còn trên máy chủ, mở ra nhiều cơ hội trong việc phát triển ứng dụng web và dự án phía máy chủ.

Để cài đặt Node.js, bạn có thể làm theo các bước sau:

1. **Truy cập trang web chính thức của Node.js**: Điều này giúp bạn tải xuống phiên bản mới nhất của Node.js. Trang web chính thức là [https://nodejs.org/](https://nodejs.org/).
2. **Tải xuống Node.js**: Tại trang web chính thức, bạn sẽ thấy hai phiên bản Node.js: LTS (Long-Term Support) và Current. Đối với mục đích học React, bạn nên chọn phiên bản LTS, nó ổn định và hỗ trợ lâu dài.
3. **Cài đặt Node.js**: Sau khi tải xuống, mở tệp tải về và làm theo hướng dẫn để cài đặt Node.js. Quá trình cài đặt sẽ cài đặt cả Node.js và npm (Node Package Manager).
4. **Kiểm tra cài đặt**: Mở cửa sổ dòng lệnh (Command Prompt hoặc Terminal) và chạy các lệnh sau để kiểm tra xem Node.js và npm đã được cài đặt đúng cách:

   ```shell
   node -v
   npm -v
   ```

   Nếu bạn nhìn thấy phiên bản của Node.js và npm xuất hiện, thì việc cài đặt đã hoàn tất.

Sau khi đã cài đặt Node.js, bạn có thể bắt đầu học React bằng cách tạo dự án React bằng Create React App (CRA), một công cụ tạo dự án React phổ biến.


## Một số tính năng trên trình soạn thảo bạn nên sử dụng

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
