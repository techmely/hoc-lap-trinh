---
title: "LinkedList trong java"
description: "LinkedList là một cấu trúc dữ liệu tuyến tính. Các phần tử trong LinkedList không được lưu trữ liền kề nhau giống như arrays. Mỗi phần tử trong LinkedList liên kết với nhau bằng một con trỏ, nghĩa là mỗi phần tử sẽ tham chiếu đến địa chỉ của phần tử tiếp theo."
keywords:
  [
    "linkedlist trong java",
    "ví dụ về linkedlist trong java",
    "danh sách liên kết trong java",
    "danh sách liên kết đơn trong java",
    "linked list trong java",
  ]
author:
  fullname: Techmely Team
  username: Techmely Team
  avatar: "/configs/author/logo.jpg"
chapter:
  name: "Java collections"
  slug: "chuong-04-java-collections"
category:
  logo: "/language/java.png"
  name: "Java"
  slug: "java"
  description: "Học Java từ cơ bản đến thông thạo cho mọi đối tượng"
image: https://user-images.githubusercontent.com/29374426/143202802-fb867763-f54b-40e5-9d4a-64be9ea60016.png
position: 4
---

**LinkedList** là một cấu trúc dữ liệu tuyến tính. Các phần tử trong LinkedList không được lưu trữ liền kề nhau giống như arrays. Mỗi phần tử trong LinkedList liên kết với nhau bằng một con trỏ, nghĩa là mỗi phần tử sẽ tham chiếu đến địa chỉ của phần tử tiếp theo.

## Sử dụng LinkedList trong Java

Class LinkedList trong Java triển khai danh sách liên kết đôi. Mỗi phần tử trong một LinkedList được gọi là một nút .

