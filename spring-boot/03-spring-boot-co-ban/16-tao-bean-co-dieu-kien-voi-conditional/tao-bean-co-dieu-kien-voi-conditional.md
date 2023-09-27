---
title: "Tạo Bean có điều kiện với @Conditional"
description: "Trong quá trình xây dựng ứng dụng với Spring Boot, đôi khi bạn muốn tạo một bean chỉ khi nó đáp ứng một số điều kiện cụ thể. Ví dụ, bạn có thể muốn tạo một bean chỉ trong môi trường kiểm thử (test environment) và không cần thiết trong môi trường sản phẩm"
chapter:
  name: "Spring Boot cơ bản"
  slug: "chuong-03-spring-boot-co-ban"
position: 16
---

Trong quá trình xây dựng ứng dụng với **Spring Boot**, đôi khi bạn muốn tạo một bean chỉ khi nó đáp ứng một số điều kiện cụ thể. Ví dụ, bạn có thể muốn tạo một bean chỉ trong môi trường kiểm thử (test environment) và không cần thiết trong môi trường sản phẩm (production environment). **Spring Boot** hỗ trợ việc này thông qua annotation `@Conditional`.

### Cách tạo bean có điều kiện

Trong **Spring Boot**, có nhiều cách để tạo bean, bao gồm `@Component`, `@Configuration`, `@Bean`, `@Service`, v.v. Bạn có thể thêm một hoặc nhiều điều kiện để chỉ tạo bean khi các điều kiện đó được đáp ứng.

Tất cả các điều kiện sử dụng tiền tố `@Conditional...`. Hậu tố của các điều kiện này sẽ được đề cập sau. Cách hoạt động của tất cả các điều kiện `@Conditional` giống nhau.

```java
@Configuration
public class ConditionalExample {
    /*
    Bean này chỉ được tạo khi các điều kiện thỏa mãn
    */
    @Bean
    @Conditional...
    ABeanWithCondition aBeanWithCondition() {
        return new ABeanWithCondition();
    }
}
```

Nếu bạn gắn điều kiện trên một `@Configuration`, tất cả các bean bên trong nó sẽ chịu tác động của điều kiện đó.

```java
@Conditional...
@Configuration
public class ConditionalExample {
    /*
    Bean này chỉ được tạo khi điều kiện thỏa mãn
    */
    @Bean
    SomeOtherBean someOtherBean() {
        return new SomeOtherBean();
    }
}
```

Tương tự, bạn có thể sử dụng các điều kiện với các annotation khác như `@Component`, `@Service`, `@Repository`, v.v.

```java
@Conditional...
@Component
public class ConditionalExample {
}
```

Tiếp theo, chúng ta sẽ đi qua các loại điều kiện trong **Spring Boot**.

### @ConditionalOnBean

`@ConditionalOnBean` được sử dụng khi bạn muốn tạo một bean chỉ khi một bean khác đã tồn tại trong context.

```java
@Configuration
public class ConditionalOnBeanExample {
    /*
    ABeanWithCondition chỉ được tạo ra khi RandomBean đã tồn tại trong context.
    */
    @Bean
    @ConditionalOnBean(RandomBean.class)
    ABeanWithCondition aBeanWithACondition() {
        return new ABeanWithCondition();
    }
}
```

### @ConditionalOnProperty annotation

`@ConditionalOnProperty` được sử dụng khi bạn muốn quyết định việc tạo bean dựa trên giá trị của một thuộc tính cấu hình (property).

```java
@Configuration
public class ConditionalOnPropertyExample {
    /*
    Bean này chỉ được tạo ra khi giá trị của property "kungfutech.bean2.enabled" là "true".
    */
    @Bean
    @ConditionalOnProperty(
            value="kungfutech.bean2.enabled",
            havingValue = "true", // Bean chỉ được tạo nếu giá trị property là "true"
            matchIfMissing = false) // Bean không được tạo nếu property không tồn tại
    ABeanWithCondition2 aBeanWithCondition2(){
        return new ABeanWithCondition2();
    }
}
```

File cấu hình _application.properties_:

```properties
# Thay đổi thành true để tạo bean2
kungfutech.bean2.enabled=true
```

### @ConditionalOnExpression annotation

`@ConditionalOnExpression` được sử dụng khi bạn muốn đặt nhiều điều kiện và thỏa mãn điều kiện này bằng một biểu thức.

```java
@Configuration
@ConditionalOnExpression(
        "${kungfutech.expression1.enabled:true} and ${kungfutech.expression2.enabled:true}"
)
public class ConditionalOnExpressionExample {
}
```

### @ConditionalOnMissingBean annotation

`@ConditionalOnMissingBean` được sử dụng khi bạn muốn tạo một bean chỉ khi chưa tồn tại bất kỳ bean nào tương tự trong context.

```java
@Configuration
public class ConditionalOnMissingBeanExample {
    /**
     * Bean này chỉ được tạo ra nếu chưa tồn tại bất kỳ SomeMissingBean nào trong context.
     */
    @ConditionalOnMissingBean
    DataSource someMissingBean(){
        return new DataSource();
    }
}
```

### @ConditionalOnResource annotation

`@ConditionalOnResource` được sử dụng khi bạn muốn tạo bean chỉ khi một tài nguyên nào đó mà bạn chỉ định tồn tại.

```java
@Configuration
@ConditionalOnResource(resources = "/application.properties")
public class ConditionalOnResourceExample {
}
```

### @ConditionalOnClass annotation

`@ConditionalOnClass` được sử dụng khi bạn muốn tạo bean chỉ khi một class cụ thể nào đó tồn tại trong classpath.

```java
@Configuration
@ConditionalOnClass(name = "com.example.SomeClass")
class ConditionalOnClassExample {
}
```

### @ConditionalOnMissingClass annotation

`@ConditionalOnMissingClass` ngược lại với `@ConditionalOnClass`. Nó thỏa mãn khi class cụ thể không tồn tại trong `classpath`.

```java
@Configuration
@ConditionalOnMissingClass(name = "com.example.SomeClass")
class ConditionalOnMissingClassExample {
}
```

### @ConditionalOnJava annotation

`@ConditionalOnJava` thỏa mãn khi môi trường chạy Java có phiên bản đúng với điều kiện.

```java
@Configuration
@ConditionalOnJava(JavaVersion.EIGHT)
class ConditionalOnJavaExample {
}
```

### Các Loại Điều Kiện Khác

Còn nhiều loại điều kiện khác, nhưng chúng ít được sử dụng, nên ở đây chỉ đề cập các điều kiện quan trọng.

### Tự Định Nghĩa Điều Kiện

Nếu bạn cần, bạn cũng có thể tự định nghĩa điều kiện tùy chỉnh. Chúng ta sẽ tìm hiểu cách thực hiện điều này trong bài viết sau.

::alert{type="success"}

Trong bài viết này, chúng ta đã tìm hiểu cách tạo bean có điều kiện trong **Spring Boot** sử dụng annotation `@Conditional`. Điều này giúp chúng ta kiểm soát việc tạo bean dựa trên các điều kiện như sự tồn tại của bean khác, giá trị cấu hình, sự hiện diện của tài nguyên, và nhiều điều kiện khác. Việc này giúp tạo ra các ứng dụng linh hoạt và dễ quản lý hơn.

::
