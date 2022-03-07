---
title: "LinkedHashMap trong Java"
description: "LinkedHashMap trong Java là một lớp triển khai interface (giao diện) Map trong Java, LinkedHashMap cho phép chúng ta gán value (giá trị) cho một key (khóa)"
keywords:
  [
    "LinkedHashMap trong Java",
    "Tạo một LinkedHashMap trong Java",
    "Tạo LinkedHashMap từ các Map khác",
    "Chèn các phần tử vào LinkedHashMap",
    "Truy cập các phần tử LinkedHashMap",
    "Xóa các phần tử khỏi LinkedHashMap",
    "Các hàm khác của LinkedHashMap",
  ]
chapter:
  name: "Java collections"
  slug: "chuong-04-java-collections"
category:
  logo: "/language/java.png"
  name: "Java"
  slug: "java"
  description: "Học Java từ cơ bản đến thông thạo cho mọi đối tượng"
image: https://user-images.githubusercontent.com/29374426/145676841-ec321d4f-eb6d-46aa-b451-8a2cf775c9d9.png
position: 12
---

## LinkedHashMap trong Java là gì?

Giống như `HashMap`, `LinkedHashMap` trong Java là một lớp triển khai interface (giao diện) Map trong Java, `LinkedHashMap` cho phép chúng ta gán `value (giá trị)` cho một `key (khóa)`.

