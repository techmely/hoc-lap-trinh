---
title: "Thuật toán cơ bản trong Javascript"
description: "Thuật toán giúp cho lập trình viên rèn luyện tư duy.Ngoài ra, khi thuật toán tốt thì chương trình viết ra sẽ chạy nhanh hơn, hoặc trông sẽ sáng sủa, dễ hiểu và dễ bảo trì hơn."
keywords: [
"Thuật toán cơ bản trong Javascript",
"bai tap thuat toan javascript",
"thuat toan javascript",
"luyen thuat toan javascript",
"hoc thuat toan co ban",
"luyen giai thuat javascript",
"code javascript co ban",
"Bài tập thuật toán JavaScript",
"Thuật toán JavaScript",
"Tìm hiểu độ phức tạp thuật toán thông qua JavaScript",
"Algorithm trong Javascript"
]
chapter:
  name: "Thuật toán với Javascript"
  slug: "chuong-18-javascript-algorithm"
category:
  name: "Javascript"
  slug: "javascript"
image: https://kungfutech.edu.vn/thumbnail.png
position: 1
---

Trong lập trình nói chung và lập trình JavaScript nói riêng, việc học thuật toán vẫn luôn vô cùng quan trọng. Thuật toán giúp cho lập trình viên rèn luyện tư duy.

Ngoài ra, khi thuật toán tốt thì chương trình viết ra sẽ chạy nhanh hơn, hoặc trông sẽ sáng sủa, dễ hiểu và dễ bảo trì hơn.

Bôm nay, mình sẽ tổng hợp lại những bài toán thuộc chủ đề **Basic Algorithm Scripting** trên freeCodeCamp để các bạn tiện theo dõi và có thể tham khảo khi cần.

Tuy nhiên, những bài toán này khá đơn giản nên mình sẽ không giải thích cách làm. Nếu các bạn có thắc mắc hay góp ý thì có thể để lại ở phần bình luận phía dưới.

Trước khi đi vào tìm hiểu các bài toán, các bạn có thể đọc trước các bài viết sau. Chúng khá hữu ích vì các thuật toán sau đây sẽ sử dụng đến những kiến thức trong đó.

## Basic Algorithm Scripting - Reverse a String

Cho một string, nhiệm vụ của bạn là phải đảo ngược lại string đó. Ví dụ: **Hello** => **olleH.**

```js
function reverseString(str) {
  return str.split("").reverse().join("");
}

reverseString("hello");
```

Tham khảo:

- [Global String Object](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/String)
- [String.prototype.split()](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/String/split)
- [Array.prototype.reverse()](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array/reverse)
- [Array.prototype.join()](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array/join)

## Basic Algorithm Scripting - Factorialize a Number

Tính giai thừa của một số tự nhiên n!. Ví dụ: **5! = 5 \* 4 \* 3 \* 2 \* 1**.

```js
function factorialize(num) {
  if (num == 0) return 1;

  for (var i = num - 1; i >= 1; i--) num *= i;

  return num;
}

factorialize(5);
```

Tham khảo:

- [Arithmetic Operators](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Operators/Arithmetic_Operators)

## Basic Algorithm Scripting - Check for Palindromes

Kiểm tra xem một string có phải là **palindrome** hay không? (Một string được gọi là **palindrome** khi và chỉ khi đọc ngược và đọc xuôi đều giống nhau, với điều kiện bỏ qua các dấu câu, kí tự đặc biệt, dấu cách). Ví dụ: **boob, eye,...**

```js
function palindrome(str) {
  var newStr = str.replace(/[^a-zA-Z0-9]/g, "").toLowerCase();
  var newStrReverse = newStr.split("").reverse().join("");
  return newStr === newStrReverse;
}

palindrome("eye");
```

Tham khảo:

- [Tìm hiểu Regular Expression JavaScript](/bai-viet/javascript/tim-hieu-regex-javascript)
- [String.prototype.replace()](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/String/replace)
- [String.prototype.toLowerCase()](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/String/toLowerCase)

## Basic Algorithm Scripting - Find the Longest Word in a String

Tìm độ dài của từ dài nhất trong câu.

