---
title: "Kỹ thuật Debug cơ bản"
description: "Xây dựng ứng dụng React-Native khác với ứng dụng native là bạn không thể đặt break point rồi chạy và chờ chương trình nhảy vào vị trí mà bạn đợi và xem trạng thái hay biến lúc đó bằng bao nhiêu đang như thế nào."
chapter:
  name: "Làm quen với react native"
  slug: "chuong-03-lam-quen-voi-react-native"
image: https://kungfutech.edu.vn/thumbnail.png
position: 2
---

Xây dựng ứng dụng React-Native khác với ứng dụng native là bạn không thể đặt break point rồi chạy và chờ chương trình nhảy vào vị trí mà bạn đợi và xem trạng thái hay biến lúc đó bằng bao nhiêu đang như thế nào. Thay vì vậy chương trình React-Native cho phép bạn in giá trị tại thời điểm đó và xuất ra màn hình console.

Sử dụng lệnh `console.log(variable)` để in giá trị của biến bất kì (xem ví dụ phía trên để biết việc in giá trị của biến message trong state)

Xcode và Android studio mặc định khi run debug sẽ xuất các log này ra trong phần All Output (Xcode), Logcat (Android Studio).

Bên cạnh đó bạn có thể sử dụng chức năng Debug JS Remotely (xem phần hiển thị menu điều khiển trong mục 4) để thấy các log này trong phần console của trình duyệt web.

Ngoài ra bạn có thể sử dụng terminal (cmd) để xem log IOS hoặc Android bằng cách gõ lệnh:

```bash
react-native log-ios
# or
react-native log-android
```
