---
title: "Con trỏ và giá trị trong Go"
description: "Bài viết này tóm tắt về sử dụng con trỏ và giá trị trong Go. Nó giải thích các tình huống khi nào nên sử dụng giá trị và khi nào thì sử dụng con trỏ. Nếu không chắc chắn, sử dụng con trỏ để thay đổi dữ liệu. Bài viết cũng đề cập đến việc truyền giá trị cho hàm và chi phí sao chép cấu trúc. Cuối cùng, nó giới thiệu cấu trúc, tạo receiver cho hàm và kiểu dữ liệu con trỏ trong Go."
keywords:
  [
    "con trỏ",
    "giá trị",
    "Go",
    "sử dụng con trỏ",
    "sử dụng giá trị",
    "hàm trong Go",
    "cấu trúc Go",
    "receiver",
    "kiểu dữ liệu con trỏ",
    "truyền giá trị",
  ]
chapter:
  name: "Cấu trúc trong Go"
  slug: "chuong-03-cau-truc-trong-go"
category:
  name: "Go"
  slug: "go"
image: https://kungfutech.edu.vn/thumbnail.png
position: 4
---

## Con trỏ và giá trị

Khi viết mã Go, bạn có thể sẽ tự hỏi _khi nào nên dùng giá trị, khi nào thì dùng con trỏ?_ Trước hết, câu trả lời là giống nhau, trừ một trong các tình huống sau:

- Gán một biến cục bộ
- Thay đổi trường của một cấu trúc
- Giá trị trả về của một hàm
- Tham số của một hàm
- receiver của một phương thức

Sau đó, nếu bạn vẫn không chắc chắn, hãy dùng con trỏ.

Như chúng ta thấy, truyền một giá trị cho hàm là cách để giá trị đó không thay đổi được (các thay đổi bên trong hàm sẽ không làm thay đổi đến các giá trị bên ngoài hàm). Đôi khi, cách xử lý này là cách mà bạn muốn.

Thậm chí nếu bạn không muốn thay đổi dữ liệu, hãy xem xét chi phí để tạo một bản sao của một cấu trúc lớn. Ngược lại, bạn có các cấu trúc nhỏ, ví dụ:

```go
type Point struct {
  X int
  Y int
}
```

Trong trường hợp này, chi phí của việc sao chép cấu trúc là có thể bù đắp được bằng việc có thể truy cập `x` và `y` trực tiếp.

Một lần nữa, đây là tất cả các tình huống khá tinh tế. Bạn sẽ quen với điều này nếu trải nghiệm hàng nghìn hoặc hàng chục nghìn tình huống tương tự.

<content-warning>

Tóm lại, chương này giới thiệu các cấu trúc, làm thế nào để tạo một receiver cho một hàm, và chúng ta biết thêm được kiểu dữ liệu con trỏ trong Go. Các chương sau sẽ xây dựng trên những gì chúng ta biết về cấu trúc cũng như các hoạt động bên trong mà chúng ta đã tìm hiểu.

</content-warning>
