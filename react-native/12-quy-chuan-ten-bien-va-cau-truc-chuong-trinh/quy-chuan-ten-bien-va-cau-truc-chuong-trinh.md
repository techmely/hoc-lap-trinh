---
title: "Quy chuẩn tên biến và cấu trúc chương trình"
description: "Khi bạn tìm hiểu được kha khá các vấn đề về React-Native và code được một vài chương trình đơn giản thì cũng là lúc chúng ta nên xem lại các quy chuẩn thiết kế, cũng như quy chuẩn về tên biến"
keywords:
  [
    "gioi thieu react native",
    "giới thiệu react native",
    "khoá học react native",
    "giới thiệu react native",
    "giới thiệu react native cơ bản",
    "react native la gi",
    "tong quan ve react native",
    "gioi thieu ve ngon ngu lap trinh react native",
    "tom tat react native",
    "code react native la gi",
  ]
chapter:
  name: "Quy chuẩn tên biến và cấu trúc chương trình"
  slug: "chuong-12-quy-chuan-ten-bien-va-cau-truc-chuong-trinh"
category:
  name: "React Native"
  slug: "react-native"
image: https://kungfutech.edu.vn/thumbnail.png
position: 12
---

Khi bạn tìm hiểu được kha khá các vấn đề về React-Native và code được một vài chương trình đơn giản thì cũng là lúc chúng ta nên xem lại các quy chuẩn thiết kế, cũng như quy chuẩn về tên biến để:

- Khi đọc lại bớt bỡ ngỡ (trước mình code cái gì vậy)
- Người khác đọc vào biết bạn đang làm gì?
- Có thể bạn khác join vào dự án biết cách sửa đổi.
- Làm dự án lớn nhiều người tham gia.
- ....

Mình xin dưa ra một số quy chuẩn cơ bản như sau:

## Tên biến và hàm

- **Một vài quy chuẩn tên biến mà mình cần tuân thủ như**:

  - Tên biến phải bắt đầu bằng ký tự viết thường.
  - Tên biến không được bắt đầu bằng số hoặc ký tự đặc biệt.
  - Những chữ cái đầu của mỗi từ đều viết hoa.
  - Tên biến phải mang ý nghĩa rõ ràng.
  - Nếu là style thì nên thêm viết tắt của view ở phía trước

- **Một vài ví dụ về tên biến**:

  - maxNumber
  - minNumber
  - textMessageAnswer
  - btnActionAgree
  - ....

- **Một vài quy chuẩn tên hàm**:

  - Tên hàm cũng bắt đầu bằng ký tự viết thường.
  - Tên hàm không chứa các ký tự đặc biệt.
  - Những chữ cái đầu của mỗi từ đều viết hoa.
  - Tên hàm phải mang ý nghĩa rõ ràng và thể hiện được chức năng của hàm.

- **Một vài ví dụ về tên hàm**:

  - findMinOfTowNumber(firstNumber, secondNumeber){}
  - onPressBtnLanguage(){}
  - onPressNegativeAction(){}
  - ....

## Cấu trúc chương trình

Sau những dự án và tìm hiểu trên mạng. Mình có đưa ra mô hình cấu trúc thư mục dự án như sau

Toàn bộ source code của chương trình sẽ được đặt trong thư mục app:

- **assets** là thư mục chứa resource của mình bao gồm các resource như custom font (fonts), hình ảnh (images), ngôn ngữ (languages)
- **configs** là thư mục chứa các cấu hình của ứng dụng: bao gồm các cấu hình server, link, màu sắc cơ bản.
- **libs** là thư mục chứa các thư viện cơ bản của mình để xử lý một số vấn đề nội bộ như:
  - **Database** (xử lý lưu trữ dữ liệu bằng database)
  - **Storage** (xử lý lưu trữ dữ liệu bằng storage)
  - **Language** (Cấu hình xử lý đa ngôn ngữ trong ứng dụng)
  - **RESTClient** (Cấu hình, danh sách các api truy cập hệ thống server)
  - **SoundPlayer** (Điều khiển âm thanh)
  - **Inapp** (Một vài cấu hình, xử lý thanh toán mua bán với store)
  - **Ads** (Cấu hình hiển thị quảng cáo từ bên thứ 3)
  - .....
- **models** là thư mục chứa các model do mình định nghĩa, có thể là định nghĩa các đối tượng hoặc các loại của đối tượng
- **modules** là thư mục chứa các module do mình định nghĩa hoặc tùy biến lại. Trong đó bao gồm:
  - **screens** - module chứa toàn bộ xử lý màn hình của ứng dụng
  - **views** - module chứa toàn bộ view đã được custom.
  - Và một số module mình muốn chỉnh sửa từ thư viện, thì có thể thêm vào đây để tùy biến.
