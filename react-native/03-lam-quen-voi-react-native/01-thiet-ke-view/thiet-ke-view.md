---
title: "Thiết kế View"
description: "Sau đây là một đoạn code Demo về Style của ứng dụng React-Native. Code có sẵn trong Example"
chapter:
  name: "Làm quen với react native"
  slug: "chuong-03-lam-quen-voi-react-native"
category:
  name: "React Native"
  slug: "react-native"
image: https://kungfutech.edu.vn/thumbnail.png
position: 1
---

Sau đây là một đoạn code Demo về Style của ứng dụng React-Native.

```javascript
export class StyleDemo extends React.Component {
  render() {
    return (
      <View>
        <Text style={styles.red}>just red</Text>
        <Text style={styles.bigblue}>just bigblue</Text>
        <Text style={[styles.bigblue, styles.red]}>bigblue, then red</Text>
        <Text style={[styles.red, styles.bigblue]}>red, then bigblue</Text>
      </View>
    );
  }
}

const styles = StyleSheet.create({
  bigblue: {
    color: "blue",
    fontWeight: "bold",
    fontSize: 30,
  },
  red: {
    color: "red",
  },
});
```

Giống như một ứng dụng web cơ bản, React-Native sử dụng một số thẻ css để vẽ những gì bạn muốn. Nếu bạn là lập trình web quen thuộc với css thì việc thiết kế này khá đơn giản. Để trau dồi những khả năng này chỉ có cách là làm nhiều bạn sẽ tìm hiểu những style bạn muốn và sẽ làm ứng dụng của bạn đẹp hơn.

Ở ví dụ trên bạn có thể thay đổi các thuộc tính của style rồi reload lại để thấy sự thay đổi nhé.

Trong ví dụ thư mục Home tôi đã chia phần Style qua một file khác để dễ quản lý (Từ các ví dụ sau trở đi, tôi sẽ chia phần style này sang 1 file khác để dễ quản lý). Bạn có thể vào đó, thử thay đổi, xóa sửa để biết được thuộc tính nào dùng để làm gì nhé. Làm nhiều phần này thì sẽ có kinh nghiệm thiết kế đẹp thôi.

::alert{type="warning"}
Một vài lưu ý:

- Bạn nên biết thuộc tính nào dùng để làm gì, sử dụng tối ưu để hiệu quả nhất (Có thể copy code của ai đó nhưng nên hiểu dòng style nào làm việc gì).
- Không nên quá rườm rà code ngắn nhưng đạt được yêu cầu là tốt nhất.

::
