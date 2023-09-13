---
title: "Vòng đời của Thread trong Java"
description: "Chúng ta sẽ cùng tìm hiểu vòng đời của một thread, các trạng thái mà nó trải qua trước khi chết đi"
chapter:
  name: "Lập trình đa luồng"
  slug: "chuong-06-lap-trinh-da-luong"
category:
  name: "Java"
  slug: "java"
image: https://user-images.githubusercontent.com/29374426/146295451-dd3f5502-81f5-4983-bb8b-769b739db327.png
position: 2
---

Khi một chương trình java khởi chạy JVM sẽ tạo 1 `thread` gọi là `main thread` sẽ được khởi tạo và đây là nơi thực thi chương trình. Ngoài ra chúng ta có thể tạo thêm các `thread` khác tùy vào nhu cầu sử dụng. Khi chương trình tạo ra các `thread` khác ngoài `main thread` thì nhu cầu về đồng bộ hóa là cần thiết để tránh dẫn đến deadlock hoặc thu được các kết quả không mong muốn. Khi sử dụng `wait()`, `join()`, `sleep()` method để đồng bộ hóa có ai đặt câu hỏi rằng `thread` lúc này đang ở trạng thái nào không? Trong bài viết này chúng ta sẽ cùng tìm hiểu vòng đời của một thread, các trạng thái mà nó trải qua trước khi chết đi.

![Vòng đời của Thread trong Java](https://user-images.githubusercontent.com/29374426/146295451-dd3f5502-81f5-4983-bb8b-769b739db327.png)

## Các trạng thái trong vòng đời của thread trong Java

Về cơ bản một thread có các trạng thái sau:

- `New` – Tạo mới
- `Runnable` – Đang thực thi
- `Blocked` – Bị chặn
- `Waiting` – Trạng thái chờ
- `Timed Waiting` – Trạng thái chờ trong một khoảng thời gian xác định
- `Terminated` – Chấm dứt

Sơ đồ các `enum` bên trong một `Thread` sẽ thể hiện rõ nhất các trạng thái bên trong một vòng đời của `Thread` này. Bạn hãy nhìn các state dưới `enum` dưới đây

<img width="686" alt="Vòng đời của thread trong Java" src="https://user-images.githubusercontent.com/29374426/146179060-b8b78f3d-f2fd-4aca-91bc-5e212b4a6a87.png">

Ngay khi bạn tạo mới một `Thread`, nhưng vẫn chưa gọi đến phương thức `start()`, trạng thái của nó sẽ là `NEW`.

![Trạng thái new trong Thread](https://user-images.githubusercontent.com/29374426/146178768-3bd727f2-1b89-4b86-9075-eecd71b5bc25.png)

Còn khi bạn đã gọi đến `start()`, `thread` đó sẽ vào trạng thái `RUNNABLE`, trạng thái này đưa `Thread` vào hàng đợi để đợi hệ thống cấp tài nguyên và khởi chạy sau đó.

![Trạng thái runnable trong java](https://user-images.githubusercontent.com/29374426/146178835-533a1939-0f55-4f6b-a05b-c1317e14106c.png)

Trong quá trình `Thread` đang chạy, nếu có bất kỳ tác động nào, ngoại trừ làm kết thúc vòng đời của `Thread`, nó sẽ vào trạng thái `BLOCKED`, hoặc `WAITING`, hoặc `TIMED_WAITING`.

**Blocked/Waiting:**

- Khi một `thread` ngừng hoạt động tạm thời trong một khoảng thời gian thì nó sẽ nằm 1 trong 2 trạng thái `Blocked` hoặc `Waiting`.
- Khi một `thread` chờ một tác vụ I/O thực thi hoàn tất, nó đang ở trong trạng thái `Blocked`. Khi đang ở trong trại thái này `thread` sẽ không thể thực thi thêm bất kỳ đoạn mã nào của nó cho đến khi nó được chuyển sang trạng thái `Runnable`.
- Các `thread` sẽ bị chặn khi cố truy cập vào một đoạn mã code đang được chiếm bởi một `thread` khác, lúc này chúng sẽ rơi vào trạng thái `Blocked`. Khi đoạn mã được `thread` chiếm đóng giải phóng, chương trình sẽ chọn 1 trong số các `thread` chờ để thực thi đoạn mã hoặc do các điều kiện mà chúng ta đưa ra thì chúng ta chuyển sang trạng thái `Waiting`. Khi một `thread` được chọn để thực thi đoạn mã thì nó sẽ chuyển sang trạng thái `Runnable`.

**Timed Waiting:** các thread sẽ chuyển sang trạng thái `Timed Waiting` khi các method `wait()`, `join()` được gọi với một khoản thời gian cụ thể. Sau khi hết thời gian chờ chúng sẽ quay trở lại với trạng thái `Runnable`.

![Vòng đời thread trong Java](https://user-images.githubusercontent.com/29374426/146178947-9994c1aa-4a40-4e87-9fa0-458f2e7809da.png)

Một `thread` sẽ kết thúc chu trình sống sau khi chúng đã thực thi hết mã bên trong nó hoặc xảy ra một lỗi ngoại lệ nào đó. Sau khi chuyển qua trạng thái `Terminated thread` sẽ không còn tiêu tốn tài nguyên của CPU và đợi cho đến khi trình dọn rác dọn dẹp.

![Trạng thái terminated trong java](https://user-images.githubusercontent.com/29374426/146179003-9e3a33f5-22f0-4dcd-9282-f100e70443f1.png)

Tổng quan là vậy, còn chi tiết từng trạng thái thì chúng ta sẽ tiếp tục đến phầnn tiếpp theo.

## Ví dụ vòng đời của Thread trong Java

```java
class thread implements Runnable {
    public void run() {
        // moving thread2 to timed waiting state
        try {
            Thread.sleep(1500);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.println("State of thread1 while it called join() method on thread2 -" +
                Test.thread1.getState());
        try {
            Thread.sleep(200);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}
class Test implements Runnable {
    public static Thread thread1;
    public static Test obj;
    public static void main(String[] args) {
        obj = new Test();
        thread1 = new Thread(obj);
        // thread1 created and is currently in the NEW state.
        System.out.println("State of thread1 after creating it - " + thread1.getState());
        thread1.start();
        // thread1 moved to Runnable state
        System.out.println("State of thread1 after calling .start() method on it - " +
                thread1.getState());
    }
    public void run() {
        thread myThread = new thread();
        Thread thread2 = new Thread(myThread);
        // thread1 created and is currently in the NEW state.
        System.out.println("State of thread2 after creating it - " + thread2.getState());
        thread2.start();
        // thread2 moved to Runnable state
        System.out.println("State of thread2 after calling .start() method on it - " +
                thread2.getState());
        // moving thread1 to timed waiting state
        try {
            //moving thread1 to timed waiting state
            Thread.sleep(200);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.println("State of thread2 after calling .sleep() method on it - " +
                thread2.getState());
        try {
            // waiting for thread2 to die
            thread2.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.println("State of thread2 when it has finished it's execution - " +
                thread2.getState());
    }
}
```

::result

State of thread1 after creating it – NEW<br/>
State of thread1 after calling .start() method on it – RUNNABLE<br/>
State of thread2 after creating it – NEW<br/>
State of thread2 after calling .start() method on it – RUNNABLE<br/>
State of thread2 after calling .sleep() method on it – TIMED_WAITING<br/>
State of thread1 while it called join() method on thread2 -WAITING<br/>
State of thread2 when it has finished it’s execution – TERMINATED<br/>

::
