---
title: "Set trong Java"
description: "Set Interface là một loại Interface Collection, khác với List, các phần tử trong List có thể giống nhau, còn đối với Set, các phần tử trong Set là duy nhất (nghĩa là giá trị của các phần tử này không được giống nhau)"
keywords:
  [
    "set trong java",
    "Tập hợp Set trong Java",
    "Thêm một phần tử vào Set",
    "Duyệt qua các phần tử trong Set",
    "Xóa một phần tử trong Set",
    "Xóa tất cả các phần tử trong Set",
    "Thêm tất cả các phần tử từ một tập hợp Set khác",
    "Kiểm tra một phần tử đã tồn tại trong Set chưa",
  ]
chapter:
  name: "Java collections"
  slug: "chuong-04-java-collections"
category:
  logo: "/language/java.png"
  name: "Java"
  slug: "java"
  description: "Học Java từ cơ bản đến thông thạo cho mọi đối tượng"
image: https://user-images.githubusercontent.com/29374426/144745593-8e1da2a4-1f30-46d6-96cd-4ca90bc30386.png
position: 6
---

## Tập hợp Set trong Java là gì?

Set Interface là một loại **Interface Collection**. Khác với `List`, các phần tử trong `List` có thể giống nhau, còn đối với `Set`, các phần tử trong `Set` là duy nhất (nghĩa là giá trị của các phần tử này không được giống nhau). Các phần tử trong Set là duy nhất, chúng ta có thể thêm, xóa, sửa các phần tử trong Set.

![Set trong Java](https://user-images.githubusercontent.com/29374426/144745593-8e1da2a4-1f30-46d6-96cd-4ca90bc30386.png)

Ví dụ tạo một Set như sau:

```java
import java.util.HashSet;

public class SetExample {
    public static void main(String[] args) {
        Set setA = new HashSet();
        setA.add(element);
        System.out.println( setA.contains(element) );
    }
}
```

Trong ví dụ trên ta tạo ra một tập hợp Set với implementation (lớp thực thi) là HashSet. Ngoài HashSet thì chúng ta có những lớp implementation của Set như sau:

- EnumSet
- HashSet
- LinkedHashSet
- TreeSet

Mỗi một implementation của Set đều chứa đựng sự khác biệt về cách sử dụng và tốc độ xử lý các phần tử trong tập hợp. Tuỳ vào yêu cầu bài toán mà ta có thể chọn các loại tập hợp Set tương ứng. Chi tiết mỗi tập hợp sẽ được nói trong từng bài cụ thể sau. Ví dụ:

```java
import java.util.HashSet;
import java.util.LinkedHashSet;
import java.util.Set;
import java.util.TreeSet;

public class SetExample {
    public static void main(String[] args) {
        Set setA = new HashSet();
        Set setB = new LinkedHashSet();
        Set setC = new TreeSet();

    }
}
```

## Thêm một phần tử vào Set

Để thêm một phần tử vào Set ta sử dụng phương thức `add()`. Ví dụ:

```java
import java.util.HashSet;
import java.util.LinkedHashSet;
import java.util.Set;
import java.util.TreeSet;

public class SetExample {
    public static void main(String[] args) {
       Set<String> setA = new HashSet<>();
      setA.add("element 1");
      setA.add("element 2");
      setA.add("element 3");

    }
}
```

## Duyệt qua các phần tử trong Set

Sử dụng Iterator để duyệt qua các phần tử trong một set. Ví dụ:

```java
Set<String> setA = new HashSet<>();

setA.add("element 1");
setA.add("element 2");
setA.add("element 3");

Iterator<String> iterator = set.iterator();

while(iterator.hasNext(){
  String element = iterator.next();
}
```

Chúng ta cũng có thể sử dụng `For Each` để duyệt qua các phần tử:

```java
Set set = new HashSet();

for(Object object : set) {
    String element = (String) object;
}
```

## Xóa một phần tử trong Set

Chúng ta sử dụng phương thức `remove()` để xóa phần tử trong `Set`. Ví dụ:

```java
set.remove("object-to-remove");
```

## Xóa tất cả các phần tử trong Set

Để xóa tất cả các phần tử ta sử dụng phương thức `clear()`. Ví dụ:

```java
set.clear();
```

## Thêm tất cả các phần tử từ một tập hợp Set khác

Set cung cấp cho chúng ta phương thức `addAll()` để thêm các phần tử từ một tập hợp khác vào trong Set. Ví dụ:

```java
Set<String> set = new HashSet<>();
set.add("one");
set.add("two");
set.add("three");

Set<String> set2 = new HashSet<>();
set2.add("four");

set2.addAll(set)
```

## Kiểm tra kích thước của Set

Chúng ta sử dụng phương thức `size()` để xem có bao nhiêu phần tử trong Set. Ví dụ:

```java
Set<String> set = new HashSet<>();

set.add("123");
set.add("456");
set.add("789");

int size = set.size();
```

## Kiểm tra Set có rỗng không

Để kiểm tra Set có rỗng không ta sử dụng phương thức `isEmpty()`

```java
Set<String> set = new HashSet<>();
boolean isEmpty = set.isEmpty();
```

## Kiểm tra một phần tử đã tồn tại trong Set chưa

Chúng ta sử dụng phương thức `contains()` để kiểm tra xem phần tử đã tồn tại trong Set chưa. Ví dụ:

```java
Set<String> set = new HashSet<>();

set.add("123");
set.add("456");

boolean contains123 = set.contains("123");
```

## Chuyển tập hợp Set thành List

Chúng ta có thể cover một tập hợp Set thành List bằng phương thức `addAll()`. Ví dụ:

```java
Set<String> set = new HashSet<>();
set.add("123");
set.add("456");

List<String> list = new ArrayList<>();
list.addAll(set);
```
