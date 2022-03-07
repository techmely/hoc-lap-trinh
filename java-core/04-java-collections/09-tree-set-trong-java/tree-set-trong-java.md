---
title: "TreeSet trong Java"
description: "Lớp TreeSet trong Java cài đặt (implement) Set Interface, nó sử dụng một cây (tree) cho lưu giữ các phần tử. TreeSet kế thừa lớp (extends) AbstractSet và cài đặt (implement) NavigableSet Interface. Các đối tượng của lớp TreeSet được lưu trữ theo thứ tự tăng dần"
keywords:
  [
    "TreeSet trong Java",
    "Khởi tạo TreeSet trong Java",
    "Tập hợp TreeSet trong Java là gì",
    "Chèn các phần tử vào TreeSet",
    "Duyệt qua các phần tử trong TreeSet",
    "Xóa các phần tử trong TreeSet",
    "Sự khác biệt của các set",
    "Các phương thức khác của TreeSet",
    "So sánh TreeSet và HashSet",
  ]
chapter:
  name: "Java collections"
  slug: "chuong-04-java-collections"
category:
  logo: "/language/java.png"
  name: "Java"
  slug: "java"
  description: "Học Java từ cơ bản đến thông thạo cho mọi đối tượng"
image: https://user-images.githubusercontent.com/29374426/145005207-2c303812-92fc-4e44-bbf0-d4d7119f1117.png
position: 9
---

## Tập hợp TreeSet trong Java là gì?

Lớp `TreeSet` trong Java cài đặt (implement) Set Interface, nó sử dụng một cây (tree) cho lưu giữ các phần tử. TreeSet kế thừa lớp (extends) `AbstractSet` và cài đặt (implement) `NavigableSet Interface`. Các đối tượng của lớp `TreeSet` được lưu trữ theo thứ tự tăng dần.

