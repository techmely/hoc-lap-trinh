---
title: "Luồng Daemon (Daemon Thread) trong Java"
description: "Java chia thread làm 2 loại một loại thông thường và Daemon Thread, chúng chỉ khác nhau ở cách thức ngừng hoạt động. Trong một chương trình các luồng thông thường và luồng Daemon chạy song song với nhau. Khi tất cả các luồng thông thường kết thúc, mọi luồng Daemon cũng sẽ bị kết thúc theo bất kể nó đang làm việc gì"
chapter:
  name: "Lập trình đa luồng"
  slug: "chuong-06-lap-trinh-da-luong"
category:
  name: "Java"
  slug: "java"
image: https://user-images.githubusercontent.com/29374426/146481113-81aab741-c1b0-4f17-9280-fb7c393c86db.png
position: 7
---

## Luồng Daemon (Daemon Thread) là gì?

Java chia `thread` làm 2 loại một loại thông thường và `Daemon Thread`, chúng chỉ khác nhau ở cách thức ngừng hoạt động. Trong một chương trình các luồng thông thường và luồng `Daemon` chạy song song với nhau. Khi tất cả các luồng thông thường kết thúc, mọi luồng `Daemon` cũng sẽ bị kết thúc theo bất kể nó đang làm việc gì.

![Luồng Daemon (Daemon Thread)](https://user-images.githubusercontent.com/29374426/146481113-81aab741-c1b0-4f17-9280-fb7c393c86db.png)

Sử dụng `setDaemon(boolean)` để xác định một luồng là `Daemon` hoặc không. Chú ý, bạn chỉ có thể gọi hàm `setDeamon(boolean)` khi `thread` chưa được chạy. Điều đó có nghĩa là khi `thread` đã chạy bạn không thể chuyển luồng từ `non-daemon` sang `daemon` và ngược lại. Khi bạn cố gắng thay đổi trạng thái của luồng, một ngoại lệ `IllegalThreadStateException` được ném ra và luồng kết thúc xử lý.

Khi một luồng mới được tạo ra, nó được thừa hưởng đặc tính `daemon` từ luồng cha. Như vậy khi bạn tạo một luồng trong hàm main của 1 `class` nó vốn là luồng `non-daemon`, vì vậy `thread` tạo ra mặc định cũng là `non-daemon`. Như vậy nếu bạn tạo một luồng mới trong một luồng `Daemon`, mặc định nó cũng sẽ là `Daemon` .

## Luồng Daemon thường dùng làm gì?

Một trong các luồng Deamon quan trọng của Java đó là luồng gom rác, nghĩa là gom các tài nguyên không còn sử dụng để giải phóng bộ nhớ. Khi tất cả các luồng người dùng không còn hoạt động nữa luồng gom rác cũng bị dừng theo.

Ví dụ tạo một luồng WorkingThread

```java
package com.gpcoder.daemonthread;

public class WorkingThread implements Runnable {

    @Override
    public void run() {
        while (true) {
            processSomething();
        }
    }

    private void processSomething() {
        try {
            System.out.println("Processing working thread");
            Thread.sleep(500);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }

}
```

Ví dụ chương trình Non-Daemon Thread

```java
package com.gpcoder.daemonthread;

public class NonDaemonThreadTest {
    public static void main(String[] args) throws InterruptedException {
        Thread dt = new Thread(new WorkingThread(), "My Non-Daemon Thread");
        dt.start();

        // continue program
        Thread.sleep(3000);
        System.out.println(">><< Finishing main program");
    }
}
```

::result

Processing working thread</br>
Processing working thread</br>
Processing working thread</br>
Processing working thread</br>
Processing working thread</br>
Processing working thread</br>

> > << Finishing main program</br>
> > Processing working thread</br>
> > Processing working thread</br>
> > Processing working thread

::

Như bạn thấy luồng `Non-Daemon Thread` chạy song song với `MainThread`. Khi MainThread kết thúc thì luồng `Non-Daemon Thread` vẫn còn tiếp tục xử lý cho đến khi hoàn thành.

Ví dụ chương trình Non-Daemon Thread

```java
package com.gpcoder.daemonthread;

public class DaemonThreadTest {

    public static void main(String[] args) throws InterruptedException {
        Thread dt = new Thread(new WorkingThread(), "My Daemon Thread");
        dt.setDaemon(true);
        dt.start();

        // continue program
        Thread.sleep(3000);
        System.out.println(">><< Finishing main program");
    }

}
```

::result

Processing working thread</br>
Processing working thread</br>
Processing working thread</br>
Processing working thread</br>
Processing working thread</br>
Processing working thread</br>

> > << Finishing main program</br>

::

Như bạn thấy `DaemonThread` chạy song song với `MainThread`. Khi `MainThread` kết thúc thì tất cả `DaemonThread` cũng kết thúc.
