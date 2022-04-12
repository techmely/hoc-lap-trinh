---
title: "Đối tượng Date trong Javascript"
description: ""
keywords: []
chapter:
  name: "Kiểu dữ liệu trong Javascript"
  slug: "chuong-04-kieu-du-lieu-trong-javascript"
category:
  name: "Javascript"
  slug: "javascript"
image: https://kungfutech.edu.vn/thumbnail.png
position: 18
---

Date trong JavaScript là một [đối tượng sẵn có](/object-la-gi-object-trong-javascript/) giúp bạn lưu trữ **date (ngày, tháng, năm)**, **time (giờ, phút, giây)** và quản lý date/time.

Ví dụ, bạn có thể sử dụng `Date` để lưu thời gian tạo và chỉnh sửa dữ liệu, đo lường thời gian hay hiển thị thời gian hiện tại.

[](#kh%E1%BB%9Fi-t%E1%BA%A1o-date-trong-javascript)Khởi tạo Date trong JavaScript
---------------------------------------------------------------------------------

Để khởi tạo một đối tượng `Date` trong JavaScript, bạn chỉ cần gọi hàm khởi tạo `new Date()` với một trong các tham số sau đây.

► `new Date()`

Hàm khởi tạo **không tham số** tạo mới một đối tượng `Date` với thời gian hiện tại, ví dụ:

    let currentDate = new Date();
    console.log(currentDate);
    
    // hiển thị thời gian hiện tại, ví dụ:
    // Sun Dec 19 2021 09:25:51 GMT+0700 (Indochina Time)

► `new Date(milliseconds)`

Tạo mới đối tượng `Date` với thời gian tương ứng với `milliseconds` (mili giây) sau ngày 01/01/1970 UTC+0.

    // 0 tương ứng với ngày 01/01/1970 UTC+0
    let jan01_1970 = new Date(0);
    console.log(jan01_1970); // Thu Jan 01 1970 07:00:00 GMT+0700 (Indochina Time)
    
    // cộng thêm 24 giờ => ngày 02/01/1970 UTC+0
    let jan02_1970 = new Date(24 * 3600 * 1000);
    console.log(jan02_1970); // Fri Jan 02 1970 07:00:00 GMT+0700 (Indochina Time)

**Số nguyên** ứng với tham số `milliseconds` biểu diễn số **mili giây** sau ngày 01/01/1970 UTC+0 được gọi là **timestamp**.

> **Chú ý**: kết quả của câu lệnh `console.log(jan01_1970)` trên là ứng với múi giờ `+0700` tại Việt Nam.
> 
> Vì vậy, thời gian hiển thị là `07:00:00` (7 giờ 00 phút 00 giây), thay vì `00:00:00` (0 giờ 00 phút 00 giây) tại múi giờ `+0000`.

Bạn có thể tạo mới đối tượng `Date` từ timestamp (như trên). Ngược lại, bạn cũng có thể [chuyển đổi kiểu dữ liệu](/chuyen-doi-kieu-du-lieu-trong-javascript/) từ đối tượng `Date` ra timestamp bằng phương thức `date.getTime()` (được trình bày bên dưới).

Thời gian trước ngày 01/01/1970 có **timestamp âm**, ví dụ ngày 31/12/1969:

    // ngày 31/12/1969 trước ngày 01/01/1970 là 1 ngày
    let dec31_1969 = new Date(0 - 24 * 3600 * 1000);
    console.log(dec31_1969); // Wed Dec 31 1969 07:00:00 GMT+0700 (Indochina Time)

► `new Date(string)`

Nếu hàm khởi tạo Date trong JavaScript có một tham số và đó là string thì string sẽ được chuyển đổi tự động sang `Date`.

Thuật toán chuyển đổi **string** sang đối tượng `Date` tương tự như cách sử dụng của phương thức `Date.parse()` (được trình bày bên dưới).

    let date = new Date("2021-12-19");
    console.log(date); // Sun Dec 19 2021 07:00:00 GMT+0700 (Indochina Time)
    
    // Thời gian không được cài đặt, nên mặc định đó là 00:00:00 tại GMT+0000,
    // hoặc 07:00:00 tại GMT+0700.

► `new Date(year, month, date, hours, minutes, seconds, ms)`

Đây là hàm khởi tạo **đầy đủ các thông tin** của Date trong JavaScript với múi giờ local. Trong đó, hai tham số đầu tiên `year` và `month` là bắt buộc.

*   `year` (năm) phải có 4 chữ số: `2021` là hợp lệ, `21` là không hợp lệ.
*   `month` (tháng) đếm từ `0` (tháng 1) đến `11` (tháng 12).
*   `date` là ngày trong tháng, nếu không truyền gì vào thì mặc định giá trị của tham số `date` là `1`.
*   `hours` (giờ), `minutes` (phút), `seconds` (giây) và `ms` (mili giây) nếu không truyền vào thì mặc định là `0`.

Ví dụ hai câu lệnh sau khởi tạo đối tượng Date giống nhau:

    new Date(2021, 0, 1, 0, 0, 0, 0); // 1 Jan 2021, 00:00:00
    new Date(2021, 0, 1); // giống câu lệnh trên

Độ chính xác tối đa là **1 mili giây**:

    let date = new Date(2021, 0, 1, 2, 3, 4, 567);
    // 01/01/2021, 02:03:04.567

[](#truy-c%E1%BA%ADp-c%C3%A1c-ph%E1%BA%A7n-t%E1%BB%AD-c%E1%BB%A7a-date)Truy cập các phần tử của Date
----------------------------------------------------------------------------------------------------

Sau đây là những phương thức phổ biến để truy cập vào các phần tử của Date trong JavaScript:

*   Phương thức [`getFullYear()`](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Date/getFullYear): trả về năm (gồm 4 chữ số).
*   Phương thức [`getMonth()`](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Date/getFullYear): trả về tháng (từ 0 đến 11).
*   Phương thức [`getDate()`](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Date/getFullYear): trả về ngày trong tháng (từ 1 đến 31).
*   Phương thức [`getHours()`](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Date/getHours): trả về giờ.
*   Phương thức [`getMinutes()`](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Date/getHours): trả về phút.
*   Phương thức [`getSeconds()`](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Date/getSeconds): trả về giây.
*   Phương thức [`getMilliseconds()`](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Date/getMilliseconds): trả về mili giây.

> **Chú ý:** phương thức `getYear()` đã **lỗi thời** và chỉ trả về **hai chữ số** của năm. Vì vậy, bạn không nên sử dụng phương thức `getYear()`.

Ngoài ra, bạn có thể lấy **ngày trong tuần** bằng phương thức [`getDay()`](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Date/getDay) - trả về giá trị từ `0` (thứ 2) đến `6` (chủ nhật).

Tất cả phương thức trên đều trả về giá trị tương đối ứng với múi giờ trên máy tính. Múi giờ của Việt Nam là `+0700`.

Để lấy giá trị ngày, tháng, năm,... tại múi giờ **UTC+0**, bạn chỉ cần viết thêm `UTC` vào các phương thức trên, phía sau `get`, ví dụ: `getUTCFullYear()`, `getUTCMonth()`, `getUTCDate()`,...

    let date = new Date();
    console.log(date.getHours()); // 10
    console.log(date.getUTCHours()); // 3

Ngoài các phương thức trên, còn hai phương thức khác không có `UTC` là:

*   [`getTime()`](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Date/getTime): trả về timestamp của date.
*   [`getTimezoneOffset()`](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Date/getTimezoneOffset): trả về sự sai khác về múi giờ giữa UTC+0 với múi giờ trên máy tính (tính theo phút).

    let date = new Date();
    console.log(date.getTime()); // 1639883864463
    console.log(date.getTimezoneOffset()); // -420 (ứng với -7 giờ)

[](#thay-%C4%91%E1%BB%95i-c%C3%A1c-ph%E1%BA%A7n-t%E1%BB%AD-c%E1%BB%A7a-date)Thay đổi các phần tử của Date
---------------------------------------------------------------------------------------------------------

Để thay đổi giá trị các phần tử của Date trong JavaScript, bạn sử dụng một trong các phương thức sau đây:

*   Phương thức [`setFullYear(year, [month], [date])`](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Date/setFullYear)
*   Phương thức [`setMonth(month, [date])`](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Date/setMonth)
*   Phương thức [`setDate(date)`](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Date/setDate)
*   Phương thức [`setHours(hour, [min], [sec], [ms]`)](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Date/setHours)
*   Phương thức [`setMinutes(min, [sec], [ms])`](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Date/setMinutes)
*   Phương thức [`setSeconds(sec, [ms])`](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Date/setSeconds)
*   Phương thức [`setMilliseconds(ms)`](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Date/setSeconds)
*   Phương thức [`setTime(milliseconds)`](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Date/setTime)

Tất cả các phương thức trên - ngoại trừ `setTime()`, đều có dạng `UTC`, ví dụ: `setUTCHours()`.

Và một số phương thức bên trên có nhiều tham số. Trong đó, tham số đầu tiên là bắt buộc, các tham số sau nếu không set thì bỏ qua, ví dụ `setHours(hour, [min], [sec], [ms])`.

    let today = new Date();
    console.log(today); // thời gian hiện tại
    
    today.setHours(0);
    console.log(today); // ngày hiện tại, nhưng giờ được set thành 0
    
    today.setHours(0, 0, 0, 0);
    console.log(today); // ngày hiện tại, nhưng giờ, phút, giây, mili giây đều = 0

[](#t%E1%BB%B1-%C4%91%E1%BB%99ng-%C4%91i%E1%BB%81u-ch%E1%BB%89nh-date)Tự động điều chỉnh date
---------------------------------------------------------------------------------------------

Đối tượng Date trong JavaScript có một tính năng khá hữu ích đó là: **tự động điều chỉnh thời gian**, ví dụ:

    let date = new Date(2021, 0, 32); // 32/01/2021 - ngày không hợp lệ
    console.log(date); // tự động điều chỉnh thành 01/02/2021!

Tham số truyền vào vượt ngoài giá trị cho phép của ngày, tháng, năm,... được tự động điều chỉnh **tăng hoặc giảm**.

Giả sử, bạn muốn tăng từ ngày 28/02/2021 lên **2 ngày**. Bạn không chắc đó là ngày 01/03/2021 hay 02/03/2021. Vì bạn không rõ năm 2021 có phải là **năm nhuận hay không**.

Với đối tượng Date trong JavaScript, bạn chỉ cần cộng thêm 2 ngày. [JavaScript engine](/javascript-la-gi/#javascript-engine-l%C3%A0-g%C3%AC) sẽ xử lý cho bạn.

    let date = new Date(2021, 1, 28);
    date.setDate(date.getDate() + 2);
    
    console.log(date); // Tue Mar 02 2021 00:00:00 GMT+0700 (Indochina Time)

Tính năng này còn được áp dụng để lấy Date sau một khoảng thời gian. Ví dụ lấy thông tin Date sau khoảng thời gian **80 giây** tính từ hiện tại:

    let date = new Date();
    console.log(date); // Sun Dec 19 2021 10:50:50 GMT+0700 (Indochina Time)
    
    date.setSeconds(date.getSeconds() + 80);
    console.log(date); // Sun Dec 19 2021 10:52:10 GMT+0700 (Indochina Time)

Ngoài ra, bạn có thể truyền tham số là `0` hoặc **số âm**. Khi đó, thời gian được lấy lùi lại quá khứ:

    let date = new Date(2021, 0, 2); // 02/01/2021
    
    date.setDate(1); // set ngày của tháng thành mùng 1
    console.log(date); // 01/01/2021
    
    date.setDate(0); // set ngày của tháng bằng 0 => ngày cuối cùng của tháng trước
    console.log(date); // 31/12/2020

[](#chuy%E1%BB%83n-date-v%E1%BB%81-number)Chuyển Date về number
---------------------------------------------------------------

Khi đối tượng Date trong JavaScript được chuyển đổi về dạng số, `Date` sẽ trở thành **timestamp**, giống như cách sử dụng `date.getTime()`.

    let date = new Date();
    console.log(+date); // 1639886372852
    console.log(date.getTime()); // 1639886372852

Ngoài ra, bạn có thể **trừ** hai giá trị Date trong JavaScript cho nhau. Kết quả trả về là **số mili giây chênh lệch**.

Tính năng này được áp dụng để tính thời gian của một tác vụ:

    // bắt đầu tính thời gian
    let start = new Date();
    
    // bắt đầu tác vụ
    for (let i = 0; i < 1000000; i++) {
      let doSomething = i * i * i;
    }
    
    // kết thúc tính thời gian
    let end = new Date();
    
    // Tổng thời gian thực hiện vòng lặp là:
    console.log(`${end - start} ms`); // 3 ms

[](#datenow-trong-javascript)Date.now trong JavaScript
------------------------------------------------------

Nếu chỉ cần tính thời gian của một tác vụ, bạn không cần thiết phải khởi tạo đối tượng `Date`. Thay vào đó, bạn có thể dùng phương thức `Date.now()` để trả về giá trị timestamp hiện tại.

Phương thức `Date.now()` về cơ bản là giống `new Date().getTime()`. Tuy nhiên, `Date.now()` không cần khởi tạo đối tượng `Date` mới, nên phương thức này không ảnh hưởng tới quá trình [garbage collection](/garbage-collection-trong-javascript/).

    // bắt đầu tính thời gian
    let start = Date.now()
    // bắt đầu tác vụ
    for (let i = 0; i < 1000000; i++) {
      let doSomething = i * i * i;
    }
    
    // kết thúc tính thời gian
    let end = Date.now()
    // Tổng thời gian thực hiện vòng lặp là:
    console.log(`${end - start} ms`); // 3 ms

> 💡 **Chú ý:** các cách tính thời gian với `Date` trên có độ chính xác cao nhất là **1 ms**.
> 
> Nếu bạn cần độ chính xác cao hơn thì bạn có thể dùng phương thức [`performance.now()`](https://developer.mozilla.org/en-US/docs/Web/API/Performance/now).

    // bắt đầu tính thời gian
    let start = performance.now()
    // bắt đầu tác vụ
    for (let i = 0; i < 1000000; i++) {
      let doSomething = i * i * i;
    }
    
    // kết thúc tính thời gian
    let end = performance.now()
    // Tổng thời gian thực hiện vòng lặp là:
    console.log(`${end - start} ms`); // 2.7000000029802322 ms

[](#dateparse-trong-javascript)Date.parse trong JavaScript
----------------------------------------------------------

Bạn có thể dùng phương thức `Date.parse(string)` để parse date trong JavaScript từ một `string`.

Định dạng Date đầy đủ với string là: `YYYY-MM-DDTHH:mm:ss.sssZ`.

Trong đó:

*   `YYYY-MM-DD` là **năm-tháng-ngày**.
*   Kí tự `T` dùng để phân tách.
*   `HH:mm:ss.sss` lần lượt là giờ, phút, giây và mili giây.
*   Kí tự `Z` dùng để biểu diễn múi giờ dạng `+-hh:mm`. Ngoài ra, một kí tự `Z` tương đương với **UTC+0**.

Định dạng date ngắn gọn hơn có thể là: `YYYY-MMMM-DD`, `YYYY-MM` hoặc thậm chí là `YYYY`,...

Phương thức `Date.parse(str)` sẽ parse string ở định dạng tương ứng và trả về giá trị timestamp, nếu định dạng hoặc giá trị không hợp lệ thì trả về `NaN`, ví dụ:

    let ms = Date.parse("2012-12-19T11:30:50.217+07:00");
    console.log(ms); // 1355891450217  (timestamp)

Bạn có thể tạo luôn đối tượng `Date` mới từ timestamp như sau:

    let date = new Date(Date.parse("2021-12-19T11:30:50.217+07:00"));
    console.log(date); // Sun Dec 19 2021 11:30:50 GMT+0700 (Indochina Time)

[](#t%E1%BB%95ng-k%E1%BA%BFt)Tổng kết
-------------------------------------

Date trong JavaScript được biểu diễn bởi đối tượng `Date`, trong đó:

*   Tháng đếm từ `0` (tháng 1) đến `11` (tháng 12).
*   Ngày trong tuần đếm từ `0` (chủ nhật) đến `6` (thứ 7).

Đối tượng `Date` có tính năng tự động điều chỉnh **tăng hay giảm** nếu giá trị truyền vào vượt quá phạm vi biểu diễn của ngày, tháng, năm,... Tính năng này đặc biệt hữu ích khi bạn muốn cộng/trừ với ngày/tháng/giờ,...

Ngoài ra, bạn có thể **trừ hai giá trị date** cho nhau, kết quả trả về là **số mili giây chênh lệch**. Bởi vì, `Date` trở thành **timestamp** khi chuyển thành **number**.

Phương thức `Date.now()` trả về timestamp hiện tại mà không cần tạo mới đối tượng `Date`.

[](#th%E1%BB%B1c-h%C3%A0nh)Thực hành
------------------------------------

### [](#b%C3%A0i-1)Bài 1

Tạo đối tượng `Date` bởi thời gian **Feb 20, 2021, 11:12am** với múi giờ của bạn.

 Xem đáp án

Bạn có thể sử dụng hàm khởi tạo `new Date(year, month, date, hour, minute)` với:

*   `year`: 2021.
*   `month`: tháng 2 (ứng với số `1`).
*   `date`: ngày 20.
*   `hour`: 11 giờ.
*   `minute`: 12 phút.

    let date = new Date(2021, 1, 20, 11, 12);
    console.log(date); // Sat Feb 20 2021 11:12:00 GMT+0700 (Indochina Time)

### [](#b%C3%A0i-2)Bài 2

Viết hàm `getWeekDay(date)` trả về ngày trong tuần dạng rút gọn: `SU` (chủ nhật), `MO` (thứ hai), `TU` (thứ 3), `WE` (thứ 4), `TH` (thứ 5), `FR` (thứ 6), `SA` (thứ 7).

 Xem đáp án

Phương thức `date.getDay()` trả về các ngày trong tuần bắt đầu từ `0` (chủ nhật) đến `6` (thứ 7) - giống với chỉ số của mảng.

Vì vậy, bạn có thể tạo mảng string chứa thông tin các ngày trong tuần. Rồi sau đó, bạn lấy kết quả của `date.getDay()` làm chỉ số để truy cập giá trị của mảng.

    function getWeekDay(date) {
      let weekDays = ["SU", "MO", "TU", "WE", "TH", "FR", "SA"];
      return weekDays[date.getDay()];
    }
    
    let date = new Date(2021, 1, 1); // 01/01/2021
    console.log(getWeekDay(date)); // MO

### [](#b%C3%A0i-3)Bài 3

Viết hàm `getDateAgo(date, days)` trả về ngày trong tháng với `days` ngày trước ngày `date`.

Ví dụ hôm nay là ngày 19/12/2021. Khi đó, 1 ngày trước ngày hiện tại là ngày 18/12/2021.

**Chú ý**: hàm `getDateAgo` không làm thay đổi giá trị của tham số `date` truyền vào.

 Xem đáp án

    function getDateAgo(date, days) {
      // khởi tạo biến dateAgo bằng với date hiện tại
      // để không làm thay đổi giá trị của tham số date
      let dateAgo = new Date(date.getTime());
    
      // lùi về số ngày là: days
      dateAgo.setDate(dateAgo.getDate() - days);
    
      // trả về giá trị ngày trong tháng
      return dateAgo.getDate();
    }
    
    // ví dụ ngày hôm nay
    let toDay = new Date();
    
    // hôm qua
    let yesterday = getDateAgo(toDay, 1);
    console.log(yesterday); // 18
    
    // ngày này năm trước
    let lastYear = getDateAgo(toDay, 365);
    console.log(lastYear); // 19

### [](#b%C3%A0i-4)Bài 4

Viết hàm `getLastDayOfMonth(year, month)` trả về ngày cuối cùng của tháng, trong đó:

*   `year`: là năm (4 chữ số).
*   `month`: là tháng (là số từ `0` đến `11`).

 Xem đáp án

    function getLastDayOfMonth(year, month) {
      // lấy date ứng với ngày đầu tiên của tháng tiếp theo
      let date = new Date(year, month + 1);
    
      // giảm date đi 1 đơn vị để lấy ngày cuối cùng của tháng hiện tại
      date.setDate(date.getDate() - 1);
    
      // trả về date
      return date.getDate();
    }
    
    console.log(getLastDayOfMonth(2021, 0)); // 31 - tháng 1
    console.log(getLastDayOfMonth(2021, 1)); // 28 - tháng 2
    console.log(getLastDayOfMonth(2021, 2)); // 31 - tháng 3
    console.log(getLastDayOfMonth(2021, 3)); // 30 - tháng 4
    console.log(getLastDayOfMonth(2021, 4)); // 31 - tháng 5
    console.log(getLastDayOfMonth(2021, 5)); // 30 - tháng 6
    console.log(getLastDayOfMonth(2021, 6)); // 31 - tháng 7
    console.log(getLastDayOfMonth(2021, 7)); // 31 - tháng 8
    console.log(getLastDayOfMonth(2021, 8)); // 30 - tháng 9
    console.log(getLastDayOfMonth(2021, 9)); // 31 - tháng 10
    console.log(getLastDayOfMonth(2021, 10)); // 30 - tháng 11
    console.log(getLastDayOfMonth(2021, 11)); // 31 - tháng 12

### [](#b%C3%A0i-5)Bài 5

Viết hàm `getSecondsDay()` trả về số giây đã qua của ngày hôm nay.

 Xem đáp án

    function getSecondsDay() {
      // lấy thời điểm hiện tại
      let nowDate = new Date();
    
      // lấy thời điểm 0 giờ 0 phút 0 giây của ngày hiện tại
      let beginingDate = new Date(
        nowDate.getFullYear(),
        nowDate.getMonth(),
        nowDate.getDate()
      );
    
      return Math.round((nowDate - beginingDate) / 1000);
    }
    
    console.log(getSecondsDay());

### [](#b%C3%A0i-6)Bài 6

Viết hàm `getSecondsToTomorrow()` trả về số giây từ hiện tại cho đến ngày mai.

 Xem đáp án

    function getSecondsToTomorrow() {
      // thời điểm hiện tại
      let nowDate = new Date();
    
      // 0 giờ, 0 phút, 0 giây ngày tiếp theo
      let tomorrowDate = new Date(
        nowDate.getFullYear(),
        nowDate.getMonth(),
        nowDate.getDate() + 1
      );
    
      return Math.round((tomorrowDate - nowDate) / 1000);
    }
    
    console.log(getSecondsToTomorrow());

Tham khảo: [Date and time](https://javascript.info/date)