---
title: "Thread Group trong Java"
description: "Java cung cấp một cách thuận tiện để nhóm nhiều thread trong một đối tượng duy nhất. Bằng cách đó, chúng ta có thể suspend, resume hoặc interrupt một nhóm các thread bằng việc gọi một phương thức duy nhất"
chapter:
  name: "Lập trình đa luồng"
  slug: "chuong-06-lap-trinh-da-luong"
category:
  name: "Java"
  slug: "java"
image: https://user-images.githubusercontent.com/29374426/146481584-116afdfd-3676-4c73-87d7-15bdd8b6b927.png
position: 9
---

Java cung cấp một cách thuận tiện để nhóm nhiều `thread` trong một đối tượng duy nhất. Bằng cách đó, chúng ta có thể `suspend`, `resume` hoặc `interrupt` một nhóm các `thread` bằng việc gọi một phương thức duy nhất.

![Thread Group trong Java](https://user-images.githubusercontent.com/29374426/146481584-116afdfd-3676-4c73-87d7-15bdd8b6b927.png)

## Khởi tạo Thread Group trong Java

Chỉ có 2 constructor để khởi tạo Thread Group trong Java:

- `ThreadGroup(String name)`: Tạo một nhóm thread có tên.
- `ThreadGroup(ThreadGroup parent, String name)`: Tạo một nhóm `thread` với một nhóm cha và tên.

```java
// ThreadGroupDemo.java
public class ThreadGroupDemo implements Runnable {
    public void run() {
        System.out.println(Thread.currentThread().getName());
    }

    public static void main(String[] args) {
        ThreadGroupDemo runnable = new ThreadGroupDemo();
        ThreadGroup tg1 = new ThreadGroup("Parent ThreadGroup");

        Thread t1 = new Thread(tg1, runnable, "one");
        t1.start();
        Thread t2 = new Thread(tg1, runnable, "two");
        t2.start();
        Thread t3 = new Thread(tg1, runnable, "three");
        t3.start();

        System.out.println("Thread Group Name: " + tg1.getName());
        tg1.list();
    }
}
```

::result

two
Thread Group Name: Parent ThreadGroup</br>
java.lang.ThreadGroup[name=Parent ThreadGroup,maxpri=10]</br>
Thread[one,5,Parent ThreadGroup]</br>
Thread[three,5,Parent ThreadGroup]</br>
three</br>
one

::

## Các hàm trong Thread Group

Có nhiều phương thức trong lớp `ThreadGroup`. Dưới đây là danh sách các phương thức quan trọng:

- `int activeCount()`: Trả về số thread đang chạy trong nhóm hiện tại.
- `int activeGroupCount()`: Trả về số nhóm thread active trong nhóm thread hiện tại.
- `void destroy()`: Phá hủy nhóm thread này và tất cả các nhóm con của nó.
- `String getName()`: Trả về tên của nhóm thread này.
- `ThreadGroup getParent()`: Trả về nhóm cha của nhóm thread này.
- `void interrupt()`: Ngắt tất cả các thread trong nhóm này.
- `void list()`: In thông tin của nhóm này lên màn hình console.

```java
ThreadGroup tg1 = new ThreadGroup("Group A");
Thread t1 = new Thread(tg1, new MyRunnable(), "one");
Thread t2 = new Thread(tg1, new MyRunnable(), "two");
Thread t3 = new Thread(tg1, new MyRunnable(), "three");
```

Trong đoạn mã trên, chúng ta đã nhóm các `thread` vào `tg1`, `MyRunnable` là một lớp `implements` giao diện `Runnable`, và "one", "two" và "three" là tên của các luồng.

Bây giờ, chúng ta có thể ngắt tất cả các `thread` trong nhóm bằng một dòng mã như sau:

```java
Thread.currentThread().getThreadGroup().interrupt();
```

Thread Group trong Java là một cách mạnh mẽ để quản lý và kiểm soát các luồng trong ứng dụng của bạn. Chúng cho phép bạn nhóm các luồng liên quan lại với nhau và thực hiện các hoạt động như ngắt tất cả các luồng trong nhóm một cách dễ dàng.
