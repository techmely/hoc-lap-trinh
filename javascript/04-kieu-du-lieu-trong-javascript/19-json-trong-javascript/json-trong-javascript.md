---
title: "JSON trong Javascript"
description: "JSON là viết tắt của JavaScript Object Notation, là một kiểu định dạng dữ liệu tuân theo một quy luật nhất định mà hầu hết các ngôn ngữ lập trình hiện nay đều có thể đọc được. JSON là một tiêu chuẩn mở để trao đổi dữ liệu trên web."
keywords: ["JSON trong Javascript",
"json trong javascript",
"json trong javascript la gi",
"json trong javascript dung de lam gi",
"cach dung json trong javascript",
"xu ly file json trong javascript",
"cach lay du lieu tu json trong java script",
"Đọc file JSON trong JavaScript",
"ham json trong javascript",
"json_encode trong javascript"
]
chapter:
  name: "Kiểu dữ liệu trong Javascript"
  slug: "chuong-04-kieu-du-lieu-trong-javascript"
category:
  name: "Javascript"
  slug: "javascript"
image: https://user-images.githubusercontent.com/29374426/168244482-e12888eb-898f-427c-ad6c-4a403cd31dd3.png
position: 19
---

Giả sử, bạn có một object phức tạp. Và bạn muốn **chuyển object thành dạng string** để gửi lên server hoặc ghi log ra file.

