---
title: "EnumMap trong Java"
description: "EnumMap là một Map implementation được thiết kế để làm việc với kiểu dữ liệu Enum trong Java. Trong bài viết này chúng ta sẽ cùng nhau tìm hiểu về nó, cũng như một số trường hợp sử dụng cơ bản, và khi nào thì nên sử dụng EnumMap"
keywords:
  [
    "EnumMap trong Java",
    "Tạo một EnumMap trong Java",
    "Chèn các phần tử vào EnumMap",
    "Truy cập các phần tử EnumMap",
    "Xóa các phần tử khỏi EnumMap",
    "Thay thế các phần tử EnumMap",
    "Các hàm trong EnumMap",
  ]
chapter:
  name: "Java collections"
  slug: "chuong-04-java-collections"
category:
  logo: "/language/java.png"
  name: "Java"
  slug: "java"
  description: "Học Java từ cơ bản đến thông thạo cho mọi đối tượng"
image: https://user-images.githubusercontent.com/29374426/145797889-981dcdc2-f28f-43ac-93f5-bbcef6c199d1.png
position: 16
---

## EnumMap trong Java là gì?

`EnumMap` là một Map `implementation` được thiết kế để làm việc với kiểu dữ liệu `Enum` trong Java. Trong bài viết này chúng ta sẽ cùng nhau tìm hiểu về nó, cũng như một số trường hợp sử dụng cơ bản, và khi nào thì nên sử dụng `EnumMap`

