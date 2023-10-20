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
Bạn cần cài đặt Node.js để phát triển ứng dụng React cục bộ.
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

Remix là một framework React toàn diện với định tuyến lồng nhau. Nó cho phép bạn chia ứng dụng thành các phần lồng nhau có thể tải dữ liệu song song và làm mới dựa trên hành động của người dùng. Để tạo dự án Remix mới, hãy chạy lệnh sau:

```shell
npx create-remix
```

Nếu bạn mới làm quen với Remix, hãy xem hướng dẫn blog Remix (ngắn) và hướng dẫn ứng dụng Remix (dài).

Remix được duy trì bởi Shopify. Khi bạn tạo dự án Remix, bạn cần chọn mục tiêu triển khai của mình. Bạn có thể triển khai ứng dụng Remix lên bất kỳ máy chủ Node.js hoặc dịch vụ serverless nào bằng cách sử dụng hoặc viết một adapter.

### Gatsby

Gatsby là một framework React cho các trang web nhanh hỗ trợ bởi hệ thống quản lý nội dung (CMS). Hệ sinh thái plugin đa dạng và lớp dữ liệu GraphQL của nó giúp đơn giản hóa việc tích hợp nội dung, API và dịch vụ vào một trang web duy nhất. Để tạo dự án Gatsby mới, hãy chạy lệnh sau:

```shell
npx create-gatsby
```

Nếu bạn mới làm quen với Gatsby, hãy xem hướng dẫn Gatsby.

Gatsby được duy trì bởi Netlify. Bạn có thể triển khai một trang web Gatsby hoàn toàn tĩnh lên bất kỳ dịch vụ hosting tĩnh nào. Nếu bạn chọn sử dụng các tính năng chỉ chạy trên máy chủ, hãy đảm bảo nhà cung cấp hosting của bạn hỗ trợ chúng cho Gatsby.

### Expo (dành cho ứng dụng di động)

Expo là một framework React cho phép bạn tạo ứng dụng Android, iOS và web có giao diện người dùng thực sự native. Nó cung cấp một SDK cho React Native giúp việc sử dụng các phần native dễ dàng hơn. Để tạo dự án Expo mới, hãy chạy lệnh sau:

```shell
npx create-expo-app
```

Nếu bạn mới làm quen với Expo, hãy xem hướng dẫn Expo.

Expo được duy trì bởi Expo (công ty). Xây dựng ứng dụng với Expo là miễn phí và bạn có thể đăng ký chúng lên cửa hàng ứng dụng Google và Apple mà không bị hạn chế. Expo cung cấp thêm các dịch vụ đám mây có thể chọn tham gia với phí.

## Tiếp tục khám phá

**Có thể sử dụng React mà không cần một framework không?**
React ngày càng tiến xa hơn trong việc tích hợp chặt chẽ với các framework (cụ thể là định tuyến, đóng gói và công nghệ máy chủ). Điều này là cơ hội lớn nhất để giúp người dùng React xây dựng các ứng dụng tốt hơn. Nhóm Next.js đã đồng ý hợp tác với chúng tôi để nghiên cứu, phát triển, tích hợp và thử nghiệm các tính năng React bleeding-edge (như React Server Components) không phụ thuộc vào framework.

Các tính năng này ngày càng tiến gần đến việc sẵn sàng cho sản xuất hàng ngày và chúng tôi đã thảo luận với các nhà phát triển bundler và framework khác về việc tích hợp chúng. Hi vọng rằng trong một hoặc hai năm tới, tất cả các framework được liệt kê trên trang này sẽ có sự hỗ trợ đầy đủ cho các tính năng này. (Nếu bạn là một tác giả framework quan tâm đến việc hợp tác với chúng tôi để thử nghiệm các tính năng này, hãy cho chúng tôi biết!)

**Next.js (App Router)**
Next.js's App Router là một phiên bản mới thiết kế lại của các API Next.js nhằm mục tiêu hoàn thành tầm nhìn kiến trúc full-stack của nhóm React. Nó cho phép bạn truy xuất dữ liệu trong các thành phần bất đồng bộ chạy trên máy chủ hoặc thậm chí trong quá trình xây dựng.

Next.js được duy trì bởi Vercel. Bạn có thể triển khai ứng dụng Next.js lên bất kỳ máy chủ Node.js hoặc dịch vụ serverless nào, hoặc máy chủ của bạn. Next.js cũng hỗ trợ xuất tĩnh mà không yêu cầu máy chủ.
