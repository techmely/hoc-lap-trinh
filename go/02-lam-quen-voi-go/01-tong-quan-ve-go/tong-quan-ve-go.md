---
title: "Tổng quan về ngôn ngữ Go"
description: "Go được xây dựng như một ngôn ngữ lập trình hệ thống (ví dụ, hệ điều hành, trình điều khiển thiết bị) và do đó nó hướng tới các lập trình viên quen với C và C++. Theo nhóm phát triển Go, không phải người phát triển hệ thống mà là các nhà phát triển ứng dụng sẽ trở thành những người sử dụng Go chủ yếu. Tại sao? Tôi không thể nói thay cho các nhà phát triển hệ thống, nhưng đối với những người xây dựng trang web, dịch vụ, các ứng dụng máy tính để bàn, các nhu cầu mới xuất hiện cho một lớp của các hệ thống mà đứng ở giữa các ứng dụng hệ thống cấp thấp và ứng dụng cấp cao hơn."
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
  name: "Làm quen với Go"
  slug: "chuong-02-lam-quen-voi-go"
category:
  name: "Go"
  slug: "go"
image: https://kungfutech.edu.vn/thumbnail.png
position: 1
---
#  Cơ bản

Go là ngôn ngữ biên dịch, liên kết tĩnh, có cú pháp giống C và kèm theo một trình tự động dọn dẹp bộ nhớ (garbage collection - GC). Điều đó nghĩa là gì?

## Biên dịch trong Go

