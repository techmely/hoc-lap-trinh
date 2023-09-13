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

## Dependency Injection là gì

Để hiểu định nghĩa trên, mình có ví dụ sau:

- Mình có 1 ứng dụng gọi tới object của class `MySQLDAO`(class `MySQLDAO` chuyên thực hiện truy vấn với cơ sở dữ liệu MySQL của ứng dụng)
- Bây giờ bạn muốn truy vấn tới cơ sở dữ liệu `postgre`. Bạn phải xóa khai báo `MySQLDAO` trong ứng dụng và thay bằng `PostgreDAO`, sau đó muốn dùng lại MySQLDAO bạn lại làm ngược lại… rõ ràng code sẽ phải sửa lại và test nhiều lần.
- Giải pháp dùng if-else kiểm tra điều kiện sẽ dùng đối tượng `DAO` nào… nhưng sau đấy có thêm một `DAO` khác ví dụ như `MSSQLDAO` chẳng hạn… phức tạp hơn nhiều phải không.

(Thường thì ít khi 1 ứng dụng dùng nhiều loại cơ sở dữ liệu khác nhau nhưng sẽ có trường hợp sử dụng nhiều database, mình để thành nhiều loại cơ sở dữ liệu khác nhau cho dễ hình dung)

Dependency Inject chính là để giải quyết cho trường hợp như thế này.

Trong ví dụ trên ta tạo 1 interface `AbstractDAO` và cho các class DAO kia thừa kế `AbstractDAO`. Bây giờ trong các class sử dụng DAO ta khai báo `AbstractDAO`, tùy theo điều kiện tương ứng `AbstractDAO` có thể là MySQLDAO hoặc `PostgreDAO`.

Việc thay thế `AbstractDAO` bằng `MySQLDAO/PostgreDAO` được gọi là injection.

