---
title: "TreeMap trong Java"
description: "Lớp TreeMap trong java là một lớp kế thừa lớp AbstractMap và triển khai của NavigableMap Interface (NavigableMap kế thừa SortedMap, SortedMap kế thừa Map interface). Trong Collections Framework nên nó sẽ có một vài đặc điểm và phương thức tương đồng với Map và SortedMap và NavigableMap. TreeMap được sử dụng để lưu trữ các phần tử dưới dạng key/value. Key và value là kiểu dữ liệu bất kỳ, và bạn có thể try cập các giá trị của HasMap bằng một key cụ thể."
chapter:
  name: "Java collections"
  slug: "chuong-04-java-collections"
category:
  name: "Java"
  slug: "java"
image: https://user-images.githubusercontent.com/29374426/145682018-69cc074d-31ed-4950-a72d-1bad074b889f.png
position: 13
---

## TreeMap trong Java là gì?

Lớp TreeMap trong java là một lớp kế thừa lớp `AbstractMap` và triển khai của `NavigableMap Interface` (NavigableMap kế thừa SortedMap, SortedMap kế thừa Map interface). Trong Collections Framework nên nó sẽ có một vài đặc điểm và phương thức tương đồng với `Map` và `SortedMap` và `NavigableMap`. `TreeMap` được sử dụng để lưu trữ các phần tử dưới dạng "key/value". Key và value là kiểu dữ liệu bất kỳ, và bạn có thể try cập các giá trị của `HasMap` bằng một key cụ thể.

