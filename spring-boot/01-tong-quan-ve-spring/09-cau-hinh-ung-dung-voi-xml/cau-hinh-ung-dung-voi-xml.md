---
title: "Cấu hình ứng dụng với xml"
description: "Cấu hình ứng dụng với xml"
chapter:
  name: "Tổng quan về Spring"
  slug: "chuong-01-tong-quan-ve-spring"
category:
  name: "Spring Boot"
  slug: "spring-boot"
image: https://kungfutech.edu.vn/thumbnail.png
position: 9
---

Với Spring bạn có thể sử dụng XML để cấu hình hoặc annotation để cấu hình ứng dụng. Thông
thường người ta sử dụng cả2loại này để cấu hình ứng dụng. Khi đó annotation chỉ đóng vai trò giảm
tải một số thành phần trong file cấu hình để tránh sự phức tạp khi file cấu hình quá lớn. XML vẫn phải
được sử dụng chính để chứa các khai báo cơ bản nhất của hệ thống hoặc những bean cũ không sử
dụng annotation lúc định nghĩa.

## Cấu hình bằng XML

File cấu hình ứng dụng

![Cấu hình ứng dụng Spring boot bằng XML](https://1.bp.blogspot.com/-oRr1QEA6qEM/Xg7KBxBC57I/AAAAAAAAAcA/o8kPwFt27N421GadfgAp5j7xeLL2BehBACLcBGAsYHQ/s1600/p1.png)

Trong ứng dụng đơn gian, chung ta thương cau hình ứng dụng với3file:

- web.xml
- dispatcher-servlet.xml
- applicationContext.xml

Trong ứng dụng đơn giản, chúng ta thường cấu hình ứng dụng với 2 file web.xml và dispatcher-servlet.xml:

- `web.xml`: cấu hình ứng dụng web của java, trong đó có chỉ ra file cấu hình Spring MVC là dispatcher-servlet.xml
- `dispatcher-servlet.xml`: cấu hình dành riêng cho ứng dụng Spring MVC
- `applicationContext.xml` định nghĩa các bean được chia sẻ giữa tất cả các servlet.

Nếu ứng dụng có nhiều hơn một servlet thì việc xác định các tài nguyên phổ biến trong `applicationContext.ml` sẽ có ý nghĩa hơn.

## File cấu hình web.xml

File web.xml được sử dụng để cấu hình nhiều công việc khác nhau cho ứng dụng web nói chung (jsp, servlet, structs, spring v.v) Trong phần này chúng ta chỉ khai thác các khai báo liên quan đến ứng dụng Spring MVC.

```xml
<?xml version="1.0" encoding="UTF-8"?>
<web-app xmlns="http://xmlns.jcp.org/xml/ns/javaee"
    xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
      xsi:schemaLlocation="http://xmlns.jcp.org/xml/ns/javaee http://xmlns.jcp.org/xml/ns/javaee/web-
app_4_0.xsd"
    version="4.0">
  <context-param>
    <param-name>contextConfigLocation</param-name>
    <param-value>/WEB-INF/applicationContext.xml</param-value>
  </context-param>
  <listener>
    <listener-class>org.springframework.web.context.ContextLoaderListener</listener-class>
  </listener>
  <servlet>
    <servlet-name>dispatcher</servlet-name>
    <servlet-class>org.springframework.web.servlet.DispatcherServlet</servlet-class>
    <load-on-startup>1</load-on-startup>
  </servlet>
  <servlet-mapping>
    <servlet-name>dispatcher</servlet-name>
    <url-pattern>/</url-pattern>
  </servlet-mapping>
</web-app>
```

Trong khai báo này thì org.springframework.web.servlet.DispatcherServlet được sử dụng để tiếp nhận tất cả các yêu cầu có địa chỉ url (**<'url-pattern'>/ </'url-pattern'>**), nếu **<'url-pattern'>\*.jsp</'url-pattern'>** được hiểu là DispatcherServlet sẽ tiếp nhận tất cả các yêu cầu có địa chỉ url kết thúc bởi .jsp. DispatcherServlet sẽ phân giải để chuyển đến các action phù hợp với các yêu cầu dựa vào định dạng của url.
Hãy lưu ý rằng, trong file cấu hình này chúng ta sử dụng dispatcher để đặt tên cho servlet (**<'servlet-name>dispatcher</'servlet-name'>**). Theo quy ước mặc định của Spring thì file cấu hình Spring sẽ có tên là “<tên servlet>-servlet.xml". Và vì vậy trong trường hợp này là dispatcher-servlet.xml.
Nếu chúng ta đặt tên là **<'servlet-name'>my-config</'servlet-name'>** thì file cấu hình Spring MVC sẽ là "my-config-servlet.xml".

## File cầu hình dispatcher-servlet.xml

```xml
<?xml version="1.0" encoding="UTF-8"?>
<beans xmlns="http://www.springframework.org/schema/beans"
   xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
   xmlns:context="http://www.springframework.org/schema/context"
   xmlns:mvc="http://www.springframework.org/schema/mvc"
   xsi:schemalocation="http://www.springframework.org/schema/beans
   http://www.springframework.org/schema/beans/spring-beans.xsd
   http://www.springframework.org/schema/context
   http://www.springframework.org/schema/context/spring-context.xsd
   http://www.springframework.org/schema/mvc
   http://www.springframework.org/schema/mvc/spring-mvc.xsd"
  <context:component-scan base-package%="codelean.controller"/>
  <mvc:annotation-driven/>
  <bean class="org.springframework.web.servlet.view.InternalResourceViewResolver">
    <property name="prefix" value="/WEB-INF/views/"/>
    <property name="suffix" value=".jsp"/>
  </bean>
</beans>
```

Tập tin cầu hình này chứa đúng một thẻ **< bean>**, thẻ này chứa các thuộc tính khá phức tạp như:

```java
xmlns="http://www.springframework.org/schema/beans"
xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
xmlns:context="http://www.springframework.org/schema/context"
xmlns:mvc="http://www.springframework.org/schema/mvc"
xsi:schemalocation="http://www.springframework.org/schema/beans
http://www.springframework.org/schema/beans/spring-beans.xsd
http://www.springframework.org/schema/context
http://www.springframework.org/schema/context/spring-context.xsd
http://www.springframework.org/schema/mvc
http://www.springframework.org/schema/mvc/spring-mvc.xsd"
```

Các namespace này được khai báo để sử dụng cho các thẻ ở phần cấu hình. Thông thường, chúng ta dùng đến đầu thì khai báo đến đó.
Tuy nhiên, chúng ta có thể khai báo tất cả những gì cần thiết đế
chuẩn bị cho các khả năng có thể sử dụng cho ứng dụng sau này.

## View Resolver

Sau khi một action trong controller hoàn thành nhiệm vụ thì nó phải chỉ ra view nào cần được sử dụng để hiển thị giao diện kết quả cho người dùng.
Chỉ có tên view được chỉ định trong action còn vị trí đặt view hoặc phần mở rộng của view thì giao lại cho ViewResolver giải quyết.
Ví dụ: Trong một controller có định nghĩa một action như sau:

```java
@RequestMapping(value="/greeting", method= RequestMethod.GET
public String greeting(){
    return "greeting";
}
```

Với khai báo ViewResolver được cấu hình

```xml
<bean class="org.springframework.web.servlet.view.InternalResourceViewResolver">
  <property name="prefix" value="/WEB-INF/views/"/>
  <property name="suffix" value=".jsp"/>
</bean>
```

Khi đó view WEB-INF/views/greeting.jsp se được lựa chọn để sinh giao diện.

## Cho phép sử dụng annotation

Trong các ứng dụng Spring MVC phát triển từ 3+ gần như sử dụng annotation để đơn giải hoá công việc phát triển ứng dụng. Để ứng dụng Spring nhận biết điều này cần khai báo trong file cấu hình dispatcher-servlet dòng mã sau:

```xml
<mvc:annotation-driven/>
```

Với khai báo này, trong Spring MVC có thể đánh dấu các thành phần bằng các annotation:

- @Controller
- @RequestMapping
- @Component
- @PostMappling/@GetMapping
- @Service
  ...

## Vị trí chứa controller

Khi bạn yêu cần một action, ứng dụng Spring phải truy tìm phương thức ánh xạ tới action đó thông qua @RequestMapping hoặc @PostMapping hoặc @GetMapping.
Như vậy cần phải biết phương thức của lớpn nào được ánh xạ để thực hiện yêu cầu với khai báo:

```bash
context:component-scan base-package="codelean.controller"/>
```

Trong trường hợp này, các lớp controller thuộc gói codelean.controller sẽ được tham chiếu đến. Trong trường hợp có nhiều controller thuộc nhiều gói khác nhau thì phải chỉ rõ các gói bằng dấu phẩy.

```xml
<context:component-scan base-package%="codelean.controller1, codelean.controller2, "/>
```
