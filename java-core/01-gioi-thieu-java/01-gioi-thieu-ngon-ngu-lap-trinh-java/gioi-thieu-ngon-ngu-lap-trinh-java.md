---
title: "Giới thiệu ngôn ngữ lập trình Java"
description: "Bài này sẽ cung cấp cho các bạn về khái niệm, kiến thức cơ bản liên quan đến việc lập trình ứng dụng bằng ngôn ngữ Java như: lịch sử phát triển của java, các đặc điểm của java, khái niệm máy ảo, cấu trúc của một chương trình đơn giản viết bằng Java cũng như cách xây dựng, dịch và thực thi một chương trình Java"
keywords:
  [
    "giới thiệu ngôn ngữ lập trình java",
    "giới thiệu ngôn ngữ java",
    "java là gì",
    "lập trình java là gì",
    "tìm hiểu ngôn ngữ java",
    "tim hieu ngon ngu java",
    "tự học java",
    "tu hoc java",
  ]
chapter:
  name: "Giới thiệu Java"
  slug: "chuong-01-gioi-thieu-java"
category:
  name: "Java"
  slug: "java"
image: https://user-images.githubusercontent.com/29374426/126056559-263bdade-6b6c-4e64-83a7-e21411391d64.png
position: 1
---

Bài này sẽ cung cấp cho các bạn về khái niệm, kiến thức cơ bản liên quan đến việc lập trình ứng dụng bằng ngôn ngữ Java như: lịch sử phát triển của java, các đặc điểm của java, khái niệm máy ảo, cấu trúc của một chương trình đơn giản viết bằng Java cũng như cách xây dựng, dịch và thực thi một chương trình Java.

## Java là gì?