![EnumMap trong Java](https://user-images.githubusercontent.com/29374426/145797889-981dcdc2-f28f-43ac-93f5-bbcef6c199d1.png)

## Tạo một EnumMap trong Java

Để tạo `EnumMap`, trước tiên chúng ta phải import gói `java.util.EnumMap`. Khi chúng ta `import`, sau đây là cách chúng ta có thể tạo `EnumMap` trong Java.

```java
enum Size {
    SMALL, MEDIUM, LARGE, EXTRALARGE
}

EnumMap<Size, Integer> sizes = new EnumMap<>(Size.class);
```

Trong ví dụ trên, chúng ta đã tạo ra một `EnumMap` có tên là `sizes`. Ở đây:

- `Size` - các `key` của `enum` liên kết với các `value`
- `Integer` - các `value` của `EnumMap` liên kết với các `key` tương ứng

## Chèn các phần tử vào EnumMap

- `put()` – chèn cặp `key/value` được chỉ định (mục nhập) vào `EnumMap`
- `putAll()` – chèn tất cả các mục của map được chỉ định vào `map` này

<div class="example"></div>

```java
import java.util.EnumMap;

class Main {

    enum Size {
        SMALL, MEDIUM, LARGE, EXTRALARGE
    }
    public static void main(String[] args) {

        // Creating an EnumMap of the Size enum
        EnumMap<Size, Integer> sizes1 = new EnumMap<>(Size.class);

        // Using the put() Method
        sizes1.put(Size.SMALL, 28);
        sizes1.put(Size.MEDIUM, 32);
        System.out.println("EnumMap1: " + sizes1);

        EnumMap<Size, Integer> sizes2 = new EnumMap<>(Size.class);

        // Using the putAll() Method
        sizes2.putAll(sizes1);
        sizes2.put(Size.LARGE, 36);
        System.out.println("EnumMap2: " + sizes2);
    }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>EnumMap1: {SMALL=28, MEDIUM=32}</code><br/>
    <code>EnumMap2: {SMALL=28, MEDIUM=32, LARGE=36}</code><br/>
  </div>
</div>

Ở ví dụ trên, chúng ta đã sử dụng hàm `putAll()` để chèn tất cả các phần tử của EnumMap `sizes1` đến một EnumMap của `sizes2`.

Nó cũng có thể chèn các phần tử từ các map khác như `HashMap`, `TreeMap`,... tới một `EnumMap` bằng cách sử dụng hàm `putAll()`. Tuy nhiên, tất cả các map nên cùng loại `enum`.

## Truy cập các phần tử EnumMap

- `entrySet()` – trả về một tập hợp tất cả các cặp key / value (mục nhập) của EnumMap
- `keySet()` – trả về một tập hợp tất cả các key của EnumMap
- `values()` – trả về một tập hợp tất cả các value của EnumMap

<div class="example"></div>

```java
import java.util.EnumMap;

class Main {

    enum Size {
        SMALL, MEDIUM, LARGE, EXTRALARGE
    }
    public static void main(String[] args) {

        // Creating an EnumMap of the Size enum
        EnumMap<Size, Integer> sizes = new EnumMap<>(Size.class);
        sizes.put(Size.SMALL, 28);
        sizes.put(Size.MEDIUM, 32);
        sizes.put(Size.LARGE, 36);
        sizes.put(Size.EXTRALARGE, 40);
        System.out.println("EnumMap: " + sizes);

        // Using the entrySet() Method
        System.out.println("Key/Value mappings: " + sizes.entrySet());

        // Using the keySet() Method
        System.out.println("Keys: " + sizes.keySet());

        // Using the values() Method
        System.out.println("Values: " + sizes.values());
    }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>EnumMap: {SMALL=28, MEDIUM=32, LARGE=36, EXTRALARGE=40}</code><br/>
    <code>Key/Value mappings: [SMALL=28, MEDIUM=32, LARGE=36, EXTRALARGE=40]</code><br/>
    <code>Keys: [SMALL, MEDIUM, LARGE, EXTRALARGE]</code><br/>
    <code>Values: [28, 32, 36, 40]</code>
  </div>
</div>

- Hàm `get()` trả về `value` liên kết với key chỉ định. Nó trả về `null` nếu không tìm thấy `key` được chỉ định

<div class="example"></div>

```java
import java.util.EnumMap;

class Main {

    enum Size {
        SMALL, MEDIUM, LARGE, EXTRALARGE
    }
    public static void main(String[] args) {

        // Creating an EnumMap of the Size enum
        EnumMap<Size, Integer> sizes = new EnumMap<>(Size.class);
        sizes.put(Size.SMALL, 28);
        sizes.put(Size.MEDIUM, 32);
        sizes.put(Size.LARGE, 36);
        sizes.put(Size.EXTRALARGE, 40);
        System.out.println("EnumMap: " + sizes);

        // Using the get() Method
        int value = sizes.get(Size.MEDIUM);
        System.out.println("Value of MEDIUM: " + value);
    }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>EnumMap: {SMALL=28, MEDIUM=32, LARGE=36, EXTRALARGE=40}</code><br/>
    <code>Value of MEDIUM: 32</code>
  </div>
</div>

## Xóa các phần tử khỏi EnumMap

- `remove(key)` – trả về và xóa mục nhập được liên kết với key được chỉ định khỏi `map`
- `remove(key, value)` – chỉ xóa mục nhập khỏi `maps` nếu key được chỉ định liên kết với `value` đã chỉ định và trả về giá trị `boolean`

<div class="example"></div>

```java
import java.util.EnumMap;

class Main {

    enum Size {
        SMALL, MEDIUM, LARGE, EXTRALARGE
    }
    public static void main(String[] args) {

        // Creating an EnumMap of the Size enum
        EnumMap<Size, Integer> sizes = new EnumMap<>(Size.class);
        sizes.put(Size.SMALL, 28);
        sizes.put(Size.MEDIUM, 32);
        sizes.put(Size.LARGE, 36);
        sizes.put(Size.EXTRALARGE, 40);
        System.out.println("EnumMap: " + sizes);

        // Using the remove() Method
        int value = sizes.remove(Size.MEDIUM);
        System.out.println("Removed Value: " + value);

        boolean result = sizes.remove(Size.SMALL, 28);
        System.out.println("Is the entry {SMALL=28} removed? " + result);

        System.out.println("Updated EnumMap: " + sizes);
    }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>EnumMap: {SMALL=28, MEDIUM=32, LARGE=36, EXTRALARGE=40}</code><br/>
    <code>Removed Value: 32</code><br/>
    <code>Is the entry {SMALL=28} removed? True</code><br/>
    <code>Updated EnumMap: {LARGE=36, EXTRALARGE=40}</code>
  </div>
</div>

## Thay thế các phần tử EnumMap

- `replace(key, value)` – thay thế `value` liên kết với `key` chỉ định bằng `value` mới
- `replace(key, old, new)` – thay thế cũ `value` bằng va`lue mới nếu `value`cũ đã được liên kết với`key` chỉ định
- `replaceAll(function)` – thay thế từng `value` của `map` bằng kết quả của chức năng được chỉ định

<div class="example"></div>

```java
import java.util.EnumMap;

class Main {

    enum Size {
        SMALL, MEDIUM, LARGE, EXTRALARGE
    }
    public static void main(String[] args) {

        // Creating an EnumMap of the Size enum
        EnumMap<Size, Integer> sizes = new EnumMap<>(Size.class);
        sizes.put(Size.SMALL, 28);
        sizes.put(Size.MEDIUM, 32);
        sizes.put(Size.LARGE, 36);
        sizes.put(Size.EXTRALARGE, 40);
        System.out.println("EnumMap: " + sizes);

        // Using the replace() Method
        sizes.replace(Size.MEDIUM, 30);
        sizes.replace(Size.LARGE, 36, 34);
        System.out.println("EnumMap using replace(): " + sizes);

        // Using the replaceAll() Method
        sizes.replaceAll((key, oldValue) -> oldValue + 3);
        System.out.println("EnumMap using replaceAll(): " + sizes);
    }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>EnumMap: {SMALL=28, MEDIUM=32, LARGE=36, EXTRALARGE=40}</code><br/>
    <code>EnumMap using replace(): {SMALL=28, MEDIUM=30, LARGE=34, EXTRALARGE=40}</code><br/>
    <code>EnumMap using replaceAll(): {SMALL=31, MEDIUM=33, LARGE=37, EXTRALARGE=43}</code>
  </div>
</div>

Trong chương trình trên, chú ý câu lệnh:

```java
sizes.replaceAll((key, oldValue) -> oldValue + 3);
```

Ở đây, hàm này truy cập tất cả các mục của `map`. Sau đó, nó thay thế tất cả các `value` bằng các `value` mới được cung cấp bởi các biểu thức lambda .

## Các hàm trong EnumMap

| Hàm | Mô tả |
| --- | --- |
| `clone()` | Tạo một bản sao của EnumMap |
| `containsKey()` | Tìm kiếm key được chỉ định trong EnumMap và trả về kết quả boolean |
| `containsValue()` | Tìm kiếm value được chỉ định trong EnumMap và trả về kết quả boolean |
| `size()` | Trả về kích thước của EnumMap |
| `clear()` | Xóa tất cả các mục từ EnumMap |

## So sánh Enumset với EnumMap

Cả class [Enumset](/bai-viet/java/enumset-trong-java) và EnumMap đều cung cấp cấu trúc dữ liệu để lưu trữ các `value` `enum`. Tuy nhiên, có một số khác biệt lớn giữa chúng.

- `Enumset` được biểu diễn nội bộ dưới dạng một chuỗi các bit, trong khi `EnumMap` được biểu diễn nội bộ dưới dạng mảng.
- `Enumset` được tạo ra bằng các hàm xác định trước của nó như `allOf()`, `noneOf()`, `of()`,... Tuy nhiên, một `EnumMap` được tạo bằng `constructor` của nó.
