---
title: "Mô hình MVC là gì?"
description: "MVC là viết tắt của cụm từ “Model-View-Controller“ - một mô hình kiến trúc phần mềm được tạo ra với mục đích quản lí và xây dựng dự án phần mềm có hệ thống hơn."
chapter:
  name: "Tổng quan về Spring"
  slug: "chuong-01-tong-quan-ve-spring"
image: https://kungfutech.edu.vn/thumbnail.png
position: 4
---

Mô hình MVC (Model-View-Controller) là một mô hình kiến trúc phần mềm giúp quản lý và xây dựng các dự án phần mềm một cách có hệ thống hơn. Hãy cùng tìm hiểu về mô hình này một cách dễ hiểu.

![Mô hình MVC là gì](https://github.com/techmely/hoc-lap-trinh/assets/29374426/ccf4b629-2efb-48e7-ac73-30ef550bb7cb)

## Định Nghĩa

MVC là viết tắt của ba thành phần chính trong kiến trúc này:

1. **Model:** Đại diện cho dữ liệu và logic của ứng dụng. Model thường chứa thông tin về các đối tượng và thực hiện các thao tác liên quan đến dữ liệu như truy xuất cơ sở dữ liệu.

2. **View:** Là phần hiển thị dữ liệu cho người dùng. View có nhiệm vụ nhận dữ liệu từ Model và hiển thị chúng theo cách thích hợp. Điều này bao gồm việc tạo giao diện người dùng và hiển thị dữ liệu trên đó.

3. **Controller:** Là thành phần trung gian giữa Model và View. Controller nhận yêu cầu từ người dùng thông qua giao diện (View), sau đó xử lý yêu cầu, tương tác với Model để truy xuất hoặc cập nhật dữ liệu, và sau đó trả kết quả về cho View để hiển thị cho người dùng.

![Mô hình MVC](https://github.com/techmely/hoc-lap-trinh/assets/29374426/4f3a0d22-eebe-49bd-bc32-9df03fe8ae6b)

## Luồng Công Việc trong Mô hình MVC

Hãy tưởng tượng một luồng công việc cơ bản trong mô hình MVC khi người dùng tương tác với ứng dụng:

1. Người dùng gửi yêu cầu từ máy client tới máy chủ.

2. Controller nhận yêu cầu và xử lý nó. Trong trường hợp cần, Controller có thể tương tác với Model để truy xuất hoặc cập nhật dữ liệu.

3. Controller sau đó chuẩn bị dữ liệu cần thiết và chuyển chúng đến View.

4. View nhận dữ liệu từ Controller và hiển thị nó theo cách thích hợp trên giao diện người dùng.

5. Kết quả cuối cùng được trả về cho người dùng qua máy client.

## Ưu và Nhược Điểm của Mô hình MVC

### Ưu Điểm của Mô hình MVC:

- **Kiểm tra Dễ Dàng:** Với MVC, bạn có thể kiểm tra và rà soát lỗi phần mềm trước khi đưa ra người dùng, đảm bảo chất lượng và độ tin cậy cao hơn.

- **Chức Năng Kiểm Soát:** Mô hình MVC cho phép bạn có quyền kiểm soát tốt hơn đối với các yếu tố quan trọng như giao diện, dữ liệu và logic ứng dụng.

- **Tích hợp dễ dàng:** Mô hình này cho phép tích hợp ứng dụng dễ dàng trên nền tảng web và giảm tải máy chủ.

- **Phân Tách Các Trách Nhiệm:** MVC phân tách rõ ràng các phần khác nhau của ứng dụng như Model, View và Controller, giúp dễ dàng quản lý và bảo trì mã nguồn.

### Nhược Điểm của Mô hình MVC:

- Mô hình này thường được ưa chuộng trong các dự án lớn, có thể gây cồng kềnh và tốn thời gian đối với các dự án nhỏ hơn.

## Ứng Dụng của Mô hình MVC

Mô hình MVC đã được ứng dụng rộng rãi trong lập trình phần mềm. Nó cho phép phát triển giao diện người dùng (front-end) và logic ứng dụng (back-end) độc lập mà không cần can thiệp, chia sẻ, hoặc chỉnh sửa các tập tin trong khi một hoặc hai bên vẫn đang làm việc. Mô hình MVC cung cấp tính kết hợp và quản lý mã nguồn dễ dàng, giúp ứng dụng phát triển một cách hiệu quả và bảo trì dễ dàng.
