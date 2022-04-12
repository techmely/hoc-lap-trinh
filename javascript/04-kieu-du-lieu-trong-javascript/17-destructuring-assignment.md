---
title: "Destructuring assignment trong Javascript"
description: ""
keywords: []
chapter:
  name: "Kiểu dữ liệu trong Javascript"
  slug: "chuong-04-kieu-du-lieu-trong-javascript"
category:
  name: "Javascript"
  slug: "javascript"
image: https://kungfutech.edu.vn/thumbnail.png
position: 17
---

**Destructuring Assignment trong JavaScript** là một cú pháp đặc biệt cho phép bạn **lấy ra dữ liệu** từ [Object](/object-la-gi-object-trong-javascript/) hoặc [Array](/array-la-gi-array-trong-javascript/) và gán chúng vào các biến thông thường.

Tuy nhiên, việc "lấy ra dữ liệu" này **chỉ copy mà không làm thay đổi cấu trúc** của Object hoặc Array.

Dưới đây, mình sẽ tìm hiểu về cách sử dụng và ứng dụng của Destructuring Assignment trong JavaScript với **Array và Object**.

[](#destructuring-assignment-v%E1%BB%9Bi-array)Destructuring Assignment với Array
---------------------------------------------------------------------------------

Sau đây là những kiến thức cơ bản và ứng dụng của Destructuring Assignment trong JavaScript với Array.

### [](#c%C3%A1ch-s%E1%BB%AD-d%E1%BB%A5ng-c%C6%A1-b%E1%BA%A3n)Cách sử dụng cơ bản

Ví dụ về destructuring assignment với array:

    let [firstName, lastName] = ["David", "Walsh"];
    /*
     * firstName = David
     * lastName = Walsh
     */

Ví dụ trên thực hiện **khai báo và gán** luôn giá trị cho các biến `firstName` và `lastName`. Ngoài ra, bạn có thể tách biệt việc khai báo và gán giá trị như sau:

    let firstName, lastName;
    
    [firstName, lastName] = ["David", "Walsh"];
    /*
     * firstName = David
     * lastName = Walsh
     */

Ở đây, JavaScript thực hiện việc gán giá trị ở **vế phải** cho biến ở **vế trái** theo đúng thứ tự chỉ số xuất hiện trong mảng.

![Array destructuring assignment](/static/e43a47337056a699a8405931069e2cd0/cd94f/array-destructuring-assignment-completejavascript.com_.png "Array destructuring assignment")

Đoạn code trên sẽ tương đương với:

    let arr = ["David", "Walsh"];
    let firstName, lastName;
    
    firstName = arr[0];
    lastName = arr[1];

> **Chú ý**: trong trường hợp **số lượng phần tử vế trái nhiều hơn vế phải** thì thành phần thừa ra có giá trị là **undefined**.

    let [firstName, lastName] = ["David"];
    /*
     * firstName = David
     * lastName = undefined - vế phải có 1 phần tử nên lastName là undefined
     */

Để tránh trường hợp này, bạn có thể khai báo giá trị **default** cho biến như dưới đây.

### [](#khai-b%C3%A1o-gi%C3%A1-tr%E1%BB%8B-default)Khai báo giá trị default

Để khai báo giá trị default (mặc định), bạn sử dụng toán tử gán `=` như sau:

    let [firstName, lastName = "Anonymous"] = ["David"];
    /*
     * firstName = David
     * lastName = Anonymous
     */

Vế phải có một phần tử nên `lastName` nhận giá trị mặc định bằng `Anonymous`.

### [](#b%E1%BB%8F-qua-m%E1%BB%99t-s%E1%BB%91-ph%E1%BA%A7n-t%E1%BB%AD-trong-m%E1%BA%A3ng)Bỏ qua một số phần tử trong mảng

Trong mảng có thể chứa nhiều phần tử và bạn chỉ muốn lấy ra **một vài giá trị trong đó** thì có thể sử dụng toán tử dấu phẩy `,` như sau:

    let [title, , , color] = ["window", 300, 400, "#000"];
    /*
     * title = "window"
     * color = "#000"
     */

Lúc này, phần tử ứng chỉ số `1` (bằng `300`) và `2` (bằng `400`) bị bỏ qua.

### [](#g%C3%A1n-c%C3%A1c-gi%C3%A1-tr%E1%BB%8B-c%C3%B2n-l%E1%BA%A1i-c%E1%BB%A7a-m%E1%BA%A3ng-cho-m%E1%BB%99t-bi%E1%BA%BFn-kh%C3%A1c)Gán các giá trị còn lại của mảng cho một biến khác

Khác với trường hợp trên, ở đây mình lấy ra một phần tử và các phần tử còn lại được gán vào một biến khác, bằng cách sử dụng cú pháp **spread** `...`:

    let [title, ...others] = ["window", 300, 400, "#000"];
    /*
     * title = "window"
     * others = [300, 400, "#000"]
     */

Khi đó, biến `others` có giá trị là một mảng các phần tử còn lại.

### [](#ho%C3%A1n-%C4%91%E1%BB%95i-gi%C3%A1-tr%E1%BB%8B-c%E1%BB%A7a-bi%E1%BA%BFn)Hoán đổi giá trị của biến

Trước khi có destructuring assignment trong JavaScript, bạn có thể **hoán đổi giá trị của hai biến** bằng một số cách sau đây.

► **Sử dụng biến trung gian**

    // khai báo hai biến a, b
    let a = 1;
    let b = 2;
    
    // sử dụng biến trung gian c, gán bằng a
    let c = a;
    
    // hoán đổi giá trị của a, b thông qua c
    a = b;
    b = c;
    /*
     * a = 2
     * b = 1
     */

► **Sử dụng tính toán số học**

    // khai báo hai biến a, b
    let a = 1;
    let b = 2;
    
    // cộng dồn b vào a
    // khi đó giá trị mới của a là tổng của a + b
    a = a + b;
    
    // thực hiện phép trừ để được kết quả
    b = a - b;
    a = a - b;
    /*
     * a = 2
     * b = 1
     */

Khi **áp dụng destructuring assignment** trong JavaScript, việc hoán đổi giá trị hai biến trở nên vô cùng đơn giản:

    let a = 1;
    let b = 2;
    
    [a, b] = [b, a];
    /*
     * a = 2
     * b = 1
     */

Ở đây, mình tạo ra một mảng tạm `[b, a]` ở vế phải. Sau đó, mình sử dụng destructuring assignment để đảo lại giá trị hai biến.

> **Chú ý:** cách hoán đổi trên có thể áp dụng được với nhiều biến (lớn hơn 2).

### [](#sao-ch%C3%A9p-m%E1%BA%A3ng)Sao chép mảng

Mảng trong JavaScript là **kiểu dữ liệu tham chiếu**, nên việc sử dụng toán tử gán `=` thực chất là **copy địa chỉ**, ví dụ:

    const a = [1, 2];
    const b = a;
    
    console.log(b); // [1, 2]
    console.log(b === a); // true

Nếu bạn muốn `b` vẫn có giá trị giống `a` nhưng `b === a` là `false` thì có thể sử dụng destructuring assignment trong JavaScript với cú pháp spread `...` như sau:

    const a = [1, 2];
    const [...b] = a;
    
    console.log(b); // [1, 2]
    console.log(b === a); // false

[](#destructuring-assignment-v%E1%BB%9Bi-object)Destructuring Assignment với Object
-----------------------------------------------------------------------------------

Sau đây là những kiến thức cơ bản và ứng dụng của Destructuring Assignment trong JavaScript với Object.

### [](#c%C3%A1ch-s%E1%BB%AD-d%E1%BB%A5ng-c%C6%A1-b%E1%BA%A3n-1)Cách sử dụng cơ bản

Ví dụ destructuring assignment với object:

    let { firstName, lastName } = { firstName: "David", lastName: "Walsh" };
    /*
     * firstName = David
     * lastName = Walsh
     */

Ví dụ trên thực hiện **khai báo và gán** luôn giá trị cho các biến `firstName` và `lastName`. Ngoài ra, bạn có thể **tách biệt** việc khai báo và gán như sau:

    let firstName, lastName;
    ({ firstName, lastName } = { firstName: "David", lastName: "Walsh" });
    /*
     * firstName = David
     * lastName = Walsh
     */

Ở đây, JavaScript thực hiện việc gán giá trị ở **vế phải** cho biến ở **vế trái** tương ứng với giá trị của **key** trong Object mà không phân biệt thứ tự.

![Object destructuring assignment](/static/d1143250ce531dc7d974b7867efd32d1/11b02/object-destructuring-assignment-completejavascript.com_.png "Object destructuring assignment")

Giả sử, mình đổi thứ tự của `firstName` và `lastName` như sau thì kết quả vẫn không đổi:

    let firstName, lastName;
    ({ lastName, firstName } = { firstName: "David", lastName: "Walsh" });
    /*
     * firstName = David
     * lastName = Walsh
     */

Không biết bạn có thắc mắc **tại sao đoạn code thực hiện Destructuring Assignment bên trên phải đặt trong cặp dấu ngoặc đơn** hay không.

Vì nếu thiếu cặp dấu `()` thì sẽ bị lỗi cú pháp.

    let firstName, lastName;
    { lastName, firstName } = { firstName: "David", lastName: "Walsh" };
    // Lỗi: Uncaught SyntaxError: Unexpected token =

JavaScript hiểu rằng **cặp dấu ngoặc** đầu tiên là một **block code** (khối code), chứ không phải destructuring assignment.

> Ví dụ về khối code như sau:
> 
>     let firstName = "David";
>     let lastName = "Walsh";
>     
>     // bắt đầu một block code
>     {
>       // biến bên trong trùng tên với bên ngoài nhưng có giá trị khác.
>       // vì chúng ở các phạm vi khác nhau.
>       let firstName, lastName;
>       console.log(firstName, lastName); // undefined undefined
>     }

Ngoài ra, đoạn code phía trên tương đương với cách làm thông thường như sau:

    let obj = { firstName: "David", lastName: "Walsh" };
    
    let firstName = obj.firstName;
    let lastName = obj.lastName;

> **Chú ý**: trong trường hợp object **thiếu thuộc tính** mà bạn muốn lấy ra giá trị thì giá trị đó là **undefined**.

    let { firstName, lastName } = { firstName: "David" };
    /*
     * firstName = David
     * lastName = undefined - về phải không có thuộc tính lastName
     */

Để giải quyết vấn đề này, bạn có thể khai báo giá trị **default** (mặc định) như dưới đây.

### [](#khai-b%C3%A1o-gi%C3%A1-tr%E1%BB%8B-default-1)Khai báo giá trị default

Để khai báo giá trị default (mặc định), bạn có thể sử dụng toán tử gán `=`, ví dụ:

    let { firstName, lastName = "Anonymous" } = { firstName: "David" };
    /*
     * firstName = David
     * lastName = Anonymous - lastName bằng Anonymous vì vế phải không có lastName
     */

### [](#g%C3%A1n-t%C3%AAn-m%E1%BB%9Bi-cho-bi%E1%BA%BFn)Gán tên mới cho biến

Nhiều khi thuộc tính mà bạn muốn thực hiện destructuring assignment ở object **quá dài hoặc tên trùng với một biến khác**.

Để ngắn gọn, bạn có thể **đặt tên mới cho biến** khi thực hiện destructuring như sau:

    let { firstName: fn, lastName: ln } = { firstName: "David", lastName: "Walsh" };
    /*
     * fn = David
     * ln = Walsh
     */

Ý nghĩa đoạn code trên là:

*   Lấy giá trị của `firstName` rồi gán giá trị đó vào biến `fn`.
*   Lấy giá trị của `lastName` rồi gán giá trị đó vào biến `ln`.

Để gán giá trị **mặc định** cho biến trong trường hợp này, bạn có thể thực hiện theo cách:

    let { firstName: fn, lastName: ln = "Anonymous" } = { firstName: "David" };
    /*
     * fn = David
     * ln = Anonymous
     */

### [](#g%C3%A1n-c%C3%A1c-gi%C3%A1-tr%E1%BB%8B-c%C3%B2n-l%E1%BA%A1i-c%E1%BB%A7a-object-cho-m%E1%BB%99t-bi%E1%BA%BFn-kh%C3%A1c)Gán các giá trị còn lại của Object cho một biến khác

Tương tự như mảng, bạn có thể sử dụng **cú pháp spread** `...` để gán các thuộc tính còn lại cho object khi thực hiện destructuring.

    let { a, b, ...rest } = { a: 10, b: 20, c: 30, d: 40 };
    /*
     * a = 10
     * b = 20
     * rest = { c: 30, d: 40 }
     */

Trong ví dụ trên, bạn lấy ra hai thuộc tính `a` và `b`. Các thuộc tính còn lại được sao chép vào đối tượng `rest`.

### [](#destructuring-v%E1%BB%9Bi-object-v%C3%A0-array-l%E1%BB%93ng-nhau)Destructuring với Object và Array lồng nhau

Bạn cũng có thể sử dụng destructuring assignment trong JavaScript với **object và array lồng nhau nhiều tầng**, ví dụ:

    let options = {
      size: {
        width: 100,
        height: 200,
      },
      items: ["Cake", "Donut"],
      extra: true, // trường này không destruct
    };
    
    // cấu trúc để destruct phải giống với cấu trúc của Object
    let {
      size: { width, height },
      items: [item1, item2],
      title = "Menu", // gán giá trị bởi default
    } = options;
    
    /*
     * Kết quả các biến thu được sau khi destructuring:
     * title = "Menu" - giá trị mặc định, vì vế phải không có thuộc tính title
     * width = 100
     * height = 200
     * item1 = "Cake"
     * item2 = "Donut"
     */

### [](#c%C3%A0i-%C4%91%E1%BA%B7t-gi%C3%A1-tr%E1%BB%8B-default-cho-c%C3%A1c-tham-s%E1%BB%91-c%E1%BB%A7a-h%C3%A0m)Cài đặt giá trị default cho các tham số của hàm

Bạn có thể áp dụng destructuring assignment trong JavaScript để **cài đặt giá trị mặc định cho các tham số** khi truyền vào hàm.

Sau đây, mình so sánh cách làm thông thường và cách dùng destructuring assignment để thấy sự khác biệt.

#### [](#c%C3%A1ch-l%C3%A0m-th%C3%B4ng-th%C6%B0%E1%BB%9Dng)Cách làm thông thường

Sau đây là cách bình thường để cài đặt **giá trị mặc định** cho các tham số của hàm:

    function drawCicle(x = 0, y = 0, radius = 1, color = "black") {
      // code xử lý
    }
    
    // Sử dụng
    drawCicle(); // hợp lệ
    drawCicle(1, 2, 3); // hợp lệ
    drawCicle(1, 2, 3, "red"); // hợp lệ
    drawCicle("red"); // không hợp lệ
    drawCicle("red", 1, 2, 3); // không hợp lệ

Cách trên có **một số nhược điểm** là:

*   Bạn phải **ghi nhớ vị trí** của các tham số.
*   Nếu muốn cài đặt giá trị mặc định cho tham số, bạn **chỉ có thể** áp dụng với các tham số bên phải, ngoài cùng.
*   Không có cách nào để áp dụng giá trị default cho các tham số ở giữa.

Giả sử, bạn muốn áp dụng giá trị default cho `y` và `radius` bằng cách gọi hàm:

    drawCicle(1, "red");

Cách gọi hàm trên **không sai về cú pháp** nhưng sai về mặt ý nghĩa. Vì JavaScript sẽ hiểu `x = 1`, `y = "red"`, `radius = 1` và `color = "black"`.

Để tránh việc **phải ghi nhớ thứ tự các tham số**, bạn có thể gộp chúng vào một object. Sau đó, bạn chỉ cần truyền 1 tham số vào [function](/ham-la-gi-ham-trong-javascript/) như dưới đây.

#### [](#g%E1%BB%99p-c%C3%A1c-tham-s%E1%BB%91-v%C3%A0o-th%C3%A0nh-m%E1%BB%99t-object)Gộp các tham số vào thành một Object

Tương tự như ví dụ trên, nhưng giờ chỉ còn một tham số là object:

    function drawCicle(options) {
      let x = options.x || 0;
      let y = options.y || 0;
      let radius = options.radius || 1;
      let color = options.color || "black";
      // code xử lý
    }
    
    // Sử dụng:
    drawCicle({}); // hợp lệ
    drawCicle({ x: 1, y: 2, radius: 3 }); // hợp lệ
    drawCicle({ x: 1, y: 2, radius: 3, color: "red" }); // hợp lệ
    drawCicle({ color: "red", y: 2, x: 1, radius: 3 }); // hợp lệ

Khi các tham số được gộp vào thành một object `options` thì bạn viết chúng theo thứ nào cũng không quan trọng (vì object không phân biệt thứ tự các thuộc tính).

Tuy nhiên, cách cài đặt giá trị default như trên (dùng toán tử OR `||` ) vẫn còn khá dài dòng và phức tạp.

Sau đây, mình thử áp dụng destructuring assigment trong JavaScript để thấy sự khác biệt.

#### [](#g%E1%BB%99p-c%C3%A1c-tham-s%E1%BB%91-th%C3%A0nh-object-k%E1%BA%BFt-h%E1%BB%A3p-destructuring-assignment)Gộp các tham số thành object kết hợp destructuring assignment

Ví dụ trên có thể thay đổi như sau:

    function drawCicle({ x = 0, y = 0, radius = 1, color = "black" }) {
      // code xử lý
    }
    
    // Sử dụng
    drawCicle({}); // hợp lệ
    drawCicle({ x: 1, y: 2, radius: 3 }); // hợp lệ
    drawCicle({ x: 1, y: 2, radius: 3, color: "red" }); // hợp lệ
    drawCicle({ color: "red", y: 2, x: 1, radius: 3 }); // hợp lệ

Bây giờ, mình đã **khắc phục được hai nhược điểm** đề cập bên trên. Tuy nhiên, cách làm này vẫn chưa thật hoàn thiện.

**Vì sao?**

Giả sử, bạn muốn sử dụng giá trị default cho **tất cả các thuộc tính** bên trong object. Bạn vẫn phải truyền vào một object rỗng (`{}`).

Để khắc phục vấn đề này, bạn có thể sửa lại đoạn code trên một chút:

    function drawCicle({ x = 0, y = 0, radius = 1, color = "black" } = {}) {
      // code xử lý
    }
    
    drawCicle({}); // hợp lệ
    drawCircle(); // vẫn hợp lệ

Khi bạn **không truyền bất kỳ tham số nào** vào hàm trên, `options` sẽ lấy giá trị mặc định là object rỗng `{}`.

[](#t%E1%BB%95ng-k%E1%BA%BFt)Tổng kết
-------------------------------------

Destructuring assignment trong JavaScript cho phép bạn "mapping" object hoặc array vào các biến một cách đơn giản.

► Cú pháp destructuring assignment với array:

    let [item1 = default, item2, ...rest] = array

Trong đó, phần tử đầu tiên được gán vào biến `item1`, phần tử thứ hai được gán vào biến `item2` và các phần tử còn lại được gán vào biến `rest` (mảng).

► Cú pháp destructuring assignment với object:

    let {prop : varName = default, ...rest} = object

Trong đó, giá trị thuộc tính `prop` được gán vào biến `varName`. Nếu thuộc tính `prop` không tồn tại trong `object` thì biến `varName` có giá trị mặc định là `default`. Và các thuộc tính còn lại được copy vào đối tượng `rest`.

Ngoài ra, bạn có thể áp dụng destructuring assignment trong JavaScript với object và mảng lồng nhau. Khi đó, cấu trúc ở vế trái phải tương đồng với cấu trúc vế phải.

[](#th%E1%BB%B1c-h%C3%A0nh)Thực hành
------------------------------------

### [](#b%C3%A0i-1)Bài 1

Cho object:

    let user = {
      name: "Alex",
      years: 28,
    };

Sử dụng destructuring assignment trong JavaScript thực hiện các yêu cầu sau:

*   Đọc giá trị thuộc tính `name` và gán vào biến `name`.
*   Đọc giá trị thuộc tính `years` và gán vào biến `age`.
*   Đọc giá trị thuộc tính `isAdmin` và gán vào biến `isAdmin` (nếu thuộc tính không tồn tại thì giá trị mặc định là `false`).

 Xem đáp án

    let user = {
      name: "Alex",
      years: 28,
    };
    
    let { name, years: age, isAdmin = false } = user;
    
    console.log(name, age, isAdmin); // Alex 28 false

### [](#b%C3%A0i-2)Bài 2

Cho đối tượng sau:

    let people = {
      Ana: 25,
      Alex: 28,
      John: 27,
    };

Viết hàm `topAge(people)` trả về tên của người nhiều tuổi nhất.

*   Nếu `people` là rỗng thì hàm trên trả về `null`.
*   Nếu có nhiều người có cùng tuổi nhiều nhất thì trả về một người bất kỳ.

 Xem đáp án

    function topAge(people) {
      // nếu people không tồn tại thì trả về null
      if (!people) {
        return null;
      }
    
      // khai báo biến để lưu thông tin lớn nhất
      let nameOfLargest = "";
      let ageOfLargest = -Infinity;
    
      // sử dụng destructuring assignment với mỗi phần tử
      // khi sử dụng for...of với Object.entries(people)
      // chú ý: Object.entries(people) trả về iterable object
      // với mỗi phần tử có dạng [key, value]
      for (let [name, age] of Object.entries(people)) {
        // nếu phần tử đang xét có age lớn hơn ageOfLargest thì cập nhật
        if (age > ageOfLargest) {
          ageOfLargest = age;
          nameOfLargest = name;
        }
      }
    
      // trả về tên của người lớn tuổi nhất
      return nameOfLargest;
    }
    
    let people = {
      Ana: 25,
      Alex: 28,
      John: 27,
    };
    
    let ret = topAge(people);
    console.log(ret); // Alex

**Tham khảo:**

*   [Destructuring assignment - MDN](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Operators/Destructuring_assignment)
*   [Destructuring assignment - JavaScript.info](https://javascript.info/destructuring-assignment)
*   [Destructuring and Function Arguments - DavidWalsh](https://davidwalsh.name/destructuring-function-arguments)
*   [Aliases with JavaScript Destructuring - DavidWalsh](https://davidwalsh.name/destructuring-alias)
*   [Array Destructuring - DavidWalsh](https://davidwalsh.name/array-destructuring)