---
title: "Sắp xếp mảng trong Javascript"
description: "Bạn có thể tự do sắp xếp phần tử trong mảng JavaScript theo thứ tự tăng dần, giảm dần hoặc là theo một điều kiện tuỳ ý. Hãy tìm hiểu cách sắp xếp phần tử trong mảng JavaScript bằng phương thức sort() thông qua bài học này nhé."
keywords: [
"Sắp xếp mảng trong Javascript",
"sap xep mang tang dan trong javascript",
"sap xep mang giam dan trong javascript",
"thuat toan sap xep trong javascript",
"sap xep mang object trong javascript",
"Sắp xếp mảng đối tượng trong JavaScript",
"Sort array object JavaScript",
"cach su dung ham sap xep trong javascript",
"sap xep mang trong javascript là gì",
"sap xep mang trong javascript nhu the nao",
"sap xep mang trong javascript nhanh"
]
chapter:
  name: "Kiểu dữ liệu trong Javascript"
  slug: "chuong-04-kieu-du-lieu-trong-javascript"
category:
  name: "Javascript"
  slug: "javascript"
image: https://user-images.githubusercontent.com/29374426/168242982-85255f57-649f-4ce2-9d8f-b18e7000d66d.png
position: 8
---

Bài viết sau đây tập trung tìm hiểu về **phương thức sắp xếp mảng trong JavaScript**. Và cách triển khai một số **thuật toán sắp xếp mảng cơ bản**.

