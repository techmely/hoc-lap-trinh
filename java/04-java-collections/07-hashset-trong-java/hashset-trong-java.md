---
title: "HashSet trong Java"
description: "Các điểm quan trọng về lớp HashSet trong java là HashSet chỉ chứa các phần tử duy nhất, không chấp nhận 2 phần tử trùng nhau, HashSet lưu trữ các phần tử bằng cách sử dụng một cơ chế được gọi là hashing (băm) và không đảm bảo thứ tự được thêm vào, ngoài ra HashSet cho phép chứa phần tử NULL"
chapter:
  name: "Java collections"
  slug: "chuong-04-java-collections"
category:
  name: "Java"
  slug: "java"
image: https://user-images.githubusercontent.com/29374426/144748740-2011fa75-dcf1-40ab-a71a-7a990d52899d.png
position: 7
---

## HashSet trong Java là gì?

Lớp `HashSet` trong Java kế thừa `AbstractSet` và triển khai `Set` Interface. Nó tạo một collection mà sử dụng một hash table để lưu giữ.

Một hash table lưu giữ thông tin bởi sử dụng một kỹ thuật được gọi là hashing (băm). Trong hashing, nội dung mang tính thông tin của một key được sử dụng để quyết định một value duy nhất, được gọi là hash code của nó.

Hash code sau đó được sử dụng như là index, tại đó dữ liệu mà liên kết với key được lưu giữ. Phép biến đổi của key vào trong hash code của nó được thực hiện tự động.

