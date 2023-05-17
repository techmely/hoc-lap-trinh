---
title: "Gói"
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
position: 1
---
Để có thể xây dựng được những thư viện phức tạp, chúng ta cần tìm hiểu về khái niệm gói (packages). Trong Go, mỗi gói được đặt tên theo cấu trúc của thử mục trong workspace. Nếu chúng ta xây dựng một hệ thống bán hàng, chúng ta thường bắt đầu bằng một gói có tên là "shopping" và đặt các file mã nguồn trong thư mục `$GOPATH/src/shopping/`.

Chúng ta không muốn đặt tất cả mọi thứ bên trong thư mục này. Ví dụ, có thể chúng ta muốn đặt một vài thành phần thuộc về cơ sở dữ liệu vào một thư mục khác. Để đạt điều đó, chúng ta tạo một thử mục con `$GOPATH/src/shopping/db`. Tên của gói của các file trong thư mục con này, đơn giản là `db`, nhưng để truy cập  nó từ một gói khác, kể cả là gói `shopping` chúng ta cần sử dụng lệnh import `shopping/db`.

Nói cách khác, khi bạn đặt tên một gói, thông qua từ khóa `package`, bạn cung cấp một giá trị đơn, không phải là một đường dẫn đầy đủ (ví dụ, "shopping" hoặc "db"). Khi bạn sử dụng một gói, bạn cần chỉ đường dẫn đẩy đủ đến gói đó.

Trong thư mục `src` nằm bên trong workspace (thư mục chúng ta dùng để cài đặt ở phần đầu tiên của cuốn sách này), tạo một thư mục mới và đặt tên là `shopping` và một thư mục con bên trong nó, đặt tên là `db`.

Trong thư mục `shopping/db`, tạo một file và đặt tên là `db.go` và chứa đoạn mã sau:

```go
package db

type Item struct {
  Price float64
}

func LoadItem(id int) *Item {
  return &Item{
    Price: 9.001,
  }
}
```

Chú ý rằng tên của gói phải trùng với tên của thư mục. Và cũng nhớ rằng, chúng ta vẫn chưa thực sự truy cập database, chúng ta chỉ dùng ví dụ này để mô tả cách tổ chức mã nguồn.

Bây giờ, hãy tạo một file có tên là `pricecheck.go` bên trong thư mục chính `shopping`. Nội dung của nó là:

```go
package shopping

import (
  "shopping/db"
)

func PriceCheck(itemId int) (float64, bool) {
  item := db.LoadItem(itemId)
  if item == nil {
    return 0, false
  }
  return item.Price, true
}
```

Thật lạ vì bạn đang thêm gói `shopping/db` trong khi chúng ta đang đứng bên trong thư mục `shopping`. Thực tế, đường dẫn khi import một gói sẽ là `$GOPATH/src/shopping/db`, có nghĩa rằng bạn có thể dễ dàng thêm gói `test/db` nếu bạn có một gói được đặt tên là `db` bên trong thư mục `src/test`.

Nếu bạn đang xây dựng một gói, bạn sẽ không cần làm thêm gì nữa, ngoài việc bố trí thư mục như trên. Để tạo một file thực thi bạn cần một gói có tên `main`. Cách tôi thường dùng để làm việc này là tạo một thư mục có tên `main` bên trong thư mục `shopping` cùng với một file đặt tene là `main.go` và có nội dung như sau:

```go
package main

import (
  "shopping"
  "fmt"
)

func main() {
  fmt.Println(shopping.PriceCheck(4343))
}
```

Bây giờ bạn có thể chạy mã bằng cách chuyển tới thư mục của dự án `shopping` và gõ:

```
go run main/main.go
```

### Imports lồng nhau

Khi bạn bắt đầu xây dựng một hệ thống phức tạp hơn, bạn có thể gặp tình trạng import lồng nhau (cyclical imports). Điều này xảy ra nếu gói A import gói B nhưng gói B lại import chính gói A (một cách trực tiếp hoặc gián tiếp thông qua các gói khác). Trình biên dịch không cho phép điều này xảy ra.

Hãy thay đổi cấu trúc của hệ thống shopping và khiến nó bị lỗi.

Chuyển định nghĩa `Item` từ `shopping/db/db.go` sang `shopping/pricecheck.go`. File `pricecheck.go` của bạn sẽ trông thế này:

```go
package shopping

import (
  "shopping/db"
)

type Item struct {
  Price float64
}

func PriceCheck(itemId int) (float64, bool) {
  item := db.LoadItem(itemId)
  if item == nil {
    return 0, false
  }
  return item.Price, true
}
```

Nếu bạn thử chạy đoạn mã trên, bạn sẽ gặp một loạt các lỗi từ `db/db.go` vì `Item` chưa được định nghĩa. Điều đó là hiển nhiên. `Item` không còn nằm trong gói `db` nữa; nó đã được chuyển sang `shopping`. Chúng ta cần thay đổi một chút trong file `shopping/db/db.go` thành:

```go
package db

import (
  "shopping"
)

func LoadItem(id int) *shopping.Item {
  return &shopping.Item{
    Price: 9.001,
  }
}
```

Bây giờ khi bạn thử chạy mã, bạn sẽ nhận được thông báo lỗi *import cycle not allowed*. Chúng ta giải quyết vấn đề này bằng cách tạo ra một gói mới chứa các cấu trúc được chia sẻ giữa các gói với nhau. Cấu trúc thư mục sẽ là:

```bash
$GOPATH/src
  - shopping
    pricecheck.go
    - db
      db.go
    - models
      item.go
    - main
      main.go
```

`pricecheck.go` vẫn import `shopping/db`, nhưng `db.go` giờ sẽ import `shopping/models` thay vì `shopping`, do đó sẽ không bị lồng nhau. Vì chúng ta đâ chuyển cấu trúc `Item` sang file `shopping/models/item.go`, chúng ta cần thay đổiv `shopping/db/db.go` tham chiếu đến cấu trúc `Item` trong `models`:

```go
package db

import (
  "shopping/models"
)

func LoadItem(id int) *models.Item {
  return &models.Item{
    Price: 9.001,
  }
}
```

Bạn sẽ thường xuyên thấy sự chia sẻ các cấu trúc như thế này giống như gói `model`, do đó, bạn nên có một thư mục khác đặt tên là `utilities` hoặc thứ gì đó tương tự. Nguyên tắc quan trọng khi viết các gói chia sẻ này là chúng sẽ không import bất cứ một gói nào từ `shopping` hoặc các gói con của nó. Chúng ta sẽ xem xét cách interface được dùng để giảm thiểu các loại phụ thuộc này.

### Visibility trong Go

(Người dịch: nên hiểu là khả năng một thành phần nào đó của gói có thể được truy cập từ gói khác, do tiếng Việt không có từ tương đương nên không dịch)

Go sử dụng một luật đơn giản để xác định các kiểu dữ liệu hoặc các hàm có thể được truy cập từ ngoài gói chưa nó hay không. Nếu tên của kiểu hoặc hàm bắt đầu bằng kí tự in hoa, thì nó có thể truy cập được, ngược lại, nếu là kí tự thường thì không truy cập được từ các gói khác.

Điều này cũng đúng với các trường trong một cấu trúc. Nếu tên của một trường trong một cấu trúc bắt đầu bằng một kí tự thường thì chỉ có các đoạn code trong cùng một gói với nó có thể truy cập được.

Ví dụ, nếu `items.go` có một hàm như thế này:

```go
func NewItem() *Item {
  // ...
}
```

hàm đó có thể được gọi từ bên ngoài bằng lời gọi hàm `models.NewItem()`. Nhưng nếu hàm đó được đặt tên là `newItem`, chúng ta sẽ không sử dụng được nó từ một gói khác.

Bạn nãy thử thay đổi tên của các hàm, các trường trong mã nguồn của `shopping`. Ví dụ, nếu bạn đổi tên trường của `Item`: `Price` thành `price`, bạn sẽ gặp lỗi biên dịch.

### Quản lý các gói

Lệnh `go` chúng ta hay dùng là `run` và `build`, có một lệnh khác là `get` được dùng để lấy các thư viện của bên ngoài (third-party libraries). `go get` hỗ trợ nhiều giao thức khác nhau nhưng trong ví dụ này, chúng ta sẽ thử lấy các thư viện trong Github, có nghĩa là, bạn nên cài đặt `git` trong hệ thống.

Giả sử như bạn đã có git được cài trong hệ thống, từ shell/command prompt, nhập:

```
go get github.com/mattn/go-sqlite3
```

`go get` sẽ tải file từ internet về workspace của bạn. Kiểm tra thư mục `$GOPATH/src`. Ngoài ra, cùng cấp với thư mục của `shopping`, bạn sẽ thấy một thư mục tên là `github.com`. Bên trong nó, bạn sẽ thấy thư mục `mattn`, trong đó lại chứa `go-sqlite3`.

Chúng ta vừa nói về cách để import các gói thư viện trong workspace. Để sử dụng gói `go-sqlite3` vừa mới tải về, chúng ta làm như sau:

```go
import (
  "github.com/mattn/go-sqlite3"
)
```

Tôi biết là nó trông giống hnw một URL, nhưng nó sẽ import gói `go-sqlite3` nếu nó được tìm thấy trong thư mục `$GOPATH/src/github.com/mattn/go-sqlite3`.

### Quản lý các thành phần phụ thuộc

`go get` có một vài lệnh đặc biệt khác. Nếu chúng ta dùng `go get` bên trong một dự án, nó sẽ quét tất cả các file, tìm kiếm các thư viện khác đang được import và tải chúng. Theo cách này, mã nguồn của chúng tớ trông giống như một `Gemfile` hoặc `package.json`.

Nếu bạn gọi `go get -u` nó sẽ cập nhật các gói (hoặc bạn cũng có thể cập nhật một gói được chỉ định bằng cách `go get -u TÊN_ĐẦY_ĐỦ_CỦA_GÓI_CẦN_CẬP_NHẬT`).

Cuối cùng, bạn có thể thấy `go get` vẫn chưa hoàn chỉnh. Ví dụ, không có cách nào để chỉ định một phiên bản (revision), nó luôn trỏ về `master/head/trunk/default`. Điều này sẽ là vấn đề lớn nếu bạn có hai dự án cần hai phiên bản khác nhau của cùng một thư viện.

Để giải quyết vấn đề này, bạn có thể sử dụng công cụ quản lý phiên bản thư viện. Chúng còn khá mới [goop](https://github.com/nitrous-io/goop) và [godep](https://github.com/tools/godep). Danh sách các công cụ tương tự ở đây [go-wiki](https://code.google.com/p/go-wiki/wiki/PackageManagementTools).


