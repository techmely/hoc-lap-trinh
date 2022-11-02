---
title: "Toán tử trong C#"
description: "Trong bài này mình sẽ giới thiệu toán tử trong C# là gì và các loại toán tử trong C#."
keywords: [
"Toán tử trong C#",
"Toan tu trong C#"
]
chapter:
  name: "Tổng quan về C#"
  slug: "chuong-01-tong-quan-ve-csharp"
categoy:
  name: "C#"
  slug: "C#"
image: https://kungfutech.edu.vn/thumbnail.png
position: 5
---

## Giới thiệu

Để có thể thao tác được với dữ liệu ta cần 1 công cụ, đó là toán tử. Trong lập trình C# có nhiều loại toán tử khác nhau và mỗi loại sẽ có 1 ký hiệu riêng để đại diện cho một thao tác cụ thể với dữ liệu.

## Phân loại toán tử

Trong C# có 6 loại toán tử cơ bản đó là:

- Toán tử toán học
- Toán tử quan hệ
- Toán tử logic
- Toán tử khởi tạo và gán
- Toán tử so sánh trên bit
- Toán tử khác

### 1. Toán tử toán học

| Toán tử | Miêu tả                                    | Ví dụ             |
| ------- | ------------------------------------------ | ----------------- |
| +       | Thêm hai toán hạng                         | A=1, B=2 ->A+B=3  |
| -       | Trừ giá trị toán hạng hai từ toán hạng đầu | A=1, B=2 ->A-B=-1 |
| \*      | Nhân hai toán hạng                         | A=3, B=2 ->A\*B=6 |
| /       | Chia lấy phần nguyên hai toán hạng         | A=3, B=2 ->A/B=1  |
| %       | Chia lấy phần dư                           | A=3, B=2 ->A%B=1  |
| ++      | Thêm 1 đơn vị cho toán hạng                | A=1 -> A++=2      |
| --      | Giảm 1 đơn vị của toán hạng                | A=1 -> A -- =0    |

### 2. Toán tử quan hệ

| Toán tử | Miêu tả                                                                                                                  | Ví dụ                        |
| ------- | ------------------------------------------------------------------------------------------------------------------------ | ---------------------------- |
| ==      | Kiểm tra nếu 2 toán hạng bằng nhau hay không. Nếu bằng thì điều kiện là true.                                            | A=1, B=2 ->(A == B) là false |
| !=      | Kiểm tra 2 toán hạng có giá trị khác nhau hay không. Nếu không bằng thì điều kiện là true.                               | A=1, B=2 ->(A != B) là true  |
| >       | Kiểm tra nếu toán hạng bên trái có giá trị lớn hơn toán hạng bên phải hay không. Nếu lớn hơn thì điều kiện là true       | A=1, B=2 ->(A > B) là false  |
| <       | Kiểm tra nếu toán hạng bên trái nhỏ hơn toán hạng bên phải hay không. Nếu nhỏ hơn thì là true.                           | A=3, B=2 ->(A<B) là false    |
| >=      | Kiểm tra nếu toán hạng bên trái có giá trị lớn hơn hoặc bằng giá trị của toán hạng bên phải hay không. Nếu đúng là true. | A=3, B=3 -> (A>=B) là true   |
| <=      | Kiểm tra nếu toán hạng bên trái có giá trị nhỏ hơn hoặc bằng toán hạng bên phải hay không. Nếu đúng là true.             | A=3, B=5 -> (A<=B) là true   |

### 3. Toán tử logic

| Toán tử | Miêu tả                             | Ví dụ                                |
| ------- | ----------------------------------- | ------------------------------------ |
| &&      | Được gọi là toán tử logic AND (và)  | A= true, B = true -> (A&&B)-> true   |
| \|\|    | Được gọi là toán tử logic OR (hoặc) | A= true, B = false-> (A\|\|B)-> true |
| !       | Được gọi là toán tử NOT (phủ định)  | A=true -> !A=false                   |

### 4. Toán tử khởi tạo và gán

| Toán tử | Miêu tả                                                                                                           | Ví dụ                                |
| ------- | ----------------------------------------------------------------------------------------------------------------- | ------------------------------------ |
| =       | Gán giá trị của toán hạng bên phải cho toán hạng bên trái                                                         | A= 1 sẽ gán cho biến A giá giá trị 1 |
| +=      | Lấy toán hạng bên trái cộng toán hạng bên phải sau đó gán kết quả lại cho toán hạng bên trái                      | A += 1 tương đương với A = A + 1     |
| -=      | Lấy toán hạng bên trái nhân toán hạng bên phải sau đó gán kết quả lại cho toán hạng bên trái                      | A _= 1 tương đương với A = A _ 1     |
| \*=     | Lấy toán hạng bên trái trừ toán hạng bên phải sau đó gán kết quả lại cho toán hạng bên trái                       | A -= 1 tương đương với A = A - 1     |
| /=      | Lấy toán hạng bên trái chia lấy phần nguyên với toán hạng bên phải sau đó gán kết quả lại cho toán hạng bên trái. | A /= 1 tương đương với A = A / 1     |
| %=      | Lấy toán hạng bên trái chia lấy dư với toán hạng bên phải sau đó gán kết quả lại cho toán hạng bên trái.          | A %= 1 tương đương với A = A % 1     |

