---
title: "Tạo Custom @Conditional trong Spring Boot"
description: "Bài viết này sẽ hướng dẫn bạn cách tạo và sử dụng các điều kiện tùy chỉnh cho ứng dụng Spring Boot của mình khi các điều kiện mà Spring Boot cung cấp không đáp ứng đủ yêu cầu."
chapter:
  name: "Spring Boot cơ bản"
  slug: "chuong-03-spring-boot-co-ban"
position: 17
---

Để hiểu rõ về cách tạo Custom `@Conditional` trong Spring Boot, bạn cần đã đọc bài viết về [@Conditional](/bai-viet/spring-boot/tao-bean-co-dieu-kien-voi-conditional). Bài viết này sẽ hướng dẫn bạn cách tạo và sử dụng các điều kiện tùy chỉnh cho ứng dụng Spring Boot của mình khi các điều kiện mà Spring Boot cung cấp không đáp ứng đủ yêu cầu.

### Tạo Custom @Conditional

Để tạo một điều kiện tùy chỉnh, bạn cần kế thừa lớp `Condition` và triển khai lại phương thức `matches`. Phương thức `matches` là nơi bạn đặt các điều kiện kiểm tra xem có nên tạo bean không.

```java
/*
Định nghĩa một điều kiện tùy chỉnh, phải kế thừa lớp Condition của Spring Boot
*/
public class MyCustomCondition implements Condition {

    @Override
    public boolean matches(ConditionContext context, AnnotatedTypeMetadata metadata) {
        // Thực hiện kiểm tra điều kiện ở đây, ví dụ:
        // Nếu điều kiện thỏa mãn, trả về true; ngược lại, trả về false.
        return true; // Đây là ví dụ đơn giản, bạn cần thay thế bằng điều kiện thực tế của bạn.
    }
}
```

Sau khi bạn đã định nghĩa điều kiện tùy chỉnh, bạn có thể sử dụng nó trong cấu hình Spring Boot như sau:

```java
@Configuration
public class AppConfiguration {

    /*
    Bean này chỉ được tạo ra khi thỏa mãn điều kiện tùy chỉnh MyCustomCondition
    */
    @Conditional(MyCustomCondition.class)
    @Bean
    SomeBean someBean() {
        return new SomeBean();
    }
}
```

### Tạo Custom Annotation @Conditional

Nếu bạn muốn sử dụng một `Annotation` thay vì sử dụng `@Conditional(MyCustomCondition.class)`, bạn có thể tự tạo một `Annotation` tùy chỉnh. Dưới đây là cách bạn có thể làm:

```java
import org.springframework.context.annotation.Conditional;
import java.lang.annotation.*;

@Target({ ElementType.TYPE, ElementType.METHOD })
@Retention(RetentionPolicy.RUNTIME)
@Documented
@Conditional(MyCustomCondition.class) // Đánh dấu Annotation này với điều kiện tùy chỉnh MyCustomCondition
public @interface MyCustomConditional {
    // Bạn có thể định nghĩa thêm các thuộc tính nếu cần thiết
}
```

Sau khi đã tạo `Annotation` tùy chỉnh, bạn có thể sử dụng nó trong cấu hình Spring Boot như sau:

```java
@Configuration
public class AppConfiguration {

    /*
    Bean này chỉ được tạo ra khi thỏa mãn điều kiện tùy chỉnh MyCustomCondition
    */
    @MyCustomConditional
    @Bean
    SomeBean someBean() {
        return new SomeBean();
    }
}
```

### Chạy thử

Để kiểm tra cách hoạt động của điều kiện tùy chỉnh, bạn có thể chạy ứng dụng và xem kết quả. Dưới đây là một ví dụ đơn giản:

```java
@SpringBootApplication
public class App {
    public static void main(String[] args) {
        ApplicationContext context = SpringApplication.run(App.class, args);
        try {
            SomeBean someBean = context.getBean(SomeBean.class);
            System.out.println("SomeBean đã được tạo!");
        } catch (Exception e) {
            System.out.println("SomeBean chỉ được tạo khi thỏa mãn điều kiện tùy chỉnh.");
        }
    }
}
```

Hãy thử bỏ `@MyCustomConditional` và chạy ứng dụng để xem sự khác biệt.

### Kết hợp Nhiều Điều Kiện với OR

Bạn có thể kết hợp nhiều điều kiện với nhau bằng phép OR. Spring Boot hỗ trợ điều này bằng cách kế thừa lớp `AnyNestedCondition`. Dưới đây là cách bạn có thể làm:

```java
/**
 * Lớp này kế thừa AnyNestedCondition và chấp nhận mọi điều kiện @Conditional bên trong nó.
 */
public class MyCustomOrCondition extends AnyNestedCondition {

    public MyCustomOrCondition() {
        super(ConfigurationPhase.REGISTER_BEAN);
    }

    /*
    Bạn cần định nghĩa các điều kiện bên trong lớp kế thừa AnyNestedCondition
    */
    @Conditional(MyCustomCondition1.class)
    public class Condition1 {}

    @Conditional(MyCustomCondition2.class)
    public class Condition2 {}
}
```

Sử dụng điều kiện này trong cấu hình Spring Boot:

```java
@Configuration
public class AppConfiguration {

    /*
    Bean này chỉ được tạo ra khi thỏa mãn điều kiện MyCustomOrCondition (OR)
    */
    @MyCustomOrCondition
    @Bean
    SomeBean someBean() {
        return new SomeBean();
    }
}
```

### Kết hợp Nhiều Điều Kiện với AND

Bạn cũng có thể kết hợp nhiều điều kiện với nhau bằng phép AND bằng cách kế thừa lớp `AllNestedConditions`. Cách kế thừa tương tự với `AnyNestedCondition`.

Ngoài ra, bạn cũng có thể sử dụng nhiều custom `@Conditional` cùng một lúc. Ví dụ:

```java
@Bean
@MyCustomConditional
@Conditional(MyCustomCondition2.class)
SomeBean someBean() {
    return new SomeBean();
}
```

::alert{type="success"}
Với kiến thức về cách tạo Custom `@Conditional` trong Spring Boot, bạn có thể kiểm soát quá trình tạo bean dựa trên các điều kiện tùy chỉnh của mình. Điều này rất hữu ích khi bạn cần tạo các ứng dụng linh hoạt có thể hoạt động trong các môi trường khác nhau như môi trường phát triển (dev) và môi trường sản phẩm (production).
::
