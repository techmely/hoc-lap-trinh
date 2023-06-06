---
title: "Slices trong Go"
description: "Bài viết này giới thiệu về slice trong ngôn ngữ Go và cách sử dụng chúng thay vì mảng. Nó cung cấp các ví dụ về khai báo slice, khởi tạo slice với make, cách thêm phần tử vào slice bằng append, khái niệm kích thước và dung lượng của slice, cách sử dụng append để mở rộng slice, và một số ví dụ khác liên quan đến slice."
keywords:
  [
    "Go slice",
    "slice trong Go",
    "khai báo slice",
    "khởi tạo slice",
    "make và append trong Go",
    "kích thước và dung lượng slice",
    "re-slice trong Go",
    "mảng động trong Go",
  ]
chapter:
  name: "Maps, Arrays và Slices"
  slug: "chuong-04-maps-arrays-va-slices"
category:
  name: "Go"
  slug: "go"
image: https://kungfutech.edu.vn/thumbnail.png
position: 2
---

Trong Go, bạn sẽ rất hiếm khi dùng mảng một cách trực tiếp. Thay vào đó, bạn sẽ sử dụng `slices`. Một `slice` là một cấu trúc nhỏ gọn mô tả một vị trí trong một mảng. Có một vài cách để tạo một `slice`. Cách đầu tiên là một biến thể của khai báo mảng:

```go
scores := []int{1,4,293,4,9}
```

Không giống như khai báo mảng, slice được mô tả nhưng không xác định kích thước trong ngoặc vuông. Để hiểu chúng khác nhau thế nào, hãy xem một cách khai báo slice khác, dùng `make`:

```go
scores := make([]int, 10)
```

Chúng ta dùng `make` thay vì `new` vì `new` chỉ đơn thuần là cấp phát bộ nhớ và không làm gì cả. Trong khi đó, `make` cấp phát bộ nhớ, và khởi tạo cho bộ nhớ. Trong ví dụ trên, chúng ta khởi tạo một slice có kích thước (length) 10 và có dung lượng (capacity) là 10. Kích thước của slice là số phần tử hiện đang có trong slice, dung lượng của slice là kích thước tối đa của một slice. Sử dụng `make` để khởi tạo 2 giá trị này riêng biệt:

```go
scores := make([]int, 0, 10)
```

Câu lệnh sẽ tạo một slice có kích thước là 0 nhưng có dung lượng là 10. (Nếu bạn để ý, bạn sẽ thấy rằng `make` và `len` _là_ overloaded. Go là một ngôn ngữ có một số điểm đáng thất vọng, khi làm ra một số tính năng nhưng không cho phép lập trình viên dùng nó.)

Để hiểu rõ hơn về kích thước và dung lượng, hãy xem các ví dụ sau:

```go
func main() {
  scores := make([]int, 0, 10)
  scores[7] = 9033
  fmt.Println(scores)
}
```

Ví dụ đầu tiên bị lỗi. Tại sao? Vì kích thước của slice đang là 0. Dung lượng của slice là 10 phần tử, nhưng chúng ta cần mở rộng slice một cách tường minh, trước khi truy cập vào các phần tử của nó. Một cách để thêm phần tử vào slice là dùng hàm `append`:

```go
func main() {
  scores := make([]int, 0, 10)
  scores = append(scores, 5)
  fmt.Println(scores) // in phần tử [5]
}
```

Nhưng thay đổi này đã không đúng với ý tưởng ban đầu của đoạn mã. `Append` một phần tử vào slice có kích thước bằng 0 tức là gán giá trị cho phần tử đầu tiên của slice. Thực tế, chúng ta cần truy cập phần tử có chỉ số là 7. Để làm điều này, cần thực hiện re-slice:

```go
func main() {
  scores := make([]int, 0, 10)
  scores = scores[0:8]
  scores[7] = 9033
  fmt.Println(scores)
}
```

Một slice có thể thay đổi kích thước tói mức nào? Kích thước tối đa là dung lượng của slice, trong trường hợp này là 10. Ban có thể đang nghĩ rằng _điều này chả giải quyết được vấn đề ban đầu. Vẫn là một mảng có kích thước cố định._ Tuy nhiên, hàm `append` khá đặc biệt. Nếu slice đã đầy, nó sẽ tạo một mảng mới, sao chép toàn bộ các giá trị ở mảng cũ sang (nó giống hệt như khái niệm mảng động của PHP, Python, Ruby, JavaScript, ...). Đó là lý do vì sao lại giới thiệu hàm `append`. Chúng ta có thể gán lại giá trị trả về của `append` to biến `scores`: `append` có thể trả về một mảng mới, nếu mảng cũ đã đầy.

Nếu tôi nói rằng Go tăng kích thước mảng theo thuật toán nhân đôi, bạn có thể đoán được đầu ra của các lệnh sau không?

```go
func main() {
  scores := make([]int, 0, 5)
  c := cap(scores)
  fmt.Println(c)

  for i := 0; i < 25; i++ {
    scores = append(scores, i)

    // nếu dùng lượng thay đổi,
    // Go đã mở rộng mảng để chứa được các dữ liệu mới
    if cap(scores) != c {
      c = cap(scores)
      fmt.Println(c)
    }
  }
}
```

Dung lượng ban đầu của `scores` là 5. Để lưu được 25 giá trị, nó phải được mở rộng 3 lần với dung lượng tăng lần lượt là 10, 20 và cuối cùng là 40.

Ví dụ cuối cùng:

```go
func main() {
  scores := make([]int, 5)
  scores = append(scores, 9332)
  fmt.Println(scores)
}
```

