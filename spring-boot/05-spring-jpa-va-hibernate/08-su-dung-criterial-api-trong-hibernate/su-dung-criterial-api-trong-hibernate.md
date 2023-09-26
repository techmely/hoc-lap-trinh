---
title: "Sử dụng Criteria API trong Hibernate"
description: "JPA Criteria API cho phép bạn tạo các câu truy vấn trong Hibernate bằng cách sử dụng đối tượng Java thay vì viết trực tiếp câu truy vấn bằng chuỗi như JPQL (Java Persistence Query Language)"
chapter:
  name: "Spring JPA và Hibernate"
  slug: "chuong-05-spring-jpa-va-hibernate"
category:
  name: "SpringBoots"
  slug: "springboots"
image: https://kungfutech.edu.vn/thumbnail.png
position: 8
---

JPA Criteria API cho phép bạn tạo các câu truy vấn trong Hibernate bằng cách sử dụng đối tượng Java thay vì viết trực tiếp câu truy vấn bằng chuỗi như JPQL (Java Persistence Query Language). Thay vì viết:

```sql
SELECT o FROM Office o
```

Bạn có thể sử dụng Criteria API như sau:

```java
CriteriaBuilder cb = em.getCriteriaBuilder();
CriteriaQuery<Office> q = cb.createQuery(Office.class);
Root<Office> c = q.from(Office.class);
q.select(c);
```

Mặc dù cú pháp sử dụng Criteria API có vẻ phức tạp hơn, nhưng việc sử dụng nó có nhiều ưu điểm mà bạn sẽ khám phá trong bài viết này.

## JPQL vs. Criteria API

JPQL có thể thực hiện hầu hết các chức năng truy vấn mà bạn cần chỉ với một câu lệnh, nhưng nó thường không linh hoạt và không dễ tùy chỉnh. Việc chỉnh sửa hoặc tái sử dụng câu lệnh JPQL phức tạp có thể gặp khó khăn, và việc theo dõi lỗi cũng không dễ dàng.

Ngược lại, Criteria API cho phép bạn xây dựng câu truy vấn một cách linh hoạt và không bị ràng buộc bởi chuỗi. Bạn có thể xây dựng các câu truy vấn động dựa trên ngữ cảnh của ứng dụng và dễ dàng theo dõi lỗi ngay khi biên dịch chương trình.

Ví dụ, với các câu lệnh truy vấn phức tạp và có nhiều điều kiện khác nhau, sử dụng Criteria API sẽ dễ dàng hơn và giúp bạn duyệt qua các thay đổi một cách linh hoạt.

## Sử dụng Criteria API

### Cơ bản về Criteria API

Để sử dụng Criteria API, bạn cần làm theo các bước sau:

1. Lấy đối tượng `CriteriaBuilder` từ `EntityManager`.

```java
CriteriaBuilder builder = em.getCriteriaBuilder();
```

2. Tạo đối tượng `CriteriaQuery` để khai báo kiểu dữ liệu bạn muốn truy vấn.

```java
CriteriaQuery<Office> query = builder.createQuery(Office.class);
```

3. Tạo đối tượng `Root` để chỉ định đối tượng cơ sở của truy vấn.

```java
Root<Office> root = query.from(Office.class);
```

4. Xây dựng truy vấn bằng cách sử dụng các phương thức của `CriteriaBuilder` và các biểu thức như `equal`, `like`, `and`, `or`, và nhiều phép toán khác.

```java
Predicate condition = builder.equal(root.get("city"), "hanoi");
```

5. Sử dụng truy vấn đã tạo để lấy dữ liệu từ cơ sở dữ liệu.

```java
query.select(root).where(condition);
List<Office> results = em.createQuery(query).getResultList();
```

### Ví dụ về sử dụng Criteria API

Dưới đây là một ví dụ cụ thể về cách sử dụng Criteria API để lấy danh sách các văn phòng (Offices) ở thành phố "hanoi":

```java
@Repository
public class OfficeRepository {

    @PersistenceContext
    private EntityManager em;

    public List<Office> getOfficesInCity(String city) {
        CriteriaBuilder builder = em.getCriteriaBuilder();
        CriteriaQuery<Office> query = builder.createQuery(Office.class);
        Root<Office> root = query.from(Office.class);

        Predicate condition = builder.equal(root.get("city"), city);

        query.select(root).where(condition);

        return em.createQuery(query).getResultList();
    }
}
```

Trong ví dụ này, chúng ta sử dụng `CriteriaBuilder` để tạo truy vấn, `CriteriaQuery` để khai báo loại dữ liệu cần truy vấn (trong trường hợp này là `Office`), và `Root` để xác định đối tượng gốc của truy vấn. Sau đó, chúng ta sử dụng `builder.equal` để so sánh trường "city" với giá trị "hanoi" và sử dụng `query.select(root).where(condition)` để xây dựng truy vấn. Kết quả cuối cùng là danh sách các văn phòng ở thành phố "hanoi".

Sử dụng Criteria API trong Hibernate cho phép bạn xây dựng các truy vấn linh hoạt và dễ dàng tùy chỉnh theo nhu cầu của ứng dụng. Bạn có thể tạo các truy vấn động và theo dõi lỗi một cách dễ dàng hơn. Mặc dù cú pháp có thể phức tạp hơn so với JPQL, nhưng việc sử dụng Criteria API mang lại nhiều lợi ích cho sự phát triển và bảo trì ứng dụng của bạn.

::alert{type="success"}
Trong bài viết này, chúng ta đã tìm hiểu cách sử dụng cơ bản của Criteria API và xây dựng một ví dụ thực tế. Criteria API có nhiều tính năng mạnh mẽ khác để khám phá, bao gồm việc kết hợp nhiều bảng (join) và thêm các điều kiện phức tạp hơn vào các truy vấn.
::