![Dependency Injection là gì](https://github.com/techmely/hoc-lap-trinh/assets/29374426/1042c183-71f5-4e7b-b71b-ec2ebedcfffc)

## Ví dụ về Dependency Injection

Mình sẽ code demo ví dụ trên:

Tạo một interface để khai báo các method giao tiếp với database:

```java
// Abstract.java
public interface AbstractDAO {
  void insert();
  void delete();
  void update();
}
```

Tạo các class DAO tương ứng với từng loại database và implements các method của AbstractDAO

MySQLDAO.java

```java
// MySQLDAO.java
public class MySQLDAO implements AbstractDAO {
  @Override
  public void insert() {
    System.out.println("MySQL insert");
  }
  @Override
  public void delete() {
    System.out.println("MySQL delete");
  }
  @Override
  public void update() {
    System.out.println("MySQL update");
  }
}
```

```java
// PostgreDAO.java
public class PostgreDAO implements AbstractDAO {
  @Override
  public void insert() {
    System.out.println("Postgre insert");
  }
  @Override
  public void delete() {
    System.out.println("Postgre delete");
  }
  @Override
  public void update() {
    System.out.println("Postgre update");
  }
}
```

```java
// MSSQLDAO.java
public class MSSQLDAO implements AbstractDAO {
  @Override
  public void insert() {
    System.out.println("MSSQL insert");
  }
  @Override
  public void delete() {
    System.out.println("MSSQL delete");
  }
  @Override
  public void update() {
    System.out.println("MSSQL update");
  }
}
```

file `config.properites` lưu thông tin config quyết định sẽ kết nối tới database nào.

```bash
## 1: MySQL | 2: Postgre | 3: MSSQL
database=2
```

Bây giờ ở class cần dùng đến dao ta sẽ khai báo `AbstractDAO`, tùy theo tham số trong file config mà ta khởi tạo đối tượng `AbstractDAO` là `MySQLDAO`, `PostgreDAO` hay `MSSQLDAO`.

```java
public class Client {
  AbstractDAO dao;
  public Client() {
    dao = FactoryDAO.getDAO();
  }
  public AbstractDAO getDao() {
    return dao;
  }
  public void setDao(AbstractDAO dao) {
    this.dao = dao;
  }

  public void execute() {
    dao.insert();
    dao.update();
    dao.delete();
  }
}
```

Như các bạn thấy ở đây mình dùng [Factory Pattern](/bai-viet/java/factory-pattern-trong-java) để quyết định đối tượng được tạo ra. Class FactoryDAO (Factory class) sẽ đọc file và quyết định đối tượng nào được tạo ra.

```java
// FactoryDAO.java
public class FactoryDAO {
  public static AbstractDAO getDAO() {
    Properties prop = new Properties();
    InputStream input = null;
    try {
      input = new FileInputStream("source/config.properties");
      // load a properties file
      prop.load(input);
      // get the database value
      String database = prop.getProperty("database");
      if (database.equals("1")) {
        return new MySQLDAO();
      }
      if (database.equals("2")) {
        return new PostgreDAO();
      }
      if (database.equals("3")) {
        return new MSSQLDAO();
      }
    } catch (IOException ex) {
      ex.printStackTrace();
      return null;
    }
    return null;
  }
}
```

### Demo ví dụ trên

```java
public class MainApp {
  public static void main(String[] args) {
    Client client = new Client();
    client.execute();
  }
}
```

::result

Postgre insert
Postgre update
Postgre delete

::

Sửa giá trị database trong file config.properties bằng 1 và chạy lại

::result

MySQL insert
MySQL update
MySQL delete

::

Bây giờ nếu bạn có thêm 1 loại database khác cần sử dụng thì chỉ cần tạo DAO cho nó, implements `AbstractDAO` và sửa lại `FactoryDAO` là được.

Ví dụ mình có thêm database `DB2`.

mình sẽ tạo class `DB2DAO.java` implements `AbstractDAO`.

trong method `getDAO()` của `FactoryDAO` thêm điều kiện nếu `database = 4` thì sẽ trả về `DB2DAO`.

rõ ràng cách làm này giúp ta sẽ mở rộng ứng dụng hơn rất nhiều và mỗi lần thay đổi đối tượng dao ta không cần phải khởi động/deploy lại ứng dụng mà chỉ cần thay đổi thông tin trong file `config.properties`.

Việc lấy thông tin từ file `config.properites` rồi quyết định tạo đối tượng trong class `Client.java` chính là tiêm sự phụ thuộc (Dependency Injection – DI)

## Các phương pháp thực hiện Dependency Injection

Các phương pháp cơ bản để Dependency Injection.

- **Constructor Injection**: Các dependency sẽ được truyền vào (inject vào) 1 class thông qua constructor của class đó. Đây là cách thông dụng nhất. (ví dụ trên mình dùng theo cách này)
- **Setter Injection**: Các dependency sẽ được truyền vào 1 class thông qua các hàm **Setter/Getter**
  Ví dụ ở trên mình sẽ sửa method getDao ở class `Client.java` thành

```java
public AbstractDAO getDao() {
  dao = FactoryDAO.getDAO();
  return dao;
}
```

- **Public fields**: Các dependency sẽ được truyền vào 1 class một cách trực tiếp vào các public field. Cách này ít được sử dụng nhất. Ví dụ ở trên khi khai báo `AbstractDAO` ở class `Client.java` thành

```java
AbstractDAO dao = FactoryDAO.getDAO();
```

## Ưu nhược điểm của Dependency Injection

### Ưu điểm

- Giảm sự kết dính giữa các module
- Code dễ bảo trì, dễ thay thế module
- Rất dễ test và viết Unit Test
- Dễ dàng thấy quan hệ giữa các module (Vì các dependecy đều được inject vào constructor)

### Nhược điểm

- Khái niệm DI hơi khó hiểu với người mới
- Khó debug vì không biết implements nào của interface được gọi đến
- Các object được khởi tạo từ đầu làm giảm performance
- Làm tăng độ phức tạp của code

Do đó với những ứng dụng nhỏ gọn, làm ăn luôn thì ko nên áp dụng DI, còn những ứng dụng cần sự linh hoạt, mở rộng, maintain thì sử dụng DI.

## Một số khái niệm khác

### DI Container

- DI Container là chỉ những thành phần tạo và quản lý module/object con được Inject, ví dụ ở trên là `FactoryDAO`.
- Hiện tại có rất nhiều Framework và các thư viện hỗ trợ làm DI như CDI, Spring DI, JSF…

### Inversion of Control

- Inversion of Control dịch là đảo ngược điều khiển (hơi khó hiểu)
- Ý của nó là làm thay đổi luồng điều khiển của ứng dụng. ví dụ như ở trên việc thay đổi thông tin trong file config.properties đã làm thay đổi luồng chạy của ứng dụng.
