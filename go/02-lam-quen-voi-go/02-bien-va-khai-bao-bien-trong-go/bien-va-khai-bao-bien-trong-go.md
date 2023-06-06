---
title: "Biến và khai báo biến trong Go"
description: "Go được xây dựng như một ngôn ngữ lập trình hệ thống (ví dụ, hệ điều hành, trình điều khiển thiết bị) và do đó nó hướng tới các lập trình viên quen với C và C++. Theo nhóm phát triển Go, không phải người phát triển hệ thống mà là các nhà phát triển ứng dụng sẽ trở thành những người sử dụng Go chủ yếu. Tại sao? Tôi không thể nói thay cho các nhà phát triển hệ thống, nhưng đối với những người xây dựng trang web, dịch vụ, các ứng dụng máy tính để bàn, các nhu cầu mới xuất hiện cho một lớp của các hệ thống mà đứng ở giữa các ứng dụng hệ thống cấp thấp và ứng dụng cấp cao hơn."
keywords:
  [
    "biến",
    "khai báo biến",
    "biến trong Go",
    "biến trong go",
    "Khai báo biến trong go",
    "khai bao bien trong go",
  ]
chapter:
  name: "Làm quen với Go"
  slug: "chuong-02-lam-quen-voi-go"
category:
  name: "Go"
  slug: "go"
image: https://kungfutech.edu.vn/thumbnail.png
position: 2
---

## Biến và khai báo biến trong Go

Hãy bắt đầu khai báo một biến số bằng cách _bạn khai báo và gán giá trị cho một biến bằng cách x = 4._ Thật không may, mọi thứ phức tạp hơn trong Go. Chúng ta bắt đầu bằng cách xem xét một ví dụ đơn giản. Sau đó, ở chương sau, chúng ta sẽ giải thích một lần nữa khi xem cách tạo và sử dụng cấu trúc. Tuy nhiên, nó có thể sẽ mất thời gian trước khi bạn thực sự cảm thấy quen với nó.

Bạn có thể đang nghĩ _Ồ! Sao lại phức tạp thế?_ Hãy xem một vài ví dụ sau.

Cách tường minh nhất để khai báo và gán một biến trong Go rất dài dòng:

```go
package main

import (
  "fmt"
)

func main() {
  var power int
  power = 9000
  fmt.Printf("It's over %d\n", power)
}
```

Ở đây, chúng ta khai báo một biến `power` có kiểu `int`. Mặc định, Go gán giá trị 0 cho các biến. Số nguyên được gán `0`, biến logic là `false`, xâu thì gán `""`. Tiếp theo, chúng ta gán `9000` cho biến `power`. Chúng ta có thể ghép hai dòng thành một:

```go
var power int = 9000
```

Tuy nhiên, vẫn quá nhiều thứ phải gõ. Go có một cách khai báo biến ngắn gọn, thông qua toán tử khai báo, `:=`, từ đó kiểu dữ liệu được nội suy:

```go
power := 9000
```

Điều tiện lợi này cũng sử dụng được với hàm:

```go
func main() {
  power := getPower()
}

func getPower() int {
  return 9001
}
```

Cần nhớ rằng `:=` được dùng để khai báo biến và gán giá trị cho nó. Một biến không thể khai báo hai lần (không phải trong cùng một phạm vi). Nếu bạn thử chạy đoạn mã sau, bạn sẽ gặp lỗi.

```go
func main() {
  power := 9000
  fmt.Printf("It's over %d\n", power)

  // LỖI BIÊN DỊCH:
  // no new variables on left side of :=
  power := 9001
  fmt.Printf("It's also over %d\n", power)
}
```

Chương trình biên dịch sẽ thông báo _no new variables on left side of :=_. Điều này có nghĩa là chúng ta khai báo biến lần đầu tiên với toán tử `:=` nhưng lần thứ hai tác động vào biến, chúng ta phải dùng toán tử gán `=`. Điều này rất quan trọng, nó khiến bạn nhớ nhiều hơn khi sử dụng chuyển đổi giữa 2 loại toán tử.

Nếu bạn đọc một thông báo lỗi, bạn sẽ nhận thấy thông báo sử dụng số nhiều khi viết về các biến: _variables_. Go cho phép bạn gán nhiều giá trị vào nhiều biến khác nhau cùng một lúc (sử dụng `=` hoặc `:=`):

```go
func main() {
  name, power := "Goku", 9000
  fmt.Printf("%s's power is over %d\n", name, power)
}
```

Miễn là có một biến số mới, thì đều có thể dùng `:=`. Xem đoạn mã sau:

```go
func main() {
  power := 1000
  fmt.Printf("default power is %d\n", power)

  name, power := "Goku", 9000
  fmt.Printf("%s's power is over %d\n", name, power)
}
```

Mặc dù `power` được sử dụng 2 lần với toán tử `:=`, trình biên dịch sẽ không phát sinh lỗi ở lần thứ 2, nó phát hiện ra một biến khác, `name`, là một biến mới và sử dụng `:=` là hợp lệ. Tuy nhiên, bạn không thể đổi kiểu của biến `power`. Nó được khai báo (không tường minh) là một số nguyên (integer) và vì thế chỉ có thể được gán giá trị là số nguyên.

Bây giờ, thứ cuối cùng cần xem xét, giống như `import`, Go không cho phép bạn khai báo biến mà không sử dụng. Ví dụ:

```go
func main() {
  name, power := "Goku", 1000
  fmt.Printf("default power is %d\n", power)
}
```

Đoạn mã trên sẽ không biên dịch được do biến `name` được khai báo nhưng không được sử dụng. Giống như các khai báo import không được dùng, khai báo biến thừa sẽ không làm chậm lại, nhưng tôi nghĩ rằng điều đó khiến cho mã nguồn sáng sủa và dễ đọc hơn.

Tóm lại, để khai báo và gán một biến, cần nhớ: bạn sẽ sử dụng khai báo `var NAME TYPE` khi khai báo một biến và gán giá trị 0 cho nó, `NAME := VALUE` khi khái báo một biến và gán giá trị, và `NAME = VALUE` khi gán giá trị cho một biến đã khai báo trước đó.
