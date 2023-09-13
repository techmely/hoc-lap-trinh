---
title: "LinkedHashMap trong Java"
description: "LinkedHashMap trong Java là một lớp triển khai interface (giao diện) Map trong Java, LinkedHashMap cho phép chúng ta gán value (giá trị) cho một key (khóa)"
chapter:
  name: "Java collections"
  slug: "chuong-04-java-collections"
category:
  name: "Java"
  slug: "java"
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

::result

LinkedHashMap1: {Two=2, Four=4}<br/>
LinkedHashMap2: {Two=2, Four=4, Three=3}

::

## Chèn các phần tử vào LinkedHashMap

- `put()` – chèn key/ value được chỉ định vào map
- `putAll()` – chèn tất cả các mục từ map được chỉ định vào map này
- `putIfAbsent()` – chèn `key/value` được chỉ định vào map nếu key được chỉ định không có trong map

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

::result

Original LinkedHashMap: {Two=2, Four=4}<br/>
Updated LinkedHashMap: {Two=2, Four=4, Six=6}<br/>
New LinkedHashMap: {One=1, Two=2, Four=4, Six=6}

::

## Truy cập các phần tử LinkedHashMap

- `entrySet()` – trả về một tập hợp tất cả key/ value của map
- `keySet()` – trả về một tập hợp tất cả các key của map
- `values()` – trả về một tập hợp tất cả các value của map

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

::result

LinkedHashMap: {One=1, Two=2, Three=3}<br/>
Key/Value mappings: [One=1, Two=2, Three=3]<br/>
Keys: [One, Two, Three]<br/>
Values: [1, 2, 3]

::

- `get()` - Trả về value liên kết với key được chỉ định. Nếu không tìm thấy key, nó sẽ trả về null.
- `getOrDefault()` - Trả về value liên quan đến key được chỉ định. Nếu không tìm thấy key, nó sẽ trả về value mặc định đã chỉ định.

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

::result

LinkedHashMap: {One=1, Two=2, Three=3}<br/>
Returned Number: 3<br/>
Returned Number: 5

::

## Xóa các phần tử khỏi LinkedHashMap

- `remove(key)` – trả về và xóa mục liên quan đến key chỉ định từ map
- `remove(key, value)` – chỉ xóa mục khỏi map nếu key được chỉ định liên kết với `value` được chỉ định và trả về giá trị `boolean`

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

::result

LinkedHashMap: {One=1, Two=2, Three=3}<br/>
Removed value: 2<br/>
Is the entry {Three=3} removed? True<br/>
Updated LinkedHashMap: {One=1}

::

## Các hàm khác của LinkedHashMap

| Hàm               | Sự miêu tả                                                                       |
| ----------------- | -------------------------------------------------------------------------------- |
| `clear()`         | xóa tất cả các mục khỏi map                                                      |
| `containsKey()`   | kiểm tra xem map có chứa key được chỉ định hay không và trả về giá trị boolean   |
| `containsValue()` | kiểm tra xem map có chứa value được chỉ định hay không và trả về giá trị boolean |
| `size() `         | trả về kích thước của map                                                        |
| `isEmpty()`       | kiểm tra xem map có trống không và trả về giá trị boolean                        |

## So sánh LinkedHashMap với HashMap

Cả `LinkedHashMap` và `HashMap` đều triển khai giao diện Map. Tuy nhiên, có một số khác biệt giữa chúng.

- `LinkedHashMap` duy trì một danh sách liên kết đôi trong nội bộ. Do đó, nó bảo toàn thứ tự được chèn vào của các phần tử của nó.
- `Class LinkedHashMap` tốn nhiều vùng lưu trữ hơn `HashMap`. Đó là do `LinkedHashMap` duy trì `LinkedList` trong nội bộ.
- Hiệu suất của `LinkedHashMap` chậm hơn `HashMap`.
