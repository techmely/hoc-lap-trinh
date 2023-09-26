---
title: "Annotation là gì?"
description: "Annotation (chú thích) là một tính năng quan trọng trong lập trình Java, cho phép bạn thêm các thông tin bổ sung vào mã nguồn của bạn, giúp trình biên dịch và các công cụ phát triển hiểu và xử lý mã nguồn của bạn một cách thông minh"
chapter:
  name: "Spring Boot cơ bản"
  slug: "chuong-03-spring-boot-co-ban"
position: 1
---

Annotation (chú thích) là một tính năng quan trọng trong lập trình Java, cho phép bạn thêm các thông tin bổ sung vào mã nguồn của bạn, giúp trình biên dịch và các công cụ phát triển hiểu và xử lý mã nguồn của bạn một cách thông minh. Annotation được sử dụng rộng rãi trong Java để đánh dấu và cung cấp metadata cho các lớp, phương thức, biến, hoặc gói.

Annotation không ảnh hưởng đến hoạt động chương trình khi chạy, nhưng chúng mang thông tin quan trọng về cấu trúc và mục đích của mã nguồn. Điều này có lợi cho việc tự động hóa các tác vụ, kiểm tra mã nguồn, và cung cấp hướng dẫn cho các công cụ phát triển.

## Cú Pháp Cơ Bản của Annotation

Annotation trong Java được đặt trong một dấu `@`, theo sau là tên của annotation. Một số annotation có thể có giá trị được đặt trong dấu ngoặc đơn `(value = ...)`, nhưng nếu chỉ có một giá trị và không cần gán tên, bạn có thể viết trực tiếp giá trị đó.

Dưới đây là cú pháp cơ bản của annotation:

```java
@AnnotationName
@AnnotationName(value = "someValue")
```

## Ví dụ về Annotation

### 1. `@Override`

`@Override` là một trong những annotation được sử dụng phổ biến nhất trong Java. Nó được đặt trên một phương thức để thông báo rằng phương thức này ghi đè (override) một phương thức từ lớp cha. Điều này giúp trình biên dịch kiểm tra xem phương thức thực sự có ghi đè một phương thức từ lớp cha hay không.

```java
class Animal {
    void makeSound() {
        System.out.println("Animal makes a sound");
    }
}

class Dog extends Animal {
    @Override
    void makeSound() {
        System.out.println("Dog barks");
    }
}
```

### 2. `@Deprecated`

`@Deprecated` được sử dụng để đánh dấu một phần của mã nguồn hoặc một phương thức đã bị lỗi thời hoặc không nên sử dụng nữa. Nếu bạn sử dụng một phần được đánh dấu `@Deprecated`, trình biên dịch sẽ cảnh báo bạn về điều này.

```java
class OldLibrary {
    @Deprecated
    void oldMethod() {
        System.out.println("This method is deprecated.");
    }
}
```

### 3. `@SuppressWarnings`

`@SuppressWarnings` được sử dụng để tắt cảnh báo của trình biên dịch tại các vị trí cụ thể trong mã nguồn. Điều này có thể hữu ích khi bạn muốn tắt cảnh báo cụ thể mà bạn biết là không cần thiết.

```java
@SuppressWarnings("unused")
public class Example {
    int unusedVariable;

    @SuppressWarnings("deprecation")
    void useDeprecatedMethod() {
        OldLibrary library = new OldLibrary();
        library.oldMethod();
    }
}
```

::result
Annotation là một tính năng mạnh mẽ trong Java, cho phép bạn cung cấp thông tin bổ sung và metadata cho mã nguồn của bạn. Chúng được sử dụng rộng rãi trong thư viện và framework Java để tối ưu hóa việc phát triển và kiểm tra mã nguồn. Hãy tận dụng khả năng của annotation để viết mã Java hiệu quả hơn.
::
