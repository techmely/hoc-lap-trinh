---
title: "Hàm tương tác với người dùng alert, confirm, prompt"
description: "Hàm tương tác với người dùng alert, confirm, prompt"
keywords: 
  [
    "khoá học javascript",
    "tương tác với người dùng trong javascript",
    "Hàm tương tác với người dùng",
    "alert, confirm, prompt",
    "alert trong js",
    "tao thong bao trong javascript",
    "alert javascript",
    "Popup thông báo",
    "Tạo thông báo",
    "tương tác với người dùng"
  ]
chapter:
  name: "Javascript cơ bản"
  slug: "chuong-02-javascript-co-ban"
category:
  name: "Javascript"
  slug: "javascript"
image: https://kungfutech.edu.vn/thumbnail.png
position: 8
---

Trong bài viết về [chương trình JavaScript đầu tiên](/bai-viet/khoa-hoc-javascript/chuong-trinh-javascript-dau-tien/), mình có đề cập đến việc hiển thị hộp thoại với hàm `alert`. Đây là một trong ba hàm giúp tương tác người dùng mà mình sẽ tìm hiểu kỹ hơn trong bài viết này.

## Tương tác người dùng với hàm `alert`

Hàm `alert` dùng để hiển thị hộp thoại, bao gồm nội dung tin nhắn và nút bấm (button) **OK**. Khi người dùng bấm vào **OK** thì hộp thoại sẽ đóng lại.

Cú pháp:

```js
alert(message);
```

<content-example />

```js
alert("Say hello from completejavascript.com");
```

Kết quả:

![Hàm alert trong javascript](https://user-images.githubusercontent.com/29374426/156864947-d56c860a-baee-400c-81c5-5185eeaadaae.png)

Hộp thoại này còn được gọi là "modal window". Nghĩa là người dùng **chỉ tương tác được với hộp thoại** mà **không tương tác được với nội dung còn lại** của trang web (bên dưới hộp thoại).

## Tương tác người dùng với hàm `confirm`

Tương tự như hàm `alert`, hàm `confirm` cũng đưa ra một thông báo trực tiếp tới người dùng.

Tuy nhiên, hàm `confirm` yêu cầu người dùng xác nhận bằng cách chọn **OK** hoặc **Cancel**.

- Nếu người dùng chọn **OK** thì hàm `confirm` trả về `true`.
- Ngược lại, nếu người dùng chọn **Cancel** thì kết quả trả về là `false`.

Cú pháp:

```js
result = confirm(message);
```

Ví dụ:

```js
const result = confirm("Bạn muốn tiếp tục sử dụng chương trình?");
alert(result);

// result = true nếu người dùng bấm OK.
// result = false nếu người dùng bấm Cancel.
```

Kết quả:

![Hàm confirm trong javascript](https://user-images.githubusercontent.com/29374426/156864965-375492e0-fd28-4365-8613-dc1a30bda979.png)


Tương tự như hàm `alert`, hộp thoại với hàm `confirm` cũng là dạng "modal window".

## Tương tác người dùng với hàm `prompt`

Hàm `prompt` cũng lại tương tự như hàm `confirm` và hàm `alert` nhưng cho phép người dùng nhập vào [string](/bai-viet/khoa-hoc-javascript/cac-kieu-du-lieu-trong-javascript).

Cú pháp:

```js
result = prompt(title, [defaultValue]);
```

Trong đó:

- **title**: nội dung chữ hiển thị tới người dùng.
- **defaultValue**: giá trị mặc định cho ô nhập (input) và đây là giá trị không bắt buộc.

Ví dụ:

```js
const name = prompt("Nhập vào tên của bạn:", "Anonymous");
alert(name);
```

Kết quả:

![Hàm prompt trong javascript](https://user-images.githubusercontent.com/29374426/156864981-b03a0c67-18fe-4e48-832a-81831ad3d98b.png)

Trong ví dụ trên:

- Giá trị **title** là `Nhập vào tên của bạn:`.
- Giá trị **defaultValue** là `Anonymous`.

Khi người dùng nhấn vào **OK** hoặc **Cancel** thì hộp thoại sẽ đóng lại. Với trường hợp **OK**, giá trị trả về là giá trị trong ô nhập **input** lúc đó. Với trường hợp **Cancel** thì giá trị trả về là `null`.

## Tổng kết

Trên đây mình đã giới thiệu với bạn về ba hàm tương tác người dùng:

- Hàm `alert`: hiển thị hộp thoại với dòng chữ.
- Hàm `confirm`: hiển thị hộp thoại với dòng chữ và yêu cầu người dùng nhấn vào **OK** hoặc **Cancel**.
  - Nếu người dùng nhấn vào **OK** thì hộp thoại đóng lại và trả về giá trị `true`.
  - Nếu người dùng nhấn vào **Cancel**, hộp thoại cũng đóng lại, nhưng trả về giá trị `false`.
- Hàm `prompt`: hiển thị hộp thoại với dòng chữ và yêu cầu người dùng nhập nội dung vào ô nhập (input). Sau đó, yêu cầu người dùng nhấn vào **OK** hoặc **Cancel**.
  - Nếu người dùng nhấn vào **OK** thì hộp thoại đóng lại và trả về giá trị hiện tại của ô nhập.
  - Nếu người dùng nhấn vào **Cancel**, hộp thoại cũng đóng lại, nhưng trả về giá trị `null`.

Cả ba hàm trên đều hiển thị hộp thoại dạng "modal window". Nghĩa là người dùng chỉ tương tác được với hộp thoại mà không tương tác được với nội dung bên dưới hộp thoại.

Bạn có thể thấy rằng, ba hàm trên đều rất đơn giản, dễ sử dụng. Nhưng nhược điểm của chúng là: bạn không thể quyết định được giao diện hiển thị của hộp thoại. Mà giao diện hộp thoại hoàn toàn phụ thuộc vào trình duyệt.

## Thực hành

Tạo một trang web đơn giản với chức năng là hỏi người dùng bao nhiêu tuổi "How old are you?", với giá trị mặc định là `18`.

Sau đó, hiển thị nội dung tương ứng với giá trị người dùng nhập vào "You are X years old!" (với **X** là giá trị người dùng đã nhập).

Xem đáp án

```html
<html>
  <body>
    <script>
      const age = prompt("How old are you!", 18);
      alert("You are " + age + " years old!");
    </script>
  </body>
</html>
```
