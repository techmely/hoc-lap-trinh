# **[Tổng quan về Web] HTTP và những điều cần biết**
-------
> #### *__Nội dung bài viết__*
> - [HTTP là gì](#http-là-gì)
> - [Các khía cạnh cơ bản của HTTP](#các-khía-cạnh-cơ-bản-của-http)
> - [HTTP Message](#tổng-quan-về-http-messenges)
>   - [HTTP Request](#http-request)
>   - [HTTP Response](#tổng-quan-về-http-messenges)
>   - [HTTP Status Code](#http-status-code)

### HTTP là gì
**Hyper Text Transfer Protocol** (HTTP) là một giao thức để tìm nạp các tài nguyên như tài liệu HTML. Nó là nền tảng của bất kỳ trao đổi dữ liệu nào trên Web và nó là một giao thức khách-máy chủ (**Client-Server**), có nghĩa là các yêu cầu được khởi tạo bởi người nhận, thường là trình duyệt Web. 
![](https://1.bp.blogspot.com/-L95P9p9PDfI/WqvflWNeEqI/AAAAAAAAAa0/JPzrhonvuDElUidmK0oS0jqmDwn_aPwPwCLcBGAs/s1600/Client-server-model.svg.png)
Một tài liệu hoàn chỉnh được tạo lại từ các tài liệu con khác nhau được tìm nạp, chẳng hạn như văn bản, mô tả bố cục, hình ảnh, video, tập lệnh, v.v. 
![](https://developer.mozilla.org/en-US/docs/Web/HTTP/Overview/fetching_a_page.png)

### Các khía cạnh cơ bản của HTTP
* ### **Tính đơn giản (Simple)**: 
 HTTP thường được thiết kế để trở nên đơn giản và thân thiện để con người có thể đọc được. Với các HTTP message, chúng ta có thể được đọc và hiểu được, cung cấp khả năng testing hơn cho các dev và giảm thiểu độ phức tạp cho bất cứ người mới nào.
* ### **Có thể mở rộng (Extensible)**:
 Được giới thiệu trong HTTP/1.0, các header HTTP làm cho giao thức này dễ dàng mở rộng và thử nghiệm hơn nữa. Chức năng mới thậm chí có thể được giới thiệu bằng 1 thỏa thuận đơn giản giữa 1 client và 1 máy chủ về ngữ nghĩa của 1 header mới.
* ### **Stateless (But Not Sessionless)**
 Server và Client biết về nhau chi trong một yêu cầu hiện tại. Sau đó, cả hai chúng nó quên tất cả về nhau. Do bản chất của giao thức, cả Client và các trình duyệt có thể giữ lại thông tin giữa các yêu cầu khác nhau giữa các trang web.
> Để khắc phục vấn đề này, HTTP cho phép mở rộng tự do các header. Trong đó, người dùng có thể tự tạo cho mình session trên mỗi request nhằm mục đích chia sẻ các ngữ cảnh hoặc trạng thái giữa các request với nhau. Sở dĩ trường hợp này có thể thực hiện được vì bản thân HTTP là stateless.

### Tổng quan về HTTP Message
* #### HTTP Request
HTTP request là thông tin được gửi từ client lên server, để yêu cầu server tìm hoặc xử lý một số thông tin, dữ liệu mà client muốn. 
> - Method: là phương thức mà HTTP Request này sử dụng, thường là GET, POST, ngoài ra còn một số phương thức khác như HEAD, PUT, DELETE, OPTION, CONNECT. Trong ví dụ trên là GET
>  - URI: là địa chỉ định danh của tài nguyên. Trong tường hợp này URI là / - tức request cho tài nguyên gốc, nếu request không yêu cầu một tài nguyên cụ thể, URI có thể là dấu *.
>  - HTTP version: là phiên bản HTTP đang sử dụng, ở đây là HTTP 1.1.  

![](https://theegeek.com/wp-content/uploads/2014/12/HTTP-Request-Stream-Example.jpg)

Tiếp theo là các trường request-header, cho phép client gửi thêm các thông tin bổ sung về thông điệp HTTP request và về chính client. Một số trường thông dụng như:
> - Accept: loại nội dung có thể nhận được từ thông điệp response. Ví dụ: text/plain, text/html…
> - Accept-Encoding: các kiểu nén được chấp nhận. Ví dụ: gzip, deflate, xz, exi…
> - Connection: tùy chọn điều khiển cho kết nối hiện thời. Ví dụ: keep-alive, Upgrade…
> - Cookie: thông tin HTTP Cookie từ server.
User-Agent: thông tin về user agent của người dùng.
* #### HTTP Response
Cấu trúc HTTP response gần giống với HTTP request, chỉ khác nhau là thay vì Request-Line, thì HTTP có response có Status-Line. Và giống như Request-Line, Status-Line cũng có ba phần như sau:
> - HTTP-version: phiên bản HTTP cao nhất mà server hỗ trợ.
> - Status-Code: mã kết quả trả về.
> - Reason-Phrase: mô tả về Status-Code.

![](https://images.viblo.asia/d4d042c6-1606-44c8-a7cc-0130d38f281e.png)

* ### HTTP Status Code
Một số loại Status-Code thông dụng mà server trả về cho client như sau:

> 1xx (Information Message): các status code này chỉ có tính chất tạm thời, client có thể không quan tâm.

> 2xx (Successful): khi đã xử lý thành công request của client, server trả về status dạng này:

> 3xx (Redirection): erver thông báo cho client phải thực hiện thêm thao tác để hoàn tất request:

> 4xx (Client Error): lỗi của client

> 5xx (Server Error): lỗi của server

![](https://softcrony.com/blog/wp-content/uploads/2020/07/http-code.png)


