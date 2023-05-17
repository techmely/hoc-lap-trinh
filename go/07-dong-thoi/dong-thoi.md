---
title: "Lập trình tính toán đồng thời trong Go"
description: "Go được mô tả là một ngôn ngữ hỗ trợ lập trình tính toán đồng thời. Nó có một cú pháp đơn giản để hỗ trợ điều này. Go sử dụng hai cơ chế sau để thực hiện tính toán đồng thời: goroutines và channels."
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
  name: "Lập trình tính toán đồng thời trong Go"
  slug: "chuong-07-lap-trinh-tinh-toan-dong-thoi-trong-go" 
category:
  name: "Go"
  slug: "go"
image: https://kungfutech.edu.vn/thumbnail.png
position: 1
---
(Người dịch: trong tiếng Anh Concurrency có nghĩa là thực hiện nhiều việc trong cùng một khoảng thời gian. Có người sẽ dịch Concurrency là song song. Riêng tôi cho rằng, song song có nghĩa là hai hoặc nhiều việc cũng được thực hiện trong cùng một thời điểm. Điều này khác với bản chất của Go và mô hình xử lý đa luồng M:N. Nếu 2 Goroutine nằm trên 2 luồng hệ điều hành, thì có thể coi là chúng hoạt động song song. Nếu chúng cùng nằm trên 1 luồng của hệ điều hành, thì không thể coi là hoạt động song song được. Chúng ta chỉ biết rằng, trong một khoảng thời gian xác định, chắc chắn cả hai Goroutine đều được thực thi. Do đó trong chương này, tôi sẽ dùng từ `đồng thời`. )

Go được mô tả là một ngôn ngữ hỗ trợ lập trình tính toán đồng thời. Nó có một cú pháp đơn giản để hỗ trợ điều này. Go sử dụng hai cơ chế sau để thực hiện tính toán đồng thời: goroutines và channels.

## Goroutines trong Go

Goroutine (Tiến trình Go) gần tương tự như luồng (thread), nhưng nó được kiểm soát thực thi bởi Go, chứ không phải hệ điều hành. Đoạn mã sau chạy một goroutine có thể thực thi đồng thời với các đoạn mã khác. Hãy xem ví dụ đơn giản sau:

```go
package main

import (
  "fmt"
  "time"
)

func main() {
  fmt.Println("start")
  go process()
  time.Sleep(time.Millisecond * 10) // rất tệ, đừng làm thế!
  fmt.Println("done")
}

func process() {
  fmt.Println("processing")
}
```

Điểm quan trọng là chúng ta bắt đầu một goroutine như thế nào. Chúng ta chỉ cần sử dụng từ khóa `go`, theo sau đó là hàm cần thực thi. Nếu chúng ta chỉ muốn thực thi mã, giống như ở trên, mà không phải định nghĩa một hàm mới, chúng ta có thể dùng hàm ẩn danh (anonymous function), loại hàm này không phải chỉ dùng được với goroutine.

```go
go func() {
  fmt.Println("processing")
}()
```

Goroutine sẽ tiêu tốn tài nguyên một chút. Nhiều hàm goroutine có thể cùng hoạt động trên một luồng của OS. Mô hình này thường được gọi là mô hình đa luồng M:N vì chúng ta có M goroutine chạy trên N luồng của hệ điều hành. Kết quả là một goroutine sẽ sử dụng ít tài nguyên (một vài kB) hơn một luồng của hệ điều hành. Trên các hệ thống phần cứng hiện đại, có thể có hàng triệu goroutine.

Hơn nữa, sự phức tạp của cơ chế ánh xạ và lập lịch sẽ được ẩn đi. Chúng ta chỉ cần nói *các đoạn mã này nên chạy đồng thời* và để cho Go thực hiện chúng.

Quay trở lại ví dụ trên, bạn sẽ thấy chúng ta có hàm `Sleep` trong một vài mili giây. Bởi vì tiến trình chính kết thúc trước khi goroutine có cơ hội thực thi (hàm main không đợi cho đến khi tất cả các Goroutine kết thúc).

