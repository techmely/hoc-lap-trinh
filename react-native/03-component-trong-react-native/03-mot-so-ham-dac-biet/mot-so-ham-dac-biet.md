---
title: "Một số hàm đặc biệt"
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
position: 3
---
### Một số hàm đặc biệt

- **Hàm this.setState()** - Hàm dùng để thay đổi state của component. Đây là phương thức chính để cập nhật giao diện người dùng. Khi hàm này thực thi xong thì hàm **render()** sẽ được tự động gọi lại. **Những giá trị nào của state thay đổi thì chỉ những thành phần có sử dụng biến state tương ứng đó được gọi để vẽ lại UI**.
<br>Lưu ý: hàm này chạy bất đồng bộ nên chúng ta không nên đọc giá trị sau khi gọi hàm này. <br>Cách sử dụng: 

```javascript
this.setState({
	message: "Chào mừng",
	key: "Value",
})
console.log(this.state.message) //không nên
// không sử dụng this.state ngay sau khi vừa set xong
// biến truyền vào cho hàm setState là một đối tượng có dạng key: value.

```

Có thể sử dụng callback để check dữ liệu hoặc xử lý một số tác vụ sau khi thay đổi trạng thái

```javascript
this.setState({
	message: "Chào mừng"
}, ()=>{
	console.log(this.state.message)   // kết quả: Chào mừng
})

```


- **Hàm forceUpdate()** - Mặc định hàm render() sẽ được gọi khi props hoặc state thay đổi. Nhưng nếu một vài thành phần UI sử dụng một số dữ liệu khác state hoặc prop muốn thay đổi, thì chúng ta cần thông báo cho React biết để vẽ lại toàn bộ bằng cách gọi hàm forceUpdate().

###  Một vài lưu ý nhỏ khi dùng React-Native
- Dữ liệu cần in ra màn hình và cần thay đổi lại UI khi nó thay đổi thì đặt vào state.
- Dữ liệu không cần thay đổi UI khi nó thay đổi thì có thể dùng ```this.xxx``` như vậy biến này có thể thực hiện thao tác = (gán) và sử dụng trực tiếp như các biến thông thường.
- Dữ liệu trong prop thì không nên thay đổi.
- Trong **state** chỉ nên chứa dữ liệu, không nên chứa các **View / Component** vào trong state. Làm như vậy có thể gây double dữ liệu và việc quản lý UI trở nên phức tạp hơn và khó tùy biến sau này.