Biên dịch là quá trình chuyển đổi mã nguồn sang một dạng ngôn ngữ ở mức thấp hơn hoặc dạng hợp ngữ (assembly) (trong trường hợp của Go), hoặc một dạng ngôn ngữ trung gian khác (như Java hoặc C#).

Ngôn ngữ biên dịch có thể gây khó chịu nếu biên dịch chậm. Thật khó để viết chương trình nhanh chóng, nếu bạn phải mất hàng phút hoặc hàng giờ đồng hộ để đợi chương trình dịch xong. Tốc độ biên dịch nhanh là một trong những mục tiêu chính khi thiết kế Go. Đây là tin tốt cho những người làm việc trên các dự án lớn cũng như những người đã quen với những phản hồi nhanh chóng được cung cấp bởi ngôn ngữ thông dịch.

Ngôn ngữ biên dịch sẽ hướng tới chương trình chạy nhanh hơn và file thực thi có thể chạy độc lập (ít nhất, điều đó đúng với các ngôn ngữ giống C, C++ và Go dịch trực tiếp ra hợp ngữ).
(Người dịch: tác giả sử dụng từ assembly trong bản gốc, tuy nhiên, nên hiểu là mã máy, hoặc mã nhị phân).

## Kiểu dữ liệu tĩnh

Kiểu dữ liệu tĩnh nghĩa là các biến phải được xác định kiểu (int, string, bool, []byte, ...). Trình biên dịch sẽ xác định các kiểu dữ liệu khi biến được khai báo, trong nhiều trường hợp, cho phép trình biên dịch nội suy ra kiểu dữ liệu tương ứng (chúng ta sẽ xem ví dụ sau).

Có rất nhiều điều cần nói về kiểu dữ liệu tĩnh, nhưng tôi tin rằng có một cách tốt hơn là đọc mã nguồn. Nếu bạn đang sử dụng kiểu dữ liệu động, bạn có thể thấy điều này phức tạp. Bạn không sai, nhưng ưu điểm đặc biệt là khi bạn đặt kiểu dữ liệu tĩnh với biên dịch. Cả hai tương ứng với nhau. Một trình biên dịch có thể phát hiện các vấn đề sai cú pháp đơn thuần cũng như thực hiện tối ưu hóa hơn nữa với kiểu dữ liệu tĩnh.

## Cú pháp giống C

Nói rằng một ngôn ngữ có cú pháp giống C có nghĩa là nếu bạn quen với một ngôn ngữ họ C khác như C, C++, Java, JavaScript and C#, thì bạn sẽ thấy Go rất quen thuộc. Ví dụ, `&&` được sử dụng như toán tử AND, `==` được sử dụng để so sánh bằng, `{` and `}` là hai kí tự bắt đầu và kết thúc, một mảng được đánh chỉ số từ 0.

Cú pháp giống C có nghĩa là dấu chấm phẩy dùng để kết thúc một dòng và dấu ngoặc đơn ( ) được dùng khi mô tả các biểu thức điều kiện. Go không hỗ trợ kiểu nào cả, mặc dù ngoặc đơn vẫn còn được sử dụng để xác định thứ tự ưu tiên. Ví dụ, một lệnh `if`:

```go
if name == "Leto" {
  print("the spice must flow")
}
```

Trong trường hợp phức tạp, ta dùng dấu ngoặc:

```go
if (name == "Goku" && power > 9000) || (name == "gohan" && power < 4000) {
  print("super Saiyan")
}
```

Ngoài ra, Go gần với C hơn so với C# hoặc Java - không chỉ về mặt cú pháp, mà về mục đích. Điều đó phản ánh sự trong sáng và đơn giản của ngôn ngữ, hy vọng sẽ dần trở nên rõ ràng hơn khi bạn tìm hiểu nó.

## Garbage Collected (GC)

Một số biến có thể xác định được quá trình tồn tại của nó ngay từ khi khai báo. Ví dụ như một biến cục bộ cho một hàm sẽ bị thu hồi khi thoát ra khỏi hàm. Trong trường hợp khác, nó không phải là quá rõ ràng -- ít nhất là đối với một chương trình biên dịch. Ví dụ, thời gian sống của một biến được trả về bởi một hàm hoặc tham chiếu bởi các biến và các đối tượng khác có thể khó xác định. Nếu không có GC, lập trình viên phải tự giải phóng bộ nhớ các biến không cần thiết. Bằng cách nào? Trong C, bạn sẽ dùng `free(str);` .

Ngôn ngữ có GC (ví dụ, Ruby, Python, Java, JavaScript, C #, Go) có thể theo dõi những điều này và giải phóng bộ nhớ khi chúng không còn được sử dụng. GC sẽ làm chương trình nặng hơn, nhưng nó cũng giúp loại bỏ một số lỗi nghiêm trọng.

## Chạy mã Go

Hãy bắt đầu cuộc hành trình của chúng ta bằng cách tạo ra một chương trình đơn giản và học làm cách nào để biên dịch và thực thi nó. Mở soạn thảo văn bản yêu thích của bạn và viết mã sau đây:

```go
package main

func main() {
  println("it's over 9000!")
}
```

Lưu tập tin là `main.go`. Bây giờ, bạn có thể lưu nó bất cứ nơi nào bạn muốn; chúng ta không cần đặt trong workspace của Go cho ví dụ đơn giản này.

Tiếp theo, mở một shell/command prompt và chuyển đến thư mục mà bạn đã lưu tập tin. Đối với tôi, nghĩa là gõ `cd ~/code`.

Cuối cùng, chạy chương trình bằng cách nhập:

```
go run main.go
```

Nếu mọi thứ hoạt động đúng, bạn sẽ nhìn thấy dòng *it's over 9000!*.

Nhưng khoan đã, bước biên dịch là bước nào? `go run` là một lệnh cho phép biên dịch *và* chạy. Nó sử dụng thư mục tạm để biên dịch chương trình, thực thi nó và xóa chương trình tạm. Bạn có thể thấy vị trí của thư mục tạm bằng cách chạy lệnh sau:

```
go run --work main.go
```

Để biên dịch ra file thực thi, sử dụng `go build`:

```
go build main.go
```

Lệnh này sẽ sinh ra một file thực thi có tên `main` và bạn có thể dùng nó để chạy. Trên Linux / OSX, đừng quên thêm dot-slash trước file thực thi, do đó bạn cần gõ là `./main`.

Trong khi lập trình, bạn có thể sử dụng `go run` hoặc `go build`. Khi triển khai sản phẩm, tất nhiên, bạn chỉ biên dịch ra file nhị phân bằng lệnh `go build` và thực thi nó.

### Main trong Go

Hi vọng rằng, đoạn mã vừa rồi dễ hiểu. Chúng ta đã tạo một hàm và in ra một xâu bằng hàm có sẵn `println`. `go run` liệu có biết vị trí để bắt đầu thực thi hay không, vì chúng ta chỉ có một file duy nhất? Không. Trong Go, điểm bắt đầu của chương trình (the entry point) là một hàm có tên `main` bên trong gói (package) `main`.

Chúng ta sẽ nói thêm về các gói trong các chương kế tiếp. Bây giờ, khi chúng ta tập trung vào các phần cơ bản của Go, chúng ta sẽ viết mã trong gói `main`.

Nếu bạn muốn, bạn có thể thay đổi mã và tên của gói. Khi chạy lệnh `go run` và bạn sẽ nhận được một thông báo lỗi. Sau đó, đổi tên gói trở lại thành `main` nhưng vẫn giữ nguyên tên hàm. Bạn sẽ nhận một thông báo lỗi khác. Thử các thay đổi trên nhưng sử dụng lệnh `go build`. Chú ý rằng khi mã nguồn được biên dịch, không có một entry point nào. Điều này rất cần thiết khi biên dịch các thư viện.

## Imports trong Go

Go có một lượng lớn các hàm có sẵn, giống như `println`, có thể dùng mà không cần tham chiếu. Chúng ta không thể làm gì nhiều hơn nếu không sử dụng các thư viện chuẩn của Go và các thư viện bên ngoài. Trong Go, từ khóa `import` được dùng để xác định một gói mà đoạn mã bên trong file có tham chiếu tới.

Hãy thay đổi chương trình thành:

```go
package main

import (
  "fmt"
  "os"
)

func main() {
  if len(os.Args) != 2 {
    os.Exit(1)
  }
  fmt.Println("It's over", os.Args[1])
}
```

Bạn có thể chạy nó bằng lệnh:

```
go run main.go 9000
```

Chúng ta bây giờ đã dùng hai thư viện chuẩn của Go: `fmt` và `os`. Chúng ta cũng được giới thiệu một hàm dựng sẵn khác `len`. `len` trả về kích thước của một chuỗi, hoặc số lượng phần tử trong một từ điển (dictionary), hoặc như chúng ta thấy, số lượng phần tử trong một mảng (array). Nếu bạn hỏi vì sao chúng ta cần 2 tham số cho chương trình, vì tham số thứ nhất -- ở vị trí 0 -- là đường dẫn tới file thực thi hiện tại. (Hãy tự thay đổi chương trình và hiển thị nó.)

Bạn sẽ nhận thấy chúng ta thêm đằng trước của tên hàm là tên của gói, ví dụ, `fmt.Println`. Điều này khác so với nhiều ngôn ngữ khác. Chúng ta sẽ học thêm về các gói ở các chương sau. Bây giờ, cần biết làm thế nào để thêm một gói và sử dụng nó.

Go là một ngôn ngữ quản lý gói khá nghiêm ngặt. Nó sẽ không biên dịch nếu bạn import một gói nhưng lại không sử dụng. Thử chạy lệnh sau:

```go
package main

import (
  "fmt"
  "os"
)

func main() {
}
```

Bạn sẽ có 2 lỗi về `fmt` và `os` được import nhưng không được dùng. Bạn có bực mình không? Chắc chắn. Theo thời gian, bạn sẽ quen với nó (dù nó vẫn gây bực mình). Go quản lý nghiêm việc này do việc thêm các gói không dùng có thể khiến quá trình biên dịch bị chậm; thật sự thì tôi không đồng ý với điều này.

Một điều khác cần lưu ý là Go có bộ thư viện chuẩn được tài liệu hóa khá đầy đủ. Bạn có thể vào <https://golang.org/pkg/fmt/#Println>  để học cách sử dụng `Println`. Bạn cũng có thể click vào tiêu đề để tham khảo mã nguồn, đến đầu trang để tham khảo các cách format của hàm.

Nếu bạn không có internet, bạn có thể đọc tài liệu tại máy tính của mình thông qua cách sau:

```
godoc -http=:6060
```

và dùng trình duyệt để duyệt tới `http://localhost:6060`
