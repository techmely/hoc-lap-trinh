---
title: "Strict Mode trong JavaScript"
description: "Strict Mode là một tính năng rất hay ho được thêm trong phiên bản EMAScript 2015. Đây là một khái niệm mới, hãy cùng mình tìm hiểu nhé."
keywords:
  [
    "strict mode trong javascript",
    "strict mode trong javascript là gì",
    "strict mode là gì",
    "có nên sử dụng strict mode không",
    "tại sao nên sử dụng strict mode",
    "khoá học javascript cơ bản",
    "javascript strict mode",
    "strict mode la gi",
    "Tìm hiểu về Strict Mode",
    "Use strict trong JS"
  ]
chapter:
  name: "Javascript cơ bản"
  slug: "chuong-02-javascript-co-ban"
category:
  name: "Javascript"
  slug: "javascript"
image: https://kungfutech.edu.vn/thumbnail.png
position: 3
---

Từ khóa use strict là từ khóa để bật chế độ `Strict Mode`, tạm dịch là chế độ nghiêm ngặt của JavaScript, bắt đầu xuất hiện từ phiên bản `ECMAScript 5`. Khi một đoạn lệnh được khai báo `use strict` thì tất cả các dòng code ở phía dưới dòng khai báo use strict sẽ được JavaScript quản lý nghiêm ngặt hơn về mặt cú pháp.

## Strict mode trong javascript là gì?

`Strict` hiểu đơn giản theo nghĩa tiếng Việt là "nghiêm ngặt, nghiêm khắc". `Strict Mode` là một quy mẫu nghiêm khắc của Javascript. Nếu như coi việc viết code bình thường là `Normal Mode`, thì `Strict Mode` sẽ có thêm nhiều quy định khác so với `Normal Mode`. Việc đó khiến cho một thao tác vốn bình thường có thể chạy ngon lành trở nên lỗi, và throw ra errors.

Nhìn chung, Strict được tạo ra nhằm:

- Ngăn chặn sử dụng, và `throw errors` khi người lập trình thực hiện những xử lý được coi là `unsafe`, những xử lý mà có thể là ngoài ý muốn.
- Vô hiệu hoá các tính năng có thể gây nhầm lẫn, hoặc không nên được sử dụng.
- Ngăn chặn sử dụng một số từ mà có thể sẽ được sử dụng làm `keywork` trong tương lai.

`Strict Mode` có nhiều hạn chế hơn so với `normal mode`. Với việc tuân theo những quy định đó, bạn sẽ làm cho code Javascript của mình trở nên sáng sủa, dễ đọc hơn, cũng như ít vướng phải những lỗi không mong muốn.

Khi đọc đến đây, chắc hẳn bạn sẽ đặt câu hỏi rằng, vậy sau người ta không thay đổi hẳn phần đặc tả của ECMAScript liên quan đến những gì được đề cập trong `Strict Mode` đi, mà lại sinh ra thêm cái `Strict Mode` làm gì cho nó rắc rối?

Có lẽ một phần là để đảm bảo phần nào tính backward compatible giữa ES5 và phiên bản trước đó là ES3, phần nữa là để ECMAScript vẫn giữ được tính đơn giản, mềm dẻo từ trước, chứ không phải bị giới hạn bởi những quy tắc cứng nhắc mới được thêm vào. Từ đó ECMAScript sẽ trở nên dễ dàng tiếp cận hơn đối với những người mới làm quen.

Tuy nhiên khi đã qua giai đoạn "làm quen" rồi, thì bạn cần thay đổi. Đó là lúc bạn cần đến `Strict Mode`.

## Cách sử dụng strict mode trong javascript

Để bật chế độ strict mode cũng rất đơn giản, bạn chỉ cần đặt như thế này ở đầu file JS, hoặc đầu một hàm:

```js
"use strict";
```

Chỉ cần gõ như vậy ở đầu một file (dành cho toàn cục), hay đầu một function (dành cho cục bộ).

