---
title: "Trình lên lịch của Thread trong Java"
description: "Trình lên lịch của Thread (Thread scheduler) trong java là một phần của JVM có nhiệm vụ quyết định thread nào nên được chạy."
keywords:
  [
    "Trình lên lịch của Thread",
    "Thread scheduler trong java",
    "cách hoạt động của trình lên lịch của thread",
    "cách hoạt động của Thread scheduler",
  ]
author:
  fullname: Techmely Team
  username: Techmely Team
  avatar: "/configs/author/logo.jpg"
chapter:
  name: "Lập trình đa luồng"
  slug: "chuong-06-lap-trinh-da-luong"
category:
  logo: "/language/java.png"
  name: "Java"
  slug: "java"
  description: "Học Java từ cơ bản đến thông thạo cho mọi đối tượng"
image: https://user-images.githubusercontent.com/29374426/146302578-b037c1d6-4274-4153-b0d0-8b7ff37ec592.png
position: 4
---

## Trình lên lịch của Thread trong Java là gì?

Trình lên lịch của Thread (Thread scheduler) trong java là một phần của JVM có nhiệm vụ quyết định `thread` nào nên được chạy.

Không có sự đảm bảo rằng `thread` có trạng thái `runnable` nào sẽ được chọn để chạy bởi `thread scheduler`.

Chỉ có một `thread` tại một thời điểm có thể chạy trong một xử lý duy nhất.

`Thread scheduler` chủ yếu sử dụng việc lập kệ hoạch ưu tiên hoặc phân chia thời gian để lên lịch các luồng.

## Trình lên lịch của Thread hoạt động như thế nào?

Có hai yếu tố để lên lịch cho một luồng tức là **Mức độ ưu tiên** và **Thời gian đến**.

- **Mức độ ưu tiên:** mức độ ưu tiên của mỗi luồng nằm trong khoảng từ `1 đến 10`. Nếu một luồng có mức độ ưu tiên cao hơn, điều đó có nghĩa là luồng đó có cơ hội tốt hơn được Trình lên lịch luồng chọn.
- **Thời gian đến:** giả sử hai luồng có cùng mức độ ưu tiên nhập vào trạng thái chạy được, thì mức độ ưu tiên không thể là yếu tố để chọn một luồng từ hai luồng này. Trong trường hợp này, thời gian đến của luồng được xem xét bởi Trình lên lịch luồng. Một chủ đề đến trước sẽ được ưu tiên hơn các chủ đề khác.

Ví dụ có các thread được thể hiện ở bảng dưới đây:

| Thread | Thời gian đến |
| ------ | ------------- |
| t1     | 0             |
| t2     | 1             |
| t3     | 2             |
| t4     | 3             |

Trong bảng trên, chúng ta có thể thấy rằng Luồng t1 đã đến đầu tiên, sau đó đến Luồng t2, rồi đến t3, và cuối cùng là t4, và thứ tự mà các luồng sẽ được xử lý là theo thời gian đến của các luồng.

![Trình lên lịch của Thread](https://user-images.githubusercontent.com/29374426/146302543-fae9369b-d29d-44ba-ae46-9e7a7e244667.png)

Do đó, Luồng t1 sẽ được xử lý đầu tiên và Luồng t4 sẽ được xử lý sau cùng.

Thông thường, thuật toán `First Come First Serve` là non-preemptive, điều này không tốt vì nó có thể dẫn đến bị block vô hạn. Để tránh điều đó chúng sẽ đc cắt ra thành các lát và được cung cấp cho các luồng một thời gian để sau một thời gian, luồng đang chạy phải ra khỏi CPU. Do đó, các luồng chờ khác cũng có thời gian để thực hiện công việc của họ.

![Thread scheduler trong java](https://user-images.githubusercontent.com/29374426/146302578-b037c1d6-4274-4153-b0d0-8b7ff37ec592.png)

Trong sơ đồ trên, mỗi luồng được đưa ra một lát thời gian là 2 giây. Vì vậy, sau 2 giây, luồng đầu tiên ra khỏi CPU, và sau đó CPU được bắt bởi Thread2. Quá trình tương tự cũng lặp lại cho các chủ đề khác.

![Trình lập lịch trong java hoạt động như thế nào](https://user-images.githubusercontent.com/29374426/146302636-7747b558-0d09-4288-b705-1b05996da6a9.png)

Giả sử có nhiều luồng có sẵn ở trạng thái có thể chạy được. Trình lên lịch luồng chọn luồng có mức độ ưu tiên cao nhất. Vì thuật toán cũng có tính ưu tiên, do đó, các lát thời gian cũng được cung cấp cho các luồng để tránh bị starvation. Do đó, sau một thời gian, ngay cả khi luồng ưu tiên cao nhất chưa hoàn thành công việc của nó, nó vẫn phải giải phóng CPU vì quyền ưu tiên.

![Thread scheduler](https://user-images.githubusercontent.com/29374426/146302693-550682c9-0195-460c-a729-4fff335ad600.png)

Giả sử, có năm luồng có thời gian đến khác nhau và mức độ ưu tiên khác nhau. Bây giờ, trình lên lịch luồng có trách nhiệm quyết định luồng nào sẽ lấy CPU trước.

Trình lên lịch luồng chọn luồng có mức ưu tiên cao nhất và luồng bắt đầu thực hiện công việc. Nếu một luồng đã ở trạng thái có thể chạy được và một luồng khác (có mức ưu tiên cao hơn) đạt đến trạng thái có thể chạy được, thì luồng hiện tại được xóa trước từ bộ xử lý và luồng đến có mức độ ưu tiên cao hơn sẽ nhận được thời gian của CPU.

Khi hai luồng (Luồng 2 và Luồng 3) có cùng mức độ ưu tiên và thời gian đến, việc lập lịch sẽ được quyết định dựa trên thuật toán FCFS. Do đó, luồng đến trước sẽ có cơ hội thực thi trước.
