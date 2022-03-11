---
title: "ArrayList trong Java"
description: "Bài này chúng ta sẽ tìm hiểu về List trong Java, chia sẻ kiến thức về java"
keywords: []
chapter:
  name: "Java collections"
  slug: "chuong-04-java-collections"
category:
  name: "Java"
  slug: "java"
image: https://viettuts.vn/images/java/java-collection/hiararchy-lop-arraylist-trong-java.png
position: 3
---

Trong Java, chúng ta cần khai báo độ dài của một mảng trước khi sử dụng. Khi đã khai báo kích thước của một mảng rồi thì rất khó để thay đổi kích thước đó. Để xử lý vấn đề này, chúng ta có thể sử dụng lớp `ArrayList`.Các lớp `ArrayList` có mặt trong gói `java.util` cho phép chúng ta tạo ra các mảng có thể thay đổi kích thước.

Không giống như mảng, ArrayList (đối tượng của class ArrayList) có thể tự động điều chỉnh kích cỡ của nó khi chúng ta thêm vào hoặc xóa đi các phần tử. Do đó, ArrayList còn được gọi là mảng động.

**Những điểm về ArrayList:**

- Lớp ArrayList trong java có thể chứa các phần tử trùng lặp.
- Lớp ArrayList duy trì thứ tự của phần tử được thêm vào.
- Lớp ArrayList là không đồng bộ (non-synchronized).
- Lớp ArrayList cho phép truy cập ngẫu nhiên vì nó lưu dữ liệu theo chỉ mục.
- Lớp ArrayList trong java, thao tác chậm vì cần nhiều sự dịch chuyển nếu bất kỳ phần tử nào bị xoá khỏi danh sách.

## Khởi tạo một ArrayList

Khởi tạo ArrayList trong java ta sử dụng cú pháp sau

```java
ArrayList<Type> arrayList= new ArrayList<>();
```

Trong đó `Type` là kiểu dữ liệu của `ArrayList` mà ta muốn tạo

<content-example />

```java
// create Integer type arraylist
ArrayList<Integer> arrayList = new ArrayList<>();

// create String type arraylist
ArrayList<String> arrayList = new ArrayList<>();
```

## Constructor của lớp ArrayList

| Constructor             | Mô tả                                                                                          |
| ----------------------- | ---------------------------------------------------------------------------------------------- |
| ArrayList()             | Nó được sử dụng để khởi tạo một danh sách mảng trống.                                          |
| ArrayList(Collection c) | Nó được sử dụng để xây dựng một danh sách mảng được khởi tạo với các phần tử của collection c. |
| ArrayList(int capacity) | Nó được sử dụng để xây dựng một danh sách mảng mà có dung lượng ban đầu được chỉ định.         |

## Phương thức của lớp ArrayList

### Thêm một phần tử vào ArrayList

Để thêm một phần tử vào ArrayList, chúng ta sử dụng hàm `add()`

```java
import java.util.ArrayList;

class Main {
  public static void main(String[] args){
      ArrayList<String> animals = new ArrayList<>();
    // Add elements
    animals.add("Dog");
    animals.add("Cat");
    animals.add("Horse");
    System.out.println("ArrayList: " + animals);
  }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>ArrayList: [Dog, Cat, Horse]</code><br/>
  </div>
</div>

Hoặc ta cũng có thể thêm nhiều phần tử vào một `ArrayList` bằng cách sử dụng các chỉ số

```java
import java.util.ArrayList;

