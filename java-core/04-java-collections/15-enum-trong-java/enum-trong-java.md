---
title: "Enum trong Java"
description: "Enum là một từ khóa trong Java, là một kiểu dữ liệu đặc biệt được sử dụng để đại diện cho hằng số cố định. Một enum có thể chứa các trường, phương thức và constructor. Bởi vì các giá trị của `Enum` là các hằng số, nên tên của các trường kiểu enum thường là các chữ cái hoa"
keywords:
  [
    "Enum trong Java",
    "Khai báo Enum trong Java",
    "Duyệt các phần tử trong enum",
    "So sánh các phần tử enum trong java",
    "Enum sử dụng trong switch case",
    "class enum trong java",
    "cách sử dụng enum trong java",
    "enum constructor trong java",
    "enum là gì",
    "enum là gì java",
  ]
chapter:
  name: "Java collections"
  slug: "chuong-04-java-collections"
category:
  name: "Java"
  slug: "java"
image: https://user-images.githubusercontent.com/29374426/145763981-728dcb20-8cf1-417b-9f3a-45585e48a366.png
position: 15
---

## Enum trong Java là gì?

`Enum` là một từ khóa trong Java, là một kiểu dữ liệu đặc biệt được sử dụng để đại diện cho hằng số cố định. Một enum có thể chứa các trường, `phương thức` và `constructor`. Bởi vì các giá trị của `Enum` là các hằng số, nên tên của các trường kiểu `enum` thường là các chữ cái hoa.

