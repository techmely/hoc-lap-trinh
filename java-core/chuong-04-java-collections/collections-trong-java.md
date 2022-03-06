---
title: "Collections trong Java"
description: "Bài này chúng ta sẽ tìm hiểu về Các lớp tập hợp, tự học lập trình java, chia sẻ kiến thức về java"
keywords:
  [
    "bài tập collection trong java",
    "bài tập về collection trong java",
    "cau truc collection trong java",
    "collection framework trong java",
    "collection framework trong java là gì",
    "collection java",
    "collection là gì java",
    "collection sort trong java",
    "collection trong java",
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
image: https://user-images.githubusercontent.com/29374426/132952801-20345632-c056-4c52-9603-9970fa3988b5.png
position: 1
---

Tập hợp (Collections) trong java là một khuôn khổ cung cấp một kiến trúc để lưu trữ và thao tác tới nhóm các đối tượng. Tất cả các hoạt động mà bạn thực hiện trên một dữ liệu như tìm kiếm, phân loại, chèn, xóa,... có thể được thực hiện bởi Java Collections.

Collection trong java là một root interface trong hệ thống cấp bậc Collection. Java Collection cung cấp nhiều interface (`Set`, `List`, `Queue`, `Deque`,....) và các lớp (`ArrayList`, `Vector`, `LinkedList`, `PriorityQueue`, `HashSet`, `LinkedHashSet`, `TreeSet`,...).

![image](https://user-images.githubusercontent.com/29374426/132952801-20345632-c056-4c52-9603-9970fa3988b5.png)

## Phần cài đặt trong collections

Gói `java.util` cung cấp tập các lớp cài đặt các giao diện lõi để tạo ra những cấu trúc dữ liệu thường sử dụng như: `Vector`, `HashTable`, `HashSet`, `LinkedList`, `TreeSet`,.... Những lớp này và giao diện lõi được xây dựng theo cấu trúc phân cấp như sau:

![image](https://user-images.githubusercontent.com/29374426/132952809-7b363990-dfe2-42aa-800b-456035b1fd26.png)

## Phần interface trong collections

Giao diện (interface) Collection là cơ sở để phát triển, mở rộng thành các giao diện khác như `Set`, `List`, `SortedSet` và `Map` và giao diện cơ sở để mở rộng thành `SortedMap`. Các giao diện lõi của cấu trúc Collection được mô tả trong bảng sau:

| interface | Mô tả |
| --- | --- |
| Collection | interface cơ sở định nghĩa tất cả các phép toán cơ bản cho các lớp cần duy trì thực hiện và cài đặt chúng |
| Set | là một collection không thể chứa 2 giá trị trùng lặp. Set được sử dụng để biểu diễn các bộ, chẳng hạn như bộ tú lu khơ, thời khóa biểu của học sinh, các tiến trình đang chạy trên máy tính... |
| SortedSet | Mở rộng Set để cài đặt cấu trúc tập hợp được sắp, trong đó không có phần tử được lặp và chúng được sắp xếp theo thứ tự |
| List | là một collection có thứ tự (đôi khi còn được gọi là một chuỗi). List có thể chứa các phần tử trùng lặp. Thường có quyền kiểm soát chính xác vị trí các phần tử được chèn vào và có thể truy cập chúng bằng chỉ số (vị trí của chúng). |
| Map | interface cơ sở định nghĩa các phép toán để các lớp sử dụng và cài đặt các ánh xạ từ khoá sang các giá trị |
| SortedMap | Mở rộng của Map để cài đặt các ánh xạ khoá theo thứ tự |
| Queue | là một collection được sử dụng để chứa nhiều phần tử trước khi xử lý. Bên cạnh các thao tác cơ bản của collection, Queue cung cấp các thao tác bổ sung như chèn, lấy ra và kiểm tra. Queue có thể được sử dụng như là FIFO (first-in, first-out - vào trước, ra trước) |
| Deque | là một collection được sử dụng để chứa nhiều phần tử trước khi xử lý. Ngoài các thao tác cơ bản của collection, một Deque cung cấp các thao tác bổ sung như chèn, lấy ra và kiểm tra. Deques có thể được sử dụng như là FIFO (first-in, first-out - vào trước, ra trước) và LIFO (last-in, first-out - vào sau, ra trước). Trong một Deque, tất cả các phần tử mới có thể được chèn vào, lấy ra và lấy ra ở cả hai đầu. |

## Phần thuật toán trong collections

Lớp `java.util.Collection` (cần phân biệt với giao diện Collection) cung cấp một số hàm `static` thực hiện những thuật toán đa xạ cho những phép toán khác nhau trên tập hợp, kể cả sắp xếp, tìm kiểm và dịch chuyển các phần tử.

Một số hàm trong số đó là:

Sử dụng thuật toán tìm kiếm nhị phân để xác định chỉ số của phần tử key trong danh sách list.

```java
static int binarySearch(List list, Object key)
```

Thay thế tất cả các phần tử trong danh sách list bằng obj

```java
static void fill(List list, Object obj)
```

Hoán vị các phần tử của danh sách list một cách ngẫu nhiên.

```java
static void shuffle(List list)
```

Sắp xếp các phần tử trong danh sách list theo thứ tự tăng dần.

```java
static void sort(List list)
```

### Collection trong Java

Giao diện Collection được xây dựng như là mẫu hợp đồng cho tất cả các cấu trúc tập hợp có thể dựa vào đó mà thực thi và cài đặt. Gói java.util cung cấp các lớp tập hợp và cài đặt hầu hết các hàm của Collection.

Các phép toán cơ sở

```java
int size(); // Xác định kích thước của tập hợp.
boolean isEmpty(); // Trả lại true nếu tập hợp rỗng, ngược lại false.

boolean contains(Object obj); // Trả lại true nếu tập hợp chứa obj, ngược lại false. boolean add(Object obj);	// Tùy chọn
boolean remove(Object obj); // Tùy chọn
```

Trả lại true nếu tập hợp thực hiện thành công việc bổ sung (loại bỏ) obj, ngược lại false.

**Một số phép toán khác**

Những phép toán sau thực hiện trên tập hợp như một đơn vị cấu trúc dữ liệu.

Kiểm tra xem tập hợp hiện thời có chứa cả tập hợp c hay không.

```java
boolean cotainAll(Collection c);	// Tùy chọn
```

Thực hiện phép hợp hai tập hợp

```java
boolean addAll(Collection c);// Tùy chọn
```

Thực hiện phép trừ hai tập hợp

```java
boolean removeAll(Collection c); // Tùy chọn
```

Thực hiện phép giao hai tập hợp

```java
boolean retainAll(Collection c); // Tùy chọn
```

Hủy bỏ đối tượng trong tập hợp các phép trên trả lại true nếu thực hiện thành công và cho kết quả thực hiện được minh họa như trong hình H6-4, trong đó a, b là hai tập hợp bất kỳ.

```java
void clear() // Tùy chọn
```

Hình Các phép toán trên các tập hợp

```java
a.addAll(b)
a.removeAll(b)
a.retainAll(b)
```
