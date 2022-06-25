---
title: "Tìm hiểu về HTTP Cookie trong JavaScript"
description: "Cookie là phương thức hiệu quả nhất để nhớ và theo dấu vết của việc đặt mua, đặt bán, các ưu đãi, và thông tin khác được yêu cầu cho sự trải nghiệm tốt hơn của khách truy cập."
keywords: [
"HTTP Cookie trong JavaScript",
"cookie trong javascript",
"http cookie trong javascript là gì",
"lưu trữ dữ liệu trong javascript",
"Cách dùng cookie trong Javascript",
"Tìm hiểu về HTTP Cookie với JavaScript",
"ví dụ cookie trong javascript",
"cookie trong javascript là gì",
"tìm hiểu về cookie trong javascript",
"cookie trong js"
]
chapter:
  name: "Lưu trữ dữ liệu"
  slug: "chuong-15-luu-tru-du-lieu"
category:
  name: "Javascript"
  slug: "javascript"
image: https://kungfutech.edu.vn/thumbnail.png
position: 3
---

Nếu bạn tìm kiếm Google về "cookie" hay "HTTP Cookie" thì sẽ ra rất nhiều kết quả như: "kỹ thuật lấy cắp cookie của nạn nhân", "cách thức đánh cắp cookie thông qua lỗ hổng XSS", "khai thác cookie trình duyệt để bypass HTTPS và đánh cắp thông tin"... Qua đây, bạn có thể thấy cookie thường sẽ liên quan đến những thông tin cá nhân khá nhạy cảm. Và đó chính là một trong những mục tiêu tấn công của các Hackers.

**Vậy rốt cuộc HTTP Cookie là gì?**

Sau đây mình sẽ cùng nhau tìm hiểu về HTTP Cookie nhé!

## Cơ bản về HTTP Cookie

### HTTP Cookie là gì?