![Enum trong Java](https://user-images.githubusercontent.com/29374426/145763981-728dcb20-8cf1-417b-9f3a-45585e48a366.png)

Giả sử chúng ta tạo ra một đối tượng trong đó có thuộc tính giới tính có giá trị là **nam**, **nữ**, **khác**. Trong trường hợp này Java hỗ trợ ta có thể tạo ra một kiểu là Enum, ví dụ như đối với bài toán trên ta có thể tạo ra giới tính là các số nguyên với **giá trị 1 là nam, -1 là nữ, 0 là khác!**

```java
public class Person {
  // ...
  // 1: nam, -1 nu, 0 khac
  int gender;
}
```

Nhìn vào `Person` có vẽ khá rõ nghĩa. Giả sử mình là một dev mới vào, được giao nhiệm vụ implement một `class` mới tên là `statistic` trong đó có hàm `checkAndShowGender`(Person person), hàm này sẽ nhận `Person` và kiểm tra in ra màn hình giới tính của `person` truyền vào. Và mình chưa hề đụng đến `class Person`.

```java
public class Statistic {
    public void checkGenderAndShow(Person person) {
        if (person.gender == 1) {
            // what is gender?
        }
    }
}
```

Tại sao `gender` lại là số nguyên? rồi giá trị `1` ứng với gì? Lúc này các bạn phải đi thẳng vào `class Person` mà coi thôi. Rõ ràng, nếu làm như vậy thì sẽ khiến cho code trở nên khó đọc hơn rất nhiều phải không!

Vậy thì Java đã giải quyết vấn đề trên với enum cho phép chúng ra định nghĩa một tập các hằng số. Mỗi hằng số này sẽ đại diện cho một giá trị nhất định. Điểm tuyệt vời ở đây là những hằng số có tên rõ ràng, đọc vào là hiểu ngay ý nghĩa của nó.

Để định nghĩa một `enum` trong java chúng ta làm như sau:

```java
public enum Gender {
    MALE,
    FEMALE,
    OHTER
}
```

## Khai báo Enum trong Java

<div class="example">enum định nghĩa bên trong một lớp</div>

```java
public class EnumExample {
    enum WeekDay {
        MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY;
    }

    public static void main(String[] args) {
        WeekDay d = WeekDay.MONDAY;
            System.out.println(d);
    }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>MONDAY</code>
  </div>
</div>

<div class="example">enum định nghĩa bên ngoài một lớp</div>

```java
enum WeekDay { // Không được khai báo access modifier (sử dụng default)
    MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY;
}

public class EnumExample {
    public static void main(String[] args) {
        WeekDay d = WeekDay.MONDAY;
            System.out.println(d);
    }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>MONDAY</code>
  </div>
</div>

## Duyệt các phần tử trong enum

Chúng ta có thể duyệt trên tất cả các phần tử của Enum, thông qua method `values()`. Trình biên dịch trong java tự động thêm phương thức `values()` vào enum khi nó được biên dịch. Phương thức `values()` trả về một mảng chứa tất cả các giá trị của enum.

<content-example />

```java
public class EnumExample {
    enum WeekDay {
        MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY;
    }

    public static void main(String[] args) {
        for (WeekDay d : WeekDay.values()) {
            System.out.println(d);
        }

    }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>MONDAY</code><br/>
    <code>TUESDAY</code><br/>
    <code>WEDNESDAY</code><br/>
    <code>THURSDAY</code><br/>
    <code>FRIDAY</code><br/>
    <code>SATURDAY</code><br/>
    <code>SUNDAY</code>
  </div>
</div>

## Khởi tạo giá trị đặc biệt cho hằng số enum

Các hằng số enum có giá trị ban đầu bắt đầu từ `0, 1, 2, 3, …` Nhưng chúng ta có thể khởi tạo giá trị cụ thể cho các hằng số enum bằng cách định nghĩa các trường và các `Constructor`. Như đã giới thiệu, Enum có thể có các trường, phương thức và `Constructor`.

`Constructor` của enum trong java là `private`. Khi bạn không khai báo là `private` thì trình biên dịch sẽ tạo ra `constructor private` không có tham số. Các phần tử trong enum luôn là `static final`. Có thể viết một `static method` trong enum.

<content-example />

```java
public class EnumExample3 {
    enum WeekDay {
        // Khởi tạo các phần tử từ construnctor
        // Các phần tử này luôn là static final
        MONDAY(2), TUESDAY(3), WEDNESDAY(4), THURSDAY(5), FRIDAY(7), SATURDAY(7), SUNDAY(1);

        private int value;

        // constructor này chỉ dùng trong nội bộ Enum
        // Modifier của constructor enum luôn là private
        // Nếu không khai báo private, java cũng sẽ hiểu là private.
        WeekDay(int value) {
            this.value = value;
        }

        // Có thể viết một static method lấy ra WeekDay theo value.
        public static WeekDay getWeekDayByValue(int value) {
            for (WeekDay d : WeekDay.values()) {
                if (d.value == value) {
                    return d;
                }
            }
            return null;
        }
    }

    public static void main(String[] args) {
        for (WeekDay d : WeekDay.values()) {
            System.out.println(d + " = " + d.value);
        }

        // Sử dụng static method của enum
        WeekDay d = WeekDay.getWeekDayByValue(3);
        System.out.println("value 3 is " + d);
    }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>MONDAY = 2</code><br/>
    <code>TUESDAY = 3</code><br/>
    <code>WEDNESDAY = 4</code><br/>
    <code>THURSDAY = 5</code><br/>
    <code>FRIDAY = 7</code><br/>
    <code>SATURDAY = 7</code><br/>
    <code>SUNDAY = 1</code><br/>
    <code>value 3 is TUESDAY</code><br/>
  </div>
</div>

## So sánh các phần tử enum trong Java

Enum là một đối tượng tham chiếu giống như class, [interface](/bai-viet/java/interface-trong-java) nhưng nó cũng có thể sử dụng toán tử `==` hoặc `equals()` để so sánh các phần tử enum.

<content-example />

```java
public class EnumExample {
    enum WeekDay {
        MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY;
    }

    public static void main(String[] args) {
        WeekDay today = WeekDay.SUNDAY;

        // use equal() method
        if (today.equals(WeekDay.SUNDAY)) {
            System.out.println("Today is holiday");
        } else {
            System.out.println("Today is working day");
        }

        // use == operator
        if (today == WeekDay.SUNDAY) {
            System.out.println("Today is holiday");
        } else {
            System.out.println("Today is working day");
        }
    }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>Today is holiday</code><br/>
    <code>Today is holiday</code>
  </div>
</div>

## Enum sử dụng trong switch case

Cũng giống với các kiểu dữ liệu nguyên thủy (int,float,..) Enum có thể sử dụng như một tham số trong câu lệnh `switch case`.

<content-example />

```java
public class EnumExample {
    enum WeekDay {
        MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY;
    }

    public static void main(String[] args) {
        WeekDay today = WeekDay.SUNDAY;

        switch (today) {
        case MONDAY:
            System.out.println("Today is working day");
            break;
        case SATURDAY:
        case SUNDAY:
            System.out.println("Today is holiday");
            break;
        default:
            System.out.println(today);
        }
    }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>Today is holiday</code>
  </div>
</div>

## Ghi đè phương thức trong Enum

Do enum cũng là một kiểu dữ liệu được kết thừa từ lớp `Object`, nên chúng ta có thể ghi đè method `toString()` của lớp `Object`.

<content-example />

```java
public class EnumExample3 {
    enum WeekDay {
        MONDAY(2), TUESDAY(3), WEDNESDAY(4), THURSDAY(5), FRIDAY(7), SATURDAY(7), SUNDAY(1);

        private int value;

        WeekDay(int value) {
            this.value = value;
        }

        @Override
        public String toString() {
            if (value == 1) { // other way: if (this == SUNDAY) {
                return "Today is holiday";
            } else {
                return "Today is working day";
            }
        }
    }

    public static void main(String[] args) {
        WeekDay today = WeekDay.SUNDAY;
        System.out.println(today);
        System.out.println(today.toString());
    }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>Today is holiday</code><br/>
    <code>Today is holiday</code>
  </div>
</div>
