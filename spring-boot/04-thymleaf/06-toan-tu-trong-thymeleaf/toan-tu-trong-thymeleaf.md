---
title: "Toán tử trong Thymeleaf"
description: "Toán tử đóng vai trò quan trọng trong việc kiểm soát và hiển thị dữ liệu trên trang web của bạn. Trong Thymeleaf, một Java Template Engine phổ biến, bạn có khả năng sử dụng các toán tử để thực hiện các phép tính và kiểm tra các điều kiện"
chapter:
  name: "Thymeleaf"
  slug: "chuong-04-thymeleaf"
image: https://kungfutech.edu.vn/thumbnail.png
position: 6
---

Toán tử đóng vai trò quan trọng trong việc kiểm soát và hiển thị dữ liệu trên trang web của bạn. Trong Thymeleaf, một Java Template Engine phổ biến, bạn có khả năng sử dụng các toán tử để thực hiện các phép tính và kiểm tra các điều kiện. Trong bài viết này, chúng ta sẽ khám phá các toán tử phổ biến trong Thymeleaf và cách chúng có thể giúp bạn tạo ra các trang web động và linh hoạt.

## Các Loại Toán Tử Thường Sử Dụng

### Toán Tử Toán Học

Thymeleaf hỗ trợ tất cả các toán tử toán học cơ bản, bao gồm cộng (+), trừ (-), nhân (\*), chia (/), và modulo (%). Bạn có thể sử dụng chúng để thực hiện các phép tính trên các biến hoặc giá trị trong mã Thymeleaf.

Ví dụ:

```html
<p th:text="${5 + 3}"></p>
<!-- Kết quả: 8 -->
```

### Toán Tử So Sánh

Bạn có thể sử dụng các toán tử so sánh như `==`, `!=`, `<`, `>`, `<=`, và `>=` để so sánh các giá trị và điều kiện trong Thymeleaf.

Ví dụ:

```html
<p th:text="${age &gt;= 18}"></p>
<!-- Kết quả: true hoặc false tùy thuộc vào giá trị của age -->
```

### Toán Tử Gán Giá Trị

Toán tử `=` trong Thymeleaf dùng để gán giá trị cho biến hoặc thuộc tính.

Ví dụ:

```html
<p th:with="x=10" th:text="${x}"></p>
<!-- Kết quả: 10 -->
```

### Toán Tử Logic

Thymeleaf hỗ trợ các toán tử logic như `and`, `or`, và `not`, giúp bạn kiểm tra các điều kiện phức tạp.

Ví dụ:

```html
<p th:text="${(isAdult and hasLicense) or (isStudent and hasID)}"></p>
<!-- Kết quả: true hoặc false tùy thuộc vào các giá trị của biến -->
```

## Sử Dụng Toán Tử trong Biểu Thức Thymeleaf

Toán tử có thể được sử dụng trong biểu thức Thymeleaf để tính toán giá trị hoặc kiểm tra điều kiện. Dưới đây là một số ví dụ:

### Sử Dụng Toán Tử Toán Học

```html
<p th:text="${totalPrice = price * quantity}"></p>
<!-- Kết quả: Giá trị của totalPrice được tính dựa trên price và quantity -->
```

### Sử Dụng Toán Tử So Sánh

```html
<p th:text="${isAdult = age >= 18}"></p>
<!-- Kết quả: Giá trị của isAdult là true hoặc false tùy thuộc vào giá trị của age -->
```

### Sử Dụng Toán Tử Logic

```html
<p th:text="${(hasPermission and isActive) or isAdmin}"></p>
<!-- Kết quả: Giá trị của biểu thức logic -->
```

## Sử Dụng Toán Tử Trong Câu Lệnh Điều Kiện

Toán tử thường được sử dụng trong câu lệnh điều kiện `th:if` và `th:unless` để kiểm tra và điều khiển việc hiển thị dữ liệu trên trang web.

Ví dụ:

```html
<div th:if="${isAuthenticated}">
  <p>Xin chào, bạn đã đăng nhập!</p>
</div>
<div th:unless="${isAuthenticated}">
  <p>Vui lòng đăng nhập để truy cập nội dung.</p>
</div>
```

::alert{type="success"}

Toán tử trong Thymeleaf là một phần quan trọng của việc xây dựng các trang web động và phức tạp. Bạn có thể sử dụng các toán tử toán học, so sánh, gán giá trị và logic để kiểm soát và hiển thị dữ liệu theo cách linh hoạt và mạnh mẽ. Điều này giúp bạn tạo ra các trang web phản ánh các phép tính và điều kiện phức tạp, cung cấp trải nghiệm tốt cho người dùng. Hãy sử dụng toán tử một cách khéo léo để cải thiện trang web của bạn và làm cho nó trở nên đa dạng và thú vị hơn.

::
