---
title: "Chuyển đổi kiểu dữ liệu trong C"
description: "Chuyển Đổi Kiểu Dữ Liệu trong C nhấn mạnh vào quá trình biến đổi dữ liệu từ một kiểu sang kiểu khác trong ngôn ngữ lập trình C, còn được gọi là ép kiểu (type casting). Việc này là một khía cạnh quan trọng để làm cho chương trình linh hoạt hơn và xử lý dữ liệu một cách hiệu quả."
chapter:
  name: "Nhập môn C"
  slug: "chuong-02-basic-concepts"
category:
  name: "C"
  slug: "c"
image: https://user-images.githubusercontent.com/29374426/127596066-fa46df01-982f-4a72-b6d1-f7d8f5c5a9b3.png
position: 6
---

Những kiểu dữ liệu khác nhau có thể chứa những giá trị giống nhau. Vì thế trong một số trường hợp, ta cần đưa dữ liệu về dạng mong muốn, hay chuyển đổi sang một kiểu dữ liệu mới để dễ dàng thực hiện việc thao tác xử lý. Khi đó ta sẽ thực hiện việc ép kiểu dữ liệu _(chuyển đổi kiểu dữ liệu này sang kiểu dữ liệu khác)_.

Chuyển đổi một kiểu dữ liệu này thành một kiểu dữ liệu khác được gọi là **`type casting`** hoặc **`type conversion`**.

Ép kiểu có hai loại sau:

- Ép kiểu ngầm định (Implicit Type Conversion)
- Ép kiểu tường minh (Explicit Type Conversion)

## Ép kiểu ngầm định trong C

Chuyển đổi ngầm định là việc chuyển đổi được thực hiện tự động bởi trình biên dịch và chúng ta không cần làm gì - lập trình viên không cần can thiệp trực tiếp vào quá trình chuyển đổi.

Việc chuyển đổi kiểu dữ liệu này được thực hiện khi muốn chuyển kiểu dữ liệu nhỏ sang kiểu dữ liệu lớn hơn có nghĩa là kích thước kiểu dữ liệu trước phải nhỏ hơn kích thước của kiểu dữ liệu sau.

`char` -> `int` -> `long` -> `float` -> `double`

Ví dụ: Chuyển kiểu dữ liệu `int` _(2bytes)_ sang kiểu `float` _(4bytes)_.

Ví dụ 1:

```cpp
#include <stdio.h>

int main() {

    int a = 10;
    float b = a;  // ép kiểu int sang float

    printf("a = %d\n", a);
    printf("b = %f", b);
}
```

Kết quả:

::result
a = 10
b = 10.000000
::

Ví dụ 2:

```cpp
#include <stdio.h>

int main() {

    float b = 5;  // ép kiểu int sang float
}
```

Ở ví dụ 2, số `5` bên phải được nhận diện là `int`, nên khi viết `float b = 5;` cũng là ép kiểu `int` sang `float`. Để viết đúng giá trị bên phải là kiểu số thập phân, chúng ta cần viết thêm dấu chấm động vào như sau:

```cpp
#include <stdio.h>

int main() {

    float b = 5.0f;
}
```

Chữ `f` cuối cùng để phân biệt đây là giá trị thập phân của kiểu `float` - phân biệt với kiểu `double`. Đối với kiểu `double` chúng ta chỉ cần viết `double b = 5.0;` (không có chữ `f` và không có chữ gì).

> Chuyển đổi giá trị **từ một kiểu sang một kiểu dữ liệu tương tự lớn hơn** thường **an toàn**, và **không mất dữ liệu**.

**Chúng ta có thể chuyển kiểu dữ liệu nhỏ sang kiểu dữ liệu lớn hơn nên vì vậy cũng có thể chuyển kiểu dữ liệu lớn hơn sang kiểu dữ liệu nhỏ hơn - nhưng điều này có những vấn đề quan trọng cần lưu ý sau:**

