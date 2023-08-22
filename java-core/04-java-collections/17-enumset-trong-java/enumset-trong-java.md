---
title: "Enumset trong Java"
description: "Class EnumSet của collections framework trong Java triển khai tập hợp các phần tử của một enum đơn. Trước khi bạn tìm hiểu về EnumSet, hãy chắc chắn rằng bạn đã biết về Enums trong Java"
chapter:
  name: "Java collections"
  slug: "chuong-04-java-collections"
category:
  name: "Java"
  slug: "java"
image: https://user-images.githubusercontent.com/29374426/145766680-a7bd0eb6-6b24-442a-8ff4-13998b902c39.png
position: 18
---

## EnumSet trong Java là gì?

`Class EnumSet` của collections framework trong Java triển khai tập hợp các phần tử của một enum đơn. Trước khi bạn tìm hiểu về `EnumSet`, hãy chắc chắn rằng bạn đã biết về [Enums trong Java](/bai-viet/java/enum-trong-java).

`EnumSet` giúp ta lưu trữ các giá trị `enum` một cách hiệu quả so các set khác (như `HashSet`, `TreeSet`).

Một `EnumSet` chỉ lưu trữ các giá trị `enum` của một `enum` cụ thể. Do đó, JVM sẽ biết tất cả các giá trị có thể có của `set`. Đây là lý do tại sao các `EnumSet` được triển khai nội bộ như một chuỗi các `bit`. Các `bit` xác định xem các phần tử có trong `EnumSet` hay không.

