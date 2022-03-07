---
title: "Xử lý ngoại lệ (Exception) trong Java"
description: "Exception là một tình trạng bất thường. Một exception (ngoại lệ) trong Java là một vấn đề xảy ra trong quá trình thực hiện của chương trình mà phá vỡ luồng chuẩn của chương trình."
keywords:
  [
    "bai tap ve exception trong java",
    "chained exception trong java",
    "checked exception trong java",
    "checked và unchecked exception trong java",
    "các exception trong java",
    "các loại exception trong java",
    "dinh nghia exception trong java",
    "error vs exception trong java",
    "exception handling trong java",
    "exception trong java",
  ]
chapter:
  name: "Xử lý ngoại lệ"
  slug: "chuong-05-xu-ly-ngoai-le"
category:
  logo: "/language/java.png"
  name: "Java"
  slug: "java"
  description: "Học Java từ cơ bản đến thông thạo cho mọi đối tượng"
image: https://user-images.githubusercontent.com/29374426/142722429-d5b4a38c-448a-4aed-994b-52e06755bfea.png
position: 1
---

**Exception** là một tình trạng bất thường. Một exception (ngoại lệ) trong Java là một vấn đề xảy ra trong quá trình thực hiện của chương trình mà phá vỡ luồng chuẩn của chương trình.

## Exception trong Java là gì

Mô hình sử lý ngoại lệ của java dựa trên ba hoạt động chính: **đặc tả ngoại lệ**, **ném ra ngoại lệ**, và **bắt ngoại lệ**. Mỗi phương thức đều có thể phát sinh các ngoại lệ, các ngoại lệ có thể phát sinh cần được mô tả chi tiết trong lệnh khai báo của phương thức, việc khai báo này đựơc gọi là đặc tả ngoại lệ.

Khi một câu lệnh trong phương thức gây lỗi, mà người lập trình không cung cấp mã xử lý lỗi, thì ngoại lệ được chuyển đến phương thức gọi phương thức đó, việc này được gọi là ném ra biệt lệ, ta có thể ném ra biệt lệ một cách tường minh (điều này sẽ được giới thiếu sau).

Đối với người lập trình họ có thể gặp một trong các lỗi sau:

- Lỗi cú pháp (syntac error)
- Lỗi logic thuật toán
- Lỗi lúc thực thi ( runtime error)

Đối với lỗi cú pháp người lập trình có thể phát hiện và sửa lỗi, dựa vào trình biên dịch, đây là lỗi dễ phát hiện và sửa chữa, tuy nhiêmn đây cũng là lỗi gây khó khăn và chán nản đối với người mới học lập trình.

Đối với lỗi thuật toán, đây là lỗi khó phát hiện và sửa chữa nhất, tuy nhiên trong bài này ta không bàn luận về vấn đề này.

Đối với lỗi lúc thực thi, ta hoàn toàn có thể kiểm soát được chúng, thông thường lỗi runtime thường do nguyên nhân khách quan như: truy cập vào một ổ đĩa nhưng ổ đĩa này lại chưa sẵn sàng, hay thực hiện phép chia nhưng mẫu số lại bằng 0, kết nối với máy tính ở xa nhưng máy đó lại không tồn tại…, khi một lỗi runtime xẩy ra JVM sẽ phát sinh một ngoại lệ, nếu một chương trình không cung cấp mã sử lý ngoại lệ có thể kết thúc không bình thường, trong bài hôm nay ta sẽ bàn về vấn đề sử lý ngoại lệ trong java.

Ví dụ:

- Người dùng nhập dữ liệu không hợp lệ.
- Một file cần được mở nhưng không thể tìm thấy.
- Kết nối mạng bị ngắt trong quá trình thực hiện giao tiếp hoặc JVM hết bộ nhớ.

Để hiểu về cách xử lý ngoại lệ trong Java, bạn cần phải hiểu những loại ngoại lệ như sau:

### Checked Exception

Checked Exception là ngoại lệ thường xảy ra do người dùng mà không thể lường trước được bởi lập trình viên. Ví dụ, một file được mở, nhưng file đó không thể tìm thấy và ngoại lệ xảy ra. Những ngoại lệ này không thể được bỏ qua trong quá trình biên dịch. Checked Exception là các lớp mà kế thừa lớp Throwable ngoại trừ RuntimeException và Error. Ví dụ như `IOException`, `SQLException`, … Checked Exception được kiểm tra tại thời gian biên dịch compile-time.

