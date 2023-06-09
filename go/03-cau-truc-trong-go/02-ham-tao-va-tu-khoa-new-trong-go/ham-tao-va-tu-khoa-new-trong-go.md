---
title: "Hàm tạo và từ khoá new trong Go"
description: "Hàm tạo (Constructors) trong Go giới thiệu cách sử dụng hàm tạo trong Go thay vì sử dụng cấu trúc hàm tạo như trong các ngôn ngữ khác. Bài viết đề cập đến việc tạo ra một hàm trả về một biến với cấu trúc đã được định nghĩa trước, tương tự như một factory. Nó cung cấp ví dụ về cách tạo hàm tạo và sử dụng từ khóa new để cấp phát bộ nhớ cho một kiểu dữ liệu"
keywords:
  [
    "Hàm tạo trong Go",
    "Constructors Go",
    "Cấu trúc hàm tạo Go",
    "Factory trong Go",
    "Từ khóa New trong Go",
    "Sử dụng từ khóa New Go",
    "Hàm dựng sẵn New Go",
    "Cấp phát bộ nhớ trong Go",
    "Lập trình Go",
    "Ngôn ngữ lập trình Go",
  ]
chapter:
  name: "Cấu trúc trong Go"
  slug: "chuong-03-cau-truc-trong-go"
category:
  name: "Go"
  slug: "go"
image: https://kungfutech.edu.vn/thumbnail.png
position: 2
---

## Hàm tạo (Constructors) trong Go

Cấu trúc thì không có hàm tạo. Thay vào đó, bạn tạo một hàm trả về một biến với cấu trúc định nghĩa trước (giống như một factory):

```go
func NewSaiyan(name string, power int) *Saiyan {
  return &Saiyan{
    Name: name,
    Power: power,
  }
}
```

Rất nhiều lập trình viên mắc lỗi ở đây. Một mặt, có một chút thay đổi cú pháp; mặt khác, viết theo cách có ít sự khác biệt hơn.

`factory` không trả về một con trỏ, nhưng vẫn hoàn toàn hợp lệ:

```go
func NewSaiyan(name string, power int) Saiyan {
  return Saiyan{
    Name: name,
    Power: power,
  }
}
```

## Từ khoá `New` trong Go

Dù không có hàm tạo, Go vẫn có một hàm dựng sẵn `new` để cấp phát bộ nhớ cho một kiểu dữ liệu. Kết quả của `new(X)` giống như `&X{}`:

```go
goku := new(Saiyan)
// giống như
goku := &Saiyan{}
```

Bạn sử dụng cách nào thì tùy, nhưng bạn sẽ thấy đa phần người ta chọn cách sau khi họ có thể khởi tạo các trường dữ liệu, cũng như đoạn mã trở nên sáng sủa hơn:

```go
goku := new(Saiyan)
goku.name = "goku"
goku.power = 9001

//vs

goku := &Saiyan {
  name: "goku",
  power: 9000,
}
```

Dù bạn chọn cách nào, nếu bạn làm theo các mô hình factory ở trên, bạn có thể bảo vệ phần còn lại của mã của bạn khỏi lo ngại về vấn đề cấp phát bộ nhớ.
