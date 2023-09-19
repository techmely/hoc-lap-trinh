---
title: "Các phương thức của lớp Thread trong Java"
description: "Trong Java, lớp Thread cung cấp nhiều phương thức quan trọng để quản lý và kiểm soát luồng thực thi. Dưới đây, chúng ta sẽ tìm hiểu về các phương thức quan trọng của lớp Thread và cách chúng có thể được sử dụng"
chapter:
  name: "Lập trình đa luồng"
  slug: "chuong-06-lap-trinh-da-luong"
category:
  name: "Java"
  slug: "java"
image: https://user-images.githubusercontent.com/29374426/146480996-d756c28a-258f-4913-a357-965e22ee85e6.png
position: 10
---

Lớp `Thread` trong Java cung cấp nhiều phương thức mạnh mẽ để quản lý và tương tác với luồng. Dưới đây, chúng ta sẽ tìm hiểu về các phương thức quan trọng của lớp `Thread` và cách sử dụng chúng.

![Các Phương Thức của Lớp Thread trong Java](https://user-images.githubusercontent.com/29374426/146480996-d756c28a-258f-4913-a357-965e22ee85e6.png)

## Phương thức `suspend()` và `resume()`

- **`suspend()`**: Phương thức này tạm dừng hoạt động của một luồng bằng cách ngưng cung cấp CPU cho luồng đó. Luồng vẫn tồn tại và có thể được khởi động lại bằng phương thức `resume()`. Chú ý rằng việc sử dụng `suspend()` không nên được khuyến nghị vì nó có thể dẫn đến các vấn đề như deadlock.

- **`resume()`**: Phương thức này sử dụng để tiếp tục hoạt động của một luồng sau khi nó đã bị tạm dừng bằng `suspend()`.

**Ví dụ:**

```java
class MyThread extends Thread {
    public void run() {
        for (int i = 1; i <= 5; i++) {
            System.out.println("Thread " + Thread.currentThread().getId() + " - Count: " + i);
            try {
                Thread.sleep(500);
            } catch (InterruptedException e) {
                System.out.println(e);
            }
        }
    }
}

public class SuspendResumeExample {
    public static void main(String[] args) {
        MyThread t1 = new MyThread();
        MyThread t2 = new MyThread();

        t1.start();
        t2.start();

        // Suspend t1 temporarily
        t1.suspend();
        System.out.println("Thread " + t1.getId() + " suspended.");

        try {
            Thread.sleep(2000);
        } catch (InterruptedException e) {
            System.out.println(e);
        }

        // Resume t1
        t1.resume();
        System.out.println("Thread " + t1.getId() + " resumed.");

        try {
            t1.join();
            t2.join();
        } catch (InterruptedException e) {
            System.out.println(e);
        }
    }
}
```

::result

Thread 10 - Count: 1</br>
Thread 11 - Count: 1</br>
Thread 10 - Count: 2</br>
Thread 11 - Count: 2</br>
Thread 10 - Count: 3</br>
Thread 11 - Count: 3</br>
Thread 10 - Count: 4</br>
Thread 11 - Count: 4</br>
Thread 10 - Count: 5</br>
Thread 11 - Count: 5</br>
Thread 10 suspended.</br>
Thread 10 resumed.

::

## Phương thức `stop()`

- **Ý nghĩa**: Phương thức này dùng để kết thúc một luồng bằng cách ném ra ngoại lệ `ThreadDeath`. Tuy nhiên, việc sử dụng `stop()` không được khuyến nghị, vì nó có thể gây ra các vấn đề như sảy ra deadlock và không giải phóng tài nguyên một cách đúng đắn.

## Phương thức `destroy()`

- **Ý nghĩa**: Phương thức này dùng để đột ngột dừng một luồng. Tương tự như `stop()`, việc sử dụng `destroy()` không nên được khuyến nghị do nguy cơ gây ra các vấn đề không mong muốn.

## Phương thức `isAlive()`

- **Ý nghĩa**: Phương thức này kiểm tra xem một luồng còn sống (active) hay không. Nó trả về `true` nếu

luồng đã được khởi động bằng `start()` và vẫn còn hoạt động, ngược lại trả về `false`.

## Phương thức `yield()`

- **Ý nghĩa**: Phương thức `yield()` dùng để nhường CPU cho các luồng khác trong hàng đợi Ready. Nó ngừng cấp CPU trong lần nhận CPU đó và cho phép các luồng khác được chạy.

## Các phương thức khác của lớp Thread trong Java

- **`sleep()`:** Sử dụng để ngừng luồng trong một khoảng thời gian nhất định.
- **`join()`:** Sử dụng để đợi một luồng khác hoàn thành trước khi luồng hiện tại tiếp tục thực thi.
- **`getName()`:** Trả về tên của luồng.
- **`setName()`:** Thay đổi tên của luồng.
- **`getId()`:** Trả về ID của luồng.
- **`getState()`:** Trả về trạng thái của luồng.
- **`currentThread()`:** Trả về tham chiếu của luồng đang được thi hành.
- **`getPriority()`:** Trả về mức độ ưu tiên của luồng.
- **`setPriority()`:** Thay đổi mức độ ưu tiên của luồng.
- **`isDaemon()`:** Kiểm tra xem luồng có phải là luồng daemon hay không.
- **`setDaemon()`:** Xác định xem luồng có phải là luồng daemon hay không.
- **`interrupt()`:** Sử dụng để gián đoạn một luồng, thường dùng để kết thúc một luồng đang chạy.

Trên đây là một số phương thức quan trọng của lớp `Thread` trong Java. Việc hiểu và sử dụng chúng một cách đúng đắn là rất quan trọng để quản lý và tương tác với các luồng trong ứng dụng Java.
