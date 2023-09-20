---
title: "Dependency Injection (DI)"
description: "Dependency Injection (DI) là một design pattern trong lập trình, giúp quản lý sự phụ thuộc (dependency) giữa các thành phần của ứng dụng. Trong DI, các module không giao tiếp trực tiếp với nhau mà thông qua giao diện (interface). Các module cấp thấp sẽ thực thi giao diện, và module cấp cao sẽ giao tiếp thông qua giao diện này"
chapter:
  name: "Các khái niệm cơ bản về Spring"
  slug: "chuong-02-cac-khai-niem-co-ban"
category:
  name: "Spring Boot"
  slug: "spring-boot"
image: https://kungfutech.edu.vn/thumbnail.png
position: 8
---

![Dependency Injection](https://github.com/techmely/hoc-lap-trinh/assets/29374426/3bbde695-58c3-472a-a717-201536a42ab3)

## DI là gì?

Dependency Injection (DI) là một design pattern trong lập trình, giúp quản lý sự phụ thuộc (dependency) giữa các thành phần của ứng dụng. Trong DI, các module không giao tiếp trực tiếp với nhau mà thông qua giao diện (interface). Các module cấp thấp sẽ thực thi giao diện, và module cấp cao sẽ giao tiếp thông qua giao diện này.

Ví dụ: Để giao tiếp với cơ sở dữ liệu, chúng ta có thể sử dụng một giao diện `IDatabase`, và có hai module cấp thấp là `XMLDatabase` và `SQLDatabase` thực thi giao diện này. Module cấp cao, ví dụ như `CustomerBusiness`, sẽ sử dụng giao diện `IDatabase` để tương tác với cơ sở dữ liệu.

Điều quan trọng là việc khởi tạo các module cấp thấp sẽ được DI container thực hiện. Module cấp cao không cần biết về chi tiết cụ thể của các module cấp thấp.

### Các Dạng của Dependency Injection

Có ba dạng chính của Dependency Injection:

1. **Constructor Injection**: Dependency được tiêm vào thông qua constructor của lớp.

2. **Setter Injection**: Dependency được tiêm vào thông qua các phương thức setter.

3. **Interface Injection**: Lớp cần tiêm sẽ thực thi một giao diện (interface) chứa phương thức `inject`. Container sẽ tiêm các dependency vào lớp thông qua phương thức `inject` của giao diện.

## Dependency Injection trong Java

Trong Java, Dependency Injection thường được thực hiện bằng cách sử dụng các framework như Spring, Guice, Dagger, và nhiều thư viện khác. Dưới đây là một ví dụ sử dụng Spring để thực hiện Dependency Injection.

```java
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

public class MainApp {
    public static void main(String[] args) {
        ApplicationContext context = new ClassPathXmlApplicationContext("applicationContext.xml");

        HelloWorld helloWorld1 = (HelloWorld) context.getBean("helloWorld1");
        helloWorld1.print();

        HelloWorld helloWorld2 = (HelloWorld) context.getBean("helloWorld2");
        helloWorld2.print();
    }
}
```

Spring cho phép chúng ta cấu hình các dependency trong file XML. Dưới đây là một ví dụ cấu hình bằng XML:

```xml
<?xml version="1.0" encoding="UTF-8"?>
<beans xmlns="http://www.springframework.org/schema/beans"
  xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
  xsi:schemaLocation="http://www.springframework.org/schema/beans
                      http://www.springframework.org/schema/beans/spring-beans-3.0.xsd">

    <bean id="helloWorld1" class="com.example.HelloWorld">
        <property name="message" value="inject by setter" />
    </bean>

    <bean id="helloWorld2" class="com.example.HelloWorld">
        <constructor-arg value="inject by constructor" type="String" />
    </bean>
</beans>
```

Trong ví dụ này, chúng ta đã cấu hình hai bean `helloWorld1` và `helloWorld2` trong file XML. Spring sẽ tiêm các dependency vào các bean này dựa trên cấu hình.

::result
Print: inject by setter</br>
Print: inject by constructor
::

## Ưu điểm của Dependency Injection

- Tách biệt giữa việc tạo đối tượng và việc sử dụng đối tượng, làm cho ứng dụng dễ dàng mở rộng và bảo trì.
- Tạo sự linh hoạt trong việc thay đổi các dependency mà không cần sửa đổi mã nguồn của các class sử dụng chúng.
- Dễ dàng kiểm thử với các mock object để tạo các bài kiểm tra đơn vị (unit tests).
- Cải thiện khả năng đọc và hiểu mã nguồn.

::alert{type="success"}
Trong tổng quan, Dependency Injection là một phần quan trọng của việc thiết kế và phát triển ứng dụng Java hiện đại. Nó giúp giảm sự phụ thuộc giữa các thành phần, tạo ra mã nguồn dễ quản lý và đảm bảo tính linh hoạt của ứng dụng.
::