![Tập hợp HashSet trong Java](https://user-images.githubusercontent.com/29374426/144748740-2011fa75-dcf1-40ab-a71a-7a990d52899d.png)

Các điểm quan trọng về lớp `HashSet` trong java là:

- `HashSet` chỉ chứa các phần tử duy nhất, không chấp nhận 2 phần tử trùng nhau.
- `HashSet` lưu trữ các phần tử bằng cách sử dụng một cơ chế được gọi là hashing (băm).
- `HashSet` không đảm bảo thứ tự được thêm vào.
- `HashSet` cho phép chứa phần tử `NULL`.

![phân cấp hashset trong java](https://user-images.githubusercontent.com/29374426/144748790-581eb22c-fb30-43be-a5bd-69656e78bbca.png)

Lớp `java.util.HashSet` được định nghĩa như sau:

```java
public class HashSet<E> extends AbstractSet<E>
        implements Set<E>, Cloneable, java.io.Serializable {
    static final long serialVersionUID = -5024744406713321676L;

    private transient HashMap<E,Object> map;

    private static final Object PRESENT = new Object();

    public HashSet() {
        map = new HashMap<>();
    }
}
```

## Khởi tạo HashSet trong Java

Để tạo HashSet, trước tiên chúng ta phải import gói `java.util.HashSet`.

- `HashSet()`: khởi tạo một danh sách mảng trống.
- `HashSet(Collection c)`: khởi tạo một danh sách với các phần tử của collection c.

```java
HashSet<Integer> numbers = new HashSet<>(8, 0.75);
```

Ở đây, chúng ta đã tạo ra một HashSet có tên numbers.Chú ý, phần HashSet<>(8, 0.75). Ở đây, tham số đầu tiên là capacity và tham số thứ hai là `loadFactor`.

- `capacity` – Dung lượng của HashSet này là 8. Ý nghĩa: nó có thể lưu trữ 8 phần tử.
- `loadFactor` – Hệ số tải của HashSet này là 0,6. Điều này có nghĩ là, khi nào HashSet của chúng ta được lấp đầy 60%, các phần tử được chuyển sang hash table mới có kích thước gấp đôi hash table ban đầu.

Cách thứ 2, có thể tạo hash table mà không cần xác định công suất và hệ số tải của nó.

```java
HashSet<Integer> numbers1 = new HashSet<>();

```

Theo mặc định:

- Công suất của HashSet sẽ là 16
- Hệ số tải sẽ là 0,75

## Thêm phần tử vào Hashset

- `add()` – chèn phần tử được chỉ định vào set
- `addAll()` – chèn tất cả các phần tử của collection đã chỉ định vào `set`

```java
import java.util.HashSet;

class Main {
    public static void main(String[] args) {
        HashSet<Integer> evenNumber = new HashSet<>();

        // Using add() method
        evenNumber.add(2);
        evenNumber.add(4);
        evenNumber.add(6);
        System.out.println("HashSet: " + evenNumber);

        HashSet<Integer> numbers = new HashSet<>();

        // Using addAll() method
        numbers.addAll(evenNumber);
        numbers.add(5);
        System.out.println("New HashSet: " + numbers);
    }
}
```

::result

HashSet: [2, 4, 6]</code><br/>
New HashSet: [2, 4, 5, 6]</code>

::

## Duyệt qua các phần tử trong Hashset

Để truy cập các phần tử của Hashset, chúng ta có thể sử dụng hàm `iterator()`. Để sử dụng hàm này, chúng ta phải import gói `java.util.Iterator`.

```java
import java.util.HashSet;
import java.util.Iterator;

class Main {
    public static void main(String[] args) {
        HashSet<Integer> numbers = new HashSet<>();
        numbers.add(2);
        numbers.add(5);
        numbers.add(6);
        System.out.println("HashSet: " + numbers);

        // Calling iterator() method
        Iterator<Integer> iterate = numbers.iterator();
        System.out.print("HashSet using Iterator: ");
        // Accessing elements
        while(iterate.hasNext()) {
            System.out.print(iterate.next());
            System.out.print(", ");
        }
    }
}
```

::result

HashSet: [2, 5, 6]</code><br/>
HashSet using Iterator: 2, 5, 6,</code>

::

## Xóa các phần tử trong Hashset

- `remove()` – xóa phần tử đã chỉ định khỏi set
- `removeAll()` – loại bỏ tất cả các phần tử khỏi set

```java
import java.util.HashSet;

class Main {
    public static void main(String[] args) {
        HashSet<Integer> numbers = new HashSet<>();
        numbers.add(2);
        numbers.add(5);
        numbers.add(6);
        System.out.println("HashSet: " + numbers);

        // Using remove() method
        boolean value1 = numbers.remove(5);
        System.out.println("Is 5 removed? " + value1);

        boolean value2 = numbers.removeAll(numbers);
        System.out.println("Are all elements removed? " + value2);
    }
}
```

::result

HashSet: [2, 5, 6]</code><br/>
Is 5 removed? true</code><br/>
Are all elements removed? true</code><br/>

::

## Lấy phần hợp trong HashSet

Để lấy phần hợp của 2 set, chúng ta có thể sử dụng hàm `addAll()`.

```java
import java.util.HashSet;

class Main {
    public static void main(String[] args) {
        HashSet<Integer> evenNumbers = new HashSet<>();
        evenNumbers.add(2);
        evenNumbers.add(4);
        System.out.println("HashSet1: " + evenNumbers);

        HashSet<Integer> numbers = new HashSet<>();
        numbers.add(1);
        numbers.add(3);
        System.out.println("HashSet2: " + numbers);

        // Union of two set
        numbers.addAll(evenNumbers);
        System.out.println("Union is: " + numbers);
    }
}
```

::result

HashSet1: [2, 4]</code><br/>
HashSet2: [1, 3]</code><br/>
Union is: [1, 2, 3, 4]</code><br/>

::

## Lấy phần giao trong HashSet

Để lấy phần giao của 2 set, chúng ta có thể sử dụng hàm `retainAll()`.

```java
import java.util.HashSet;

class Main {
    public static void main(String[] args) {
        HashSet<Integer> primeNumbers = new HashSet<>();
        primeNumbers.add(2);
        primeNumbers.add(3);
        System.out.println("HashSet1: " + primeNumbers);

        HashSet<Integer> evenNumbers = new HashSet<>();
        evenNumbers.add(2);
        evenNumbers.add(4);
        System.out.println("HashSet2: " + evenNumbers);

        // Intersection of two sets
        evenNumbers.retainAll(primeNumbers);
        System.out.println("Intersection is: " + evenNumbers);
    }
}
```

::result

HashSet1: [2, 3]</code><br/>
HashSet2: [2, 4]</code><br/>
Intersection is: [2]</code>

::

## Tính hiệu của các set

Để tính hiệu hai set, chúng ta có thể sử dụng hàm `removeAll()`.

```java
import java.util.HashSet;

class Main {
    public static void main(String[] args) {
        HashSet<Integer> primeNumbers = new HashSet<>();
        primeNumbers.add(2);
        primeNumbers.add(3);
        primeNumbers.add(5);
        System.out.println("HashSet1: " + primeNumbers);

        HashSet<Integer> oddNumbers = new HashSet<>();
        oddNumbers.add(1);
        oddNumbers.add(3);
        oddNumbers.add(5);
        System.out.println("HashSet2: " + oddNumbers);

        // Difference between HashSet1 and HashSet2
        primeNumbers.removeAll(oddNumbers);
        System.out.println("Difference : " + primeNumbers);
    }
}
```

::result

HashSet1: [2, 3, 5]</code><br/>
HashSet2: [1, 3, 5]</code><br/>
Difference: [2]</code>

::

## Kiểm tra có phải tập con hay không trong HashSet

Để kiểm tra xem một set có phải là tập con của set khác hay không, chúng ta có thể sử dụng hàm `containsAll()`.

```java
import java.util.HashSet;

class Main {
    public static void main(String[] args) {
        HashSet<Integer> numbers = new HashSet<>();
        numbers.add(1);
        numbers.add(2);
        numbers.add(3);
        numbers.add(4);
        System.out.println("HashSet1: " + numbers);

        HashSet<Integer> primeNumbers = new HashSet<>();
        primeNumbers.add(2);
        primeNumbers.add(3);
        System.out.println("HashSet2: " + primeNumbers);

        // Check if primeNumbers is a subset of numbers
        boolean result = numbers.containsAll(primeNumbers);
        System.out.println("Is HashSet2 is subset of HashSet1? " + result);
    }
}
```

::result

HashSet1: [1, 2, 3, 4]</code><br/>
HashSet2: [2, 3]</code><br/>
Is HashSet2 is a subset of HashSet1? true</code>

::

## Một số hàm khác của Hashset

| Hàm          | Mô tả                                                                |
| ------------ | -------------------------------------------------------------------- |
| `clone()`    | Tạo một bản sao của HashSet                                          |
| `contains()` | Tìm kiếm phần tử đã chỉ định trong HashSet và trả về kết quả boolean |
| `isEmpty()`  | Kiểm tra xem HashSet có trống không                                  |
| `size()`     | Trả về kích thước của HashSet                                        |
| `clear()`    | Loại bỏ tất cả các phần tử khỏi HashSet                              |
