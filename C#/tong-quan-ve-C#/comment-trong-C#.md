—
title:”Chú thích (comment) trong C#”
description:”Trong bài này mình sẽ giới thiệu chú thích trong lập trình để làm gì và các cách chú thích trong C#.”
keywords:[
“chú thích trong C#”,
“comment trong C#”,
“chu thich trong C#”
]
chapter:—
title:”Chú thích (comment) trong C#”
description:”Trong bài này mình sẽ giới thiệu chú thích trong lập trình để làm gì và các cách chú thích trong C#.”
keywords:[
“chú thích trong C#”,
“comment trong C#”,
“chu thich trong C#”
]
chapter:
name: ”Chú thích (comment) trong C#”
slug: “chu-thich-trong-C#”
categoy:
name: "C#"
slug: "C#"
image: <https://kungfutech.edu.vn/thumbnail.png>
position: 6
—

## Giới thiệu

Trong bài viết này chúng ta sẽ tìm hiều về chú thích (comment) trong C#. Các kiểu chú thích khác nhau và tại sao ta phải sử dụng chú thích khi lập trình.

Chú thích (comment) trong mã nguồn giúp cho các đoạn code của bạn chở nên dễ hiểu hơn. Khi người mới đọc đoạn code đó hoặc chính bạn khi đọc lại cũng sẽ nhanh chóng hiểu được ý đồ thể hiện trong từng dòng code. Các dòng comment sẽ được trình biên dịch bỏ qua. Vì vậy chúng ta có thể sử viết comment một cách tự do sao cho phù hợp với quy định của từng dự án.

## Các kiểu Comment trong C#

C# có 3 kiểu Comment khác nhau
* Comment trên 1 dòng
* Comment trên nhiều dòng
* Comment cho hàm, phương thức, interface hoặc class (XML Comment)

### Comment trên 1 dòng

Comment trên một dòng sẽ bắt đầu bằng dấu `//`. Trình biên dịch sẽ bỏ qua tất cả đoạn code đằng sau dấu `//` trên dòng code đó. Ví dụ:

```
int a = 5 + 7; // Cộng 5 với 7
```
### Comment trên nhiều dòng

Comment trên nhiều dòng sẽ bắt đầu bằng dấu `/*` và kết thúc bằng dấu `*/`.  Trình biên dịch sẽ bỏ qua tất cả đoạn code nằm giữa dấu `/*` và dấu  `*/`.

### Comment cho hàm, phương thức, interface hoặc class (XML Comment)

Đây là một loại Comment đặc biệt trong C#. Nó bắt đầu bằng dấu `///` ở mỗi dõng và nó sử dụng thêm các thẻ ( do từng dự án quy định) để làm rõ nghĩa cho comment. Loại comment này có cấu trúc giống với một đoạn mã XML nên còn được gọi là (XLM documentation Comments). Trình biên dịch sẽ bỏ qua tất cả đoạn code đằng sau dấu `///` trên dòng code đó. Ví dụ:

```
/// <summary>
///  This is a hello world program.
/// </summary>

using System;

namespace HelloWorld
{
	class Program
	{
		public static void Main(string[] args)
		{
			Console.WriteLine("Hello World!");
		}
	}
}
```

Trong ví dụ trên ta dùng thẻ <summary> (Theo quy định từng dự án) để bổ nghĩa Cho ý nghĩa tổng quan của chương trình. 

Trong tài liệu của microsoft đưa ra danh sách gợi ý gồm 18 thẻ hay sử dụng trong mã nguồn C#. Các bạn có thể tham khảo ở link bên dưới:

https://learn.microsoft.com/en-us/dotnet/csharp/language-reference/language-specification/documentation-comments#d310-paramref

## Sử dụng comment sao cho đúng

Comment là cách hữu hiệu để giải thích mã nguồn nhưng chúng ta không được lạm dụng nó quá mức. Ví dụ:

```
// In ra dòng chứ Hello World
Console.WriteLine("Hello World");
```

Comment như kiểu trên là không cần thiết. Thay vào đó khi sử dụng Comment chúng ta nên lưu ý những điều sau:

* Comment để giải thích các thuật toán phức tạp và các công nghệ được sử dụng trong dự án.
* Comment phải ngắn gọn và dễ hiểu.
* Comment nên giải thích "lý do tại sao" thay vì giải thích "làm như thể nào"