## Đồng bộ hóa trong Go

Tạo một goroutine khá bình thường, chính vì chúng cần ít tài nguyên nên ta có thể tạo ra nhiều tiến trình như vậy, tuy nhiên các đoạn mã đồng thời cần liên lạc và có thể phối hợp với nhau. Để giải quyết vấn đề này, Go cung cấp `channels`. Trước khi tiếp cận `channels`, tôi thấy hiểu một chút về lý thuyết lập trình đồng thời là rất quan trọng.

Viết các đoạn mã đồng thời yêu cầu bạn quan tâm đến khi nào bạn đọc và khi nào ghi các giá trị. Theo cách khác, nó giống như lập trình mà không có bộ dọn rác. Nó yêu cầu bạn nghĩ về dữ liệu ở một góc độ mới, và luôn đề phòng những thao tác nguy hiểm. Ví dụ:

```go
package main

import (
  "fmt"
  "time"
)

var counter = 0

func main() {
  for i := 0; i < 20; i++ {
    go incr()
  }
  time.Sleep(time.Millisecond * 10)
}

func incr() {
  counter++
  fmt.Println(counter)
}
```

Bạn nghĩ kết quả hiển thị là gì?

Nếu bạn nói kết quả là `1, 2, ... 20` bạn vừa đúng lại vừa sai. Có thể bạn chạy đoạn mã trên, kết quả hiển thị cũng tương tự như thế. Tuy nhiên sự thật là hoạt động của chương trình không thể biết trước được. Tại sao? Bởi vì có thể có nhiều Goroutine (trường hợp này là hai) cùng ghi vào một biến `counter`, trong cùng một lúc. Hoặc, một Goroutine có thể đọc `counter` trong khi tiến trình còn lại đang ghi vào đó.

Điều đó có nguy hiểm không? Có, tất nhiên là rất nguy hiểm. `counter++` giống như là 1 dòng code, nhưng nếu chia nhỏ ra, thì nó là nhiều dòng hợp ngữ -- thứ chạy trực tiếp trên máy tính của bạn. Nếu chạy ví dụ này, bạn sẽ thấy một hàng số được hiển thị, hoặc bị lặp, hoặc bị mất. Tuy nhiên, một trường hợp có thể xảy ra là nếu 2 luồng cùng đọc lúc `counter` bằng `0` và bạn sẽ nhận được kết quả `1, 1`. Có nhiều tình huống còn tồi tệ hơn, ví dụ như hệ thống bị lỗi hoặc truy cập vào một vùng nhớ bất kì và thay dổi nó!

Chỉ có đọc dữ liệu từ một biến có thể thực hiện đồng thời mà vẫn an toàn. Bạn có thể đọc từ nhiều luồng khác nhau, nhưng nếu ghi dữ liệu thì bạn phải sử dụng đồng bộ hóa. Có nhiều cách để làm như thế, bao gồm dùng các hành động nguyên tố (atomic operation) dựa trên một vài lệnh đặc biệt của CPU. Tuy nhiên, cách tiếp cận chung nhất là sử dụng mutex:

```go
package main

import (
  "fmt"
  "time"
  "sync"
)

var (
  counter = 0
  lock sync.Mutex
)

func main() {
  for i := 0; i < 20; i++ {
    go incr()
  }
  time.Sleep(time.Millisecond * 10)
}

func incr() {
  lock.Lock()
  defer lock.Unlock()
  counter++
  fmt.Println(counter)
}
```

Một mutex có thể truy cập tuần tự vào đoạn mã thông qua một khóa. Chúng ta có thể khai báo đơn giản trong mã nguồn như sau `lock sync.Mutex`, giá trị mặc định của `sync.Mutex` là chưa khóa.

