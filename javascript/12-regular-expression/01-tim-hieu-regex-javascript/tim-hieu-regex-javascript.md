---
title: "Tìm hiểu regex trong Javascript"
description: "Biểu thức chính quy (regular expressions ) là các mẫu dùng để tìm kiếm các bộ kí tự được kết hợp với nhau trong các chuỗi kí tự."
keywords: [
"Tìm hiểu regex trong Javascript",
"regex trong Javascript",
"regex trong Javascript là gì",
"Cách sử dụng regex trong Javascript",
"regex javascript",
"Kí tự đặc biệt trong regex javascript",
"Regular expression trong javascript",
"biểu thức chính quy RegEx trong Javascript",
"biểu thức chính quy trong Javascript"
]
chapter:
  name: "Regular expression"
  slug: "chuong-12-regular-expression"
category:
  name: "Javascript"
  slug: "javascript"
image: https://kungfutech.edu.vn/thumbnail.png
position: 1
---

Regular expression hay còn được gọi tắt là Regex hay RegExp, là một cách để biểu diễn khuôn mẫu của string. Regex là một phần quan trọng của ngôn ngữ lập trình JavaScript, cũng như nhiều ngôn ngữ lập trình khác.

Nếu bạn là một lập trình viên và đã từng sử dụng Regular Expression thì bạn chắc hẳn sẽ thấy rằng nó có cú pháp rất kinh khủng và có phần "bí ẩn". Tuy nhiên, công cụ này lại cực kì mạnh mẽ và hiệu quả khi dùng để xử lý string.

Sau đây, chúng ta sẽ cùng tìm hiểu về Regular Expression trong JavaScript.

## Khởi tạo Regular Expression

Có hai cách để tạo ra một Regex JavaScript là:

- Sử dụng hàm khởi tạo của [đối tượng](/bai-viet/javascript/object-la-gi-object-trong-javascript) RegExp
- Viết trực tiếp sử dụng cặp dấu "/ /"

```js
var re1 = new RegExp("abc");
var re2 = /abc/;
```

Cả hai cách trên ta đều thu được một Regular Expression biểu diễn một string có dạng: _abc_.

## Một số phương thức của Regular Expression

### Phương thức Test

Đây là phương thức đơn giản nhất dùng để kiểm tra xem một string có chứa khuôn mẫu đã định nghĩa hay không. Nếu có thì kết quả trả về là TRUE và ngược lại thì là FALSE.

```js
console.log(/abc/.test("abcde"));
// => true
console.log(/abc/.test("12abcde"));
// => true
console.log(/abc/.test("abxcde"));
// => false
```

Trong ví dụ trên, 2 string "abcde" và "12abcde" đều chứa "abc" nên kết quả trả về là true. String còn lại "abxcde" không chứa "abc" nên kết quả là false.

#### Kiểm tra trùng khớp với tập hợp các kí tự

Nếu chỉ kiểm tra như ví dụ trên thì bạn hoàn toàn có thể sử dụng phương thức _indexOf_ của string thay vì sử dụng JavaScript Regular Expression.

Tuy nhiên, với RegExp JavaScript thì bạn có thể kiểm tra những mẫu string phức tạp hơn.

**Ví dụ:**

```js
console.log(/[0123456789]/.test("in 1992"));
// => true
console.log(/[0-9]/.test("in 1992"));
// => true
console.log(/[0-9]/.test("Hello "));
// => false
console.log(/[0-5]/.test("Gold 9999"));
// => false
```

Ví dụ 1, 2, 3 kiểm tra xem string có chứa bất kì chữ số nào từ 0 đến 9. Ví dụ cuối cùng kiểm tra xem string có chứa bất kì chữ số nào từ 0 đến 5.

JavaScript sử dụng cặp dấu ngoặc vuông \[\] để biểu thị việc kiểm tra string có chứa bất kì kí tự nào có trong cặp dấu \[\] hay không. Trong đó, dấu "-" giữa hai kí tự dùng để chỉ 1 khoảng giữa hai kí tự đó.

- `\[0-9\]` là các chữ số từ 0 đến 9
- `\[a-z\]` là các chữ cái từ a đến z

Ngoài ra, JavaScript cung cấp sẵn một số cách biểu diễn một tập hợp các kí tự:

- `\\d` : bất kì chữ số nào từ 0 đến 9
- `\\w` : một chữ cái
- `\\s` : kí tự trắng (dấu cách, tab, dòng mới,...)
- `\\D` : kí tự không phải số
- `\\W` : kí tự không phải chữ cái
- `\\S` : kí tự không phải kí tự trắng
- `.` : bất kì kí tự nào trừ dòng mới.

Ví dụ kiểm tra ngày giờ có định dạng: **dd-mm-yyyy hh:mm**

```js
var dateTime = /\d\d-\d\d-\d\d\d\d \d\d:\d\d/;
console.log(dateTime.test("30-01-2003 15:20"));
// => true
console.log(dateTime.test("30-jan-2003 15:20"));
// => false
```

