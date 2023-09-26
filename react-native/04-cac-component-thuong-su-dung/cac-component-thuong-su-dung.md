---
title: "Các component thường sử dụng"
description: "Dưới đây là code demo những component cơ bản thường sử dụng. Bạn có thể code lại, copy hoặc chạy demo từ example (demo có sử dụng hình ảnh nên bạn phải copy hình ảnh trong example"
chapter:
  name: "Các component thường sử dụng"
  slug: "chuong-04-cac-component-thuong-su-dung"
image: https://kungfutech.edu.vn/thumbnail.png
position: 1
---

Dưới đây là code demo những component cơ bản thường sử dụng.

```javascript
import React from "react";
import {
  Image,
  View,
  Text,
  Button,
  TouchableOpacity,
  FlatList,
  StyleSheet,
} from "react-native";
import { Colors } from "../../../configs/style";

export class Components extends React.Component {
  //Header ứng dụng (tùy chọn)
  static navigationOptions = ({ navigation }) => {
    return {
      title: "COMPONENT",
      headerStyle: {
        backgroundColor: Colors.primary,
      },
      headerTintColor: Colors.white,
      headerTitleStyle: {
        alignSelf: "center",
      },
    };
  };

  constructor(props) {
    super(props);
    this.state = {
      message: "Message 2",
      listData: [
        {
          image: require("../../../assets/images/ios.png"),
          title: "IOS",
        },
        {
          image: require("../../../assets/images/android.png"),
          title: "Android",
        },
        {
          image: require("../../../assets/images/react-native.png"),
          title: "React Native",
        },
      ],
    };
    this.clickButton = 0;
    this.clickTouchAbleOpecity = 0;
  }

  onPressButtonDemo() {
    this.clickButton++;
    this.setState({
      message: "Clicked Button: " + this.clickButton,
    });
  }

  onPressTouchableOpacityDemo() {
    this.clickTouchAbleOpecity++;
    this.setState({
      message: "Clicked TouchableOpacity: " + this.clickTouchAbleOpecity,
    });
  }

  render() {
    return (
      <View style={Styles.container}>
        {/* Hiển thị Một message lên màn hình */}
        <Text style={Styles.textMessage}>WELCOME TO TEXT OF REACT-NATIVE</Text>
        <View style={Styles.containImage}>
          {/* Hiển thị ảnh từ local resource */}
          <Image
            style={Styles.imgLogo} /* Style của ảnh */
            resizeMode={
              "contain"
            } /* chế độ hiển thị (center, contain, cover, repeat, stretch )  của ảnh */
            source={require("../../../assets/images/react-native.png")}
          />

          {/* Hiển thị ảnh từ web/server */}
          <Image
            style={Styles.imgLogo}
            resizeMode={"contain"}
            source={{
              uri: "https://facebook.github.io/react-native/docs/assets/favicon.png",
            }}
          />
        </View>
        {/* In một giá trị của state lên màn hình */}
        <Text style={Styles.textMessage}>{this.state.message}</Text>

        {/* Sử dụng Button với chức năng press vào nút */}
        <Button
          onPress={() => this.onPressButtonDemo()}
          title="Click Me!"
          color="#841584"
        />

        {/* Sử dụng TouchableOpacity với chức năng press giống như button */}
        <TouchableOpacity
          style={Styles.btnStyle}
          onPress={() => this.onPressTouchableOpacityDemo()}
        >
          <Text style={Styles.textAction}>Touchable Opacity</Text>
        </TouchableOpacity>

        {/* Sử dụng FlatList để hiển thị ra một danh sách */}
        <FlatList
          data={this.state.listData}
          renderItem={({ item }) => this.renderItem(item)}
          keyExtractor={(item, index) => index.toString()}
        />
      </View>
    );
  }

  /* Hiển thị chi tiết 1 item như thế nào */
  renderItem(item) {
    return (
      <View style={Styles.containerItem}>
        <Image
          style={Styles.imgLogo}
          resizeMode={"contain"}
          source={item.image}
        />
        <Text>{item.title}</Text>
      </View>
    );
  }
}
//Trong example mình tách phần Styles này qua file khác cho dễ đọc
const Styles = StyleSheet.create({
  container: {
    flex: 1,
    flexDirection: "column",
    alignItems: "center",
    backgroundColor: Colors.white,
  },
  containImage: {
    marginTop: 16,
    flexDirection: "row",
    justifyContent: "center",
  },
  textMessage: {
    marginTop: 16,
    color: "green",
    fontSize: 16,
  },
  imgLogo: {
    width: 50,
    height: 50,
    margin: 4,
  },
  btnStyle: {
    height: 50,
    width: 200,
    borderColor: Colors.primary,
    borderRadius: 5,
    borderWidth: 2,
    justifyContent: "center",
    alignItems: "center",
    margin: 8,
  },
  textAction: {
    color: Colors.primary,
    fontSize: 20,
    fontWeight: "bold",
  },
  containerItem: {
    marginTop: 16,
    flexDirection: "row",
    alignItems: "center",
  },
});
```

Sau khi chạy Demo ta được UI như sau

