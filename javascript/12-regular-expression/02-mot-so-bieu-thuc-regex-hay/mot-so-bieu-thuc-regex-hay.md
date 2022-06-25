---
title: "Một số biểu thức regex hay"
description: "Một số biểu thức regex hay trong javascript. Cùng tìm hiểu ngay."
keywords: [
"Một số biểu thức regex hay trong javascript",
"regex loai bo ky tu dac biet trong javascript",
"chuỗi các kí tự abc trong javascript",
"regex chi nhap so trong javascript",
"bieu thuc chinh quy javascript trong javascript",
"Kí tự đặc biệt trong regex trong javascript",
"Ví dụ regex trong javascript",
"Regex số nguyên dương trong javascript",
"mot so bieu thuc regex hay trong javascript",
"mot so bieu thuc regex hay nhat trong javascript",
"Kiểm tra string là số thập phân trong javascript",
"các regex thường gặp trong javascript",
"regex thuong gap trong javascript",
]
chapter:
  name: "Regular expression"
  slug: "chuong-12-regular-expression"
category:
  name: "Javascript"
  slug: "javascript"
image: https://kungfutech.edu.vn/thumbnail.png
position: 2
---

Trong bài viết [tìm hiểu Regular Expression JavaScript](/bai-viet/javascript/tim-hieu-regex-javascript), mình có giới thiệu với bạn về Regular Expression trong JavaScript rồi. Hy vọng qua bài viết đó, bạn đã biết và hiểu về các cú pháp cơ bản của RegExp. Còn trong trường hợp bạn vẫn chưa biết gì về nó, mình khuyên bạn nên quay lại bài viết kia để tìm hiểu về RegExp thật kỹ trước đã. Vì trong bài viết này, mình sẽ chỉ tổng hợp lại một số biểu thức chính quy RegExp hay mà mình sưu tầm được và sẽ không giải thích gì nhiều.

Trước khi đi vào nội dung chính của bài viết, mình sẽ tóm tắt lại một số kiến thức cơ bản về biểu thức chính quy RegExp để bạn tiện theo dõi:

- `/abc/` : chuỗi các kí tự abc
- `/\[abc\]`: bất kỳ kí tự nào thuộc tập hợp a, b, c
- `/\[^abc\]`: bất kỳ kí tự nào không thuộc tập a, b, c
- `/\[0-9\]/`: bất kỳ kí tự nào thuộc đoạn từ 0 đến 9
- `/x+/`: thành phần x xuất hiện >= 1 lần
- `/x\*/`: thành phần x xuất hiện >= 0 lần (có thể không xuất hiện)
- `/x?/`: thành phần x xuất hiện 0 hoặc 1 lần
- `/x{2, 4}/`: thành phần x xuất hiện từ 2 đến 4 lần
- `/(abc)/`: cụm abc
- `/a|b|c/`: bất kì pattern nào trong 3 loại a, b, c
- `/\\d/`: chữ số từ 0 đến 9
- `/\\w/`: chữ cái
- `/\\s/`: kí tự trắng (dấu cách, tab, dòng mới,…)
- `/./` : bất kỳ kí tự nào trừ dòng mới
- `/\\b/`: ranh giới từ
- `/^/`: bắt đầu string
- `/$/`: kết thúc string

Bây giờ, mình bắt đầu vào nội dung chính nhé!

**Regex:**

`/^[a-zA-Z]+$/;`

**Test:**

```js
const isAlpha = /^[a-zA-Z]+$/;
console.log(isAlpha.test("javascript")); // true
console.log(isAlpha.test("JavaScript")); // true
console.log(isAlpha.test("2019")); // false
console.log(isAlpha.test("javascript2019")); // false
console.log(isAlpha.test("J@vascr!pt")); // false
console.log(isAlpha.test("java script")); // false
console.log(isAlpha.test("java-script")); // false
console.log(isAlpha.test("")); // false
```

**Regex:**

`/^\d+$/;`

**Test:**

```js
const isNumeric = /^\d+$/;
console.log(isNumeric.test("2019")); // true
console.log(isNumeric.test("javascript")); // false
console.log(isNumeric.test("JavaScript")); // false
console.log(isNumeric.test("20 19")); // false
console.log(isNumeric.test("javascript2019")); // false
console.log(isNumeric.test("J@vascr!pt")); // false
console.log(isNumeric.test("java script")); // false
console.log(isNumeric.test("java-script")); // false
console.log(isNumeric.test("")); // false
```

