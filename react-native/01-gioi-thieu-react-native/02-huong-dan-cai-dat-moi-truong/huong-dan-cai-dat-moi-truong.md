---
title: "Hướng dẫn cài đặt môi trường"
description: "Chào mừng các bạn đến với hướng dẫn học React-Native cho người mới bắt. Sau đây là một số chia sẻ, hướng dẫn của mình cho người mới bắt đầu tìm hiểu về React-Native. Qua đó nhằm giúp các bạn có cách nhìn tổng quát hơn và dễ dàng tìm hiểu vấn đề khi mới chập chững bước chân vào lập trình với React-Native."
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
  name: "Giới thiệu react native"
  slug: "chuong-01-gioi-thieu-react-native"
category:
  name: "React Native"
  slug: "react-native"
image: https://kungfutech.edu.vn/thumbnail.png
position: 2
---

## Hướng dẫn cài đặt môi trường react-native trên hệ điều hành Windows

- **Bước 1**: Cài đặt Chocolatey từ <https://chocolatey.org> (Chocolatey là trình quản lý các gói thư viện của Windows)
- **Bước 2**: Cài đặt Nodejs Java và Python 2 thông qua Chocolatey sử dụng dòng lệnh sau (dùng cmd để chạy lệnh này):

```bash
choco install -y nodejs.install python2 jdk8
```

- **Bước 3**: Cài đặt Android studio
- **Bước 4**: Cài đặt SDK: Nên cài SDK Platform 23 vì mặc định react-native hiện tại sử dụng Android SDK Platform 23 để build ứng dụng

Lưu ý: Trên hệ điều hành windows chỉ có thể build ứng dụng trên Android.

## Hướng dẫn cài đặt môi trường react-native trên hệ điều hành MAC OS

- **Bước 1**: Cài đặt Brew: Brew là trình quản lý các gói thứ viện, MACOS không tích hợp sẵn và bạn phải sử dụng terminal để cài đặt brew bằng cách chạy dòng lệnh sau.

```bash
/usr/bin/ruby -e "$(curl –fsSL https://raw.githubusercontent.com/ Homebrew/install/master/install)"
```

- **Bước 2**: Cài đặt Nodejs:
  `brew install node`
- **Bước 3**: Cài đặt Watchman:
  `brew install watchman`
- **Bước 4**: Cài đặt react-native:
  `npm install -g react-native-cli`
- **Bước 5**: Cài đặt Xcode: truy cập App Store trên MACOS để cài đặt Xcode.
- **Bước 6** (option): Nếu bạn xây dựng ứng dụng android sử dụng hệ điều hành MACOS thì bạn cần cài đặt thêm các gói như JDK, Android Studio, Android SDK. (xem thêm phần cài đặt cho Windonws để hiểu rõ hơn.)

## Các IDE khuyên dùng

- Code: Hiện tại mình sử dụng Visual Studio Code các bạn có thể download về và cài đặt tại <https://code.visualstudio.com/> Các bạn cũng có thể sử dụng bất kỳ IDE nào các bạn thích như Sublime Text Atom, Vim Editer...
- Build ứng dụng:
- IOS: sử dụng Xcode (search trên store apple nhé)
- Android: sử dụng Android studio <https://developer.android.com/studio/>

P/s: Nếu sử dụng MAC thì nên dùng Xcode để chạy ứng dụng. Bởi vì một số lý do như: Run các lần sau nhanh hơn, xem log debug mà không cần bật chức năng Debug JS Remotely và quan trọng là làm quen với một số chức năng của Xcode để lúc xảy ra lỗi fix lỗi nhanh hơn. Với Android thì có một vài trở ngại khi dùng Android studio như việc run mà không dùng code react-native mới nhất, chức năng host reloading cũng khó hoạt động.

## Khởi tạo dự án đầu tiên

- **Bước 1**: Khởi tạo dự án: mở Terminal (cmd) sau đó gõ lệnh này vào (cd vào thư mục bạn muốn tạo dự án trước)
  `react-native init ProjectName`
- **Bước 2**: Truy cập vào dự án vừa tạo.
  `cd ProjectName`