- **Chuyển đổi giá trị sang một kiểu dữ liệu có miền giá trị nhỏ hơn sẽ gây ra kết quả không mong muốn.**

  ```cpp
  #include <stdio.h>

  int main() {

      long n = 5000000000;
      int c = n;

      printf("c = %d", c);
  }
  ```

  Vì `int` chỉ lưu trữ được `+- 2,147,483,647` trong khi `n = 5,000,000,000` vượt quá ngưỡng lưu trữ của `int`, vì vậy khi chạy chúng ta sẽ nhận được kết quả sai không mong muốn như sau:

  ::result
  c = 705032704
  ::

- **Đối với kiểu số chấm động (floating point), chuyển đổi giá trị về kiểu dữ liệu nhỏ hơn có thể gây mất độ chính xác.**

  ```cpp
  #include <stdio.h>

  int main() {

      float c = 0.123456789; // ép double về float

      printf("c = %f", c);
  }
  ```

  Vì kiểu `float` chỉ đủ để lưu trữ 6 đến 7 chữ số thập phân sau dấu phẩy, vì vậy phần thập phân dài hơn của `double` sẽ bị mất, kết quả sẽ mất đi độ chính xác như sau:

  ::result
  c = 0.123457
  ::

- **Chuyển đổi một giá trị từ số chấm động sang số nguyên sẽ làm mất đi phần thập thân.**

  ```cpp
  #include <stdio.h>

  int main() {

      double n = 2.5;
      int c = n;
      printf("c = %d", c);
  }
  ```

  Vì `int` không thế chứa được dấu chấm động vì vậy phần thập phân sẽ bị mất đi như sau:

  ::result
  c = 2
  ::

> Chuyển đổi giá trị **từ một kiểu sang một kiểu dữ liệu tương tự nhỏ hơn**, hoặc **giữa các kiểu dữ liệu khác nhau** thường **không an toàn**, nó có thể dẫn đến **mất mát dữ liệu** sau khi chuyển đổi.

## Ép kiểu tường minh trong C

Ép kiểu tường minh là việc chuyển đổi được thực hiện một cách rõ ràng bởi yêu cầu của người lập trình bằng cách sử dụng toán tử ép kiểu (**casting operator**) để thực hiện việc chuyển đổi.

Chúng ta cùng xem ví dụ sau:

```cpp
#include <stdio.h>

int main() {

    float result = 5 / 2;

    printf("result = %f", result);
}
```

Kết quả:

::result
result = 2.000000
::

Vì sao lại không ra kết quả mong muốn?

- Dòng code `float result = 5 / 2;` có 2 toán từ là **phép chia `/`** và **phép gán `=`**. Ở đây, phép chia sẽ được ưu tiên thực hiện trước phép gán.
- `5 / 2` sẽ được thực hiện, xét về kiểu dữ liệu ta sẽ có `int / int`. Vậy kết quả sẽ trả về `int`, vì `5 / 2 = 2.5` nhưng kiểu `int` không lưu được dấu chấm động nên vì vậy `2.5` sẽ chuyển về bằng `2`.
- Vậy ta sẽ có `float result = 2;`, bây giờ phép gán mới thực hiện gán `2` cho biến `result`, `2` lại được ép kiểu về kiểu `float` nên sẽ có dấu chấm động. Vì vậy cuối cùng chúng ta sẽ nhận được kết quả là `result = 2.000000`.

Làm thế nào chúng ta có thể nói với chương trình rằng chúng ta muốn có kết quả trả về là số thập phân? Hãy xem lại ví dụ:

```cpp
#include <stdio.h>

int main() {

    float result = (float) 5 / 2;

    printf("result = %f", result);
}
```

Kết quả:

::result
result = 2.500000
::

`(float) 5` được gọi là **casting** - được thực hiện thông qua toán tử `()` với tên của kiểu dữ liệu bạn muốn chuyển đổi được đặt bên trong. Lúc này `5` đang là `int` sẽ được ép kiểu về kiểu `float`, và `float / int = float`. Chúng ta cũng có thể lựa chọn **casting** số `2` đều cho ra kết quả tương tự.

Ngoài ra **casting** còn có thể viết lại như sau:

```cpp
#include <stdio.h>

int main() {

    float result = float(5) / 2;

    printf("result = %f", result);
}
```