class Main {
  public static void main(String[] args){
    ArrayList<String> animals = new ArrayList<>();
    // Add elements
    animals.add(0,"Dog");
    animals.add(1,"Cat");
    animals.add(2,"Horse");
    System.out.println("ArrayList: " + animals);
  }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>ArrayList: [Dog, Cat, Horse]</code><br/>
  </div>
</div>

### Thêm tất cả các phần tử từ ArrayList này sang ArrayList khác

Để thêm tất cả các phần tử của `ArrayList` này vào một `ArrayList` mới, chúng ta sử dụng hàm `addAll()`.

```java
import java.util.ArrayList;

class Main {
  public static void main(String[] args){
    ArrayList<String> mammals = new ArrayList<>();
    mammals.add("Dog");
    mammals.add("Cat");
    mammals.add("Horse");
    System.out.println("Mammals: " + mammals);

    ArrayList<String> animals = new ArrayList<>();
    animals.add("Crocodile");

    // Add all elements of mammals in animals
    animals.addAll(mammals);
    System.out.println("Animals: " + animals);
  }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>Mammals: [Dog, Cat, Horse]</code><br/>
    <code>Animals: [Crocodile, Dog, Cat, Horse]</code><br/>
  </div>
</div>

### Truy cập tới các phần tử trong ArrayList

Để truy cập ngẫu nhiên các phần tử của `ArrayList`, chúng ta sử dụng hàm `get()`

```java
import java.util.ArrayList;

class Main {
  public static void main(String[] args) {
    ArrayList<String> animals= new ArrayList<>();
    // Add elements in the array list
    animals.add("Dog");
    animals.add("Horse");
    animals.add("Cat");
    System.out.println("ArrayList: " + animals);
    // Get the element from the array list
    String str = animals.get(0);
    System.out.print("Element at index 0: " + str);
  }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>ArrayList: [Dog, Horse, Cat]</code><br/>
    <code>Element at index 0: Dog</code><br/>
  </div>
</div>

Để truy cập các phần tử của ArrayList một cách tuần tự, chúng ta sử dụng hàm `iterator()`. Chúng ta phải nhập gói `java.util.Iterator` để sử dụng hàm này

```java
import java.util.ArrayList;
import java.util.Iterator;

class Main {
  public static void main(String[] args){
    ArrayList<String> animals = new ArrayList<>();
    // Add elements in the array list
    animals.add("Dog");
    animals.add("Cat");
    animals.add("Horse");
    animals.add("Zebra");
    // Create an object of Iterator
    Iterator<String> iterate = animals.iterator();
    System.out.print("ArrayList: ");
    // Use methods of Iterator to access elements
    while(iterate.hasNext()){
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
    <code>ArrayList: Dog, Cat, Horse, Zebra,</code><br/>
  </div>
</div>

<content-info>
<ul>
  <li>Hàm hasNext() trả về true nếu có một phần tử tiếp theo trong ArrayList.</li>
  <li>Hàm next() trả về phần tử tiếp theo trong ArrayList.</li>
</ul>
</content-info>

### Thay đổi phần tử trong ArrayList

Để thay đổi các phần tử của ArrayList, chúng ta có thể sử dụng hàm `set()` để cập nhật nội dung phần tử trong ArrayList.

```java
import java.util.ArrayList;

class Main {
  public static void main(String[] args) {
    ArrayList<String> animals= new ArrayList<>();
    // Add elements in the array list
    animals.add("Dog");
    animals.add("Cat");
    animals.add("Horse");
    System.out.println("ArrayList: " + animals);
    // Change the element of the array list
    animals.set(2, "Zebra");
    System.out.println("Modified ArrayList: " + animals);
  }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>ArrayList: [Dog, Cat, Horse]</code><br/>
    <code>Modified ArrayList: [Dog, Cat, Zebra]</code><br/>
  </div>
</div>

### Xóa phần tử trong ArrayList

Để loại bỏ một phần tử khỏi ArrayList, chúng ta có thể sử dụng hàm `remove()`.

```java
import java.util.ArrayList;

class Main {
  public static void main(String[] args) {
    ArrayList<String> animals = new ArrayList<>();
    // Add elements in the array list
    animals.add("Dog");
    animals.add("Cat");
    animals.add("Horse");
    System.out.println("Initial ArrayList: " + animals);
    // Remove element from index 2
    String str = animals.remove(2);
    System.out.println("Final ArrayList: " + animals);
    System. out.println("Removed Element: " + str);
  }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>Initial ArrayList: [Dog, Cat, Horse]</code><br/>
    <code>Final ArrayList: [Dog, Cat]</code><br/>
    <code>Removed Element: Horse</code><br/>
  </div>
</div>

Ngoài ra, nếu bạn muốn loại bỏ tất cả các phần tử khỏi ArrayList, chúng ta sử dụng hàm `removeAll()`

```java
import java.util.ArrayList;

class Main {
  public static void main(String[] args) {
    ArrayList<String> animals = new ArrayList<>();
    // Add elements in the ArrayList
    animals.add("Dog");
    animals.add("Cat");
    animals.add("Horse");
    System.out.println("Initial ArrayList: " + animals);
    // Remove all the elements
    animals.removeAll(animals);
    System.out.println("Final ArrayList: " + animals);
  }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>Initial ArrayList: [Dog, Cat, Horse]</code><br/>
    <code>Final ArrayList: []</code><br/>
  </div>
</div>

Thêm một hàm nữa là hàm `clear()` để loại bỏ tất cả các phần tử khỏi ArrayList.

```java
import java.util.ArrayList;

class Main {
  public static void main(String[] args) {
    ArrayList<String> animals= new ArrayList<>();
    // Add elements in the array list
    animals.add("Dog");
    animals.add("Cat");
    animals.add("Horse");
    System.out.println("Initial ArrayList: " + animals);
    // Remove all the elements
    animals.clear();
    System.out.println("Final ArrayList: " + animals);
  }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>Initial ArrayList: [Dog, Cat, Horse]</code><br/>
    <code>Final ArrayList: []</code><br/>
  </div>
</div>

### Lặp qua các phần tử trong ArrayList

Cách thứ nhất chúng ta có thể sử dụng hàm for thông thường để lặp qua các phần tử

```java
import java.util.ArrayList;

class Main {
  public static void main(String[] args) {
    // Creating an array list
    ArrayList<String> animals = new ArrayList<>();
    animals.add("Cow");
    animals.add("Cat");
    animals.add("Dog");
    System.out.println("ArrayList: " + animals);
    // Using for loop
    System.out.print("Accessing individual elements: ");
    for(int i = 0; i < animals.size(); i++) {
        System.out.print(animals.get(i));
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
    <code>ArrayList: [Cow, Cat, Dog]</code><br/>
    <code>Accessing individual elements: Cow, Cat, Dog,</code><br/>
  </div>
</div>

Cách thứ hai là chúng ta có thể sử dụng forEach để lặp qua các phần tử của ArrayList

```java
import java.util.ArrayList;

class Main {
  public static void main(String[] args) {
    // Creating an array list
    ArrayList<String> animals = new ArrayList<>();
    animals.add("Cow");
    animals.add("Cat");
    animals.add("Dog");
    System.out.println("ArrayList: " + animals);
    // Using forEach loop
    System.out.print("Accessing individual elements:  ");
    for(String animal : animals) {
        System.out.print(animal);
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
    <code>ArrayList: [Cow, Cat, Dog]</code><br/>
    <code>Accessing individual elements: Cow, Cat, Dog,</code><br/>
  </div>
</div>

### Kiểm tra độ dài của ArrayList

Để có thể lấy số lượng các phần tử của một ArrayList chúng ta có thể sử dụng hàm `size()`

```java
import java.util.ArrayList;

class Main {
  public static void main(String[] args) {
    ArrayList<String> animals= new ArrayList<>();
    // Adding elements in the arrayList
    animals.add("Dog");
    animals.add("Horse");
    animals.add("Cat");
    System.out.println("ArrayList: " + animals);
    // getting the size of the arrayList
    System.out.println("Size: " + animals.size());
  }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>ArrayList: [Dog, Horse, Cat]</code><br/>
    <code>Size: 3</code><br/>
  </div>
</div>

### Sắp xếp các phần tử của một ArrayList

Để sắp xếp các phần tử của một ArrayList, chúng ta sử dụng hàm `sort()` của class Collections. Theo mặc định, việc sắp xếp xảy ra theo thứ tự bảng chữ cái hoặc thứ tự số theo chiều tăng dần.

```java
import java.util.ArrayList;
import java.util.Collections;

class Main {
  public static void main(String[] args){
    ArrayList<String> animals= new ArrayList<>();
    // Add elements in the array list
    animals.add("Horse");
    animals.add("Zebra");
    animals.add("Dog");
    animals.add("Cat");
    System.out.println("Unsorted ArrayList: " + animals);
    // Sort the array list
    Collections.sort(animals);
    System.out.println("Sorted ArrayList: " + animals);
  }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>Unsorted ArrayList: [Horse, Zebra, Dog, Cat]</code><br/>
    <code>Sorted ArrayList: [Cat, Dog, Horse, Zebra]</code><br/>
  </div>
</div>

### Cách chuyển một ArrayList thành một mảng Array trong Java

Trong Java, chúng ta có thể chuyển đổi ArrayList thành một Array bằng hàm `toArray()`

```java
import java.util.ArrayList;

class Main {
  public static void main(String[] args) {
    ArrayList<String> animals= new ArrayList<>();
    // Add elements in the array list
    animals.add("Dog");
    animals.add("Cat");
    animals.add("Horse");
    System.out.println("ArrayList: " + animals);
    // Create a new array of String type
    String[] arr = new String[animals.size()];
    // Convert ArrayList into an array
    animals.toArray(arr);
    System.out.print("Array: ");
    for(String item:arr) {
      System.out.print(item+", ");
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
    <code>ArrayList: [Dog, Cat, Horse]</code><br/>
    <code>Array: Dog, Cat, Horse,</code><br/>
  </div>
</div>

### Chuyển mảng thành ArrayList trong Java

Chúng ta cũng có thể chuyển đổi Array thành một ArrayList, để làm được điều này chúng ta có thể sử dụng hàm `asList()` của class Array.

```java
import java.util.ArrayList;
import java.util.Arrays;

class Main {
  public static void main(String[] args) {
    // Create an array of String type
    String[] arr = {"Dog", "Cat", "Horse"};
    System.out.print("Array: ");
    // Print array
    for(String str: arr) {
        System.out.print(str);
        System.out.print(" ");
    }
    // Create an ArrayList from an array
    ArrayList<String> animals = new ArrayList<>(Arrays.asList(arr));
    System.out.println("\nArrayList: " + animals);
  }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>Array: Dog, Cat, Horse</code><br/>
    <code>ArrayList: [Dog, Cat, Horse]</code><br/>
  </div>
</div>

### Chuyển ArrayList thành String trong Java

Để chuyển đổi một Java thành String, chúng ta có thể sử dụng hàm `toString()`

```java
import java.util.ArrayList;

class Main {
  public static void main(String[] args) {
    ArrayList<String> animals = new ArrayList<>();
    // Add elements in the ArrayList
    animals.add("Dog");
    animals.add("Cat");
    animals.add("Horse");
    System.out.println("ArrayList: " + animals);
    // Convert ArrayList into an String
    String str = animals.toString();
    System.out.println("String: " + str);
  }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>ArrayList: [Dog, Cat, Horse]</code><br/>
    <code>String: [Dog, Cat, Horse]</code><br/>
  </div>
</div>

### Một số hàm trong ArrayList

| Hàm              | Mô tả                                                                            |
| ---------------- | -------------------------------------------------------------------------------- |
| clone()          | Tạo một ArrayList mới với cùng phần tử, kích thước và dung lượng.                |
| contains()       | Tìm kiếm ArrayList cho phần tử đã chỉ định và trả về kết quả boolean.            |
| ensureCapacity() | Chỉ định tổng phần tử mà ArrayList có thể chứa.                                  |
| isEmpty()        | Kiểm tra nếu ArrayList trống.                                                    |
| indexOf()        | Tìm kiếm một phần tử được chỉ định trong ArrayList và trả về chỉ số của phần tử. |
| trimToSize()     | Giảm dung lượng của một ArrayList về kích thước hiện tại của nó.                 |
