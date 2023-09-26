---
title: "Prop và cách truyền dữ liệu giữa các view"
description: "Prop và cách truyền dữ liệu giữa các view"
chapter:
  name: "Tương tác trong react native"
  slug: "chuong-05-tuong-tac-trong-react-native"
image: https://kungfutech.edu.vn/thumbnail.png
position: 1
---

## Prop và cách truyền dữ liệu giữa các View

Tạo file App.js như sau

```javascript
import React from "react";
import { View, Text, FlatList, StyleSheet } from "react-native";
import { Colors } from "../../../configs/style";
import { ViewItem } from "./ViewItem";

export class App extends React.Component {
  //Header ứng dụng (tùy chọn)
  static navigationOptions = ({ navigation }) => {
    return {
      title: "PROPS",
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
      message: "",
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
  }

  // onPressItem
  onPressItem(item, index) {
    this.setState({
      message: "Click item: " + index + " - title: " + item.title,
    });
  }

  render() {
    return (
      <View style={Styles.container}>
        <Text style={Styles.textMessage}>{this.state.message}</Text>
        <FlatList
          style={Styles.containList}
          data={this.state.listData}
          renderItem={({ item, index }) => this.renderItem(item, index)}
          keyExtractor={(item, index) => index.toString()}
        />
      </View>
    );
  }

  /* Hiển thị chi tiết 1 item như thế nào */
  renderItem(item, index) {
    return (
      <ViewItem
        data={item} //Truyền item này qua ViewItem như một prop
        onPressItem={(itemPress) => {
          this.onPressItem(itemPress, index);
        }} // truyền một hàm qua để bắt sự kiện click item
      />
    );
  }
}

const Styles = StyleSheet.create({
  container: {
    flex: 1,
    flexDirection: "column",
    alignItems: "center",
    backgroundColor: Colors.white,
  },
  textMessage: {
    marginTop: 16,
    color: "green",
    fontSize: 16,
  },
  containList: {
    width: "100%",
  },
});
```

và 1 file ViewItem.js nằm cùng thư mục

```javascript
import React from "react";
import { Image, View, Text, TouchableOpacity, StyleSheet } from "react-native";
import { Colors } from "../../../configs/style";

export class ViewItem extends React.Component {
  constructor(props) {
    super(props);
    this.state = {
      color: Colors.white,
    };
  }

  onPressItem() {
    //Bạn có thể xử lý sự kiện ở đây nếu cần, ví dụ như như đổi màu item
    let newColor = Colors.white;
    if (this.state.color == Colors.white) {
      newColor = Colors.primary;
    }
    this.setState({
      color: newColor,
    });

    //Hoặc chuyển việc xử lý đó ra phía ngoài thông qua hàm được truyền vào.
    //Có thể truyền dữ liệu ra ngoài để hàm phía ngoài xử lý
    this.props.onPressItem(this.props.data);
  }

  render() {
    //in props được truyền qua để kiểm tra
    console.log(this.props.data);
    //render ra màn hình item được truyền vào thông qua props
    return (
      <TouchableOpacity
        style={[Styles.containerItem, { backgroundColor: this.state.color }]}
        onPress={() => this.onPressItem()}
      >
        <Image
          style={Styles.imgLogo}
          resizeMode={"contain"}
          source={this.props.data.image} //sử dụng prop được truyền qua
        />
        <Text>{this.props.data.title}</Text>
      </TouchableOpacity>
    );
  }
}

const Styles = StyleSheet.create({
  imgLogo: {
    width: 50,
    height: 50,
    margin: 4,
  },
  containerItem: {
    marginLeft: 16,
    marginRight: 16,
    marginTop: 16,
    flexDirection: "row",
    alignItems: "center",
  },
});
```

Trong Example mình đã gộp style lại và đưa nó ra 1 file riêng là `styles.js` để dễ quản lý

Ở ví dụ trên ta demo việc truyền dữ liệu giữa 2 component thông qua props

Bên gửi qua (ViewItem đóng vai trò là 1 component được tùy biến)

```javascript
<ViewItem
  data={item} //Truyền item này qua ViewItem như một prop
  onPressItem={(itemPress) => {
    this.onPressItem(itemPress, index);
  }} // truyền một hàm qua để bắt sự kiện click item
/>
```

Bên nhận dữ liệu có thể sử dụng dữ liệu được truyền qua thông qua props. (Kiểu nó ném mấy cái dữ liệu qua thì bên nhận này truy xuất thông qua props)

```javascript
...
render() {
    //in props được truyền qua để kiểm tra
    console.log(this.props.data)
    //render ra màn hình item được truyền vào thông qua props
    return (
        <TouchableOpacity style={[Styles.containerItem, { backgroundColor: this.state.color }]} onPress={() => this.onPressItem()}>
            <Image
                style={Styles.imgLogo}
                resizeMode={'contain'}
                source={this.props.data.image}  //sử dụng prop được truyền qua
            />
            <Text>{this.props.data.title}</Text>
        </TouchableOpacity>
    )
}
```

Việc truyền dữ liệu ngược lại cũng được thể hiện trong ví dụ thông qua việc xử lý sự kiện onPressItem()

```javascript
onPressItem() {
    //Bạn có thể xử lý sự kiện ở đây nếu cần, ví dụ như như đổi màu item
    let newColor = Colors.white;
    if (this.state.color == Colors.white) {
        newColor = Colors.primary
    }
    this.setState({
        color: newColor
    })

    //Hoặc chuyển việc xử lý đó ra phía ngoài thông qua hàm được truyền vào.
    //Có thể truyền dữ liệu ra ngoài để hàm phía ngoài xử lý
    this.props.onPressItem(this.props.data)
}

```

::alert{type="warning"}
Một vài lưu ý khi sử dụng props

- Không thay đổi dữ liệu trong prop ở bên nhận.
- Nên chia mỗi thành phần riêng biệt ra mỗi component riêng và giao tiếp với component chính thông qua props để giảm thiểu việc phải vẽ lại nguyên toàn bộ, nhất là những component có chứa các `timmer` (`setInterval()`, `setTimeOut()`...).

::
