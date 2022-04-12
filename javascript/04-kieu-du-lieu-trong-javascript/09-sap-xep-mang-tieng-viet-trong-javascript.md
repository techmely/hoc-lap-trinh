---
title: "Sắp xếp mảng tiếng việt trong Javascript"
description: ""
keywords: []
chapter:
  name: "Kiểu dữ liệu trong Javascript"
  slug: "chuong-04-kieu-du-lieu-trong-javascript"
category:
  name: "Javascript"
  slug: "javascript"
image: https://kungfutech.edu.vn/thumbnail.png
position: 9
---

Sắp xếp là một bài toán không thể thiếu trong lập trình. Tuy nhiên, nhiều bạn vẫn đang gặp khó khăn với việc **sắp xếp Tiếng việt trong JavaScript**.

Vì vậy, mình sẽ giới thiệu với bạn về cách mình giải quyết bài toán sắp xếp Tiếng Việt này.

[](#nh%E1%BA%AFc-l%E1%BA%A1i-h%C3%A0m-sort-trong-javascript)Nhắc lại hàm `sort()` trong JavaScript
--------------------------------------------------------------------------------------------------

Trong bài viết về [sắp xếp mảng](/sap-xep-mang-trong-javascript/), mình đã giới thiệu với bạn khá chi tiết về hàm [sort()](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array/sort) và cách triển khai một số [thuật toán](/tag/thuat-toan/) sắp xếp cơ bản.

Bây giờ, mình sẽ nhắc lại hàm `sort()` một chút cho bạn tiện theo dõi. Vì phần sau đây sử dụng hàm này để sắp xếp Tiếng Việt trong JavaScript.

Cú pháp cơ bản của hàm `sort(compareFunction)` là:

    arr.sort(compareFunction);

► Tham số `compareFunction`:

*   Là [hàm](/ham-la-gi-ham-trong-javascript/) dùng để xác định thứ tự sắp xếp.
*   Nếu bạn bỏ qua tham số này, mặc định JavaScript sẽ sắp xếp theo thứ tự tăng dần trong bảng mã Unicode (đơn giản là thứ tự tăng dần bảng chữ cái).
*   Ý nghĩa đối với thứ tự sắp xếp:
    *   Nếu hàm `compareFunction(a, b)` trả về giá trị nhỏ hơn `0` thì `a` sẽ đứng trước `b`.
    *   Nếu hàm `compareFunction(a, b)` trả về giá trị lớn hơn `0` thì `a` sẽ đứng sau `b`.
    *   Nếu hàm `compareFunction(a, b)` trả về giá trị bằng `0` thì giữ nguyên thứ tự `a`, `b`.

► Giá trị trả về:

*   Là [mảng](/array-la-gi-array-trong-javascript/) đã được sắp xếp.
*   Mảng ban đầu có bị thay đổi.

Ví dụ:

    const a = ["c", "g", "w", "a"];
    const b = a.sort();
    
    console.log(a); // ["a", "c", "g", "w"]
    console.log(b); // ["a", "c", "g", "w"]

Trên đây là những kiến thức cơ bản về cách sử dụng hàm `sort()` trong JavaScript. Tiếp theo, mình bắt đầu áp dụng hàm `sort()` để sắp xếp Tiếng Việt trong JavaScript.

[](#s%E1%BA%AFp-x%E1%BA%BFp-ti%E1%BA%BFng-vi%E1%BB%87t-trong-javascript)Sắp xếp Tiếng Việt trong JavaScript
-----------------------------------------------------------------------------------------------------------

### [](#%C4%91%E1%BA%B7t-b%C3%A0i-to%C3%A1n)Đặt bài toán

Giả sử mình có một mảng string Tiếng Việt là tên một số tỉnh thành tại Việt Nam:

    const provinces = [
      "Hà Giang",
      "Hà Nam",
      "Hà Nội",
      "Hà Tĩnh",
      "Hòa Bình",
      "Hưng Yên",
      "Hải Dương",
      "Hải Phòng",
      "Hậu Giang",
    ];

Mình cần sắp xếp các tên này theo thứ tự tăng dần của bảng chữ cái Tiếng Việt. Kết quả mong muốn thu được là:

    const sorted = [
      "Hà Giang",
      "Hà Nam",
      "Hà Nội",
      "Hà Tĩnh",
      "Hải Dương",
      "Hải Phòng",
      "Hậu Giang",
      "Hòa Bình",
      "Hưng Yên",
    ];

### [](#s%E1%BA%AFp-x%E1%BA%BFp-ti%E1%BA%BFng-vi%E1%BB%87t-b%E1%BA%B1ng-h%C3%A0m-sort-th%C3%B4ng-th%C6%B0%E1%BB%9Dng)Sắp xếp Tiếng Việt bằng hàm `sort()` thông thường

Trước tiên, mình thử sắp xếp mảng trên bằng hàm `sort()` thông thường.

Vì mặc định hàm `sort()` sẽ sắp xếp string theo thứ tự tăng dần nên mình không cần truyền vào **compareFunction**.

Do đó, kết quả thu được như sau:

    const result = provinces.sort();
    console.log(result);
    
    /*
    [
      "Hà Giang", 
      "Hà Nam", 
      "Hà Nội", 
      "Hà Tĩnh", 
      "Hòa Bình", 
      "Hưng Yên", 
      "Hải Dương", 
      "Hải Phòng", 
      "Hậu Giang"
    ]
    */

Kết quả trên là **sai so với mong muốn ban đầu**. Vậy mình phải làm sao đây?

### [](#s%E1%BA%AFp-x%E1%BA%BFp-ti%E1%BA%BFng-vi%E1%BB%87t-trong-javascript-v%E1%BB%9Bi-localecompare)Sắp xếp Tiếng Việt trong JavaScript với `localeCompare()`

Nguyên nhân hàm `sort()` trên thực hiện sai là vì nó đang so sánh string với Tiếng Anh. Vì vậy, mấu chốt của vấn đề là: làm sao có thể so sánh string với Tiếng Việt để đưa vào hàm `sort()`?

Câu trả lời là: sử dụng phương thức [`localeCompare()`](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/String/localeCompare) với cú pháp cơ bản là:

    a.localeCompare(b);

Có 3 trường hợp xảy ra với kết quả trả về:

*   Nếu kết quả trả về nhỏ hơn `0` thì `a` sẽ đứng trước `b`.
*   Nếu kết quả trả về lớn hơn `0` thì `a` sẽ đứng sau `b`.
*   Nếu kết quả trả về bằng `0` thì `a` và `b` giống nhau.

Thật là trùng hợp, cách hoạt động của phương thức `localeCompare()` lại hoàn toàn giống với `compareFunction` bên trên. Vì vậy, mình có thể áp dụng ngay để sắp xếp Tiếng Việt như sau:

    const result = provinces.sort((a, b) => a.localeCompare(b));
    console.log(result);
    
    /*
    [
      "Hà Giang", 
      "Hà Nam", 
      "Hà Nội", 
      "Hà Tĩnh", 
      "Hải Dương", 
      "Hải Phòng", 
      "Hậu Giang", 
      "Hòa Bình", 
      "Hưng Yên"
    ]
    */

Kết quả thu được bây giờ hoàn toàn đúng với mong đợi.

[](#l%E1%BB%9Di-k%E1%BA%BFt)Lời kết
-----------------------------------

Như vậy là mình đã sắp xếp Tiếng Việt trong JavaScript một cách đơn giản rồi phải không?

Ngoài cách làm trên ra, bạn còn biết phương pháp nào khác để sắp xếp Tiếng Việt trong JavaScript không?

Nếu có thì bạn hãy chia sẻ dưới phần bình luận nhé!