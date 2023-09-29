---
title: "Giới thiệu Pure Component trong Reactjs"
description: "Trong React, sự hiểu biết về Pure Component là một phần quan trọng để tạo ra mã nguồn sạch sẽ và tránh được nhiều lỗi khó hiểu. Trong bài viết này, chúng ta sẽ tìm hiểu về Pure Component, tại sao chúng quan trọng, và cách sử dụng chúng trong ứng dụng React"
chapter:
  name: "Giao diện trong ReactJs"
  slug: "chuong-03-giao-dien-trong-reactjs"
image: https://kungfutech.edu.vn/thumbnail.png
position: 8
---

React.js là một thư viện JavaScript mạnh mẽ được sử dụng rộng rãi để phát triển ứng dụng web hiệu suất cao và dễ bảo trì. Trong React, sự hiểu biết về Pure Component là một phần quan trọng để tạo ra mã nguồn sạch sẽ và tránh được nhiều lỗi khó hiểu. Trong bài viết này, chúng ta sẽ tìm hiểu về Pure Component, tại sao chúng quan trọng, và cách sử dụng chúng trong ứng dụng React.

## Tính "Pure": Các Component như Công thức

Trong khoa học máy tính và đặc biệt là trong thế giới của lập trình hàm, một hàm "pure" là một hàm có các đặc điểm sau:

- **Tự lực tự cường:** Nó không thay đổi bất kỳ đối tượng hoặc biến nào tồn tại trước khi nó được gọi.
- **Cùng đầu vào, cùng đầu ra:** Với cùng một đầu vào, một hàm "pure" luôn trả về cùng một kết quả.

Bạn có thể quen thuộc với ví dụ về hàm "pure" từ toán học. Xem xét công thức toán học sau: `y = 2x`.

- Nếu `x = 2`, thì `y = 4`. Luôn luôn.
- Nếu `x = 3`, thì `y = 6`. Luôn luôn.

Nếu `x = 3`, thì y không bao giờ là 9 hoặc -1 hoặc 2.5 dựa vào thời gian trong ngày hoặc trạng thái của thị trường chứng khoán.

Nếu chúng ta biểu diễn nó dưới dạng một hàm JavaScript, nó sẽ trông như sau:

```javascript
function double(number) {
  return 2 * number;
}
```

Ở ví dụ trên, hàm `double` là một hàm "pure". Nếu bạn truyền nó giá trị 3, nó sẽ luôn luôn trả về 6.

React được thiết kế xung quanh khái niệm này. React giả định rằng mọi component bạn viết đều là một hàm "pure". Điều này có nghĩa rằng các component React bạn viết phải luôn trả về cùng một JSX khi có cùng đầu vào.

## Sử dụng Pure Component trong React

Để minh họa cách sử dụng Pure Component trong React, hãy xem xét một ví dụ cụ thể. Bạn có một component `Recipe` để hiển thị hướng dẫn làm một ly trà, và bạn muốn nó hiển thị số lượng cốc trà dựa trên đầu vào.

```javascript
function Recipe({ drinkers }) {
  return (
    <ol>
      <li>Boil {drinkers} cups of water.</li>
      <li>
        Add {drinkers} spoons of tea and {0.5 * drinkers} spoons of spice.
      </li>
      <li>Add {0.5 * drinkers} cups of milk to boil and sugar to taste.</li>
    </ol>
  );
}
```

Khi bạn truyền `drinkers={2}` vào `Recipe`, nó sẽ trả về JSX chứa 2 cốc nước. Luôn luôn.

Nếu bạn truyền `drinkers={4}`, nó sẽ trả về JSX chứa 4 cốc nước. Luôn luôn.

Chính như một công thức toán học.

Bạn có thể nghĩ về các component của bạn như các công thức: nếu bạn tuân thủ chúng và không đưa thêm thành phần mới vào quá trình nấu ăn, bạn sẽ luôn luôn có món ăn giống nhau. Món ăn đó chính là JSX mà component trả về để React render.

## Hiệu ứng phụ: Những hậu quả (không) được dự tính

Quá trình render của React luôn phải là "pure". Các component chỉ nên trả về JSX của họ, và không thay đổi bất kỳ đối tượng hoặc biến nào tồn tại trước quá trình render - điều này sẽ làm cho chúng trở thành "không pure"!

Dưới đây là một ví dụ về một component vi phạm quy tắc này:

```javascript
let guest = 0;

function Cup() {
  // Xấu: thay đổi biến đã tồn tại!
  guest = guest + 1;
  return <h2>Tea cup for guest #{guest}</h2>;
}
```

Component này đang đọc và thay đổi một biến `guest` được khai báo bên ngoài nó. Điều này có nghĩa rằng việc gọi component này nhiều lần sẽ tạo ra JSX khác nhau! Hơn nữa, nếu các component khác đọc biến `guest`, họ cũng sẽ tạo ra JSX khác nhau, tùy thuộc vào thời điểm họ được render. Điều này không thể dự đoán.

Trở lại với công thức y = 2x, ngay cả khi x = 2, chúng ta không thể tin rằng y = 4. Các bài kiểm tra của chúng ta có thể thất bại, người dùng sẽ bối rối, máy bay sẽ rơi - bạn có thể thấy cách điều này dẫn đến các lỗi khó hiểu!

Bạn có thể sửa component này bằng cách truyền `guest` như một prop:

```javascript
function Cup({ guest }) {
  return <h2>Tea cup for guest #{guest}</h2>;
}
```

Bây giờ component của bạn là "pure", vì JSX nó trả về chỉ phụ thuộc vào prop `guest`.

Nhìn chung, bạn không nên mong đợi các component của bạn sẽ được render theo bất kỳ thứ tự nào. Không quan trọng liệu bạn gọi y = 2x trước hay sau y = 5x: cả hai công thức sẽ được tính toán độc lập. Tương tự, mỗi component chỉ nên "tự nghĩ cho bản thân", không cố gắng phối hợp hoặc phụ thuộc vào nhau trong quá trình render. Render giống như một bài kiểm tra trường học: mỗi component chỉ nên tính toán JSX dựa trên bản thân!

## Nhận biết tính không "pure" với Strict Mode

Trong React, để giúp phát hiện các lỗi liên quan đến tính "pure", bạn có thể sử dụng `Strict Mode`. Chế độ này cung cấp cảnh báo và thông báo lỗi khi React gặp các hành vi không mong muốn trong quá trình render. Điều này giúp bạn sửa lỗi sớm hơn và duy trì tính "pure" của ứng dụng React của bạn.

::alert{type="success"}

Trong bài viết này, chúng ta đã tìm hiểu về Pure Component trong React.js và tại sao chúng quan trọng. Chúng ta đã thấy rằng tính "pure" của một component giúp tránh được nhiều lỗi bất ngờ và hành vi khó hiểu trong mã nguồn của chúng ta. Để duy trì tính "pure", bạn cần tránh thay đổi các biến hoặc đối tượng tồn tại trước quá trình render và cân nhắc việc sử dụng `Strict Mode` để phát hiện lỗi.

Việc viết các hàm "pure" có thể cần thực hành, nhưng nó mở khóa sức mạnh của mô hình lập trình React. Hãy cố gắng bảo tồn tính "pure" của các component của bạn và thực hiện các tính toán chính trong JSX mà bạn trả về. Khi bạn cần "thay đổi điều gì đó", bạn thường muốn làm điều đó trong một event handler.

::
