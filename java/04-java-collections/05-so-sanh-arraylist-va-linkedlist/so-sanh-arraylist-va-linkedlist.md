---
title: "So sánh ArrayList và LinkedList"
description: "So sánh ArrayList và LinkedList"
chapter:
  name: "Java collections"
  slug: "chuong-04-java-collections"
category:
  name: "Java"
  slug: "java"
image: https://user-images.githubusercontent.com/29374426/143202802-fb867763-f54b-40e5-9d4a-64be9ea60016.png
position: 5
---

## Sự khác nhau giữa ArrayList và LinkedList

Cả hai lớp ArrayList và LinkedList đều được implements từ giao tiếp List và duy trì thứ tự của phần tử được thêm vào.

![Sự khác nhau giữa ArrayList và LinkedList](https://user-images.githubusercontent.com/29374426/143270459-b408c711-1429-4fe7-99af-294900ad796b.png)

Cả hai lớp này đều là lớp không đồng bộ (non-synchronized). Có vài sự khác nhau giữa ArrayList và LinkedList được đưa ra như trong bảng dưới đây:

| ArrayList                                                                                                                                         | LinkedList                                                                                                                                         |
| ------------------------------------------------------------------------------------------------------------------------------------------------- | -------------------------------------------------------------------------------------------------------------------------------------------------- |
| ArrayList nội bộ sử dụng mảng động để lưu trữ các phần tử.                                                                                        | LinkedList nội bộ sử dụng danh sách liên kết doubly để lưu trữ các phần tử.                                                                        |
| Thao tác với ArrayList là chậm bởi vì nó sử dụng nội bộ mảng. Nếu bất kỳ phần tử nào được xoá khỏi mảng, tất cả các bit được chuyển trong bộ nhớ. | Thao tác với LinkedList là nhanh hơn so với ArrayList bởi vì nó sử dụng danh sách liên kết doubly do đó không cần chuyển đổi bit nào trong bộ nhớ. |
| Lớp ArrayList trong java chỉ có thể hoạt động như một list vì nó chỉ implements giao tiếp List.                                                   | Lớp LinkedList trong java có thể hoạt động như một list và queue(hàng đợi) vì nó implements các giao tiếp List và Deque.                           |
| ArrayList là tốt hơn trong việc lưu trữ và truy cập dữ liệu.                                                                                      | LinkedList là tốt hơn trong việc thao tác dữ liệu.                                                                                                 |

## Ví dụ về ArrayList và LinkedList trong java

Dưới đây là ví dụ đơn giản về việc sử dụng ArrayList và LinkedList trong java

```java
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

public class ArraylistAndLinkedListExample {
    public static void main(String args[]) {

        // create arrayList
        List<String> arrayList = new ArrayList<String>();
        // add object in arraylist
        arrayList.add("Java");
        arrayList.add("C++");
        arrayList.add("PHP");
        arrayList.add("Python");

        // create linkedlist
        List<String> linkedList = new LinkedList<String>();
        // aadd object in linkedlist
        linkedList.add("Hiberante");
        linkedList.add("Struts2");
        linkedList.add("Spring");
        linkedList.add("Mybatis");

        System.out.println("arraylist: " + arrayList);
        System.out.println("linkedlist: " + linkedList);
    }
}
```

<content-result>
    <code>arraylist: [Java, C++, PHP, Python]</code><br/>
    <code>linkedlist: [Hiberante, Struts2, Spring, Mybatis]</code><br/>
</content-result>
