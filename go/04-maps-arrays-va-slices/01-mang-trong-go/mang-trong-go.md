---
title: "Mảng trong Go"
description: "Bài viết tóm tắt về khái niệm mảng động trong Go, một ngôn ngữ lập trình. Trong Go, mảng được khai báo với kích thước cố định từ đầu và không thể thay đổi. Bài viết giới thiệu cách khai báo, truy cập và khởi tạo mảng. Ngoài ra, bài viết cũng đề cập đến sự hạn chế của mảng và giới thiệu đến khái niệm slices - một cách linh hoạt hơn để lưu trữ dữ liệu."
keywords:
  [
    "mảng động Go",
    "khai báo mảng Go",
    "truy cập mảng Go",
    "khởi tạo mảng Go",
    "slices Go",
    "lập trình Go",
    "ngôn ngữ Go",
    "học Go",
    "mảng và slices",
    "lưu trữ dữ liệu trong Go",
  ]
chapter:
  name: "Maps, Arrays và Slices"
  slug: "chuong-04-maps-arrays-va-slices"
category:
  name: "Go"
  slug: "go"
image: https://kungfutech.edu.vn/thumbnail.png
position: 1
---

Nếu bạn đã quen với Python, Ruby, Perl, JavaScript hoặc PHP..., bạn sẽ quen với khái niệm lập trình _mảng động (dynamic arrays)_. Đó là các mảng dữ liệu có khả năng tự động thay đổi kích thước nếu có thêm dữ liệu được thêm vào mảng. Trong Go, giống nhiều ngôn ngữ khác, một mảng được xác định kích thước từ đầu. Khai báo một mảng yêu cầu phải chỉ rõ kích thước của mảng, một khi kích thước mảng được xác định, nó sẽ không thể tăng thêm:

```go
var scores [10]int
scores[0] = 339
```

Mảng khai báo ở trên có thể lưu tối đa 10 phần tử từ `scores[0]` đến `scores[9]`. Cố gắng để truy cập vào chỉ số ngoài phạm vi của mảng sẽ dẫn đến một lỗi khi biên dịch hoặc khi thực thi chương trình.

Chúng ta có thể khởi tạo mảng với các giá trị như sau:

```go
scores := [4]int{9001, 9333, 212, 33}
```

Chúng ta có thể dùng `len` để xác định độ lớn của mảng. `range` có thể dùng để duyệt các phần tử trong mảng:

```go
for index, value := range scores {

}
```

Mảng là cách lưu dữ liệu hiệu quả nhưng không linh hoạt. Chúng ta thường không biết số lượng các phần tử cần phải khai báo trước. Để giải quyết vấn đề này, chúng ta dùng slices.