Trông có vẻ đơn giản? Có một lớp các lỗi nghiêm trọng sinh ra trong quá trình lập trình đồng thời. Tất nhiên, không phải lúc nào cũng như vậy, nhưng rõ ràng rằng các đoạn mã trong chương trình cần được bảo vệ để đảm bảo nó có thể chạy đúng. Nó có thể được bảo vệ bằng cách sử dụng khóa (khóa sẽ bao quanh đoạn mã cần được bảo vệ), tuy nhiên, bằng cách này thì sẽ làm mất đi ý nghĩa của lập trình đồng thời mà chúng ta đang đề cập. Chúng ta sử dụng khóa cũng giống như chúng ta sẽ không đi trên đường cao tốc mười làn xe, mà quay về đường chỉ có một làn.

Một vấn đề khác hay gặp phải là deadlock**s** (lưu ý là tôi sử dụng số nhiều -- người dịch). Với một khóa đơn, vấn đề này không xảy ra nhưng nếu sử dụng nhiều hơn một khóa để tác động vào cùng một đoạn mã, thì vấn đề này thật sự nghiêm trọng. Khi tiến trình A giữ khóa A nhưng cần truy cập vào khóa B nhưng tiến trình B đang giữ khóa B và lại phải truy cập vào khóa A.

Vấn đề này cũng có thể xảy ra với một khóa đơn, nếu chúng ta khóa và quên không mở khóa. Điều đó không thực sự quá nghiêm trọng như sử dụng nhiều khóa vì lỗi này **rất dễ** phát hiện nhưng bạn có thể xem chuyện gì xảy ra nếu chạy đoạn mã sau:

```go
package main

import (
  "time"
  "sync"
)

var (
  lock sync.Mutex
)

func main() {
  go func() { lock.Lock() }()
  time.Sleep(time.Millisecond * 10)
  lock.Lock()
}
```

Có nhiều cách để lập trình đồng thời hơn chúng ta vừa xem. Ví dụ, có một mutex khác được gọi là mutex đọc ghi (read-write mutex). Nó cho thấy có 2 chức năng có thể khóa: một để khóa trước khi đọc và một để khóa trước khi ghi. Sự phân biệt này cho phép nhiều tiến trình đọc đồng thời trong khi không cho phép bất cứ một tiến trình nào thực hiện ghi dữ liệu. Trong Go, `sync.RWMutex` là một khóa như vậy. Thêm vào đó, hàm `Lock` và `Unlock` của `sync.Mutex`, cũng ch thấy có hai hàm `RLock` và `RUnlock` ; trong đó `R` có nghĩa là *Read*. Trong khi các mutex đọc ghi được sử dụng phổ biến, chúng à một gánh năng cho lập trình viên, : chúng ta phải quan tâm không chỉ là lúc nào thao tác với dữ liệu mà còn quan tâm tới phương thức truy cập là đọc hay ghi.

Hơn nữa, một phần của lập trình đồng thời không phải là truy cập tuần tự vào phần hẹp nhất của đoạn mã, nó còn là cách phối hợp giữa nhiều tiến trình với nhau. Ví dụ, tạm dựng hoạt động 10 mili giây giây không phải là một giải pháp hợp lý. Chuyện gì sẽ xảy ra nếu một tiến trình cần nhiều hơn 10 mili giây? Nếu nó cần ít hơn 10 mili giây, thì chúng ta đang lãng phí thời gian? Ngoài ra, thay vì đợi cho luông xử lý khác kết thúc, tôi muốn hiển thị *này, Tôi có dữ liệu mới để xử lý đây!* thì phải làm thế nào?

Trên đây là tất cả các thứ có thể làm được mà không cần `channels`. Với trường hợp đơn giản, tôi nghĩ bạn **nên dùng** các thành phần cơ bản như `sync.Mutex` và `sync.RWMutex`, nhưng trong phần kế tiếp, `channels` sẽ làm cho lập trình đồng thời trong sáng hơn và ít lỗi.

## Channels trong Go

