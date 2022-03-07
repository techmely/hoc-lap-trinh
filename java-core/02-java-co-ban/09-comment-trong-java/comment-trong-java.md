---
title: "Comment trong Java"
description: "Tất cả các ngôn ngữ lập trình đều hỗ trợ comment (đoạn bình luận chỉ để hiển thị, cung câp thêm thông tin sẽ bị trình biên dịch bỏ qua) và trong Java cũng vậy, bài này chúng ta sẽ cùng nhau tìm hiểu comment trong java"
keywords:
  [
    "comment nhiều dòng trong java",
    "comment trong java",
    "comment trong java eclipse",
    "comment trong java example",
    "comment trong java explorer",
    "comment trong java extension",
    "comment một dòng trong java",
  ]
chapter:
  name: "Nhập môn Java"
  slug: "chuong-02-nhap-mon-java"
category:
  name: "Java"
  slug: "java"
image: https://user-images.githubusercontent.com/29374426/126426149-ac16a161-b637-44a5-ba1f-18892453c095.png
position: 9
---

Comment trong Java là các ghi chú trong code Java bị bỏ qua bởi trình biên dịch và runtime engine. Các comment code là các nhận xét, giải thích mã nguồn, chẳng hạn như mô tả về các class, interfaces, method và fields làm cho chúng dễ đọc hơn chứ không phải là làm rối thêm.

![comment-trong-java](https://user-images.githubusercontent.com/29374426/126426149-ac16a161-b637-44a5-ba1f-18892453c095.png)

## Khi nào cần comment code?

Mặc dù không phải lúc nào chúng ta cũng nên viết comment code, nhưng khi nào thì chúng ta cần comment code? Câu trả lời hợp lí là: comment phải mô tả được suy nghĩ của người viết code và giải đáp được những thắc mắc của người đọc.

Comment không chỉ nên là việc giải thích đoạn code này làm gì, mà nó nên mang cả ý nghĩa “tại sao” người viết lại viết như vậy, thậm chí dự đoán trước được những điều mà người đọc sẽ có khả năng thắc mắc trong tương lai. Chúng ta xem xét thử những tình huống sau:

- Cần nói rõ ý định tại sao: viết code để chương trình hoạt động đúng đã là 1 việc khó, việc làm cho người khác hiểu được ý định của mình đằng sau những đoạn code lại càng khó hơn. Cùng một vấn đề nhưng đôi khi có nhiều cách để giải quyết, chúng ta nên xem xét việc comment để nói rõ “tại sao” ta lại xử lí như vậy.
- Những phần code dễ bị hiểu sai
- Những comment mang lại cái nhìn bao quát: nếu bạn tham gia một dự án nào đó, mà bạn không phải là người phát triển ngay từ đầu, điều khó nhất có thể không chỉ là những hiểu biết mang tính kĩ thuật, mà đến từ việc “hiểu được dự án đó đã và đang thực sự làm gì”.
- Những đoạn code thực sự khó hiểu: ngoài những xử lí thông thường, đôi khi chúng ta có thứ gọi là “thuật toán” hoặc là “design pattern”. Những thứ đó đôi khi rất phức tạp, nếu code mà không có comment chú thích thì rất khó để người đọc hình dung đó là gì. Tốt hơn là ta cứ nên viết thêm dòng comment để nói ra đó là gì.

## Cách comment trong Java

### Comment 1 dòng

Để comment 1 dòng, bạn sư dụng ký hiệu `//` hai dấu gạch chéo về phía trước, theo sau là comment. Ví dụ:

```java
// Comment 1 dòng int guessNumber = (int) (Math.random() * 10);
```

Khi trình biên dịch thấy 2 dấu gạch chéo về phía trước, nó biết những thứ ở bên phải là comment, thế nên cho dù nó có là code thì cũng bị bỏ qua. Điều này cũng rất hữu ích để bạn fix bug. Chỉ cần thêm một comment từ một dòng mã bạn đang gỡ lỗi và trình biên dịch sẽ không thực thi nó:

Comment ngắn cuối dòng code để mô tả nhanh.

<div class="example"></div>

```java
int guessNumber = (int) (Math.random() * 10); // Random từ 1 đến 10
```

### Comment nhiều dòng

Để bắt đầu comment nhiều dòng, bạn cần gõ `/*`. Mọi thứ giữa dấu gạch chéo về phía trước và dấu hoa thị, ngay cả khi nó nằm trên một dòng khác, chúng đều được coi là một comment cho đến khi các ký tự `*/` kết thúc comment.

```java
/* Đây
 là
 một
 comment
 nhiều dòng
*/

/* Đây cũng thế */
```