![TreeSet trong Java là gì](https://user-images.githubusercontent.com/29374426/145005207-2c303812-92fc-4e44-bbf0-d4d7119f1117.png)

Các điểm quan trọng về lớp TreeSet trong java là:

- Chỉ chứa các phần tử duy nhất giống như `HashSet`.
- Duy trì thứ tự tăng dần.
- `TreeSet` không cho phép chứa phần tử null.
- Bạn cần phải cung cấp bộ Comparator trong khi tạo một `TreeSet`. Nếu bạn không cung cấp bộ so sánh (Comparator) cho TreeSet, các phần tử sẽ được đặt theo thứ tự tăng dần.
- `TreeSet` không được đồng bộ. Để có được một TreeSet đồng bộ, hãy sử dụng phương thức Collections.synchronizedSortedSet ().
- Độ phức tạp của `TreeSet` là log(n) cho thao tác thêm (insertion), loại bỏ (removal) và truy xuất (retrieval).
- `TreeSet` sử dụng `TreeMap` để lưu trữ các phần tử, giống như `HashSet` và `LinkedHashSet` sử dụng `HashMap` và `LinkedHashMap` tương ứng để lưu trữ các phần tử của chúng.

## Khởi tạo TreeSet trong Java

- `TreeSet()`: khởi tạo một tập hợp rỗng.
- `TreeSet(Collection c)`: khởi tạo một tập hợp với các phần tử của collection c
- `TreeSet(Comparator comparator)`: khởi tạo một tập hợp rỗng mà các phần tử được xếp thứ tự theo bộ so sánh được xác định bởi comparator.

<div class="example"></div>

```java
TreeSet<Integer> numbers = new TreeSet<>();
```

Ở đây, chúng ta đã tạo một `TreeSet` mà không có bất kỳ đối số nào. Trong trường hợp này, các phần tử trong `TreeSet` được sắp xếp tự nhiên (thứ tự tăng dần).

Tuy nhiên, chúng ta có thể tùy chỉnh việc sắp xếp các phần tử bằng cách sử dụng `Comparator interface`. Chúng ta sẽ tìm hiểu về nó ở phần sau trong hướng dẫn này.

## Chèn các phần tử vào TreeSet

- `add()` – chèn phần tử được chỉ định vào tập hợp.
- `addAll()` – chèn tất cả các phần tử của tập hợp được chỉ định vào tập hợp.

<div class="example"></div>

```java
import java.util.TreeSet;

class Main {
    public static void main(String[] args) {

        TreeSet<Integer> evenNumbers = new TreeSet<>();

        // Using the add() method
        evenNumbers.add(2);
        evenNumbers.add(4);
        evenNumbers.add(6);
        System.out.println("TreeSet: " + evenNumbers);

        TreeSet<Integer> numbers = new TreeSet<>();
        numbers.add(1);

        // Using the addAll() method
        numbers.addAll(evenNumbers);
        System.out.println("New TreeSet: " + numbers);
    }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>TreeSet: [2, 4, 6]</code><br/>
    <code>New TreeSet: [1, 2, 4, 6]</code>
  </div>
</div>

## Duyệt qua các phần tử trong TreeSet

Để truy cập các phần tử của một tập cây, chúng ta có thể sử dụng `iterator()`. Để sử dụng phương thức này, chúng ta phải nhập gói `java.util.Iterator`.

<div class="example"></div>

```java
import java.util.TreeSet;
import java.util.Iterator;

class Main {
    public static void main(String[] args) {
        TreeSet<Integer> numbers = new TreeSet<>();
        numbers.add(2);
        numbers.add(5);
        numbers.add(6);
        System.out.println("TreeSet: " + numbers);

        // Calling iterator() method
        Iterator<Integer> iterate = numbers.iterator();
        System.out.print("TreeSet using Iterator: ");
        // Accessing elements
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
    <code>TreeSet: [2, 5, 6]</code><br/>
    <code>TreeSet using Iterator: 2, 5, 6,</code>
  </div>
</div>

## Xóa các phần tử trong TreeSet

- `remove()` – xóa phần tử được chỉ định khỏi tập hợp
- `removeAll()` – xóa tất cả các phần tử khỏi tập hợp

<div class="example"></div>

```java
import java.util.TreeSet;

class Main {
    public static void main(String[] args) {
        TreeSet<Integer> numbers = new TreeSet<>();
        numbers.add(2);
        numbers.add(5);
        numbers.add(6);
        System.out.println("TreeSet: " + numbers);

        // Using the remove() method
        boolean value1 = numbers.remove(5);
        System.out.println("Is 5 removed? " + value1);

        // Using the removeAll() method
        boolean value2 = numbers.removeAll(numbers);
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
    <code>TreeSet: [2, 5, 6]</code><br/>
    <code>Is 5 removed? true</code><br/>
    <code>Are all elements removed? true</code>
  </div>
</div>

## Phương pháp điều hướng trong TreeSet

Vì lớp TreeSet thực thi NavigableSet, nó cung cấp các phương thức khác nhau để điều hướng qua các phần tử của tập cây.

- `first()` – trả về phần tử đầu tiên của tập hợp
- `last()` – trả về phần tử cuối cùng của tập hợp

<div class="example"></div>

```java
import java.util.TreeSet;

class Main {
    public static void main(String[] args) {
        TreeSet<Integer> numbers = new TreeSet<>();
        numbers.add(2);
        numbers.add(5);
        numbers.add(6);
        System.out.println("TreeSet: " + numbers);

        // Using the first() method
        int first = numbers.first();
        System.out.println("First Number: " + first);

        // Using the last() method
        int last = numbers.last();
        System.out.println("Last Number: " + last);
    }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>TreeSet: [2, 5, 6]</code><br/>
    <code>First Number: 2</code><br/>
    <code>Last Number: 6</code>
  </div>
</div>

- `higher(element)` - Trả về phần tử thấp nhất trong số các phần tử lớn hơn giá trị được chỉ định element.
- `lower(element)` – Trả về phần tử lớn nhất trong số các phần tử nhỏ hơn giá trị được chỉ định element.
- `ceiling(element)` – Trả về phần tử thấp nhất trong số các phần tử lớn hơn giá trị đã chỉ định thành phần. Nếu element được truyền tồn tại trong một tập hợp cây, nó trả về giá trị element được truyền dưới dạng đối số.
- `floor(element)` – Trả về phần tử lớn nhất trong số các phần tử nhỏ hơn giá trị được chỉ định element. Nếu element được truyền tồn tại trong một tập hợp cây, nó trả về giá trị element được truyền dưới dạng đối số.

<div class="example"></div>

```java
import java.util.TreeSet;

class Main {
    public static void main(String[] args) {
        TreeSet<Integer> numbers = new TreeSet<>();
        numbers.add(2);
        numbers.add(5);
        numbers.add(4);
        numbers.add(6);
        System.out.println("TreeSet: " + numbers);

        // Using higher()
        System.out.println("Using higher: " + numbers.higher(4));

        // Using lower()
        System.out.println("Using lower: " + numbers.lower(4));

        // Using ceiling()
        System.out.println("Using ceiling: " + numbers.ceiling(4));

        // Using floor()
        System.out.println("Using floor: " + numbers.floor(3));

    }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>TreeSet: [2, 4, 5, 6]</code><br/>
    <code>Using higher: 5</code><br/>
    <code>Using lower: 2</code><br/>
    <code>Using ceiling: 4</code><br/>
    <code>Using floor: 2</code>
  </div>
</div>

- `pollFirst()` – trả về và xóa phần tử đầu tiên khỏi tập hợp
- `pollLast()` – trả về và xóa phần tử cuối cùng khỏi tập hợp

<div class="example"></div>

```java
import java.util.TreeSet;

class Main {
    public static void main(String[] args) {
        TreeSet<Integer> numbers = new TreeSet<>();
        numbers.add(2);
        numbers.add(5);
        numbers.add(4);
        numbers.add(6);
        System.out.println("TreeSet: " + numbers);

        // Using pollFirst()
        System.out.println("Removed First Element: " + numbers.pollFirst());

        // Using pollLast()
        System.out.println("Removed Last Element: " + numbers.pollLast());

        System.out.println("New TreeSet: " + numbers);
    }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>TreeSet: [2, 4, 5, 6]</code><br/>
    <code>Removed First Element: 2</code><br/>
    <code>Removed Last Element: 6</code><br/>
    <code>New TreeSet: [4, 5]</code>
  </div>
</div>

- `headSet(phần tử, booleanValue)` - trả về tất cả các yếu tố của một bộ cây trước khi quy định thành phần (được chuyển như một đối số). Tham số booleanValue là tùy chọn. Giá trị mặc định của nó là `false`. Nếu `true` được thông qua dưới dạng booleanValue, phương thức trả về tất cả các phần tử trước phần tử được chỉ định bao gồm phần tử được chỉ định.

<div class="example"></div>

```java
import java.util.TreeSet;

class Main {
    public static void main(String[] args) {
        TreeSet<Integer> numbers = new TreeSet<>();
        numbers.add(2);
        numbers.add(5);
        numbers.add(4);
        numbers.add(6);
        System.out.println("TreeSet: " + numbers);

        // Using headSet() with default boolean value
        System.out.println("Using headSet without boolean value: " + numbers.headSet(5));

        // Using headSet() with specified boolean value
        System.out.println("Using headSet with boolean value: " + numbers.headSet(5, true));
    }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>TreeSet: [2, 4, 5, 6]</code><br/>
    <code>Using headSet without boolean value: [2, 4]</code><br/>
    <code>Using headSet with boolean value: [2, 4, 5]</code>
  </div>
</div>

- `tailSet(phần tử, booleanValue)` - phương thức `tailSet()` trả về tất cả các yếu tố của một bộ cây sau khi quy định thành phần (được truyền dưới dạng tham số) bao gồm thành phần. Tham số `booleanValue` là tùy chọn. Giá trị mặc định của nó là `true`. Nếu `false` được thông qua dưới dạng `booleanValue`, phương thức trả về tất cả các phần tử sau thành phần mà không bao gồm các thành phần.

<div class="example"></div>

```java
import java.util.TreeSet;

class Main {
    public static void main(String[] args) {
        TreeSet<Integer> numbers = new TreeSet<>();
        numbers.add(2);
        numbers.add(5);
        numbers.add(4);
        numbers.add(6);
        System.out.println("TreeSet: " + numbers);

        // Using tailSet() with default boolean value
        System.out.println("Using tailSet without boolean value: " + numbers.tailSet(4));

        // Using tailSet() with specified boolean value
        System.out.println("Using tailSet with boolean value: " + numbers.tailSet(4, false));
    }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>TreeSet: [2, 4, 5, 6]</code><br/>
    <code>Using tailSet without boolean value: [4, 5, 6]</code><br/>
    <code>Using tailSet with boolean value: [5, 6]</code>
  </div>
</div>

- `subSet(e1, bv1, e2, bv2)` - phương thức `subSet()` trả về tất cả các yếu tố giữa e1 và e2 kể cả e1. Các bv1 và bv2là các tham số tùy chọn. Giá trị mặc định của bv1 là `true`, và giá trị mặc định của bv2 là `false`. Nếu `false` được truyền vào bv1, phương thức trả về tất cả các phần tử giữa e1 và e2 mà không bao gồm e1. Nếu `true` được truyền vào là bv2, phương thức trả về tất cả các phần tử giữa e1 và e2, kể cả e1.

<div class="example"></div>

```java
import java.util.TreeSet;

class Main {
    public static void main(String[] args) {
        TreeSet<Integer> numbers = new TreeSet<>();
        numbers.add(2);
        numbers.add(5);
        numbers.add(4);
        numbers.add(6);
        System.out.println("TreeSet: " + numbers);

        // Using subSet() with default boolean value
        System.out.println("Using subSet without boolean value: " + numbers.subSet(4, 6));

        // Using subSet() with specified boolean value
        System.out.println("Using subSet with boolean value: " + numbers.subSet(4, false, 6, true));
    }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>TreeSet: [2, 4, 5, 6]</code><br/>
    <code>Using subSet without boolean value: [4, 5]</code><br/>
    <code>Using subSet with boolean value: [5, 6]</code>
  </div>
</div>

## Hoạt động của Set

Các phương thức của lớp `TreeSet` cũng có thể được sử dụng để thực hiện các hoạt động tập hợp khác nhau.

## Liên hiệp các Set

Để thực hiện kết hợp giữa hai tập hợp, chúng ta sử dụng phương thức `addAll()`

<div class="example"></div>

```java
import java.util.TreeSet;;

class Main {
    public static void main(String[] args) {
        TreeSet<Integer> evenNumbers = new TreeSet<>();
        evenNumbers.add(2);
        evenNumbers.add(4);
        System.out.println("TreeSet1: " + evenNumbers);

        TreeSet<Integer> numbers = new TreeSet<>();
        numbers.add(1);
        numbers.add(2);
        numbers.add(3);
        System.out.println("TreeSet2: " + numbers);

        // Union of two sets
        numbers.addAll(evenNumbers);
        System.out.println("Union is: " + numbers);

    }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>TreeSet1: [2, 4]</code><br/>
    <code>TreeSet2: [1, 2, 3]</code><br/>
    <code>Union is: [1, 2, 3, 4]</code>
  </div>
</div>

### Giao điểm của Set

Để thực hiện giao giữa hai tập hợp, ta sử dụng phương thức `retainAll()`.

<div class="example"></div>

```java
import java.util.TreeSet;;

class Main {
    public static void main(String[] args) {
        TreeSet<Integer> evenNumbers = new TreeSet<>();
        evenNumbers.add(2);
        evenNumbers.add(4);
        System.out.println("TreeSet1: " + evenNumbers);

        TreeSet<Integer> numbers = new TreeSet<>();
        numbers.add(1);
        numbers.add(2);
        numbers.add(3);
        System.out.println("TreeSet2: " + numbers);

        // Intersection of two sets
        numbers.retainAll(evenNumbers);
        System.out.println("Intersection is: " + numbers);
    }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>TreeSet1: [2, 4]</code><br/>
    <code>TreeSet2: [1, 2, 3]</code><br/>
    <code>Intersection is: [2]</code>
  </div>
</div>

### Sự khác biệt của các set

Để tính toán sự khác biệt giữa hai tập hợp, chúng ta có thể sử dụng phương thức `removeAll()`

<div class="example"></div>

```java
import java.util.TreeSet;;

class Main {
    public static void main(String[] args) {
        TreeSet<Integer> evenNumbers = new TreeSet<>();
        evenNumbers.add(2);
        evenNumbers.add(4);
        System.out.println("TreeSet1: " + evenNumbers);

        TreeSet<Integer> numbers = new TreeSet<>();
        numbers.add(1);
        numbers.add(2);
        numbers.add(3);
        numbers.add(4);
        System.out.println("TreeSet2: " + numbers);

        // Difference between two sets
        numbers.removeAll(evenNumbers);
        System.out.println("Difference is: " + numbers);
    }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>TreeSet1: [2, 4]</code><br/>
    <code>TreeSet2: [1, 2, 3, 4]</code><br/>
    <code>Difference is: [1, 3]</code>
  </div>
</div>

### Tập hợp con của một Tập hợp

Để kiểm tra một tập hợp có phải là tập hợp con của tập hợp khác hay không, chúng ta sử dụng phương thức `containsAll()`

<div class="example"></div>

```java
import java.util.TreeSet;

class Main {
    public static void main(String[] args) {
        TreeSet<Integer> numbers = new TreeSet<>();
        numbers.add(1);
        numbers.add(2);
        numbers.add(3);
        numbers.add(4);
        System.out.println("TreeSet1: " + numbers);

        TreeSet<Integer> primeNumbers = new TreeSet<>();
        primeNumbers.add(2);
        primeNumbers.add(3);
        System.out.println("TreeSet2: " + primeNumbers);

        // Check if primeNumbers is subset of numbers
        boolean result = numbers.containsAll(primeNumbers);
        System.out.println("Is TreeSet2 subset of TreeSet1? " + result);
    }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>TreeSet1: [1, 2, 3, 4]</code><br/>
    <code>TreeSet2: [2, 3]</code><br/>
    <code>Is TreeSet2 subset of TreeSet1? True</code>
  </div>
</div>

## Các phương thức khác của TreeSet

| Phương thức | Sự miêu tả |
| --- | --- |
| clone() | Tạo một bản sao của TreeSet |
| contains() | Tìm kiếm TreeSet cho phần tử được chỉ định và trả về kết quả Boolean |
| isEmpty() | Kiểm tra xem TreeSet có trống không |
| size() | Trả về kích thước của TreeSet |
| clear() | Loại bỏ tất cả các phần tử khỏi TreeSet |

## So sánh TreeSet và HashSet

Cả hai TreeSet cũng như HashSet đều triển khai từ Set interface. Tuy nhiên, tồn tại một số khác biệt giữa chúng.

- Không giống như `HashSet`, các phần tử trong TreeSet được lưu trữ theo một số thứ tự. Đó là bởi vì `TreeSet` thực hiện `SortedSet` interface là tốt.
- `TreeSet` cung cấp một số phương thức để điều hướng dễ dàng. Ví dụ, `first()`, `last()`, `headSet()`, `tailSet()`... Đó là bởi vì `TreeSet` cũng thực hiện các `NavigableSet` interface.
- `HashSet` nhanh hơn so TreeSet với các thao tác cơ bản như thêm, bớt, chứa và kích thước.
