---
title: "Tạo HTTP request đến server trong JavaScript qua XMLHttpRequest"
description: "Interface XMLHttpRequest trong Javascript được thiết kế để đọc các nguồn dữ liệu từ một URL."
keywords: [
"xml http request trong javascript",
"xml http request la gi",
"ghi file bang javascript",
"ví dụ xmlhttprequest trong javascript",
"xml http request trong javascript có tác dụng gì",
"XML Http Request open",
"XML Http Request JavaScript",
"javascript xml http request events"
]
chapter:
  name: "Network request"
  slug: "chuong-14-network-requests"
category:
  name: "Javascript"
  slug: "javascript"
image: https://kungfutech.edu.vn/thumbnail.png
position: 1
---

Có bao giờ bạn thắc mắc, chuyện gì thực sự diễn ra khi chúng ta gõ một địa chỉ trang web (ví dụ: [kungfutech.edu.vn](/)) lên trình duyệt và nhấn **Enter**?

Đầu tiên, trình duyệt sẽ tìm kiếm địa chỉ IP của server ứng với tên miền, sau đó là mở kết nối TCP đến server thông qua cổng 80 - cổng mặc định của giao thức HTTP. Nếu server tồn tại và chấp nhận kết nối, trình duyệt sẽ gửi yêu cầu dạng GET đến server để lấy thông tin trang web. Tiếp theo, server phản hồi lại trình duyệt theo đúng kết nối đó. Và cuối cùng, trình duyệt xử lý thông tin phản hồi và hiển thị nó lên trang web.

Quá trình này được thực hiện hoàn toàn dựa trên trình duyệt. Tuy nhiên, bài viết này sẽ hướng dẫn bạn gửi yêu cầu HTTP đến server bằng JavaScript thông qua [đối tượng](/bai-viet/javascript/object-la-gi-object-trong-javascript) XMLHttpRequest. Nhưng trước khi đi vào tìm hiểu cách sử dụng XMLHttpRequest, chúng ta hãy lướt qua một chút về giao thức HTTP để biết nó là cái gì trước đã. OK?

## HTTP là gì?

