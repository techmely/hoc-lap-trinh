---
title: "Khai báo biến trong Go"
description: "Go không phải là ngôn ngữ hướng đối tượng như C++, Java, Ruby hay C#. Thay vào đó, Go sử dụng cấu trúc và tổ hợp (composition) để thực hiện các tính năng tương tự. Bài viết giới thiệu cách khai báo và khởi tạo biến cấu trúc, cách thêm phương thức vào cấu trúc và ưu điểm của việc sử dụng con trỏ trong Go."
keywords:
  [
    "Go",
    "Ngôn ngữ Go",
    "Khai báo biến Go",
    "Cấu trúc trong Go",
    "Tổ hợp trong Go",
    "Con trỏ Go",
    "Hướng đối tượng trong Go",
    "Phương thức trong Go",
    "Tính kế thừa trong Go",
    "Tính đa hình trong Go",
  ]
chapter:
  name: "Cấu trúc trong Go"
  slug: "chuong-03-cau-truc-trong-go"
category:
  name: "Go"
  slug: "go"
image: https://kungfutech.edu.vn/thumbnail.png
position: 1
---

Go không phải là một ngôn ngữ hướng đói tượng (OO) giống như C++, java, Ruby hoặc C#. Go không có các đối tượng cũng như khả năng kế thừa (inheritance). Do đó, Go không có các lý thuyết thường được nhắc đến khi nói về OO như đa hình (polymorphism) hay ghi đè (overloading).

Thứ mà Go có là các cấu trúc, có thể kết hợp với các phương thức. Go hỗ trợ một dạng đơn giản nhưng hiệu quả của tổ hợp (composition). Nhìn chung, đó là sự kết hợp của những đoạn mã đơn giản, mà lại không cần đến một số tính năng mà OO cung cấp. (Điều đó cho thấy sự tối ưu của _composition_ so với _inheritance_ và Go là ngôn ngữ đầu tiên tôi sử dụng có một nền tảng vững chắc về vấn đề này.)

Mặc dù Go không giống như OOP mà bạn quen dùng, bạn sẽ nhận thấy có rất nhiều điểm giống nhau giữa định nghĩa một cấu trúc (structure) và định nghĩa một lớp (class). Ví dụ đơn giản sau mô tả một cấu trúc:

```go
type Saiyan struct {
  Name string
  Power int
}
```

Chúng ta sẽ xem làm thế nào để thêm một phương thức vào một cấu trúc sau, giống như bạn có các phương thức là một phần của lớp. Trước khi làm điều đó, chúng ta quay trở lại bước khai báo.

## Khai báo và khởi tạo

Khi chúng ta xem cách khởi tạo một biến, chúng ta chỉ xem xét đến các kiểu dữ liệu có sẵn, giống như kiểu số nguyên hoặc xâu. Giờ đây chúng ta sẽ nói về cấu trúc, và nói rộng ra, là các con trỏ.

Cách đơn giản nhất để tạo một biến theo kiểu cấu trúc đã định nghĩa:

```go
goku := Saiyan{
  Name: "Goku",
  Power: 9000,
}
```

<content-warning>

_Lưu ý:_ Các dấu `,` trong cấu trúc bên trên là bắt buộc. Không có nó, trình biên dịch sẽ báo lỗi. Bạn sẽ đánh giá cao tính nhất quán này, đặc biệt khi bạn đã sử dụng qua một ngôn ngữ hoặc một định dạng không nhất quán.

</content-warning>

Chúng ta không nhất thiết phải gán một trường nào trong các trường trên. Cả hai ví dụ sau đều là hợp lệ:

```go
goku := Saiyan{}

// hoặc

goku := Saiyan{Name: "Goku"}
goku.Power = 9000
```

Giống như các biến chưa được gán giá trị, các trường này sẽ được gán giá trị mặc định.

Hơn nữa, bạn có thể bỏ qua tên của trường và dựa vào thứ tự của các trường khi khai báo (để cho rõ ràng, bạn chỉ nên làm thế nếu có ít trường):

```go
goku := Saiyan{"Goku", 9000}
```

Ví dụ trên sẽ định nghĩa một biến `goku` và gán giá trị cho nó.

