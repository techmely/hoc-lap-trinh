---
title: "Tidbits trong Go"
description: "Trong chương này, chúng ta sẽ bàn về những tính năng đặc biệt của Go."
keywords:
  [
    "gioi thieu go",
    "giới thiệu go",
    "khoá học go",
    "giới thiệu Go",
    "giới thiệu go cơ bản",
    "go la gi",
    "tong quan ve go",
    "gioi thieu ve ngon ngu lap trinh go",
    "tom tat go",
    "code go la gi",
  ]
chapter:
  name: "Tidbits trong Go"
  slug: "chuong-06-tidbits-trong-go"
category:
  name: "Go"
  slug: "go"
image: https://kungfutech.edu.vn/thumbnail.png
position: 1
---
## Xử lý lỗi

Cách xử lý lỗi trong Go là sử dụng giá trị trả về của hàm, mà không phải phát sinh ngoại lệ (exceptions). Xem hàm `strconv.Atoi`, nó nhận đối số đầu vào là một xâu và cố gắng chuyển nó thành một số nguyên:

```go
package main

import (
  "fmt"
  "os"
  "strconv"
)

func main() {
  if len(os.Args) != 2 {
    os.Exit(1)
  }

  n, err := strconv.Atoi(os.Args[1])
  if err != nil {
    fmt.Println("not a valid number")
  } else {
    fmt.Println(n)
  }
}
```

Bạn cũng có thể tạo ra một kiểu lỗi mới, yêu cầu duy nhất của loại dữ liệu này là phải tuân theo đầy đủ mô tả interface `error`, một interface có sẵn của Go, đó là:

```go
type error interface {
  Error() string
}
```

Chúng ta có thể tự tạo ra một kiểu lỗi (error type) bằng cách import gói `errors` và sử dụng nó trong hàm `New`:

```go
import (
  "errors"
)


func process(count int) error {
  if count < 1 {
    return errors.New("Invalid count")
  }
  ...
  return nil
}
```

Đó là một mẫu chung trong thư viện chuẩn của Go về cách sử dụng biến kiểu error. Ví dụ, gói `io` có biến `EOF` được định nghĩa là:

```go
var EOF = errors.New("EOF")
```

Đây là một biến của gói, nó được định nghĩa bên ngoài các hàm, có thể truy cập từ các gói khác (Kí tự đầu tiên là chữ in hoa). Rất nhiều hàm có thể trả về lỗi này, khi chúng ta đọc từ một file hoặc STDIN. Nếu trong một ngữ cảnh phù hợp, bạn nên dùng lỗi này. Là người dùng, chúng ta có thể sử dụng như sau:

```go
package main

import (
  "fmt"
  "io"
)

func main() {
  var input int
  _, err := fmt.Scan(&input)
  if err == io.EOF {
    fmt.Println("no more input!")
  }
}
```

Lưu ý: Go có hàm `panic` và `recover`. `panic` tương đương với phát sinh một ngoại lệ (throw an exception) trong khi `recover` tương đương với `catch`; chúng gần như không được sử dụng.

## Defer trong Go


Mặc dù Go có một bộ gom rác tự động (GC), một số tài nguyên cần được giải phóng một cách tường minh. Ví dụ, chúng ta cần phải `Close()` tập tin sau khi hoàn thành công việc. Lệnh này phải sử dụng rất thận trọng. Với ví dụ này, chúng ta đang viết một hàm, và rất dễ quên `Close` đối tượng mà chúng ta đã khai báo ở 10 dòng trước đó. Trong trường hợp khác, một hàm có thể có nhiều điểm kết thúc. Giải pháp của Go là từ khóa `defer`:

```go
package main

import (
  "fmt"
  "os"
)

func main() {
  file, err := os.Open("a_file_to_read")
  if err != nil {
    fmt.Println(err)
    return
  }
  defer file.Close()
  // đọc nội dung file
}
```

Nếu bạn thử chạy đoạn mã trên, bạn sẽ nhận được một lỗi (file không tồn tại). Điểm nổi bật ở đây là cách mà `defer` hoạt động. Bất cứ lệnh nào đi kèm với từ khóa `defer` sẽ được thực thi sau khi hàm (trong trường hợp này, là hàm `main()`) kết thúc. Điều này giúp bạn giải phóng tài nguyên gần như ở bất cứ chỗ nào nó được sử dụng xong, và bạn sẽ không phải quan tâm quá nhiều nếu hàm có nhiều điểm kết thúc.

## go fmt

Hầu hết các chương trình được viết bằng Go đều theo một cách định dạng, đặt tên, tab được dùng để dóng hàng và dấu ngoặc được dùng trên một dòng như một biểu thức.

Tôi biết, bạn có phong cách riêng và bạn muốn gắn bó với nó. Đó là điều mà tôi làm trong một thời gian dài, nhưng tôi rất vui vì cuối cùng thì tôi cũng bỏ được nó. Một vấn đề lớn là lệnh `go fmt`. Nó rất dễ sử dụng.

Khi bạn làm việc trong một dự án, bạn có thể áp dụng cách định dạng với toàn bộ thư mục đó và các thư mục con của nó bằng cách:

```
go fmt ./...
```

Hãy thử nó. Nó không chỉ căn chỉnh mã nguồn giúp bạn. Nó cũng căn lại các khai báo trường và sắp xép thứ tự của các gói được thêm vào mã nguồn theo thứ tự alphabet.