![Checked Exception](https://user-images.githubusercontent.com/29374426/142722429-d5b4a38c-448a-4aed-994b-52e06755bfea.png)

### Unchecked Exception

Unchecked Exception một ngoại lệ xảy ra ở runtime là ngoại lệ có thể tránh được bởi lập trình viên. Unchecked Exception là các lớp kế thừa `RuntimeException`, ví dụ `ArithmaticException`, `NullPointerException`, `ArrayIndexOutOfBoundsException`, … Unchecked Exception không được kiểm tra tại compile-time, thay vào đó chúng được kiểm tra tại runtime.

![Unchecked Exception](https://user-images.githubusercontent.com/29374426/142722434-f651efed-8d61-4a19-a785-63cf29d23e34.png)

### Error

Nó không giống các exception, nhưng vấn đề xảy ra vượt quá tầm kiểm soát của lập trình viên hay người dùng. Error được bỏ qua trong code của bạn vì bạn hiếm khi có thể làm gì đó khi chương trình bị error. Ví dụ như `OutOfMemoryError`, `VirtualMachineError`, `AssertionError`,… Nó được bỏ qua trong quá trình Java biên dịch.

Giả sử có 10 lệnh trong chương trình của bạn và xuất hiện một Exception tại lệnh 5, phần còn lại của code sẽ không được thực thi (từ lệnh 6 tới lệnh 10). Nếu chúng ta thực hiện Exception Handling, phần lệnh còn lại sẽ được thực thi. Đó là ý nghĩa của việc sử dụng Exception Handling trong Java.

```java
statement 1;
statement 2;
statement 3;
statement 4;
statement 5; // xuất hiện exception
statement 6;
statement 7;
statement 8;
statement 9;
statement 10;
```

## Hệ thống cấp bậc của các lớp ngoại lệ trong Java

Tất cả các lớp exception đều là lớp con của lớp `java.lang.Exception`. Lớp exception là lớp con của lớp Throwable. Một loại lớp exception khác là `Error` cũng là lớp con của lớp `Throwable`.

![Hệ thống cấp bậc của các lớp ngoại lệ trong Java](https://user-images.githubusercontent.com/29374426/142722321-fc300efc-3618-44d7-8334-0ee0ad988471.png)

Erros không thường được đặt bẫy bởi các chương trình Java. Error thường được tạo ra để thể hiện lỗi trong môi trường runtime. Ví dụ: JVM hết bộ nhớ. Thông thường các chương trình không thể khôi phục từ các lỗi.

## Các kiểu ngoại lệ phổ biến

| Phương thức | Miêu tả |
| --- | --- |
| IOException | Trả về một message cụ thể về exception đã xảy ra. Message này được khởi tạo bởi phương thức contructor của Throwable |
| SQLException | Ngoại lệ liên quan đến cú pháp SQL |
| DataAccessException | Ngoại lệ liên quan đến việc truy cập CSDL |
| ClassNotFoundException | Bị ném khi JVM không thể tìm thấy một lớp mà nó cần, do lỗi dòng lệnh, sự cố đường dẫn hoặc tệp, class bị thiếu... |
| InstantiationException | Ngoại lệ khi cố gắng tạo đối tượng của một abstract class hoặc interface |
| NullPointerException | Ngoại lệ bị ném ra khi cố gắng truy cập một đối tượng có biến tham chiếu có giá trị hiện tại là null |
| ArrayIndexOutOfBound | Ngoại lệ khi cố gắng truy cập một phần tử vượt quá độ dài của mảng |
| IllegalArgumentException | Ngoại lệ bị ném ra khi một phương thức nhận được một đối số được định dạng khác với phương thức mong đợi. |
| IllegalStateException | Ngoại lệ bị ném ra khi trạng thái của môi trường không phù hợp với hoạt động cố gắng thực hiện, ví dụ: Sử dụng Scanner đã bị đóng. |
| NumberFormatException | Ngoại lệ bị ném khi một phương thức chuyển đổi một Chuỗi thành số nhưng không thể chuyển đổi. |
| ArithmeticException | Lỗi số học, chẳng hạn như chia cho 0. |
