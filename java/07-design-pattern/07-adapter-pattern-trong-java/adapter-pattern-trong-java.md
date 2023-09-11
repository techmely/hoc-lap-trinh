---
title: "Adapter Pattern trong Java"
description: "Mục đích của Adapter Pattern là cho phép các interface không liên quan tới nhau có thể làm việc cùng nhau. Điều này thường xảy ra khi bạn muốn sử dụng một lớp đã tồn tại mà không phù hợp với giao diện (interface) của bạn."
chapter:
  name: "Design Pattern"
  slug: "chuong-07-design-pattern"
category:
  name: "Java"
  slug: "java"
image: https://user-images.githubusercontent.com/29374426/146175674-fa7e09f7-4e42-485e-a2b5-8c664601b203.png
position: 7
---

## Adapter Pattern là gì

**Adapter Pattern** là một mẫu cấu trúc (Structural Pattern) trong lập trình.

**Mục đích** của Adapter Pattern là cho phép các interface không liên quan tới nhau có thể làm việc cùng nhau. Điều này thường xảy ra khi bạn muốn sử dụng một lớp đã tồn tại mà không phù hợp với giao diện (interface) của bạn. Đối tượng giúp kết nối các interface này gọi là Adapter.

**Ví dụ trong cuộc sống**: Hãy tưởng tượng bạn có một ổ cắm điện có 3 chân, nhưng ở nhà bạn chỉ có ổ cắm có 2 lỗ. Để kết nối được, bạn cần sử dụng một bộ chuyển đổi (adapter) để chuyển từ 3 chân thành 2 chân.

## Adapter Pattern UML Diagram

![Adapter Pattern UML Diagram](https://github.com/techmely/hoc-lap-trinh/assets/29374426/fd6297b5-be8c-4739-85fc-ed24505a87b9)

**UML Diagram** của Adapter Pattern cho thấy mối quan hệ giữa các thành phần chính:

- **Client**: Đối tượng sử dụng interface `Target`.
- **Target**: Interface mà Client mong muốn sử dụng.
- **Adapter**: Lớp này kế thừa hoặc sử dụng `Adaptee` và triển khai `Target`. Nó làm cho `Adaptee` có thể làm việc với `Client`.
- **Adaptee**: Đối tượng đã tồn tại, không phù hợp với `Target`. `Adapter` giúp `Client` sử dụng `Adaptee` một cách thuận tiện.

## Ví dụ về Adapter Pattern

Giả sử bạn có một lớp `CheckNumberAdaptee` thực hiện kiểm tra chuỗi ký tự có phải là kiểu số không. Bạn muốn kiểm tra xem một chuỗi có phải là số điện thoại (có từ 10 đến 11 chữ số) hay không bằng cách sử dụng `CheckNumberAdaptee`. Để làm điều này, bạn sẽ sử dụng một lớp `Adapter` để triển khai interface `PhoneTarget` và sử dụng `CheckNumberAdaptee` để thực hiện kiểm tra số điện thoại.

Dưới đây là ví dụ code trong Java:

```java
public class CheckNumberAdaptee {
  public boolean checkNumber(String input) {
    String regex = "[0-9]+";
    return input.matches(regex);
  }
}

public interface PhoneTarget {
  boolean checkPhoneNumber(String input);
}

public class Adapter implements PhoneTarget {
  CheckNumberAdaptee checkNumberAdaptee = new CheckNumberAdaptee();

  @Override
  public boolean checkPhoneNumber(String input) {
    if (!checkNumberAdaptee.checkNumber(input)) {
      return false;
    }
    if (input.length() > 11 || input.length() < 10) {
      return false;
    }
    return true;
  }
}

public class Client {
  public static void main(String[] args) {
    PhoneTarget phoneTarget = new Adapter();
    String input1 = "sdflkqweqweq";
    String input2 = "123";
    String input3 = "01234342342";
    System.out.println(input1 + " is phone number: " + phoneTarget.checkPhoneNumber(input1));
    System.out.println(input2 + " is phone number: " + phoneTarget.checkPhoneNumber(input2));
    System.out.println(input3 + " is phone number: " + phoneTarget.checkPhoneNumber(input3));
  }
}
```

<content-result>
sdflkqweqweq is phone number: false
123 is phone number: false
01234342342 is phone number: true
</content-result>

Trong ví dụ này:

- `CheckNumberAdaptee` là đối tượng không phù hợp với interface `PhoneTarget`.
- `Adapter` cho phép `CheckNumberAdaptee` làm việc với interface `PhoneTarget`.
- `Client` sử dụng `PhoneTarget` để kiểm tra số điện thoại và sử dụng `Adapter` để kết nối với `CheckNumberAdaptee`.