![Sắp xếp mảng trong Javascript](https://user-images.githubusercontent.com/29374426/168242982-85255f57-649f-4ce2-9d8f-b18e7000d66d.png)


Nói về sắp xếp mảng thì đây là một vấn đề vô cùng phổ biến trong các chương trình. Nhiều ứng dụng (từ điển, danh bạ, quản lý tài khoản,...) thường có chức năng sắp xếp theo thứ tự từ điển (a-z). Việc sắp xếp giúp người quản lý và người dùng dễ dàng tìm kiếm nội dung hơn.

<content-info>

Hiện tại có rất nhiều thuật toán sắp xếp với độ phức tạp khác nhau. Ví dụ các thuật toán sắp xếp mảng là: selection sort, insertion sort, binary insertion sort, interchange sort, bubble sort, shaker sort, quick sort, merge sort, heap sort,...

</content-info>

Bạn không cần thiết phải viết lại lại những thuật toán sắp xếp này. Vì JavaScript hỗ trợ sẵn một [function](/bai-viet/javascript/ham-trong-javascript) để sắp xếp.

## Cú pháp hàm sắp xếp mảng trong JavaScript

Hàm sắp xếp mảng trong JavaScript là `sort()`:

```js
arr.sort();
arr.sort(compareFunction);
```

► Tham số `compareFunction`:

- Dùng để xác định thứ tự sắp xếp.
- Nếu bạn bỏ qua tham số này, mặc định JavaScript sẽ sắp xếp mảng theo thứ tự tăng dần trong bảng mã Unicode (hay đơn giản là thứ tự tăng dần bảng chữ cái).

► Giá trị trả về:

- Là mảng đã được sắp xếp.
- Mảng ban đầu có bị thay đổi.

```js
let a = ["c", "g", "w", "a"];
let b = a.sort();

console.log(a); // ["a", "c", "g", "w"]
console.log(b); // ["a", "c", "g", "w"]
```

## Tìm hiểu compareFunction

Hàm `compareFunction` dùng để xác định **thứ tự sắp xếp mảng**.

Giả sử, `a` và `b` là hai phần tử dùng để so sánh:

- Nếu hàm `compareFunction(a, b)` trả về giá trị nhỏ hơn `0` thì `a` sẽ đứng trước `b`.
- Nếu hàm `compareFunction(a, b)` trả về giá trị lớn hơn `0` thì `a` sẽ đứng sau `b`.
- Nếu hàm `compareFunction(a, b)` trả về giá trị bằng `0` thì giữ nguyên thứ tự `a`, `b`.

## Sắp xếp mảng number

JavaScript hỗ trợ **sắp xếp nhiều kiểu dữ liệu**. Tuy nhiên, phổ biến nhất vẫn là [numbers](/bai-viet/javascript/kieu-du-lieu-number-trong-javascript).

Và như mình đã nói ở trên, mặc định hàm `sort()` sẽ so sánh theo kiểu string để sắp xếp. Do đó, kết quả sẽ như sau:

```js
let a = [9, 100, 45, 33];

console.log(a.sort());
// [100, 33, 45, 9]
```

Kết quả trên là **hoàn toàn chính xác**. Vì khi so sánh theo kiểu string thì thứ tự là: `'1' < '3' < '4' < '9'`.

Vì vậy, để sắp xếp chúng theo kiểu **numbers** thì bạn cần phải sử dụng hàm `compareFunction`.

### Sử dụng hàm `compareNumbers` sắp xếp theo thứ tự tăng dần

```js
function compareNumbers(a, b) {
  return a - b;
}

let a = [9, 100, 45, 33];
console.log(a.sort(compareNumbers));
// [9, 33, 45, 100]
```

Khi `a` nhỏ hơn `b` thì `a - b < 0` là `true`. Theo đúng mô tả của hàm `compareFunction` thì suy ra `a` sẽ đứng trước `b`.

Nghĩa là số nhỏ hơn sẽ đứng trước. Áp dụng quy tắc này, ta được mảng các số **sắp xếp theo thứ tự tăng dần**.

Ngoài cách viết **hàm độc lập** như trên, bạn có thể áp dụng [arrow function](/bai-viet/javascript/arrow-function-trong-javascript) cho ngắn gọn:

```js
let a = [9, 100, 45, 33];

a.sort((a, b) => a - b);

console.log(a);
// [9, 33, 45, 100]
```

### Sắp xếp mảng numbers theo thứ tự giảm dần

Để sắp xếp mảng numbers **theo thứ tự giảm dần**, bạn chỉ cần thay đổi nội dung hàm `compareNumbers`. Thay vì trả về `a - b` thì bây giờ trả về `b - a`.

```js
let a = [9, 100, 45, 33];

a.sort((a, b) => b - a);
console.log(a);
// [100, 45, 33, 9]
```

Bây giờ, khi `a` nhỏ hơn `b` thì `b - a > 0`. Suy ra, `a` sẽ đứng sau `b`. Nói cách khác, số nhỏ hơn sẽ đứng sau. Do đó, kết quả thu được là **dãy số giảm dần** như trên.

Trên đây là cách sử dụng hàm `sort()` để sắp xếp mảng trong JavaScript.

Nhưng nếu bạn không muốn sử dụng hàm mặc định này, bạn vẫn có thể tự viết lại hàm sắp xếp sử dụng một số thuật toán sắp xếp cơ bản.

## Sắp xếp mảng trong JavaScript sử dụng thuật toán

Nếu bạn từng học ít nhất một ngôn ngữ lập trình như C/C++, Java,... thì mình dám chắc là bạn đã **từng triển khai thuật toán sắp xếp** rồi.

Một số thuật toán cơ bản như:

- Thuật toán sắp xếp chọn trực tiếp - Selection Sort
- Sắp xếp chèn trực tiếp - Insertion Sort
- Sắp xếp chèn trực tiếp dựa trên tìm kiếm nhị phân - Binary Insertion Sort
- Thuật toán sắp xếp đổi chỗ trực tiếp - Interchange Sort
- Sắp xếp nổi bọt - Bubble Sort
- Thuật toán Shaker Sort
- Sắp xếp nhanh - Quick Sort
- Sắp xếp trộn - Merge Sort
- Sắp xếp vun đống - Heap Sort

Sau đây, mình chia sẻ cách triển khai các thuật toán sắp xếp mảng trong JavaScript.

### Array sorting với sắp xếp chọn trực tiếp - Selection Sort

```js
function selectionSort(array) {
  for (let i = 0; i < array.length - 1; i++) {
    let idmin = i;
    for (let j = i + 1; j < array.length; j++) {
      if (array[j] < array[idmin]) idmin = j;
    }

    // swap
    let t = array[i];
    array[i] = array[idmin];
    array[idmin] = t;
  }
}
```

### Sắp xếp chèn trực tiếp - Insertion Sort

```js
function insertionSort(array) {
  let pos, x;
  for (let i = 1; i < array.length; i++) {
    pos = i - 1;
    x = array[i];
    while (pos >= 0 && array[pos] > x) {
      array[pos + 1] = array[pos];
      pos--;
    }
    array[pos + 1] = x;
  }
}
```

### Sắp xếp chèn trực tiếp dựa trên tìm kiếm nhị phân - Binary Insertion Sort

```js
function binaryInsertionSort(array) {
  let l, r, m, x;
  for (let i = 1; i < array.length; i++) {
    l = 0;
    r = i - 1;
    x = array[i];

    while (l <= r) {
      m = Math.floor((l + r) / 2);
      if (array[m] > x) r = m - 1;
      else l = m + 1;
    }

    for (let j = i; j > l; j--) array[j] = array[j - 1];
    array[l] = x;
  }
}
```

### Sắp xếp đổi chỗ trực tiếp - Interchange Sort

```js
function interChangeSort(array) {
  for (let i = 0; i < array.length - 1; i++) {
    for (let j = i + 1; j < array.length; j++) {
      if (array[j] < array[i]) {
        let t = array[i];
        array[i] = array[j];
        array[j] = t;
      }
    }
  }
}
```

### Sắp xếp nổi bọt - Bubble Sort

```js
function bubbleSort(array) {
  for (let i = 0; i < array.length - 1; i++) {
    for (let j = array.length - 1; j > i; j--) {
      if (array[j] < array[j - 1]) {
        let t = array[j];
        array[j] = array[j - 1];
        array[j - 1] = t;
      }
    }
  }
}
```

### Thuật toán Shaker Sort

```js
function shakerSort(array) {
  let left, right, k;

  left = 0;
  right = array.length - 1;
  k = array.length - 1;

  while (left < right) {
    for (let j = right; j > left; j--) {
      if (array[j] < array[j - 1]) {
        let t = array[j];
        array[j] = array[j - 1];
        array[j - 1] = t;
        k = j;
      }
    }
    left = k;

    for (let j = left; j < right; j++) {
      if (array[j] > array[j + 1]) {
        let t = array[j];
        array[j] = array[j + 1];
        array[j + 1] = t;
        k = j;
      }
    }
    right = k;
  }
}
```

### Sắp xếp nhanh - Quick Sort

```js
function quickSort(array, left, right) {
  let l = left,
    r = right;
  let m = Math.floor((l + r) / 2);
  let pivot = array[m];

  while (l <= r) {
    while (array[l] < pivot) l++;
    while (array[r] > pivot) r--;
    if (l <= r) {
      let t = array[l];
      array[l] = array[r];
      array[r] = t;
      l++;
      r--;
    }
  }

  if (l < right) quickSort(array, l, right);
  if (r > left) quickSort(array, left, r);
}
```

### Sắp xếp trộn - Merge Sort

```js
function merge(array, left, m, right) {
  let l = left,
    r = m + 1;
  let tmp = [];

  while (l <= m && r <= right) {
    if (array[l] < array[r]) tmp.push(array[l++]);
    else tmp.push(array[r++]);
  }

  while (l <= m) tmp.push(array[l++]);
  while (r <= right) tmp.push(array[r++]);

  for (let i = 0; i < tmp.length; i++) array[i + left] = tmp[i];
}

function mergeSort(array, left, right) {
  if (left < right) {
    let m = Math.floor((left + right) / 2);
    mergeSort(array, left, m);
    mergeSort(array, m + 1, right);
    merge(array, left, m, right);
  }
}
```

### Sắp xếp vun đống - Heap Sort

```js
function heapify(array, N, i) {
  let left = 2 * i + 1,
    right = 2 * i + 2,
    largest;

  if (left < N && array[left] > array[i]) largest = left;
  else largest = i;

  if (right < N && array[right] > array[largest]) largest = right;

  if (largest != i) {
    let t = array[i];
    array[i] = array[largest];
    array[largest] = t;
    heapify(array, N, largest);
  }
}

function buildHeap(array) {
  let m = Math.floor(array.length / 2 - 1);
  for (let i = m; i >= 0; i--) heapify(array, array.length, i);
}

function heapSort(array) {
  buildHeap(array);

  for (let i = array.length - 1; i >= 0; i--) {
    let t = array[0];
    array[0] = array[i];
    array[i] = t;

    heapify(array, i, 0);
  }
}
```

Trên đây là những vấn đề cơ bản về sắp xếp mảng trong JavaScript, cùng với một số thuật toán sắp xếp mảng 1 chiều. Theo mình, đây là những kiến thức cơ bản và có thể được áp dụng rất nhiều.
