---
title: "Độ ưu tiên Thread trong Java"
description: "Mỗi thread có một mức ưu tiên (priority), đại diện bởi một số từ 1 đến 10. Trong hầu hết các trường hợp, trình lên lịch của thread được sắp xếp theo thứ tự ưu tiên của chúng (được gọi là lập kế hoạch ưu tiên)"
keywords:
  [
    "độ ưu tiên thread trong java",
    "độ ưu tien thread",
    "do uu tien thread",
    "ví dụ độ ưu tiên thread trong java",
    "hàm setPriority trong java",
    "hàm getPriority trong java",
  ]
chapter:
  name: "Lập trình đa luồng"
  slug: "chuong-06-lap-trinh-da-luong"
category:
  name: "Java"
  slug: "java"
image: https://user-images.githubusercontent.com/29374426/146319085-7f834fbb-f3a4-49a8-996a-13d14b00efd0.png
position: 5
---

Mỗi thread có một mức ưu tiên (priority), đại diện bởi một số từ 1 đến 10. Trong hầu hết các trường hợp, [trình lên lịch của thread](/bai-viet/java/trinh-len-lich-cua-thread-trong-java) được sắp xếp theo thứ tự ưu tiên của chúng (được gọi là lập kế hoạch ưu tiên). Nhưng nó không được bảo đảm bởi vì nó phụ thuộc vào thông số kỹ thuật của JVM.

![Độ ưu tiên Thread trong Java](https://user-images.githubusercontent.com/29374426/146319085-7f834fbb-f3a4-49a8-996a-13d14b00efd0.png)

## Độ ưu tiên Thread trong Java là gì?

Như đã nói ở trên, mỗi luồng có 1 độ ưu tiên nhất định, đây sẽ là thông số quyết định mức ưu tiên khi cấp phát CPU cho các luồng.

Trong java, đế đặt độ ưu tiên cho 1 luồng ta dùng phương thức: `void setPriority(int newPriority)`, trong đó `int newPriority` là giá trị từ 1 đến 10.

Java có định nghĩa sẵn 3 mức ưu tiên chuẩn như sau:

- `Thread.MIN_PRIORITY` (giá trị 1)
- `Thread.NORM_PRIORITY` (giá trị 5)
- `Thread.MAX_PRIORITY` (giá trị 10)

Để lấy độ ưu tiên của 1 luồng, ta dùng phương thức `int getPriority()`

## Ví dụ sử dụng độ ưu tiên Thread trong Java

<content-example />

```java
class TestMultiPriority1 extends Thread {
    public void run() {
        System.out.println("Đang chạy luồng:"
                + Thread.currentThread().getName());
        System.out.println("Độ ưu tiên là:"
                + Thread.currentThread().getPriority());
    }

    public static void main(String args[]) {
        TestMultiPriority1 m1 = new TestMultiPriority1();
        TestMultiPriority1 m2 = new TestMultiPriority1();
        m1.setPriority(Thread.MIN_PRIORITY);
        m2.setPriority(Thread.MAX_PRIORITY);
        m1.start();
        m2.start();
    }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>Đang chạy luồng:Thread-1</code><br/>
    <code>Đang chạy luồng:Thread-0</code><br/>
    <code>Độ ưu tiên là:1</code><br/>
    <code>Độ ưu tiên là:10</code>
  </div>
</div>

<div class="example">một ví dụ khác</div>

```java
// file: WorkingThread.java

public class WorkingThread extends Thread {
    public WorkingThread(String name) {
        super(name);
    }

    public void run() {
        for (int i = 0; i &amp;lt; 5; i++) {
            System.out.printf("Luồng: %s có độ ưu tiên là %d \n", getName(), getPriority());
        }
    }
}
```

```java
// file: ThreadInfoExample.java

public class ThreadInfoExample {

    public static void main(String[] args) {
        Thread t1 = new WorkingThread("Luồng 1");
        Thread t2 = new WorkingThread("Luồng 2");
        Thread t3 = new WorkingThread("Luồng 3");

        System.out.println("ID luồng 1: " + t1.getId());
        System.out.println("ID luồng 2: " + t2.getId());
        System.out.println("ID luồng 3: " + t3.getId());

        t1.setPriority(1);
        t2.setPriority(5);
        t3.setPriority(10);

        t1.start();
        t2.start();
        t3.start();
    }

}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>ID luồng 1: 10</code><br/>
    <code>ID luồng 2: 11</code><br/>
    <code>ID luồng 3: 12</code><br/>
    <code>Luồng: Luồng 2 có độ ưu tiên là 5</code><br/>
    <code>Luồng: Luồng 2 có độ ưu tiên là 5</code><br/>
    <code>Luồng: Luồng 2 có độ ưu tiên là 5</code><br/>
    <code>Luồng: Luồng 2 có độ ưu tiên là 5</code><br/>
    <code>Luồng: Luồng 2 có độ ưu tiên là 5</code><br/>
    <code>Luồng: Luồng 1 có độ ưu tiên là 1</code><br/>
    <code>Luồng: Luồng 3 có độ ưu tiên là 10</code><br/>
    <code>Luồng: Luồng 3 có độ ưu tiên là 10</code><br/>
    <code>Luồng: Luồng 3 có độ ưu tiên là 10</code><br/>
    <code>Luồng: Luồng 3 có độ ưu tiên là 10</code><br/>
    <code>Luồng: Luồng 3 có độ ưu tiên là 10</code><br/>
    <code>Luồng: Luồng 1 có độ ưu tiên là 1</code><br/>
    <code>Luồng: Luồng 1 có độ ưu tiên là 1</code><br/>
    <code>Luồng: Luồng 1 có độ ưu tiên là 1</code><br/>
    <code>Luồng: Luồng 1 có độ ưu tiên là 1</code>
  </div>
</div>
