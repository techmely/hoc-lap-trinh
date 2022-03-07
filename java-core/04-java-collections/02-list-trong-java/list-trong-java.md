---
title: "List trong Java"
description: "ist trong java là một interface trong java, nó chứa các phương thức để chèn và xóa các phần tử dựa trên chỉ số index."
keywords:
  [
    "arraylist trong java",
    "arraylist va list trong java",
    "arraylist và list trong java",
    "bài tập về linked list trong java",
    "code list trong java",
    "collection list trong java",
    "contains list trong java",
    "các loại list trong java",
    "cách tạo linked list trong java",
    "doubly linked list trong java",
    "duyệt list trong java",
    "get phần tử trong list java",
    "hàm list trong java",
  ]
chapter:
  name: "Java collections"
  slug: "chuong-04-java-collections"
category:
  logo: "/language/java.png"
  name: "Java"
  slug: "java"
  description: "Học Java từ cơ bản đến thông thạo cho mọi đối tượng"
image: https://user-images.githubusercontent.com/29374426/133044726-cd098fdc-4a33-4f3f-a603-82ba49089dc9.png
position: 2
---

List trong java là một [interface](/bai-viet/java/interface-trong-java) trong java. Nó chứa các phương thức để chèn và xóa các phần tử dựa trên chỉ số index.

## Sử dụng List trong Java

Cấu trúc `List` là dạng tập hợp các phần tử được sắp theo thứ tự (còn được gọi là dãy tuần tự) và trong đó cho phép lặp (hai phần tử giống nhau). Vì `List` là một [interface](/bai-viet/java/interface-trong-java), nên chúng ta không thể tạo các đối tượng từ nó. Để sử dụng các tính năng của List interface, chúng ta có thể sử dụng các class sau:

- ArrayList
- LinkedList
- Vector
- Stack

![Các class triển khai List interface](https://user-images.githubusercontent.com/29374426/133044726-cd098fdc-4a33-4f3f-a603-82ba49089dc9.png)

## Khai báo List trong java

Trong Java, chúng ta phải import package là java.util.List để sử dụng được List.

```java
// ArrayList triển khai List
List<String> list1 = new ArrayList<>();

// LinkedList triển khai List
List<String> list2 = new LinkedList<>();
```

Ở đây, chúng ta đã tạo các đối tượng `list1` và `list2` của class `ArrayList` và `LinkedList. Các đối tượng này có thể sử dụng các tính năng của List interface.

## Các phương thức của List

Ngoài những hàm mà nó được kế thừa từ [Collection](/bai-viet/java/cac-collection-trong-java), List còn bổ sung thêm những hàm như:

| Method | Mô tả |
| --- | --- |
| Object get(int index) | Cho lại phần tử được xác định bởi index. |
| Object set(int index, Object elem) | Thay thế phần tử được xác định bởi index bằng elem |
| void add(int index, Object elem) | Chèn elem vào sau phần tử được xác định bởi index. |
| Object remove(int index) | Bỏ đi phần tử được xác định bởi index |
| boolean addAll(int index, Collection c) | Chèn các phần tử của tập hợp c vào vị trí được xác định bởi index |
| int indexOf(Object elem) | Cho biết vị trí lần xuất hiện đầu tiên của phần tử trong danh sách |
| int lastIndexOf(Object elem) | Cho biết vị trí lần xuất hiện cuối cùng của elem trong danh sách. |
| List subList(int fromIndex, int toIndex) | Lấy ra một danh sách con từ vị trí fromIndex đến toIndex |
| ListIterator listIterator() | Cho lại các phần tử liên tiếp bắt đầu từ phần tử đầu tiên. |
| ListIterator listIterator(int index) | Cho lại các phần tử liên tiếp bắt đầu từ phần tử được xác định bởi. Trong đó `ListIterator` là interface mở rộng giao diện `Iterator` đã có trong `java.lang.` |

## Ví dụ về List trong java

<div class="example">
Hãy xem ví dụ đơn giản về List trong java sau
</div>

```java
import java.util.ArrayList;
import java.util.List;

public class ListExample {
    public static void main(String args[]) {
        List<String> list = new ArrayList<String>();
        list.add("Java");
        list.add("C++");
        list.add("PHP");
        list.add(1, "Python");
        System.out.println("Phan tu co index = 2 la: " + list.get(2));
        // show list
        for (String s : list) {
            System.out.println(s);
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
    <code>Phan tu co index = 2 la: C++</code><br/>
    <code>Java</code><br/>
    <code>Python</code><br/>
    <code>C++</code><br/>
    <code>PHP</code>
  </div>
</div>

<div class="example">Sử dụng Arrays.asList()</div>

```java
import java.util.Arrays;
import java.util.List;

public class ListExample1 {
    public static void main(String args[]) {
        // create new array
        String[] arr = { "Java", "C++", "PHP", "Python" };
        // convert array to List
        List<String> list = Arrays.asList(arr);
        // show list
        for (String s : list) {
            System.out.println(s);
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
    <code>Java</code><br/>
    <code>C++</code><br/>
    <code>PHP</code><br/>
    <code>Python</code>
  </div>
</div>

## List Iterator trong java

`ListIterator` là một interface được sử dụng để duyệt các phần tử của List trong java. Các phương thức của interface ListIterator trong java

| Method | Mô tả |
| --- | --- |
| boolean hasNext() | Phương thức này trả về true nếu list interator có tồn tại phần tử kế tiếp phần tử hiện tại. |
| Object next() | Phương thức này trả về phần tử kế tiếp trong danh sách và vị trí con trỏ tăng lên 1. |
| boolean hasPrevious() | Phương pháp này trả về true nếu list interator có tồn tại phần tử kế sau phần tử hiện tại. |
| Object previous() | Phương thức này trả về phần tử kế sau trong danh sách và vị trí con trỏ giảm đi 1 |

<div class="example">Hãy xem ví dụ đơn giả về việc duyệt các phần tử của List trong java bằng cách sử dụng ListIterator</div>

```java
import java.util.ArrayList;
import java.util.List;
import java.util.ListIterator;

public class Thaycacac {
    public static void main(String args[]) {
        List<String> list = new ArrayList<String>();
        list.add("Java");
        list.add("C++");
        list.add("PHP");
        list.add(1, "Python");
        System.out.println("Phan tu co index = 2 la: " + list.get(2));

        ListIterator<String> itr = list.listIterator();
        System.out.println("Duyet cac phan tu tu dau den cuoi:");
        while (itr.hasNext()) {
            System.out.println("\t" + itr.next());
        }
        System.out.println("Duyet cac phan tu tu cuoi ve dau:");
        while (itr.hasPrevious()) {
            System.out.println("\t" + itr.previous());
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
    <code>Phan tu co index = 2 la: C++</code><br/>
    <code>Duyet cac phan tu tu dau den cuoi:</code><br/>
    <code>Java</code><br/>
    <code>Python</code><br/>
    <code>C++</code><br/>
    <code>PHP</code><br/>
    <code>Duyet cac phan tu tu cuoi ve dau:</code><br/>
    <code>PHP</code><br/>
    <code>C++</code><br/>
    <code>Python</code><br/>
    <code>Java</code><br/>
  </div>
</div>