Theo [wikipedia](https://vi.wikipedia.org/wiki/Hypertext_Transfer_Protocol): HTTP - viết tắt của HyperText Transfer Protocol - giao thức truyền tải siêu văn bản, là một trong năm chuẩn về mạng Internet, được dùng để liên hệ thông tin giữa máy cung cấp dịch vụ (Web server) và máy sử dụng dịch vụ (Web client). HTTP là một giao thức sử dụng bộ giao thức TCP/IP.

### Các phương thức request của HTTP

HTTP hỗ trợ các phương thức request sau:

- **GET**: phương thức này dùng để lấy thông tin từ server sử dụng URI. Và phương thức GET chỉ nên dùng để lấy thông tin mà không có ảnh hưởng khác tới dữ liệu.
- **HEAD**: tương tự như GET, nhưng phương thức này chỉ dùng để lấy thông tin dòng trạng thái và phần tiêu đề (header).
- **POST**: phương thức này dùng để gửi dữ liệu từ client lên server, ví dụ: thông tin khách hàng, file,...
- **PUT**: dùng để thay thế dữ liệu hiện tại trên server bằng một dữ liệu mới được tải lên. Nói ngắn gọn thì là upload dữ liệu.
- **DELETE**: xoá dữ liệu trên server sử dụng URI.
- **CONNECT**: thiết lập một kênh truyền đến server sử dụng URI.
- **OPTIONS**: miêu tả các tuỳ chọn giao tiếp đến tài nguyên trên server.
- **TRACE**: thực hiện một bài test lặp lại vòng lặp thông báo với đường dẫn đến tài nguyên đích trên server.

### Các status code

Status-code là một số nguyên gồm 3 chữ số, dùng để phân loại phản hồi được gửi về từ server. Có 5 loại status-code là:

- **1xx**: (100, 101) : Nó có nghĩa là yêu cầu đã được chấp nhận và tiến trình sẽ được tiếp tục.
- **2xx**: (200 - 206) : Nó có nghĩa là hành động đã được nhận, hiểu và thực hiện thành công.
- **3xx**: (300 - 307) : Nó có nghĩa là phải thực hiện thêm hành động để hoàn thành yêu cầu.
- **4xx**: (400 - 417 ) : Nó có nghĩa là yêu cầu bị sai cú pháp hay là không thể được hoàn thành.
- **5xx**: (500 - 505) : Nó có nghĩa là server không thể thực hiện được yêu cầu.

Cụ thể về từng status-code, bạn có thể tìm hiểu thêm tại [đây](https://www.tutorialspoint.com/http/http_status_codes.htm).

## Gửi HTTP request sử dụng XMLHttpRequest

Thông thường, vì lý do an toàn nên server sẽ chặn các request từ các tên miền khác với "tên miền của server". Do đó, bạn sẽ không thể thực hiện gửi HTTP request đến server sử dụng XMLHttpRequest từ localhost. Sau đây, mình sẽ sử dụng server chuyên dùng để test HTTP request tại: [https://httpbin.org/](https://httpbin.org)

Ví dụ sau gửi phương thức request dạng GET đến [https://httpbin.org/get](https://httpbin.org/get):

```js
const req = new XMLHttpRequest();
req.open("GET", "https://httpbin.org/get", false);
req.send(null);
console.log(req.status);
console.log(req.responseText);
```

Kết quả trả về là:

```js
200
    {
      "args": {},
      "headers": {
        "Accept": "*/*",
        "Accept-Encoding": "gzip, deflate, br",
        "Accept-Language": "en-US,en;q=0.8,vi;q=0.6",
        "Connection": "close",
        "Host": "httpbin.org",
        "Origin": "null",
        "User-Agent": "Mozilla/5.0 (iPhone; CPU iPhone OS 9_1 like Mac OS X) AppleWebKit/601.1.46 (KHTML, like Gecko) Version/9.0 Mobile/13B143 Safari/601.1"
      },
      "origin": "183.81.50.73",
      "url": "https://httpbin.org/get"
    }
```

### Giải thích

Trong JavaScript, câu lệnh để tạo mới một đối tượng XMLHttpRequest: **var req = new XMLHttpRequest();**.

Sau khi đã có đối tượng req, mình sử dụng phương thức **open** để cấu hình cho request. Trong đó:

- Thuộc tính đầu tiên là tên kiểu request: **GET, HEAD, POST, PUT, DELETE,**...
- Thuộc tính tiếp theo là địa chỉ URL mà mình muốn gửi request đến.
- Thuộc tính cuối cùng là đối số [kiểu bool](/bai-viet/javascript/cac-kieu-du-lieu-trong-javascript), với giá trị **false** ý nghĩa là request kiểu đồng bộ (đợi cho đến khi nhận được kết quả phản hồi response) và giá trị **true** ý nghĩa là request kiểu bất đồng bộ (không đợi kết quả trả về mà sẽ tiếp tục thực hiện lệnh phía dưới, kết quả trả về sẽ được xử lý trong [hàm](/bai-viet/javascript/ham-trong-javascript) callback).

Lúc này, request mới được cấu hình. Để gửi request này đến server, mình sẽ sử dụng phương thức **send** với đối số là **body** của request. Trong ví dụ này, mình gửi request kiểu **GET** nên body chỉ cần là **null**.

Kết quả trả về có nhiều thuộc tính, nhưng quan trọng nhất là 2 thuộc tính:

- **status**: chính là status-code. Kết quả trả về là 200, chứng tỏ request thành công.
- **responseText**: là nội dung phản hồi từ server. Trong trường hợp này, kết quả trả về là một chuỗi [JSON](/tim-hieu-ve-json-trong-javascript/).

Ngoài ra, nhiều trường hợp bạn phải chèn thêm header cho request thì server mới chấp nhận. Để làm được việc này, bạn có thể sử dụng phương thức [setRequestHeader](https://developer.mozilla.org/en-US/docs/Web/API/XMLHttpRequest/setRequestHeader) đơn giản như sau:

```js
XMLHttpRequest.setRequestHeader(header, value);
```

Ví dụ, để cấu hình request sử dụng body kiểu JSON, bạn có thể set header "Content-Type":

```js
req.setRequestHeader("Content-Type", "application/json;charset=UTF-8");
```

### Sử dụng XMLHttpRequest với phương thức POST

Ví dụ sau gửi phương thức request dạng POST:

```js
const req = new XMLHttpRequest();
req.open("POST", "https://httpbin.org/post", false);
req.setRequestHeader("Content-Type", "application/json; charset=UTF-8");

const jsonBody = {
  name: "Thaycacac",
  url: "kungfutech.edu.vn",
};
req.send(jsonBody);

console.log(req.status);
console.log(req.responseText);
```

Kết quả:

```js
200
    {
      "args": {},
      "data": "[object Object]",
      "files": {},
      "form": {},
      "headers": {
        "Accept": "*/*",
        "Accept-Encoding": "gzip, deflate, br",
        "Accept-Language": "en-US,en;q=0.8,vi;q=0.6",
        "Connection": "close",
        "Content-Length": "15",
        "Content-Type": "application/json; charset=UTF-8",
        "Host": "httpbin.org",
        "Origin": "null",
        "User-Agent": "Mozilla/5.0 (iPhone; CPU iPhone OS 9_1 like Mac OS X) AppleWebKit/601.1.46 (KHTML, like Gecko) Version/9.0 Mobile/13B143 Safari/601.1"
      },
      "json": null,
      "origin": "183.81.50.73",
      "url": "https://httpbin.org/post"
    }
```

Phần này cũng tương tự như phần sử dụng phương thức GET. Chỉ khác là ở đây, mình sử dụng phương thức **setRequestHeader** để cấu hình **content-type** là JSON. Khi gửi request, thay vì gửi **null** thì ở đây mình gửi đi một đối tượng JSON.

Đối với các phương thức request còn lại như PUT, DELETE, HEAD,... bạn có thể làm tương tự như hai ví dụ trên.

### XMLHttpRequest với request bất đồng bộ

Trong các ví dụ trên, mình mới chỉ sử dụng request đồng bộ. Việc sử dụng request đồng bộ dẫn đến chương trình bị dừng lại để chờ cho đến khi có thông tin phản hồi từ server.

Nếu như server bị lỗi, hoặc việc xử lý request mất nhiều thời gian, điều này dẫn đến chương trình sẽ bị dừng hoạt động, trang web sẽ bị **đơ**.

Do đó, chỉ nên sử dụng request đồng bộ với những yêu cầu có thể xử lý nhanh. Nhìn chung, bạn nên sử dụng request bất đồng bộ.

Như mình đã nói ở trên, để cấu hình request là bất đồng bộ, bạn chỉ cần truyền vào **true** ở thuộc tính thứ 3 của phương thức **open**. Ngoài ra, bạn cần phải [đăng ký sự kiện](/bai-viet/javascript/mot-so-event-javascript) **load** và truyền vào hàm callback - hàm này được thực hiện khi có thông tin phản hồi từ server.

```js
const req = new XMLHttpRequest();
req.open("GET", "https://httpbin.org/get", true);
req.addEventListener("load", function () {
  console.log(req.status);
  console.log(req.responseText);
});
req.send(null);
console.log("Sent");
```

Kết quả:

```js
Sent
    200
    {
      "args": {},
      "headers": {
        "Accept": "*/*",
        "Accept-Encoding": "gzip, deflate, br",
        "Accept-Language": "en-US,en;q=0.8,vi;q=0.6",
        "Connection": "close",
        "Host": "httpbin.org",
        "Origin": "null",
        "User-Agent": "Mozilla/5.0 (iPhone; CPU iPhone OS 9_1 like Mac OS X) AppleWebKit/601.1.46 (KHTML, like Gecko) Version/9.0 Mobile/13B143 Safari/601.1"
      },
      "origin": "183.81.50.73",
      "url": "https://httpbin.org/get"
    }
```

Kết quả cho thấy, dòng lệnh **console.log('Sent')** được thực hiện ngay sau lệnh **req.send(null)**. Và 2 câu lệnh **console.log(req.status); console.log(req.responseText);** chỉ được thực hiện khi có thông tin phản hồi về từ server. Đó chính là cách thức hoạt động của XMLHttpRequest bất đồng bộ.

Ngoài ra, bạn có thể đăng ký sự kiện **error** để xử lý trường hợp request bị lỗi:

```js
const req = new XMLHttpRequest();
req.open("GET", "https://httpbin.org/get", true);
req.addEventListener("load", function () {
  console.log(req.status);
  console.log(req.responseText);
});
req.addEventListener("error", function () {
  console.log("Error occurred!");
});
req.send(null);
console.log("Sent");
```

## Tổng kết

Trên đây là một số kiến thức cơ bản về HTTP và cách sử dụng XMLHttpRequest trong JavaScript để gửi HTTP request. Mình có thể tóm tắt như sau:

- HTTP - viết tắt của HyperText Transfer Protocol - giao thức truyền tải siêu văn bản, sử dụng giao thức TCP/IP
- HTTP hỗ trợ các phương thức request: GET, POST, HEAD, PUT, DELETE, CONNECT, TRACE, OPTIONS.
- XMLHttpRequest giúp bạn gửi HTTP request đến server và hỗ trợ hai kiểu request: đồng bộ và bất đồng bộ. Nhìn chung, bạn nên sử dụng kiểu bất đồng bộ.

Về HTTP và XMLHttpRequest còn rất nhiều thứ, bài viết này chỉ đưa ra những kiến thức cơ bản nhất. Bạn có thể tự tìm hiểu thêm trên Internet.

Xin chào và hẹn gặp lại bạn ở bài viết tiếp theo, thân ái!

## Tham khảo

- [HTTP and Forms](https://eloquentjavascript.net/18_http.html)
- [HTTP - Requests](https://www.tutorialspoint.com/http/http_requests.htm)
- [HTTP - Status Codes](https://www.tutorialspoint.com/http/http_status_codes.htm)
