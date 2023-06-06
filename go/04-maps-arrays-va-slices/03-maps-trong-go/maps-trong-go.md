---
title: "Maps trong Go"
description: "Bài viết tập trung vào Maps trong Go và cách sử dụng chúng. Maps được xem như hashtables hoặc dictionaries trong các ngôn ngữ khác, cho phép xác định và thao tác giá trị thông qua các khóa. Bài viết giới thiệu cách khai báo, khởi tạo, lấy và xóa giá trị từ một map trong Go."
keywords:
  [
    "Maps Go",
    "hashtables Go",
    "dictionaries Go",
    "khai báo map Go",
    "thao tác map Go",
    "xóa giá trị map Go",
    "duyệt map Go",
    "truyền con trỏ Go",
    "truyền giá trị Go",
    "lưu trữ dữ liệu Go",
  ]
chapter:
  name: "Maps, Arrays và Slices"
  slug: "chuong-04-maps-arrays-va-slices"
category:
  name: "Go"
  slug: "go"
image: https://kungfutech.edu.vn/thumbnail.png
position: 3
---

Maps trong Go và các ngôn ngữ khác được gọi là hashtables hoặc dictionaries. Nó hoạt động như bạn đang nghĩ: bạn định nghĩa một cặp khóa (key) và giá trị (value), và bạn có thể lấy (get), thay đổi (set) và xóa (delete) giá trị thông qua khóa.

Maps, cũng như slices, được tạo ra thông qua hàm `make`. Hãy xem ví dụ sau:

```go
func main() {
  lookup := make(map[string]int)
  lookup["goku"] = 9001
  power, exists := lookup["vegeta"]

  // in ra 0, false
  // 0 giá trị mặc dịnh của số nguyên
  fmt.Println(power, exists)
}
```

Để biết số lượng các khóa đang có, chúng ta dùng `len`. Để xóa một giá trị dựa vào khóa, dùng `delete`:

```go
// returns 1
total := len(lookup)

// không có giá trị trả về, có thể khóa tìm kiếm không tồn tại
delete(lookup, "goku")
```

Maps tăng kích thước tự động. Tuy nhiên, chúng ta có thể cung cấp tham số thứ 2 cho hàm `make` để khởi tạo kích thước ban đầu cho map:

```go
lookup := make(map[string]int, 100)
```

Nếu bạn có thể đoán được có bao nhiêu khóa sẽ có trong map, hãy xác định kích thước khởi tạo để tăng hiệu năng.

Để định nghĩa một map là một trường của một cấu trúc, làm như sau:

```go
type Saiyan struct {
  Name string
  Friends map[string]*Saiyan
}
```

Một cách để khởi tạo cấu trúc trên là:

```go
goku := &Saiyan{
  Name: "Goku",
  Friends: make(map[string]*Saiyan),
}
goku.Friends["krillin"] = ... //todo load or create Krillin
```

Đó là một cách khác để khai báo và khởi tạo giá trị trong Go. Giống như `make`, cách tiếp cận này chỉ dùng được cho maps và arrays. Chúng ta có thể khai báo như sau:

```go
lookup := map[string]int{
  "goku": 9001,
  "gohan": 2044,
}
```

Chúng ta có thể duyệt qua một map bằng câu lệnh `for` kết hợp với từ khóa `range` :

```go
for key, value := range lookup {
  ...
}
```

Duyệt qua các phần tử của map là không theo thứ tự. Mỗi phần tử trong quá trình tìm kiếm được chọn theo thứ tự ngẫu nhiên.

## Con trỏ vs giá trị

Chúng ta kết thúc chương 2 bằng câu hỏi nên truyền con trỏ hay giá trị cho hàm. Giờ chúng ta có một câu hỏi tương tự, đối với array và map. Nên sử dụng loại nào?

```go
a := make([]Saiyan, 10)
//hoặc
b := make([]*Saiyan, 10)
```

Nhiều lập trình viên nghĩ rằng truyền `b` cho hàm hoặc lấy `b` là giá trị trả về của hàm, sẽ hiệu quả hơn. Tuy nhiên, dù truyền hay nhận lại gì, thì đó cũng là một bản sao của một slice, bản thân nó đã là tham chiếu đến dữ liệu, do đó không có sự khác biệt nào.

Khi bạn thấy sự khác nhau là khi bạn sửa giá trị của một slice hoặc map. Ở điểm này, logic cũng giống như ở chương 2. Vì vậy, quyết định về việc có nên xác định một mảng của các con trỏ so với một mảng các giá trị chính là cách bạn sử dụng các giá trị, không phải là cách bạn sử dụng array hoặc map.

<content-warning>

Arrays và maps trong Go hoạt động giống như các ngôn ngữ khác. Nếu bạn quen với các mảng dữ liệu động, thì sẽ có một chút thay đổi nhỏ, nhưng `append` sẽ giải quyết các vấn đề khó chịu này. Nếu chúng ta xem xét tới slice, ta sẽ thấy đó là sự mở rộng của mảng.

Có một số khía cạnh mà chúng ta đã không đề cập đến nó, nhưng bạn cũng gần như không động đến chúng bao giờ. Và nếu bạn tiếp cận chúng, hy vọng rằng chúng ta sẽ mô tả nó ở đây để cho bạn biết điều gì đang xảy ra.

</content-warning>
