---
title: "HashTable trong Java"
description: "HashTable là một mảng của list, mỗi list được biết đến như một bucket vùng chứa) các phần tử, vị trí của một bucket được xác định bằng việc gọi phương thức hashcode"
chapter:
  name: "Java collections"
  slug: "chuong-04-java-collections"
category:
  name: "Java"
  slug: "java"
image: https://user-images.githubusercontent.com/29374426/145697837-43c57a8a-b188-4d77-90f1-533edb0caaa2.png
position: 14
---

## `HashTable` trong Java là gì?

Lớp `Java HashTable` cài đặt (implement) một bảng HashTable để map khóa và giá trị. `HashTable` kế thừa lớp `Dictionary` và cài đặt (implement) `Map Interface`.

![HashTable trong Java](https://user-images.githubusercontent.com/29374426/145697837-43c57a8a-b188-4d77-90f1-533edb0caaa2.png)

Các đặc điểm quan trọng về lớp `HashTable` trong java là:

- `HashTable` là một mảng của list. Mỗi list được biết đến như một bucket (vùng chứa) các phần tử. Vị trí của một bucket được xác định bằng việc gọi phương thức `hashcode()`.
- `HashTable` cũng lưu trữ dữ liệu dưới dạng cặp `key` và `value`.
- `HashTable` chứa các key duy nhất.
- `HashTable` KHÔNG thể có bất kỳ key hoặc giá trị nào là `null`.
- `HashTable` được đồng bộ (synchronized).

## Tạo một `HashTable` trong Java

Để tạo `HashMap`, trước tiên chúng ta phải import gói `java.util.HashMap`. Khi chúng ta đã `import` xong, sau đây là cách chúng ta có thể tạo các hashmap trong Java.

```java
// HashMap creation with 8 capacity and 0.6 load factor
HashMap<Key, Value> numbers = new HashMap<>(8, 0.6f);
```

Trong đoạn code trên, chúng ta đã tạo ra một `hashmap` có tên là `numbers`. Trong đó:

- `Key` là code định danh duy nhất được sử dụng để liên kết từng phần tử (value) trong map
- `Value` là các phần tử được liên kết bởi các key trong map

Lưu ý về đoạn code `new HashMap<>(8, 0.6)`. Ở đây, tham số đầu tiên là `capacity` và tham số thứ hai là `loadFactor` .

- `capacity` là dung lượng của HashMap này là 8. Ý nghĩa nó có thể lưu trữ 8 mục.
- `loadFactor` là hệ số tải của hashmap này là 0,6. Điều này có nghĩa là bất cứ khi nào bảng băm của chúng ta được lấp đầy 60%, các mục mới sẽ được chuyển sang bảng băm mới có kích thước gấp đôi bảng băm ban đầu.

## Tạo `HashMap` từ các Map khác

Sau đây là cách chúng ta có thể tạo một hashmap chứa tất cả các phần tử của các map khác.

```java
import java.util.HashMap;

class Main {
    public static void main(String[] args) {
        // Creating a hashmap of even numbers
        HashMap<String, Integer> evenNumbers = new HashMap<>();
        evenNumbers.put("Two", 2);
        evenNumbers.put("Four", 4);
        System.out.println("HashMap1: " + evenNumbers);

        // Creating a hash map from other hashmap
        HashMap<String, Integer> numbers = new HashMap<>(evenNumbers);
        numbers.put("Three", 3);
        System.out.println("HashMap2: " + numbers);
    }
}
```

::result

HashMap1: {Four=4, Two=2}<br/>
HashMap2: {Two=2, Three=3, Four=4}

::

## Chèn các phần tử vào `HashMap`

- `put()` – chèn cặp `key/value` được chỉ định vào map
- `putAll()` – chèn tất cả các mục từ map được chỉ định vào map hiện tại
- `putIfAbsent()` – chèn cặp `key/value` được chỉ định vào map nếu key được chỉ định không có trong map

```java
import java.util.HashMap;

class Main {
    public static void main(String[] args) {
        // Creating HashMap of even numbers
        HashMap<String, Integer> evenNumbers = new HashMap<>();

        // Using put()
        evenNumbers.put("Two", 2);
        evenNumbers.put("Four", 4);

        // Using putIfAbsent()
        evenNumbers.putIfAbsent("Six", 6);
        System.out.println("HashMap of even numbers: " + evenNumbers);

        //Creating HashMap of numbers
        HashMap<String, Integer> numbers = new HashMap<>();
        numbers.put("One", 1);

        // Using putAll()
        numbers.putAll(evenNumbers);
        System.out.println("HashMap of numbers: " + numbers);
    }
}
```

::result

HashMap of even numbers: {Six=6, Four=4, Two=2}<br/>
HashMap of numbers: {Six=6, One=1, Four=4, Two=2}

::

## Lấy các phần tử trong `HashMap`

- `entrySet()` – trả về một tập hợp gồm tất cả cặp key / value của map
- `keySet()` – trả về một tập hợp gồm tất cả các key của map
- `values()` – trả về một tập hợp gồm tất cả các value của map

```java
import java.util.HashMap;

class Main {
    public static void main(String[] args) {
        HashMap<String, Integer> numbers = new HashMap<>();

        numbers.put("One", 1);
        numbers.put("Two", 2);
        numbers.put("Three", 3);
        System.out.println("HashMap: " + numbers);

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

HashMap: {One=1, Two=2, Three=3}<br/>
Key/Value mappings: [One=1, Two=2, Three=3]<br/>
Keys: [One, Two, Three]<br/>
Values: [1, 2, 3]

::

- `get()`- Trả về value liên kết với `key` được chỉ định. Trả về `null` nếu không tìm thấy key.
- `getOrDefault()`- Trả về `value` liên kết với key được chỉ định. Trả về `value` mặc định đã chỉ định nếu không tìm thấy `key`.

```java
import java.util.HashMap;

class Main {
    public static void main(String[] args) {

        HashMap<String, Integer> numbers = new HashMap<>();
        numbers.put("One", 1);
        numbers.put("Two", 2);
        numbers.put("Three", 3);
        System.out.println("HashMap: " + numbers);

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

HashMap: {One=1, Two=2, Three=3}<br/>
Returned Number: 3<br/>
Returned Number: 5

::

## Xóa phần tử hỏi `HashTable`

- `remove(key)` – trả về và xóa mục liên kết với key được chỉ định khỏi map
- `remove(key, value)` – chỉ xóa mục khỏi map nếu key được chỉ định liên kết với value đã chỉ định và trả về giá trị `boolean`

```java
import java.util.HashMap;

class Main {
    public static void main(String[] args) {

        HashMap<String, Integer> numbers = new HashMap<>();
        numbers.put("One", 1);
        numbers.put("Two", 2);
        numbers.put("Three", 3);
        System.out.println("HashMap: " + numbers);

        // remove method with single parameter
        int value = numbers.remove("Two");
        System.out.println("Removed value: " + value);

        // remove method with two parameters
        boolean result = numbers.remove("Three", 3);
        System.out.println("Is the entry Three removed? " + result);

        System.out.println("Updated HashMap: " + numbers);
    }
}
```

::result

HashMap: {One=1, Two=2, Three=3}<br/>
Removed value: 2<br/>
Is the entry Three removed? True<br/>
Updated HashMap: {One=1}

::

## Thay thế các phần tử trong `HashTable`

- `replace(key, value)` – thay thế value liên kết với Key được chỉ định bằng một value mới
- `replace(key, old, new)` – thay thế value old bằng value new nếu value old đã liên kết với Key được chỉ định
- `replaceAll(function)` – thay thế từng value của map bằng kết quả của hàm được chỉ định

```java
import java.util.HashMap;

class Main {
    public static void main(String[] args) {

        HashMap<String, Integer> numbers = new HashMap<>();
        numbers.put("First", 1);
        numbers.put("Second", 2);
        numbers.put("Third", 3);
        System.out.println("Original HashMap: " + numbers);

        // Using replace()
        numbers.replace("Second", 22);
        numbers.replace("Third", 3, 33);
        System.out.println("HashMap using replace(): " + numbers);

        // Using replaceAll()
        numbers.replaceAll((key, oldValue) -> oldValue + 2);
        System.out.println("HashMap using replaceAll(): " + numbers);
    }
}
```

::result

Original HashMap: {Second=2, Third=3, First=1}<br/>
HashMap using replace: {Second=22, Third=33, First=1}<br/>
HashMap using replaceAll: {Second=24, Third=35, First=3}

::

Trong chương trình trên chú ý câu lệnh:

```java
numbers.replaceAll((key, oldValue) -> oldValue + 2);
```

Ở đây, hàm này truy cập tất cả các mục của map. Sau đó, nó thay thế tất cả các value bằng các value mới được cung cấp bởi biểu thức lambda .

## Tính toán lại các giá trị

- `compute()` - Tính toán một value mới bằng cách sử dụng hàm được chỉ định. Sau đó, nó liên kết `value` được tính toán với `key` được chỉ định.
- `computeIfAbsent()` - Nếu key được chỉ định không được liên kết với bất kỳ value nào, hàm này sẽ tính toán một value mới bằng cách sử dụng hàm được chỉ định. Sau đó, nó liên kết value mới với key.
- `computeIfPresent()` - Nếu key được chỉ định đã được liên kết với bất kỳ value nào, hàm này sẽ tính toán một value mới bằng cách sử dụng hàm được chỉ định. Sau đó, nó liên kết value mới với `key`.

```java
import java.util.HashMap;

class Main {
    public static void main(String[] args) {

        HashMap<String, Integer> numbers = new HashMap<>();
        numbers.put("First", 1);
        numbers.put("Second", 2);
        System.out.println("Original HashMap: " + numbers);

        // Using compute()
        numbers.compute("First", (key, oldValue) -> oldValue + 2);
        numbers.compute("Second", (key, oldValue) -> oldValue + 1);
        System.out.println("HashMap using compute(): " + numbers);

        // Using computeIfAbsent()
        numbers.computeIfAbsent("Three", key -> 5);
        System.out.println("HashMap using computeIfAbsent(): " + numbers);

        // Using computeIfPresent()
        numbers.computeIfPresent("Second", (key, oldValue) -> oldValue * 2);
        System.out.println("HashMap using computeIfPresent(): " + numbers);
    }
}
```

::result

Original HashMap: {Second=2, First=1}<br/>
HashMap using compute(): {Second=3, First=3}<br/>
HashMap using computeIfAbsent(): {Second=3 First=3, Three=5}<br/>
HashMap using computeIfPresent(): {Second=6, First=3, three=5}

::

Trong ví dụ trên, chúng ta đã tính toán lại các `value` của map bằng hàm `compute()`. Ở đây, chúng ta đã sử dụng các biểu thức lambda làm đối số hàm để tính toán lại các `value`

- `merge()` - liên kết value được chỉ định với để `key` được chỉ định nếu key đó chưa được liên kết với `value` nào. Tuy nhiên, nếu `key` được chỉ định đã được liên kết với một `value`, nó sẽ hợp nhất value được chỉ định mới với `value` cũ hiện có.

```java
import java.util.HashMap;

class Main {
    public static void main(String[] args) {

        HashMap<String, Integer> numbers = new HashMap<>();
        numbers.put("First", 1);
        numbers.put("Second", 2);
        System.out.println("Original HashMap: " + numbers);

        // Using merge() Method
        numbers.merge("First", 4, (oldValue, newValue) -> oldValue + newValue);
        System.out.println("New HashMap: " + numbers);
    }
}
```

::result

Original HashMap: {Second=2, First=1}<br/>
New HashMap: {Second=2, First=5}

::

Trong ví dụ trên, hàm `merge()` này có 3 tham số: `key` , `newValue` và biểu thức lambda (biểu thức này tính value hợp nhất mới).

## Duyệt qua từng phần tử trong HashMap

Trong một HashMap, chúng ta có thể

- Lặp qua các `key` của nó
- Lặp qua các `value` của nó
- Lặp qua các `key/value` của nó

```java
import java.util.HashMap;
import java.util.Map.Entry;

class Main {
    public static void main(String[] args) {

        // Creating a HashMap
        HashMap<String, Integer> numbers = new HashMap<>();
        numbers.put("One", 1);
        numbers.put("Two", 2);
        numbers.put("Three", 3);
        System.out.println("HashMap: " + numbers);

        // Accessing the key/value pair
        System.out.print("Entries: ");
        for(Entry<String, Integer> entry: numbers.entrySet()) {
            System.out.print(entry);
            System.out.print(", ");
        }

        // Accessing the key
        System.out.print("\nKeys: ");
        for(String key: numbers.keySet()) {
            System.out.print(key);
            System.out.print(", ");
        }

        // Accessing the value
        System.out.print("\nValues: ");
        for(Integer value: numbers.values()) {
            System.out.print(value);
            System.out.print(", ");
        }
    }
}
```

::result

HashMap: {One=1, Two=2, Three=3}<br/>
Entries: One=1, Two=2, Three=3<br/>
Keys: One, Two, Three,<br/>
Values: 1, 2, ,3,

::

Trong chương trình trên, lưu ý rằng chúng ta đã import gói `java.util.Map.Entry`. Ở đây, `Map.Entry` là `class` trong của Map interface. Class trong này trả về một view (các phần tử) của map.

Ngoài ra chúng ta cũng có thể lặp lại HashMap bằng cách sử dụng hàm `iterator()`. Để sử dụng hàm này, chúng ta phải `import java.util.Iterator` gói.

```java
import java.util.HashMap;
import java.util.Iterator;
import java.util.Map.Entry;

class Main {
    public static void main(String[] args) {
        // Creating a HashMap
        HashMap<String, Integer> numbers = new HashMap<>();
        numbers.put("One", 1);
        numbers.put("Two", 2);
        numbers.put("Three", 3);
        System.out.println("HashMap: " + numbers);

        // Creating an object of Iterator
        Iterator<Entry<String, Integer>> iterate1 = numbers.entrySet().iterator();

        // Accessing the Key/Value pair
        System.out.print("Entries: ");
        while(iterate1.hasNext()) {
            System.out.print(iterate1.next());
            System.out.print(", ");
        }

        // Accessing the key
        Iterator<String> iterate2 = numbers.keySet().iterator();
        System.out.print("\nKeys: ");
        while(iterate2.hasNext()) {
            System.out.print(iterate2.next());
            System.out.print(", ");
        }

        // Accessing the value
        Iterator<Integer> iterate3 = numbers.values().iterator();
         System.out.print("\nValues: ");
        while(iterate3.hasNext()) {
            System.out.print(iterate3.next());
            System.out.print(", ");
        }
    }
}
```

::result

HashMap: {One=1, Two=2, Three=3}<br/>
Entries: One=1, Two=2, Three=3<br/>
Keys: One, Two, Three,<br/>
Values: 1, 2, 3,

::

## Một số hàm của HashMap

| Hàm               | Mô tả                                                                              |
| ----------------- | ---------------------------------------------------------------------------------- |
| `clear()`         | Xóa tất cả các mục khỏi `map`                                                      |
| `containsKey()`   | Kiểm tra xem map có chứa `key` được chỉ định hay không và trả về giá trị `boolean` |
| `containsValue()` | Kiểm tra xem map có chứa value được chỉ định hay không và trả về giá trị `boolean` |
| `size()`          | Trả về kích cỡ của map                                                             |
| `isEmpty()`       | Kiểm tra xem map có trống không và trả về giá trị `boolean`                        |
