---
title: "Converter trong Spring"
description:"Trong template thymeleaf, để lấy các thông tin trong Model. bạn sẽ sử dụng Thymeleaf Standard Expression"
keywords:
  [
    "khóa học Spring cơ bản",
    "Converter trong Spring",
    "Convert Spring là gì",
    "Spring Data JPA là gì",
    "Hướng dẫn converter trong Spring",
    "sử dụng converter trong Spring",
    "cách khởi tạo converter trong Spring",
    "chuyển đổi kiểu dữ liệu với converter",
    "hướng dẫn Spring cơ bản và nâng cao",
    "Spring Data JPA cơ bản"
  ]
chapter:
  name: "Spring Data JPA"
  slug: "chuong-06-spring-data-jpa"
category:
  name: "spring"
  slug: "spring"

---
## Converter trong Spring
![Thymeleaf](https://github.com/techmely/hoc-lap-trinh/blob/spring-boots/spring-boot/images/spring-converter.png)


### Spring Converter là gì?
`Spring Converter` là một đối tượng được dùng để chuyển đổi kiểu dữ liệu này sang kiểu dữ liệu khác. 
Ví dụ, chúng ta có thể biểu diễn cùng một ngày theo những định dạng khác nhau, chẳng hạn như: “December 25, 2016,” 12/25/2016,” “2016-12-25”. 

Mặc định, **Spring** sẽ sử dụng định dạng ngày của địa phương hiện tại (*current locale*). Chẳng hạn, định dạng của Hoa Kỳ sẽ là `MM/dd/yyyy`. Trong trường hợp chúng ta muốn thay đổi định dạng của ngày khi liên kết một trường string với một đối tượng **LocalDate** thì chúng ta cần viết một **converter** để chuyển đổi từ `string` sang ngày.

 <content-warning>***Lưu ý***: Lớp `java.time.LocalDate` là một lớp mới được bổ sung cho **Java 8**, thay thế cho lớp `java.util.Date`. Chúng ta nên sử dụng bộ **API** mới về ngày tháng và thời gian, thay vì sử dụng các lớp **Date** và **Calendar** như cũ.</content-warning> 

Để tạo một **Converter**, chúng ta viết một lớp **Java** triển khai interface `org.springframework.core.convert.converter.Converter`. Đây là một interface generic:
```java
public interface Converter<S, T>
```
- S đại diện cho kiểu dữ liệu nguồn
- T đại diện cho kiểu dữ liệu đích

Chẳng hạn, nếu muốn tạo một **converter** để chuyển đổi từ kiểu Long sang kiểu **LocalDate** thì chúng ta có thể khai báo một lớp như sau:
```java
public class MyConverter implements Converter<Long, LocalDate> {
// Write code here
}
```
Bên trong lớp này, chúng ta triển khai phương thức convert() của interface Converter.
```java
T convert(S source)
```