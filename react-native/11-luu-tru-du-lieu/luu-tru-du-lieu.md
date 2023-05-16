---
title: "Lưu trữ dữ liệu"
description: "React-Native mặc định hỗ trợ chức năng lưu trữ thông qua AsyncStorage được cung cấp mặc định trong gói thư viện react-native. Xem phần Storage phía dưới để tìm hiểu thêm về phương pháp lưu trữ này. Bên cạnh đó mình xin được giới thiệu phương pháp lưu trữ theo dạng dữ liệu có cấu trúc sử dụng realm database"
keywords:
  [
    "gioi thieu react native",
    "giới thiệu react native",
    "khoá học react native",
    "giới thiệu react native",
    "giới thiệu react native cơ bản",
    "react native la gi",
    "tong quan ve react native",
    "gioi thieu ve ngon ngu lap trinh react native",
    "tom tat react native",
    "code react native la gi",
  ]
chapter:
  name: "Lưu trữ dữ liệu"
  slug: "chuong-11-luu-tru-du-lieu"
category:
  name: "React Native"
  slug: "react-native"
image: https://kungfutech.edu.vn/thumbnail.png
position: 11
---

React-Native mặc định hỗ trợ chức năng lưu trữ thông qua AsyncStorage được cung cấp mặc định trong gói thư viện react-native. Xem phần Storage phía dưới để tìm hiểu thêm về phương pháp lưu trữ này. Bên cạnh đó mình xin được giới thiệu phương pháp lưu trữ theo dạng dữ liệu có cấu trúc sử dụng realm database. Theo bản thân mình realm được đánh giá là một trong những thư viện hỗ trợ database tốt và tối ưu cho dân lập trình trên các dòng mobile hiện tại.

## AsyncStorage

Bởi vì AsyncStorage chạy bất đồng bộ vì vậy mình chỉ sử dụng AsyncStorage để lưu một số config của ứng dụng ví dụ như user data hay language code ..., những dữ liệu quan trọng và có cấu trúc thường mình sẽ sử dụng database để lưu trữ, truy xuất nhanh và dễ dàng hơn.

import thư viện AsyncStorage:

```javascript
import { AsyncStorage } from "react-native";
```

Sử dụng thư viện:

```javascript
// lưu trữ dữ liệu theo dạng key -> value (nếu value là một đối tượng thì nên chuyển đổi về JSON trước sử dụng JSON.stringify(obj))
AsyncStorage.setItem("language", "vi");

//Đọc giá trị lên và sử dụng.
AsyncStorage.getItem("language").then((result) => {
  console.log(result); //in ra màn hình console: vi
});
```
