---
title: "Thuộc tính và phương thức private của class trong Javascript"
description: "Tính bao đóng trong Java thể hiện bằng cách để phạm vi truy cập của các thuộc tính là private và truy xuất tới các thuộc tính này thông qua phương thức public."
keywords: [
"Thuộc tính và phương thức private của class trong Javascript",
"Thuộc tính và phương thức private của class trong Javascript là gì",
"Thuộc tính và phương thức private của class trong Javascript có ý nghĩa như thế nào",
"private trong javascript",
"private trong javascript la gi",
"thế nào là private trong javascript",
"Phương thức private trong JavaScript",
"Phương thức private trong JavaScript là gì",
"Cách sử dụng private trong javascript"
]
chapter:
  name: "ES6 Class"
  slug: "chuong-08-es6-class"
category:
  name: "Javascript"
  slug: "javascript"
image: https://kungfutech.edu.vn/thumbnail.png
position: 4
---

Một trong những tính chất quan trọng của lập trình hướng đối tượng là [tính đóng gói](<https://vi.wikipedia.org/wiki/%C4%90%C3%B3ng_g%C3%B3i_(l%E1%BA%ADp_tr%C3%ACnh_m%C3%A1y_t%C3%ADnh)>) - **Encapsulation**.

<content-info>

Hiểu đơn giản, **tính đóng gói** là khả năng **che giấu thông tin của đối tượng với môi trường bên ngoài**. Việc cho phép môi trường bên ngoài tác động lên các dữ liệu bên trong của đối tượng hoàn toàn tùy thuộc vào người lập trình.

</content-info>

Để làm được điều này, các ngôn ngữ lập trình như C++, Java,... hỗ trợ từ khóa `private` và `protected` giúp **hạn chế phạm vi sử dụng** của các thuộc tính và phương thức trong class.

Tuy nhiên, JavaScript lại không hỗ trợ các từ khóa này. Vậy thì làm sao để khai báo và sử dụng các **phương thức private (protected), thuộc tính private (protected)** trong JavaScript?

## Đặt bài toán

---

Trước khi đi vào chi tiết cách triển khai phương thức private (protected), thuộc tính private (protected) trong JavaScript, mình đặt ra bài toán minh họa về **bình nước** như sau:

```js
class WaterBottle {
  waterAmount = 0; // lượng nước trong bình

  constructor(volume) {
    this.volume = volume; // thế tích của bình
  }
}

// tạo mới bình nước
let waterBottle = new WaterBottle(100);

// gán giá trị nước
waterBottle.waterAmount = 10;
```

Trong đoạn code trên, mình định nghĩa class `WaterBottle` bao gồm:

- Thuộc tính `waterAmount` là lượng nước trong bình.
- Thuộc tính `volume` là thể tích của bình.

Với cách định nghĩa như trên, thuộc tính `waterAmount` và `volume` là hoàn toàn **public**. Nói cách khác, bạn có thể **dễ dàng get/set giá trị** cho chúng từ bên ngoài class `WaterBottle` mà không bị giới hạn gì.

```js
waterBottle.waterAmount = 20;
waterBottle.volume = 200;
```

Tuy nhiên, thực tế là luôn có giới hạn. Mình mong muốn giá trị của `volume` **không đổi** sau khi tạo đối tượng. Còn thuộc tính `waterAmount` luôn không âm và không vượt quá `volume`.

Vì vậy, mình muốn **các thuộc tính trên được bảo vệ** để có thể dễ dàng kiểm soát việc thay đổi chúng.

## Định nghĩa thuộc tính protected và phương thức protected

Như mình đã nói ở trên, JavaScript không hỗ trợ từ khóa **protected**. Tuy nhiên, có một cách mà nhiều lập trình viên ngầm định với nhau là sử dụng dấu gạch dưới `_` để biểu diễn phương thức protected và thuộc tính protected.

Với cách này, đoạn code trên có thể sửa thành như sau:

```js
class WaterBottle {
  _waterAmount = 0; // lượng nước trong bình

  get waterAmount() {
    return this._waterAmount;
  }

  set waterAmount(value) {
    if (value < 0) value = 0;
    if (value > this._volume) value = this._volume;
    this._waterAmount = value;
  }

  get volume() {
    return this._volume;
  }

  constructor(volume) {
    this._volume = volume; // thế tích của bình
  }
}

let waterBottle = new WaterBottle(100); // tạo mới bình nước

waterBottle.waterAmount = -10; // gán giá trị nước
console.log(waterBottle.waterAmount); // 0

waterBottle.waterAmount = 200; // gán giá trị nước
console.log(waterBottle.waterAmount); // 100

waterBottle.waterAmount = 50; // gán giá trị nước
console.log(waterBottle.waterAmount); // 50
```

Trong đoạn code trên, mình đã đổi tên các thuộc tính thành `_waterAmount` và `_volume`.

Giờ đây, việc get/set giá trị của `waterAmount` đều thông qua hàm get và set. Trong hàm `set waterAmount()`, mình có thêm **các điều kiện ràng buộc** để đảm bảo giá trị của `waterAmount` luôn không âm và không vượt quá `volume`.

Đối với `_volume`, vì mình mong muốn thuộc tính này không thay đổi sau khi khởi tạo đối tượng, nên mình chỉ triển khai hàm get `volume` chứ không viết hàm set.

**Chú ý:**

► Mình muốn nhấn mạnh lại rằng, việc get/set giá trị cho các thuộc tính `_waterAmount` và `_volume` là hoàn toàn có thể. Tuy nhiên, việc này là không khuyến khích vì có thể gây ra lỗi logic sau này.

```js
waterBottle._waterAmount = -10; // gán giá trị nước
waterBottle._volume = 0; // thay đổi thế tích
```

► Ngoài cách sử dụng hàm [getter và setter](/bai-viet/javascript/getter-va-setter-trong-javascript), bạn có thể viết hàm bình thường dạng `get...` và `set...` như sau:

```js
class WaterBottle {
  _waterAmount = 0; // lượng nước trong bình

  getWaterAmount() {
    return this._waterAmount;
  }
  setWaterAmount(value) {
    if (value < 0) value = 0;
    if (value > this._volume) value = this._volume;
    this._waterAmount = value;
  }
  getVolume() {
    return this._volume;
  }
  constructor(volume) {
    this._volume = volume; // thế tích của bình
  }
}

let waterBottle = new WaterBottle(100); // tạo mới bình nước
waterBottle.setWaterAmount(50);
console.log(waterBottle.getWaterAmount()); // 50
```

Cách viết này thường dài dòng hơn cách sử dụng getter/setter, tuy nhiên lại linh động hơn.

Vì cách sử dụng getter/setter, bạn chỉ truyền được một tham số. Còn khi viết hàm bình thường, bạn có thể truyền số lượng tham số tùy ý.

► Các thuộc tính, phương thức protected với `_` như trên không khác gì các thuộc tính, phương thức thông thường về mặt logic. Vì vậy, chúng có thể được truy cập từ các class kế thừa thông qua prototype hay [từ khóa `extend`](/bai-viet/javascript/ke-thua-class-trong-javascript).

## Định nghĩa thuộc tính private và phương thức private

Để định nghĩa thuộc tính private và phương thức private trong class JavaScript, bạn chỉ cần thêm kí tự `#` trước tên thuộc tính hay phương thức.

<content-info>

**Chú ý:** thuộc tính private hay phương thức private **chưa support hoàn toàn** trên các trình duyệt, bạn có thể tham khảo thêm tại đây: [CanIUse - JavaScript classes: Private class fields](https://caniuse.com/mdn-javascript_classes_private_class_fields)

</content-info>

Áp dụng cách này vào đoạn code trên ta có kết quả như sau:

```js
class WaterBottle {
  #waterAmount = 0; // lượng nước trong bình
  #volume = 0; // thế tích của bình

  get waterAmount() {
    return this.#waterAmount;
  }

  set waterAmount(value) {
    if (value < 0) value = 0;
    if (value > this.#volume) value = this.#volume;
    this.#waterAmount = value;
  }

  get volume() {
    return this.#volume;
  }

  constructor(volume) {
    this.#volume = volume;
  }
}

let waterBottle = new WaterBottle(100); // tạo mới bình nước
console.log(waterBottle.#volume);
// Lỗi: Private field '#volume' must be declared in an enclosing class
```

Trong đoạn code trên, mình đã thay đổi `_waterAmount` và `_volume` thành `#waterAmount` và `#volume`. Lúc này, các thuộc tính đã **hoàn toàn private**. Nếu bạn cố tình truy cập các thuộc tính này từ bên ngoài class thì sẽ gặp lỗi dạng như trên:

<content-result>

Private field '#volume' must be declared in an enclosing class

</content-result>

Đặc biệt, với thuộc tính private và phương thức private, bạn không thể truy cập được chúng từ class kế thừa, ví dụ:

```js
class ExtendedWaterBottle extends WaterBottle {
  constructor(volume) {
    super(volume);
  }

  debug() {
    console.log(this.#volume);
  }
}

let waterBottle = new ExtendedWaterBottle(100); // tạo mới bình nước
console.log(waterBottle.#volume);
// Lỗi: Private field '#volume' must be declared in an enclosing class
```

**Chú ý:** thuộc tính private và phương thức private không thể truy cập thông qua cách sử dụng `this[name]`, ví dụ:

```js
class WaterBottle {
  #volume = 0; // lượng nước trong bình

  debug() {
    const fieldName = "#volume";
    console.log("this[fieldName]", this[fieldName]);
    console.log("this.#volume", this.#volume);
  }

  constructor(volume) {
    this.#volume = volume;
  }
}

let waterBottle = new WaterBottle(100);
waterBottle.debug();
// this[fieldName] undefined
// this.#volume 100
```

## Tổng kết

---

Tính đóng gói là một trong bốn tính chất quan trọng của lập trình hướng đối tượng. Việc sử dụng tính đóng gói giúp tách biệt phần triển khai code với phần sử dụng bên ngoài.

Điều này đặc biệt hữu ích khi bạn xây dựng các module và thư viện. Khi mà người sử dụng code không cần biết đến phần triển khai bên trong, giúp việc sử dụng code trở nên đơn giản hơn.

Để áp dụng tính chất đóng gói vào class trong JavaScript, bạn có thể sử dụng một trong hai cách sau:

- **Thuộc tính protected và phương thức protected**: sử dụng kí tự `_` trước tên thuộc tính hay phương thức (quy định ngầm).
- **Thuộc tính private và phương thức private**: sử dụng kí tự `#` trước tên thuộc tính hay phương thức (trình duyệt hỗ trợ).

Tham khảo: [Private and protected properties and methods](https://javascript.info/private-protected-properties-methods)
