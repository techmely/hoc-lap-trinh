---
title: "Giới thiệu về ngôn ngữ Go"
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
  name: "Giới thiệu về ngôn ngữ Go"
  slug: "chuong-01-gioi-thieu-ve-go"
category:
  name: "Go"
  slug: "go"
image: https://kungfutech.edu.vn/thumbnail.png
position: 1
---
# Giới thiệu
Tôi quan tâm việc học ngôn ngữ mới. Một mặt, ngôn ngữ rất gần với những gì chúng ta làm, ngay cả những thay đổi nhỏ có thể có tác động nhìn thấy được. Một thay đổi nhỏ sẽ ảnh hưởng tới cách bạn lập trình và cách bạn suy nghĩ trong các ngôn ngữ khác. Ngôn ngữ mới được cài tiến. Học từ khoá mới, hệ thống kiểu dữ liệu, phong cách viết mã cũng như các thư viện mới, các cộng đồng và mô hình được xem là một công việc không nhỏ. So với tất cả mọi thứ khác chúng ta phải học, học ngôn ngữ mới thường được xem là rất mất thời gian.

Do đó, chúng ta *phải* cố gắng. Chúng ta *phải* sẵn sàng để thực hiện các bước thay đổi vì, một lần nữa, ngôn ngữ là nền tảng của những gì chúng ta làm. Mặc dù những thay đổi này thường tăng thêm. Chúng có xu hướng tác động tới phạm vi rộng và chúng ảnh hưởng đến năng suất, khả năng đọc, hiệu suất, khả năng kiểm thử, quản lý phụ thuộc, xử lý lỗi, tài liệu, hồ sơ, cộng đồng phát triển, thư viện chuẩn, ... Nói theo cách tích cực *death by a thousand cuts*? (Người dịch: Đây là tên của một cuốn sách).

Chúng ta có một câu hỏi quan trọng: **Vì sao chọn Go?** Đối với tôi, có hai lý do hấp dẫn. Việc đầu tiên là nó là một ngôn ngữ khá đơn giản với một thư viện tiêu chuẩn. Cải tiến của Go là đơn giản hóa những thứ phức tạp được thêm vào ngôn ngữ lập trình trong vài thập kỷ gần đây. Lý do khác là đối với nhiều nhà phát triển, nó sẽ bổ sung cho kho công cụ hiện có.

Go được xây dựng như một ngôn ngữ lập trình hệ thống (ví dụ, hệ điều hành, trình điều khiển thiết bị) và do đó nó hướng tới các lập trình viên quen với C và C++. Theo nhóm phát triển Go, không phải người phát triển hệ thống mà là các nhà phát triển ứng dụng sẽ trở thành những người sử dụng Go chủ yếu. Tại sao? Tôi không thể nói thay cho các nhà phát triển hệ thống, nhưng đối với những người xây dựng trang web, dịch vụ, các ứng dụng máy tính để bàn, các nhu cầu mới xuất hiện cho một lớp của các hệ thống mà đứng ở giữa các ứng dụng hệ thống cấp thấp và ứng dụng cấp cao hơn.

Có thể đó là hệ thống nhắn tin, caching, phân tích dữ liệu tính toán lớn, chương trình dòng lệnh, ghi log hoặc giám sát. Tôi không biết các cách khác nhau để đặt tên cho nó, nhưng trong quá trình làm việc của tôi, các hệ thống ngày càng trở nên phức tạp và phải phục vụ nhiều hoạt động đồng thời, việc cấp phát tài nguyên cho nhu cầu mở rộng hệ thống tăng lên. Bạn *có thể* xây dựng hệ thống như vậy với Ruby hay Python hay thứ gì khác (nhiều người làm thế), nhưng các loại hệ thống này có thể được hưởng lợi từ một hệ thống kiên cố hơn và hiệu suất cao hơn. Tương tự như vậy, bạn *có thể* sử dụng Go để xây dựng các trang web (nhiều người chọn cách này), nhưng tôi vẫn thích, Node hay Ruby cho hệ thống như vậy.

Có những lĩnh vực mà Go tỏ ra vượt trội. Ví dụ, một chương trình Go sẽ không cần thư viện đi kèm. Bạn không cần phải lo lắng nếu người dùng của bạn đã cài đặt Ruby hoặc JVM hoặc quan tâm tới phiên bản của chúng. Vì lý do này, Go ngày càng trở nên phổ biến như là một ngôn ngữ cho chương trình giao diện dòng lệnh và các loại chương trình khác bạn cần triển khai (ví dụ, một chương trình thu thập log).

Rõ ràng, học Go là một phương án hợp lý. Bạn sẽ không phải mất nhiều giờ học hoặc và làm chủ Go, và bạn sẽ đạt được kết quả thiết thực.

## Lưu ý của tác giả