- **Bước 3**: Chạy ứng dụng trên hệ điều hành:
  - IOS: `react-native run-ios`
  - Android: `react-native run-android`

Khi chạy lệnh này hệ điều hành sẽ tạo một server local để build code react của bạn. Kèm theo đó là chạy các lệnh để build ứng dụng.Bạn cũng có thể mở file /ios/ProjectName.xcodeproj bằng Xcode để khởi chạy ứng dụng, hoặc mở nguyên thư mục android bằng Android studio để khởi chạy ứng dụng.

- **Hiển thị Menu điều khiển**:

  - Command + D (hoặc lắc điện thoại IOS) để hiển thị menu điều khiển khi run debug ứng dụng trên MacOS.
  - ctrl + D hoặc phím menu để hiển thị menu điều khiển khi run debug ứng dụng trên Windown.
  - Command + R để reload lại source code máy ảo IOS
  - R + R để reload lại source code máy ảo Android.

- **Một vài lệnh vui vui để sửa lỗi** (Bật terminal or cmd trong dự án vừa khởi tạo)

  - Không khởi tạo server để build khi run debug trên android thì chạy
    `react-native start`

  - Khi run Android mà không sử dụng code react-native mới nhất thì chạy dòng này (Build toàn bộ source của bạn thành 1 file và đặt nó vào trong assets, tạo các resource android tương ứng mà bạn sử dụng).

```bash
react-native bundle --platform android --dev false --entry-file index.js --bundle-output android/app/src/main/assets/index.android.bundle --assets-dest android/app/src/main/res
```

- Khi general APK mà bị lỗi double resource thì xóa thư mục drawable trong android/app/src/main/res thì sẽ build được.

- Khi run app ios bị lỗi "Build input file cannot be found: '../Example/node_modules/react-native/third-party/double-conversion-1.1.6/src/strtod.cc'" thì chạy 2 dòng lệnh sau:

```bash
cd node_modules/react-native/scripts && ./ios-install-third-party.sh && cd ../../../
cd node_modules/react-native/third-party/glog-0.3.5/ && ../../scripts/ios-configure-glog.sh && cd ../../../../
```

Chú ý version phiên bản glog (0.3.5) mà bạn đang sử dụng.

## Các thành phần cơ bản của dự án

Cấu trúc thư mục mà bạn nhìn thấy có thể sẽ như dưới đây (tùy version react-native hiện tại của bạn). Hình dưới đây không bao gồm một vài file bị ẩn thuộc cấu hình của react-native

![Các thành phần cơ bản của dự án react native](https://github.com/techmely/hoc-lap-trinh/assets/29374426/3c428a2d-d2f8-4eb6-ba1f-5779ed0c0262)

- **Thư mục Android**: chứa toàn bộ source build ứng dụng Android. Chúng ta có thể mở thư mục Android bằng Android studio và chạy ứng dụng thay vì sử dụng dòng lệnh `react-native run-android` nhưng có thể ứng dụng sẽ không build mã javascript được và sẽ xuất hiện màn hình trắng trên điện thoại android.
- **Thư mục IOS**: chứa toàn bộ source build ứng dụng IOS. Chúng ta có thể mở file ProjectName.xcodeproj bằng Xcode để run ứng dụng IOS thay vì sử dụng dòng lệnh `react-native run-ios`. Lần đầu có thể chạy hơi lâu nhưng những lần tiếp theo sẽ nhanh hơn việc build bằng dòng lệnh.
- **Thư mục node_modules**: chứa toàn bộ các package (thư viện) cần để chạy một ứng dụng react-native.
- **File package.js**: file quản lý các package nodejs đi kèm với dự án. Nếu bạn tải các dự án demo về cần dử dụng dòng lệnh `npm install` để tải toàn bộ thư viện yêu cầu của dự án về.
- **File package-lock.js** file được general sau khi chạy cài đặt `npm install`
- **File index.js**: file đầu tiên được binding khi chạy ứng dụng. File này sẽ đăng ký một component, component này sẽ được load lên đầu tiên khi chạy, mặc định ứng dụng sẽ đăng ký component trong App.js
- **File app.json**: file config tên ứng dụng và tên hiển thị.
- **File App.js** là một component mặc định có sử dụng một số Component khác như Text, View...
