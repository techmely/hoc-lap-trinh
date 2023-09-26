---
title: "Prototype Pattern trong Java"
description: "Prototype Pattern là một mẫu thiết kế tạo dựng (Creation Pattern) trong lập trình. Đây là cách để bạn tạo ra các đối tượng mới dựa trên các đối tượng hiện có một cách hiệu quả, đặc biệt khi việc tạo đối tượng tốn nhiều thời gian và tài nguyên"
chapter:
  name: "Design Pattern"
  slug: "chuong-07-design-pattern"
image: https://user-images.githubusercontent.com/29374426/146175674-fa7e09f7-4e42-485e-a2b5-8c664601b203.png
position: 6
---

**Prototype Pattern** là một mẫu thiết kế tạo dựng (Creation Pattern) trong lập trình. Đây là cách để bạn tạo ra các đối tượng mới dựa trên các đối tượng hiện có một cách hiệu quả, đặc biệt khi việc tạo đối tượng tốn nhiều thời gian và tài nguyên. Prototype Pattern giúp bạn sao chép (copy) các đối tượng đã tồn tại và thay đổi các giá trị thuộc tính nếu cần.

Ví dụ, trong Java, bạn có thể sử dụng **Prototype Pattern** bằng cách triển khai giao diện `Cloneable` và sử dụng phương thức `clone()` để sao chép đối tượng.

## Prototype Pattern là gì

**Prototype Pattern** thường được sử dụng khi:

1. Tạo một đối tượng mới tốn nhiều thời gian hoặc tài nguyên.
2. Bạn đã có một đối tượng tương tự và bạn muốn tạo một bản sao với một số sự thay đổi.

## Prototype Pattern UML Diagram

Trong **Prototype Pattern**, có hai trường hợp chính:

**Trường hợp 1: Shallow copy (Sao chép nông)**: Các đối tượng con bên trong chỉ được tham chiếu, tức là cả đối tượng gốc và bản sao đều trỏ đến cùng một đối tượng con. Điều này có nghĩa là nếu bạn thay đổi đối tượng con ở một nơi, nó sẽ thay đổi cả ở nơi còn lại.

![Prototype Pattern UML Diagram](https://github.com/techmely/hoc-lap-trinh/assets/29374426/9e1bf1ab-0e37-4bb0-a79d-e6f4e2428f5e)

**Trường hợp 2: Deep copy (Sao chép sâu)**: Các đối tượng con bên trong được sao chép hoàn toàn, tức là cả đối tượng gốc và bản sao đều có các đối tượng con riêng biệt.

![Prototype Pattern UML Diagram](https://github.com/techmely/hoc-lap-trinh/assets/29374426/8052e2eb-c4d6-40b1-a03c-3279cd31af55)

## Ví dụ về Prototype Pattern

Dưới đây là một ví dụ về **Prototype Pattern** sử dụng một lớp `User` có thể sao chép đối tượng theo hai cách: sao chép nông và sao chép sâu.

```java
public class User {
  private String firstName;
  private String lastName;
  private String displayName;
  private String email;
  private Address address;

  // Constructors and getters/setters for properties...

  public User shallowCopy() {
    User user = new User(this.firstName, this.lastName, this.displayName, this.email, this.address);
    return user;
  }

  public User deepCopy() {
    Address address = new Address(this.address.getProvince(), this.address.getDistrict(), this.address.getStreet());
    User user = new User(this.firstName, this.lastName, this.displayName, this.email, address);
    return user;
  }
}
```

Trong ví dụ trên:

- Phương thức `shallowCopy()` chỉ sao chép tham chiếu của đối tượng `address`, nên nếu bạn thay đổi địa chỉ của đối tượng gốc, nó cũng thay đổi đối tượng sao chép.
- Phương thức `deepCopy()` thực hiện sao chép đối tượng `address` một cách hoàn toàn, vì vậy đối tượng sao chép có một bản sao riêng biệt của địa chỉ.

Khi bạn thử chạy ví dụ, bạn sẽ thấy rằng việc thay đổi địa chỉ của đối tượng sao chép sâu không ảnh hưởng đến đối tượng gốc, trong khi đối tượng sao chép nông thay đổi địa chỉ sẽ ảnh hưởng đến cả đối tượng gốc.
