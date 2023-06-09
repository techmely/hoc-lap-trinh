---
title: "Chuyển đổi giữa các màn hình"
description: "Một ứng dụng bạn phát triển không thể chỉ có một màn hình. Vì vậy bạn phải biết cách chuyển đổi qua lại giữa các màn hình. Hiện tại mình sử dụng thư viện react-navigation (v.2.18.1) để chuyển đổi giữa các màn hình. Các bạn có thể tìm hiểu thêm về thư viện này tại (<https://reactnavigation.org>)"
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
  name: "Tương tác trong react native"
  slug: "chuong-05-tuong-tac-trong-react-native"
category:
  name: "React Native"
  slug: "react-native"
image: https://kungfutech.edu.vn/thumbnail.png
position: 3
---

## Chuyển đổi giữa các màn hình

Một ứng dụng bạn phát triển không thể chỉ có một màn hình. Vì vậy bạn phải biết cách chuyển đổi qua lại giữa các màn hình. Hiện tại mình sử dụng thư viện react-navigation (v.2.18.1) để chuyển đổi giữa các màn hình. Các bạn có thể tìm hiểu thêm về thư viện này tại (<https://reactnavigation.org>)

**Cài đặt thư viện**

Vào dự án bạn tạo và chạy dòng lệnh sau để cài đặt thư viện

`npm install --save react-navigation`

**Sử dụng thư viện**

Xây dựng cấu trúc ứng dụng: Dưới đây là phần tạo cấu trúc sườn của ứng dụng dựa vào StackNavigator của thư viện react-navigation.

```javascript
import React, { Component } from "react";
import { StackNavigator } from "react-navigation";
import { StyleSheet, View } from "react-native";

// import toàn bộ các class Screen từ modules/screens (những class được xuất thông qua file modules/screens/index.js)
import * as Screens from "./modules/screens";

//Tạo StackNavigator từ thư viện react-navigation
const AppNavigator = StackNavigator(
  {
    HOME: {
      screen: Screens.Home,
    },
    STYLES: {
      screen: Screens.StyleDemo,
    },
    COMPONENT: {
      screen: Screens.Components,
    },
    PROPS: {
      screen: Screens.Props,
    },
  },
  {
    headerMode: "screen",
  }
);

export default class App extends Component {
  render() {
    return (
      <View style={styles.container}>
        {/*Vẽ stack ứng dụng ra màn hình*/}
        <AppNavigator />
      </View>
    );
  }
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
  },
});
```

Như bạn thấy ở trên ta khai báo 1 ứng dụng có 4 màn hình HOME, STYLES, COMPONENT, PROPS. Mặc định màn hình nào ở trên cùng sẽ được xuất hiện đầu tiên.

Nội dung mỗi màn hình có dạng:

```js
HOME: {
  screen: Screens.Home;
}
```

Trong đó Screens.Home là class được import từ module screens.

Lưu ý dòng lệnh:

```js
import * as Screens from "./modules/screens";
```

Dòng lệnh này thực hiện import toàn bộ những class được xuất ra thông qua file index.js. Vì vậy nếu bạn thêm màn hình mới lưu ý vào file index.js để xuất thêm class bạn vừa tạo.

Chuyển đổi màn hình: có 2 cách chuyển màn hình:

- Chuyển đổi và xóa toàn bộ màn hình trước đó:

```js
// chuyển qua màn hình PROPS đã khai báo trong App StackNavigator
let pageContinue = NavigationActions.reset({
  index: 0,
  actions: [NavigationActions.navigate({ routeName: "PROPS", params: {} })],
});
this.props.navigation.dispatch(pageContinue);
```

params: {} - Đây là phần để bạn truyền dữ liệu qua màn hình kế tiếp. Bạn có thể truyền qua cho màn hình tiếp theo một đối tượng theo cú pháp này.

- Chuyển đổi và giữ lại màn hình trước để quay lại

```js
// chuyển qua màn hình PROPS đã khai báo trong App StackNavigator
this.props.navigation.navigate("PROPS");
//or
this.props.navigation.navigate("PROPS", {});
```

`{}` - Đây cũng là cách để bạn truyền một đối tượng qua cho màn hình kế tiếp.

Mặc định nếu bạn hiển thị Status bar thì sẽ có phím quay về, nhưng nếu cần thiết có thể quay về bằng cách gọi hàm sau đây:
`this.props.navigation.goBack();`

Hiển thị Status bar:

```js
static navigationOptions = ({ navigation }) => {
	return {
    	title: "PROPS",
    	headerStyle: {
        	backgroundColor: Colors.primary
    	},
    	headerTintColor: Colors.white,
    	headerTitleStyle: {
        	alignSelf: 'center'
    	}
	};
};
```