![EnumSet trong Java](https://user-images.githubusercontent.com/29374426/145766680-a7bd0eb6-6b24-442a-8ff4-13998b902c39.png)

## Tạo Enumset trong Java

Để tạo một `EnumSet`, trước tiên chúng ta phải import gói `java.util.EnumSet`. Khác với việc triển khai `set`, `EnumSet` không có các `constructor` công khai. Chúng ta phải sử dụng các hàm được xác định trước để tạo ra một `EnumSet`.

### Sử dụng hàm allOf(Size)

Hàm `allof()` tạo ra một `EnumSet` có chứa tất cả các giá trị của enum kiểu `Size` đã chỉ định.

<content-example />

```java
import java.util.EnumSet;

class Main {
    // an enum named Size
    enum Size {
        SMALL, MEDIUM, LARGE, EXTRALARGE
    }

    public static void main(String[] args) {
        // Creating an EnumSet using allOf()
        EnumSet<Size> sizes = EnumSet.allOf(Size.class);
        System.out.println("EnumSet: " + sizes);
    }

}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>EnumSet: [SMALL, MEDIUM, LARGE, EXTRALARGE]</code>
  </div>
</div>

Lưu ý câu lệnh

```java
EnumSet<Size> sizes = EnumSet.allOf(Size.class);
```

Ở đây, `Size.Class` biểu diễn `enum` có tên `Size` mà chúng ta đã tạo ra.

### Sử dụng noneOf(Size)

Hàm `noneOf()` tạo ra một `EnumSet` trống.

<content-example />

```java
import java.util.EnumSet;

class Main {

     // an enum type Size
    enum Size {
        SMALL, MEDIUM, LARGE, EXTRALARGE
    }

    public static void main(String[] args) {

        // Creating an EnumSet using noneOf()
        EnumSet<Size> sizes = EnumSet.noneOf(Size.class);

        System.out.println("Empty EnumSet: " + sizes);
    }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>Empty EnumSet : []</code>
  </div>
</div>

Ở đây, chúng ta đã tạo ra một `enum` trống có tên là `Size`. Lưu ý chúng ta chỉ có thể chèn các phần tử của kiểu enum `Size` trong chương trình trên. Bởi vì chúng ta đã tạo ra `EnumSet` trống bằng cách sử dụng `enum Size`.

### Sử dụng hàm range(e1, e2)

Hàm `range()` tạo ra một EnumSet chứa tất cả các giá trị của một `enum` giữa 2 giá trị `e1` và `e2` bao gồm cả hai giá trị này.

<content-example />

```java
import java.util.EnumSet;

class Main {

    enum Size {
        SMALL, MEDIUM, LARGE, EXTRALARGE
    }

    public static void main(String[] args) {

        // Creating an EnumSet using range()
        EnumSet<Size> sizes = EnumSet.range(Size.MEDIUM, Size.EXTRALARGE);

        System.out.println("EnumSet: " + sizes);
    }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>EnumSet: [MEDIUM, LARGE, EXTRALARGE]</code>
  </div>
</div>

### Sử dụng hàm of()

Hàm `of()` tạo ra một EnumSet có chứa các phần tử đã chỉ định.

<content-example />

```java
import java.util.EnumSet;

class Main {

    enum Size {
        SMALL, MEDIUM, LARGE, EXTRALARGE
    }

    public static void main(String[] args) {

        // Using of() with a single parameter
        EnumSet<Size> sizes1 = EnumSet.of(Size.MEDIUM);
        System.out.println("EnumSet1: " + sizes1);

        EnumSet<Size> sizes2 = EnumSet.of(Size.SMALL, Size.LARGE);
        System.out.println("EnumSet2: " + sizes2);
    }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>EnumSet1: [MEDIUM]</code><br/>
    <code>EnumSet2: [SMALL, LARGE]</code>
  </div>
</div>

## Chèn các phần tử vào Enumset trong Java

- `add()` – chèn các giá trị enum được chỉ định vào `EnumSet`
- `addAll()` chèn tất cả các phần tử của `collection` đã chỉ định vào `set`

<content-example />

```java
import java.util.EnumSet;

class Main {

    enum Size {
        SMALL, MEDIUM, LARGE, EXTRALARGE
    }

    public static void main(String[] args) {

        // Creating an EnumSet using allOf()
        EnumSet<Size> sizes1 = EnumSet.allOf(Size.class);

        // Creating an EnumSet using noneOf()
        EnumSet<Size> sizes2 = EnumSet.noneOf(Size.class);

        // Using add method
        sizes2.add(Size.MEDIUM);
        System.out.println("EnumSet Using add(): " + sizes2);

        // Using addAll() method
        sizes2.addAll(sizes1);
        System.out.println("EnumSet Using addAll(): " + sizes2);
    }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>EnumSet using add(): [MEDIUM]</code><br/>
    <code>EnumSet using addAll(): [SMALL, MEDIUM, LARGE, EXTRALARGE]</code>
  </div>
</div>

Trong ví dụ trên, chúng ta đã sử dụng hàm `addAll()` để chèn tất cả các phần tử của `EnumSet Size1` đến `EnumSet Size2`. Ta cũng có thể chèn các phần tử từ các collection khác như `ArrayList`, Link`edList,... để một `EnumSet`bằng cách sử dụng hàm`addAll()`. Tuy nhiên, tất cả các `collection`nên thuộc cùng loại`enum`.

## Truy cập các phần tử của Enumset

Để truy cập các phần tử của `EnumSet`, chúng ta có thể sử dụng hàm `iterator()`. Để sử dụng hàm này, chúng ta phải `import` gói `java.util.Iterator`.

<content-example />

```java
import java.util.EnumSet;
import java.util.Iterator;

class Main {

    enum Size {
        SMALL, MEDIUM, LARGE, EXTRALARGE
    }

    public static void main(String[] args) {

        // Creating an EnumSet using allOf()
        EnumSet<Size> sizes = EnumSet.allOf(Size.class);

        Iterator<Size> iterate = sizes.iterator();

        System.out.print("EnumSet: ");
        while(iterate.hasNext()) {
            System.out.print(iterate.next());
            System.out.print(", ");
        }
    }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>EnumSet: SMALL, MEDIUM, LARGE, EXTRALARGE,</code>
  </div>
</div>

Lưu ý:

- `hasNext()` trả về `true` nếu có phần tử tiếp theo trong `EnumSet`
- `next()` trả về phần tử tiếp theo trong `EnumSet`

## Xóa bỏ các phần tử khỏi Enumset

- `remove()` – xóa phần tử đã chỉ định khỏi `EnumSet`
- `removeAll()` – loại bỏ tất cả các phần tử khỏi `EnumSet`

<content-example />

```java
import java.util.EnumSet;

class Main {

    enum Size {
        SMALL, MEDIUM, LARGE, EXTRALARGE
    }

    public static void main(String[] args) {

        // Creating EnumSet using allOf()
        EnumSet<Size> sizes = EnumSet.allOf(Size.class);
        System.out.println("EnumSet: " + sizes);

        // Using remove()
        boolean value1 = sizes.remove(Size.MEDIUM);
        System.out.println("Is MEDIUM removed? " + value1);

        // Using removeAll()
        boolean value2 = sizes.removeAll(sizes);
        System.out.println("Are all elements removed? " + value2);
    }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>EnumSet: [SMALL, MEDIUM, LARGE, EXTRALARGE]</code><br/>
    <code>Is MEDIUM removed? true</code><br/>
    <code>Are all elements removed? true</code>
  </div>
</div>

## Một số hàm trong Enumset

| Hàm          | Mô tả                                                                    |
| ------------ | ------------------------------------------------------------------------ |
| `copyOf()`   | Tạo một bản sao của `EnumSet`                                            |
| `contains()` | Tìm kiếm phần tử đã chỉ định trong `EnumSet` và trả về kết quả `boolean` |
| `isEmpty()`  | Kiểm tra xem `EnumSet` có trống hay không                                |
| `size()`     | Trả về kích thước của `EnumSet`                                          |
| `clear()`    | Loại bỏ tất cả các phần tử khỏi `EnumSet`                                |