Tôi đã lưỡng lự khi viết quyển sách này vì vài lý do. Đầu tiên là tài liệu gốc của Go, đặc biệt là [Effective Go](https://golang.org/doc/effective_go.html), rất chi tiết.

Một cản trở khác là sự khó chịu của tôi lúc viết một cuốn sách về một ngôn ngữ lập trình. Khi tôi viết The Little MongoDB Book, tôi đã giả định rằng hầu hết người đọc hiểu những điều cơ bản của cơ sở dữ liệu quan hệ và mô hình hóa. Với The Little Redis Book, có thể giả định bạn đã quen với lưu và đọc dữ liệu từ một khóa.

Khi tôi bắt đầu viết các đoạn và các chương đầu tiên, tôi biết rằng tôi sẽ không thể giả định tương tự thế. Cần bao nhiêu thời gian để mô tả về interface cho các độc giả về khái niệm này, trong khi những người khác sẽ chỉ cần biết *Go hỗ trợ interface?* Cuối cùng, tôi quyết định các bạn sẽ cho tôi biết phần nào của quyển sách quá hời hợt trong khi phần nào lại quá chi tiết.

# Mở đầu

Nếu bạn đang muốn thử dùng Go, bạn nên xem qua [Go Playground](https://play.golang.org/). Nó cho phép người dùng chạy mã trực tiếp trên trình duyệt mà không cần phải cài đặt bất cứ thứ gì. Đây cũng là cách chung nhất để chia sẻ mã nguồn Go trên các trang cộng đồng như [Diễn đàn thảo luận của Go](https://groups.google.com/forum/#!forum/golang-nuts) và những nơi như StackOverflow.

Cài đặt Go khá đơn giản. Bạn có thể cài đặt nó từ mã nguồn, nhưng tôi khuyên nên sử dụng các bộ được biên dịch sẵn từ trang chủ của Go. Khi bạn tải [Go từ trang chủ](https://golang.org/dl/), bạn sẽ thấy các bộ cài đặt cho nhiều nền tảng khác nhau.

Trừ các mã đơn giản, Go được thiết kế để làm việc khi mã của bạn được đặt trong một workspace. Workspace là một thư mục gồm các thư mục con là `bin`, `pkg` và `src`. Bạn cũng có thể thiết lập workspace theo cách riêng của mình, nhưng cách này không được khuyến khích.

Bình thường, tôi đặt các dự án của mình bên trọng thư mục `~/code`. Ví dụ, `~/code/blog` chứa blog của tôi. Với Go, workspace của tôi là `~/code/go` và blog viết bằng Go của tôi sẽ đặt tại `~/code/go/src/blog`.

Tóm lại, tạo một thư mục `go` với một thư mục con `src` ở bất cứ chỗ nào bạn muốn đặt các project của bạn.

## OSX / Linux
Tải file `tar.gz` tương ứng với nền tảng của bạn. Với OSX, bạn sẽ tải các file `go#.#.#.darwin-amd64-osx10.8.tar.gz`, với `#.#.#` là phiên bản mới nhất Go.

Giải nén file vào thư mục `/usr/local` bằng lệnh `tar -C /usr/local -xzf go#.#.#.darwin-amd64-osx10.8.tar.gz`.

Thiết lập 2 biến môi trường (environment variables):

  1. `GOPATH` trỏ tới workspace, trong trường hợp này, đó là `$HOME/code/go`.
  2. Chúng ta cần thêm đường dẫn tới thư mục chứa file chạy của Go vào biến `PATH`.

Bạn có thể thiết lập thông qua 2 lệnh shell sau:

    echo 'export GOPATH=$HOME/code/go' >> $HOME/.profile
    echo 'export PATH=$PATH:/usr/local/go/bin' >> $HOME/.profile

Bạn sẽ cần phải kích hoạt các biến môi trường này. Bạn đóng và mở lại shell, sau đó chạy lệnh `source $HOME/.profile`.

Gõ `go version` và bạn sẽ nhận được kết quả hiển thị như sau `go version go1.3.3 darwin/amd64`.

## Windows
Tải phiên bản mới nhất của go, dạng file zip. Nếu bạn sử dụng hệ điều hành 64 bit, bạn sẽ tải file có dạng `go#.#.#.windows-amd64.zip`, với `#.#.#` là phiên bản mới nhất Go.

Giải nén vào một thư mục bất kì, ví dụ là `c:\Go`.

Thiết lập 2 biến môi trường (environment variables):

  1. `GOPATH` trỏ tới workspace, trong trường hợp này, đó là `c:\users\goku\work\go`.
  2. Thêm `c:\Go\bin` vào biến môi trường `PATH`.

Biến môi trường có thể được thiết lập qua nút `Environment Variables` trong thẻ `Advanced` của `System` control panel. Một số phiên bản Windows cung cấp các thiết lập này ở `Advanced System Settings` bên trong `System` control panel.

Mở cmd.exe và gõ `go version`. Bạn sẽ nhận được kết quả hiển thị như sau `go version go1.3.3 windows/amd64`.