![JSON trong Javascript](https://user-images.githubusercontent.com/29374426/168244482-e12888eb-898f-427c-ad6c-4a403cd31dd3.png)


Cách đơn giản là bạn viết phương thức `toString()` chứa tất cả các thuộc tính của object, ví dụ:

```js
let user = {
  name: "Alex",
  age: 28,
  toString() {
    return `{name: ${this.name}, age: ${this.age}}`;
  },
};

console.log(user.toString()); // {name: Alex, age: 28}
```

Tuy nhiên, cách này gặp **khó khăn khi phát triển**. Vì các thuộc tính của object **có thể thay đổi**, thêm hoặc bớt bất kỳ lúc nào.

Khi đó, bạn phải thường xuyên cập nhật lại phương thức `toString()`. Việc này chắc chắn sẽ mất thời gian.

May mắn thay, bạn có một công cụ vô cùng mạnh mẽ là: **JSON trong JavaScript**.

## JSON trong JavaScript

[JSON](https://vi.wikipedia.org/wiki/JSON) là viết tắt của **JavaScript Object Notation**. Đây là một định dạng chung để biểu diễn các giá trị và object.

Ban đầu, JSON được tạo ra để dùng trong JavaScript. Sau đó, **nhiều thư viện ở các ngôn ngữ khác nhau** được sinh ra để xử lý JSON.

Qua đó, JSON được sử dụng nhiều để trao đổi dữ liệu giữa client (JavaScript) và server (Ruby, PHP, Java,...).

JSON trong JS có hai phương thức là:

- `JSON.stringify()`: chuyển object thành string.
- `JSON.parse()`: chuyển string thành object.

## Phương thức `JSON.stringify`

Ví dụ sử dụng `JSON.stringify()` để chuyển đối tượng `user` thành string như sau:

```js
let user = {
  name: "Alex",
  age: 28,
};

let json = JSON.stringify(user);
console.log(json); // {"name":"Alex","age":28}
console.log(typeof json); // string
```

Trong ví dụ trên, phương thức `JSON.stringify(user)` nhận vào một object và trả về string biểu diễn object đã truyền vào.

**Chú ý:** JSON trong JavaScript khác với kí hiệu object (object literal).

- Trong JSON, string luôn sử dụng dấu nháy kép `""`, mà không sử dụng dấu nháy đơn `''` hay dấu backtick ` `` `.
- Thuộc tính của object cũng chuyển thành string sử dụng dấu nháy kép `""`. Do đó, `name` và `age` trở thành `"name"` và `"age"`.

`JSON.stringify` cũng có thể áp dụng cho kiểu dữ liệu nguyên thủy. Và sau đây là những kiểu dữ liệu mà JSON trong JavaScript hỗ trợ:

- Object `{...}`
- Array `[...]`
- Kiểu nguyên thủy:
  - string
  - number
  - boolean
  - `null`

Ví dụ JSON với các kiểu dữ liệu:

```js
// số chuyển sang JSON vẫn là số
console.log(JSON.stringify(1)); // 1

// string chuyển sang JSON vẫn là string, nhưng sử dụng dấu ""
console.log(JSON.stringify("test")); // "test"

// boolean chuyển sang JSON vẫn là boolean
console.log(JSON.stringify(true)); // true

// mảng chuyển sang JSON
console.log(JSON.stringify([1, 2, 3])); // [1,2,3]
```

JSON chỉ **đơn giản là dữ liệu** và độc lập với ngôn ngữ lập trình. Do đó, một vài thuộc tính của object bị bỏ qua khi dùng `JSON.stringify` như:

- [Phương thức của object](/bai-viet/javascript/object-la-gi-object-trong-javascript).
- [Symbol](/bai-viet/javascript/symbol-trong-javascript) key và value.
- Thuộc tính với giá trị là `undefined`.

```js
let user = {
  // phương thức bị bỏ qua
  sayHi() {
    console.log("Hello");
  },
  [Symbol("id")]: 12356, // symbole bị bỏ qua
  something: undefined, // thuộc tính với giá trị undefined cũng bị bỏ qua
};

console.log(JSON.stringify(user)); // {} (string không có thuộc tính nào)
```

> Điều này là hoàn toàn bình thường. Nhưng nếu đó không phải thứ bạn muốn, bạn vẫn có thể **tùy biến được quá trình** chuyển từ object sang string.

Phương thức `JSON.stringify` áp dụng được với object, array có nhiều tầng lồng nhau, ví dụ:

```js
let meetup = {
  title: "Conference",
  room: { number: 23, participants: ["alex", "ann"] },
};

console.log(JSON.stringify(meetup));
```

<content-result>

<code>
{
  "title":"Conference",
  "room":{"number":23,"participants":["alex","ann"]},
}
</code>

</content-result>

Tuy nhiên, `JSON.stringify` không hỗ trợ nếu object có **tham chiếu vòng tròn**, ví dụ:

```js
let room = {
  number: 23,
};

let meetup = {
  title: "Conference",
  participants: ["alex", "ann"],
};

meetup.place = room; // meetup tham chiếu đến room
room.occupiedBy = meetup; // room tham chiếu lại đến meetup.

JSON.stringify(meetup); // Lỗi: Converting circular structure to JSON
```

## Tùy biến phương thức `JSON.stringify`

Cú pháp đầy đủ của `JSON.stringify` trong JavaScript là:

```js
let json = JSON.stringify(value[, replacer, space])
```

Trong đó:

- `value`: là giá trị đầu vào cần chuyển thành string.
- `replacer`: **mảng chứa các thuộc tính** được dùng để chuyển sang string hoặc một hàm `function(key, value)` - được gọi với mỗi thuộc tính của object.
- `space`: số lượng kí tự **dấu cách** dùng để format JSON trong JS.

Thông thường, phương thức `JSON.stringify` chỉ cần truyền vào tham số đầu tiên.

Tuy nhiên, nếu bạn muốn tùy chỉnh quá trình chuyển từ object sang JSON, bạn có thể sử dụng tham số thứ 2 và thứ 3.

Ví dụ truyền vào một mảng các thuộc tính dành cho `JSON.stringify`:

```js
let room = {
  number: 23,
};

let meetup = {
  title: "Conference",
  participants: [{ name: "Alex" }, { name: "Anna" }],
  place: room, // meetup tham chiếu đến room
};

room.occupiedBy = meetup; // room tham chiếu đến meetup

console.log(JSON.stringify(meetup, ["title", "participants"])); // {"title":"Conference","participants":[{},{}]}
```

Bây giờ, `JSON.stringify` đã không bị lỗi **tham chiếu vòng** như trên.

Tuy nhiên, thuộc tính `place` bị biến mất và các phần tử bên trong mảng `participants` lại là object rỗng `{}`. Đó là bởi vì thuộc tính `name` và `place` không nằm trong danh sách cho phép.

Bạn có thể tùy chỉnh danh sách thuộc tính cho phép để chấp nhận tất cả các thuộc tính, ngoại trừ thuộc tính có tham chiếu vòng `occupiedBy` như sau:

```js
let room = {
  number: 23,
};

let meetup = {
  title: "Conference",
  participants: [{ name: "Alex" }, { name: "Anna" }],
  place: room, // meetup tham chiếu đến room
};

room.occupiedBy = meetup; // room tham chiếu đến meetup

let json = JSON.stringify(meetup, [
  "title",
  "participants",
  "place",
  "number",
  "name",
]);
console.log(json);
// {"title":"Conference","participants":[{"name":"Alex"},{"name":"Anna"}],"place":{"number":23}}
```

Tất cả các thuộc tính (trừ `occupiedBy`) đã được đưa vào JSON. Tuy nhiên, cách sử dụng vẫn khá dài dòng. Để giải quyết vấn đề này, bạn có thể dùng hàm `replacer` thay thế cho mảng.

Hàm `replacer` được gọi với mỗi cặp **(key, value)** trong object và trả về giá trị được thay thế hoặc trả về `undefined` nếu bạn muốn bỏ qua thuộc tính.

```js
let room = {
  number: 23,
};

let meetup = {
  title: "Conference",
  participants: [{ name: "Alex" }, { name: "Anna" }],
  place: room, // meetup tham chiếu đến room
};

room.occupiedBy = meetup; // room tham chiếu đến meetup

let json = JSON.stringify(meetup, function (key, value) {
  console.log(`${key}: ${value}`);
  return key == "occupiedBy" ? undefined : value;
});

console.log(json);
/*
    : [object Object]
    title: Conference
    participants: [object Object],[object Object]
    0: [object Object]
    name: Alex
    1: [object Object]
    name: Anna
    place: [object Object]
    number: 23
    occupiedBy: [object Object]

    {"title":"Conference","participants":[{"name":"Alex"},{"name":"Anna"}],"place":{"number":23}}
    */
```

**Chú ý:** hàm `replacer` được gọi với mỗi cặp `(key, value)` bao gồm cả object và mảng lồng nhau **một cách đệ quy**. Giá trị `this` trong hàm `replacer` là object chứa thuộc tính đang xét.

Lần gọi hàm đầu tiên, hàm `replacer` tạo ra một "wrapper object": `{"": meetup}`. Nói cách khác, cặp `(key, value)` đầu tiên không có `key`, còn `value` là toàn bộ object `meetup`.

Đó là lý do tại sao dòng đầu tiên in ra: `: [object Object]`.

## Sử dụng tham số `space` trong `JSON.stringify`

Tham số thứ ba trong `JSON.stringify(value, replacer, space)` là số lượng kí tự dấu cách "space" dùng để định dạng json.

Trong các ví dụ trên, mình không sử dụng `space` nên kết quả json luôn là "string nằm trên một dòng".

> "JSON nằm trên một dòng" là tốt cho việc gửi dữ liệu lên server. Tuy nhiên, nếu bạn muốn ghi log ra để theo dõi thì cách này lại rất khó nhìn.

Ví dụ sử dụng `JSON.stringify` với `space = 2` để in log tốt hơn:

```js
let user = {
  name: "Alex",
  age: 28,
  roles: {
    isAdmin: false,
    isEditor: true,
  },
};

// replacer = null - nếu không muốn tùy chỉnh tham số này.
// space = 2 - các thuộc tính sẽ xuống dòng và thụt 2 dấu cách so với cha.
let json = JSON.stringify(user, null, 2);
console.log(json);
/*
    {
      "name": "Alex",
      "age": 28,
      "roles": {
        "isAdmin": false,
        "isEditor": true
      }
    }
    */
```

Bạn có thể tùy chỉnh giá trị của `space` lớn hơn `2` nếu muốn khoảng cách rộng hơn.

Ngoài ra, giá trị của `space` có thể là một string. Khi đó, string được sử dụng thay thế cho dấu cách - giống trường hợp `space=2` như sau:

```js
let user = {
  name: "Alex",
  age: 28,
  roles: {
    isAdmin: false,
    isEditor: true,
  },
};

// space = "a" - các thuộc tính sẽ xuống dòng và thụt 2 string "a" so với cha.
let json = JSON.stringify(user, null, "aa");
console.log(json);
/*
    {
    aa"name": "Alex",
    aa"age": 28,
    aa"roles": {
    aaaa"isAdmin": false,
    aaaa"isEditor": true
    aa}
    }
     */
```

## Tùy biến `toJSON`

Tương tự như phương thức `toString` khi chuyển đổi kiểu dữ liệu sang string, object có thể cung cấp phương thức `toJSON` để chuyển đổi sang JSON với `JSON.stringify`, ví dụ:

```js
let room = {
  number: 23,
};

let meetup = {
  title: "Conference",
  date: new Date(Date.UTC(2021, 11, 19)),
  room,
};

console.log(JSON.stringify(meetup, null, 2));
/*
    {
      "title": "Conference",
      "date": "2021-12-19T00:00:00.000Z",
      "room": {
        "number": 23
      }
    }
    */
```

Bạn thấy rằng [đối tượng `Date`](/bai-viet/javascript/doi-tuong-date-trong-javascript/) đã chuyển sang string. Vì bản thân đối tượng `Date` đã có phương thức `toJSON` trả về string như trên.

Mình cũng có thể thêm phương thức `toJSON` vào đối tượng `room`:

```js
let room = {
  number: 23,
  toJSON() {
    return this.number;
  },
};

console.log(JSON.stringify(room)); // 23
```

## Phương thức `JSON.parse`

Phương thức `JSON.parse(json)` dùng để chuyển JSON-string trở thành giá trị (object, array hoặc các kiểu dữ liệu nguyên thủy tương ứng) với cú pháp:

```js
let value = JSON.parse(str, [reviver]);
```

Trong đó:

- `str` là JSON-string để parse.
- `reviver` là một hàm (không bắt buộc) dạng `function(key, value)` - được gọi với mỗi cặp `(key, value)` và biến đổi value.

Ví dụ:

```js
// JSON-string dạng mảng
let numbers = "[0, 1, 2, 3]";

// parse JSON-string về mảng
numbers = JSON.parse(numbers);

// sau khi numbers được parse thành array,
// bạn có thể truy cập phần tử mảng qua chỉ số
console.log(numbers[1]); // 1
```

Hoặc object lồng nhau:

```js
let data =
  '{ "name": "John", "age": 35, "isAdmin": false, "friends": [0,1,2,3] }';

let user = JSON.parse(data);

console.log(user.friends[1]); // 1
```

JSON có thể có cấu trúc phức tạp, bao gồm nhiều kiểu dữ liệu, mảng, object lồng nhau. Nhưng chúng bắt buộc phải tuân theo định dạng chuẩn của JSON.

Một số lỗi JSON không hợp lệ như sau:

```js
let json = `{
      name: "John",           // không hợp lệ: thuộc tính không có nháy kép ""
      "surname": 'Smith',     // không hợp lệ: giá trị sử dụng nháy đơn ''
      'isAdmin': false        // không hợp lệ: thuộc tính sử dụng nháy đơn
      "birthday": new Date(), // không hợp lệ: toán tử new không được phép
      "friends": [0,1,2,3]    // hợp lệ
    }`;
```

Ngoài ra, JSON khác với Object là không chấp nhận **comment code** và **không chấp nhận dấu phẩy đuôi**:

```js
// comment trong JSON
let json1 = `{
      "x": 1, // comment 1
      "y": 2
    }`;
JSON.parse(json1); // Lỗi: Unexpected token / in JSON at position 12

// dấu phẩy đuôi trong JSON
let json2 = `{
      "x": 1,
      "y": 2,
    }`;
JSON.parse(json2); // Lỗi: Unexpected token } in JSON at position 22
```

## Sử dụng `reviver` trong `JSON.parse`

Giả sử, bạn có JSON-string lấy từ server như sau:

```js
// title: (meetup title), date: (meetup date)
let str = '{"title":"Conference","date":"2021-12-19T10:00:00.000Z"}';
```

Bạn muốn parse JSON-string về object để lấy thông tin:

```js
let str = '{"title":"Conference","date":"2021-12-19T10:00:00.000Z"}';

let meetup = JSON.parse(str);

console.log(meetup.date.getDate());
// Lỗi: meetup.date.getDate is not a function
```

Đúng vậy, giá trị `meetup.date` là một string `"2021-12-19T10:00:00.000Z"` chứ không phải đối tượng `Date`.

Để giải quyết vấn đề này, bạn có thể sử dụng hàm `reviver` để chuyển đổi giá trị của `date` thành object `Date` như sau:

```js
let str = '{"title":"Conference","date":"2021-12-19T10:00:00.000Z"}';

let meetup = JSON.parse(str, function (key, value) {
  // nếu key là "date" thì trả về new Date(value)
  if (key === "date") {
    return new Date(value);
  }

  // ngược lại thì giữ nguyên giá trị value gốc.
  return value;
});

console.log(meetup.date.getDate()); // 19
```

Cách này cũng áp dụng được với các đối tượng lồng nhau:

```js
let schedule = `{
      "meetups": [
        {"title":"Conference","date":"2021-12-19T10:00:00.000Z"},
        {"title":"Birthday","date":"2021-12-20T10:00:00.000Z"}
      ]
    }`;

schedule = JSON.parse(schedule, function (key, value) {
  if (key === "date") return new Date(value);
  return value;
});

console.log(schedule.meetups[1].date.getDate()); // 20
```

## Tổng kết

JSON trong JavaScript thực chất là một định dạng dữ liệu độc lập và có nhiều thư viện hỗ trợ xử lý JSON.

JSON trong JS hỗ trợ các kiểu dữ liệu như: object nguyên thủy, mảng, string, number, boolean và `null`.

JSON cung cấp hai phương thức:

- `JSON.stringify`: dùng dể chuyển giá trị thành JSON.
- `JSON.parse`: dùng để chuyển JSON thành giá trị tương ứng trong JavaScript.

Cả hai phương thức trên đều hỗ trợ truyền vào hàm để tùy biến quá trình chuyển đổi.

Nếu một object có phương thức `toJSON`, thì phương thức này sẽ được gọi bởi `JSON.stringify`.

## Thực hành

Chuyển đối tượng `user` thành JSON rồi đọc lại vào biến khác:

```js
let user = {
  name: "Alex",
  age: 28,
};
```

Xem đáp án

```js
let user = {
  name: "Alex",
  age: 28,
};

// chuyển user về JSON
let json = JSON.stringify(user);

// chuyển json về biến khác
let other = JSON.parse(json);
console.log(other); // {name: 'Alex', age: 28}
```

**Tham khảo**

- [Higher-Order Functions](https://eloquentjavascript.net/05_higher_order.html)
- [JavaScript and JSON differences](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/JSON#JavaScript_and_JSON_differences)
- [JSON methods, toJSON](https://javascript.info/json)