Thách thức với lập trình đồng thời xuất phát từ chia sẻ dữ liệu. Nếu các goroutine không chia sẻ dữ liệu, bạn không cần phải lo lắng về việc đồng bộ hóa chúng. Đó không phải là một lựa chọn cho tất cả các hệ thống. Trong thực tế, nhiều hệ thống được xây dựng với mục tiêu ngay từ đầu là: có thể chia sẻ dữ liệu giữa các thành phần với nhau. Một bộ nhớ cache hoặc một cơ sở dữ liệu, là những ví dụ tốt về điều này. Điều này đang trở thành một thực tế ngày càng phổ biến.

Channel (kênh) giúp cho lập trình đồng thời lập trình dễ hơn. Một channel là một pipe giao tiếp giữa các goroutine, và được sử dụng để truyền dữ liệu. Nói cách khác, một goroutine có dữ liệu chuyển dữ liệu cho một goroutine khác thông qua một channel. Kết quả là, tại bất kỳ thời điểm nào, chỉ có một goroutine có quyền truy cập vào dữ liệu.

Channel cũng cần phải xác định kiểu. Đây là kiểu dữ liệu mà chúng ta sẽ truyền qua channel. Ví dụ, để tạo một channel có thể được sử dụng để truyền một số nguyên, chúng ta sẽ làm như sau:

```go
c := make(chan int)
```

Loại channel này là `chan int`. Vì vậy, để truyền qua channel này đến một hàm, signature của hàm như sau:

```go
func worker(c chan int) { ... }
```

Các channel hỗ trợ hai thao tác: nhận (receive) và gửi (send). Chúng ta gửi dữ liệu đến channel bằng cách:

```
CHANNEL <- DATA
```

và nhận bằng cách

```
VAR := <-CHANNEL
```

Mũi tên chỉ hướng đi của dữ liệu. Khi gửi, dữ liệu được truyền vào channel. Khi nhận, dữ liệu được lấy ra khỏi channel.

Điều cuối cùng cần biết trước khi chúng ta nhìn vào ví dụ đầu tiên là nhận và gửi từ một channel là một quá trình chờ (blocking). Đó là, khi chúng ta nhận từ một channel, goroutine sẽ chờ cho đến khi dữ liệu đã sẵn sàng. Tương tự như vậy, khi chúng ta gửi vào một channel, goroutine sẽ chờ cho đến khi dữ liệu được nhận.

Hãy xem xét một hệ thống xử lý dữ liệu đến mà chúng ta muốn xử lý trong các goroutine riêng biệt. Đây là một yêu cầu chung. Nếu chúng ta xử lý dữ liệu ngay trên goroutine mà chấp nhận kết nối đến, chúng ta sẽ có nguy cơ các client bị chờ quá lâu. Đầu tiên, chúng ta sẽ viết worker (có nghĩa là hàm xử lý dữ liệu nhận được -- người dịch) . Đây có thể là một hàm đơn giản, nhưng tôi sẽ làm cho nó một cấu trúc cho nó:

```go
type Worker struct {
  id int
}

func (w Worker) process(c chan int) {
  for {
    data := <-c
    fmt.Printf("worker %d got %d\n", w.id, data)
  }
}
```

Worker rất đơn giản. Nó chờ đợi cho đến khi dữ liệu sẵn sàng sau đó "process" nó. Nó hoạt động trong một vòng lặp vô hạn và sẽ chờ thêm dữ liệu để xử lý.

Để sử dụng, điều đầu tiên chúng ta làm là tạo và chạy một vài worker:

```go
c := make(chan int)
for i := 0; i < 5; i++ {
  worker := &Worker{id: i}
  go worker.process(c)
}
```

Và sau đó cho chúng một chút dữ liệu:

```go
for {
  c <- rand.Int()
  time.Sleep(time.Millisecond * 50)
}
```

Đây là toàn bộ mã nguồn:

```go
package main

import (
  "fmt"
  "time"
  "math/rand"
)

func main() {
  c := make(chan int)
  for i := 0; i < 5; i++ {
    worker := &Worker{id: i}
    go worker.process(c)
  }

  for {
    c <- rand.Int()
    time.Sleep(time.Millisecond * 50)
  }
}

type Worker struct {
  id int
}

func (w *Worker) process(c chan int) {
  for {
    data := <-c
    fmt.Printf("worker %d got %d\n", w.id, data)
  }
}
```
Chúng ta không biết worker nào đang lấy dữ liệu. Những gì chúng ta biết, những gì Go đảm bảo, là dữ liệu được chúng ta gửi cho channel sẽ chỉ được nhận bởi một worker duy nhất.

Chú ý rằng thứ được chia sẻ chỉ là channel, chúng ta có thể gửi và nhận dữ liệu đồng thời một cách an toàn. Các channel cung cấp các mã đồng bộ, chúng ta cần và cũng đảm bảo rằng, tại bất kỳ thời điểm nào, chỉ có một goroutine có quyền truy cập vào một phần cụ thể của dữ liệu.

### Buffered Channels

Với đoạn mã trên, chuyện gì sẽ xảy ra nếu chúng ta có nhiều dữ liệu đi vào hơn chúng ta có thể xử lý? Bạn có thể mô phỏng này bằng cách thay đổi các worker, cho chúng tạm dừng sau khi nó đã nhận được dữ liệu:

```go
for {
  data := <-c
  fmt.Printf("worker %d got %d\n", w.id, data)
  time.Sleep(time.Millisecond * 500)
}
```

Trong hàm xử lý chính, là hàm nhận dữ liệu của người dùng (mà chúng ta vừa mô phỏng với một bộ tạo số ngẫu nhiên) sẽ bị block, không thể gửi được, do không có worker nào đang chờ xử lý.

Trong trường hợp bạn cần phải đảm bảo rằng dữ liệu phải được xử lý, có thể bạn sẽ muốn tạm dừng tiếp nhận dữ liệu từ phía client. Trong trường hợp khác, bạn có thể sẵn sàng nới lỏng những đảm bảo. Có một vài cách phổ biến để làm điều này. Đầu tiên là bộ đệm dữ liệu. Nếu không có worker đang chờ, chúng ta muốn tạm thời lưu trữ các dữ liệu trong một loại hàng đợi. Channel có này khả năng lưu tạm thời các dữ liệu. Khi chúng ta tạo ra channel bằng `make`, chúng ta có thể cung cấp kích thước cho channel:

```go
c := make(chan int, 100)
```

Bạn có thể thực hiện thay đổi này, nhưng bạn sẽ nhận thấy rằng việc xử lý vẫn bị không hoàn toàn trọn vẹn. Buffered channel không cung cấp thêm khả năng cho worker; mà chỉ đơn thuần cung cấp một hàng đợi để lưu trữ tạm thời trong tình huống dữ liệu nhiều lên đột ngột. Trong ví dụ của chúng ta, chúng ta đang liên tục đẩy thêm nhiều dữ liệu hơn so với khả năng mà worker có thể xử lý.

Tuy nhiên, chúng ta có thể kiểm tra buffered channel bằng cách xem `len` của channel:

```go
for {
  c <- rand.Int()
  fmt.Println(len(c))
  time.Sleep(time.Millisecond * 50)
}
```
Bạn có thể thấy nó tăng dần cho đến khi nó đầy, lúc này nếu dữ liệu được gửi đến đầu channel, thì sẽ không tiếp tục được.

### Select trong Go

Ngay cả với buffered channel, sẽ đến một thời điểm mà chúng ta cần phải bắt đầu không nhận được dữ liệu. Chúng ta không thể để bộ nhớ tăng vô hạn và hy vọng woker sẽ giải quyết nó. Đối với việc này, chúng ta sử dụng `select`.

`select` hơi giống như switch. Trước tiên, hãy xóa buffered channel để chúng ta có thể nhìn thấy rõ cách `select` hoạt động:

```go
c := make(chan int)
```

Tiếp theo, chúng ta sửa vòng lặp `for`:

