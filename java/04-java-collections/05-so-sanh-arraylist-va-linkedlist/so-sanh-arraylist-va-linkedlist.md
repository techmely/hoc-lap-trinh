---
title: "So sánh ArrayList và LinkedList"
description: "So sánh ArrayList và LinkedList"
chapter:
  name: "Java collections"
  slug: "chuong-04-java-collections"
image: https://user-images.githubusercontent.com/29374426/143202802-fb867763-f54b-40e5-9d4a-64be9ea60016.png
position: 5
---

Trong lập trình Java, có hai cấu trúc dữ liệu phổ biến để lưu trữ và quản lý danh sách các phần tử: `ArrayList` và `LinkedList`. Trong bài viết này, chúng ta sẽ so sánh hai cấu trúc dữ liệu này để hiểu rõ sự khác biệt giữa chúng và khi nào nên sử dụng mỗi loại.

![Sự khác nhau giữa ArrayList và LinkedList](https://user-images.githubusercontent.com/29374426/143270459-b408c711-1429-4fe7-99af-294900ad796b.png)

## Sự Khác Nhau Giữa ArrayList và LinkedList

Cả `ArrayList` và `LinkedList` đều implement giao diện `List` và duy trì thứ tự của các phần tử. Tuy nhiên, có sự khác biệt quan trọng giữa chúng:

### 1. Cơ Chế Lưu Trữ

- [ArrayList](/bai-viet/java/array-list-trong-java): Sử dụng một mảng động để lưu trữ các phần tử. Điều này có nghĩa rằng nó có thể thực hiện các thao tác truy cập một cách nhanh chóng. Tuy nhiên, nếu bạn xoá một phần tử khỏi mảng, toàn bộ các phần tử sau nó phải được di chuyển trong bộ nhớ để đảm bảo thứ tự không bị thay đổi.
- [LinkedList](/bai-viet/java/array-list-trong-java): Sử dụng danh sách liên kết đôi để lưu trữ các phần tử. Thao tác với LinkedList nhanh hơn so với ArrayList vì khi xoá hoặc chèn một phần tử, chỉ cần điều chỉnh các liên kết giữa các nút trong danh sách liên kết, không cần di chuyển dữ liệu trong bộ nhớ.

### 2. Sử Dụng

- **ArrayList**: Thích hợp cho việc lưu trữ và truy cập dữ liệu khi bạn cần nhanh chóng truy cập các phần tử theo chỉ số. Ví dụ: danh sách điểm của một lớp học.
- **LinkedList**: Thích hợp cho các thao tác thêm/xoá dữ liệu thường xuyên, chẳng hạn như danh sách cuộc gọi hoặc hàng đợi (queue) với việc thêm/xoá phần tử ở cả hai đầu. Nó cũng là lựa chọn tốt cho việc duyệt danh sách theo cách lùi.

### 3. Giao Diện

- **ArrayList**: Chỉ hỗ trợ giao diện `List`.
- **LinkedList**: Hỗ trợ cả giao diện `List` và `Deque`, cho phép bạn sử dụng nó như một hàng đợi (queue).

## Ví dụ về ArrayList và LinkedList trong Java

Dưới đây là ví dụ đơn giản về việc sử dụng `ArrayList` và `LinkedList` trong Java:

```java
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

public class ArrayListAndLinkedListExample {
    public static void main(String args[]) {

        // Tạo ArrayList
        List<String> arrayList = new ArrayList<String>();
        // Thêm phần tử vào ArrayList
        arrayList.add("Java");
        arrayList.add("C++");
        arrayList.add("PHP");
        arrayList.add("Python");

        // Tạo LinkedList
        List<String> linkedList = new LinkedList<String>();
        // Thêm phần tử vào LinkedList
        linkedList.add("Hibernate");
        linkedList.add("Struts2");
        linkedList.add("Spring");
        linkedList.add("Mybatis");

        System.out.println("ArrayList: " + arrayList);
        System.out.println("LinkedList: " + linkedList);
    }
}
```

::result

ArrayList: [Java, C++, PHP, Python]<br/>
LinkedList: [Hibernate, Struts2, Spring, Mybatis]

::

Như bạn có thể thấy, `ArrayList` và `LinkedList` đều cho phép bạn thêm và truy cập các phần tử một cách dễ dàng. Tuy nhiên, chọn loại cấu trúc dữ liệu phù hợp với nhu cầu cụ thể của bạn là rất quan trọng để đảm bảo hiệu suất tối ưu trong ứng dụng của bạn.
