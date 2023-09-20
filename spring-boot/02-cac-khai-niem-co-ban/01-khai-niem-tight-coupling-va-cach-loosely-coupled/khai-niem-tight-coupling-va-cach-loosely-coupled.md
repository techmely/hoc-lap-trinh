---
title: "Khái niệm tight-coupling và cách loosely coupled"
description: "Sử dụng loose coupling và Dependency Injection giúp mã nguồn trở nên linh hoạt, dễ bảo trì và dễ mở rộng. Nó cho phép bạn thay đổi các phần của ứng dụng mà không ảnh hưởng đến các phần khác, giúp bạn quản lý sự phụ thuộc giữa các lớp một cách hiệu quả hơn."
chapter:
  name: "Các khái niệm cơ bản về Spring"
  slug: "chuong-02-cac-khai-niem-co-ban"
category:
  name: "Spring Boot"
  slug: "spring-boot"
position: 1
---

Trong lập trình Java, khái niệm **tight-coupling** (liên kết ràng buộc) ám chỉ mối quan hệ giữa các lớp (classes) quá chặt chẽ. Khi sử dụng tight-coupling, các lớp kết nối với nhau một cách mạnh mẽ, và sự thay đổi trong một lớp có thể ảnh hưởng đến toàn bộ hệ thống hoặc các lớp khác. Điều này có thể tạo ra sự phụ thuộc không mong muốn và làm cho mã nguồn trở nên khó bảo trì và mở rộng.

Ngược lại, **loose coupling** (liên kết lỏng) là cách để giảm bớt sự phụ thuộc giữa các lớp với nhau. Trong loose coupling, các lớp hoạt động độc lập và không biết gì về cấu trúc hoặc chi tiết triển khai của các lớp khác. Điều này tạo điều kiện thuận lợi cho việc mở rộng và bảo trì mã nguồn.

## Ví dụ Dễ Hiểu

Hãy xem xét một ví dụ để hiểu rõ hơn về tight-coupling và loose coupling bằng ngôn ngữ Java.

### Tight Coupling

Giả sử bạn có một lớp `VeryComplexService` thực hiện một nhiệm vụ phức tạp, trong đó một phần của nhiệm vụ là sắp xếp một mảng dữ liệu trước khi xử lý. Ở mức tight coupling, mã nguồn có thể trông như sau:

```java
public class BubbleSortAlgorithm {

    public void sort(int[] array) {
        // TODO: Add your sorting logic here
        System.out.println("Sorted using bubble sort algorithm");
    }
}

public class VeryComplexService {
    private BubbleSortAlgorithm bubbleSortAlgorithm = new BubbleSortAlgorithm();

    public VeryComplexService() {
    }

    public void complexBusiness(int[] array) {
        bubbleSortAlgorithm.sort(array);
        // TODO: More business logic here
    }
}
```

Trong trường hợp này, `VeryComplexService` và `BubbleSortAlgorithm` quá chặt chẽ kết nối với nhau. Khi bạn cần thay đổi thuật toán sắp xếp sang QuickSort, bạn sẽ phải sửa cả hai lớp.

### Loose Coupling

Ở mức loose coupling, chúng ta sử dụng một giao diện (interface) `SortAlgorithm` để giảm sự phụ thuộc giữa các lớp. Mỗi thuật toán sắp xếp cụ thể sẽ triển khai giao diện này. Mã nguồn có thể trông như sau:

```java
public interface SortAlgorithm {
    void sort(int[] array);
}

public class BubbleSortAlgorithm implements SortAlgorithm {

    @Override
    public void sort(int[] array) {
        // TODO: Add bubble sort logic here
        System.out.println("Sorted using bubble sort algorithm");
    }
}

public class VeryComplexService {
    private SortAlgorithm sortAlgorithm;

    public VeryComplexService(SortAlgorithm sortAlgorithm) {
        this.sortAlgorithm = sortAlgorithm;
    }

    public void complexBusiness(int[] array) {
        sortAlgorithm.sort(array);
        // TODO: More business logic here
    }
}
```

Với loose coupling, `VeryComplexService` không còn phụ thuộc vào cụ thể của thuật toán sắp xếp. Bạn có thể dễ dàng thay đổi thuật toán bằng cách truyền một đối tượng thuật toán khác vào `VeryComplexService`.

## Dependency Injection

Một cách để thực hiện loose coupling là sử dụng **Dependency Injection** (DI), trong đó các phụ thuộc của một lớp không được tạo bên trong lớp đó mà được cung cấp từ bên ngoài. Điều này giúp tách biệt việc xây dựng và cấu hình đối tượng từ việc sử dụng nó. Trong ví dụ trên, `VeryComplexService` sử dụng DI để nhận một đối tượng `SortAlgorithm` từ bên ngoài.

::alert{type="success"}
Sử dụng loose coupling và Dependency Injection giúp mã nguồn trở nên linh hoạt, dễ bảo trì và dễ mở rộng. Nó cho phép bạn thay đổi các phần của ứng dụng mà không ảnh hưởng đến các phần khác, giúp bạn quản lý sự phụ thuộc giữa các lớp một cách hiệu quả hơn.
::