**Regex:**

`/^[a-zA-Z0-9]+$/;`

**Test:**

```js
const isNumeric = /^[a-zA-Z0-9]+$/;
console.log(isNumeric.test("javascript")); // true
console.log(isNumeric.test("JavaScript")); // true
console.log(isNumeric.test("2019")); // true
console.log(isNumeric.test("javascript2019")); // true
console.log(isNumeric.test("20 19")); // false
console.log(isNumeric.test("J@vascr!pt")); // false
console.log(isNumeric.test("java script")); // false
console.log(isNumeric.test("java-script")); // false
console.log(isNumeric.test("")); // false
```

## Kiểm tra string là base64

**Regex:**

`/^([0-9a-zA-Z+/]{4})*(([0-9a-zA-Z+/]{2}==)|([0-9a-zA-Z+/]{3}=))?$/;`

**Test:**

```js
const isBase64 =
  /^([0-9a-zA-Z+/]{4})*(([0-9a-zA-Z+/]{2}==)|([0-9a-zA-Z+/]{3}=))?$/;
console.log(isBase64.test("SomeStringObviouslyNotBase64Encoded...")); // false
console.log(isBase64.test("U29tZVN0cmluZ09idmlvdXNseU5vdEJhc2U2NEVuY29kZWQ=")); // true
```

