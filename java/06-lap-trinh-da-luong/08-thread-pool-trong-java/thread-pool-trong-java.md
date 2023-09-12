---
title: "Thread Pool trong Java"
description: " ThreadPool ra đời để giới hạn số lượng Thread được chạy bên trong ứng dụng chúng ta cùng một thời điểm."
chapter:
  name: "Lập trình đa luồng"
  slug: "chuong-06-lap-trinh-da-luong"
category:
  name: "Java"
  slug: "java"
image: https://user-images.githubusercontent.com/29374426/146481640-6aee573d-28e4-4f40-b060-36d3e3192291.png
position: 8
---

`Thread` được sinh ra để thực hiện một nhiệm vụ cụ thể, nhiều `Thread` cùng xử lý công việc giúp chúng ta giải quyết được bài toán thời gian và hiệu năng khi xử lý một tác vụ nào đó...

![Thread Pool trong Java](https://user-images.githubusercontent.com/29374426/146481640-6aee573d-28e4-4f40-b060-36d3e3192291.png)

Câu trả lời là không phải cứ tạo nhiều `Thread` cùng hoạt động thì sẽ đem lại hiệu năng cao vì mỗi khi có một `Thread` mới được tạo ra và được cấp phát bộ nhớ bằng từ hóa new thì sẽ có vấn đề bộ nhớ và hiệu suất nên có thể dẫn tới `crash` chương trình.

Để giải quyết bài toán đó `ThreadPool` ra đời để giới hạn số lượng `Thread` được chạy bên trong ứng dụng chúng ta cùng một thời điểm.

## ThreadPool là gì?

Xét về hiệu suất, tạo ra một `Thread` mới là một hoạt động tốn kém bởi vì nó đòi hỏi hệ điều hành cung cấp tài nguyên để có thể thực thi task (tác vụ). Trên thực tế, `ThreadPool` được sử dụng cho các ứng dụng quy mô lớn khởi chạy rất nhiều luồng ngắn ngủi để sử dụng hiệu quả các tài nguyên và tăng hiệu suất.

Trong Java, `ThreadPool` được dùng để giới hạn số lượng `Thread` được chạy bên trong ứng dụng của chúng ta trong cùng một thời điểm. Nếu chúng ta không có sự giới hạn này, mỗi khi có một `Thread` mới được tạo ra và được cấp phát bộ nhớ bằng từ khóa new thì sẽ có vấn đề về bộ nhớ và hiệu suất, có thể dẫn đến lỗi crash chương trình.

Ví dụ khi chúng ta viết chương trình tải các tập tin từ `Internet`, mỗi tập tin cần 1 `Thread` để thực hiện quá trình tải, giả sử cần tải 100 tệp hình ảnh thì chúng ta phải cần tới `100 Thread` hoạt động cùng một thời điểm trong cùng một chương trình. Điều này sẽ dễ dẫn đến lỗi quá tải của chương trình, làm ảnh hưởng đến hiệu suất và có thể dẫn đến gây lỗi (crash) chương trình.

Vì vậy, thay vì tạo các luồng mới khi các task (nhiệm vụ) mới đến, một ThreadPool sẽ giữ một số luồng nhàn rỗi (no task) đã sẵn sàng để thực hiện tác vụ nếu cần. Sau khi một thread hoàn thành việc thực thi một tác vụ, nó sẽ không chết. Thay vào đó nó vẫn không hoạt động trong `ThreadPool` và chờ đợi được lựa chọn để thực hiện nhiệm vụ mới.

Chúng ta có thể giới hạn một số lượng nhất định các Thread đồng thời trong `ThreadPool`, rất hữu ích để ngăn chặn quá tải. Nếu tất cả các Thread đang bận rộn thực hiện nhiệm vụ, nhiệm vụ mới được đặt trong một hàng đợi (`BlockingQueue`), chờ đợi một `Thread` trở nên có sẵn.

`Java Concurrency API` hỗ trợ một vài loại `ThreadPool` sau:

- **Cached thread pool**: giữ một số luồng còn sống (alive) và tạo ra các luồng mới nếu cần.
- **Fixed thread pool**: giới hạn số lượng tối đa của các Thread được tạo ra để thực thi các task (nhiệm vụ). Các task khác đang chờ trong hàng đợi (BlockingQueue).
- **Single-threaded pool**: chỉ giữ một Thread thực thi một nhiệm vụ một lúc.
- **Fork/Join pool**: một Thread đặc biệt sử dụng `Fork/ Join` Framework để tận dụng lợi thế của nhiều bộ vi xử lý để thực hiện công việc lớn nhanh hơn bằng cách chia nhỏ công việc thành các phần nhỏ hơn để xử lý đệ quy.

Trong thực tế, `ThreadPool` được sử dụng rộng rãi trong các máy chủ web, nơi một `ThreadPool` được sử dụng để phục vụ các yêu cầu của khách hàng. `Thread` pool cũng được sử dụng trong các ứng dụng cơ sở dữ liệu nơi mà một `ThreadPool` được sử dụng để duy trì các kết nối mở với cơ sở dữ liệu.

Việc cài đặt `ThreadPool` là một công việc phức tạp, nhưng chúng ta không cần phải lo lắng điều này bởi vì `Java Concurrency API` đã xây dựng sẵn (build-in) các lớp hỗ trợ `ThreadPool` trong gói `java.util.concurrent.` Chúng ta sẽ tiếp tục tìm hiểu ở các phần tiếp theo của bài viết này.

## Executor là gì?

Một `Executor` là một đối tượng chịu trách nhiệm quản lý các luồng và thực hiện các tác vụ `Runnable` được yêu cầu xử lý. Nó tách riêng các chi tiết của việc tạo `Thread`, lập kế hoạch (scheduling), … để chúng ta có thể tập trung phát triển logic của tác vụ mà không quan tâm đến các chi tiết quản lý `Thread`.

`Java Concurrency API` định nghĩa 3 interfaces cơ bản sau cho các `Executor`:

- **Executor**: là interface cha của tất cả Executor. Nó xác định chỉ một phương thực `excute(Runnable)`.
- **ExecutorService**: là một `Executor` cho phép theo dõi tiến trình của các tác vụ trả về giá trị (Callable) thông qua đối tượng Future, và quản lý việc kết thúc các luồng. Các phương thức chính của nó bao gồm `submit()` và `shutdown()`.
- **ScheduledExecutorService**: là một ExecutorService có thể lên lịch cho các tác vụ để thực thi sau một khoảng thời gian nhất định, hoặc để thực hiện định kỳ. Các phương thức chính của nó là `schedule()`, `scheduleAtFixedRate()` and `scheduleWithFixedDelay()`.

Chúng có thể tạo một `Executor` bằng cách sử dụng một trong các phương thức được cung cấp bởi lớp tiện ích `Executors` như sau:

- `newSingleThreadExecutor()`: trong `ThreadPool` chỉ có 1 Thread và các task (nhiệm vụ) sẽ được xử lý một cách tuần tự.
- `newCachedThreadPool()`: trong `ThreadPool` sẽ có nhiều Thread và các nhiệm vụ sẽ được xử lý một cách song song. Các `Thread` cũ sau khi xử lý xong sẽ được sử dụng lại cho nhiệm vụ mới. Mặc định nếu một `Thread` không được sử dụng trong vòng 60 giây thì `Thread` đó sẽ bị tắt.
- `newFixedThreadPool(int n)`: trong `ThreadPool` sẽ được cố định các `Thread`. Nếu một nhiệm vụ mới được đưa vào mà các `Thread` đều đang “bận rộn” thì nhiệm vụ đó sẽ được gửi vào Blocking Queue và sau đó nếu có một `Thread` đã thực thi xong nhiệm vụ của nó thì nhiệm vụ đang ở trong `Queue` đó sẽ được push ra khỏi `Queue` và được Thread đó xử lý tiếp.
- `newScheduledThreadPool(int corePoolSize)`: tương tự như `newCachedThreadPool()` nhưng sẽ có thời gian delay giữa các `Thread`.
- `newSingleThreadScheduledExecutor()`: tương tự như `newSingleThreadExecutor()` nhưng sẽ có khoảng thời gian delay giữa các `Thread`.

## Các ví dụ minh họa tạo và sử dụng ThreadPool

Trước khi đi vào chi tiết cách sử dụng các phương thức của lớp `Executors`, hãy xem một task (tác vụ) sẽ được sử dụng để minh họa cho các ví dụ tiếp theo.

```java
public class WorkerThread implements Runnable {

    private String task;

    public WorkerThread(String s) {
        this.task = s;
    }

    @Override
    public void run() {
        System.out.println(Thread.currentThread().getName() + " Starting. Task = " + task);
        processCommand();
        System.out.println(Thread.currentThread().getName() + " Finished.");
    }

    private void processCommand() {
        try {
            Thread.sleep(2000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}
```

<div class="example">sử dụng newSingleThreadExecutor()</div>

```java
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class SingleThreadExecutorExample {
    public static void main(String[] args) {
        ExecutorService executor = Executors.newSingleThreadExecutor();

        for (int i = 1; i <= 10; i++) {
            Runnable worker = new WorkerThread("" + i);
            executor.execute(worker);
        }

        executor.shutdown();

        // Wait until all threads are finish
        while (!executor.isTerminated()) {
            // Running ...
        }

        System.out.println("Finished all threads");
    }
}
```

Trong chương trình trên, tôi đã tạo ra `ThreadPool` sử dụng phương thức `newSingleThreadExecutor()` vì vậy kích thước của `ThreadPool` là `1`, nên nó sẽ bắt đầu thực thi chương trình trên với 1 task và các task khác sẽ ở trạng thái đợi (waiting), ngay khi một task hoàn thành, một task khác từ hàng đợi sẽ được chọn và thực thi. Ta có kết quả của chương trình trên như sau:

::Result

    <code>pool-1-thread-1 Starting. Task = 1<code></br>
    <code>pool-1-thread-1 Finished.<code></br>
    <code>pool-1-thread-1 Starting. Task = 2<code></br>
    <code>pool-1-thread-1 Finished.<code></br>
    <code>pool-1-thread-1 Starting. Task = 3<code></br>
    <code>pool-1-thread-1 Finished.<code></br>
    <code>pool-1-thread-1 Starting. Task = 4<code></br>
    <code>pool-1-thread-1 Finished.<code></br>
    <code>pool-1-thread-1 Starting. Task = 5<code></br>
    <code>pool-1-thread-1 Finished.<code></br>
    <code>pool-1-thread-1 Starting. Task = 6<code></br>
    <code>pool-1-thread-1 Finished.<code></br>
    <code>pool-1-thread-1 Starting. Task = 7<code></br>
    <code>pool-1-thread-1 Finished.<code></br>
    <code>pool-1-thread-1 Starting. Task = 8<code></br>
    <code>pool-1-thread-1 Finished.<code></br>
    <code>pool-1-thread-1 Starting. Task = 9<code></br>
    <code>pool-1-thread-1 Finished.<code></br>
    <code>pool-1-thread-1 Starting. Task = 10<code></br>
    <code>pool-1-thread-1 Finished.<code></br>
    <code>Finished all threads<code></br>

::

<div class="example">sử dụng newFixedThreadPool()</div>

```java
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class FixedThreadPoolExample {

    public static final int NUM_OF_THREAD = 5;

    public static void main(String[] args) {

        ExecutorService executor = Executors.newFixedThreadPool(NUM_OF_THREAD);

        for (int i = 1; i <= 10; i++) {
            Runnable worker = new WorkerThread("" + i);
            executor.execute(worker);
        }
        executor.shutdown();

        // Wait until all threads are finish
        while (!executor.isTerminated()) {
            // Running ...
        }

        System.out.println("Finished all threads");
    }
}
```

Trong chương trình trên, tôi đã tạo ra `ThreadPool` có kích thước cố định là 5. Sau đó, tôi đã tạo 10 task (công việc) vào `ThreadPool`, vì kích thước `ThreadPool` là 5, nên nó sẽ bắt đầu thực thi chương trình trên vói 5 task và các task khác sẽ ở trạng thái đợi (waiting), ngay khi một task hoàn thành, một task khác từ hàng đợi sẽ được chọn và thực thi. Ta có kết quả của chương trình trên như sau:

::Result

    <code>pool-1-thread-3 Starting. Task = 3</code><br/>
    <code>pool-1-thread-2 Starting. Task = 2</code><br/>
    <code>pool-1-thread-1 Starting. Task = 1</code><br/>
    <code>pool-1-thread-4 Starting. Task = 4</code><br/>
    <code>pool-1-thread-5 Starting. Task = 5</code><br/>
    <code>pool-1-thread-2 Finished.</code><br/>
    <code>pool-1-thread-3 Finished.</code><br/>
    <code>pool-1-thread-2 Starting. Task = 6</code><br/>
    <code>pool-1-thread-3 Starting. Task = 7</code><br/>
    <code>pool-1-thread-1 Finished.</code><br/>
    <code>pool-1-thread-5 Finished.</code><br/>
    <code>pool-1-thread-4 Finished.</code><br/>
    <code>pool-1-thread-5 Starting. Task = 9</code><br/>
    <code>pool-1-thread-1 Starting. Task = 8</code><br/>
    <code>pool-1-thread-4 Starting. Task = 10</code><br/>
    <code>pool-1-thread-3 Finished.</code><br/>
    <code>pool-1-thread-2 Finished.</code><br/>
    <code>pool-1-thread-5 Finished.</code><br/>
    <code>pool-1-thread-1 Finished.</code><br/>
    <code>pool-1-thread-4 Finished.</code><br/>
    <code>Finished all threads</code><br/>

::

<div class="example">sử dụng newCachedThreadPool()</div>

```java
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class CachedThreadPoolExample {
    public static void main(String[] args) throws InterruptedException {
        ExecutorService executor = Executors.newCachedThreadPool();

        for (int i = 1; i <= 10; i++) {
            Runnable worker = new WorkerThread("" + i);
            executor.execute(worker);
            Thread.sleep(400);
        }

        executor.shutdown();

        // Wait until all threads are finish
        while (!executor.isTerminated()) {
            // Running ...
        }

        System.out.println("Finished all threads");
    }
}
```

Trong chương trình trên, tôi đã tạo ra `ThreadPool` sử dụng phương thức `newCachedThreadPool()` vì vậy kích thước của `ThreadPool` là gần như không giới hạn (`Integer.MAX_VALUE`), nên nó sẽ bắt đầu thực thi chương trình trên với 1 task và các task khác sẽ ở không phải đợi. Nếu có `Thread` rảnh thì nó sẽ nhận task và thực thi. Nếu không có `Thread` rãnh thì nó sẽ tạo một `Thread` mới và thực thi. Ta có kết quả của chương trình trên như sau:

::Result

    <code>pool-1-thread-1 Starting. Task = 1</code><br/>
    <code>pool-1-thread-2 Starting. Task = 2</code><br/>
    <code>pool-1-thread-3 Starting. Task = 3</code><br/>
    <code>pool-1-thread-4 Starting. Task = 4</code><br/>
    <code>pool-1-thread-5 Starting. Task = 5</code><br/>
    <code>pool-1-thread-1 Finished.</code><br/>
    <code>pool-1-thread-6 Starting. Task = 6</code><br/>
    <code>pool-1-thread-1 Starting. Task = 7</code><br/>
    <code>pool-1-thread-2 Finished.</code><br/>
    <code>pool-1-thread-3 Finished.</code><br/>
    <code>pool-1-thread-3 Starting. Task = 8</code><br/>
    <code>pool-1-thread-4 Finished.</code><br/>
    <code>pool-1-thread-4 Starting. Task = 9</code><br/>
    <code>pool-1-thread-5 Finished.</code><br/>
    <code>pool-1-thread-5 Starting. Task = 10</code><br/>
    <code>pool-1-thread-6 Finished.</code><br/>
    <code>pool-1-thread-1 Finished.</code><br/>
    <code>pool-1-thread-3 Finished.</code><br/>
    <code>pool-1-thread-4 Finished.</code><br/>
    <code>pool-1-thread-5 Finished.</code><br/>
    <code>Finished all threads</code><br/>

::

<div class="example">sử dụng newScheduledThreadPool()</div>

```java
import java.util.concurrent.Executors;
import java.util.concurrent.ScheduledExecutorService;
import java.util.concurrent.TimeUnit;

public class ScheduledThreadPoolExample {

    public static final int NUM_OF_THREAD = 2;
    public static final int INITIAL_DELAY = 1; // second
    public static final int DELAY = 3; // second

    public static void main(String[] args) throws InterruptedException {
        ScheduledExecutorService executor = Executors.newScheduledThreadPool(NUM_OF_THREAD);

        for (int i = 1; i <= 5; i++) {
            Runnable worker = new WorkerThread("" + i);
            executor.scheduleWithFixedDelay(worker, INITIAL_DELAY, DELAY, TimeUnit.SECONDS);
        }

        // waits for termination for 10 seconds only
        executor.awaitTermination(10, TimeUnit.SECONDS);

        executor.shutdown();

        // Wait until all threads are finish
        while (!executor.isTerminated()) {
            // Running ...
        }

        System.out.println("Finished all threads");
    }
}
```

Trong chương trình trên, tôi đã tạo ra `ThreadPool` có kích thước cố định là 2. Sau đó, tôi đã tạo 5 task (công việc) vào `ThreadPool`, vì kích thước `ThreadPool` là 2, nên nó sẽ bắt đầu thực thi chương trình trên vói 5 task và các task khác sẽ ở trạng thái đợi (`waiting`), ngay khi một task hoàn thành, một task khác từ hàng đợi sẽ được chọn và thực thi.

Các thread này được lên kế hoạch thực thi bằng phương thức `scheduleWithFixedDelay()`, sau khi thực thi lần đầu tiên, nó sẽ được gọi để thực thi lại sau khoảng thời gian `delay` xác định. Phương thức này gồm 4 tham số như sau:

- **Runnable**: tác vụ sẽ được thực thi.
- **initialDelay**: thời gian trì hoãn trước khi thực thi lần đầu tiên.
- **delay**: thời gian trì hoãn kể từ khi thực thi lần trước đó kết thúc.
- **TimeUnit**: đơn vị thời gian của tham số initialDelay và delay.

  Trong chương trình trên, tôi còn sử dụng một phương thức `awaitTermination()` - phương thức này xác định thời gian chờ tối đa để các task hoàn thành thực thi.

Ta có kết quả của chương trình trên như sau:

::Result

    <code>pool-1-thread-1 Starting. Task = 1</code><br/>
    <code>pool-1-thread-2 Starting. Task = 2</code><br/>
    <code>pool-1-thread-1 Finished.</code><br/>
    <code>pool-1-thread-2 Finished.</code><br/>
    <code>pool-1-thread-1 Starting. Task = 3</code><br/>
    <code>pool-1-thread-2 Starting. Task = 4</code><br/>
    <code>pool-1-thread-1 Finished.</code><br/>
    <code>pool-1-thread-2 Finished.</code><br/>
    <code>pool-1-thread-1 Starting. Task = 5</code><br/>
    <code>pool-1-thread-2 Starting. Task = 1</code><br/>
    <code>pool-1-thread-1 Finished.</code><br/>
    <code>pool-1-thread-1 Starting. Task = 2</code><br/>
    <code>pool-1-thread-2 Finished.</code><br/>
    <code>pool-1-thread-2 Starting. Task = 3</code><br/>
    <code>pool-1-thread-1 Finished.</code><br/>
    <code>pool-1-thread-1 Starting. Task = 4</code><br/>
    <code>pool-1-thread-2 Finished.</code><br/>
    <code>pool-1-thread-1 Finished.</code><br/>
    <code>Finished all threads</code><br/>

::

## Custom Thread Pool Executor

Trong trường hợp chúng ta muốn kiểm soát nhiều hơn các hành vi của một `ThreadPool`, chúng ta có thể tạo một bộ xử lý `ThreadPool` trực tiếp từ lớp `ThreadPoolExecutor` thay vì các phương thức có sẵn của lớp tiện ích `Executors`.

Một `ThreadPoolExecutor` có hàm khởi tạo như sau:

```java
public ThreadPoolExecutor(int corePoolSize,
int maximumPoolSize,
long keepAliveTime,
TimeUnit unit,
BlockingQueue<Runnable> workQueue,
ThreadFactory threadFactory,
RejectedExecutionHandler handler)
```

Các tham số của phương thức này là:

- `int corePoolSize`: số lượng các `Thread` để giữ trong `ThreadPool`.
- `int maximumPoolSize`: số lượng tối đa của `Thread` để cho phép trong `ThreadPool`.
- `long keepAliveTime`: nếu `ThreadPool` hiện có nhiều hơn các `Thread corePoolSize`, `Thread` vượt quá sẽ bị chấm dứt nếu nó đã được nhàn rỗi hơn một khoảng thời gian `keepAliveTime`.
- `TimeUnit unit`: đơn vị thời gian cho đối số `keepAliveTime`. Có thể là `NANOSECONDS`, `MILLISECONDS`, `SECONDS`, `MINUTES`, `HOURS` AND `DAYS`.
- `BlockingQueue workQueue`: hàng đợi được sử dụng để giữ các task trước khi chúng được thực hiện. Các lựa chọn mặc định là `SynchronousQueue` cho `multi-thread` và `LinkedBlockingQueue` cho các `single-thread`.
- `ThreadFactory threadFactory`: factory được sử dụng khi tạo một Thread mới.
- `RejectedExecutionHandler handler`: handler được sử dụng khi một execute bị chặn (blocked) khi vượt quá `maximumPoolSize`.

Cài đặt `RejectedExecutionHandler` để xử lý các tác vụ bị từ chối.

```java
import java.util.concurrent.RejectedExecutionHandler;
import java.util.concurrent.ThreadPoolExecutor;

public class RejectedExecutionHandlerImpl implements RejectedExecutionHandler {

    @Override
    public void rejectedExecution(Runnable r, ThreadPoolExecutor executor) {
        System.out.println(r.toString() + " is rejected");
    }
}
```

Tạo một lớp `ThreadFactoryBuilder` để tùy chỉnh `ThreadFactory` trong việc đặt tên `Thread`, xử lý ngoại lệ, xác định độ ưu tiên của `Thread`, xác định luồng daemon:

```java
import java.lang.Thread.UncaughtExceptionHandler;
import java.util.concurrent.Executors;
import java.util.concurrent.ThreadFactory;
import java.util.concurrent.atomic.AtomicLong;

public class ThreadFactoryBuilder {
    private String namePrefix = null;
    private boolean daemon = false;
    private int priority = Thread.NORM_PRIORITY;
    private ThreadFactory backingThreadFactory = null;
    private UncaughtExceptionHandler uncaughtExceptionHandler = null;

    public ThreadFactoryBuilder() {

    }
    public ThreadFactoryBuilder setNamePrefix(String namePrefix) {
        if (namePrefix == null) {
            throw new NullPointerException();
        }
        this.namePrefix = namePrefix;
        return this;
    }

    public ThreadFactoryBuilder setDaemon(boolean daemon) {
        this.daemon = daemon;
        return this;
    }

    public ThreadFactoryBuilder setPriority(int priority) {
        if (priority < Thread.MIN_PRIORITY) { throw new IllegalArgumentException( String.format("Thread priority (%s) must be >= %s", priority, Thread.MIN_PRIORITY));
        }

        if (priority > Thread.MAX_PRIORITY) {
            throw new IllegalArgumentException(
                    String.format("Thread priority (%s) must be <= %s", priority, Thread.MAX_PRIORITY));
        }

        this.priority = priority;
        return this;
    }

    public ThreadFactoryBuilder setUncaughtExceptionHandler(UncaughtExceptionHandler uncaughtExceptionHandler) {
        if (null == uncaughtExceptionHandler) {
            throw new NullPointerException("UncaughtExceptionHandler cannot be null");
        }
        this.uncaughtExceptionHandler = uncaughtExceptionHandler;
        return this;
    }

    public ThreadFactoryBuilder setThreadFactory(ThreadFactory backingThreadFactory) {
        if (null == uncaughtExceptionHandler) {
            throw new NullPointerException("BackingThreadFactory cannot be null");
        }
        this.backingThreadFactory = backingThreadFactory;
        return this;
    }

    public ThreadFactory build() {
        return build(this);
    }

    private static ThreadFactory build(ThreadFactoryBuilder builder) {
        final String namePrefix = builder.namePrefix;
        final Boolean daemon = builder.daemon;
        final Integer priority = builder.priority;
        final UncaughtExceptionHandler uncaughtExceptionHandler = builder.uncaughtExceptionHandler;
        final ThreadFactory backingThreadFactory = (builder.backingThreadFactory != null) ? builder.backingThreadFactory
                : Executors.defaultThreadFactory();

        final AtomicLong count = new AtomicLong(0);

        return new ThreadFactory() {
            @Override
            public Thread newThread(Runnable runnable) {
                Thread thread = backingThreadFactory.newThread(runnable);
                if (namePrefix != null) {
                    thread.setName(namePrefix + "-" + count.getAndIncrement());
                }
                if (daemon != null) {
                    thread.setDaemon(daemon);
                }
                if (priority != null) {
                    thread.setPriority(priority);
                }
                if (uncaughtExceptionHandler != null) {
                    thread.setUncaughtExceptionHandler(uncaughtExceptionHandler);
                }
                return thread;
            }
        };
    }
}
```

Tạo lớp `MonitorThread` để giám sát trạng thái của `executor` hiện tại, kích thước của `ThreadPool`, số lượng `Thread` đang hoạt động, …

```java
public class WorkerThread implements Runnable {

    private String task;

    public WorkerThread(String s) {
        this.task = s;
    }

    @Override
    public void run() {
        System.out.println(Thread.currentThread().getName() + " Starting. Task = " + task);
        processCommand();
        System.out.println(Thread.currentThread().getName() + " Finished.");
    }

    private void processCommand() {
        try {
            Thread.sleep(5000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }

    @Override
    public String toString() {
        return "Task = " + task;
    }
}
```

Tạo chương trình minh họa thực thi tác vụ nhiều tác vụ `WorkerThread`, được giám sát bởi `MonitorThread` với các tùy chỉnh `RejectedExecutionHandler`, `ThreadFactory`.

```java
import java.lang.Thread.UncaughtExceptionHandler;
import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.BlockingQueue;
import java.util.concurrent.ThreadFactory;
import java.util.concurrent.ThreadPoolExecutor;
import java.util.concurrent.TimeUnit;

public class ThreadPoolExecutorExample {

    public static void main(String args[]) throws InterruptedException {

        // the number of threads to keep in the pool, even if they are idle
        final int CORE_POOL_SIZE = 2; //

        // the maximum number of threads to allow in the pool
        final int MAX_POOL_SIZE = 4;

        // the queue to use for holding tasks before they are executed
        final long KEEP_ALIVE_TIME = 10;

        // the queue to use for holding tasks before they are executed. This queue will
        // hold only the Runnable tasks submitted by the execute method.
        BlockingQueue<Runnable> workQueue = new ArrayBlockingQueue<Runnable>(2);

        // RejectedExecutionHandler implementation
        RejectedExecutionHandlerImpl rejectionHandler = new RejectedExecutionHandlerImpl();

        // The handler to use when execution is blocked because the thread bounds
        // and queue capacities are reached
        // ThreadFactory threadFactory = Executors.defaultThreadFactory();
        ThreadFactory threadFactory = new ThreadFactoryBuilder()
                .setNamePrefix("GPCoder-ThreadPool")
                .setDaemon(false)
                .setPriority(Thread.MAX_PRIORITY)
                .setUncaughtExceptionHandler(new UncaughtExceptionHandler() {
                    @Override
                    public void uncaughtException(Thread t, Throwable e) {
                        System.err.println(String.format("Custom Exception: Thread %s threw exception - %s",
                                t.getName(), e.getMessage()));

                    }
                }).build();

        // creating the ThreadPoolExecutor
        ThreadPoolExecutor executorPool = new ThreadPoolExecutor(
                CORE_POOL_SIZE, MAX_POOL_SIZE, KEEP_ALIVE_TIME,
                TimeUnit.SECONDS, workQueue, threadFactory, rejectionHandler);

        // start the monitoring thread
        MonitorThread monitor = new MonitorThread(executorPool, 3);
        Thread monitorThread = new Thread(monitor);
        monitorThread.start();

        // submit work to the thread pool
        for (int i = 1; i <= 10; i++) {
            executorPool.execute(new WorkerThread("cmd" + i));
        }

        Thread.sleep(30000);

        // shut down the pool
        executorPool.shutdown();

        // shut down the monitor thread
        Thread.sleep(5000);
        monitor.shutdown();

    }
}
```

Trong chương trình trên, tôi đã tạo ra `ThreadPool` sử dụng `ThreadPoolExecutor` với:

- Số lượng Thread ban đầu là 2 (corePoolSize) và tối đa là 4 (maximumPoolSize) `Thread` trong `ThreadPool`.
- Một `workQueue` để lưu giữ các task sẽ được thực thi.
- Chương trình sẽ yêu cầu thực thi 10 task.
- Do `maximumPoolSize` là 4 nên chỉ có 4 `Thread` được thực thi cùng lúc, `workQueue` là 2 nên sẽ có 2 task được nằm trong hàng đợi (`BlockingQueue`), `4 Thread` còn lại sẽ bị từ chối thực thi.
- Sau khi `Thread` hoàn thành thực thi task một khoảng thời gian `keepAliveTime`, nếu số lượng `Thread` trong `ThreadPool` lớn hơn `corePoolSize` và workQueue không còn task yêu cầu thực thi thì Thread sẽ bị đóng lại (đóng các Thread cho đến khi số lượng `Thread = corePoolSize` trong `ThreadPool`).
- `ThreadFactory` sẽ tạo tên `Thread` với tiếp đầu ngữ là là `GPCoder-ThreadPool`.
- `MonitorThread` định kỳ khoảng 3 giây sẽ hiển thị thông tin của `executor` hiện tại.

Hãy xem kết quả thực thi chương trình trên như sau:

::Result

    <code>GPCoder-ThreadPool-0 Starting. Task = cmd1</code><br/>
    <code>GPCoder-ThreadPool-1 Starting. Task = cmd2</code><br/>
    <code>GPCoder-ThreadPool-2 Starting. Task = cmd5</code><br/>
    <code>GPCoder-ThreadPool-3 Starting. Task = cmd6</code><br/>
    <code>Task = cmd7 is rejected</code><br/>
    <code>Task = cmd8 is rejected</code><br/>
    <code>Task = cmd9 is rejected</code><br/>
    <code>Task = cmd10 is rejected</code><br/>
    <code>[monitor] [0/2] Active: 0, Completed: 0, Task: 2, isShutdown: false, isTerminated: false</code><br/>
    <code>[monitor] [4/2] Active: 4, Completed: 0, Task: 6, isShutdown: false, isTerminated: false</code><br/>
    <code>GPCoder-ThreadPool-0 Finished.</code><br/>
    <code>GPCoder-ThreadPool-1 Finished.</code><br/>
    <code>GPCoder-ThreadPool-0 Starting. Task = cmd3</code><br/>
    <code>GPCoder-ThreadPool-1 Starting. Task = cmd4</code><br/>
    <code>GPCoder-ThreadPool-2 Finished.</code><br/>
    <code>GPCoder-ThreadPool-3 Finished.</code><br/>
    <code>[monitor] [4/2] Active: 2, Completed: 4, Task: 6, isShutdown: false, isTerminated: false</code><br/>
    <code>[monitor] [4/2] Active: 2, Completed: 4, Task: 6, isShutdown: false, isTerminated: false</code><br/>
    <code>GPCoder-ThreadPool-0 Finished.</code><br/>
    <code>GPCoder-ThreadPool-1 Finished.</code><br/>
    <code>[monitor] [4/2] Active: 0, Completed: 6, Task: 6, isShutdown: false, isTerminated: false</code><br/>
    <code>[monitor] [2/2] Active: 0, Completed: 6, Task: 6, isShutdown: false, isTerminated: false</code><br/>
    <code>[monitor] [2/2] Active: 0, Completed: 6, Task: 6, isShutdown: false, isTerminated: false</code><br/>
    <code>[monitor] [2/2] Active: 0, Completed: 6, Task: 6, isShutdown: false, isTerminated: false</code><br/>
    <code>[monitor] [2/2] Active: 0, Completed: 6, Task: 6, isShutdown: false, isTerminated: false</code><br/>
    <code>[monitor] [2/2] Active: 0, Completed: 6, Task: 6, isShutdown: false, isTerminated: false</code><br/>
    <code>[monitor] [0/2] Active: 0, Completed: 6, Task: 6, isShutdown: true, isTerminated: true</code><br/>
    <code>[monitor] [0/2] Active: 0, Completed: 6, Task: 6, isShutdown: true, isTerminated: true</code><br/>

::

## Một vài lưu ý về sử dụng ExecutorService

Khi bạn đã thêm tất cả các task cần thiết để thực thi vào `executor` bạn nên tắt nó bằng phương thức `shutdown()`. Khi bạn gọi phương thức này có nghĩa ExcutorService sẽ từ chối nhận thêm các task, và một khi tất cả các nhiệm vụ đã được thêm vào trước đó đã hòan thành thì `Executor` sẽ được tắt. Có nghĩa tất cả các task được thêm vào trước khi gọi `shutdown()` đều sẽ được thực thi, các task thêm sau sẽ bị từ chối (rejected).

Nếu bạn muốn tắt `ExecutorService` ngay lập tức, bạn có thể gọi phương thức `shutdownNow()`. Điều này sẽ cố gắng ngăn chặn tất cả các nhiệm vụ ngay lập tức và loại bỏ các nhiệm vụ đã được đưa vào `Queue` nhưng chưa được thực thi. Không có gì đảm bảo về việc tắt các nhiệm vụ đang chạy hoàn toàn, nhưng phương thức này sẽ cố gắng để tắt tất cả chúng.

Lưu ý: Sử dụng phương thức `shutdownNow()` cũng tương tự việc sử dụng `interupt()` trong Thread. Để an toàn và chắc chắn hơn khi stop các task đang được thực thi bạn nên thêm vào 1 biến flag chung cho các nhiệm vụ, khi bạn stop tất cả Thread sử dụng kèm cả `shutdownNow()` và set giá trị cho biến flag để quá trình dừng lại.
