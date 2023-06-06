---
title: "Khai báo hàm trong Go"
description: "Một hàm có thể trả về một hoặc nhiều giá trị, và bài viết đưa ra ba ví dụ cụ thể: một hàm không có giá trị trả về, một hàm trả về một giá trị và một hàm trả về hai giá trị. Để sử dụng giá trị trả về của một hàm, ta có thể gán nó cho các biến và kiểm tra tính tồn tại của giá trị trả về"
keywords:
  [
    "Khai báo hàm",
    "Hàm trong Go",
    "Hàm không trả về",
    "Hàm trả về giá trị",
    "Hàm trả về nhiều giá trị",
    "Sử dụng hàm trong Go",
    "Gán giá trị trả về",
    "Giá trị tồn tại",
    "Blank identifier",
    "Cú pháp dạng ngắn",
  ]
chapter:
  name: "Làm quen với Go"
  slug: "chuong-02-lam-quen-voi-go"
category:
  name: "Go"
  slug: "go"
image: https://kungfutech.edu.vn/thumbnail.png
position: 3
---

## Khai báo hàm trong Go

Một hàm có thể trả về một hoặc nhiều giá trị. Hãy xem ba hàm sau: một hàm không có giá trị trả về, một hàm trả về một giá trị, một hàm trả về hai giá trị.

```go
func log(message string) {
}

func add(a int, b int) int {
}

func power(name string) (int, bool) {
}
```

Chúng ta sử dụng hàm cuối cùng như sau:

```go
value, exists := power("goku")
if exists == false {
  // xử lý trường hợp có lỗi
}
```

Thi thoảng, bạn chỉ quan tâm đến một trong số các giá trị trả về. Trong trường hợp này, bạn gán các giá trị khác là `_`:

```go
_, exists := power("goku")
if exists == false {
  // xử lý trường hợp có lỗi
}
```

Điều này không phải chỉ là một quy ước. `_`, (blank identifier), đại diện cho giá trị trả về không được gán. Nó cho phép bạn sử dụng `_` mọi chỗ, bất kể kiểu dữ liệu trả về là gì.

Cuối cùng, có một lưu ý trong khi khai báo hàm, nếu các tham số của hàm có cùng một kiểu dữ liệu, thì có thể dụng cú pháp dạng ngắn để viết:

```go
func add(a, b int) int {

}
```

Hàm có thể trả về nhiều giá trị được sử dụng thường xuyên. Bạn cũng sẽ thường xuyên sử dụng `_` để loại bỏ một giá trị.

<content-warning>

Chúng ta đã xem một số ví dụ rời rạc trong chương này. Chúng ta sẽ dần dần xây dựng ví dụ lớn hơn và sẽ lắp ghép các mảnh với nhau.

Nếu bạn quen với một ngôn ngữ động, sự phức tạp của các kiểu dữ liệu và khai báo có thể có vẻ khiến cho chương trình sử dụng ngôn ngữ kém hiệu quả hơn. Tôi không đồng ý với bạn. Đối với một số hệ thống, ngôn ngữ động là khá hiệu quả.

Nếu bạn quen với một ngôn ngữ kiểu tĩnh, có lẽ bạn đang cảm thấy thoải mái với Go. Nội suy ra kiểu dữ liệu và hàm có nhiều giá trị trả về khá hay (mặc dù không phải chỉ Go mới có). Hy vọng rằng khi chúng ta tìm hiểu thêm, bạn sẽ thấy cú pháp trong sáng và ngắn gọn của nó.

</content-warning>
