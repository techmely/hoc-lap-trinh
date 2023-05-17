---
title: "Giao diện"
description: "Để có thể xây dựng được những thư viện phức tạp, chúng ta cần tìm hiểu về khái niệm gói (packages). Trong Go, mỗi gói được đặt tên theo cấu trúc của thử mục trong workspace."
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
  name: "Cách tổ chức mã nguồn và Interfaces"
  slug: "chuong-05-cach-to-chuc-ma-nguon-va-interfaces"
category:
  name: "Go"
  slug: "go"
image: https://kungfutech.edu.vn/thumbnail.png
position: 2
---
Interfaces là kiểu dữ liệu chỉ chứa các chữ kí mô tả cho hàm. Đây là ví dụ:

```go
type Logger interface {
  Log(message string)
}
```

Implementation của một hàm là các đoạn mã bên trong của hàm đó. Có thể có nhiều hàm khác nhau với cách implementation khác nhau, nhưng lại cùng được mô tả bởi một prototype giống nhau.

Bạn có thể tự hỏi mục đích của interface là gì. Interface giúp tách biệt phần mã implementation của hàm và phần gọi hàm ra các đối tượng riêng biệt. Ví dụ, bạn có thể gọi nhiều loại hàm ghi log khác nhau:

```go
type SqlLogger struct { ... }
type ConsoleLogger struct { ... }
type FileLogger struct { ... }
```

Trong một chương trình, bao giờ cũng tồn tại 2 thành phần: thành phần gọi hàm (hoặc còn gọi là sử dụng hàm) và implementation của hàm. Thành phần gọi hàm có thể không thay đổi nhiều, nhưng implementation của hàm có thể thay đổi rất nhiều.

Bạn sử dụng chúng thé nào? Cũng giống như bất kỳ một kiểu dữ liệu nào khác, có thể coi nó là một trường trong một cấu trúc:

```go
type Server struct {
  logger Logger
}
```

hoặc một tham số của hàm hoặc giá trị trả về:

```go
func process(logger Logger) {
  logger.Log("hello!")
}
```

Trong ngôn gữ C# hoặc Java, chúng ta có thể khai báo tường minh một lớp tuân theo một interface:

```java
public class ConsoleLogger : Logger {
  public void Logger(message string) {
    Console.WriteLine(message)
  }
}
```

Trong Go, điều đó là không tường minh. Nếu cấu trúc của bạn có một hàm tên là `Log` với tham số đầu vào là `string` và không có giá trị trả về, sau đó nó có thể được dùng như một `Logger`. Điều này làm cho việc sử dụng giao diện không rõ ràng:

```go
type ConsoleLogger struct {}
func (l ConsoleLogger) Log(message string) {
  fmt.Println(message)
}
```

Nó hướng tới các interface nhỏ và cô đọng. Các thư viện chuẩn là những interface đầy đủ. Gói `io` có các interface như `io.Reader`, `io.Writer`, và `io.Closer`.
Interface cũng có thể được dùng trong composition. Các interface cũng có thể được kết hợp từ nhiều interface khác. Ví dụ, `io.ReadCloser` là một interface được kết hợp từ `io.Reader` và `io.Closer` .

Cuối cùng, interface được sử dụng để tránh tình trạng import lồng nhau. Vì interface không có implementation, chúng sẽ gần như không cần gói thư viện bên ngoài.

## Trước khi đọc tiếp

Tóm lại, bạn tạo cấu trúc mã nguồn của bạn thế nào trong workspace cũng được, miễn là bạn cảm thấy thoải mái sau khi viết một vài project cỡ vừa. Điều quan trọng nhất cần nhớ là mối quan hệ chặt chẽ giữa tên của gói và cấu trúc thư mục của bạn (không chỉ trong một dự án, mà là trong toàn bộ workspace).

Cách mà Go phân quyền truy cập các kiểu dữ liệu khá đơn giản và hiệu quả. Nó cũng khá thích hợp. Có một vài thứ chúng ta chưa xem qua ở đây, ví dụ như các hằng số, biến toàn cục nhưng cách xác định quyền truy cập của chúng hoàn toàn tương tự.

Cuối cùng, nếu bạn mới biết tới interface, bạn cần thời gian để quen với nó.


