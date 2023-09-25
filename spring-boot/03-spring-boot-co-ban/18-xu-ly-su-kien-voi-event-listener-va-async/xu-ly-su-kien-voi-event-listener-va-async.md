---
title: "Xử lý Sự kiện với @EventListener và @Async trong Spring Boot"
description: "Trong bài viết này, chúng ta sẽ tìm hiểu cách sử dụng @EventListener và @Async trong Spring Boot để tạo và xử lý sự kiện một cách hiệu quả và đồng thời giải quyết vấn đề đồng bộ hóa."
chapter:
  name: "Spring Boot cơ bản"
  slug: "chuong-03-spring-boot-co-ban"
category:
  name: "Spring Boot"
  slug: "spring-boot"
position: 18
---

Trong lập trình Java, mô hình thiết kế `Listener Pattern` thường được sử dụng để xử lý sự kiện và thông báo giữa các đối tượng khác nhau. Trong bài viết này, chúng ta sẽ tìm hiểu cách sử dụng `@EventListener` và `@Async` trong Spring Boot để tạo và xử lý sự kiện một cách hiệu quả và đồng thời giải quyết vấn đề đồng bộ hóa.

## Cơ bản về Sự kiện và Người lắng nghe

Sự kiện (Event) là một yếu tố quan trọng trong lập trình, cho phép bạn thông báo về sự thay đổi hoặc hành động trong ứng dụng. Sự kiện thường được gửi từ nguồn gốc (Source) và được người lắng nghe (Listener) xử lý. Trong Spring Boot, chúng ta sử dụng `@EventListener` để lắng nghe và xử lý sự kiện.

## Sự kiện (Event)

Để sử dụng Spring Boot hỗ trợ cho sự kiện, chúng ta cần định nghĩa một lớp sự kiện và kế thừa lớp `ApplicationEvent`.

```java
public class DoorBellEvent extends ApplicationEvent {
    public DoorBellEvent(Object source, String guestName) {
        super(source);
    }
}
```

Lớp sự kiện `DoorBellEvent` kế thừa từ `ApplicationEvent` và có một số thông tin đi kèm (trong trường hợp này là `guestName`). Một sự kiện phải kế thừa lớp `ApplicationEvent` để được công nhận là một sự kiện hợp lệ.

## Người phát sự kiện (Event Publisher)

Trong Spring Boot, chúng ta sử dụng đối tượng `ApplicationEventPublisher` để phát ra các sự kiện. Đây là một bean được cung cấp bởi Spring và có thể được tự động nạp vào ứng dụng của bạn.

```java
@Component
public class MyHouse {
    @Autowired
    ApplicationEventPublisher applicationEventPublisher;

    public void ringDoorbellBy(String guestName) {
        applicationEventPublisher.publishEvent(new DoorBellEvent(this, guestName));
    }
}
```

Lớp `MyHouse` có một phương thức `ringDoorbellBy` để phát ra sự kiện `DoorBellEvent` với thông tin `guestName`. `ApplicationEventPublisher` giúp chúng ta phát ra sự kiện một cách dễ dàng.

## Người lắng nghe sự kiện (Event Listener)

Để lắng nghe các sự kiện, chúng ta sử dụng `@EventListener` trên các phương thức trong các bean của ứng dụng. Dưới đây là ví dụ về cách lắng nghe sự kiện `DoorBellEvent`.

```java
@Component
public class MyDog {
    @Async
    @EventListener
    public void doorBellEventListener(DoorBellEvent doorBellEvent) throws InterruptedException {
        Thread.sleep(1000);
        System.out.println("Chó ngủ dậy!!!");
        System.out.println(String.format("Go go!! Có người tên là %s gõ cửa!!!", doorBellEvent.getGuestName()));
    }
}
```

Chúng ta đánh dấu phương thức `doorBellEventListener` bằng `@EventListener` để nói với Spring Boot rằng phương thức này là một lắng nghe sự kiện. Bởi vì chúng ta muốn xử lý sự kiện bất đồng bộ, chúng ta sử dụng cả `@Async`. Điều này cho phép sự kiện được xử lý trong một luồng riêng biệt mà không ảnh hưởng tới luồng chính của ứng dụng.

## Chạy thử ứng dụng

Chúng ta sẽ chạy thử ứng dụng để xem kết quả:

```java
@SpringBootApplication
public class App {
    @Autowired
    MyHouse myHouse;

    public static void main(String[] args) {
        SpringApplication.run(App.class, args);
    }

    @Bean
    CommandLineRunner run() {
        return args -> {
            System.out.println("Loda đi tới cửa nhà !!!");
            System.out.println("=> Loda bấm chuông và khai báo họ tên!");
            myHouse.ringDoorbellBy("Loda");
            System.out.println("Loda quay lưng bỏ đi");
        };
    }
}
```

Kết quả:

```
Loda đi tới cửa nhà !!!
=> Loda bấm chuông và khai báo họ tên!
Loda qu

ay lưng bỏ đi
Chó ngủ dậy!!!
Go go!! Có người tên là Loda gõ cửa!!!
```

Quá trình xử lý sự kiện xảy ra một cách đồng thời và bất đồng bộ như chúng ta đã mong đợi. Người bấm chuông và chó cùng hoạt động mà không ảnh hưởng tới nhau.

::alert{type="success"}
Sử dụng `@EventListener` và `@Async` trong Spring Boot cho phép bạn quản lý sự kiện trong ứng dụng của mình một cách hiệu quả và đồng thời giải quyết vấn đề đồng bộ hóa. Điều này rất hữu ích khi bạn muốn xử lý sự kiện trong các luồng riêng biệt mà không ảnh hưởng tới luồng chính của ứng dụng.
::
