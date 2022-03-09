---
title: "Mảng (array) trong Java"
description: "Mảng trong Java là một đối tượng chứa các phần tử có kiểu dữ liệu giống nhau. Mảng là một cấu trúc dữ liệu nơi lưu trữ các phần tử giống nhau"
keywords: []
chapter:
  name: "Lập trình hướng đối tượng"
  slug: "chuong-03-lap-trinh-huong-doi-tuong"
category:
  name: "Java"
  slug: "java"
image: https://user-images.githubusercontent.com/29374426/132833011-54534065-b9ea-48f0-9e44-a9ef4f8a4951.png
position: 27
---

Mảng trong Java là một đối tượng chứa các phần tử có kiểu dữ liệu giống nhau. Mảng là một cấu trúc dữ liệu nơi lưu trữ các phần tử giống nhau. Với mảng trong java chúng ta chỉ có thể lưu trữ một tập các phần tử có số lượng phần tử cố định.

## Mảng trong Java

Thông thường, mảng (array) là một tập hợp các phần tử có cùng kiểu được lưu trữ gần nhau trong bộ nhớ. Mảng trong java lưu các phần tử theo chỉ số, chỉ số của phần tử đầu tiên là 0.

Dưới đây là hình ảnh mô tả một mảng một chiều, chúng ta sẽ tìm hiểu kỹ ở phần dưới nhé.

