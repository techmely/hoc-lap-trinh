---
title: "Mảng đa chiều trong java"
description: "Lệnh break sẽ chấm dứt quá trình lặp mà không thực hiện nốt phân còn lại của cấu trúc lặp, continue sẽ ngưng thực thi phần còn lại của thân vòng lặp và chuyển điều khiển về điểm bắt đầu của vòng lặp"
chapter:
  name: "Nhập môn Java"
  slug: "chuong-02-nhap-mon-java"
image: https://user-images.githubusercontent.com/29374426/127758655-3a4c7e05-729c-4781-9568-9bfa546c0ed8.png
position: 25
---

Mảng đa chiều có thể định nghĩa đơn giản là mảng của mảng, dữ liệu bên trong một phần tử của mảng là một mảng.

```java
<Kiểu dữ liệu>[][][]..[] <tên mảng> = new <kiểu dữ liệu>[<kích thước thứ 1>][<kích thước thứ 2>]….[<kích thước thứ n>];
```

Trong đó:

- **Kiểu dữ liệu:** Kiểu dữ liệu của mảng, ví dụ int, char, double etc.
- **Tên mảng:** Tên mảng
- **Kích thước thứ 1, kích thước thứ 2, …, kích thước thứ n:** Kích thước mảng tương ứng

```java
// Mảng 2 chiều
int[][] mang1 = new int[10][20];
// Mảng 3 chiều
int[][][] mang2 = new int[10][20][30];
```

Trong đó:

- Đối với mảng 2 chiều **mang1**, là một mảng 10 phần tử, với mỗi phần tử là một mảng gồm 20 phần tử.
- Đối với mảng 3 chiều **mang2**, là 1 mảng 10 phần tử, mỗi phần tử là một mảng 20 phần tử, trong 20 phần tử này mỗi phần tử lại là một mảng 30 phần tử.

Ngoài ra chúng ta có thể khởi tạo mảng và trực tiếp giá trị cho từng phần tử trong mảng đa chiều như sau

```java
<Kiểu dữ liệu>[][] <tên mảng> = {
  {giaTriR1C1, giaTriR1C2, ....},
  {giaTriR2C1, giaTriR2C2, ....}
};
```

```java
Ví dụ: int[][] arr = {{1, 2}, {3, 4}};
```

## Cách tính số phần tử trong mảng đa chiều

Tổng số phần tử được lưu trong mảng đa chiều được tính bằng tích kích thước của từng mảng bên trong mảng đa chiều. Ví dụ

```java
  mang1[10][20] // kích thước là 10 * 20 = 200 phần tử
  mang2[10][20][30] // kích thước là 10 * 20 *30 = 6000 phần tử
```

### Truy xuất ngẫu nhiên trong mảng đa chiều

Ví dụ để truy xuất ngẫu nhiên một phần tử trong mảng 2 chiều sử dụng cú pháp

```java
  <Tên mảng>[<Vị trí hàng>][<Vị trí cột>]
```

![Mảng đa chiều trong java](https://user-images.githubusercontent.com/29374426/127758655-3a4c7e05-729c-4781-9568-9bfa546c0ed8.png)

```java
class Thaycacac {
  public static void main(String[] args) {
    int[][] arr = { { 1, 2 }, { 3, 4 } };
    for (int i = 0; i < 2; i++)
      for (int j = 0; j < 2; j++)
        System.out.println("arr[" + i + "][" + j + "] = " + arr[i][j]);
  }
}
```

::result

arr[0][0] = 1<br/>
arr[0][1] = 2<br/>
arr[1][0] = 3<br/>
arr[1][1] = 4

::