![LinkedHashMap trong Java là gì](https://user-images.githubusercontent.com/29374426/145676841-ec321d4f-eb6d-46aa-b451-8a2cf775c9d9.png)

Những điểm quan trọng về lớp `LinkedHashMap` trong java cần nhớ là:

- `LinkedHashMap` lưu trữ dữ liệu dưới dạng cặp `key` và `value`.
- `LinkedHashMap` chỉ chứa các `key` duy nhất.
- `LinkedHashMap` có thể có 1 `key` là `null` và nhiều giá trị `null`.
- `LinkedHashMap` duy trì các phần tử theo thứ tự chèn.

## Tạo một LinkedHashMap trong Java

Để tạo một `LinkedHashMap`, trước hết ta cần import gói `java.util.LinkedHashMap`. Khi `import` xong, chúng ta có thể tạo các `LinkedHashMap` trong Java theo cách sau:

```java
// LinkedHashMap with initial capacity 8 and load factor 0.6
LinkedHashMap<Key, Value> numbers = new LinkedHashMap<>(8, 0.6f);
```

Trong đoạn code trên, chúng ta đã tạo ra một `LinkedHashMap` có tên là `numbers`.

- `Key` - một mã định danh duy nhất được sử dụng để liên kết từng phần tử(giá trị) trong map
- `Value` - các phần tử được liên kết bởi các key trong map

Chú ý phần `new LinkedHashMap<>(8, 0.6)`, tham số đầu tiên là `capacity` và tham số thứ hai là `loadFactor`.

- `capacity` là dung lượng của linked hashmap này là `8`. Ý nghĩa nó có thể lưu trữ 8 mục.
- `loadFactor` là hệ số tải của `LinkedHashMap` này là `0,6`. Điều này có nghĩa là, bất cứ khi nào `HashMap` của chúng ta được lấp đầy `60%`, các mục nhập vào sau đó sẽ được chuyển sang hash table mới có kích thước gấp đôi `hash table` ban đầu.

## Tạo LinkedHashMap từ các Map khác

Sau đây là cách chúng ta có thể tạo một `LinkedHashMap` có chứa tất cả các phần tử của các map khác.

<div class="example"></div>

```java
import java.util.LinkedHashMap;

class Main {
    public static void main(String[] args) {
        // Creating a LinkedHashMap of even numbers
        LinkedHashMap<String, Integer> evenNumbers = new LinkedHashMap<>();
        evenNumbers.put("Two", 2);
        evenNumbers.put("Four", 4);
        System.out.println("LinkedHashMap1: " + evenNumbers);

        // Creating a LinkedHashMap from other LinkedHashMap
        LinkedHashMap<String, Integer> numbers = new LinkedHashMap<>(evenNumbers);
        numbers.put("Three", 3);
        System.out.println("LinkedHashMap2: " + numbers);
    }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>LinkedHashMap1: {Two=2, Four=4}</code><br/>
    <code>LinkedHashMap2: {Two=2, Four=4, Three=3}</code>
  </div>
</div>

## Chèn các phần tử vào LinkedHashMap

- `put()` – chèn key/ value được chỉ định vào map
- `putAll()` – chèn tất cả các mục từ map được chỉ định vào map này
- `putIfAbsent()` – chèn `key/value` được chỉ định vào map nếu key được chỉ định không có trong map

<div class="example"></div>

```java
import java.util.LinkedHashMap;

class Main {
    public static void main(String[] args) {
        // Creating LinkedHashMap of even numbers
        LinkedHashMap<String, Integer> evenNumbers = new LinkedHashMap<>();

        // Using put()
        evenNumbers.put("Two", 2);
        evenNumbers.put("Four", 4);
        System.out.println("Original LinkedHashMap: " + evenNumbers);

        // Using putIfAbsent()
        evenNumbers.putIfAbsent("Six", 6);
        System.out.println("Updated LinkedHashMap(): " + evenNumbers);

        //Creating LinkedHashMap of numbers
        LinkedHashMap<String, Integer> numbers = new LinkedHashMap<>();
        numbers.put("One", 1);

        // Using putAll()
        numbers.putAll(evenNumbers);
        System.out.println("New LinkedHashMap: " + numbers);
    }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>Original LinkedHashMap: {Two=2, Four=4}</code><br/>
    <code>Updated LinkedHashMap: {Two=2, Four=4, Six=6}</code><br/>
    <code>New LinkedHashMap: {One=1, Two=2, Four=4, Six=6}</code>
  </div>
</div>

## Truy cập các phần tử LinkedHashMap

- `entrySet()` – trả về một tập hợp tất cả key/ value của map
- `keySet()` – trả về một tập hợp tất cả các key của map
- `values()` – trả về một tập hợp tất cả các value của map

<div class="example"></div>

```java
import java.util.LinkedHashMap;

class Main {
    public static void main(String[] args) {
        LinkedHashMap<String, Integer> numbers = new LinkedHashMap<>();

        numbers.put("One", 1);
        numbers.put("Two", 2);
        numbers.put("Three", 3);
        System.out.println("LinkedHashMap: " + numbers);

        // Using entrySet()
        System.out.println("Key/Value mappings: " + numbers.entrySet());

        // Using keySet()
        System.out.println("Keys: " + numbers.keySet());

        // Using values()
        System.out.println("Values: " + numbers.values());
    }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>LinkedHashMap: {One=1, Two=2, Three=3}</code><br/>
    <code>Key/Value mappings: [One=1, Two=2, Three=3]</code><br/>
    <code>Keys: [One, Two, Three]</code><br/>
    <code>Values: [1, 2, 3]</code>
  </div>
</div>

- `get()` - Trả về value liên kết với key được chỉ định. Nếu không tìm thấy key, nó sẽ trả về null.
- `getOrDefault()` - Trả về value liên quan đến key được chỉ định. Nếu không tìm thấy key, nó sẽ trả về value mặc định đã chỉ định.

<div class="example"></div>

```java
import java.util.LinkedHashMap;

class Main {
    public static void main(String[] args) {

        LinkedHashMap<String, Integer> numbers = new LinkedHashMap<>();
        numbers.put("One", 1);
        numbers.put("Two", 2);
        numbers.put("Three", 3);
        System.out.println("LinkedHashMap: " + numbers);

        // Using get()
        int value1 = numbers.get("Three");
        System.out.println("Returned Number: " + value1);

        // Using getOrDefault()
        int value2 = numbers.getOrDefault("Five", 5);
        System.out.println("Returned Number: " + value2);
    }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>LinkedHashMap: {One=1, Two=2, Three=3}</code><br/>
    <code>Returned Number: 3</code><br/>
    <code>Returned Number: 5</code>
  </div>
</div>

## Xóa các phần tử khỏi LinkedHashMap

- `remove(key)` – trả về và xóa mục liên quan đến key chỉ định từ map
- `remove(key, value)` – chỉ xóa mục khỏi map nếu key được chỉ định liên kết với `value` được chỉ định và trả về giá trị `boolean`

<div class="example"></div>

```java
import java.util.LinkedHashMap;

class Main {
    public static void main(String[] args) {

        LinkedHashMap<String, Integer> numbers = new LinkedHashMap<>();
        numbers.put("One", 1);
        numbers.put("Two", 2);
        numbers.put("Three", 3);
        System.out.println("LinkedHashMap: " + numbers);

        // remove method with single parameter
        int value = numbers.remove("Two");
        System.out.println("Removed value: " + value);

        // remove method with two parameters
        boolean result = numbers.remove("Three", 3);
        System.out.println("Is the entry Three removed? " + result);

        System.out.println("Updated LinkedHashMap: " + numbers);
    }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>LinkedHashMap: {One=1, Two=2, Three=3}</code><br/>
    <code>Removed value: 2</code><br/>
    <code>Is the entry {Three=3} removed? True</code><br/>
    <code>Updated LinkedHashMap: {One=1}</code>
  </div>
</div>

## Các hàm khác của LinkedHashMap

| Hàm | Sự miêu tả |
| --- | --- |
| `clear()` | xóa tất cả các mục khỏi map |
| `containsKey()` | kiểm tra xem map có chứa key được chỉ định hay không và trả về giá trị boolean |
| `containsValue()` | kiểm tra xem map có chứa value được chỉ định hay không và trả về giá trị boolean |
| `size() ` | trả về kích thước của map |
| `isEmpty()` | kiểm tra xem map có trống không và trả về giá trị boolean |

## So sánh LinkedHashMap với HashMap

Cả `LinkedHashMap` và `HashMap` đều triển khai giao diện Map. Tuy nhiên, có một số khác biệt giữa chúng.

- `LinkedHashMap` duy trì một danh sách liên kết đôi trong nội bộ. Do đó, nó bảo toàn thứ tự được chèn vào của các phần tử của nó.
- `Class LinkedHashMap` tốn nhiều vùng lưu trữ hơn `HashMap`. Đó là do `LinkedHashMap` duy trì `LinkedList` trong nội bộ.
- Hiệu suất của `LinkedHashMap` chậm hơn `HashMap`.