### 5. Toán tử so sánh trên bit

Đấy là loại toán tử đặc biệt rất ít khi sử dụng nên các bạn không cần tìm hiểu kỹ phần này.

Ví dụ: A có giá trị bằng 10, B có giá trị bằng 9. Giá trị biến đổi của a và b ra hệ nhị phân lần lượt là là 1010 và 1001

| Toán tử | Miêu tả                                                                                                                    | Ví dụ                                  |
| ------- | -------------------------------------------------------------------------------------------------------------------------- | -------------------------------------- |
| &       | Sao chép bit 1 tới kết quả nếu nó tồn tại trong cả hai toán hạng tại vị trí tương ứng, ngược lại thì bit kết quả bằng 0    | a&b sẽ cho kết quả nhị phân là 1000    |
| \|      | Sao chép bit 1 tới kết quả nếu nó tồn tại ở một trong hai toán hạng tại vị trí tương ứng, ngược lại thì bit kết quả bằng 0 | a\|b sẽ cho kết quả nhị phân là 1011   |
| \^      | Sao chép bit 1 tới kết quả nếu nó chỉ tồn tại ở một toán hạng tại vị trí tương ứng, ngược lại thì bit kết quả bằng 0       | a^b sẽ cho kết quả nhị phân là 0011    |
| ~       | Dùng để đảo bit 0 thành 1 và ngược lại 1 thành 0                                                                           | ~a sẽ cho kết quả nhị phân là 0101     |
| <<      | Dịch trái n bit. Giá trị toán hạng bên trái sẽ được dịch trái n bit với n được xác định bởi toán hạng bên phải             | a<<2 sẽ cho kết quả nhị phân là 101000 |
| >>      | Dịch phải n bit. Giá trị toán hạng bên trái sẽ được dịch phải n bit với n được xác định bởi toán hạng bên phải             | a>>2 sẽ cho kết quả nhị phân là 0010   |

### 6. Toán tử khác

| Toán tử  | Miêu tả                                                                                                        | Ví dụ                                                 |
| -------- | -------------------------------------------------------------------------------------------------------------- | ----------------------------------------------------- |
| sizeof() | Trả về kích cỡ của một kiểu dữ liệu                                                                            | sizeof(int) sẽ trả về 4                               |
| typeof() | Trả về kiểu của một lớp (khái niệm về lớp sẽ được trình bày trong bài CLASS TRONG C#)                          | typeof(string) sẽ trả về System.String                |
| new      | Cấp phát vùng nhớ mới, áp dụng cho kiểu dữ liệu tham chiếu                                                     | DateTime dt = new DateTime()                          |
| is       | Xác định đối tượng có phải là một kiểu cụ thể nào đó hay không. Nếu đúng sẽ trả về true ngược lại trả về false | var A = 1 -> (A is null) có kết quả false             |
| as       | Ép kiểu mà không gây ra lỗi. Nếu ép kiểu không thành công sẽ trả về null                                       | int A=1 ->( A as double) thì A có giá trị kiểu Double |
| ?:       | Toán tử 3 ngôi ( chi tiết sẽ được trình bày tại bài toán tử 3 ngôi)                                            | A= (1 < 2) ? 1 : 0 -> A = 1                           |

# Độ ưu tiên của toán tử

| Toán tử                            | Thứ tự ưu tiên |
| ---------------------------------- | -------------- |
| () []                              | Trái sang phải |
| + – ! ~ ++ – – (type)\* & sizeof   | Phải sang trái |
| \* / %                             | Trái sang phải |
| + –                                | Trái sang phải |
| << >>                              | Trái sang phải |
| < <= > >=                          | Trái sang phải |
| == !=                              | Trái sang phải |
| &                                  | Trái sang phải |
| ^                                  | Trái sang phải |
| \|                                 | Trái sang phải |
| &&                                 | Trái sang phải |
| \|\|                               | Trái sang phải |
| ?:                                 | Phải sang trái |
| = += -= \*= /= %=>>= <<= &= ^= \|= | Phải sang trái |
