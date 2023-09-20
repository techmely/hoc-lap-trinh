---
title: "Cấu hình view trong Spring."
description: "Thông thường trong ứng dụng Spring bạn thường chỉ cần sử dụng duy nhất một công nghệ cho tầng View, nó có thể là Thymeleaf, JSP."
chapter:
  name: "Thymeleaf"
  slug: "chuong-05-thymeleaf"
category:
  name: "Spring Boot"
  slug: "spring-boot"
image: https://kungfutech.edu.vn/thumbnail.png
position: 5
---

## Cấu hình view trong Spring

![view](https://1.bp.blogspot.com/-H9ad-4FmlUg/XgK57mYwfbI/AAAAAAAAAVg/zpzHwyp7ds0VgJe8pxlg2Lu_uqPgkCKvgCLcBGAsYHQ/s320/spring-mvc-concepts-2.jpg)

### Cấu hình view trong ứng dụng Spring MVC

Có hai interface trong Spring MVC phù hợp với core của hệ thống templating:

- org.springframework.web.servlet.View
- org.springframework.web.servlet. ViewResolver

Đây là các view model trong các ứng dụng. Nó cho phép sửa đổi, xác định trước hành vi bằng cách định nghĩa nó là các bean. Các view phụ trách việc hiễn thị giao diện HTML, thường là thực thi một số template engine như Thymeleaf.

Các ViewResolver (trình phân giải view) là các đối tượng chịu trách nhiệm lấy các đối tượng View cho một hành động và vị trí cụ thể. Thông thường, các controller yêu cầu ViewResolvers chuyến tiếp đến một view với một tên cụ thể (một chuỗi được trả về bởi phương thức). Sau đó, tất cả các view resolver trong ứng dụng thực thi theo thứ tự cho đến khi một trong số đó có thể phân giải view trong trường
hợp một đối tượng View được trả vể và điều khiển được truyền tới nó cho việc render HTML.

::alert{type="warning"}
Lưu ý: Không phải tất cả các trạng thái trong ứng dụng của chúng ta đều được định nghĩa là Views, chỉ những hành vi mà chúng ta muốn phi chuẩn hoặc được cấu hình theo một cách cụ thể (ví dụ, bằng cách gắn một số bean đặc biệt với nó). Nếu một ViewResolver yêu cầu một view mà không có bean tương ứng, một đối tượng View mới được tạo ra một cách đặc biết và được trả về.
::

Một cấu hình điển hình cho JSP+ViewResolver JSPL trong ứng dụng Spring MVC trước đây trông như sau:

```xml
<bean class="org.springframework.web.servlet.view.InternalResourceViewResolver">
  <property name="viewClass" value="org.springframework.web.servlet.view.JstlView" />
  <property name="prefix" value="/WEB-INF/jsps/" />
  <property name="suffix" value=".jsp" />
  <property name="order" value="2" />
  <property name="viewNames" value="*jsp" />
</bean>
```

### Cấu hình view trong Thymleaf

Thymeleaf cung cấp các triển khai cho hai interface được đề cập ở trên:

- org.thymeleaf.spring4.view.ThymeleafView
- org.thymeleaf.spring4.view.ThymeleafViewResolver

Hai lớp này sẽ chịu trách nhiệm xử lý các template Thymeleaf như là kết quả của việc thực thi các controller.
Cấu hình của Thymeleaf View Resolver rất giống với cấu hình của JSP:

```java
@Bean
public ThymeleafviewResolver viewResolver (){
   ThymeleafviewResolver viewResolver=new ThymeleafviewResolver ();
    viewResolver.setTemplateEngine (templateEngine ());
   // NOTE 'order' and 'viewNames' are optional
   viewResolver.setOrder (1);
   viewResolver.setViewNames (new String [] {".html", ".xhtml"});
   return viewResolver;
}
```

Hoặc trong XML:

```xml
<bean class="org.thymeleaf.spring4.view. ThymeleafViewResolver">
   <property name="templateEngine" ref="templateEngine" />
   <!-- NOTE 'order' and 'viewNames' are optional -->
   <property name-"order" value="1" />
   <property name="viewNames" value="*.html,*.xhtml" />
</bean>
```

**Lưu ý**: Không cần tham số prefix hoặc suffix, bởi vì chúng đã được chỉ định tại Template Resolver (lần lượt được truyền tới Template Engine).
Và điều gì xảy ra nếu chúng ta muốn định nghĩa một bean “View" và thêm một số biến tĩnh vào nó?
Chúng ta chỉ cần xác định một prototype (nguyên mẫu) bean cho nó:

```java
@Bean
@Ecope ("prototype")
public Thymeleafview mainview (){
   Thymeleafview view=new Thymeleafview ("main"); // templateName='main'
   view.setStaticvariables(
   Collections.singletonMap ("footer", "The ACME Fruit Company"));
   return view;
```

Bằng cách này, bạn có thể thực thi bean "View" bằng cách chọn nó bằng tên bean (mainView, trong trường hợp này).
