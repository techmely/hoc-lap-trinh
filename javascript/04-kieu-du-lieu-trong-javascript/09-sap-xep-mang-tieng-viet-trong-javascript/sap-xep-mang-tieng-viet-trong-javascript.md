---
title: "Sắp xếp mảng tiếng việt trong Javascript"
description: "Sắp xếp là một bài toán không thể thiếu trong lập trình. Tuy nhiên, nhiều bạn vẫn đang gặp khó khăn với việc sắp xếp Tiếng việt trong JavaScript.Vì vậy, mình sẽ giới thiệu với bạn về cách mình giải quyết bài toán sắp xếp Tiếng Việt này."
keywords: ["Sắp xếp mảng tiếng việt trong Javascript",
"sap xep mang javascript",
"sap xep mang tieng viet javascript",
"sap xep mang theo ten trong javascript",
"sort trong javascript",
"sap xep trong javascript",
"cách sắp xếp mảng tiếng việt trong JavaScript",
"sắp xếp mảng tiếng việt trong javascript như thế nào",
"sap xep mang tieng viet trong javascript nhu the nao",
"cac cach sap xep trong jacascript"
]
chapter:
  name: "Kiểu dữ liệu trong Javascript"
  slug: "chuong-04-kieu-du-lieu-trong-javascript"
category:
  name: "Javascript"
  slug: "javascript"
image: https://user-images.githubusercontent.com/29374426/168242982-85255f57-649f-4ce2-9d8f-b18e7000d66d.png
position: 9
---

Sắp xếp là một bài toán không thể thiếu trong lập trình. Tuy nhiên, nhiều bạn vẫn đang gặp khó khăn với việc **sắp xếp Tiếng việt trong JavaScript**.

Vì vậy, mình sẽ giới thiệu với bạn về cách mình giải quyết bài toán sắp xếp Tiếng Việt này.

## Nhắc lại hàm `sort()` trong JavaScript

Trong bài viết về [sắp xếp mảng](/bai-viet/javascript/sap-xep-mang-trong-javascript), mình đã giới thiệu với bạn khá chi tiết về hàm [sort()](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array/sort) và cách triển khai một số thuật toán sắp xếp cơ bản.

Bây giờ, mình sẽ nhắc lại hàm `sort()` một chút cho bạn tiện theo dõi. Vì phần sau đây sử dụng hàm này để sắp xếp Tiếng Việt trong JavaScript.

Cú pháp cơ bản của hàm `sort(compareFunction)` là:

```js
arr.sort(compareFunction);
```

► Tham số `compareFunction`:

- Là [hàm](/bai-viet/javascript/ham-trong-javascript) dùng để xác định thứ tự sắp xếp.
- Nếu bạn bỏ qua tham số này, mặc định JavaScript sẽ sắp xếp theo thứ tự tăng dần trong bảng mã Unicode (đơn giản là thứ tự tăng dần bảng chữ cái).
- Ý nghĩa đối với thứ tự sắp xếp:
  - Nếu hàm `compareFunction(a, b)` trả về giá trị nhỏ hơn `0` thì `a` sẽ đứng trước `b`.
  - Nếu hàm `compareFunction(a, b)` trả về giá trị lớn hơn `0` thì `a` sẽ đứng sau `b`.
  - Nếu hàm `compareFunction(a, b)` trả về giá trị bằng `0` thì giữ nguyên thứ tự `a`, `b`.

► Giá trị trả về:

- Là [mảng](/bai-viet/javascript/mang-array-trong-javascript) đã được sắp xếp.
- Mảng ban đầu có bị thay đổi.

Ví dụ:

```js
const a = ["c", "g", "w", "a"];
const b = a.sort();

console.log(a); // ["a", "c", "g", "w"]
console.log(b); // ["a", "c", "g", "w"]
```

Trên đây là những kiến thức cơ bản về cách sử dụng hàm `sort()` trong JavaScript. Tiếp theo, mình bắt đầu áp dụng hàm `sort()` để sắp xếp Tiếng Việt trong JavaScript.

## Sắp xếp Tiếng Việt trong JavaScript

### Đặt bài toán

Giả sử mình có một mảng string Tiếng Việt là tên một số tỉnh thành tại Việt Nam:

```js
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
```

Mình cần sắp xếp các tên này theo thứ tự tăng dần của bảng chữ cái Tiếng Việt. Kết quả mong muốn thu được là:

```js
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
```

### ` thông thường

Trước tiên, mình thử sắp xếp mảng trên bằng hàm `sort()` thông thường.

Vì mặc định hàm `sort()` sẽ sắp xếp string theo thứ tự tăng dần nên mình không cần truyền vào **compareFunction**.

Do đó, kết quả thu được như sau:

```js
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
```

Kết quả trên là **sai so với mong muốn ban đầu**. Vậy mình phải làm sao đây?

Nguyên nhân hàm `sort()` trên thực hiện sai là vì nó đang so sánh string với Tiếng Anh. Vì vậy, mấu chốt của vấn đề là: làm sao có thể so sánh string với Tiếng Việt để đưa vào hàm `sort()`?

Câu trả lời là: sử dụng phương thức [`localeCompare()`](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/String/localeCompare) với cú pháp cơ bản là:

    a.localeCompare(b);

Có 3 trường hợp xảy ra với kết quả trả về:

- Nếu kết quả trả về nhỏ hơn `0` thì `a` sẽ đứng trước `b`.
- Nếu kết quả trả về lớn hơn `0` thì `a` sẽ đứng sau `b`.
- Nếu kết quả trả về bằng `0` thì `a` và `b` giống nhau.

Thật là trùng hợp, cách hoạt động của phương thức `localeCompare()` lại hoàn toàn giống với `compareFunction` bên trên. Vì vậy, mình có thể áp dụng ngay để sắp xếp Tiếng Việt như sau:

```js
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
```

Kết quả thu được bây giờ hoàn toàn đúng với mong đợi.

## Tổng kết

Như vậy là mình đã sắp xếp Tiếng Việt trong JavaScript một cách đơn giản rồi phải không?

Ngoài cách làm trên ra, bạn còn biết phương pháp nào khác để sắp xếp Tiếng Việt trong JavaScript không?

Nếu có thì bạn hãy chia sẻ dưới phần bình luận nhé!