#### Đảo ngược tập hợp các kí tự

Trường hợp bạn muốn kiểm tra một string chứa bất kì kí tự nào không có trong tập hợp đã cho thì bạn có thể sử dụng kí tự "^".

Ví dụ:

```js
var notBinary = /[^01]/;
console.log(notBinary.test("1100100010100110"));
// => false
console.log(notBinary.test("1100100010200110"));
// => true
```

#### Lặp lại khuôn mẫu

Trong ví dụ về kiểm tra ngày giờ bên trên, "\\d" xuất hiện lặp lại rất nhiều lần. Điều này gây nên sự khó theo dõi. Do đó, JavaScript cung cấp cách thức để biểu diễn sự lặp lại khuôn mẫu:

- "+": biểu thị phần tử xuất hiện >= 1 lần

```js
console.log(/'\d+'/.test("'123'"));
// => true
console.log(/'\d+'/.test("''"));
// => false
```

- "\*": biểu thị phần tử xuất hiện >= 0 lần (có thể không xuất hiện)

```js
console.log(/'\d*'/.test("'123'"));
// => true
console.log(/'\d*'/.test("''"));
// => true
```

- "?": biểu thị phần tử xuất hiện 0 hoặc 1 lần

```js
var neighbor = /neighbou?r/;
console.log(neighbor.test("neighbour"));
// => true
console.log(neighbor.test("neighbor"));
// => true
console.log(neighbor.test("neighbouur"));
// => false
```

- {n}: biểu thị phần tử xuất hiện đúng n lần

```js
console.log(/\d{4}/.test("1234"));
// => true
console.log(/\d{4}/.test("12345"));
// => true
console.log(/\d{4}/.test("123"));
// => false
```

- {x,y}: biểu thị phần tử xuất hiện từ x đến y lần

```js
console.log(/\d{2,4}/.test("12345"));
// => true
console.log(/\d{2,4}/.test("1234"));
// => true
console.log(/\d{2,4}/.test("123"));
// => true
console.log(/\d{2,4}/.test("12"));
// => true
console.log(/\d{2,4}/.test("1"));
// => false
```

- {x, }: biểu thị phần tử xuất hiện >= x lần

```js
console.log(/\d{2,}/.test("12"));
// => true
console.log(/\d{2,}/.test("1234"));
// => true
console.log(/\d{2,}/.test("1"));
// => false
```

#### Nhóm các phần tử

Trong nhiều trường hợp bạn muốn lặp lại cả một nhóm các phần tử. Khi đó, bạn phải nhóm các phần tử đó lại sử dụng cặp dấu ngoặc đơn "( )".

```js
var cartoonCrying = /boo+(hoo+)+/i;
console.log(cartoonCrying.test("Boohoooohoohooo"));
// => true
```

#### Lựa chọn khuôn mẫu

Trường hợp bạn có nhiều khuôn mẫu và bạn cần kiểm tra xem string đưa ra chứa một trong các khuôn mẫu đó thì bạn có thể viết các Regular Expression tương ứng để kiểm tra. Hoặc sử dụng kí tự (|) để biểu diễn "hoặc":

```js
var animalCount = /\d+ (pig|cow|chicken)s?/;
console.log(animalCount.test("15 pigs"));
// => true
console.log(animalCount.test("15 pigchickens"));
// => false
```

### Phương thức Exec

Nếu như phương thức **test** chỉ kiểm tra xem có tồn tại khuôn mẫu hay không thì phương thức **exec** sẽ trả về một đối tượng chứa thông tin thành phần trùng khớp với khuôn mẫu, ngược lại thì trả về null.

```js
var match = /\d+/.exec("one two 100 200");
console.log(match);
// => ["100", index: 8, input: "one two 100 200"]
console.log(match.index);
// => 8
```

Ví dụ trên trả về thành phần thoả mãn khuôn mẫu đầu tiên là: "100". _Index_ là vị trí đầu tiên của string thoả mãn khuôn mẫu.

Khi Regular Expression chứa group với cặp dấu ngoặc đơn thì phần tử đầu tiên trong kết quả sẽ là toàn bộ thành phần trùng khớp, thành phần tiếp theo là phần trùng khớp với group đầu tiên, thành phần tiếp theo là phần trùng khớp với group thứ 2,...

```js
var quotedText = /'([^']*)'/;
console.log(quotedText.exec("she said 'hello'"));
// => ["'hello'", "hello", index: 9, input: "she said 'hello'"]

console.log(/bad(ly)?/.exec("bad"));
// => ["bad", undefined, index: 0, input: "bad"]

console.log(/(\d)+/.exec("123"));
// => ["123", "3", index: 0, input: "123"]
```

Đặc biệt nếu một group có nhiều thành phần trùng khớp thì chỉ lấy thành phần trùng khớp cuối cùng. Trong ví dụ trên, group **(\\d)** có 3 thành phần trùng khớp là **1**, **2**, **3**. Nhưng chỉ thành phần trùng khớp cuối cùng là **3** xuất hiện trong kết quả.