```go
for {
  select {
  case c <- rand.Int():
    //các mã khác ở đây
  default:
    //dòng này để trống để không xử lý dữ liệu
    fmt.Println("dropped")
  }
  time.Sleep(time.Millisecond * 50)
}
```
Chúng ta đang đẩy 20 tin nhắn mỗi giây, nhưng worker chỉ có thể xử lý 10 mỗi giây; do đó, một nửa các thông điệp sẽ không được xử lý.

Đây chỉ là bắt đầu của những gì chúng ta có thể làm với `select`. Mục đích chính của `select` là để quản lý nhiều channel. Với nhiều channel, `select` sẽ đưa hệ thống vào trạng thái chờ cho đến khi có một channel khả dụng. Nếu không có channel, `default` được sử dụng. Một channel được lựa chọn ngẫu nhiên trong các channel có thể sử dụng.

Thật khó để đưa ra một ví dụ đơn giản thể hiện cách xử lý này vì nó là một tính năng khá tiên tiến. Các phần tiếp theo có thể giúp minh họa cho select.

### Timeout trong Go

Chúng ta xử lý các tin nhắn được lưu tạm thời cũng tương tự như cách không xử lý chúng. Một tùy chọn khác phổ biến là để thời gian chờ. Chúng ta có thể không nhận dữ liệu trong một khoảng thời gian, nhưng không phải mãi mãi. Việc này rất dễ làm trong Go. Phải thừa nhận rằng, cú pháp có thể hơi khó hiểu, nhưng nó là một tính năng rất hữu ích.

Để ngừng xử lý trong một khoảng thời gian, chúng ta có thể dùng hàm `time.After`. Để sử dụng, viết đoạn mã như sau:

```go
for {
  select {
  case c <- rand.Int():
  case <-time.After(time.Millisecond * 100):
    fmt.Println("timed out")
  }
  time.Sleep(time.Millisecond * 50)
}
```

`time.After` trả về một channel, do đó chúng ta có thể `select` từ channel. Channel sẽ được đẩy dữ liệu vào sau một khoảng thời gian chờ. Không có gì là ma thuật ở đây cả. Nếu bạn thắc mắc, thì cách xây dựng hàm `after` trông như thế này:

```go
func after(d time.Duration) chan bool {
  c := make(chan bool)
  go func() {
    time.Sleep(d)
    c <- true
  }()
  return c
}
```

Trở lại với `select`, có một số thứ mà bạn có thể xem qua. Đầu tiên, chuyện gì sẽ xảy ra nếu bạn thêm `default` vào đó? Bạn có thể đoán? Hãy thử nó. Nếu bạn không chắc chắn những gì đang xảy ra, hãy nhớ rằng `default` được gọi ngay lập tức nếu không có channel nào đang sẵn sàng.

Ngoài ra, `time.After` là một channel có kiểu `chan time.Time`. Trong ví dụ trên, chúng ta chỉ đơn giản là loại bỏ các giá trị đã được gửi đến channel. Nếu muốn, bạn có thể nhận:

```go
case t := <-time.After(time.Millisecond * 100):
  fmt.Println("timed out at", t)
```

Hãy chú ý đến `select`. Chú ý rằng chúng ta đang gửi tới `c` nhưng nhận từ `time.After`. `Select` hoạt động như nhau bất kể chúng ta đang nhận, đang gửi, hoặc bất kỳ sự kết hợp của các channel:

* Các channel khả dụng đầu tiên được chọn.
* Nếu nhiều channel khả dụng, Go sẽ chọn ngẫu nhiên một cái.
* Nếu không có channel khả dụng, trường hợp mặc định được thực thi.
* Nếu không có mặc định, thì hệ thống sẽ vào trạng thái chờ.

Cuối cùng, `select` rất hay dùng bên trong một vòng lặp `for`. Xem đoạn mã sau:

```go
for {
  select {
  case data := <-c:
    fmt.Printf("worker %d got %d\n", w.id, data)
  case <-time.After(time.Millisecond * 10):
    fmt.Println("Break time")
    time.Sleep(time.Second)
  }
}
```