## Lệnh If có khởi tạo

Gô hỗ trợ lệnh If với một thay đổi nhỏ, một giá trị có thể được khởi tạo trước khi nó được đem so sánh:

```go
if x := 10; count > x {
  ...
}
```

Đó là một ví dụ quá đơn giản. Trong thực tế, bạn có thể làm như sau:

```go
if err := process(); err != nil {
  return err
}
```

Điều thú vị là, giá trị này sẽ không tồn tại ở ngoài lệnh if, nó chỉ tồn tại bên trong lệnh `if`, `else if` hoặc `else`.

## Interface rỗng và Chuyển đổi kiểu dữ liệu

Trong hầu hết các ngôn ngữ hướng đối tượng, một lớp cơ bản được dựng sẵn, thường tên là `object`, nó là lớp cha của tất cả các lớp khác. Go, không có khái niệm kế thừa, tất nhiên là nó cũng chẳng có lớp cha nào cả. Go cho phép tồn tại một interface rỗng (empty interface), không chứa một phương thức nào: `interface{}`. Tất cả các loại dữ liệu khác đều có thể coi là một thể hiện (implementation) của empty interface, một cách không tường minh.

 Nếu muốn, chúng ta có thể viết một hàm `add` có chữ kí như sau:

```go
func add(a interface{}, b interface{}) interface{} {
  ...
}
```

Để chuyển dổi một biến interface sang một kiểu tường minh, sử dụng `.(TYPE)`:

```go
return a.(int) + b.(int)
```

Lưu ý là nếu kiểu dữ liệu cần chuyển đôi không tương thích với kiểu `int`, lệnh trên sẽ phát sinh lỗi.

Bạn cũng có thể sử dụng cách sau để kiểm tra kiểu của biến:

```go
switch a.(type) {
  case int:
    fmt.Printf("a is now an int and equals %d\n", a)
  case bool, string:
    // ...
  default:
    // ...
}
```

Bạn có thể sử dụng interface bây giờ. Nhưng phải thừa nhận rằng, mã nguồn sẽ không dễ đọc. Chuyển đổi kiểu qua lại đôi khi khá nguy hiểm nhưng đó là cách duy nhất để làm việc này trong một ngôn ngữ tĩnh.

## Xâu (String) và mảng byte (Byte Array)

Xâu va mảng byte có liên hệ khá gần với nhau. Chúng ta có thể dễ dàng chuyển đổi loại này sang loại kia:

```go
stra := "the spice must flow"
byts := []byte(stra)
strb := string(byts)
```

Sự thật là, cách ép kiểu này là cách chuyển đổi kiểu dữ liệu thông dụng giữa nhiều kiểu dữ liệu với nhau. Một số hàm yêu cầu đầu vào rất tường minh:`int32` , `int64` hoặc một số không dấu. Bạn có thể làm điều tương tư như sau:

```go
int64(count)
```

Khi nói đến byte và xâu, nó có thể là thứ bạn sử dụng thường xuyên. Nhớ rằng khi bạn dùng `[]byte(X)` hoặc `string(X)`, bạn đang tạo ra một bản sao của dữ liệu gốc. Điều đó là cần thiết, vì các xâu thường không thay đổi được.

Các xâu được tạo ta từ [`runes`](https://en.wikipedia.org/wiki/Runes) là các kí tự unicode. Bạn có thể không tính được đúng giá trị độ dài của xâu. Đoạn mã sau đây in số 3:

    fmt.Println(len("椒"))

Nếu bạn duyệt qua xâu bằng `range`, bạn sẽ nhận được từng kí tự, chứ không phải từng byte. Tất nhiên, khi bạn chuyển một xâu sang kiểu mảng byte, bạn sẽ lấy được dữ liệu đúng.

## Kiểu dữ liệu hàm (Function Type)

Hàm là một loại dữ liệu lớp đầu tiên:

```go
type Add func(a int, b int) int
```

Nó có thể được dùng ở bất cứ đâu, như một kiểu dữ liệu thông thường, một tham số hoặc một giá trị trả về.

```go
package main

import (
  "fmt"
)

type Add func(a int, b int) int

func main() {
  fmt.Println(process(func(a int, b int) int{
      return a + b
  }))
}

func process(adder Add) int {
  return adder(1, 2)
}
```

## Trước khi đọc tiếp

Chúng ta đã nhìn vào nhiều khía cạnh khác nhau của một chương trình Go. Đáng chú ý nhất là chúng ta hiểu cách xử lý lỗi và làm thế nào để giải phóng tài nguyên, ví dụ như các kết nối hoặc các file đang mở. Nhiều người không thích cách tiếp cận của Go trong khi xử lý lỗi. Nó giống như một bước lùi. Trong một số trường hợp, tôi đồng ý với ý kiến đó. Tuy nhiên, tôi cũng thấy rằng cách làm của Go khiến cho mã nguồn rất dễ theo dõi. `defer` là một cách tiếp cận khác nhưng hiệu quả khi quản lý tài nguyên. Sự thật là nó không phải chỉ để dùng khi quản lý tài nguyên. Bạn có thể dùng `defer` cho bất cứ mục đích nào khác, ví dụ như ghi log khi kết thúc hàm.

Chắc chắn là chúng ta không xem hết tất cả các tính năng đặc biệt của Go trong chương này. Nhưng bạn có thể thấy đủ với những ghì bạn đã được học.

