---
title: "Lớp Object trong Java"
description: "Lớp object là lớp cơ sở nhất, định nghĩa hầu như tất cả những phương thức phần cơ bản để các lớp con cháu của nó sử dụng trực tiếp hoặc viết đè"
keywords:
  [
    "class object trong java",
    "class và object trong java",
    "khai báo object trong java",
    "lớp object trong java",
    "lớp object trong java bị lỗi",
    "lớp object trong java code",
    "lớp object trong java cơ bản",
    "lớp object trong java ebook",
    "lớp object trong java fpt",
    "lớp object trong java free",
  ]
author:
  fullname: Techmely Team
  username: Techmely Team
  avatar: "/configs/author/logo.jpg"
chapter:
  name: "Lập trình hướng đối tượng"
  slug: "chuong-03-lap-trinh-huong-doi-tuong"
category:
  logo: "/language/java.png"
  name: "Java"
  slug: "java"
  description: "Học Java từ cơ bản đến thông thạo cho mọi đối tượng"
image: https://user-images.githubusercontent.com/29374426/131332846-f14a1cc6-dca3-40a8-a0ae-003a31abdae1.png
position: 18
---

Các lớp cơ bản, hay sử dụng của Java như: **Object**, các lớp **Wrapper** (lớp bao của các kiểu dữ liệu nguyên thủy), **Math, String** và lớp **StringBuffer**... Những lớp này được xây dựng trong gói java.lang (gói mặc định của Java, khi cần sử dụng các lớp trong gói này ta không cần phải import nó). Mọi lớp trong Java đều là lớp con của lớp **Object**

## Lớp Object

Tất cả các lớp được xây dựng trong các chương trình Java đều hoặc là trực tiếp hoặc gián tiếp được mở rộng từ lớp Object. Đây là lớp cơ sở nhất, định nghĩa hầu như tất cả những phương thức phần cơ bản để các lớp con cháu của nó sử dụng trực tiếp hoặc viết đè.

![image](https://user-images.githubusercontent.com/29374426/131332846-f14a1cc6-dca3-40a8-a0ae-003a31abdae1.png)

Lớp Object cung cấp một vài cách xử lý chung cho tất cả các đối tượng như đối tượng có thể được so sánh, đối tượng có thể được cloned, đối tượng có thể được notified...

## Các phương thức của lớp Object

| Phương thức | Mô tả |
| --- | --- |
| public final Class getClass() | Trả lại tên lớp của đối tượng hiện thời |
| public int hashCode() | Trả về số hashcode cho đối tượng hiện tại. Khi các đối tượng được lưu vào các bảng băm (hash table), hàm này có thể sử dụng để xác định duy nhất giá trị cho mỗi đối tượng. Điều này đảm bảo tính nhất quán của hệ thống khi thực hiện chương trình. |
| public boolean equals(Object obj) | Cho lại kết quả true khi đối tượng hiện thời và obj là cùng một đối tượng. Hàm này thường được viết đè ở các lớp con cho phù hợp với ngữ cảnh so sánh bằng nhau trong các lớp mở rộng đó |
| protected Object clone() throws CloneNotSupportedException | Đối tượng mới được tạo ra có cùng các trạng thái như đối tượng hiện thời khi sử dụng clone(), nghĩa là tạo ra bản copy mới của đối tượng hiện thời |
| public String toString() | Nếu các lớp con không viết đè hàm này thì nó sẽ trả lại dạng biểu diễn văn bản (textual) của đối tượng. Hàm println() ở lớp PrintStream sẽ chuyển các đối số của nó sang dạng văn bản khi sử dụng hàm toString() |
| protected void finalize() throws Throwable | Hàm này được gọi ngay trước khi đối tượng bị dọn vào “thùng rác”, nghĩa là trước khi đối tượng đó bị huỷ bỏ. |
| public final void notify() | Đánh thức một luồng, đợi trình giám sát của đối tượng hiện tại |
| public final void notifyAll() | đánh thức tất cả các luồng. đợi trình giám sát của đối tượng hiện tại |
| public final void wait(long timeout)throws InterruptedException | Làm cho Thread hiện tại đợi trong khoảng thời gian là số mili giây cụ thể, tới khi Thread khác thông báo (gọi phương thức notify() hoặc notifyAll()). |
| public final void wait(long timeout,int nanos)throws InterruptedException | làm cho Thread hiện tại đợi trong khoảng thời gian là số mili giây và nano giây cụ thể, tới khi Thread khác thông báo (gọi phương thức notify() hoặc notifyAll()). |
| public final void wait()throws InterruptedException | làm Thread hiện tại đợi, tới khi Thread khác thông báo (gọi phương thức notify() hoặc notifyAll()). |
