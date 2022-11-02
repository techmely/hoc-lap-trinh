---
title: "Tạo chương trình C# đầu tiên"
description: "Trong bài này mình sẽ giới thiệu cách cài đặt môi trường để các bạn có thể lập trình với C# và hướng dẫn tạo một chương trình C# đơn giản."
keywords: [
	"chương trình C# đầu tiên",
	"chuong trinh C# đau tien",
	"chương trình C# đơn giản",
	"chuong trinh C# đon gian",
	"cài đặt môi trường phát triển C#",
	"cai dat moi truong phat trien C#"
]
chapter:
  name: "Tổng quan về C#"
  slug: "chuong-01-tong-quan-ve-csharp"
categoy:
  name: "C#"
  slug: "C#"
image: https://kungfutech.edu.vn/thumbnail.png
position: 1
---

## Tạo ứng dụng C# đầu tiên với Visual Studio

 <content-info>
 Để tập trung vào các khía cạnh cốt lõi của C#, sẽ thực hành trên các ứng dụng loại C# Console (.NET Core) (loại ứng dụng dòng lệnh không sử dụng giao diện đồ họa GUI). Sau đó sẽ nâng cao dần với các loại ứng dụng như ASP.NET, WPF ...
 </content-info>

 <content-info>
 IDE (môi trường viết, biên dịch, debug) để phát triển ứng dụng C# bạn có thể chọn là Visual Studio hoặc Visual Studio Code (Đối với các bạn mới học lập trình, nên ưu tiên sử dụng Visual Studio).
 </content-info>

## Cài đặt môi trường phát triển C

Truy cập đường dẫn: <https://visualstudio.microsoft.com/downloads/.>
Microsoft cung cấp các công cụ phát triển sau cho lập trình C#:

- Visual Studio (VS)
- Visual C# Express (VCE)
- Visual Web Developer

**Các bước tiến hành**:

**Bước 1:** Ở màn hình bên dưới, nhấn nút Download, rồi tiến hành cài đặt

![image](https://user-images.githubusercontent.com/50008521/182108009-cf7f27e1-4fa2-4943-b7f6-20746089bcca.png)

<content-info>Đối với các bạn mới làm quen với C# chưa sử dụng đến nhiều chức năng phức tạp của visual studio thì các bạn nên chọn bản Community vì nó nhỏ gọn và miễn phí</content-info>

**Bước 2:** Mở file tải về lên và nhấn "Continue", trình cài đặt sẽ cài đặt file về máy tính bạn.

![image](https://user-images.githubusercontent.com/50008521/182108048-3410c353-a6bb-4ec8-b3d9-ac90dc6ce301.png)

![image](https://user-images.githubusercontent.com/50008521/182108095-a0d564f2-0001-4f94-93fd-2d32f8cc8b9e.png)

**Bước 3:** Mở tab "Workload". Tùy vào nhu cầu lập trình mà ta sẽ chọn các gói khác nhau. Ví dụ khi bạn muốn làm các dự án về web thì chọn mục "ASP.NET and web development".Sau đó bạn ấn cài đặt

![image](https://user-images.githubusercontent.com/50008521/182108144-68aa5294-ce2e-468c-af8c-72ebedf5e279.png)

**Bước 4:** Sau khi chờ hệ thống cài đặt xong, ta tiến hành restart lại hệ thống.
![image](https://user-images.githubusercontent.com/50008521/182108181-8771e2d1-7b55-4eb9-9993-754242f56f4e.png)

![image](https://user-images.githubusercontent.com/50008521/182108225-10daff0e-9ad1-47b8-b1a4-59f8054c863a.png)

**Bước 5:** Mở Visual Studio.
![image](https://user-images.githubusercontent.com/50008521/182108262-a152de22-b6a3-4600-9bf5-2c550494ede2.png)

Bạn có thể chọn đăng nhập hoặc không

![image](https://user-images.githubusercontent.com/50008521/182108299-68dd8f2e-1912-4ea7-8134-ec62c70816fe.png)

Chọn màu giao diện mà bạn muốn
Như vậy là ta đã hoàn thành việc cài đặt Visual Studio. Phần tiếp theo sẽ là hướng dẫn cách viết chương trình C# trên Visual Studio

## Viết chương trình C# đầu tiên

Sau khi tiến hành cài đặt xong Visual Studio, ta bật Visual Studio lên và thực hiện tạo dự án đầu tiên với **Console App**.

### Các bước tiến hành

**Bước 1:** Mở Visual Studio và nhấn vào **Create a new Project**

![image](https://user-images.githubusercontent.com/50008521/182108333-fee69ecc-f527-41d4-9e42-96985fa2faab.png)

**Bước 2:** Tiếp theo ta nhấn vào mục **Console App**

![image](https://user-images.githubusercontent.com/50008521/182108373-2a0bec81-588c-450d-99ae-7fa49646d2fd.png)

**Bước 3:** Tiếp theo ta nhập **Project name**( tên dự án), **Location**(nơi lưu trữ dự án), **Solution name**(tên giải pháp, 1 giải pháp sẽ có 1 hoặc nhiều dự án khác nhau bên trong). Sau khi nhập xong các trường trên ta ấn **Create**.

![image](https://user-images.githubusercontent.com/50008521/182108397-0243f8fc-7a22-41c6-b60f-ae881df674cc.png)

**Bước 4:** Visual Studio sẽ tạo ra ví dụ 1 dự án mặc đinh cho chúng ta như sau:
![image](https://user-images.githubusercontent.com/50008521/182108437-ec76bbfd-f99c-48ac-89ba-a6dcc8fb2ba3.png)
Dòng 1: là phần khai báo thư viện. C# sử dụng từ khóa **using** + tên tự viện để tiến hành khai báo.

<content-result>using System;</content-result>

Dòng 3: là khai báo **namespace**. **Namespace** trong C# được dùng để tổ chức quản lý code. Có thể tưởng tượng namespace như một cái hộp chứa, trong đó có thể chứa những chiếc hộp khác (namespace con) và các vật dụng (các kiểu dữ liệu như struct, class, interface).

<content-result>namespace HelloWorld</content-result>

Dòng 5: là tên **Class** . **Class** là bản mô tả những tính chất và hành vi chung của những gì tồn tại trong thực tế. "Những gì tồn tại trong thực tế" đó được gọi là các đối tượng (object) cụ thể. Từ các đối tượng cụ thể, chúng ta phân tích ra những điểm chung về thông tin và hoạt động để tạo thành **Class**.

<content-result>class Program</content-result>

Dòng 7: là tên hàm. Trong các dự án C# thì hàm đầu tiên được khởi chạy đó làm hàm **Main()**

<content-result>static void Main(string[] args)</content-result>

Dòng 8: phần thân hàm. Tại đây sẽ là nội dung của hàm Main. Trong ví dụ trên chúng ta thực hiện in dòng chữ _Hello World:_. Các bạn có thể tùy chỉnh nội dung mà bạn muốn in ra bằng cách thanh đổi nội dung giữa 2 dấu đóng mở ngoặc tròn.

<content-result>Console.WriteLine("Hello World!")</content-result>

Nhấn tổ hợp Ctrl + F5 hoặc phím mũi tên xanh góc trên ở giữa để thực hiện chạy chương trình.

![image](https://user-images.githubusercontent.com/50008521/182108488-997ecd1f-ef3d-45d5-aeaa-ebee9b99184f.png)