![Các component thường sử dụng](https://github.com/techmely/hoc-lap-trinh/assets/29374426/4e8ae1ff-1a4e-46a8-b0bf-40701d73e1b1)

## View trong React Native

Là một component cũng thường xuyên được sử dụng. Thường được sử dụng với mục đích chia các view con theo hàng dọc hoặc hàng ngang dựa vào thuộc tính flexDirection trong style là 'column/row' (dọc / ngang), hoặc sử dụng để chứa nhiều view con hoặc khi cần in ra màn hình một view không hiển thị gì hết ví dụ như trong cấu trúc toán tử:

```js
{
	(Điều kiện) ?  <Text> Text Message <Text> : <View/>
}
```

flex: 1 ở style sẽ giúp kéo view rộng hết khung chứa có thể.

## Text trong React Native

Dùng để hiển thị 1 message lên màn hình. Có thể sử dụng text cố định hoặc in nội dung của một biến lên màn hình

```js
<Text>Message Here<Text>
<Text>{variable_here}<Text>
```

## Image trong React Native

Dùng để hiển thị hình ảnh lên màn hình. Có 3 cách hiển thị:

**Hiển thị ảnh Local**

```js
<Image source={require("/react-native/img/favicon.png")} />
```

**Hiển thị ảnh từ url**

```js
<Image
  style={{ width: 50, height: 50 }}
  source={{
    uri: "https://facebook.github.io/react-native/docs/assets/favicon.png",
  }}
/>
```

**Hiển thị ảnh base 64**

```js
<Image
  style={{ width: 66, height: 58 }}
  source={{
    uri: "data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAADMAAAAzCAYAAAA6oTAqAAAAEXRFWHRTb2Z0d2FyZQBwbmdjcnVzaEB1SfMAAABQSURBVGje7dSxCQBACARB+2/ab8BEeQNhFi6WSYzYLYudDQYGBgYGBgYGBgYGBgYGBgZmcvDqYGBgmhivGQYGBgYGBgYGBgYGBgYGBgbmQw+P/eMrC5UTVAAAAABJRU5ErkJggg==",
  }}
/>
```

Resize Mode quen thuộc:

- `cover`: (mặc định) Hình ảnh sẽ giữ nguyên tỷ lệ. Ảnh sẽ lớn hơn hoặc bằng khung chứa.
- `contain`: Hình ảnh vẫn giữ nguyên tỷ lệ. Ảnh sẽ nhỏ hơn hoặc bằng khung chứa
- `center`: Căn giữa hình ảnh theo 2 chiều. Lấy phần ở giữa, gần giống với cover.
- `repeat`: Lặp lại hình ảnh để che hết phần kích thước ô chứa.
- `stretch`: Thay đổi tỷ lệ hình ảnh để kéo dãn bằng với ô chứa.

## Button trong React Native

Cách sử dụng một Button

```js

onPressButtonDemo(){
    console.log("Click Button")
}

....
<Button
    onPress={() => this.onPressButtonDemo()}
    title="Click Me!"
    color="#841584"
/>
```

Thông thường mình ít khi sử dụng Button vì lý do custom style nó không hoạt động đúng với cả Android và IOS vì vậy nên mình thường sử dụng TouchableOpacity hơn.

Nhưng lưu ý cách sử dụng sự kiện onPress `onPress={() => this.onPressButtonDemo()}` Vui lòng viết theo cấu trúc này để giảm thiểu lỗi hoặc là phải binding hàm trong contrucstor trước lúc sử dụng.

Sự kiện `onPress` chỉ có một số component hỗ trợ, Text thì không hỗ trợ nên nếu muốn sử dụng `onPress` cho Text thì đọc phần `TouchableOpacity` phía dưới nhé.

### TouchableOpacity trong React Native

Thông thường mình thay thế việc sử dụng Button bằng TouchableOpacity để việc định dạng style giống nhau cho cả android và ios, TouchableOpacity có thể chứa bất kỳ view con nào, và nhớ lưu ý cách dùng sự kiện onPress giống như Button nhé.

```javascript
<TouchableOpacity
  style={Styles.btnStyle}
  onPress={() => this.onPressTouchableOpacityDemo()}
>
  <Text style={Styles.textAction}>Click Me</Text>
</TouchableOpacity>
```

### Flatlist trong React Native

Đây là Component thường được sử dụng để hiển thị 1 danh sách lên màn hình.

Cách dùng:

```javascript
<FlatList
    data={this.state.listData}
    renderItem={({ item }) => this.renderItem(item)}
    keyExtractor={(item, index) => index.toString()}
/>

/* Hiển thị chi tiết 1 item như thế nào */
renderItem(item) {
    return (
        <View style={Styles.containerItem}>
            <Image
                style={Styles.imgLogo}
                resizeMode={'contain'}
                source={item.image}
            />
            <Text>{item.title}</Text>
        </View>
    )
}
```

Một vài lưu ý khi sử dụng Flatlist:

- Khi một thành phần data (ví dụ `data[0] = ...`) của bạn thay đổi thường thì không vẽ lại UI cho nên bạn sẽ cần thêm một thuộc tính là `extraData={this.state}`. Lúc này mỗi lần state thay đổi thì danh sách lại được vẽ lại.
- Có thể sử dụng **Flatlist** để làm như GridView trong android dựa vào thuộc tính numColumns={colum} (colum là số cột). Nhưng bạn sẽ cần phải tính toán width, height của mỗi colum để hiển thị đẹp nhất (Không có sẵn như fill_parent trong android).

Các component ở trên mình chỉ mang tính chất giới thiệu để các bạn tìm hiểu. Để hiểu rõ hơn cũng như tìm hiểu thêm về các thuộc tính của mỗi component thì vui lòng đọc riêng tài liệu của các Component nhé.

Mỗi component sẽ có nhiều thuộc tính khác để hỗ trợ bạn làm UI tốt và mượt nhất có thể.
