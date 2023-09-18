---
title: "Lớp Object trong Java"
description: "Lớp object là lớp cơ sở nhất, định nghĩa hầu như tất cả những phương thức phần cơ bản để các lớp con cháu của nó sử dụng trực tiếp hoặc viết đè"
chapter:
  name: "Lập trình hướng đối tượng"
  slug: "chuong-03-lap-trinh-huong-doi-tuong"
category:
  name: "Java"
  slug: "java"
image: https://user-images.githubusercontent.com/29374426/131332846-f14a1cc6-dca3-40a8-a0ae-003a31abdae1.png
position: 18
---

Lập trình hướng đối tượng (OOP) là một trong những khái niệm quan trọng nhất trong ngôn ngữ lập trình Java, và tất cả các đối tượng trong Java đều được xây dựng dựa trên lớp gốc "Object." Trong bài viết này, chúng ta sẽ tìm hiểu về lớp "Object" và các phương thức quan trọng của nó.

## Lớp Object - Cơ Sở của Tất Cả

Lớp "Object" là lớp cơ sở nhất trong Java. Tất cả các lớp khác, cả những lớp do bạn tự định nghĩa, đều trực tiếp hoặc gián tiếp kế thừa từ lớp "Object." Điều này có nghĩa rằng mọi đối tượng Java cuối cùng đều là một thể hiện của lớp "Object."

![Lớp Object là lớp cơ sở của tất cả các đối tượng trong Java](https://user-images.githubusercontent.com/29374426/131332846-f14a1cc6-dca3-40a8-a0ae-003a31abdae1.png)

## Các Phương Thức Quan Trọng Của Lớp Object

Lớp "Object" cung cấp một số phương thức quan trọng mà bạn có thể sử dụng hoặc viết đè trong lớp của bạn để tuân theo các quy tắc cơ bản của OOP. Dưới đây là một số phương thức quan trọng của lớp "Object":

### 1. `getClass()`

Phương thức này trả về tên lớp của đối tượng hiện tại. Nó cho phép bạn biết được lớp mà một đối tượng thuộc về.

### 2. `hashCode()`

Phương thức này trả về một số hash code cho đối tượng hiện tại. Số hash code này có thể được sử dụng để xác định đối tượng trong các tình huống như khi lưu trữ trong bảng băm (hash table).

### 3. `equals(Object obj)`

Phương thức này so sánh đối tượng hiện tại với một đối tượng khác. Nó trả về `true` nếu cả hai đối tượng là cùng một, và `false` nếu không.

### 4. `clone()`

Phương thức này tạo ra một bản sao mới của đối tượng hiện tại. Điều này giúp bạn tạo một bản copy của đối tượng mà không ảnh hưởng đến đối tượng gốc.

### 5. `toString()`

Phương thức này trả về một chuỗi biểu diễn của đối tượng. Thường được sử dụng để biểu diễn đối tượng dưới dạng chuỗi văn bản.

### 6. `finalize()`

Phương thức này được gọi trước khi đối tượng bị thu gom (garbage collected). Nó cho phép bạn thực hiện các tác vụ dọn dẹp hoặc giải phóng tài nguyên trước khi đối tượng bị huỷ bỏ.

### 7. `notify()` và `notifyAll()`

Các phương thức này được sử dụng trong ngữ cảnh đa luồng (multithreading) để thông báo cho các luồng đang chờ về sự kiện xảy ra trên đối tượng.

### 8. `wait()`, `wait(long timeout)`, và `wait(long timeout, int nanos)`

Các phương thức này được sử dụng để làm cho luồng hiện tại đợi trong một khoảng thời gian cụ thể cho đến khi một luồng khác thông báo hoặc cho đến khi thời gian chờ kết thúc.

## Tổng hợp phương thức của lớp Object

| Phương thức                                                                 | Mô tả                                                                                                                                                                                                                                                |
| --------------------------------------------------------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| `public final Class getClass()`                                             | Trả lại tên lớp của đối tượng hiện thời                                                                                                                                                                                                              |
| `public int hashCode()`                                                     | Trả về số hashcode cho đối tượng hiện tại. Khi các đối tượng được lưu vào các bảng băm (hash table), hàm này có thể sử dụng để xác định duy nhất giá trị cho mỗi đối tượng. Điều này đảm bảo tính nhất quán của hệ thống khi thực hiện chương trình. |
| `public boolean equals(Object obj)`                                         | Cho lại kết quả true khi đối tượng hiện thời và obj là cùng một đối tượng. Hàm này thường được viết đè ở các lớp con cho phù hợp với ngữ cảnh so sánh bằng nhau trong các lớp mở rộng đó                                                             |
| `protected Object clone() throws CloneNotSupportedException`                | Đối tượng mới được tạo ra có cùng các trạng thái như đối tượng hiện thời khi sử dụng clone(), nghĩa là tạo ra bản copy mới của đối tượng hiện thời                                                                                                   |
| `public String toString()`                                                  | Nếu các lớp con không viết đè hàm này thì nó sẽ trả lại dạng biểu diễn văn bản (textual) của đối tượng. Hàm println() ở lớp PrintStream sẽ chuyển các đối số của nó sang dạng văn bản khi sử dụng hàm toString()                                     |
| `protected void finalize() throws Throwable`                                | Hàm này được gọi ngay trước khi đối tượng bị dọn vào “thùng rác”, nghĩa là trước khi đối tượng đó bị huỷ bỏ.                                                                                                                                         |
| `public final void notify()`                                                | Đánh thức một luồng, đợi trình giám sát của đối tượng hiện tại                                                                                                                                                                                       |
| `public final void notifyAll()`                                             | đánh thức tất cả các luồng. đợi trình giám sát của đối tượng hiện tại                                                                                                                                                                                |
| `public final void wait(long timeout)throws InterruptedException`           | Làm cho Thread hiện tại đợi trong khoảng thời gian là số mili giây cụ thể, tới khi Thread khác thông báo (gọi phương thức notify() hoặc notifyAll()).                                                                                                |
| `public final void wait(long timeout,int nanos)throws InterruptedException` | làm cho Thread hiện tại đợi trong khoảng thời gian là số mili giây và nano giây cụ thể, tới khi Thread khác thông báo (gọi phương thức notify() hoặc notifyAll()).                                                                                   |
| `public final void wait()throws InterruptedException`                       | làm Thread hiện tại đợi, tới khi Thread khác thông báo (gọi phương thức `notify()` hoặc `notifyAll()`).                                                                                                                                              |