![Java là gì](https://user-images.githubusercontent.com/29374426/126056559-263bdade-6b6c-4e64-83a7-e21411391d64.png)

Java là một trong những ngôn ngữ lập trình phổ biến nhất trên thế giới hiện nay. Nó được chính thức ra mắt vào ngày 23 tháng 5 năm 1995.

Java là ngôn ngữ lập trình bậc cao, được phát triển bởi **Sun Microsystems**, do **James Gosling** khởi xướng và phát hành như là một thành phần cốt lõi của nền tảng Java của **Sun Microsystems (Java 1.0 [J2SE])**. Java chạy trên rất nhiều nền tảng khác nhau, như **Windows**, **Mac** và các phiên bản khác nhau của **UNIX**. 

Java được hiểu là một loại ngôn ngữ lập trình hướng đối tượng (OOP) và dựa trên các lớp. Không giống với những ngôn ngữ lập trình thông thường, thay vì việc biên dịch mã nguồn trở thành mã nguồn máy hoặc trực tiếp thông dịch mã nguồn khi chạy thì Java được thiết kế để biên dịch mã nguồn thành bytecode. Sau đó, bytecode sẽ được môi trường thực thi (runtime environment).

## Lịch sử phát triển của ngôn ngữ lập trình Java

Ngôn ngữ lập trình Java do James Gosling và các công sự của Công ty Sun Microsystem phát triển.

Đầu thập niên 90, Sun Microsystem tập hợp các nhà nghiên cứu thành lập nên nhóm đặt tên là Green Team. Nhóm Green Team có trách nhiệm xây dựng công nghệ mới cho ngành điện tử tiêu dùng. Để giải quyết vấn đề này nhóm nghiên cứu phát triển đã xây dựng một ngôn ngữ lập trình mới đặt tên là Oak tương tự như C++ nhưng loại bỏ một số tính năng nguy hiểm của C++ và có khả năng chạy trên nhiều nền phần cứng khác nhau. Cùng lúc đó world wide web bắt đầu phát triển và Sun đã thấy được tiềm năng của ngôn ngữ Oak nên đã đầu tư cải tiến và phát triển. Sau đó không lâu ngôn ngữ mới với tên gọi là Java ra đời và được giới thiệu năm 1995.

Java là tên gọi của một hòn đảo ở Indonexia, Đây là nơi nhóm nghiên cứu phát triển đã chọn để đặt tên cho ngôn ngữ lập trình Java trong một chuyến đi tham quan và làm việc trên hòn đảo này. Hòn đảo Java này là nơi rất nổi tiếng với nhiều khu vườn trồng cafe, đó chính là lý do chúng ta thường thấy biểu tượng ly café trong nhiều sản phẩm phần mềm, công cụ lập trình Java của Sun cũng như một số hãng phần mềm khác đưa ra.

## Một số đặc điểm của Java

- **Hướng đối tượng**: Trong Java, mọi thứ đều là Object. Java có thể mở rộng vì nó dựa trên mô hình Object.
- **Nền tảng độc lập**: Không giống như nhiều ngôn ngữ lập trình khác (C, C++), khi Java được biên dịch, nó không biên dịch sang một máy tính cụ thể trên nền tảng nào, thay vào đó là những byte code độc lập với nền tảng. Byte code này được phân phối trên web và được thông dịch bằng Virtual Machine (JVM) trên bất cứ nền tảng nào mà nó đang chạy.
- **Đơn giản**: Java được thiết kế để dễ học. Nếu bạn hiểu cơ bản về khái niệm lập trình hướng đối tượng Java, thì có thể nắm bắt ngôn ngữ này rất nhanh.
- **Bảo mật**: Với tính năng an toàn của Java, nó cho phép phát triển những hệ thống không có virus, giả mạo. Các kỹ thuật xác thực dựa trên mã hóa công khai.
- **Kiến trúc trung lập**: Trình biên dịch của Java tạo ra một định dạng file object có kiến trúc trung lập, làm cho code sau khi biên dịch có thể chạy trên nhiều bộ vi xử lý, với sự hiện diện của Java runtime system.
- **Mạnh mẽ**: Java nỗ lực loại trừ những tình huống dễ bị lỗi bằng cách nhấn mạnh chủ yếu là kiểm tra lỗi thời gian biên dịch và kiểm tra runtime.
- **Đa luồng**: Với tính năng đa luồng của Java, bạn có thể viết các chương trình có thể thực hiện nhiều tác vụ đồng thời. Tính năng này cho phép các nhà phát triển xây dựng các ứng dụng tương tác có thể chạy trơn tru.
- **Thông dịch**: Byte code của Java được dịch trực tiếp tới các nền tảng gốc và nó không được lưu trữ ở bất cứ đâu. 
- **Hiệu suất cao**: Với việc sử dụng trình biên dịch Just-In-Time, Java cho phép thực thi với hiệu suất cao, nhanh chóng phát hiện, gỡ lỗi.
- **Phân tán**: Java được thiết kế cho môi trường phân tán của Internet.
- **Linh động**: Java được coi là năng động hơn C hay C++ vì nó được thiết kế để thích nghi với môi trường đang phát triển. Các chương trình Java có thể mang theo một lượng lớn thông tin run-time, được sử dụng để xác minh và giải quyết các truy cập đến đối tượng trong thời gian chạy.

## Ứng dụng của JAVA

Có 4 loại ứng dụng chính mà có thể được tạo bởi sử dụng ngôn ngữ lập trình Java:

- **Standalone App**  
Nó còn được biết đến với tên gọi khác là **Destop App** hoặc **Windows-based App**. Một ứng dụng mà chúng ta cần cài đặt trên mỗi thiết bị như media player, antivirus... **AWT** và **Swing** được sử dụng trong Java để tạo các **Standalone App**.
- **Web App**  
Một ứng dụng mà chạy trên **Server Side** và tạo **Dynamic Page**, được gọi là **Web App**. Hiện tại, các công nghệ Servlet, JSP, Struts, JSF... được sử dụng để tạo **Web App** trong Java.
- **Enterprise App**  
Một ứng dụng dạng như **Banking App**, có lợi thế là tính bảo mật cao, cân bằng tải (load balancing) và clustering. Trong java, **EJB** được sử dụng để tạo các **Enterprise App**.
- **Mobile App**  
Đây là loại ứng dụng được tạo cho thiết bị mobile. Hiện tại thì **Android** và **Java ME** được sử dụng để tạo loại ứng dụng này.

## Tại sao nên học Java?

- Đây là một trong những ngôn ngữ lập trình phổ biến nhất trên thế giới
- Nó rất dễ học và đơn giản để sử dụng
- Nó là nguồn mở và miễn phí
- Nó có một sự hỗ trợ cộng đồng lớn (hàng chục triệu nhà phát triển)
- Vì Java gần với C++ và C# , nên các lập trình viên dễ dàng chuyển sang Java hoặc ngược lại.
