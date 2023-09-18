---
title: "Collections trong Java"
description: "Collections (Tập hợp) là một khái niệm quan trọng và mạnh mẽ cho việc lưu trữ và quản lý một nhóm các đối tượng. Chúng ta có thể thực hiện nhiều thao tác trên các tập hợp như tìm kiếm, sắp xếp, chèn, xóa và nhiều thao tác khác. Bài viết này sẽ giới thiệu về Collections trong Java, bao gồm các giao diện, lớp cài đặt, và các thuật toán cơ bản"
chapter:
  name: "Java collections"
  slug: "chuong-04-java-collections"
category:
  name: "Java"
  slug: "java"
image: https://user-images.githubusercontent.com/29374426/132952801-20345632-c056-4c52-9603-9970fa3988b5.png
position: 1
---

Trong lập trình Java, Collections (Tập hợp) là một khái niệm quan trọng và mạnh mẽ cho việc lưu trữ và quản lý một nhóm các đối tượng. Chúng ta có thể thực hiện nhiều thao tác trên các tập hợp như tìm kiếm, sắp xếp, chèn, xóa và nhiều thao tác khác. Bài viết này sẽ giới thiệu về Collections trong Java, bao gồm các giao diện, lớp cài đặt, và các thuật toán cơ bản.

## Khái niệm về Collections trong Java

Trong Java, "Collections" là một khung (framework) cung cấp kiến trúc để lưu trữ và thao tác trên các tập hợp đối tượng. Java Collections cho phép bạn làm việc với các dữ liệu phức tạp và cung cấp các giao diện và lớp cài đặt cho một loạt các cấu trúc dữ liệu, chẳng hạn như danh sách (List), tập hợp (Set), hàng đợi (Queue), và ánh xạ (Map).

![Collections trong Java](https://user-images.githubusercontent.com/29374426/132952801-20345632-c056-4c52-9603-9970fa3988b5.png)

## Cài đặt trong Collections

Gói `java.util` cung cấp tập các lớp cài đặt các giao diện lõi để tạo ra những cấu trúc dữ liệu thường sử dụng như: `Vector`, `HashTable`, `HashSet`, `LinkedList`, `TreeSet`,.... Những lớp này và giao diện lõi được xây dựng theo cấu trúc phân cấp như sau:

![Cài đặt trong Collections](https://user-images.githubusercontent.com/29374426/132952809-7b363990-dfe2-42aa-800b-456035b1fd26.png)

## Phần interface trong collections

Giao diện (interface) Collection là cơ sở để phát triển, mở rộng thành các giao diện khác như `Set`, `List`, `SortedSet` và `Map` và giao diện cơ sở để mở rộng thành `SortedMap`. Các giao diện lõi của cấu trúc Collection được mô tả trong bảng sau:

| interface    | Mô tả                                                                                                                                                                                                                                                                                                                                                                                                                   |
| ------------ | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| `Collection` | interface cơ sở định nghĩa tất cả các phép toán cơ bản cho các lớp cần duy trì thực hiện và cài đặt chúng                                                                                                                                                                                                                                                                                                               |
| `Set`        | là một collection không thể chứa 2 giá trị trùng lặp. Set được sử dụng để biểu diễn các bộ, chẳng hạn như bộ tú lu khơ, thời khóa biểu của học sinh, các tiến trình đang chạy trên máy tính...                                                                                                                                                                                                                          |
| `SortedSet`  | Mở rộng Set để cài đặt cấu trúc tập hợp được sắp, trong đó không có phần tử được lặp và chúng được sắp xếp theo thứ tự                                                                                                                                                                                                                                                                                                  |
| `List`       | là một collection có thứ tự (đôi khi còn được gọi là một chuỗi). List có thể chứa các phần tử trùng lặp. Thường có quyền kiểm soát chính xác vị trí các phần tử được chèn vào và có thể truy cập chúng bằng chỉ số (vị trí của chúng).                                                                                                                                                                                  |
| `Map`        | interface cơ sở định nghĩa các phép toán để các lớp sử dụng và cài đặt các ánh xạ từ khoá sang các giá trị                                                                                                                                                                                                                                                                                                              |
| `SortedMap`  | Mở rộng của Map để cài đặt các ánh xạ khoá theo thứ tự                                                                                                                                                                                                                                                                                                                                                                  |
| `Queue`      | là một collection được sử dụng để chứa nhiều phần tử trước khi xử lý. Bên cạnh các thao tác cơ bản của collection, Queue cung cấp các thao tác bổ sung như chèn, lấy ra và kiểm tra. Queue có thể được sử dụng như là FIFO (first-in, first-out - vào trước, ra trước)                                                                                                                                                  |
| `Deque`      | là một collection được sử dụng để chứa nhiều phần tử trước khi xử lý. Ngoài các thao tác cơ bản của collection, một Deque cung cấp các thao tác bổ sung như chèn, lấy ra và kiểm tra. Deques có thể được sử dụng như là FIFO (first-in, first-out - vào trước, ra trước) và LIFO (last-in, first-out - vào sau, ra trước). Trong một Deque, tất cả các phần tử mới có thể được chèn vào, lấy ra và lấy ra ở cả hai đầu. |

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

## Thuật toán trong Collections

Java Collections cung cấp một loạt các thuật toán mạnh mẽ để thực hiện trên các tập hợp dữ liệu. Dưới đây là một số phương thức thuật toán quan trọng:

- `binarySearch(List list, Object key)`: Tìm kiếm một phần tử trong danh sách đã sắp xếp bằng thuật toán tìm kiếm nhị phân.
- `fill(List list, Object obj)`: Thay thế tất cả các phần tử trong danh sách bằng một đối tượng cụ thể.
- `shuffle(List list)`: Hoán vị các phần tử trong danh sách một cách ngẫu nhiên.
- `sort(List list)`: Sắp xếp các phần tử trong danh sách theo thứ tự tăng dần.

Các phương thức này giúp bạn thực hiện các thao tác phức tạp trên tập hợp dữ liệu một cách dễ dàng và hiệu quả.

:alert{type="success"}
Collections trong Java cung cấp một cơ hội mạnh mẽ để làm việc với các dữ liệu phức tạp và đa dạng. Bài viết này đã giới thiệu về các giao diện, lớp cài đặt và các thuật toán quan trọng trong Java Collections. Sử dụng Java Collections có thể giúp bạn quản lý và thao tác dữ liệu một cách hiệu quả trong ứng dụng của bạn.
::
