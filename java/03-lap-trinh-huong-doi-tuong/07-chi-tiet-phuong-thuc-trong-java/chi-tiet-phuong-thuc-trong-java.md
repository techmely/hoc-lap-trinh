---
title: "Chi tiết phương thức trong Java"
description: "Một phương thức là một tập hợp các khối lệnh (code) để thi hành một chức năng nào đó. Bài này chúng ta cùng nhau tìm hiểu kỹ hơn về các thành phần có trong một phương thức trong Java nhé."
chapter:
  name: "Lập trình hướng đối tượng"
  slug: "chuong-03-lap-trinh-huong-doi-tuong"
category:
  name: "Java"
  slug: "java"
image: https://user-images.githubusercontent.com/29374426/131202396-f4ab4d7f-60a6-45b4-8f32-9e8ef7fdc63f.png
position: 7
---

Một phương thức là một tập hợp các khối lệnh (code) để thi hành một chức năng nào đó. Bài này chúng ta cùng nhau tìm hiểu kỹ hơn về các thành phần có trong một phương thức trong Java nhé.

![Chi tiết phương thức trong Java](https://user-images.githubusercontent.com/29374426/131202396-f4ab4d7f-60a6-45b4-8f32-9e8ef7fdc63f.png)

## Các thành phần trong phương thức

| Thành phần                             | Mô tả                                                   |
| -------------------------------------- | :------------------------------------------------------ |
| Access Specifier (hay Access Modifier) | mô tả mức độ truy cập đến phương thức                   |
| static                                 | đây là phương thức lớp                                  |
| abstract                               | đây là phương thức không có cài đặt                     |
| final                                  | phương thức này không thể ghi đè                        |
| native                                 | phương thức này được viết trong một ngôn ngữ khác       |
| synchronized                           | đây là phương thức đồng bộ                              |
| returnType                             | giá trị trả về của phương thức                          |
| MethodName                             | tên của phương thức                                     |
| throws exception                       | khai báo các ngoại lệ có thể được nem ra từ phương thức |

_Trong đó:_

- **accessLevel** có thể là một trong các từ khoá `public`, `private`, `protected` hoặc bỏ trống, ý nghĩa của nó thể hiện [cấp độ truy cập trong java](/bai-viet/java/cap-do-truy-cap-trong-java).
- **static** là từ khoá báo cho java biết đây là một [phương thức tĩnh](/bai-viet/java/phuong-thuc-tinh-trong-java).
- **abstract** từ khoá cho biết đây là một [lớp trừu tượng](/bai-viet/java/lop-truu-tuong-trong-java), nó không có cài đặt.
- **final** đây là từ khoá báo cho java biết đây là [phương thức không thể ghi đè từ lớp con](/bai-viet/java/tu-khoa-final-trong-java)
- **native** đây là từ khoá báo cho java biết phương thức này được viết bằng một ngôn ngữ lập trình nào đó không phải là java ( thường được viết bằng C/C++)
- **synchronized** đây là một phương thức đồng bộ, nó rất hữu ích khi nhiều phương thức cùng truy cập đồng thời vào tài nguyên miền găng
- **returnType** là một kiểu dữ liệu, đây là kiểu trả về của phương thức, khi phương thức không trả về dữ liệu thì phải dùng từ khoá void
- **MethodName** là tên của phương thức, tên của phương thức được đặt theo quy tắc đặt tên của java
- **throws** là từ khoá dùng để khai báo các ngoại lệ có thể được ném ra từ phương thức, theo sau từ khoá này là danh sách các ngoại lệ có thể được phương thức này ném ra

_Chú ý:_

- Nếu trong lớp có ít nhất một phương thức trừu tượng thì lớp đó phải là lớp trừu tượng
- Không có thuộc tính trừu tượng
- Ta không thể tạo đối tượng của lớp trừu tượng
- Khác với ngôn ngữ C/C++, java bắt buộc bạn phải khai báo giá trị trả về cho phương thức, nếu phương thức không trả về dữ liệu thi dùng từ khoá void (trong C/C++ khi ta không khai báo giá trị trả về thì mặc định giá trị trả về là int)

## Nhận giá trị trả về từ phương thức

Ta khai báo kiểu giá trị trả về từ lúc ta khai báo phương thức, bên trong thân của phương thức ta phải sử dụng phát biểu return value; để nhận về kết quả, nếu hàm được khai báo kiểu void thì ta chỉ sử dụng phát biểu return; mệnh đề return đôi khi còn được dùng để kết thúc một phương thức

## Truyền tham số cho phương thức

Khi ta viết các phương thức, một số phương thức yêu cầu phải có một số tham số, các tham số của một phương thức được khai báo trong lời khai báo phương thức, chúng phải được khai báo chi tiết có bao nhiêu tham số, mỗi tham số cần phải cung cấp cho chúng một cái tên và kiểu dữ liệu của chúng.

Ví dụ: ta có một phương thức dùng để tính tổng của hai số, phương thức này được khai báo như sau:

```java
public double tongHaiSo(double a, double b){
  return (a + b);
}
```

### Kiểu tham số

Trong java ta có thể truyền vào phương thức một tham số có kiểu bất kỳ, từ kiểu dữ liệu nguyên thuỷ cho đến tham chiếu đối tượng.

### Tên tham số

Khi bạn khai báo một tham số để truyền vào phương thức thì bạn phải cung cấp cho nó một cái tên, tên nay được sử dụng bên trong thân của phương thức để tham chiếu đến tham số được truyền vào.

**Chú ý:** tên của tham số có thể trùng với tên của thuộc tính, khi đó tên của tham số sẽ “che” đi tên của phương thức, bởi vậy bên trong thân của phương thức mà có tham số có tên trùng với tên của thuộc tính, thì khi nhắc đến cái tên đó có nghĩa là nhắc đến tham số

### Truyền tham số theo trị

Khi gọi một phương thức mà tham số của phương thức có kiểu nguyên thuỷ, thì bản sao giá trị của tham số thực sự sẽ được chuyển đến phương thức, đây là đặc tính truyền theo trị ( pass- by – value ), nghĩa là phương thức không thể thay đổi giá trị của các tham số truyền vào.

Ta kiểm tra điều này qua ví dụ sau:

```java
public class TestPassByValue {
  public static void test(int t) {
    t++;
    System.out.println("Gia tri của t bi?n trong ham sau khi tang len 1 la " + t);
  }

  public static void main(String[] args) {
    int t = 10;
    System.out.println("Gia tri của t tru?c khi gọi ham = " + t);
    test(t);
    System.out.println("Gia tri của t truoc khi gọi ham = " + t);
  }
}
```

Ta sẽ nhận được kết quả ra như sau:

<content-result>
    <code>Gia tri của t truoc khi gọi ham = 10</code><br/>
    <code>Gia tri của t bên trong ham sau khi tang len 1 la 11 Gia tri của t truoc khi gọi ham = 10</code>
</content-result>

## Thân của phương thức

Trong ví dụ sau thân của phương thức isEmpty và phương thức pop được in đậm và có mầu đỏ

```java
class Stack {
  static final int STACK_EMPTY = -1; Object[] stackelements;
  int topelement = STACK_EMPTY;
  ...
  boolean isEmpty() {
    if (topelement == STACK_EMPTY) return true;
    else return false;
  }
  Object pop() {
    if (topelement == STACK_EMPTY) return null;
    else {
      return stackelements[topelement--];
    }
  }
}
```
