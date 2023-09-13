---
title: "Tạo Thread trong Java"
description: "Trong Java, có hai cách để bạn tạo một thread là thừa kế từ lớp Thread và implement từ Interface Runnable nhưng mỗi cách lại có những mục đích và lợi ích khác nhau"
chapter:
  name: "Lập trình đa luồng"
  slug: "chuong-06-lap-trinh-da-luong"
category:
  name: "Java"
  slug: "java"
image: https://user-images.githubusercontent.com/29374426/146299112-60eb7f5d-8316-4ff9-92a1-f495c3eb8223.png
position: 3
---

Trong Java, có hai cách để bạn tạo một `thread` nhưng mỗi cách lại có những mục đích và lợi ích khác nhau. Nhiệm vụ của bạn là phải biết rõ cả hai cách này. Tại sao phải biết cả hai cách? Ngoài việc bạn phải biết hết để có thể khai báo và sử dụng, bạn còn phải biết để còn đọc hiểu source code của người khác khi họ không dùng giống bạn nữa.

![image](https://user-images.githubusercontent.com/29374426/146299112-60eb7f5d-8316-4ff9-92a1-f495c3eb8223.png)

Trước tiên chúng ta sẽ cần phải tạo `thread` bằng cách:

```java
Thread thread = new Thread();
```

Để khởi chạy Java thread, chúng ta gọi phương thức `start()`:

```java
thread.start();
```

Ví dụ này không có bất kỳ các tác vụ nào cho các `thread` thực thi. Do vậy, `thread` sẽ dừng lại ngay lập tức sau khi nó được bắt đầu. Để lập trình các tác vụ cho thread chúng ta sẽ đến phần tiếp theo.

## Tạo Thread bằng cách thừa kế từ lớp Thread

Cách thứ nhất là kế thừa `class Thread`:

- Bạn tạo mới một lớp và kế thừa lớp này từ lớp cha `Thread`.
- Trong lớp mới tạo đó, bạn override phương thức `run()`.
- Cuối cùng, ở nơi khác, khi muốn tạo ra một Thread từ lớp này, bạn khai báo đối tượng cho nó, rồi gọi đến phương thức `start()` của nó để bắt đầu khởi chạy Thread.

Thật đơn giản đúng không nào. Để khai báo một lớp là `Thread`, thì đơn giản chỉ kế thừa nó từ lớp cha `Thread`, chính phương thức `run()` bên trong lớp đó sẽ trở thành một Luồng xử lý bởi hệ thống khi đâu đó bên ngoài gọi đến phương thức `start()` của lớp này.

<div class="example">Tạo một Thread đếm ngược 10 giây. Khi start, Thread sẽ bắt đầu in ra console giá trị 10, mỗi một giây trôi qua Thread sẽ giảm con số này đi một đơn vị và lại in ra console, đến khi giảm đến giá trị 0 Thread sẽ in “Hết giờ”.</div>

```java
public class CountDownThread extends Thread {

    @Override
    public void run() {
        // Bước sau chúng ta sẽ code thêm
    }
}
```

Một khung sườn cho `Thread` chỉ như vậy thôi. Theo đề bài, `CountDownThread` khi được `start` sẽ bắt đầu đếm ngược từ 10 giây, đến 0 giây sẽ hiển thị chuỗi _"Hết giờ"_. Việc hiển thị số giây ra `console` thì bạn biết rồi, mình chỉ bật mí là để làm cho con số này chỉ được cập nhật và hiển thị ở mỗi giây thì chúng ta sử dụng phương thức `Thread.sleep(1000)`. Phương thức này sẽ giúp làm cho các `Thread` đang chạy trở nên _"ngủ"_ trong một khoảng thời gian được tính bằng mili giây, trong trường hợp này chúng ta truyền vào `1000` mili giây, tức là 1 giây. Sau khi ngủ hết thời lượng cho phép, `Thread` sẽ _"thức dậy"_ và thực hiện tiếp tác vụ của nó. Chú ý là bạn phải try catch phương thức `Thread.sleep()` này với một `Checked Exception` có tên `InteruptedException`. Và mình sẽ nói rõ về phương thức `Thread.Sleep()` ở bài sau nhé. Còn đây là code hoàn chỉnh của `CountDownThread`.

```java
public class CountDownThread extends Thread {

    @Override
    public void run() {
        int count = 10;
        for (int i = count; i > 0; i--) {
            System.out.println(i);
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                // TODO Auto-generated catch block
                e.printStackTrace();
            }
        }
        System.out.println("Hết giờ");
    }
}
```

Để khởi chạy Thread vừa tạo thì chúng ta sẽ gọi phương thức `start()` của nó như sau.

```java
public static void main(String[] args) {
    CountDownThread countDownThread = new CountDownThread();
    countDownThread.start();
}
```

::result

10</code></br>
9</code></br>
8</code></br>
7</code></br>
6</code></br>
5</code></br>
4</code></br>
3</code></br>
2</code></br>
1</code></br>
Hết giờ</code></br>

::

## Tạo Thread bằng cách implement từ Interface Runnable

Nếu như cách trên kia thì bạn phải kế thừa từ lớp `Thread`, thì cách thứ 2 này bạn lại `implement` một `interface` có tên `Runnable`. Với cách này bạn làm như sau.

Bạn tạo mới một lớp và `implement` lớp này với `interface` có tên `Runnable`. Trong lớp mới tạo đó, bạn `override` phương thức `run()`. Cuối cùng, ở nơi khác, khi muốn tạo ra một `Thread` từ lớp này, trước hết bạn khai báo đối tượng cho nó, rồi bạn khai báo thêm một đối tượng của `Thread` nữa và truyền đối tượng của lớp này vào hàm khởi tạo của `Thread`. Khi phương thức `start()` của lớp Thread vừa tạo được gọi đến, thì phương thức `run()` bên trong lớp dẫn xuất của `Runnable` sẽ được gọi để tạo thành một Luồng trong hệ thống.

<div class="example">Chúng ta xây dựng lại ví dụ bên trên nhưng bằng cách thức 2</div>

```java
public class CountDownThread implements Runnable {

    @Override
    public void run() {
        int count = 10;
        for (int i = count; i > 0; i--) {
            System.out.println(i);
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                // TODO Auto-generated catch block
                e.printStackTrace();
            }
        }
        System.out.println("Hết giờ");
    }
}
```

Vấn đề khai báo một `Thread` không khác nhau lắm giữa hai cách đúng không nào. Khác biệt nhiều hơn sẽ nằm ở cách khởi chạy `Thread`. Code ở phương thức `main()` sẽ phải thay đổi như sau.

```java
public static void main(String[] args) {
    CountDownThread countDownThread = new CountDownThread();
    Thread thread = new Thread(countDownThread);
    thread.start();
}
```

::result

10</code></br>
9</code></br>
8</code></br>
7</code></br>
6</code></br>
5</code></br>
4</code></br>
3</code></br>
2</code></br>
1</code></br>
Hết giờ</code></br>

::

## Lấy ra Thread hiện tại

Method `Thread.currentThread()` trả về tham chiều tới `Thread instance` đang được thực thi. Bằng cách này bạn có thể lấy được quyền truy cập vào các Java `Thread object` đại diện cho các `Thread` thực hiện một khối mã lệnh.

```java
Thread thread = Thread.currentThread();
```

Một khi bạn có một tham chiếu đến `Thread object`, bạn có thể gọi các `method` trên nó. Ví dụ, bạn có thể lấy tên của các `thread` hiện đang thực hiện:

```java
String threadName = Thread.currentThread().getName();
```