Ở đây, giá trị hiển thị được sẽ là `[0, 0, 0, 0, 0, 9332]`. Có lẽ bạn sẽ nghĩ nó phải là `[9332, 0, 0, 0, 0]`? Với người, điều đó có vẻ rất logic. Với trình biên dịch, nó được yêu cầu thêm phần tử 9332 vào một slice đã có sẵn 5 phần tử.

Cuối cùng, có bốn cách phổ biến để khởi tạo một slice:

```go
names := []string{"leto", "jessica", "paul"}
checks := make([]bool, 10)
var names []string
scores := make([]int, 0, 20)
```

Khi nào bạn sử dụng loại nào? Loại đầu tiên không cần nhiều lời giải thích. Bạn sử dụng khi bạn biết những giá trị mà bạn muốn trong mảng.

Loại thứ hai là hữu ích khi bạn có thể gi vào một vị trí cụ thể của một slice. Ví dụ:

```go
func extractPowers(saiyans []*Saiyans) []int {
  powers := make([]int, len(saiyans))
  for index, saiyan := range saiyans {
    powers[index] = saiyan.Power
  }
  return powers
}
```

Loại thứ ba là cách khai báo một slice rỗng, được dùng cùng với `append`, khi không biết trước số lượng phần tử.

Loại cuối cùng cho phép chúng ta khởi tạo giá trị của dung lượng trong slice; nó có ích nếu chúng ta có được số lượng đối tượng chúng ta cần.

Thậm chi khi đã biết được kích thước, `append` vẫn có thể dùng được.

```go
func extractPowers(saiyans []*Saiyans) []int {
  powers := make([]int, 0, len(saiyans))
  for _, saiyan := range saiyans {
    powers = append(powers, saiyan.Power)
  }
  return powers
}
```

Slices được coi là phần mở rộng của arrays. Nhiều ngôn ngữ có khái niệm slicing một mảng. Cả JavaScript và Ruby đều có khái niệm mảng và phương thức `slice` cho mảng. Bạn có thể dùng slice trong Ruby bằng cách `[START..END]` hoặc trong Python thông qua `[START:END]`. Tuy nhiên, trong những ngôn ngữ này, một slice là một mảng mới hoàn toàn với các giá trị được sao chép từ mảng cũ. Với Ruby, kết quả của các lệnh sau là gì?

```go
scores = [1,2,3,4,5]
slice = scores[2..4]
slice[0] = 999
puts scores
```

Câu trả lời là`[1, 2, 3, 4, 5]`. Bởi vì `slice` là một mảng mới hoàn toàn với dữ liệu được sao chép từ mảng cũ. Bây giờ, xem một ví dụ Go tương đương:

```go
scores := []int{1,2,3,4,5}
slice := scores[2:4]
slice[0] = 999
fmt.Println(scores)
```

Kêt quả chạy chương trình là `[1, 2, 999, 4, 5]`.

Thay đổi này sẽ thay đổi cách bạn viết mã. Ví dụ, một số lượng lớn các hàm nhận tham số đầu vào là vị trí. Trong JavaScript, nếu chúng ta muốn tìm kí tự khoảng trắng (space) đầu tiên trong xâu (đúng, slices cũng có thể hoạt động như một chuỗi!) đứng sau 5 kí tự đầu tiên, chúng ta viết:

```javascript
haystack = "the spice must flow";
console.log(haystack.indexOf(" ", 5));
```

Trong Go, chúng ta dùng slice:

```go
strings.Index(haystack[5:], " ")
```

Chúng ta có thể thấy ở đoạn mã phía trên `[X:]` là viết tắt của _từ X tới cuối_ trong khi `[:X]` là viết tắt cửa _từ đầu tới X_. Không giống các ngôn ngữ khác, Go không hỗ trợ giá trị âm cho chỉ số. Nếu bạn muốn một slice chứa tất cả các phần tử trừ phần tử cuối cùng, chúng ta viết:

```go
scores := []int{1, 2, 3, 4, 5}
scores = scores[:len(scores)-1]
```

Đoạn mã bên dưới là một cách hiệu quả để xóa một phần từ khởi một slice chưa sắp xếp:

```go
func main() {
  scores := []int{1, 2, 3, 4, 5}
  scores = removeAtIndex(scores, 2)
  fmt.Println(scores) // [1 2 5 4]
}

// không theo thứ tự
func removeAtIndex(source []int, index int) []int {
  lastIndex := len(source) - 1
  //chuyển chỗ giá trị cuối cùng và giá trị chúng ta muốn xóa
  source[index], source[lastIndex] = source[lastIndex], source[index]
  return source[:lastIndex]
}
```

Cuối cùng, bây giờ chúng ta đã biết về slice, chúng ta có thể tìm hiểu một hàm khác: `copy`. `copy` là một trong những hàm làm nổi bật cách mà slice thay đổi nội dung của nó. Bình thường, hàm sẽ sao chép các giá trị từ mảng này qua mảng khác với 5 tham số: `source`, `sourceStart`, `count`, `destination` and `destinationStart`. Với slice, chỉ cần 2 tham số:

```go
import (
  "fmt"
  "math/rand"
  "sort"
)

func main() {
  scores := make([]int, 100)
  for i := 0; i < 100; i++ {
    scores[i] = int(rand.Int31n(1000))
  }
  sort.Ints(scores)

  worst := make([]int, 5)
  copy(worst, scores[:5])
  fmt.Println(worst)
}
```

Hãy thử chạy đoạn mã trên. Thử một vài biến thể của nó. Hãy xem chuyện gì xảy ra nếu bạn đổi hàm `copy` thành `copy(worst[2:4], scores[:5])`, hoặc chuyện gì xảy ra khi cố sao chép nhiều hơn hoặc ít hơn `5` giá trị vào `worst`?