## Trước khi đọc tiếp

Nếu bạn mới biết đến lập trình đồng thời, có thể bạn sẽ rất bối rối. Nó cần thời gian để làm quen và tìm hiểu một cách sâu sắc. Go sinh ra để nhằm mục đích giảm thiểu những khó khăn này.

Goroutines cho phép bạn viết mã cho những gì cần chạy đồng thời. Các channel giúp loại bỏ một số lỗi nghiêm trọng có thể xảy ra khi dữ liệu được chia sẻ bằng cách loại bỏ việc chia sẻ dữ liệu. Điều này không chỉ loại bỏ lỗi, nhưng nó thay đổi cách lập trình đồng thời. Bạn suy nghĩ về tính đồng thời của dữ liệu, chứ không phải tính đồng thời trong quá trình xử lý.

Phải nói rằng, tôi vẫn sử dụng cách đồng bộ khá đơn giản trong gói `sync` và `sync/atomic`. Tôi nghĩ rằng điều quan trọng là tôi cảm thấy thoải mái. Tôi khuyên bạn tập trung vào các channel trước, nhưng khi bạn nhìn thấy một trường hợp đơn giản mà cần một khóa đơn, hãy thử sử dụng mutex hoặc mutex đọc-ghi .

# Kết luận

Có người mô tả Go là một ngôn ngữ *tẻ nhạt*. Tẻ nhạt vì nó dễ học, dễ viết và quan trọng là dễ đọc. Chúng ta *đã dành* ra 3 chương để nói về các kiểu dữ liệu, và cách khai báo các kiểu đó.

Nếu bạn có kiến thức về ngôn ngữ có kiểu dữ liệu tĩnh, hầu hết những gì chúng ta đã xem đều đầy đủ. Go cũng có con trỏ và slice trong Go chứng minh rằng không phải chỉ có Java hay C# mới làm được tính năng này.

Nếu bạn chủ yếu sử dụng ngôn ngữ động, bạn sẽ cảm thấy hơi khác một chút. Nó đáng để tìm hiểu. Không ít trong số đó là cú pháp khai báo và khởi tạo khác nhau. Dù là một fan hâm mộ của Go, tôi thấy rằng hầu hết các cải tiến đều theo hướng đơn giản hóa. Tuy nhiên, một số thứ lại bị phức tạp hóa (như bạn chỉ có thể khai báo biến một lần và `:=` dùng khai báo biến) và một vài khái niệm cơ bản (như `new(X)` hoặc `&X{}` chỉ cấp phát bộ nhớ, nhưng slice, map và các channel cần nhiều khởi tạo hơn, `make`).

Ngoài ra, Go tạo ra một cách đơn giản nhưng hiệu quả để tổ chức mã nguồn. Interface, xử lý lỗi thông qua giá trị trả về, `defer` cho quản lý tài nguyên và một cách đơn giản tạo một cấu trúc tổ hợp.

Cuối cùng, Go hỗ trợ sẵn cơ chế lập trình đồng thời. Khó có thể dùng một từ nào để mô tả về goroutine, ngoại trừ hiệu quả và đơn giản (đơn giản vì sử dụng thế nào cũng được). Đó là khái niệm trừu tượng. Các channel thì phức tạp hơn. Tôi luôn nghĩ rằng điều quan trọng là phải hiểu mô hình cơ bản trước khi sử dụng các lớp bao quanh ở mức cao. Tôi *nghĩ* học lập trình đồng thời không dùng channel sẽ rất tốt. Tuy nhiên, các channel đã được xây dựng sẵn, với tôi, không thấy giống như một khái niệm trừu tượng đơn giản. Tôi nói điều này bởi vì chúng thay đổi cách bạn viết và suy nghĩ về lập trình đồng thời. Nó giải quyết các vấn đề khó trong lập trình đồng thời, và chắc chắn là thứ tuyệt vời.