#### Trích xuất dữ liệu từ string

Phương thức này đặc biệt hữu ích khi bạn muốn lấy thông tin ra từ string.

Ví dụ sau đưa ra một string biểu diễn ngày, tháng, năm. Sau đó chúng ta sẽ trích xuất ra thông tin về ngày, tháng và năm ở trong đó:

```js
function findDate(string) {
  var dateTime = /(\d{1,2})-(\d{1,2})-(\d{4})/;
  var match = dateTime.exec(string);
  return {
    day: match[1],
    month: match[2],
    year: match[3],
  };
}
var obj = findDate("30-1-2003");
console.log(obj);
// => Object {day: "30", month: "1", year: "2003"}
```

#### Ranh giới của string

Trong ví dụ trên, hàm findDate vẫn tìm ra kết quả nếu như string là "30-1-200300" hay "1130-1-2003",... Đây là trường hợp không mong muốn.

Regular Expression JavaScript cung cấp 2 cách để giải quyết vấn đề này:

- Sử dụng kí tự biểu diễn bắt đầu (^) và kết thúc ($) string

```js
function findDate(string) {
  var dateTime = /^(\d{1,2})-(\d{1,2})-(\d{4})$/;
  var match = dateTime.exec(string);
  if (!match) return null;
  return {
    day: match[1],
    month: match[2],
    year: match[3],
  };
}
var obj1 = findDate("30-1-2003");
console.log(obj1);
// => Object {day: "30", month: "1", year: "2003"}

var obj2 = findDate("0030-1-200300");
console.log(obj2);
// => null

var obj3 = findDate("Hello 30-1-2003 Haha");
console.log(obj3);
// => null
```

- Sử dụng kí tự biên (\\b)

```js
function findDate(string) {
  var dateTime = /\b(\d{1,2})-(\d{1,2})-(\d{4})\b/;
  var match = dateTime.exec(string);
  if (!match) return null;
  return {
    day: match[1],
    month: match[2],
    year: match[3],
  };
}
var obj1 = findDate("30-1-2003");
console.log(obj1);
// => Object {day: "30", month: "1", year: "2003"}

var obj2 = findDate("0030-1-200300");
console.log(obj2);
// => null

var obj3 = findDate("Hello 30-1-2003 Haha");
console.log(obj3);
// => Object {day: "30", month: "1", year: "2003"}
```

## Tạo đối tượng RegExp JavaScript một cách linh động

Trong nhiều trường hợp, bạn muốn tạo ra một Regular Expression với nội dung chưa được biết trước. Bạn có thể sử dụng hàm khởi tạo của RegExp theo cách sau:

```js
var name = "lampv";
var text = "LamPV is a suspicious character.";
var regexp = new RegExp("\\b(" + name + ")\\b", "gi");
console.log(text.replace(regexp, "_$1_"));
// => _LamPV_ is a suspicious character.
```

Trong đó:

- tham số g: chỉ ra rằng khuôn mẫu áp dụng Global, nghĩa là nó áp dụng cho tất cả thành phần trùng khớp.
- tham số i: chỉ ra rằng khuôn mẫu không phân biệt chữ hoa và chữ thường.

Ngoài ra, ở đây mình có sử dụng phương thức _replace_ của [string](/bai-viet/javascript/cac-kieu-du-lieu-trong-javascript) - dùng để thay thế tất cả những thành phần trùng khớp với khuôn mẫu với "_$1_".

Ở đây $1 chính là nội dung của group thứ nhất.

## Kết luận

Trên đây là một số kiến thức cơ bản về Regular Expression. Hy vọng qua bài viết này bạn phần nào hiểu và biết cách sử dụng Regex JavaScript.

Tóm tắt một số khuôn mẫu cơ bản của Regex trong JavaScript:

- `/abc/` : chuỗi các kí tự _abc_
- `/\[abc\]`: bất kỳ kí tự nào thuộc tập hợp a, b, c
- `/\[^abc\]`: bất kỳ kí tự nào không thuộc tập a, b, c
- `/\[0-9\]/`: bất kỳ kí tự nào thuộc đoạn từ 0 đến 9
- `/x+/`: thành phần x xuất hiện >= 1 lần
- `/x\*/`: thành phần x xuất hiện >= 0 lần (có thể không xuất hiện)
- `/x?/`: thành phần x xuất hiện 0 hoặc 1 lần
- `/x{2, 4}/`: thành phần x xuất hiện từ 2 đến 4 lần
- `/(abc)/`: cụm _abc_
- `/a|b|c/`: bất kì pattern nào trong 3 loại a, b, c
- `/\\d/`: chữ số từ 0 đến 9
- `/\\w/`: chữ cái
- `/\\s/`: kí tự trắng (dấu cách, tab, dòng mới,...)
- `/./` : bất kỳ kí tự nào trừ dòng mới
- `/\\b/`: ranh giới từ
- `/^/`: bắt đầu string
- `/$/`: kết thúc string

## Tham khảo

- [Regular Expressions](https://eloquentjavascript.net/09_regexp.html)