### Khai báo strict mode trong toàn cục

Các bạn xem đoạn code dưới đây, tình huống đặt ra là chúng ta sử dụng `use strict` cho toàn bộ code JavaScript. Sau đó, chúng ta không khai báo biến `message` mà vẫn sử dụng nó.

```html
<script>
  // Khai báo đầu file
  "use strict";

  // Đoạn code này lỗi vì biến message chưa được khởi tạo
  message = "Học lập trình JavaScript cơ bản!";

  // In ra màn hình
  document.write(message);
</script>
```

Kết quả trong tab console như sau:

![Khai báo strict mode trong toàn cục](https://user-images.githubusercontent.com/29374426/156493527-e32455e1-37af-4ae6-87a4-a315c955293c.png)

Chương trình sẽ báo lỗi như trên do chúng ta sử dụng strict mode (chế độ code nghiêm ngặt). Bây giờ mình comment dòng // “use strict”; lại và chạy lại để xem kết quả:

![strict mode trong toàn cục](https://user-images.githubusercontent.com/29374426/156493575-39159323-4417-47b4-a4a9-23ecd915019d.png)

Chương trình sẽ chạy bình thường dù chúng ta không khai báo biến `message` trước đó. Nhưng, điều này có thể gây ra lỗi về sau.

### Khai báo strict mode trong cục bộ

Để khai báo stric mode trong cục bộ, đơn giản là bạn đặt `use strict` trong phạm vi cục bộ nào đó.

Ví dụ, mình tinh chỉnh một chút ở đoạn code trên để nó thành phạm vi cục bộ cho các bạn tiện theo dõi.

```html
<script>
  function print_message() {
    // Khai báo đầu function
    "use strict";
  }
  print_message();
  message = "Phạm vi ngoài hàm print_message";
  document.write(message);
</script>
```

Chạy trên trình duyệt, kết quả nhận được:

![strict mode trong cục bộ](https://user-images.githubusercontent.com/29374426/156493603-c07874e5-b8cc-474e-b5c1-4cf98891689b.png)

Đoạn code này thì kết quả vẫn chạy bình thường vì chúng ta `use strict` trong hàm `print_message()` nên không ảnh hưởng ra bên ngoài.

Nếu chúng ta sử dụng một biến không khai báo trong phạm vi cục bộ này thì chương trình sẽ báo lỗi và không chạy.

```html
<script>
  function print_message() {
    // Khai báo đầu function
    "use strict";
    // Đoạn code này lỗi vì biến message chưa được khởi tạo
    message = "Học lập trình JavaScript cơ bản!";

    // In ra màn hình
    document.write(message);
  }
  print_message();
  message = "Phạm vi ngoài hàm print_message";
  document.write(message);
</script>
```

Đến đây thì bạn đã hiểu cơ bản về chế độ nghiêm ngặt trong phạm vi toàn cục và phạm vi cục bộ rồi.

## Browser console

Khi bạn sử dụng developer console trên trình duyệt (như chrome, safari,...) để chạy code thì mặc định là chế độ không nghiêm ngặt. Đôi khi bạn cần sử dụng chế độ `use strict` để kiểm tra kết quả thì hãy thêm `"use strict"` như các ví dụ bên trên nhé.

```js
'use strict'; <Shift+Enter for a newline>
//  ...your code
<Enter to run>
```

## Vậy có nên sử dụng use strict không

Câu trả lời có vẻ hiển nhiên là có, nhưng không phải vậy.

Người ta có thể khuyên bạn nên bắt đầu các tập lệnh với "use strict"... Nhưng bạn biết điều gì thú vị không?

JavaScript hiện đại hỗ trợ `classes` và `modules` - các cấu trúc ngôn ngữ nâng cao (chúng ta sẽ tìm hiểu ở các bài sau), mà tự động sử dụng `use strict`. Vì vậy, chúng ta không cần phải thêm chỉ thị "use strict", nếu chúng ta sử dụng chúng.
