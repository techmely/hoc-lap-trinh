---
title: "Kiểu dữ liệu của biến"
description: "Trong bài này mình sẽ giới thiệu kiểu dữ liệu của biến và phân loại chúng như thế nào."
chapter:
  name: "Tổng quan về C#"
  slug: "chuong-01-tong-quan-ve-csharp"
image: https://kungfutech.edu.vn/thumbnail.png
position: 4
---

## Kiểu dữ liệu là gì

Kiểu dữ liệu (data type) là một tập hợp gồm các nhóm loại dữ liệu có cùng đặc tính, cùng cách lưu trữ của dữ liệu và cùng cách thao tác xử lý trên trường dữ liệu đó nhằm mục đích phân loại các loại dữ liệu. Trong C#, một biến (variable) khi khởi tạo lên đã được chỉ định một kiểu dữ liệu xác định cho nó.

> Mọi biến khi khởi tạo trong C# đều phải có kiểu dữ liệu xác định.

## Các cách phân loại kiểu dữ liệu

Trong C#, kiểu dữ liệu được chia thành 2 tập hợp kiểu dữ liệu chính:

- Kiểu dữ liệu nguyên thủy mà ngôn ngữ cung cấp (Primitive Data Types)
- Kiểu dữ liệu do người dùng định nghĩa (user - defined)

Mỗi tập hợp kiểu dữ liệu trên lại chia thành 2 loại đó là:

- Kiểu dữ liệu giá trị
- Kiểu dữ liệu tham chiếu

### Kiểu dữ liệu nguyên thủy và kiểu người dùng tự định nghĩa

#### Kiểu dữ liệu nguyên thủy (Primitive Data Types) trong C#

là kiểu các kiểu dữ liệu mặc định được C# cung cấp sẵn.
Các kiểu dữ liệu nguyên thủy trong C# bao gồm:
| Ký hiệu| .NET Class| Kiểu dữ liệu| Độ rộng (bit) | Miền giá trị|
| --- | --- | --- | --- | --- |
| **byte**| Byte| Unsigned integer| 8| từ 0 đến 255|
| **sbyte**| SByte| Signed integer| 8| từ -128 đến 127|
| **int**| Int32| Signed integer| 32| từ -2,147,483,648 đến 2,147,483,647|
| **uint**| Int32| Unsigned integer| 32| từ 0 đến 4,294,967,295|
| **short**| Int16| Signed integer| 16| từ -32,768 đến 32,767|
| **ushort**| UInt16| Unsigned integer| 16| từ 0 đến 65,535|
| **long**| Int64| Signed integer| 64| từ -9,223,372,036,854,775,808 đến 9,223,372,036,854,775,807|
| **ulong**| UInt64| Unsigned integer| 64| từ 0 đến 18,446,744,073,709,551,615|
| **float**| Single| Single-precision floating point type| 32| từ -3.402823**e**38 đến 3.402823**e**38 |
| **double**| Double| Double-precision floating point type| 32| từ -1.797,693,134,862,32**e**308 đến 1.797,693,134,862,32**e**308|
| **char**| Char| A single Unicode character| 16| từ 0 đến 4,294,967,295|
| **bool** | Boolean| Logical boolean type | 8| true hoặc false|
| **object** | Object| Base type of all other types | | |
| **string** | String| A sequence of characters | | |
| **decimal** | Decimal| Logical boolean type |128 | từ +-1.0 x 10**e**-28 đến +-7.9 x 10**e**28 |

#### Kiểu dữ liệu người dùng tự định nghĩa

Là kiểu dữ liệu dữ liệu được lập trình viên định nghĩa dựa trên các kiểu dữ liệu nguyên thủy hoặc kiểu dữ liệu tự định nghĩa khác. Chúng ta sẽ tìm hiểu kĩ hơn về phần này trong loạt bài về Class, interface, struct trong C#

### Kiểu tham chiếu và kiểu tham trị

#### Kiểu dữ liệu tham trị

Một biến khi khai báo kiểu dữ liệu tham trị thì vùng nhớ của biến đó sẽ lưu trữ giá trị của đối tượng lưu trữ (khác với kiểu tham chiếu biến chứa địa chỉ trỏ đến nơi lưu đối tượng thực). Giá trị này được lưu trữ trong bộ nhớ **Stack**.

#### Kiểu dữ liệu tham chiếu

Một biến khi khai báo kiểu dữ liệu tham chiếu thì vùng nhớ của biến đó chỉ chứa địa chỉ của đối tượng dữ liệu và lưu trong bộ nhớ **Stack**. Dữ liệu thực sự được lưu trong bộ nhớ **Heap**.

![Vùng nhớ lưu trữ giá trị và địa chỉ của biến](https://user-images.githubusercontent.com/50008521/193491385-b3f741d6-6365-4d57-aa63-36b726ddf736.jpg)

Dữ liệu thuộc kiểu tham chiếu: object, dynamic, string, kiểu dữ liệu người dùng tự định nghĩa.
