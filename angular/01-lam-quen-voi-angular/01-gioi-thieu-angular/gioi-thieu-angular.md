---
title: "Giới thiệu Angular"
description: "JAngular là một javascript framework do google phát triển để xây dựng các Single Page Application (SPA) bằng JavaScript , HTML và TypeScript"
keywords:
  [
    "gioi thieu angular",
    "giới thiệu angular",
    "khoá học angular",
    "giới thiệu angular",
    "giới thiệu angular cơ bản",
    "angular la gi",
    "tong quan ve angular",
    "gioi thieu ve ngon ngu lap trinh angular",
    "tom tat angular",
    "code angular la gi",
  ]
chapter:
  name: "Làm quen với angular"
  slug: "01-lam-quen-voi-angular"
category:
  name: "Angular"
  slug: "angular"
image: https://kungfutech.edu.vn/thumbnail.png
position: 1
---

## Giới thiệu angular

Trong vài năm trở lại đây, Angular đã có nhiều cải tiến mới, cả về feature và performance. Càng ngày càng có nhiều công ty/tổ chức, dự án sử dụng Angular để phát triển các sản phẩm giàu tính tương tác. Angular là một javascript framework do google phát triển để xây dựng các Single Page Application (SPA) bằng JavaScript , HTML và TypeScript . Angular cung cấp các tính năng tích hợp cho animation , http service và có các tính năng như auto-complete , navigation , toolbar , menus ,… Code được viết bằng TypeScript , biên dịch thành JavaScript và hiển thị tương tự trong trình duyệt.

Để học được angular thì bạn cần biết các kiển thức cơ bản sau:

- HTML
- CSS
- JavaScript
- TypeScript
- Document Object Model (DOM)

## Trong Angular có gì?

Angular – ứng dụng là một tập hợp những component (thành phần) và một vài services (dịch vụ) cung cấp chức năng trên những component đó.

Công thức cấu thành Angular có thể hiểu đơn giản như sau:

**Angular Application = Component + Component + Component … + services**

Trong đó: Component = Template + Class + Metadata

- `Component` bao gồm một mẫu HTML render ra một “frame” giao diện người dùng.
- `Class` code những gì liên kết với view. Những thuộc tính, những phần tử dữ liệu có sẵn để phục vụ cho các view và các phương thức thực hiện những hành động cho view sẽ được ghi đầy đủ trong class.
- Đồng thời, component cũng có metadata. Nhiệm vụ của chúng là cung cấp thêm những thông tin của component cho Angular. Metadata này để xác định Class là một Angular component.

## Những tính năng nổi bật của Angular

### Cơ chế Two-Way Data Binding

Đây là tính năng được developer đánh giá là ấn tượng nhất của Angular. Data binding tự động, tức thời. Bất cứ thay đổi nào trên view, dù là nhỏ nhất, cũng đều được tự động cập nhật thuộc tính “model” vào component class và ngược lại.

Thêm vào đó, Angular cũng hỗ trợ property binding. Developer có thể ràng buộc thuộc tính HTML với thuộc tính của component class, data sẽ tự động xuất hiện bên trong view thông qua việc điều khiển DOM.

### Hỗ trợ cơ chế Routing (điều hướng) mạnh mẽ

Angular có cơ chế routing tải trang một cách bất đồng bộ trên cùng một trang cho phép chúng ta tạo SPA.

Đa số các ứng dụng Web không chỉ có 1 view hay một page duy nhất, mà sẽ cung cấp nhiều view khác nhau tương ứng với với các chức năng chính. Ví dụ: các trang liên hệ, giới thiệu chung, nội dung, báo giá, … trong một website. Hiển thị đúng view vào đúng thời điểm là mục đích của điều hướng (routing).

Angular giúp định nghĩa các đường dẫn (route) cho mỗi page view của ứng dụng. Developer sẽ kích hoạt route dựa trên tương tác của người dùng (user).

### Mở rộng HTML

Nhờ Angular, developer có thể sử dụng cấu trúc lập trình giống như điều kiện IF, vòng lặp FOR, những biến địa phương “local variables”, …để render các control.

### Thiết kế module hoá

Angular tiếp cận theo hướng thiết kế module hoá. Người dùng phải tạo các Angular Module để tổ chức tốt hơn và quản lý source code.

### Hỗ trợ làm việc với hệ thống Backend

Hỗ trợ làm việc với backend server, thực thi bất cứ logic nào và nhận dữ liệu về – Angular được xây dựng như thế!

### Cộng đồng hỗ trợ rộng lớn

- Nhiều tài liệu phong phú, đa dạng từ cơ bản đến nâng cao các API của Angular, cũng như có hẳn một Tutorial Basic được xây dựng nên bởi Angular team.
- Mã nguồn mở.
- Được Google hỗ trợ, liên tục cập nhật
