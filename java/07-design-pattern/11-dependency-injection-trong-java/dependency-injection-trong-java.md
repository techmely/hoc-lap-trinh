---
title: "Dependency Injection trong Java"
description: "Dependency Injection (DI) là một kỹ thuật hoặc một design pattern trong lập trình, giúp quản lý các phụ thuộc (dependencies) trong một ứng dụng một cách linh hoạt và dễ quản lý. "
chapter:
  name: "Design Pattern"
  slug: "chuong-07-design-pattern"
category:
  name: "Java"
  slug: "java"
image: https://user-images.githubusercontent.com/29374426/146175674-fa7e09f7-4e42-485e-a2b5-8c664601b203.png
position: 11
---

**Dependency Injection (DI)** là một kỹ thuật và một mô hình thiết kế trong lập trình phần mềm. Nó giúp quản lý và giảm bớt sự phụ thuộc giữa các thành phần của ứng dụng, làm cho ứng dụng dễ dàng mở rộng, bảo trì và thay đổi.

Để hiểu định nghĩa trên, mình có ví dụ sau:

- Mình có 1 ứng dụng gọi tới object của class `MySQLDAO`(class `MySQLDAO` chuyên thực hiện truy vấn với cơ sở dữ liệu MySQL của ứng dụng)
- Bây giờ bạn muốn truy vấn tới cơ sở dữ liệu `postgre`. Bạn phải xóa khai báo `MySQLDAO` trong ứng dụng và thay bằng `PostgreDAO`, sau đó muốn dùng lại MySQLDAO bạn lại làm ngược lại… rõ ràng code sẽ phải sửa lại và test nhiều lần.
- Giải pháp dùng if-else kiểm tra điều kiện sẽ dùng đối tượng `DAO` nào… nhưng sau đấy có thêm một `DAO` khác ví dụ như `MSSQLDAO` chẳng hạn… phức tạp hơn nhiều phải không.

(Thường thì ít khi 1 ứng dụng dùng nhiều loại cơ sở dữ liệu khác nhau nhưng sẽ có trường hợp sử dụng nhiều database, mình để thành nhiều loại cơ sở dữ liệu khác nhau cho dễ hình dung)

Dependency Inject chính là để giải quyết cho trường hợp như thế này.

Trong ví dụ trên ta tạo 1 interface `AbstractDAO` và cho các class DAO kia thừa kế `AbstractDAO`. Bây giờ trong các class sử dụng DAO ta khai báo `AbstractDAO`, tùy theo điều kiện tương ứng `AbstractDAO` có thể là MySQLDAO hoặc `PostgreDAO`.

Việc thay thế `AbstractDAO` bằng `MySQLDAO/PostgreDAO` được gọi là injection.

### Ví dụ về Dependency Injection

1. Đầu tiên, bạn tạo một giao diện (interface) gọi là `DAO`:

```java
public interface DAO {
    void saveData();
}
```

2. Sau đó, bạn tạo hai lớp cụ thể `MySQLDAO` và `PostgreSQLDAO` để thực hiện giao diện này:

```java
public class MySQLDAO implements DAO {
    @Override
    public void saveData() {
        System.out.println("Data saved using MySQL.");
    }
}

public class PostgreSQLDAO implements DAO {
    @Override
    public void saveData() {
        System.out.println("Data saved using PostgreSQL.");
    }
}
```

3. Bây giờ, bạn tạo một lớp `Service`:

```java
public class Service {
    private DAO dao;

    // Constructor Injection
    public Service(DAO dao) {
        this.dao = dao;
    }

    public void performSave() {
        dao.saveData();
    }
}
```

Lúc này, bạn đã áp dụng Dependency Injection thông qua việc truyền đối tượng `DAO` vào qua constructor của `Service`.

4. Cuối cùng, bạn có thể sử dụng ứng dụng của mình như sau:

```java
public class MainApp {
    public static void main(String[] args) {
        DAO mysqlDao = new MySQLDAO();
        Service mysqlService = new Service(mysqlDao);
        mysqlService.performSave();

        DAO postgresDao = new PostgreSQLDAO();
        Service postgresService = new Service(postgresDao);
        postgresService.performSave();
    }
}
```

Kết quả sẽ là:

<content-result>
Data saved using MySQL.
Data saved using PostgreSQL.
</content-result>

Bằng cách này, bạn có thể thay đổi `DAO` mà `Service` sử dụng chỉ bằng cách thay đổi constructor mà không cần sửa mã nguồn của `Service`. Điều này làm cho ứng dụng dễ mở rộng và bảo trì hơn.
