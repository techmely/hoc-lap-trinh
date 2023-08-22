---
title: "Postman là gì?"
description: "Là một công cụ cho phép chúng ta thao tác với API, phổ biến nhất là REST."
chapter:
  name: "Web Service RESTFull"
  slug: "chuong-08-web-service-RESTFull"
category:
  name: "SpringBoots"
  slug: "springboots"
image: https://kungfutech.edu.vn/thumbnail.png
position: 4
---

## Giới thiệu POSTMAN

### Postman là gì?

Postman là một công cụ cho phép chúng ta thao tác với API, phổ biến nhất là REST. Postman hiện là một trong những công cụ phổ biến nhất được sử dụng trong thử nghiệm các API. Với Postman, ta có thể gọi Rest API mà không cần viết dòng code nào.

Postman hỗ trợ tất cả các phương thức HTTP (GET, POST, PUT, PATCH, DELETE, …). Bên cạnh đó, nó còn cho phép lưu lại lịch sử các lần request, rất tiện cho việc sử dụng lại khi cần.

### Tại sao sử dụng Postman?

Những lợi ích khi sử dụng Postman:

- Sử dụng Collections (Bộ sưu tập)
- Postman cho phép người dùng tạo bộ sưu tập cho các lệnh gọi API của họ. Mỗi bộ sưu tập có thể tạo các thư mục con và nhiều yêu cầu (request). Điều này giúp việc tổ chức các bộ thử nghiệm.
- Collaboration – Collections và environment có thể được import hoặc export giúp chia sẻ tệp dễ dàng.
- API Testing – Test trạng thái phản hồi HTTP.
- Gỡ lỗi – Bảng điều khiển Postman giúp kiểm tra dữ liệu nào đã được truy xuất giúp dễ dàng gỡ lỗi kiểm tra.

### Cách sử dụng Postman

#### Các chức năng cơ bản

- Cho phép gửi HTTP Request với các method GET, POST, PUT, DELETE.
- Cho phép post dữ liệu dưới dạng form (key-value), text, json.
- Hiện kết quả trả về dạng text, hình ảnh, XML, JSON.
- Hỗ trợ authorization (Oauth1, 2).
- Cho phép thay đổi header của các request.

#### Giao diện POSTMAN

![giaodien-post-man](https://github.com/techmely/hoc-lap-trinh/assets/29374426/e199b218-96bb-49c5-9fca-f47da06ccff1)

Việc sử dụng Postman rất đơn giản. Bạn chỉ cần chọn method, điền URL, thêm các thông tin cho body, header trong những trường hợp cần thiết, rồi nhấn SEND. Việc của bạn là đợi và Postman sẽ cho bạn kết quả trả về nó có hình thù như thế nào.

### Những chức năng phần mềm chính

- New: Là nơi cho phép bạn tạo request, enviroment mới hoặc collection.
- Import: Được sử dụng nhằm import collection hoặc environment. Một số tùy chọn còn được dùng để import từ file folder, paste từ text thuần hoặc link
- Open new: Dùng để mở một tab mới, cửa sổ postman hoặc cửa sổ runner bằng việc kích nút này.
- Runner: Nhằm kiểm tra tự động hóa giúp thực hiện thông qua Runner cả collection.
- My workspace: Tạo cửa sổ làm việc riêng hoặc dành cho một nhóm.
- Invite: Làm việc và cộng tác với nhiều thành viên hơn bằng cách mời các thành viên.
- History: Những request mà bạn đã thực hiện sẽ hiển thị ở mục history. Từ đó, bạn hoàn toàn có thể lần theo hành động đã làm từ trước.
- Collections: Nhằm tổ chức các thử nghiệm bằng cách tạo collection. Mỗi một collection sẽ có thư mục con với nhiều yêu cầu có thể là request hoặc thư mục trùng lặp.
- Tab request: giúp hiển thị tiêu đề request mà bạn làm việc. Nó sẽ mặc định “untitled Request và hiển thị cho những request không có tiêu đề khác.
- Request URL: hay còn gọi là điểm cuối, nó là nơi giúp bạn xác định liên kết đến nơi mà API sẽ giao tiếp.
- HTTP Request: Khi click vào đây thì danh sách hiển thị sẽ được thả xuống với những request khác. Chúng có thể là: post, copy, get, delete,...
- Save: Nếu như thay đổi với request bạn chỉ cần nhấp vào save để các thay đổi được lưu và không bị ghi đè.
- Params: Giúp bạn vẽ những tham số cần thiết cho một request.
- Headers: Bạn có thể tiến hành thiết lập các header như nội dung JSON tùy theo cách tổ chức của bản thân.
- Body: Cho phép chúng ta tùy chỉnh các chi tiết trong request và thường được dùng nhiều trong request Post.
- Tests: Là những script được thực hiện khi thực hiện request. Tuy nhiên, cần phải có các thử nghiệm như thiết lập điểm checkpoint nhằm kiểm tra trạng thái. Khi đó, dữ liệu nhận được sẽ như mong đợi và sở hữu các thử nghiệm khác.
- Pre-request script: Các tập lệnh sẽ được thực thi trước request. Đa phần chúng sẽ cho môi trường được sử dụng để đảm bảo cho các kiểm tra và được chạy ở trong môi trường chính xác nhất.
