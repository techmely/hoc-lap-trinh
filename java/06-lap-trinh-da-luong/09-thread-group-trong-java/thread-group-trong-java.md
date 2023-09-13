---
title: "Thread Group trong Java"
description: "Java cung cấp một cách thuận tiện để nhóm nhiều thread trong một đối tượng duy nhất. Bằng cách đó, chúng ta có thể suspend, resume hoặc ` interrupt một nhóm các thread bằng việc gọi một phương thức duy nhất."
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

Chỉ có 2 [constructor](/bai-viet/java/constructor-trong-java) để khởi tạo Thread Group trong Java

- `ThreadGroup(String name)` - tạo một nhóm thread có tên.
- `ThreadGroup(ThreadGroup parent, String name)` - tạo một nhóm `thread` với một nhóm cha và tên.

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

two</code><br/>
Thread Group Name: Parent ThreadGroup</code><br/>
java.lang.ThreadGroup[name=Parent ThreadGroup,maxpri=10]</code><br/>
Thread[one,5,Parent ThreadGroup]</code><br/>
Thread[three,5,Parent ThreadGroup]</code><br/>
three</code><br/>
one</code><br/>

::

## Các hàm trong Thread Group

Có nhiều phương thức trong lớp `ThreadGroup`. Một danh sách các phương thức quan trọng được đưa ra dưới đây.

|Method| Description| |`int activeCount()`| Trả về số no. của các thread đang chạy trong nhóm hiện tại.| |`int activeGroupCount()`| Trả về số no. của nhóm active trong nhóm thread này.| |`void destroy()`| Phá hủy nhóm thread này và tất cả các nhóm con của nó.| |`String getName()` |Trả về tên của nhóm này.| |`ThreadGroup getParent()`| Trả lại nhóm cha của nhóm này.| |`void interrupt()` |Ngắt tất cả các thread của nhóm này.| |`void list()`| In thông tin của nhóm này tới console tiêu chuẩn.|

```java
ThreadGroup tg1 = new ThreadGroup("Group A");
Thread t1 = new Thread(tg1,new MyRunnable(),"one");
Thread t2 = new Thread(tg1,new MyRunnable(),"two");
Thread t3 = new Thread(tg1,new MyRunnable(),"three");
```

Đoạn code trên chúng ta nhóm các Thread, ở đây `tg1` là tên của `thread` group, `MyRunnable` là lớp `inplements` giao tiếp `Runnable` và _"one", "two" và "three"_ là các tên luồng.

Và bây giờ chúng ta có thể ngắt tất cả các `thread` bằng một dòng code duy nhất như sau:

```java
Thread.currentThread().getThreadGroup().interrupt();
```
