---
title: "Vòng đời của Thread trong Java"
description: "Chúng ta sẽ cùng tìm hiểu vòng đời của một thread, các trạng thái mà nó trải qua trước khi chết đi"
chapter:
  name: "Lập trình đa luồng"
  slug: "chuong-06-lap-trinh-da-luong"
image: https://user-images.githubusercontent.com/29374426/146295451-dd3f5502-81f5-4983-bb8b-769b739db327.png
position: 2
---

Khi một chương trình Java khởi chạy, JVM sẽ tạo ra một `thread` gọi là `main thread`, đây là nơi thực thi chương trình. Ngoài `main thread`, chúng ta có thể tạo thêm các `thread` khác tùy theo nhu cầu sử dụng. Khi sử dụng các phương thức như `wait()`, `join()`, `sleep()` để đồng bộ hóa, chúng ta cần biết `thread` đang ở trong trạng thái nào. Trong bài viết này, chúng ta sẽ tìm hiểu về vòng đời của một `thread`, các trạng thái mà nó trải qua trước khi kết thúc.

## Các Trạng Thái trong Vòng Đời của Thread trong Java

Một `thread` có các trạng thái sau:

1. **NEW (Tạo Mới)**: Trạng thái khi `thread` mới được tạo, trước khi gọi `start()`.
2. **RUNNABLE (Đang Thực Thi)**: `Thread` sẵn sàng để chạy sau khi gọi `start()`.
3. **BLOCKED (Bị Chặn)**: `Thread` bị chặn khi cố gắng truy cập một đoạn mã đang được chiếm bởi `thread` khác hoặc khi chờ tài nguyên I/O.
4. **WAITING (Chờ)**: `Thread` chờ vô thời hạn khi gọi `wait()` hoặc chờ với thời gian xác định khi gọi `sleep()`.
5. **TIMED_WAITING (Chờ Với Thời Gian Xác Định)**: `Thread` chờ với thời gian xác định khi gọi `wait(timeout)` hoặc `sleep(timeout)`.
6. **TERMINATED (Chấm Dứt)**: `Thread` kết thúc sau khi thực thi xong hoặc xảy ra ngoại lệ.

Sơ đồ `enum` dưới đây thể hiện các trạng thái trong vòng đời của một `Thread`:

![Vòng Đời của Thread trong Java](https://user-images.githubusercontent.com/29374426/146295451-dd3f5502-81f5-4983-bb8b-769b739db327.png)

### Trạng Thái "NEW" (Tạo Mới)

Khi một `thread` được tạo nhưng chưa gọi `start()`, nó ở trạng thái "NEW".

![Trạng Thái NEW trong Thread](https://user-images.githubusercontent.com/29374426/146178768-3bd727f2-1b89-4b86-9075-eecd71b5bc25.png)

### Trạng Thái "RUNNABLE" (Đang Thực Thi)

Khi gọi `start()`, `thread` chuyển sang trạng thái "RUNNABLE", và hệ thống sẽ quản lý việc thực thi `thread` này.

![Trạng Thái RUNNABLE trong Java](https://user-images.githubusercontent.com/29374426/146178835-533a1939-0f55-4f6b-a05b-c1317e14106c.png)

### Trạng Thái "BLOCKED" (Bị Chặn) và "WAITING" (Chờ)

Khi một `thread` chờ tài nguyên hoặc bị chặn khi truy cập vào đoạn mã đang được chiếm bởi `thread` khác, nó có thể ở trong trạng thái "BLOCKED". Khi `thread` gọi `wait()` hoặc `sleep()`, nó có thể chuyển sang trạng thái "WAITING". Khi các điều kiện thỏa mãn, `thread` sẽ trở lại "RUNNABLE".

![Trạng Thái BLOCKED và WAITING trong Java](https://user-images.githubusercontent.com/29374426/146178947-9994c1aa-4a40-4e87-9fa0-458f2e7809da.png)

### Trạng Thái "TIMED_WAITING" (Chờ Với Thời Gian Xác Định)

Khi `thread` gọi `wait(timeout)` hoặc `sleep(timeout)`, nó chuyển sang trạng thái "TIMED_WAITING". Sau thời gian chờ, `thread` sẽ trở lại "RUNNABLE".

### Trạng Thái "TERMINATED" (Chấm Dứt)

`

Thread` kết thúc sau khi thực thi xong hoặc xảy ra ngoại lệ.

![Trạng Thái TERMINATED trong Java](https://user-images.githubusercontent.com/29374426/146179003-9e3a33f5-22f0-4dcd-9282-f100e70443f1.png)

## Ví Dụ Vòng Đời của Thread trong Java

Dưới đây là một ví dụ minh họa vòng đời của `Thread`:

```java
class MyThread implements Runnable {
    public void run() {
        try {
            Thread.sleep(1500);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.println("Trạng thái của thread1 sau khi gọi join() trên thread2 - " +
                Main.thread1.getState());
        try {
            Thread.sleep(200);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}

public class Main implements Runnable {
    public static Thread thread1;
    public static Main obj;

    public static void main(String[] args) {
        obj = new Main();
        thread1 = new Thread(obj);

        System.out.println("Trạng thái của thread1 sau khi tạo - " + thread1.getState());

        thread1.start();

        System.out.println("Trạng thái của thread1 sau khi gọi start() - " +
                thread1.getState());
    }

    public void run() {
        MyThread myThread = new MyThread();
        Thread thread2 = new Thread(myThread);

        System.out.println("Trạng thái của thread2 sau khi tạo - " + thread2.getState());

        thread2.start();

        System.out.println("Trạng thái của thread2 sau khi gọi start() - " +
                thread2.getState());

        try {
            Thread.sleep(200);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        System.out.println("Trạng thái của thread2 sau khi gọi sleep() - " +
                thread2.getState());

        try {
            thread2.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        System.out.println("Trạng thái của thread2 sau khi kết thúc - " +
                thread2.getState());
    }
}
```

::result
Trạng thái của thread1 sau khi tạo - NEW<br/>
Trạng thái của thread1 sau khi gọi start() - RUNNABLE<br/>
Trạng thái của thread2 sau khi tạo - NEW<br/>
Trạng thái của thread2 sau khi gọi start() - RUNNABLE<br/>
Trạng thái của thread2 sau khi gọi sleep() - TIMED_WAITING<br/>
Trạng thái của thread1 sau khi gọi join() trên thread2 - WAITING<br/>
Trạng thái của thread2 sau khi kết thúc - TERMINATED
::

Trên đây là ví dụ về vòng đời của một `Thread` trong Java, chúng ta đã thấy các trạng thái khác nhau mà một `Thread` có thể trải qua trong quá trình thực thi. Hiểu về vòng đời của `Thread` là quan trọng để quản lý và đồng bộ hóa các `Thread` trong ứng dụng của bạn.