![TreeMap trong Java](https://user-images.githubusercontent.com/29374426/145682018-69cc074d-31ed-4950-a72d-1bad074b889f.png)

Những điểm quan trọng về lớp TreeMap trong java cần nhớ là:

- `TreeMap` lưu trữ dữ liệu dưới dạng cặp `key` và `value`.
- `TreeMap` chỉ chứa các key duy nhất.
- `TreeMap` KHÔNG cho phép bất kỳ key nào là `null` và nhưng có thể có nhiều giá trị `null`.
- `TreeMap` duy trì các phần tử được thêm vào theo thứ tự key tăng dần.

## Tạo một TreeMap trong Java

Để tạo một `TreeMap`, chúng ta phải `import java.util.TreeMap` gói đầu tiên. Khi đã `import` xong, chúng ta có thể tạo `TreeMap` trong Java theo cách dưới đây.

```java
TreeMap<Key, Value> numbers = new TreeMap<>();
```

Trong đoạn code trên, chúng ta đã tạo ra một TreeMap tên là numbers mà không có argument. Trong trường hợp này, các phần tử trong `TreeMap` được sắp xếp một cách tự nhiên (thứ tự tăng dần). Tuy nhiên, chúng ta có thể tùy chỉnh việc sắp xếp các phần tử bằng cách sử dụng `Comparator Interface`. Chúng ta sẽ tìm hiểu về nó sau trong bài này.

- `key` là một code định danh duy nhất được sử dụng để liên kết từng phần tử (value) trong map
- `value` là các phần tử được liên kết bởi các key trong một `map`

## Chèn các phần tử vào TreeMap

- `put()` – chèn cặp key / value được chỉ định (mục nhập) vào map
- `putAll()` – chèn tất cả các mục từ map được chỉ định vào map này
- `putIfAbsent()` – chèn cặp `key/value` được chỉ định vào map nếu key được chỉ định không có trong map

```java
import java.util.TreeMap;

class Main {
    public static void main(String[] args) {
        // Creating TreeMap of even numbers
        TreeMap<String, Integer> evenNumbers = new TreeMap<>();

        // Using put()
        evenNumbers.put("Two", 2);
        evenNumbers.put("Four", 4);

        // Using putIfAbsent()
        evenNumbers.putIfAbsent("Six", 6);
        System.out.println("TreeMap of even numbers: " + evenNumbers);

        //Creating TreeMap of numbers
        TreeMap<String, Integer> numbers = new TreeMap<>();
        numbers.put("One", 1);

        // Using putAll()
        numbers.putAll(evenNumbers);
        System.out.println("TreeMap of numbers: " + numbers);
    }
}
```

::result

TreeMap of even numbers: {Four=4, Six=6, Two=2}</code><br/>
TreeMap of numbers: {Four=4, One=1, Six=6, Two=2}</code>

::

## Lấy các phần tử trong TreeMap

- `entrySet()` – trả về tập hợp gồm tất cả cặp `key/value` (mục nhập) của treemap
- `keySet()` – trả về tập hợp gồm tất cả các key của `TreeMap`
- `values()` – trả về một tập hợp gồm tất cả các map của `TreeMap`

```java
import java.util.TreeMap;

class Main {
    public static void main(String[] args) {
        TreeMap<String, Integer> numbers = new TreeMap<>();

        numbers.put("One", 1);
        numbers.put("Two", 2);
        numbers.put("Three", 3);
        System.out.println("TreeMap: " + numbers);

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

TreeMap: {One=1, Three=3, Two=2}</code><br/>
Key/Value mappings: [One=1, Three=3, Two=2]</code><br/>
Keys: [One, Three, Two]</code><br/>
Values: [1, 3, 2]</code>

::

- `get()` - Trả về value liên kết với key được chỉ định. Trả về null nếu không tìm thấy key.
- `getOrDefault()` - Trả về value liên kết vớikey được chỉ định. Trả về value mặc định đã chỉ định nếu không tìm thấy key.

```java
import java.util.TreeMap;

class Main {
    public static void main(String[] args) {

        TreeMap<String, Integer> numbers = new TreeMap<>();
        numbers.put("One", 1);
        numbers.put("Two", 2);
        numbers.put("Three", 3);
        System.out.println("TreeMap: " + numbers);

        // Using get()
        int value1 = numbers.get("Three");
        System.out.println("Using get(): " + value1);

        // Using getOrDefault()
        int value2 = numbers.getOrDefault("Five", 5);
        System.out.println("Using getOrDefault(): " + value2);
    }
}
```

::result

TreeMap: {One=1, Three=3, Two=2}</code><br/>
Using get(): 3</code><br/>
Using getOrDefault(): 5</code>

::

## Xóa các phần tử khỏi TreeMap

- `remove(key)` – trả về và xóa mục nhập được liên kết với key đã chỉ định khỏi TreeMap
- `remove(key, value)` – chỉ xóa mục nhập khỏi map nếu key được chỉ định liên kết với value được chỉ định và trả về giá trị boolean

```java
import java.util.TreeMap;

class Main {
    public static void main(String[] args) {

        TreeMap<String, Integer> numbers = new TreeMap<>();
        numbers.put("One", 1);
        numbers.put("Two", 2);
        numbers.put("Three", 3);
        System.out.println("TreeMap: " + numbers);

        // remove method with single parameter
        int value = numbers.remove("Two");
        System.out.println("Removed value: " + value);

        // remove method with two parameters
        boolean result = numbers.remove("Three", 3);
        System.out.println("Is the entry {Three=3} removed? " + result);

        System.out.println("Updated TreeMap: " + numbers);
    }
}
```

::result

TreeMap: {One=1, Three=3, Two=2}</code><br/>
Removed value = 2</code><br/>
Is the entry {Three=3} removed? True</code><br/>
Updated TreeMap: {One=1}</code>

::

## Thay thế các phần tử trong TreeMap

- `replace(key, value)` – thay thế value liên kết với key được chỉ định với value mới
- `replace(key, old, new)` – chỉ thay thế value cũ bằng value mới nếu value cũ được liên kết với key đã chỉ định
- `replaceAll(function)` – thay thế từng value của map bằng kết quả của một chức năng đã được chỉ định

```java
import java.util.TreeMap;

class Main {
    public static void main(String[] args) {

        TreeMap<String, Integer> numbers = new TreeMap<>();
        numbers.put("First", 1);
        numbers.put("Second", 2);
        numbers.put("Third", 3);
        System.out.println("Original TreeMap: " + numbers);

        // Using replace()
        numbers.replace("Second", 22);
        numbers.replace("Third", 3, 33);
        System.out.println("TreeMap using replace: " + numbers);

        // Using replaceAll()
        numbers.replaceAll((key, oldValue) -> oldValue + 2);
        System.out.println("TreeMap using replaceAll: " + numbers);
    }
}
```

::result

Original TreeMap: {First=1, Second=2, Third=3}</code><br/>
TreeMap using replace(): {First=1, Second=22, Third=33}</code><br/>
TreeMap using replaceAll(): {First=3, Second=24, Third=35}</code>

::

Trong chương trình trên, chú ý câu lệnh:

```java
numbers.replaceAll((key, oldValue) -> oldValue + 2);
```

Ở đây, chúng ta đã thông qua một biểu thức lambda như là một đối số. Hàm `replaceAll()` truy cập tất cả các mục của map. Sau đó, nó thay thế tất cả các phần tử bằng các `value` mới (được trả về từ biểu thức lambda).

## Các hàm điều hướng trong TreeMap

- `firstKey()` – trả về key đầu tiên của map
- `firstEntry()` – trả về cặp key / value trong key đầu tiên của map
- `lastKey()` – trả về key cuối cùng của map
- `lastEntry()` – trả về cặp key / value trong key cuối cùng của map

```java
import java.util.TreeMap;

class Main {
    public static void main(String[] args) {
        TreeMap<String, Integer> numbers = new TreeMap<>();
        numbers.put("First", 1);
        numbers.put("Second", 2);
        numbers.put("Third", 3);
        System.out.println("TreeMap: " + numbers);

        // Using the firstKey() method
        String firstKey = numbers.firstKey();
        System.out.println("First Key: " + firstKey);

        // Using the lastKey() method
        String lastKey = numbers.lastKey();
        System.out.println("Last Key: " + lastKey);

        // Using firstEntry() method
        System.out.println("First Entry: " + numbers.firstEntry());


        // Using the lastEntry() method
        System.out.println("Last Entry: " + numbers.lastEntry());
    }
}
```

::result

TreeMap: {First=1, Second=2, Third=3}</code><br/>
First Key: First</code><br/>
Last Key: Third</code><br/>
First Entry: First=1</code><br/>
Last Entry: Third=3</code>

::

- `elevKey()` – Trả về key thấp nhất trong số các key lớn hơn key đã chỉ định.
- `elevEntry()` – Trả về một mục được liên kết với key thấp nhất trong số tất cả các key lớn hơn key được chỉ định.
- `lowKey()` – Trả về key lớn nhất trong số tất cả các key nhỏ hơn key đã chỉ định.
- `lowEntry()` – Trả về mục được liên kết với key lớn nhất trong số tất cả các key nhỏ hơn key được chỉ định.
- `ceilingKey()` – Trả về key thấp nhất trong số các key lớn hơn key đã chỉ định. Nếu key được truyền dưới dạng đối số có trong map, nó sẽ trả về key đó.
- `CeilingEntry()` – Trả về một mục được liên kết với key thấp nhất trong số các key lớn hơn key được chỉ định. Nếu đó là một mục được liên kết với key thông qua một đối số có trong map, nó trả về mục được liên kết với key đó.
- `floorKey()` – Trả về key lớn nhất trong số các key nhỏ hơn key đã chỉ định. Nếu key được truyền dưới dạng đối số thì nó trả về key đó.
- `floorEntry()` – Trả về mục được liên kết với key lớn nhất trong số các key nhỏ hơn key được chỉ định. Nếu key được truyền dưới dạng đối số có mặt, nó sẽ trả về key đó.

```java
import java.util.TreeMap;

class Main {
    public static void main(String[] args) {

        TreeMap<String, Integer> numbers = new TreeMap<>();
        numbers.put("First", 1);
        numbers.put("Second", 5);
        numbers.put("Third", 4);
        numbers.put("Fourth", 6);
        System.out.println("TreeMap: " + numbers);

        // Using higher()
        System.out.println("Using higherKey(): " + numbers.higherKey("Fourth"));
        System.out.println("Using higherEntry(): " + numbers.higherEntry("Fourth"));

        // Using lower()
        System.out.println("\nUsing lowerKey(): " + numbers.lowerKey("Fourth"));
        System.out.println("Using lowerEntry(): " + numbers.lowerEntry("Fourth"));

        // Using ceiling()
        System.out.println("\nUsing ceilingKey(): " + numbers.ceilingKey("Fourth"));
        System.out.println("Using ceilingEntry(): " + numbers.ceilingEntry("Fourth"));

        // Using floor()
        System.out.println("\nUsing floorKey(): " + numbers.floorKey("Fourth"));
        System.out.println("Using floorEntry(): " + numbers.floorEntry("Fourth"));
    }
}
```

::result

TreeMap: {First=1, Fourth=6, Second=5, Third=4}</code><br/>
Using higherKey(): Second</code><br/>
Using higherEntry(): Second=5</code><br/>
<br/>
Using lowerKey(): First</code><br/>
Using lowerEntry(): First=1</code><br/>
<br/>
Using ceilingKey(): Fourth</code><br/>
Using ceilingEntry(): Fourth=6</code><br/>
<br/>
Using floorkey(): Fourth</code><br/>
Using floorEntry(): Fourth=6</code>

::

- `pollFirstEntry()` – trả về và xóa mục nhập được liên kết với key đầu tiên của map
- `pollLastEntry()` – trả về và xóa mục nhập được liên kết với key cuối cùng của map

```java
import java.util.TreeMap;

class Main {
    public static void main(String[] args) {

        TreeMap<String, Integer> numbers = new TreeMap<>();
        numbers.put("First", 1);
        numbers.put("Second", 2);
        numbers.put("Third", 3);
        System.out.println("TreeMap: " + numbers);

        //Using the pollFirstEntry() method
        System.out.println("Using pollFirstEntry(): " + numbers.pollFirstEntry());

        // Using the pollLastEntry() method
        System.out.println("Using pollLastEntry(): " + numbers.pollLastEntry());

        System.out.println("Updated TreeMap: " + numbers);

    }
}
```

::result

TreeMap: {First=1, Second=2, Third=3}</code><br/>
Using pollFirstEntry(): First=1</code><br/>
Using pollLastEntry(): Third=3</code><br/>
Updated TreeMap: {Second=2}</code><br/>

::

- `headMap(key, booleanValue)`: hàm `headMap()` trả về tất cả các cặp `key / value` của một treemap đứng trước key được chỉ định (được thông qua như là một đối số). Tham số `booleanValue` là tùy chọn. Giá trị mặc định của nó là `false`. Nếu `true` được thông qua như một `booleanValue`, hàm này cũng sẽ bao gồm cặp `key/value` của key được truyền dưới dạng đối số.

```java
import java.util.TreeMap;

class Main {
    public static void main(String[] args) {

        TreeMap<String, Integer> numbers = new TreeMap<>();
        numbers.put("First", 1);
        numbers.put("Second", 2);
        numbers.put("Third", 3);
        numbers.put("Fourth", 4);
        System.out.println("TreeMap: " + numbers);

        System.out.println("\nUsing headMap() Method:");
        // Using headMap() with default booleanValue
        System.out.println("Without boolean value: " + numbers.headMap("Fourth"));

        // Using headMap() with specified booleanValue
        System.out.println("With boolean value: " + numbers.headMap("Fourth", true));

    }
}
```

::result

TreeMap: {First=1, Fourth=4, Second=2, Third=3}</code><br/>
<br/>
Using headMap() Method:</code><br/>
Without boolean value: {First=1}</code><br/>
With boolean value: {First=1, Fourth=4}</code><br/>

::

- `tailMap(key, booleanValue)`: hàm `tailMap()` trả về tất cả các cặp `key/value` của một treemap bắt đầu từ key được chỉ định (được thông qua như là một đối số). `booleanValue` là một tham số tùy chọn. Giá trị mặc định của nó là `true`. Nếu `false` được thông qua như một `booleanValue`, hàm sẽ không bao gồm cặp `key/value` của key được chỉ định.

```java
import java.util.TreeMap;

class Main {
    public static void main(String[] args) {

        TreeMap<String, Integer> numbers = new TreeMap<>();
        numbers.put("First", 1);
        numbers.put("Second", 2);
        numbers.put("Third", 3);
        numbers.put("Fourth", 4);
        System.out.println("TreeMap: " + numbers);

        System.out.println("\nUsing tailMap() Method:");
        // Using tailMap() with default booleanValue
        System.out.println("Without boolean value: " + numbers.tailMap("Second"));

        // Using tailMap() with specified booleanValue
        System.out.println("With boolean value: " + numbers.tailMap("Second", false));

    }
}
```

::result

TreeMap: {First=1, Fourth=4, Second=2, Third=3}</code><br/>
<br/>
Using tailMap() Method:</code><br/>
Without boolean value: {Second=2, Third=3}</code><br/>
With boolean value: {Third=3}</code>

::

- `subMap (k1, bV1, k2, bV2)`: hàm `subMap()` trả về tất cả các mục có liên quan với các key trong khoảng k1 và k2 bao gồm cả mục của k1. bV1 và bV2 là các tham số `boolean` tùy chọn. Giá trị mặc định của bV1 là true và giá trị mặc định của bV2 là false. Nếu false được thông qua như bv1, hàm này sẽ trả về tất cả các mục được liên kết với các key trong khoảng k1 và k2 không bao gồm mục của k1. Nếu true được thông qua như bV2, hàm này sẽ trả về tất cả các mục được liên kết với các key trong khoảng k1 và k2 bao gồm cả mục của k2.

```java
class Main {
    public static void main(String[] args) {

        TreeMap<String, Integer> numbers = new TreeMap<>();
        numbers.put("First", 1);
        numbers.put("Second", 2);
        numbers.put("Third", 3);
        numbers.put("Fourth", 4);
        System.out.println("TreeMap: " + numbers);

        System.out.println("\nUsing subMap() Method:");
        // Using subMap() with default booleanValue
        System.out.println("Without boolean value: " + numbers.subMap("Fourth", "Third"));

        // Using subMap() with specified booleanValue
        System.out.println("With boolean value: " + numbers.subMap("Fourth", false, "Third", true));

    }
}
```

::result

TreeMap: {First=1, Fourth=2, Second=2, Third=3}</code><br/>
<br/>
Using subMap() Method:</code><br/>
Without boolean value: {Fourth=4, Second=2}</code><br/>
With boolean value: {Second=2, Third=3}</code>

::

## Một số hàm của TreeMap

| Hàm               | Mô tả                                                                |
| ----------------- | -------------------------------------------------------------------- |
| `clone()`         | Tạo một bản sao của TreeMap                                          |
| `containsKey()`   | Tìm kiếm key được chỉ định trong TreeMap và trả về kết quả boolean   |
| `containsValue()` | Tìm kiếm value được chỉ định trong TreeMap và trả về kết quả boolean |
| `size()`          | Trả về kích thước của TreeMap                                        |
| `clear()`         | Xóa tất cả các mục khỏi TreeMap                                      |
