---
title: "Các phương thức của lớp Thread trong Java"
description: "Tổng hợp các hàm của lớp Thread như suspend, resume, stop, destroy, isAlive, yeild, getName, currentThread"
keywords:
  [
    "Hàm suspend() của lớp Thread",
    "Hàm resume() của lớp Thread",
    "Hàm stop() của lớp Thread",
    "Hàm destroy() của lớp Thread",
    "Hàm isAlive() của lớp Thread",
    "Hàm yeild() của lớp Thread",
    "Hàm getName() của lớp Thread",
    "Hàm setName(String name) của lớp Thread",
    "Hàm getId() của lớp Thread",
    "Hàm getState() của lớp Thread",
    "Hàm currentThread() của lớp Thread",
    "Hàm getPriority() của lớp Thread",
    "Hàm setPriority(int) của lớp Thread",---
title: "Các phương thức của lớp Thread trong Java"
description: "Tổng hợp các hàm của lớp Thread như suspend, resume, stop, destroy, isAlive, yeild, getName, currentThread"
keywords:
  [
    "Hàm suspend() của lớp Thread",
    "Hàm resume() của lớp Thread",
    "Hàm stop() của lớp Thread",
    "Hàm destroy() của lớp Thread",
    "Hàm isAlive() của lớp Thread",
    "Hàm yeild() của lớp Thread",
    "Hàm getName() của lớp Thread",
    "Hàm setName(String name) của lớp Thread",
    "Hàm getId() của lớp Thread",
    "Hàm getState() của lớp Thread",
    "Hàm currentThread() của lớp Thread",
    "Hàm getPriority() của lớp Thread",
    "Hàm setPriority(int) của lớp Thread",
  ]
chapter:
  name: "Lập trình đa luồng"
  slug: "chuong-06-lap-trinh-da-luong"
category:
  name: "Java"
  slug: "java"
image: https://user-images.githubusercontent.com/29374426/146480996-d756c28a-258f-4913-a357-965e22ee85e6.png
position: 10
---

![Các phương thức của lớp Thread trong Java](https://user-images.githubusercontent.com/29374426/146480996-d756c28a-258f-4913-a357-965e22ee85e6.png)

## Hàm suspend() của lớp Thread

Đây là phương thức làm tạm dừng hoạt động của 1 luồng nào đó bằng các ngưng cung cấp CPU cho luồng này. Để cung cấp lại CPU cho luồng ta sử dụng phương thức `resume()`. Cần lưu ý 1 điều là ta không thể dừng ngay hoạt động của luồng bằng phương thức này. Phương thức `suspend()` không dừng ngay tức thì hoạt động của luồng mà sau khi luồng này trả CPU về cho hệ điều hành thì không cấp CPU cho luồng nữa.

## Hàm resume() của lớp Thread

Đây là phương thức làm cho luồng chạy lại khi luồng bị dừng do phương thức `suspend()` bên trên. Phương thức này sẽ đưa luồng vào lại lịch điều phối CPU để luồng được cấp CPU chạy lại bình thường.

## Hàm stop() của lớp Thread

Luồng này sẽ kết thúc phương thức `run()` bằng cách ném ra 1 ngoại lệ ThreadDeath, điều này cũng sẽ làm luồng kết thúc 1 cách ép buộc. Nếu giả sử, trước khi gọi `stop()` mà luồng đang nắm giữa 1 đối tượng nào đó hoặc 1 tài nguyên nào đó mà luồng khác đang chờ thì có thể dẫn tới việc sảy ra deadlock.

<div class="example">sử dụng hàm suspend, resume, stop</div>

```java
class RunnableDemo implements Runnable {
   public Thread t;
   private String threadName;
   boolean suspended = false;   RunnableDemo( String name){
       threadName = name;
       System.out.println("Creating " +  threadName );
   }
   public void run() {
      System.out.println("Running " +  threadName );
      try {
         for(int i = 10; i > 0; i--) {
            System.out.println("Thread: " + threadName + ", " + i);
            // Let the thread sleep for a while.
            Thread.sleep(300);
            synchronized(this) {
            while(suspended) {
               wait();
            }
          }
         }
     } catch (InterruptedException e) {
         System.out.println("Thread " +  threadName + " interrupted.");
     }
     System.out.println("Thread " +  threadName + " exiting.");
   }   public void start ()
   {
      System.out.println("Starting " +  threadName );
      if (t == null)
      {
         t = new Thread (this, threadName);
         t.start ();
      }
   }
   void suspend() {
      suspended = true;
   }
   synchronized void resume() {
      suspended = false;
       notify();
   }
}public class TestThread {
   public static void main(String args[]) {      RunnableDemo R1 = new RunnableDemo( "Thread-1");
      R1.start();      RunnableDemo R2 = new RunnableDemo( "Thread-2");
      R2.start();      try {
         Thread.sleep(1000);
         R1.suspend();
         System.out.println("Suspending First Thread");
         Thread.sleep(1000);
         R1.resume();
         System.out.println("Resuming First Thread");
         R2.suspend();
         System.out.println("Suspending thread Two");
         Thread.sleep(1000);
         R2.resume();
         System.out.println("Resuming thread Two");
      } catch (InterruptedException e) {
         System.out.println("Main thread Interrupted");
      }
      try {
         System.out.println("Waiting for threads to finish.");
         R1.t.join();
         R2.t.join();
      } catch (InterruptedException e) {
         System.out.println("Main thread Interrupted");
      }
      System.out.println("Main thread exiting.");
   }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>Creating Thread-1</code><br/>
    <code>Starting Thread-1</code><br/>
    <code>Creating Thread-2</code><br/>
    <code>Starting Thread-2</code><br/>
    <code>Running Thread-1</code><br/>
    <code>Thread: Thread-1, 10</code><br/>
    <code>Running Thread-2</code><br/>
    <code>Thread: Thread-2, 10</code><br/>
    <code>Thread: Thread-1, 9</code><br/>
    <code>Thread: Thread-2, 9</code><br/>
    <code>Thread: Thread-1, 8</code><br/>
    <code>Thread: Thread-2, 8</code><br/>
    <code>Thread: Thread-1, 7</code><br/>
    <code>Thread: Thread-2, 7</code><br/>
    <code>Suspending First Thread</code><br/>
    <code>Thread: Thread-2, 6</code><br/>
    <code>Thread: Thread-2, 5</code><br/>
    <code>Thread: Thread-2, 4</code><br/>
    <code>Resuming First Thread</code><br/>
    <code>Suspending thread Two</code><br/>
    <code>Thread: Thread-1, 6</code><br/>
    <code>Thread: Thread-1, 5</code><br/>
    <code>Thread: Thread-1, 4</code><br/>
    <code>Thread: Thread-1, 3</code><br/>
    <code>Resuming thread Two</code><br/>
    <code>Thread: Thread-2, 3</code><br/>
    <code>Waiting for threads to finish.</code><br/>
    <code>Thread: Thread-1, 2</code><br/>
    <code>Thread: Thread-2, 2</code><br/>
    <code>Thread: Thread-1, 1</code><br/>
    <code>Thread: Thread-2, 1</code><br/>
    <code>Thread Thread-1 exiting.</code><br/>
    <code>Thread Thread-2 exiting.</code><br/>
    <code>Main thread exiting.</code><br/>
  </div>
</div>

## Hàm destroy() của lớp Thread

Hàm này dùng để dừng hẳn luồng. So với `suspend()` thì `destroy()` giống gần như hoàn toàn, Khi `destroy()` luồng cũng sẽ không được cấp CPU nữa, có 1 điều cần lưu ý là: Sau khi luồng bị `suspend()` thì có thể cho luồng tiếp tục chạy bằng phương thức `resume()` nhưng với `destroy()` thì sẽ không có phương thức nào để luồng được cấp CPU lại cả. Như vậy, destroy còn nguy hiểm hơn cà `stop()` và `suspend()` vì:

- Tài nguyên của luồng không được giải phóng
- Nếu luồng đang giữ 1 monitor nào đó của 1 đối tượng, mà đối tượng này đang được chờ bởi 1 luồng khác thì phải chờ vô thời hạn vì luồng giữ `monitor` sẽ không bao giờ chạy lại nên deadlock sảy ra.

## Hàm isAlive() của lớp Thread

Phương thức này kiểm tra xem luồng còn active hay không. Phương thức sẽ trả về true nếu luồng đã được `start()` và chưa rơi vào trạng thái dead. Nếu phương thức trả về false thì luồng đang ở trạng thái _"New Thread"_ hoặc là đang ở trạng thái _"Dead"_.

## Hàm yeild() của lớp Thread

Hệ điều hành đa nhiệm sẽ phân phối CPU cho các tiến trình, các luồng theo vòng xoay. Mỗi luồng sẽ được cấp `CPU` trong 1 khoảng thời gian nhất định, sau đó trả lại CPU cho hệ điều hành, hệ điều hành sẽ cấp CPU cho luồng khác. Các luồng sẽ nằm chờ trong hàng đợi Ready để nhận CPU theo thứ tự. Java có cung cấp cho chúng ta 1 phương thức khá đặc biệt là `yeild()`, khi gọi phương thức này luồng sẽ bị ngừng cấp CPU và nhường cho luồng tiếp theo trong hàng chờ Ready. Luồng không phải ngưng cấp CPU như suspend mà chỉ ngưng cấp trong lần nhận CPU đó mà thôi.

## Hàm sleep(), join() của lớp Thread

Tìm hiểu thêm tại [sử dụng sleep và join trong java](/bai-viet/java/su-dung-sleep-va-join-trong-java)

## Hàm getName() của lớp Thread

Hàm getNam trả về tên của thread.

## Hàm setName(String name) của lớp Thread

Thay đổi tên của thread.

## Hàm getId() của lớp Thread

Trả về id của thread.

## Hàm getState() của lớp Thread

Trả về trạng thái của thread.

## Hàm currentThread() của lớp Thread

Trả về tham chiếu của thread đang được thi hành.

## Hàm getPriority() của lớp Thread

Trả về mức độ ưu tiên của thread.

## Hàm setPriority(int) của lớp Thread

Thay đổi mức độ ưu tiên của `thread`.

## Hàm isDaemon() của lớp Thread

Kiểm tra nếu `thread` là một luồng Daemon.

## Hàm setDaemon(boolean) của lớp Thread

Xác định thread là một luồng Daemon hay không.

## Hàm interrupt() của lớp Thread

Làm gián đoạn một luồng trong java. Nếu thread nằm trong trạng thái sleep hoặc `wait`, nghĩa là `sleep()` hoặc `wait()` được gọi ra. Việc gọi phương thức `interrupt()` trên `thread` đó sẽ phá vỡ trạng thái `sleep` hoặc `wait` và ném ra ngoại lệ `InterruptedException`. Nếu `thread` không ở trong trạng thái `sleep` hoặc `wait`, việc gọi phương thức `interrupt()` thực hiện hành vi bình thường và không làm gián đoạn thread nhưng đặt cờ `interrupt` thành `true`.

## Hàm isInterrupted() của lớp Thread

Kiểm tra nếu thread đã bị ngắt.

## Hàm interrupted() của lớp Thread

Kiểm tra nếu thread hiện tại đã bị ngắt.
---
title: "Các phương thức của lớp Thread trong Java"
description: "Tổng hợp các hàm của lớp Thread như suspend, resume, stop, destroy, isAlive, yeild, getName, currentThread"
keywords:
  [
    "Hàm suspend() của lớp Thread",
    "Hàm resume() của lớp Thread",
    "Hàm stop() của lớp Thread",
    "Hàm destroy() của lớp Thread",
    "Hàm isAlive() của lớp Thread",
    "Hàm yeild() của lớp Thread",
    "Hàm getName() của lớp Thread",
    "Hàm setName(String name) của lớp Thread",
    "Hàm getId() của lớp Thread",
    "Hàm getState() của lớp Thread",
    "Hàm currentThread() của lớp Thread",
    "Hàm getPriority() của lớp Thread",
    "Hàm setPriority(int) của lớp Thread",
  ]
chapter:
  name: "Lập trình đa luồng"
  slug: "chuong-06-lap-trinh-da-luong"
category:
  name: "Java"
  slug: "java"
image: https://user-images.githubusercontent.com/29374426/146480996-d756c28a-258f-4913-a357-965e22ee85e6.png
position: 10
---

![Các phương thức của lớp Thread trong Java](https://user-images.githubusercontent.com/29374426/146480996-d756c28a-258f-4913-a357-965e22ee85e6.png)

## Hàm suspend() của lớp Thread

Đây là phương thức làm tạm dừng hoạt động của 1 luồng nào đó bằng các ngưng cung cấp CPU cho luồng này. Để cung cấp lại CPU cho luồng ta sử dụng phương thức `resume()`. Cần lưu ý 1 điều là ta không thể dừng ngay hoạt động của luồng bằng phương thức này. Phương thức `suspend()` không dừng ngay tức thì hoạt động của luồng mà sau khi luồng này trả CPU về cho hệ điều hành thì không cấp CPU cho luồng nữa.

## Hàm resume() của lớp Thread

Đây là phương thức làm cho luồng chạy lại khi luồng bị dừng do phương thức `suspend()` bên trên. Phương thức này sẽ đưa luồng vào lại lịch điều phối CPU để luồng được cấp CPU chạy lại bình thường.

## Hàm stop() của lớp Thread

Luồng này sẽ kết thúc phương thức `run()` bằng cách ném ra 1 ngoại lệ ThreadDeath, điều này cũng sẽ làm luồng kết thúc 1 cách ép buộc. Nếu giả sử, trước khi gọi `stop()` mà luồng đang nắm giữa 1 đối tượng nào đó hoặc 1 tài nguyên nào đó mà luồng khác đang chờ thì có thể dẫn tới việc sảy ra deadlock.

<div class="example">sử dụng hàm suspend, resume, stop</div>

```java
class RunnableDemo implements Runnable {
   public Thread t;
   private String threadName;
   boolean suspended = false;   RunnableDemo( String name){
       threadName = name;
       System.out.println("Creating " +  threadName );
   }
   public void run() {
      System.out.println("Running " +  threadName );
      try {
         for(int i = 10; i > 0; i--) {
            System.out.println("Thread: " + threadName + ", " + i);
            // Let the thread sleep for a while.
            Thread.sleep(300);
            synchronized(this) {
            while(suspended) {
               wait();
            }
          }
         }
     } catch (InterruptedException e) {
         System.out.println("Thread " +  threadName + " interrupted.");
     }
     System.out.println("Thread " +  threadName + " exiting.");
   }   public void start ()
   {
      System.out.println("Starting " +  threadName );
      if (t == null)
      {
         t = new Thread (this, threadName);
         t.start ();
      }
   }
   void suspend() {
      suspended = true;
   }
   synchronized void resume() {
      suspended = false;
       notify();
   }
}public class TestThread {
   public static void main(String args[]) {      RunnableDemo R1 = new RunnableDemo( "Thread-1");
      R1.start();      RunnableDemo R2 = new RunnableDemo( "Thread-2");
      R2.start();      try {
         Thread.sleep(1000);
         R1.suspend();
         System.out.println("Suspending First Thread");
         Thread.sleep(1000);
         R1.resume();
         System.out.println("Resuming First Thread");
         R2.suspend();
         System.out.println("Suspending thread Two");
         Thread.sleep(1000);
         R2.resume();
         System.out.println("Resuming thread Two");
      } catch (InterruptedException e) {
         System.out.println("Main thread Interrupted");
      }
      try {
         System.out.println("Waiting for threads to finish.");
         R1.t.join();
         R2.t.join();
      } catch (InterruptedException e) {
         System.out.println("Main thread Interrupted");
      }
      System.out.println("Main thread exiting.");
   }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>Creating Thread-1</code><br/>
    <code>Starting Thread-1</code><br/>
    <code>Creating Thread-2</code><br/>
    <code>Starting Thread-2</code><br/>
    <code>Running Thread-1</code><br/>
    <code>Thread: Thread-1, 10</code><br/>
    <code>Running Thread-2</code><br/>
    <code>Thread: Thread-2, 10</code><br/>
    <code>Thread: Thread-1, 9</code><br/>
    <code>Thread: Thread-2, 9</code><br/>
    <code>Thread: Thread-1, 8</code><br/>
    <code>Thread: Thread-2, 8</code><br/>
    <code>Thread: Thread-1, 7</code><br/>
    <code>Thread: Thread-2, 7</code><br/>
    <code>Suspending First Thread</code><br/>
    <code>Thread: Thread-2, 6</code><br/>
    <code>Thread: Thread-2, 5</code><br/>
    <code>Thread: Thread-2, 4</code><br/>
    <code>Resuming First Thread</code><br/>
    <code>Suspending thread Two</code><br/>
    <code>Thread: Thread-1, 6</code><br/>
    <code>Thread: Thread-1, 5</code><br/>
    <code>Thread: Thread-1, 4</code><br/>
    <code>Thread: Thread-1, 3</code><br/>
    <code>Resuming thread Two</code><br/>
    <code>Thread: Thread-2, 3</code><br/>
    <code>Waiting for threads to finish.</code><br/>
    <code>Thread: Thread-1, 2</code><br/>
    <code>Thread: Thread-2, 2</code><br/>
    <code>Thread: Thread-1, 1</code><br/>
    <code>Thread: Thread-2, 1</code><br/>
    <code>Thread Thread-1 exiting.</code><br/>
    <code>Thread Thread-2 exiting.</code><br/>
    <code>Main thread exiting.</code><br/>
  </div>
</div>

## Hàm destroy() của lớp Thread

Hàm này dùng để dừng hẳn luồng. So với `suspend()` thì `destroy()` giống gần như hoàn toàn, Khi `destroy()` luồng cũng sẽ không được cấp CPU nữa, có 1 điều cần lưu ý là: Sau khi luồng bị `suspend()` thì có thể cho luồng tiếp tục chạy bằng phương thức `resume()` nhưng với `destroy()` thì sẽ không có phương thức nào để luồng được cấp CPU lại cả. Như vậy, destroy còn nguy hiểm hơn cà `stop()` và `suspend()` vì:

- Tài nguyên của luồng không được giải phóng
- Nếu luồng đang giữ 1 monitor nào đó của 1 đối tượng, mà đối tượng này đang được chờ bởi 1 luồng khác thì phải chờ vô thời hạn vì luồng giữ `monitor` sẽ không bao giờ chạy lại nên deadlock sảy ra.

## Hàm isAlive() của lớp Thread

Phương thức này kiểm tra xem luồng còn active hay không. Phương thức sẽ trả về true nếu luồng đã được `start()` và chưa rơi vào trạng thái dead. Nếu phương thức trả về false thì luồng đang ở trạng thái _"New Thread"_ hoặc là đang ở trạng thái _"Dead"_.

## Hàm yeild() của lớp Thread

Hệ điều hành đa nhiệm sẽ phân phối CPU cho các tiến trình, các luồng theo vòng xoay. Mỗi luồng sẽ được cấp `CPU` trong 1 khoảng thời gian nhất định, sau đó trả lại CPU cho hệ điều hành, hệ điều hành sẽ cấp CPU cho luồng khác. Các luồng sẽ nằm chờ trong hàng đợi Ready để nhận CPU theo thứ tự. Java có cung cấp cho chúng ta 1 phương thức khá đặc biệt là `yeild()`, khi gọi phương thức này luồng sẽ bị ngừng cấp CPU và nhường cho luồng tiếp theo trong hàng chờ Ready. Luồng không phải ngưng cấp CPU như suspend mà chỉ ngưng cấp trong lần nhận CPU đó mà thôi.

## Hàm sleep(), join() của lớp Thread

Tìm hiểu thêm tại [sử dụng sleep và join trong java](/bai-viet/java/su-dung-sleep-va-join-trong-java)

## Hàm getName() của lớp Thread

Hàm getNam trả về tên của thread.

## Hàm setName(String name) của lớp Thread

Thay đổi tên của thread.

## Hàm getId() của lớp Thread

Trả về id của thread.

## Hàm getState() của lớp Thread

Trả về trạng thái của thread.

## Hàm currentThread() của lớp Thread

Trả về tham chiếu của thread đang được thi hành.

## Hàm getPriority() của lớp Thread

Trả về mức độ ưu tiên của thread.

## Hàm setPriority(int) của lớp Thread

Thay đổi mức độ ưu tiên của `thread`.

## Hàm isDaemon() của lớp Thread

Kiểm tra nếu `thread` là một luồng Daemon.

## Hàm setDaemon(boolean) của lớp Thread

Xác định thread là một luồng Daemon hay không.

## Hàm interrupt() của lớp Thread

Làm gián đoạn một luồng trong java. Nếu thread nằm trong trạng thái sleep hoặc `wait`, nghĩa là `sleep()` hoặc `wait()` được gọi ra. Việc gọi phương thức `interrupt()` trên `thread` đó sẽ phá vỡ trạng thái `sleep` hoặc `wait` và ném ra ngoại lệ `InterruptedException`. Nếu `thread` không ở trong trạng thái `sleep` hoặc `wait`, việc gọi phương thức `interrupt()` thực hiện hành vi bình thường và không làm gián đoạn thread nhưng đặt cờ `interrupt` thành `true`.

## Hàm isInterrupted() của lớp Thread

Kiểm tra nếu thread đã bị ngắt.

## Hàm interrupted() của lớp Thread

Kiểm tra nếu thread hiện tại đã bị ngắt.

  ]
chapter:
  name: "Lập trình đa luồng"
  slug: "chuong-06-lap-trinh-da-luong"
category:
  name: "Java"
  slug: "java"
image: https://user-images.githubusercontent.com/29374426/146480996-d756c28a-258f-4913-a357-965e22ee85e6.png
position: 10
---

![Các phương thức của lớp Thread trong Java](https://user-images.githubusercontent.com/29374426/146480996-d756c28a-258f-4913-a357-965e22ee85e6.png)

## Hàm suspend() của lớp Thread

Đây là phương thức làm tạm dừng hoạt động của 1 luồng nào đó bằng các ngưng cung cấp CPU cho luồng này. Để cung cấp lại CPU cho luồng ta sử dụng phương thức `resume()`. Cần lưu ý 1 điều là ta không thể dừng ngay hoạt động của luồng bằng phương thức này. Phương thức `suspend()` không dừng ngay tức thì hoạt động của luồng mà sau khi luồng này trả CPU về cho hệ điều hành thì không cấp CPU cho luồng nữa.
---
title: "Các phương thức của lớp Thread trong Java"
description: "Tổng hợp các hàm của lớp Thread như suspend, resume, stop, destroy, isAlive, yeild, getName, currentThread"
keywords:
  [
    "Hàm suspend() của lớp Thread",
    "Hàm resume() của lớp Thread",
    "Hàm stop() của lớp Thread",
    "Hàm destroy() của lớp Thread",
    "Hàm isAlive() của lớp Thread",
    "Hàm yeild() của lớp Thread",
    "Hàm getName() của lớp Thread",
    "Hàm setName(String name) của lớp Thread",
    "Hàm getId() của lớp Thread",
    "Hàm getState() của lớp Thread",
    "Hàm currentThread() của lớp Thread",
    "Hàm getPriority() của lớp Thread",
    "Hàm setPriority(int) của lớp Thread",
  ]
chapter:
  name: "Lập trình đa luồng"
  slug: "chuong-06-lap-trinh-da-luong"
category:
  name: "Java"
  slug: "java"
image: https://user-images.githubusercontent.com/29374426/146480996-d756c28a-258f-4913-a357-965e22ee85e6.png
position: 10
---

![Các phương thức của lớp Thread trong Java](https://user-images.githubusercontent.com/29374426/146480996-d756c28a-258f-4913-a357-965e22ee85e6.png)

## Hàm suspend() của lớp Thread

Đây là phương thức làm tạm dừng hoạt động của 1 luồng nào đó bằng các ngưng cung cấp CPU cho luồng này. Để cung cấp lại CPU cho luồng ta sử dụng phương thức `resume()`. Cần lưu ý 1 điều là ta không thể dừng ngay hoạt động của luồng bằng phương thức này. Phương thức `suspend()` không dừng ngay tức thì hoạt động của luồng mà sau khi luồng này trả CPU về cho hệ điều hành thì không cấp CPU cho luồng nữa.

## Hàm resume() của lớp Thread

Đây là phương thức làm cho luồng chạy lại khi luồng bị dừng do phương thức `suspend()` bên trên. Phương thức này sẽ đưa luồng vào lại lịch điều phối CPU để luồng được cấp CPU chạy lại bình thường.

## Hàm stop() của lớp Thread

Luồng này sẽ kết thúc phương thức `run()` bằng cách ném ra 1 ngoại lệ ThreadDeath, điều này cũng sẽ làm luồng kết thúc 1 cách ép buộc. Nếu giả sử, trước khi gọi `stop()` mà luồng đang nắm giữa 1 đối tượng nào đó hoặc 1 tài nguyên nào đó mà luồng khác đang chờ thì có thể dẫn tới việc sảy ra deadlock.

<div class="example">sử dụng hàm suspend, resume, stop</div>

```java
class RunnableDemo implements Runnable {
   public Thread t;
   private String threadName;
   boolean suspended = false;   RunnableDemo( String name){
       threadName = name;
       System.out.println("Creating " +  threadName );
   }
   public void run() {
      System.out.println("Running " +  threadName );
      try {
         for(int i = 10; i > 0; i--) {
            System.out.println("Thread: " + threadName + ", " + i);
            // Let the thread sleep for a while.
            Thread.sleep(300);
            synchronized(this) {
            while(suspended) {
               wait();
            }
          }
         }
     } catch (InterruptedException e) {
         System.out.println("Thread " +  threadName + " interrupted.");
     }
     System.out.println("Thread " +  threadName + " exiting.");
   }   public void start ()
   {
      System.out.println("Starting " +  threadName );
      if (t == null)
      {
         t = new Thread (this, threadName);
         t.start ();
      }
   }
   void suspend() {
      suspended = true;
   }
   synchronized void resume() {
      suspended = false;
       notify();
   }
}public class TestThread {
   public static void main(String args[]) {      RunnableDemo R1 = new RunnableDemo( "Thread-1");
      R1.start();      RunnableDemo R2 = new RunnableDemo( "Thread-2");
      R2.start();      try {
         Thread.sleep(1000);
         R1.suspend();
         System.out.println("Suspending First Thread");
         Thread.sleep(1000);
         R1.resume();
         System.out.println("Resuming First Thread");
         R2.suspend();
         System.out.println("Suspending thread Two");
         Thread.sleep(1000);
         R2.resume();
         System.out.println("Resuming thread Two");
      } catch (InterruptedException e) {
         System.out.println("Main thread Interrupted");
      }
      try {
         System.out.println("Waiting for threads to finish.");
         R1.t.join();
         R2.t.join();
      } catch (InterruptedException e) {
         System.out.println("Main thread Interrupted");
      }
      System.out.println("Main thread exiting.");
   }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>Creating Thread-1</code><br/>
    <code>Starting Thread-1</code><br/>
    <code>Creating Thread-2</code><br/>
    <code>Starting Thread-2</code><br/>
    <code>Running Thread-1</code><br/>
    <code>Thread: Thread-1, 10</code><br/>
    <code>Running Thread-2</code><br/>
    <code>Thread: Thread-2, 10</code><br/>
    <code>Thread: Thread-1, 9</code><br/>
    <code>Thread: Thread-2, 9</code><br/>
    <code>Thread: Thread-1, 8</code><br/>
    <code>Thread: Thread-2, 8</code><br/>
    <code>Thread: Thread-1, 7</code><br/>
    <code>Thread: Thread-2, 7</code><br/>
    <code>Suspending First Thread</code><br/>
    <code>Thread: Thread-2, 6</code><br/>
    <code>Thread: Thread-2, 5</code><br/>
    <code>Thread: Thread-2, 4</code><br/>
    <code>Resuming First Thread</code><br/>
    <code>Suspending thread Two</code><br/>
    <code>Thread: Thread-1, 6</code><br/>
    <code>Thread: Thread-1, 5</code><br/>
    <code>Thread: Thread-1, 4</code><br/>
    <code>Thread: Thread-1, 3</code><br/>
    <code>Resuming thread Two</code><br/>
    <code>Thread: Thread-2, 3</code><br/>
    <code>Waiting for threads to finish.</code><br/>
    <code>Thread: Thread-1, 2</code><br/>
    <code>Thread: Thread-2, 2</code><br/>
    <code>Thread: Thread-1, 1</code><br/>
    <code>Thread: Thread-2, 1</code><br/>
    <code>Thread Thread-1 exiting.</code><br/>
    <code>Thread Thread-2 exiting.</code><br/>
    <code>Main thread exiting.</code><br/>
  </div>
</div>

## Hàm destroy() của lớp Thread

Hàm này dùng để dừng hẳn luồng. So với `suspend()` thì `destroy()` giống gần như hoàn toàn, Khi `destroy()` luồng cũng sẽ không được cấp CPU nữa, có 1 điều cần lưu ý là: Sau khi luồng bị `suspend()` thì có thể cho luồng tiếp tục chạy bằng phương thức `resume()` nhưng với `destroy()` thì sẽ không có phương thức nào để luồng được cấp CPU lại cả. Như vậy, destroy còn nguy hiểm hơn cà `stop()` và `suspend()` vì:

- Tài nguyên của luồng không được giải phóng
- Nếu luồng đang giữ 1 monitor nào đó của 1 đối tượng, mà đối tượng này đang được chờ bởi 1 luồng khác thì phải chờ vô thời hạn vì luồng giữ `monitor` sẽ không bao giờ chạy lại nên deadlock sảy ra.

## Hàm isAlive() của lớp Thread

Phương thức này kiểm tra xem luồng còn active hay không. Phương thức sẽ trả về true nếu luồng đã được `start()` và chưa rơi vào trạng thái dead. Nếu phương thức trả về false thì luồng đang ở trạng thái _"New Thread"_ hoặc là đang ở trạng thái _"Dead"_.

## Hàm yeild() của lớp Thread

Hệ điều hành đa nhiệm sẽ phân phối CPU cho các tiến trình, các luồng theo vòng xoay. Mỗi luồng sẽ được cấp `CPU` trong 1 khoảng thời gian nhất định, sau đó trả lại CPU cho hệ điều hành, hệ điều hành sẽ cấp CPU cho luồng khác. Các luồng sẽ nằm chờ trong hàng đợi Ready để nhận CPU theo thứ tự. Java có cung cấp cho chúng ta 1 phương thức khá đặc biệt là `yeild()`, khi gọi phương thức này luồng sẽ bị ngừng cấp CPU và nhường cho luồng tiếp theo trong hàng chờ Ready. Luồng không phải ngưng cấp CPU như suspend mà chỉ ngưng cấp trong lần nhận CPU đó mà thôi.

## Hàm sleep(), join() của lớp Thread

Tìm hiểu thêm tại [sử dụng sleep và join trong java](/bai-viet/java/su-dung-sleep-va-join-trong-java)

## Hàm getName() của lớp Thread

Hàm getNam trả về tên của thread.

## Hàm setName(String name) của lớp Thread

Thay đổi tên của thread.

## Hàm getId() của lớp Thread

Trả về id của thread.

## Hàm getState() của lớp Thread

Trả về trạng thái của thread.

## Hàm currentThread() của lớp Thread

Trả về tham chiếu của thread đang được thi hành.

## Hàm getPriority() của lớp Thread

Trả về mức độ ưu tiên của thread.

## Hàm setPriority(int) của lớp Thread

Thay đổi mức độ ưu tiên của `thread`.

## Hàm isDaemon() của lớp Thread

Kiểm tra nếu `thread` là một luồng Daemon.

## Hàm setDaemon(boolean) của lớp Thread

Xác định thread là một luồng Daemon hay không.

## Hàm interrupt() của lớp Thread

Làm gián đoạn một luồng trong java. Nếu thread nằm trong trạng thái sleep hoặc `wait`, nghĩa là `sleep()` hoặc `wait()` được gọi ra. Việc gọi phương thức `interrupt()` trên `thread` đó sẽ phá vỡ trạng thái `sleep` hoặc `wait` và ném ra ngoại lệ `InterruptedException`. Nếu `thread` không ở trong trạng thái `sleep` hoặc `wait`, việc gọi phương thức `interrupt()` thực hiện hành vi bình thường và không làm gián đoạn thread nhưng đặt cờ `interrupt` thành `true`.

## Hàm isInterrupted() của lớp Thread

Kiểm tra nếu thread đã bị ngắt.

## Hàm interrupted() của lớp Thread

Kiểm tra nếu thread hiện tại đã bị ngắt.

## Hàm resume() của lớp Thread

Đây là phương thức làm cho luồng chạy lại khi luồng bị dừng do phương thức `suspend()` bên trên. Phương thức này sẽ đưa luồng vào lại lịch điều phối CPU để luồng được cấp CPU chạy lại bình thường.

## Hàm stop() của lớp Thread

Luồng này sẽ kết thúc phương thức `run()` bằng cách ném ra 1 ngoại lệ ThreadDeath, điều này cũng sẽ làm luồng kết thúc 1 cách ép buộc. Nếu giả sử, trước khi gọi `stop()` mà luồng đang nắm giữa 1 đối tượng nào đó hoặc 1 tài nguyên nào đó mà luồng khác đang chờ thì có thể dẫn tới việc sảy ra deadlock.

<div class="example">sử dụng hàm suspend, resume, stop</div>

```java
class RunnableDemo implements Runnable {
   public Thread t;
   private String threadName;
   boolean suspended = false;   RunnableDemo( String name){
       threadName = name;
       System.out.println("Creating " +  threadName );
   }
   public void run() {
      System.out.println("Running " +  threadName );
      try {
         for(int i = 10; i > 0; i--) {
            System.out.println("Thread: " + threadName + ", " + i);
            // Let the thread sleep for a while.
            Thread.sleep(300);
            synchronized(this) {
            while(suspended) {
               wait();
            }
          }
         }
     } catch (InterruptedException e) {
         System.out.println("Thread " +  threadName + " interrupted.");
     }
     System.out.println("Thread " +  threadName + " exiting.");
   }   public void start ()
   {
      System.out.println("Starting " +  threadName );
      if (t == null)
      {
         t = new Thread (this, threadName);
         t.start ();
      }
   }
   void suspend() {
      suspended = true;
   }
   synchronized void resume() {
      suspended = false;
       notify();
   }
}public class TestThread {
   public static void main(String args[]) {      RunnableDemo R1 = new RunnableDemo( "Thread-1");
      R1.start();      RunnableDemo R2 = new RunnableDemo( "Thread-2");
      R2.start();      try {
         Thread.sleep(1000);
         R1.suspend();
         System.out.println("Suspending First Thread");
         Thread.sleep(1000);
         R1.resume();
         System.out.println("Resuming First Thread");
         R2.suspend();
         System.out.println("Suspending thread Two");
         Thread.sleep(1000);
         R2.resume();
         System.out.println("Resuming thread Two");
      } catch (InterruptedException e) {
         System.out.println("Main thread Interrupted");
      }
      try {
         System.out.println("Waiting for threads to finish.");
         R1.t.join();
         R2.t.join();
      } catch (InterruptedException e) {
         System.out.println("Main thread Interrupted");
      }
      System.out.println("Main thread exiting.");
   }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>Creating Thread-1</code><br/>
    <code>Starting Thread-1</code><br/>
    <code>Creating Thread-2</code><br/>
    <code>Starting Thread-2</code><br/>
    <code>Running Thread-1</code><br/>
    <code>Thread: Thread-1, 10</code><br/>
    <code>Running Thread-2</code><br/>
    <code>Thread: Thread-2, 10</code><br/>
    <code>Thread: Thread-1, 9</code><br/>
    <code>Thread: Thread-2, 9</code><br/>
    <code>Thread: Thread-1, 8</code><br/>
    <code>Thread: Thread-2, 8</code><br/>
    <code>Thread: Thread-1, 7</code><br/>
    <code>Thread: Thread-2, 7</code><br/>
    <code>Suspending First Thread</code><br/>
    <code>Thread: Thread-2, 6</code><br/>
    <code>Thread: Thread-2, 5</code><br/>
    <code>Thread: Thread-2, 4</code><br/>
    <code>Resuming First Thread</code><br/>
    <code>Suspending thread Two</code><br/>
    <code>Thread: Thread-1, 6</code><br/>
    <code>Thread: Thread-1, 5</code><br/>
    <code>Thread: Thread-1, 4</code><br/>
    <code>Thread: Thread-1, 3</code><br/>
    <code>Resuming thread Two</code><br/>
    <code>Thread: Thread-2, 3</code><br/>
    <code>Waiting for threads to finish.</code><br/>
    <code>Thread: Thread-1, 2</code><br/>
    <code>Thread: Thread-2, 2</code><br/>
    <code>Thread: Thread-1, 1</code><br/>
    <code>Thread: Thread-2, 1</code><br/>
    <code>Thread Thread-1 exiting.</code><br/>
    <code>Thread Thread-2 exiting.</code><br/>
    <code>Main thread exiting.</code><br/>
  </div>
</div>

## Hàm destroy() của lớp Thread

Hàm này dùng để dừng hẳn luồng. So với `suspend()` thì `destroy()` giống gần như hoàn toàn, Khi `destroy()` luồng cũng sẽ không được cấp CPU nữa, có 1 điều cần lưu ý là: Sau khi luồng bị `suspend()` thì có thể cho luồng tiếp tục chạy bằng phương thức `resume()` nhưng với `destroy()` thì sẽ không có phương thức nào để luồng được cấp CPU lại cả. Như vậy, destroy còn nguy hiểm hơn cà `stop()` và `suspend()` vì:

- Tài nguyên của luồng không được giải phóng
- Nếu luồng đang giữ 1 monitor nào đó của 1 đối tượng, mà đối tượng này đang được chờ bởi 1 luồng khác thì phải chờ vô thời hạn vì luồng giữ `monitor` sẽ không bao giờ chạy lại nên deadlock sảy ra.

## Hàm isAlive() của lớp Thread

Phương thức này kiểm tra xem luồng còn active hay không. Phương thức sẽ trả về true nếu luồng đã được `start()` và chưa rơi vào trạng thái dead. Nếu phương thức trả về false thì luồng đang ở trạng thái _"New Thread"_ hoặc là đang ở trạng thái _"Dead"_.

## Hàm yeild() của lớp Thread

Hệ điều hành đa nhiệm sẽ phân phối CPU cho các tiến trình, các luồng theo vòng xoay. Mỗi luồng sẽ được cấp `CPU` trong 1 khoảng thời gian nhất định, sau đó trả lại CPU cho hệ điều hành, hệ điều hành sẽ cấp CPU cho luồng khác. Các luồng sẽ nằm chờ trong hàng đợi Ready để nhận CPU theo thứ tự. Java có cung cấp cho chúng ta 1 phương thức khá đặc biệt là `yeild()`, khi gọi phương thức này luồng sẽ bị ngừng cấp CPU và nhường cho luồng tiếp theo trong hàng chờ Ready. Luồng không phải ngưng cấp CPU như suspend mà chỉ ngưng cấp trong lần nhận CPU đó mà thôi.

## Hàm sleep(), join() của lớp Thread

Tìm hiểu thêm tại [sử dụng sleep và join trong java](/bai-viet/java/su-dung-sleep-va-join-trong-java)

## Hàm getName() của lớp Thread

Hàm getNam trả về tên của thread.

## Hàm setName(String name) của lớp Thread

Thay đổi tên của thread.

## Hàm getId() của lớp Thread

Trả về id của thread.

## Hàm getState() của lớp Thread

Trả về trạng thái của thread.

## Hàm currentThread() của lớp Thread

Trả về tham chiếu của thread đang được thi hành.

## Hàm getPriority() của lớp Thread

Trả về mức độ ưu tiên của thread.

## Hàm setPriority(int) của lớp Thread

Thay đổi mức độ ưu tiên của `thread`.

## Hàm isDaemon() của lớp Thread

Kiểm tra nếu `thread` là một luồng Daemon.

## Hàm setDaemon(boolean) của lớp Thread

Xác định thread là một luồng Daemon hay không.

## Hàm interrupt() của lớp Thread

Làm gián đoạn một luồng trong java. Nếu thread nằm trong trạng thái sleep hoặc `wait`, nghĩa là `sleep()` hoặc `wait()` được gọi ra. Việc gọi phương thức `interrupt()` trên `thread` đó sẽ phá vỡ trạng thái `sleep` hoặc `wait` và ném ra ngoại lệ `InterruptedException`. Nếu `thread` không ở trong trạng thái `sleep` hoặc `wait`, việc gọi phương thức `interrupt()` thực hiện hành vi bình thường và không làm gián đoạn thread nhưng đặt cờ `interrupt` thành `true`.

## Hàm isInterrupted() của lớp Thread

Kiểm tra nếu thread đã bị ngắt.

## Hàm interrupted() của lớp Thread

Kiểm tra nếu thread hiện tại đã bị ngắt.