Theo MDN, [HTTP Cookie](https://developer.mozilla.org/en-US/docs/Web/HTTP/Cookies) được định nghĩa như sau:

<content-info>
HTTP Cookie (web cookie, browser cookie) là dữ liệu được gửi từ server tới trình duyệt của người dùng. Trình duyệt sẽ lưu dữ liệu cookie này và gửi lại theo mỗi HTTP request về cho cùng server đó. Về cơ bản, cookie dùng để nói cho server biết các request đến từ một trình duyệt, ví dụ để giữ lại trạng thái đăng nhập...
</content-info>

Đúng vậy, HTTP là [stateless](https://developer.mozilla.org/en-US/docs/Web/HTTP/Overview#HTTP_is_stateless_but_not_sessionless). Do đó, mọi request đến server đều giống nhau. Vì vậy, server không thể phân biệt được request được gửi đến là từ một client đã thực hiện request trước đó, đã đăng nhập,... hay từ một client mới.

Vì vậy, HTTP Cookie đã ra đời để giải quyết vấn đề này.

### Các tác dụng của cookie

Cụ thể, các tác dụng chính của cookie là:

- **Quản lý session**: trạng thái đăng nhập, thông tin giỏ hàng,...
- **Lưu thông tin cài đặt của người dùng**: theme dark mode hay light mode), ngôn ngữ (tiếng việt, tiếng anh), thông tin username/email trong mục bình luận,...
- **Theo dõi và phân tích hành vi người dùng**: các trang đã truy cập, truy cập bao nhiêu lần,...

### Một số giới hạn của cookie

HTTP Cookie có nhiều lợi ích, nhưng cũng tồn tại nhiều giới hạn như:

- Dung lượng lưu trữ giới hạn khoảng 4KB. Vì vậy, số lượng cookie lưu trữ cũng giới hạn theo.
- Cookie là **private** đối với một domain. Do đó, một trang web chỉ có thể đọc được cookies của chính nó.
- Khi số lượng cookie được lưu trữ vượt quá giới hạn, các cookie mới tạo ra sẽ thay thế cookies cũ.
- Nếu người dùng **disable cookie** thì bạn sẽ không thể sử dụng được các tính năng của nó.
- Thông tin lưu trữ ở cookie là không bảo mật nên có thể bị đánh cắp.

## Các thao tác với cookie

Thực tế, HTTP Cookie có thể được thao tác (cài đặt, đọc) từ cả **server** và **client**. Và khi bạn thiết lập **chỉ sử dụng cookie phía server** thì những phần mình nói sau đây sẽ không thể thực hiện.

Tuy nhiên, do mình đang tập trung vào JavaScript nên sẽ giả định là server cho phép client truy cập vào cookie. Và đối tượng giúp tương tác với HTTP Cookie phía trình duyệt, chính là [document.cookie](https://developer.mozilla.org/en-US/docs/Web/API/Document/cookie). Sau đây, mình sẽ tìm hiểu về các thao tác mà đối tượng này hỗ trợ.

### Tạo mới một cookie

Cách đơn giản nhất để tạo mới một cookie là:

```js
document.cookie = "foo1=bar1";
```

Đoạn code trên sẽ tạo thêm một cookie với **key** là _foo1_ và **value** là _bar1_.

**Chú ý**: Tuy đoạn code trên thực hiện phép gán, nhưng thực tế, nó sẽ không ghi đè lên các cookies có sẵn mà chỉ tạo thêm giá trị mới. Nghĩa là nếu bạn muốn tạo thêm cookie với key là _foo2_ và value là _bar2_, bạn có thể viết tiếp:

```js
document.cookie = "foo2=bar2";
```

Lúc này, bạn sẽ có 2 cookie là: `'foo1=bar1; foo2=bar2'`.

Ngoài ra, giá trị của cookie nên được encode với phương thức [encodeURIComponent()](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/encodeURIComponent) để tránh các kí tự không hợp lệ như: dấu cách, dấu phẩy và dấu chấm phẩy. Ví dụ, nếu mình muốn thêm cookie với key là _name_ và value là _Lam Pham_, thì có thể làm như sau:

```js
const value = encodeURIComponent("Lam Pham");
document.cookie = `name=${value}`;
```

Khi đó, giá trị cookie thu được là: `'foo1=bar1; foo2=bar2; name=Lam%20Pham'`.

#### Cài đặt thời điểm hết hạn cookie (expiration date)

Nếu bạn không cài đặt thời gian hết hạn cho HTTP Cookie thì mặc định nó sẽ bị xoá khi trình duyệt đóng. Để tránh việc này, bạn có thể cài đặt thời điểm hết hạn cho cookie bằng cách khai báo thêm thuộc tính **expires** với giá trị thời gian ở định dạng UTC, ví dụ:

```js
document.cookie = "foo1=bar1; expires=Thu, 04 Apr 2019 17:00:00 GMT";
```

Để thu được định dạng thời gian như trên, bạn có thể dùng phương thức [toUTCString()](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Date/toUTCString):

```js
const d = new Date(2019, 03, 5).toUTCString();
console.log(d);
// => Thu, 04 Apr 2019 17:00:00 GMT
```

#### Cài đặt thời gian hết hạn cookie (duration)

Thay vì cài đặt thời điểm hết hạn cookie, bạn có thể cài đặt thời gian hết hạn cho nó. Hay nói cách khác là sau bao nhiêu lâu thì cookies sẽ bị hết hạn. Để làm việc này, bạn cài đặt thuộc tính **max-age** với giá trị là thời gian tính bằng đơn vị giây, ví dụ:

```js
document.cookie = "foo1=bar1; max-age=3600"; // hết hạn sau 60 phút
document.cookie = "foo2=bar2; max-age=31536000"; // hết hạn sau 1 năm
```

#### Cài đặt tên miền (domain) cho cookie

Khi bạn không cài đặt thuộc tính **domain** cho cookie, mặc định, giá trị này được gán cho domain mà bạn sử dụng, giả sử là _domain.com_. Khi đó, cookies cũng được sử dụng cho các subdomain, ví dụ: _sub1.domain.com_, _sub2.domain.com_, _child.sub2.domain.com_... Tuy nhiên, bạn cũng có thể giới hạn domain sử dụng bằng cách cài đặt chính xác giá trị cho nó:

```js
document.cookie = 'foo1=bar1; domain="sub1.domain.com";';
```

Khi đó, cookies chỉ tồn tại ở domain _sub1.domain.com_ (mà không có ở _sub2.domain.com_) và các domain con của nó như _child1.sub1.domain.com_, _child2.sub1.domain.com_,...

#### Cài đặt path cho cookie

Tương tự như domain, nếu bạn không cài đặt **path** thì mặc định, giá trị này sẽ là "/". Khi đó, cookies sẽ tồn tại ở trang chủ "/" và các trang con như: "/tag", "/category", "/category/cookie",... Ngoài ra, bạn cũng có thể xác định rõ giá trị cho nó:

```js
document.cookie = 'foo=bar; path="/category"';
```

Khi đó, cookies sẽ có giá trị ở path _/category_ và các path con của nó như _/category/cookie_, _/category/session_,... mà không có ở các path khác như _/tag_,...

<content-warning>

**Chú ý:** trên đây mình chỉ ví dụ minh hoạ cho mỗi thuộc tính, thực tế bạn có thể kết hợp chúng lại với nhau:

</content-warning>

```js
document.cookie =
  'foo1=bar1; expires=Thu, 04 Apr 2019 17:00:00 GMT; domain="mysite.com"; path="/category"';
document.cookie =
  'foo2=bar2; max-age=3600; domain="sub.mysite.com"; path="/tag"';
```

### Cập nhật một cookie

Để cập nhật giá trị cho một cookie, bạn cũng sử dụng cú pháp như việc tạo mới một cookie. Chỉ khác là ở đây, tên của cookie đã tồn tại, nên giá trị của nó sẽ bị ghi đè:

```js
document.cookie = "foo=bar1";
console.log(document.cookie);
// => foo=bar1

document.cookie = "foo=bar2; max-age=3600";
console.log(document.cookie);
// => foo=bar2
```

### Đọc giá trị của cookie

Để đọc giá trị của cookie, bạn sẽ lấy ra giá trị của _document.cookie_.

```js
const cookies = document.cookie;
console.log(cookies);
// => 'foo1=bar1; foo2=bar2; foo3=bar3'
```

Giá trị trả về sẽ là một đoạn string chứa tất cả các cookies. Với các cặp cookie có dạng **key=value** được phân cách nhau bởi một dấu chấm phẩy và một dấu cách theo sau (trừ cặp cuối cùng). Khi đó, để lấy ra giá trị tương ứng với một cookie cụ thể, bạn chỉ cần duyệt string trên để lấy ra giá trị của nó.

### Xoá một Cookie

Để xoá một cookie, bạn cũng sử dụng cú pháp phần cập nhật cookie bên trên. Với **key** là tên của cookie bạn muốn xoá và **value** bạn bỏ trống, cùng với giá trị của **expires** là một thời điểm trong quá khứ. Ví dụ:

```js
document.cookie = "foo=; expires=Wed, 27 Feb 2019 07:41:28 GMT;";
```

## Thao tác với Cookie từ Server

Bên trên, mình đã tìm hiểu về việc thao tác với HTTP Cookie phía client sử dụng JavaScript. Phần này, mình sẽ tìm hiểu cơ bản về cách làm việc với cookie từ phía server.

Khi server nhận được một [HTTP request](/bai-viet/javascript/network-requests) từ client, response trả về sẽ sử dụng header **Set-Cookie** để xác định những cookie được trình duyệt lưu lại, với cấu trúc đơn giản:

```js
HTTP/2.0 200 OK
    Content-type: text/html
    Set-Cookie: foo1=bar1
    Set-Cookie: foo2=bar2

    [page content]
```

Và sau đó, với mỗi request đến server, trình duyệt sẽ sử dụng header **Cookie** để gửi lại các cookies lên server:

```js
GET /sample.html HTTP/2.0
    Host: www.example.org
    Cookie: foo1=bar1; foo2=bar2
```

Dĩ nhiên, bạn không cần phải làm việc trực tiếp với cấu trúc này. Vì mỗi ngôn ngữ lập trình đều có API riêng giúp bạn thao tác với cookies một cách đơn giản, ví dụ: [PHP](https://secure.php.net/manual/en/function.setcookie.php), [Node.JS](https://nodejs.org/dist/latest-v8.x/docs/api/http.html#http_response_setheader_name_value), [Python](https://docs.python.org/3/library/http.cookies.html), [Ruby on Rails](https://api.rubyonrails.org/classes/ActionDispatch/Cookies.html).

Ngoài ra, bạn cũng có thể cài đặt thêm các thuộc tính **Expires**, **Max-Age**, **Domain** và **Path** tương tự như mình đã trình bày bên trên. Và một vài các thuộc tính khác giúp cho việc sử dụng HTTP Cookie an toàn hơn, đó là:

- **Secure**: sử dụng tham số này thì đảm bảo cookie chỉ được phép gửi thông qua giao thức HTTPS mà không được gửi qua HTTP.
- **HttpOnly**: tham số này làm cho cookie chỉ có thể được truy cập, sửa đổi từ phía server mà không thể thao tác với cookie thông qua _document.cookie_.
- **SameSite**: tham số này cho phép server yêu cầu cookies không được gửi thông qua _cross-site requests_. Tuy nhiên, tính năng này vẫn đang được thử nghiệm và chưa được support rộng rãi.

## Kiểm tra giá trị của cookie trên trình duyệt

Để kiểm tra giá trị của cookie trên trình duyệt, bạn có thể sử dụng thông qua Console của DevTools (được mở bằng cách nhấn _F12_ hoặc tổ hợp _Ctrl Shift I_). Tại console, bạn gõ lệnh `document.cookie`, khi đó kết quả thu được là:

```js
document.cookie;
// => "foo1=bar1; foo2=bar2"
```

Hoặc cũng trong DevTools, bạn vào tab _Application -> Storage -> Cookies_. Khi đó, thông tin chi tiết về các cookies sẽ được hiển thị.

## Lời kết

Trên đây là những kiến thức cơ bản về HTTP Cookie. Hy vọng bạn có thể hiểu được về cookie và cách sử dụng nó phía client và server. Nếu có gì thắc mắc hay góp ý, bạn vui lòng để lại trong phần bình luận phía dưới. Mình sẽ cố gắng giải đáp.

Tham khảo:

- [Learn how HTTP Cookies work](https://flaviocopes.com/cookies/#restrictions-of-cookies)
- [HTTP cookies](https://developer.mozilla.org/en-US/docs/Web/HTTP/Cookies)
- [Document.cookie](https://developer.mozilla.org/en-US/docs/Web/API/Document/cookie)
- [An overview of HTTP](https://developer.mozilla.org/en-US/docs/Web/HTTP/Overview)
- [JavaScript Cookies](https://www.w3schools.com/js/js_cookies.asp)
- [JavaScript Cookie - npm](https://www.npmjs.com/package/js-cookie)
- [cookie-session - npm](https://www.npmjs.com/package/cookie-session)
