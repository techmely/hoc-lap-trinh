---
title: "Vòng đời của component"
description: "Component là một thành phần cơ bản trong ứng dụng react-native. Mọi view, screen đều được kế thừa từ lớp component này."
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
  name: "Component trong react native"
  slug: "chuong-02-component-trong-react-native"
category:
  name: "React Native"
  slug: "react-native"
image: https://kungfutech.edu.vn/thumbnail.png
position: 1
---

## Vòng đời của component

![Vòng đời của component react native](https://github.com/techmely/hoc-lap-trinh/assets/29374426/158ab286-e781-4bcb-87e5-22af5b7aa696)

### Các hàm được gọi trong vòng đời của Component

`constructor(props)` - Hàm khởi tạo component. Trong hàm này chúng ta thường dùng để khởi tạo state, binding các hàm con của component.

<content-warning>
Không được thay đổi state bằng phương thức `this.setState()` trong hàm này.
</content-warning>

`componentWillMount()` - Hàm này sẽ bị loại bỏ ở phiên bản mới.

`render()` - Đây là hàm bắt buộc có trong component. Sau khi khởi tạo hàm này được gọi để trả về các thành phần hiển thị lên màn hình.

Hàm này sẽ được tự động gọi lại khi state hoặc props của nó thay đổi. Chỉ những component có sử dụng state hoặc props thì mới được gọi lại để render lại.

**Lưu ý:**

- Trong hàm này cũng không được sử dụng phương thức `this.setState()`
- Trong hàm này không nên chạy xử lý dữ liệu nhiều để không bị lag khi render (nên xử lý dữ liệu trong componentDidMount hoặc constructor).
- `componentDidMount()` - Hàm này sẽ được gọi ngay sau khi hàm `render()` lần đầu tiên được gọi. Thông thường trong hàm này ta có thể lấy dữ liệu từ server hoặc client để render dữ liệu ra. Khi chạy đến đây thì các phần từ đã được sinh ra rồi, ta có thể tương tác với các thành phần UI.
- `componentWillReceiveProps(nextProps)` - Hàm này được gọi khi props của component được khởi tạo thay đổi.
- `shouldComponentUpdate(nextProps, nextState)` - Hàm này được gọi trước `render()` khi cập nhật dữ liệu. Hàm này trả về giá trị `true` hoặc `false`. Nếu `false` thì không gọi lại hàm render mặc định nó trả về `true`.
- `componentWillUpdate(nextProps, nextState)` - Hàm này được gọi ngay sau khi hàm `shouldComponentUpdate()` trả về `true`. Trong hàm này cũng không được set lại state.
- `componentDidUpdate(prevProps, prevState)` - Hàm này được gọi ngay sau hàm render() từ lần thứ 2 trở đi.
- `componentWillUnmount()` - Hàm này được gọi khi component này bị loại bỏ. Chúng ta nên thực hiện các thao tác dọn dẹp, hủy timer hoặc các tiến trình đang xử lý.