Nhiều khi, chúng ta không muốn một biến chứa lưu trực tiếp các giá trị, nhưng lại cần một biến lưu con trỏ trỏ tới các giá trị đó. Một con trỏ là một địa chỉ bộ nhớ; nó cho biết vị trí mà tại đó lưu dữ liệu. Đó là một cách truy cập dữ liệu gián tiếp. Nói cách khác, có một sự khác biệt khi so sánh một ngôi nhà và đường tới ngôi nhà.

Tại sao chúng ta cần một con trỏ trỏ tới một giá trị, thay vì chính giá trị đó? Nó chỉ ra cách mà Go truyền tham số cho một hàm: một bản sao. Nội dung gì sẽ được in ra sau lệnh sau?

```go
func main() {
  goku := Saiyan{"Goku", 9000}
  Super(goku)
  fmt.Println(goku.Power)
}

func Super(s Saiyan) {
  s.Power += 10000
}
```

Câu trả lời là 9000, không phải 19000. Tại sao? Bởi vì `Super` thay đổi bản sao của biến `goku` và do đó, các thay đổi bên trong `Super` sẽ không tác động đến các biến trước khi gọi. Để có thể thay đổi được nội dung của biến, ta truyền một con trỏ tới giá trị của biến:

```go
func main() {
  goku := &Saiyan{"Goku", 9000}
  Super(goku)
  fmt.Println(goku.Power)
}

func Super(s *Saiyan) {
  s.Power += 10000
}
```

Chúng ta thực hiện hai thay đổi. Bước thứ nhất là sử dụng toán tử `&` để lấy địa chỉ của biến (nó được gọi là toán tử địa chỉ). Sau đó, chúng ta thay đổi loại của tham số của hàm `Super`. Trước khi thay đổi, hàm nhận tham số là một giá trị có kiểu `Saiyan` nhưng giờ là địa chỉ của một biến có kiểu `*Saiyan`, với `*X` nghĩa là _con trỏ trỏ tới một giá trị kiểu X_. Dù hai kiểu dữ liệu `Saiyan` và `*Saiyan` có liên hệ với nhau, nhưng chúng vẫn là hai kiểu phân biệt.

Chú ý rằng chúng ta vẫn truyền bản sao của biến `s` vào hàm `Super`, nhưng nó trở thành địa chỉ của biến. Bản sao này có giá trị giống hệt như bản chính, đó là sự truy cập gián tiếp. Tưởng tượng rằng có một bản sao của đường đi tới quán ăn. Dù bạn có một bản sao, nhưng nó vẫn chỉ về cùng một quán ăn như bản gốc.

Chúng ta có thể chứng minh rằng đó là một bản sao, bằng cách cố thay đổi vị trí con trỏ đang trỏ tới:

```go
func main() {
  goku := &Saiyan{"Goku", 9000}
  Super(goku)
  fmt.Println(goku.Power)
}

func Super(s *Saiyan) {
  s = &Saiyan{"Gohan", 1000}
}
```

Đoạn mã trên, một lần nữa sẽ in ra 9000. Rất nhiều ngôn ngữ có cách hoạt động giống như thế này, bao gồm Ruby, Python, Java và C#. Go, và ở một số tình huống của C#, có thể nhận thấy điều này.

Rõ ràng là sao chép một con trỏ thì tốn ít chi phí hơn sao chép toàn bộ cấu trúc. Trên các hệ thống 64-bit, một con trỏ có độ lớn 64 bit. Nếu chúng ta có một cấu trúc có nhiều trường, tạo một bản sao của nó sẽ rất tốn kém. Ưu điểm của con trỏ là cho phép bạn chia sẻ các giá trị. Bạn muốn hàm `Super` thay đổi một bản sao của `goku` hay thay đổi các giá trị của `goku`?

Tuy nhiên, bạn sẽ không cần sử dụng con trỏ trong tất cả các trường hợp. Ở cuối chương, sau khi tìm hiểu thêm về cấu trúc, chúng ta sẽ quay lại các câu hỏi về con trỏ và giá trị của nó.

## Hàm trên cấu trúc

Chúng ta có thể gắn một phương thức vào một cấu trúc:

```go
type Saiyan struct {
  Name string
  Power int
}

func (s *Saiyan) Super() {
  s.Power += 10000
}
```

Trong đoạn mã nguồn trên, chúng ta nói rằng loại dữ liệu `*Saiyan` là **receiver** của phương thức `Super`. Chúng ta gọi `Super` như sau:

```go
goku := &Saiyan{"Goku", 9001}
goku.Super()
fmt.Println(goku.Power) // sẽ in ra 19001
```
