---
title: "Sử dụng sleep() và join() trong Java"
description: "Thread.sleep() được sử dụng để tạm ngưng quá trình của thread hiện tại với một khoảng thời gian được chỉ định. Phương thức join() được sử dụng để đảm bảo cho quá trình thực thi của Thread đang chạy không bị gián đoạn bởi các Thread khác"
chapter:
  name: "Lập trình đa luồng"
  slug: "chuong-06-lap-trinh-da-luong"
category:
  name: "Java"
  slug: "java"
image: https://user-images.githubusercontent.com/29374426/146351845-14230f5d-ebfc-4997-b0e9-3c11d1a0e345.png
position: 6
---

## Thread sleep() là gì?

`Thread.sleep()` được sử dụng để tạm ngưng quá trình của `thread` hiện tại với một khoảng thời gian được chỉ định. Lưu ý khoảng thời gian tạm ngưng không thể là số âm nếu không sẽ bị ném ra [exception](/bai-viet/java/exception-trong-java) `IllegalArgumentException`.

![Thread sleep](https://user-images.githubusercontent.com/29374426/146351845-14230f5d-ebfc-4997-b0e9-3c11d1a0e345.png)

Chúng ta có các overloading `sleep()` sau:

- `Thread.sleep(long millis)` – Tạm ngưng `thread` hiện tại khoảng millis.
- `Thread.sleep(long milis, long nanos)` – Tạm ngưng thread hiện tại khoảng `millis` và thêm một khoảng nanos từ `0` đến `999999`.

## Thread sleep() hoạt động như thế nào?

`Thread.sleep()` sẽ nói chuyện với [trình lên lịch](/bai-viet/java/trinh-len-lich-cua-thread-trong-java) của hệ thống để đẩy thread hiện tại và trạng thái chờ với một khoảng thời gian được chỉ định. Khi khoảng thời gian chờ `thread` sẽ chuyển từ trạng thái chờ sang trạng thais `runnable` và chờ đến khi `CPU` thực thi tiếp thread.

Như vậy khoảng thời gian chờ thật sự sẽ phụ thuộc vào [trình lên lịch](/bai-viet/java/trinh-len-lich-cua-thread-trong-java) và bộ hẹn giờ của hệ thống. Nếu hệ thống đang rảnh thì khoảng thời gian chờ có thể gần với khoảng thời gian mà chúng ta chỉ định, còn nếu hệ thống đang bận thì khoảng chênh lệch sẽ khá lớn so với khoảng thời gian được chỉ định.

Thread sleep sẽ không làm ảnh hưởng đến `thread` hiện tại mà chỉ đơn giản là tạm ngưng thực thi một khoảng thời gian, các cơ chế đồng bộ, các kết quả tính toán sẽ không bị ảnh hưởng. Một `thread` đang ngủ có thể bị làm gián đoạn bởi các `thread` khác đang chạy, lúc này `thread` đang ngủ sẽ thức dậy và ném `InterruptedException`, cho nên chúng ta phải xử lý exception cho `sleep()`.

<div class="example">Tạm ngưng main thread trong khoảng thời gian 2000ms</div>

```java
public class ThreadSleep {
    public static void main(String[] args) throws InterruptedException {
        long start = System.currentTimeMillis();
        Thread.sleep(2000);
        System.out.println("Sleep time in ms = "+(System.currentTimeMillis()-start));

    }
}
```

::Result

    <code>Output: leep time in ms = 2001</code>

::

Kết quả trên mình đã chạy nhiều lần mới được, để chúng ta thấy rằng không phải cứ `sleep(2000)` là nó chờ đúng `2000ms` đâu nhé.

<div class="example">Tạm ngưng main thread trong khoảng thời gian 2000ms</div>

```java
class ThreadSleep {
    public static void main(String[] args) throws InterruptedException {
        System.out.println("Main thread start");
        long startMain = System.currentTimeMillis();
        Thread.sleep(1000);
        Thread t = new Thread(() -> {
            System.out.println("Child thread start");
            try {
                long start = System.currentTimeMillis();
                Thread.sleep(1000);
                System.out.println("Child thread:" + (System.currentTimeMillis() - start));
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        });
        t.start();
        System.out.println("Main thread:" + (System.currentTimeMillis() - startMain));
    }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Tạm ngưng main thread và một thread con của main thread trong khoảng thời gian 1s</span>
  </div>
  <div class="window-body">
    <code>Main thread start</code></br>
    <code>Main thread:1030</code></br>
    <code>Child thread start</code></br>
    <code>Child thread:1000</code></br>

::

## Thread join() là gì?

Phương thức `join()` được sử dụng để đảm bảo cho quá trình thực thi của `Thread` đang chạy không bị gián đoạn bởi các `Thread` khác. Nói một cách khác, nếu một `Thread` đang trong quá trình được thực thi thì các `Thread` khác sẽ phải chờ đợi cho đến khi `Thread` đó thực thi xong. `join()` được sử dụng khi trong một chương trình Java có nhiều hơn một `Thread` và chúng ta cần đảm bảo các `Thread` thực thi và kết thúc đúng theo thứ tự mà chúng đã được khởi tạo.

![Thread join trong java](https://user-images.githubusercontent.com/29374426/146351994-bd416ab0-cb79-4917-bc15-0d0c8ab36385.png)

Trong một chương trình Java thường có nhiều hơn một thread, trong đó có `main thread` - có chức năng khởi tạo và kích hoạt để chạy các `thread` khác, tuy nhiên các `main threa`d không đảm bảo các `thread` thực thi và kết thúc theo đúng thứ tự mà chúng đã được khởi chạy.

<div class="example">Khi không sử dụng hàm Join</div>

Ở đây có 3 thread `th1, th2, th3`. Mặc dù các `thread` được khởi chạy theo thứ tự `th1>th2>th3` nhưng kết thúc thực thi của 3 thread trên không theo thứ tự `th1>th2>th3`. Ở mỗi thời điển chạy chương trình có thể nhận được các kết quả khác nhau.

```java
public class JoinExample {
 public static void main(String[]args){
  Thread th1 = new Thread(new MyThread(),"th1");
  Thread th2 = new Thread(new MyThread(),"th2");
  Thread th3 = new Thread(new MyThread(),"th3");
  th1.start();
  th2.start();
  th3.start();
 }
}
class MyThread implements Runnable {
 public void run() {
  Thread t = Thread.currentThread();
  System.out.println("Bắt đầu thread: " + t.getName());
  try{
   Thread.sleep(4000);
  }catch(InterruptedException e){
   e.printStackTrace();
  }
  System.out.println("Kết thúc thread:" + t.getName());
 }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Tạm ngưng main thread và một thread con của main thread trong khoảng thời gian 1s</span>
  </div>
  <div class="window-body">
    <code>Bắt đầu thread: th1</code></br>
    <code>Bắt đầu thread: th3</code></br>
    <code>Bắt đầu thread: th2</code></br>
    <code>Kết thúc thread:th3</code></br>
    <code>Kết thúc thread:th1</code></br>
    <code>Kết thúc thread:th2</code></br>

::

<div class="example">Khi sử dụng hàm Join</div>

Câu hỏi đưa ra là làm thế nào để các thread thực thi và kết thúc theo đúng thứ tự mà chúng được khởi chạy. Câu trả lời là sử dụng hàm Join sẵn có của Java. Giả sử thứ tự của các `thread` là `thread1` chạy trước, sau đó là `thread2`, `thread3` chạy sau cùng. Chương trình cài đặt sử dụng hàm Join như sau:

```java
public class JoinExample {
 public static void main(String[]args){
  Thread th1 = new Thread(new MyThread(),"th1");
  Thread th2 = new Thread(new MyThread(),"th2");
  Thread th3 = new Thread(new MyThread(),"th3");
  //khởi chạy thread 1.
  th1.start();
  try {
   th1.join();
  } catch (InterruptedException e) {
   e.printStackTrace();
  }
  //khởi chạy thread 2.
  th2.start();
  try {
   th2.join();
  } catch (InterruptedException e) {
   e.printStackTrace();
  }
  //khởi chạy thread 3.
  th3.start();
  try {
   th3.join();
  } catch (InterruptedException e) {
   e.printStackTrace();
  }
 }
}
class MyThread implements Runnable {
 public void run() {
  Thread t = Thread.currentThread();
  System.out.println("Bắt đầu thread: " + t.getName());
  try{
   Thread.sleep(4000);
  }catch(InterruptedException e){
   e.printStackTrace();
  }
  System.out.println("Kết thúc thread:" + t.getName());
 }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Tạm ngưng main thread và một thread con của main thread trong khoảng thời gian 1s</span>
  </div>
  <div class="window-body">
    <code>Bắt đầu thread: th1</code></br>
    <code>Kết thúc thread:th1</code></br>
    <code>Bắt đầu thread: th2</code></br>
    <code>Kết thúc thread:th2</code></br>
    <code>Bắt đầu thread: th3</code></br>
    <code>Kết thúc thread:th3</code></br>

::

Khi so sánh với chương trình cài đặt không sử dụng hàm `Join`, `thread2, thread3`, chưa khởi chạy ngay được gọi bằng lệnh `th2.start()`, `th3.start()` , `thead2` và `thread3` đã đợi cho đến khi `thread1` thực thi xong mới khởi chạy. Tương tự khi `thread2` chạy thì thread3 vẫn phải đợi cho đến khi `thread2` thực thi xong. Do đó mà kết quả in ra màn hình theo đúng thứ tự `th1>th2>th3` mà chúng đã được khởi chạy.

## Ví dụ phương thức join()

- `public void join()throws InterruptedException`
- `public void join(long milliseconds)throws InterruptedException`

<div class="example">về phương thức join()</div>

```java
class TestJoinMethod1 extends Thread {
    public void run() {
        for (int i = 1; i <= 5; i++) {
            try {
                Thread.sleep(500);
            } catch (Exception e) {
                System.out.println(e);
            }
            System.out.println(i);
        }
    }

    public static void main(String args[]) {
        TestJoinMethod1 t1 = new TestJoinMethod1();
        TestJoinMethod1 t2 = new TestJoinMethod1();
        TestJoinMethod1 t3 = new TestJoinMethod1();
        t1.start();
        try {
            t1.join();
        } catch (Exception e) {
            System.out.println(e);
        }

        t2.start();
        t3.start();
    }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Tạm ngưng main thread và một thread con của main thread trong khoảng thời gian 1s</span>
  </div>
  <div class="window-body">
    <code>1</code></br>
    <code>2</code></br>
    <code>3</code></br>
    <code>4</code></br>
    <code>5</code></br>
    <code>1</code></br>
    <code>1</code></br>
    <code>2</code></br>
    <code>2</code></br>
    <code>3</code></br>
    <code>3</code></br>
    <code>4</code></br>
    <code>4</code></br>
    <code>5</code></br>
    <code>5</code>

::

Như bạn thấy trong ví dụ trên, khi `t1` hoàn thành nhiệm vụ của nó thì `t2` và `t3` bắt đầu thực thi.

<div class="example">về phương thức join(long miliseconds)</div>

```java
class TestJoinMethod2 extends Thread {
    public void run() {
        for (int i = 1; i <= 5; i++) {
            try {
                Thread.sleep(500);
            } catch (Exception e) {
                System.out.println(e);
            }
            System.out.println(i);
        }
    }

    public static void main(String args[]) {
        TestJoinMethod2 t1 = new TestJoinMethod2();
        TestJoinMethod2 t2 = new TestJoinMethod2();
        TestJoinMethod2 t3 = new TestJoinMethod2();
        t1.start();
        try {
            t1.join(1500);
        } catch (Exception e) {
            System.out.println(e);
        }

        t2.start();
        t3.start();
    }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Tạm ngưng main thread và một thread con của main thread trong khoảng thời gian 1s</span>
  </div>
  <div class="window-body">
    <code>1</code></br>
    <code>2</code></br>
    <code>3</code></br>
    <code>4</code></br>
    <code>1</code></br>
    <code>1</code></br>
    <code>5</code></br>
    <code>2</code></br>
    <code>2</code></br>
    <code>3</code></br>
    <code>3</code></br>
    <code>4</code></br>
    <code>4</code></br>
    <code>5</code></br>
    <code>5</code>

::

Trong ví dụ trên, khi `t1` hoàn thành nhiệm vụ của nó cho 1500 mili giây (3 lần) thì t2 và t3 bắt đầu thực thi.