![image](https://user-images.githubusercontent.com/29374426/132833011-54534065-b9ea-48f0-9e44-a9ef4f8a4951.png)

## Mảng 1 chiều trong Java

### Khai báo

Cú pháp khai báo:

- `Kiểu_dữ_liệu tên_mảng[];`: Khai báo một con trỏ mảng
- `Kiểu_dữ_liệu []tên_mảng;`: tương tự như trên
- `Kiểu_dữ_liệu tên_mảng[] = new Kiểu_dữ_liệu[Số_lượng_phần_tử];`: Tạo ra một mảng có spt phần tử

Trong cú pháp trên thì:

- [Kiểu dữ liệu](/bai-viet/java/cac-kieu-du-lieu-trong-java) gồm: kiểu nguyên thủy, kiểu đối tượng… nó xác định kiểu dữ liệu của từng phần tử của mảng.
- Số phần tử là số lượng phần tử của mảng và là một số nguyên

<content-note>
  <ul>
    <li>Mảng trong Java là một đối tượng</li>
    <li>Cũng như các đối tượng khác, mảng phải được tạo ra bằng toán tử `new` như sau: Tên_mảng = new Kiểu_dữ_liệu[spt];</li>
    <li>Khi mảng được tạo ra thì mỗi phần tử của mảng sẽ nhận một giá trị mặc định, quy tắc khởi tạo giá trị cho các phần tử của mảng cũng chính là quy tắc khởi đầu giá trị cho các thuộc tính của đối tượng, tức là mỗi phần tử của mảng sẽ nhận giá trị: (0 - đối với kiểu number, '\0' - đối với kiểu dữ liệu là ký tự, false - đối với kiểu dữ liệu boolean, null - nếu kiểu dữ liệu là một lớp nào đó)</li>
  </ul>
</content-note>

<div class="example">Khai báo một mảng số nguyên gồm 100 phần tử</div>

```java
// Cách 1
int mangInt[]; // Khai báo một con trỏ đến mảng các số nguyên
mangInt = new int[100]; // Tạo ra mảng

// Cách 2
int mangInt[]=new int[100];
```

<div class="example">Giả sử ta có lớp SinhVien đã đươc định nghĩa, hãy khai báo một mảng gồm 100 đối tượng của lớp SinhVien</div>

```java
SinhVien arraySinhVien[] = new SinhVien[100];
```

<content-note>Lúc này mỗi phần tử của mảng arraySinhVien là một con trỏ của lớp SinhVien và hiện giờ mỗi phần tử của mảng đang trỏ đến giá trị null. Để khởi tạo từng phần tử của mảng ta phải làm như sau:</content-note>

```java
arraySinhVien[0]=new SinhVien("sv01", "Nguyễn Văn An", "Hưng Yên");
arraySinhVien[1]=new SinhVien("sv02", "Nguyễn Thị Bình", "Bắc Giang");
….
arraySinhVien[99]=new SinhVien("sv100", "Đào Thị Mến", "Hà Nam");
```

<div class="example">Ngoài cách khai báo trên Java còn cho phép ta kết hợp cả khai báo và khởi gán các phần tử của mảng theo cách sau: tạo ra một mảng gồm 5 phần tử, các phần tử của mảng lần lượt được gán các giá trị là: 1, 3, 5, 7, 9</div>

```java
// Với trường hợp là số
int[] mangInt = {1, 3, 5, 7, 9};

// Với trường hợp là object
SinhVien[] mangSinhVien = {
  new	SinhVien("sv01",	"Nguyễn	Văn	A", "HY"),
  new SinhVien("sv02", "Nguyễn Thị B", "HN"), new SinhVien("sv03", "Đỗ Thị Q", "BG"),
  null
};
```

Khai báo một mảng gồm 4 phần tử, giá trị của các phần tử lần lượt được khởi gán như sau:

```java
mangSinhVien [0]=new SinhVien("sv01", "Nguyễn Văn A", "HY")
mangSinhVien [1]=new SinhVien("sv02", "Nguyễn Thị B", "HN")
mangSinhVien [2]=new SinhVien("sv03", "Đỗ Thị Q", "BG")
mangSinhVien [3]=null
```

### Truy xất đến các phần tử của mảng một chiều

Để truy xuất đến phần tử thứ ind của mảng ta sử dụng cú pháp như sau:

```java
Tên_mảng[Vị_trí_của_phần tử]
```

<content-note>Phần tử đầu tiên của mảng có chỉ số là 0</content-note>

<content-example />

```java
int a[] = new int [3]; // Khai báo và tạo ra mảng gồm 3 phần tử
```

Lúc này các phần tử của mảng lần lượt được truy xuất như sau:

- Phần tử đầu tiên của mảng là `a[0]`
- Phần tử thứ 2 của mảng là `a[1]`
- Phần tử thứ 3 đồng thời là phần tử cuối cùng của mảng là `a[2]`

<div class="example">Truy cập các phần tử của một mảng trong Java</div>

```java
public class Thaycacac {
    public static void main(String[] args) {
        String[] cars = { "Honda", "BMW", "Ford", "Mazda" };
        System.out.println(cars[0]);
    }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>Honda</code>
  </div>
</div>

### Thay đổi một phần tử mảng trong Java

Để thay đổi giá trị của một phần tử cụ thể, hãy gán lại giá trị dựa vào vị trí của phần tử trong mảng

<content-example />

```java
public class TruyCapArray2 {
    public static void main(String[] args) {
        String[] cars = { "Honda", "BMW", "Ford", "Mazda" };

        // thay đổi phần tử đầu tiên của mảng cars
        cars[0] = "Morning";

        // hiển thị phần tử đầu tiên của mảng cars
        System.out.println("Phần tử đầu tiên: " + cars[0]);
    }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>Phần tử đầu tiên: Morning</code>
  </div>
</div>

### Lấy về số phần tử hiện tại của mảng trong java

Mảng trong Java là một đối tượng, do vậy nó cũng có các thuộc tính và các phương thức như các đối tượng khác. Để lấy về số phần tử của mảng ta sử dụng thuộc tính `length` như sau:

```java
Tên_mảng.length
```

<content-example />

```java
public class Thaycacac {
    public static void main(String[] args) {
        String[] cars = { "Honda", "BMW", "Ford", "Mazda" };
        System.out.println("Độ dài của mảng cars là: " + cars.length);
    }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>Độ dài của mảng cars là: 4</code>
  </div>
</div>

### Duyệt các phần tử của mảng trong Java

**Sử dụng vòng lặp for:** bạn có thể lặp qua các phần tử mảng bằng vòng lặp for và sử dụng thuộc tính length để chỉ định số lần vòng lặp sẽ chạy.

```java
public class Thaycacac {
    public static void main(String[] args) {
        String[] cars = { "Honda", "BMW", "Ford", "Mazda" };
        for (int i = 0; i < cars.length; i++) {
            System.out.println(cars[i]);
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
    <code>Honda</code><br/>
    <code>BMW</code><br/>
    <code>Ford</code><br/>
    <code>Mazda</code>
  </div>
</div>

**Sử dụng foreach:** so với vòng lặp `for` thì vòng lặp `foreach` dễ viết hơn, nó không yêu cầu bộ đếm (sử dụng thuộc tính length) và nó dễ đọc hơn.

```java
public class Thaycacac {
    public static void main(String[] args) {
        String[] cars = { "Honda", "BMW", "Ford", "Mazda" };
        for (String car : cars) {
            System.out.println(car);
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
    <code>Honda</code><br/>
    <code>BMW</code><br/>
    <code>Ford</code><br/>
    <code>Mazda</code>
  </div>
</div>

## Sắp xếp mảng trong Java

Có nhiều phương thức mảng có sẵn, ví dụ `Sort()`, sắp xếp một mảng theo thứ tự bảng chữ cái hoặc theo thứ tự tăng dần.

```java
import java.util.Arrays;

public class Thaycacac {
    public static void main(String[] args) {
        String[] cars = { "Honda", "BMW", "Ford", "Mazda" };
        // sap xep mangr cars theo thu tu tang dan
        Arrays.sort(cars);
        System.out.println("Mảng cars sau khi được sắp xếp:");
        for (String car : cars) {
            System.out.println(car);
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
    <code>Mảng cars sau khi được sắp xếp:</code><br/>
    <code>BMW</code><br/>
    <code>Ford</code><br/>
    <code>Honda</code><br/>
    <code>Mazda</code>
  </div>
</div>

### Truyền mảng vào phương thức trong java

Chúng ta có thể truyền mảng vào phương thức, điều này giúp tái sử dụng code logic để xử lý mảng bất kỳ

```java
public class Thaycacac {
    static void min(int arr[]) {
        int min = arr[0];
        for (int i = 1; i < arr.length; i++)
            if (min > arr[i]) {
                min = arr[i];
            }
        System.out.println(min);
    }

    public static void main(String args[]) {
        int a[] = { 33, 3, 4, 5 };
        min(a);// truyền mảng tới phương thức
    }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>3</code><br/>
  </div>
</div>

### Sao chép một mảng trong java

Chúng ta có thể sao chép một mảng tới mảng khác bởi phương thức arraycopy của lớp System. Cú pháp của phương thức arraycopy

```java
public class Thaycacac {
    public static void main(String[] args) {
        char[] copyFrom = { 'd', 'e', 'c', 'a', 'f',
                'f', 'e', 'i', 'n', 'a', 't', 'e', 'd' };
        char[] copyTo = new char[7];

        System.arraycopy(copyFrom, 2, copyTo, 0, 7);
        System.out.println(new String(copyTo));
    }
}
```

<div class="window">
  <div class="window-header">
    <div class="action-buttons"></div>
    <span class="title-popup">Kết quả</span>
  </div>
  <div class="window-body">
    <code>caffein</code><br/>
  </div>
</div>

## Mảng nhiều chiều

### Khai báo

Khai báo mảng N chiều trong Java được tiến hành như sau:

![image](https://user-images.githubusercontent.com/29374426/125579948-0ac51e29-616e-4542-af06-c292027c7441.png)

Hoặc

![image](https://user-images.githubusercontent.com/29374426/125579984-cc7a0116-701a-43e7-9381-7f29d43cb91a.png)

Trong đó:

- [KDL](/bai-viet/java/cac-kieu-du-lieu-trong-java) gồm: kiểu nguyên thủy, kiểu đối tượng… nó xác định kiểu dữ liệu của từng phần tử của mảng.
- sp1, sp2, …, sptN lần lượt là số phần tử trên chiều thứ 1, 2, .., N

<content-example />

```java
// Khai báo một con trỏ của mảng 2 chiều
int[][] a;
int a[][]; // Cách khác để khai báo một con trỏ của mảng 2 chiều

// Khai báo và tạo ra mảng 2 chiều: Ma trận gồm 2 hàng, 3 cột
int[][] a = new int[2][3];

// Khai báo và khởi gán giá trị cho các phần tử của mảng 2 chiều:
int a[][]={
  {1, 2, 5}. //Các phần tử trên hàng thứ nhất
  {2, 4, 7, 9}. //Các phần tử trên hàng thứ hai
  {1, 7}. //Các phần tử trên hàng thứ ba
}
```

Khai báo trên sẽ tạo ra một mảng hai chiều gồm: 3 hàng, nhưng trên mỗi hàng lại có số phần tử khác nhau, cụ thể là: trên hàng thứ nhất có 3 phần tử, hảng 2 gồm 4 phần tử và hàng thứ 3 gồm 2 phần tử.

<content-note>
Với khai báo trên nếu ta liệt kê các phần tử của mảng theo trình tự từ trái qua phải và từ trên xuống dưới thì các phần tử lần lượt là: <code>a[0][0], a[0][1], a[0][2], a[1][0], a[1][1], a[1][2], a[1][3], a[2][0], a[2][1]</code>
</content-note>

### Truy xuất đến phần tử mảng nhiều chiều

```java
tên_mảng[ind1][ind2]
```

<div class="example">khai báo và khởi tạo mảng đa chiều trong java</div>

```java
public class TestArray3 {
    public static void main(String args[]) {

        // khai báo và khởi tạo mảng 2 chiều
        int arr[][] = { { 1, 2, 3 }, { 2, 4, 5 }, { 4, 4, 5 } };

        // in mảng 2 chiều r màn hình
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                System.out.print(arr[i][j] + " ");
            }
            System.out.println();
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
    <code>1 2 3</code><br/>
    <code>2 4 5</code><br/>
    <code>4 4 5</code>
  </div>
</div>