Tham khảo: [Determine if string is in base64 using JavaScript](https://stackoverflow.com/questions/7860392/determine-if-string-is-in-base64-using-javascript/)

## Kiểm tra string là boolean

**Regex:**

`/^true|false$/;`

**Test:**

```js
const isBoolean = /^true|false$/;
console.log(isBoolean.test("true")); // true
console.log(isBoolean.test("false")); // true
console.log(isBoolean.test("TRUE")); // false
console.log(isBoolean.test("FAlse")); // false
console.log(isBoolean.test("abc")); // false
console.log(isBoolean.test("123")); // false
console.log(isBoolean.test("")); // false
```

## Kiểm tra string là số thập phân

**Regex:**

`/^[+-]?((\d+(\.\d*)?)|(\.\d+))$/;`

**Test:**

```js
const isDecimal = /^[+-]?((\d+(\.\d*)?)|(\.\d+))$/;
console.log(isDecimal.test("123")); // true
console.log(isDecimal.test("23.45")); // true
console.log(isDecimal.test("34.")); // true
console.log(isDecimal.test(".45")); // true
console.log(isDecimal.test("-123")); // true
console.log(isDecimal.test("-273.15")); // true
console.log(isDecimal.test("-42.")); // true
console.log(isDecimal.test("-.45")); // true
console.log(isDecimal.test("+516")); // true
console.log(isDecimal.test("+9.8")); // true
console.log(isDecimal.test("+2.")); // true
console.log(isDecimal.test("+.5")); // true
console.log(isDecimal.test(".")); // false
console.log(isDecimal.test("-.")); // false
console.log(isDecimal.test("+.")); // false
console.log(isDecimal.test("*12.34")); // false
console.log(isDecimal.test("abc")); // false
console.log(isDecimal.test("")); // false
```

Tham khảo: [Decimal number regular expression, where digit after decimal is optional](https://stackoverflow.com/questions/12117024/decimal-number-regular-expression-where-digit-after-decimal-is-optional)

## Kiểm tra string là số Hexadecimal

**Regex:**

```js
/^[0-9a-fA-F]+$/;
```

**Test:**

```js
const isHexaDecimal = /^[0-9a-fA-F]+$/;
console.log(isHexaDecimal.test("012")); // true
console.log(isHexaDecimal.test("A23A1")); // true
console.log(isHexaDecimal.test("1AFFa1")); // true
console.log(isHexaDecimal.test("2f43")); // true
console.log(isHexaDecimal.test("12308")); // true
console.log(isHexaDecimal.test("1ab6")); // true
console.log(isHexaDecimal.test("1a2b4c5d6e7f")); // true
console.log(isHexaDecimal.test("abcdef")); // true
console.log(isHexaDecimal.test("xyz")); // false
console.log(isHexaDecimal.test("1.23")); // false
console.log(isHexaDecimal.test(".09")); // false
console.log(isHexaDecimal.test("#F0h")); // false
console.log(isHexaDecimal.test("#1234567")); // false
```

Tham khảo: [Verify if String is hexadecimal](https://stackoverflow.com/questions/11424540/verify-if-string-is-hexadecimal)

## Kiểm tra string là mã màu dạng hexa

**Regex:**

`/^#([A-Fa-f0-9]{6}|[A-Fa-f0-9]{3})$/;`

**Test:**

```js
const isHexColor = /^#([A-Fa-f0-9]{6}|[A-Fa-f0-9]{3})$/;
console.log(isHexColor.test("#1f1f1F")); // true
console.log(isHexColor.test("#AFAFAF")); // true
console.log(isHexColor.test("#1AFFa1")); // true
console.log(isHexColor.test("#222fff")); // true
console.log(isHexColor.test("#F00")); // true
console.log(isHexColor.test("123456")); // false
console.log(isHexColor.test("#afafah")); // false
console.log(isHexColor.test("#123abce")); // false
console.log(isHexColor.test("aFaE3f")); // false
console.log(isHexColor.test("F00")); // false
console.log(isHexColor.test("#afaf")); // false
console.log(isHexColor.test("#F0h")); // false
console.log(isHexColor.test("#1234567")); // false
```

Tham khảo: [How to validate Hex color code with regular expression](http://www.mkyong.com/regular-expressions/how-to-validate-hex-color-code-with-regular-expression/)

## Kiểm tra string là mã màu RGB

**Regex:**

`/^rgb\(((\s*(\d|[1-9]\d|1\d\d|2[0-4][0-9]|25[0-5])\s*),){2}(\s*(\d|[1-9]\d|1\d\d|2[0-4][0-9]|25[0-5])\s*)\)$/;`

**Test:**

```js
const isRGBColor =
  /^rgb\(((\s*(\d|[1-9]\d|1\d\d|2[0-4][0-9]|25[0-5])\s*),){2}(\s*(\d|[1-9]\d|1\d\d|2[0-4][0-9]|25[0-5])\s*)\)$/;
console.log(isRGBColor.test("rgb(0, 0, 0)")); // true
console.log(isRGBColor.test("rgb(0, 15, 120)")); // true
console.log(isRGBColor.test("rgb(10, 1, 230)")); // true
console.log(isRGBColor.test("rgb(255, 15, 9)")); // true
console.log(isRGBColor.test("rgb(255, 255, 255)")); // true
console.log(isRGBColor.test("rgb(255,15,120)")); // true
console.log(isRGBColor.test("rgb( 255, 15,  120 )")); // true
console.log(isRGBColor.test("rgc(255,15,120)")); // false
console.log(isRGBColor.test("rgb[255,15,120]")); // false
console.log(isRGBColor.test("rgb(255-15-120)")); // false
console.log(isRGBColor.test("rgb( 255,5,120,)")); // false
console.log(isRGBColor.test("rgb(355, 5, 120)")); // false
console.log(isRGBColor.test("rgb(155, 405, 120)")); // false
console.log(isRGBColor.test("rgb(5, 5, 520)")); // false
console.log(isRGBColor.test("rgb(255,,120)")); // false
console.log(isRGBColor.test("rgb(03, 15, 120)")); // false
```

## Kiểm tra string là mã màu RGBA

**Regex:**

`/^rgba\(((\s*(\d|[1-9]\d|1\d\d|2[0-4][0-9]|25[0-5])\s*),){3}(\s*(1(\.0+)?|0?\.\d+)\s*)\)$/;`

**Test:**

```js
const isRGBAColor =
  /^rgba\(((\s*(\d|[1-9]\d|1\d\d|2[0-4][0-9]|25[0-5])\s*),){3}(\s*(1(\.0+)?|0?\.\d+)\s*)\)$/;
console.log(isRGBAColor.test("rgba(0, 0, 0, 1)")); // true
console.log(isRGBAColor.test("rgba(0, 15, 120, 1.0)")); // true
console.log(isRGBAColor.test("rgba(10, 1, 230, 1.00)")); // true
console.log(isRGBAColor.test("rgba(255, 15, 9, 0.3)")); // true
console.log(isRGBAColor.test("rgba(255, 255, 255, .555)")); // true
console.log(isRGBAColor.test("rgba(255,15,120,0.4)")); // true
console.log(isRGBAColor.test("rgba( 255, 15,  120 , 1.0)")); // true
console.log(isRGBAColor.test("rgbd(255,15,120,1.0)")); // false
console.log(isRGBAColor.test("rgba[255,15,120,1.0]")); // false
console.log(isRGBAColor.test("rgba(255-15-120-1.0)")); // false
console.log(isRGBAColor.test("rgba( 255,5,120,1,)")); // false
console.log(isRGBAColor.test("rgba(155, 5, 120,2)")); // false
console.log(isRGBAColor.test("rgba(155, 405, 120, 0.3)")); // false
console.log(isRGBAColor.test("rgba(5, 5, 520, 0.4)")); // false
console.log(isRGBAColor.test("rgba(255,,120, 1)")); // false
console.log(isRGBAColor.test("rgba(03, 15, 120, 0.5)")); // false
```

## Kiểm tra string là email

**Regex:**

`/^[a-z0-9!#$%&'*+/=?^_`{|}~-]+(?:\.[a-z0-9!#$%&'*+/=?^_`{|}~-]+)_@(?:[a-z0-9](?:[a-z0-9-]_[a-z0-9])?\.)+[a-z0-9](?:[a-z0-9-]*[a-z0-9])?$/i;`

**Test:**

```js
const isEmail =
  /^[a-z0-9!#$%&'*+/=?^_`{|}~-]+(?:\.[a-z0-9!#$%&'*+/=?^_`{|}~-]+)*@(?:[a-z0-9](?:[a-z0-9-]*[a-z0-9])?\.)+[a-z0-9](?:[a-z0-9-]*[a-z0-9])?$/i;
console.log(isEmail.test("123")); // false
console.log(isEmail.test("email")); // false
console.log(isEmail.test("lam@hotmail")); // false
console.log(isEmail.test("@lpv@yahoo")); // false
console.log(isEmail.test("+admin@test")); // false
console.log(isEmail.test("editer@dm.vn_")); // false
console.log(isEmail.test("lampv@gmail.com")); // true
console.log(isEmail.test("-lamp@mail.co")); // true
console.log(isEmail.test("LM.pv666@domain.vn")); // true
console.log(isEmail.test("124la@test.com")); // true
console.log(isEmail.test("+Admin@test.io")); // true
console.log(isEmail.test("user@test.com.vn")); // true
console.log(isEmail.test("lam-pv@js.vn")); // true
```

Tham khảo: [How to validate an email address in JavaScript?](https://stackoverflow.com/questions/46155/how-to-validate-an-email-address-in-javascript)

## Kiểm tra string là IPv4

**Regex:**

`/^(([0-9]|[1-9][0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5])\.){3}([0-9]|[1-9][0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5])$/;`

**Test:**

```js
const isIPv4 =
  /^(([0-9]|[1-9][0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5])\.){3}([0-9]|[1-9][0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5])$/;
console.log(isIPv4.test("255.255.255.255")); // true
console.log(isIPv4.test("0.0.0.0")); // true
console.log(isIPv4.test("0.12.34.56")); // true
console.log(isIPv4.test("255.0.0.255")); // true
console.log(isIPv4.test("12.34.56.78")); // true
console.log(isIPv4.test("02.34.56.78")); // false
console.log(isIPv4.test("12.04.56.78")); // false
console.log(isIPv4.test("12.34.06.78")); // false
console.log(isIPv4.test("12.34.56.08")); // false
console.log(isIPv4.test("12.34.56.055")); // false
console.log(isIPv4.test("12..34.56.0")); // false
console.log(isIPv4.test("ab.ab.ab.ab")); // false
console.log(isIPv4.test(".255.255.23")); // false
console.log(isIPv4.test("11.11.0.256")); // false
console.log(isIPv4.test("1000.0.0.00")); // false
console.log(isIPv4.test("255.255.255.00")); // false
console.log(isIPv4.test("12.34.56.78.")); // false
console.log(isIPv4.test("111111111111")); // false
```

Tham khảo: [IP v4 validation REGEX](https://www.regexpal.com/104851)

## Check string là địa chỉ MAC

**Regex:**

`/^([0-9A-Fa-f]{2}[:-]){5}([0-9A-Fa-f]{2})$/;`

**Test:**

```js
const isMACAddress = /^([0-9A-Fa-f]{2}[:-]){5}([0-9A-Fa-f]{2})$/;
console.log(isMACAddress.test("3D:F2:C9:A6:B3:4F")); // true
console.log(isMACAddress.test("3d:f2:c9:a6:b3:4f")); // true
console.log(isMACAddress.test("3D-F2-C9-A6-B3-4F")); // true
console.log(isMACAddress.test("3d-f2-c9-a6-b3-4F")); // true
console.log(isMACAddress.test("d3-2f-9c-6a-3b-f4")); // true
console.log(isMACAddress.test("00-00-00-00-00-00")); // true
console.log(isMACAddress.test("3D:F2-C9:A6-B3:4F")); // true
console.log(isMACAddress.test("99:99:99:99:99:99")); // true
console.log(isMACAddress.test("0:0:0:0:0:0")); // false
console.log(isMACAddress.test("d33-2ff-9c4-6aa-3b4-b56")); // false
console.log(isMACAddress.test("qw:er:ty:ui:op:as")); // false
console.log(isMACAddress.test("3A.FC.C0.B6.A8.45")); // false
console.log(isMACAddress.test("3A-FC-C0-B6-A9")); // false
console.log(isMACAddress.test("d3-2f-9c-6a-3b-f4-b5")); // false
```

Tham khảo: [What is a regular expression for a MAC Address?](https://stackoverflow.com/questions/4260467/what-is-a-regular-expression-for-a-mac-address)

## Kiểm tra string là MD5

**Regex:**

`/^[a-f0-9]{32}$/;`

**Test:**

```js
const isMD5Format = /^[a-f0-9]{32}$/;
console.log(isMD5Format.test("00236a2ae558018ed13b5222ef1bd987")); // true
console.log(isMD5Format.test("00236a2ae558018ed13b5222ef1bd9878")); // false
console.log(isMD5Format.test("00236a2ae558018ed13b5222ef1bd98")); // false
console.log(isMD5Format.test("00236a2ae558018ed13b5222ef1bd9.8")); // false
console.log(isMD5Format.test("00236a2ae558018ed13b5222ef1bdxyz")); // false
```

Tham khảo: [Regex to match md5 hashes](https://stackoverflow.com/questions/21517102/regex-to-match-md5-hashes)

## Kiểm tra string là số điện thoại Việt Nam

Phần này mình kiểm tra một string nhập vào là số điện thoại di động 10 số ở Việt Nam (sau khi đã chuyển đổi từ 11 số về 10 số).

Còn về phần test thì có khá nhiều trường hợp nên mình không thể viết hết trong bài này được. Do đó, khi sử dụng bạn cần kiểm thử lại độ chính xác với những test case của bạn nhé.

**Regex:**

`/^(0|\+84)(\s|\.)?((3[2-9])|(5[689])|(7[06-9])|(8[1-689])|(9[0-46-9]))(\d)(\s|\.)?(\d{3})(\s|\.)?(\d{3})$/`

**Test:**

```js
const isVNPhoneMobile =
  /^(0|\+84)(\s|\.)?((3[2-9])|(5[689])|(7[06-9])|(8[1-689])|(9[0-46-9]))(\d)(\s|\.)?(\d{3})(\s|\.)?(\d{3})$/;

console.log(isVNPhoneMobile.test("0866888999")); // true - Viettel
console.log(isVNPhoneMobile.test("0.866.888.999")); // true
console.log(isVNPhoneMobile.test("+84.866.888.999")); // true
console.log(isVNPhoneMobile.test("0 866 888 999")); // true
console.log(isVNPhoneMobile.test("0866 888 999")); // true
console.log(isVNPhoneMobile.test("+84 866 888 999")); // true
console.log(isVNPhoneMobile.test("0966 888 999")); // true
console.log(isVNPhoneMobile.test("0977 888 999")); // true
console.log(isVNPhoneMobile.test("0988 888 999")); // true
console.log(isVNPhoneMobile.test("0322 888 999")); // true
console.log(isVNPhoneMobile.test("0333 888 999")); // true
console.log(isVNPhoneMobile.test("0344 888 999")); // true
console.log(isVNPhoneMobile.test("0355 888 999")); // true
console.log(isVNPhoneMobile.test("0366 888 999")); // true
console.log(isVNPhoneMobile.test("0377 888 999")); // true
console.log(isVNPhoneMobile.test("0388 888 999")); // true
console.log(isVNPhoneMobile.test("0399 888 999")); // true

console.log(isVNPhoneMobile.test("0899 888 999")); // true - Mobifone
console.log(isVNPhoneMobile.test("0900 888 999")); // true
console.log(isVNPhoneMobile.test("0933 888 999")); // true
console.log(isVNPhoneMobile.test("0700 888 999")); // true
console.log(isVNPhoneMobile.test("0799 888 999")); // true
console.log(isVNPhoneMobile.test("0777 888 999")); // true
console.log(isVNPhoneMobile.test("0766 888 999")); // true
console.log(isVNPhoneMobile.test("0788 888 999")); // true

console.log(isVNPhoneMobile.test("0888 888 999")); // true - Vinaphone
console.log(isVNPhoneMobile.test("0911 888 999")); // true
console.log(isVNPhoneMobile.test("0944 888 999")); // true
console.log(isVNPhoneMobile.test("0833 888 999")); // true
console.log(isVNPhoneMobile.test("0844 888 999")); // true
console.log(isVNPhoneMobile.test("0855 888 999")); // true
console.log(isVNPhoneMobile.test("0811 888 999")); // true
console.log(isVNPhoneMobile.test("0822 888 999")); // true

console.log(isVNPhoneMobile.test("0922 888 999")); // true - Vietnamobile
console.log(isVNPhoneMobile.test("0566 888 999")); // true
console.log(isVNPhoneMobile.test("0588 888 999")); // true

console.log(isVNPhoneMobile.test("0999 888 999")); // true - GMobile
console.log(isVNPhoneMobile.test("0599 888 999")); // true

console.log(isVNPhoneMobile.test("1234 567 890")); // false
console.log(isVNPhoneMobile.test("0311 888 999")); // false
console.log(isVNPhoneMobile.test("0511 888 999")); // false
console.log(isVNPhoneMobile.test("0522 888 999")); // false
console.log(isVNPhoneMobile.test("0533 888 999")); // false
console.log(isVNPhoneMobile.test("0544 888 999")); // false
console.log(isVNPhoneMobile.test("0555 888 999")); // false
console.log(isVNPhoneMobile.test("0711 888 999")); // false
console.log(isVNPhoneMobile.test("0722 888 999")); // false
console.log(isVNPhoneMobile.test("0733 888 999")); // false
console.log(isVNPhoneMobile.test("0744 888 999")); // false
console.log(isVNPhoneMobile.test("0755 888 999")); // false
console.log(isVNPhoneMobile.test("0800 888 999")); // false
console.log(isVNPhoneMobile.test("0877 888 999")); // false
console.log(isVNPhoneMobile.test("0955 888 999")); // false
```

## Kiểm tra string là mật khẩu mạnh

Theo bạn, thế nào là một mật khẩu mạnh? Ở đây, mình định nghĩa một mật khẩu mạnh là cái thỏa mãn những điều kiện sau đây:

- Có tối thiểu 8 ký tự
- Có ít nhất một kí tự viết thường (a-z)
- Có ít nhất một kí tự viết hoa (A-Z)
- Có ít nhất một chữ số (0-9)
- Có ít nhất một ký tự đặc biệt (_!@#$%^&_)

**Regex:**

`/^(?=.*[a-z])(?=.*[A-Z])(?=.*[0-9])(?=.*[!@#\$%\^&\*]).{8,}$/`

**Test:**

```js
const isStrongPassword =
  /^(?=.*[a-z])(?=.*[A-Z])(?=.*[0-9])(?=.*[!@#\$%\^&\*]).{8,}$/;

console.log(isStrongPassword.test("Abcd!234")); // true
console.log(isStrongPassword.test("aBcd1@345")); // true
console.log(isStrongPassword.test("abCd12$4")); // true
console.log(isStrongPassword.test("AbcD1234%")); // true
console.log(isStrongPassword.test("@bcCd!234^")); // true
console.log(isStrongPassword.test("@B&d!234&*7890")); // true
console.log(isStrongPassword.test("12345678")); // false
console.log(isStrongPassword.test("!2345678")); // false
console.log(isStrongPassword.test("abcdefgh")); // false
console.log(isStrongPassword.test("AcD1%")); // false
console.log(isStrongPassword.test("ABCDEFGH")); // false
```

## Lời kết

Trên đây là những biểu thức chính quy RegExp hay, hữu ích mà mình đã sưu tầm được. Tuy nhiên, Regular Expression là một chủ đề khá phức tạp. Vì vậy, rất khó để có được những biểu thức chính quy RegExp chính xác một cách tuyệt đối.

Khi áp dụng vào project thực tế, bạn vẫn nên kiểm tra lại. Hoặc bạn kết hợp với các phương pháp khác để có được giải pháp chính xác nhất. Thay vì việc cứ copy-paste một solution nào đó trên mạng (kể cả của mình).

Cuối cùng, nếu có phần nào khó hiểu hoặc có bài toán nào bạn chưa giải quyết được, thì bạn cứ thoải mái chia sẻ với mình trong phần bình luận phía dưới nhé!

Xin chào và hẹn gặp lại, thân ái!
