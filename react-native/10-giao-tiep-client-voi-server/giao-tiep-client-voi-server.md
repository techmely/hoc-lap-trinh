---
title: "Giao tiếp Client với Server"
description: ""
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
  name: "Giao tiếp Client với Server"
  slug: "chuong-10-giao-tiep-client-voi-server"
category:
  name: "React Native"
  slug: "react-native"
image: https://kungfutech.edu.vn/thumbnail.png
position: 1
---

## RESTful API là gì

![RESTful API.](https://github.com/techmely/hoc-lap-trinh/assets/29374426/7292bacd-2485-49e0-ac16-565667acfdd8)

Nếu bạn không biết RESTful API là gì thì có thể đọc thêm bài viết này (<https://viblo.asia/p/thiet-ke-restful-api-GrLZD98Vlk0>) để hiểu rõ hơn về RESTful API. Đây là một trong những chuẩn giao tiếp phổ biến giữa client và server.

Phần Demo này được trình bày khá rõ ràng và chi tiết trong ví dụ Example (app/modules/screens/RestFul/RestFul.js). Bạn nên chạy ví dụ trước để thấy cách hoạt động của nó. Demo bao gồm việc gọi một public api từ <https://api.ice5.skyx.app/get_languages> (GET) và hiển thị kết quả như sau:

![Giao tiếp Client vs Server react native](https://github.com/techmely/hoc-lap-trinh/assets/29374426/271b6c2e-a957-4357-bec0-b13cf4ce77cd)

- File Thiết kế RestFull tổng quan: app/libs/RESTClient.js

```javascript
import { getBaseURL } from "../configs/config";

let networkError = {
  error_code: -1,
  message: "Network error",
  data: {},
};

export class RESTFulAPI {
  //Định nghĩa một api lấy language từ server.
  // Public api có sẵn tại https://api.ice5.skyx.app/get_languages

  getLanguage() {
    let api = getBaseURL() + "get_languages";
    return this.fetchData(api);
  }

  //Định nghĩa một hàm bất đồng bộ hỗ trợ các phương thức, GET, POST, PUT, DELETE (mặc định là GET)
  async fetchData(api, method = "GET", body) {
    let headers = {
      Accept: "application/json",
      "Content-Type": "application/json",
    };
    try {
      let response = await fetch(api, {
        method: method,
        headers: headers,
        body: JSON.stringify(body),
      });
      let responseJson = await response.json();
      return responseJson;
    } catch (error) {
      return networkError;
    }
  }
}

export default RESTClient = new RESTFulAPI();
```

Ở đây mình định nghĩa 1 lớp để quản lý việc trao đổi, giao tiếp giữa client và server. Hàm fetchData() là một hàm bất đồng bộ hỗ trợ gọi các phương thức RESTful.

Và đây là cách chúng ta gọi hàm fetchData() và định nghĩa rõ ràng 1 api truy cập để lấy danh sách ngôn ngữ. Lưu ý: Thay vì việc mình đặt trực tiếp link <https://api.ice5.skyx.app/get_languages> thì mình lại gọi hàm getBaseURL() là để sau này có thay api, thì mình không phải đi thay nhiều chỗ, chỉ cần vào config và thay đổi là hoàn tất.

```javascript
getLanguage() {
    let api = getBaseURL() + "get_languages";
    return this.fetchData(api);
}
```

Ví dụ gọi fetchData() với phương thức POST

```js
let api = getBaseURL() + "get_languages";
let body = {...}
return this.fetchData(api, 'POST', body);
//Đây là cách POST 1 đối tượng body lên hệ thống.
// Phương thức POST trên server này không hỗ trợ nên ắt hẳn không hoạt động rồi. Mình chỉ muốn demo cho các bạn biết cách gọi phương thức khác ntn thôi. =))
```

- Cách sử dụng RESTClient

```javascript
import RESTClient from '../../../libs/RESTClient';

...

getLanguagesFromServer() {
    //todo có thể làm cái xoay xoay ở đây
    //Gọi hàm lấy language từ lớp RestClient để lấy dữ liệu
    RESTClient.getLanguage().then(
        (result) => {
            //Đây là quá trình bất đồng bộ, và trả về result sau khi kết thúc
            if (result.error_code == 0) {
                //Kiểm tra trạng thái lỗi và set lại dữ liệu để render data
                this.setState({
                    listData: result.data
                })
            }
            //todo Gọi xong thì tắt cái xoay xoay đi
        }
    )
}

```

Lưu ý: Phương thức `getLanguagesFromServer()` nên gọi trong `componentDidMount()` hoặc các sự kiện sau khi constructor() hoàn tất để trách những lỗi có nguy cơ tiềm ẩn ví dụ như api nhanh quá, `constructor` chạy chưa xong và nó đi `setState()` thì app của bạn nó làm việc không đúng.
