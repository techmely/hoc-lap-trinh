---
title: "Cấu hình ứng dụng với XML"
description: "Spring cho phép bạn cấu hình ứng dụng bằng cách sử dụng tệp XML hoặc Annotation. Thường thì người ta sử dụng cả hai loại này để cấu hình ứng dụng. Annotation thường được sử dụng để giảm tải phần cấu hình trong tệp XML để tránh sự phức tạp khi tệp cấu hình quá lớn."
chapter:
  name: "Tổng quan về Spring"
  slug: "chuong-01-tong-quan-ve-spring"
category:
  name: "Spring Boot"
  slug: "spring-boot"
image: https://kungfutech.edu.vn/thumbnail.png
position: 7
---

Spring cho phép bạn cấu hình ứng dụng bằng cách sử dụng tệp XML hoặc Annotation. Thường thì người ta sử dụng cả hai loại này để cấu hình ứng dụng. Annotation thường được sử dụng để giảm tải phần cấu hình trong tệp XML để tránh sự phức tạp khi tệp cấu hình quá lớn. Tuy nhiên, tệp XML vẫn phải được sử dụng để chứa các khai báo cơ bản của hệ thống hoặc những bean cũ không sử dụng Annotation khi được định nghĩa.

## Cấu hình bằng XML

Trong ứng dụng Spring thông thường, chúng ta sẽ cấu hình ứng dụng bằng cách sử dụng 2 tệp:

1. `web.xml`: Đây là tệp cấu hình cho ứng dụng web Java. Trong tệp này, chúng ta chỉ định tệp cấu hình Spring MVC là `dispatcher-servlet.xml`.

2. `dispatcher-servlet.xml`: Đây là tệp cấu hình dành riêng cho ứng dụng Spring MVC.

Nếu ứng dụng có nhiều servlet, việc xác định các tài nguyên chung trong `applicationContext.xml` sẽ trở nên quan trọng hơn.

## Tệp cấu hình web.xml

Tệp web.xml được sử dụng để cấu hình nhiều khía cạnh của ứng dụng web (chẳng hạn như JSP, Servlet, Spring, và nhiều thứ khác). Trong bài viết này, chúng ta chỉ quan tâm đến các khai báo liên quan đến ứng dụng Spring MVC.

Dưới đây là một ví dụ về tệp web.xml:

```xml
<?xml version="1.0" encoding="UTF-8"?>
<web-app xmlns="http://xmlns.jcp.org/xml/ns/javaee"
    xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
    xsi:schemaLocation="http://xmlns.jcp.org/xml/ns/javaee http://xmlns.jcp.org/xml/ns/javaee/web-app_4_0.xsd"
    version="4.0">

  <!-- Khai báo vị trí của tệp applicationContext.xml -->
  <context-param>
    <param-name>contextConfigLocation</param-name>
    <param-value>/WEB-INF/applicationContext.xml</param-value>
  </context-param>

  <!-- Sử dụng ContextLoaderListener để tải applicationContext.xml -->
  <listener>
    <listener-class>org.springframework.web.context.ContextLoaderListener</listener-class>
  </listener>

  <!-- Định nghĩa DispatcherServlet -->
  <servlet>
    <servlet-name>dispatcher</servlet-name>
    <servlet-class>org.springframework.web.servlet.DispatcherServlet</servlet-class>
    <load-on-startup>1</load-on-startup>
  </servlet>

  <!-- Ánh xạ DispatcherServlet với URL pattern "/" -->
  <servlet-mapping>
    <servlet-name>dispatcher</servlet-name>
    <url-pattern>/</url-pattern>
  </servlet-mapping>
</web-app>
```

Trong tệp cấu hình này:

- Chúng ta khai báo `contextConfigLocation` để chỉ ra vị trí của tệp `applicationContext.xml`.
- Sử dụng `ContextLoaderListener` để tải tệp `applicationContext.xml`.
- Định nghĩa `DispatcherServlet` và ánh xạ nó với URL pattern "/".

Tên `dispatcher` được sử dụng cho `servlet-name` để xác định tên của Servlet và do đó tên của tệp cấu hình Spring MVC là `dispatcher-servlet.xml`. Nếu bạn đặt `servlet-name` thành `my-config`, tên tệp cấu hình Spring MVC sẽ là `my-config-servlet.xml`.

## Tệp cấu hình dispatcher-servlet.xml

Dưới đây là một ví dụ về tệp cấu hình `dispatcher-servlet.xml`:

```xml
<?xml version="1.0" encoding="UTF-8"?>
<beans xmlns="http://www.springframework.org/schema/beans"
   xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
   xmlns:context="http://www.springframework.org/schema/context"
   xmlns:mvc="http://www.springframework.org/schema/mvc"
   xsi:schemaLocation="http://www.springframework.org/schema/beans
   http://www.springframework.org/schema/beans/spring-beans.xsd
   http://www.springframework.org/schema/context
   http://www.springframework.org/schema/context/spring-context.xsd
   http://www.springframework.org/schema/mvc
   http://www.springframework.org/schema/mvc/spring-mvc.xsd">

  <!-- Quét các component trong gói codelean.controller -->
  <context:component-scan base-package="codelean.controller"/>

  <!-- Cho phép sử dụng Annotation trong Spring MVC -->
  <mvc:annotation-driven/>

  <!-- Cấu hình ViewResolver để xác định vị trí và phần mở rộng của view -->
  <bean class="org.springframework.web.servlet.view.InternalResourceViewResolver">
    <property name="prefix" value="/WEB-INF/views/"/>
    <property name="suffix" value=".jsp"/>
  </bean>
</beans>
```

Trong tệp cấu hình này:

- Chúng ta sử dụng các namespace để định nghĩa các thẻ trong tệp XML. Các namespace này được khai báo ở đầu tệp để sử dụng trong các thẻ cấu hình.
- Chúng ta sử dụng `<context:component-scan>` để quét các thành phần trong gói `codelean.controller`.
- `<mvc:annotation-driven/>` cho phép sử dụng Annotation trong Spring MVC.
- `<bean class="org.springframework.web.servlet.view.InternalResourceViewResolver">` cấu hình `ViewResolver` để xác định vị trí và phần mở

rộng của view. Ở đây, view sẽ được tìm ở thư mục `/WEB-INF/views/` và có phần mở rộng là `.jsp`.

Khi bạn sử dụng Annotation như `@Controller`, `@RequestMapping`, `@Component`, `@PostMapping`, `@GetMapping`, `@Service`,... bạn cần có khai báo `<mvc:annotation-driven/>` để ứng dụng Spring MVC biết rằng bạn đang sử dụng Annotation trong phần cấu hình.

Điều quan trọng là bạn cần cấu hình `ViewResolver` để xác định nơi và cách bạn lưu trữ các trang JSP để hiển thị giao diện cho người dùng.