```js
function findLongestWord(str) {
  var words = str.split(" ");
  var maxLength = words.reduce(function (acc, cur) {
    return cur.length > acc ? cur.length : acc;
  }, 0);
  return maxLength;
}

findLongestWord("The quick brown fox jumped over the lazy dog");
```

Tham khảo:

- [String.prototype.split()](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/String/split)
- [String.length](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/String/length)
- [Array.prototype.reduce()](https://developer.mozilla.org/en/docs/Web/JavaScript/Reference/Global_Objects/Array/reduce)

## Basic Algorithm Scripting - Title Case a Sentence

Trả về string với các từ có chữ cái đầu tiên viết hoa. Ví dụ: **I'm a little tea pot** => **I'm A Little Tea Pot**.

```js
function titleCase(str) {
  var words = str.split(" ");

  var newWords = words.map(function (word) {
    var chars = word.split("");

    chars[0] = chars[0].toUpperCase();
    for (var i = 1; i < chars.length; i++) {
      chars[i] = chars[i].toLowerCase();
    }

    return chars.join("");
  });

  return newWords.join(" ");
}

titleCase("I'm a little tea pot");
```

Tham khảo:

- [String.prototype.split()](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/String/split)
- [String.prototype.toUpperCase()](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/String/toUpperCase)
- [String.prototype.toLowerCase()](https://developer.mozilla.org/en/docs/Web/JavaScript/Reference/Global_Objects/String/toLowerCase)
- [Array.prototype.join()](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array/join)

## Basic Algorithm Scripting - Return Largest Numbers in Arrays

Trả về một mảng gồm các số lớn nhất của mỗi sub-array.

```js
function largestOfFour(arr) {
  var answer = [];
  for (var i = 0; i < arr.length; i++) {
    var max = 0;
    for (var j = 0; j < arr[i].length; j++) {
      if (arr[i][j] > max) max = arr[i][j];
    }
    answer.push(max);
  }
  return answer;
}

largestOfFour([
  [4, 5, 1, 3],
  [13, 27, 18, 26],
  [32, 35, 37, 39],
  [1000, 1001, 857, 1],
]);
```

Tham khảo:

- [Comparison Operators](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Operators/Comparison_Operators)
- [Array.prototype.push()](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array/push)

## Basic Algorithm Scripting - Confirm the Ending

Kiểm tra xem một string có được kết thúc bởi một string khác.

```js
function confirmEnding(str, target) {
  return target === str.substr(-target.length);
}

confirmEnding("Bastian", "n");
```

Tham khảo:

- [String.prototype.substr()](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/String/substr)
- [String.prototype.substring()](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/String/substring)

## Basic Algorithm Scripting - Repeat a string repeat a string

Lặp lại string với số lần cho trước.

```js
function repeatStringNumTimes(str, num) {
  var answer = "";
  for (var i = 0; i < num; i++) answer += str;
  return answer;
}

repeatStringNumTimes("abc", 3);
```

Tham khảo:

- [Global String Object](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/String)

## Basic Algorithm Scripting - Truncate a string

Rút gọn string nếu nó dài quá n kí tự.

```js
function truncateString(str, num) {
  if (str.length <= num) return str;
  if (num <= 3) return str.slice(0, num) + "...";
  return str.slice(0, num - 3) + "...";
}

truncateString("A-tisket a-tasket A green and yellow basket", 11);
```

Tham khảo:

- [String.prototype.slice()](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/String/slice)

## Basic Algorithm Scripting - Chunky Monkey

Chia mảng thành các phần với độ dài n cho trước.

```js
function chunkArrayInGroups(arr, size) {
  var answer = [];
  for (var i = 0; i < arr.length; i += size) {
    answer.push(arr.slice(i, i + size));
  }
  return answer;
}

chunkArrayInGroups(["a", "b", "c", "d"], 2);
```

Tham khảo:

- [Array.prototype.push()](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array/push)
- [Array.prototype.slice()](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array/slice)

## Basic Algorithm Scripting - Slasher Flick

Trả về những phần tử của mảng sau khi đã cắt đi n phần tử đầu tiên.

```js
function slasher(arr, howMany) {
  arr.splice(0, howMany);
  return arr;
}

slasher([1, 2, 3], 2);
```

Tham khảo:

- [Array.prototype.slice()](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array/slice)
- [Array.prototype.splice()](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array/splice)

## Basic Algorithm Scripting - Mutations

Kiểm tra xem trong 1 string có chứa tất cả các kí tự của string thứ 2 hay không.

```js
function mutation(arr) {
  arr[0] = arr[0].toLowerCase();
  arr[1] = arr[1].toLowerCase();
  for (var i = 0; i < arr[1].length; i++) {
    if (arr[0].indexOf(arr[1][i]) < 0) return false;
  }
  return true;
}

mutation(["hello", "hey"]);
```

Tham khảo:

- [String.prototype.indexOf()](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/String/indexOf)
- [String.prototype.toLowerCase()](https://developer.mozilla.org/en/docs/Web/JavaScript/Reference/Global_Objects/String/toLowerCase)

## Basic Algorithm Scripting - Falsy Bouncer

Bỏ đi tất cả các giá trị **falsy** khỏi một mảng (giá trị **falsy** là false, null, 0, "", undefined và NaN).

```js
function bouncer(arr) {
  var answer = arr.filter(function (val) {
    return (
      (typeof val == "string" && val != "") ||
      (val != false &&
        val != null &&
        val != 0 &&
        val != undefined &&
        !isNaN(val))
    );
  });
  return answer;
}

bouncer([7, "ate", "", false, 9]);
```

Tham khảo:

- [Boolean Objects](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Boolean)
- [Array.prototype.filter()](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array/filter)
- [isNaN()](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/isNaN)

## Basic Algorithm Scripting - Seek and Destroy

Bỏ đi tất cả các phần tử của mảng giống với tập cho trước.

```js
function destroyer(arr) {
  var args = arguments;
  var answer = arr.filter(function (val) {
    for (var i = 1; i < args.length; i++) {
      if (val === args[i]) return false;
    }
    return true;
  });
  return answer;
}

destroyer([1, 2, 3, 1, 2, 3], 2, 3);
```

Tham khảo:

- [Arguments object](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Functions/arguments)
- [Array.prototype.filter()](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array/filter)

## Basic Algorithm Scripting - Where do I belong

Tìm ra vị trí có chỉ số nhỏ nhất phù hợp để chèn một số cho trước vào.

```js
function getIndexToIns(arr, num) {
  var newArr = arr.sort(function (a, b) {
    return a - b;
  });
  var index = 0;
  while (true) {
    if (index == newArr.length || newArr[index] >= num) return index;
    index++;
  }
}

getIndexToIns([40, 60], 50);
```

Tham khảo:

- [Array Sorting – vấn đề muôn thuở](/bai-viet/javascript/sap-xep-mang-trong-javascript)
- [Array.prototype.sort()](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array/sort)

## Basic Algorithm Scripting - Caesars Cipher

Giải mã string cho trước sử dụng **ROT13**.

```js
function rot13(str) {
  // LBH QVQ VG!
  var arr = str.split("");
  var code, delta;
  for (var i = 0; i < arr.length; i++) {
    code = arr[i].charCodeAt(0) - 13;

    if (arr[i] >= "A" && arr[i] < "N") {
      delta = "A".charCodeAt(0) - code;
      code = "Z".charCodeAt(0) - delta + 1;
      arr[i] = String.fromCharCode(code);
    } else if (arr[i] >= "N" && arr[i] <= "Z") {
      arr[i] = String.fromCharCode(code);
    }
  }
  return arr.join("");
}

// Change the inputs below to test
rot13("SERR PBQR PNZC");
```

Tham khảo:

- [String.prototype.charCodeAt()](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/String/charCodeAt)
- [String.fromCharCode()](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/String/fromCharCode)

## Kết luận

Trên đây là tổng hợp các bài toán thuộc chủ đề **Basic Algorithm Scripting** trên freeCodeCamp. Theo cá nhân mình thấy thì các bài toán trên khá dễ. Nhưng lại rất hay ở chỗ, nó giúp ta áp dụng được kiến thức lý thuyết. Nếu các bạn có gì thắc mắc, góp ý hay cải tiến các thuật toán trên. Vui lòng để lại bình luận phía dưới nhé.
