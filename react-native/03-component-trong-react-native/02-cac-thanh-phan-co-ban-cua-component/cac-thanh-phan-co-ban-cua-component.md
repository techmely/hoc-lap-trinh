---
title: "Các thành phần cơ bản của component"
description: "Component là một thành phần cơ bản trong ứng dụng react-native. Mọi view, screen đều được kế thừa từ lớp component này."
keywords:
  [
    "gioi thieu react native",
    "giới thiệu react native",
    "khoá học react native",
    "giới thiệu react native",
    "giới thiệu jreact native cơ bản",
    "react native la gi",
    "tong quan ve react native",
    "gioi thieu ve ngon ngu lap trinh react native",
    "tom tat react native",
    "code react native la gi",
  ]
chapter:
  name: "Component trong React Native"
  slug: "chuong-03-component-trong-react-native"
category:
  name: "React Native"
  slug: "react-native"
image: https://kungfutech.edu.vn/thumbnail.png
position: 2
---

## Các thành phần cơ bản của component

Sau đây là chương trình mẫu cơ bản để ta hiểu được các thành phần của một Component

```javascript
import React, { Component } from "react";
import { Text, View } from "react-native";

export default class App extends Component {
  constructor(props) {
    super(props);
    this.state = {
      message: "Welcome to Code 101 - React-native",
    };
  }

  render() {
    return (
      <View>
        <Text>{this.state.message}</Text>
      </View>
    );
  }
}
```

- **State** - là biến điều khiển trạng thái nội bộ của 1 component. State có thể thay đổi bằng cách gọi hàm this.setState({...}). Mỗi lần thay đổi state hàm render sẽ được gọi lại ngay sau đó (hàm render chỉ thay đổi những thành phần có liên quan đến những giá trị trong state bị thay đổi).<br> Chúng ta nên bỏ các biến có liên quan đến UI vào trong state này, để khi state thay đổi, UI màn hình sẽ được vẽ lại và thay đổi theo.
  <br>**Lưu ý:** Không được thay đổi state trực tiếp bằng cách gọi this.state = {...} nếu sử dụng thay đổi state trực tiếp toàn bộ component này sẽ không còn hoạt động đúng như mong muốn nữa.

- **Props** - là các thuộc tính được thằng sử dụng truyền vào. Đây là các thông số được truyền vào để tùy chỉnh theo ý muốn của người xây dựng Component. Khác với state chúng ta không được thay đổi props ở trong chính bản thân của nó. Chúng ta chỉ nên đọc các thuộc tính được truyền vào để sử dụng mà thôi.<br> Ví dụ sử dụng props: cũng là ví dụ trên nhưng chúng ta custom một số thứ để bạn có thể hiểu rõ hơn về props.

```javascript
import React, { Component } from "react";
import { Text, View } from "react-native";

class CustomText extends Component {
  constructor(props) {
    super(props);
  }

  render() {
    return (
      <Text>
        {this.props.message}
      </Text> /*Sử dụng props được truyền từ ngoài vào.*/
    );
  }
}

export default class App extends Component {
  constructor(props) {
    super(props);
    this.state = {
      message: "Welcome to Code 101 - React-native",
    };
  }

  render() {
    return (
      <CustomText
        message={this.state.message}
      /> /*truyền 1 props vào cho thằng con sử dụng.*/
    );
  }
}
```
