---
title: "Hibernate là gì?"
description: "Hibernate là một thư viện ORM (Object-Relational Mapping) mã nguồn mở giúp lập trình viên viết ứng dụng Java có thể ánh xạ các đối tượng (POJO) với cơ sở dữ liệu quan hệ. Nó hỗ trợ việc thực hiện các khái niệm lập trình hướng đối tượng với cơ sở dữ liệu quan hệ. Hibernate là một lớp trung gian giữa ứng dụng Java của bạn và cơ sở dữ liệu"
chapter:
  name: "Spring JPA và Hibernate"
  slug: "chuong-05-spring-jpa-va-hibernate"
category:
  name: "SpringBoots"
  slug: "springboots"
image: https://kungfutech.edu.vn/thumbnail.png
position: 2
---

Hibernate là một framework được sử dụng nhiều nhất hiện nay để giúp lập trình viên Java có thể ánh xạ các class (POJO - Plain Old Java Object) với một cơ sở dữ liệu quan hệ bất kỳ. Trước khi Hibernate xuất hiện, chúng ta thường thao tác với cơ sở dữ liệu thông qua JDBC. Tuy nhiên, JDBC có nhiều hạn chế như code thừa, tốn thời gian cho việc ánh xạ dữ liệu vào Java, và khó bảo trì khi cơ sở dữ liệu thay đổi. Hibernate ra đời để giải quyết những vấn đề này.

## Định nghĩa

Hibernate là một thư viện ORM (Object-Relational Mapping) mã nguồn mở giúp lập trình viên viết ứng dụng Java có thể ánh xạ các đối tượng (POJO) với cơ sở dữ liệu quan hệ. Nó hỗ trợ việc thực hiện các khái niệm lập trình hướng đối tượng với cơ sở dữ liệu quan hệ. Hibernate là một lớp trung gian giữa ứng dụng Java của bạn và cơ sở dữ liệu.

### Lợi ích của Hibernate:

1. **Giảm thiểu code thừa**: Hibernate giúp giảm việc viết code thừa mà chỉ phục vụ mục đích lấy dữ liệu.
2. **Tiết kiệm thời gian**: Việc ánh xạ dữ liệu vào đối tượng Java trở nên đơn giản và tiết kiệm thời gian hơn.
3. **Dễ bảo trì**: Khi cơ sở dữ liệu thay đổi, Hibernate giúp giảm tác động lên mã nguồn của ứng dụng.
4. **Hỗ trợ tính OOP**: Hibernate giúp bạn làm việc với cơ sở dữ liệu mà không cần lo lắng về SQL truyền thống và hỗ trợ tính chất hướng đối tượng (OOP) trong cơ sở dữ liệu.

## POJO

POJO (Plain Old Java Object) là một class Java đại diện cho một bảng trong cơ sở dữ liệu. Một POJO có các thuộc tính private với các phương thức getter và setter public.

Ví dụ Java đơn giản:

```java
public class Product {
    private Long id;
    private String name;
    private double price;

    // Constructors, getters, and setters
}
```

## Ánh xạ dữ liệu

Khi đã có các POJO đại diện cho các bảng trong cơ sở dữ liệu, chúng ta cần ánh xạ dữ liệu từ cơ sở dữ liệu vào các đối tượng Java. Điều này được thực hiện bằng cách sử dụng các chú thích (annotations) của Hibernate.

Ví dụ ánh xạ một POJO đến một bảng trong cơ sở dữ liệu:

```java
@Entity // Đánh dấu đây là một Entity, chịu sự quản lý của Hibernate
@Table(name = "products") // Đánh dấu Entity này đại diện cho bảng "products" trong cơ sở dữ liệu
public class Product {
    @Id // Đánh dấu thuộc tính "id" là khóa chính của bảng
    @GeneratedValue(strategy = GenerationType.IDENTITY) // Tự động tạo giá trị khi insert
    private Long id;

    @Column(name = "product_name") // Ánh xạ thuộc tính "name" vào cột "product_name" trong bảng
    private String name;

    @Column(name = "product_price") // Ánh xạ thuộc tính "price" vào cột "product_price" trong bảng
    private double price;

    // Constructors, getters, and setters
}
```

## Session

Để thực hiện các thao tác đối với cơ sở dữ liệu sử dụng Hibernate, chúng ta sử dụng đối tượng `Session`. Session là một đối tượng quan trọng trong Hibernate và được tạo ra từ `SessionFactory`.

Đoạn mã sau đây minh họa cách sử dụng Session để truy vấn dữ liệu:

```java
SessionFactory factory = HibernateSessionUtils.getSessionFactory();

Session session = factory.getCurrentSession();

try {
    session.getTransaction().begin();

    List<Product> products = session.createQuery("SELECT p FROM Product p", Product.class).getResultList();

    session.getTransaction().commit();
} catch (Exception e) {
    session.getTransaction().rollback();
}
```

## Hibernate Query Language (HQL)

Hibernate sử dụng ngôn ngữ truy vấn Hibernate (HQL) để truy vấn dữ liệu. HQL tương tự SQL nhưng sử dụng tên của các đối tượng Java thay vì tên bảng.

Ví dụ:

```java
// SQL
// Truy vấn từ bảng "products"
SELECT * FROM products;

// HQL
// Truy vấn từ đối tượng "Product"
SELECT p FROM Product p;
```

Như vậy, Hibernate giúp bạn tiết kiệm thời gian và công sức trong việc làm việc với cơ sở dữ liệu, đồng thời giúp bạn duy trì tính OOP trong ứng dụng của mình.

::alert{type="success"}
Hibernate là một framework ORM mạnh mẽ và phổ biến trong cộng đồng Java. Nó giúp bạn ánh xạ các đối tượng Java với cơ sở dữ liệu một cách dễ dàng, tiết kiệm thời gian và giảm thiểu
::
