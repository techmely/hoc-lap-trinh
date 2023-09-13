---
title: "Map trong Java"
description: "map được sử dụng để lưu trữ và truy xuất dữ liệu theo cặp khóa (key) và giá trị (value), mỗi cặp key và value được gọi là entry."
chapter:
  name: "Java collections"
  slug: "chuong-04-java-collections"
category:
  name: "Java"
  slug: "java"
image: https://user-images.githubusercontent.com/29374426/145352732-65bf2fe2-2478-4163-828e-ce73057c13eb.png
position: 10
---

## Map trong Java là gì?

Trong java, `map` được sử dụng để lưu trữ và truy xuất dữ liệu theo cặp **khóa (key)** và **giá trị (value)**. Mỗi cặp key và value được gọi là entry.

Map chỉ chứa các giá trị key duy nhất, không chứa các `key` trùng lặp.

![Map trong Java](https://user-images.githubusercontent.com/29374426/145352732-65bf2fe2-2478-4163-828e-ce73057c13eb.png)

Các lớp cài đặt (implements) Map interface là:

- `HashMap` không đảm bảo thứ tự các entry được thêm vào.
- `LinkedHashMap` đảm bảo thứ tự các entry được thêm vào.
- `TreeMap` duy trình thứ tự các phần tử dựa vào bộ so sánh Comparator.
- `EnumMap`
- WeakHashMap
- TreeMap

![Các lớp cài đặt Map interface](https://user-images.githubusercontent.com/29374426/145352782-375c0313-e6ba-4610-99a8-4893fd41524a.png)

Sức chứa (compacity) mặc định khi khởi tạo map là `2^4 = 16`. Kích thước này sẽ tự động tăng gấp đôi mỗi khi thêm phần tử vượt quá kích thước của nó.

## Sử dụng Map trong Java

Trong Java, chúng ta phải import gói `java.util.Map` để sử dụng `Map`. Khi chúng ta đã `import` gói, sau đây là cách chúng ta có thể tạo map.

```java
// Map implementation using HashMap
Map<Key, Value> numbers = new HashMap<>();
```

Trong đoạn code trên, chúng ta đã tạo ra một Map tên là numbers. Chúng ta đã sử dụng `class HashMap` để triển khai `Map interface`. Ở đây:

- `Key` – Code định danh duy nhất được sử dụng để liên kết từng phần tử (value) trong map
- `Value` – các phần tử được liên kết bởi các key trong map

## Các hàm của Map trong Java

- `put (K, V)` – Chèn liên kết của key `K` và value `V` vào `map`. Nếu key đã có sẵn, value mới sẽ thay thế value cũ.
- `putAll()` – Chèn tất cả các mục từ map đã chỉ định vào map hiện tại.
- `putIfAbsent (K,V)` – Chèn liên kết nếu key K chưa được liên kết với value `V`.
- `get(K)` – Trả về value được liên kết với key K được chỉ định. Nếu không tìm thấy `key`, nó sẽ trả về `null`.
- `getOrDefault(K, defaultValue)` – Trả về value được liên kết với key `k` được chỉ định. Nếu không tìm thấy key, nó sẽ trả về value mặc định.
- `containsKey(K)` – Kiểm tra xem key được chỉ định `K` đã có trong map chưa.
- `containsValue(V)` – Kiểm tra xem value `v` được chỉ định đã có trong map chưa.
- `replace(K, V)` – Thay thế value của key `K` với value `v` được chỉ định mới.
- `replace(K, oldValue, newValue)` – Thay thế value của key `K` với value mới là `newValue` nếu key `K` được liên kết với value `oldValue`.
- `remove(K)` – Xóa mục được đại diện bởi key `K` khỏi `map`.
- `remove(K, V)` – Xóa mục có key `K` liên kết với value `V` khỏi map.
- `keyset()` – Trả về một tập hợp gồm tất cả các `key` có trong map.
- `value()` – Trả về tập hợp tất gồm cả các value có trong map.
- `entryset()` – Trả về tập hợp gồm tất cả cặp `key/value` có trong map.

```java
package com.gpcoder.collection.map;

import java.util.HashMap;
import java.util.Map;
import java.util.Map.Entry;

public class MapExample {
    public static void main(String args[]) {
        // init map
        Map<Integer, String> map = new HashMap<Integer, String>();
        map.put(1, "Basic java");
        map.put(2, "OOP");
        map.put(3, "Collection");

        // show map using method keySet()
        for (Integer key : map.keySet()) {
            String value = map.get(key);
            System.out.println(key + " = " + value);
        }

        System.out.println("---");

        // show map using method keySet()
        for (Entry<Integer, String> entry : map.entrySet()) {
            Integer key = entry.getKey();
            String value = entry.getValue();
            System.out.println(key + " = " + value);
        }
    }
}
```

::result

1 = Basic java<br/>
2 = OOP<br/>
3 = Collection<br/>
---<br/>
1 = Basic java<br/>
2 = OOP<br/>
3 = Collection

::
