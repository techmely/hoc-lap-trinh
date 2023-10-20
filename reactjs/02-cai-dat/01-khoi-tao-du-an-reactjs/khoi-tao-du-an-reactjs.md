---
title: "Khởi tạo dự án với ReactJs"
description: "Nếu bạn muốn xây dựng một ứng dụng hoặc trang web hoàn toàn bằng React, chúng tôi đề xuất bạn nên chọn một trong các framework sử dụng React phổ biến trong cộng đồng"
chapter:
  name: "Cài đặt"
  slug: "chuong-02-cai-dat-reactjs"
image: https://kungfutech.edu.vn/thumbnail.png
position: 1
---

Nếu bạn muốn xây dựng một ứng dụng hoặc trang web hoàn toàn bằng React, mình khuyên bạn nên chọn một trong các framework sử dụng React phổ biến trong cộng đồng. Các framework cung cấp các tính năng mà hầu hết các ứng dụng và trang web cần, bao gồm định tuyến (routing), truy xuất dữ liệu và tạo HTML...

::alert{type="warning"}
Bạn cần cài đặt Node.js để phát triển ứng dụng React.
::

## Các framework React phổ biến nhất

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

