---
title: "Sử dụng Typescript cho React"
description: "TypeScript là một cách phổ biến để thêm các định nghĩa kiểu cho các dự án mã JavaScript, bài này chúng ta sẽ cùng nhau tìm hiểu về typescript và cách sử dụng typescript cho React"
chapter:
  name: "Cài đặt"
  slug: "chuong-02-cai-dat-reactjs"
image: https://kungfutech.edu.vn/thumbnail.png
position: 4
---

TypeScript là một cách phổ biến để thêm các định nghĩa kiểu cho các dự án mã JavaScript, bài này chúng ta sẽ cùng nhau tìm hiểu về typescript và cách sử dụng typescript cho React

![image](https://github.com/techmely/hoc-lap-trinh/assets/29374426/8e060b96-bfb5-4b70-867d-3f48292458ab)


## Tổng quan về Typecript

Typecript do Microsoft phát triển ,nó là 1 mã nguồn mở cho lập trình viên phát triển. Là hàng của ông lớn, nên chắc chắn nó phải xịn và được nhiều lập trình viên đón nhận.

Những điểm mạnh của typecript:

- Kế thừa các cú pháp từ javascript nên rất dễ sử dụng hơn các mã nguồn tương tự
- Ngoài kế thừa từ các phiên bản javascript, nó càng hỗ trợ các cú pháp đặc trưng của hướng đối tượng như interface, class,vv nên rất mạnh mẽ khi apply các design pattern.
- Được các lib/framework khuyến khích sử dụng(vì bản thân nó cũng được dần chuyển qua viết bằng typescirpt)
- Những dự án lớn thành công cũng đã áp dụng typescript
- Một điều nữa là nó hỗ trợ rất tốt khi dùng 1 công cụ là visual code (hàng của microsoft) được nhiều ae frontend sử dụng, hỗ trợ suggest code và báo lỗi cực mạnh khi dùng typescirpt trong công cụ này

Hình dưới đây là các tool hỗ trợ typescipt

![Tổng quan về Typecript](https://github.com/techmely/hoc-lap-trinh/assets/29374426/d80b55af-e450-47b5-9460-dde2efe89be2)

## Lợi ích của việc sử dụng Typescript với React

Bạn vẫn có thể tự hỏi, "nhưng tại sao tôi nên sử dụng Typecript cho một dự án React.js?" . Hãy phân tích các lợi ích của Typescript và chỉ ra cách nó giúp cho việc phát triển frontend React dễ dàng hơn.

- **Gợi ý mã**: Loại chỉ định cung cấp các đề xuất và tùy chọn trong khi bạn nhập. Điều này giúp tiết kiệm rất nhiều công sức và giúp một nhà phát triển mới sử dụng mã nguồn của bạn dễ dàng hơn. Các đề xuất mã này ngăn chặn thời gian lãng phí, dễ dàng giao tiếp nhóm và làm cho cơ sở mã của bạn nhất quán hơn.
- **Khả năng đọc và xác thực**: Vì Typecript là một hệ thống được định kiểu tĩnh, bạn có thể thêm các kiểu vào các biến, hàm và thuộc tính, làm cho mã của bạn dễ đọc hơn rất nhiều. Typecript cũng dùng để loại bỏ PropTypes của React, điều này giúp cho việc phát triển React dễ dàng hơn.
- **Bắt lỗi sớm hơn và IntelliSense**: Một trong những tính năng được yêu thích nhất của Typescript là khả năng đánh dấu lỗi ngay khi chúng xuất hiện. Typecript hiển thị cho bạn các lỗi trước khi bạn chạy mã, tiết kiệm hàng giờ đồng hồ để sửa lỗi hoặc nhầm lẫn sớm.
- **Duy trì và tái cấu trúc mã chính xác**: Khi cơ sở mã của một ứng dụng React phát triển, nó có thể trở nên quá khó khăn để đọc, chia sẻ hoặc duy trì. Việc điều hướng các cơ sở mã này có thể tẻ nhạt và việc cấu trúc lại mã rất rủi ro. Typecript thực sự giúp bạn cấu trúc lại mã và ngăn lỗi chính tả, giúp việc duy trì và cập nhật dễ dàng hơn nhiều mà không thay đổi bất kỳ hành vi nào của nó.
- **Cải thiện việc sử dụng JavaScript**: Typescript tích hợp hoàn toàn với JavaScript và sử dụng các tính năng mới nhất có sẵn cho nhà phát triển JavaScript. Các dự án React được xây dựng bằng biên dịch Typecript thành một phiên bản JavaScript chạy trên bất kỳ trình duyệt nào.

## Hướng dẫn tạo dự án ReactJS mới sử dụng TypeScript

Trước hết, bạn cần cài đặt Node.js và npm (Node Package Manager) trên máy tính của mình. Sau khi đã cài đặt thành công Node.js và npm, bạn có thể bắt đầu tạo một dự án ReactJS mới sử dụng TypeScript.

### Bước 1: Tạo dự án ReactJS mới với Create React App

Create React App là một công cụ giúp bạn nhanh chóng tạo dự án ReactJS với cấu hình mặc định. Để tạo dự án mới, mở terminal và thực hiện lệnh sau:

```bash
npx create-react-app ten-du-an --template typescript
```

- `ten-du-an` là tên dự án của bạn. Bạn có thể thay thế nó bằng tên dự án mong muốn.

Lệnh trên sẽ tạo một thư mục mới với tên dự án của bạn và cấu hình sẵn TypeScript cho dự án ReactJS.

### Bước 2: Khám phá dự án

Sau khi tạo dự án, hãy di chuyển vào thư mục dự án:

```bash
cd ten-du-an
```

Trong thư mục này, bạn sẽ thấy cấu trúc dự án ReactJS chuẩn với TypeScript đã được thiết lập sẵn. Bạn có thể bắt đầu phát triển ứng dụng của mình trong các thư mục và tệp tin tương ứng.

### Bước 3: Chạy ứng dụng

Để chạy ứng dụng ReactJS, sử dụng lệnh sau:

```bash
npm start
```

Ứng dụng sẽ khởi động và mở trình duyệt mặc định của bạn, hiển thị ứng dụng ReactJS của bạn tại địa chỉ `http://localhost:3000`.

## Hướng dẫn thêm TypeScript vào dự án ReactJS hiện có

Nếu bạn đã có một dự án ReactJS và muốn thêm TypeScript vào nó, bạn có thể thực hiện các bước sau:

### Bước 1: Cài đặt TypeScript

Trước hết, bạn cần cài đặt TypeScript bằng lệnh:

```bash
npm install --save typescript @types/node @types/react @types/react-dom @types/jest
```

### Bước 2: Tạo tệp `tsconfig.json`

Sau khi cài đặt TypeScript, bạn cần tạo một tệp `tsconfig.json` để cấu hình TypeScript cho dự án. Sử dụng lệnh sau:

```bash
npx tsc --init
```

### Bước 3: Đổi tên tệp JS sang TS

Hãy đảm bảo rằng bạn đổi tên các tệp JavaScript hiện có trong dự án thành các tệp TypeScript bằng cách đổi đuôi tệp `.js` thành `.tsx`.

### Bước 4: Chỉnh sửa tệp `tsconfig.json`

Mở tệp `tsconfig.json` và chỉnh sửa các tùy chọn cấu hình theo nhu cầu của bạn, ví dụ:

```json
{
  "compilerOptions": {
    "target": "es5",
    "module": "commonjs",
    "strict": true,
    "jsx": "react",
    "esModuleInterop": true,
    "skipLibCheck": true,
    "forceConsistentCasingInFileNames": true
  }
}
```

### Bước 5: Chạy dự án

Sử dụng lệnh để chạy dự án:

```bash
npm start
```

Với các bước trên, bạn đã thêm TypeScript vào dự án ReactJS hiện có và có thể bắt đầu viết mã TypeScript trong dự án của mình.

::alert{type="success"}
Bài này đã giới thiệu các cơ bản của việc sử dụng TypeScript với React, nhưng còn rất nhiều thứ để học.
::
