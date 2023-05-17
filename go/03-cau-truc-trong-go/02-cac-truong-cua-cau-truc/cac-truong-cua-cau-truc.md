---
title: "Các trường của cấu trúc"
description: "Go không phải là một ngôn ngữ hướng đói tượng (OO) giống như C++, java, Ruby hoặc C#. Go không có các đối tượng cũng như khả năng kế thừa (inheritance). Do đó, Go không có các lý thuyết thường được nhắc đến khi nói về OO như đa hình (polymorphism) hay ghi đè (overloading). Thứ mà Go có là các cấu trúc, có thể kết hợp với các phương thức. Go hỗ trợ một dạng đơn giản nhưng hiệu quả của tổ hợp (composition). Nhìn chung, đó là sự kết hợp của những đoạn mã đơn giản, mà lại không cần đến một số tính năng mà OO cung cấp. (Điều đó cho thấy sự tối ưu của *composition* so với *inheritance* và Go là ngôn ngữ đầu tiên tôi sử dụng có một nền tảng vững chắc về vấn đề này.) Mặc dù Go không giống như OO mà bạn quen dùng, bạn sẽ nhận thấy có rất nhiều điểm giống nhau giữa định nghĩa một cấu trúc (structure) và định nghĩa một lớp (class)."
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
  name: "Cấu trúc trong Go"
  slug: "chuong-03-cau-truc-trong-go"
category:
  name: "Go"
  slug: "go"
image: https://kungfutech.edu.vn/thumbnail.png
position: 2
---
Trong ví dụ chúng ta thấy ở trên, `Saiyan` có hai trường `Name` và `Power` có kiểu tương ứng là `string` và `int`. Các trường có thể có bất cứ kiểu nào, kể cả là một cấu trúc khác và các kiểu chúng ta chưa thử như mảng (array), maps, interfaces và hàm.

Ví dụ, chúng ta có thể khai báo của cấu trúc `Saiyan`:

```go
type Saiyan struct {
  Name string
  Power int
  Father *Saiyan
}
```

và khởi tạo như sau:

```go
gohan := &Saiyan{
  Name: "Gohan",
  Power: 1000,
  Father: &Saiyan {
    Name: "Goku",
    Power: 9001,
    Father: nil,
  },
}
```

## Composition trong Go

Go hỗ trợ tổ hợp hóa (composition), cho phép một cấu trúc có thể chứa một cấu trúc khác. Trong một số ngôn ngữ, nó được gọi là thuộc tính, hoặc kiểu hỗn hợp. Các ngôn ngữ không có composition tường minh có thể mô tả nó theo nhiều kiểu khác nhau. Trong Java, người ta thường xử dụng *kế thừa* (inheritance) để mở rộng một cấu trúc có sẵn:

```java
public class Person {
  private String name;

  public String getName() {
    return this.name;
  }
}

public class Saiyan {
  // Saiyan chắc chắn phải là một đối tượng person
  private Person person;

  // Chúng ta chuyển tiếp tới person
  public String getName() {
    return this.person.getName();
  }
  ...
}
```

Điều này khá nhàm chán. Tất cả các phương thức của `Person` sẽ được nhân đôi trong `Saiyan`. Go sẽ cố gắng tránh điều này:

```go
type Person struct {
  Name string
}

func (p *Person) Introduce() {
  fmt.Printf("Hi, I'm %s\n", p.Name)
}

type Saiyan struct {
  *Person
  Power int
}

// and to use it:
goku := &Saiyan{
  Person: &Person{"Goku"},
  Power: 9001,
}
goku.Introduce()
```

Cấu trúc `Saiyan` có một trường có kiểu dữ liệu `*Person`. Vì chúng ta không khai báo tường minh tên của trường, chúng ta có thể truy cập không tường minh các trường và phương thức của các kiểu dữ liệu được tích hợp bên trong. Tuy nhiên, trình biên dịch Go *đặt* một tên trường cho nó khi biên dịch, điều này được xem là hoàn toàn hợp lệ:

```go
goku := &Saiyan{
  Person: &Person{"Goku"},
}
fmt.Println(goku.Name)
fmt.Println(goku.Person.Name)
```

Cả hai dòng lệnh trên đều in ra "Goku".

Liệu kiểu tổ hợp (composition) có tốt hơn kế thừa (inheritance) không? Nhiều người nghĩ rằng đây là một cách tiện lợi và nhanh chóng để chia sẻ mã nguồn. Khi sử dụng kế thừa, lớp của bạn được gắn với lớp cha, và hình thành một cách phân chia theo kiểu phân cấp chứ không phải theo chức năng.

### Overloading trong Go

Dù overloading không dành cho cấu trúc, nhưng nó vẫn đáng được nêu ra. Một cách đơn giản, Go không hỗ trợ overloading. Vì lý do này, bạn sẽ thấy có rất nhiều hàm như sau: `Load`, `LoadById`, `LoadByName` ...

Tuy nhiên, vì cho phép kết hợp không tường minh của các cấu trúc với nhau, chúng ta có thể dùng mẹo sau để "ghi đè" các hàm của một cấu trúc. Ví dụ, cấu trúc `Saiyan` có thể có hàm `Introduce` của riêng nó:

```go
func (s *Saiyan) Introduce() {
  fmt.Printf("Hi, I'm %s. Ya!\n", s.Name)
}
```

Cấu trúc mới có thể truy cập hàm cũ như sau `s.Person.Introduce()`.

## Con trỏ và giá trị

Khi viết mã Go, bạn có thể sẽ tự hỏi *khi nào nên dùng giá trị, khi nào thì dùng con trỏ?* Trước hết, câu trả lời là giống nhau, trừ một trong các tình huống sau:

* Gán một biến cục bộ
* Thay đổi trường của một cấu trúc
* Giá trị trả về của một hàm
* Tham số của một hàm
* receiver của một phương thức

Sau đó, nếu bạn vẫn không chắc chắn, hãy dùng con trỏ.

Như chúng ta thấy, truyền một giá trị cho hàm là cách để giá trị đó không thay đổi được (các thay đổi bên trong hàm sẽ không làm thay đổi đến các giá trị bên ngoài hàm). Đôi khi, cách xử lý này là cách mà bạn muốn.

Thậm chí nếu bạn không muốn thay đổi dữ liệu, hãy xem xét chi phí để tạo một bản sao của một cấu trúc lớn. Ngược lại, bạn có các cấu trúc nhỏ, ví dụ:

```go
type Point struct {
  X int
  Y int
}
```

Trong trường hợp này, chi phí của việc sao chép cấu trúc là có thể bù đắp được bằng việc có thể truy cập `x` và `y` trực tiếp.

Một lần nữa, đây là tất cả các tình huống khá tinh tế. Bạn sẽ quen với điều này nếu trải nghiệm hàng nghìn hoặc hàng chục nghìn tình huống tương tự.

## Trước khi đọc tiếp

Tóm lại, chương này giới thiệu các cấu trúc, làm thế nào để tạo một receiver cho một hàm, và chúng ta biết thêm được kiểu dữ liệu con trỏ trong Go. Các chương sau sẽ xây dựng trên những gì chúng ta biết về cấu trúc cũng như các hoạt động bên trong mà chúng ta đã tìm hiểu.


