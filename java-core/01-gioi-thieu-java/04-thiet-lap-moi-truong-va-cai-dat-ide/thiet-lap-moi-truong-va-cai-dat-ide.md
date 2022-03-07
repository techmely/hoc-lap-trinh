---
title: "Thiết lập môi trường và cài đặt IDE"
description: "Bài này chúng ta sẽ tìm hiểu về cơ hội nghề nghiệp với Java"
keywords:
  [
    "học java",
    "tự học java",
    "tự học lập trình java",
    "tu hoc lap trinh java",
    "học java fpt",
    "học java thaycacac",
    "học lập trình ngôn ngữ java",
    "hoc lap trinh ngon ngu java",
    "tự học lập trình với java",
    "tự học lập trình java",
    "cach thiet lap moi truong trong java",
    "cach cai dat ide",
    "cách thiết lập môi trường và cài đặt ide trong java",
  ]
chapter:
  name: "Giới thiệu Java"
  slug: "chuong-01-gioi-thieu-java"
category:
  logo: "/language/java.png"
  name: "Java"
  slug: "java"
  description: "Học Java từ cơ bản đến thông thạo cho mọi đối tượng"
image: https://user-images.githubusercontent.com/29374426/126056653-c45effaa-d29d-4e4d-857d-845388633329.png
position: 4
---

Bước 1: Download Netbeans tại: [https://www.oracle.com/technetwork/java/javase/downloads/jdk-netbeans-jsp-3413139-esa.html](https://www.oracle.com/technetwork/java/javase/downloads/jdk-netbeans-jsp-3413139-esa.html). Bạn nhớ chọn Netbeans With JDK.

Bước 2: Tiến hành cài đặt chương trình như các chương trình thông thường khác.

Bước 3: Mở Netbeans sau đó chọn File -> New Project

![thiet-lap-moi-truong-va-cai-dat-ide](https://user-images.githubusercontent.com/29374426/129512215-3dfa4f02-33ef-4fe6-9d1b-565239693fd9.png)

Bước 4: Chọn Java Application

![thiet-lap-moi-truong-va-cai-dat-ide](https://user-images.githubusercontent.com/29374426/129512231-bb0b611c-a729-412f-8406-4bb55fa18a3c.png)

Bước 5: Điền tên Project Name và chọn đường dẫn lưu ứng dụng. Lưu ý là tên class main phải trùng với tên class chúng ta khai báo trong mã nguồn.

![thiet-lap-moi-truong-va-cai-dat-ide](https://user-images.githubusercontent.com/29374426/129512240-d4f36cd7-46ed-49bf-a987-eed66ac8c1a6.png)

Bước 6: Xóa hết mã có sẵn trong class HelloWorldApp và chèn đoạn mã sau vào

```java
public static void main(String[] args) {
  System.out.println("Hello world");
}
```

![thiet-lap-moi-truong-va-cai-dat-ide](https://user-images.githubusercontent.com/29374426/129512251-96d18e6f-0e93-4ad7-91eb-565495b9d205.png)

Bước 7: Thực thi ứng dụng bằng cách ấn Shift+F6. Nếu xuất hiện thông báo màu xanh Build Sucess là bạn đã thành công.

![thiet-lap-moi-truong-va-cai-dat-ide](https://user-images.githubusercontent.com/29374426/129512259-3d7c67df-fdb1-46a5-bcc4-8c7a00b17107.png)

Netbeans và Eclipse là những IDE rất lý tưởng đối với các bạn đang bước đầu học Java. IDE sẽ giúp bạn giảm thiểu các lỗi cú pháp, gợi ý các function (bạn sử dụng phím ctr+space để xổ các hàm được gợi ý), debug, refactor, tự động import thư viện.
