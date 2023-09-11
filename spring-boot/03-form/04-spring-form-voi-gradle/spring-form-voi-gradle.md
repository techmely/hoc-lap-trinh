---
title: "Form trong Spring sử dụng Maven."
description: "Form trong Spring sử dụng Maven."
chapter:
  name: "Form"
  slug: "chuong-03-form"
category:
  name: "Spring Boot"
  slug: "spring-boot"
image: https://kungfutech.edu.vn/thumbnail.png
position: 4
---

## Xử lý Form trong Spring MVC

Các công nghệ sử dụng trong bài viết này

- Spring 5.0.2.RELEASE
- Maven
- JDK 1.8
- Eclipse 4.6 Neon
- Server tomcat

Trong 2 bài trước chúng ta đã tìm hiểu các tạo một ứng dụng web với Spring MVC sử dụng xml config và annotation config.

Bản thân mình thấy annoation config thì khá là gọn nhẹ và nhanh chóng, nhưng mình lại thích xml config hơn vì nó phân tách rõ giữa phần code và phần cấu hình, trong các ứng dụng cần nhiều cấu hình thì xml tỏ ra rõ ràng và dễ đọc hơn.

==> Trong các ví dụ từ đây mình sẽ đều sử dụng xml config.

### Ví dụ 1:

Nhập thông tin của 1 nhân viên (gồm id và name) sau đó chuyển name thành chữ hoa và in ra màn hình.

#### Các thư viện sử dụng:

```xml
<project xmlns="http://maven.apache.org/POM/4.0.0" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
  xsi:schemaLocation="http://maven.apache.org/POM/4.0.0 http://maven.apache.org/xsd/maven-4.0.0.xsd">
  <modelVersion>4.0.0</modelVersion>
  <groupId>stackjava.com</groupId>
  <artifactId>SpringForm</artifactId>
  <version>0.0.1-SNAPSHOT</version>
  <packaging>war</packaging>
  <properties>
    <spring.version>5.0.2.RELEASE</spring.version>
  </properties>
  <dependencies>
    <dependency>
      <groupId>org.springframework</groupId>
      <artifactId>spring-webmvc</artifactId>
      <version>${spring.version}</version>
    </dependency>
    <dependency>
      <groupId>jstl</groupId>
      <artifactId>jstl</artifactId>
      <version>1.2</version>
    </dependency>
    <dependency>
      <groupId>javax.servlet</groupId>
      <artifactId>jsp-api</artifactId>
      <version>2.0</version>
      <scope>provided</scope>
    </dependency>
  </dependencies>
</project>
```

#### Các file entities:

```java
package stackjava.com.springmvchello.entities;
public class Employee {
  private int id;
  private String name;
  // getter/setter
}
```

#### File Controller

```java
package stackjava.com.springmvchello.controller;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.ui.ModelMap;
import org.springframework.web.bind.annotation.ModelAttribute;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import stackjava.com.springmvchello.entities.Employee;
@Controller
public class EmployeeController {
  @RequestMapping(value = { "/"}, method = RequestMethod.GET)
  public String addEmployee(Model model) {
    model.addAttribute("employee", new Employee());
    return "add-employee";
  }
  @RequestMapping(value = "/addEmployee", method = RequestMethod.POST)
  public String doAddEmployee(@ModelAttribute("employee") Employee employee, ModelMap modelMap) {
    employee.setName(employee.getName().toUpperCase());
    modelMap.addAttribute("employee", employee);
    return "view-employee";
  }
}
```

Tham số model hay modelMap trong các method là các biến được dùng để truyền dữ liệu giữa màn hình với controller, giữa các controller.
VD: ở method addEmployee: `model.addAttribute("employee", new Employee());` nó sẽ truyền một đối tượng `new Employee()` với name là employee tới màn hình add-employee.

#### File Spring Config

```xml
<?xml version="1.0" encoding="UTF-8"?>
<beans xmlns="http://www.springframework.org/schema/beans"
  xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:context="http://www.springframework.org/schema/context"
  xsi:schemaLocation="http://www.springframework.org/schema/beans http://www.springframework.org/schema/beans/spring-beans.xsd
    http://www.springframework.org/schema/context http://www.springframework.org/schema/context/spring-context-4.3.xsd">
  <context:component-scan base-package="stackjava.com.springmvchello" />
  <bean
    class="org.springframework.web.servlet.view.InternalResourceViewResolver">
    <property name="prefix">
      <value>/WEB-INF/views/jsp/</value>
    </property>
    <property name="suffix">
      <value>.jsp</value>
    </property>
  </bean>
</beans>
```

#### File web.xml

```xml
<?xml version="1.0" encoding="UTF-8"?>
<web-app xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
  xmlns="http://java.sun.com/xml/ns/javaee"
  xsi:schemaLocation="http://java.sun.com/xml/ns/javaee http://java.sun.com/xml/ns/javaee/web-app_2_5.xsd"
  version="2.5">
  <display-name>SpringMVCHello</display-name>
  <servlet>
    <servlet-name>spring-mvc</servlet-name>
    <servlet-class>org.springframework.web.servlet.DispatcherServlet</servlet-class>
    <load-on-startup>1</load-on-startup>
  </servlet>
  <servlet-mapping>
    <servlet-name>spring-mvc</servlet-name>
    <url-pattern>/</url-pattern>
  </servlet-mapping>
</web-app>

```

#### File add-employee.jsp sẽ định nghĩa form để nhập thông tin id/name

```html
<%@taglib uri="http://www.springframework.org/tags/form" prefix="form"%>
<html>
  <head>
    <title>Spring MVC Form Handling</title>
  </head>
  <body>
    <h2>Employee</h2>
    <form:form method="POST" action="addEmployee" modelAttribute="employee">
      Id: <form:input path="id" />
      <br />
      Name: <form:input path="name" />
      <input type="submit" value="Submit" />
    </form:form>
  </body>
</html>
```

- modelAttribute: biểu thị đối tượng được sử dụng trong form. Ví dụ modelAttribute=”employee” tức là form này sẽ thực hiện xử lý các thuộc tính của đối tượng employee vừa truyền tới từ controller.
- Thuộc tính path trong các thẻ form thực hiện map với các thuộc tính của đối tượng trong modelAttribute. Ví dụ path=”id” sẽ được hiểu là giá trị của thuộc tính ‘id’ trong đối tượng employee.

#### File view-employee.jsp sẽ hiển thị các thông tin id/name vừa nhập

```html
<%@taglib uri="http://www.springframework.org/tags/form" prefix="form"%>
<html>
  <head>
    <title>Spring MVC Form Handling</title>
  </head>
  <body>
    <h2>Employee</h2>
    Id:${employee.id}
    <br />
    Name:${employee.name}
  </body>
</html>
```

cú pháp ${value} là cú pháp của JTSL thực hiện in ra giá trị của đối tượng bên trong

#### Demo:

![demo](https://scontent.xx.fbcdn.net/v/t1.15752-9/280295419_798993481485847_7553100076039742746_n.png?stp=dst-png_s280x280&_nc_cat=105&ccb=1-7&_nc_sid=aee45a&_nc_ohc=kOtRVRNPi-MAX_2ba4Q&_nc_ad=z-m&_nc_cid=0&_nc_ht=scontent.xx&oh=03_AVKGkV32zuJqdNAuMJ98-4CUkm96s0t-PN0wU0h0rdcqLg&oe=62B7A74A)