![Sử dụng LinkedList trong Java](https://user-images.githubusercontent.com/29374426/143202802-fb867763-f54b-40e5-9d4a-64be9ea60016.png)

Nó bao gồm 3 trường:

- **Prev** – Lưu địa chỉ của phần tử trước trong list. Trả về null đối với các phần tử đầu tiên.
- **Next** – Lưu trữ địa chỉ của phần tử tiếp theo trong danh sách. Trả về null đối với các phần tử cuối cùng.
- **Data** – Lưu trữ dữ liệu thực.

Các phần tử trong **LinkedList** không được lưu trữ theo trình tự. Thay vào đó, chúng nằm rải rác và được kết nối thông qua các liên kết (Prev và Next).

![Triển khai LinkedList trong Java](https://user-images.githubusercontent.com/29374426/143202928-a03de807-a606-47a6-8eef-6bd173da364c.png)

Ở đây chúng ta có 3 phần tử trong một LinkedList:

- Dog – đây là phần tử đầu tiên, phần tử của địa chỉ trước là null và phần tử của địa chỉ tiếp theo là Cat
- Cat – đây là phần tử thứ hai, phần tử của địa chỉ trước là Dog và phần tử của địa chỉ tiếp theo là Cow
- Cow – đây là phần tử cuối cùng, phần tử địa chỉ trước là Cat và phần tử của địa chỉ tiếp theo là null

## Cách tạo một LinkedList trong Java

Đây là cách chúng ta có thể tạo các LinkedList trong Java:

```java
LinkedList<Type> linkedList = new LinkedList<>();
```

Ở đây, Type là kiểu của LinkedList. Ví dụ:

```java
// create Integer type linked list
LinkedList<Integer> linkedList = new LinkedList<>();

// create String type linked list
LinkedList<String> linkedList = new LinkedList<>();
```

## Tạo LinkedList bằng cách sử dụng Interface

```java
List<String> animals1 = new LinkedList<>();
```

Ở đây chúng ta đã khai báo một LinkedList animals1, bằng cách sử dụng List interface. LinkedList chỉ có thể truy cập các hàm của List interface. Thêm một ví dụ nữa nhé:

```java
Queue<String> animals2 = new LinkedList<>();
Deque<String> animals3 = new LinkedList<>();
```

Ở đây, animals2 có thể truy cập các hàm của Queue interface. Tuy nhiên, animals3 chỉ có thể truy cập các hàm của Dequevà Queue interface. Đó là bởi vì Deque là một subinterface của Queue.

## Thêm các phần tử vào LinkedList

Để thêm một phần tử (nút) vào cuối LinkedList, chúng ta sử dụng hàm add(). Ví dụ:

```java
import java.util.LinkedList;

class Main {
    public static void main(String[] args){
        LinkedList<String> animals = new LinkedList<>();

        // Add elements to LinkedList
        animals.add("Dog");
        animals.add("Cat");
        animals.add("Horse");
        System.out.println("LinkedList: " + animals);
    }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>LinkedList: [Dog, Cat, Horse]</code><br/>
  </div>
</div>

## Thêm phần tử từ LinkedList này sang LinkedList khác

Để thêm tất cả các phần tử từ LinkedList này sang LinkedList khác, chúng ta sử dụng hàm `addAll()`. Ví dụ:

```java
import java.util.LinkedList;

class Main {
    public static void main(String[] args){
        LinkedList<String> mammals = new LinkedList<>();

        mammals.add("Dog");
        mammals.add("Cat");
        mammals.add("Horse");
        System.out.println("Mammals: " + mammals);

        LinkedList<String> animals = new LinkedList<>();
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

Ngoài ra, chúng ta cũng có thể sử dụng hàm `listsIterator()` để thêm các phần tử vào LinkedList. Để sử dụng nó, chúng ta phải nhập vào gói `java.util.ListIterator`. Ví dụ:

```java
import java.util.ArrayList;
import java.util.ListIterator;

class Main {
    public static void main(String[] args) {
        ArrayList<String> animals= new ArrayList<>();

        // Creating an object of ListIterator
        ListIterator<String> listIterate = animals.listIterator();
        listIterate.add("Dog");
        listIterate.add("Cat");

        System.out.println("LinkedList: " + animals);
    }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>LinkedList: [Dog, Cat]</code><br/>
  </div>
</div>

## Truy cập tới các phần tử trong LinkedList

Để truy cập một phần tử từ LinkedList, chúng ta có thể sử dụng hàm `get()`. Ví dụ:

```java
import java.util.LinkedList;

class Main {
    public static void main(String[] args) {
        LinkedList<String> animals= new LinkedList<>();

        // Add elements in the linked list
        animals.add("Dog");
        animals.add("Horse");
        animals.add("Cat");
        System.out.println("LinkedList: " + animals);

        // Get the element from the linked list
        String str = animals.get(1);
        System.out.print("Element at index 1: " + str);
    }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>LinkedList: [Dog, Horse, Cat]</code><br/>
    <code>Element at index 1: Horse</code><br/>
  </div>
</div>

Ngoài cách này ra, để lặp lại các phần tử của LinkedList, chúng ta có thể sử dụng hàm `iterator()`. Chúng ta phải nhập gói `java.util.Iterator` để sử dụng hàm này. Ví dụ:

```java
import java.util.LinkedList;
import java.util.Iterator;

class Main {
    public static void main(String[] args) {
        LinkedList<String> animals= new LinkedList<>();

        // Add elements in LinkedList
        animals.add("Dog");
        animals.add("Horse");
        animals.add("Cat");

        // Creating an object of Iterator
        Iterator<String> iterate = animals.iterator();
        System.out.print("LinkedList: ");

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
    <code>LinkedList: Dog, Cat, Horse,</code><br/>
  </div>
</div>

Ở đây:

- Hàm `hasNext()`- trả về true nếu có phần tử tiếp theo
- Hàm `next()` – trả về phần tử tiếp theo

Chúng ta cũng có thể sử dụng hàm `listIterator()` để lặp lại các phần tử của LinkedList. Để sử dụng hàm này, chúng ta phải nhập gói `java.util.ListIterator`. Hàm `listsIterator()` được ưa chuộng hơn trong LinkedList. Đó là bởi vì các đối tượng `listIterator()` cũng có thể lặp theo chiều lại. Ví dụ:

```java
import java.util.LinkedList;
import java.util.ListIterator;

class Main {
    public static void main(String[] args) {
        LinkedList<String> animals= new LinkedList<>();

        // Add elements in LinkedList
        animals.add("Dog");
        animals.add("Horse");
        animals.add("Cat");

        // Create an object of ListIterator
        ListIterator<String> listIterate = animals.listIterator();
        System.out.print("LinkedList: ");

        while(listIterate.hasNext()) {
            System.out.print(listIterate.next());
            System.out.print(", ");
        }

        // Iterate backward
        System.out.print("\nReverse LinkedList: ");

        while(listIterate.hasPrevious()) {
            System.out.print(listIterate.previous());
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
    <code>LinkedList: Dog, Horse, Cat,</code><br/>
    <code>Reverse LinkedList: Cat, Horse, Dog,</code><br/>
  </div>
</div>

Ở đây:

- Hàm `hasNext()` trả về true nếu có phần tử tiếp theo
- Hàm `next()` trả về phần tử tiếp theo
- Hàm `hasPrevious()` trả về true nếu có các phần tử trước
- Hàm `previous()` trả về phần tử trước

## Tìm kiếm các phần tử trong LinkedList

Để kiểm tra xem LinkedList có chứa một phần tử cụ thể hay không, chúng ta sử dụng hàm `contains()`. Ví dụ:

```java
import java.util.LinkedList;

class Main {
    public static void main(String[] args) {
        LinkedList<String> animals= new LinkedList<>();

        // Add elements in the linked list
        animals.add("Dog");
        animals.add("Horse");
        animals.add("Cat");
        System.out.println("LinkedList: " + animals);

        // Checks if Dog is in the linked list
        if(animals.contains("Dog")) {
            System.out.println("Dog is in LinkedList.");
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
    <code>LinkedList: [Dog, Horse, Cat]</code><br/>
    <code>Dog is in LinkedList.</code><br/>
  </div>
</div>

## Tìm kiếm vị trí phần tử trong LinkedList

- Hàm `indexOf()` – trả về chỉ số xuất hiện đầu tiên của một phần tử, trả về -1 nếu không tìm thấy phần tử đã chỉ định.
- Hàm `lastIndexOf()` – trả về chỉ số của lần xuất hiện cuối cùng của một phần tử, trả về -1 nếu không tìm thấy phần tử đã chỉ định.

```java
import java.util.LinkedList;

class Main {
    public static void main(String[] args) {
        LinkedList<String> animals= new LinkedList<>();

        // Add elements in the linked list
        animals.add("Dog");
        animals.add("Horse");
        animals.add("Cat");
        animals.add("Dog");
        System.out.println("LinkedList: " + animals);

        // First Occurrence of Dog
        int index1 = animals.indexOf("Dog");
        System.out.println("First Occurrence of Dog: " + index1);

        // Last Occurrence of Dog
        int index2 = animals.lastIndexOf("Dog");
        System.out.println("Last Occurrence of Dog: " + index2);
    }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>LinkedList: [Dog, Horse, Cat, Dog]</code><br/>
    <code>First Occurrence of Dog: 0</code><br/>
    <code>Last Occurrence of Dog: 3</code><br/>
  </div>
</div>

## Thay đổi các phần tử trong LinkedList

Để thay đổi các phần tử của LinkedList, chúng ta có thể sử dụng hàm `set()`. Ví dụ:

```java
import java.util.LinkedList;

class Main {
    public static void main(String[] args) {
        LinkedList<String> animals= new LinkedList<>();

        // Add elements in the linked list
        animals.add("Dog");
        animals.add("Horse");
        animals.add("Cat");
        animals.add("Dog");
        System.out.println("LinkedList: " + animals);

        // Change elements at index 3
        animals.set(3, "Zebra");
        System.out.println("New LinkedList: " + animals);
    }
}
```

Chúng ta cũng có thể thay đổi các phần tử trong LinkedList bằng cách sử dụng hàm `listIterator()`. Ví dụ:

```java
import java.util.ArrayList;
import java.util.ListIterator;

class Main {
    public static void main(String[] args) {
        ArrayList<String> animals= new ArrayList<>();

        // Add elements
        animals.add("Dog");
        animals.add("Cat");
        animals.add("Horse");
        System.out.println("LinkedList: " + animals);

        // Creating an object of ListIterator
        ListIterator<String> listIterate = animals.listIterator();
        listIterate.next();

        // Change element returned by next()
        listIterate.set("Cow");
        System.out.println("New LinkedList: " + animals);
    }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>LinkedList: [Dog, Cat, Horse]</code><br/>
    <code>New LinkedList: [Cow, Cat, Horse]</code><br/>
  </div>
</div>

## Xóa các phần tử khỏi LinkedList

Để xóa một phần tử khỏi LinkedList, chúng ta có thể sử dụng hàm `remove()`. Ví dụ:

```java
import java.util.LinkedList;

class Main {
    public static void main(String[] args) {
        LinkedList<String> animals= new LinkedList<>();

        // Add elements in LinkedList
        animals.add("Dog");
        animals.add("Horse");
        animals.add("Cat");
        animals.add("Zebra");
        System.out.println("LinkedList: " + animals);

        // Remove elements from index 1
        String str = animals.remove(1);
        System.out.println("Removed Element: " + str);

        System.out.println("New LinkedList: " + animals);
    }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>LinkedList : [Dog, Horse, Cat, Zebra]</code><br/>
    <code>Removed Element: Horse</code><br/>
    <code>New LinkedList: [Dog, Cat, Zebra]</code><br/>
  </div>
</div>

Chúng ta cũng có thể xóa các phần tử khỏi LinkedList bằng hàm `listsIterator()`. Ví dụ:

```java
import java.util.ArrayList;
import java.util.ListIterator;

class Main {
    public static void main(String[] args) {
        ArrayList<String> animals= new ArrayList<>();

        // Add elements
        animals.add("Dog");
        animals.add("Cat");
        animals.add("Horse");
        System.out.println("LinkedList: " + animals);

        // Creating an object of ListIterator
        ListIterator<String> listIterate = animals.listIterator();
        listIterate.next();

        // Remove element returned by next()
        listIterate.remove();
        System.out.println("New LinkedList: " + animals);
    }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>LinkedList: [Dog, Cat, Horse]</code><br/>
    <code>New LinkedList: [Cat, Horse]</code><br/>
  </div>
</div>

Ngoài ra, để xóa tất cả các phần tử khỏi LinkedList, chúng ta có thể sử dụng hàm `clear()`. Ví dụ:

```java
import java.util.LinkedList;

class Main {
    public static void main(String[] args) {
        LinkedList<String> animals= new LinkedList<>();

        // Add elements in LinkedList
        animals.add("Dog");
        animals.add("Cat");
        animals.add("Horse");
        System.out.println("LinkedList: " + animals);

        // Remove all the elements
        animals.clear();
        System.out.println("New LinkedList: " + animals);
    }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>LinkedList: [Dog, Cat, Horse]</code><br/>
    <code>New LinkedList: []</code><br/>
  </div>
</div>

Lưu ý: Chúng ta cũng có thể sử dụng hàm `removeAll()`để loại bỏ tất cả các phần tử. Tuy nhiên, hàm `clear()` được cho là hiệu quả hơn hàm `removeAll()`.

Chúng ta cũng có thể xóa các phần tử khỏi LinkedList nếu chúng thỏa mãn một điều kiện nhất định. Để làm điều này, chúng ta sử dụng hàm `removeIf()`. Ví dụ:

```java
import java.util.LinkedList;

class Main {
    public static void main(String[] args) {
        LinkedList<Integer> animals= new LinkedList<>();

        // Add elements in LinkedList
        animals.add(2);
        animals.add(3);
        animals.add(4);
        animals.add(5);
        System.out.println("LinkedList: " + animals);

        // Remove all elements less than 4
        animals.removeIf((Integer i)->i < 4);
        System.out.println("New LinkedList: " + animals);

       /** Here we have used the lambda expression
         * For now just remember
         * parameter inside removeIf() is a condition
         */
    }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>LinkedList: [2, 3, 4, 5]</code><br/>
    <code>New LinkedList: [4, 5]</code><br/>
  </div>
</div>

Lưu ý: `(Integer i)->i<4` là một biểu thức lambda. Để tìm hiểu về biểu thức lambda, hãy truy cập Biểu thức Lambda của Java .

## Deque và Queue trong LinkedList

Vì class LinkedList cũng triển khai Queue interface và Deque interface, nó cũng có thể thực hiện các hàm của các interface này. Dưới đây là một số hàm thường được sử dụng:

- Hàm `addFirst()` – thêm phần tử được chỉ định vào đầu LinkedList
- Hàm `addLast()` – thêm phần tử được chỉ định vào cuối LinkedList

Ví dụ:

```java
import java.util.LinkedList;
import java.util.Deque;

class Main {
    public static void main(String[] args){
        Deque<String> animals = new LinkedList<>();

        // Add element at starting of LinkedList
        animals.addFirst("Cow");
        animals.addFirst("Dog");
        animals.addFirst("Cat");
        System.out.println("LinkedList: " + animals);

        // Add elements at the end of LinkedList
        animals.addLast("Zebra");
        System.out.println("New LinkedList: " + animals);
    }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>LinkedList: [Cat, Dog, Cow]</code><br/>
    <code>New LinkedList: [Cat, Dog, Cow, Zebra]</code><br/>
  </div>
</div>

- Hàm `getFirst()` – trả về phần tử đầu tiên
- Hàm `getLast()` – trả về phần tử cuối cùng

Ví dụ:

```java
import java.util.LinkedList;
import java.util.Deque;

class Main {
    public static void main(String[] args) {
        Deque<String> animals= new LinkedList<>();

        // Add elements in the linked list
        animals.add("Dog");
        animals.add("Horse");
        animals.add("Cat");
        System.out.println("LinkedList: " + animals);

        // Get the first element from the linked list
        String str1 = animals.getFirst();
        System.out.println("First Element: " + str1);

        // Get the last element from the linked list
        String str2 = animals.getLast();
        System.out.println("Last Element: " + str2);
    }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>LinkedList: [Dog, Horse, Cat]</code><br/>
    <code>First Element: Dog</code><br/>
    <code>Last Element: Cat</code><br/>
  </div>
</div>

- Hàm `removeFirst()` – loại bỏ phần tử đầu tiên
- Hàm `removeLast()` – loại bỏ phần tử cuối cùng

Ví dụ:

```java
import java.util.LinkedList;
import java.util.Deque;

class Main {
    public static void main(String[] args) {
        Deque<String> animals= new LinkedList<>();

        // Add elements in LinkedList
        animals.add("Dog");
        animals.add("Horse");
        animals.add("Cat");
        System.out.println("LinkedList: " + animals);

        // Remove the first element from LinkedList
        String str1 = animals.removeFirst();
        System.out.println("Removed Element: " + str1);

        // Remove the last element from LinkedList
        String str2 = animals.removeLast();
        System.out.println("Removed Element: " + str2);

        System.out.println("New LinkedList: " + animals);
    }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>LinkedList: [Dog, Horse, Cat]</code><br/>
    <code>Removed Element: Dog</code><br/>
    <code>Removed Element: Cat</code><br/>
    <code>New LinkedList: [Horse]</code><br/>
  </div>
</div>

- Hàm `peek()` trả về phần tử đầu tiên (đầu) của LinkedList. Ví dụ:

```java
import java.util.LinkedList;
import java.util.Queue;

class Main {
    public static void main(String[] args) {
        Queue<String> animals= new LinkedList<>();

        // Add elements in LinkedList
        animals.add("Dog");
        animals.add("Horse");
        animals.add("Cat");
        System.out.println("LinkedList: " + animals);

        // Access the first element of LinkedList
        String str = animals.peek();
        System.out.println("Element Accessed: " + str);
        System.out.println("New LinkedList: " + animals);
    }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>LinkedList: [Dog, Horse, Cat]</code><br/>
    <code>Element Accessed: Dog</code><br/>
    <code>New LinkedList: [Dog, Horse, Cat]</code><br/>
  </div>
</div>

- Hàm `poll()` trả về và loại bỏ phần tử đầu tiên trong LinkedList. Ví dụ:

```java
import java.util.LinkedList;
import java.util.Queue;

class Main {
    public static void main(String[] args) {
        Queue<String> animals= new LinkedList<>();

        // Add elements in LinkedList
        animals.add("Dog");
        animals.add("Horse");
        animals.add("Cat");
        System.out.println("LinkedList: " + animals);

        // Returns and removes the first element
        String str = animals.poll();
        System.out.println("Removed Element: " + str);
        System.out.println("New LinkedList: " + animals);
    }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>LinkedList: [Dog, Horse, Cat]</code><br/>
    <code>Removed Element: Dog</code><br/>
    <code>New LinkedList: [Horse, Cat]</code><br/>
  </div>
</div>

- Hàm `offer()` bổ sung thêm các phần tử cụ thể ở phần cuối của LinkedList. Ví dụ:

```java
import java.util.LinkedList;
import java.util.Queue;

class Main {
    public static void main(String[] args) {
        Queue<String> animals= new LinkedList<>();

        // Add elements in LinkedList
        animals.add("Dog");
        animals.add("Horse");
        System.out.println("LinkedList: " + animals);

        // Adds element at the end of LinkedList
        animals.offer("Cat");
        System.out.println("New LinkedList: " + animals);
    }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>LinkedList: [Dog, Horse]</code><br/>
    <code>New LinkedList: [Dog, Horse, Cat]</code><br/>
  </div>
</div>

## Lặp qua các phần tử của LinkedList

Chúng ta có thể sử dụng `forEach` để lặp qua các phần tử của LinkList

```java
import java.util.LinkedList;

class Main {
    public static void main(String[] args) {
        // Creating a linked list
        LinkedList<String> animals = new LinkedList<>();
        animals.add("Cow");
        animals.add("Cat");
        animals.add("Dog");
        System.out.println("LinkedList: " + animals);

        // Using forEach loop
        System.out.println("Accessing linked list elements:");
        for(String animal: animals) {
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
    <code>LinkedList: [Cow, Cat, Dog]</code><br/>
    <code>Accessing linked list elements:</code><br/>
    <code>Cow, Cat, Dog,</code><br/>
  </div>
</div>

Chúng ta cũng có thể dụng vòng lặp `for` để lặp qua các phần tử của một LinkedList

```java
import java.util.LinkedList;

class Main {
    public static void main(String[] args) {
        // Creating a linked list
        LinkedList<String> animals = new LinkedList<>();
        animals.add("Cow");
        animals.add("Cat");
        animals.add("Dog");
        System.out.println("LinkedList: " + animals);

        // Using for loop
        System.out.println("Accessing linked list elements:");
        for(int i=0; i < animals.size(); i++) {
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
    <code>LinkedList: [Cow, Cat, Dog]</code><br/>
    <code>Accessing linked list elements:</code><br/>
    <code>Cow, Cat, Dog,</code><br/>
  </div>
</div>

Chúng ta có thể sử dụng hàm `iterator()` để truy cập các phần tử của LinkedList. Để sử dụng hàm này, chúng ta phải nhập gói `java.util.Iterator`.

```java
import java.util.LinkedList;
import java.util.Iterator;

class Main {
    public static void main(String[] args) {
        // Creating a linked list
        LinkedList<String> animals = new LinkedList<>();
        animals.add("Cow");
        animals.add("Cat");
        animals.add("Dog");
        System.out.println("LinkedList: " + animals);

        // Using the iterator() method
        System.out.println("LinkedList using the iterator() method:");
        Iterator<String> iterate = animals.iterator();
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
    <code>LinkedList: [Cow, Cat, Dog]</code><br/>
    <code>LinkedList using the iterator() method:</code><br/>
    <code>Cow, Cat, Dog,</code><br/>
  </div>
</div>
