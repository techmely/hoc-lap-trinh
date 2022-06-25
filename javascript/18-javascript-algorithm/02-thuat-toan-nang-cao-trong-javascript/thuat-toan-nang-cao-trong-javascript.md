---
title: "Thuật toán nâng cao trong Javascript"
description: "Thuật toán giúp cho lập trình viên rèn luyện tư duy.Ngoài ra, khi thuật toán tốt thì chương trình viết ra sẽ chạy nhanh hơn, hoặc trông sẽ sáng sủa, dễ hiểu và dễ bảo trì hơn."
keywords: [
"Thuật toán nâng cao trong Javascript",
"bai tap thuat toan javascript",
"thuat toan javascript",
"luyen thuat toan javascript",
"hoc thuat toan nâng cao",
"luyen giai thuat javascript",
"code javascript nâng cao",
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
position: 2
---

Bài viết trước mình đã chia sẻ với bạn các bài toán thuộc chủ đề [Basic Algorithm Scripting](/bai-viet/javascript/thuat-toan-co-ban-trong-javascript). Nếu bạn đã đọc qua thì có thể thấy rằng, đó đều là những bài toán khá dễ. Ngược lại, các bài toán hôm nay sẽ khó hơn một chút. Vì chúng thuộc chủ đề **Intermediate Algorithm Scripting**.

## Intermediate Algorithm Scripting - Sum All Numbers in a Range

Tính tổng các số trong một khoảng cho trước.

```js
function sumAll(arr) {
  var min = Math.min(arr[0], arr[1]);
  var max = Math.max(arr[0], arr[1]);
  var ans = 0;
  for (var i = min; i <= max; i++) {
    ans += i;
  }
  return ans;
}

sumAll([1, 4]);
```

Tham khảo:

- [Math.max()](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Math/max)
- [Math.min()](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Math/min)

## Intermediate Algorithm Scripting - Diff Two Arrays 

Kiểm tra hai mảng cho trước và trả về mảng mới chứa những phần tử thuộc chỉ một trong hai mảng đó.

```js
function diffArray(arr1, arr2) {
  function isExist(item, arr) {
    for (var i = 0; i < arr.length; i++) {
      if (arr[i] === item) return true;
    }
    return false;
  }

  var newArr = [];
  arr1.forEach(function (val) {
    if (!isExist(val, arr2)) newArr.push(val);
  });
  arr2.forEach(function (val) {
    if (!isExist(val, arr1)) newArr.push(val);
  });
  return newArr;
}

diffArray([1, 2, 3, 5], [1, 2, 3, 4, 5]);
```

Tham khảo:

- [Array.prototype.forEach()](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array/forEach)

## Intermediate Algorithm Scripting - Roman Numeral Converter

Convert số cho trước sang số La Mã.

```js
function convertToRoman(num) {
  var table = {
    1000: "M",
    900: "CM",
    500: "D",
    400: "CD",
    100: "C",
    90: "XC",
    50: "L",
    40: "XL",
    10: "X",
    9: "IX",
    5: "V",
    4: "IV",
    1: "I",
  };

  var keys = Object.keys(table).sort(function (a, b) {
    return b - a;
  });

  var ans = "";
  keys.forEach(function (key) {
    while (num >= key) {
      ans += table[key];
      num -= key;
    }
  });
  return ans;
}

convertToRoman(36);
```

Tham khảo:

- [Object.keys()](https://developer.mozilla.org/en/docs/Web/JavaScript/Reference/Global_Objects/Object/keys)
- [Array.prototype.sort()](https://developer.mozilla.org/en/docs/Web/JavaScript/Reference/Global_Objects/Array/sort)
- [Array.prototype.forEach()](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array/forEach)

## Intermediate Algorithm Scripting - Wherefore art thou

Duyệt mảng của các [object](/bai-viet/javascript/object-la-gi-object-trong-javascript) và trả về một mảng bao gồm các object chứa thuộc tính trùng khớp với thành phần cho trước.

```js
function whatIsInAName(collection, source) {
  var arr = [];
  collection.forEach(function (item) {
    for (var key in source) {
      if (!item.hasOwnProperty(key) || item[key] !== source[key]) return;
    }
    arr.push(item);
  });
  return arr;
}

whatIsInAName(
  [
    { first: "Romeo", last: "Montague" },
    { first: "Mercutio", last: null },
    { first: "Tybalt", last: "Capulet" },
  ],
  { last: "Capulet" }
);
```

Tham khảo:

- [Array.prototype.forEach()](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array/forEach)
- [Object.prototype.hasOwnProperty()](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Object/hasOwnProperty)
- [Array.prototype.push()](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array/push)

## Intermediate Algorithm Scripting - Search and Replace

Thực hiện tìm và thay thế trên một string sử dụng tham số cho trước, sau đó trả về một string mới.

```js
function myReplace(str, before, after) {
  var beforeFirst = before.charAt(0);
  var afterChars = after.split("");

  var answer = [];
  var words = str.split(" ");
  words.forEach(function (word) {
    if (word === before) {
      if (beforeFirst >= "A" && beforeFirst <= "Z") {
        afterChars[0] = afterChars[0].toUpperCase();
      } else if (beforeFirst >= "a" && beforeFirst <= "z") {
        afterChars[0] = afterChars[0].toLowerCase();
      }
      answer.push(afterChars.join(""));
    } else {
      answer.push(word);
    }
  });
  return answer.join(" ");
}

myReplace("A quick brown fox jumped over the lazy dog", "jumped", "leaped");
```

Tham khảo:

- [String.prototype.charAt()](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/String/charAt)
- [String.prototype.split()](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/String/split)
- [Array.prototype.join()](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array/join)
- [Array.prototype.push()](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array/push)
- [String.prototype.toUpperCase()](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/String/toUpperCase)
- [String.prototype.toLowerCase()](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/String/toLowerCase)

## Intermediate Algorithm Scripting - Pig Latin

Dịch string cho trước sang ngôn ngữ **Latin Lợn**.

```js
function translatePigLatin(str) {
  var firstVowel = str.search(/[ueoai]/);
  if (firstVowel > 0) {
    var firstConsonant = str.substr(0, firstVowel);
    var others = str.substr(firstVowel);
    return others + firstConsonant + "ay";
  }
  return str + "way";
}

translatePigLatin("consonant");
```

Tham khảo:

- [Tìm hiểu Regular Expression JavaScript](/bai-viet/javascript/tim-hieu-regex-javascript)
- [String.prototype.substr()](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/String/substr)

## Intermediate Algorithm Scripting - DNA Pairing

Các DNA đang thiếu các thành phần tương ứng. Hãy tìm các kí tự tương ứng với thành phần cho trước rồi trả về kết quả là một mảng 2 chiều.

```js
function pairElement(str) {
  var ans = [];
  str.split("").forEach(function (val) {
    var tmp = [val];
    switch (val) {
      case "A":
        tmp.push("T");
        break;
      case "T":
        tmp.push("A");
        break;
      case "G":
        tmp.push("C");
        break;
      case "C":
        tmp.push("G");
        break;
    }
    ans.push(tmp);
  });
  return ans;
}

pairElement("GCG");
```

Tham khảo:

- [Array.prototype.forEach()](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array/forEach)
- [Array.prototype.push()](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array/push)

## Intermediate Algorithm Scripting - Missing letters

Tìm kí tự thiếu ở một chuỗi các kí tự cho trước. Nếu tất cả các kí tự đầy đủ thì trả về **undefined**.

```js
function fearNotLetter(str) {
  for (var i = 1; i < str.length; i++) {
    var currCode = str.charCodeAt(i);
    var beforeCode = str.charCodeAt(i - 1);
    if (currCode > beforeCode + 1) return String.fromCharCode(beforeCode + 1);
  }
}

fearNotLetter("abce");
```

Tham khảo:

- [String.prototype.charCodeAt()](https://developer.mozilla.org/en/docs/Web/JavaScript/Reference/Global_Objects/String/charCodeAt)
- [String.fromCharCode()](https://developer.mozilla.org/en/docs/Web/JavaScript/Reference/Global_Objects/String/fromCharCode)

## Intermediate Algorithm Scripting - Boo who

Kiểm tra xem nếu một giá trị cho trước là kiểu boolean, rồi trả về kết quả là **true** hoặc **false**.

```js
function booWho(bool) {
  return typeof bool == "boolean";
}

booWho(null);
```

Tham khảo:

- [typeof](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Operators/typeof)

## Intermediate Algorithm Scripting - Sorted Union

Viết một [function](/bai-viet/javascript/ham-trong-javascript) nhận đầu vào là 2 hay nhiều array. Trả về một array mới bao gồm các phần tử duy nhất, theo đúng thứ tự ban đầu.

```js
function uniteUnique(arr) {
  var table = {};
  var ans = [];
  for (var i = 0; i < arguments.length; i++) {
    for (var j = 0; j < arguments[i].length; j++) {
      var val = arguments[i][j];
      if (table[val] == undefined) {
        ans.push(val);
        table[val] = 1;
      }
    }
  }
  return ans;
}

uniteUnique([1, 3, 2], [5, 2, 1, 4], [2, 1]);
```

Tham khảo:

- [Arguments object](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Functions/arguments)
- [Array.prototype.push()](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array/push)

## Intermediate Algorithm Scripting - Convert HTML Entities

Chuyển các kí tự &, <, >, " và ' ở một string cho trước sang dạng [HTML Entities](https://dev.w3.org/html5/html-author/charref).

```js
function convertHTML(str) {
  var table = {
    "&": "&amp;",
    "<": "&lt;",
    ">": "&gt;",
    '"': "&quot;",
    "'": "&apos;",
  };
  for (var key in table) {
    str = str.replace(RegExp(key, "g"), table[key]);
  }
  return str;
}

convertHTML("Hamburgers < Pizza < Tacos");
```

Tham khảo:

- [Tìm hiểu Regular Expression JavaScript](/bai-viet/javascript/tim-hieu-regex-javascript)
- [String.prototype.replace()](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/String/replace)

## Intermediate Algorithm Scripting - Spinal Tap Case

Convert một string sang dạng **spinal case** - bao gồm các chữ cái thường phân cách nhau bởi dấu -.

```js
function spinalCase(str) {
  var words = str.split(/[\s_-]/);
  words = words.map(function (word) {
    return word.replace(/[A-Z]/g, function (match, offset) {
      var lower = match.toLowerCase();
      return offset > 0 ? "-" + lower : lower;
    });
  });
  return words.join("-");
}

spinalCase("This Is Spinal Tap");
```

Tham khảo:

- [String.prototype.split()](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/String/split)
- [Array.prototype.map()](https://developer.mozilla.org/en/docs/Web/JavaScript/Reference/Global_Objects/Array/map)
- [String.prototype.replace()](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/String/replace)
- [String.prototype.toLowerCase()](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/String/toLowerCase)
- [Array.prototype.join()](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array/join)

## Intermediate Algorithm Scripting - Sum All Odd Fibonacci Numbers

Cho trước một số nguyên dương, tính tổng các số Fibonacci lẻ nhỏ hơn hoặc bằng số cho trước.

```js
function sumFibs(num) {
  if (num == 0 || num == 1) return 0;
  if (num == 2) return 2;

  var a = 1,
    b = 1,
    c = 0;
  var ans = 2;
  while (true) {
    c = b + a;

    if (c > num) break;
    if (c % 2) ans += c;

    a = b;
    b = c;
  }
  return ans;
}

sumFibs(75025);
```

## Intermediate Algorithm Scripting - Sum All Primes

Tính tổng các số nguyên tố nhỏ hơn hoặc bằng số cho trước.

```js
function sumPrimes(num) {
  function isPrime(val) {
    if (val == 0 || val == 1) return false;
    if (val == 2) return true;

    for (var i = 2; i * i <= val; i++) {
      if (val % i == 0) return false;
    }
    return true;
  }
  var sum = 0;
  for (var j = 0; j <= num; j++) {
    if (isPrime(j)) sum += j;
  }
  return sum;
}

sumPrimes(10);
```

## Intermediate Algorithm Scripting - Smallest Common Multiple

Tìm bội số chung nhỏ nhất của các số trong một khoảng cho trước.

```js
function smallestCommons(arr) {
  function isDivisibleBy(num, from, to) {
    for (var i = from; i <= to; i++) {
      if (num % i) return false;
    }
    return true;
  }

  var max = Math.max(arr[0], arr[1]);
  var min = Math.min(arr[0], arr[1]);
  var mul = max;
  while (true) {
    if (isDivisibleBy(mul, min, max)) break;
    else mul += max;
  }
  return mul;
}

smallestCommons([1, 5]);
```

Tham khảo:

- [Math.max()](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Math/max)
- [Math.min()](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Math/min)

## Intermediate Algorithm Scripting - Finders Keepers

Duyệt một mảng các số và tìm ra số đầu tiên thỏa mãn test.

```js
function findElement(arr, func) {
  for (var i = 0; i < arr.length; i++) {
    var val = arr[i];
    if (func(val)) return val;
  }
}

findElement([1, 3, 5, 8, 9, 10], function (num) {
  return num % 2 === 0;
});
```

## Intermediate Algorithm Scripting - Drop it

Bỏ đi các số của một mảng, từ trái sang phải, cho đến khi thỏa mãn test.

```js
function dropElements(arr, func) {
  while (arr.length > 0) {
    if (func(arr[0]) == false) arr.shift();
    else break;
  }
  return arr;
}

dropElements([1, 2, 3], function (n) {
  return n < 3;
});
```

Tham khảo:

- [Array.prototype.shift()](https://developer.mozilla.org/en/docs/Web/JavaScript/Reference/Global_Objects/Array/shift)

## Intermediate Algorithm Scripting - Steamroller

San phẳng (chuyển về mảng một chiều) một mảng nhiều chiều cho trước.

```js
function steamrollArray(arr) {
  var ans = [];
  for (var i = 0; i < arr.length; i++) {
    var item = arr[i];
    if (Array.isArray(item)) {
      ans = ans.concat(steamrollArray(item));
    } else {
      ans = ans.concat([item]);
    }
  }
  return ans;
}

steamrollArray([1]);
```

Tham khảo:

- [Array.isArray()](https://developer.mozilla.org/en/docs/Web/JavaScript/Reference/Global_Objects/Array/isArray)
- [Array.prototype.concat()](https://developer.mozilla.org/en/docs/Web/JavaScript/Reference/Global_Objects/Array/concat)

## Intermediate Algorithm Scripting - Binary Agents

Trả về một string bao gồm các kí tự tiếng anh từ chuỗi nhị phân cho trước.

```js
function binaryAgent(str) {
  function bin2Dec(bin) {
    var binArr = bin.split("");
    return binArr.reduce(function (acc, cur, index) {
      return acc * 2 + Number(cur);
    }, 0);
  }
  var arr = str.split(/\s+/).map(function (bin) {
    var dec = bin2Dec(bin);
    return String.fromCharCode(dec);
  });
  return arr.join("");
}

binaryAgent(
  "01000001 01110010 01100101 01101110 00100111 01110100 00100000 01100010 01101111 01101110 01100110 01101001 01110010 01100101 01110011 00100000 01100110 01110101 01101110 00100001 00111111"
);
```

Tham khảo:

- [String.prototype.split()](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/String/split)
- [Array.prototype.map()](https://developer.mozilla.org/en/docs/Web/JavaScript/Reference/Global_Objects/Array/map)
- [Array.prototype.join()](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array/join)
- [String.fromCharCode()](https://developer.mozilla.org/en/docs/Web/JavaScript/Reference/Global_Objects/String/fromCharCode)

## Intermediate Algorithm Scripting - Everything Be True

Kiểm tra xem tham số thứ 2 đưa vào hàm có tồn tại trong tất cả các phần tử thuộc tham số thứ nhất.

```js
function truthCheck(collection, pre) {
  for (var i = 0; i < collection.length; i++) {
    if (!collection[i].hasOwnProperty(pre) || !collection[i][pre]) return false;
  }
  return true;
}

truthCheck(
  [
    { user: "Tinky-Winky", sex: "male" },
    { user: "Dipsy", sex: "male" },
    { user: "Laa-Laa", sex: "female" },
    { user: "Po", sex: "female" },
  ],
  "sex"
);
```

Tham khảo:

- [Object.prototype.hasOwnProperty()](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Object/hasOwnProperty)

## Intermediate Algorithm Scripting - Arguments Optional

Viết một hàm số tính tổng 2 tham số. Nếu chỉ có một tham số được đưa vào thì trả về một function mới yêu cầu đưa vào một tham số, cuối cùng trả về kết quả tổng.

```js
function addTogether() {
  function isNumber(val) {
    if (typeof val === "number") return true;
    return false;
  }

  if (isNumber(arguments[0])) {
    if (isNumber(arguments[1])) return arguments[0] + arguments[1];
    if (arguments.length == 1) {
      var sum = arguments[0];
      return function () {
        if (isNumber(arguments[0])) return sum + arguments[0];
      };
    }
  }
}

addTogether(2, "3");
```

Tham khảo:

- [Tìm hiểu JavaScript Closures](/bai-viet/javascript/closure-trong-javascript)
- [Arguments object](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Functions/arguments)

## Kết luận

Trên đây là tổng hợp các bài toán thuộc chủ đề **Intermediate Algorithm Scripting** trên freeCodeCamp.

Nếu bạn có gì thắc mắc, góp ý hay cải tiến các thuật toán trên. Vui lòng để lại bình luận phía dưới nhé.

Xin chào và hẹn gặp lại bạn trong bài viết tiếp theo, thân ái!
